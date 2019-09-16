
namespace OPENXR_HPP_NAMESPACE {

#ifndef OPENXR_HPP_NO_SMART_HANDLE

namespace traits {

template <typename Type, typename Dispatch>
class UniqueHandleTraits;

}  // namespace traits

namespace impl {

// Used when returning unique handles.
template <typename T>
using RemoveRefConst = typename std::remove_const<typename std::remove_reference<T>::type>::type;
}  // namespace impl

/*!
 * Template class for holding a handle with unique ownership, much like unique_ptr.
 *
 * Note that this does not keep track of children or parents, though OpenXR specifies that destruction of a handle also destroys its
 * children automatically.
 */
template <typename Type, typename Dispatch>
class UniqueHandle : public traits::UniqueHandleTraits<Type, Dispatch>::deleter {
   private:
    using Deleter = typename traits::UniqueHandleTraits<Type, Dispatch>::deleter;

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

    typename Type::RawHandleType *put() {
        reset();
        return m_value.put();
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
class UniqueHandle<Type, Dispatch &> : public UniqueHandle<Type, Dispatch> {};

template <typename Type, typename Dispatch>
class UniqueHandle<Type, Dispatch const> : public UniqueHandle<Type, Dispatch> {};

//! @relates UniqueHandle
template <typename Type, typename Dispatch>
OPENXR_HPP_INLINE void swap(UniqueHandle<Type, Dispatch> &lhs, UniqueHandle<Type, Dispatch> &rhs) {
    lhs.swap(rhs);
}

//! @brief Equality comparison between two UniqueHandles, potentially of different dispatch.
//! @relates UniqueHandle
template <typename Type, typename D1, typename D2>
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(UniqueHandle<Type, D1> const &lhs, UniqueHandle<Type, D2> const &rhs) {
    return lhs.get() == rhs.get();
}
//! @brief Inequality comparison between two UniqueHandles, potentially of different dispatch.
//! @relates UniqueHandle
template <typename Type, typename D1, typename D2>
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(UniqueHandle<Type, D1> const &lhs, UniqueHandle<Type, D2> const &rhs) {
    return lhs.get() != rhs.get();
}
//! @brief Equality comparison between UniqueHandle and nullptr: true if the handle is
//! null.
//! @relates UniqueHandle
template <typename Type, typename Dispatch>
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(UniqueHandle<Type, Dispatch> const &lhs, std::nullptr_t /* unused */) {
    return lhs.get() == XR_NULL_HANDLE;
}
//! @brief Equality comparison between nullptr and UniqueHandle: true if the handle is
//! null.
//! @relates UniqueHandle
template <typename Type, typename Dispatch>
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(std::nullptr_t /* unused */, UniqueHandle<Type, Dispatch> const &rhs) {
    return rhs.get() == XR_NULL_HANDLE;
}
//! @brief Inequality comparison between UniqueHandle and nullptr: true if the handle
//! is not null.
//! @relates UniqueHandle
template <typename Type, typename Dispatch>
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(UniqueHandle<Type, Dispatch> const &lhs, std::nullptr_t /* unused */) {
    return lhs.get() != XR_NULL_HANDLE;
}
//! @brief Inequality comparison between nullptr and UniqueHandle: true if the handle
//! is not null.
//! @relates UniqueHandle
template <typename Type, typename Dispatch>
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(std::nullptr_t /* unused */, UniqueHandle<Type, Dispatch> const &rhs) {
    return rhs.get() != XR_NULL_HANDLE;
}
#endif

template <typename Dispatch>
class ObjectDestroy {
   public:
    ObjectDestroy(Dispatch const &dispatch = Dispatch()) : m_dispatch(&dispatch) {}

   protected:
    template <typename T>
    void destroy(T t) {
        t.destroy(*m_dispatch);
    }

   private:
    Dispatch const *m_dispatch;
};
}  // namespace OPENXR_HPP_NAMESPACE
