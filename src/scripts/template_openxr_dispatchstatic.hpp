
namespace OPENXR_HPP_NAMESPACE {
// Forward declaration
class DispatchLoaderDynamic;

/*!
 * Dispatch class for OpenXR core functions that uses exported, statically-available symbols.
 */
class DispatchLoaderStatic {
   public:
    /*
     * Core Commands
     */

    //# for cur_cmd in gen.core_commands
    /*{cur_cmd.cdecl | collapse_whitespace | replace(";", "")}*/ const {
        return ::/*{cur_cmd.name}*/ (/*{ forwardCommandArgs(cur_cmd) }*/);
    }
    //# endfor
};

}  // namespace OPENXR_HPP_NAMESPACE
