
#include <openxr/openxr.h>
#include <openxr/openxr_platform.h>

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstring>
#include <initializer_list>
#include <string>
#include <system_error>
#include <tuple>
#include <type_traits>
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
#include <memory>
#include <vector>
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

// Fix name collisions from noisy includes
#ifdef Success
#undef Success
#endif

#if !defined(OPENXR_HPP_ASSERT)
#include <cassert>
#define OPENXR_HPP_ASSERT assert
#endif

// 32-bit OpenXR is not typesafe for handles, so don't allow copy constructors
// on this platform by default. To enable this feature on 32-bit platforms
// please define OPENXR_HPP_TYPESAFE_CONVERSION
#if defined(__LP64__) || defined(_WIN64) || (defined(__x86_64__) && !defined(__ILP32__)) || defined(_M_X64) || defined(__ia64) || \
    defined(_M_IA64) || defined(__aarch64__) || defined(__powerpc64__)
#if !defined(OPENXR_HPP_TYPESAFE_CONVERSION)
#define OPENXR_HPP_TYPESAFE_CONVERSION
#endif
#endif

#if !defined(OPENXR_HPP_INLINE)
#if defined(__clang___)
#if __has_attribute(always_inline)
#define OPENXR_HPP_INLINE __attribute__((always_inline)) __inline__
#else
#define OPENXR_HPP_INLINE inline
#endif
#elif defined(__GNUC__)
#define OPENXR_HPP_INLINE __attribute__((always_inline)) __inline__
#elif defined(_MSC_VER)
#define OPENXR_HPP_INLINE inline
#else
#define OPENXR_HPP_INLINE inline
#endif
#endif

#if defined(OPENXR_HPP_TYPESAFE_CONVERSION)
#define OPENXR_HPP_TYPESAFE_EXPLICIT
#else
#define OPENXR_HPP_TYPESAFE_EXPLICIT explicit
#endif

#if defined(_MSC_VER) && (_MSC_VER <= 1800)
#define OPENXR_HPP_CONSTEXPR
#else
#define OPENXR_HPP_CONSTEXPR constexpr
#endif

//! @todo set this to constexpr in c++14
#define OPENXR_HPP_SWITCH_CONSTEXPR

#if !defined(OPENXR_HPP_NAMESPACE)
#define OPENXR_HPP_NAMESPACE xr
#endif

#define OPENXR_HPP_STRINGIFY2(text) #text
#define OPENXR_HPP_STRINGIFY(text) OPENXR_HPP_STRINGIFY2(text)
#define OPENXR_HPP_NAMESPACE_STRING OPENXR_HPP_STRINGIFY(OPENXR_HPP_NAMESPACE)
