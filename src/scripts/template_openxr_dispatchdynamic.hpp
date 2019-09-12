
namespace OPENXR_HPP_NAMESPACE {

/*% macro make_pfn_name(cur_cmd) -%*/ /*{cur_cmd.name | replace("xr", "pfn")}*/ /*%- endmacro %*/

/*% macro make_pfn_type(cur_cmd) -%*/ /*{"PFN_" + cur_cmd.name}*/ /*%- endmacro %*/

/*!
 * @brief Dispatch class for OpenXR that looks up all functions using a provided or statically-available xrGetInstanceProcAddr
 * function and the optional Instance.
 *
 * This is safer to use, especially in large/multi-module applications, than DispatchLoaderStatic, and is thus recommended.
 *
 * By default, it is lazy-populating: only populating a function pointer when it is attempted to be called (if this object is not
 * const). You can early-populate it using the createFullyPopulated() factory method, providing an Instance and optionally a
 * xrGetInstanceProcAddr function pointer.
 *
 * This class stores all function pointers as type-erased PFN_xrVoidFunction, casting at time of call. This allows the same memory
 * representation to be used across translation units that may not share the same platform defines. Only the member function
 * trampolines containing the casts are conditional on platform defines.
 *
 * @ingroup dispatch
 */
class DispatchLoaderDynamic {
   public:
    /*!
     * @name Constuctor/Factory functions
     * @{
     */
    /*!
     * @brief Create a lazy-populating dispatch table.
     *
     * If getInstanceProcAddr is not supplied, the static ::xrGetInstanceProcAddr will be used.
     */
    explicit DispatchLoaderDynamic(Instance instance = nullptr, PFN_xrGetInstanceProcAddr getInstanceProcAddr = nullptr)
        : m_instance(instance), pfnGetInstanceProcAddr(reinterpret_cast<PFN_xrVoidFunction>(getInstanceProcAddr)) {
        if (pfnGetInstanceProcAddr == nullptr) {
            pfnGetInstanceProcAddr = reinterpret_cast<PFN_xrVoidFunction>(&::xrGetInstanceProcAddr);
        }
    }

    /*!
     * @brief Create a fully-populated dispatch table given a non-null XrInstance and an optional getInstanceProcAddr.
     *
     * If getInstanceProcAddr is not supplied, the static ::xrGetInstanceProcAddr will be used.
     */
    static DispatchLoaderDynamic createFullyPopulated(Instance instance, PFN_xrGetInstanceProcAddr getInstanceProcAddr = nullptr) {
        OPENXR_HPP_ASSERT(instance != nullptr);
        DispatchLoaderDynamic dispatch{instance, getInstanceProcAddr};
        //# for cur_cmd in sorted_cmds
        dispatch.populate_(/*{cur_cmd.name | quote_string}*/, dispatch./*{make_pfn_name(cur_cmd)}*/);
        //# endfor
        return dispatch;
    }

    //! @}

    /*!
     * @name Entry points
     * @brief These populate the function pointer (if required and non-const), then cast it and call it.
     *
     * We store everything as PFN_xrVoidFunction to allow us to have the same representation all over,
     * despite containing function pointers that might not be accessible without some platform defines.
     * Thus, only our accessor methods differ between different includes of this header, not our data members.
     *
     * @{
     */

    //# for cur_cmd in sorted_cmds
    /*{ protect_begin(cur_cmd) }*/
    //! @brief Call /*{cur_cmd.name}*/, populating function pointer if required.
    /*{cur_cmd.cdecl | collapse_whitespace | replace(";", "")}*/ {
        //## Populate
        XrResult result = populate_(/*{cur_cmd.name | quote_string}*/, /*{make_pfn_name(cur_cmd)}*/);
        if (XR_FAILED(result)) {
            return result;
        }
        //## Cast and call
        return (reinterpret_cast</*{ make_pfn_type(cur_cmd) }*/>(/*{make_pfn_name(cur_cmd)}*/))(
            /*{ forwardCommandArgs(cur_cmd) }*/);
    }

    //! @brief Call /*{cur_cmd.name}*/ (const overload - does not populate function pointer)
    /*{cur_cmd.cdecl | collapse_whitespace | replace(";", "")}*/ const {
        //## Cast and call
        return (reinterpret_cast</*{ make_pfn_type(cur_cmd) }*/>(/*{make_pfn_name(cur_cmd)}*/))(
            /*{ forwardCommandArgs(cur_cmd) }*/);
    }
    /*{ protect_end(cur_cmd) }*/

    //# endfor

    //! @}
   private:
    //! @brief Internal utility function to populate a function pointer if it is nullptr.
    XrResult populate_(const char *function_name, PFN_xrVoidFunction &pfn) {
        if (pfn == nullptr) {
            return reinterpret_cast<PFN_xrGetInstanceProcAddr>(pfnGetInstanceProcAddr)(m_instance.get(), function_name, &pfn);
        }
        return XR_SUCCESS;
    }
    Instance m_instance;
    //# for cur_cmd in sorted_cmds
    PFN_xrVoidFunction /*{ make_pfn_name(cur_cmd) }*/ {};
    //# endfor
};

}  // namespace OPENXR_HPP_NAMESPACE
