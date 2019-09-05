
namespace OPENXR_HPP_NAMESPACE {
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
