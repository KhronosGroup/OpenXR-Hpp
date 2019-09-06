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


from automatic_source_generator import AutomaticSourceOutputGenerator, write
from jinja_helpers import JinjaTemplate, make_jinja_environment

VALID_FOR_NULL_INSTANCE = set((
    'xrEnumerateInstanceExtensionProperties',
    'xrEnumerateApiLayerProperties',
    'xrCreateInstance'
))


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

        self.dispatch = "Dispatch&& d"
        self.decl_dispatch = self.dispatch
        if self.is_core:
            self.decl_dispatch += " = Dispatch()"

        self.dispatch_type_default = " = DispatchLoaderStatic" if self.is_core else ""

    def _declparams(self):
        params = (self.decl_dict[param.name] for param in self.params)
        params = [x for x in params if x is not None]
        return params

    def get_declaration_params(self):
        params = self._declparams()
        params.append(self.decl_dispatch)
        return params

    def get_definition_params(self):
        params = self._declparams()
        params.append(self.dispatch)
        return params

    def get_invocation(self, custom_return=None):
        lines = self.pre_statements[:]
        invocation_params = (self.access_dict[param.name] for param in self.params)
        main_invoke = "Result result = static_cast<Result>( d.{}({}) );".format(
            self.name, ", ".join(invocation_params)
        )
        lines.append(main_invoke)
        lines.extend(self.post_statements)
        lines.append(custom_return if custom_return else self.return_statement)
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
        pass

    def outputCopywriteHeader(self):
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

    def _update_enhanced_return_type(self, method):
        if method.successes_arg:
            if method.bare_return_type == "void":
                method.return_type = "Result"
            else:
                method.return_type = "ResultValue<{}>".format(method.bare_return_type)
        else:
            method.return_type = "ResultValueType<{}>::type".format(method.bare_return_type)
            if method.bare_return_type != "void":
                method.return_type = "typename " + method.return_type

    def _enhanced_method_projection(self, method):
        method.masks_simple = True
        self._basic_method_projection(method)
        method.bare_return_type = "void"
        successes = method.get_success_codes()
        if len(successes) > 1:
            method.successes_arg = ", {%s}" % (", ".join(successes))
        else:
            method.successes_arg = ""

        method.return_statement = 'return createResultValue(result, OPENXR_HPP_NAMESPACE_STRING "::{}"{});'.format(
            method.qualified_name, method.successes_arg)

        if method.is_create:
            method.masks_simple = False
            outparam = method.decl_params[-1]
            cpp_outtype = _project_type_name(outparam.type)
            method.bare_return_type = cpp_outtype

            method.decl_params.pop()
            method.decl_dict[outparam.name] = None
            method.pre_statements.append("{} handle;".format(cpp_outtype))
            method.access_dict[outparam.name] = "handle.put()"
            method.return_statement = method.return_statement.replace("result,", "result, handle,")
        self._update_enhanced_return_type(method)

    def _unique_method_projection(self, method):

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

        method.post_statements.append('ObjectDestroy<Dispatch> deleter{d};')
        method.return_statement = 'return createResultValue<{}, Dispatch>(result, handle, OPENXR_HPP_NAMESPACE_STRING "::{}", deleter{});'.format(
            method.bare_return_type,
            method.qualified_name,
            method.successes_arg)
        method.bare_return_type = "UniqueHandle<{}, Dispatch>".format(method.bare_return_type)
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
            unique_cmds=unique_cmds

        )
        write(file_data, file=self.outFile)

        # Finish processing in superclass
        AutomaticSourceOutputGenerator.endFile(self)
