struct Version {
    OPENXR_HPP_CONSTEXPR Version()
        : major(0)
        , minor(0)
        , patch(0)
    {
    }

    explicit Version(uint64_t version) : Version()
    {
        reinterpret_cast<uint64_t&>(*this) = version;
    }

    uint64_t patch : 32;
    uint64_t minor : 16;
    uint64_t major : 16;

    static Version current() noexcept
    {
        return Version { XR_CURRENT_API_VERSION };
    }
};
static_assert(sizeof(Version) == sizeof(XrVersion), "handle and wrapper have different size!");
