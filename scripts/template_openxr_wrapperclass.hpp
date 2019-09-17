//## This file is typically used by extending: see e.g. time and duration
//# set raw_type = "Xr" + type

//## By default, assume these are "small" and should be passed by value
//# if not input_param_type
//#     set input_param_type = type
//# endif

//## Default to only providing equality/inequality
//# if not comparison_operators
//#     set comparison_operators = ('==', '!=')
//# endif

//# block comment_class
//! /*{ raw_type }*/ wrapper class
//!
//! See the related specification text at /*{ make_spec_url(type) }*/
//# endblock comment_class
class /*{ type }*/ {
   public:

//# block member_types
//# endblock member_types

    /*!
     * @name Constructors, assignment, and conversions
     * @{
     */
//# block constructor_default
    //! Default constructor.
    OPENXR_HPP_CONSTEXPR /*{ type }*/ () = default;
//# endblock constructor_default

//# block constructor_explicit
    //! Explicit constructor from raw /*{ raw_type }*/
    OPENXR_HPP_CONSTEXPR explicit /*{ type }*/ (/*{ raw_type }*/ v) noexcept : val_(v) {}
//# endblock constructor_explicit

//# block extra_constructors_conversion_assign
//# endblock extra_constructors_conversion_assign

    //! @}

//# block validity
    /*!
     * @name Validity checking
     * @{
     */
//# block conversion_explicit_bool
    //# if invalid
    //! Returns true in conditionals if this /*{ type }*/ is valid
    OPENXR_HPP_CONSTEXPR explicit operator bool() const noexcept { return val_ != /*{ invalid }*/; }
    //# endif
//# endblock conversion_explicit_bool

//# block operator_negation
    //# if invalid
    //! Unary negation: True if this /*{ type }*/ is invalid
    OPENXR_HPP_CONSTEXPR bool operator!() const noexcept { return val_ == /*{ invalid }*/; }
    //# endif
//# endblock operator_negation

//# block extra_validity
//# endblock extra_validity
    //! @}
//# endblock validity

    //! @name Raw /*{ raw_type }*/ manipulation
    //! @{

//# block method_get
    //! Gets the raw /*{ raw_type }*/ type.
    OPENXR_HPP_CONSTEXPR /*{ raw_type }*/ get() const noexcept { return val_; }
//# endblock method_get

//# block method_put
    //! @brief Clears this value, then returns the address of the raw /*{ raw_type }*/ type,
    //! for use in creation/assignment.
    /*{ raw_type }*/ *put() noexcept {
        val_ = /*{ invalid if invalid else "0"}*/;
        return &val_;
    }
//# endblock method_put
    //! @}

//# block extra_methods
//# endblock extra_methods

   private:
    /*{ raw_type }*/ val_{/*{ invalid }*/};
};

//# block size_assert
static_assert(sizeof(/*{ type }*/) == sizeof(/*{raw_type}*/), "raw type and wrapper have different size!");
//# endblock size_assert

//# block free_get
//! @brief Free function for getting the raw /*{ raw_type }*/ from /*{type}*/.
//!
//! Should be found via argument-dependent lookup and thus not need explicit namespace qualification.
//! @see /*{type}*/::get()
//! @relates /*{type}*/
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE /*{ raw_type }*/ get(/*{input_param_type}*/ v) noexcept { return v.get(); }
//# endblock free_get

//# block free_put
//! @brief Free function for clearing and getting the raw /*{ raw_type }*/ from /*{type}*/.
//!
//! Should be found via argument-dependent lookup and thus not need explicit namespace qualification.
//! @see /*{type}*/::put()
//! @relates /*{type}*/
OPENXR_HPP_INLINE /*{ raw_type }*/ *put(/*{type}*/ &v) noexcept { return v.put(); }
//# endblock free_put

//# block comparisons

//# block compare_self
//# for op in comparison_operators
//! @brief `/*{op}*/` comparison between /*{type}*/.
//! @relates /*{type}*/
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator/*{- op -}*/(/*{input_param_type}*/ lhs, /*{input_param_type}*/ rhs) noexcept {
    return lhs.get() /*{- op -}*/ rhs.get();
}
//# endfor
//# endblock compare_self

//# block compare_raw
//# for op in comparison_operators
//! @brief `/*{op}*/` comparison between /*{type}*/ and raw /*{raw_type}*/.
//! @relates /*{type}*/
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator/*{- op -}*/(/*{input_param_type}*/ lhs, /*{raw_type}*/ rhs) noexcept {
    return lhs.get() /*{- op -}*/ rhs;
}
//! @brief `/*{op}*/` comparison between raw /*{raw_type}*/ and /*{type}*/.
//! @relates /*{type}*/
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator/*{- op -}*/(/*{raw_type}*/ lhs, /*{input_param_type}*/ rhs) noexcept {
    return lhs /*{- op -}*/ rhs.get();
}
//# endfor
//# endblock compare_raw

//# endblock comparisons

//# block extra_free_functions
//# endblock extra_free_functions
