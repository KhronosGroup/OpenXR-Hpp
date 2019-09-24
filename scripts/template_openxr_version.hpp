//# set type = "Version"
//# set comparison_operators = ('<', '>', '<=', '>=', '==', '!=')
//# set invalid = ""
//# extends "template_openxr_wrapperclass.hpp"

//## No validity methods
//# block validity
//# endblock

//# block extra_methods
//! Get the major component.
OPENXR_HPP_CONSTEXPR uint32_t major() const noexcept
{
    return static_cast<uint32_t>(val_ >> 32);
}
//! Set the major component.
void major(uint32_t val) noexcept
{
    // blank the top 32 bits
    val_ &= 0xffffffff;
    val_ |= uint64_t(val) << 32;
}

//! Get the minor component.
OPENXR_HPP_CONSTEXPR uint16_t minor() const noexcept
{
    return static_cast<uint16_t>((val_ >> 16) & 0xffff);
}
//! Set the minor component.
void minor(uint16_t val) noexcept
{
    // blank the correct 16 bits
    val_ &= 0xffffffff0000ffff;
    val_ |= uint64_t(val) << 16;
}

//! Get the patch component.
OPENXR_HPP_CONSTEXPR uint16_t patch() const noexcept
{
    return static_cast<uint16_t>(val_ & 0xffff);
}
//! Set the patch component.
void patch(uint16_t val) noexcept
{
    // blank the least-significant 16 bits
    val_ &= 0xffffffffffff0000;
    val_ |= val;
}

//! Get the current version.
static OPENXR_HPP_CONSTEXPR Version current() noexcept
{
    return Version{XR_CURRENT_API_VERSION};
}
//# endblock
