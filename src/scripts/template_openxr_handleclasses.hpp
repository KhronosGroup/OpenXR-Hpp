namespace OPENXR_HPP_NAMESPACE {

// forward declarations

template <ObjectType o>
struct cpp_type;

//# for handle in gen.api_handles
class /*{ project_type_name(handle.name) }*/;
//# endfor

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

//! /*{cur_cmd.name}*/ wrapper
template </*{ method.template_decls }*/>
/*{method.return_type}*/ /*{method.cpp_name}*/ (
    /*{ method.get_declaration_params() | join(", ")}*/) /*{method.qualifiers}*/;

//# if hide_simple
#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
//# else
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
//# endif

    //! /*{cur_cmd.name}*/ wrapper - enhanced mode
    template </*{ enhanced.template_decls }*/>
    /*{enhanced.return_type}*/ /*{enhanced.cpp_name}*/ (
        /*{ enhanced.get_declaration_params() | join(", ")}*/) /*{enhanced.qualifiers}*/;

//# if enhanced.is_two_call
//! /*{cur_cmd.name}*/ wrapper - enhanced mode, stateful allocator
    template </*{ enhanced.template_decls }*/>
    /*{enhanced.return_type}*/ /*{enhanced.cpp_name}*/ (
        /*{ enhanced.get_declaration_params(extras=["Allocator const& vectorAllocator"], suppress_default_dispatch_arg=true) | join(", ")}*/) /*{enhanced.qualifiers}*/;

//# endif
    //# if enhanced.is_create
#ifndef OPENXR_HPP_NO_SMART_HANDLE

    //#     set uniq = unique_cmds[cur_cmd.name]
    //! /*{cur_cmd.name}*/ wrapper returning a smart handle
    template </*{ uniq.template_decls }*/>
    /*{uniq.return_type}*/ /*{uniq.cpp_name}*/ (
        /*{ uniq.get_declaration_params() | join(", ")}*/) /*{uniq.qualifiers}*/;
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
    //# endif

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

/*{ discouraged_end(cur_cmd) }*/ 
/*{ protect_end(cur_cmd, context) }*/
//# endmacro

//# for handle in gen.api_handles
//# set shortname = project_type_name(handle.name)

/*{- protect_begin(handle) }*/
#ifndef OPENXR_HPP_NO_SMART_HANDLE

template <typename Dispatch>
class UniqueHandleTraits</*{shortname}*/, Dispatch> {
   public:
    using deleter = ObjectDestroy<Dispatch>;
};
using /*{'Unique' + shortname}*/ = UniqueHandle</*{shortname}*/, DispatchLoaderStatic>;
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/

class /*{shortname}*/ {
   public:
    using Type = /*{ shortname }*/;
    using RawHandleType = /*{handle.name}*/;
    OPENXR_HPP_CONSTEXPR /*{shortname -}*/ () : m_raw(XR_NULL_HANDLE) {}

    OPENXR_HPP_CONSTEXPR /*{shortname -}*/ (std::nullptr_t /* unused */) : m_raw(XR_NULL_HANDLE) {}

    OPENXR_HPP_TYPESAFE_EXPLICIT /*{shortname -}*/ (RawHandleType handle) : m_raw(handle) {}

#if defined(OPENXR_HPP_TYPESAFE_CONVERSION)
    Type &operator=(RawHandleType handle) {
        m_raw = handle;
        return *this;
    }
#endif

    Type &operator=(std::nullptr_t /* unused */) {
        m_raw = XR_NULL_HANDLE;
        return *this;
    }

    OPENXR_HPP_CONSTEXPR OPENXR_HPP_TYPESAFE_EXPLICIT operator RawHandleType() const { return m_raw; }

    OPENXR_HPP_CONSTEXPR explicit operator bool() const { return m_raw != XR_NULL_HANDLE; }

    OPENXR_HPP_CONSTEXPR bool operator!() const { return m_raw == XR_NULL_HANDLE; }

    RawHandleType *put() {
        m_raw = XR_NULL_HANDLE;
        return &m_raw;
    }
    OPENXR_HPP_CONSTEXPR RawHandleType get() const { return m_raw; }

    //## Generate "member function" prototypes
    //# for cur_cmd in sorted_cmds if cur_cmd.params[0].type == handle.name
/*{ method_prototypes(cur_cmd, handle) }*/

//# endfor

   private:
    RawHandleType m_raw;
};
static_assert(sizeof(/*{ shortname }*/) == sizeof(/*{handle.name}*/), "handle and wrapper have different size!");

OPENXR_HPP_INLINE bool operator==(/*{shortname}*/ const &lhs, /*{shortname}*/ const &rhs) { return lhs.get() == rhs.get(); }
OPENXR_HPP_INLINE bool operator==(/*{shortname}*/ const &lhs, /*{handle.name}*/ rhs) { return lhs.get() == rhs; }
OPENXR_HPP_INLINE bool operator==(/*{handle.name}*/ lhs, /*{shortname}*/ const &rhs) { return rhs == lhs; }
OPENXR_HPP_INLINE bool operator==(/*{shortname}*/ const &lhs, std::nullptr_t /* unused */) { return lhs.get() == XR_NULL_HANDLE; }
OPENXR_HPP_INLINE bool operator==(std::nullptr_t /* unused */, /*{shortname}*/ const &rhs) { return rhs.get() == XR_NULL_HANDLE; }
OPENXR_HPP_INLINE bool operator!=(/*{shortname}*/ const &lhs, /*{shortname}*/ const &rhs) { return !(lhs == rhs); }
OPENXR_HPP_INLINE bool operator!=(/*{shortname}*/ const &lhs, /*{handle.name}*/ rhs) { return !(lhs == rhs); }
OPENXR_HPP_INLINE bool operator!=(/*{handle.name}*/ lhs, /*{shortname}*/ const &rhs) { return !(lhs == rhs); }
OPENXR_HPP_INLINE bool operator!=(/*{shortname}*/ const &lhs, std::nullptr_t /* unused */) { return lhs.get() != XR_NULL_HANDLE; }
OPENXR_HPP_INLINE bool operator!=(std::nullptr_t /* unused */, /*{shortname}*/ const &rhs) { return rhs.get() != XR_NULL_HANDLE; }

OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR /*{handle.name}*/ get(/*{shortname}*/ const &h) { return h.get(); }

OPENXR_HPP_INLINE /*{handle.name}*/ *put(/*{shortname}*/ &h) { return h.put(); }

OPENXR_HPP_INLINE /*{handle.name}*/ *put(/*{shortname}*/ *h) { return h->put(); }

template <>
struct cpp_type<ObjectType::/*{shortname}*/> {
    using type = /*{shortname}*/;
};

/*{- protect_end(handle) }*/

//# endfor

//## Generate free-function prototypes

    //# for cur_cmd in sorted_cmds if not cur_cmd.handle
/*{ method_prototypes(cur_cmd, none) }*/
    //# endfor

}  // namespace OPENXR_HPP_NAMESPACE
