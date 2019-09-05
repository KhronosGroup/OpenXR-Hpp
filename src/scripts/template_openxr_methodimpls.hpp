
namespace OPENXR_HPP_NAMESPACE {

//# for cur_cmd in sorted_cmds
// /*{ cur_cmd }*/
//#     if cur_cmd.handle is not none
//#         set qualified_name = project_type_name(cur_cmd.handle_type) + "::" + member_function_name(cur_cmd.name)
//#         set qualifiers = "const"
//#     else
//#         set qualified_name = member_function_name(cur_cmd.name)
//#         set qualifiers = ""
//#     endif
//## Should we hide the result-returning function in enhanced mode?
//#     set hide_simple = not cur_cmd.is_create_connect
//#     set successes = filter_for_success_codes(cur_cmd.return_values)
//#     if (successes | length) > 1
//#         set successes_arg = ", {" + (successes | join(', ')) + "}"
//#     else
//#         set successes_arg = ""
//#     endif
/*{ protect_begin(cur_cmd) }*/
//# if hide_simple
#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
//# endif
template <typename Dispatch>
OPENXR_HPP_INLINE Result /*{ qualified_name -}*/ (
    /*{- project_params_for_definition(cur_cmd) -}*/) /*{qualifiers}*/ {
    return static_cast<Result>(d./*{ cur_cmd.name -}*/ (/*{ project_params_for_implementation(cur_cmd) }*/));
}
//# if hide_simple
#endif /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
//# endif

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
//# if cur_cmd.is_create_connect
//#     set out_param = cur_cmd.params[-1]
//#     set out_type = project_type_name(out_param.type)
template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType</*{ out_type }*/>::type /*{ qualified_name -}*/ (
    /*{- project_params_for_definition(cur_cmd, enhanced=true) -}*/) /*{qualifiers}*/ {
    /*{ out_type }*/ handle;
    Result result =
        static_cast<Result>(d./*{ cur_cmd.name -}*/ (/*{ project_params_for_implementation(cur_cmd, true) }*/, handle.put()));
    return createResultValue(result, handle,
                             OPENXR_HPP_NAMESPACE_STRING "::" /*{- qualified_name | quote_string-}*/ /*{successes_arg}*/);
}

#ifndef OPENXR_HPP_NO_SMART_HANDLE
template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<UniqueHandle</*{ out_type }*/, Dispatch>>::type /*{ qualified_name + "Unique" -}*/ (
    /*{- project_params_for_definition(cur_cmd, enhanced=true) -}*/) /*{qualifiers}*/ {
    /*{ out_type }*/ handle;
    Result result =
        static_cast<Result>(d./*{ cur_cmd.name -}*/ (/*{ project_params_for_implementation(cur_cmd, true) }*/, handle.put()));
    ObjectDestroy<Dispatch> deleter(d);
    return createResultValue</*{ out_type }*/, Dispatch>(
        result, handle, OPENXR_HPP_NAMESPACE_STRING "::" /*{ (qualified_name + "Unique") | quote_string -}*/, deleter);
}
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
//# else
//## Not create/connect
template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<void>::type /*{ qualified_name -}*/ (
    /*{- project_params_for_definition(cur_cmd, enhanced=true) -}*/) /*{qualifiers}*/ {
    Result result =
        static_cast<Result>(d./*{ cur_cmd.name -}*/ (/*{ project_params_for_implementation(cur_cmd, enhanced=true) }*/));
    return createResultValue(result, OPENXR_HPP_NAMESPACE_STRING "::" /*{- qualified_name | quote_string-}*/ /*{successes_arg}*/);
}
//# endif
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/
/*{ protect_end(cur_cmd) }*/
//# endfor

//## Must manually provide this one for ease of use.
template <typename Dispatch = DispatchLoaderStatic>
OPENXR_HPP_INLINE Result createInstance(const XrInstanceCreateInfo *createInfo, Instance &instance, Dispatch &&d = Dispatch()) {
    return static_cast<Result>(d.xrCreateInstance(createInfo, instance.put()));
}
#if 1
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<Instance>::type createInstance(const XrInstanceCreateInfo &createInfo, Dispatch &&d) {
    Instance instance;
    Result result = static_cast<Result>(d.xrCreateInstance(&createInfo, instance.put()));
    return createResultValue(result, instance, OPENXR_HPP_NAMESPACE_STRING "::createInstance");
}
#ifndef OPENXR_HPP_NO_SMART_HANDLE
template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<UniqueHandle<Instance, Dispatch>>::type createInstanceUnique(
    const XrInstanceCreateInfo &createInfo, Dispatch &&d) {
    Instance instance;
    Result result = static_cast<Result>(d.xrCreateInstance(&createInfo, instance.put()));

    ObjectDestroy<Dispatch> deleter(d);
    return createResultValue<Instance, Dispatch>(result, instance, OPENXR_HPP_NAMESPACE_STRING "::createInstanceUnique", deleter);
}
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/
#endif

}  // namespace OPENXR_HPP_NAMESPACE
