//## This file is typically used by extending: see e.g. time and duration
//# set raw_type = "Xr" + type

//## By default, assume these are "small" and should be passed by value
//# if not input_param_type
//#     set input_param_type = type
//# endif

//! /*{ raw_type }*/ wrapper class
//!
//! See the related specification text at /*{ make_spec_url(type) }*/
class /*{ type }*/ {
   public:
    //# block constructor_default
    //! Default constructor.
    OPENXR_HPP_CONSTEXPR /*{ type }*/ () = default;
    //# endblock

    //# block constructor_explicit
    //! Explicit constructor from raw /*{ raw_type }*/
    OPENXR_HPP_CONSTEXPR explicit /*{ type }*/ (/*{ raw_type }*/ v) noexcept : val_(v) {}
    //# endblock

    //# block conversion_explicit_bool
    //# if invalid
    //! True if this /*{ type }*/ is valid
    OPENXR_HPP_CONSTEXPR explicit operator bool() const noexcept { return val_ != /*{ invalid }*/; }
    //# endif
    //# endblock

    //# block method_get
    //! Gets the raw /*{ raw_type }*/ type.
    OPENXR_HPP_CONSTEXPR /*{ raw_type }*/ get() const noexcept { return val_; }
    //# endblock

    //# block method_put
    //! @brief Clears this value, then returns the address of the raw /*{ raw_type }*/ type,
    //! for use in creation/assignment.
    /*{ raw_type }*/ *put() noexcept {
        val_ = /*{ invalid if invalid else "0"}*/;
        return &val_;
    }
    //# endblock

    /*% block extra_methods %*/ /*% endblock %*/

   private:
    /*{ raw_type }*/ val_{/*{ invalid }*/};
};

//# block free_get
//! @brief Free function for getting the raw /*{ raw_type }*/ from /*{type}*/.
//!
//! Should be found via argument-dependent lookup and thus not need explicit namespace qualification.
//! @see /*{type}*/::get()
//! @relates /*{type}*/
OPENXR_HPP_CONSTEXPR inline /*{ raw_type }*/ get(/*{input_param_type}*/ v) noexcept { return v.get(); }
//# endblock

//# block free_put
//! @brief Free function for clearing and getting the raw /*{ raw_type }*/ from /*{type}*/.
//!
//! Should be found via argument-dependent lookup and thus not need explicit namespace qualification.
//! @see /*{type}*/::put()
//! @relates /*{type}*/
inline /*{ raw_type }*/ *put(/*{type}*/ &v) noexcept { return v.put(); }
//# endblock

//## Default to only providing equality/inequality
//# if not comparison_operators
//#     set comparison_operators = ('==', '!=')
//# endif

//# block compare_self
//# for op in comparison_operators
//! @brief `/*{op}*/` comparison between /*{type}*/.
//! @relates /*{type}*/
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator/*{- op -}*/(/*{input_param_type}*/ lhs, /*{input_param_type}*/ rhs) noexcept {
    return lhs.get() /*{- op -}*/ rhs.get();
}
//# endfor
//# endblock

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
//# endblock

/*% block extra_free_functions %*/ /*% endblock %*/
