namespace OPENXR_HPP_NAMESPACE {

// forward declarations

//# for handle in gen.api_handles
class /*{ project_type_name(handle.name) }*/;
//# endfor

//# for handle in gen.api_handles
//# set shortname = project_type_name(handle.name)
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

    OPENXR_HPP_TYPESAFE_EXPLICIT operator RawHandleType() const { return m_raw; }

    explicit operator bool() const { return m_raw != XR_NULL_HANDLE; }

    bool operator!() const { return m_raw == XR_NULL_HANDLE; }

    RawHandleType *put() {
        m_raw = XR_NULL_HANDLE;
        return &m_raw;
    }
    RawHandleType get() const { return m_raw; }

    //## Generate "member function" prototypes
    //# for cur_cmd in sorted_cmds

    //#     if cur_cmd.params[0].type == handle.name

    /*{- protect_begin(cur_cmd) }*/
    //#         if gen.isCoreExtensionName(cur_cmd.ext_name)
    //#             set dispatch_type_default = " = DispatchLoaderStatic"
    //#             set param_decl_list = member_function_params(cur_cmd) + ["Dispatch const &d = Dispatch()"]
    //#         else
    //#             set dispatch_type_default = ""
    //#             set param_decl_list = member_function_params(cur_cmd) + ["Dispatch const &d"]
    //#         endif
    //! /*{cur_cmd.name}*/ wrapper
    template <typename Dispatch /*{- dispatch_type_default}*/>
    /*{project_type_name(cur_cmd.return_type.text)}*/ /*{ member_function_name(cur_cmd.name) -}*/ (
        /*{- project_params_for_declaration(cur_cmd) -}*/) const;
    /*{ protect_end(cur_cmd) }*/

    //#     endif
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

#ifndef OPENXR_HPP_NO_SMART_HANDLE

template <typename Dispatch>
class UniqueHandleTraits</*{shortname}*/, Dispatch> {
   public:
    using deleter = ObjectDestroy<Dispatch>;
};
using /*{'Unique' + shortname}*/ = UniqueHandle</*{shortname}*/, DispatchLoaderStatic>;
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/

//# endfor

}  // namespace OPENXR_HPP_NAMESPACE
