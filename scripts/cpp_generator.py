#!/usr/bin/python3 -i
#
# Copyright (c) 2017-2022 The Khronos Group Inc.
# Copyright (c) 2017-2019 Valve Corporation
# Copyright (c) 2017-2019 LunarG, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import re

from automatic_source_generator import AutomaticSourceOutputGenerator, write
from jinja_helpers import JinjaTemplate, make_jinja_environment

VALID_FOR_NULL_INSTANCE = set((
    'xrEnumerateInstanceExtensionProperties',
    'xrEnumerateApiLayerProperties',
    'xrCreateInstance',
    'xrLoaderInitKHR',
))

# These break the projection right now.
SKIP = set((
    'xrGetSceneComputeStateMSFT',
    'xrGetSwapchainStateFB',
))

DISCOURAGED = set((
    'xrResultToString',
    'xrStructureTypeToString',
))

TEMPLATED_TWO_CALL = set([
    'xrEnumerateSwapchainImages'
])

MANUALLY_PROJECTED_SCALARS = set((
    "XrTime",
    "XrDuration",
))

MANUALLY_PROJECTED = set((
    "XrEventDataBuffer",
)).union(MANUALLY_PROJECTED_SCALARS)

SKIP_PROJECTION = set((
    "XrBaseInStructure",
    "XrBaseOutStructure",
    # Array of XrColor4f not getting initialized right
    "XrPassthroughColorMapMonoToRgbaFB",
    # No "invalid" atom value
    'XrAsyncRequestIdFB',
    'XrEventDataSpatialAnchorCreateCompleteFB',
    'XrEventDataSpaceSetStatusCompleteFB',
    'XrEventDataSpaceQueryCompleteFB',
    'XrEventDataSpaceEraseCompleteFB',
    'XrEventDataSpaceQueryResultsAvailableFB',
    'XrEventDataSpaceSaveCompleteFB',
    'XrSpaceSaveInfoFB',
))

TWO_CALL_STRING_NAME = "buffer"

RULE_BREAKING_ENUMS = {
    'XrResult': 'XR',
    'XrStructureType': 'XR_TYPE',
    # Legacy oopsie that made it in unintentionally.
    # Won't happen again, scripts guarantee that.
    'XrPerfSettingsNotificationLevelEXT': 'XR_PERF_SETTINGS_NOTIF_LEVEL_EXT',
}

SINGLE_LINE_COMMENT_STARTS = ('///', '//!', '//')

CAPACITY_INPUT_RE = re.compile(r'(?P<itemname>[a-zA-Z]*)CapacityInput')
COUNT_OUTPUT_RE = re.compile(r'(?P<itemname>[a-zA-Z]*)CountOutput')

UPPER_TOKENS = set((
    "API",
    "CV1",
    "EGL",
    "ES",
    "RGB",
    "CW",  # clockwise
    "CCW",  # counter-clockwise
))

SPECIAL_TOKENS = {
    "OPENGL": "OpenGL"
}


def _discouraged_begin(cmd):
    if cmd.name in DISCOURAGED:
        return "\n#ifdef OPENXR_HPP_PROVIDE_DISCOURAGED_FUNCTIONS\n"
    return ""


def _discouraged_end(cmd):
    return _discouraged_begin(cmd).replace("#ifdef", "#endif  // ")


def _member_function_name(cmdname):
    base = cmdname[2].lower() + cmdname[3:]
    if base.startswith('destroy'):
        return 'destroy'
    return base


def _to_camel_case(val):
    chars = []
    for token in val.split('_'):
        if token in UPPER_TOKENS:
            # We take this token unmodified.
            chars.extend(token)
            continue
        if token in SPECIAL_TOKENS:
            # We have a special way of camel-casing this.
            chars.extend(SPECIAL_TOKENS[token])
            continue
        next_char_upper = True
        for c in token:
            if str.isdigit(c):
                # A letter immediately following a number should be kept uppercase
                # for things like 2D, Vector3F, etc.
                next_char_upper = True
                chars.append(c)
            elif next_char_upper:
                chars.append(c)
                next_char_upper = False
            else:
                chars.append(str.lower(c))

    return ''.join(chars)


def _strip_prefix(val, prefix):
    if val.startswith(prefix):
        return val[len(prefix):]
    return val


def _strip_suffix(val, suffix):
    if val.endswith(suffix):
        return val[:-len(suffix)]
    return val


def _project_type_name(typename):
    return _strip_prefix(typename, "Xr")


def _is_static_length_array(member):
    return member.is_array and member.pointer_count == 0


def _is_static_length_string(member):
    return member.type == "char" and _is_static_length_array(member)


def _block_comment(s, doxygen=False):
    def clean_line(line):
        line = line.rstrip()
        ls = line.lstrip()
        for prefix in SINGLE_LINE_COMMENT_STARTS:

            if ls.startswith(prefix):
                line = ls[len(prefix):]
                if line.startswith(' '):
                    line = line[1:]
                break
        return line

    lines = [clean_line(line).rstrip() for line in s.split('\n') if line]

    # Remove leading and trailing empty lines
    while lines and not lines[-1]:
        lines.pop()
    while lines and not lines[0]:
        lines.pop(0)

    # if a line is a second+ consecutive blank line,
    # then both that line, and the preceding one (lined up with zip)
    # will be false-ish.
    lines = [line
             for prev, line in zip([""] + lines, lines)
             if prev or line]
    # Prepend the *
    lines = [' * ' + line for line in lines]
    lines.insert(0, "/*!" if doxygen else "/*")
    lines.append(' */')
    lines.append('')
    return '\n'.join(lines)


def _block_doxygen_comment(s):
    return _block_comment(s, doxygen=True)


# def _make_dummy_param(name, typename, cdecl):
#     return MemberOrParam(typename, False, True, False, False, False, 0, False, [], None, None, 0, None, False, True, name, None, cdecl)

class StructProjection:
    """Stores the struct details implementation."""

    def __init__(self, struct, gen):
        self.struct = struct
        self.conventions = gen.genOpts.conventions
        self.name = struct.name
        self.cpp_name = _project_type_name(struct.name)
        self.qualified_name = self.cpp_name
        self.is_core = gen.isCoreExtensionName(struct.ext_name)
        self.typed_struct = gen._is_tagged_type(struct.name)
        self.is_base_only = gen._is_base_only(struct)
        self.has_type_enum_value = self.typed_struct and not self.is_base_only

        self.is_derived_type = struct.name in gen.struct_parents
        self.parent_fields = []
        self.is_output = gen._is_struct_output(struct)

        self.parent_type = None
        if self.typed_struct:
            self.is_abstract = self.is_base_only
            if self.is_output:
                self.parent_cpp_type = "impl::OutputStructBase"
                self.next_chain_type = "void *"
            else:
                self.parent_cpp_type = "impl::InputStructBase"
                self.next_chain_type = "const void *"

            if self.is_derived_type:
                self.parent_type = gen.struct_parents[struct.name]
                self.parent_cpp_type = _project_type_name(self.parent_type)
                self.parent_fields = gen.struct_fields[gen.struct_parents[struct.name]]
        else:
            self.is_abstract = False
            self.parent_cpp_type = None
            self.next_chain_type = None

        self.struct_type_enum = gen._get_tag(struct.name) if self.has_type_enum_value else None

    @property
    def struct_parent_decl(self):
        if self.typed_struct:
            return f": public {self.parent_cpp_type}"
        return ""

    @property
    def next_param_decl_with_default(self):
        if self.typed_struct:
            return self.next_param_decl + " = nullptr"
        return None

    @property
    def next_param_decl(self):
        if self.typed_struct:
            return f"{self.next_chain_type} {self.next_param_name}"
        return None

    @property
    def next_param_name(self):
        if self.typed_struct:
            return "next_"
        return None


DISPATCH_TEMPLATE_PARAM_NAME = "Dispatch"
DISPATCH_TEMPLATE_DEFN = "typename " + DISPATCH_TEMPLATE_PARAM_NAME
# ENABLE_IF_TEMPLATE_DEFN = "typename std::enable_if<traits::is_dispatch<{}>::value, int>::type".format(DISPATCH_TEMPLATE_PARAM_NAME)
ENABLE_IF_TEMPLATE_DEFN = "OPENXR_HPP_REQUIRE_DISPATCH({})".format(DISPATCH_TEMPLATE_PARAM_NAME)

ENABLE_IF_TEMPLATE_DECL = ENABLE_IF_TEMPLATE_DEFN + " = 0"


class MethodProjection:
    """Stores the method declaration and implementation."""

    def __init__(self, cmd, gen):
        self.cmd = cmd
        self.conventions = gen.genOpts.conventions
        self.name = cmd.name
        self.cpp_name = _member_function_name(cmd.name)
        self.is_member_function = False
        self.is_core = gen.isCoreExtensionName(cmd.ext_name)
        self.params = cmd.params[:]
        self.decl_params = cmd.params[:]
        self.is_create = cmd.is_create_connect
        self.is_destroy = cmd.is_destroy_disconnect
        self.is_two_call = False

        self.handle = cmd.handle
        if self.handle:
            self.cpp_handle = _project_type_name(cmd.handle_type)
        else:
            self.cpp_handle = None

        self.decl_dict = {x.name: x.cdecl.strip() for x in self.params}
        """
        Maps an original parameter name to how the corresponding parameter in the projection, if any, should be declared in the prototype.
        """

        self.access_dict = {x.name: x.name.strip() for x in self.params}
        """
        Maps an original parameter name to what should be passed as that parameter within the projection.
        """

        self.return_type = "Result"
        self.bare_return_type = self.return_type

        self.return_codes = cmd.return_values[:]
        self.cpp_return_codes = ['Result::' + gen.createEnumValue(x, 'XrResult')
                                 for x in self.return_codes]

        self.return_statement = "return result;"
        self.pre_statements = []
        self.post_statements = []

        self.masks_simple = False

        self.result_name = 'result'
        self.returns = [self.result_name]
        self.return_template_params = []

        self.dispatch = DISPATCH_TEMPLATE_PARAM_NAME + "&& d"
        self.template_decl_list = [DISPATCH_TEMPLATE_DEFN]
        """Template parameters to use in the method (forward) declaration."""

        self.template_defn_list = self.template_decl_list[:]
        """Template parameters to use in the method definition - should not include default args."""

        # Add these to limit what can be deduced as a dispatch.
        self.template_decl_list.append(ENABLE_IF_TEMPLATE_DECL)
        self.template_defn_list.append(ENABLE_IF_TEMPLATE_DEFN)

        self.exceptions_permitted = True
        self.explicit_result_elided = False
        """If true, our most advanced enhanced wrapper doesn't have an XrResult anywhere."""

    @property
    def qualified_name(self):
        if self.handle and self.is_member_function:
            return "{}::{}".format(self.cpp_handle, self.cpp_name)
        return self.cpp_name

    def _declparams(self, replacements=None):
        def find_decl(name):
            if replacements and name in replacements:
                return replacements.get(name)
            return self.decl_dict.get(name)
        params = (find_decl(param.name) for param in self.decl_params)
        params = [x for x in params if x is not None]
        return params

    @property
    def prose_bare_return(self):
        if 'string' in self.bare_return_type:
            return "the output string"
        return "the output of type %s" % self.bare_return_type

    def get_template_decls(self, suppress_default_dispatch_arg=False):
        decls = self.template_decl_list[:]
        if not suppress_default_dispatch_arg:
            for i, decl in enumerate(decls):
                if DISPATCH_TEMPLATE_DEFN == decl:
                    if self.is_core:
                        decls[i] = decl + " OPENXR_HPP_DEFAULT_CORE_DISPATCH_TYPE_ARG"
                    else:
                        decls[i] = decl + " OPENXR_HPP_DEFAULT_EXT_DISPATCH_TYPE_ARG"
        return ", ".join(decls)

    @property
    def template_defns(self):
        return ", ".join(self.template_defn_list)

    def get_declaration_params(self, replacements=None, extras=None, suppress_default_dispatch_arg=False):
        params = self._declparams(replacements)
        if extras:
            params.extend(extras)

        params.append(self.dispatch)
        if not suppress_default_dispatch_arg:
            if self.is_core:
                params[-1] = params[-1] + " OPENXR_HPP_DEFAULT_CORE_DISPATCH_ARG"
            else:
                params[-1] = params[-1] + " OPENXR_HPP_DEFAULT_EXT_DISPATCH_ARG"
        return params

    def get_definition_params(self, replacements=None, extras=None):
        params = self._declparams(replacements)
        if extras:
            params.extend(extras)
        params.append(self.dispatch)
        return params

    def get_main_invoke(self, replacements=None):
        def find_invoke(name):
            if replacements and name in replacements:
                return replacements.get(name)
            return self.access_dict.get(name)
        invocation_params = (find_invoke(param.name) for param in self.params)
        return "Result result = static_cast<Result>( d.{}({}) );".format(
            self.name, ", ".join(invocation_params)
        )

    def get_invocation(self, **kwargs):
        lines = self.pre_statements[:]
        lines.append(self.get_main_invoke(**kwargs))
        lines.extend(self.post_statements)
        lines.append(self.return_statement)
        return lines

    def get_success_codes(self):
        return [x for x in self.cpp_return_codes if "Error" not in x and "LossPending" not in x]

    @property
    def qualifiers(self):
        if self.handle and not self.is_destroy:
            return "const"
        return ""


class CppGenerator(AutomaticSourceOutputGenerator):
    """Generate C++ wrapper header using XML element attributes from registry"""

    def __init__(self, *args, **kwargs):
        self.quiet = kwargs.pop('quiet', False)
        super().__init__(*args, **kwargs)
        self.env = make_jinja_environment(file_with_templates_as_sibs=__file__, trim_blocks=False)
        self.env.filters['block_doxygen_comment'] = _block_doxygen_comment

    def outputGeneratedAuthorNote(self):
        # Disabled
        pass

    def outputCopywriteHeader(self):
        # Disabled - there is one in the template.
        pass

    def computeNullAtom(self, typename):
        null_atom = self.conventions.generate_structure_type_from_name(typename)
        return null_atom.replace('XR_TYPE', 'XR_NULL')

    def findVendorSuffix(self, name):
        for vendor in self.vendor_tags:
            if name.endswith(vendor):
                return vendor

    def getEnumValuePrefixSuffix(self, typename):
        if typename in RULE_BREAKING_ENUMS:
            prefix = RULE_BREAKING_ENUMS[typename]
        else:
            prefix = self.conventions.generate_structure_type_from_name(typename)
            prefix = prefix.replace('XR_TYPE', 'XR')
        suffix = self.findVendorSuffix(prefix)
        if suffix:
            prefix = _strip_suffix(prefix, '_' + suffix)
        return prefix, suffix

    def createEnumValue(self, name, typename):
        prefix, type_suffix = self.getEnumValuePrefixSuffix(typename)
        name = _strip_prefix(name, prefix + '_')
        suffix = None
        if type_suffix:
            name = _strip_suffix(name, '_' + type_suffix)

        suffix = self.findVendorSuffix(name)
        if suffix:
            name = _strip_suffix(name, '_' + suffix)
        enum_name = _to_camel_case(name)

        if suffix:
            enum_name += suffix

        return enum_name

    def getFlagValuePrefixSuffix(self, typename):
        prefix = self.conventions.generate_structure_type_from_name(typename)
        prefix = prefix.replace('XR_TYPE', 'XR')
        suffix = self.findVendorSuffix(prefix)
        if suffix:
            prefix = _strip_suffix(prefix, '_' + suffix)
            suffix = 'BIT_' + suffix
        else:
            suffix = 'BIT'

        prefix = prefix[:-len('_FLAG_BITS')]
        return prefix, suffix

    def createFlagValue(self, name, typename):
        prefix, type_suffix = self.getFlagValuePrefixSuffix(typename)
        name = _strip_prefix(name, prefix + '_')
        suffix = None
        if type_suffix:
            name = _strip_suffix(name, '_' + type_suffix)

        suffix = self.findVendorSuffix(name)
        if suffix:
            name = _strip_suffix(name, '_' + suffix)
        enum_name = _to_camel_case(name)

        if suffix:
            enum_name += suffix

        return enum_name

    def createEnumException(self, name):
        enum_val = self.createEnumValue(name, 'XrResult')
        suffix = self.findVendorSuffix(name)
        if suffix:
            enum_val = _strip_suffix(enum_val, suffix)
        result = enum_val.replace('Error', '') + 'Error'
        if suffix:
            result += suffix
        return result

    def _basic_method_projection(self, method):
        """Perform the basic manipulation of a MethodProjection to convert it from C to C++."""

        is_two_call = self._enhanced_method_detect_twocall(method)

        # Free function to method
        if method.handle:
            handle = method.params[0]
            method.decl_params.pop(0)
            method.is_member_function = True
            method.decl_dict[handle.name] = None
            method.access_dict[handle.name] = "this->get()"
            # if method.cpp_name.endswith(method.cpp_handle):
            #     method.cpp_name = _strip_suffix(method.cpp_name, method.cpp_handle)

        # Convert handles
        for param in method.decl_params:
            if param.type in self.dict_handles:
                name = param.name
                cpp_type = _project_type_name(param.type)
                if param.pointer_count == 0:
                    # Input handle
                    method.decl_dict[name] = "{} {}".format(
                        cpp_type, name)
                    method.access_dict[name] = "{}.get()".format(name.strip())
                elif param.pointer_count == 1:
                    # Output handle
                    method.decl_dict[name] = "{}& {}".format(
                        cpp_type, name)
                    method.access_dict[name] = "{}.put()".format(name.strip())

        # Convert enums
        for param in method.decl_params:
            if param.type in self.dict_enums:
                name = param.name
                cpp_type = _project_type_name(param.type)
                if param.pointer_count == 0:
                    # Input enum
                    method.decl_dict[name] = "{} {}".format(
                        cpp_type, name)
                    method.access_dict[name] = "OPENXR_HPP_NAMESPACE::get({})".format(name.strip())
                elif param.pointer_count == 1 and not is_two_call:
                    # Output enum
                    method.decl_dict[name] = "{}& {}".format(
                        cpp_type, name)
                    method.pre_statements.append(
                        "{} {}_tmp;".format(param.type, name.strip()))
                    method.access_dict[name] = "{}_tmp".format(name.strip())
                    method.post_statements.append(
                        "{name} = static_cast<{t}>({name}_tmp);".format(name=name.strip(), t=cpp_type))

        # Convert structs
        for param in method.decl_params:
            if param.type not in self.dict_structs:
                continue
            if self._is_base_only(self.dict_structs[param.type]):
                # This is a polymorphic parameter: skip conversion for now.
                continue
            if param.type in SKIP_PROJECTION:
                # This is a mess to project.
                continue
            name = param.name
            cpp_type = _project_type_name(param.type)
            if param.is_const:
                # Input struct
                method.decl_dict[name] = "const {}& {}".format(cpp_type, name)
                method.access_dict[name] = "{}.get()".format(name.strip())
            elif param.pointer_count == 1 and not is_two_call:
                # Output struct
                method.decl_dict[name] = "{}& {}".format(cpp_type, name)
                method.access_dict[name] = "{}.put()".format(name.strip())

        # Convert atoms, plus XrTime and XrDuration as special case (promoted from raw ints to constexpr wrapper classes)
        for param in method.decl_params:
            if param.type not in MANUALLY_PROJECTED_SCALARS and param.type not in self.dict_atoms:
                continue
            if param.type in SKIP_PROJECTION:
                continue
            name = param.name
            cpp_type = _project_type_name(param.type)
            method.decl_dict[name] = "{} {}".format(cpp_type, name)
            method.access_dict[name] = "{}.get()".format(name.strip())

    def _update_enhanced_return_type(self, method):
        """Set the return type based on the bare return type.

        Used by _enhanced_method_projection and _unique_method_projection."""
        if method.multiple_success_codes or not method.exceptions_permitted:
            # If we aren't allowed exceptions, or have some extra success results,
            # we always have to return the Result.
            if method.bare_return_type == "void":
                method.return_type = "Result"
                method.return_statement = 'return {};'.format(method.returns[0])
            else:
                method.return_type = "ResultValue<{}>".format(method.bare_return_type)
                method.return_statement = 'return { %s, std::move(%s) };' % (method.returns[0], method.returns[1])
        else:
            # OK, we will throw an exception if allowed and just directly return the output.
            method.explicit_result_elided = True
            method.return_type = method.bare_return_type
            if method.bare_return_type == "void":
                method.return_statement = 'return;'
            else:
                method.return_statement = 'return {};'.format(method.returns[1])

        if method.return_template_params:
            # tmpl = "<{}>".format(",".join(method.return_template_params))
            return_val = "{}({})".format(method.bare_return_type, ", ".join(method.returns[1:]))
            if method.multiple_success_codes or not method.exceptions_permitted:
                method.return_statement = 'return { %s, %s };' % (method.returns[0], return_val)
            else:
                method.return_statement = 'return %s;' % return_val
        # method.return_statement = 'return impl::createResultValue{tmpl}({rets}, OPENXR_HPP_NAMESPACE_STRING "::{name}"{successes});'.format(
        #     tmpl=tmpl,
        #     rets=",".join(method.returns),
        #     name=method.qualified_name, successes=method.successes_arg)
        # else:
        #     tmpl = ""

    def _is_tagged_type(self, typename):
        if typename not in self.dict_structs:
            return False
        return any((x.name == "type" for x in self.dict_structs[typename].members))

    def _get_tag(self, typename):
        if typename not in self.dict_structs:
            return None
        tag_member = [x for x in self.dict_structs[typename].members
                      if x.name == "type"]
        if not tag_member:
            return None
        raw_tag = tag_member[0].values
        if not raw_tag:
            return None
        return "StructureType::" + self.createEnumValue(raw_tag, "XrStructureType")

    def _enhanced_method_detect_twocall(self, method):
        # Find the three important parameters
        capacity_input_param_name = None
        count_output_param_name = None
        array_param_name = None
        for i, p in enumerate(method.decl_params):
            if p.no_auto_validity:
                continue
            param_name = p.name
            match = CAPACITY_INPUT_RE.match(param_name)
            if match:
                capacity_input_param_name = param_name
                continue
            match = COUNT_OUTPUT_RE.match(param_name)
            if match:
                count_output_param_name = param_name
                continue

            # Try detecting the output array using its length field
            if capacity_input_param_name is not None \
                    and p.pointer_count_var == capacity_input_param_name:
                array_param_name = param_name

        return capacity_input_param_name and count_output_param_name and array_param_name

    def _enhanced_method_projection_twocall(self, method):
        # Find the three important parameters
        capacity_input_param = None
        capacity_input_param_name = None
        count_output_param = None
        count_output_param_name = None
        array_param = None
        array_param_name = None
        for i, p in enumerate(method.decl_params):
            if p.no_auto_validity:
                continue
            param_name = p.name
            match = CAPACITY_INPUT_RE.match(param_name)
            if match:
                capacity_input_param = {
                    "param": p,
                    "index": i,
                    "match": match
                }
                capacity_input_param_name = param_name
                continue
            match = COUNT_OUTPUT_RE.match(param_name)
            if match:
                count_output_param = {
                    "param": p,
                    "index": i,
                    "match": match
                }
                count_output_param_name = param_name
                continue

            # Try detecting the output array using its length field
            if capacity_input_param_name is not None \
                    and p.pointer_count_var == capacity_input_param_name:
                array_param = {
                    "param": p,
                    "index": i,
                    "match": match
                }
                array_param_name = param_name

        if not capacity_input_param_name or \
                not count_output_param_name or \
                not array_param_name:
            # If we're missing at least one, stop checking two-call stuff here.
            return False

        method.is_two_call = True
        method.masks_simple = False
        # Should we put "ToVector" on the method name?
        needs_name_decoration = True
        item_type = array_param['param'].type
        method.item_type = item_type

        item_type_cpp = _project_type_name(item_type)
        method.item_type_cpp = item_type_cpp
        templated = method.name in TEMPLATED_TWO_CALL
        method.templated = templated

        vector_member_type = item_type_cpp
        if templated:
            vector_member_type = 'ResultItemType'

        vec_type = "std::vector<{}, Allocator>".format(vector_member_type)
        method.vec_type = vec_type
        method.template_decl_list.insert(0, "typename Allocator = std::allocator<{}>".format(vector_member_type))
        method.template_defn_list.insert(0, "typename Allocator")

        if templated:
            method.template_decl_list.insert(0, "typename ResultItemType")
            method.template_defn_list.insert(0, "typename ResultItemType")

        method.capacity_input_param_name = capacity_input_param_name
        method.count_output_param_name = count_output_param_name
        method.array_param_name = array_param_name
        method.capacity_input_param = capacity_input_param
        method.count_output_param = count_output_param
        method.array_param = array_param

        method.decl_dict[capacity_input_param_name] = None
        method.decl_dict[count_output_param_name] = None
        method.decl_dict[array_param_name] = None

        method.access_dict[count_output_param_name] = "&" + count_output_param_name

        if item_type == "char":
            method.bare_return_type = "string_with_allocator<Allocator>"
            method.return_constructor = method.bare_return_type + "{%s.begin(), %s.end(), vectorAllocator}" % (array_param_name, array_param_name)
            method.returns.append("str")
            needs_name_decoration = False
        else:
            method.bare_return_type = vec_type
            method.return_constructor = array_param_name
            method.returns.append(array_param_name)

        if needs_name_decoration:
            self._append_to_method_name_before_vendor(method, "ToVector")
        self._update_enhanced_return_type(method)

    def _method_has_single_output(self, method):
        if len(method.get_success_codes()) > 1:
            return False

        last_param = method.params[-1]
        if last_param.is_const or last_param.pointer_count != 1 or last_param.array_count_var != '':
            return False

        # Do not return a single output of a type we aren't projecting
        if last_param.type in SKIP_PROJECTION:
            return False

        for param in method.params[:-1]:
            if param.is_handle:
                continue
            if param.pointer_count > 0 and not param.is_const:
                return False

        if not self.quiet:
            print("method " + method.name + " has output parameter " + last_param.name + " of type " + last_param.type)
        return True

    def _enhanced_method_projection(self, method):
        """Perform the manipulation of a MethodProjection to convert it from C to C++ for "enhanced mode"."""
        method.masks_simple = True
        self._basic_method_projection(method)
        method.bare_return_type = "void"
        successes = method.get_success_codes()
        method.multiple_success_codes = len(successes) > 1

        if len(successes) > 1:
            method.successes_arg = ", {%s}" % (", ".join(successes))
        else:
            method.successes_arg = ""

        outhandles = [x for x in reversed(method.decl_params)
                      if x.is_handle and x.pointer_count]

        if method.is_create and len(outhandles) != 1:
            # This isn't really a create from our point of view
            method.is_create = False

        if method.is_create:
            method.masks_simple = False
            outparam = outhandles[0]
            cpp_outtype = _project_type_name(outparam.type)
            method.bare_return_type = cpp_outtype

            # Filter out the one we're returning.
            method.decl_params = [x for x in method.decl_params
                                  if x != outparam]
            method.decl_dict[outparam.name] = None
            method.pre_statements.append("{} handle;".format(cpp_outtype))
            method.access_dict[outparam.name] = "handle.put()"
            method.returns.append("handle")
        elif method.is_destroy:
            # Clear the handle
            method.post_statements.append("val_ = XR_NULL_HANDLE;")

        elif self._method_has_single_output(method):
            method.masks_simple = False
            outparam = method.decl_params[-1]
            cpp_outtype = _project_type_name(outparam.type)
            method.bare_return_type = cpp_outtype

            method.decl_params.pop()
            method.decl_dict[outparam.name] = None
            method.pre_statements.append("{} returnVal;".format(cpp_outtype))
            if outparam.type in self.projected_types:
                method.access_dict[outparam.name] = "OPENXR_HPP_NAMESPACE::put(returnVal)"
            else:
                method.access_dict[outparam.name] = "&returnVal"
            method.returns.append("returnVal")

        self._update_enhanced_return_type(method)

        # Look for two-call
        if self._enhanced_method_projection_twocall(method):
            # No further enhancements.
            return

    def _unique_method_projection(self, method):
        """Perform the manipulation of a MethodProjection for a creation function to convert it from C to C++ returning a UniqueHandle."""

        self._enhanced_method_projection(method)
        self._append_to_method_name_before_vendor(method, "Unique")

        method.returns.append("deleter")

        method.return_template_params = [method.bare_return_type, "impl::RemoveRefConst<Dispatch>"]
        method.post_statements.append('ObjectDestroy<impl::RemoveRefConst<Dispatch>> deleter{d};')
        method.handle_return_type = method.bare_return_type
        method.bare_return_type = "UniqueHandle<{}, impl::RemoveRefConst<Dispatch>>".format(method.bare_return_type)
        # method.returns[1] = "{}({}, {})"
        self._update_enhanced_return_type(method)

    def _append_to_method_name_before_vendor(self, method, s):
        "Append a string to the end of the cpp_name of a method, but before any vendor suffix."
        vendor = self.findVendorSuffix(method.cpp_name)
        if vendor:
            # Keep the vendor suffix on the end.
            method.cpp_name = _strip_suffix(method.cpp_name, vendor)
        method.cpp_name += s
        if vendor:
            method.cpp_name += vendor

    def outputGeneratedHeaderWarning(self):
        # File Comment
        generated_warning = '// *********** THIS FILE IS GENERATED - DO NOT EDIT ***********\n'
        generated_warning += '//     See cpp_generator.py for modifications\n'
        generated_warning += '// ************************************************************\n'
        assert(self.createEnumValue("XR_TYPE_SPATIAL_ANCHOR_SPACE_CREATE_INFO_MSFT", "XrStructureType")
               == "SpatialAnchorSpaceCreateInfoMSFT")
        assert(self.createEnumValue("XR_PERF_SETTINGS_SUB_DOMAIN_COMPOSITING_EXT", "XrPerfSettingsSubDomainEXT")
               == "Compositing")
        write(generated_warning, file=self.outFile)

    # Call the base class to properly begin the file, and then add
    # the file-specific header information.
    #   self            the ConformanceLayerHeaderGenerator object
    #   gen_opts        the ConformanceLayerHeaderGeneratorOptions object
    def beginFile(self, genOpts):
        AutomaticSourceOutputGenerator.beginFile(self, genOpts)
        self.conventions = self.genOpts.conventions
        self.env.globals['filename'] = genOpts.filename
        self.env.tests['cpp_hidden_member'] = self._cpp_hidden_member
        self.env.tests['struct_output'] = self._is_struct_output
        self.env.tests['struct_input'] = self._is_struct_input
        self.template = JinjaTemplate(
            self.env, "template_{}".format(genOpts.filename))

    def extensionReturnCodesForCommand(self, cur_cmd):
        return (x for x
                in self.registry.commandextensionerrors + self.registry.commandextensionsuccesses
                if x.command == cur_cmd.name)

    def allReturnCodesForCommand(self, cur_cmd):
        return cur_cmd.return_values + list(self.extensionReturnCodesForCommand(cur_cmd))

    def _is_base_only(self, struct):
        if not struct:
            return False
        tag_member = [x for x in struct.members if x.name == "type"]
        if not tag_member:
            return False
        return tag_member[0].values is None

    def _cpp_hidden_member(self, member):
        return member.name == "type" or member.name == "next"

    def _struct_member_count(self, struct):
        return len(struct.members)

    def _bitmask_for_flags(self, flags):
        return self.dict_bitmasks[flags.valid_flags]

    def _is_struct_input(self, struct):
        nextptr = [x.cdecl for x in struct.members
                   if x.name == 'next']
        return nextptr and 'const' in nextptr[0]

    def _is_struct_output(self, struct):
        if struct.returned_only:
            return True
        nextptr = [x.cdecl for x in struct.members
                   if x.name == 'next']
        if not nextptr:
            return False
        return 'const' not in nextptr[0]

    def _is_member_defaultable(self, member):
        if member.pointer_count > 0 or (member.type == 'char' and member.is_array):
            return True
        if self._is_type_defaultable(member.type):
            return True
        return False

    def _get_default_for_member(self, member, struct_name=None, default_val="{}"):
        defaultValue = default_val
        if member.pointer_count > 0 or (member.type == 'char' and member.is_array):
            defaultValue = "nullptr"
        elif member.type.startswith("uint") or member.type.startswith("int"):
            defaultValue = "0"
        elif member.type.startswith("float"):
            # special case XrQuaternionf::w so a default constructor xr::Quaternionf is an identity
            if struct_name == 'XrQuaternionf' and member.name == 'w':
                defaultValue = '1.0f'
            else:
                defaultValue = '0.0f'
        elif member.type == "XrBool32":
            defaultValue = "false"
        elif not self._is_tagged_type(member.type):
            defaultValue = default_val
        elif member.type in self.dict_structs:
            member_struct = self.dict_structs[member.type]
            if self._is_struct_output(member_struct):
                defaultValue = default_val
        else:
            defaultValue = default_val
        return defaultValue

    def _is_type_defaultable(self, typename: str):
        if typename.startswith("uint") or typename.startswith("int") or typename.startswith("float"):
            return True
        if typename == "XrBool32":
            return True
        if typename in self.dict_atoms:
            return self.computeNullAtom(typename) is not None
        if self._is_tagged_type(typename):
            tag = self._get_tag(typename)

            if tag is None:
                return False
            member_struct = self.dict_structs[typename]
            if self._is_struct_output(member_struct):
                return True

            for member in tuple(x for x in member_struct.members if not self._cpp_hidden_member(x)):
                if not self._is_member_defaultable(member):
                    return False

            return True
        return True

    def _index0_of_first_visible_defaultable_member(self, members):
        for i, member in reversed(tuple(enumerate(x for x in members if not self._cpp_hidden_member(x)))):
            if not self._is_member_defaultable(member):
                raise RuntimeError("Found a non-defaultable member, errors possible elsewhere due to untested codepath.")
                return i + 1
        return 0

    def _project_cppdecl(self, struct, member, defaulted=False, suffix="", input=False):
        result = member.cdecl.strip()
        if "[" in result:
            # Insert the suffix before the array decl
            pos = result.find("[")
            result = result[:pos] + suffix + result[pos:]
        else:
            result += suffix
        # Kind of hacky, perhaps switch _project_type_name to a regex based approach?
        if (member.is_const):
            result = _strip_prefix(result, "const").strip()
        if member.type.startswith("Xr"):
            result = _project_type_name(result)
        if (member.is_const):
            result = "const " + result

        if input:
            if member.type == 'char' and member.is_array and member.pointer_count == 0:
                # We'll initialize a fixed-size string with a cstring.
                result = "const char* " + member.name + suffix
            elif member.type.startswith("Xr") and member.pointer_count == 0:
                result = "const " + _project_type_name(member.type) + "& " + member.name + suffix

        if defaulted:
            defaultValue = self._get_default_for_member(member, struct.name)
            result = result + " = " + defaultValue
        return result

    def requires_platform_header(self, entity):
        if not hasattr(entity, "extname"):
            return False
        extname = entity.extname
        if self.isCoreExtensionName(extname):
            return False
        return self.dict_extensions[extname].protect_value is not None

    # Write out all the information for the appropriate file,
    # and then call down to the base class to wrap everything up.
    #   self            the ConformanceLayerBaseGenerator object
    def endFile(self):
        sorted_cmds = self.core_commands + self.ext_commands

        self.dict_extensions = {}
        for ext in self.extensions:
            self.dict_extensions[ext.name] = ext

        self.dict_handles = {}
        for handle in self.api_handles:
            self.dict_handles[handle.name] = handle

        self.dict_enums = {}
        for enum in self.api_enums:
            self.dict_enums[enum.name] = enum
            if enum.name == 'XrResult':
                result_enum = enum

        self.dict_structs = {}
        for struct in self.api_structures:
            self.dict_structs[struct.name] = struct

        self.dict_bitmasks = {}
        for bitmask in self.api_bitmasks:
            self.dict_bitmasks[bitmask.name] = bitmask

        self.dict_atoms = {}
        for basetype in self.api_base_types:
            if basetype.type == "XR_DEFINE_ATOM":
                self.dict_atoms[basetype.name] = basetype

        self.projected_types = MANUALLY_PROJECTED.union(self.dict_handles.keys())
        self.projected_types.update(self.dict_enums.keys())
        self.projected_types.update(self.dict_structs.keys())
        self.projected_types.update(self.dict_bitmasks.keys())
        self.projected_types.update(self.dict_atoms.keys())
        self.projected_types.difference_update(SKIP_PROJECTION)

        # Every type mentioned in some other type's parentstruct attribute.
        struct_parents = ((otherType, otherType.elem.get('parentstruct'))
                          for otherType in self.registry.typedict.values())
        self.struct_parents = {child.elem.get('name'): parent for child, parent in struct_parents
                               if parent is not None}
        self.parents = set(self.struct_parents.values())

        self.skip_projection = SKIP_PROJECTION

        def children_of(t):
            return set(child for child, parent in self.struct_parents.items() if parent == t)

        self.struct_children = {parent: children_of(parent) for parent in self.parents}

        def fields_of(t):
            struct = self.dict_structs[t]
            members = struct.members
            return set(field.name for field in members if not self._cpp_hidden_member(field))

        self.struct_fields = {parent: fields_of(parent) for parent in self.parents
                              if parent in self.dict_structs}

        basic_cmds = {}
        enhanced_cmds = {}
        enhanced_cmds_no_exceptions = {}
        unique_cmds = {}
        unique_cmds_no_exceptions = {}
        for cmd in sorted_cmds:
            basic = MethodProjection(cmd, self)
            self._basic_method_projection(basic)
            basic_cmds[cmd.name] = basic

            enhanced = MethodProjection(cmd, self)
            self._enhanced_method_projection(enhanced)
            enhanced_cmds[cmd.name] = enhanced
            if enhanced.explicit_result_elided:

                # Now try again to make one without exceptions.
                enhanced_noexcept = MethodProjection(cmd, self)
                enhanced_noexcept.exceptions_permitted = False
                self._enhanced_method_projection(enhanced_noexcept)
                enhanced_cmds_no_exceptions[cmd.name] = enhanced_noexcept

            if enhanced.is_create:
                unique = MethodProjection(cmd, self)
                self._unique_method_projection(unique)
                unique_cmds[cmd.name] = unique

                # Now try again to make one without exceptions,
                if unique.explicit_result_elided:
                    # all creation calls can elide the result.
                    unique_noexcept = MethodProjection(cmd, self)
                    unique_noexcept.exceptions_permitted = False
                    self._unique_method_projection(unique_noexcept)
                    unique_cmds_no_exceptions[cmd.name] = unique_noexcept
                else:
                    # assumption violated
                    assert(False)
        # Verify
        self.selftests()

        file_data = self.template.render(
            gen=self,
            registry=self.registry,
            null_instance_ok=VALID_FOR_NULL_INSTANCE,
            sorted_cmds=sorted_cmds,
            create_enum_value=self.createEnumValue,
            create_flag_value=self.createFlagValue,
            project_type_name=_project_type_name,
            result_enum=result_enum,
            create_enum_exception=self.createEnumException,
            basic_cmds=basic_cmds,
            enhanced_cmds=enhanced_cmds,
            enhanced_cmds_no_exceptions=enhanced_cmds_no_exceptions,
            unique_cmds=unique_cmds,
            unique_cmds_no_exceptions=unique_cmds_no_exceptions,
            discouraged_begin=_discouraged_begin,
            discouraged_end=_discouraged_end,
            generate_structure_type_from_name=self.conventions.generate_structure_type_from_name,
            is_tagged_type=self._is_tagged_type,
            project_cppdecl=self._project_cppdecl,
            bitmask_for_flags=self._bitmask_for_flags,
            is_static_length_array=_is_static_length_array,
            is_static_length_string=_is_static_length_string,
            struct_parents=self.struct_parents,
            struct_children=self.struct_children,
            struct_fields=self.struct_fields,
            project_struct=(lambda s: StructProjection(s, self)),
            get_default_for_member=self._get_default_for_member,
            index0_of_first_visible_defaultable_member=self._index0_of_first_visible_defaultable_member,
            manually_projected=MANUALLY_PROJECTED,
            skip=SKIP,
        )
        write(file_data, file=self.outFile)

        # Finish processing in superclass
        AutomaticSourceOutputGenerator.endFile(self)

    def selftests(self):
        assert(self._is_struct_input(self.dict_structs['XrCompositionLayerProjection']))
        assert(self._is_struct_input(self.dict_structs['XrCompositionLayerBaseHeader']))
        assert(not self._is_struct_input(self.dict_structs['XrApplicationInfo']))
        assert(not self._is_struct_output(self.dict_structs['XrApplicationInfo']))
        # index = self._index0_of_first_visible_defaultable_member(self.dict_structs['XrApplicationInfo'].members)
        # print(index)
        assert(self._index0_of_first_visible_defaultable_member(self.dict_structs['XrApplicationInfo'].members) == 0)
        # index = self._index0_of_first_visible_defaultable_member(self.dict_structs['XrInstanceCreateInfo'].members)
        # print(index)
        # assert(self._index0_of_first_visible_defaultable_member(self.dict_structs['XrInstanceCreateInfo'].members) == 0)
        # members = self.dict_structs['XrInstanceCreateInfo'].members
        # for i, member in enumerate(members):
        #     print(i, member.name, self._is_member_defaultable(member))
