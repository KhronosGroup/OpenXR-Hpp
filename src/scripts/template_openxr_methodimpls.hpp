
namespace OPENXR_HPP_NAMESPACE {

//# for cur_cmd in sorted_cmds
//## /*{ cur_cmd }*/

/*{ protect_begin(cur_cmd) }*/
//#     set method = basic_cmds[cur_cmd.name]
//#     set enhanced = enhanced_cmds[cur_cmd.name]

//## Should we hide the result-returning function in enhanced mode?
//#     set hide_simple = enhanced.masks_simple

//# if hide_simple
#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
//# endif
template </*{ method.template_defns }*/>
OPENXR_HPP_INLINE /*{method.return_type}*/ /*{method.qualified_name}*/ (
    /*{ method.get_definition_params() | join(", ")}*/) /*{ method.qualifiers }*/ {
    /*{ method.get_invocation() | join("\n") | indent}*/
}
//# if hide_simple
#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
//# else

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
//# endif

template </*{ enhanced.template_defns }*/>
OPENXR_HPP_INLINE /*{enhanced.return_type}*/ /*{enhanced.qualified_name}*/ (
    /*{ enhanced.get_definition_params() | join(", ")}*/) /*{enhanced.qualifiers}*/ {
    /*{ enhanced.get_invocation() | join("\n") | indent}*/
}

//# if enhanced.is_create
#ifndef OPENXR_HPP_NO_SMART_HANDLE

//#     set uniq = unique_cmds[cur_cmd.name]
template </*{ uniq.template_defns }*/>
OPENXR_HPP_INLINE /*{uniq.return_type}*/ /*{uniq.qualified_name}*/ (
    /*{ uniq.get_definition_params() | join(", ")}*/) /*{uniq.qualifiers}*/ {
    /*{ uniq.get_invocation() | join("\n") | indent}*/
}

#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
//# endif
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/
/*{ protect_end(cur_cmd) }*/
//# endfor


}  // namespace OPENXR_HPP_NAMESPACE
