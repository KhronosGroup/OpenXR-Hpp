//# set type = "Time"
//# set comparison_operators = ('<', '>', '<=', '>=', '==', '!=')
//# set invalid = ""
//# extends "template_openxr_wrapperclass.hpp"

//# block conversion_explicit_bool
//! True if this time is valid (positive)
OPENXR_HPP_CONSTEXPR explicit operator bool() const noexcept { return val_ > 0; }
//# endblock

//# block operator_negation
//! Unary negation: True if this /*{ type }*/ is invalid
OPENXR_HPP_CONSTEXPR bool operator!() const noexcept { return val_ <= 0; }
//# endblock

//# block extra_methods
//! Add a Duration to the current Time
Time& operator+=(Duration d) noexcept {
    val_ += d.get();
    return *this;
}

//! Subtract a Duration from the current Time
Time& operator-=(Duration d) noexcept {
    val_ -= d.get();
    return *this;
}
//# endblock

//# block extra_free_functions
//! The difference between two Time values is a Duration.
OPENXR_HPP_CONSTEXPR inline Duration operator-(Time lhs, Time rhs) noexcept { return Duration{lhs.get() - rhs.get()}; }

//! Subtract a Duration from a Time to get another Time
OPENXR_HPP_CONSTEXPR inline Time operator-(Time lhs, Duration rhs) noexcept { return Time{lhs.get() - rhs.get()}; }

//! Add a Duration to a Time to get another Time
OPENXR_HPP_CONSTEXPR inline Time operator+(Time lhs, Duration rhs) noexcept { return Time{lhs.get() + rhs.get()}; }

//# endblock
