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


class MemberParamProjection:
    """Converting to/from the C++ projection of OpenXR for a member or parameter."""

    def __init__(self, name, declaration, get, put=None):
        self.name = name
        self.decl = declaration
        self.get_val = get
        self.put_val = put

    def declaration(self):
        return self.decl

    def get_convert_from(self, struct_access=None):
        """Get the code to retrieve the value(s) and convert to native C format."""
        if struct_access:
            return self.get_val.replace(self.name, struct_access + self.name)
        return self.get_val

    # def get_convert_to(self, struct_access=None):
    #     """Get the code to retrieve the value(s) and convert to native C format."""
    #     if struct_access:
    #         return self.get_val.replace(self.name, struct_access + self.name)
    #     return self.get_val


def _member_function_name(cmdname):
    base = cmdname[2].lower() + cmdname[3:]
    if base.startswith('destroy'):
        return 'destroy'
    return base


def _member_function_params(cmd):
    return [x.cdecl.strip() for x in cmd.params[1:]]


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


def _simple_project_typename(typename):
    return _strip_suffix(typename, "Xr")


RULE_BREAKING_ENUMS = {
    'XrResult': 'XR',
    'XrStructureType': 'XR_TYPE',
}


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
            prefix = self.genOpts.conventions.generate_structure_type_from_name(typename).replace('XR_TYPE', 'XR')
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

    def filter_for_success_codes(self, return_codes):
        return ['Result::' + self.createEnumValue(x, 'XrResult')
                for x in return_codes
                if not x.startswith('XR_ERROR')]

    def createEnumException(self, name):
        enum_val = self.createEnumValue(name, 'XrResult')
        return enum_val.replace('Error', '') + 'Error'

    def projectTypeName(self, typename):
        return typename.replace('Xr', '')

    def projectParam(self, param, context):
        """Return a tuple of the argument declaration and the argument usage."""
        if param.is_bool:
            return MemberParamProjection(param.name,
                                         "bool {}".format(param.name),
                                         "({} ? XR_TRUE : XR_FALSE)".format(param.name))
        if param.type in self.dict_handles:
            decl = param.cdecl.replace(param.type, self.projectTypeName(param.type)).strip()
            if context.is_create_connect and param.pointer_count and not param.is_const:
                return MemberParamProjection(param.name,
                                             decl,
                                             "OPENXR_HPP_NAMESPACE::put({})".format(param.name))

            return MemberParamProjection(param.name,
                                         decl,
                                         "OPENXR_HPP_NAMESPACE::get({})".format(param.name))

        return MemberParamProjection(param.name,
                                     param.cdecl.strip(),
                                     param.name.strip())

    def projectParamsForDeclaration(self, cur_cmd, enhanced=False):
        param_string = self.projectParamsForDefinition(cur_cmd, enhanced=enhanced)
        if self.isCoreExtensionName(cur_cmd.ext_name):
            param_string += " = Dispatch()"
        return param_string

    def projectParamsForDefinition(self, cur_cmd, enhanced=False):

        params = [self.projectParam(x, cur_cmd).declaration()
                  for x in cur_cmd.params]
        if cur_cmd.handle is not None:
            params.pop(0)
        if cur_cmd.is_create_connect and enhanced:
            params.pop()
        params.append("Dispatch && d")
        return ", ".join(params)

    def projectParamsForImplementation(self, cur_cmd, enhanced=False):
        params = [self.projectParam(x, cur_cmd).get_convert_from()
                  for x in cur_cmd.params]

        if cur_cmd.handle is not None:
            params[0] = 'get()'
        if cur_cmd.is_create_connect and enhanced:
            params.pop()
        return ", ".join(params)

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

        file_data = self.template.render(
            gen=self,
            registry=self.registry,
            null_instance_ok=VALID_FOR_NULL_INSTANCE,
            sorted_cmds=sorted_cmds,
            member_function_name=_member_function_name,
            member_function_params=_member_function_params,
            project_params_for_declaration=self.projectParamsForDeclaration,
            project_params_for_definition=self.projectParamsForDefinition,
            project_params_for_implementation=self.projectParamsForImplementation,
            create_enum_value=self.createEnumValue,
            project_type_name=self.projectTypeName,
            result_enum=result_enum,
            create_enum_exception=self.createEnumException,
            filter_for_success_codes=self.filter_for_success_codes
        )
        write(file_data, file=self.outFile)

        # Finish processing in superclass
        AutomaticSourceOutputGenerator.endFile(self)
