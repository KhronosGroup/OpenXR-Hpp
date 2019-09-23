
namespace OPENXR_HPP_NAMESPACE {

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

#endif  // !OPENXR_HPP_DISABLE_ENHANCED_MODE

}  // namespace OPENXR_HPP_NAMESPACE
