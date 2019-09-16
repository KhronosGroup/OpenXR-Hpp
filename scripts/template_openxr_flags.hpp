
namespace OPENXR_HPP_NAMESPACE {

/*!
 * @defgroup enums Flags
 * @brief C++ flags classes corresponding to OpenXR C flags and flagbits, plus associated utility functions.
 * @{
 */

//# for flags in gen.api_flags
//#     set projected_type = project_type_name(flags.name)
//#     set bitmask = bitmask_for_flags(flags)
//#     set projected_bits_type = project_type_name(flags.valid_flags)
/*{ protect_begin(flags) }*/
//! @brief Flags class associated with /*{flags.name}*/
//!
//! See the related specification text at /*{ make_spec_url(flags.name) }*/
enum class /*{projected_bits_type }*/ : XrFlags64 {
    None = 0,
    //# for val in bitmask.values
    /*{ create_flag_value(val.name, flags.valid_flags) }*/ = /*{val.name}*/,
    //# endfor
    AllBits = 0
              //# for val in bitmask.values
              | /*{ val.name}*/
    //# endfor
};

using /*{projected_type }*/ = Flags</*{projected_bits_type }*/, /*{flags.name}*/>;

/*{ protect_end(flags) }*/
//# endfor

//! @}

}  // namespace OPENXR_HPP_NAMESPACE
