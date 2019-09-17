//# set type = "Duration"
//# set comparison_operators = ('<', '>', '<=', '>=', '==', '!=')
//# set invalid = ""
//# extends "template_openxr_wrapperclass.hpp"

//# block extra_methods
//! Add a Duration to the current Duration
Duration& operator+=(Duration d) noexcept {
    val_ += d.val_;
    return *this;
}

//! Subtract a Duration from the current Duration
Duration& operator-=(Duration d) noexcept {
    val_ -= d.val_;
    return *this;
}

//! For timeouts, indicates the timeout is immediate
static OPENXR_HPP_CONSTEXPR Duration noDuration() noexcept { return Duration{XR_NO_DURATION}; }

//! For timeouts, indicates the timeout never occurs.
static OPENXR_HPP_CONSTEXPR Duration infinite() noexcept { return Duration{XR_INFINITE_DURATION}; }

//! For haptic vibration, the shortest pulse possible for the device
static OPENXR_HPP_CONSTEXPR Duration minHaptic() noexcept { return Duration{XR_MIN_HAPTIC_DURATION}; }
//# endblock

//# block extra_free_functions
//! Add two Duration values
OPENXR_HPP_CONSTEXPR inline Duration operator+(Duration lhs, Duration rhs) noexcept { return Duration{lhs.get() + rhs.get()}; }

//! Subtract two Duration values
OPENXR_HPP_CONSTEXPR inline Duration operator-(Duration lhs, Duration rhs) noexcept { return Duration{lhs.get() - rhs.get()}; }
//# endblock
