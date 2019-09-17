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
using Type = /*{ shortname }*/;
using RawHandleType = /*{handle.name}*/;
//# endblock

//# block constructor_default
//! Default (empty/null) constructor
OPENXR_HPP_CONSTEXPR /*{shortname -}*/ () : val_(XR_NULL_HANDLE) {}
//# endblock
//# block constructor_explicit
//! @brief Conversion constructor from the raw /*{handle.name}*/ type
//!
//! Explicit on 32-bit platforms by default unless OPENXR_HPP_TYPESAFE_CONVERSION is defined.
OPENXR_HPP_TYPESAFE_EXPLICIT /*{shortname -}*/ (RawHandleType handle) : val_(handle) {}
//# endblock

//# block extra_constructors_conversion_assign
//! Constructor from nullptr - creates empty/null handle.
OPENXR_HPP_CONSTEXPR /*{shortname -}*/ (std::nullptr_t /* unused */) : val_(XR_NULL_HANDLE) {}

#if defined(OPENXR_HPP_TYPESAFE_CONVERSION)
//! @brief Assignment operator from the raw /*{handle.name}*/
//!
//! Does *not* destroy any contained non-null handle first! For that, see UniqueHandle<>.
//!
//! Only provided if OPENXR_HPP_TYPESAFE_CONVERSION is defined (defaults to only on 64-bit).
Type &operator=(RawHandleType handle) {
    val_ = handle;
    return *this;
}
#endif

//! @brief Assignment operator from nullptr - assigns to empty/null handle.
//!
//! Does *not* destroy any contained non-null handle first! For that, see UniqueHandle<>.
Type &operator=(std::nullptr_t /* unused */) {
    val_ = XR_NULL_HANDLE;
    return *this;
}

//! @brief Conversion operator to the raw /*{handle.name}*/ type
//!
//! Explicit on 32-bit platforms by default unless OPENXR_HPP_TYPESAFE_CONVERSION is defined.
OPENXR_HPP_CONSTEXPR OPENXR_HPP_TYPESAFE_EXPLICIT operator RawHandleType() const { return val_; }
//# endblock

//# block method_put
//! @brief "Put" function for assigning as null then getting the address of the raw pointer to pass to creation functions.
//!
//! e.g.
//! ```
//! /*{shortname}*/ yourHandle;
//! auto result = d.xrCreate/*{shortname}*/(..., yourHandle.put()));
//! ```
//!
//! See also OPENXR_HPP_NAMESPACE::put()
RawHandleType *put() {
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
//# for cur_cmd in sorted_cmds if cur_cmd.params[0].type == handle.name
/*{ method_prototypes(cur_cmd, handle) }*/

//# endfor

//! @}

//# endblock

//# block extra_free_functions
//! @brief Equality comparison between /*{shortname}*/ and nullptr: true if the handle is null.
//! @relates /*{shortname}*/
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(/*{shortname}*/ const &lhs, std::nullptr_t /* unused */) {
    return lhs.get() == XR_NULL_HANDLE;
}
//! @brief Equality comparison between nullptr and /*{shortname}*/: true if the handle is null.
//! @relates /*{shortname}*/
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(std::nullptr_t /* unused */, /*{shortname}*/ const &rhs) {
    return rhs.get() == XR_NULL_HANDLE;
}
//! @brief Inequality comparison between /*{shortname}*/ and nullptr: true if the handle is not null.
//! @relates /*{shortname}*/
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(/*{shortname}*/ const &lhs, std::nullptr_t /* unused */) {
    return lhs.get() != XR_NULL_HANDLE;
}
//! @brief Inequality comparison between nullptr and /*{shortname}*/: true if the handle is not null.
//! @relates /*{shortname}*/
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(std::nullptr_t /* unused */, /*{shortname}*/ const &rhs) {
    return rhs.get() != XR_NULL_HANDLE;
}
//# endblock

//# block free_put
//! @brief Free "put" function for clearing and getting the address of the raw /*{handle.name}*/ handle in a /*{shortname}*/ (by
//! reference).
//!
//! e.g.
//! ```
//! /*{shortname}*/ yourHandle;
//! auto result = d.xrCreate/*{shortname}*/(..., put(yourHandle));
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the namespace specified.
//! @relates /*{shortname}*/
OPENXR_HPP_INLINE /*{ raw_type }*/ *put(/*{type}*/ &v) noexcept { return v.put(); }

//! @brief Free "put" function for clearing and getting the address of the raw /*{handle.name}*/ handle in a /*{shortname}*/ (by
//! pointer).
//!
//! e.g.
//! ```
//! void yourFunction(/*{shortname}*/* yourHandle) {
//!     auto result = d.xrCreate/*{shortname}*/(..., put(yourHandle));
//!     ....
//! }
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the namespace specified.
//! @relates /*{shortname}*/
OPENXR_HPP_INLINE /*{handle.name}*/ *put(/*{shortname}*/ *h) noexcept {
    OPENXR_HPP_ASSERT(h != nullptr);
    return h->put();
}
//# endblock
