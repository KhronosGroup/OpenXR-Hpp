//# set type = shortname
//# set raw_type = handle.name
//# set input_param_type = type + " const&"
//# set invalid = "XR_NULL_HANDLE"
//# set comparison_operators = ('<', '>', '<=', '>=', '==', '!=')

//# extends "template_openxr_wrapperclass.hpp"

//# block comment_class
//! @brief Handle class - wrapping /*{raw_type}*/
//!
//! See the related specification text at /*{ make_spec_url(raw_type) }*/
//! @ingroup handles
//# endblock

//# block member_types
using Type = /*{ type }*/;
using RawHandleType = /*{raw_type}*/;
//# endblock member_types

//# block constructor_default
//! Default (empty/null) constructor
OPENXR_HPP_CONSTEXPR /*{ type }*/ () noexcept : val_(XR_NULL_HANDLE) {}
//# endblock constructor_default

//# block constructor_explicit
//! @brief Conversion constructor from the raw /*{raw_type}*/ type
//!
//! Explicit on 32-bit platforms by default unless OPENXR_HPP_TYPESAFE_CONVERSION is defined.
OPENXR_HPP_TYPESAFE_EXPLICIT /*{ type }*/ (RawHandleType handle) noexcept : val_(handle) {}
//# endblock constructor_explicit

//# block extra_constructors_conversion_assign
//! Constructor from nullptr - creates empty/null handle.
OPENXR_HPP_CONSTEXPR /*{ type }*/ (std::nullptr_t /* unused */) noexcept : val_(XR_NULL_HANDLE) {}

#if defined(OPENXR_HPP_TYPESAFE_CONVERSION)
//! @brief Assignment operator from the raw /*{raw_type}*/
//!
//! Does *not* destroy any contained non-null handle first! For that, see UniqueHandle<>.
//!
//! Only provided if OPENXR_HPP_TYPESAFE_CONVERSION is defined (defaults to only on 64-bit).
Type &operator=(RawHandleType handle) noexcept {
    val_ = handle;
    return *this;
}
#endif

//! @brief Assignment operator from nullptr - assigns to empty/null handle.
//!
//! Does *not* destroy any contained non-null handle first! For that, see UniqueHandle<>.
Type &operator=(std::nullptr_t /* unused */) noexcept {
    val_ = XR_NULL_HANDLE;
    return *this;
}

//! @brief Conversion operator to the raw /*{raw_type}*/ type
//!
//! Explicit on 32-bit platforms by default unless OPENXR_HPP_TYPESAFE_CONVERSION is defined.
OPENXR_HPP_CONSTEXPR OPENXR_HPP_TYPESAFE_EXPLICIT operator RawHandleType() const noexcept { return val_; }
//# endblock extra_constructors_conversion_assign

//# block method_put
//! @brief "Put" function for assigning as null then getting the address of the raw pointer to pass to creation functions.
//!
//! e.g.
//! ```
//! /*{type}*/ yourHandle;
//! auto result = d.xrCreate/*{- type -}*/(..., yourHandle.put()));
//! ```
//!
//! See also OPENXR_HPP_NAMESPACE::put()
RawHandleType *put() noexcept {
    val_ = XR_NULL_HANDLE;
    return &val_;
}
//# endblock

//# block extra_methods
/*!
 * @name OpenXR API calls as member functions
 * @{
 */
//## Generate "member function" prototypes
//# for cur_cmd in sorted_cmds if cur_cmd.params[0].type == raw_type
/*{ method_prototypes(cur_cmd, handle) }*/

//# endfor

//! @}
//# endblock extra_methods

//# block extra_free_functions
//! @brief Equality comparison between /*{type}*/ and nullptr: true if the handle is null.
//! @relates /*{type}*/
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(/*{type}*/ const &lhs, std::nullptr_t /* unused */) noexcept {
    return lhs.get() == XR_NULL_HANDLE;
}
//! @brief Equality comparison between nullptr and /*{type}*/: true if the handle is null.
//! @relates /*{type}*/
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(std::nullptr_t /* unused */, /*{type}*/ const &rhs) noexcept {
    return rhs.get() == XR_NULL_HANDLE;
}
//! @brief Inequality comparison between /*{type}*/ and nullptr: true if the handle is not null.
//! @relates /*{type}*/
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(/*{type}*/ const &lhs, std::nullptr_t /* unused */) noexcept {
    return lhs.get() != XR_NULL_HANDLE;
}
//! @brief Inequality comparison between nullptr and /*{type}*/: true if the handle is not null.
//! @relates /*{type}*/
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(std::nullptr_t /* unused */, /*{type}*/ const &rhs) noexcept {
    return rhs.get() != XR_NULL_HANDLE;
}
//# endblock extra_free_functions

//# block free_put
//! @brief Free "put" function for clearing and getting the address of the raw /*{raw_type}*/ handle in a /*{type}*/ (by
//! reference).
//!
//! e.g.
//! ```
//! /*{type}*/ yourHandle;
//! auto result = d.xrCreate/*{- type -}*/(..., put(yourHandle));
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the namespace specified.
//! @relates /*{type}*/
OPENXR_HPP_INLINE /*{ raw_type }*/ *put(/*{type}*/ &v) noexcept { return v.put(); }

//! @brief Free "put" function for clearing and getting the address of the raw /*{raw_type}*/ handle in a /*{type}*/ (by
//! pointer).
//!
//! e.g.
//! ```
//! void yourFunction(/*{type}*/* yourHandle) {
//!     auto result = d.xrCreate/*{- type -}*/(..., put(yourHandle));
//!     ....
//! }
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the namespace specified.
//! @relates /*{type}*/
OPENXR_HPP_INLINE /*{raw_type}*/ *put(/*{type}*/ *h) noexcept {
    OPENXR_HPP_ASSERT(h != nullptr);
    return h->put();
}
//# endblock free_put
