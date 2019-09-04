#ifndef OPENXR_HPP_
#define OPENXR_HPP_ 1

/*
** Copyright (c) 2017-2019 The Khronos Group Inc.
** Copyright (c) 2019 Collabora, Ltd.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

/*
** This header is generated from the Khronos OpenXR XML API Registry.
**
*/

#include <openxr/openxr.h>
#include <openxr/openxr_platform.h>

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <initializer_list>
#include <string>
#include <system_error>
#include <tuple>
#include <type_traits>

#if !defined(OPENXR_HPP_ASSERT)
#include <cassert>
#define OPENXR_HPP_ASSERT assert
#endif

// 32-bit OpenXR is not typesafe for handles, so don't allow copy constructors
// on this platform by default. To enable this feature on 32-bit platforms
// please define OPENXR_HPP_TYPESAFE_CONVERSION
#if defined(__LP64__) || defined(_WIN64) || (defined(__x86_64__) && !defined(__ILP32__)) || defined(_M_X64) || defined(__ia64) || \
    defined(_M_IA64) || defined(__aarch64__) || defined(__powerpc64__)
#if !defined(OPENXR_HPP_TYPESAFE_CONVERSION)
#define OPENXR_HPP_TYPESAFE_CONVERSION
#endif
#endif

#if !defined(OPENXR_HPP_INLINE)
#if defined(__clang___)
#if __has_attribute(always_inline)
#define OPENXR_HPP_INLINE __attribute__((always_inline)) __inline__
#else
#define OPENXR_HPP_INLINE inline
#endif
#elif defined(__GNUC__)
#define OPENXR_HPP_INLINE __attribute__((always_inline)) __inline__
#elif defined(_MSC_VER)
#define OPENXR_HPP_INLINE inline
#else
#define OPENXR_HPP_INLINE inline
#endif
#endif

#if defined(OPENXR_HPP_TYPESAFE_CONVERSION)
#define OPENXR_HPP_TYPESAFE_EXPLICIT
#else
#define OPENXR_HPP_TYPESAFE_EXPLICIT explicit
#endif

#if defined(_MSC_VER) && (_MSC_VER <= 1800)
#define OPENXR_HPP_CONSTEXPR
#else
#define OPENXR_HPP_CONSTEXPR constexpr
#endif

#if !defined(OPENXR_HPP_NAMESPACE)
#define OPENXR_HPP_NAMESPACE xr
#endif

#define OPENXR_HPP_STRINGIFY2(text) #text
#define OPENXR_HPP_STRINGIFY(text) OPENXR_HPP_STRINGIFY2(text)
#define OPENXR_HPP_NAMESPACE_STRING OPENXR_HPP_STRINGIFY(OPENXR_HPP_NAMESPACE)

namespace OPENXR_HPP_NAMESPACE {

template <typename FlagBitsType>
struct FlagTraits {
    enum { allFlags = 0 };
};

template <typename BitType, typename MaskType = XrFlags64>
class Flags {
   public:
    OPENXR_HPP_CONSTEXPR Flags() : m_mask(0) {}

    Flags(BitType bit) : m_mask(static_cast<MaskType>(bit)) {}

    Flags(Flags<BitType> const &rhs) : m_mask(rhs.m_mask) {}

    explicit Flags(MaskType flags) : m_mask(flags) {}

    Flags<BitType> &operator=(Flags<BitType> const &rhs) {
        m_mask = rhs.m_mask;
        return *this;
    }

    Flags<BitType> &operator|=(Flags<BitType> const &rhs) {
        m_mask |= rhs.m_mask;
        return *this;
    }

    Flags<BitType> &operator&=(Flags<BitType> const &rhs) {
        m_mask &= rhs.m_mask;
        return *this;
    }

    Flags<BitType> &operator^=(Flags<BitType> const &rhs) {
        m_mask ^= rhs.m_mask;
        return *this;
    }

    Flags<BitType> operator|(Flags<BitType> const &rhs) const {
        Flags<BitType> result(*this);
        result |= rhs;
        return result;
    }

    Flags<BitType> operator&(Flags<BitType> const &rhs) const {
        Flags<BitType> result(*this);
        result &= rhs;
        return result;
    }

    Flags<BitType> operator^(Flags<BitType> const &rhs) const {
        Flags<BitType> result(*this);
        result ^= rhs;
        return result;
    }

    bool operator!() const { return !m_mask; }

    Flags<BitType> operator~() const {
        Flags<BitType> result(*this);
        result.m_mask ^= FlagTraits<BitType>::allFlags;
        return result;
    }

    bool operator==(Flags<BitType> const &rhs) const { return m_mask == rhs.m_mask; }

    bool operator!=(Flags<BitType> const &rhs) const { return m_mask != rhs.m_mask; }

    explicit operator bool() const { return !!m_mask; }

    explicit operator MaskType() const { return m_mask; }

   private:
    MaskType m_mask;
};

template <typename BitType>
Flags<BitType> operator|(BitType bit, Flags<BitType> const &flags) {
    return flags | bit;
}

template <typename BitType>
Flags<BitType> operator&(BitType bit, Flags<BitType> const &flags) {
    return flags & bit;
}

template <typename BitType>
Flags<BitType> operator^(BitType bit, Flags<BitType> const &flags) {
    return flags ^ bit;
}

template <typename RefType>
class Optional {
   public:
    Optional(RefType &reference) { m_ptr = &reference; }
    Optional(RefType *ptr) { m_ptr = ptr; }
    Optional(std::nullptr_t) { m_ptr = nullptr; }

    operator RefType *() const { return m_ptr; }
    RefType const *operator->() const { return m_ptr; }
    explicit operator bool() const { return !!m_ptr; }

   private:
    RefType *m_ptr;
};

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename T>
class ArrayProxy {
   public:
    OPENXR_HPP_CONSTEXPR ArrayProxy(std::nullptr_t) : m_count(0), m_ptr(nullptr) {}

    ArrayProxy(T &ptr) : m_count(1), m_ptr(&ptr) {}

    ArrayProxy(uint32_t count, T *ptr) : m_count(count), m_ptr(ptr) {}

    template <size_t N>
    ArrayProxy(std::array<typename std::remove_const<T>::type, N> &data) : m_count(N), m_ptr(data.data()) {}

    template <size_t N>
    ArrayProxy(std::array<typename std::remove_const<T>::type, N> const &data) : m_count(N), m_ptr(data.data()) {}

    template <class Allocator = std::allocator<typename std::remove_const<T>::type>>
    ArrayProxy(std::vector<typename std::remove_const<T>::type, Allocator> &data)
        : m_count(static_cast<uint32_t>(data.size())), m_ptr(data.data()) {}

    template <class Allocator = std::allocator<typename std::remove_const<T>::type>>
    ArrayProxy(std::vector<typename std::remove_const<T>::type, Allocator> const &data)
        : m_count(static_cast<uint32_t>(data.size())), m_ptr(data.data()) {}

    ArrayProxy(std::initializer_list<T> const &data)
        : m_count(static_cast<uint32_t>(data.end() - data.begin())), m_ptr(data.begin()) {}

    const T *begin() const { return m_ptr; }

    const T *end() const { return m_ptr + m_count; }

    const T &front() const {
        OPENXR_HPP_ASSERT(m_count && m_ptr);
        return *m_ptr;
    }

    const T &back() const {
        OPENXR_HPP_ASSERT(m_count && m_ptr);
        return *(m_ptr + m_count - 1);
    }

    bool empty() const { return (m_count == 0); }

    uint32_t size() const { return m_count; }

    T *data() const { return m_ptr; }

   private:
    uint32_t m_count;
    T *m_ptr;
};
#endif

/*% macro forwardCommandArgs(cur_cmd) %*/ /*{ cur_cmd.params | map(attribute="name") | join(", ") }*/ /*% endmacro %*/

class DispatchLoaderStatic {
   public:
    /*
     * Core Commands
     */

    //# for cur_cmd in gen.core_commands
    /*{cur_cmd.cdecl | collapse_whitespace | replace(";", "")}*/ {
        return ::/*{cur_cmd.name}*/ (/*{ forwardCommandArgs(cur_cmd) }*/);
    }
    //# endfor
};

// forward declarations

//# for handle in gen.api_handles
class /*{ handle.name | replace("Xr", "") }*/;
//# endfor

//# for handle in gen.api_handles
//# set shortname = handle.name | replace("Xr", "")
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
    /*{cur_cmd.return_type.text}*/ /*{ member_function_name(cur_cmd.name) -}*/ (
        /*{- project_params_for_declaration(cur_cmd) -}*/) const;
    /*{ protect_end(cur_cmd) }*/

    //#     endif
    //# endfor

   private:
    RawHandleType m_raw;
};
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

//# endfor

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
#endif
