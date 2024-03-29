//## Copyright (c) 2017-2023 The Khronos Group Inc.
//## Copyright (c) 2019-2023 Collabora, Ltd.
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

//# include('file_header.hpp')
/**
 * @file
 * @brief Contains a "static" dispatcher class: provides only core entry points directly provided by linking against the loader.
 *
 * @ingroup dispatch
 */

//# from 'macros.hpp' import forwardCommandArgs, make_pfn_type, make_pfn_getter_name

#include <openxr/openxr.h>

#ifdef OPENXR_HPP_DOXYGEN
#include <openxr/openxr_platform.h>
#endif

#include <type_traits>

//# include('define_inline_constexpr.hpp') without context
//# include('define_namespace.hpp') without context


/*!
 * @defgroup dispatch Dispatch classes
 * @brief Classes providing a method or function pointer member for OpenXR APIs.
 *
 * The classes provided here are useful basic classes, but all places that can take a dispatch class are templated to be able to
 * accept any class that meets the requirements.
 */


#ifndef XR_NO_PROTOTYPES

namespace OPENXR_HPP_NAMESPACE {

/*!
 * @brief Dispatch class for OpenXR core functions that uses exported, statically-available symbols.
 *
 * Not for use in game engines or other multi-module software where different modules might want newer OpenXR APIs. If this is used,
 * all parts of an application must build against and use the same loader library.
 *
 * Does not provide extension functions because those are not exported from the loader library.
 *
 * @ingroup dispatch
 */
class DispatchLoaderStatic {
   public:
    /*!
     * @name Core Commands
     * @{
     */

    //# for cur_cmd in gen.core_commands
    //! @brief Call /*{cur_cmd.name}*/
    OPENXR_HPP_INLINE /*{cur_cmd.cdecl | collapse_whitespace | replace(";", "")}*/ const {
        return ::/*{cur_cmd.name}*/ (/*{ forwardCommandArgs(cur_cmd) }*/);
    }

    //! @brief Return the function pointer for /*{cur_cmd.name}*/ - provided just for feature parity with xr::DispatchLoaderDynamic
    OPENXR_HPP_INLINE /*{ make_pfn_type(cur_cmd) }*/ /*{ make_pfn_getter_name(cur_cmd) }*/ () const {
        return &::/*{cur_cmd.name}*/;
    }
    //# endfor

    //! @}
};

#ifndef OPENXR_HPP_DOXYGEN
// forward declare and manually defining trait to avoid include
namespace traits {
    template <typename T>
    struct is_dispatch;
    template <>
    struct is_dispatch<::OPENXR_HPP_NAMESPACE::DispatchLoaderStatic> : std::true_type {};
}  // namespace traits
#endif  // !OPENXR_HPP_DOXYGEN

}  // namespace OPENXR_HPP_NAMESPACE

#endif  // ifndef XR_NO_PROTOTYPES


//# include('file_footer.hpp')
