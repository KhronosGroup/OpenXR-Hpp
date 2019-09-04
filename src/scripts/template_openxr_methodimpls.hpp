
namespace OPENXR_HPP_NAMESPACE {

//# for cur_cmd in sorted_cmds
//#     if gen.isHandle(cur_cmd.params[0].type)
/*{ protect_begin(cur_cmd) }*/
//#         set param_decl_list = member_function_params(cur_cmd) + ["Dispatch const &d"]
template <typename Dispatch>
OPENXR_HPP_INLINE /*{cur_cmd.return_type.text}*/ /*{cur_cmd.params[0].type | replace("Xr", "") -}*/ ::
    /*{- member_function_name(cur_cmd.name) -}*/ (/*{- project_params_for_definition(cur_cmd) -}*/) const {
    d./*{ cur_cmd.name -}*/ (/*{ project_params_for_implementation(cur_cmd) }*/);
}
/*{ protect_end(cur_cmd) }*/
//#     endif
//# endfor

//## Must manually provide this one for ease of use.
template <typename Dispatch = DispatchLoaderStatic>
OPENXR_HPP_INLINE XrResult createInstance(const XrInstanceCreateInfo *createInfo, Instance &instance,
                                          Dispatch const &d = Dispatch()) {
    return d.xrCreateInstance(createInfo, instance.put());
}

}  // namespace OPENXR_HPP_NAMESPACE
