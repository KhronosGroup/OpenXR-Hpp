
namespace OPENXR_HPP_NAMESPACE {

/*% macro make_pfn_name(cur_cmd) -%*/ /*{cur_cmd.name | replace("xr", "pfn")}*/ /*%- endmacro %*/

/*% macro make_pfn_type(cur_cmd) -%*/ /*{"PFN_" + cur_cmd.name}*/ /*%- endmacro %*/

class DispatchLoaderDynamic {
   public:
    /*!
     * Create a lazy-populating dispatch table.
     *
     * If getInstanceProcAddr is not supplied, the static ::xrGetInstanceProcAddr will be used.
     */
    explicit DispatchLoaderDynamic(XrInstance instance = XR_NULL_HANDLE, PFN_xrGetInstanceProcAddr getInstanceProcAddr = nullptr)
        : m_instance(instance), pfnGetInstanceProcAddr(reinterpret_cast<PFN_xrVoidFunction>(getInstanceProcAddr)) {
        if (pfnGetInstanceProcAddr == nullptr) {
            pfnGetInstanceProcAddr = reinterpret_cast<PFN_xrVoidFunction>(&::xrGetInstanceProcAddr);
        }
    }

    /*!
     * Create a fully-populated dispatch table given a non-null XrInstance and an optional getInstanceProcAddr.
     *
     * If getInstanceProcAddr is not supplied, the static ::xrGetInstanceProcAddr will be used.
     */
    static DispatchLoaderDynamic createFullyPopulated(XrInstance instance,
                                                      PFN_xrGetInstanceProcAddr getInstanceProcAddr = nullptr) {
        OPENXR_HPP_ASSERT(instance != XR_NULL_HANDLE);
        DispatchLoaderDynamic dispatch{instance, getInstanceProcAddr};
        //# for cur_cmd in sorted_cmds
        dispatch.populate_(/*{cur_cmd.name | quote_string}*/, dispatch./*{make_pfn_name(cur_cmd)}*/);
        //# endfor
        return dispatch;
    }

    /*
     * Entry points: they populate the function pointer, then cast it and call it.
     * We store everything as PFN_xrVoidFunction to allow us to have the same representation all over,
     * despite containing function pointers that might not be accessible without some platform defines.
     * Thus, only our accessor methods differ between different includes of this header, not our data members.
     */

    //# for cur_cmd in sorted_cmds
    /*{ protect_begin(cur_cmd) }*/
    /*{cur_cmd.cdecl | collapse_whitespace | replace(";", "")}*/ {
        XrResult result = populate_(/*{cur_cmd.name | quote_string}*/, /*{make_pfn_name(cur_cmd)}*/);
        if (XR_FAILED(result)) {
            return result;
        }
        return (reinterpret_cast</*{ make_pfn_type(cur_cmd) }*/>(/*{make_pfn_name(cur_cmd)}*/))(
            /*{ forwardCommandArgs(cur_cmd) }*/);
    }
    /*{ protect_end(cur_cmd) }*/
    //# endfor

   private:
    XrResult populate_(const char *function_name, PFN_xrVoidFunction &pfn) {
        if (pfn == nullptr) {
            return reinterpret_cast<PFN_xrGetInstanceProcAddr>(pfnGetInstanceProcAddr)(m_instance, function_name, &pfn);
        }
        return XR_SUCCESS;
    }
    XrInstance m_instance;
    //# for cur_cmd in sorted_cmds
    PFN_xrVoidFunction /*{ make_pfn_name(cur_cmd) }*/;
    //# endfor
};


}  // namespace OPENXR_HPP_NAMESPACE
