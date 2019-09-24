struct Version
{
    OPENXR_HPP_CONSTEXPR Version() noexcept = default;

    OPENXR_HPP_CONSTEXPR explicit Version(uint64_t version) noexcept : value(version)
    {
    }

    uint64_t value{0};

    //! Get the major component.
    OPENXR_HPP_CONSTEXPR uint32_t major() const noexcept
    {
        return static_cast<uint32_t>(value >> 32);
    }
    //! Set the major component.
    void major(uint32_t val) noexcept
    {
        // blank the top 32 bits
        value &= 0xffffffff;
        value |= uint64_t(val) << 32;
    }

    //! Get the minor component.
    OPENXR_HPP_CONSTEXPR uint16_t minor() const noexcept
    {
        return static_cast<uint16_t>((value >> 16) & 0xffff);
    }
    //! Set the minor component.
    void minor(uint16_t val) noexcept
    {
        // blank the correct 16 bits
        value &= 0xffffffff0000ffff;
        value |= uint64_t(val) << 16;
    }

    //! Get the patch component.
    OPENXR_HPP_CONSTEXPR uint16_t patch() const noexcept
    {
        return static_cast<uint16_t>(value & 0xffff);
    }
    //! Set the patch component.
    void patch(uint16_t val) noexcept
    {
        // blank the least-significant 16 bits
        value &= 0xffffffffffff0000;
        value |= val;
    }

    //! Get the current version.
    static OPENXR_HPP_CONSTEXPR Version current() noexcept
    {
        return Version{XR_CURRENT_API_VERSION};
    }
};
static_assert(sizeof(Version) == sizeof(XrVersion), "handle and wrapper have different size!");
