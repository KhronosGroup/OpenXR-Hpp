
namespace OPENXR_HPP_NAMESPACE {

//# for cur_cmd in sorted_cmds
//## /*{ cur_cmd }*/

/*{ protect_begin(cur_cmd) }*/
/*{ discouraged_begin(cur_cmd) }*/

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


//# if enhanced.is_two_call
template </*{ enhanced.template_defns }*/>
OPENXR_HPP_INLINE /*{enhanced.return_type}*/ /*{enhanced.qualified_name}*/ (
    /*{ enhanced.get_definition_params() | join(", ")}*/) /*{enhanced.qualifiers}*/ {
    // Two-call idiom
    /*{ enhanced.vec_type }*/ /*{ enhanced.array_param_name }*/;
    /*% set twocallbody %*/
    uint32_t /*{ enhanced.count_output_param_name }*/ = 0;
    uint32_t /*{ enhanced.capacity_input_param_name }*/ = 0;
    
    /*{ enhanced.pre_statements |join("\n") | indent }*/
    //# if enhanced.item_type == 'char'
    std::basic_string<char, std::char_traits<char>, Allocator> str{vectorAllocator};
    //# endif
    /*{ enhanced.get_main_invoke({enhanced.array_param_name: "nullptr"}) }*/
    if (!unqualifiedSuccess(result) || /*{ enhanced.count_output_param_name }*/ == 0) {

        /*{ enhanced.return_statement }*/
    }
    do {
        /*{ enhanced.array_param_name }*/.resize(/*{ enhanced.count_output_param_name }*/);
        /*{ enhanced.capacity_input_param_name }*/ = static_cast<uint32_t>(/*{enhanced.array_param_name}*/.size());
        //# set raw_array_param = enhanced.array_param_name + ".data()"
        //# set array_param = "reinterpret_cast<" + enhanced.array_param.param.type + "*>(" + raw_array_param + ")"
        /*{ enhanced.get_main_invoke({ enhanced.array_param_name: array_param }) | replace("Result ", "") }*/
    } while (result == xr::Result::ErrorSizeInsufficient);
    if (result == xr::Result::Success) {
        OPENXR_HPP_ASSERT(/*{ enhanced.count_output_param_name }*/ <= /*{enhanced.array_param_name}*/.size());
        /*{enhanced.array_param_name}*/.resize(/*{ enhanced.count_output_param_name }*/);
    }
    /*{ enhanced.post_statements |join("\n") | indent }*/
    //# if enhanced.item_type == 'char'
    str.assign(/*{ enhanced.array_param_name }*/.begin(), /*{ enhanced.array_param_name }*/.end());
    //# endif
    /*{ enhanced.return_statement }*/
    /*% endset %*/
    /*{ twocallbody |replace('vectorAllocator', '{}') }*/
}

template </*{ enhanced.template_defns }*/>
OPENXR_HPP_INLINE /*{enhanced.return_type}*/ /*{enhanced.qualified_name}*/ (
    //# set params = enhanced.get_definition_params(extras=["Allocator const& vectorAllocator"])
    /*{ params | join(", ")}*/) /*{enhanced.qualifiers}*/ {
    // Two-call idiom
    /*{ enhanced.vec_type }*/ /*{ enhanced.array_param_name }*/{vectorAllocator};
    /*{ twocallbody }*/
}
//# else
//## Not two-call

template </*{ enhanced.template_defns }*/>
OPENXR_HPP_INLINE /*{enhanced.return_type}*/ /*{enhanced.qualified_name}*/ (
    /*{ enhanced.get_definition_params() | join(", ")}*/) /*{enhanced.qualifiers}*/ {
    /*{ enhanced.get_invocation() | join("\n") | indent}*/
}
//# endif


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

/*{ discouraged_end(cur_cmd) }*/ 
/*{ protect_end(cur_cmd) }*/
//# endfor


}  // namespace OPENXR_HPP_NAMESPACE
