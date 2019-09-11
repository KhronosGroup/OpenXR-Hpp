namespace OPENXR_HPP_NAMESPACE {

// forward declarations

//! Type trait associating an ObjectType enum value with its C++ type.
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
//! /*{cur_cmd.name}*/ wrapper - enhanced mode, stateful allocator for two-call result
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

//! Traits associating a deleter type with handles of type /*{shortname}*/
template <typename Dispatch>
class UniqueHandleTraits</*{shortname}*/, Dispatch> {
   public:
    using deleter = ObjectDestroy<Dispatch>;
};

//## TODO use DispatchLoaderDynamic for extension-provided handles!
//! Shorthand name for unique handles of type /*{shortname}*/, using a static dispatch.
using /*{'Unique' + shortname}*/ = UniqueHandle</*{shortname}*/, DispatchLoaderStatic>;
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/

//! Handle class - wrapping /*{handle.name}*/
class /*{shortname}*/ {
   public:
    using Type = /*{ shortname }*/;
    using RawHandleType = /*{handle.name}*/;

    //! Default (empty/null) constructor
    OPENXR_HPP_CONSTEXPR /*{shortname -}*/ () : m_raw(XR_NULL_HANDLE) {}

    //! Constructor from nullptr - creates empty/null handle.
    OPENXR_HPP_CONSTEXPR /*{shortname -}*/ (std::nullptr_t /* unused */) : m_raw(XR_NULL_HANDLE) {}

    //! Conversion constructor from the raw /*{handle.name}*/ type
    //!
    //! Explicit on 32-bit platforms by default unless OPENXR_HPP_TYPESAFE_CONVERSION is defined.
    OPENXR_HPP_TYPESAFE_EXPLICIT /*{shortname -}*/ (RawHandleType handle) : m_raw(handle) {}

#if defined(OPENXR_HPP_TYPESAFE_CONVERSION)
    //! Assignment operator from the raw /*{handle.name}*/
    //!
    //! Does *not* destroy any contained non-null handle first! For that, see UniqueHandle<>.
    //!
    //! Only provided if OPENXR_HPP_TYPESAFE_CONVERSION is defined (defaults to only on 64-bit).
    Type &operator=(RawHandleType handle) {
        m_raw = handle;
        return *this;
    }
#endif

    //! Assignment operator from nullptr - assigns to empty/null handle.
    //!
    //! Does *not* destroy any contained non-null handle first! For that, see UniqueHandle<>.
    Type &operator=(std::nullptr_t /* unused */) {
        m_raw = XR_NULL_HANDLE;
        return *this;
    }

    //! Conversion operator to the raw /*{handle.name}*/ type
    //!
    //! Explicit on 32-bit platforms by default unless OPENXR_HPP_TYPESAFE_CONVERSION is defined.
    OPENXR_HPP_CONSTEXPR OPENXR_HPP_TYPESAFE_EXPLICIT operator RawHandleType() const { return m_raw; }

    //! Returns true in conditionals if this handle is non-null
    OPENXR_HPP_CONSTEXPR explicit operator bool() const { return m_raw != XR_NULL_HANDLE; }

    //! Negation operator: true if this handle is null
    OPENXR_HPP_CONSTEXPR bool operator!() const { return m_raw == XR_NULL_HANDLE; }

    //! "Put" function for assigning as null then getting the address of the raw pointer to pass to creation functions.
    //!
    //! See also OPENXR_HPP_NAMESPACE::put()
    RawHandleType *put() {
        m_raw = XR_NULL_HANDLE;
        return &m_raw;
    }

    //! Gets the raw handle type.
    //!
    //! See also OPENXR_HPP_NAMESPACE::get()
    OPENXR_HPP_CONSTEXPR RawHandleType get() const { return m_raw; }

    //## Generate "member function" prototypes
    //# for cur_cmd in sorted_cmds if cur_cmd.params[0].type == handle.name
/*{ method_prototypes(cur_cmd, handle) }*/

//# endfor

   private:
    RawHandleType m_raw;
};
static_assert(sizeof(/*{ shortname }*/) == sizeof(/*{handle.name}*/), "handle and wrapper have different size!");

//! Free function accessor for the raw /*{handle.name}*/ handle in a /*{shortname}*/
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE /*{handle.name}*/ get(/*{shortname}*/ const &h) { return h.get(); }

//! Free "put" function for clearing and getting the address of the raw /*{handle.name}*/ handle in a /*{shortname}*/ (by reference)
OPENXR_HPP_INLINE /*{handle.name}*/ *put(/*{shortname}*/ &h) { return h.put(); }

//! Free "put" function for clearing and getting the address of the raw /*{handle.name}*/ handle in a /*{shortname}*/ (by pointer)
OPENXR_HPP_INLINE /*{handle.name}*/ *put(/*{shortname}*/ *h) { return h->put(); }

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
