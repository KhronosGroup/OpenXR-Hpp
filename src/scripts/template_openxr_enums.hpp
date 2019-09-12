
namespace OPENXR_HPP_NAMESPACE {
/*!
 * @defgroup enums Enumerations
 * @brief C++ enum classes corresponding to OpenXR C enumerations, plus associated utility functions.
 *
 * All enumerations have three utility functions defined:
 *
 * - get() - returns the raw C enum value
 * - to_string_literal() - returns a const char* containing the C++ name
 * - to_string() - wraps to_string_literal(), returning a std::string
 *
 * @{
 */
//# for enum in gen.api_enums
//#     set projected_type = project_type_name(enum.name)
/*{ protect_begin(enum) }*/
//! @brief Enum class associated with /*{enum.name}*/
//!
//! See the related specification text at /*{ make_spec_url(enum.name) }*/
enum class /*{projected_type -}*/ : /*{ 'int32_t' if enum.name == 'XrResult' else 'uint32_t' }*/ {
    //# for val in enum.values
    /*{ protect_begin(val, enum) }*/
    /*{create_enum_value(val.name, enum.name)}*/ = /*{val.name}*/,
    /*{ protect_end(val, enum) }*/
    //# endfor
};

//! @brief Free function for retrieving the raw /*{enum.name}*/ value from a /*{projected_type}*/
//! @relates /*{projected_type}*/
OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR /*{enum.name}*/ get(/*{projected_type}*/ const& v) {
    return static_cast</*{enum.name}*/>(v);
}

//! @brief Free function for retrieving the string name of a /*{projected_type}*/ value as a const char *
//! @relates /*{projected_type}*/
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char* to_string_literal(/*{projected_type}*/ value) {
    switch (value) {
            //# for val in enum.values
        /*{ protect_begin(val, enum) }*/
        //# set valname = create_enum_value(val.name, enum.name)
        case /*{projected_type -}*/ ::/*{- valname }*/:
            return /*{ valname | quote_string }*/;
            /*{ protect_end(val, enum) }*/
            //# endfor
        default:
            return "invalid";
    }
}

//! @brief Free function for retrieving the string name of a /*{projected_type}*/ value as a std::string
//! @relates /*{projected_type}*/
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string to_string(/*{projected_type}*/ value) {
    return {to_string_literal(value)};
}

/*{ protect_end(enum) }*/
//# endfor

//! @}

}  // namespace OPENXR_HPP_NAMESPACE
