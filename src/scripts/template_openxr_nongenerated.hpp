
#include <openxr/openxr.h>
#include <openxr/openxr_platform.h>

#include <array>
#include <cstddef>
#include <initializer_list>
#include <type_traits>
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
#include <memory>
#include <vector>
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

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
class OptionalRef {
   public:
    OptionalRef(RefType &reference) { m_ptr = &reference; }
    OptionalRef(RefType *ptr) { m_ptr = ptr; }
    OptionalRef(std::nullptr_t) { m_ptr = nullptr; }

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

#ifndef OPENXR_HPP_NO_SMART_HANDLE

template <typename Type, typename Dispatch>
class UniqueHandleTraits;

template <typename Type, typename Dispatch>
class UniqueHandle : public UniqueHandleTraits<Type, Dispatch>::deleter {
   private:
    using Deleter = typename UniqueHandleTraits<Type, Dispatch>::deleter;

   public:
    explicit UniqueHandle(Type const &value = Type(), Deleter const &deleter = Deleter()) : Deleter(deleter), m_value(value) {}

    UniqueHandle(UniqueHandle const &) = delete;

    UniqueHandle(UniqueHandle &&other) : Deleter(std::move(static_cast<Deleter &>(other))), m_value(other.release()) {}

    ~UniqueHandle() {
        if (m_value) this->destroy(m_value);
    }

    UniqueHandle &operator=(UniqueHandle const &) = delete;

    UniqueHandle &operator=(UniqueHandle &&other) {
        reset(other.release());
        *static_cast<Deleter *>(this) = std::move(static_cast<Deleter &>(other));
        return *this;
    }

    explicit operator bool() const { return m_value.operator bool(); }

    Type const *operator->() const { return &m_value; }

    Type *operator->() { return &m_value; }

    Type const &operator*() const { return m_value; }

    Type &operator*() { return m_value; }

    const Type &get() const { return m_value; }

    Type &get() { return m_value; }

    void reset(Type const &value = Type()) {
        if (m_value != value) {
            if (m_value) this->destroy(m_value);
            m_value = value;
        }
    }

    Type release() {
        Type value = m_value;
        m_value = nullptr;
        return value;
    }

    void swap(UniqueHandle<Type, Dispatch> &rhs) {
        std::swap(m_value, rhs.m_value);
        std::swap(static_cast<Deleter &>(*this), static_cast<Deleter &>(rhs));
    }

   private:
    Type m_value;
};

template <typename Type, typename Dispatch>
OPENXR_HPP_INLINE void swap(UniqueHandle<Type, Dispatch> &lhs, UniqueHandle<Type, Dispatch> &rhs) {
    lhs.swap(rhs);
}
#endif

template <typename X, typename Y>
struct isStructureChainValid {
    enum { value = false };
};

template <typename P, typename T>
struct TypeList {
    using list = P;
    using last = T;
};

template <typename List, typename X>
struct extendCheck {
    static const bool valid = isStructureChainValid<typename List::last, X>::value || extendCheck<typename List::list, X>::valid;
};

template <typename T, typename X>
struct extendCheck<TypeList<void, T>, X> {
    static const bool valid = isStructureChainValid<T, X>::value;
};

template <typename X>
struct extendCheck<void, X> {
    static const bool valid = true;
};

template <class Element>
class StructureChainElement {
   public:
    explicit operator Element &() { return value; }
    explicit operator const Element &() const { return value; }

   private:
    Element value;
};

template <typename... StructureElements>
class StructureChain : private StructureChainElement<StructureElements>... {
   public:
    StructureChain() { link<void, StructureElements...>(); }

    StructureChain(StructureChain const &rhs) { linkAndCopy<void, StructureElements...>(rhs); }

    StructureChain(StructureElements const &... elems) { linkAndCopyElements<void, StructureElements...>(elems...); }

    StructureChain &operator=(StructureChain const &rhs) {
        linkAndCopy<void, StructureElements...>(rhs);
        return *this;
    }

    template <typename ClassType>
    ClassType &get() {
        return static_cast<ClassType &>(*this);
    }

   private:
    template <typename List, typename X>
    void link() {
        static_assert(extendCheck<List, X>::valid, "The structure chain is not valid!");
    }

    template <typename List, typename X, typename Y, typename... Z>
    void link() {
        static_assert(extendCheck<List, X>::valid, "The structure chain is not valid!");
        X &x = static_cast<X &>(*this);
        Y &y = static_cast<Y &>(*this);
        x.pNext = &y;
        link<TypeList<List, X>, Y, Z...>();
    }

    template <typename List, typename X>
    void linkAndCopy(StructureChain const &rhs) {
        static_assert(extendCheck<List, X>::valid, "The structure chain is not valid!");
        static_cast<X &>(*this) = static_cast<X const &>(rhs);
    }

    template <typename List, typename X, typename Y, typename... Z>
    void linkAndCopy(StructureChain const &rhs) {
        static_assert(extendCheck<List, X>::valid, "The structure chain is not valid!");
        X &x = static_cast<X &>(*this);
        Y &y = static_cast<Y &>(*this);
        x = static_cast<X const &>(rhs);
        x.pNext = &y;
        linkAndCopy<TypeList<List, X>, Y, Z...>(rhs);
    }

    template <typename List, typename X>
    void linkAndCopyElements(X const &xelem) {
        static_assert(extendCheck<List, X>::valid, "The structure chain is not valid!");
        static_cast<X &>(*this) = xelem;
    }

    template <typename List, typename X, typename Y, typename... Z>
    void linkAndCopyElements(X const &xelem, Y const &yelem, Z const &... zelem) {
        static_assert(extendCheck<List, X>::valid, "The structure chain is not valid!");
        X &x = static_cast<X &>(*this);
        Y &y = static_cast<Y &>(*this);
        x = xelem;
        x.pNext = &y;
        linkAndCopyElements<TypeList<List, X>, Y, Z...>(yelem, zelem...);
    }
};

}  // namespace OPENXR_HPP_NAMESPACE
