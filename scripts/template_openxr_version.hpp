//# set type = "Version"
//# set comparison_operators = ('<', '>', '<=', '>=', '==', '!=')
//# set invalid = ""
//# extends "template_openxr_wrapperclass.hpp"

//## No validity methods
//# block validity
//# endblock

//# block extra_methods
//! Get the major component.
OPENXR_HPP_CONSTEXPR uint16_t major() const noexcept
{
    return static_cast<uint16_t>(val_ >> 48);
}
//! Set the major component.
void major(uint16_t val) noexcept
{
    // blank the top 16 bits
    val_ &= 0x0000ffffffffffff;
    val_ |= uint64_t(val) << 48;
}

//! Get the minor component.
OPENXR_HPP_CONSTEXPR uint16_t minor() const noexcept
{
    return static_cast<uint16_t>((val_ >> 32) & 0xffff);
}
//! Set the minor component.
void minor(uint16_t val) noexcept
{
    // blank the correct 16 bits
    val_ &= 0xffff0000ffffffff;
    val_ |= uint64_t(val) << 32;
}

//! Get the patch component.
OPENXR_HPP_CONSTEXPR uint32_t patch() const noexcept
{
    return static_cast<uint32_t>(val_ & 0xffffffff);
}
//! Set the patch component.
void patch(uint32_t val) noexcept
{
    // blank the least-significant 32 bits
    val_ &= 0xffffffff00000000;
    val_ |= val;
}

//! Get the current version.
static OPENXR_HPP_CONSTEXPR Version current() noexcept
{
    return Version{XR_CURRENT_API_VERSION};
}
//# endblock
