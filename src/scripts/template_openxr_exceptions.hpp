
namespace OPENXR_HPP_NAMESPACE {

/*!
 * @defgroup result_helpers Result helper free functions
 * @{
 */
//! @brief Return true if the Result is negative, indicating a failure.
//! Equivalent of XR_FAILED()
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool failed(Result v) { return static_cast<int>(v) < 0; }

//! @brief Return true if the result is non-negative, indicating a success or non-error result.
//! Equivalent of XR_SUCCEEDED()
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool succeeded(Result v) { return static_cast<int>(v) >= 0; }

//! @brief Return true if the result is exactly equal to Result::Success.
//! Equivalent of XR_UNQUALIFIED_SUCCESS()
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool unqualifiedSuccess(Result v) { return v == Result::Success; }
//! @}

//# for op in ('<', '>', '<=', '>=', '==', '!=')
//! @brief `/*{op}*/` comparison between Result and integer, for compatibility with the XR_ function-type macros and XrResult.
//! @relates Result
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator/*{- op -}*/(Result lhs, int rhs) { return get(lhs) /*{- op -}*/ rhs; }

//! @brief `/*{op}*/` comparison between integer and Result, for compatibility with the XR_ function-type macros and XrResult.
//! @relates Result
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator/*{- op -}*/(int lhs, Result rhs) { return lhs /*{- op -}*/ get(rhs); }

//# endfor

}  // namespace OPENXR_HPP_NAMESPACE

#if !defined(OPENXR_HPP_NO_EXCEPTIONS)

namespace OPENXR_HPP_NAMESPACE {

//! Implementation details
namespace impl {
#if defined(_MSC_VER) && (_MSC_VER == 1800)
#define noexcept _NOEXCEPT
#endif

class ErrorCategoryImpl : public std::error_category {
   public:
    virtual const char* name() const noexcept override { return OPENXR_HPP_NAMESPACE_STRING "::Result"; }
    virtual std::string message(int ev) const override { return to_string(static_cast<Result>(ev)); }
};

#if defined(_MSC_VER) && (_MSC_VER == 1800)
#undef noexcept
#endif

OPENXR_HPP_INLINE const std::error_category& errorCategory() {
    static impl::ErrorCategoryImpl instance;
    return instance;
}

OPENXR_HPP_INLINE std::error_code make_error_code(Result e) { return std::error_code(static_cast<int>(e), errorCategory()); }

OPENXR_HPP_INLINE std::error_condition make_error_condition(Result e) {
    return std::error_condition(static_cast<int>(e), errorCategory());
}

#if defined(_MSC_VER) && (_MSC_VER == 1800)
#define noexcept _NOEXCEPT
#endif
}  // namespace impl

//! OpenXR exceptions
namespace exceptions {
/*!
 * @defgroup exceptions Exceptions
 *
 * @{
 */
/*!
 * @defgroup base_exceptions Exception base classes
 * @{
 */
//! @brief Base class for all OpenXR exceptions.
//!
//! Only used for catching all OpenXR exceptions.
class Error {
   public:
    virtual ~Error() = default;

    virtual const char* what() const noexcept = 0;
};

//! @brief OpenXR logic error base exception class.
//!
//! Derives from both Error and std::logic_error for flexibility in catching.
class LogicError : public Error, public std::logic_error {
   public:
    explicit LogicError(const std::string& what) : Error(), std::logic_error(what) {}
    explicit LogicError(char const* what) : Error(), std::logic_error(what) {}
    virtual ~LogicError() = default;

    virtual const char* what() const noexcept { return std::logic_error::what(); }
};

//! @brief OpenXR system error exception class - may be derived from or thrown directly.
//!
//! Derives from both Error and std::system_error for flexibility in catching.
class SystemError : public Error, public std::system_error {
   public:
    SystemError(std::error_code ec) : Error(), std::system_error(ec) {}
    SystemError(std::error_code ec, std::string const& what) : Error(), std::system_error(ec, what) {}
    SystemError(std::error_code ec, char const* what) : Error(), std::system_error(ec, what) {}
    SystemError(int ev, std::error_category const& ecat) : Error(), std::system_error(ev, ecat) {}
    SystemError(int ev, std::error_category const& ecat, std::string const& what) : Error(), std::system_error(ev, ecat, what) {}
    SystemError(int ev, std::error_category const& ecat, char const* what) : Error(), std::system_error(ev, ecat, what) {}
    virtual ~SystemError() = default;

    virtual const char* what() const noexcept { return std::system_error::what(); }
};

// end of base_exceptions
//! @}
#if defined(_MSC_VER) && (_MSC_VER == 1800)
#undef noexcept
#endif

/*!
 * @defgroup result_exceptions Result-specific exceptions
 * @{
 */
//! @todo identify which errors would be considered LogicError and subclass that instead. Add to XML?
//# for val in result_enum.values
//# if "XR_ERROR" in val.name
/*{ protect_begin(val, enum) }*/
//#     set valname = create_enum_value(val.name, 'XrResult')
//#    set classname = create_enum_exception(val.name)
//! @brief Exception class associated with the Result::/*{valname}*/ aka /*{val.name}*/ result code.
class /*{classname}*/ : public SystemError {
   public:
    /*{classname}*/ (std::string const& message)
        : SystemError(impl::make_error_code(Result::/*{valname}*/), message){}

          /*{classname}*/ (char const* message)
        : SystemError(impl::make_error_code(Result::/*{valname}*/), message) {}
};
/*{ protect_end(val, enum) }*/
//# endif
//# endfor

// end of result_exceptions
//! @}

/*!
 * @brief Throws the best exception for a result code.
 *
 * Takes a result code and a message (usually the method triggering the exception) and throws the most-specific exception available
 * for that result code. As a fallback, it will throw a SystemError directly.
 */
OPENXR_HPP_INLINE void throwResultException(Result result, char const* message) {
    switch (result) {
        //# for val in result_enum.values
        /*{ protect_begin(val, enum) }*/
        //#     set valname = create_enum_value(val.name, 'XrResult')
        case Result::/*{valname}*/:
            //# if "XR_ERROR" in val.name
            //#     set classname = create_enum_exception(val.name)
            throw /*{classname}*/ (message);
            //# else
            // Not actually an error!
            throw SystemError(impl::make_error_code(result));
            //# endif
            /*{ protect_end(val, enum) }*/

            //# endfor

        default:
            throw SystemError(impl::make_error_code(result));
    }
}
//! @}
}  // namespace exceptions
}  // namespace OPENXR_HPP_NAMESPACE

#if !defined(OPENXR_HPP_DOXYGEN)
namespace std {
template <>
struct is_error_code_enum<OPENXR_HPP_NAMESPACE::Result> : public true_type {};
}  // namespace std
#endif  // !defined(OPENXR_HPP_DOXYGEN)
#endif  // !defined(OPENXR_HPP_NO_EXCEPTIONS)

namespace OPENXR_HPP_NAMESPACE {

/*!
 * @defgroup return_results Returning results
 * @brief Types and functions used by API call wrappers to return output in a friendly, C++ manner.
 *
 * A user of openxr.hpp will not typically call the functions here directly,
 * but knowing how they work could be useful.
 * @{
 */
/*!
 * @brief Contains a Result enumerant and a returned value.
 *
 * Implicitly convertible to std::tuple<> so you can do `std::tie(result, value)
 * = callThatReturnsResultValue()`
 *
 * @ingroup utilities
 */
template <typename T>
struct ResultValue {
    ResultValue(Result r, T const& v) : result(r), value(v) {}

    ResultValue(Result r, T&& v) : result(r), value(std::move(v)) {}

    Result result;
    T value;

    operator std::tuple<Result&, T&>() { return std::tuple<Result&, T&>(result, value); }
};

/*!
 * @brief Computes the return type of a function (in enhanced mode) with no
 * non-Result::Success success codes and potentially an output value of type T.
 *
 * The behavior differs based on whether or not you have
 * OPENXR_HPP_NO_EXCEPTIONS defined. If it is defined, then all functions return
 * either a Result (for T=void) or a ResultValue<T>. Otherwise, with exceptions
 * enabled, the Result does not need to be returned in these cases, so the
 * return type is T (which may be void).
 */
template <typename T>
struct ResultValueType;

#ifdef OPENXR_HPP_NO_EXCEPTIONS
template <typename T>
struct ResultValueType {
    typedef ResultValue<T> type;
};
template <>
struct ResultValueType<void> {
    typedef Result type;
};
#else
template <typename T>
struct ResultValueType {
    typedef T type;
};
template <>
struct ResultValueType<void> {
    typedef void type;
};
#endif

/*!
 * @brief Returned by enhanced-mode functions with no output value and no
 * non-Result::Success success codes.
 *
 * On failure:
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
 *
 * - Throws an appropriate exception on failure.
 * - Returns nothing (void)
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is defined:
 *
 * - Asserts that result == Result::Success.
 * - Returns Result.
 */
OPENXR_HPP_INLINE ResultValueType<void>::type createResultValue(Result result, char const* message) {
#ifdef OPENXR_HPP_NO_EXCEPTIONS
    (void)message;
    OPENXR_HPP_ASSERT(result == Result::Success);
    return result;
#else
    if (failed(result)) {
        exceptions::throwResultException(result, message);
    }
#endif
}

/*!
 * @brief Returned by enhanced-mode functions with output value of type T and no
 * non-Result::Success success codes.
 *
 * On failure:
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
 *
 * - Throws an appropriate exception on failure.
 * - Returns the value of type T
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is defined:
 *
 * - Asserts that result == Result::Success.
 * - Returns ResultValue<T> containing both the result (which may be an error or
 * Result::Success) and the value.
 */
template <typename T>
OPENXR_HPP_INLINE typename ResultValueType<T>::type createResultValue(Result result, T& data, char const* message) {
#ifdef OPENXR_HPP_NO_EXCEPTIONS
    (void)message;
    OPENXR_HPP_ASSERT(result == Result::Success);
    return ResultValue<T>(result, std::move(data));
#else
    if (failed(result)) {
        exceptions::throwResultException(result, message);
    }
    return std::move(data);
#endif
}

/*!
 * @brief Returned by enhanced-mode functions with no output value and at least one
 * success code specified that is not Result::Success.
 *
 * Return type is always Result.
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
 *
 * - Throws an appropriate exception on failure.
 * - Returns Result (which may be Result::Success, or a non-Result::Success
 * success code)
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is defined:
 *
 * - Asserts that result == Result::Success.
 * - Returns Result (which may be an error, Result::Success, or a
 * non-Result::Success success code).
 */
OPENXR_HPP_INLINE Result createResultValue(Result result, char const* message, std::initializer_list<Result> successCodes) {
#ifdef OPENXR_HPP_NO_EXCEPTIONS
    (void)message;
    OPENXR_HPP_ASSERT(std::find(successCodes.begin(), successCodes.end(), result) != successCodes.end());
#else
    if (std::find(successCodes.begin(), successCodes.end(), result) == successCodes.end()) {
        exceptions::throwResultException(result, message);
    }
#endif
    return result;
}

/*!
 * @brief Returned by enhanced-mode functions with an output value of type T and at
 * least one success code specified that is not Result::Success.
 *
 * Return type is always ResultValue<T>, containing both a Result and the output
 * of type T.
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
 *
 * - Throws an appropriate exception on failure.
 * - Returns ResultValue<T>, containing both a Result (which may be
 * Result::Success, or a non-Result::Success success code) and the output of
 * type T.
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is defined:
 *
 * - Asserts that result == Result::Success.
 * - Returns ResultValue<T>, containing both a Result (which may be an error,
 * Result::Success, or a non-Result::Success success code) and the output of
 * type T.
 */
template <typename T>
OPENXR_HPP_INLINE ResultValue<T> createResultValue(Result result, T& data, char const* message,
                                                   std::initializer_list<Result> successCodes) {
#ifdef OPENXR_HPP_NO_EXCEPTIONS
    (void)message;
    OPENXR_HPP_ASSERT(std::find(successCodes.begin(), successCodes.end(), result) != successCodes.end());
#else
    if (std::find(successCodes.begin(), successCodes.end(), result) == successCodes.end()) {
        exceptions::throwResultException(result, message);
    }
#endif
    return ResultValue<T>(result, data);
}

#ifndef OPENXR_HPP_NO_SMART_HANDLE
/*!
 * @brief Returned by enhanced-mode functions that create a UniqueHandle<T, D>
 * (a handle of type T, with deleter using dispatch type D) and
 * no non-Result::Success success codes.
 *
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
 *
 * - Throws an appropriate exception on failure.
 * - Returns UniqueHandle<T, D>.
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is defined:
 *
 * - Asserts that result == Result::Success.
 * - Returns ResultValue<UniqueHandle<T, D>>, containing both a Result (which may be an error,
 * Result::Success, or a non-Result::Success success code) and the UniqueHandle<T, D>.
 */
template <typename T, typename D>
OPENXR_HPP_INLINE typename ResultValueType<UniqueHandle<T, D>>::type createResultValue(
    Result result, T& data, typename traits::UniqueHandleTraits<T, D>::deleter const& deleter, char const* message) {
#ifdef OPENXR_HPP_NO_EXCEPTIONS
    (void)message;
    OPENXR_HPP_ASSERT(result == Result::Success);
    return ResultValue<UniqueHandle<T, D>>(result, UniqueHandle<T, D>(std::move(data), deleter));
#else
    if (failed(result)) {
        exceptions::throwResultException(result, message);
    }
    return UniqueHandle<T, D>(data, deleter);
#endif
}

/*!
 * @brief Returned by enhanced-mode functions that create a UniqueHandle<T, D>
 * (a handle of type T, with deleter using dispatch type D) and
 * at least one success code specified that is not Result::Success.
 *
 * Return type is always ResultValue<UniqueHandle<T, D>>, containing both a Result
 * and the UniqueHandle<T, D> (which may be null).
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
 *
 * - Throws an appropriate exception on failure.
 * - Returns ResultValue<UniqueHandle<T, D>>, containing both a Result (which may be
 * Result::Success, or a non-Result::Success success code) and the UniqueHandle<T, D>.
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is defined:
 *
 * - Asserts that result == Result::Success.
 * - Returns ResultValue<T>, containing both a Result (which may be an error,
 * Result::Success, or a non-Result::Success success code) and the UniqueHandle<T, D>.
 */
template <typename T, typename D>
OPENXR_HPP_INLINE ResultValue<UniqueHandle<T, D>> createResultValue(
    Result result, T& data, typename traits::UniqueHandleTraits<T, D>::deleter const& deleter, char const* message,
    std::initializer_list<Result> successCodes) {
#ifdef OPENXR_HPP_NO_EXCEPTIONS
    (void)message;
    OPENXR_HPP_ASSERT(std::find(successCodes.begin(), successCodes.end(), result) != successCodes.end());
    return ResultValue<UniqueHandle<T, D>>(result, UniqueHandle<T, D>(std::move(data), deleter));
#else
    if (std::find(successCodes.begin(), successCodes.end(), result) == successCodes.end()) {
        exceptions::throwResultException(result, message);
    }
    return ResultValue<UniqueHandle<T, D>>(result, UniqueHandle<T, D>{data, deleter});
#endif
}
#endif

//! @}

}  // namespace OPENXR_HPP_NAMESPACE
