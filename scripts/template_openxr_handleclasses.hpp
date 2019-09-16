namespace OPENXR_HPP_NAMESPACE {

//! Type traits
namespace traits {
//! Type trait associating an ObjectType enum value with its C++ type.
template <ObjectType o>
struct cpp_type;
}  // namespace traits

// forward declarations

//# for handle in gen.api_handles
class /*{ project_type_name(handle.name) }*/;
//# endfor

/*% macro shared_comments(cur_cmd, method) -%*/
//!
//! See the related specification text at /*{ make_spec_url(cur_cmd.name) }*/
/*% if not method.is_core %*/
//!
//! @note No default dispatch is provided as this is a non-core function,
//! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
/*%- endif -%*/
/*%- endmacro -%*/

//# macro enhanced_method_behavior(enhanced)
//
//# if enhanced.bare_return_type == "void" and enhanced.successes_arg
//## No return value, has non-Success success codes
// - Returns Result (which may be Result::Success, or a non-Result::Success success code)

//# elif enhanced.bare_return_type == "void"
//## No return value, only Result::Success or errors
// - Returns nothing (void)

//# elif enhanced.successes_arg
//## Some return value, has non-Success success codes
// - Returns ResultValue</*{enhanced.bare_return_type}*/>, containing both a Result (which may be
// Result::Success, or a non-Result::Success success code) and /*{enhanced.prose_bare_return}*/.

//# else
//## Some return value, only Result::Success or errors
// - Returns the value of type /*{enhanced.bare_return_type}*/
//# endif
//
// If OPENXR_HPP_NO_EXCEPTIONS is defined:
//

// - Asserts that result is /*{ "one of the expected success codes." if enhanced.successes_arg else "Result::Success." }*/

//# if enhanced.bare_return_type == "void" and enhanced.successes_arg
//## No return value, has non-Success success codes
// - Returns Result (which may be an error, Result::Success, or a non-Result::Success success code).

//# elif enhanced.bare_return_type == "void"
//## No return value, only Result::Success or errors
// - Returns Result.

//# elif enhanced.successes_arg
//## Some return value, has non-Success success codes
// - Returns ResultValue</*{enhanced.bare_return_type}*/>, containing both a Result (which may be an error,
// Result::Success, or a non-Result::Success success code) and /*{enhanced.prose_bare_return}*/.
//# else
//## Some return value, only Result::Success or errors
// - Returns the output of type /*{enhanced.bare_return_type}*/.
//# endif
//# endmacro

//# macro method_prototypes(cur_cmd, context)

/*{- protect_begin(cur_cmd, context) }*/
/*{- discouraged_begin(cur_cmd) }*/
//#     set method = basic_cmds[cur_cmd.name]
//#     set enhanced = enhanced_cmds[cur_cmd.name]

//## Should we hide the result-returning function in enhanced mode?
//#     set hide_simple = enhanced.masks_simple

//# if hide_simple
#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
//# endif

//# filter block_doxygen_comment
//! @brief /*{cur_cmd.name}*/ wrapper.
/*{ shared_comments(cur_cmd, method) }*/
//# endfilter
template </*{ method.template_decls }*/>
/*{method.return_type}*/ /*{method.cpp_name}*/ (
    /*{ method.get_declaration_params() | join(", ")}*/) /*{method.qualifiers}*/;

//# if hide_simple
#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
//# else
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
//# endif

//# filter block_doxygen_comment
    //! @brief /*{cur_cmd.name}*/ wrapper - enhanced mode/*% if hide_simple %*/ (hides basic wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined)/*% endif %*/. /*%- if enhanced.is_two_call %*/Performs two-call idiom./*% endif %*/
    /*{ enhanced_method_behavior(enhanced) }*/
    /*{ shared_comments(cur_cmd, enhanced) }*/
//# endfilter
    template </*{ enhanced.template_decls }*/>
    /*{enhanced.return_type}*/ /*{enhanced.cpp_name}*/ (
        /*{ enhanced.get_declaration_params() | join(", ")}*/) /*{enhanced.qualifiers}*/;

//# if enhanced.is_two_call
//# filter block_doxygen_comment
    //! @brief /*{cur_cmd.name}*/ wrapper - enhanced mode. Performs two-call idiom with a stateful allocator.
    /*{ enhanced_method_behavior(enhanced) }*/
    /*{ shared_comments(cur_cmd, enhanced) }*/
//# endfilter
    template </*{ enhanced.template_decls }*/>
    /*{enhanced.return_type}*/ /*{enhanced.cpp_name}*/ (
        /*{ enhanced.get_declaration_params(extras=["Allocator const& vectorAllocator"], suppress_default_dispatch_arg=true) | join(", ")}*/) /*{enhanced.qualifiers}*/;

//# endif
    //# if enhanced.is_create
#ifndef OPENXR_HPP_NO_SMART_HANDLE

    //#     set uniq = unique_cmds[cur_cmd.name]

//# filter block_doxygen_comment
    //! @brief /*{cur_cmd.name}*/ wrapper returning a smart handle.
    /*{ enhanced_method_behavior(uniq) }*/
    /*{ shared_comments(cur_cmd, uniq) }*/
//# endfilter
    template </*{ uniq.template_decls }*/>
    /*{uniq.return_type}*/ /*{uniq.cpp_name}*/ (
        /*{ uniq.get_declaration_params() | join(", ")}*/) /*{uniq.qualifiers}*/;
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
    //# endif

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

/*{ discouraged_end(cur_cmd) }*/
/*{ protect_end(cur_cmd, context) }*/
//# endmacro

/*!
 * @defgroup handles Handle types
 * @brief Wrappers for OpenXR handle types, with associated functions mapped as methods.
 * @{
 */
/*!
 * @defgroup unique_handle_aliases Aliases for UniqueHandle types
 * @brief Convenience names for specializations of UniqueHandle<>
 */
//! @}

//# for handle in gen.api_handles
//# set shortname = project_type_name(handle.name)

/*{- protect_begin(handle) }*/
#ifndef OPENXR_HPP_NO_SMART_HANDLE

namespace traits {
//! Traits associating a deleter type with handles of type /*{shortname}*/
template <typename Dispatch>
class UniqueHandleTraits</*{shortname}*/, Dispatch> {
   public:
    using deleter = ObjectDestroy<Dispatch>;
};
} //namespace traits

//! @addtogroup unique_handle_aliases
//! @{

//## TODO use DispatchLoaderDynamic for extension-provided handles!
//! Shorthand name for unique handles of type /*{shortname}*/, using a static dispatch.
using /*{'Unique' + shortname}*/ = UniqueHandle</*{shortname}*/, DispatchLoaderStatic>;
//! Shorthand name for unique handles of type /*{shortname}*/, using a dynamic dispatch.
using /*{'UniqueDynamic' + shortname}*/ = UniqueHandle</*{shortname}*/, DispatchLoaderDynamic>;
//! @}
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/

//# include "template_openxr_handle.hpp"

namespace traits {
//! @brief Explicit specialization of cpp_type for /*{shortname}*/
template <>
struct cpp_type<ObjectType::/*{shortname}*/> {
    using type = /*{shortname}*/;
};
} // namespace traits

/*{- protect_end(handle) }*/

//# endfor

//## Generate free-function prototypes
/*!
 * @defgroup api_free_functions OpenXR API free functions
 *
 * Equivalent to the method wrappers in the handle classes,
 * but for the few functions that don't take (or don't require)
 * a handle as their first argument.
 * @{
 */
// Forward declarations - implementations at the bottom of the file

//# for cur_cmd in sorted_cmds if not cur_cmd.handle
/*{ method_prototypes(cur_cmd, none) }*/
//# endfor

//! @}

}  // namespace OPENXR_HPP_NAMESPACE
