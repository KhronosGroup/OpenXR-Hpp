
#include <openxr/openxr.h>
#include <openxr/openxr_platform.h>

#include <array>
#include <cstddef>
#include <initializer_list>
#include <memory>
#include <type_traits>

// #include <cstdint>
// #include <cstring>
// #include <string>
// #include <system_error>
// #include <tuple>

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

#if !defined(OPENXR_HPP_NAMESPACE)
#define OPENXR_HPP_NAMESPACE xr
#endif

#define OPENXR_HPP_STRINGIFY2(text) #text
#define OPENXR_HPP_STRINGIFY(text) OPENXR_HPP_STRINGIFY2(text)
#define OPENXR_HPP_NAMESPACE_STRING OPENXR_HPP_STRINGIFY(OPENXR_HPP_NAMESPACE)

namespace OPENXR_HPP_NAMESPACE {

template <typename FlagBitsType>
struct FlagTraits {
    enum { allFlags = 0 };
};

template <typename BitType, typename MaskType = XrFlags64>
class Flags {
   public:
    OPENXR_HPP_CONSTEXPR Flags() : m_mask(0) {}

    Flags(BitType bit) : m_mask(static_cast<MaskType>(bit)) {}

    Flags(Flags<BitType> const &rhs) : m_mask(rhs.m_mask) {}

    explicit Flags(MaskType flags) : m_mask(flags) {}

    Flags<BitType> &operator=(Flags<BitType> const &rhs) {
        m_mask = rhs.m_mask;
        return *this;
    }

    Flags<BitType> &operator|=(Flags<BitType> const &rhs) {
        m_mask |= rhs.m_mask;
        return *this;
    }

    Flags<BitType> &operator&=(Flags<BitType> const &rhs) {
        m_mask &= rhs.m_mask;
        return *this;
    }

    Flags<BitType> &operator^=(Flags<BitType> const &rhs) {
        m_mask ^= rhs.m_mask;
        return *this;
    }

    Flags<BitType> operator|(Flags<BitType> const &rhs) const {
        Flags<BitType> result(*this);
        result |= rhs;
        return result;
    }

    Flags<BitType> operator&(Flags<BitType> const &rhs) const {
        Flags<BitType> result(*this);
        result &= rhs;
        return result;
    }

    Flags<BitType> operator^(Flags<BitType> const &rhs) const {
        Flags<BitType> result(*this);
        result ^= rhs;
        return result;
    }

    bool operator!() const { return !m_mask; }

    Flags<BitType> operator~() const {
        Flags<BitType> result(*this);
        result.m_mask ^= FlagTraits<BitType>::allFlags;
        return result;
    }

    bool operator==(Flags<BitType> const &rhs) const { return m_mask == rhs.m_mask; }

    bool operator!=(Flags<BitType> const &rhs) const { return m_mask != rhs.m_mask; }

    explicit operator bool() const { return !!m_mask; }

    explicit operator MaskType() const { return m_mask; }

   private:
    MaskType m_mask;
};

template <typename BitType>
Flags<BitType> operator|(BitType bit, Flags<BitType> const &flags) {
    return flags | bit;
}

template <typename BitType>
Flags<BitType> operator&(BitType bit, Flags<BitType> const &flags) {
    return flags & bit;
}

template <typename BitType>
Flags<BitType> operator^(BitType bit, Flags<BitType> const &flags) {
    return flags ^ bit;
}

template <typename RefType>
class Optional {
   public:
    Optional(RefType &reference) { m_ptr = &reference; }
    Optional(RefType *ptr) { m_ptr = ptr; }
    Optional(std::nullptr_t) { m_ptr = nullptr; }

    operator RefType *() const { return m_ptr; }
    RefType const *operator->() const { return m_ptr; }
    explicit operator bool() const { return !!m_ptr; }

   private:
    RefType *m_ptr;
};

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename T>
class ArrayProxy {
   public:
    OPENXR_HPP_CONSTEXPR ArrayProxy(std::nullptr_t) : m_count(0), m_ptr(nullptr) {}

    ArrayProxy(T &ptr) : m_count(1), m_ptr(&ptr) {}

    ArrayProxy(uint32_t count, T *ptr) : m_count(count), m_ptr(ptr) {}

    template <size_t N>
    ArrayProxy(std::array<typename std::remove_const<T>::type, N> &data) : m_count(N), m_ptr(data.data()) {}

    template <size_t N>
    ArrayProxy(std::array<typename std::remove_const<T>::type, N> const &data) : m_count(N), m_ptr(data.data()) {}

    template <class Allocator = std::allocator<typename std::remove_const<T>::type>>
    ArrayProxy(std::vector<typename std::remove_const<T>::type, Allocator> &data)
        : m_count(static_cast<uint32_t>(data.size())), m_ptr(data.data()) {}

    template <class Allocator = std::allocator<typename std::remove_const<T>::type>>
    ArrayProxy(std::vector<typename std::remove_const<T>::type, Allocator> const &data)
        : m_count(static_cast<uint32_t>(data.size())), m_ptr(data.data()) {}

    ArrayProxy(std::initializer_list<T> const &data)
        : m_count(static_cast<uint32_t>(data.end() - data.begin())), m_ptr(data.begin()) {}

    const T *begin() const { return m_ptr; }

    const T *end() const { return m_ptr + m_count; }

    const T &front() const {
        OPENXR_HPP_ASSERT(m_count && m_ptr);
        return *m_ptr;
    }

    const T &back() const {
        OPENXR_HPP_ASSERT(m_count && m_ptr);
        return *(m_ptr + m_count - 1);
    }

    bool empty() const { return (m_count == 0); }

    uint32_t size() const { return m_count; }

    T *data() const { return m_ptr; }

   private:
    uint32_t m_count;
    T *m_ptr;
};
#endif
}  // namespace OPENXR_HPP_NAMESPACE
