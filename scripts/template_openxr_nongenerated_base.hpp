
#include <openxr/openxr.h>
#include <openxr/openxr_platform.h>

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstring>
#include <functional>
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
#ifdef None
#undef None
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

/*!
 * @brief Namespace containing all openxr.hpp entities.
 *
 * If the default namespace `xr` isn't suitable, you can define OPENXR_HPP_NAMESPACE to a different name before including this
 * header.
 */
namespace OPENXR_HPP_NAMESPACE {
// Forward declaration
class DispatchLoaderDynamic;

// The generalization of std::string with user-specifiable allocator types.
template <typename Allocator = std::allocator<char>>
using string_with_allocator = std::basic_string<char, std::char_traits<char>, Allocator>;

using Bool32 = XrBool32;
using Path = XrPath;
using SystemId = XrSystemId;
using Version = XrVersion;

enum Side : uint32_t {
    Left = 0,
    Right = 1,
};

constexpr uint32_t SIDE_COUNT = 2;

using BilateralPaths = std::array<Path, SIDE_COUNT>;

using SideHandler = std::function<void(Side)>;
using IndexHandler = std::function<void(uint32_t)>;

constexpr char const* const reserved_paths[] = {
    "/user/hand/left", "/user/hand/right", "/user/head", "/user/gamepad", "/user/treadmill",
};

constexpr char const* const interaction_profiles[] = {
    "/interaction_profiles/khr/simple_controller",       "/interaction_profiles/google/daydream_controller",
    "/interaction_profiles/htc/vive_controller",         "/interaction_profiles/htc/vive_pro",
    "/interaction_profiles/microsoft/motion_controller", "/interaction_profiles/microsoft/xbox_controller",
    "/interaction_profiles/oculus/go_controller",        "/interaction_profiles/oculus/touch_controller",
    "/interaction_profiles/valve/index_controller",
};

template <typename SideHandler>
static inline void for_each_side(SideHandler&& handler) {
    handler(Left);
    handler(Right);
}

template <typename IndexHandler>
static inline void for_each_side_index(IndexHandler&& handler) {
    handler(0);
    handler(1);
}

class Duration {
   public:
    OPENXR_HPP_CONSTEXPR Duration() = default;
    OPENXR_HPP_CONSTEXPR explicit Duration(XrDuration t) : val_(t) {}

    OPENXR_HPP_CONSTEXPR XrDuration get() const noexcept { return val_; }

    XrDuration* put() noexcept {
        val_ = 0;
        return &val_;
    }

    Duration& operator-=(Duration d) noexcept {
        val_ -= d.val_;
        return *this;
    }
    Duration& operator+=(Duration d) noexcept {
        val_ += d.val_;
        return *this;
    }

    static OPENXR_HPP_CONSTEXPR Duration infinite() noexcept { return Duration{XR_INFINITE_DURATION}; }

    static OPENXR_HPP_CONSTEXPR Duration minHaptic() noexcept { return Duration{XR_MIN_HAPTIC_DURATION}; }

   private:
    XrDuration val_{};
};

OPENXR_HPP_CONSTEXPR inline XrDuration get(Duration d) noexcept { return d.get(); }

inline XrDuration* put(Duration& d) noexcept { return d.put(); }
OPENXR_HPP_CONSTEXPR inline Duration operator+(Duration lhs, Duration rhs) noexcept { return Duration{lhs.get() + rhs.get()}; }
OPENXR_HPP_CONSTEXPR inline Duration operator-(Duration lhs, Duration rhs) noexcept { return Duration{lhs.get() - rhs.get()}; }

class Time {
   public:
    OPENXR_HPP_CONSTEXPR Time() = default;
    OPENXR_HPP_CONSTEXPR explicit Time(XrTime t) : val_(t) {}

    OPENXR_HPP_CONSTEXPR explicit operator bool() const noexcept { return val_ == 0; }
    OPENXR_HPP_CONSTEXPR XrTime get() const noexcept { return val_; }

    XrTime* put() noexcept {
        val_ = 0;
        return &val_;
    }

    Time& operator-=(Duration d) noexcept {
        val_ -= d.get();
        return *this;
    }
    Time& operator+=(Duration d) noexcept {
        val_ += d.get();
        return *this;
    }

   private:
    XrTime val_{};
};

OPENXR_HPP_CONSTEXPR inline XrTime get(Time t) noexcept { return t.get(); }

inline XrTime* put(Time& t) noexcept { return t.put(); }

OPENXR_HPP_CONSTEXPR inline Duration operator-(Time lhs, Time rhs) noexcept { return Duration{lhs.get() - rhs.get()}; }

OPENXR_HPP_CONSTEXPR inline Time operator-(Time lhs, Duration rhs) noexcept { return Time{lhs.get() - rhs.get()}; }

OPENXR_HPP_CONSTEXPR inline Time operator+(Time lhs, Duration rhs) noexcept { return Time{lhs.get() + rhs.get()}; }

//# for type in ("Duration", "Time")
//# set raw_type = "Xr" + type
//# for op in ('<', '>', '<=', '>=', '==', '!=')
//! @brief /*{op}*/ comparison between /*{type}*/.
//! @relates /*{type}*/
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator/*{- op -}*/(/*{type}*/ const &lhs, /*{type}*/ const &rhs) { return lhs.get() /*{- op -}*/ rhs.get(); }
//! @brief /*{op}*/ comparison between /*{type}*/ and raw /*{raw_type}*/.
//! @relates /*{type}*/
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator/*{- op -}*/(/*{type}*/ const &lhs, /*{raw_type}*/ rhs) { return lhs.get() /*{- op -}*/ rhs; }
//! @brief /*{op}*/ comparison between raw /*{raw_type}*/ and /*{type}*/.
//! @relates /*{type}*/
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator/*{- op -}*/(/*{raw_type}*/ lhs, /*{type}*/ const &rhs) { return lhs /*{- op -}*/ rhs.get(); }
//# endfor
//# endfor


}  // namespace OPENXR_HPP_NAMESPACE
