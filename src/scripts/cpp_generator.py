#!/usr/bin/python3 -i
#
# Copyright (c) 2017-2019 The Khronos Group Inc.
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
    'xrCreateInstance'
))

DISCOURAGED = set((
    'xrResultToString',
    'xrStructureTypeToString',
))

SUPPRESS_TWO_CALL = set([
    'xrEnumerateSwapchainImages'
])

TWO_CALL_STRING_NAME = "buffer"

CAPACITY_INPUT_RE = re.compile(r'(?P<itemname>[a-z]*)CapacityInput')
COUNT_OUTPUT_RE = re.compile(r'(?P<itemname>[a-z]*)CountOutput')


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
    keep_upper = True
    for c in val:
        if c == '_':
            keep_upper = True
        elif str.isdigit(c):
            keep_upper = True
            chars.append(c)
        elif keep_upper:
            chars.append(c)
            keep_upper = False
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


RULE_BREAKING_ENUMS = {
    'XrResult': 'XR',
    'XrStructureType': 'XR_TYPE',
}


# def _make_dummy_param(name, typename, cdecl):
#     return MemberOrParam(typename, False, True, False, False, False, 0, False, [], None, None, 0, None, False, True, name, None, cdecl)


class MethodProjection:
    """Stores the method declaration and implementation."""

    def __init__(self, cmd, gen):
        self.cmd = cmd
        self.conventions = gen.genOpts.conventions
        self.name = cmd.name
        self.cpp_name = _member_function_name(cmd.name)
        self.qualified_name = self.cpp_name
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
        self.access_dict = {x.name: x.name.strip() for x in self.params}

        self.return_type = "Result"
        self.bare_return_type = self.return_type

        self.return_codes = cmd.return_values[:]
        self.cpp_return_codes = ['Result::' + gen.createEnumValue(x, 'XrResult')
                                 for x in self.return_codes]

        self.return_statement = "return result;"
        self.pre_statements = []
        self.post_statements = []

        self.masks_simple = False

        self.returns = ['result']
        self.return_template_params = []

        self.dispatch = "Dispatch&& d"
        self.suppress_default_dispatch_arg = not self.is_core
        self.template_decl_list = ["typename Dispatch"]
        self.template_defn_list = self.template_decl_list[:]
        if self.is_core:
            self.template_decl_list[0] = self.template_decl_list[0] + " = DispatchLoaderStatic"

    def _declparams(self, replacements=None):
        def find_decl(name):
            if replacements and name in replacements:
                return replacements.get(name)
            return self.decl_dict.get(name)
        params = (find_decl(param.name) for param in self.decl_params)
        params = [x for x in params if x is not None]
        return params

    @property
    def template_decls(self):
        return ", ".join(self.template_decl_list)

    @property
    def template_defns(self):
        return ", ".join(self.template_defn_list)

    def get_declaration_params(self, replacements=None, extras=None, suppress_default_dispatch_arg=False):
        params = self._declparams(replacements)
        if extras:
            params.extend(extras)

        params.append(self.dispatch)
        if not self.suppress_default_dispatch_arg \
                and not suppress_default_dispatch_arg:
            params[-1] = params[-1] + " = Dispatch{}"
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
        return [x for x in self.cpp_return_codes if "Error" not in x]

    @property
    def qualifiers(self):
        if self.handle:
            return "const"
        return ""


class CppGenerator(AutomaticSourceOutputGenerator):
    """Generate C++ wrapper header using XML element attributes from registry"""

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.env = make_jinja_environment(file_with_templates_as_sibs=__file__)

    def outputGeneratedAuthorNote(self):
        # Disabled
        pass

    def outputCopywriteHeader(self):
        # Disabled - there is one in the template.
        pass

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

    def createEnumException(self, name):
        enum_val = self.createEnumValue(name, 'XrResult')
        return enum_val.replace('Error', '') + 'Error'

    def _basic_method_projection(self, method):
        """Perform the basic manipulation of a MethodProjection to convert it from C to C++."""
        # Free function to method
        if method.handle:
            handle = method.params[0]
            method.decl_params.pop(0)
            method.decl_dict[handle.name] = None
            method.access_dict[handle.name] = "this->get()"
            # if method.cpp_name.endswith(method.cpp_handle):
            #     method.cpp_name = _strip_suffix(method.cpp_name, method.cpp_handle)
            method.qualified_name = "{}::{}".format(method.cpp_handle, method.cpp_name)

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
                elif param.pointer_count == 1:
                    # Output enum
                    method.decl_dict[name] = "{}& {}".format(
                        cpp_type, name)
                    method.pre_statements.append(
                        "{} {}_tmp;".format(param.type, name.strip()))
                    method.access_dict[name] = "{}_tmp".format(name.strip())
                    method.post_statements.append(
                        "{name} = static_cast<{t}>({name}_tmp);".format(name=name.strip(), t=cpp_type))

    def _update_enhanced_return_type(self, method):
        """Set the return type based on the bare return type.

        Used by _enhanced_method_projection and _unique_method_projection."""
        if method.successes_arg:
            if method.bare_return_type == "void":
                method.return_type = "Result"
            else:
                method.return_type = "ResultValue<{}>".format(method.bare_return_type)
        else:
            method.return_type = "ResultValueType<{}>::type".format(method.bare_return_type)
            if method.bare_return_type != "void":
                method.return_type = "typename " + method.return_type

        if method.return_template_params:
            tmpl = "<{}>".format(",".join(method.return_template_params))
        else:
            tmpl = ""
        method.return_statement = 'return createResultValue{tmpl}({rets}, OPENXR_HPP_NAMESPACE_STRING "::{name}"{successes});'.format(
            tmpl=tmpl,
            rets=",".join(method.returns),
            name=method.qualified_name, successes=method.successes_arg)

    def _is_tagged_type(self, typename):
        if typename not in self.dict_structs:
            return False
        return any((x.name == "type" for x in self.dict_structs[typename].members))

    def _enhanced_method_projection_twocall(self, method):
        if method.name in SUPPRESS_TWO_CALL:
            return False
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
        item_type = array_param['param'].type
        method.item_type = item_type

        item_type_cpp = item_type
        if item_type in self.dict_enums:
            item_type_cpp = _project_type_name(item_type)
        method.item_type_cpp = item_type_cpp

        vec_type = "::std::vector<{}, Allocator>".format(item_type_cpp)
        method.vec_type = vec_type
        method.template_decl_list.insert(0, "typename Allocator = ::std::allocator<{}>".format(item_type_cpp))
        method.template_defn_list.insert(0, "typename Allocator")

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
            method.bare_return_type = "::std::basic_string<char, ::std::char_traits<char>, Allocator>"
            method.return_constructor = method.bare_return_type + "{%s.begin(), %s.end(), vectorAllocator}" % (array_param_name, array_param_name)
            method.returns.append("str")
        else:
            method.bare_return_type = vec_type
            method.return_constructor = array_param_name
            method.returns.append(array_param_name)
        self._update_enhanced_return_type(method)

        print(method.name, "is a two-call")

    def _enhanced_method_projection(self, method):
        """Perform the manipulation of a MethodProjection to convert it from C to C++ for "enhanced mode"."""
        method.masks_simple = True
        self._basic_method_projection(method)
        method.bare_return_type = "void"
        successes = method.get_success_codes()
        if len(successes) > 1:
            method.successes_arg = ", {%s}" % (", ".join(successes))
        else:
            method.successes_arg = ""

        if method.is_create:
            method.masks_simple = False
            outparam = method.decl_params[-1]
            cpp_outtype = _project_type_name(outparam.type)
            method.bare_return_type = cpp_outtype

            method.decl_params.pop()
            method.decl_dict[outparam.name] = None
            method.pre_statements.append("{} handle;".format(cpp_outtype))
            method.access_dict[outparam.name] = "handle.put()"
            method.returns.append("handle")
        self._update_enhanced_return_type(method)

        # Look for two-call
        if self._enhanced_method_projection_twocall(method):
                # No further enhancements.
            return

    def _unique_method_projection(self, method):
        """Perform the manipulation of a MethodProjection for a creation function to convert it from C to C++ returning a UniqueHandle."""

        self._enhanced_method_projection(method)
        vendor = self.findVendorSuffix(method.cpp_name)
        if vendor:
            # Keep the vendor suffix on the end.
            method.cpp_name = _strip_suffix(method.cpp_name, vendor)
        method.cpp_name += "Unique"
        if vendor:
            method.cpp_name += vendor
        if method.handle:
            method.qualified_name = "{}::{}".format(method.cpp_handle, method.cpp_name)
        else:
            method.qualified_name = method.cpp_name

        method.returns.append("deleter")
        method.return_template_params = [method.bare_return_type, "impl::RemoveRefConst<Dispatch>"]
        method.post_statements.append('ObjectDestroy<impl::RemoveRefConst<Dispatch>> deleter{d};')
        method.bare_return_type = "UniqueHandle<{}, impl::RemoveRefConst<Dispatch>>".format(method.bare_return_type)
        self._update_enhanced_return_type(method)

    def outputGeneratedHeaderWarning(self):
        # File Comment
        generated_warning = '// *********** THIS FILE IS GENERATED - DO NOT EDIT ***********\n'
        generated_warning += '//     See cpp_generator.py for modifications\n'
        generated_warning += '// ************************************************************\n'
        assert(self.createEnumValue("XR_TYPE_SPATIAL_ANCHOR_SPACE_CREATE_INFO_MSFT", "XrStructureType") ==
               "SpatialAnchorSpaceCreateInfoMSFT")
        assert(self.createEnumValue("XR_PERF_SETTINGS_SUB_DOMAIN_COMPOSITING_EXT", "XrPerfSettingsSubDomainEXT") ==
               "Compositing")
        write(generated_warning, file=self.outFile)

    # Call the base class to properly begin the file, and then add
    # the file-specific header information.
    #   self            the ConformanceLayerHeaderGenerator object
    #   gen_opts        the ConformanceLayerHeaderGeneratorOptions object
    def beginFile(self, genOpts):
        AutomaticSourceOutputGenerator.beginFile(self, genOpts)
        self.conventions = self.genOpts.conventions
        self.template = JinjaTemplate(
            self.env, "template_{}".format(genOpts.filename))

    def extensionReturnCodesForCommand(self, cur_cmd):
        return (x for x
                in self.registry.commandextensionerrors + self.registry.commandextensionsuccesses
                if x.command == cur_cmd.name)

    def allReturnCodesForCommand(self, cur_cmd):
        return cur_cmd.return_values + list(self.extensionReturnCodesForCommand(cur_cmd))

    # Write out all the information for the appropriate file,
    # and then call down to the base class to wrap everything up.
    #   self            the ConformanceLayerBaseGenerator object
    def endFile(self):
        sorted_cmds = self.core_commands + self.ext_commands

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

        basic_cmds = {}
        enhanced_cmds = {}
        unique_cmds = {}
        for cmd in sorted_cmds:
            basic = MethodProjection(cmd, self)
            self._basic_method_projection(basic)
            basic_cmds[cmd.name] = basic

            enhanced = MethodProjection(cmd, self)
            self._enhanced_method_projection(enhanced)
            enhanced_cmds[cmd.name] = enhanced

            if enhanced.is_create:
                unique = MethodProjection(cmd, self)
                self._unique_method_projection(unique)
                unique_cmds[cmd.name] = unique

        file_data = self.template.render(
            gen=self,
            registry=self.registry,
            null_instance_ok=VALID_FOR_NULL_INSTANCE,
            sorted_cmds=sorted_cmds,
            create_enum_value=self.createEnumValue,
            project_type_name=_project_type_name,
            result_enum=result_enum,
            create_enum_exception=self.createEnumException,
            basic_cmds=basic_cmds,
            enhanced_cmds=enhanced_cmds,
            unique_cmds=unique_cmds,
            discouraged_begin=_discouraged_begin,
            discouraged_end=_discouraged_end,
            generate_structure_type_from_name=self.conventions.generate_structure_type_from_name,
            is_tagged_type=self._is_tagged_type
        )
        write(file_data, file=self.outFile)

        # Finish processing in superclass
        AutomaticSourceOutputGenerator.endFile(self)
