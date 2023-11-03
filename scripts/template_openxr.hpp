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

//# include 'file_header.hpp'
/*!
 * @file
 * @brief Meta-header including all OpenXR-Hpp headers.
 *
 * It is usually recommended to include just those headers you specifically need.
 */

/*!
 * @defgroup wrappers Wrappers for OpenXR types and functions
 * @brief When using OpenXR-Hpp, you can use these instead of their counterparts defined in the specification.
 */
/*!
 * @defgroup config Configuration options
 * @brief Preprocessor macros that may be set to control the behavior of OpenXR-Hpp
 */

/*!
 * @defgroup utilities Miscellaneous utilities
 */

/*!
 * @defgroup utility_accessors Utility free-function accessors
 * @brief Free functions for "getting" or "putting" from/to a wrapped or projected type, etc (see "more" for shared documentation by function name).
 *
 * These have common names, like `get()`, `put()`, and `to_string()`. They should be found by argument-dependent lookup and not need explicit namespace specification, e.g. do `get(myInstance)` not `xr::get(myInstance)`.
 *
 * These functions have shared behavior. For the purposes of these functions, the packed version type xr::Version behaves like a structure projection.
 *
 * - `get()` functions "unwrap" one layer of projection.
 *   - If applied to a structure projection, it gives you a pointer to const for the original (C) struct type.
 *   - If applied to a handle projection, you get the raw handle.
 *   - If applied to a `UniqueHandle<>` wrapper (or a type alias like xr::UniqueInstance),
 *     which act like smart pointers, it gives you the "pointed-to" projected handle (e.g. xr::Instance).
 *     Apply it twice to get the raw handle if needed for something.
 *   - If applied to an xr::Flags type, it gives you the raw C integer value.
 * - `get_base()` is a variant of `get()` for structure projections that are "derived" - it gets the "parent struct" pointer instead.
 * - `put()` functions clear what they're given (by default, some types optionally allow not clearing) and return the address for use in an output parameter.
 *   - If applied to a `UniqueHandle<>` or alias, the previous handle, if any, is destroyed, then the address of the raw handle is returned.
 *   - If applied to a handle projection, the handle is reset to null (by default) and the address of the raw handle is returned. (The handle is not destroyed because these types do not convey ownership!) To avoid clearing, pass `false` for the optional argument `clear`.
 *   - If applied to a (non-abstract) structure projection, the structure is cleared/reset except for the value of `next` (by default), then the address is returned as a pointer to the raw C structure type. To avoid clearing, pass `false` for the optional argument `clear`.
 * - `to_string_literal()` is available only for enums, and returns (constexpr if supported by your language version) the stringification of the projected value name as a string literal.
 * - `to_string()` is available only for enums, and wraps the result of `to_string_literal()` in a `std::string` to match the standard library's behavior.
 */

/**
 * @def OPENXR_HPP_NAMESPACE
 * @brief Define to the namespace you wish to place OpenXR-Hpp in: defaults to `xr`.
 *
 * @ingroup config
 */

//# include('define_namespace.hpp') without context

/*!
 * @namespace xr
 * @brief Namespace containing all OpenXR-Hpp entities.
 *
 * If the default namespace `xr` isn't suitable, you can define `OPENXR_HPP_NAMESPACE` to a different name before including any OpenXR-Hpp headers.
 *
 * @see OPENXR_HPP_NAMESPACE
 */
namespace OPENXR_HPP_NAMESPACE {}  // namespace OPENXR_HPP_NAMESPACE

#include "openxr_atoms.hpp"
#include "openxr_time.hpp"
#include "openxr_version.hpp"
#include "openxr_dispatch_static.hpp"
#include "openxr_dispatch_dynamic.hpp"
#include "openxr_handles.hpp"
#include "openxr_structs.hpp"

/*
 * Inline implementations of all trampoline methods and free functions follow.
 * Prototypes may be found in openxr_handles.hpp, either in the associated handle class, or immediately following the section of handle classes.
 */
#include "openxr_method_impls.hpp"


//# include 'file_footer.hpp'
