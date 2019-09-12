
namespace OPENXR_HPP_NAMESPACE {
// Forward declaration
class DispatchLoaderDynamic;
/*!
 * @defgroup dispatch Dispatch classes
 * @brief Classes providing a method or function pointer member for OpenXR APIs.
 *
 * The classes provided here are useful basic classes, but all places that can take a dispatch class are templated to be able to
 * accept any class that meets the requirements.
 */
/*!
 * @brief Dispatch class for OpenXR core functions that uses exported, statically-available symbols.
 *
 * Not for use in game engines or other multi-module software where different modules might want newer OpenXR APIs. If this is used,
 * all parts of an application must build against and use the same loader library.
 *
 * Does not provide extension functions because those are not exported from the loader library.
 *
 * @ingroup dispatch
 */
class DispatchLoaderStatic {
   public:
    /*!
     * @name Core Commands
     * @{
     */

    //# for cur_cmd in gen.core_commands
    /*{cur_cmd.cdecl | collapse_whitespace | replace(";", "")}*/ const {
        return ::/*{cur_cmd.name}*/ (/*{ forwardCommandArgs(cur_cmd) }*/);
    }
    //# endfor

    //! @}
};

}  // namespace OPENXR_HPP_NAMESPACE
