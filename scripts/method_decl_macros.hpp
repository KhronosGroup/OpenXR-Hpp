//## Copyright (c) 2017-2019 The Khronos Group Inc.
//## Copyright (c) 2019 Collabora, Ltd.
//##
//## Licensed under the Apache License, Version 2.0 (the "License");
//## you may not use this file except in compliance with the License.
//## You may obtain a copy of the License at
//##
//##     http://www.apache.org/licenses/LICENSE-2.0
//##
//## Unless required by applicable law or agreed to in writing, software
//## distributed under the License is distributed on an "AS IS" BASIS,
//## WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//## See the License for the specific language governing permissions and
//## limitations under the License.
//##
//## ---- Exceptions to the Apache 2.0 License: ----
//##
//## As an exception, if you use this Software to generate code and portions of
//## this Software are embedded into the generated code as a result, you may
//## redistribute such product without providing attribution as would otherwise
//## be required by Sections 4(a), 4(b) and 4(d) of the License.
//##
//## In addition, if you combine or link code generated by this Software with
//## software that is licensed under the GPLv2 or the LGPL v2.0 or 2.1
//## ("`Combined Software`") and if a court of competent jurisdiction determines
//## that the patent provision (Section 3), the indemnity provision (Section 9)
//## or other Section of the License conflicts with the conditions of the
//## applicable GPL or LGPL license, you may retroactively and prospectively
//## choose to deem waived or otherwise exclude such Section(s) of the License,
//## but only in their entirety and only with respect to the Combined Software.

//# from 'macros.hpp' import make_spec_url

/*% macro shared_comments(cur_cmd, method) %*/
//!
//! See the related specification text at /*{ make_spec_url(cur_cmd.name) }*/
//!
//! @xrentity{/*{ cur_cmd.name }*/}
/*% if not method.is_core %*/
//!
//! @note By default, no default dispatch is provided as this is a non-core function,
//! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic).
//! See OPENXR_HPP_DEFAULT_EXTENSION_DISPATCHER for details.
/*% endif %*/
/*% endmacro %*/

//# macro _describe_result(enhanced, exceptions_allowed)
//#     filter replace("\n", " ")
Result
//#         if enhanced.multiple_success_codes or exceptions_allowed != true
(which may be /*{ enhanced.get_success_codes() | join(", ") }*/, or an error code if asserts are not active /*{ "and exceptions are disabled" if exceptions_allowed == "maybe" }*/)
//#         endif
//#     endfilter
//# endmacro

//# macro enhanced_method_behavior(enhanced, exceptions_allowed)
//#     if exceptions_allowed == false
// Asserts that the result is /*{ "one of the expected success codes." if enhanced.multiple_success_codes else "Result::Success." }*/
//#     else
// Throws an appropriate exception on failure /*%- if exceptions_allowed == "maybe" %*/ if OPENXR_HPP_NO_EXCEPTIONS is not defined/*% endif %*/.
//#     endif
//
//# if enhanced.return_type.startswith("ResultValue")
//#     set return_type = enhanced.bare_return_type
//#     set ret_value_prefix = "\n// - "
// @returns a ResultValue tuple containing:
// - /*{ _describe_result(enhanced, exceptions_allowed) | trim }*/
//# elif enhanced.return_type == "Result"
// @returns /*{ _describe_result(enhanced, exceptions_allowed) | trim }*/
//# set return_type = ""
//# elif enhanced.return_type == "void"
//# set return_type = ""
//# else
//#     set return_type = enhanced.return_type
//#     set ret_value_prefix = "// @returns "
//# endif
//# if return_type
//#     if return_type.startswith("UniqueHandle")
/*{- ret_value_prefix }*/ a smart wrapper uniquely owning a /*{ enhanced.handle_return_type }*/
//#     else
/*{- ret_value_prefix }*//*{ enhanced.prose_bare_return  | trim }*/
//#     endif
//# endif
//
//# endmacro

//# macro enhanced_comment_intro(cur_cmd, exceptions_allowed, only_no_exceptions, hide_simple, brief, brief_suffix="")
//#     if brief
//! @brief /*{cur_cmd.name}*/ wrapper /*{ brief }*/ /*{ brief_suffix }*/
//#     else
//! @brief /*{cur_cmd.name}*/ wrapper - enhanced mode/*% if hide_simple %*/ (hides basic wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined)/*% endif %*/.
//#     endif
//#     if only_no_exceptions
//!
//! Will not throw exceptions. Only available when `OPENXR_HPP_NO_EXCEPTIONS` is defined.
//#     elif exceptions_allowed == true
//!
//! Only available when `OPENXR_HPP_NO_EXCEPTIONS` is not defined.
//#     endif
//# endmacro

//# macro method_proto(cur_cmd, enhanced, exceptions_allowed, only_no_exceptions, hide_simple, brief)
//# filter block_doxygen_comment
/*{ enhanced_comment_intro(cur_cmd, exceptions_allowed, only_no_exceptions, hide_simple, brief) }*/
//! /*% if enhanced.is_two_call %*/Performs two-call idiom./*% endif %*/
/*{ enhanced_method_behavior(enhanced, exceptions_allowed) }*/
/*{ shared_comments(cur_cmd, enhanced) }*/
//# endfilter
    template </*{ enhanced.get_template_decls() }*/>
    /*{enhanced.return_type}*/ /*{enhanced.cpp_name}*/ (
        /*{ enhanced.get_declaration_params() | join(", ")}*/) /*{enhanced.qualifiers}*/;
//# if enhanced.is_two_call
//# filter block_doxygen_comment
    /*{ enhanced_comment_intro(cur_cmd, exceptions_allowed, only_no_exceptions, hide_simple, brief, "Performs two-call idiom with a stateful allocator.") }*/
    //!
    /*{ enhanced_method_behavior(enhanced) }*/
    /*{ shared_comments(cur_cmd, enhanced) }*/
//# endfilter
    template </*{ enhanced.get_template_decls(suppress_default_dispatch_arg=true) }*/>
    /*{enhanced.return_type}*/ /*{enhanced.cpp_name}*/ (
        /*{ enhanced.get_declaration_params(extras=["Allocator const& vectorAllocator"], suppress_default_dispatch_arg=true) | join(", ")}*/) /*{enhanced.qualifiers}*/;

//# endif
//# endmacro

//# macro method_prototypes(cur_cmd, protection_context)

/*{ protect_begin(cur_cmd, protection_context) }*/
//## /*{ discouraged_begin(cur_cmd) }*/
//#     set method = basic_cmds[cur_cmd.name]
//#     set enhanced = enhanced_cmds[cur_cmd.name]

//## Should we hide the result-returning function in enhanced mode?
//#     set hide_simple = enhanced.masks_simple

//#     if hide_simple
#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
//#     endif
//#     filter block_doxygen_comment
//! @brief /*{cur_cmd.name}*/ wrapper (basic).
/*{ shared_comments(cur_cmd, method) }*/
//#     endfilter
template </*{ method.get_template_decls() }*/>
/*{method.return_type}*/ /*{method.cpp_name}*/ (
    /*{ method.get_declaration_params() | join(", ")}*/) /*{method.qualifiers}*/;

//#     if hide_simple
#else  // OPENXR_HPP_DISABLE_ENHANCED_MODE
//#     else
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
//#     endif

//#     if enhanced.explicit_result_elided
#ifdef OPENXR_HPP_NO_EXCEPTIONS
/*{ method_proto(cur_cmd, enhanced_cmds_no_exceptions[enhanced.name], false, true, hide_simple, "") }*/
# else
/*{ method_proto(cur_cmd, enhanced, true, false, hide_simple, "") }*/
#endif // OPENXR_HPP_NO_EXCEPTIONS

//#     else
/*{ method_proto(cur_cmd, enhanced, "maybe", false, hide_simple, "") }*/
//#     endif

//#     if enhanced.is_create
#ifndef OPENXR_HPP_NO_SMART_HANDLE

//#         set uniq = unique_cmds[cur_cmd.name]
//#         if uniq.explicit_result_elided
#ifdef OPENXR_HPP_NO_EXCEPTIONS
/*{ method_proto(cur_cmd, unique_cmds_no_exceptions[uniq.name], false, true, false, "returning a smart handle.") }*/
#else
/*{ method_proto(cur_cmd, uniq, true, false, false, "returning a smart handle.") }*/
#endif
//#         else
/*{ method_proto(cur_cmd, uniq, "maybe", false, false, "returning a smart handle.") }*/
//#         endif

#endif // !OPENXR_HPP_NO_SMART_HANDLE
//#     endif

#endif  // !OPENXR_HPP_DISABLE_ENHANCED_MODE

//## /*{ discouraged_end(cur_cmd) }*/
/*{ protect_end(cur_cmd, protection_context) }*/
//# endmacro
