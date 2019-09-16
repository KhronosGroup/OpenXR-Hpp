// *********** THIS FILE IS GENERATED - DO NOT EDIT ***********
//     See cpp_generator.py for modifications
// ************************************************************

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
#include <cstring>
#include <initializer_list>
#include <string>
#include <system_error>
#include <tuple>
#include <type_traits>
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
#include <memory>
#include <vector>
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

// Fix name collisions from noisy includes
#ifdef Success
#undef Success
#endif

#if !defined(OPENXR_HPP_ASSERT)
#include <cassert>
#define OPENXR_HPP_ASSERT assert
#endif

// 32-bit OpenXR is not typesafe for handles, so don't allow copy constructors
// on this platform by default. To enable this feature on 32-bit platforms
// please define OPENXR_HPP_TYPESAFE_CONVERSION
#if defined(__LP64__) || defined(_WIN64) ||                                    \
    (defined(__x86_64__) && !defined(__ILP32__)) || defined(_M_X64) ||         \
    defined(__ia64) || defined(_M_IA64) || defined(__aarch64__) ||             \
    defined(__powerpc64__)
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

//! @todo set this to constexpr in c++14
#define OPENXR_HPP_SWITCH_CONSTEXPR

#if !defined(OPENXR_HPP_NAMESPACE)
#define OPENXR_HPP_NAMESPACE xr
#endif

#define OPENXR_HPP_STRINGIFY2(text) #text
#define OPENXR_HPP_STRINGIFY(text) OPENXR_HPP_STRINGIFY2(text)
#define OPENXR_HPP_NAMESPACE_STRING OPENXR_HPP_STRINGIFY(OPENXR_HPP_NAMESPACE)

/*!
 * @brief Namespace containing all openxr.hpp entities.
 *
 * If the default namespace `xr` isn't suitable, you can define
 * OPENXR_HPP_NAMESPACE to a different name before including this header.
 */
namespace OPENXR_HPP_NAMESPACE {
// Forward declaration
class DispatchLoaderDynamic;

// The generalization of std::string with user-specifiable allocator types.
template <typename Allocator = std::allocator<char>>
using string_with_allocator =
    std::basic_string<char, std::char_traits<char>, Allocator>;

} // namespace OPENXR_HPP_NAMESPACE
namespace OPENXR_HPP_NAMESPACE {

/*!
 * @defgroup dispatch Dispatch classes
 * @brief Classes providing a method or function pointer member for OpenXR APIs.
 *
 * The classes provided here are useful basic classes, but all places that can
 * take a dispatch class are templated to be able to accept any class that meets
 * the requirements.
 */

/*!
 * @brief Dispatch class for OpenXR core functions that uses exported,
 * statically-available symbols.
 *
 * Not for use in game engines or other multi-module software where different
 * modules might want newer OpenXR APIs. If this is used, all parts of an
 * application must build against and use the same loader library.
 *
 * Does not provide extension functions because those are not exported from the
 * loader library.
 *
 * @ingroup dispatch
 */
class DispatchLoaderStatic {
public:
  /*!
   * @name Core Commands
   * @{
   */

  XrResult xrGetInstanceProcAddr(XrInstance instance, const char *name,
                                 PFN_xrVoidFunction *function) const {
    return ::xrGetInstanceProcAddr(instance, name, function);
  }
  XrResult
  xrEnumerateApiLayerProperties(uint32_t propertyCapacityInput,
                                uint32_t *propertyCountOutput,
                                XrApiLayerProperties *properties) const {
    return ::xrEnumerateApiLayerProperties(propertyCapacityInput,
                                           propertyCountOutput, properties);
  }
  XrResult xrEnumerateInstanceExtensionProperties(
      const char *layerName, uint32_t propertyCapacityInput,
      uint32_t *propertyCountOutput, XrExtensionProperties *properties) const {
    return ::xrEnumerateInstanceExtensionProperties(
        layerName, propertyCapacityInput, propertyCountOutput, properties);
  }
  XrResult xrCreateInstance(const XrInstanceCreateInfo *createInfo,
                            XrInstance *instance) const {
    return ::xrCreateInstance(createInfo, instance);
  }
  XrResult xrDestroyInstance(XrInstance instance) const {
    return ::xrDestroyInstance(instance);
  }
  XrResult
  xrGetInstanceProperties(XrInstance instance,
                          XrInstanceProperties *instanceProperties) const {
    return ::xrGetInstanceProperties(instance, instanceProperties);
  }
  XrResult xrPollEvent(XrInstance instance,
                       XrEventDataBuffer *eventData) const {
    return ::xrPollEvent(instance, eventData);
  }
  XrResult xrResultToString(XrInstance instance, XrResult value,
                            char buffer[XR_MAX_RESULT_STRING_SIZE]) const {
    return ::xrResultToString(instance, value, buffer);
  }
  XrResult
  xrStructureTypeToString(XrInstance instance, XrStructureType value,
                          char buffer[XR_MAX_STRUCTURE_NAME_SIZE]) const {
    return ::xrStructureTypeToString(instance, value, buffer);
  }
  XrResult xrGetSystem(XrInstance instance, const XrSystemGetInfo *getInfo,
                       XrSystemId *systemId) const {
    return ::xrGetSystem(instance, getInfo, systemId);
  }
  XrResult xrGetSystemProperties(XrInstance instance, XrSystemId systemId,
                                 XrSystemProperties *properties) const {
    return ::xrGetSystemProperties(instance, systemId, properties);
  }
  XrResult xrEnumerateEnvironmentBlendModes(
      XrInstance instance, XrSystemId systemId,
      XrViewConfigurationType viewConfigurationType,
      uint32_t environmentBlendModeCapacityInput,
      uint32_t *environmentBlendModeCountOutput,
      XrEnvironmentBlendMode *environmentBlendModes) const {
    return ::xrEnumerateEnvironmentBlendModes(
        instance, systemId, viewConfigurationType,
        environmentBlendModeCapacityInput, environmentBlendModeCountOutput,
        environmentBlendModes);
  }
  XrResult xrCreateSession(XrInstance instance,
                           const XrSessionCreateInfo *createInfo,
                           XrSession *session) const {
    return ::xrCreateSession(instance, createInfo, session);
  }
  XrResult xrDestroySession(XrSession session) const {
    return ::xrDestroySession(session);
  }
  XrResult xrEnumerateReferenceSpaces(XrSession session,
                                      uint32_t spaceCapacityInput,
                                      uint32_t *spaceCountOutput,
                                      XrReferenceSpaceType *spaces) const {
    return ::xrEnumerateReferenceSpaces(session, spaceCapacityInput,
                                        spaceCountOutput, spaces);
  }
  XrResult xrCreateReferenceSpace(XrSession session,
                                  const XrReferenceSpaceCreateInfo *createInfo,
                                  XrSpace *space) const {
    return ::xrCreateReferenceSpace(session, createInfo, space);
  }
  XrResult
  xrGetReferenceSpaceBoundsRect(XrSession session,
                                XrReferenceSpaceType referenceSpaceType,
                                XrExtent2Df *bounds) const {
    return ::xrGetReferenceSpaceBoundsRect(session, referenceSpaceType, bounds);
  }
  XrResult xrCreateActionSpace(XrSession session,
                               const XrActionSpaceCreateInfo *createInfo,
                               XrSpace *space) const {
    return ::xrCreateActionSpace(session, createInfo, space);
  }
  XrResult xrLocateSpace(XrSpace space, XrSpace baseSpace, XrTime time,
                         XrSpaceLocation *location) const {
    return ::xrLocateSpace(space, baseSpace, time, location);
  }
  XrResult xrDestroySpace(XrSpace space) const {
    return ::xrDestroySpace(space);
  }
  XrResult xrEnumerateViewConfigurations(
      XrInstance instance, XrSystemId systemId,
      uint32_t viewConfigurationTypeCapacityInput,
      uint32_t *viewConfigurationTypeCountOutput,
      XrViewConfigurationType *viewConfigurationTypes) const {
    return ::xrEnumerateViewConfigurations(
        instance, systemId, viewConfigurationTypeCapacityInput,
        viewConfigurationTypeCountOutput, viewConfigurationTypes);
  }
  XrResult xrGetViewConfigurationProperties(
      XrInstance instance, XrSystemId systemId,
      XrViewConfigurationType viewConfigurationType,
      XrViewConfigurationProperties *configurationProperties) const {
    return ::xrGetViewConfigurationProperties(
        instance, systemId, viewConfigurationType, configurationProperties);
  }
  XrResult xrEnumerateViewConfigurationViews(
      XrInstance instance, XrSystemId systemId,
      XrViewConfigurationType viewConfigurationType, uint32_t viewCapacityInput,
      uint32_t *viewCountOutput, XrViewConfigurationView *views) const {
    return ::xrEnumerateViewConfigurationViews(
        instance, systemId, viewConfigurationType, viewCapacityInput,
        viewCountOutput, views);
  }
  XrResult xrEnumerateSwapchainFormats(XrSession session,
                                       uint32_t formatCapacityInput,
                                       uint32_t *formatCountOutput,
                                       int64_t *formats) const {
    return ::xrEnumerateSwapchainFormats(session, formatCapacityInput,
                                         formatCountOutput, formats);
  }
  XrResult xrCreateSwapchain(XrSession session,
                             const XrSwapchainCreateInfo *createInfo,
                             XrSwapchain *swapchain) const {
    return ::xrCreateSwapchain(session, createInfo, swapchain);
  }
  XrResult xrDestroySwapchain(XrSwapchain swapchain) const {
    return ::xrDestroySwapchain(swapchain);
  }
  XrResult
  xrEnumerateSwapchainImages(XrSwapchain swapchain, uint32_t imageCapacityInput,
                             uint32_t *imageCountOutput,
                             XrSwapchainImageBaseHeader *images) const {
    return ::xrEnumerateSwapchainImages(swapchain, imageCapacityInput,
                                        imageCountOutput, images);
  }
  XrResult
  xrAcquireSwapchainImage(XrSwapchain swapchain,
                          const XrSwapchainImageAcquireInfo *acquireInfo,
                          uint32_t *index) const {
    return ::xrAcquireSwapchainImage(swapchain, acquireInfo, index);
  }
  XrResult
  xrWaitSwapchainImage(XrSwapchain swapchain,
                       const XrSwapchainImageWaitInfo *waitInfo) const {
    return ::xrWaitSwapchainImage(swapchain, waitInfo);
  }
  XrResult xrReleaseSwapchainImage(
      XrSwapchain swapchain,
      const XrSwapchainImageReleaseInfo *releaseInfo) const {
    return ::xrReleaseSwapchainImage(swapchain, releaseInfo);
  }
  XrResult xrBeginSession(XrSession session,
                          const XrSessionBeginInfo *beginInfo) const {
    return ::xrBeginSession(session, beginInfo);
  }
  XrResult xrEndSession(XrSession session) const {
    return ::xrEndSession(session);
  }
  XrResult xrRequestExitSession(XrSession session) const {
    return ::xrRequestExitSession(session);
  }
  XrResult xrWaitFrame(XrSession session, const XrFrameWaitInfo *frameWaitInfo,
                       XrFrameState *frameState) const {
    return ::xrWaitFrame(session, frameWaitInfo, frameState);
  }
  XrResult xrBeginFrame(XrSession session,
                        const XrFrameBeginInfo *frameBeginInfo) const {
    return ::xrBeginFrame(session, frameBeginInfo);
  }
  XrResult xrEndFrame(XrSession session,
                      const XrFrameEndInfo *frameEndInfo) const {
    return ::xrEndFrame(session, frameEndInfo);
  }
  XrResult xrLocateViews(XrSession session,
                         const XrViewLocateInfo *viewLocateInfo,
                         XrViewState *viewState, uint32_t viewCapacityInput,
                         uint32_t *viewCountOutput, XrView *views) const {
    return ::xrLocateViews(session, viewLocateInfo, viewState,
                           viewCapacityInput, viewCountOutput, views);
  }
  XrResult xrStringToPath(XrInstance instance, const char *pathString,
                          XrPath *path) const {
    return ::xrStringToPath(instance, pathString, path);
  }
  XrResult xrPathToString(XrInstance instance, XrPath path,
                          uint32_t bufferCapacityInput,
                          uint32_t *bufferCountOutput, char *buffer) const {
    return ::xrPathToString(instance, path, bufferCapacityInput,
                            bufferCountOutput, buffer);
  }
  XrResult xrCreateActionSet(XrInstance instance,
                             const XrActionSetCreateInfo *createInfo,
                             XrActionSet *actionSet) const {
    return ::xrCreateActionSet(instance, createInfo, actionSet);
  }
  XrResult xrDestroyActionSet(XrActionSet actionSet) const {
    return ::xrDestroyActionSet(actionSet);
  }
  XrResult xrCreateAction(XrActionSet actionSet,
                          const XrActionCreateInfo *createInfo,
                          XrAction *action) const {
    return ::xrCreateAction(actionSet, createInfo, action);
  }
  XrResult xrDestroyAction(XrAction action) const {
    return ::xrDestroyAction(action);
  }
  XrResult xrSuggestInteractionProfileBindings(
      XrInstance instance,
      const XrInteractionProfileSuggestedBinding *suggestedBindings) const {
    return ::xrSuggestInteractionProfileBindings(instance, suggestedBindings);
  }
  XrResult xrAttachSessionActionSets(
      XrSession session,
      const XrSessionActionSetsAttachInfo *attachInfo) const {
    return ::xrAttachSessionActionSets(session, attachInfo);
  }
  XrResult xrGetCurrentInteractionProfile(
      XrSession session, XrPath topLevelUserPath,
      XrInteractionProfileState *interactionProfile) const {
    return ::xrGetCurrentInteractionProfile(session, topLevelUserPath,
                                            interactionProfile);
  }
  XrResult xrGetActionStateBoolean(XrSession session,
                                   const XrActionStateGetInfo *getInfo,
                                   XrActionStateBoolean *state) const {
    return ::xrGetActionStateBoolean(session, getInfo, state);
  }
  XrResult xrGetActionStateFloat(XrSession session,
                                 const XrActionStateGetInfo *getInfo,
                                 XrActionStateFloat *state) const {
    return ::xrGetActionStateFloat(session, getInfo, state);
  }
  XrResult xrGetActionStateVector2f(XrSession session,
                                    const XrActionStateGetInfo *getInfo,
                                    XrActionStateVector2f *state) const {
    return ::xrGetActionStateVector2f(session, getInfo, state);
  }
  XrResult xrGetActionStatePose(XrSession session,
                                const XrActionStateGetInfo *getInfo,
                                XrActionStatePose *state) const {
    return ::xrGetActionStatePose(session, getInfo, state);
  }
  XrResult xrSyncActions(XrSession session,
                         const XrActionsSyncInfo *syncInfo) const {
    return ::xrSyncActions(session, syncInfo);
  }
  XrResult xrEnumerateBoundSourcesForAction(
      XrSession session,
      const XrBoundSourcesForActionEnumerateInfo *enumerateInfo,
      uint32_t sourceCapacityInput, uint32_t *sourceCountOutput,
      XrPath *sources) const {
    return ::xrEnumerateBoundSourcesForAction(session, enumerateInfo,
                                              sourceCapacityInput,
                                              sourceCountOutput, sources);
  }
  XrResult xrGetInputSourceLocalizedName(
      XrSession session, const XrInputSourceLocalizedNameGetInfo *getInfo,
      uint32_t bufferCapacityInput, uint32_t *bufferCountOutput,
      char *buffer) const {
    return ::xrGetInputSourceLocalizedName(
        session, getInfo, bufferCapacityInput, bufferCountOutput, buffer);
  }
  XrResult
  xrApplyHapticFeedback(XrSession session,
                        const XrHapticActionInfo *hapticActionInfo,
                        const XrHapticBaseHeader *hapticFeedback) const {
    return ::xrApplyHapticFeedback(session, hapticActionInfo, hapticFeedback);
  }
  XrResult
  xrStopHapticFeedback(XrSession session,
                       const XrHapticActionInfo *hapticActionInfo) const {
    return ::xrStopHapticFeedback(session, hapticActionInfo);
  }
  //! @}
};

} // namespace OPENXR_HPP_NAMESPACE

namespace OPENXR_HPP_NAMESPACE {

#ifndef OPENXR_HPP_NO_SMART_HANDLE

namespace traits {

template <typename Type, typename Dispatch> class UniqueHandleTraits;

} // namespace traits

namespace impl {

// Used when returning unique handles.
template <typename T>
using RemoveRefConst =
    typename std::remove_const<typename std::remove_reference<T>::type>::type;
} // namespace impl

/*!
 * Template class for holding a handle with unique ownership, much like
 * unique_ptr.
 *
 * Note that this does not keep track of children or parents, though OpenXR
 * specifies that destruction of a handle also destroys its children
 * automatically.
 */
template <typename Type, typename Dispatch>
class UniqueHandle
    : public traits::UniqueHandleTraits<Type, Dispatch>::deleter {
private:
  using Deleter = typename traits::UniqueHandleTraits<Type, Dispatch>::deleter;

public:
  explicit UniqueHandle(Type const &value = Type(),
                        Deleter const &deleter = Deleter())
      : Deleter(deleter), m_value(value) {}

  UniqueHandle(UniqueHandle const &) = delete;

  UniqueHandle(UniqueHandle &&other)
      : Deleter(std::move(static_cast<Deleter &>(other))),
        m_value(other.release()) {}

  ~UniqueHandle() {
    if (m_value)
      this->destroy(m_value);
  }

  UniqueHandle &operator=(UniqueHandle const &) = delete;

  UniqueHandle &operator=(UniqueHandle &&other) {
    reset(other.release());
    *static_cast<Deleter *>(this) = std::move(static_cast<Deleter &>(other));
    return *this;
  }

  explicit operator bool() const { return m_value.operator bool(); }

  Type const *operator->() const { return &m_value; }

  Type *operator->() { return &m_value; }

  Type const &operator*() const { return m_value; }

  Type &operator*() { return m_value; }

  const Type &get() const { return m_value; }

  Type &get() { return m_value; }

  void reset(Type const &value = Type()) {
    if (m_value != value) {
      if (m_value)
        this->destroy(m_value);
      m_value = value;
    }
  }

  typename Type::RawHandleType *put() {
    reset();
    return m_value.put();
  }

  Type release() {
    Type value = m_value;
    m_value = nullptr;
    return value;
  }

  void swap(UniqueHandle<Type, Dispatch> &rhs) {
    std::swap(m_value, rhs.m_value);
    std::swap(static_cast<Deleter &>(*this), static_cast<Deleter &>(rhs));
  }

private:
  Type m_value;
};
template <typename Type, typename Dispatch>
class UniqueHandle<Type, Dispatch &> : public UniqueHandle<Type, Dispatch> {};

template <typename Type, typename Dispatch>
class UniqueHandle<Type, Dispatch const> : public UniqueHandle<Type, Dispatch> {
};

//! @relates UniqueHandle
template <typename Type, typename Dispatch>
OPENXR_HPP_INLINE void swap(UniqueHandle<Type, Dispatch> &lhs,
                            UniqueHandle<Type, Dispatch> &rhs) {
  lhs.swap(rhs);
}
#endif

template <typename Dispatch> class ObjectDestroy {
public:
  ObjectDestroy(Dispatch const &dispatch = Dispatch())
      : m_dispatch(&dispatch) {}

protected:
  template <typename T> void destroy(T t) { t.destroy(*m_dispatch); }

private:
  Dispatch const *m_dispatch;
};
} // namespace OPENXR_HPP_NAMESPACE

namespace OPENXR_HPP_NAMESPACE {
/*!
 * @defgroup enums Enumerations
 * @brief C++ enum classes corresponding to OpenXR C enumerations, plus
 * associated utility functions.
 *
 * All enumerations have three utility functions defined:
 *
 * - get() - returns the raw C enum value
 * - to_string_literal() - returns a const char* containing the C++ name
 * - to_string() - wraps to_string_literal(), returning a std::string
 *
 * @{
 */

//! @brief Enum class associated with XrResult
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrResult>
enum class Result : int32_t {

  Success = XR_SUCCESS,

  TimeoutExpired = XR_TIMEOUT_EXPIRED,

  SessionLossPending = XR_SESSION_LOSS_PENDING,

  EventUnavailable = XR_EVENT_UNAVAILABLE,

  SpaceBoundsUnavailable = XR_SPACE_BOUNDS_UNAVAILABLE,

  SessionNotFocused = XR_SESSION_NOT_FOCUSED,

  FrameDiscarded = XR_FRAME_DISCARDED,

  ErrorValidationFailure = XR_ERROR_VALIDATION_FAILURE,

  ErrorRuntimeFailure = XR_ERROR_RUNTIME_FAILURE,

  ErrorOutOfMemory = XR_ERROR_OUT_OF_MEMORY,

  ErrorApiVersionUnsupported = XR_ERROR_API_VERSION_UNSUPPORTED,

  ErrorInitializationFailed = XR_ERROR_INITIALIZATION_FAILED,

  ErrorFunctionUnsupported = XR_ERROR_FUNCTION_UNSUPPORTED,

  ErrorFeatureUnsupported = XR_ERROR_FEATURE_UNSUPPORTED,

  ErrorExtensionNotPresent = XR_ERROR_EXTENSION_NOT_PRESENT,

  ErrorLimitReached = XR_ERROR_LIMIT_REACHED,

  ErrorSizeInsufficient = XR_ERROR_SIZE_INSUFFICIENT,

  ErrorHandleInvalid = XR_ERROR_HANDLE_INVALID,

  ErrorInstanceLost = XR_ERROR_INSTANCE_LOST,

  ErrorSessionRunning = XR_ERROR_SESSION_RUNNING,

  ErrorSessionNotRunning = XR_ERROR_SESSION_NOT_RUNNING,

  ErrorSessionLost = XR_ERROR_SESSION_LOST,

  ErrorSystemInvalid = XR_ERROR_SYSTEM_INVALID,

  ErrorPathInvalid = XR_ERROR_PATH_INVALID,

  ErrorPathCountExceeded = XR_ERROR_PATH_COUNT_EXCEEDED,

  ErrorPathFormatInvalid = XR_ERROR_PATH_FORMAT_INVALID,

  ErrorPathUnsupported = XR_ERROR_PATH_UNSUPPORTED,

  ErrorLayerInvalid = XR_ERROR_LAYER_INVALID,

  ErrorLayerLimitExceeded = XR_ERROR_LAYER_LIMIT_EXCEEDED,

  ErrorSwapchainRectInvalid = XR_ERROR_SWAPCHAIN_RECT_INVALID,

  ErrorSwapchainFormatUnsupported = XR_ERROR_SWAPCHAIN_FORMAT_UNSUPPORTED,

  ErrorActionTypeMismatch = XR_ERROR_ACTION_TYPE_MISMATCH,

  ErrorSessionNotReady = XR_ERROR_SESSION_NOT_READY,

  ErrorSessionNotStopping = XR_ERROR_SESSION_NOT_STOPPING,

  ErrorTimeInvalid = XR_ERROR_TIME_INVALID,

  ErrorReferenceSpaceUnsupported = XR_ERROR_REFERENCE_SPACE_UNSUPPORTED,

  ErrorFileAccessError = XR_ERROR_FILE_ACCESS_ERROR,

  ErrorFileContentsInvalid = XR_ERROR_FILE_CONTENTS_INVALID,

  ErrorFormFactorUnsupported = XR_ERROR_FORM_FACTOR_UNSUPPORTED,

  ErrorFormFactorUnavailable = XR_ERROR_FORM_FACTOR_UNAVAILABLE,

  ErrorApiLayerNotPresent = XR_ERROR_API_LAYER_NOT_PRESENT,

  ErrorCallOrderInvalid = XR_ERROR_CALL_ORDER_INVALID,

  ErrorGraphicsDeviceInvalid = XR_ERROR_GRAPHICS_DEVICE_INVALID,

  ErrorPoseInvalid = XR_ERROR_POSE_INVALID,

  ErrorIndexOutOfRange = XR_ERROR_INDEX_OUT_OF_RANGE,

  ErrorViewConfigurationTypeUnsupported =
      XR_ERROR_VIEW_CONFIGURATION_TYPE_UNSUPPORTED,

  ErrorEnvironmentBlendModeUnsupported =
      XR_ERROR_ENVIRONMENT_BLEND_MODE_UNSUPPORTED,

  ErrorNameDuplicated = XR_ERROR_NAME_DUPLICATED,

  ErrorNameInvalid = XR_ERROR_NAME_INVALID,

  ErrorActionsetNotAttached = XR_ERROR_ACTIONSET_NOT_ATTACHED,

  ErrorActionsetsAlreadyAttached = XR_ERROR_ACTIONSETS_ALREADY_ATTACHED,

  ErrorLocalizedNameDuplicated = XR_ERROR_LOCALIZED_NAME_DUPLICATED,

  ErrorLocalizedNameInvalid = XR_ERROR_LOCALIZED_NAME_INVALID,

  ErrorAndroidThreadSettingsIdInvalidKHR =
      XR_ERROR_ANDROID_THREAD_SETTINGS_ID_INVALID_KHR,

  ErrorAndroidThreadSettingsFailureKHR =
      XR_ERROR_ANDROID_THREAD_SETTINGS_FAILURE_KHR,

  ErrorCreateSpatialAnchorFailedMSFT =
      XR_ERROR_CREATE_SPATIAL_ANCHOR_FAILED_MSFT,

};

//! @brief Free function for retrieving the raw XrResult value from a Result
//! @relates Result
OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR XrResult get(Result const &v) {
  return static_cast<XrResult>(v);
}

//! @brief Free function for retrieving the string name of a Result value as a
//! const char *
//! @relates Result
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char *
to_string_literal(Result value) {
  switch (value) {

  case Result::Success:
    return "Success";

  case Result::TimeoutExpired:
    return "TimeoutExpired";

  case Result::SessionLossPending:
    return "SessionLossPending";

  case Result::EventUnavailable:
    return "EventUnavailable";

  case Result::SpaceBoundsUnavailable:
    return "SpaceBoundsUnavailable";

  case Result::SessionNotFocused:
    return "SessionNotFocused";

  case Result::FrameDiscarded:
    return "FrameDiscarded";

  case Result::ErrorValidationFailure:
    return "ErrorValidationFailure";

  case Result::ErrorRuntimeFailure:
    return "ErrorRuntimeFailure";

  case Result::ErrorOutOfMemory:
    return "ErrorOutOfMemory";

  case Result::ErrorApiVersionUnsupported:
    return "ErrorApiVersionUnsupported";

  case Result::ErrorInitializationFailed:
    return "ErrorInitializationFailed";

  case Result::ErrorFunctionUnsupported:
    return "ErrorFunctionUnsupported";

  case Result::ErrorFeatureUnsupported:
    return "ErrorFeatureUnsupported";

  case Result::ErrorExtensionNotPresent:
    return "ErrorExtensionNotPresent";

  case Result::ErrorLimitReached:
    return "ErrorLimitReached";

  case Result::ErrorSizeInsufficient:
    return "ErrorSizeInsufficient";

  case Result::ErrorHandleInvalid:
    return "ErrorHandleInvalid";

  case Result::ErrorInstanceLost:
    return "ErrorInstanceLost";

  case Result::ErrorSessionRunning:
    return "ErrorSessionRunning";

  case Result::ErrorSessionNotRunning:
    return "ErrorSessionNotRunning";

  case Result::ErrorSessionLost:
    return "ErrorSessionLost";

  case Result::ErrorSystemInvalid:
    return "ErrorSystemInvalid";

  case Result::ErrorPathInvalid:
    return "ErrorPathInvalid";

  case Result::ErrorPathCountExceeded:
    return "ErrorPathCountExceeded";

  case Result::ErrorPathFormatInvalid:
    return "ErrorPathFormatInvalid";

  case Result::ErrorPathUnsupported:
    return "ErrorPathUnsupported";

  case Result::ErrorLayerInvalid:
    return "ErrorLayerInvalid";

  case Result::ErrorLayerLimitExceeded:
    return "ErrorLayerLimitExceeded";

  case Result::ErrorSwapchainRectInvalid:
    return "ErrorSwapchainRectInvalid";

  case Result::ErrorSwapchainFormatUnsupported:
    return "ErrorSwapchainFormatUnsupported";

  case Result::ErrorActionTypeMismatch:
    return "ErrorActionTypeMismatch";

  case Result::ErrorSessionNotReady:
    return "ErrorSessionNotReady";

  case Result::ErrorSessionNotStopping:
    return "ErrorSessionNotStopping";

  case Result::ErrorTimeInvalid:
    return "ErrorTimeInvalid";

  case Result::ErrorReferenceSpaceUnsupported:
    return "ErrorReferenceSpaceUnsupported";

  case Result::ErrorFileAccessError:
    return "ErrorFileAccessError";

  case Result::ErrorFileContentsInvalid:
    return "ErrorFileContentsInvalid";

  case Result::ErrorFormFactorUnsupported:
    return "ErrorFormFactorUnsupported";

  case Result::ErrorFormFactorUnavailable:
    return "ErrorFormFactorUnavailable";

  case Result::ErrorApiLayerNotPresent:
    return "ErrorApiLayerNotPresent";

  case Result::ErrorCallOrderInvalid:
    return "ErrorCallOrderInvalid";

  case Result::ErrorGraphicsDeviceInvalid:
    return "ErrorGraphicsDeviceInvalid";

  case Result::ErrorPoseInvalid:
    return "ErrorPoseInvalid";

  case Result::ErrorIndexOutOfRange:
    return "ErrorIndexOutOfRange";

  case Result::ErrorViewConfigurationTypeUnsupported:
    return "ErrorViewConfigurationTypeUnsupported";

  case Result::ErrorEnvironmentBlendModeUnsupported:
    return "ErrorEnvironmentBlendModeUnsupported";

  case Result::ErrorNameDuplicated:
    return "ErrorNameDuplicated";

  case Result::ErrorNameInvalid:
    return "ErrorNameInvalid";

  case Result::ErrorActionsetNotAttached:
    return "ErrorActionsetNotAttached";

  case Result::ErrorActionsetsAlreadyAttached:
    return "ErrorActionsetsAlreadyAttached";

  case Result::ErrorLocalizedNameDuplicated:
    return "ErrorLocalizedNameDuplicated";

  case Result::ErrorLocalizedNameInvalid:
    return "ErrorLocalizedNameInvalid";

  case Result::ErrorAndroidThreadSettingsIdInvalidKHR:
    return "ErrorAndroidThreadSettingsIdInvalidKHR";

  case Result::ErrorAndroidThreadSettingsFailureKHR:
    return "ErrorAndroidThreadSettingsFailureKHR";

  case Result::ErrorCreateSpatialAnchorFailedMSFT:
    return "ErrorCreateSpatialAnchorFailedMSFT";

  default:
    return "invalid";
  }
}

//! @brief Free function for retrieving the string name of a Result value as a
//! std::string
//! @relates Result
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string
to_string(Result value) {
  return {to_string_literal(value)};
}

//! @brief Enum class associated with XrStructureType
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrStructureType>
enum class StructureType : uint32_t {

  Unknown = XR_TYPE_UNKNOWN,

  ApiLayerProperties = XR_TYPE_API_LAYER_PROPERTIES,

  ExtensionProperties = XR_TYPE_EXTENSION_PROPERTIES,

  InstanceCreateInfo = XR_TYPE_INSTANCE_CREATE_INFO,

  SystemGetInfo = XR_TYPE_SYSTEM_GET_INFO,

  SystemProperties = XR_TYPE_SYSTEM_PROPERTIES,

  ViewLocateInfo = XR_TYPE_VIEW_LOCATE_INFO,

  View = XR_TYPE_VIEW,

  SessionCreateInfo = XR_TYPE_SESSION_CREATE_INFO,

  SwapchainCreateInfo = XR_TYPE_SWAPCHAIN_CREATE_INFO,

  SessionBeginInfo = XR_TYPE_SESSION_BEGIN_INFO,

  ViewState = XR_TYPE_VIEW_STATE,

  FrameEndInfo = XR_TYPE_FRAME_END_INFO,

  HapticVibration = XR_TYPE_HAPTIC_VIBRATION,

  EventDataBuffer = XR_TYPE_EVENT_DATA_BUFFER,

  EventDataInstanceLossPending = XR_TYPE_EVENT_DATA_INSTANCE_LOSS_PENDING,

  EventDataSessionStateChanged = XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED,

  ActionStateBoolean = XR_TYPE_ACTION_STATE_BOOLEAN,

  ActionStateFloat = XR_TYPE_ACTION_STATE_FLOAT,

  ActionStateVector2F = XR_TYPE_ACTION_STATE_VECTOR2F,

  ActionStatePose = XR_TYPE_ACTION_STATE_POSE,

  ActionSetCreateInfo = XR_TYPE_ACTION_SET_CREATE_INFO,

  ActionCreateInfo = XR_TYPE_ACTION_CREATE_INFO,

  InstanceProperties = XR_TYPE_INSTANCE_PROPERTIES,

  FrameWaitInfo = XR_TYPE_FRAME_WAIT_INFO,

  CompositionLayerProjection = XR_TYPE_COMPOSITION_LAYER_PROJECTION,

  CompositionLayerQuad = XR_TYPE_COMPOSITION_LAYER_QUAD,

  ReferenceSpaceCreateInfo = XR_TYPE_REFERENCE_SPACE_CREATE_INFO,

  ActionSpaceCreateInfo = XR_TYPE_ACTION_SPACE_CREATE_INFO,

  EventDataReferenceSpaceChangePending =
      XR_TYPE_EVENT_DATA_REFERENCE_SPACE_CHANGE_PENDING,

  ViewConfigurationView = XR_TYPE_VIEW_CONFIGURATION_VIEW,

  SpaceLocation = XR_TYPE_SPACE_LOCATION,

  SpaceVelocity = XR_TYPE_SPACE_VELOCITY,

  FrameState = XR_TYPE_FRAME_STATE,

  ViewConfigurationProperties = XR_TYPE_VIEW_CONFIGURATION_PROPERTIES,

  FrameBeginInfo = XR_TYPE_FRAME_BEGIN_INFO,

  CompositionLayerProjectionView = XR_TYPE_COMPOSITION_LAYER_PROJECTION_VIEW,

  EventDataEventsLost = XR_TYPE_EVENT_DATA_EVENTS_LOST,

  InteractionProfileSuggestedBinding =
      XR_TYPE_INTERACTION_PROFILE_SUGGESTED_BINDING,

  EventDataInteractionProfileChanged =
      XR_TYPE_EVENT_DATA_INTERACTION_PROFILE_CHANGED,

  InteractionProfileState = XR_TYPE_INTERACTION_PROFILE_STATE,

  SwapchainImageAcquireInfo = XR_TYPE_SWAPCHAIN_IMAGE_ACQUIRE_INFO,

  SwapchainImageWaitInfo = XR_TYPE_SWAPCHAIN_IMAGE_WAIT_INFO,

  SwapchainImageReleaseInfo = XR_TYPE_SWAPCHAIN_IMAGE_RELEASE_INFO,

  ActionStateGetInfo = XR_TYPE_ACTION_STATE_GET_INFO,

  HapticActionInfo = XR_TYPE_HAPTIC_ACTION_INFO,

  SessionActionSetsAttachInfo = XR_TYPE_SESSION_ACTION_SETS_ATTACH_INFO,

  ActionsSyncInfo = XR_TYPE_ACTIONS_SYNC_INFO,

  BoundSourcesForActionEnumerateInfo =
      XR_TYPE_BOUND_SOURCES_FOR_ACTION_ENUMERATE_INFO,

  InputSourceLocalizedNameGetInfo =
      XR_TYPE_INPUT_SOURCE_LOCALIZED_NAME_GET_INFO,

  CompositionLayerCubeKHR = XR_TYPE_COMPOSITION_LAYER_CUBE_KHR,

  InstanceCreateInfoAndroidKHR = XR_TYPE_INSTANCE_CREATE_INFO_ANDROID_KHR,

  CompositionLayerDepthInfoKHR = XR_TYPE_COMPOSITION_LAYER_DEPTH_INFO_KHR,

  VulkanSwapchainFormatListCreateInfoKHR =
      XR_TYPE_VULKAN_SWAPCHAIN_FORMAT_LIST_CREATE_INFO_KHR,

  EventDataPerfSettingsEXT = XR_TYPE_EVENT_DATA_PERF_SETTINGS_EXT,

  CompositionLayerCylinderKHR = XR_TYPE_COMPOSITION_LAYER_CYLINDER_KHR,

  CompositionLayerEquirectKHR = XR_TYPE_COMPOSITION_LAYER_EQUIRECT_KHR,

  DebugUtilsObjectNameInfoEXT = XR_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT,

  DebugUtilsMessengerCallbackDataEXT =
      XR_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT,

  DebugUtilsMessengerCreateInfoEXT =
      XR_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT,

  DebugUtilsLabelEXT = XR_TYPE_DEBUG_UTILS_LABEL_EXT,

  GraphicsBindingOpenglWin32KHR = XR_TYPE_GRAPHICS_BINDING_OPENGL_WIN32_KHR,

  GraphicsBindingOpenglXlibKHR = XR_TYPE_GRAPHICS_BINDING_OPENGL_XLIB_KHR,

  GraphicsBindingOpenglXcbKHR = XR_TYPE_GRAPHICS_BINDING_OPENGL_XCB_KHR,

  GraphicsBindingOpenglWaylandKHR = XR_TYPE_GRAPHICS_BINDING_OPENGL_WAYLAND_KHR,

  SwapchainImageOpenglKHR = XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_KHR,

  GraphicsRequirementsOpenglKHR = XR_TYPE_GRAPHICS_REQUIREMENTS_OPENGL_KHR,

  GraphicsBindingOpenglEsAndroidKHR =
      XR_TYPE_GRAPHICS_BINDING_OPENGL_ES_ANDROID_KHR,

  SwapchainImageOpenglEsKHR = XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_ES_KHR,

  GraphicsRequirementsOpenglEsKHR = XR_TYPE_GRAPHICS_REQUIREMENTS_OPENGL_ES_KHR,

  GraphicsBindingVulkanKHR = XR_TYPE_GRAPHICS_BINDING_VULKAN_KHR,

  SwapchainImageVulkanKHR = XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR,

  GraphicsRequirementsVulkanKHR = XR_TYPE_GRAPHICS_REQUIREMENTS_VULKAN_KHR,

  GraphicsBindingD3D11KHR = XR_TYPE_GRAPHICS_BINDING_D3D11_KHR,

  SwapchainImageD3D11KHR = XR_TYPE_SWAPCHAIN_IMAGE_D3D11_KHR,

  GraphicsRequirementsD3D11KHR = XR_TYPE_GRAPHICS_REQUIREMENTS_D3D11_KHR,

  GraphicsBindingD3D12KHR = XR_TYPE_GRAPHICS_BINDING_D3D12_KHR,

  SwapchainImageD3D12KHR = XR_TYPE_SWAPCHAIN_IMAGE_D3D12_KHR,

  GraphicsRequirementsD3D12KHR = XR_TYPE_GRAPHICS_REQUIREMENTS_D3D12_KHR,

  VisibilityMaskKHR = XR_TYPE_VISIBILITY_MASK_KHR,

  EventDataVisibilityMaskChangedKHR =
      XR_TYPE_EVENT_DATA_VISIBILITY_MASK_CHANGED_KHR,

  SpatialAnchorCreateInfoMSFT = XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_MSFT,

  SpatialAnchorSpaceCreateInfoMSFT =
      XR_TYPE_SPATIAL_ANCHOR_SPACE_CREATE_INFO_MSFT,

};

//! @brief Free function for retrieving the raw XrStructureType value from a
//! StructureType
//! @relates StructureType
OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR XrStructureType
get(StructureType const &v) {
  return static_cast<XrStructureType>(v);
}

//! @brief Free function for retrieving the string name of a StructureType value
//! as a const char *
//! @relates StructureType
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char *
to_string_literal(StructureType value) {
  switch (value) {

  case StructureType::Unknown:
    return "Unknown";

  case StructureType::ApiLayerProperties:
    return "ApiLayerProperties";

  case StructureType::ExtensionProperties:
    return "ExtensionProperties";

  case StructureType::InstanceCreateInfo:
    return "InstanceCreateInfo";

  case StructureType::SystemGetInfo:
    return "SystemGetInfo";

  case StructureType::SystemProperties:
    return "SystemProperties";

  case StructureType::ViewLocateInfo:
    return "ViewLocateInfo";

  case StructureType::View:
    return "View";

  case StructureType::SessionCreateInfo:
    return "SessionCreateInfo";

  case StructureType::SwapchainCreateInfo:
    return "SwapchainCreateInfo";

  case StructureType::SessionBeginInfo:
    return "SessionBeginInfo";

  case StructureType::ViewState:
    return "ViewState";

  case StructureType::FrameEndInfo:
    return "FrameEndInfo";

  case StructureType::HapticVibration:
    return "HapticVibration";

  case StructureType::EventDataBuffer:
    return "EventDataBuffer";

  case StructureType::EventDataInstanceLossPending:
    return "EventDataInstanceLossPending";

  case StructureType::EventDataSessionStateChanged:
    return "EventDataSessionStateChanged";

  case StructureType::ActionStateBoolean:
    return "ActionStateBoolean";

  case StructureType::ActionStateFloat:
    return "ActionStateFloat";

  case StructureType::ActionStateVector2F:
    return "ActionStateVector2F";

  case StructureType::ActionStatePose:
    return "ActionStatePose";

  case StructureType::ActionSetCreateInfo:
    return "ActionSetCreateInfo";

  case StructureType::ActionCreateInfo:
    return "ActionCreateInfo";

  case StructureType::InstanceProperties:
    return "InstanceProperties";

  case StructureType::FrameWaitInfo:
    return "FrameWaitInfo";

  case StructureType::CompositionLayerProjection:
    return "CompositionLayerProjection";

  case StructureType::CompositionLayerQuad:
    return "CompositionLayerQuad";

  case StructureType::ReferenceSpaceCreateInfo:
    return "ReferenceSpaceCreateInfo";

  case StructureType::ActionSpaceCreateInfo:
    return "ActionSpaceCreateInfo";

  case StructureType::EventDataReferenceSpaceChangePending:
    return "EventDataReferenceSpaceChangePending";

  case StructureType::ViewConfigurationView:
    return "ViewConfigurationView";

  case StructureType::SpaceLocation:
    return "SpaceLocation";

  case StructureType::SpaceVelocity:
    return "SpaceVelocity";

  case StructureType::FrameState:
    return "FrameState";

  case StructureType::ViewConfigurationProperties:
    return "ViewConfigurationProperties";

  case StructureType::FrameBeginInfo:
    return "FrameBeginInfo";

  case StructureType::CompositionLayerProjectionView:
    return "CompositionLayerProjectionView";

  case StructureType::EventDataEventsLost:
    return "EventDataEventsLost";

  case StructureType::InteractionProfileSuggestedBinding:
    return "InteractionProfileSuggestedBinding";

  case StructureType::EventDataInteractionProfileChanged:
    return "EventDataInteractionProfileChanged";

  case StructureType::InteractionProfileState:
    return "InteractionProfileState";

  case StructureType::SwapchainImageAcquireInfo:
    return "SwapchainImageAcquireInfo";

  case StructureType::SwapchainImageWaitInfo:
    return "SwapchainImageWaitInfo";

  case StructureType::SwapchainImageReleaseInfo:
    return "SwapchainImageReleaseInfo";

  case StructureType::ActionStateGetInfo:
    return "ActionStateGetInfo";

  case StructureType::HapticActionInfo:
    return "HapticActionInfo";

  case StructureType::SessionActionSetsAttachInfo:
    return "SessionActionSetsAttachInfo";

  case StructureType::ActionsSyncInfo:
    return "ActionsSyncInfo";

  case StructureType::BoundSourcesForActionEnumerateInfo:
    return "BoundSourcesForActionEnumerateInfo";

  case StructureType::InputSourceLocalizedNameGetInfo:
    return "InputSourceLocalizedNameGetInfo";

  case StructureType::CompositionLayerCubeKHR:
    return "CompositionLayerCubeKHR";

  case StructureType::InstanceCreateInfoAndroidKHR:
    return "InstanceCreateInfoAndroidKHR";

  case StructureType::CompositionLayerDepthInfoKHR:
    return "CompositionLayerDepthInfoKHR";

  case StructureType::VulkanSwapchainFormatListCreateInfoKHR:
    return "VulkanSwapchainFormatListCreateInfoKHR";

  case StructureType::EventDataPerfSettingsEXT:
    return "EventDataPerfSettingsEXT";

  case StructureType::CompositionLayerCylinderKHR:
    return "CompositionLayerCylinderKHR";

  case StructureType::CompositionLayerEquirectKHR:
    return "CompositionLayerEquirectKHR";

  case StructureType::DebugUtilsObjectNameInfoEXT:
    return "DebugUtilsObjectNameInfoEXT";

  case StructureType::DebugUtilsMessengerCallbackDataEXT:
    return "DebugUtilsMessengerCallbackDataEXT";

  case StructureType::DebugUtilsMessengerCreateInfoEXT:
    return "DebugUtilsMessengerCreateInfoEXT";

  case StructureType::DebugUtilsLabelEXT:
    return "DebugUtilsLabelEXT";

  case StructureType::GraphicsBindingOpenglWin32KHR:
    return "GraphicsBindingOpenglWin32KHR";

  case StructureType::GraphicsBindingOpenglXlibKHR:
    return "GraphicsBindingOpenglXlibKHR";

  case StructureType::GraphicsBindingOpenglXcbKHR:
    return "GraphicsBindingOpenglXcbKHR";

  case StructureType::GraphicsBindingOpenglWaylandKHR:
    return "GraphicsBindingOpenglWaylandKHR";

  case StructureType::SwapchainImageOpenglKHR:
    return "SwapchainImageOpenglKHR";

  case StructureType::GraphicsRequirementsOpenglKHR:
    return "GraphicsRequirementsOpenglKHR";

  case StructureType::GraphicsBindingOpenglEsAndroidKHR:
    return "GraphicsBindingOpenglEsAndroidKHR";

  case StructureType::SwapchainImageOpenglEsKHR:
    return "SwapchainImageOpenglEsKHR";

  case StructureType::GraphicsRequirementsOpenglEsKHR:
    return "GraphicsRequirementsOpenglEsKHR";

  case StructureType::GraphicsBindingVulkanKHR:
    return "GraphicsBindingVulkanKHR";

  case StructureType::SwapchainImageVulkanKHR:
    return "SwapchainImageVulkanKHR";

  case StructureType::GraphicsRequirementsVulkanKHR:
    return "GraphicsRequirementsVulkanKHR";

  case StructureType::GraphicsBindingD3D11KHR:
    return "GraphicsBindingD3D11KHR";

  case StructureType::SwapchainImageD3D11KHR:
    return "SwapchainImageD3D11KHR";

  case StructureType::GraphicsRequirementsD3D11KHR:
    return "GraphicsRequirementsD3D11KHR";

  case StructureType::GraphicsBindingD3D12KHR:
    return "GraphicsBindingD3D12KHR";

  case StructureType::SwapchainImageD3D12KHR:
    return "SwapchainImageD3D12KHR";

  case StructureType::GraphicsRequirementsD3D12KHR:
    return "GraphicsRequirementsD3D12KHR";

  case StructureType::VisibilityMaskKHR:
    return "VisibilityMaskKHR";

  case StructureType::EventDataVisibilityMaskChangedKHR:
    return "EventDataVisibilityMaskChangedKHR";

  case StructureType::SpatialAnchorCreateInfoMSFT:
    return "SpatialAnchorCreateInfoMSFT";

  case StructureType::SpatialAnchorSpaceCreateInfoMSFT:
    return "SpatialAnchorSpaceCreateInfoMSFT";

  default:
    return "invalid";
  }
}

//! @brief Free function for retrieving the string name of a StructureType value
//! as a std::string
//! @relates StructureType
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string
to_string(StructureType value) {
  return {to_string_literal(value)};
}

//! @brief Enum class associated with XrFormFactor
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrFormFactor>
enum class FormFactor : uint32_t {

  HeadMountedDisplay = XR_FORM_FACTOR_HEAD_MOUNTED_DISPLAY,

  HandheldDisplay = XR_FORM_FACTOR_HANDHELD_DISPLAY,

};

//! @brief Free function for retrieving the raw XrFormFactor value from a
//! FormFactor
//! @relates FormFactor
OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR XrFormFactor get(FormFactor const &v) {
  return static_cast<XrFormFactor>(v);
}

//! @brief Free function for retrieving the string name of a FormFactor value as
//! a const char *
//! @relates FormFactor
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char *
to_string_literal(FormFactor value) {
  switch (value) {

  case FormFactor::HeadMountedDisplay:
    return "HeadMountedDisplay";

  case FormFactor::HandheldDisplay:
    return "HandheldDisplay";

  default:
    return "invalid";
  }
}

//! @brief Free function for retrieving the string name of a FormFactor value as
//! a std::string
//! @relates FormFactor
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string
to_string(FormFactor value) {
  return {to_string_literal(value)};
}

//! @brief Enum class associated with XrViewConfigurationType
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrViewConfigurationType>
enum class ViewConfigurationType : uint32_t {

  PrimaryMono = XR_VIEW_CONFIGURATION_TYPE_PRIMARY_MONO,

  PrimaryStereo = XR_VIEW_CONFIGURATION_TYPE_PRIMARY_STEREO,

  PrimaryQuadVARJO = XR_VIEW_CONFIGURATION_TYPE_PRIMARY_QUAD_VARJO,

};

//! @brief Free function for retrieving the raw XrViewConfigurationType value
//! from a ViewConfigurationType
//! @relates ViewConfigurationType
OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR XrViewConfigurationType
get(ViewConfigurationType const &v) {
  return static_cast<XrViewConfigurationType>(v);
}

//! @brief Free function for retrieving the string name of a
//! ViewConfigurationType value as a const char *
//! @relates ViewConfigurationType
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char *
to_string_literal(ViewConfigurationType value) {
  switch (value) {

  case ViewConfigurationType::PrimaryMono:
    return "PrimaryMono";

  case ViewConfigurationType::PrimaryStereo:
    return "PrimaryStereo";

  case ViewConfigurationType::PrimaryQuadVARJO:
    return "PrimaryQuadVARJO";

  default:
    return "invalid";
  }
}

//! @brief Free function for retrieving the string name of a
//! ViewConfigurationType value as a std::string
//! @relates ViewConfigurationType
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string
to_string(ViewConfigurationType value) {
  return {to_string_literal(value)};
}

//! @brief Enum class associated with XrEnvironmentBlendMode
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrEnvironmentBlendMode>
enum class EnvironmentBlendMode : uint32_t {

  Opaque = XR_ENVIRONMENT_BLEND_MODE_OPAQUE,

  Additive = XR_ENVIRONMENT_BLEND_MODE_ADDITIVE,

  AlphaBlend = XR_ENVIRONMENT_BLEND_MODE_ALPHA_BLEND,

};

//! @brief Free function for retrieving the raw XrEnvironmentBlendMode value
//! from a EnvironmentBlendMode
//! @relates EnvironmentBlendMode
OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR XrEnvironmentBlendMode
get(EnvironmentBlendMode const &v) {
  return static_cast<XrEnvironmentBlendMode>(v);
}

//! @brief Free function for retrieving the string name of a
//! EnvironmentBlendMode value as a const char *
//! @relates EnvironmentBlendMode
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char *
to_string_literal(EnvironmentBlendMode value) {
  switch (value) {

  case EnvironmentBlendMode::Opaque:
    return "Opaque";

  case EnvironmentBlendMode::Additive:
    return "Additive";

  case EnvironmentBlendMode::AlphaBlend:
    return "AlphaBlend";

  default:
    return "invalid";
  }
}

//! @brief Free function for retrieving the string name of a
//! EnvironmentBlendMode value as a std::string
//! @relates EnvironmentBlendMode
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string
to_string(EnvironmentBlendMode value) {
  return {to_string_literal(value)};
}

//! @brief Enum class associated with XrReferenceSpaceType
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrReferenceSpaceType>
enum class ReferenceSpaceType : uint32_t {

  View = XR_REFERENCE_SPACE_TYPE_VIEW,

  Local = XR_REFERENCE_SPACE_TYPE_LOCAL,

  Stage = XR_REFERENCE_SPACE_TYPE_STAGE,

  UnboundedMSFT = XR_REFERENCE_SPACE_TYPE_UNBOUNDED_MSFT,

};

//! @brief Free function for retrieving the raw XrReferenceSpaceType value from
//! a ReferenceSpaceType
//! @relates ReferenceSpaceType
OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR XrReferenceSpaceType
get(ReferenceSpaceType const &v) {
  return static_cast<XrReferenceSpaceType>(v);
}

//! @brief Free function for retrieving the string name of a ReferenceSpaceType
//! value as a const char *
//! @relates ReferenceSpaceType
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char *
to_string_literal(ReferenceSpaceType value) {
  switch (value) {

  case ReferenceSpaceType::View:
    return "View";

  case ReferenceSpaceType::Local:
    return "Local";

  case ReferenceSpaceType::Stage:
    return "Stage";

  case ReferenceSpaceType::UnboundedMSFT:
    return "UnboundedMSFT";

  default:
    return "invalid";
  }
}

//! @brief Free function for retrieving the string name of a ReferenceSpaceType
//! value as a std::string
//! @relates ReferenceSpaceType
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string
to_string(ReferenceSpaceType value) {
  return {to_string_literal(value)};
}

//! @brief Enum class associated with XrActionType
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrActionType>
enum class ActionType : uint32_t {

  BooleanInput = XR_ACTION_TYPE_BOOLEAN_INPUT,

  FloatInput = XR_ACTION_TYPE_FLOAT_INPUT,

  Vector2FInput = XR_ACTION_TYPE_VECTOR2F_INPUT,

  PoseInput = XR_ACTION_TYPE_POSE_INPUT,

  VibrationOutput = XR_ACTION_TYPE_VIBRATION_OUTPUT,

};

//! @brief Free function for retrieving the raw XrActionType value from a
//! ActionType
//! @relates ActionType
OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR XrActionType get(ActionType const &v) {
  return static_cast<XrActionType>(v);
}

//! @brief Free function for retrieving the string name of a ActionType value as
//! a const char *
//! @relates ActionType
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char *
to_string_literal(ActionType value) {
  switch (value) {

  case ActionType::BooleanInput:
    return "BooleanInput";

  case ActionType::FloatInput:
    return "FloatInput";

  case ActionType::Vector2FInput:
    return "Vector2FInput";

  case ActionType::PoseInput:
    return "PoseInput";

  case ActionType::VibrationOutput:
    return "VibrationOutput";

  default:
    return "invalid";
  }
}

//! @brief Free function for retrieving the string name of a ActionType value as
//! a std::string
//! @relates ActionType
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string
to_string(ActionType value) {
  return {to_string_literal(value)};
}

//! @brief Enum class associated with XrEyeVisibility
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrEyeVisibility>
enum class EyeVisibility : uint32_t {

  Both = XR_EYE_VISIBILITY_BOTH,

  Left = XR_EYE_VISIBILITY_LEFT,

  Right = XR_EYE_VISIBILITY_RIGHT,

};

//! @brief Free function for retrieving the raw XrEyeVisibility value from a
//! EyeVisibility
//! @relates EyeVisibility
OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR XrEyeVisibility
get(EyeVisibility const &v) {
  return static_cast<XrEyeVisibility>(v);
}

//! @brief Free function for retrieving the string name of a EyeVisibility value
//! as a const char *
//! @relates EyeVisibility
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char *
to_string_literal(EyeVisibility value) {
  switch (value) {

  case EyeVisibility::Both:
    return "Both";

  case EyeVisibility::Left:
    return "Left";

  case EyeVisibility::Right:
    return "Right";

  default:
    return "invalid";
  }
}

//! @brief Free function for retrieving the string name of a EyeVisibility value
//! as a std::string
//! @relates EyeVisibility
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string
to_string(EyeVisibility value) {
  return {to_string_literal(value)};
}

//! @brief Enum class associated with XrSessionState
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrSessionState>
enum class SessionState : uint32_t {

  Unknown = XR_SESSION_STATE_UNKNOWN,

  Idle = XR_SESSION_STATE_IDLE,

  Ready = XR_SESSION_STATE_READY,

  Synchronized = XR_SESSION_STATE_SYNCHRONIZED,

  Visible = XR_SESSION_STATE_VISIBLE,

  Focused = XR_SESSION_STATE_FOCUSED,

  Stopping = XR_SESSION_STATE_STOPPING,

  LossPending = XR_SESSION_STATE_LOSS_PENDING,

  Exiting = XR_SESSION_STATE_EXITING,

};

//! @brief Free function for retrieving the raw XrSessionState value from a
//! SessionState
//! @relates SessionState
OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR XrSessionState
get(SessionState const &v) {
  return static_cast<XrSessionState>(v);
}

//! @brief Free function for retrieving the string name of a SessionState value
//! as a const char *
//! @relates SessionState
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char *
to_string_literal(SessionState value) {
  switch (value) {

  case SessionState::Unknown:
    return "Unknown";

  case SessionState::Idle:
    return "Idle";

  case SessionState::Ready:
    return "Ready";

  case SessionState::Synchronized:
    return "Synchronized";

  case SessionState::Visible:
    return "Visible";

  case SessionState::Focused:
    return "Focused";

  case SessionState::Stopping:
    return "Stopping";

  case SessionState::LossPending:
    return "LossPending";

  case SessionState::Exiting:
    return "Exiting";

  default:
    return "invalid";
  }
}

//! @brief Free function for retrieving the string name of a SessionState value
//! as a std::string
//! @relates SessionState
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string
to_string(SessionState value) {
  return {to_string_literal(value)};
}

//! @brief Enum class associated with XrObjectType
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrObjectType>
enum class ObjectType : uint32_t {

  Unknown = XR_OBJECT_TYPE_UNKNOWN,

  Instance = XR_OBJECT_TYPE_INSTANCE,

  Session = XR_OBJECT_TYPE_SESSION,

  Swapchain = XR_OBJECT_TYPE_SWAPCHAIN,

  Space = XR_OBJECT_TYPE_SPACE,

  ActionSet = XR_OBJECT_TYPE_ACTION_SET,

  Action = XR_OBJECT_TYPE_ACTION,

  DebugUtilsMessengerEXT = XR_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT,

  SpatialAnchorMSFT = XR_OBJECT_TYPE_SPATIAL_ANCHOR_MSFT,

};

//! @brief Free function for retrieving the raw XrObjectType value from a
//! ObjectType
//! @relates ObjectType
OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR XrObjectType get(ObjectType const &v) {
  return static_cast<XrObjectType>(v);
}

//! @brief Free function for retrieving the string name of a ObjectType value as
//! a const char *
//! @relates ObjectType
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char *
to_string_literal(ObjectType value) {
  switch (value) {

  case ObjectType::Unknown:
    return "Unknown";

  case ObjectType::Instance:
    return "Instance";

  case ObjectType::Session:
    return "Session";

  case ObjectType::Swapchain:
    return "Swapchain";

  case ObjectType::Space:
    return "Space";

  case ObjectType::ActionSet:
    return "ActionSet";

  case ObjectType::Action:
    return "Action";

  case ObjectType::DebugUtilsMessengerEXT:
    return "DebugUtilsMessengerEXT";

  case ObjectType::SpatialAnchorMSFT:
    return "SpatialAnchorMSFT";

  default:
    return "invalid";
  }
}

//! @brief Free function for retrieving the string name of a ObjectType value as
//! a std::string
//! @relates ObjectType
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string
to_string(ObjectType value) {
  return {to_string_literal(value)};
}

#if defined(XR_USE_PLATFORM_ANDROID)
//! @brief Enum class associated with XrAndroidThreadTypeKHR
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrAndroidThreadTypeKHR>
enum class AndroidThreadTypeKHR : uint32_t {

  ApplicationMain = XR_ANDROID_THREAD_TYPE_APPLICATION_MAIN_KHR,

  ApplicationWorker = XR_ANDROID_THREAD_TYPE_APPLICATION_WORKER_KHR,

  RendererMain = XR_ANDROID_THREAD_TYPE_RENDERER_MAIN_KHR,

  RendererWorker = XR_ANDROID_THREAD_TYPE_RENDERER_WORKER_KHR,

};

//! @brief Free function for retrieving the raw XrAndroidThreadTypeKHR value
//! from a AndroidThreadTypeKHR
//! @relates AndroidThreadTypeKHR
OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR XrAndroidThreadTypeKHR
get(AndroidThreadTypeKHR const &v) {
  return static_cast<XrAndroidThreadTypeKHR>(v);
}

//! @brief Free function for retrieving the string name of a
//! AndroidThreadTypeKHR value as a const char *
//! @relates AndroidThreadTypeKHR
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char *
to_string_literal(AndroidThreadTypeKHR value) {
  switch (value) {

  case AndroidThreadTypeKHR::ApplicationMain:
    return "ApplicationMain";

  case AndroidThreadTypeKHR::ApplicationWorker:
    return "ApplicationWorker";

  case AndroidThreadTypeKHR::RendererMain:
    return "RendererMain";

  case AndroidThreadTypeKHR::RendererWorker:
    return "RendererWorker";

  default:
    return "invalid";
  }
}

//! @brief Free function for retrieving the string name of a
//! AndroidThreadTypeKHR value as a std::string
//! @relates AndroidThreadTypeKHR
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string
to_string(AndroidThreadTypeKHR value) {
  return {to_string_literal(value)};
}

#endif // defined(XR_USE_PLATFORM_ANDROID)

//! @brief Enum class associated with XrVisibilityMaskTypeKHR
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrVisibilityMaskTypeKHR>
enum class VisibilityMaskTypeKHR : uint32_t {

  HiddenTriangleMesh = XR_VISIBILITY_MASK_TYPE_HIDDEN_TRIANGLE_MESH_KHR,

  VisibleTriangleMesh = XR_VISIBILITY_MASK_TYPE_VISIBLE_TRIANGLE_MESH_KHR,

  LineLoop = XR_VISIBILITY_MASK_TYPE_LINE_LOOP_KHR,

};

//! @brief Free function for retrieving the raw XrVisibilityMaskTypeKHR value
//! from a VisibilityMaskTypeKHR
//! @relates VisibilityMaskTypeKHR
OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR XrVisibilityMaskTypeKHR
get(VisibilityMaskTypeKHR const &v) {
  return static_cast<XrVisibilityMaskTypeKHR>(v);
}

//! @brief Free function for retrieving the string name of a
//! VisibilityMaskTypeKHR value as a const char *
//! @relates VisibilityMaskTypeKHR
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char *
to_string_literal(VisibilityMaskTypeKHR value) {
  switch (value) {

  case VisibilityMaskTypeKHR::HiddenTriangleMesh:
    return "HiddenTriangleMesh";

  case VisibilityMaskTypeKHR::VisibleTriangleMesh:
    return "VisibleTriangleMesh";

  case VisibilityMaskTypeKHR::LineLoop:
    return "LineLoop";

  default:
    return "invalid";
  }
}

//! @brief Free function for retrieving the string name of a
//! VisibilityMaskTypeKHR value as a std::string
//! @relates VisibilityMaskTypeKHR
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string
to_string(VisibilityMaskTypeKHR value) {
  return {to_string_literal(value)};
}

//! @brief Enum class associated with XrPerfSettingsDomainEXT
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrPerfSettingsDomainEXT>
enum class PerfSettingsDomainEXT : uint32_t {

  Cpu = XR_PERF_SETTINGS_DOMAIN_CPU_EXT,

  Gpu = XR_PERF_SETTINGS_DOMAIN_GPU_EXT,

};

//! @brief Free function for retrieving the raw XrPerfSettingsDomainEXT value
//! from a PerfSettingsDomainEXT
//! @relates PerfSettingsDomainEXT
OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR XrPerfSettingsDomainEXT
get(PerfSettingsDomainEXT const &v) {
  return static_cast<XrPerfSettingsDomainEXT>(v);
}

//! @brief Free function for retrieving the string name of a
//! PerfSettingsDomainEXT value as a const char *
//! @relates PerfSettingsDomainEXT
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char *
to_string_literal(PerfSettingsDomainEXT value) {
  switch (value) {

  case PerfSettingsDomainEXT::Cpu:
    return "Cpu";

  case PerfSettingsDomainEXT::Gpu:
    return "Gpu";

  default:
    return "invalid";
  }
}

//! @brief Free function for retrieving the string name of a
//! PerfSettingsDomainEXT value as a std::string
//! @relates PerfSettingsDomainEXT
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string
to_string(PerfSettingsDomainEXT value) {
  return {to_string_literal(value)};
}

//! @brief Enum class associated with XrPerfSettingsSubDomainEXT
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrPerfSettingsSubDomainEXT>
enum class PerfSettingsSubDomainEXT : uint32_t {

  Compositing = XR_PERF_SETTINGS_SUB_DOMAIN_COMPOSITING_EXT,

  Rendering = XR_PERF_SETTINGS_SUB_DOMAIN_RENDERING_EXT,

  Thermal = XR_PERF_SETTINGS_SUB_DOMAIN_THERMAL_EXT,

};

//! @brief Free function for retrieving the raw XrPerfSettingsSubDomainEXT value
//! from a PerfSettingsSubDomainEXT
//! @relates PerfSettingsSubDomainEXT
OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR XrPerfSettingsSubDomainEXT
get(PerfSettingsSubDomainEXT const &v) {
  return static_cast<XrPerfSettingsSubDomainEXT>(v);
}

//! @brief Free function for retrieving the string name of a
//! PerfSettingsSubDomainEXT value as a const char *
//! @relates PerfSettingsSubDomainEXT
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char *
to_string_literal(PerfSettingsSubDomainEXT value) {
  switch (value) {

  case PerfSettingsSubDomainEXT::Compositing:
    return "Compositing";

  case PerfSettingsSubDomainEXT::Rendering:
    return "Rendering";

  case PerfSettingsSubDomainEXT::Thermal:
    return "Thermal";

  default:
    return "invalid";
  }
}

//! @brief Free function for retrieving the string name of a
//! PerfSettingsSubDomainEXT value as a std::string
//! @relates PerfSettingsSubDomainEXT
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string
to_string(PerfSettingsSubDomainEXT value) {
  return {to_string_literal(value)};
}

//! @brief Enum class associated with XrPerfSettingsLevelEXT
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrPerfSettingsLevelEXT>
enum class PerfSettingsLevelEXT : uint32_t {

  PowerSavings = XR_PERF_SETTINGS_LEVEL_POWER_SAVINGS_EXT,

  SustainedLow = XR_PERF_SETTINGS_LEVEL_SUSTAINED_LOW_EXT,

  SustainedHigh = XR_PERF_SETTINGS_LEVEL_SUSTAINED_HIGH_EXT,

  Boost = XR_PERF_SETTINGS_LEVEL_BOOST_EXT,

};

//! @brief Free function for retrieving the raw XrPerfSettingsLevelEXT value
//! from a PerfSettingsLevelEXT
//! @relates PerfSettingsLevelEXT
OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR XrPerfSettingsLevelEXT
get(PerfSettingsLevelEXT const &v) {
  return static_cast<XrPerfSettingsLevelEXT>(v);
}

//! @brief Free function for retrieving the string name of a
//! PerfSettingsLevelEXT value as a const char *
//! @relates PerfSettingsLevelEXT
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char *
to_string_literal(PerfSettingsLevelEXT value) {
  switch (value) {

  case PerfSettingsLevelEXT::PowerSavings:
    return "PowerSavings";

  case PerfSettingsLevelEXT::SustainedLow:
    return "SustainedLow";

  case PerfSettingsLevelEXT::SustainedHigh:
    return "SustainedHigh";

  case PerfSettingsLevelEXT::Boost:
    return "Boost";

  default:
    return "invalid";
  }
}

//! @brief Free function for retrieving the string name of a
//! PerfSettingsLevelEXT value as a std::string
//! @relates PerfSettingsLevelEXT
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string
to_string(PerfSettingsLevelEXT value) {
  return {to_string_literal(value)};
}

//! @brief Enum class associated with XrPerfSettingsNotificationLevelEXT
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrPerfSettingsNotificationLevelEXT>
enum class PerfSettingsNotificationLevelEXT : uint32_t {

  XrPerfSettingsNotifLevelNormal = XR_PERF_SETTINGS_NOTIF_LEVEL_NORMAL_EXT,

  XrPerfSettingsNotifLevelWarning = XR_PERF_SETTINGS_NOTIF_LEVEL_WARNING_EXT,

  XrPerfSettingsNotifLevelImpaired = XR_PERF_SETTINGS_NOTIF_LEVEL_IMPAIRED_EXT,

};

//! @brief Free function for retrieving the raw
//! XrPerfSettingsNotificationLevelEXT value from a
//! PerfSettingsNotificationLevelEXT
//! @relates PerfSettingsNotificationLevelEXT
OPENXR_HPP_INLINE OPENXR_HPP_CONSTEXPR XrPerfSettingsNotificationLevelEXT
get(PerfSettingsNotificationLevelEXT const &v) {
  return static_cast<XrPerfSettingsNotificationLevelEXT>(v);
}

//! @brief Free function for retrieving the string name of a
//! PerfSettingsNotificationLevelEXT value as a const char *
//! @relates PerfSettingsNotificationLevelEXT
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR const char *
to_string_literal(PerfSettingsNotificationLevelEXT value) {
  switch (value) {

  case PerfSettingsNotificationLevelEXT::XrPerfSettingsNotifLevelNormal:
    return "XrPerfSettingsNotifLevelNormal";

  case PerfSettingsNotificationLevelEXT::XrPerfSettingsNotifLevelWarning:
    return "XrPerfSettingsNotifLevelWarning";

  case PerfSettingsNotificationLevelEXT::XrPerfSettingsNotifLevelImpaired:
    return "XrPerfSettingsNotifLevelImpaired";

  default:
    return "invalid";
  }
}

//! @brief Free function for retrieving the string name of a
//! PerfSettingsNotificationLevelEXT value as a std::string
//! @relates PerfSettingsNotificationLevelEXT
OPENXR_HPP_INLINE OPENXR_HPP_SWITCH_CONSTEXPR std::string
to_string(PerfSettingsNotificationLevelEXT value) {
  return {to_string_literal(value)};
}

//! @}

} // namespace OPENXR_HPP_NAMESPACE

namespace OPENXR_HPP_NAMESPACE {

/*!
 * @defgroup result_helpers Result helper free functions
 * @{
 */
//! @brief Return true if the Result is negative, indicating a failure.
//! Equivalent of XR_FAILED()
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool failed(Result v) {
  return static_cast<int>(v) < 0;
}

//! @brief Return true if the result is non-negative, indicating a success or
//! non-error result. Equivalent of XR_SUCCEEDED()
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool succeeded(Result v) {
  return static_cast<int>(v) >= 0;
}

//! @brief Return true if the result is exactly equal to Result::Success.
//! Equivalent of XR_UNQUALIFIED_SUCCESS()
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool unqualifiedSuccess(Result v) {
  return v == Result::Success;
}
//! @}

//! @brief `<` comparison between Result and integer, for compatibility with the
//! XR_ function-type macros and XrResult.
//! @relates Result
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(Result lhs, int rhs) {
  return get(lhs) < rhs;
}

//! @brief `<` comparison between integer and Result, for compatibility with the
//! XR_ function-type macros and XrResult.
//! @relates Result
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(int lhs, Result rhs) {
  return lhs < get(rhs);
}

//! @brief `>` comparison between Result and integer, for compatibility with the
//! XR_ function-type macros and XrResult.
//! @relates Result
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(Result lhs, int rhs) {
  return get(lhs) > rhs;
}

//! @brief `>` comparison between integer and Result, for compatibility with the
//! XR_ function-type macros and XrResult.
//! @relates Result
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(int lhs, Result rhs) {
  return lhs > get(rhs);
}

//! @brief `<=` comparison between Result and integer, for compatibility with
//! the XR_ function-type macros and XrResult.
//! @relates Result
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(Result lhs, int rhs) {
  return get(lhs) <= rhs;
}

//! @brief `<=` comparison between integer and Result, for compatibility with
//! the XR_ function-type macros and XrResult.
//! @relates Result
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(int lhs, Result rhs) {
  return lhs <= get(rhs);
}

//! @brief `>=` comparison between Result and integer, for compatibility with
//! the XR_ function-type macros and XrResult.
//! @relates Result
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(Result lhs, int rhs) {
  return get(lhs) >= rhs;
}

//! @brief `>=` comparison between integer and Result, for compatibility with
//! the XR_ function-type macros and XrResult.
//! @relates Result
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(int lhs, Result rhs) {
  return lhs >= get(rhs);
}

//! @brief `==` comparison between Result and integer, for compatibility with
//! the XR_ function-type macros and XrResult.
//! @relates Result
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(Result lhs, int rhs) {
  return get(lhs) == rhs;
}

//! @brief `==` comparison between integer and Result, for compatibility with
//! the XR_ function-type macros and XrResult.
//! @relates Result
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(int lhs, Result rhs) {
  return lhs == get(rhs);
}

//! @brief `!=` comparison between Result and integer, for compatibility with
//! the XR_ function-type macros and XrResult.
//! @relates Result
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(Result lhs, int rhs) {
  return get(lhs) != rhs;
}

//! @brief `!=` comparison between integer and Result, for compatibility with
//! the XR_ function-type macros and XrResult.
//! @relates Result
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(int lhs, Result rhs) {
  return lhs != get(rhs);
}

} // namespace OPENXR_HPP_NAMESPACE

#if !defined(OPENXR_HPP_NO_EXCEPTIONS)

namespace OPENXR_HPP_NAMESPACE {

//! Implementation details
namespace impl {
#if defined(_MSC_VER) && (_MSC_VER == 1800)
#define noexcept _NOEXCEPT
#endif

class ErrorCategoryImpl : public std::error_category {
public:
  virtual const char *name() const noexcept override {
    return OPENXR_HPP_NAMESPACE_STRING "::Result";
  }
  virtual std::string message(int ev) const override {
    return to_string(static_cast<Result>(ev));
  }
};

#if defined(_MSC_VER) && (_MSC_VER == 1800)
#undef noexcept
#endif

OPENXR_HPP_INLINE const std::error_category &errorCategory() {
  static impl::ErrorCategoryImpl instance;
  return instance;
}

OPENXR_HPP_INLINE std::error_code make_error_code(Result e) {
  return std::error_code(static_cast<int>(e), errorCategory());
}

OPENXR_HPP_INLINE std::error_condition make_error_condition(Result e) {
  return std::error_condition(static_cast<int>(e), errorCategory());
}

#if defined(_MSC_VER) && (_MSC_VER == 1800)
#define noexcept _NOEXCEPT
#endif
} // namespace impl

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

  virtual const char *what() const noexcept = 0;
};

//! @brief OpenXR logic error base exception class.
//!
//! Derives from both Error and std::logic_error for flexibility in catching.
class LogicError : public Error, public std::logic_error {
public:
  explicit LogicError(const std::string &what)
      : Error(), std::logic_error(what) {}
  explicit LogicError(char const *what) : Error(), std::logic_error(what) {}
  virtual ~LogicError() = default;

  virtual const char *what() const noexcept { return std::logic_error::what(); }
};

//! @brief OpenXR system error exception class - may be derived from or thrown
//! directly.
//!
//! Derives from both Error and std::system_error for flexibility in catching.
class SystemError : public Error, public std::system_error {
public:
  SystemError(std::error_code ec) : Error(), std::system_error(ec) {}
  SystemError(std::error_code ec, std::string const &what)
      : Error(), std::system_error(ec, what) {}
  SystemError(std::error_code ec, char const *what)
      : Error(), std::system_error(ec, what) {}
  SystemError(int ev, std::error_category const &ecat)
      : Error(), std::system_error(ev, ecat) {}
  SystemError(int ev, std::error_category const &ecat, std::string const &what)
      : Error(), std::system_error(ev, ecat, what) {}
  SystemError(int ev, std::error_category const &ecat, char const *what)
      : Error(), std::system_error(ev, ecat, what) {}
  virtual ~SystemError() = default;

  virtual const char *what() const noexcept {
    return std::system_error::what();
  }
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
//! @todo identify which errors would be considered LogicError and subclass that
//! instead. Add to XML?

//! @brief Exception class associated with the Result::ErrorValidationFailure
//! aka XR_ERROR_VALIDATION_FAILURE result code.
class ValidationFailureError : public SystemError {
public:
  ValidationFailureError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorValidationFailure),
                    message) {}

  ValidationFailureError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorValidationFailure),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorRuntimeFailure aka
//! XR_ERROR_RUNTIME_FAILURE result code.
class RuntimeFailureError : public SystemError {
public:
  RuntimeFailureError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorRuntimeFailure),
                    message) {}

  RuntimeFailureError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorRuntimeFailure),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorOutOfMemory aka
//! XR_ERROR_OUT_OF_MEMORY result code.
class OutOfMemoryError : public SystemError {
public:
  OutOfMemoryError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorOutOfMemory), message) {}

  OutOfMemoryError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorOutOfMemory), message) {}
};

//! @brief Exception class associated with the
//! Result::ErrorApiVersionUnsupported aka XR_ERROR_API_VERSION_UNSUPPORTED
//! result code.
class ApiVersionUnsupportedError : public SystemError {
public:
  ApiVersionUnsupportedError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorApiVersionUnsupported),
                    message) {}

  ApiVersionUnsupportedError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorApiVersionUnsupported),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorInitializationFailed
//! aka XR_ERROR_INITIALIZATION_FAILED result code.
class InitializationFailedError : public SystemError {
public:
  InitializationFailedError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorInitializationFailed),
                    message) {}

  InitializationFailedError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorInitializationFailed),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorFunctionUnsupported
//! aka XR_ERROR_FUNCTION_UNSUPPORTED result code.
class FunctionUnsupportedError : public SystemError {
public:
  FunctionUnsupportedError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorFunctionUnsupported),
                    message) {}

  FunctionUnsupportedError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorFunctionUnsupported),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorFeatureUnsupported
//! aka XR_ERROR_FEATURE_UNSUPPORTED result code.
class FeatureUnsupportedError : public SystemError {
public:
  FeatureUnsupportedError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorFeatureUnsupported),
                    message) {}

  FeatureUnsupportedError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorFeatureUnsupported),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorExtensionNotPresent
//! aka XR_ERROR_EXTENSION_NOT_PRESENT result code.
class ExtensionNotPresentError : public SystemError {
public:
  ExtensionNotPresentError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorExtensionNotPresent),
                    message) {}

  ExtensionNotPresentError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorExtensionNotPresent),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorLimitReached aka
//! XR_ERROR_LIMIT_REACHED result code.
class LimitReachedError : public SystemError {
public:
  LimitReachedError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorLimitReached), message) {
  }

  LimitReachedError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorLimitReached), message) {
  }
};

//! @brief Exception class associated with the Result::ErrorSizeInsufficient aka
//! XR_ERROR_SIZE_INSUFFICIENT result code.
class SizeInsufficientError : public SystemError {
public:
  SizeInsufficientError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorSizeInsufficient),
                    message) {}

  SizeInsufficientError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorSizeInsufficient),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorHandleInvalid aka
//! XR_ERROR_HANDLE_INVALID result code.
class HandleInvalidError : public SystemError {
public:
  HandleInvalidError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorHandleInvalid),
                    message) {}

  HandleInvalidError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorHandleInvalid),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorInstanceLost aka
//! XR_ERROR_INSTANCE_LOST result code.
class InstanceLostError : public SystemError {
public:
  InstanceLostError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorInstanceLost), message) {
  }

  InstanceLostError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorInstanceLost), message) {
  }
};

//! @brief Exception class associated with the Result::ErrorSessionRunning aka
//! XR_ERROR_SESSION_RUNNING result code.
class SessionRunningError : public SystemError {
public:
  SessionRunningError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorSessionRunning),
                    message) {}

  SessionRunningError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorSessionRunning),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorSessionNotRunning
//! aka XR_ERROR_SESSION_NOT_RUNNING result code.
class SessionNotRunningError : public SystemError {
public:
  SessionNotRunningError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorSessionNotRunning),
                    message) {}

  SessionNotRunningError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorSessionNotRunning),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorSessionLost aka
//! XR_ERROR_SESSION_LOST result code.
class SessionLostError : public SystemError {
public:
  SessionLostError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorSessionLost), message) {}

  SessionLostError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorSessionLost), message) {}
};

//! @brief Exception class associated with the Result::ErrorSystemInvalid aka
//! XR_ERROR_SYSTEM_INVALID result code.
class SystemInvalidError : public SystemError {
public:
  SystemInvalidError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorSystemInvalid),
                    message) {}

  SystemInvalidError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorSystemInvalid),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorPathInvalid aka
//! XR_ERROR_PATH_INVALID result code.
class PathInvalidError : public SystemError {
public:
  PathInvalidError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorPathInvalid), message) {}

  PathInvalidError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorPathInvalid), message) {}
};

//! @brief Exception class associated with the Result::ErrorPathCountExceeded
//! aka XR_ERROR_PATH_COUNT_EXCEEDED result code.
class PathCountExceededError : public SystemError {
public:
  PathCountExceededError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorPathCountExceeded),
                    message) {}

  PathCountExceededError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorPathCountExceeded),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorPathFormatInvalid
//! aka XR_ERROR_PATH_FORMAT_INVALID result code.
class PathFormatInvalidError : public SystemError {
public:
  PathFormatInvalidError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorPathFormatInvalid),
                    message) {}

  PathFormatInvalidError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorPathFormatInvalid),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorPathUnsupported aka
//! XR_ERROR_PATH_UNSUPPORTED result code.
class PathUnsupportedError : public SystemError {
public:
  PathUnsupportedError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorPathUnsupported),
                    message) {}

  PathUnsupportedError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorPathUnsupported),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorLayerInvalid aka
//! XR_ERROR_LAYER_INVALID result code.
class LayerInvalidError : public SystemError {
public:
  LayerInvalidError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorLayerInvalid), message) {
  }

  LayerInvalidError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorLayerInvalid), message) {
  }
};

//! @brief Exception class associated with the Result::ErrorLayerLimitExceeded
//! aka XR_ERROR_LAYER_LIMIT_EXCEEDED result code.
class LayerLimitExceededError : public SystemError {
public:
  LayerLimitExceededError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorLayerLimitExceeded),
                    message) {}

  LayerLimitExceededError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorLayerLimitExceeded),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorSwapchainRectInvalid
//! aka XR_ERROR_SWAPCHAIN_RECT_INVALID result code.
class SwapchainRectInvalidError : public SystemError {
public:
  SwapchainRectInvalidError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorSwapchainRectInvalid),
                    message) {}

  SwapchainRectInvalidError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorSwapchainRectInvalid),
                    message) {}
};

//! @brief Exception class associated with the
//! Result::ErrorSwapchainFormatUnsupported aka
//! XR_ERROR_SWAPCHAIN_FORMAT_UNSUPPORTED result code.
class SwapchainFormatUnsupportedError : public SystemError {
public:
  SwapchainFormatUnsupportedError(std::string const &message)
      : SystemError(
            impl::make_error_code(Result::ErrorSwapchainFormatUnsupported),
            message) {}

  SwapchainFormatUnsupportedError(char const *message)
      : SystemError(
            impl::make_error_code(Result::ErrorSwapchainFormatUnsupported),
            message) {}
};

//! @brief Exception class associated with the Result::ErrorActionTypeMismatch
//! aka XR_ERROR_ACTION_TYPE_MISMATCH result code.
class ActionTypeMismatchError : public SystemError {
public:
  ActionTypeMismatchError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorActionTypeMismatch),
                    message) {}

  ActionTypeMismatchError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorActionTypeMismatch),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorSessionNotReady aka
//! XR_ERROR_SESSION_NOT_READY result code.
class SessionNotReadyError : public SystemError {
public:
  SessionNotReadyError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorSessionNotReady),
                    message) {}

  SessionNotReadyError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorSessionNotReady),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorSessionNotStopping
//! aka XR_ERROR_SESSION_NOT_STOPPING result code.
class SessionNotStoppingError : public SystemError {
public:
  SessionNotStoppingError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorSessionNotStopping),
                    message) {}

  SessionNotStoppingError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorSessionNotStopping),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorTimeInvalid aka
//! XR_ERROR_TIME_INVALID result code.
class TimeInvalidError : public SystemError {
public:
  TimeInvalidError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorTimeInvalid), message) {}

  TimeInvalidError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorTimeInvalid), message) {}
};

//! @brief Exception class associated with the
//! Result::ErrorReferenceSpaceUnsupported aka
//! XR_ERROR_REFERENCE_SPACE_UNSUPPORTED result code.
class ReferenceSpaceUnsupportedError : public SystemError {
public:
  ReferenceSpaceUnsupportedError(std::string const &message)
      : SystemError(
            impl::make_error_code(Result::ErrorReferenceSpaceUnsupported),
            message) {}

  ReferenceSpaceUnsupportedError(char const *message)
      : SystemError(
            impl::make_error_code(Result::ErrorReferenceSpaceUnsupported),
            message) {}
};

//! @brief Exception class associated with the Result::ErrorFileAccessError aka
//! XR_ERROR_FILE_ACCESS_ERROR result code.
class FileAccessError : public SystemError {
public:
  FileAccessError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorFileAccessError),
                    message) {}

  FileAccessError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorFileAccessError),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorFileContentsInvalid
//! aka XR_ERROR_FILE_CONTENTS_INVALID result code.
class FileContentsInvalidError : public SystemError {
public:
  FileContentsInvalidError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorFileContentsInvalid),
                    message) {}

  FileContentsInvalidError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorFileContentsInvalid),
                    message) {}
};

//! @brief Exception class associated with the
//! Result::ErrorFormFactorUnsupported aka XR_ERROR_FORM_FACTOR_UNSUPPORTED
//! result code.
class FormFactorUnsupportedError : public SystemError {
public:
  FormFactorUnsupportedError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorFormFactorUnsupported),
                    message) {}

  FormFactorUnsupportedError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorFormFactorUnsupported),
                    message) {}
};

//! @brief Exception class associated with the
//! Result::ErrorFormFactorUnavailable aka XR_ERROR_FORM_FACTOR_UNAVAILABLE
//! result code.
class FormFactorUnavailableError : public SystemError {
public:
  FormFactorUnavailableError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorFormFactorUnavailable),
                    message) {}

  FormFactorUnavailableError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorFormFactorUnavailable),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorApiLayerNotPresent
//! aka XR_ERROR_API_LAYER_NOT_PRESENT result code.
class ApiLayerNotPresentError : public SystemError {
public:
  ApiLayerNotPresentError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorApiLayerNotPresent),
                    message) {}

  ApiLayerNotPresentError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorApiLayerNotPresent),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorCallOrderInvalid aka
//! XR_ERROR_CALL_ORDER_INVALID result code.
class CallOrderInvalidError : public SystemError {
public:
  CallOrderInvalidError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorCallOrderInvalid),
                    message) {}

  CallOrderInvalidError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorCallOrderInvalid),
                    message) {}
};

//! @brief Exception class associated with the
//! Result::ErrorGraphicsDeviceInvalid aka XR_ERROR_GRAPHICS_DEVICE_INVALID
//! result code.
class GraphicsDeviceInvalidError : public SystemError {
public:
  GraphicsDeviceInvalidError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorGraphicsDeviceInvalid),
                    message) {}

  GraphicsDeviceInvalidError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorGraphicsDeviceInvalid),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorPoseInvalid aka
//! XR_ERROR_POSE_INVALID result code.
class PoseInvalidError : public SystemError {
public:
  PoseInvalidError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorPoseInvalid), message) {}

  PoseInvalidError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorPoseInvalid), message) {}
};

//! @brief Exception class associated with the Result::ErrorIndexOutOfRange aka
//! XR_ERROR_INDEX_OUT_OF_RANGE result code.
class IndexOutOfRangeError : public SystemError {
public:
  IndexOutOfRangeError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorIndexOutOfRange),
                    message) {}

  IndexOutOfRangeError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorIndexOutOfRange),
                    message) {}
};

//! @brief Exception class associated with the
//! Result::ErrorViewConfigurationTypeUnsupported aka
//! XR_ERROR_VIEW_CONFIGURATION_TYPE_UNSUPPORTED result code.
class ViewConfigurationTypeUnsupportedError : public SystemError {
public:
  ViewConfigurationTypeUnsupportedError(std::string const &message)
      : SystemError(impl::make_error_code(
                        Result::ErrorViewConfigurationTypeUnsupported),
                    message) {}

  ViewConfigurationTypeUnsupportedError(char const *message)
      : SystemError(impl::make_error_code(
                        Result::ErrorViewConfigurationTypeUnsupported),
                    message) {}
};

//! @brief Exception class associated with the
//! Result::ErrorEnvironmentBlendModeUnsupported aka
//! XR_ERROR_ENVIRONMENT_BLEND_MODE_UNSUPPORTED result code.
class EnvironmentBlendModeUnsupportedError : public SystemError {
public:
  EnvironmentBlendModeUnsupportedError(std::string const &message)
      : SystemError(
            impl::make_error_code(Result::ErrorEnvironmentBlendModeUnsupported),
            message) {}

  EnvironmentBlendModeUnsupportedError(char const *message)
      : SystemError(
            impl::make_error_code(Result::ErrorEnvironmentBlendModeUnsupported),
            message) {}
};

//! @brief Exception class associated with the Result::ErrorNameDuplicated aka
//! XR_ERROR_NAME_DUPLICATED result code.
class NameDuplicatedError : public SystemError {
public:
  NameDuplicatedError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorNameDuplicated),
                    message) {}

  NameDuplicatedError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorNameDuplicated),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorNameInvalid aka
//! XR_ERROR_NAME_INVALID result code.
class NameInvalidError : public SystemError {
public:
  NameInvalidError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorNameInvalid), message) {}

  NameInvalidError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorNameInvalid), message) {}
};

//! @brief Exception class associated with the Result::ErrorActionsetNotAttached
//! aka XR_ERROR_ACTIONSET_NOT_ATTACHED result code.
class ActionsetNotAttachedError : public SystemError {
public:
  ActionsetNotAttachedError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorActionsetNotAttached),
                    message) {}

  ActionsetNotAttachedError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorActionsetNotAttached),
                    message) {}
};

//! @brief Exception class associated with the
//! Result::ErrorActionsetsAlreadyAttached aka
//! XR_ERROR_ACTIONSETS_ALREADY_ATTACHED result code.
class ActionsetsAlreadyAttachedError : public SystemError {
public:
  ActionsetsAlreadyAttachedError(std::string const &message)
      : SystemError(
            impl::make_error_code(Result::ErrorActionsetsAlreadyAttached),
            message) {}

  ActionsetsAlreadyAttachedError(char const *message)
      : SystemError(
            impl::make_error_code(Result::ErrorActionsetsAlreadyAttached),
            message) {}
};

//! @brief Exception class associated with the
//! Result::ErrorLocalizedNameDuplicated aka XR_ERROR_LOCALIZED_NAME_DUPLICATED
//! result code.
class LocalizedNameDuplicatedError : public SystemError {
public:
  LocalizedNameDuplicatedError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorLocalizedNameDuplicated),
                    message) {}

  LocalizedNameDuplicatedError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorLocalizedNameDuplicated),
                    message) {}
};

//! @brief Exception class associated with the Result::ErrorLocalizedNameInvalid
//! aka XR_ERROR_LOCALIZED_NAME_INVALID result code.
class LocalizedNameInvalidError : public SystemError {
public:
  LocalizedNameInvalidError(std::string const &message)
      : SystemError(impl::make_error_code(Result::ErrorLocalizedNameInvalid),
                    message) {}

  LocalizedNameInvalidError(char const *message)
      : SystemError(impl::make_error_code(Result::ErrorLocalizedNameInvalid),
                    message) {}
};

//! @brief Exception class associated with the
//! Result::ErrorAndroidThreadSettingsIdInvalidKHR aka
//! XR_ERROR_ANDROID_THREAD_SETTINGS_ID_INVALID_KHR result code.
class AndroidThreadSettingsIdInvalidKHRError : public SystemError {
public:
  AndroidThreadSettingsIdInvalidKHRError(std::string const &message)
      : SystemError(impl::make_error_code(
                        Result::ErrorAndroidThreadSettingsIdInvalidKHR),
                    message) {}

  AndroidThreadSettingsIdInvalidKHRError(char const *message)
      : SystemError(impl::make_error_code(
                        Result::ErrorAndroidThreadSettingsIdInvalidKHR),
                    message) {}
};

//! @brief Exception class associated with the
//! Result::ErrorAndroidThreadSettingsFailureKHR aka
//! XR_ERROR_ANDROID_THREAD_SETTINGS_FAILURE_KHR result code.
class AndroidThreadSettingsFailureKHRError : public SystemError {
public:
  AndroidThreadSettingsFailureKHRError(std::string const &message)
      : SystemError(
            impl::make_error_code(Result::ErrorAndroidThreadSettingsFailureKHR),
            message) {}

  AndroidThreadSettingsFailureKHRError(char const *message)
      : SystemError(
            impl::make_error_code(Result::ErrorAndroidThreadSettingsFailureKHR),
            message) {}
};

//! @brief Exception class associated with the
//! Result::ErrorCreateSpatialAnchorFailedMSFT aka
//! XR_ERROR_CREATE_SPATIAL_ANCHOR_FAILED_MSFT result code.
class CreateSpatialAnchorFailedMSFTError : public SystemError {
public:
  CreateSpatialAnchorFailedMSFTError(std::string const &message)
      : SystemError(
            impl::make_error_code(Result::ErrorCreateSpatialAnchorFailedMSFT),
            message) {}

  CreateSpatialAnchorFailedMSFTError(char const *message)
      : SystemError(
            impl::make_error_code(Result::ErrorCreateSpatialAnchorFailedMSFT),
            message) {}
};

// end of result_exceptions
//! @}

/*!
 * @brief Throws the best exception for a result code.
 *
 * Takes a result code and a message (usually the method triggering the
 * exception) and throws the most-specific exception available for that result
 * code. As a fallback, it will throw a SystemError directly.
 */
OPENXR_HPP_INLINE void throwResultException(Result result,
                                            char const *message) {
  switch (result) {

  case Result::Success:
    // Not actually an error!
    throw SystemError(impl::make_error_code(result));

  case Result::TimeoutExpired:
    // Not actually an error!
    throw SystemError(impl::make_error_code(result));

  case Result::SessionLossPending:
    // Not actually an error!
    throw SystemError(impl::make_error_code(result));

  case Result::EventUnavailable:
    // Not actually an error!
    throw SystemError(impl::make_error_code(result));

  case Result::SpaceBoundsUnavailable:
    // Not actually an error!
    throw SystemError(impl::make_error_code(result));

  case Result::SessionNotFocused:
    // Not actually an error!
    throw SystemError(impl::make_error_code(result));

  case Result::FrameDiscarded:
    // Not actually an error!
    throw SystemError(impl::make_error_code(result));

  case Result::ErrorValidationFailure:
    throw ValidationFailureError(message);

  case Result::ErrorRuntimeFailure:
    throw RuntimeFailureError(message);

  case Result::ErrorOutOfMemory:
    throw OutOfMemoryError(message);

  case Result::ErrorApiVersionUnsupported:
    throw ApiVersionUnsupportedError(message);

  case Result::ErrorInitializationFailed:
    throw InitializationFailedError(message);

  case Result::ErrorFunctionUnsupported:
    throw FunctionUnsupportedError(message);

  case Result::ErrorFeatureUnsupported:
    throw FeatureUnsupportedError(message);

  case Result::ErrorExtensionNotPresent:
    throw ExtensionNotPresentError(message);

  case Result::ErrorLimitReached:
    throw LimitReachedError(message);

  case Result::ErrorSizeInsufficient:
    throw SizeInsufficientError(message);

  case Result::ErrorHandleInvalid:
    throw HandleInvalidError(message);

  case Result::ErrorInstanceLost:
    throw InstanceLostError(message);

  case Result::ErrorSessionRunning:
    throw SessionRunningError(message);

  case Result::ErrorSessionNotRunning:
    throw SessionNotRunningError(message);

  case Result::ErrorSessionLost:
    throw SessionLostError(message);

  case Result::ErrorSystemInvalid:
    throw SystemInvalidError(message);

  case Result::ErrorPathInvalid:
    throw PathInvalidError(message);

  case Result::ErrorPathCountExceeded:
    throw PathCountExceededError(message);

  case Result::ErrorPathFormatInvalid:
    throw PathFormatInvalidError(message);

  case Result::ErrorPathUnsupported:
    throw PathUnsupportedError(message);

  case Result::ErrorLayerInvalid:
    throw LayerInvalidError(message);

  case Result::ErrorLayerLimitExceeded:
    throw LayerLimitExceededError(message);

  case Result::ErrorSwapchainRectInvalid:
    throw SwapchainRectInvalidError(message);

  case Result::ErrorSwapchainFormatUnsupported:
    throw SwapchainFormatUnsupportedError(message);

  case Result::ErrorActionTypeMismatch:
    throw ActionTypeMismatchError(message);

  case Result::ErrorSessionNotReady:
    throw SessionNotReadyError(message);

  case Result::ErrorSessionNotStopping:
    throw SessionNotStoppingError(message);

  case Result::ErrorTimeInvalid:
    throw TimeInvalidError(message);

  case Result::ErrorReferenceSpaceUnsupported:
    throw ReferenceSpaceUnsupportedError(message);

  case Result::ErrorFileAccessError:
    throw FileAccessError(message);

  case Result::ErrorFileContentsInvalid:
    throw FileContentsInvalidError(message);

  case Result::ErrorFormFactorUnsupported:
    throw FormFactorUnsupportedError(message);

  case Result::ErrorFormFactorUnavailable:
    throw FormFactorUnavailableError(message);

  case Result::ErrorApiLayerNotPresent:
    throw ApiLayerNotPresentError(message);

  case Result::ErrorCallOrderInvalid:
    throw CallOrderInvalidError(message);

  case Result::ErrorGraphicsDeviceInvalid:
    throw GraphicsDeviceInvalidError(message);

  case Result::ErrorPoseInvalid:
    throw PoseInvalidError(message);

  case Result::ErrorIndexOutOfRange:
    throw IndexOutOfRangeError(message);

  case Result::ErrorViewConfigurationTypeUnsupported:
    throw ViewConfigurationTypeUnsupportedError(message);

  case Result::ErrorEnvironmentBlendModeUnsupported:
    throw EnvironmentBlendModeUnsupportedError(message);

  case Result::ErrorNameDuplicated:
    throw NameDuplicatedError(message);

  case Result::ErrorNameInvalid:
    throw NameInvalidError(message);

  case Result::ErrorActionsetNotAttached:
    throw ActionsetNotAttachedError(message);

  case Result::ErrorActionsetsAlreadyAttached:
    throw ActionsetsAlreadyAttachedError(message);

  case Result::ErrorLocalizedNameDuplicated:
    throw LocalizedNameDuplicatedError(message);

  case Result::ErrorLocalizedNameInvalid:
    throw LocalizedNameInvalidError(message);

  case Result::ErrorAndroidThreadSettingsIdInvalidKHR:
    throw AndroidThreadSettingsIdInvalidKHRError(message);

  case Result::ErrorAndroidThreadSettingsFailureKHR:
    throw AndroidThreadSettingsFailureKHRError(message);

  case Result::ErrorCreateSpatialAnchorFailedMSFT:
    throw CreateSpatialAnchorFailedMSFTError(message);

  default:
    throw SystemError(impl::make_error_code(result));
  }
}
//! @}
} // namespace exceptions
} // namespace OPENXR_HPP_NAMESPACE

#if !defined(OPENXR_HPP_DOXYGEN)
namespace std {
template <>
struct is_error_code_enum<OPENXR_HPP_NAMESPACE::Result> : public true_type {};
} // namespace std
#endif // !defined(OPENXR_HPP_DOXYGEN)
#endif // !defined(OPENXR_HPP_NO_EXCEPTIONS)

namespace OPENXR_HPP_NAMESPACE {

/*!
 * @defgroup return_results Returning results
 * @brief Types and functions used by API call wrappers to return output in a
 * friendly, C++ manner.
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
template <typename T> struct ResultValue {
  ResultValue(Result r, T const &v) : result(r), value(v) {}

  ResultValue(Result r, T &&v) : result(r), value(std::move(v)) {}

  Result result;
  T value;

  operator std::tuple<Result &, T &>() {
    return std::tuple<Result &, T &>(result, value);
  }
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
template <typename T> struct ResultValueType;

#ifdef OPENXR_HPP_NO_EXCEPTIONS
template <typename T> struct ResultValueType { typedef ResultValue<T> type; };
template <> struct ResultValueType<void> { typedef Result type; };
#else
template <typename T> struct ResultValueType { typedef T type; };
template <> struct ResultValueType<void> { typedef void type; };
#endif

namespace impl {
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
OPENXR_HPP_INLINE ResultValueType<void>::type
createResultValue(Result result, char const *message) {
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
OPENXR_HPP_INLINE typename ResultValueType<T>::type
createResultValue(Result result, T &data, char const *message) {
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
 * @brief Returned by enhanced-mode functions with no output value and at least
 * one success code specified that is not Result::Success.
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
 * - Asserts that result is one of the expected success codes.
 * - Returns Result (which may be an error, Result::Success, or a
 * non-Result::Success success code).
 */
OPENXR_HPP_INLINE Result
createResultValue(Result result, char const *message,
                  std::initializer_list<Result> successCodes) {
#ifdef OPENXR_HPP_NO_EXCEPTIONS
  (void)message;
  OPENXR_HPP_ASSERT(std::find(successCodes.begin(), successCodes.end(),
                              result) != successCodes.end());
#else
  if (std::find(successCodes.begin(), successCodes.end(), result) ==
      successCodes.end()) {
    exceptions::throwResultException(result, message);
  }
#endif
  return result;
}

/*!
 * @brief Returned by enhanced-mode functions with an output value of type T and
 * at least one success code specified that is not Result::Success.
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
OPENXR_HPP_INLINE ResultValue<typename std::remove_reference<T>::type>
createResultValue(Result result, T &&data, char const *message,
                  std::initializer_list<Result> successCodes) {
#ifdef OPENXR_HPP_NO_EXCEPTIONS
  (void)message;
  OPENXR_HPP_ASSERT(std::find(successCodes.begin(), successCodes.end(),
                              result) != successCodes.end());
#else
  if (std::find(successCodes.begin(), successCodes.end(), result) ==
      successCodes.end()) {
    exceptions::throwResultException(result, message);
  }
#endif
  return {result, std::move(data)};
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
 * - Returns ResultValue<UniqueHandle<T, D>>, containing both a Result (which
 * may be an error, or Result::Success) and the UniqueHandle<T, D>.
 */
template <typename T, typename D>
OPENXR_HPP_INLINE typename ResultValueType<UniqueHandle<T, D>>::type
createResultValue(
    Result result, T &data,
    typename traits::UniqueHandleTraits<T, D>::deleter const &deleter,
    char const *message) {
#ifdef OPENXR_HPP_NO_EXCEPTIONS
  (void)message;
  OPENXR_HPP_ASSERT(result == Result::Success);
  return ResultValue<UniqueHandle<T, D>>(
      result, UniqueHandle<T, D>(std::move(data), deleter));
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
 * Return type is always ResultValue<UniqueHandle<T, D>>, containing both a
 * Result and the UniqueHandle<T, D> (which may be null).
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
 *
 * - Throws an appropriate exception on failure.
 * - Returns ResultValue<UniqueHandle<T, D>>, containing both a Result (which
 * may be Result::Success, or a non-Result::Success success code) and the
 * UniqueHandle<T, D>.
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is defined:
 *
 * - Asserts that result == Result::Success.
 * - Returns ResultValue<T>, containing both a Result (which may be an error,
 * Result::Success, or a non-Result::Success success code) and the
 * UniqueHandle<T, D>.
 */
template <typename T, typename D>
OPENXR_HPP_INLINE ResultValue<UniqueHandle<T, D>> createResultValue(
    Result result, T &data,
    typename traits::UniqueHandleTraits<T, D>::deleter const &deleter,
    char const *message, std::initializer_list<Result> successCodes) {
#ifdef OPENXR_HPP_NO_EXCEPTIONS
  (void)message;
  OPENXR_HPP_ASSERT(std::find(successCodes.begin(), successCodes.end(),
                              result) != successCodes.end());
  return ResultValue<UniqueHandle<T, D>>(
      result, UniqueHandle<T, D>(std::move(data), deleter));
#else
  if (std::find(successCodes.begin(), successCodes.end(), result) ==
      successCodes.end()) {
    exceptions::throwResultException(result, message);
  }
  return ResultValue<UniqueHandle<T, D>>(result,
                                         UniqueHandle<T, D>{data, deleter});
#endif
}
#endif

} // namespace impl

//! @}

} // namespace OPENXR_HPP_NAMESPACE
namespace OPENXR_HPP_NAMESPACE {

//! Type traits
namespace traits {
//! Type trait associating an ObjectType enum value with its C++ type.
template <ObjectType o> struct cpp_type;
} // namespace traits

// forward declarations

class Instance;
class Session;
class Space;
class Action;
class Swapchain;
class ActionSet;
class DebugUtilsMessengerEXT;
class SpatialAnchorMSFT;
/*!
 * @defgroup handles Handle types
 * @brief Wrappers for OpenXR handle types, with associated functions mapped as
 * methods.
 * @{
 */
/*!
 * @defgroup unique_handle_aliases Aliases for UniqueHandle types
 * @brief Convenience names for specializations of UniqueHandle<>
 */
//! @}

#ifndef OPENXR_HPP_NO_SMART_HANDLE

namespace traits {
//! Traits associating a deleter type with handles of type Instance
template <typename Dispatch> class UniqueHandleTraits<Instance, Dispatch> {
public:
  using deleter = ObjectDestroy<Dispatch>;
};
} // namespace traits

//! @addtogroup unique_handle_aliases
//! @{

//! Shorthand name for unique handles of type Instance, using a static dispatch.
using UniqueInstance = UniqueHandle<Instance, DispatchLoaderStatic>;
//! Shorthand name for unique handles of type Instance, using a dynamic
//! dispatch.
using UniqueDynamicInstance = UniqueHandle<Instance, DispatchLoaderDynamic>;
//! @}
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/

//! @brief Handle class - wrapping XrInstance
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrInstance>
//! @ingroup handles
class Instance {
public:
  using Type = Instance;
  using RawHandleType = XrInstance;

  /*!
   * @name Constructors, assignment, and conversions
   * @{
   */
  //! Default (empty/null) constructor
  OPENXR_HPP_CONSTEXPR Instance() : m_raw(XR_NULL_HANDLE) {}

  //! Constructor from nullptr - creates empty/null handle.
  OPENXR_HPP_CONSTEXPR Instance(std::nullptr_t /* unused */)
      : m_raw(XR_NULL_HANDLE) {}

  //! @brief Conversion constructor from the raw XrInstance type
  //!
  //! Explicit on 32-bit platforms by default unless
  //! OPENXR_HPP_TYPESAFE_CONVERSION is defined.
  OPENXR_HPP_TYPESAFE_EXPLICIT Instance(RawHandleType handle) : m_raw(handle) {}

#if defined(OPENXR_HPP_TYPESAFE_CONVERSION)
  //! @brief Assignment operator from the raw XrInstance
  //!
  //! Does *not* destroy any contained non-null handle first! For that, see
  //! UniqueHandle<>.
  //!
  //! Only provided if OPENXR_HPP_TYPESAFE_CONVERSION is defined (defaults to
  //! only on 64-bit).
  Type &operator=(RawHandleType handle) {
    m_raw = handle;
    return *this;
  }
#endif

  //! @brief Assignment operator from nullptr - assigns to empty/null handle.
  //!
  //! Does *not* destroy any contained non-null handle first! For that, see
  //! UniqueHandle<>.
  Type &operator=(std::nullptr_t /* unused */) {
    m_raw = XR_NULL_HANDLE;
    return *this;
  }

  //! @brief Conversion operator to the raw XrInstance type
  //!
  //! Explicit on 32-bit platforms by default unless
  //! OPENXR_HPP_TYPESAFE_CONVERSION is defined.
  OPENXR_HPP_CONSTEXPR OPENXR_HPP_TYPESAFE_EXPLICIT
  operator RawHandleType() const {
    return m_raw;
  }

  //! @}

  /*!
   * @name Validity checking
   * @{
   */
  //! Returns true in conditionals if this handle is non-null
  OPENXR_HPP_CONSTEXPR explicit operator bool() const {
    return m_raw != XR_NULL_HANDLE;
  }

  //! Negation operator: true if this handle is null
  OPENXR_HPP_CONSTEXPR bool operator!() const {
    return m_raw == XR_NULL_HANDLE;
  }
  //! @}

  /*!
   * @name Raw handle manipulation
   * @{
   */
  //! @brief "Put" function for assigning as null then getting the address of
  //! the raw pointer to pass to creation functions.
  //!
  //! e.g.
  //! ```
  //! Instance yourHandle;
  //! auto result = d.xrCreateInstance(..., yourHandle.put()));
  //! ```
  //!
  //! See also OPENXR_HPP_NAMESPACE::put()
  RawHandleType *put() {
    m_raw = XR_NULL_HANDLE;
    return &m_raw;
  }

  //! @brief Gets the raw handle type.
  //!
  //! See also OPENXR_HPP_NAMESPACE::get()
  OPENXR_HPP_CONSTEXPR RawHandleType get() const { return m_raw; }

  //! @}

  /*!
   * @name OpenXR API calls as member functions
   * @{
   */

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrGetInstanceProcAddr wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetInstanceProcAddr>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result getInstanceProcAddr(const char *name, PFN_xrVoidFunction *function,
                             Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrGetInstanceProcAddr wrapper - enhanced mode (hides basic wrapper
   * unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns nothing (void)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns Result.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetInstanceProcAddr>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type
  getInstanceProcAddr(const char *name, PFN_xrVoidFunction *function,
                      Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrDestroyInstance wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrDestroyInstance>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result destroy(Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrDestroyInstance wrapper - enhanced mode (hides basic wrapper
   * unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns nothing (void)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns Result.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrDestroyInstance>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type destroy(Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrGetInstanceProperties wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetInstanceProperties>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result getInstanceProperties(XrInstanceProperties *instanceProperties,
                               Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrGetInstanceProperties wrapper - enhanced mode (hides basic wrapper
   * unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns nothing (void)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns Result.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetInstanceProperties>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type
  getInstanceProperties(XrInstanceProperties *instanceProperties,
                        Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrPollEvent wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrPollEvent>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result pollEvent(XrEventDataBuffer *eventData,
                   Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrPollEvent wrapper - enhanced mode (hides basic wrapper unless
   * OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns Result (which may be Result::Success, or a non-Result::Success
   * success code)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns Result (which may be an error, Result::Success, or a
   * non-Result::Success success code).
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrPollEvent>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result pollEvent(XrEventDataBuffer *eventData,
                   Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_PROVIDE_DISCOURAGED_FUNCTIONS

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrResultToString wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrResultToString>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result resultToString(Result value, char buffer[XR_MAX_RESULT_STRING_SIZE],
                        Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrResultToString wrapper - enhanced mode (hides basic wrapper unless
   * OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns nothing (void)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns Result.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrResultToString>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type
  resultToString(Result value, char buffer[XR_MAX_RESULT_STRING_SIZE],
                 Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif //  OPENXR_HPP_PROVIDE_DISCOURAGED_FUNCTIONS

#ifdef OPENXR_HPP_PROVIDE_DISCOURAGED_FUNCTIONS

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrStructureTypeToString wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrStructureTypeToString>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result structureTypeToString(StructureType value,
                               char buffer[XR_MAX_STRUCTURE_NAME_SIZE],
                               Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrStructureTypeToString wrapper - enhanced mode (hides basic wrapper
   * unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns nothing (void)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns Result.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrStructureTypeToString>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type
  structureTypeToString(StructureType value,
                        char buffer[XR_MAX_STRUCTURE_NAME_SIZE],
                        Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif //  OPENXR_HPP_PROVIDE_DISCOURAGED_FUNCTIONS

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrGetSystem wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetSystem>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result getSystem(const XrSystemGetInfo *getInfo, XrSystemId *systemId,
                   Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrGetSystem wrapper - enhanced mode (hides basic wrapper unless
   * OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns nothing (void)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns Result.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetSystem>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type getSystem(const XrSystemGetInfo *getInfo,
                                        XrSystemId *systemId,
                                        Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrGetSystemProperties wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetSystemProperties>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result getSystemProperties(XrSystemId systemId,
                             XrSystemProperties *properties,
                             Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrGetSystemProperties wrapper - enhanced mode (hides basic wrapper
   * unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns nothing (void)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns Result.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetSystemProperties>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type
  getSystemProperties(XrSystemId systemId, XrSystemProperties *properties,
                      Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrEnumerateEnvironmentBlendModes wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateEnvironmentBlendModes>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result
  enumerateEnvironmentBlendModes(XrSystemId systemId,
                                 ViewConfigurationType viewConfigurationType,
                                 uint32_t environmentBlendModeCapacityInput,
                                 uint32_t *environmentBlendModeCountOutput,
                                 EnvironmentBlendMode &environmentBlendModes,
                                 Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrEnumerateEnvironmentBlendModes wrapper - enhanced mode (hides
   * basic wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns nothing (void)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns Result.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateEnvironmentBlendModes>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type
  enumerateEnvironmentBlendModes(XrSystemId systemId,
                                 ViewConfigurationType viewConfigurationType,
                                 uint32_t environmentBlendModeCapacityInput,
                                 uint32_t *environmentBlendModeCountOutput,
                                 EnvironmentBlendMode &environmentBlendModes,
                                 Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  /*!
   * @brief xrCreateSession wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateSession>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result createSession(const XrSessionCreateInfo *createInfo, Session &session,
                       Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrCreateSession wrapper - enhanced mode.    //!
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns the value of type Session
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns the output of type Session.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateSession>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<Session>::type
  createSession(const XrSessionCreateInfo *createInfo,
                Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_NO_SMART_HANDLE

  /*!
   * @brief xrCreateSession wrapper returning a smart handle.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns the value of type UniqueHandle<Session,
   * impl::RemoveRefConst<Dispatch>>
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns the output of type UniqueHandle<Session,
   * impl::RemoveRefConst<Dispatch>>.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateSession>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<
      UniqueHandle<Session, impl::RemoveRefConst<Dispatch>>>::type
  createSessionUnique(const XrSessionCreateInfo *createInfo,
                      Dispatch &&d = Dispatch{}) const;
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrEnumerateViewConfigurations wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateViewConfigurations>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result
  enumerateViewConfigurations(XrSystemId systemId,
                              uint32_t viewConfigurationTypeCapacityInput,
                              uint32_t *viewConfigurationTypeCountOutput,
                              ViewConfigurationType &viewConfigurationTypes,
                              Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrEnumerateViewConfigurations wrapper - enhanced mode (hides basic
   * wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns nothing (void)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns Result.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateViewConfigurations>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type
  enumerateViewConfigurations(XrSystemId systemId,
                              uint32_t viewConfigurationTypeCapacityInput,
                              uint32_t *viewConfigurationTypeCountOutput,
                              ViewConfigurationType &viewConfigurationTypes,
                              Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrGetViewConfigurationProperties wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetViewConfigurationProperties>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result getViewConfigurationProperties(
      XrSystemId systemId, ViewConfigurationType viewConfigurationType,
      XrViewConfigurationProperties *configurationProperties,
      Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrGetViewConfigurationProperties wrapper - enhanced mode (hides
   * basic wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns nothing (void)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns Result.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetViewConfigurationProperties>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type getViewConfigurationProperties(
      XrSystemId systemId, ViewConfigurationType viewConfigurationType,
      XrViewConfigurationProperties *configurationProperties,
      Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  /*!
   * @brief xrEnumerateViewConfigurationViews wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateViewConfigurationViews>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result enumerateViewConfigurationViews(
      XrSystemId systemId, ViewConfigurationType viewConfigurationType,
      uint32_t viewCapacityInput, uint32_t *viewCountOutput,
      XrViewConfigurationView *views, Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrEnumerateViewConfigurationViews wrapper - enhanced mode.Performs
   * two-call idiom.    //! If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns the value of type std::vector<XrViewConfigurationView, Allocator>
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns the output of type std::vector<XrViewConfigurationView,
   * Allocator>.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateViewConfigurationViews>
   */
  template <typename Allocator = std::allocator<XrViewConfigurationView>,
            typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<
      std::vector<XrViewConfigurationView, Allocator>>::type
  enumerateViewConfigurationViews(XrSystemId systemId,
                                  ViewConfigurationType viewConfigurationType,
                                  Dispatch &&d = Dispatch{}) const;

  /*!
   * @brief xrEnumerateViewConfigurationViews wrapper - enhanced mode. Performs
   * two-call idiom with a stateful allocator.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns the value of type std::vector<XrViewConfigurationView, Allocator>
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns the output of type std::vector<XrViewConfigurationView,
   * Allocator>.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateViewConfigurationViews>
   */
  template <typename Allocator = std::allocator<XrViewConfigurationView>,
            typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<
      std::vector<XrViewConfigurationView, Allocator>>::type
  enumerateViewConfigurationViews(XrSystemId systemId,
                                  ViewConfigurationType viewConfigurationType,
                                  Allocator const &vectorAllocator,
                                  Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrStringToPath wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrStringToPath>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result stringToPath(const char *pathString, XrPath *path,
                      Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrStringToPath wrapper - enhanced mode (hides basic wrapper unless
   * OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns nothing (void)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns Result.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrStringToPath>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type stringToPath(const char *pathString, XrPath *path,
                                           Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  /*!
   * @brief xrPathToString wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrPathToString>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result pathToString(XrPath path, uint32_t bufferCapacityInput,
                      uint32_t *bufferCountOutput, char *buffer,
                      Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrPathToString wrapper - enhanced mode.Performs two-call idiom. //!
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns the value of type string_with_allocator<Allocator>
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns the output of type string_with_allocator<Allocator>.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrPathToString>
   */
  template <typename Allocator = std::allocator<char>,
            typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<string_with_allocator<Allocator>>::type
  pathToString(XrPath path, Dispatch &&d = Dispatch{}) const;

  /*!
   * @brief xrPathToString wrapper - enhanced mode. Performs two-call idiom with
   * a stateful allocator.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns the value of type string_with_allocator<Allocator>
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns the output of type string_with_allocator<Allocator>.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrPathToString>
   */
  template <typename Allocator = std::allocator<char>,
            typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<string_with_allocator<Allocator>>::type
  pathToString(XrPath path, Allocator const &vectorAllocator,
               Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  /*!
   * @brief xrCreateActionSet wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateActionSet>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result createActionSet(const XrActionSetCreateInfo *createInfo,
                         ActionSet &actionSet, Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrCreateActionSet wrapper - enhanced mode.    //!
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns the value of type ActionSet
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns the output of type ActionSet.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateActionSet>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<ActionSet>::type
  createActionSet(const XrActionSetCreateInfo *createInfo,
                  Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_NO_SMART_HANDLE

  /*!
   * @brief xrCreateActionSet wrapper returning a smart handle.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns the value of type UniqueHandle<ActionSet,
   * impl::RemoveRefConst<Dispatch>>
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns the output of type UniqueHandle<ActionSet,
   * impl::RemoveRefConst<Dispatch>>.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateActionSet>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<
      UniqueHandle<ActionSet, impl::RemoveRefConst<Dispatch>>>::type
  createActionSetUnique(const XrActionSetCreateInfo *createInfo,
                        Dispatch &&d = Dispatch{}) const;
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrSuggestInteractionProfileBindings wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrSuggestInteractionProfileBindings>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result suggestInteractionProfileBindings(
      const XrInteractionProfileSuggestedBinding *suggestedBindings,
      Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrSuggestInteractionProfileBindings wrapper - enhanced mode (hides
   * basic wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns nothing (void)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns Result.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrSuggestInteractionProfileBindings>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type suggestInteractionProfileBindings(
      const XrInteractionProfileSuggestedBinding *suggestedBindings,
      Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#if defined(XR_USE_GRAPHICS_API_OPENGL)

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrGetOpenGLGraphicsRequirementsKHR wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetOpenGLGraphicsRequirementsKHR>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result getOpenGLGraphicsRequirementsKHR(
      XrSystemId systemId,
      XrGraphicsRequirementsOpenGLKHR *graphicsRequirements,
      Dispatch &&d) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrGetOpenGLGraphicsRequirementsKHR wrapper - enhanced mode (hides
   * basic wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns nothing (void)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns Result.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetOpenGLGraphicsRequirementsKHR>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  ResultValueType<void>::type getOpenGLGraphicsRequirementsKHR(
      XrSystemId systemId,
      XrGraphicsRequirementsOpenGLKHR *graphicsRequirements,
      Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_GRAPHICS_API_OPENGL)

#if defined(XR_USE_GRAPHICS_API_OPENGL_ES)

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrGetOpenGLESGraphicsRequirementsKHR wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetOpenGLESGraphicsRequirementsKHR>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result getOpenGLESGraphicsRequirementsKHR(
      XrSystemId systemId,
      XrGraphicsRequirementsOpenGLESKHR *graphicsRequirements,
      Dispatch &&d) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrGetOpenGLESGraphicsRequirementsKHR wrapper - enhanced mode (hides
   * basic wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns nothing (void)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns Result.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetOpenGLESGraphicsRequirementsKHR>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  ResultValueType<void>::type getOpenGLESGraphicsRequirementsKHR(
      XrSystemId systemId,
      XrGraphicsRequirementsOpenGLESKHR *graphicsRequirements,
      Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_GRAPHICS_API_OPENGL_ES)

#if defined(XR_USE_GRAPHICS_API_VULKAN)

  /*!
   * @brief xrGetVulkanInstanceExtensionsKHR wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetVulkanInstanceExtensionsKHR>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result getVulkanInstanceExtensionsKHR(XrSystemId systemId,
                                        uint32_t bufferCapacityInput,
                                        uint32_t *bufferCountOutput,
                                        char *buffer, Dispatch &&d) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrGetVulkanInstanceExtensionsKHR wrapper - enhanced mode.Performs
   * two-call idiom.    //! If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns the value of type string_with_allocator<Allocator>
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns the output of type string_with_allocator<Allocator>.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetVulkanInstanceExtensionsKHR>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Allocator = std::allocator<char>, typename Dispatch>
  typename ResultValueType<string_with_allocator<Allocator>>::type
  getVulkanInstanceExtensionsKHR(XrSystemId systemId, Dispatch &&d) const;

  /*!
   * @brief xrGetVulkanInstanceExtensionsKHR wrapper - enhanced mode. Performs
   * two-call idiom with a stateful allocator.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns the value of type string_with_allocator<Allocator>
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns the output of type string_with_allocator<Allocator>.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetVulkanInstanceExtensionsKHR>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Allocator = std::allocator<char>, typename Dispatch>
  typename ResultValueType<string_with_allocator<Allocator>>::type
  getVulkanInstanceExtensionsKHR(XrSystemId systemId,
                                 Allocator const &vectorAllocator,
                                 Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_GRAPHICS_API_VULKAN)

#if defined(XR_USE_GRAPHICS_API_VULKAN)

  /*!
   * @brief xrGetVulkanDeviceExtensionsKHR wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetVulkanDeviceExtensionsKHR>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result getVulkanDeviceExtensionsKHR(XrSystemId systemId,
                                      uint32_t bufferCapacityInput,
                                      uint32_t *bufferCountOutput, char *buffer,
                                      Dispatch &&d) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrGetVulkanDeviceExtensionsKHR wrapper - enhanced mode.Performs
   * two-call idiom.    //! If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns the value of type string_with_allocator<Allocator>
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns the output of type string_with_allocator<Allocator>.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetVulkanDeviceExtensionsKHR>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Allocator = std::allocator<char>, typename Dispatch>
  typename ResultValueType<string_with_allocator<Allocator>>::type
  getVulkanDeviceExtensionsKHR(XrSystemId systemId, Dispatch &&d) const;

  /*!
   * @brief xrGetVulkanDeviceExtensionsKHR wrapper - enhanced mode. Performs
   * two-call idiom with a stateful allocator.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns the value of type string_with_allocator<Allocator>
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns the output of type string_with_allocator<Allocator>.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetVulkanDeviceExtensionsKHR>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Allocator = std::allocator<char>, typename Dispatch>
  typename ResultValueType<string_with_allocator<Allocator>>::type
  getVulkanDeviceExtensionsKHR(XrSystemId systemId,
                               Allocator const &vectorAllocator,
                               Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_GRAPHICS_API_VULKAN)

#if defined(XR_USE_GRAPHICS_API_VULKAN)

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrGetVulkanGraphicsDeviceKHR wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetVulkanGraphicsDeviceKHR>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result getVulkanGraphicsDeviceKHR(XrSystemId systemId, VkInstance vkInstance,
                                    VkPhysicalDevice *vkPhysicalDevice,
                                    Dispatch &&d) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrGetVulkanGraphicsDeviceKHR wrapper - enhanced mode (hides basic
   * wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns nothing (void)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns Result.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetVulkanGraphicsDeviceKHR>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  ResultValueType<void>::type
  getVulkanGraphicsDeviceKHR(XrSystemId systemId, VkInstance vkInstance,
                             VkPhysicalDevice *vkPhysicalDevice,
                             Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_GRAPHICS_API_VULKAN)

#if defined(XR_USE_GRAPHICS_API_VULKAN)

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrGetVulkanGraphicsRequirementsKHR wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetVulkanGraphicsRequirementsKHR>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result getVulkanGraphicsRequirementsKHR(
      XrSystemId systemId,
      XrGraphicsRequirementsVulkanKHR *graphicsRequirements,
      Dispatch &&d) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrGetVulkanGraphicsRequirementsKHR wrapper - enhanced mode (hides
   * basic wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns nothing (void)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns Result.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetVulkanGraphicsRequirementsKHR>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  ResultValueType<void>::type getVulkanGraphicsRequirementsKHR(
      XrSystemId systemId,
      XrGraphicsRequirementsVulkanKHR *graphicsRequirements,
      Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_GRAPHICS_API_VULKAN)

#if defined(XR_USE_GRAPHICS_API_D3D11)

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrGetD3D11GraphicsRequirementsKHR wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetD3D11GraphicsRequirementsKHR>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result getD3D11GraphicsRequirementsKHR(
      XrSystemId systemId, XrGraphicsRequirementsD3D11KHR *graphicsRequirements,
      Dispatch &&d) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrGetD3D11GraphicsRequirementsKHR wrapper - enhanced mode (hides
   * basic wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns nothing (void)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns Result.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetD3D11GraphicsRequirementsKHR>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  ResultValueType<void>::type getD3D11GraphicsRequirementsKHR(
      XrSystemId systemId, XrGraphicsRequirementsD3D11KHR *graphicsRequirements,
      Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_GRAPHICS_API_D3D11)

#if defined(XR_USE_GRAPHICS_API_D3D12)

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrGetD3D12GraphicsRequirementsKHR wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetD3D12GraphicsRequirementsKHR>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result getD3D12GraphicsRequirementsKHR(
      XrSystemId systemId, XrGraphicsRequirementsD3D12KHR *graphicsRequirements,
      Dispatch &&d) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrGetD3D12GraphicsRequirementsKHR wrapper - enhanced mode (hides
   * basic wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns nothing (void)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns Result.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetD3D12GraphicsRequirementsKHR>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  ResultValueType<void>::type getD3D12GraphicsRequirementsKHR(
      XrSystemId systemId, XrGraphicsRequirementsD3D12KHR *graphicsRequirements,
      Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_GRAPHICS_API_D3D12)

#if defined(XR_USE_PLATFORM_WIN32)

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrConvertWin32PerformanceCounterToTimeKHR wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrConvertWin32PerformanceCounterToTimeKHR>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result convertWin32PerformanceCounterToTimeKHR(
      const LARGE_INTEGER *performanceCounter, XrTime *time,
      Dispatch &&d) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrConvertWin32PerformanceCounterToTimeKHR wrapper - enhanced mode
   * (hides basic wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined). //!
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns nothing (void)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns Result.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrConvertWin32PerformanceCounterToTimeKHR>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  ResultValueType<void>::type convertWin32PerformanceCounterToTimeKHR(
      const LARGE_INTEGER *performanceCounter, XrTime *time,
      Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_PLATFORM_WIN32)

#if defined(XR_USE_PLATFORM_WIN32)

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrConvertTimeToWin32PerformanceCounterKHR wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrConvertTimeToWin32PerformanceCounterKHR>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result convertTimeToWin32PerformanceCounterKHR(
      XrTime time, LARGE_INTEGER *performanceCounter, Dispatch &&d) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrConvertTimeToWin32PerformanceCounterKHR wrapper - enhanced mode
   * (hides basic wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined). //!
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns nothing (void)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns Result.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrConvertTimeToWin32PerformanceCounterKHR>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  ResultValueType<void>::type convertTimeToWin32PerformanceCounterKHR(
      XrTime time, LARGE_INTEGER *performanceCounter, Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_PLATFORM_WIN32)

#if defined(XR_USE_TIMESPEC)

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrConvertTimespecTimeToTimeKHR wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrConvertTimespecTimeToTimeKHR>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result convertTimespecTimeToTimeKHR(const struct timespec *timespecTime,
                                      XrTime *time, Dispatch &&d) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrConvertTimespecTimeToTimeKHR wrapper - enhanced mode (hides basic
   * wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns nothing (void)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns Result.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrConvertTimespecTimeToTimeKHR>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  ResultValueType<void>::type
  convertTimespecTimeToTimeKHR(const struct timespec *timespecTime,
                               XrTime *time, Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_TIMESPEC)

#if defined(XR_USE_TIMESPEC)

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrConvertTimeToTimespecTimeKHR wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrConvertTimeToTimespecTimeKHR>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result convertTimeToTimespecTimeKHR(XrTime time,
                                      struct timespec *timespecTime,
                                      Dispatch &&d) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrConvertTimeToTimespecTimeKHR wrapper - enhanced mode (hides basic
   * wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns nothing (void)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns Result.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrConvertTimeToTimespecTimeKHR>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  ResultValueType<void>::type
  convertTimeToTimespecTimeKHR(XrTime time, struct timespec *timespecTime,
                               Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_TIMESPEC)

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrSetDebugUtilsObjectNameEXT wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrSetDebugUtilsObjectNameEXT>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result
  setDebugUtilsObjectNameEXT(const XrDebugUtilsObjectNameInfoEXT *nameInfo,
                             Dispatch &&d) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrSetDebugUtilsObjectNameEXT wrapper - enhanced mode (hides basic
   * wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns nothing (void)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns Result.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrSetDebugUtilsObjectNameEXT>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  ResultValueType<void>::type
  setDebugUtilsObjectNameEXT(const XrDebugUtilsObjectNameInfoEXT *nameInfo,
                             Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  /*!
   * @brief xrCreateDebugUtilsMessengerEXT wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateDebugUtilsMessengerEXT>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result createDebugUtilsMessengerEXT(
      const XrDebugUtilsMessengerCreateInfoEXT *createInfo,
      DebugUtilsMessengerEXT &messenger, Dispatch &&d) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrCreateDebugUtilsMessengerEXT wrapper - enhanced mode.    //!
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns the value of type DebugUtilsMessengerEXT
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns the output of type DebugUtilsMessengerEXT.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateDebugUtilsMessengerEXT>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  typename ResultValueType<DebugUtilsMessengerEXT>::type
  createDebugUtilsMessengerEXT(
      const XrDebugUtilsMessengerCreateInfoEXT *createInfo, Dispatch &&d) const;

#ifndef OPENXR_HPP_NO_SMART_HANDLE

  /*!
   * @brief xrCreateDebugUtilsMessengerEXT wrapper returning a smart handle.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns the value of type UniqueHandle<DebugUtilsMessengerEXT,
   * impl::RemoveRefConst<Dispatch>>
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns the output of type UniqueHandle<DebugUtilsMessengerEXT,
   * impl::RemoveRefConst<Dispatch>>.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateDebugUtilsMessengerEXT>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  typename ResultValueType<UniqueHandle<DebugUtilsMessengerEXT,
                                        impl::RemoveRefConst<Dispatch>>>::type
  createDebugUtilsMessengerUniqueEXT(
      const XrDebugUtilsMessengerCreateInfoEXT *createInfo, Dispatch &&d) const;
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrSubmitDebugUtilsMessageEXT wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrSubmitDebugUtilsMessageEXT>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result submitDebugUtilsMessageEXT(
      XrDebugUtilsMessageSeverityFlagsEXT messageSeverity,
      XrDebugUtilsMessageTypeFlagsEXT messageTypes,
      const XrDebugUtilsMessengerCallbackDataEXT *callbackData,
      Dispatch &&d) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrSubmitDebugUtilsMessageEXT wrapper - enhanced mode (hides basic
   * wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns nothing (void)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns Result.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrSubmitDebugUtilsMessageEXT>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  ResultValueType<void>::type submitDebugUtilsMessageEXT(
      XrDebugUtilsMessageSeverityFlagsEXT messageSeverity,
      XrDebugUtilsMessageTypeFlagsEXT messageTypes,
      const XrDebugUtilsMessengerCallbackDataEXT *callbackData,
      Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @}
private:
  RawHandleType m_raw;
};
static_assert(sizeof(Instance) == sizeof(XrInstance),
              "handle and wrapper have different size!");

//! @brief < comparison between Instance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(Instance const &lhs,
                                                      Instance const &rhs) {
  return lhs.get() < rhs.get();
}
//! @brief < comparison between Instance and raw XrInstance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(Instance const &lhs,
                                                      XrInstance rhs) {
  return lhs.get() < rhs;
}
//! @brief < comparison between raw XrInstance and Instance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(XrInstance lhs,
                                                      Instance const &rhs) {
  return lhs < rhs.get();
}
//! @brief > comparison between Instance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(Instance const &lhs,
                                                      Instance const &rhs) {
  return lhs.get() > rhs.get();
}
//! @brief > comparison between Instance and raw XrInstance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(Instance const &lhs,
                                                      XrInstance rhs) {
  return lhs.get() > rhs;
}
//! @brief > comparison between raw XrInstance and Instance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(XrInstance lhs,
                                                      Instance const &rhs) {
  return lhs > rhs.get();
}
//! @brief <= comparison between Instance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(Instance const &lhs,
                                                       Instance const &rhs) {
  return lhs.get() <= rhs.get();
}
//! @brief <= comparison between Instance and raw XrInstance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(Instance const &lhs,
                                                       XrInstance rhs) {
  return lhs.get() <= rhs;
}
//! @brief <= comparison between raw XrInstance and Instance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(XrInstance lhs,
                                                       Instance const &rhs) {
  return lhs <= rhs.get();
}
//! @brief >= comparison between Instance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(Instance const &lhs,
                                                       Instance const &rhs) {
  return lhs.get() >= rhs.get();
}
//! @brief >= comparison between Instance and raw XrInstance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(Instance const &lhs,
                                                       XrInstance rhs) {
  return lhs.get() >= rhs;
}
//! @brief >= comparison between raw XrInstance and Instance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(XrInstance lhs,
                                                       Instance const &rhs) {
  return lhs >= rhs.get();
}
//! @brief == comparison between Instance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(Instance const &lhs,
                                                       Instance const &rhs) {
  return lhs.get() == rhs.get();
}
//! @brief == comparison between Instance and raw XrInstance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(Instance const &lhs,
                                                       XrInstance rhs) {
  return lhs.get() == rhs;
}
//! @brief == comparison between raw XrInstance and Instance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(XrInstance lhs,
                                                       Instance const &rhs) {
  return lhs == rhs.get();
}
//! @brief != comparison between Instance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(Instance const &lhs,
                                                       Instance const &rhs) {
  return lhs.get() != rhs.get();
}
//! @brief != comparison between Instance and raw XrInstance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(Instance const &lhs,
                                                       XrInstance rhs) {
  return lhs.get() != rhs;
}
//! @brief != comparison between raw XrInstance and Instance.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(XrInstance lhs,
                                                       Instance const &rhs) {
  return lhs != rhs.get();
}
//! @brief Equality comparison between Instance and nullptr: true if the handle
//! is null.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(Instance const &lhs, std::nullptr_t /* unused */) {
  return lhs.get() == XR_NULL_HANDLE;
}
//! @brief Equality comparison between nullptr and Instance: true if the handle
//! is null.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(std::nullptr_t /* unused */, Instance const &rhs) {
  return rhs.get() == XR_NULL_HANDLE;
}
//! @brief Inequality comparison between Instance and nullptr: true if the
//! handle is not null.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(Instance const &lhs, std::nullptr_t /* unused */) {
  return lhs.get() != XR_NULL_HANDLE;
}
//! @brief Inequality comparison between nullptr and Instance: true if the
//! handle is not null.
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(std::nullptr_t /* unused */, Instance const &rhs) {
  return rhs.get() != XR_NULL_HANDLE;
}

//! @brief Free function accessor for the raw XrInstance handle in a Instance
//! @relates Instance
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE XrInstance get(Instance const &h) {
  return h.get();
}

//! @brief Free "put" function for clearing and getting the address of the raw
//! XrInstance handle in a Instance (by reference).
//!
//! e.g.
//! ```
//! Instance yourHandle;
//! auto result = d.xrCreateInstance(..., put(yourHandle));
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the
//! namespace specified.
//! @relates Instance
OPENXR_HPP_INLINE XrInstance *put(Instance &h) { return h.put(); }

//! @brief Free "put" function for clearing and getting the address of the raw
//! XrInstance handle in a Instance (by pointer).
//!
//! e.g.
//! ```
//! void yourFunction(Instance* yourHandle) {
//!     auto result = d.xrCreateInstance(..., put(yourHandle));
//!     ....
//! }
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the
//! namespace specified.
//! @relates Instance
OPENXR_HPP_INLINE XrInstance *put(Instance *h) { return h->put(); }

namespace traits {
//! @brief Explicit specialization of cpp_type for Instance
template <> struct cpp_type<ObjectType::Instance> { using type = Instance; };
} // namespace traits

#ifndef OPENXR_HPP_NO_SMART_HANDLE

namespace traits {
//! Traits associating a deleter type with handles of type Session
template <typename Dispatch> class UniqueHandleTraits<Session, Dispatch> {
public:
  using deleter = ObjectDestroy<Dispatch>;
};
} // namespace traits

//! @addtogroup unique_handle_aliases
//! @{

//! Shorthand name for unique handles of type Session, using a static dispatch.
using UniqueSession = UniqueHandle<Session, DispatchLoaderStatic>;
//! Shorthand name for unique handles of type Session, using a dynamic dispatch.
using UniqueDynamicSession = UniqueHandle<Session, DispatchLoaderDynamic>;
//! @}
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/

//! @brief Handle class - wrapping XrSession
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrSession>
//! @ingroup handles
class Session {
public:
  using Type = Session;
  using RawHandleType = XrSession;

  /*!
   * @name Constructors, assignment, and conversions
   * @{
   */
  //! Default (empty/null) constructor
  OPENXR_HPP_CONSTEXPR Session() : m_raw(XR_NULL_HANDLE) {}

  //! Constructor from nullptr - creates empty/null handle.
  OPENXR_HPP_CONSTEXPR Session(std::nullptr_t /* unused */)
      : m_raw(XR_NULL_HANDLE) {}

  //! @brief Conversion constructor from the raw XrSession type
  //!
  //! Explicit on 32-bit platforms by default unless
  //! OPENXR_HPP_TYPESAFE_CONVERSION is defined.
  OPENXR_HPP_TYPESAFE_EXPLICIT Session(RawHandleType handle) : m_raw(handle) {}

#if defined(OPENXR_HPP_TYPESAFE_CONVERSION)
  //! @brief Assignment operator from the raw XrSession
  //!
  //! Does *not* destroy any contained non-null handle first! For that, see
  //! UniqueHandle<>.
  //!
  //! Only provided if OPENXR_HPP_TYPESAFE_CONVERSION is defined (defaults to
  //! only on 64-bit).
  Type &operator=(RawHandleType handle) {
    m_raw = handle;
    return *this;
  }
#endif

  //! @brief Assignment operator from nullptr - assigns to empty/null handle.
  //!
  //! Does *not* destroy any contained non-null handle first! For that, see
  //! UniqueHandle<>.
  Type &operator=(std::nullptr_t /* unused */) {
    m_raw = XR_NULL_HANDLE;
    return *this;
  }

  //! @brief Conversion operator to the raw XrSession type
  //!
  //! Explicit on 32-bit platforms by default unless
  //! OPENXR_HPP_TYPESAFE_CONVERSION is defined.
  OPENXR_HPP_CONSTEXPR OPENXR_HPP_TYPESAFE_EXPLICIT
  operator RawHandleType() const {
    return m_raw;
  }

  //! @}

  /*!
   * @name Validity checking
   * @{
   */
  //! Returns true in conditionals if this handle is non-null
  OPENXR_HPP_CONSTEXPR explicit operator bool() const {
    return m_raw != XR_NULL_HANDLE;
  }

  //! Negation operator: true if this handle is null
  OPENXR_HPP_CONSTEXPR bool operator!() const {
    return m_raw == XR_NULL_HANDLE;
  }
  //! @}

  /*!
   * @name Raw handle manipulation
   * @{
   */
  //! @brief "Put" function for assigning as null then getting the address of
  //! the raw pointer to pass to creation functions.
  //!
  //! e.g.
  //! ```
  //! Session yourHandle;
  //! auto result = d.xrCreateSession(..., yourHandle.put()));
  //! ```
  //!
  //! See also OPENXR_HPP_NAMESPACE::put()
  RawHandleType *put() {
    m_raw = XR_NULL_HANDLE;
    return &m_raw;
  }

  //! @brief Gets the raw handle type.
  //!
  //! See also OPENXR_HPP_NAMESPACE::get()
  OPENXR_HPP_CONSTEXPR RawHandleType get() const { return m_raw; }

  //! @}

  /*!
   * @name OpenXR API calls as member functions
   * @{
   */

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrDestroySession wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrDestroySession>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result destroy(Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrDestroySession wrapper - enhanced mode (hides basic wrapper unless
   * OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns nothing (void)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns Result.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrDestroySession>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type destroy(Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  /*!
   * @brief xrEnumerateReferenceSpaces wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateReferenceSpaces>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result enumerateReferenceSpaces(uint32_t spaceCapacityInput,
                                  uint32_t *spaceCountOutput,
                                  ReferenceSpaceType &spaces,
                                  Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrEnumerateReferenceSpaces wrapper - enhanced mode.Performs two-call
   * idiom.    //! If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns ResultValue<std::vector<ReferenceSpaceType, Allocator>>,
   * containing both a Result (which may be Result::Success, or a
   * non-Result::Success success code) and the output of type
   * std::vector<ReferenceSpaceType, Allocator>.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns ResultValue<std::vector<ReferenceSpaceType, Allocator>>,
   * containing both a Result (which may be an error, Result::Success, or a
   * non-Result::Success success code) and the output of type
   * std::vector<ReferenceSpaceType, Allocator>.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateReferenceSpaces>
   */
  template <typename Allocator = std::allocator<ReferenceSpaceType>,
            typename Dispatch = DispatchLoaderStatic>
  ResultValue<std::vector<ReferenceSpaceType, Allocator>>
  enumerateReferenceSpaces(Dispatch &&d = Dispatch{}) const;

  /*!
   * @brief xrEnumerateReferenceSpaces wrapper - enhanced mode. Performs
   * two-call idiom with a stateful allocator.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns ResultValue<std::vector<ReferenceSpaceType, Allocator>>,
   * containing both a Result (which may be Result::Success, or a
   * non-Result::Success success code) and the output of type
   * std::vector<ReferenceSpaceType, Allocator>.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns ResultValue<std::vector<ReferenceSpaceType, Allocator>>,
   * containing both a Result (which may be an error, Result::Success, or a
   * non-Result::Success success code) and the output of type
   * std::vector<ReferenceSpaceType, Allocator>.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateReferenceSpaces>
   */
  template <typename Allocator = std::allocator<ReferenceSpaceType>,
            typename Dispatch = DispatchLoaderStatic>
  ResultValue<std::vector<ReferenceSpaceType, Allocator>>
  enumerateReferenceSpaces(Allocator const &vectorAllocator,
                           Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  /*!
   * @brief xrCreateReferenceSpace wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateReferenceSpace>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result createReferenceSpace(const XrReferenceSpaceCreateInfo *createInfo,
                              Space &space, Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrCreateReferenceSpace wrapper - enhanced mode.    //!
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns ResultValue<Space>, containing both a Result (which may be
   * Result::Success, or a non-Result::Success success code) and the output of
   * type Space.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns ResultValue<Space>, containing both a Result (which may be an
   * error, Result::Success, or a non-Result::Success success code) and the
   * output of type Space.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateReferenceSpace>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  ResultValue<Space>
  createReferenceSpace(const XrReferenceSpaceCreateInfo *createInfo,
                       Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_NO_SMART_HANDLE

  /*!
   * @brief xrCreateReferenceSpace wrapper returning a smart handle.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns ResultValue<UniqueHandle<Space, impl::RemoveRefConst<Dispatch>>>,
   * containing both a Result (which may be Result::Success, or a
   * non-Result::Success success code) and the output of type
   * UniqueHandle<Space, impl::RemoveRefConst<Dispatch>>.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns ResultValue<UniqueHandle<Space, impl::RemoveRefConst<Dispatch>>>,
   * containing both a Result (which may be an error, Result::Success, or a
   * non-Result::Success success code) and the output of type
   * UniqueHandle<Space, impl::RemoveRefConst<Dispatch>>.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateReferenceSpace>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  ResultValue<UniqueHandle<Space, impl::RemoveRefConst<Dispatch>>>
  createReferenceSpaceUnique(const XrReferenceSpaceCreateInfo *createInfo,
                             Dispatch &&d = Dispatch{}) const;
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrGetReferenceSpaceBoundsRect wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetReferenceSpaceBoundsRect>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result getReferenceSpaceBoundsRect(ReferenceSpaceType referenceSpaceType,
                                     XrExtent2Df *bounds,
                                     Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrGetReferenceSpaceBoundsRect wrapper - enhanced mode (hides basic
   * wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns Result (which may be Result::Success, or a non-Result::Success
   * success code)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns Result (which may be an error, Result::Success, or a
   * non-Result::Success success code).
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetReferenceSpaceBoundsRect>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result getReferenceSpaceBoundsRect(ReferenceSpaceType referenceSpaceType,
                                     XrExtent2Df *bounds,
                                     Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  /*!
   * @brief xrCreateActionSpace wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateActionSpace>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result createActionSpace(const XrActionSpaceCreateInfo *createInfo,
                           Space &space, Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrCreateActionSpace wrapper - enhanced mode.    //!
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns ResultValue<Space>, containing both a Result (which may be
   * Result::Success, or a non-Result::Success success code) and the output of
   * type Space.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns ResultValue<Space>, containing both a Result (which may be an
   * error, Result::Success, or a non-Result::Success success code) and the
   * output of type Space.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateActionSpace>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  ResultValue<Space>
  createActionSpace(const XrActionSpaceCreateInfo *createInfo,
                    Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_NO_SMART_HANDLE

  /*!
   * @brief xrCreateActionSpace wrapper returning a smart handle.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns ResultValue<UniqueHandle<Space, impl::RemoveRefConst<Dispatch>>>,
   * containing both a Result (which may be Result::Success, or a
   * non-Result::Success success code) and the output of type
   * UniqueHandle<Space, impl::RemoveRefConst<Dispatch>>.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns ResultValue<UniqueHandle<Space, impl::RemoveRefConst<Dispatch>>>,
   * containing both a Result (which may be an error, Result::Success, or a
   * non-Result::Success success code) and the output of type
   * UniqueHandle<Space, impl::RemoveRefConst<Dispatch>>.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateActionSpace>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  ResultValue<UniqueHandle<Space, impl::RemoveRefConst<Dispatch>>>
  createActionSpaceUnique(const XrActionSpaceCreateInfo *createInfo,
                          Dispatch &&d = Dispatch{}) const;
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  /*!
   * @brief xrEnumerateSwapchainFormats wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateSwapchainFormats>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result enumerateSwapchainFormats(uint32_t formatCapacityInput,
                                   uint32_t *formatCountOutput,
                                   int64_t *formats,
                                   Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrEnumerateSwapchainFormats wrapper - enhanced mode.Performs
   * two-call idiom.    //! If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns ResultValue<std::vector<int64_t, Allocator>>, containing both a
   * Result (which may be Result::Success, or a non-Result::Success success
   * code) and the output of type std::vector<int64_t, Allocator>.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns ResultValue<std::vector<int64_t, Allocator>>, containing both a
   * Result (which may be an error, Result::Success, or a non-Result::Success
   * success code) and the output of type std::vector<int64_t, Allocator>.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateSwapchainFormats>
   */
  template <typename Allocator = std::allocator<int64_t>,
            typename Dispatch = DispatchLoaderStatic>
  ResultValue<std::vector<int64_t, Allocator>>
  enumerateSwapchainFormats(Dispatch &&d = Dispatch{}) const;

  /*!
   * @brief xrEnumerateSwapchainFormats wrapper - enhanced mode. Performs
   * two-call idiom with a stateful allocator.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns ResultValue<std::vector<int64_t, Allocator>>, containing both a
   * Result (which may be Result::Success, or a non-Result::Success success
   * code) and the output of type std::vector<int64_t, Allocator>.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns ResultValue<std::vector<int64_t, Allocator>>, containing both a
   * Result (which may be an error, Result::Success, or a non-Result::Success
   * success code) and the output of type std::vector<int64_t, Allocator>.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateSwapchainFormats>
   */
  template <typename Allocator = std::allocator<int64_t>,
            typename Dispatch = DispatchLoaderStatic>
  ResultValue<std::vector<int64_t, Allocator>>
  enumerateSwapchainFormats(Allocator const &vectorAllocator,
                            Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  /*!
   * @brief xrCreateSwapchain wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateSwapchain>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result createSwapchain(const XrSwapchainCreateInfo *createInfo,
                         Swapchain &swapchain, Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrCreateSwapchain wrapper - enhanced mode.    //!
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns ResultValue<Swapchain>, containing both a Result (which may be
   * Result::Success, or a non-Result::Success success code) and the output of
   * type Swapchain.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns ResultValue<Swapchain>, containing both a Result (which may be an
   * error, Result::Success, or a non-Result::Success success code) and the
   * output of type Swapchain.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateSwapchain>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  ResultValue<Swapchain>
  createSwapchain(const XrSwapchainCreateInfo *createInfo,
                  Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_NO_SMART_HANDLE

  /*!
   * @brief xrCreateSwapchain wrapper returning a smart handle.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns ResultValue<UniqueHandle<Swapchain,
   * impl::RemoveRefConst<Dispatch>>>, containing both a Result (which may be
   * Result::Success, or a non-Result::Success success code) and the output of
   * type UniqueHandle<Swapchain, impl::RemoveRefConst<Dispatch>>.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns ResultValue<UniqueHandle<Swapchain,
   * impl::RemoveRefConst<Dispatch>>>, containing both a Result (which may be an
   * error, Result::Success, or a non-Result::Success success code) and the
   * output of type UniqueHandle<Swapchain, impl::RemoveRefConst<Dispatch>>.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateSwapchain>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  ResultValue<UniqueHandle<Swapchain, impl::RemoveRefConst<Dispatch>>>
  createSwapchainUnique(const XrSwapchainCreateInfo *createInfo,
                        Dispatch &&d = Dispatch{}) const;
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrBeginSession wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrBeginSession>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result beginSession(const XrSessionBeginInfo *beginInfo,
                      Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrBeginSession wrapper - enhanced mode (hides basic wrapper unless
   * OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns Result (which may be Result::Success, or a non-Result::Success
   * success code)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns Result (which may be an error, Result::Success, or a
   * non-Result::Success success code).
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrBeginSession>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result beginSession(const XrSessionBeginInfo *beginInfo,
                      Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrEndSession wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEndSession>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result endSession(Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrEndSession wrapper - enhanced mode (hides basic wrapper unless
   * OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns Result (which may be Result::Success, or a non-Result::Success
   * success code)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns Result (which may be an error, Result::Success, or a
   * non-Result::Success success code).
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEndSession>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result endSession(Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrRequestExitSession wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrRequestExitSession>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result requestExitSession(Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrRequestExitSession wrapper - enhanced mode (hides basic wrapper
   * unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns Result (which may be Result::Success, or a non-Result::Success
   * success code)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns Result (which may be an error, Result::Success, or a
   * non-Result::Success success code).
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrRequestExitSession>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result requestExitSession(Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrWaitFrame wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrWaitFrame>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result waitFrame(const XrFrameWaitInfo *frameWaitInfo,
                   XrFrameState *frameState, Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrWaitFrame wrapper - enhanced mode (hides basic wrapper unless
   * OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns Result (which may be Result::Success, or a non-Result::Success
   * success code)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns Result (which may be an error, Result::Success, or a
   * non-Result::Success success code).
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrWaitFrame>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result waitFrame(const XrFrameWaitInfo *frameWaitInfo,
                   XrFrameState *frameState, Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrBeginFrame wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrBeginFrame>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result beginFrame(const XrFrameBeginInfo *frameBeginInfo,
                    Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrBeginFrame wrapper - enhanced mode (hides basic wrapper unless
   * OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns Result (which may be Result::Success, or a non-Result::Success
   * success code)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns Result (which may be an error, Result::Success, or a
   * non-Result::Success success code).
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrBeginFrame>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result beginFrame(const XrFrameBeginInfo *frameBeginInfo,
                    Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrEndFrame wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEndFrame>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result endFrame(const XrFrameEndInfo *frameEndInfo,
                  Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrEndFrame wrapper - enhanced mode (hides basic wrapper unless
   * OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns Result (which may be Result::Success, or a non-Result::Success
   * success code)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns Result (which may be an error, Result::Success, or a
   * non-Result::Success success code).
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEndFrame>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result endFrame(const XrFrameEndInfo *frameEndInfo,
                  Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  /*!
   * @brief xrLocateViews wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrLocateViews>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result locateViews(const XrViewLocateInfo *viewLocateInfo,
                     XrViewState *viewState, uint32_t viewCapacityInput,
                     uint32_t *viewCountOutput, XrView *views,
                     Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrLocateViews wrapper - enhanced mode.Performs two-call idiom. //!
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns ResultValue<std::vector<XrView, Allocator>>, containing both a
   * Result (which may be Result::Success, or a non-Result::Success success
   * code) and the output of type std::vector<XrView, Allocator>.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns ResultValue<std::vector<XrView, Allocator>>, containing both a
   * Result (which may be an error, Result::Success, or a non-Result::Success
   * success code) and the output of type std::vector<XrView, Allocator>.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrLocateViews>
   */
  template <typename Allocator = std::allocator<XrView>,
            typename Dispatch = DispatchLoaderStatic>
  ResultValue<std::vector<XrView, Allocator>>
  locateViews(const XrViewLocateInfo *viewLocateInfo, XrViewState *viewState,
              Dispatch &&d = Dispatch{}) const;

  /*!
   * @brief xrLocateViews wrapper - enhanced mode. Performs two-call idiom with
   * a stateful allocator.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns ResultValue<std::vector<XrView, Allocator>>, containing both a
   * Result (which may be Result::Success, or a non-Result::Success success
   * code) and the output of type std::vector<XrView, Allocator>.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns ResultValue<std::vector<XrView, Allocator>>, containing both a
   * Result (which may be an error, Result::Success, or a non-Result::Success
   * success code) and the output of type std::vector<XrView, Allocator>.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrLocateViews>
   */
  template <typename Allocator = std::allocator<XrView>,
            typename Dispatch = DispatchLoaderStatic>
  ResultValue<std::vector<XrView, Allocator>>
  locateViews(const XrViewLocateInfo *viewLocateInfo, XrViewState *viewState,
              Allocator const &vectorAllocator, Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrAttachSessionActionSets wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrAttachSessionActionSets>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result
  attachSessionActionSets(const XrSessionActionSetsAttachInfo *attachInfo,
                          Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrAttachSessionActionSets wrapper - enhanced mode (hides basic
   * wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns Result (which may be Result::Success, or a non-Result::Success
   * success code)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns Result (which may be an error, Result::Success, or a
   * non-Result::Success success code).
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrAttachSessionActionSets>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result
  attachSessionActionSets(const XrSessionActionSetsAttachInfo *attachInfo,
                          Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrGetCurrentInteractionProfile wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetCurrentInteractionProfile>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result
  getCurrentInteractionProfile(XrPath topLevelUserPath,
                               XrInteractionProfileState *interactionProfile,
                               Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrGetCurrentInteractionProfile wrapper - enhanced mode (hides basic
   * wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns Result (which may be Result::Success, or a non-Result::Success
   * success code)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns Result (which may be an error, Result::Success, or a
   * non-Result::Success success code).
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetCurrentInteractionProfile>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result
  getCurrentInteractionProfile(XrPath topLevelUserPath,
                               XrInteractionProfileState *interactionProfile,
                               Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrGetActionStateBoolean wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetActionStateBoolean>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result getActionStateBoolean(const XrActionStateGetInfo *getInfo,
                               XrActionStateBoolean *state,
                               Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrGetActionStateBoolean wrapper - enhanced mode (hides basic wrapper
   * unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns Result (which may be Result::Success, or a non-Result::Success
   * success code)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns Result (which may be an error, Result::Success, or a
   * non-Result::Success success code).
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetActionStateBoolean>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result getActionStateBoolean(const XrActionStateGetInfo *getInfo,
                               XrActionStateBoolean *state,
                               Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrGetActionStateFloat wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetActionStateFloat>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result getActionStateFloat(const XrActionStateGetInfo *getInfo,
                             XrActionStateFloat *state,
                             Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrGetActionStateFloat wrapper - enhanced mode (hides basic wrapper
   * unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns Result (which may be Result::Success, or a non-Result::Success
   * success code)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns Result (which may be an error, Result::Success, or a
   * non-Result::Success success code).
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetActionStateFloat>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result getActionStateFloat(const XrActionStateGetInfo *getInfo,
                             XrActionStateFloat *state,
                             Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrGetActionStateVector2f wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetActionStateVector2f>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result getActionStateVector2f(const XrActionStateGetInfo *getInfo,
                                XrActionStateVector2f *state,
                                Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrGetActionStateVector2f wrapper - enhanced mode (hides basic
   * wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns Result (which may be Result::Success, or a non-Result::Success
   * success code)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns Result (which may be an error, Result::Success, or a
   * non-Result::Success success code).
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetActionStateVector2f>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result getActionStateVector2f(const XrActionStateGetInfo *getInfo,
                                XrActionStateVector2f *state,
                                Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrGetActionStatePose wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetActionStatePose>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result getActionStatePose(const XrActionStateGetInfo *getInfo,
                            XrActionStatePose *state,
                            Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrGetActionStatePose wrapper - enhanced mode (hides basic wrapper
   * unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns Result (which may be Result::Success, or a non-Result::Success
   * success code)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns Result (which may be an error, Result::Success, or a
   * non-Result::Success success code).
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetActionStatePose>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result getActionStatePose(const XrActionStateGetInfo *getInfo,
                            XrActionStatePose *state,
                            Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrSyncActions wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrSyncActions>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result syncActions(const XrActionsSyncInfo *syncInfo,
                     Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrSyncActions wrapper - enhanced mode (hides basic wrapper unless
   * OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns Result (which may be Result::Success, or a non-Result::Success
   * success code)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns Result (which may be an error, Result::Success, or a
   * non-Result::Success success code).
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrSyncActions>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result syncActions(const XrActionsSyncInfo *syncInfo,
                     Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  /*!
   * @brief xrEnumerateBoundSourcesForAction wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateBoundSourcesForAction>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result enumerateBoundSourcesForAction(
      const XrBoundSourcesForActionEnumerateInfo *enumerateInfo,
      uint32_t sourceCapacityInput, uint32_t *sourceCountOutput,
      XrPath *sources, Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrEnumerateBoundSourcesForAction wrapper - enhanced mode.Performs
   * two-call idiom.    //! If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns ResultValue<std::vector<XrPath, Allocator>>, containing both a
   * Result (which may be Result::Success, or a non-Result::Success success
   * code) and the output of type std::vector<XrPath, Allocator>.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns ResultValue<std::vector<XrPath, Allocator>>, containing both a
   * Result (which may be an error, Result::Success, or a non-Result::Success
   * success code) and the output of type std::vector<XrPath, Allocator>.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateBoundSourcesForAction>
   */
  template <typename Allocator = std::allocator<XrPath>,
            typename Dispatch = DispatchLoaderStatic>
  ResultValue<std::vector<XrPath, Allocator>> enumerateBoundSourcesForAction(
      const XrBoundSourcesForActionEnumerateInfo *enumerateInfo,
      Dispatch &&d = Dispatch{}) const;

  /*!
   * @brief xrEnumerateBoundSourcesForAction wrapper - enhanced mode. Performs
   * two-call idiom with a stateful allocator.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns ResultValue<std::vector<XrPath, Allocator>>, containing both a
   * Result (which may be Result::Success, or a non-Result::Success success
   * code) and the output of type std::vector<XrPath, Allocator>.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns ResultValue<std::vector<XrPath, Allocator>>, containing both a
   * Result (which may be an error, Result::Success, or a non-Result::Success
   * success code) and the output of type std::vector<XrPath, Allocator>.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateBoundSourcesForAction>
   */
  template <typename Allocator = std::allocator<XrPath>,
            typename Dispatch = DispatchLoaderStatic>
  ResultValue<std::vector<XrPath, Allocator>> enumerateBoundSourcesForAction(
      const XrBoundSourcesForActionEnumerateInfo *enumerateInfo,
      Allocator const &vectorAllocator, Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  /*!
   * @brief xrGetInputSourceLocalizedName wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetInputSourceLocalizedName>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result
  getInputSourceLocalizedName(const XrInputSourceLocalizedNameGetInfo *getInfo,
                              uint32_t bufferCapacityInput,
                              uint32_t *bufferCountOutput, char *buffer,
                              Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrGetInputSourceLocalizedName wrapper - enhanced mode.Performs
   * two-call idiom.    //! If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns ResultValue<string_with_allocator<Allocator>>, containing both a
   * Result (which may be Result::Success, or a non-Result::Success success
   * code) and the output string.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns ResultValue<string_with_allocator<Allocator>>, containing both a
   * Result (which may be an error, Result::Success, or a non-Result::Success
   * success code) and the output string.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetInputSourceLocalizedName>
   */
  template <typename Allocator = std::allocator<char>,
            typename Dispatch = DispatchLoaderStatic>
  ResultValue<string_with_allocator<Allocator>>
  getInputSourceLocalizedName(const XrInputSourceLocalizedNameGetInfo *getInfo,
                              Dispatch &&d = Dispatch{}) const;

  /*!
   * @brief xrGetInputSourceLocalizedName wrapper - enhanced mode. Performs
   * two-call idiom with a stateful allocator.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns ResultValue<string_with_allocator<Allocator>>, containing both a
   * Result (which may be Result::Success, or a non-Result::Success success
   * code) and the output string.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns ResultValue<string_with_allocator<Allocator>>, containing both a
   * Result (which may be an error, Result::Success, or a non-Result::Success
   * success code) and the output string.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetInputSourceLocalizedName>
   */
  template <typename Allocator = std::allocator<char>,
            typename Dispatch = DispatchLoaderStatic>
  ResultValue<string_with_allocator<Allocator>>
  getInputSourceLocalizedName(const XrInputSourceLocalizedNameGetInfo *getInfo,
                              Allocator const &vectorAllocator,
                              Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrApplyHapticFeedback wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrApplyHapticFeedback>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result applyHapticFeedback(const XrHapticActionInfo *hapticActionInfo,
                             const XrHapticBaseHeader *hapticFeedback,
                             Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrApplyHapticFeedback wrapper - enhanced mode (hides basic wrapper
   * unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns Result (which may be Result::Success, or a non-Result::Success
   * success code)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns Result (which may be an error, Result::Success, or a
   * non-Result::Success success code).
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrApplyHapticFeedback>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result applyHapticFeedback(const XrHapticActionInfo *hapticActionInfo,
                             const XrHapticBaseHeader *hapticFeedback,
                             Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrStopHapticFeedback wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrStopHapticFeedback>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result stopHapticFeedback(const XrHapticActionInfo *hapticActionInfo,
                            Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrStopHapticFeedback wrapper - enhanced mode (hides basic wrapper
   * unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns Result (which may be Result::Success, or a non-Result::Success
   * success code)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns Result (which may be an error, Result::Success, or a
   * non-Result::Success success code).
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrStopHapticFeedback>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result stopHapticFeedback(const XrHapticActionInfo *hapticActionInfo,
                            Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#if defined(XR_USE_PLATFORM_ANDROID)

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrSetAndroidApplicationThreadKHR wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrSetAndroidApplicationThreadKHR>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result setAndroidApplicationThreadKHR(AndroidThreadTypeKHR threadType,
                                        uint32_t threadId, Dispatch &&d) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrSetAndroidApplicationThreadKHR wrapper - enhanced mode (hides
   * basic wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns Result (which may be Result::Success, or a non-Result::Success
   * success code)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns Result (which may be an error, Result::Success, or a
   * non-Result::Success success code).
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrSetAndroidApplicationThreadKHR>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result setAndroidApplicationThreadKHR(AndroidThreadTypeKHR threadType,
                                        uint32_t threadId, Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_PLATFORM_ANDROID)

#if defined(XR_USE_PLATFORM_ANDROID)

  /*!
   * @brief xrCreateSwapchainAndroidSurfaceKHR wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateSwapchainAndroidSurfaceKHR>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result createSwapchainAndroidSurfaceKHR(const XrSwapchainCreateInfo *info,
                                          Swapchain &swapchain,
                                          jobject *surface, Dispatch &&d) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrCreateSwapchainAndroidSurfaceKHR wrapper - enhanced mode.    //!
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns ResultValue<jobject>, containing both a Result (which may be
   * Result::Success, or a non-Result::Success success code) and the output of
   * type jobject.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns ResultValue<jobject>, containing both a Result (which may be an
   * error, Result::Success, or a non-Result::Success success code) and the
   * output of type jobject.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateSwapchainAndroidSurfaceKHR>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  ResultValue<jobject>
  createSwapchainAndroidSurfaceKHR(const XrSwapchainCreateInfo *info,
                                   Swapchain &swapchain, Dispatch &&d) const;

#ifndef OPENXR_HPP_NO_SMART_HANDLE

  /*!
   * @brief xrCreateSwapchainAndroidSurfaceKHR wrapper returning a smart handle.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns ResultValue<UniqueHandle<jobject,
   * impl::RemoveRefConst<Dispatch>>>, containing both a Result (which may be
   * Result::Success, or a non-Result::Success success code) and the output of
   * type UniqueHandle<jobject, impl::RemoveRefConst<Dispatch>>.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns ResultValue<UniqueHandle<jobject,
   * impl::RemoveRefConst<Dispatch>>>, containing both a Result (which may be an
   * error, Result::Success, or a non-Result::Success success code) and the
   * output of type UniqueHandle<jobject, impl::RemoveRefConst<Dispatch>>.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateSwapchainAndroidSurfaceKHR>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  ResultValue<UniqueHandle<jobject, impl::RemoveRefConst<Dispatch>>>
  createSwapchainAndroidSurfaceUniqueKHR(const XrSwapchainCreateInfo *info,
                                         Swapchain &swapchain,
                                         Dispatch &&d) const;
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_PLATFORM_ANDROID)

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrGetVisibilityMaskKHR wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetVisibilityMaskKHR>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result getVisibilityMaskKHR(ViewConfigurationType viewConfigurationType,
                              uint32_t viewIndex,
                              VisibilityMaskTypeKHR visibilityMaskType,
                              XrVisibilityMaskKHR *visibilityMask,
                              Dispatch &&d) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrGetVisibilityMaskKHR wrapper - enhanced mode (hides basic wrapper
   * unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns Result (which may be Result::Success, or a non-Result::Success
   * success code)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns Result (which may be an error, Result::Success, or a
   * non-Result::Success success code).
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetVisibilityMaskKHR>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result getVisibilityMaskKHR(ViewConfigurationType viewConfigurationType,
                              uint32_t viewIndex,
                              VisibilityMaskTypeKHR visibilityMaskType,
                              XrVisibilityMaskKHR *visibilityMask,
                              Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrPerfSettingsSetPerformanceLevelEXT wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrPerfSettingsSetPerformanceLevelEXT>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result perfSettingsSetPerformanceLevelEXT(PerfSettingsDomainEXT domain,
                                            PerfSettingsLevelEXT level,
                                            Dispatch &&d) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrPerfSettingsSetPerformanceLevelEXT wrapper - enhanced mode (hides
   * basic wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns Result (which may be Result::Success, or a non-Result::Success
   * success code)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns Result (which may be an error, Result::Success, or a
   * non-Result::Success success code).
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrPerfSettingsSetPerformanceLevelEXT>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result perfSettingsSetPerformanceLevelEXT(PerfSettingsDomainEXT domain,
                                            PerfSettingsLevelEXT level,
                                            Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrThermalGetTemperatureTrendEXT wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrThermalGetTemperatureTrendEXT>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result thermalGetTemperatureTrendEXT(
      PerfSettingsDomainEXT domain,
      PerfSettingsNotificationLevelEXT &notificationLevel, float *tempHeadroom,
      float *tempSlope, Dispatch &&d) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrThermalGetTemperatureTrendEXT wrapper - enhanced mode (hides basic
   * wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns Result (which may be Result::Success, or a non-Result::Success
   * success code)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns Result (which may be an error, Result::Success, or a
   * non-Result::Success success code).
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrThermalGetTemperatureTrendEXT>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result thermalGetTemperatureTrendEXT(
      PerfSettingsDomainEXT domain,
      PerfSettingsNotificationLevelEXT &notificationLevel, float *tempHeadroom,
      float *tempSlope, Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrSessionBeginDebugUtilsLabelRegionEXT wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrSessionBeginDebugUtilsLabelRegionEXT>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result
  sessionBeginDebugUtilsLabelRegionEXT(const XrDebugUtilsLabelEXT *labelInfo,
                                       Dispatch &&d) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrSessionBeginDebugUtilsLabelRegionEXT wrapper - enhanced mode
   * (hides basic wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined). //!
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns Result (which may be Result::Success, or a non-Result::Success
   * success code)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns Result (which may be an error, Result::Success, or a
   * non-Result::Success success code).
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrSessionBeginDebugUtilsLabelRegionEXT>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result
  sessionBeginDebugUtilsLabelRegionEXT(const XrDebugUtilsLabelEXT *labelInfo,
                                       Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrSessionEndDebugUtilsLabelRegionEXT wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrSessionEndDebugUtilsLabelRegionEXT>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result sessionEndDebugUtilsLabelRegionEXT(Dispatch &&d) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrSessionEndDebugUtilsLabelRegionEXT wrapper - enhanced mode (hides
   * basic wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns Result (which may be Result::Success, or a non-Result::Success
   * success code)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns Result (which may be an error, Result::Success, or a
   * non-Result::Success success code).
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrSessionEndDebugUtilsLabelRegionEXT>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result sessionEndDebugUtilsLabelRegionEXT(Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrSessionInsertDebugUtilsLabelEXT wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrSessionInsertDebugUtilsLabelEXT>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result sessionInsertDebugUtilsLabelEXT(const XrDebugUtilsLabelEXT *labelInfo,
                                         Dispatch &&d) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrSessionInsertDebugUtilsLabelEXT wrapper - enhanced mode (hides
   * basic wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns Result (which may be Result::Success, or a non-Result::Success
   * success code)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns Result (which may be an error, Result::Success, or a
   * non-Result::Success success code).
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrSessionInsertDebugUtilsLabelEXT>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result sessionInsertDebugUtilsLabelEXT(const XrDebugUtilsLabelEXT *labelInfo,
                                         Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  /*!
   * @brief xrCreateSpatialAnchorMSFT wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateSpatialAnchorMSFT>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result
  createSpatialAnchorMSFT(const XrSpatialAnchorCreateInfoMSFT *createInfo,
                          SpatialAnchorMSFT &anchor, Dispatch &&d) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrCreateSpatialAnchorMSFT wrapper - enhanced mode.    //!
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns ResultValue<SpatialAnchorMSFT>, containing both a Result (which
   * may be Result::Success, or a non-Result::Success success code) and the
   * output of type SpatialAnchorMSFT.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns ResultValue<SpatialAnchorMSFT>, containing both a Result (which
   * may be an error, Result::Success, or a non-Result::Success success code)
   * and the output of type SpatialAnchorMSFT.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateSpatialAnchorMSFT>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  ResultValue<SpatialAnchorMSFT>
  createSpatialAnchorMSFT(const XrSpatialAnchorCreateInfoMSFT *createInfo,
                          Dispatch &&d) const;

#ifndef OPENXR_HPP_NO_SMART_HANDLE

  /*!
   * @brief xrCreateSpatialAnchorMSFT wrapper returning a smart handle.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns ResultValue<UniqueHandle<SpatialAnchorMSFT,
   * impl::RemoveRefConst<Dispatch>>>, containing both a Result (which may be
   * Result::Success, or a non-Result::Success success code) and the output of
   * type UniqueHandle<SpatialAnchorMSFT, impl::RemoveRefConst<Dispatch>>.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns ResultValue<UniqueHandle<SpatialAnchorMSFT,
   * impl::RemoveRefConst<Dispatch>>>, containing both a Result (which may be an
   * error, Result::Success, or a non-Result::Success success code) and the
   * output of type UniqueHandle<SpatialAnchorMSFT,
   * impl::RemoveRefConst<Dispatch>>.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateSpatialAnchorMSFT>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  ResultValue<UniqueHandle<SpatialAnchorMSFT, impl::RemoveRefConst<Dispatch>>>
  createSpatialAnchorUniqueMSFT(const XrSpatialAnchorCreateInfoMSFT *createInfo,
                                Dispatch &&d) const;
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  /*!
   * @brief xrCreateSpatialAnchorSpaceMSFT wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateSpatialAnchorSpaceMSFT>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result createSpatialAnchorSpaceMSFT(
      const XrSpatialAnchorSpaceCreateInfoMSFT *createInfo, Space &space,
      Dispatch &&d) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrCreateSpatialAnchorSpaceMSFT wrapper - enhanced mode.    //!
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns ResultValue<Space>, containing both a Result (which may be
   * Result::Success, or a non-Result::Success success code) and the output of
   * type Space.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns ResultValue<Space>, containing both a Result (which may be an
   * error, Result::Success, or a non-Result::Success success code) and the
   * output of type Space.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateSpatialAnchorSpaceMSFT>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  ResultValue<Space> createSpatialAnchorSpaceMSFT(
      const XrSpatialAnchorSpaceCreateInfoMSFT *createInfo, Dispatch &&d) const;

#ifndef OPENXR_HPP_NO_SMART_HANDLE

  /*!
   * @brief xrCreateSpatialAnchorSpaceMSFT wrapper returning a smart handle.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns ResultValue<UniqueHandle<Space, impl::RemoveRefConst<Dispatch>>>,
   * containing both a Result (which may be Result::Success, or a
   * non-Result::Success success code) and the output of type
   * UniqueHandle<Space, impl::RemoveRefConst<Dispatch>>.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns ResultValue<UniqueHandle<Space, impl::RemoveRefConst<Dispatch>>>,
   * containing both a Result (which may be an error, Result::Success, or a
   * non-Result::Success success code) and the output of type
   * UniqueHandle<Space, impl::RemoveRefConst<Dispatch>>.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateSpatialAnchorSpaceMSFT>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  ResultValue<UniqueHandle<Space, impl::RemoveRefConst<Dispatch>>>
  createSpatialAnchorSpaceUniqueMSFT(
      const XrSpatialAnchorSpaceCreateInfoMSFT *createInfo, Dispatch &&d) const;
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @}
private:
  RawHandleType m_raw;
};
static_assert(sizeof(Session) == sizeof(XrSession),
              "handle and wrapper have different size!");

//! @brief < comparison between Session.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(Session const &lhs,
                                                      Session const &rhs) {
  return lhs.get() < rhs.get();
}
//! @brief < comparison between Session and raw XrSession.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(Session const &lhs,
                                                      XrSession rhs) {
  return lhs.get() < rhs;
}
//! @brief < comparison between raw XrSession and Session.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(XrSession lhs,
                                                      Session const &rhs) {
  return lhs < rhs.get();
}
//! @brief > comparison between Session.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(Session const &lhs,
                                                      Session const &rhs) {
  return lhs.get() > rhs.get();
}
//! @brief > comparison between Session and raw XrSession.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(Session const &lhs,
                                                      XrSession rhs) {
  return lhs.get() > rhs;
}
//! @brief > comparison between raw XrSession and Session.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(XrSession lhs,
                                                      Session const &rhs) {
  return lhs > rhs.get();
}
//! @brief <= comparison between Session.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(Session const &lhs,
                                                       Session const &rhs) {
  return lhs.get() <= rhs.get();
}
//! @brief <= comparison between Session and raw XrSession.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(Session const &lhs,
                                                       XrSession rhs) {
  return lhs.get() <= rhs;
}
//! @brief <= comparison between raw XrSession and Session.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(XrSession lhs,
                                                       Session const &rhs) {
  return lhs <= rhs.get();
}
//! @brief >= comparison between Session.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(Session const &lhs,
                                                       Session const &rhs) {
  return lhs.get() >= rhs.get();
}
//! @brief >= comparison between Session and raw XrSession.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(Session const &lhs,
                                                       XrSession rhs) {
  return lhs.get() >= rhs;
}
//! @brief >= comparison between raw XrSession and Session.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(XrSession lhs,
                                                       Session const &rhs) {
  return lhs >= rhs.get();
}
//! @brief == comparison between Session.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(Session const &lhs,
                                                       Session const &rhs) {
  return lhs.get() == rhs.get();
}
//! @brief == comparison between Session and raw XrSession.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(Session const &lhs,
                                                       XrSession rhs) {
  return lhs.get() == rhs;
}
//! @brief == comparison between raw XrSession and Session.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(XrSession lhs,
                                                       Session const &rhs) {
  return lhs == rhs.get();
}
//! @brief != comparison between Session.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(Session const &lhs,
                                                       Session const &rhs) {
  return lhs.get() != rhs.get();
}
//! @brief != comparison between Session and raw XrSession.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(Session const &lhs,
                                                       XrSession rhs) {
  return lhs.get() != rhs;
}
//! @brief != comparison between raw XrSession and Session.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(XrSession lhs,
                                                       Session const &rhs) {
  return lhs != rhs.get();
}
//! @brief Equality comparison between Session and nullptr: true if the handle
//! is null.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(Session const &lhs, std::nullptr_t /* unused */) {
  return lhs.get() == XR_NULL_HANDLE;
}
//! @brief Equality comparison between nullptr and Session: true if the handle
//! is null.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(std::nullptr_t /* unused */, Session const &rhs) {
  return rhs.get() == XR_NULL_HANDLE;
}
//! @brief Inequality comparison between Session and nullptr: true if the handle
//! is not null.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(Session const &lhs, std::nullptr_t /* unused */) {
  return lhs.get() != XR_NULL_HANDLE;
}
//! @brief Inequality comparison between nullptr and Session: true if the handle
//! is not null.
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(std::nullptr_t /* unused */, Session const &rhs) {
  return rhs.get() != XR_NULL_HANDLE;
}

//! @brief Free function accessor for the raw XrSession handle in a Session
//! @relates Session
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE XrSession get(Session const &h) {
  return h.get();
}

//! @brief Free "put" function for clearing and getting the address of the raw
//! XrSession handle in a Session (by reference).
//!
//! e.g.
//! ```
//! Session yourHandle;
//! auto result = d.xrCreateSession(..., put(yourHandle));
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the
//! namespace specified.
//! @relates Session
OPENXR_HPP_INLINE XrSession *put(Session &h) { return h.put(); }

//! @brief Free "put" function for clearing and getting the address of the raw
//! XrSession handle in a Session (by pointer).
//!
//! e.g.
//! ```
//! void yourFunction(Session* yourHandle) {
//!     auto result = d.xrCreateSession(..., put(yourHandle));
//!     ....
//! }
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the
//! namespace specified.
//! @relates Session
OPENXR_HPP_INLINE XrSession *put(Session *h) { return h->put(); }

namespace traits {
//! @brief Explicit specialization of cpp_type for Session
template <> struct cpp_type<ObjectType::Session> { using type = Session; };
} // namespace traits

#ifndef OPENXR_HPP_NO_SMART_HANDLE

namespace traits {
//! Traits associating a deleter type with handles of type Space
template <typename Dispatch> class UniqueHandleTraits<Space, Dispatch> {
public:
  using deleter = ObjectDestroy<Dispatch>;
};
} // namespace traits

//! @addtogroup unique_handle_aliases
//! @{

//! Shorthand name for unique handles of type Space, using a static dispatch.
using UniqueSpace = UniqueHandle<Space, DispatchLoaderStatic>;
//! Shorthand name for unique handles of type Space, using a dynamic dispatch.
using UniqueDynamicSpace = UniqueHandle<Space, DispatchLoaderDynamic>;
//! @}
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/

//! @brief Handle class - wrapping XrSpace
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrSpace>
//! @ingroup handles
class Space {
public:
  using Type = Space;
  using RawHandleType = XrSpace;

  /*!
   * @name Constructors, assignment, and conversions
   * @{
   */
  //! Default (empty/null) constructor
  OPENXR_HPP_CONSTEXPR Space() : m_raw(XR_NULL_HANDLE) {}

  //! Constructor from nullptr - creates empty/null handle.
  OPENXR_HPP_CONSTEXPR Space(std::nullptr_t /* unused */)
      : m_raw(XR_NULL_HANDLE) {}

  //! @brief Conversion constructor from the raw XrSpace type
  //!
  //! Explicit on 32-bit platforms by default unless
  //! OPENXR_HPP_TYPESAFE_CONVERSION is defined.
  OPENXR_HPP_TYPESAFE_EXPLICIT Space(RawHandleType handle) : m_raw(handle) {}

#if defined(OPENXR_HPP_TYPESAFE_CONVERSION)
  //! @brief Assignment operator from the raw XrSpace
  //!
  //! Does *not* destroy any contained non-null handle first! For that, see
  //! UniqueHandle<>.
  //!
  //! Only provided if OPENXR_HPP_TYPESAFE_CONVERSION is defined (defaults to
  //! only on 64-bit).
  Type &operator=(RawHandleType handle) {
    m_raw = handle;
    return *this;
  }
#endif

  //! @brief Assignment operator from nullptr - assigns to empty/null handle.
  //!
  //! Does *not* destroy any contained non-null handle first! For that, see
  //! UniqueHandle<>.
  Type &operator=(std::nullptr_t /* unused */) {
    m_raw = XR_NULL_HANDLE;
    return *this;
  }

  //! @brief Conversion operator to the raw XrSpace type
  //!
  //! Explicit on 32-bit platforms by default unless
  //! OPENXR_HPP_TYPESAFE_CONVERSION is defined.
  OPENXR_HPP_CONSTEXPR OPENXR_HPP_TYPESAFE_EXPLICIT
  operator RawHandleType() const {
    return m_raw;
  }

  //! @}

  /*!
   * @name Validity checking
   * @{
   */
  //! Returns true in conditionals if this handle is non-null
  OPENXR_HPP_CONSTEXPR explicit operator bool() const {
    return m_raw != XR_NULL_HANDLE;
  }

  //! Negation operator: true if this handle is null
  OPENXR_HPP_CONSTEXPR bool operator!() const {
    return m_raw == XR_NULL_HANDLE;
  }
  //! @}

  /*!
   * @name Raw handle manipulation
   * @{
   */
  //! @brief "Put" function for assigning as null then getting the address of
  //! the raw pointer to pass to creation functions.
  //!
  //! e.g.
  //! ```
  //! Space yourHandle;
  //! auto result = d.xrCreateSpace(..., yourHandle.put()));
  //! ```
  //!
  //! See also OPENXR_HPP_NAMESPACE::put()
  RawHandleType *put() {
    m_raw = XR_NULL_HANDLE;
    return &m_raw;
  }

  //! @brief Gets the raw handle type.
  //!
  //! See also OPENXR_HPP_NAMESPACE::get()
  OPENXR_HPP_CONSTEXPR RawHandleType get() const { return m_raw; }

  //! @}

  /*!
   * @name OpenXR API calls as member functions
   * @{
   */

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrLocateSpace wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrLocateSpace>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result locateSpace(Space baseSpace, XrTime time, XrSpaceLocation *location,
                     Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrLocateSpace wrapper - enhanced mode (hides basic wrapper unless
   * OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns Result (which may be Result::Success, or a non-Result::Success
   * success code)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns Result (which may be an error, Result::Success, or a
   * non-Result::Success success code).
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrLocateSpace>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result locateSpace(Space baseSpace, XrTime time, XrSpaceLocation *location,
                     Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrDestroySpace wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrDestroySpace>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result destroy(Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrDestroySpace wrapper - enhanced mode (hides basic wrapper unless
   * OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns nothing (void)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns Result.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrDestroySpace>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type destroy(Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @}
private:
  RawHandleType m_raw;
};
static_assert(sizeof(Space) == sizeof(XrSpace),
              "handle and wrapper have different size!");

//! @brief < comparison between Space.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(Space const &lhs,
                                                      Space const &rhs) {
  return lhs.get() < rhs.get();
}
//! @brief < comparison between Space and raw XrSpace.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(Space const &lhs,
                                                      XrSpace rhs) {
  return lhs.get() < rhs;
}
//! @brief < comparison between raw XrSpace and Space.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(XrSpace lhs,
                                                      Space const &rhs) {
  return lhs < rhs.get();
}
//! @brief > comparison between Space.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(Space const &lhs,
                                                      Space const &rhs) {
  return lhs.get() > rhs.get();
}
//! @brief > comparison between Space and raw XrSpace.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(Space const &lhs,
                                                      XrSpace rhs) {
  return lhs.get() > rhs;
}
//! @brief > comparison between raw XrSpace and Space.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(XrSpace lhs,
                                                      Space const &rhs) {
  return lhs > rhs.get();
}
//! @brief <= comparison between Space.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(Space const &lhs,
                                                       Space const &rhs) {
  return lhs.get() <= rhs.get();
}
//! @brief <= comparison between Space and raw XrSpace.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(Space const &lhs,
                                                       XrSpace rhs) {
  return lhs.get() <= rhs;
}
//! @brief <= comparison between raw XrSpace and Space.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(XrSpace lhs,
                                                       Space const &rhs) {
  return lhs <= rhs.get();
}
//! @brief >= comparison between Space.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(Space const &lhs,
                                                       Space const &rhs) {
  return lhs.get() >= rhs.get();
}
//! @brief >= comparison between Space and raw XrSpace.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(Space const &lhs,
                                                       XrSpace rhs) {
  return lhs.get() >= rhs;
}
//! @brief >= comparison between raw XrSpace and Space.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(XrSpace lhs,
                                                       Space const &rhs) {
  return lhs >= rhs.get();
}
//! @brief == comparison between Space.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(Space const &lhs,
                                                       Space const &rhs) {
  return lhs.get() == rhs.get();
}
//! @brief == comparison between Space and raw XrSpace.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(Space const &lhs,
                                                       XrSpace rhs) {
  return lhs.get() == rhs;
}
//! @brief == comparison between raw XrSpace and Space.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(XrSpace lhs,
                                                       Space const &rhs) {
  return lhs == rhs.get();
}
//! @brief != comparison between Space.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(Space const &lhs,
                                                       Space const &rhs) {
  return lhs.get() != rhs.get();
}
//! @brief != comparison between Space and raw XrSpace.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(Space const &lhs,
                                                       XrSpace rhs) {
  return lhs.get() != rhs;
}
//! @brief != comparison between raw XrSpace and Space.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(XrSpace lhs,
                                                       Space const &rhs) {
  return lhs != rhs.get();
}
//! @brief Equality comparison between Space and nullptr: true if the handle is
//! null.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(Space const &lhs, std::nullptr_t /* unused */) {
  return lhs.get() == XR_NULL_HANDLE;
}
//! @brief Equality comparison between nullptr and Space: true if the handle is
//! null.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(std::nullptr_t /* unused */, Space const &rhs) {
  return rhs.get() == XR_NULL_HANDLE;
}
//! @brief Inequality comparison between Space and nullptr: true if the handle
//! is not null.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(Space const &lhs, std::nullptr_t /* unused */) {
  return lhs.get() != XR_NULL_HANDLE;
}
//! @brief Inequality comparison between nullptr and Space: true if the handle
//! is not null.
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(std::nullptr_t /* unused */, Space const &rhs) {
  return rhs.get() != XR_NULL_HANDLE;
}

//! @brief Free function accessor for the raw XrSpace handle in a Space
//! @relates Space
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE XrSpace get(Space const &h) {
  return h.get();
}

//! @brief Free "put" function for clearing and getting the address of the raw
//! XrSpace handle in a Space (by reference).
//!
//! e.g.
//! ```
//! Space yourHandle;
//! auto result = d.xrCreateSpace(..., put(yourHandle));
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the
//! namespace specified.
//! @relates Space
OPENXR_HPP_INLINE XrSpace *put(Space &h) { return h.put(); }

//! @brief Free "put" function for clearing and getting the address of the raw
//! XrSpace handle in a Space (by pointer).
//!
//! e.g.
//! ```
//! void yourFunction(Space* yourHandle) {
//!     auto result = d.xrCreateSpace(..., put(yourHandle));
//!     ....
//! }
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the
//! namespace specified.
//! @relates Space
OPENXR_HPP_INLINE XrSpace *put(Space *h) { return h->put(); }

namespace traits {
//! @brief Explicit specialization of cpp_type for Space
template <> struct cpp_type<ObjectType::Space> { using type = Space; };
} // namespace traits

#ifndef OPENXR_HPP_NO_SMART_HANDLE

namespace traits {
//! Traits associating a deleter type with handles of type Action
template <typename Dispatch> class UniqueHandleTraits<Action, Dispatch> {
public:
  using deleter = ObjectDestroy<Dispatch>;
};
} // namespace traits

//! @addtogroup unique_handle_aliases
//! @{

//! Shorthand name for unique handles of type Action, using a static dispatch.
using UniqueAction = UniqueHandle<Action, DispatchLoaderStatic>;
//! Shorthand name for unique handles of type Action, using a dynamic dispatch.
using UniqueDynamicAction = UniqueHandle<Action, DispatchLoaderDynamic>;
//! @}
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/

//! @brief Handle class - wrapping XrAction
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrAction>
//! @ingroup handles
class Action {
public:
  using Type = Action;
  using RawHandleType = XrAction;

  /*!
   * @name Constructors, assignment, and conversions
   * @{
   */
  //! Default (empty/null) constructor
  OPENXR_HPP_CONSTEXPR Action() : m_raw(XR_NULL_HANDLE) {}

  //! Constructor from nullptr - creates empty/null handle.
  OPENXR_HPP_CONSTEXPR Action(std::nullptr_t /* unused */)
      : m_raw(XR_NULL_HANDLE) {}

  //! @brief Conversion constructor from the raw XrAction type
  //!
  //! Explicit on 32-bit platforms by default unless
  //! OPENXR_HPP_TYPESAFE_CONVERSION is defined.
  OPENXR_HPP_TYPESAFE_EXPLICIT Action(RawHandleType handle) : m_raw(handle) {}

#if defined(OPENXR_HPP_TYPESAFE_CONVERSION)
  //! @brief Assignment operator from the raw XrAction
  //!
  //! Does *not* destroy any contained non-null handle first! For that, see
  //! UniqueHandle<>.
  //!
  //! Only provided if OPENXR_HPP_TYPESAFE_CONVERSION is defined (defaults to
  //! only on 64-bit).
  Type &operator=(RawHandleType handle) {
    m_raw = handle;
    return *this;
  }
#endif

  //! @brief Assignment operator from nullptr - assigns to empty/null handle.
  //!
  //! Does *not* destroy any contained non-null handle first! For that, see
  //! UniqueHandle<>.
  Type &operator=(std::nullptr_t /* unused */) {
    m_raw = XR_NULL_HANDLE;
    return *this;
  }

  //! @brief Conversion operator to the raw XrAction type
  //!
  //! Explicit on 32-bit platforms by default unless
  //! OPENXR_HPP_TYPESAFE_CONVERSION is defined.
  OPENXR_HPP_CONSTEXPR OPENXR_HPP_TYPESAFE_EXPLICIT
  operator RawHandleType() const {
    return m_raw;
  }

  //! @}

  /*!
   * @name Validity checking
   * @{
   */
  //! Returns true in conditionals if this handle is non-null
  OPENXR_HPP_CONSTEXPR explicit operator bool() const {
    return m_raw != XR_NULL_HANDLE;
  }

  //! Negation operator: true if this handle is null
  OPENXR_HPP_CONSTEXPR bool operator!() const {
    return m_raw == XR_NULL_HANDLE;
  }
  //! @}

  /*!
   * @name Raw handle manipulation
   * @{
   */
  //! @brief "Put" function for assigning as null then getting the address of
  //! the raw pointer to pass to creation functions.
  //!
  //! e.g.
  //! ```
  //! Action yourHandle;
  //! auto result = d.xrCreateAction(..., yourHandle.put()));
  //! ```
  //!
  //! See also OPENXR_HPP_NAMESPACE::put()
  RawHandleType *put() {
    m_raw = XR_NULL_HANDLE;
    return &m_raw;
  }

  //! @brief Gets the raw handle type.
  //!
  //! See also OPENXR_HPP_NAMESPACE::get()
  OPENXR_HPP_CONSTEXPR RawHandleType get() const { return m_raw; }

  //! @}

  /*!
   * @name OpenXR API calls as member functions
   * @{
   */

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrDestroyAction wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrDestroyAction>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result destroy(Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrDestroyAction wrapper - enhanced mode (hides basic wrapper unless
   * OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns nothing (void)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns Result.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrDestroyAction>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type destroy(Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @}
private:
  RawHandleType m_raw;
};
static_assert(sizeof(Action) == sizeof(XrAction),
              "handle and wrapper have different size!");

//! @brief < comparison between Action.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(Action const &lhs,
                                                      Action const &rhs) {
  return lhs.get() < rhs.get();
}
//! @brief < comparison between Action and raw XrAction.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(Action const &lhs,
                                                      XrAction rhs) {
  return lhs.get() < rhs;
}
//! @brief < comparison between raw XrAction and Action.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(XrAction lhs,
                                                      Action const &rhs) {
  return lhs < rhs.get();
}
//! @brief > comparison between Action.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(Action const &lhs,
                                                      Action const &rhs) {
  return lhs.get() > rhs.get();
}
//! @brief > comparison between Action and raw XrAction.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(Action const &lhs,
                                                      XrAction rhs) {
  return lhs.get() > rhs;
}
//! @brief > comparison between raw XrAction and Action.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(XrAction lhs,
                                                      Action const &rhs) {
  return lhs > rhs.get();
}
//! @brief <= comparison between Action.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(Action const &lhs,
                                                       Action const &rhs) {
  return lhs.get() <= rhs.get();
}
//! @brief <= comparison between Action and raw XrAction.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(Action const &lhs,
                                                       XrAction rhs) {
  return lhs.get() <= rhs;
}
//! @brief <= comparison between raw XrAction and Action.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(XrAction lhs,
                                                       Action const &rhs) {
  return lhs <= rhs.get();
}
//! @brief >= comparison between Action.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(Action const &lhs,
                                                       Action const &rhs) {
  return lhs.get() >= rhs.get();
}
//! @brief >= comparison between Action and raw XrAction.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(Action const &lhs,
                                                       XrAction rhs) {
  return lhs.get() >= rhs;
}
//! @brief >= comparison between raw XrAction and Action.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(XrAction lhs,
                                                       Action const &rhs) {
  return lhs >= rhs.get();
}
//! @brief == comparison between Action.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(Action const &lhs,
                                                       Action const &rhs) {
  return lhs.get() == rhs.get();
}
//! @brief == comparison between Action and raw XrAction.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(Action const &lhs,
                                                       XrAction rhs) {
  return lhs.get() == rhs;
}
//! @brief == comparison between raw XrAction and Action.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(XrAction lhs,
                                                       Action const &rhs) {
  return lhs == rhs.get();
}
//! @brief != comparison between Action.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(Action const &lhs,
                                                       Action const &rhs) {
  return lhs.get() != rhs.get();
}
//! @brief != comparison between Action and raw XrAction.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(Action const &lhs,
                                                       XrAction rhs) {
  return lhs.get() != rhs;
}
//! @brief != comparison between raw XrAction and Action.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(XrAction lhs,
                                                       Action const &rhs) {
  return lhs != rhs.get();
}
//! @brief Equality comparison between Action and nullptr: true if the handle is
//! null.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(Action const &lhs, std::nullptr_t /* unused */) {
  return lhs.get() == XR_NULL_HANDLE;
}
//! @brief Equality comparison between nullptr and Action: true if the handle is
//! null.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(std::nullptr_t /* unused */, Action const &rhs) {
  return rhs.get() == XR_NULL_HANDLE;
}
//! @brief Inequality comparison between Action and nullptr: true if the handle
//! is not null.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(Action const &lhs, std::nullptr_t /* unused */) {
  return lhs.get() != XR_NULL_HANDLE;
}
//! @brief Inequality comparison between nullptr and Action: true if the handle
//! is not null.
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(std::nullptr_t /* unused */, Action const &rhs) {
  return rhs.get() != XR_NULL_HANDLE;
}

//! @brief Free function accessor for the raw XrAction handle in a Action
//! @relates Action
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE XrAction get(Action const &h) {
  return h.get();
}

//! @brief Free "put" function for clearing and getting the address of the raw
//! XrAction handle in a Action (by reference).
//!
//! e.g.
//! ```
//! Action yourHandle;
//! auto result = d.xrCreateAction(..., put(yourHandle));
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the
//! namespace specified.
//! @relates Action
OPENXR_HPP_INLINE XrAction *put(Action &h) { return h.put(); }

//! @brief Free "put" function for clearing and getting the address of the raw
//! XrAction handle in a Action (by pointer).
//!
//! e.g.
//! ```
//! void yourFunction(Action* yourHandle) {
//!     auto result = d.xrCreateAction(..., put(yourHandle));
//!     ....
//! }
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the
//! namespace specified.
//! @relates Action
OPENXR_HPP_INLINE XrAction *put(Action *h) { return h->put(); }

namespace traits {
//! @brief Explicit specialization of cpp_type for Action
template <> struct cpp_type<ObjectType::Action> { using type = Action; };
} // namespace traits

#ifndef OPENXR_HPP_NO_SMART_HANDLE

namespace traits {
//! Traits associating a deleter type with handles of type Swapchain
template <typename Dispatch> class UniqueHandleTraits<Swapchain, Dispatch> {
public:
  using deleter = ObjectDestroy<Dispatch>;
};
} // namespace traits

//! @addtogroup unique_handle_aliases
//! @{

//! Shorthand name for unique handles of type Swapchain, using a static
//! dispatch.
using UniqueSwapchain = UniqueHandle<Swapchain, DispatchLoaderStatic>;
//! Shorthand name for unique handles of type Swapchain, using a dynamic
//! dispatch.
using UniqueDynamicSwapchain = UniqueHandle<Swapchain, DispatchLoaderDynamic>;
//! @}
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/

//! @brief Handle class - wrapping XrSwapchain
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrSwapchain>
//! @ingroup handles
class Swapchain {
public:
  using Type = Swapchain;
  using RawHandleType = XrSwapchain;

  /*!
   * @name Constructors, assignment, and conversions
   * @{
   */
  //! Default (empty/null) constructor
  OPENXR_HPP_CONSTEXPR Swapchain() : m_raw(XR_NULL_HANDLE) {}

  //! Constructor from nullptr - creates empty/null handle.
  OPENXR_HPP_CONSTEXPR Swapchain(std::nullptr_t /* unused */)
      : m_raw(XR_NULL_HANDLE) {}

  //! @brief Conversion constructor from the raw XrSwapchain type
  //!
  //! Explicit on 32-bit platforms by default unless
  //! OPENXR_HPP_TYPESAFE_CONVERSION is defined.
  OPENXR_HPP_TYPESAFE_EXPLICIT Swapchain(RawHandleType handle)
      : m_raw(handle) {}

#if defined(OPENXR_HPP_TYPESAFE_CONVERSION)
  //! @brief Assignment operator from the raw XrSwapchain
  //!
  //! Does *not* destroy any contained non-null handle first! For that, see
  //! UniqueHandle<>.
  //!
  //! Only provided if OPENXR_HPP_TYPESAFE_CONVERSION is defined (defaults to
  //! only on 64-bit).
  Type &operator=(RawHandleType handle) {
    m_raw = handle;
    return *this;
  }
#endif

  //! @brief Assignment operator from nullptr - assigns to empty/null handle.
  //!
  //! Does *not* destroy any contained non-null handle first! For that, see
  //! UniqueHandle<>.
  Type &operator=(std::nullptr_t /* unused */) {
    m_raw = XR_NULL_HANDLE;
    return *this;
  }

  //! @brief Conversion operator to the raw XrSwapchain type
  //!
  //! Explicit on 32-bit platforms by default unless
  //! OPENXR_HPP_TYPESAFE_CONVERSION is defined.
  OPENXR_HPP_CONSTEXPR OPENXR_HPP_TYPESAFE_EXPLICIT
  operator RawHandleType() const {
    return m_raw;
  }

  //! @}

  /*!
   * @name Validity checking
   * @{
   */
  //! Returns true in conditionals if this handle is non-null
  OPENXR_HPP_CONSTEXPR explicit operator bool() const {
    return m_raw != XR_NULL_HANDLE;
  }

  //! Negation operator: true if this handle is null
  OPENXR_HPP_CONSTEXPR bool operator!() const {
    return m_raw == XR_NULL_HANDLE;
  }
  //! @}

  /*!
   * @name Raw handle manipulation
   * @{
   */
  //! @brief "Put" function for assigning as null then getting the address of
  //! the raw pointer to pass to creation functions.
  //!
  //! e.g.
  //! ```
  //! Swapchain yourHandle;
  //! auto result = d.xrCreateSwapchain(..., yourHandle.put()));
  //! ```
  //!
  //! See also OPENXR_HPP_NAMESPACE::put()
  RawHandleType *put() {
    m_raw = XR_NULL_HANDLE;
    return &m_raw;
  }

  //! @brief Gets the raw handle type.
  //!
  //! See also OPENXR_HPP_NAMESPACE::get()
  OPENXR_HPP_CONSTEXPR RawHandleType get() const { return m_raw; }

  //! @}

  /*!
   * @name OpenXR API calls as member functions
   * @{
   */

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrDestroySwapchain wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrDestroySwapchain>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result destroy(Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrDestroySwapchain wrapper - enhanced mode (hides basic wrapper
   * unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns nothing (void)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns Result.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrDestroySwapchain>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type destroy(Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrEnumerateSwapchainImages wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateSwapchainImages>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result enumerateSwapchainImages(uint32_t imageCapacityInput,
                                  uint32_t *imageCountOutput,
                                  XrSwapchainImageBaseHeader *images,
                                  Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrEnumerateSwapchainImages wrapper - enhanced mode (hides basic
   * wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns Result (which may be Result::Success, or a non-Result::Success
   * success code)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns Result (which may be an error, Result::Success, or a
   * non-Result::Success success code).
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateSwapchainImages>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result enumerateSwapchainImages(uint32_t imageCapacityInput,
                                  uint32_t *imageCountOutput,
                                  XrSwapchainImageBaseHeader *images,
                                  Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrAcquireSwapchainImage wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrAcquireSwapchainImage>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result acquireSwapchainImage(const XrSwapchainImageAcquireInfo *acquireInfo,
                               uint32_t *index,
                               Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrAcquireSwapchainImage wrapper - enhanced mode (hides basic wrapper
   * unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns Result (which may be Result::Success, or a non-Result::Success
   * success code)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns Result (which may be an error, Result::Success, or a
   * non-Result::Success success code).
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrAcquireSwapchainImage>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result acquireSwapchainImage(const XrSwapchainImageAcquireInfo *acquireInfo,
                               uint32_t *index,
                               Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrWaitSwapchainImage wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrWaitSwapchainImage>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result waitSwapchainImage(const XrSwapchainImageWaitInfo *waitInfo,
                            Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrWaitSwapchainImage wrapper - enhanced mode (hides basic wrapper
   * unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns Result (which may be Result::Success, or a non-Result::Success
   * success code)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns Result (which may be an error, Result::Success, or a
   * non-Result::Success success code).
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrWaitSwapchainImage>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result waitSwapchainImage(const XrSwapchainImageWaitInfo *waitInfo,
                            Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrReleaseSwapchainImage wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrReleaseSwapchainImage>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result releaseSwapchainImage(const XrSwapchainImageReleaseInfo *releaseInfo,
                               Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrReleaseSwapchainImage wrapper - enhanced mode (hides basic wrapper
   * unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns Result (which may be Result::Success, or a non-Result::Success
   * success code)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is one of the expected success codes.
   * - Returns Result (which may be an error, Result::Success, or a
   * non-Result::Success success code).
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrReleaseSwapchainImage>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result releaseSwapchainImage(const XrSwapchainImageReleaseInfo *releaseInfo,
                               Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @}
private:
  RawHandleType m_raw;
};
static_assert(sizeof(Swapchain) == sizeof(XrSwapchain),
              "handle and wrapper have different size!");

//! @brief < comparison between Swapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(Swapchain const &lhs,
                                                      Swapchain const &rhs) {
  return lhs.get() < rhs.get();
}
//! @brief < comparison between Swapchain and raw XrSwapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(Swapchain const &lhs,
                                                      XrSwapchain rhs) {
  return lhs.get() < rhs;
}
//! @brief < comparison between raw XrSwapchain and Swapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(XrSwapchain lhs,
                                                      Swapchain const &rhs) {
  return lhs < rhs.get();
}
//! @brief > comparison between Swapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(Swapchain const &lhs,
                                                      Swapchain const &rhs) {
  return lhs.get() > rhs.get();
}
//! @brief > comparison between Swapchain and raw XrSwapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(Swapchain const &lhs,
                                                      XrSwapchain rhs) {
  return lhs.get() > rhs;
}
//! @brief > comparison between raw XrSwapchain and Swapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(XrSwapchain lhs,
                                                      Swapchain const &rhs) {
  return lhs > rhs.get();
}
//! @brief <= comparison between Swapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(Swapchain const &lhs,
                                                       Swapchain const &rhs) {
  return lhs.get() <= rhs.get();
}
//! @brief <= comparison between Swapchain and raw XrSwapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(Swapchain const &lhs,
                                                       XrSwapchain rhs) {
  return lhs.get() <= rhs;
}
//! @brief <= comparison between raw XrSwapchain and Swapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(XrSwapchain lhs,
                                                       Swapchain const &rhs) {
  return lhs <= rhs.get();
}
//! @brief >= comparison between Swapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(Swapchain const &lhs,
                                                       Swapchain const &rhs) {
  return lhs.get() >= rhs.get();
}
//! @brief >= comparison between Swapchain and raw XrSwapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(Swapchain const &lhs,
                                                       XrSwapchain rhs) {
  return lhs.get() >= rhs;
}
//! @brief >= comparison between raw XrSwapchain and Swapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(XrSwapchain lhs,
                                                       Swapchain const &rhs) {
  return lhs >= rhs.get();
}
//! @brief == comparison between Swapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(Swapchain const &lhs,
                                                       Swapchain const &rhs) {
  return lhs.get() == rhs.get();
}
//! @brief == comparison between Swapchain and raw XrSwapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(Swapchain const &lhs,
                                                       XrSwapchain rhs) {
  return lhs.get() == rhs;
}
//! @brief == comparison between raw XrSwapchain and Swapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(XrSwapchain lhs,
                                                       Swapchain const &rhs) {
  return lhs == rhs.get();
}
//! @brief != comparison between Swapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(Swapchain const &lhs,
                                                       Swapchain const &rhs) {
  return lhs.get() != rhs.get();
}
//! @brief != comparison between Swapchain and raw XrSwapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(Swapchain const &lhs,
                                                       XrSwapchain rhs) {
  return lhs.get() != rhs;
}
//! @brief != comparison between raw XrSwapchain and Swapchain.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(XrSwapchain lhs,
                                                       Swapchain const &rhs) {
  return lhs != rhs.get();
}
//! @brief Equality comparison between Swapchain and nullptr: true if the handle
//! is null.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(Swapchain const &lhs, std::nullptr_t /* unused */) {
  return lhs.get() == XR_NULL_HANDLE;
}
//! @brief Equality comparison between nullptr and Swapchain: true if the handle
//! is null.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(std::nullptr_t /* unused */, Swapchain const &rhs) {
  return rhs.get() == XR_NULL_HANDLE;
}
//! @brief Inequality comparison between Swapchain and nullptr: true if the
//! handle is not null.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(Swapchain const &lhs, std::nullptr_t /* unused */) {
  return lhs.get() != XR_NULL_HANDLE;
}
//! @brief Inequality comparison between nullptr and Swapchain: true if the
//! handle is not null.
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(std::nullptr_t /* unused */, Swapchain const &rhs) {
  return rhs.get() != XR_NULL_HANDLE;
}

//! @brief Free function accessor for the raw XrSwapchain handle in a Swapchain
//! @relates Swapchain
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE XrSwapchain get(Swapchain const &h) {
  return h.get();
}

//! @brief Free "put" function for clearing and getting the address of the raw
//! XrSwapchain handle in a Swapchain (by reference).
//!
//! e.g.
//! ```
//! Swapchain yourHandle;
//! auto result = d.xrCreateSwapchain(..., put(yourHandle));
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the
//! namespace specified.
//! @relates Swapchain
OPENXR_HPP_INLINE XrSwapchain *put(Swapchain &h) { return h.put(); }

//! @brief Free "put" function for clearing and getting the address of the raw
//! XrSwapchain handle in a Swapchain (by pointer).
//!
//! e.g.
//! ```
//! void yourFunction(Swapchain* yourHandle) {
//!     auto result = d.xrCreateSwapchain(..., put(yourHandle));
//!     ....
//! }
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the
//! namespace specified.
//! @relates Swapchain
OPENXR_HPP_INLINE XrSwapchain *put(Swapchain *h) { return h->put(); }

namespace traits {
//! @brief Explicit specialization of cpp_type for Swapchain
template <> struct cpp_type<ObjectType::Swapchain> { using type = Swapchain; };
} // namespace traits

#ifndef OPENXR_HPP_NO_SMART_HANDLE

namespace traits {
//! Traits associating a deleter type with handles of type ActionSet
template <typename Dispatch> class UniqueHandleTraits<ActionSet, Dispatch> {
public:
  using deleter = ObjectDestroy<Dispatch>;
};
} // namespace traits

//! @addtogroup unique_handle_aliases
//! @{

//! Shorthand name for unique handles of type ActionSet, using a static
//! dispatch.
using UniqueActionSet = UniqueHandle<ActionSet, DispatchLoaderStatic>;
//! Shorthand name for unique handles of type ActionSet, using a dynamic
//! dispatch.
using UniqueDynamicActionSet = UniqueHandle<ActionSet, DispatchLoaderDynamic>;
//! @}
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/

//! @brief Handle class - wrapping XrActionSet
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrActionSet>
//! @ingroup handles
class ActionSet {
public:
  using Type = ActionSet;
  using RawHandleType = XrActionSet;

  /*!
   * @name Constructors, assignment, and conversions
   * @{
   */
  //! Default (empty/null) constructor
  OPENXR_HPP_CONSTEXPR ActionSet() : m_raw(XR_NULL_HANDLE) {}

  //! Constructor from nullptr - creates empty/null handle.
  OPENXR_HPP_CONSTEXPR ActionSet(std::nullptr_t /* unused */)
      : m_raw(XR_NULL_HANDLE) {}

  //! @brief Conversion constructor from the raw XrActionSet type
  //!
  //! Explicit on 32-bit platforms by default unless
  //! OPENXR_HPP_TYPESAFE_CONVERSION is defined.
  OPENXR_HPP_TYPESAFE_EXPLICIT ActionSet(RawHandleType handle)
      : m_raw(handle) {}

#if defined(OPENXR_HPP_TYPESAFE_CONVERSION)
  //! @brief Assignment operator from the raw XrActionSet
  //!
  //! Does *not* destroy any contained non-null handle first! For that, see
  //! UniqueHandle<>.
  //!
  //! Only provided if OPENXR_HPP_TYPESAFE_CONVERSION is defined (defaults to
  //! only on 64-bit).
  Type &operator=(RawHandleType handle) {
    m_raw = handle;
    return *this;
  }
#endif

  //! @brief Assignment operator from nullptr - assigns to empty/null handle.
  //!
  //! Does *not* destroy any contained non-null handle first! For that, see
  //! UniqueHandle<>.
  Type &operator=(std::nullptr_t /* unused */) {
    m_raw = XR_NULL_HANDLE;
    return *this;
  }

  //! @brief Conversion operator to the raw XrActionSet type
  //!
  //! Explicit on 32-bit platforms by default unless
  //! OPENXR_HPP_TYPESAFE_CONVERSION is defined.
  OPENXR_HPP_CONSTEXPR OPENXR_HPP_TYPESAFE_EXPLICIT
  operator RawHandleType() const {
    return m_raw;
  }

  //! @}

  /*!
   * @name Validity checking
   * @{
   */
  //! Returns true in conditionals if this handle is non-null
  OPENXR_HPP_CONSTEXPR explicit operator bool() const {
    return m_raw != XR_NULL_HANDLE;
  }

  //! Negation operator: true if this handle is null
  OPENXR_HPP_CONSTEXPR bool operator!() const {
    return m_raw == XR_NULL_HANDLE;
  }
  //! @}

  /*!
   * @name Raw handle manipulation
   * @{
   */
  //! @brief "Put" function for assigning as null then getting the address of
  //! the raw pointer to pass to creation functions.
  //!
  //! e.g.
  //! ```
  //! ActionSet yourHandle;
  //! auto result = d.xrCreateActionSet(..., yourHandle.put()));
  //! ```
  //!
  //! See also OPENXR_HPP_NAMESPACE::put()
  RawHandleType *put() {
    m_raw = XR_NULL_HANDLE;
    return &m_raw;
  }

  //! @brief Gets the raw handle type.
  //!
  //! See also OPENXR_HPP_NAMESPACE::get()
  OPENXR_HPP_CONSTEXPR RawHandleType get() const { return m_raw; }

  //! @}

  /*!
   * @name OpenXR API calls as member functions
   * @{
   */

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrDestroyActionSet wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrDestroyActionSet>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result destroy(Dispatch &&d = Dispatch{}) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrDestroyActionSet wrapper - enhanced mode (hides basic wrapper
   * unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns nothing (void)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns Result.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrDestroyActionSet>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  ResultValueType<void>::type destroy(Dispatch &&d = Dispatch{}) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  /*!
   * @brief xrCreateAction wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateAction>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  Result createAction(const XrActionCreateInfo *createInfo, Action &action,
                      Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrCreateAction wrapper - enhanced mode.    //!
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns the value of type Action
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns the output of type Action.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateAction>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<Action>::type
  createAction(const XrActionCreateInfo *createInfo,
               Dispatch &&d = Dispatch{}) const;

#ifndef OPENXR_HPP_NO_SMART_HANDLE

  /*!
   * @brief xrCreateAction wrapper returning a smart handle.
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns the value of type UniqueHandle<Action,
   * impl::RemoveRefConst<Dispatch>>
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns the output of type UniqueHandle<Action,
   * impl::RemoveRefConst<Dispatch>>.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateAction>
   */
  template <typename Dispatch = DispatchLoaderStatic>
  typename ResultValueType<
      UniqueHandle<Action, impl::RemoveRefConst<Dispatch>>>::type
  createActionUnique(const XrActionCreateInfo *createInfo,
                     Dispatch &&d = Dispatch{}) const;
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @}
private:
  RawHandleType m_raw;
};
static_assert(sizeof(ActionSet) == sizeof(XrActionSet),
              "handle and wrapper have different size!");

//! @brief < comparison between ActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(ActionSet const &lhs,
                                                      ActionSet const &rhs) {
  return lhs.get() < rhs.get();
}
//! @brief < comparison between ActionSet and raw XrActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(ActionSet const &lhs,
                                                      XrActionSet rhs) {
  return lhs.get() < rhs;
}
//! @brief < comparison between raw XrActionSet and ActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(XrActionSet lhs,
                                                      ActionSet const &rhs) {
  return lhs < rhs.get();
}
//! @brief > comparison between ActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(ActionSet const &lhs,
                                                      ActionSet const &rhs) {
  return lhs.get() > rhs.get();
}
//! @brief > comparison between ActionSet and raw XrActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(ActionSet const &lhs,
                                                      XrActionSet rhs) {
  return lhs.get() > rhs;
}
//! @brief > comparison between raw XrActionSet and ActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(XrActionSet lhs,
                                                      ActionSet const &rhs) {
  return lhs > rhs.get();
}
//! @brief <= comparison between ActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(ActionSet const &lhs,
                                                       ActionSet const &rhs) {
  return lhs.get() <= rhs.get();
}
//! @brief <= comparison between ActionSet and raw XrActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(ActionSet const &lhs,
                                                       XrActionSet rhs) {
  return lhs.get() <= rhs;
}
//! @brief <= comparison between raw XrActionSet and ActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(XrActionSet lhs,
                                                       ActionSet const &rhs) {
  return lhs <= rhs.get();
}
//! @brief >= comparison between ActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(ActionSet const &lhs,
                                                       ActionSet const &rhs) {
  return lhs.get() >= rhs.get();
}
//! @brief >= comparison between ActionSet and raw XrActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(ActionSet const &lhs,
                                                       XrActionSet rhs) {
  return lhs.get() >= rhs;
}
//! @brief >= comparison between raw XrActionSet and ActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(XrActionSet lhs,
                                                       ActionSet const &rhs) {
  return lhs >= rhs.get();
}
//! @brief == comparison between ActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(ActionSet const &lhs,
                                                       ActionSet const &rhs) {
  return lhs.get() == rhs.get();
}
//! @brief == comparison between ActionSet and raw XrActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(ActionSet const &lhs,
                                                       XrActionSet rhs) {
  return lhs.get() == rhs;
}
//! @brief == comparison between raw XrActionSet and ActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(XrActionSet lhs,
                                                       ActionSet const &rhs) {
  return lhs == rhs.get();
}
//! @brief != comparison between ActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(ActionSet const &lhs,
                                                       ActionSet const &rhs) {
  return lhs.get() != rhs.get();
}
//! @brief != comparison between ActionSet and raw XrActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(ActionSet const &lhs,
                                                       XrActionSet rhs) {
  return lhs.get() != rhs;
}
//! @brief != comparison between raw XrActionSet and ActionSet.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(XrActionSet lhs,
                                                       ActionSet const &rhs) {
  return lhs != rhs.get();
}
//! @brief Equality comparison between ActionSet and nullptr: true if the handle
//! is null.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(ActionSet const &lhs, std::nullptr_t /* unused */) {
  return lhs.get() == XR_NULL_HANDLE;
}
//! @brief Equality comparison between nullptr and ActionSet: true if the handle
//! is null.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(std::nullptr_t /* unused */, ActionSet const &rhs) {
  return rhs.get() == XR_NULL_HANDLE;
}
//! @brief Inequality comparison between ActionSet and nullptr: true if the
//! handle is not null.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(ActionSet const &lhs, std::nullptr_t /* unused */) {
  return lhs.get() != XR_NULL_HANDLE;
}
//! @brief Inequality comparison between nullptr and ActionSet: true if the
//! handle is not null.
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(std::nullptr_t /* unused */, ActionSet const &rhs) {
  return rhs.get() != XR_NULL_HANDLE;
}

//! @brief Free function accessor for the raw XrActionSet handle in a ActionSet
//! @relates ActionSet
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE XrActionSet get(ActionSet const &h) {
  return h.get();
}

//! @brief Free "put" function for clearing and getting the address of the raw
//! XrActionSet handle in a ActionSet (by reference).
//!
//! e.g.
//! ```
//! ActionSet yourHandle;
//! auto result = d.xrCreateActionSet(..., put(yourHandle));
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the
//! namespace specified.
//! @relates ActionSet
OPENXR_HPP_INLINE XrActionSet *put(ActionSet &h) { return h.put(); }

//! @brief Free "put" function for clearing and getting the address of the raw
//! XrActionSet handle in a ActionSet (by pointer).
//!
//! e.g.
//! ```
//! void yourFunction(ActionSet* yourHandle) {
//!     auto result = d.xrCreateActionSet(..., put(yourHandle));
//!     ....
//! }
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the
//! namespace specified.
//! @relates ActionSet
OPENXR_HPP_INLINE XrActionSet *put(ActionSet *h) { return h->put(); }

namespace traits {
//! @brief Explicit specialization of cpp_type for ActionSet
template <> struct cpp_type<ObjectType::ActionSet> { using type = ActionSet; };
} // namespace traits

#ifndef OPENXR_HPP_NO_SMART_HANDLE

namespace traits {
//! Traits associating a deleter type with handles of type
//! DebugUtilsMessengerEXT
template <typename Dispatch>
class UniqueHandleTraits<DebugUtilsMessengerEXT, Dispatch> {
public:
  using deleter = ObjectDestroy<Dispatch>;
};
} // namespace traits

//! @addtogroup unique_handle_aliases
//! @{

//! Shorthand name for unique handles of type DebugUtilsMessengerEXT, using a
//! static dispatch.
using UniqueDebugUtilsMessengerEXT =
    UniqueHandle<DebugUtilsMessengerEXT, DispatchLoaderStatic>;
//! Shorthand name for unique handles of type DebugUtilsMessengerEXT, using a
//! dynamic dispatch.
using UniqueDynamicDebugUtilsMessengerEXT =
    UniqueHandle<DebugUtilsMessengerEXT, DispatchLoaderDynamic>;
//! @}
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/

//! @brief Handle class - wrapping XrDebugUtilsMessengerEXT
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrDebugUtilsMessengerEXT>
//! @ingroup handles
class DebugUtilsMessengerEXT {
public:
  using Type = DebugUtilsMessengerEXT;
  using RawHandleType = XrDebugUtilsMessengerEXT;

  /*!
   * @name Constructors, assignment, and conversions
   * @{
   */
  //! Default (empty/null) constructor
  OPENXR_HPP_CONSTEXPR DebugUtilsMessengerEXT() : m_raw(XR_NULL_HANDLE) {}

  //! Constructor from nullptr - creates empty/null handle.
  OPENXR_HPP_CONSTEXPR DebugUtilsMessengerEXT(std::nullptr_t /* unused */)
      : m_raw(XR_NULL_HANDLE) {}

  //! @brief Conversion constructor from the raw XrDebugUtilsMessengerEXT type
  //!
  //! Explicit on 32-bit platforms by default unless
  //! OPENXR_HPP_TYPESAFE_CONVERSION is defined.
  OPENXR_HPP_TYPESAFE_EXPLICIT DebugUtilsMessengerEXT(RawHandleType handle)
      : m_raw(handle) {}

#if defined(OPENXR_HPP_TYPESAFE_CONVERSION)
  //! @brief Assignment operator from the raw XrDebugUtilsMessengerEXT
  //!
  //! Does *not* destroy any contained non-null handle first! For that, see
  //! UniqueHandle<>.
  //!
  //! Only provided if OPENXR_HPP_TYPESAFE_CONVERSION is defined (defaults to
  //! only on 64-bit).
  Type &operator=(RawHandleType handle) {
    m_raw = handle;
    return *this;
  }
#endif

  //! @brief Assignment operator from nullptr - assigns to empty/null handle.
  //!
  //! Does *not* destroy any contained non-null handle first! For that, see
  //! UniqueHandle<>.
  Type &operator=(std::nullptr_t /* unused */) {
    m_raw = XR_NULL_HANDLE;
    return *this;
  }

  //! @brief Conversion operator to the raw XrDebugUtilsMessengerEXT type
  //!
  //! Explicit on 32-bit platforms by default unless
  //! OPENXR_HPP_TYPESAFE_CONVERSION is defined.
  OPENXR_HPP_CONSTEXPR OPENXR_HPP_TYPESAFE_EXPLICIT
  operator RawHandleType() const {
    return m_raw;
  }

  //! @}

  /*!
   * @name Validity checking
   * @{
   */
  //! Returns true in conditionals if this handle is non-null
  OPENXR_HPP_CONSTEXPR explicit operator bool() const {
    return m_raw != XR_NULL_HANDLE;
  }

  //! Negation operator: true if this handle is null
  OPENXR_HPP_CONSTEXPR bool operator!() const {
    return m_raw == XR_NULL_HANDLE;
  }
  //! @}

  /*!
   * @name Raw handle manipulation
   * @{
   */
  //! @brief "Put" function for assigning as null then getting the address of
  //! the raw pointer to pass to creation functions.
  //!
  //! e.g.
  //! ```
  //! DebugUtilsMessengerEXT yourHandle;
  //! auto result = d.xrCreateDebugUtilsMessengerEXT(..., yourHandle.put()));
  //! ```
  //!
  //! See also OPENXR_HPP_NAMESPACE::put()
  RawHandleType *put() {
    m_raw = XR_NULL_HANDLE;
    return &m_raw;
  }

  //! @brief Gets the raw handle type.
  //!
  //! See also OPENXR_HPP_NAMESPACE::get()
  OPENXR_HPP_CONSTEXPR RawHandleType get() const { return m_raw; }

  //! @}

  /*!
   * @name OpenXR API calls as member functions
   * @{
   */

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrDestroyDebugUtilsMessengerEXT wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrDestroyDebugUtilsMessengerEXT>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result destroy(Dispatch &&d) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrDestroyDebugUtilsMessengerEXT wrapper - enhanced mode (hides basic
   * wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns nothing (void)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns Result.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrDestroyDebugUtilsMessengerEXT>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  ResultValueType<void>::type destroy(Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @}
private:
  RawHandleType m_raw;
};
static_assert(sizeof(DebugUtilsMessengerEXT) ==
                  sizeof(XrDebugUtilsMessengerEXT),
              "handle and wrapper have different size!");

//! @brief < comparison between DebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator<(DebugUtilsMessengerEXT const &lhs,
          DebugUtilsMessengerEXT const &rhs) {
  return lhs.get() < rhs.get();
}
//! @brief < comparison between DebugUtilsMessengerEXT and raw
//! XrDebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator<(DebugUtilsMessengerEXT const &lhs, XrDebugUtilsMessengerEXT rhs) {
  return lhs.get() < rhs;
}
//! @brief < comparison between raw XrDebugUtilsMessengerEXT and
//! DebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator<(XrDebugUtilsMessengerEXT lhs, DebugUtilsMessengerEXT const &rhs) {
  return lhs < rhs.get();
}
//! @brief > comparison between DebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator>(DebugUtilsMessengerEXT const &lhs,
          DebugUtilsMessengerEXT const &rhs) {
  return lhs.get() > rhs.get();
}
//! @brief > comparison between DebugUtilsMessengerEXT and raw
//! XrDebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator>(DebugUtilsMessengerEXT const &lhs, XrDebugUtilsMessengerEXT rhs) {
  return lhs.get() > rhs;
}
//! @brief > comparison between raw XrDebugUtilsMessengerEXT and
//! DebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator>(XrDebugUtilsMessengerEXT lhs, DebugUtilsMessengerEXT const &rhs) {
  return lhs > rhs.get();
}
//! @brief <= comparison between DebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator<=(DebugUtilsMessengerEXT const &lhs,
           DebugUtilsMessengerEXT const &rhs) {
  return lhs.get() <= rhs.get();
}
//! @brief <= comparison between DebugUtilsMessengerEXT and raw
//! XrDebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator<=(DebugUtilsMessengerEXT const &lhs, XrDebugUtilsMessengerEXT rhs) {
  return lhs.get() <= rhs;
}
//! @brief <= comparison between raw XrDebugUtilsMessengerEXT and
//! DebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator<=(XrDebugUtilsMessengerEXT lhs, DebugUtilsMessengerEXT const &rhs) {
  return lhs <= rhs.get();
}
//! @brief >= comparison between DebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator>=(DebugUtilsMessengerEXT const &lhs,
           DebugUtilsMessengerEXT const &rhs) {
  return lhs.get() >= rhs.get();
}
//! @brief >= comparison between DebugUtilsMessengerEXT and raw
//! XrDebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator>=(DebugUtilsMessengerEXT const &lhs, XrDebugUtilsMessengerEXT rhs) {
  return lhs.get() >= rhs;
}
//! @brief >= comparison between raw XrDebugUtilsMessengerEXT and
//! DebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator>=(XrDebugUtilsMessengerEXT lhs, DebugUtilsMessengerEXT const &rhs) {
  return lhs >= rhs.get();
}
//! @brief == comparison between DebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(DebugUtilsMessengerEXT const &lhs,
           DebugUtilsMessengerEXT const &rhs) {
  return lhs.get() == rhs.get();
}
//! @brief == comparison between DebugUtilsMessengerEXT and raw
//! XrDebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(DebugUtilsMessengerEXT const &lhs, XrDebugUtilsMessengerEXT rhs) {
  return lhs.get() == rhs;
}
//! @brief == comparison between raw XrDebugUtilsMessengerEXT and
//! DebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(XrDebugUtilsMessengerEXT lhs, DebugUtilsMessengerEXT const &rhs) {
  return lhs == rhs.get();
}
//! @brief != comparison between DebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(DebugUtilsMessengerEXT const &lhs,
           DebugUtilsMessengerEXT const &rhs) {
  return lhs.get() != rhs.get();
}
//! @brief != comparison between DebugUtilsMessengerEXT and raw
//! XrDebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(DebugUtilsMessengerEXT const &lhs, XrDebugUtilsMessengerEXT rhs) {
  return lhs.get() != rhs;
}
//! @brief != comparison between raw XrDebugUtilsMessengerEXT and
//! DebugUtilsMessengerEXT.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(XrDebugUtilsMessengerEXT lhs, DebugUtilsMessengerEXT const &rhs) {
  return lhs != rhs.get();
}
//! @brief Equality comparison between DebugUtilsMessengerEXT and nullptr: true
//! if the handle is null.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(DebugUtilsMessengerEXT const &lhs, std::nullptr_t /* unused */) {
  return lhs.get() == XR_NULL_HANDLE;
}
//! @brief Equality comparison between nullptr and DebugUtilsMessengerEXT: true
//! if the handle is null.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(std::nullptr_t /* unused */, DebugUtilsMessengerEXT const &rhs) {
  return rhs.get() == XR_NULL_HANDLE;
}
//! @brief Inequality comparison between DebugUtilsMessengerEXT and nullptr:
//! true if the handle is not null.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(DebugUtilsMessengerEXT const &lhs, std::nullptr_t /* unused */) {
  return lhs.get() != XR_NULL_HANDLE;
}
//! @brief Inequality comparison between nullptr and DebugUtilsMessengerEXT:
//! true if the handle is not null.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(std::nullptr_t /* unused */, DebugUtilsMessengerEXT const &rhs) {
  return rhs.get() != XR_NULL_HANDLE;
}

//! @brief Free function accessor for the raw XrDebugUtilsMessengerEXT handle in
//! a DebugUtilsMessengerEXT
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE XrDebugUtilsMessengerEXT
get(DebugUtilsMessengerEXT const &h) {
  return h.get();
}

//! @brief Free "put" function for clearing and getting the address of the raw
//! XrDebugUtilsMessengerEXT handle in a DebugUtilsMessengerEXT (by reference).
//!
//! e.g.
//! ```
//! DebugUtilsMessengerEXT yourHandle;
//! auto result = d.xrCreateDebugUtilsMessengerEXT(..., put(yourHandle));
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the
//! namespace specified.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_INLINE XrDebugUtilsMessengerEXT *put(DebugUtilsMessengerEXT &h) {
  return h.put();
}

//! @brief Free "put" function for clearing and getting the address of the raw
//! XrDebugUtilsMessengerEXT handle in a DebugUtilsMessengerEXT (by pointer).
//!
//! e.g.
//! ```
//! void yourFunction(DebugUtilsMessengerEXT* yourHandle) {
//!     auto result = d.xrCreateDebugUtilsMessengerEXT(..., put(yourHandle));
//!     ....
//! }
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the
//! namespace specified.
//! @relates DebugUtilsMessengerEXT
OPENXR_HPP_INLINE XrDebugUtilsMessengerEXT *put(DebugUtilsMessengerEXT *h) {
  return h->put();
}

namespace traits {
//! @brief Explicit specialization of cpp_type for DebugUtilsMessengerEXT
template <> struct cpp_type<ObjectType::DebugUtilsMessengerEXT> {
  using type = DebugUtilsMessengerEXT;
};
} // namespace traits

#ifndef OPENXR_HPP_NO_SMART_HANDLE

namespace traits {
//! Traits associating a deleter type with handles of type SpatialAnchorMSFT
template <typename Dispatch>
class UniqueHandleTraits<SpatialAnchorMSFT, Dispatch> {
public:
  using deleter = ObjectDestroy<Dispatch>;
};
} // namespace traits

//! @addtogroup unique_handle_aliases
//! @{

//! Shorthand name for unique handles of type SpatialAnchorMSFT, using a static
//! dispatch.
using UniqueSpatialAnchorMSFT =
    UniqueHandle<SpatialAnchorMSFT, DispatchLoaderStatic>;
//! Shorthand name for unique handles of type SpatialAnchorMSFT, using a dynamic
//! dispatch.
using UniqueDynamicSpatialAnchorMSFT =
    UniqueHandle<SpatialAnchorMSFT, DispatchLoaderDynamic>;
//! @}
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/

//! @brief Handle class - wrapping XrSpatialAnchorMSFT
//!
//! See the related specification text at
//! <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrSpatialAnchorMSFT>
//! @ingroup handles
class SpatialAnchorMSFT {
public:
  using Type = SpatialAnchorMSFT;
  using RawHandleType = XrSpatialAnchorMSFT;

  /*!
   * @name Constructors, assignment, and conversions
   * @{
   */
  //! Default (empty/null) constructor
  OPENXR_HPP_CONSTEXPR SpatialAnchorMSFT() : m_raw(XR_NULL_HANDLE) {}

  //! Constructor from nullptr - creates empty/null handle.
  OPENXR_HPP_CONSTEXPR SpatialAnchorMSFT(std::nullptr_t /* unused */)
      : m_raw(XR_NULL_HANDLE) {}

  //! @brief Conversion constructor from the raw XrSpatialAnchorMSFT type
  //!
  //! Explicit on 32-bit platforms by default unless
  //! OPENXR_HPP_TYPESAFE_CONVERSION is defined.
  OPENXR_HPP_TYPESAFE_EXPLICIT SpatialAnchorMSFT(RawHandleType handle)
      : m_raw(handle) {}

#if defined(OPENXR_HPP_TYPESAFE_CONVERSION)
  //! @brief Assignment operator from the raw XrSpatialAnchorMSFT
  //!
  //! Does *not* destroy any contained non-null handle first! For that, see
  //! UniqueHandle<>.
  //!
  //! Only provided if OPENXR_HPP_TYPESAFE_CONVERSION is defined (defaults to
  //! only on 64-bit).
  Type &operator=(RawHandleType handle) {
    m_raw = handle;
    return *this;
  }
#endif

  //! @brief Assignment operator from nullptr - assigns to empty/null handle.
  //!
  //! Does *not* destroy any contained non-null handle first! For that, see
  //! UniqueHandle<>.
  Type &operator=(std::nullptr_t /* unused */) {
    m_raw = XR_NULL_HANDLE;
    return *this;
  }

  //! @brief Conversion operator to the raw XrSpatialAnchorMSFT type
  //!
  //! Explicit on 32-bit platforms by default unless
  //! OPENXR_HPP_TYPESAFE_CONVERSION is defined.
  OPENXR_HPP_CONSTEXPR OPENXR_HPP_TYPESAFE_EXPLICIT
  operator RawHandleType() const {
    return m_raw;
  }

  //! @}

  /*!
   * @name Validity checking
   * @{
   */
  //! Returns true in conditionals if this handle is non-null
  OPENXR_HPP_CONSTEXPR explicit operator bool() const {
    return m_raw != XR_NULL_HANDLE;
  }

  //! Negation operator: true if this handle is null
  OPENXR_HPP_CONSTEXPR bool operator!() const {
    return m_raw == XR_NULL_HANDLE;
  }
  //! @}

  /*!
   * @name Raw handle manipulation
   * @{
   */
  //! @brief "Put" function for assigning as null then getting the address of
  //! the raw pointer to pass to creation functions.
  //!
  //! e.g.
  //! ```
  //! SpatialAnchorMSFT yourHandle;
  //! auto result = d.xrCreateSpatialAnchorMSFT(..., yourHandle.put()));
  //! ```
  //!
  //! See also OPENXR_HPP_NAMESPACE::put()
  RawHandleType *put() {
    m_raw = XR_NULL_HANDLE;
    return &m_raw;
  }

  //! @brief Gets the raw handle type.
  //!
  //! See also OPENXR_HPP_NAMESPACE::get()
  OPENXR_HPP_CONSTEXPR RawHandleType get() const { return m_raw; }

  //! @}

  /*!
   * @name OpenXR API calls as member functions
   * @{
   */

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
  /*!
   * @brief xrDestroySpatialAnchorMSFT wrapper.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrDestroySpatialAnchorMSFT>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  Result destroy(Dispatch &&d) const;

#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
  /*!
   * @brief xrDestroySpatialAnchorMSFT wrapper - enhanced mode (hides basic
   * wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).    //! If
   * OPENXR_HPP_NO_EXCEPTIONS is not defined:
   *
   * - Throws an appropriate exception on failure.
   * - Returns nothing (void)
   *
   * If OPENXR_HPP_NO_EXCEPTIONS is defined:
   *
   * - Asserts that result is Result::Success.
   * - Returns Result.
   *
   * See the related specification text at
   * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrDestroySpatialAnchorMSFT>
   *
   * @note No default dispatch is provided as this is a non-core function,
   * and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
   */
  template <typename Dispatch>
  ResultValueType<void>::type destroy(Dispatch &&d) const;

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

  //! @}
private:
  RawHandleType m_raw;
};
static_assert(sizeof(SpatialAnchorMSFT) == sizeof(XrSpatialAnchorMSFT),
              "handle and wrapper have different size!");

//! @brief < comparison between SpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator<(SpatialAnchorMSFT const &lhs, SpatialAnchorMSFT const &rhs) {
  return lhs.get() < rhs.get();
}
//! @brief < comparison between SpatialAnchorMSFT and raw XrSpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator<(SpatialAnchorMSFT const &lhs, XrSpatialAnchorMSFT rhs) {
  return lhs.get() < rhs;
}
//! @brief < comparison between raw XrSpatialAnchorMSFT and SpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator<(XrSpatialAnchorMSFT lhs, SpatialAnchorMSFT const &rhs) {
  return lhs < rhs.get();
}
//! @brief > comparison between SpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator>(SpatialAnchorMSFT const &lhs, SpatialAnchorMSFT const &rhs) {
  return lhs.get() > rhs.get();
}
//! @brief > comparison between SpatialAnchorMSFT and raw XrSpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator>(SpatialAnchorMSFT const &lhs, XrSpatialAnchorMSFT rhs) {
  return lhs.get() > rhs;
}
//! @brief > comparison between raw XrSpatialAnchorMSFT and SpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator>(XrSpatialAnchorMSFT lhs, SpatialAnchorMSFT const &rhs) {
  return lhs > rhs.get();
}
//! @brief <= comparison between SpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator<=(SpatialAnchorMSFT const &lhs, SpatialAnchorMSFT const &rhs) {
  return lhs.get() <= rhs.get();
}
//! @brief <= comparison between SpatialAnchorMSFT and raw XrSpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator<=(SpatialAnchorMSFT const &lhs, XrSpatialAnchorMSFT rhs) {
  return lhs.get() <= rhs;
}
//! @brief <= comparison between raw XrSpatialAnchorMSFT and SpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator<=(XrSpatialAnchorMSFT lhs, SpatialAnchorMSFT const &rhs) {
  return lhs <= rhs.get();
}
//! @brief >= comparison between SpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator>=(SpatialAnchorMSFT const &lhs, SpatialAnchorMSFT const &rhs) {
  return lhs.get() >= rhs.get();
}
//! @brief >= comparison between SpatialAnchorMSFT and raw XrSpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator>=(SpatialAnchorMSFT const &lhs, XrSpatialAnchorMSFT rhs) {
  return lhs.get() >= rhs;
}
//! @brief >= comparison between raw XrSpatialAnchorMSFT and SpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator>=(XrSpatialAnchorMSFT lhs, SpatialAnchorMSFT const &rhs) {
  return lhs >= rhs.get();
}
//! @brief == comparison between SpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(SpatialAnchorMSFT const &lhs, SpatialAnchorMSFT const &rhs) {
  return lhs.get() == rhs.get();
}
//! @brief == comparison between SpatialAnchorMSFT and raw XrSpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(SpatialAnchorMSFT const &lhs, XrSpatialAnchorMSFT rhs) {
  return lhs.get() == rhs;
}
//! @brief == comparison between raw XrSpatialAnchorMSFT and SpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(XrSpatialAnchorMSFT lhs, SpatialAnchorMSFT const &rhs) {
  return lhs == rhs.get();
}
//! @brief != comparison between SpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(SpatialAnchorMSFT const &lhs, SpatialAnchorMSFT const &rhs) {
  return lhs.get() != rhs.get();
}
//! @brief != comparison between SpatialAnchorMSFT and raw XrSpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(SpatialAnchorMSFT const &lhs, XrSpatialAnchorMSFT rhs) {
  return lhs.get() != rhs;
}
//! @brief != comparison between raw XrSpatialAnchorMSFT and SpatialAnchorMSFT.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(XrSpatialAnchorMSFT lhs, SpatialAnchorMSFT const &rhs) {
  return lhs != rhs.get();
}
//! @brief Equality comparison between SpatialAnchorMSFT and nullptr: true if
//! the handle is null.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(SpatialAnchorMSFT const &lhs, std::nullptr_t /* unused */) {
  return lhs.get() == XR_NULL_HANDLE;
}
//! @brief Equality comparison between nullptr and SpatialAnchorMSFT: true if
//! the handle is null.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator==(std::nullptr_t /* unused */, SpatialAnchorMSFT const &rhs) {
  return rhs.get() == XR_NULL_HANDLE;
}
//! @brief Inequality comparison between SpatialAnchorMSFT and nullptr: true if
//! the handle is not null.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(SpatialAnchorMSFT const &lhs, std::nullptr_t /* unused */) {
  return lhs.get() != XR_NULL_HANDLE;
}
//! @brief Inequality comparison between nullptr and SpatialAnchorMSFT: true if
//! the handle is not null.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool
operator!=(std::nullptr_t /* unused */, SpatialAnchorMSFT const &rhs) {
  return rhs.get() != XR_NULL_HANDLE;
}

//! @brief Free function accessor for the raw XrSpatialAnchorMSFT handle in a
//! SpatialAnchorMSFT
//! @relates SpatialAnchorMSFT
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE XrSpatialAnchorMSFT
get(SpatialAnchorMSFT const &h) {
  return h.get();
}

//! @brief Free "put" function for clearing and getting the address of the raw
//! XrSpatialAnchorMSFT handle in a SpatialAnchorMSFT (by reference).
//!
//! e.g.
//! ```
//! SpatialAnchorMSFT yourHandle;
//! auto result = d.xrCreateSpatialAnchorMSFT(..., put(yourHandle));
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the
//! namespace specified.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_INLINE XrSpatialAnchorMSFT *put(SpatialAnchorMSFT &h) {
  return h.put();
}

//! @brief Free "put" function for clearing and getting the address of the raw
//! XrSpatialAnchorMSFT handle in a SpatialAnchorMSFT (by pointer).
//!
//! e.g.
//! ```
//! void yourFunction(SpatialAnchorMSFT* yourHandle) {
//!     auto result = d.xrCreateSpatialAnchorMSFT(..., put(yourHandle));
//!     ....
//! }
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the
//! namespace specified.
//! @relates SpatialAnchorMSFT
OPENXR_HPP_INLINE XrSpatialAnchorMSFT *put(SpatialAnchorMSFT *h) {
  return h->put();
}

namespace traits {
//! @brief Explicit specialization of cpp_type for SpatialAnchorMSFT
template <> struct cpp_type<ObjectType::SpatialAnchorMSFT> {
  using type = SpatialAnchorMSFT;
};
} // namespace traits

/*!
 * @defgroup api_free_functions OpenXR API free functions
 *
 * Equivalent to the method wrappers in the handle classes,
 * but for the few functions that don't take (or don't require)
 * a handle as their first argument.
 * @{
 */
// Forward declarations - implementations at the bottom of the file

/*!
 * @brief xrEnumerateApiLayerProperties wrapper.
 *
 * See the related specification text at
 * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateApiLayerProperties>
 */
template <typename Dispatch = DispatchLoaderStatic>
Result enumerateApiLayerProperties(uint32_t propertyCapacityInput,
                                   uint32_t *propertyCountOutput,
                                   XrApiLayerProperties *properties,
                                   Dispatch &&d = Dispatch{});

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
/*!
 * @brief xrEnumerateApiLayerProperties wrapper - enhanced mode.Performs
 * two-call idiom.    //! If OPENXR_HPP_NO_EXCEPTIONS is not defined:
 *
 * - Throws an appropriate exception on failure.
 * - Returns the value of type std::vector<XrApiLayerProperties, Allocator>
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is defined:
 *
 * - Asserts that result is Result::Success.
 * - Returns the output of type std::vector<XrApiLayerProperties, Allocator>.
 *
 * See the related specification text at
 * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateApiLayerProperties>
 */
template <typename Allocator = std::allocator<XrApiLayerProperties>,
          typename Dispatch = DispatchLoaderStatic>
typename ResultValueType<std::vector<XrApiLayerProperties, Allocator>>::type
enumerateApiLayerProperties(Dispatch &&d = Dispatch{});

/*!
 * @brief xrEnumerateApiLayerProperties wrapper - enhanced mode. Performs
 * two-call idiom with a stateful allocator.
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
 *
 * - Throws an appropriate exception on failure.
 * - Returns the value of type std::vector<XrApiLayerProperties, Allocator>
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is defined:
 *
 * - Asserts that result is Result::Success.
 * - Returns the output of type std::vector<XrApiLayerProperties, Allocator>.
 *
 * See the related specification text at
 * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateApiLayerProperties>
 */
template <typename Allocator = std::allocator<XrApiLayerProperties>,
          typename Dispatch = DispatchLoaderStatic>
typename ResultValueType<std::vector<XrApiLayerProperties, Allocator>>::type
enumerateApiLayerProperties(Allocator const &vectorAllocator, Dispatch &&d);

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

/*!
 * @brief xrEnumerateInstanceExtensionProperties wrapper.
 *
 * See the related specification text at
 * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateInstanceExtensionProperties>
 */
template <typename Dispatch = DispatchLoaderStatic>
Result enumerateInstanceExtensionProperties(const char *layerName,
                                            uint32_t propertyCapacityInput,
                                            uint32_t *propertyCountOutput,
                                            XrExtensionProperties *properties,
                                            Dispatch &&d = Dispatch{});

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
/*!
 * @brief xrEnumerateInstanceExtensionProperties wrapper - enhanced
 * mode.Performs two-call idiom.    //! If OPENXR_HPP_NO_EXCEPTIONS is not
 * defined:
 *
 * - Throws an appropriate exception on failure.
 * - Returns the value of type std::vector<XrExtensionProperties, Allocator>
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is defined:
 *
 * - Asserts that result is Result::Success.
 * - Returns the output of type std::vector<XrExtensionProperties, Allocator>.
 *
 * See the related specification text at
 * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateInstanceExtensionProperties>
 */
template <typename Allocator = std::allocator<XrExtensionProperties>,
          typename Dispatch = DispatchLoaderStatic>
typename ResultValueType<std::vector<XrExtensionProperties, Allocator>>::type
enumerateInstanceExtensionProperties(const char *layerName,
                                     Dispatch &&d = Dispatch{});

/*!
 * @brief xrEnumerateInstanceExtensionProperties wrapper - enhanced mode.
 * Performs two-call idiom with a stateful allocator.
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
 *
 * - Throws an appropriate exception on failure.
 * - Returns the value of type std::vector<XrExtensionProperties, Allocator>
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is defined:
 *
 * - Asserts that result is Result::Success.
 * - Returns the output of type std::vector<XrExtensionProperties, Allocator>.
 *
 * See the related specification text at
 * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateInstanceExtensionProperties>
 */
template <typename Allocator = std::allocator<XrExtensionProperties>,
          typename Dispatch = DispatchLoaderStatic>
typename ResultValueType<std::vector<XrExtensionProperties, Allocator>>::type
enumerateInstanceExtensionProperties(const char *layerName,
                                     Allocator const &vectorAllocator,
                                     Dispatch &&d);

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

/*!
 * @brief xrCreateInstance wrapper.
 *
 * See the related specification text at
 * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateInstance>
 */
template <typename Dispatch = DispatchLoaderStatic>
Result createInstance(const XrInstanceCreateInfo *createInfo,
                      Instance &instance, Dispatch &&d = Dispatch{});

#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
/*!
 * @brief xrCreateInstance wrapper - enhanced mode.    //!
 * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
 *
 * - Throws an appropriate exception on failure.
 * - Returns the value of type Instance
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is defined:
 *
 * - Asserts that result is Result::Success.
 * - Returns the output of type Instance.
 *
 * See the related specification text at
 * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateInstance>
 */
template <typename Dispatch = DispatchLoaderStatic>
typename ResultValueType<Instance>::type
createInstance(const XrInstanceCreateInfo *createInfo,
               Dispatch &&d = Dispatch{});

#ifndef OPENXR_HPP_NO_SMART_HANDLE

/*!
 * @brief xrCreateInstance wrapper returning a smart handle.
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is not defined:
 *
 * - Throws an appropriate exception on failure.
 * - Returns the value of type UniqueHandle<Instance,
 * impl::RemoveRefConst<Dispatch>>
 *
 * If OPENXR_HPP_NO_EXCEPTIONS is defined:
 *
 * - Asserts that result is Result::Success.
 * - Returns the output of type UniqueHandle<Instance,
 * impl::RemoveRefConst<Dispatch>>.
 *
 * See the related specification text at
 * <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateInstance>
 */
template <typename Dispatch = DispatchLoaderStatic>
typename ResultValueType<
    UniqueHandle<Instance, impl::RemoveRefConst<Dispatch>>>::type
createInstanceUnique(const XrInstanceCreateInfo *createInfo,
                     Dispatch &&d = Dispatch{});
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

//! @}

} // namespace OPENXR_HPP_NAMESPACE

namespace OPENXR_HPP_NAMESPACE {

/*!
 * @brief Dispatch class for OpenXR that looks up all functions using a provided
 * or statically-available xrGetInstanceProcAddr function and the optional
 * Instance.
 *
 * This is safer to use, especially in large/multi-module applications, than
 * DispatchLoaderStatic, and is thus recommended.
 *
 * By default, it is lazy-populating: only populating a function pointer when it
 * is attempted to be called (if this object is not const). You can
 * early-populate it using the createFullyPopulated() factory method, providing
 * an Instance and optionally a xrGetInstanceProcAddr function pointer.
 *
 * This class stores all function pointers as type-erased PFN_xrVoidFunction,
 * casting at time of call. This allows the same memory representation to be
 * used across translation units that may not share the same platform defines.
 * Only the member function trampolines containing the casts are conditional on
 * platform defines.
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
   * If getInstanceProcAddr is not supplied, the static ::xrGetInstanceProcAddr
   * will be used.
   */
  explicit DispatchLoaderDynamic(
      Instance instance = nullptr,
      PFN_xrGetInstanceProcAddr getInstanceProcAddr = nullptr)
      : m_instance(instance),
        pfnGetInstanceProcAddr(
            reinterpret_cast<PFN_xrVoidFunction>(getInstanceProcAddr)) {
    if (pfnGetInstanceProcAddr == nullptr) {
      pfnGetInstanceProcAddr =
          reinterpret_cast<PFN_xrVoidFunction>(&::xrGetInstanceProcAddr);
    }
  }

  /*!
   * @brief Create a fully-populated dispatch table given a non-null XrInstance
   * and an optional getInstanceProcAddr.
   *
   * If getInstanceProcAddr is not supplied, the static ::xrGetInstanceProcAddr
   * will be used.
   */
  static DispatchLoaderDynamic createFullyPopulated(
      Instance instance,
      PFN_xrGetInstanceProcAddr getInstanceProcAddr = nullptr) {
    OPENXR_HPP_ASSERT(instance != nullptr);
    DispatchLoaderDynamic dispatch{instance, getInstanceProcAddr};
    dispatch.populate_("xrGetInstanceProcAddr",
                       dispatch.pfnGetInstanceProcAddr);
    dispatch.populate_("xrEnumerateApiLayerProperties",
                       dispatch.pfnEnumerateApiLayerProperties);
    dispatch.populate_("xrEnumerateInstanceExtensionProperties",
                       dispatch.pfnEnumerateInstanceExtensionProperties);
    dispatch.populate_("xrCreateInstance", dispatch.pfnCreateInstance);
    dispatch.populate_("xrDestroyInstance", dispatch.pfnDestroyInstance);
    dispatch.populate_("xrGetInstanceProperties",
                       dispatch.pfnGetInstanceProperties);
    dispatch.populate_("xrPollEvent", dispatch.pfnPollEvent);
    dispatch.populate_("xrResultToString", dispatch.pfnResultToString);
    dispatch.populate_("xrStructureTypeToString",
                       dispatch.pfnStructureTypeToString);
    dispatch.populate_("xrGetSystem", dispatch.pfnGetSystem);
    dispatch.populate_("xrGetSystemProperties",
                       dispatch.pfnGetSystemProperties);
    dispatch.populate_("xrEnumerateEnvironmentBlendModes",
                       dispatch.pfnEnumerateEnvironmentBlendModes);
    dispatch.populate_("xrCreateSession", dispatch.pfnCreateSession);
    dispatch.populate_("xrDestroySession", dispatch.pfnDestroySession);
    dispatch.populate_("xrEnumerateReferenceSpaces",
                       dispatch.pfnEnumerateReferenceSpaces);
    dispatch.populate_("xrCreateReferenceSpace",
                       dispatch.pfnCreateReferenceSpace);
    dispatch.populate_("xrGetReferenceSpaceBoundsRect",
                       dispatch.pfnGetReferenceSpaceBoundsRect);
    dispatch.populate_("xrCreateActionSpace", dispatch.pfnCreateActionSpace);
    dispatch.populate_("xrLocateSpace", dispatch.pfnLocateSpace);
    dispatch.populate_("xrDestroySpace", dispatch.pfnDestroySpace);
    dispatch.populate_("xrEnumerateViewConfigurations",
                       dispatch.pfnEnumerateViewConfigurations);
    dispatch.populate_("xrGetViewConfigurationProperties",
                       dispatch.pfnGetViewConfigurationProperties);
    dispatch.populate_("xrEnumerateViewConfigurationViews",
                       dispatch.pfnEnumerateViewConfigurationViews);
    dispatch.populate_("xrEnumerateSwapchainFormats",
                       dispatch.pfnEnumerateSwapchainFormats);
    dispatch.populate_("xrCreateSwapchain", dispatch.pfnCreateSwapchain);
    dispatch.populate_("xrDestroySwapchain", dispatch.pfnDestroySwapchain);
    dispatch.populate_("xrEnumerateSwapchainImages",
                       dispatch.pfnEnumerateSwapchainImages);
    dispatch.populate_("xrAcquireSwapchainImage",
                       dispatch.pfnAcquireSwapchainImage);
    dispatch.populate_("xrWaitSwapchainImage", dispatch.pfnWaitSwapchainImage);
    dispatch.populate_("xrReleaseSwapchainImage",
                       dispatch.pfnReleaseSwapchainImage);
    dispatch.populate_("xrBeginSession", dispatch.pfnBeginSession);
    dispatch.populate_("xrEndSession", dispatch.pfnEndSession);
    dispatch.populate_("xrRequestExitSession", dispatch.pfnRequestExitSession);
    dispatch.populate_("xrWaitFrame", dispatch.pfnWaitFrame);
    dispatch.populate_("xrBeginFrame", dispatch.pfnBeginFrame);
    dispatch.populate_("xrEndFrame", dispatch.pfnEndFrame);
    dispatch.populate_("xrLocateViews", dispatch.pfnLocateViews);
    dispatch.populate_("xrStringToPath", dispatch.pfnStringToPath);
    dispatch.populate_("xrPathToString", dispatch.pfnPathToString);
    dispatch.populate_("xrCreateActionSet", dispatch.pfnCreateActionSet);
    dispatch.populate_("xrDestroyActionSet", dispatch.pfnDestroyActionSet);
    dispatch.populate_("xrCreateAction", dispatch.pfnCreateAction);
    dispatch.populate_("xrDestroyAction", dispatch.pfnDestroyAction);
    dispatch.populate_("xrSuggestInteractionProfileBindings",
                       dispatch.pfnSuggestInteractionProfileBindings);
    dispatch.populate_("xrAttachSessionActionSets",
                       dispatch.pfnAttachSessionActionSets);
    dispatch.populate_("xrGetCurrentInteractionProfile",
                       dispatch.pfnGetCurrentInteractionProfile);
    dispatch.populate_("xrGetActionStateBoolean",
                       dispatch.pfnGetActionStateBoolean);
    dispatch.populate_("xrGetActionStateFloat",
                       dispatch.pfnGetActionStateFloat);
    dispatch.populate_("xrGetActionStateVector2f",
                       dispatch.pfnGetActionStateVector2f);
    dispatch.populate_("xrGetActionStatePose", dispatch.pfnGetActionStatePose);
    dispatch.populate_("xrSyncActions", dispatch.pfnSyncActions);
    dispatch.populate_("xrEnumerateBoundSourcesForAction",
                       dispatch.pfnEnumerateBoundSourcesForAction);
    dispatch.populate_("xrGetInputSourceLocalizedName",
                       dispatch.pfnGetInputSourceLocalizedName);
    dispatch.populate_("xrApplyHapticFeedback",
                       dispatch.pfnApplyHapticFeedback);
    dispatch.populate_("xrStopHapticFeedback", dispatch.pfnStopHapticFeedback);
    dispatch.populate_("xrSetAndroidApplicationThreadKHR",
                       dispatch.pfnSetAndroidApplicationThreadKHR);
    dispatch.populate_("xrCreateSwapchainAndroidSurfaceKHR",
                       dispatch.pfnCreateSwapchainAndroidSurfaceKHR);
    dispatch.populate_("xrGetOpenGLGraphicsRequirementsKHR",
                       dispatch.pfnGetOpenGLGraphicsRequirementsKHR);
    dispatch.populate_("xrGetOpenGLESGraphicsRequirementsKHR",
                       dispatch.pfnGetOpenGLESGraphicsRequirementsKHR);
    dispatch.populate_("xrGetVulkanInstanceExtensionsKHR",
                       dispatch.pfnGetVulkanInstanceExtensionsKHR);
    dispatch.populate_("xrGetVulkanDeviceExtensionsKHR",
                       dispatch.pfnGetVulkanDeviceExtensionsKHR);
    dispatch.populate_("xrGetVulkanGraphicsDeviceKHR",
                       dispatch.pfnGetVulkanGraphicsDeviceKHR);
    dispatch.populate_("xrGetVulkanGraphicsRequirementsKHR",
                       dispatch.pfnGetVulkanGraphicsRequirementsKHR);
    dispatch.populate_("xrGetD3D11GraphicsRequirementsKHR",
                       dispatch.pfnGetD3D11GraphicsRequirementsKHR);
    dispatch.populate_("xrGetD3D12GraphicsRequirementsKHR",
                       dispatch.pfnGetD3D12GraphicsRequirementsKHR);
    dispatch.populate_("xrGetVisibilityMaskKHR",
                       dispatch.pfnGetVisibilityMaskKHR);
    dispatch.populate_("xrConvertWin32PerformanceCounterToTimeKHR",
                       dispatch.pfnConvertWin32PerformanceCounterToTimeKHR);
    dispatch.populate_("xrConvertTimeToWin32PerformanceCounterKHR",
                       dispatch.pfnConvertTimeToWin32PerformanceCounterKHR);
    dispatch.populate_("xrConvertTimespecTimeToTimeKHR",
                       dispatch.pfnConvertTimespecTimeToTimeKHR);
    dispatch.populate_("xrConvertTimeToTimespecTimeKHR",
                       dispatch.pfnConvertTimeToTimespecTimeKHR);
    dispatch.populate_("xrPerfSettingsSetPerformanceLevelEXT",
                       dispatch.pfnPerfSettingsSetPerformanceLevelEXT);
    dispatch.populate_("xrThermalGetTemperatureTrendEXT",
                       dispatch.pfnThermalGetTemperatureTrendEXT);
    dispatch.populate_("xrSetDebugUtilsObjectNameEXT",
                       dispatch.pfnSetDebugUtilsObjectNameEXT);
    dispatch.populate_("xrCreateDebugUtilsMessengerEXT",
                       dispatch.pfnCreateDebugUtilsMessengerEXT);
    dispatch.populate_("xrDestroyDebugUtilsMessengerEXT",
                       dispatch.pfnDestroyDebugUtilsMessengerEXT);
    dispatch.populate_("xrSubmitDebugUtilsMessageEXT",
                       dispatch.pfnSubmitDebugUtilsMessageEXT);
    dispatch.populate_("xrSessionBeginDebugUtilsLabelRegionEXT",
                       dispatch.pfnSessionBeginDebugUtilsLabelRegionEXT);
    dispatch.populate_("xrSessionEndDebugUtilsLabelRegionEXT",
                       dispatch.pfnSessionEndDebugUtilsLabelRegionEXT);
    dispatch.populate_("xrSessionInsertDebugUtilsLabelEXT",
                       dispatch.pfnSessionInsertDebugUtilsLabelEXT);
    dispatch.populate_("xrCreateSpatialAnchorMSFT",
                       dispatch.pfnCreateSpatialAnchorMSFT);
    dispatch.populate_("xrCreateSpatialAnchorSpaceMSFT",
                       dispatch.pfnCreateSpatialAnchorSpaceMSFT);
    dispatch.populate_("xrDestroySpatialAnchorMSFT",
                       dispatch.pfnDestroySpatialAnchorMSFT);
    return dispatch;
  }

  //! @}

  /*!
   * @name Entry points
   * @brief These populate the function pointer (if required and non-const),
   * then cast it and call it.
   *
   * We store everything as PFN_xrVoidFunction to allow us to have the same
   * representation all over, despite containing function pointers that might
   * not be accessible without some platform defines. Thus, only our accessor
   * methods differ between different includes of this header, not our data
   * members.
   *
   * @{
   */

  //! @brief Call xrGetInstanceProcAddr, populating function pointer if
  //! required.
  XrResult xrGetInstanceProcAddr(XrInstance instance, const char *name,
                                 PFN_xrVoidFunction *function) {

    XrResult result =
        populate_("xrGetInstanceProcAddr", pfnGetInstanceProcAddr);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetInstanceProcAddr>(
        pfnGetInstanceProcAddr))(instance, name, function);
  }

  //! @brief Call xrGetInstanceProcAddr (const overload - does not populate
  //! function pointer)
  XrResult xrGetInstanceProcAddr(XrInstance instance, const char *name,
                                 PFN_xrVoidFunction *function) const {

    return (reinterpret_cast<PFN_xrGetInstanceProcAddr>(
        pfnGetInstanceProcAddr))(instance, name, function);
  }

  //! @brief Call xrEnumerateApiLayerProperties, populating function pointer if
  //! required.
  XrResult xrEnumerateApiLayerProperties(uint32_t propertyCapacityInput,
                                         uint32_t *propertyCountOutput,
                                         XrApiLayerProperties *properties) {

    XrResult result = populate_("xrEnumerateApiLayerProperties",
                                pfnEnumerateApiLayerProperties);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrEnumerateApiLayerProperties>(
        pfnEnumerateApiLayerProperties))(propertyCapacityInput,
                                         propertyCountOutput, properties);
  }

  //! @brief Call xrEnumerateApiLayerProperties (const overload - does not
  //! populate function pointer)
  XrResult
  xrEnumerateApiLayerProperties(uint32_t propertyCapacityInput,
                                uint32_t *propertyCountOutput,
                                XrApiLayerProperties *properties) const {

    return (reinterpret_cast<PFN_xrEnumerateApiLayerProperties>(
        pfnEnumerateApiLayerProperties))(propertyCapacityInput,
                                         propertyCountOutput, properties);
  }

  //! @brief Call xrEnumerateInstanceExtensionProperties, populating function
  //! pointer if required.
  XrResult xrEnumerateInstanceExtensionProperties(
      const char *layerName, uint32_t propertyCapacityInput,
      uint32_t *propertyCountOutput, XrExtensionProperties *properties) {

    XrResult result = populate_("xrEnumerateInstanceExtensionProperties",
                                pfnEnumerateInstanceExtensionProperties);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrEnumerateInstanceExtensionProperties>(
        pfnEnumerateInstanceExtensionProperties))(
        layerName, propertyCapacityInput, propertyCountOutput, properties);
  }

  //! @brief Call xrEnumerateInstanceExtensionProperties (const overload - does
  //! not populate function pointer)
  XrResult xrEnumerateInstanceExtensionProperties(
      const char *layerName, uint32_t propertyCapacityInput,
      uint32_t *propertyCountOutput, XrExtensionProperties *properties) const {

    return (reinterpret_cast<PFN_xrEnumerateInstanceExtensionProperties>(
        pfnEnumerateInstanceExtensionProperties))(
        layerName, propertyCapacityInput, propertyCountOutput, properties);
  }

  //! @brief Call xrCreateInstance, populating function pointer if required.
  XrResult xrCreateInstance(const XrInstanceCreateInfo *createInfo,
                            XrInstance *instance) {

    XrResult result = populate_("xrCreateInstance", pfnCreateInstance);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrCreateInstance>(pfnCreateInstance))(
        createInfo, instance);
  }

  //! @brief Call xrCreateInstance (const overload - does not populate function
  //! pointer)
  XrResult xrCreateInstance(const XrInstanceCreateInfo *createInfo,
                            XrInstance *instance) const {

    return (reinterpret_cast<PFN_xrCreateInstance>(pfnCreateInstance))(
        createInfo, instance);
  }

  //! @brief Call xrDestroyInstance, populating function pointer if required.
  XrResult xrDestroyInstance(XrInstance instance) {

    XrResult result = populate_("xrDestroyInstance", pfnDestroyInstance);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrDestroyInstance>(pfnDestroyInstance))(
        instance);
  }

  //! @brief Call xrDestroyInstance (const overload - does not populate function
  //! pointer)
  XrResult xrDestroyInstance(XrInstance instance) const {

    return (reinterpret_cast<PFN_xrDestroyInstance>(pfnDestroyInstance))(
        instance);
  }

  //! @brief Call xrGetInstanceProperties, populating function pointer if
  //! required.
  XrResult xrGetInstanceProperties(XrInstance instance,
                                   XrInstanceProperties *instanceProperties) {

    XrResult result =
        populate_("xrGetInstanceProperties", pfnGetInstanceProperties);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetInstanceProperties>(
        pfnGetInstanceProperties))(instance, instanceProperties);
  }

  //! @brief Call xrGetInstanceProperties (const overload - does not populate
  //! function pointer)
  XrResult
  xrGetInstanceProperties(XrInstance instance,
                          XrInstanceProperties *instanceProperties) const {

    return (reinterpret_cast<PFN_xrGetInstanceProperties>(
        pfnGetInstanceProperties))(instance, instanceProperties);
  }

  //! @brief Call xrPollEvent, populating function pointer if required.
  XrResult xrPollEvent(XrInstance instance, XrEventDataBuffer *eventData) {

    XrResult result = populate_("xrPollEvent", pfnPollEvent);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrPollEvent>(pfnPollEvent))(instance,
                                                             eventData);
  }

  //! @brief Call xrPollEvent (const overload - does not populate function
  //! pointer)
  XrResult xrPollEvent(XrInstance instance,
                       XrEventDataBuffer *eventData) const {

    return (reinterpret_cast<PFN_xrPollEvent>(pfnPollEvent))(instance,
                                                             eventData);
  }

  //! @brief Call xrResultToString, populating function pointer if required.
  XrResult xrResultToString(XrInstance instance, XrResult value,
                            char buffer[XR_MAX_RESULT_STRING_SIZE]) {

    XrResult result = populate_("xrResultToString", pfnResultToString);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrResultToString>(pfnResultToString))(
        instance, value, buffer);
  }

  //! @brief Call xrResultToString (const overload - does not populate function
  //! pointer)
  XrResult xrResultToString(XrInstance instance, XrResult value,
                            char buffer[XR_MAX_RESULT_STRING_SIZE]) const {

    return (reinterpret_cast<PFN_xrResultToString>(pfnResultToString))(
        instance, value, buffer);
  }

  //! @brief Call xrStructureTypeToString, populating function pointer if
  //! required.
  XrResult xrStructureTypeToString(XrInstance instance, XrStructureType value,
                                   char buffer[XR_MAX_STRUCTURE_NAME_SIZE]) {

    XrResult result =
        populate_("xrStructureTypeToString", pfnStructureTypeToString);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrStructureTypeToString>(
        pfnStructureTypeToString))(instance, value, buffer);
  }

  //! @brief Call xrStructureTypeToString (const overload - does not populate
  //! function pointer)
  XrResult
  xrStructureTypeToString(XrInstance instance, XrStructureType value,
                          char buffer[XR_MAX_STRUCTURE_NAME_SIZE]) const {

    return (reinterpret_cast<PFN_xrStructureTypeToString>(
        pfnStructureTypeToString))(instance, value, buffer);
  }

  //! @brief Call xrGetSystem, populating function pointer if required.
  XrResult xrGetSystem(XrInstance instance, const XrSystemGetInfo *getInfo,
                       XrSystemId *systemId) {

    XrResult result = populate_("xrGetSystem", pfnGetSystem);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetSystem>(pfnGetSystem))(instance, getInfo,
                                                             systemId);
  }

  //! @brief Call xrGetSystem (const overload - does not populate function
  //! pointer)
  XrResult xrGetSystem(XrInstance instance, const XrSystemGetInfo *getInfo,
                       XrSystemId *systemId) const {

    return (reinterpret_cast<PFN_xrGetSystem>(pfnGetSystem))(instance, getInfo,
                                                             systemId);
  }

  //! @brief Call xrGetSystemProperties, populating function pointer if
  //! required.
  XrResult xrGetSystemProperties(XrInstance instance, XrSystemId systemId,
                                 XrSystemProperties *properties) {

    XrResult result =
        populate_("xrGetSystemProperties", pfnGetSystemProperties);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetSystemProperties>(
        pfnGetSystemProperties))(instance, systemId, properties);
  }

  //! @brief Call xrGetSystemProperties (const overload - does not populate
  //! function pointer)
  XrResult xrGetSystemProperties(XrInstance instance, XrSystemId systemId,
                                 XrSystemProperties *properties) const {

    return (reinterpret_cast<PFN_xrGetSystemProperties>(
        pfnGetSystemProperties))(instance, systemId, properties);
  }

  //! @brief Call xrEnumerateEnvironmentBlendModes, populating function pointer
  //! if required.
  XrResult xrEnumerateEnvironmentBlendModes(
      XrInstance instance, XrSystemId systemId,
      XrViewConfigurationType viewConfigurationType,
      uint32_t environmentBlendModeCapacityInput,
      uint32_t *environmentBlendModeCountOutput,
      XrEnvironmentBlendMode *environmentBlendModes) {

    XrResult result = populate_("xrEnumerateEnvironmentBlendModes",
                                pfnEnumerateEnvironmentBlendModes);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrEnumerateEnvironmentBlendModes>(
        pfnEnumerateEnvironmentBlendModes))(
        instance, systemId, viewConfigurationType,
        environmentBlendModeCapacityInput, environmentBlendModeCountOutput,
        environmentBlendModes);
  }

  //! @brief Call xrEnumerateEnvironmentBlendModes (const overload - does not
  //! populate function pointer)
  XrResult xrEnumerateEnvironmentBlendModes(
      XrInstance instance, XrSystemId systemId,
      XrViewConfigurationType viewConfigurationType,
      uint32_t environmentBlendModeCapacityInput,
      uint32_t *environmentBlendModeCountOutput,
      XrEnvironmentBlendMode *environmentBlendModes) const {

    return (reinterpret_cast<PFN_xrEnumerateEnvironmentBlendModes>(
        pfnEnumerateEnvironmentBlendModes))(
        instance, systemId, viewConfigurationType,
        environmentBlendModeCapacityInput, environmentBlendModeCountOutput,
        environmentBlendModes);
  }

  //! @brief Call xrCreateSession, populating function pointer if required.
  XrResult xrCreateSession(XrInstance instance,
                           const XrSessionCreateInfo *createInfo,
                           XrSession *session) {

    XrResult result = populate_("xrCreateSession", pfnCreateSession);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrCreateSession>(pfnCreateSession))(
        instance, createInfo, session);
  }

  //! @brief Call xrCreateSession (const overload - does not populate function
  //! pointer)
  XrResult xrCreateSession(XrInstance instance,
                           const XrSessionCreateInfo *createInfo,
                           XrSession *session) const {

    return (reinterpret_cast<PFN_xrCreateSession>(pfnCreateSession))(
        instance, createInfo, session);
  }

  //! @brief Call xrDestroySession, populating function pointer if required.
  XrResult xrDestroySession(XrSession session) {

    XrResult result = populate_("xrDestroySession", pfnDestroySession);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrDestroySession>(pfnDestroySession))(session);
  }

  //! @brief Call xrDestroySession (const overload - does not populate function
  //! pointer)
  XrResult xrDestroySession(XrSession session) const {

    return (reinterpret_cast<PFN_xrDestroySession>(pfnDestroySession))(session);
  }

  //! @brief Call xrEnumerateReferenceSpaces, populating function pointer if
  //! required.
  XrResult xrEnumerateReferenceSpaces(XrSession session,
                                      uint32_t spaceCapacityInput,
                                      uint32_t *spaceCountOutput,
                                      XrReferenceSpaceType *spaces) {

    XrResult result =
        populate_("xrEnumerateReferenceSpaces", pfnEnumerateReferenceSpaces);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrEnumerateReferenceSpaces>(
        pfnEnumerateReferenceSpaces))(session, spaceCapacityInput,
                                      spaceCountOutput, spaces);
  }

  //! @brief Call xrEnumerateReferenceSpaces (const overload - does not populate
  //! function pointer)
  XrResult xrEnumerateReferenceSpaces(XrSession session,
                                      uint32_t spaceCapacityInput,
                                      uint32_t *spaceCountOutput,
                                      XrReferenceSpaceType *spaces) const {

    return (reinterpret_cast<PFN_xrEnumerateReferenceSpaces>(
        pfnEnumerateReferenceSpaces))(session, spaceCapacityInput,
                                      spaceCountOutput, spaces);
  }

  //! @brief Call xrCreateReferenceSpace, populating function pointer if
  //! required.
  XrResult xrCreateReferenceSpace(XrSession session,
                                  const XrReferenceSpaceCreateInfo *createInfo,
                                  XrSpace *space) {

    XrResult result =
        populate_("xrCreateReferenceSpace", pfnCreateReferenceSpace);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrCreateReferenceSpace>(
        pfnCreateReferenceSpace))(session, createInfo, space);
  }

  //! @brief Call xrCreateReferenceSpace (const overload - does not populate
  //! function pointer)
  XrResult xrCreateReferenceSpace(XrSession session,
                                  const XrReferenceSpaceCreateInfo *createInfo,
                                  XrSpace *space) const {

    return (reinterpret_cast<PFN_xrCreateReferenceSpace>(
        pfnCreateReferenceSpace))(session, createInfo, space);
  }

  //! @brief Call xrGetReferenceSpaceBoundsRect, populating function pointer if
  //! required.
  XrResult
  xrGetReferenceSpaceBoundsRect(XrSession session,
                                XrReferenceSpaceType referenceSpaceType,
                                XrExtent2Df *bounds) {

    XrResult result = populate_("xrGetReferenceSpaceBoundsRect",
                                pfnGetReferenceSpaceBoundsRect);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetReferenceSpaceBoundsRect>(
        pfnGetReferenceSpaceBoundsRect))(session, referenceSpaceType, bounds);
  }

  //! @brief Call xrGetReferenceSpaceBoundsRect (const overload - does not
  //! populate function pointer)
  XrResult
  xrGetReferenceSpaceBoundsRect(XrSession session,
                                XrReferenceSpaceType referenceSpaceType,
                                XrExtent2Df *bounds) const {

    return (reinterpret_cast<PFN_xrGetReferenceSpaceBoundsRect>(
        pfnGetReferenceSpaceBoundsRect))(session, referenceSpaceType, bounds);
  }

  //! @brief Call xrCreateActionSpace, populating function pointer if required.
  XrResult xrCreateActionSpace(XrSession session,
                               const XrActionSpaceCreateInfo *createInfo,
                               XrSpace *space) {

    XrResult result = populate_("xrCreateActionSpace", pfnCreateActionSpace);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrCreateActionSpace>(pfnCreateActionSpace))(
        session, createInfo, space);
  }

  //! @brief Call xrCreateActionSpace (const overload - does not populate
  //! function pointer)
  XrResult xrCreateActionSpace(XrSession session,
                               const XrActionSpaceCreateInfo *createInfo,
                               XrSpace *space) const {

    return (reinterpret_cast<PFN_xrCreateActionSpace>(pfnCreateActionSpace))(
        session, createInfo, space);
  }

  //! @brief Call xrLocateSpace, populating function pointer if required.
  XrResult xrLocateSpace(XrSpace space, XrSpace baseSpace, XrTime time,
                         XrSpaceLocation *location) {

    XrResult result = populate_("xrLocateSpace", pfnLocateSpace);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrLocateSpace>(pfnLocateSpace))(
        space, baseSpace, time, location);
  }

  //! @brief Call xrLocateSpace (const overload - does not populate function
  //! pointer)
  XrResult xrLocateSpace(XrSpace space, XrSpace baseSpace, XrTime time,
                         XrSpaceLocation *location) const {

    return (reinterpret_cast<PFN_xrLocateSpace>(pfnLocateSpace))(
        space, baseSpace, time, location);
  }

  //! @brief Call xrDestroySpace, populating function pointer if required.
  XrResult xrDestroySpace(XrSpace space) {

    XrResult result = populate_("xrDestroySpace", pfnDestroySpace);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrDestroySpace>(pfnDestroySpace))(space);
  }

  //! @brief Call xrDestroySpace (const overload - does not populate function
  //! pointer)
  XrResult xrDestroySpace(XrSpace space) const {

    return (reinterpret_cast<PFN_xrDestroySpace>(pfnDestroySpace))(space);
  }

  //! @brief Call xrEnumerateViewConfigurations, populating function pointer if
  //! required.
  XrResult xrEnumerateViewConfigurations(
      XrInstance instance, XrSystemId systemId,
      uint32_t viewConfigurationTypeCapacityInput,
      uint32_t *viewConfigurationTypeCountOutput,
      XrViewConfigurationType *viewConfigurationTypes) {

    XrResult result = populate_("xrEnumerateViewConfigurations",
                                pfnEnumerateViewConfigurations);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrEnumerateViewConfigurations>(
        pfnEnumerateViewConfigurations))(
        instance, systemId, viewConfigurationTypeCapacityInput,
        viewConfigurationTypeCountOutput, viewConfigurationTypes);
  }

  //! @brief Call xrEnumerateViewConfigurations (const overload - does not
  //! populate function pointer)
  XrResult xrEnumerateViewConfigurations(
      XrInstance instance, XrSystemId systemId,
      uint32_t viewConfigurationTypeCapacityInput,
      uint32_t *viewConfigurationTypeCountOutput,
      XrViewConfigurationType *viewConfigurationTypes) const {

    return (reinterpret_cast<PFN_xrEnumerateViewConfigurations>(
        pfnEnumerateViewConfigurations))(
        instance, systemId, viewConfigurationTypeCapacityInput,
        viewConfigurationTypeCountOutput, viewConfigurationTypes);
  }

  //! @brief Call xrGetViewConfigurationProperties, populating function pointer
  //! if required.
  XrResult xrGetViewConfigurationProperties(
      XrInstance instance, XrSystemId systemId,
      XrViewConfigurationType viewConfigurationType,
      XrViewConfigurationProperties *configurationProperties) {

    XrResult result = populate_("xrGetViewConfigurationProperties",
                                pfnGetViewConfigurationProperties);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetViewConfigurationProperties>(
        pfnGetViewConfigurationProperties))(
        instance, systemId, viewConfigurationType, configurationProperties);
  }

  //! @brief Call xrGetViewConfigurationProperties (const overload - does not
  //! populate function pointer)
  XrResult xrGetViewConfigurationProperties(
      XrInstance instance, XrSystemId systemId,
      XrViewConfigurationType viewConfigurationType,
      XrViewConfigurationProperties *configurationProperties) const {

    return (reinterpret_cast<PFN_xrGetViewConfigurationProperties>(
        pfnGetViewConfigurationProperties))(
        instance, systemId, viewConfigurationType, configurationProperties);
  }

  //! @brief Call xrEnumerateViewConfigurationViews, populating function pointer
  //! if required.
  XrResult xrEnumerateViewConfigurationViews(
      XrInstance instance, XrSystemId systemId,
      XrViewConfigurationType viewConfigurationType, uint32_t viewCapacityInput,
      uint32_t *viewCountOutput, XrViewConfigurationView *views) {

    XrResult result = populate_("xrEnumerateViewConfigurationViews",
                                pfnEnumerateViewConfigurationViews);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrEnumerateViewConfigurationViews>(
        pfnEnumerateViewConfigurationViews))(
        instance, systemId, viewConfigurationType, viewCapacityInput,
        viewCountOutput, views);
  }

  //! @brief Call xrEnumerateViewConfigurationViews (const overload - does not
  //! populate function pointer)
  XrResult xrEnumerateViewConfigurationViews(
      XrInstance instance, XrSystemId systemId,
      XrViewConfigurationType viewConfigurationType, uint32_t viewCapacityInput,
      uint32_t *viewCountOutput, XrViewConfigurationView *views) const {

    return (reinterpret_cast<PFN_xrEnumerateViewConfigurationViews>(
        pfnEnumerateViewConfigurationViews))(
        instance, systemId, viewConfigurationType, viewCapacityInput,
        viewCountOutput, views);
  }

  //! @brief Call xrEnumerateSwapchainFormats, populating function pointer if
  //! required.
  XrResult xrEnumerateSwapchainFormats(XrSession session,
                                       uint32_t formatCapacityInput,
                                       uint32_t *formatCountOutput,
                                       int64_t *formats) {

    XrResult result =
        populate_("xrEnumerateSwapchainFormats", pfnEnumerateSwapchainFormats);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrEnumerateSwapchainFormats>(
        pfnEnumerateSwapchainFormats))(session, formatCapacityInput,
                                       formatCountOutput, formats);
  }

  //! @brief Call xrEnumerateSwapchainFormats (const overload - does not
  //! populate function pointer)
  XrResult xrEnumerateSwapchainFormats(XrSession session,
                                       uint32_t formatCapacityInput,
                                       uint32_t *formatCountOutput,
                                       int64_t *formats) const {

    return (reinterpret_cast<PFN_xrEnumerateSwapchainFormats>(
        pfnEnumerateSwapchainFormats))(session, formatCapacityInput,
                                       formatCountOutput, formats);
  }

  //! @brief Call xrCreateSwapchain, populating function pointer if required.
  XrResult xrCreateSwapchain(XrSession session,
                             const XrSwapchainCreateInfo *createInfo,
                             XrSwapchain *swapchain) {

    XrResult result = populate_("xrCreateSwapchain", pfnCreateSwapchain);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrCreateSwapchain>(pfnCreateSwapchain))(
        session, createInfo, swapchain);
  }

  //! @brief Call xrCreateSwapchain (const overload - does not populate function
  //! pointer)
  XrResult xrCreateSwapchain(XrSession session,
                             const XrSwapchainCreateInfo *createInfo,
                             XrSwapchain *swapchain) const {

    return (reinterpret_cast<PFN_xrCreateSwapchain>(pfnCreateSwapchain))(
        session, createInfo, swapchain);
  }

  //! @brief Call xrDestroySwapchain, populating function pointer if required.
  XrResult xrDestroySwapchain(XrSwapchain swapchain) {

    XrResult result = populate_("xrDestroySwapchain", pfnDestroySwapchain);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrDestroySwapchain>(pfnDestroySwapchain))(
        swapchain);
  }

  //! @brief Call xrDestroySwapchain (const overload - does not populate
  //! function pointer)
  XrResult xrDestroySwapchain(XrSwapchain swapchain) const {

    return (reinterpret_cast<PFN_xrDestroySwapchain>(pfnDestroySwapchain))(
        swapchain);
  }

  //! @brief Call xrEnumerateSwapchainImages, populating function pointer if
  //! required.
  XrResult xrEnumerateSwapchainImages(XrSwapchain swapchain,
                                      uint32_t imageCapacityInput,
                                      uint32_t *imageCountOutput,
                                      XrSwapchainImageBaseHeader *images) {

    XrResult result =
        populate_("xrEnumerateSwapchainImages", pfnEnumerateSwapchainImages);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrEnumerateSwapchainImages>(
        pfnEnumerateSwapchainImages))(swapchain, imageCapacityInput,
                                      imageCountOutput, images);
  }

  //! @brief Call xrEnumerateSwapchainImages (const overload - does not populate
  //! function pointer)
  XrResult
  xrEnumerateSwapchainImages(XrSwapchain swapchain, uint32_t imageCapacityInput,
                             uint32_t *imageCountOutput,
                             XrSwapchainImageBaseHeader *images) const {

    return (reinterpret_cast<PFN_xrEnumerateSwapchainImages>(
        pfnEnumerateSwapchainImages))(swapchain, imageCapacityInput,
                                      imageCountOutput, images);
  }

  //! @brief Call xrAcquireSwapchainImage, populating function pointer if
  //! required.
  XrResult
  xrAcquireSwapchainImage(XrSwapchain swapchain,
                          const XrSwapchainImageAcquireInfo *acquireInfo,
                          uint32_t *index) {

    XrResult result =
        populate_("xrAcquireSwapchainImage", pfnAcquireSwapchainImage);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrAcquireSwapchainImage>(
        pfnAcquireSwapchainImage))(swapchain, acquireInfo, index);
  }

  //! @brief Call xrAcquireSwapchainImage (const overload - does not populate
  //! function pointer)
  XrResult
  xrAcquireSwapchainImage(XrSwapchain swapchain,
                          const XrSwapchainImageAcquireInfo *acquireInfo,
                          uint32_t *index) const {

    return (reinterpret_cast<PFN_xrAcquireSwapchainImage>(
        pfnAcquireSwapchainImage))(swapchain, acquireInfo, index);
  }

  //! @brief Call xrWaitSwapchainImage, populating function pointer if required.
  XrResult xrWaitSwapchainImage(XrSwapchain swapchain,
                                const XrSwapchainImageWaitInfo *waitInfo) {

    XrResult result = populate_("xrWaitSwapchainImage", pfnWaitSwapchainImage);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrWaitSwapchainImage>(pfnWaitSwapchainImage))(
        swapchain, waitInfo);
  }

  //! @brief Call xrWaitSwapchainImage (const overload - does not populate
  //! function pointer)
  XrResult
  xrWaitSwapchainImage(XrSwapchain swapchain,
                       const XrSwapchainImageWaitInfo *waitInfo) const {

    return (reinterpret_cast<PFN_xrWaitSwapchainImage>(pfnWaitSwapchainImage))(
        swapchain, waitInfo);
  }

  //! @brief Call xrReleaseSwapchainImage, populating function pointer if
  //! required.
  XrResult
  xrReleaseSwapchainImage(XrSwapchain swapchain,
                          const XrSwapchainImageReleaseInfo *releaseInfo) {

    XrResult result =
        populate_("xrReleaseSwapchainImage", pfnReleaseSwapchainImage);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrReleaseSwapchainImage>(
        pfnReleaseSwapchainImage))(swapchain, releaseInfo);
  }

  //! @brief Call xrReleaseSwapchainImage (const overload - does not populate
  //! function pointer)
  XrResult xrReleaseSwapchainImage(
      XrSwapchain swapchain,
      const XrSwapchainImageReleaseInfo *releaseInfo) const {

    return (reinterpret_cast<PFN_xrReleaseSwapchainImage>(
        pfnReleaseSwapchainImage))(swapchain, releaseInfo);
  }

  //! @brief Call xrBeginSession, populating function pointer if required.
  XrResult xrBeginSession(XrSession session,
                          const XrSessionBeginInfo *beginInfo) {

    XrResult result = populate_("xrBeginSession", pfnBeginSession);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrBeginSession>(pfnBeginSession))(session,
                                                                   beginInfo);
  }

  //! @brief Call xrBeginSession (const overload - does not populate function
  //! pointer)
  XrResult xrBeginSession(XrSession session,
                          const XrSessionBeginInfo *beginInfo) const {

    return (reinterpret_cast<PFN_xrBeginSession>(pfnBeginSession))(session,
                                                                   beginInfo);
  }

  //! @brief Call xrEndSession, populating function pointer if required.
  XrResult xrEndSession(XrSession session) {

    XrResult result = populate_("xrEndSession", pfnEndSession);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrEndSession>(pfnEndSession))(session);
  }

  //! @brief Call xrEndSession (const overload - does not populate function
  //! pointer)
  XrResult xrEndSession(XrSession session) const {

    return (reinterpret_cast<PFN_xrEndSession>(pfnEndSession))(session);
  }

  //! @brief Call xrRequestExitSession, populating function pointer if required.
  XrResult xrRequestExitSession(XrSession session) {

    XrResult result = populate_("xrRequestExitSession", pfnRequestExitSession);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrRequestExitSession>(pfnRequestExitSession))(
        session);
  }

  //! @brief Call xrRequestExitSession (const overload - does not populate
  //! function pointer)
  XrResult xrRequestExitSession(XrSession session) const {

    return (reinterpret_cast<PFN_xrRequestExitSession>(pfnRequestExitSession))(
        session);
  }

  //! @brief Call xrWaitFrame, populating function pointer if required.
  XrResult xrWaitFrame(XrSession session, const XrFrameWaitInfo *frameWaitInfo,
                       XrFrameState *frameState) {

    XrResult result = populate_("xrWaitFrame", pfnWaitFrame);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrWaitFrame>(pfnWaitFrame))(
        session, frameWaitInfo, frameState);
  }

  //! @brief Call xrWaitFrame (const overload - does not populate function
  //! pointer)
  XrResult xrWaitFrame(XrSession session, const XrFrameWaitInfo *frameWaitInfo,
                       XrFrameState *frameState) const {

    return (reinterpret_cast<PFN_xrWaitFrame>(pfnWaitFrame))(
        session, frameWaitInfo, frameState);
  }

  //! @brief Call xrBeginFrame, populating function pointer if required.
  XrResult xrBeginFrame(XrSession session,
                        const XrFrameBeginInfo *frameBeginInfo) {

    XrResult result = populate_("xrBeginFrame", pfnBeginFrame);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrBeginFrame>(pfnBeginFrame))(session,
                                                               frameBeginInfo);
  }

  //! @brief Call xrBeginFrame (const overload - does not populate function
  //! pointer)
  XrResult xrBeginFrame(XrSession session,
                        const XrFrameBeginInfo *frameBeginInfo) const {

    return (reinterpret_cast<PFN_xrBeginFrame>(pfnBeginFrame))(session,
                                                               frameBeginInfo);
  }

  //! @brief Call xrEndFrame, populating function pointer if required.
  XrResult xrEndFrame(XrSession session, const XrFrameEndInfo *frameEndInfo) {

    XrResult result = populate_("xrEndFrame", pfnEndFrame);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrEndFrame>(pfnEndFrame))(session,
                                                           frameEndInfo);
  }

  //! @brief Call xrEndFrame (const overload - does not populate function
  //! pointer)
  XrResult xrEndFrame(XrSession session,
                      const XrFrameEndInfo *frameEndInfo) const {

    return (reinterpret_cast<PFN_xrEndFrame>(pfnEndFrame))(session,
                                                           frameEndInfo);
  }

  //! @brief Call xrLocateViews, populating function pointer if required.
  XrResult xrLocateViews(XrSession session,
                         const XrViewLocateInfo *viewLocateInfo,
                         XrViewState *viewState, uint32_t viewCapacityInput,
                         uint32_t *viewCountOutput, XrView *views) {

    XrResult result = populate_("xrLocateViews", pfnLocateViews);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrLocateViews>(pfnLocateViews))(
        session, viewLocateInfo, viewState, viewCapacityInput, viewCountOutput,
        views);
  }

  //! @brief Call xrLocateViews (const overload - does not populate function
  //! pointer)
  XrResult xrLocateViews(XrSession session,
                         const XrViewLocateInfo *viewLocateInfo,
                         XrViewState *viewState, uint32_t viewCapacityInput,
                         uint32_t *viewCountOutput, XrView *views) const {

    return (reinterpret_cast<PFN_xrLocateViews>(pfnLocateViews))(
        session, viewLocateInfo, viewState, viewCapacityInput, viewCountOutput,
        views);
  }

  //! @brief Call xrStringToPath, populating function pointer if required.
  XrResult xrStringToPath(XrInstance instance, const char *pathString,
                          XrPath *path) {

    XrResult result = populate_("xrStringToPath", pfnStringToPath);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrStringToPath>(pfnStringToPath))(
        instance, pathString, path);
  }

  //! @brief Call xrStringToPath (const overload - does not populate function
  //! pointer)
  XrResult xrStringToPath(XrInstance instance, const char *pathString,
                          XrPath *path) const {

    return (reinterpret_cast<PFN_xrStringToPath>(pfnStringToPath))(
        instance, pathString, path);
  }

  //! @brief Call xrPathToString, populating function pointer if required.
  XrResult xrPathToString(XrInstance instance, XrPath path,
                          uint32_t bufferCapacityInput,
                          uint32_t *bufferCountOutput, char *buffer) {

    XrResult result = populate_("xrPathToString", pfnPathToString);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrPathToString>(pfnPathToString))(
        instance, path, bufferCapacityInput, bufferCountOutput, buffer);
  }

  //! @brief Call xrPathToString (const overload - does not populate function
  //! pointer)
  XrResult xrPathToString(XrInstance instance, XrPath path,
                          uint32_t bufferCapacityInput,
                          uint32_t *bufferCountOutput, char *buffer) const {

    return (reinterpret_cast<PFN_xrPathToString>(pfnPathToString))(
        instance, path, bufferCapacityInput, bufferCountOutput, buffer);
  }

  //! @brief Call xrCreateActionSet, populating function pointer if required.
  XrResult xrCreateActionSet(XrInstance instance,
                             const XrActionSetCreateInfo *createInfo,
                             XrActionSet *actionSet) {

    XrResult result = populate_("xrCreateActionSet", pfnCreateActionSet);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrCreateActionSet>(pfnCreateActionSet))(
        instance, createInfo, actionSet);
  }

  //! @brief Call xrCreateActionSet (const overload - does not populate function
  //! pointer)
  XrResult xrCreateActionSet(XrInstance instance,
                             const XrActionSetCreateInfo *createInfo,
                             XrActionSet *actionSet) const {

    return (reinterpret_cast<PFN_xrCreateActionSet>(pfnCreateActionSet))(
        instance, createInfo, actionSet);
  }

  //! @brief Call xrDestroyActionSet, populating function pointer if required.
  XrResult xrDestroyActionSet(XrActionSet actionSet) {

    XrResult result = populate_("xrDestroyActionSet", pfnDestroyActionSet);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrDestroyActionSet>(pfnDestroyActionSet))(
        actionSet);
  }

  //! @brief Call xrDestroyActionSet (const overload - does not populate
  //! function pointer)
  XrResult xrDestroyActionSet(XrActionSet actionSet) const {

    return (reinterpret_cast<PFN_xrDestroyActionSet>(pfnDestroyActionSet))(
        actionSet);
  }

  //! @brief Call xrCreateAction, populating function pointer if required.
  XrResult xrCreateAction(XrActionSet actionSet,
                          const XrActionCreateInfo *createInfo,
                          XrAction *action) {

    XrResult result = populate_("xrCreateAction", pfnCreateAction);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrCreateAction>(pfnCreateAction))(
        actionSet, createInfo, action);
  }

  //! @brief Call xrCreateAction (const overload - does not populate function
  //! pointer)
  XrResult xrCreateAction(XrActionSet actionSet,
                          const XrActionCreateInfo *createInfo,
                          XrAction *action) const {

    return (reinterpret_cast<PFN_xrCreateAction>(pfnCreateAction))(
        actionSet, createInfo, action);
  }

  //! @brief Call xrDestroyAction, populating function pointer if required.
  XrResult xrDestroyAction(XrAction action) {

    XrResult result = populate_("xrDestroyAction", pfnDestroyAction);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrDestroyAction>(pfnDestroyAction))(action);
  }

  //! @brief Call xrDestroyAction (const overload - does not populate function
  //! pointer)
  XrResult xrDestroyAction(XrAction action) const {

    return (reinterpret_cast<PFN_xrDestroyAction>(pfnDestroyAction))(action);
  }

  //! @brief Call xrSuggestInteractionProfileBindings, populating function
  //! pointer if required.
  XrResult xrSuggestInteractionProfileBindings(
      XrInstance instance,
      const XrInteractionProfileSuggestedBinding *suggestedBindings) {

    XrResult result = populate_("xrSuggestInteractionProfileBindings",
                                pfnSuggestInteractionProfileBindings);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrSuggestInteractionProfileBindings>(
        pfnSuggestInteractionProfileBindings))(instance, suggestedBindings);
  }

  //! @brief Call xrSuggestInteractionProfileBindings (const overload - does not
  //! populate function pointer)
  XrResult xrSuggestInteractionProfileBindings(
      XrInstance instance,
      const XrInteractionProfileSuggestedBinding *suggestedBindings) const {

    return (reinterpret_cast<PFN_xrSuggestInteractionProfileBindings>(
        pfnSuggestInteractionProfileBindings))(instance, suggestedBindings);
  }

  //! @brief Call xrAttachSessionActionSets, populating function pointer if
  //! required.
  XrResult
  xrAttachSessionActionSets(XrSession session,
                            const XrSessionActionSetsAttachInfo *attachInfo) {

    XrResult result =
        populate_("xrAttachSessionActionSets", pfnAttachSessionActionSets);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrAttachSessionActionSets>(
        pfnAttachSessionActionSets))(session, attachInfo);
  }

  //! @brief Call xrAttachSessionActionSets (const overload - does not populate
  //! function pointer)
  XrResult xrAttachSessionActionSets(
      XrSession session,
      const XrSessionActionSetsAttachInfo *attachInfo) const {

    return (reinterpret_cast<PFN_xrAttachSessionActionSets>(
        pfnAttachSessionActionSets))(session, attachInfo);
  }

  //! @brief Call xrGetCurrentInteractionProfile, populating function pointer if
  //! required.
  XrResult xrGetCurrentInteractionProfile(
      XrSession session, XrPath topLevelUserPath,
      XrInteractionProfileState *interactionProfile) {

    XrResult result = populate_("xrGetCurrentInteractionProfile",
                                pfnGetCurrentInteractionProfile);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetCurrentInteractionProfile>(
        pfnGetCurrentInteractionProfile))(session, topLevelUserPath,
                                          interactionProfile);
  }

  //! @brief Call xrGetCurrentInteractionProfile (const overload - does not
  //! populate function pointer)
  XrResult xrGetCurrentInteractionProfile(
      XrSession session, XrPath topLevelUserPath,
      XrInteractionProfileState *interactionProfile) const {

    return (reinterpret_cast<PFN_xrGetCurrentInteractionProfile>(
        pfnGetCurrentInteractionProfile))(session, topLevelUserPath,
                                          interactionProfile);
  }

  //! @brief Call xrGetActionStateBoolean, populating function pointer if
  //! required.
  XrResult xrGetActionStateBoolean(XrSession session,
                                   const XrActionStateGetInfo *getInfo,
                                   XrActionStateBoolean *state) {

    XrResult result =
        populate_("xrGetActionStateBoolean", pfnGetActionStateBoolean);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetActionStateBoolean>(
        pfnGetActionStateBoolean))(session, getInfo, state);
  }

  //! @brief Call xrGetActionStateBoolean (const overload - does not populate
  //! function pointer)
  XrResult xrGetActionStateBoolean(XrSession session,
                                   const XrActionStateGetInfo *getInfo,
                                   XrActionStateBoolean *state) const {

    return (reinterpret_cast<PFN_xrGetActionStateBoolean>(
        pfnGetActionStateBoolean))(session, getInfo, state);
  }

  //! @brief Call xrGetActionStateFloat, populating function pointer if
  //! required.
  XrResult xrGetActionStateFloat(XrSession session,
                                 const XrActionStateGetInfo *getInfo,
                                 XrActionStateFloat *state) {

    XrResult result =
        populate_("xrGetActionStateFloat", pfnGetActionStateFloat);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetActionStateFloat>(
        pfnGetActionStateFloat))(session, getInfo, state);
  }

  //! @brief Call xrGetActionStateFloat (const overload - does not populate
  //! function pointer)
  XrResult xrGetActionStateFloat(XrSession session,
                                 const XrActionStateGetInfo *getInfo,
                                 XrActionStateFloat *state) const {

    return (reinterpret_cast<PFN_xrGetActionStateFloat>(
        pfnGetActionStateFloat))(session, getInfo, state);
  }

  //! @brief Call xrGetActionStateVector2f, populating function pointer if
  //! required.
  XrResult xrGetActionStateVector2f(XrSession session,
                                    const XrActionStateGetInfo *getInfo,
                                    XrActionStateVector2f *state) {

    XrResult result =
        populate_("xrGetActionStateVector2f", pfnGetActionStateVector2f);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetActionStateVector2f>(
        pfnGetActionStateVector2f))(session, getInfo, state);
  }

  //! @brief Call xrGetActionStateVector2f (const overload - does not populate
  //! function pointer)
  XrResult xrGetActionStateVector2f(XrSession session,
                                    const XrActionStateGetInfo *getInfo,
                                    XrActionStateVector2f *state) const {

    return (reinterpret_cast<PFN_xrGetActionStateVector2f>(
        pfnGetActionStateVector2f))(session, getInfo, state);
  }

  //! @brief Call xrGetActionStatePose, populating function pointer if required.
  XrResult xrGetActionStatePose(XrSession session,
                                const XrActionStateGetInfo *getInfo,
                                XrActionStatePose *state) {

    XrResult result = populate_("xrGetActionStatePose", pfnGetActionStatePose);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetActionStatePose>(pfnGetActionStatePose))(
        session, getInfo, state);
  }

  //! @brief Call xrGetActionStatePose (const overload - does not populate
  //! function pointer)
  XrResult xrGetActionStatePose(XrSession session,
                                const XrActionStateGetInfo *getInfo,
                                XrActionStatePose *state) const {

    return (reinterpret_cast<PFN_xrGetActionStatePose>(pfnGetActionStatePose))(
        session, getInfo, state);
  }

  //! @brief Call xrSyncActions, populating function pointer if required.
  XrResult xrSyncActions(XrSession session, const XrActionsSyncInfo *syncInfo) {

    XrResult result = populate_("xrSyncActions", pfnSyncActions);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrSyncActions>(pfnSyncActions))(session,
                                                                 syncInfo);
  }

  //! @brief Call xrSyncActions (const overload - does not populate function
  //! pointer)
  XrResult xrSyncActions(XrSession session,
                         const XrActionsSyncInfo *syncInfo) const {

    return (reinterpret_cast<PFN_xrSyncActions>(pfnSyncActions))(session,
                                                                 syncInfo);
  }

  //! @brief Call xrEnumerateBoundSourcesForAction, populating function pointer
  //! if required.
  XrResult xrEnumerateBoundSourcesForAction(
      XrSession session,
      const XrBoundSourcesForActionEnumerateInfo *enumerateInfo,
      uint32_t sourceCapacityInput, uint32_t *sourceCountOutput,
      XrPath *sources) {

    XrResult result = populate_("xrEnumerateBoundSourcesForAction",
                                pfnEnumerateBoundSourcesForAction);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrEnumerateBoundSourcesForAction>(
        pfnEnumerateBoundSourcesForAction))(session, enumerateInfo,
                                            sourceCapacityInput,
                                            sourceCountOutput, sources);
  }

  //! @brief Call xrEnumerateBoundSourcesForAction (const overload - does not
  //! populate function pointer)
  XrResult xrEnumerateBoundSourcesForAction(
      XrSession session,
      const XrBoundSourcesForActionEnumerateInfo *enumerateInfo,
      uint32_t sourceCapacityInput, uint32_t *sourceCountOutput,
      XrPath *sources) const {

    return (reinterpret_cast<PFN_xrEnumerateBoundSourcesForAction>(
        pfnEnumerateBoundSourcesForAction))(session, enumerateInfo,
                                            sourceCapacityInput,
                                            sourceCountOutput, sources);
  }

  //! @brief Call xrGetInputSourceLocalizedName, populating function pointer if
  //! required.
  XrResult xrGetInputSourceLocalizedName(
      XrSession session, const XrInputSourceLocalizedNameGetInfo *getInfo,
      uint32_t bufferCapacityInput, uint32_t *bufferCountOutput, char *buffer) {

    XrResult result = populate_("xrGetInputSourceLocalizedName",
                                pfnGetInputSourceLocalizedName);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetInputSourceLocalizedName>(
        pfnGetInputSourceLocalizedName))(session, getInfo, bufferCapacityInput,
                                         bufferCountOutput, buffer);
  }

  //! @brief Call xrGetInputSourceLocalizedName (const overload - does not
  //! populate function pointer)
  XrResult xrGetInputSourceLocalizedName(
      XrSession session, const XrInputSourceLocalizedNameGetInfo *getInfo,
      uint32_t bufferCapacityInput, uint32_t *bufferCountOutput,
      char *buffer) const {

    return (reinterpret_cast<PFN_xrGetInputSourceLocalizedName>(
        pfnGetInputSourceLocalizedName))(session, getInfo, bufferCapacityInput,
                                         bufferCountOutput, buffer);
  }

  //! @brief Call xrApplyHapticFeedback, populating function pointer if
  //! required.
  XrResult xrApplyHapticFeedback(XrSession session,
                                 const XrHapticActionInfo *hapticActionInfo,
                                 const XrHapticBaseHeader *hapticFeedback) {

    XrResult result =
        populate_("xrApplyHapticFeedback", pfnApplyHapticFeedback);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrApplyHapticFeedback>(
        pfnApplyHapticFeedback))(session, hapticActionInfo, hapticFeedback);
  }

  //! @brief Call xrApplyHapticFeedback (const overload - does not populate
  //! function pointer)
  XrResult
  xrApplyHapticFeedback(XrSession session,
                        const XrHapticActionInfo *hapticActionInfo,
                        const XrHapticBaseHeader *hapticFeedback) const {

    return (reinterpret_cast<PFN_xrApplyHapticFeedback>(
        pfnApplyHapticFeedback))(session, hapticActionInfo, hapticFeedback);
  }

  //! @brief Call xrStopHapticFeedback, populating function pointer if required.
  XrResult xrStopHapticFeedback(XrSession session,
                                const XrHapticActionInfo *hapticActionInfo) {

    XrResult result = populate_("xrStopHapticFeedback", pfnStopHapticFeedback);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrStopHapticFeedback>(pfnStopHapticFeedback))(
        session, hapticActionInfo);
  }

  //! @brief Call xrStopHapticFeedback (const overload - does not populate
  //! function pointer)
  XrResult
  xrStopHapticFeedback(XrSession session,
                       const XrHapticActionInfo *hapticActionInfo) const {

    return (reinterpret_cast<PFN_xrStopHapticFeedback>(pfnStopHapticFeedback))(
        session, hapticActionInfo);
  }

#if defined(XR_USE_PLATFORM_ANDROID)
  //! @brief Call xrSetAndroidApplicationThreadKHR, populating function pointer
  //! if required.
  XrResult xrSetAndroidApplicationThreadKHR(XrSession session,
                                            XrAndroidThreadTypeKHR threadType,
                                            uint32_t threadId) {

    XrResult result = populate_("xrSetAndroidApplicationThreadKHR",
                                pfnSetAndroidApplicationThreadKHR);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrSetAndroidApplicationThreadKHR>(
        pfnSetAndroidApplicationThreadKHR))(session, threadType, threadId);
  }

  //! @brief Call xrSetAndroidApplicationThreadKHR (const overload - does not
  //! populate function pointer)
  XrResult xrSetAndroidApplicationThreadKHR(XrSession session,
                                            XrAndroidThreadTypeKHR threadType,
                                            uint32_t threadId) const {

    return (reinterpret_cast<PFN_xrSetAndroidApplicationThreadKHR>(
        pfnSetAndroidApplicationThreadKHR))(session, threadType, threadId);
  }
#endif // defined(XR_USE_PLATFORM_ANDROID)

#if defined(XR_USE_PLATFORM_ANDROID)
  //! @brief Call xrCreateSwapchainAndroidSurfaceKHR, populating function
  //! pointer if required.
  XrResult xrCreateSwapchainAndroidSurfaceKHR(XrSession session,
                                              const XrSwapchainCreateInfo *info,
                                              XrSwapchain *swapchain,
                                              jobject *surface) {

    XrResult result = populate_("xrCreateSwapchainAndroidSurfaceKHR",
                                pfnCreateSwapchainAndroidSurfaceKHR);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrCreateSwapchainAndroidSurfaceKHR>(
        pfnCreateSwapchainAndroidSurfaceKHR))(session, info, swapchain,
                                              surface);
  }

  //! @brief Call xrCreateSwapchainAndroidSurfaceKHR (const overload - does not
  //! populate function pointer)
  XrResult xrCreateSwapchainAndroidSurfaceKHR(XrSession session,
                                              const XrSwapchainCreateInfo *info,
                                              XrSwapchain *swapchain,
                                              jobject *surface) const {

    return (reinterpret_cast<PFN_xrCreateSwapchainAndroidSurfaceKHR>(
        pfnCreateSwapchainAndroidSurfaceKHR))(session, info, swapchain,
                                              surface);
  }
#endif // defined(XR_USE_PLATFORM_ANDROID)

#if defined(XR_USE_GRAPHICS_API_OPENGL)
  //! @brief Call xrGetOpenGLGraphicsRequirementsKHR, populating function
  //! pointer if required.
  XrResult xrGetOpenGLGraphicsRequirementsKHR(
      XrInstance instance, XrSystemId systemId,
      XrGraphicsRequirementsOpenGLKHR *graphicsRequirements) {

    XrResult result = populate_("xrGetOpenGLGraphicsRequirementsKHR",
                                pfnGetOpenGLGraphicsRequirementsKHR);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetOpenGLGraphicsRequirementsKHR>(
        pfnGetOpenGLGraphicsRequirementsKHR))(instance, systemId,
                                              graphicsRequirements);
  }

  //! @brief Call xrGetOpenGLGraphicsRequirementsKHR (const overload - does not
  //! populate function pointer)
  XrResult xrGetOpenGLGraphicsRequirementsKHR(
      XrInstance instance, XrSystemId systemId,
      XrGraphicsRequirementsOpenGLKHR *graphicsRequirements) const {

    return (reinterpret_cast<PFN_xrGetOpenGLGraphicsRequirementsKHR>(
        pfnGetOpenGLGraphicsRequirementsKHR))(instance, systemId,
                                              graphicsRequirements);
  }
#endif // defined(XR_USE_GRAPHICS_API_OPENGL)

#if defined(XR_USE_GRAPHICS_API_OPENGL_ES)
  //! @brief Call xrGetOpenGLESGraphicsRequirementsKHR, populating function
  //! pointer if required.
  XrResult xrGetOpenGLESGraphicsRequirementsKHR(
      XrInstance instance, XrSystemId systemId,
      XrGraphicsRequirementsOpenGLESKHR *graphicsRequirements) {

    XrResult result = populate_("xrGetOpenGLESGraphicsRequirementsKHR",
                                pfnGetOpenGLESGraphicsRequirementsKHR);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetOpenGLESGraphicsRequirementsKHR>(
        pfnGetOpenGLESGraphicsRequirementsKHR))(instance, systemId,
                                                graphicsRequirements);
  }

  //! @brief Call xrGetOpenGLESGraphicsRequirementsKHR (const overload - does
  //! not populate function pointer)
  XrResult xrGetOpenGLESGraphicsRequirementsKHR(
      XrInstance instance, XrSystemId systemId,
      XrGraphicsRequirementsOpenGLESKHR *graphicsRequirements) const {

    return (reinterpret_cast<PFN_xrGetOpenGLESGraphicsRequirementsKHR>(
        pfnGetOpenGLESGraphicsRequirementsKHR))(instance, systemId,
                                                graphicsRequirements);
  }
#endif // defined(XR_USE_GRAPHICS_API_OPENGL_ES)

#if defined(XR_USE_GRAPHICS_API_VULKAN)
  //! @brief Call xrGetVulkanInstanceExtensionsKHR, populating function pointer
  //! if required.
  XrResult xrGetVulkanInstanceExtensionsKHR(XrInstance instance,
                                            XrSystemId systemId,
                                            uint32_t bufferCapacityInput,
                                            uint32_t *bufferCountOutput,
                                            char *buffer) {

    XrResult result = populate_("xrGetVulkanInstanceExtensionsKHR",
                                pfnGetVulkanInstanceExtensionsKHR);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetVulkanInstanceExtensionsKHR>(
        pfnGetVulkanInstanceExtensionsKHR))(
        instance, systemId, bufferCapacityInput, bufferCountOutput, buffer);
  }

  //! @brief Call xrGetVulkanInstanceExtensionsKHR (const overload - does not
  //! populate function pointer)
  XrResult xrGetVulkanInstanceExtensionsKHR(XrInstance instance,
                                            XrSystemId systemId,
                                            uint32_t bufferCapacityInput,
                                            uint32_t *bufferCountOutput,
                                            char *buffer) const {

    return (reinterpret_cast<PFN_xrGetVulkanInstanceExtensionsKHR>(
        pfnGetVulkanInstanceExtensionsKHR))(
        instance, systemId, bufferCapacityInput, bufferCountOutput, buffer);
  }
#endif // defined(XR_USE_GRAPHICS_API_VULKAN)

#if defined(XR_USE_GRAPHICS_API_VULKAN)
  //! @brief Call xrGetVulkanDeviceExtensionsKHR, populating function pointer if
  //! required.
  XrResult xrGetVulkanDeviceExtensionsKHR(XrInstance instance,
                                          XrSystemId systemId,
                                          uint32_t bufferCapacityInput,
                                          uint32_t *bufferCountOutput,
                                          char *buffer) {

    XrResult result = populate_("xrGetVulkanDeviceExtensionsKHR",
                                pfnGetVulkanDeviceExtensionsKHR);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetVulkanDeviceExtensionsKHR>(
        pfnGetVulkanDeviceExtensionsKHR))(
        instance, systemId, bufferCapacityInput, bufferCountOutput, buffer);
  }

  //! @brief Call xrGetVulkanDeviceExtensionsKHR (const overload - does not
  //! populate function pointer)
  XrResult xrGetVulkanDeviceExtensionsKHR(XrInstance instance,
                                          XrSystemId systemId,
                                          uint32_t bufferCapacityInput,
                                          uint32_t *bufferCountOutput,
                                          char *buffer) const {

    return (reinterpret_cast<PFN_xrGetVulkanDeviceExtensionsKHR>(
        pfnGetVulkanDeviceExtensionsKHR))(
        instance, systemId, bufferCapacityInput, bufferCountOutput, buffer);
  }
#endif // defined(XR_USE_GRAPHICS_API_VULKAN)

#if defined(XR_USE_GRAPHICS_API_VULKAN)
  //! @brief Call xrGetVulkanGraphicsDeviceKHR, populating function pointer if
  //! required.
  XrResult xrGetVulkanGraphicsDeviceKHR(XrInstance instance,
                                        XrSystemId systemId,
                                        VkInstance vkInstance,
                                        VkPhysicalDevice *vkPhysicalDevice) {

    XrResult result = populate_("xrGetVulkanGraphicsDeviceKHR",
                                pfnGetVulkanGraphicsDeviceKHR);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetVulkanGraphicsDeviceKHR>(
        pfnGetVulkanGraphicsDeviceKHR))(instance, systemId, vkInstance,
                                        vkPhysicalDevice);
  }

  //! @brief Call xrGetVulkanGraphicsDeviceKHR (const overload - does not
  //! populate function pointer)
  XrResult
  xrGetVulkanGraphicsDeviceKHR(XrInstance instance, XrSystemId systemId,
                               VkInstance vkInstance,
                               VkPhysicalDevice *vkPhysicalDevice) const {

    return (reinterpret_cast<PFN_xrGetVulkanGraphicsDeviceKHR>(
        pfnGetVulkanGraphicsDeviceKHR))(instance, systemId, vkInstance,
                                        vkPhysicalDevice);
  }
#endif // defined(XR_USE_GRAPHICS_API_VULKAN)

#if defined(XR_USE_GRAPHICS_API_VULKAN)
  //! @brief Call xrGetVulkanGraphicsRequirementsKHR, populating function
  //! pointer if required.
  XrResult xrGetVulkanGraphicsRequirementsKHR(
      XrInstance instance, XrSystemId systemId,
      XrGraphicsRequirementsVulkanKHR *graphicsRequirements) {

    XrResult result = populate_("xrGetVulkanGraphicsRequirementsKHR",
                                pfnGetVulkanGraphicsRequirementsKHR);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetVulkanGraphicsRequirementsKHR>(
        pfnGetVulkanGraphicsRequirementsKHR))(instance, systemId,
                                              graphicsRequirements);
  }

  //! @brief Call xrGetVulkanGraphicsRequirementsKHR (const overload - does not
  //! populate function pointer)
  XrResult xrGetVulkanGraphicsRequirementsKHR(
      XrInstance instance, XrSystemId systemId,
      XrGraphicsRequirementsVulkanKHR *graphicsRequirements) const {

    return (reinterpret_cast<PFN_xrGetVulkanGraphicsRequirementsKHR>(
        pfnGetVulkanGraphicsRequirementsKHR))(instance, systemId,
                                              graphicsRequirements);
  }
#endif // defined(XR_USE_GRAPHICS_API_VULKAN)

#if defined(XR_USE_GRAPHICS_API_D3D11)
  //! @brief Call xrGetD3D11GraphicsRequirementsKHR, populating function pointer
  //! if required.
  XrResult xrGetD3D11GraphicsRequirementsKHR(
      XrInstance instance, XrSystemId systemId,
      XrGraphicsRequirementsD3D11KHR *graphicsRequirements) {

    XrResult result = populate_("xrGetD3D11GraphicsRequirementsKHR",
                                pfnGetD3D11GraphicsRequirementsKHR);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetD3D11GraphicsRequirementsKHR>(
        pfnGetD3D11GraphicsRequirementsKHR))(instance, systemId,
                                             graphicsRequirements);
  }

  //! @brief Call xrGetD3D11GraphicsRequirementsKHR (const overload - does not
  //! populate function pointer)
  XrResult xrGetD3D11GraphicsRequirementsKHR(
      XrInstance instance, XrSystemId systemId,
      XrGraphicsRequirementsD3D11KHR *graphicsRequirements) const {

    return (reinterpret_cast<PFN_xrGetD3D11GraphicsRequirementsKHR>(
        pfnGetD3D11GraphicsRequirementsKHR))(instance, systemId,
                                             graphicsRequirements);
  }
#endif // defined(XR_USE_GRAPHICS_API_D3D11)

#if defined(XR_USE_GRAPHICS_API_D3D12)
  //! @brief Call xrGetD3D12GraphicsRequirementsKHR, populating function pointer
  //! if required.
  XrResult xrGetD3D12GraphicsRequirementsKHR(
      XrInstance instance, XrSystemId systemId,
      XrGraphicsRequirementsD3D12KHR *graphicsRequirements) {

    XrResult result = populate_("xrGetD3D12GraphicsRequirementsKHR",
                                pfnGetD3D12GraphicsRequirementsKHR);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetD3D12GraphicsRequirementsKHR>(
        pfnGetD3D12GraphicsRequirementsKHR))(instance, systemId,
                                             graphicsRequirements);
  }

  //! @brief Call xrGetD3D12GraphicsRequirementsKHR (const overload - does not
  //! populate function pointer)
  XrResult xrGetD3D12GraphicsRequirementsKHR(
      XrInstance instance, XrSystemId systemId,
      XrGraphicsRequirementsD3D12KHR *graphicsRequirements) const {

    return (reinterpret_cast<PFN_xrGetD3D12GraphicsRequirementsKHR>(
        pfnGetD3D12GraphicsRequirementsKHR))(instance, systemId,
                                             graphicsRequirements);
  }
#endif // defined(XR_USE_GRAPHICS_API_D3D12)

  //! @brief Call xrGetVisibilityMaskKHR, populating function pointer if
  //! required.
  XrResult xrGetVisibilityMaskKHR(XrSession session,
                                  XrViewConfigurationType viewConfigurationType,
                                  uint32_t viewIndex,
                                  XrVisibilityMaskTypeKHR visibilityMaskType,
                                  XrVisibilityMaskKHR *visibilityMask) {

    XrResult result =
        populate_("xrGetVisibilityMaskKHR", pfnGetVisibilityMaskKHR);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrGetVisibilityMaskKHR>(
        pfnGetVisibilityMaskKHR))(session, viewConfigurationType, viewIndex,
                                  visibilityMaskType, visibilityMask);
  }

  //! @brief Call xrGetVisibilityMaskKHR (const overload - does not populate
  //! function pointer)
  XrResult xrGetVisibilityMaskKHR(XrSession session,
                                  XrViewConfigurationType viewConfigurationType,
                                  uint32_t viewIndex,
                                  XrVisibilityMaskTypeKHR visibilityMaskType,
                                  XrVisibilityMaskKHR *visibilityMask) const {

    return (reinterpret_cast<PFN_xrGetVisibilityMaskKHR>(
        pfnGetVisibilityMaskKHR))(session, viewConfigurationType, viewIndex,
                                  visibilityMaskType, visibilityMask);
  }

#if defined(XR_USE_PLATFORM_WIN32)
  //! @brief Call xrConvertWin32PerformanceCounterToTimeKHR, populating function
  //! pointer if required.
  XrResult xrConvertWin32PerformanceCounterToTimeKHR(
      XrInstance instance, const LARGE_INTEGER *performanceCounter,
      XrTime *time) {

    XrResult result = populate_("xrConvertWin32PerformanceCounterToTimeKHR",
                                pfnConvertWin32PerformanceCounterToTimeKHR);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrConvertWin32PerformanceCounterToTimeKHR>(
        pfnConvertWin32PerformanceCounterToTimeKHR))(instance,
                                                     performanceCounter, time);
  }

  //! @brief Call xrConvertWin32PerformanceCounterToTimeKHR (const overload -
  //! does not populate function pointer)
  XrResult xrConvertWin32PerformanceCounterToTimeKHR(
      XrInstance instance, const LARGE_INTEGER *performanceCounter,
      XrTime *time) const {

    return (reinterpret_cast<PFN_xrConvertWin32PerformanceCounterToTimeKHR>(
        pfnConvertWin32PerformanceCounterToTimeKHR))(instance,
                                                     performanceCounter, time);
  }
#endif // defined(XR_USE_PLATFORM_WIN32)

#if defined(XR_USE_PLATFORM_WIN32)
  //! @brief Call xrConvertTimeToWin32PerformanceCounterKHR, populating function
  //! pointer if required.
  XrResult
  xrConvertTimeToWin32PerformanceCounterKHR(XrInstance instance, XrTime time,
                                            LARGE_INTEGER *performanceCounter) {

    XrResult result = populate_("xrConvertTimeToWin32PerformanceCounterKHR",
                                pfnConvertTimeToWin32PerformanceCounterKHR);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrConvertTimeToWin32PerformanceCounterKHR>(
        pfnConvertTimeToWin32PerformanceCounterKHR))(instance, time,
                                                     performanceCounter);
  }

  //! @brief Call xrConvertTimeToWin32PerformanceCounterKHR (const overload -
  //! does not populate function pointer)
  XrResult xrConvertTimeToWin32PerformanceCounterKHR(
      XrInstance instance, XrTime time,
      LARGE_INTEGER *performanceCounter) const {

    return (reinterpret_cast<PFN_xrConvertTimeToWin32PerformanceCounterKHR>(
        pfnConvertTimeToWin32PerformanceCounterKHR))(instance, time,
                                                     performanceCounter);
  }
#endif // defined(XR_USE_PLATFORM_WIN32)

#if defined(XR_USE_TIMESPEC)
  //! @brief Call xrConvertTimespecTimeToTimeKHR, populating function pointer if
  //! required.
  XrResult xrConvertTimespecTimeToTimeKHR(XrInstance instance,
                                          const struct timespec *timespecTime,
                                          XrTime *time) {

    XrResult result = populate_("xrConvertTimespecTimeToTimeKHR",
                                pfnConvertTimespecTimeToTimeKHR);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrConvertTimespecTimeToTimeKHR>(
        pfnConvertTimespecTimeToTimeKHR))(instance, timespecTime, time);
  }

  //! @brief Call xrConvertTimespecTimeToTimeKHR (const overload - does not
  //! populate function pointer)
  XrResult xrConvertTimespecTimeToTimeKHR(XrInstance instance,
                                          const struct timespec *timespecTime,
                                          XrTime *time) const {

    return (reinterpret_cast<PFN_xrConvertTimespecTimeToTimeKHR>(
        pfnConvertTimespecTimeToTimeKHR))(instance, timespecTime, time);
  }
#endif // defined(XR_USE_TIMESPEC)

#if defined(XR_USE_TIMESPEC)
  //! @brief Call xrConvertTimeToTimespecTimeKHR, populating function pointer if
  //! required.
  XrResult xrConvertTimeToTimespecTimeKHR(XrInstance instance, XrTime time,
                                          struct timespec *timespecTime) {

    XrResult result = populate_("xrConvertTimeToTimespecTimeKHR",
                                pfnConvertTimeToTimespecTimeKHR);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrConvertTimeToTimespecTimeKHR>(
        pfnConvertTimeToTimespecTimeKHR))(instance, time, timespecTime);
  }

  //! @brief Call xrConvertTimeToTimespecTimeKHR (const overload - does not
  //! populate function pointer)
  XrResult xrConvertTimeToTimespecTimeKHR(XrInstance instance, XrTime time,
                                          struct timespec *timespecTime) const {

    return (reinterpret_cast<PFN_xrConvertTimeToTimespecTimeKHR>(
        pfnConvertTimeToTimespecTimeKHR))(instance, time, timespecTime);
  }
#endif // defined(XR_USE_TIMESPEC)

  //! @brief Call xrPerfSettingsSetPerformanceLevelEXT, populating function
  //! pointer if required.
  XrResult xrPerfSettingsSetPerformanceLevelEXT(XrSession session,
                                                XrPerfSettingsDomainEXT domain,
                                                XrPerfSettingsLevelEXT level) {

    XrResult result = populate_("xrPerfSettingsSetPerformanceLevelEXT",
                                pfnPerfSettingsSetPerformanceLevelEXT);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrPerfSettingsSetPerformanceLevelEXT>(
        pfnPerfSettingsSetPerformanceLevelEXT))(session, domain, level);
  }

  //! @brief Call xrPerfSettingsSetPerformanceLevelEXT (const overload - does
  //! not populate function pointer)
  XrResult
  xrPerfSettingsSetPerformanceLevelEXT(XrSession session,
                                       XrPerfSettingsDomainEXT domain,
                                       XrPerfSettingsLevelEXT level) const {

    return (reinterpret_cast<PFN_xrPerfSettingsSetPerformanceLevelEXT>(
        pfnPerfSettingsSetPerformanceLevelEXT))(session, domain, level);
  }

  //! @brief Call xrThermalGetTemperatureTrendEXT, populating function pointer
  //! if required.
  XrResult xrThermalGetTemperatureTrendEXT(
      XrSession session, XrPerfSettingsDomainEXT domain,
      XrPerfSettingsNotificationLevelEXT *notificationLevel,
      float *tempHeadroom, float *tempSlope) {

    XrResult result = populate_("xrThermalGetTemperatureTrendEXT",
                                pfnThermalGetTemperatureTrendEXT);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrThermalGetTemperatureTrendEXT>(
        pfnThermalGetTemperatureTrendEXT))(session, domain, notificationLevel,
                                           tempHeadroom, tempSlope);
  }

  //! @brief Call xrThermalGetTemperatureTrendEXT (const overload - does not
  //! populate function pointer)
  XrResult xrThermalGetTemperatureTrendEXT(
      XrSession session, XrPerfSettingsDomainEXT domain,
      XrPerfSettingsNotificationLevelEXT *notificationLevel,
      float *tempHeadroom, float *tempSlope) const {

    return (reinterpret_cast<PFN_xrThermalGetTemperatureTrendEXT>(
        pfnThermalGetTemperatureTrendEXT))(session, domain, notificationLevel,
                                           tempHeadroom, tempSlope);
  }

  //! @brief Call xrSetDebugUtilsObjectNameEXT, populating function pointer if
  //! required.
  XrResult
  xrSetDebugUtilsObjectNameEXT(XrInstance instance,
                               const XrDebugUtilsObjectNameInfoEXT *nameInfo) {

    XrResult result = populate_("xrSetDebugUtilsObjectNameEXT",
                                pfnSetDebugUtilsObjectNameEXT);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrSetDebugUtilsObjectNameEXT>(
        pfnSetDebugUtilsObjectNameEXT))(instance, nameInfo);
  }

  //! @brief Call xrSetDebugUtilsObjectNameEXT (const overload - does not
  //! populate function pointer)
  XrResult xrSetDebugUtilsObjectNameEXT(
      XrInstance instance,
      const XrDebugUtilsObjectNameInfoEXT *nameInfo) const {

    return (reinterpret_cast<PFN_xrSetDebugUtilsObjectNameEXT>(
        pfnSetDebugUtilsObjectNameEXT))(instance, nameInfo);
  }

  //! @brief Call xrCreateDebugUtilsMessengerEXT, populating function pointer if
  //! required.
  XrResult xrCreateDebugUtilsMessengerEXT(
      XrInstance instance, const XrDebugUtilsMessengerCreateInfoEXT *createInfo,
      XrDebugUtilsMessengerEXT *messenger) {

    XrResult result = populate_("xrCreateDebugUtilsMessengerEXT",
                                pfnCreateDebugUtilsMessengerEXT);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrCreateDebugUtilsMessengerEXT>(
        pfnCreateDebugUtilsMessengerEXT))(instance, createInfo, messenger);
  }

  //! @brief Call xrCreateDebugUtilsMessengerEXT (const overload - does not
  //! populate function pointer)
  XrResult xrCreateDebugUtilsMessengerEXT(
      XrInstance instance, const XrDebugUtilsMessengerCreateInfoEXT *createInfo,
      XrDebugUtilsMessengerEXT *messenger) const {

    return (reinterpret_cast<PFN_xrCreateDebugUtilsMessengerEXT>(
        pfnCreateDebugUtilsMessengerEXT))(instance, createInfo, messenger);
  }

  //! @brief Call xrDestroyDebugUtilsMessengerEXT, populating function pointer
  //! if required.
  XrResult xrDestroyDebugUtilsMessengerEXT(XrDebugUtilsMessengerEXT messenger) {

    XrResult result = populate_("xrDestroyDebugUtilsMessengerEXT",
                                pfnDestroyDebugUtilsMessengerEXT);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrDestroyDebugUtilsMessengerEXT>(
        pfnDestroyDebugUtilsMessengerEXT))(messenger);
  }

  //! @brief Call xrDestroyDebugUtilsMessengerEXT (const overload - does not
  //! populate function pointer)
  XrResult
  xrDestroyDebugUtilsMessengerEXT(XrDebugUtilsMessengerEXT messenger) const {

    return (reinterpret_cast<PFN_xrDestroyDebugUtilsMessengerEXT>(
        pfnDestroyDebugUtilsMessengerEXT))(messenger);
  }

  //! @brief Call xrSubmitDebugUtilsMessageEXT, populating function pointer if
  //! required.
  XrResult xrSubmitDebugUtilsMessageEXT(
      XrInstance instance, XrDebugUtilsMessageSeverityFlagsEXT messageSeverity,
      XrDebugUtilsMessageTypeFlagsEXT messageTypes,
      const XrDebugUtilsMessengerCallbackDataEXT *callbackData) {

    XrResult result = populate_("xrSubmitDebugUtilsMessageEXT",
                                pfnSubmitDebugUtilsMessageEXT);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrSubmitDebugUtilsMessageEXT>(
        pfnSubmitDebugUtilsMessageEXT))(instance, messageSeverity, messageTypes,
                                        callbackData);
  }

  //! @brief Call xrSubmitDebugUtilsMessageEXT (const overload - does not
  //! populate function pointer)
  XrResult xrSubmitDebugUtilsMessageEXT(
      XrInstance instance, XrDebugUtilsMessageSeverityFlagsEXT messageSeverity,
      XrDebugUtilsMessageTypeFlagsEXT messageTypes,
      const XrDebugUtilsMessengerCallbackDataEXT *callbackData) const {

    return (reinterpret_cast<PFN_xrSubmitDebugUtilsMessageEXT>(
        pfnSubmitDebugUtilsMessageEXT))(instance, messageSeverity, messageTypes,
                                        callbackData);
  }

  //! @brief Call xrSessionBeginDebugUtilsLabelRegionEXT, populating function
  //! pointer if required.
  XrResult xrSessionBeginDebugUtilsLabelRegionEXT(
      XrSession session, const XrDebugUtilsLabelEXT *labelInfo) {

    XrResult result = populate_("xrSessionBeginDebugUtilsLabelRegionEXT",
                                pfnSessionBeginDebugUtilsLabelRegionEXT);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrSessionBeginDebugUtilsLabelRegionEXT>(
        pfnSessionBeginDebugUtilsLabelRegionEXT))(session, labelInfo);
  }

  //! @brief Call xrSessionBeginDebugUtilsLabelRegionEXT (const overload - does
  //! not populate function pointer)
  XrResult xrSessionBeginDebugUtilsLabelRegionEXT(
      XrSession session, const XrDebugUtilsLabelEXT *labelInfo) const {

    return (reinterpret_cast<PFN_xrSessionBeginDebugUtilsLabelRegionEXT>(
        pfnSessionBeginDebugUtilsLabelRegionEXT))(session, labelInfo);
  }

  //! @brief Call xrSessionEndDebugUtilsLabelRegionEXT, populating function
  //! pointer if required.
  XrResult xrSessionEndDebugUtilsLabelRegionEXT(XrSession session) {

    XrResult result = populate_("xrSessionEndDebugUtilsLabelRegionEXT",
                                pfnSessionEndDebugUtilsLabelRegionEXT);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrSessionEndDebugUtilsLabelRegionEXT>(
        pfnSessionEndDebugUtilsLabelRegionEXT))(session);
  }

  //! @brief Call xrSessionEndDebugUtilsLabelRegionEXT (const overload - does
  //! not populate function pointer)
  XrResult xrSessionEndDebugUtilsLabelRegionEXT(XrSession session) const {

    return (reinterpret_cast<PFN_xrSessionEndDebugUtilsLabelRegionEXT>(
        pfnSessionEndDebugUtilsLabelRegionEXT))(session);
  }

  //! @brief Call xrSessionInsertDebugUtilsLabelEXT, populating function pointer
  //! if required.
  XrResult
  xrSessionInsertDebugUtilsLabelEXT(XrSession session,
                                    const XrDebugUtilsLabelEXT *labelInfo) {

    XrResult result = populate_("xrSessionInsertDebugUtilsLabelEXT",
                                pfnSessionInsertDebugUtilsLabelEXT);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrSessionInsertDebugUtilsLabelEXT>(
        pfnSessionInsertDebugUtilsLabelEXT))(session, labelInfo);
  }

  //! @brief Call xrSessionInsertDebugUtilsLabelEXT (const overload - does not
  //! populate function pointer)
  XrResult xrSessionInsertDebugUtilsLabelEXT(
      XrSession session, const XrDebugUtilsLabelEXT *labelInfo) const {

    return (reinterpret_cast<PFN_xrSessionInsertDebugUtilsLabelEXT>(
        pfnSessionInsertDebugUtilsLabelEXT))(session, labelInfo);
  }

  //! @brief Call xrCreateSpatialAnchorMSFT, populating function pointer if
  //! required.
  XrResult
  xrCreateSpatialAnchorMSFT(XrSession session,
                            const XrSpatialAnchorCreateInfoMSFT *createInfo,
                            XrSpatialAnchorMSFT *anchor) {

    XrResult result =
        populate_("xrCreateSpatialAnchorMSFT", pfnCreateSpatialAnchorMSFT);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrCreateSpatialAnchorMSFT>(
        pfnCreateSpatialAnchorMSFT))(session, createInfo, anchor);
  }

  //! @brief Call xrCreateSpatialAnchorMSFT (const overload - does not populate
  //! function pointer)
  XrResult
  xrCreateSpatialAnchorMSFT(XrSession session,
                            const XrSpatialAnchorCreateInfoMSFT *createInfo,
                            XrSpatialAnchorMSFT *anchor) const {

    return (reinterpret_cast<PFN_xrCreateSpatialAnchorMSFT>(
        pfnCreateSpatialAnchorMSFT))(session, createInfo, anchor);
  }

  //! @brief Call xrCreateSpatialAnchorSpaceMSFT, populating function pointer if
  //! required.
  XrResult xrCreateSpatialAnchorSpaceMSFT(
      XrSession session, const XrSpatialAnchorSpaceCreateInfoMSFT *createInfo,
      XrSpace *space) {

    XrResult result = populate_("xrCreateSpatialAnchorSpaceMSFT",
                                pfnCreateSpatialAnchorSpaceMSFT);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrCreateSpatialAnchorSpaceMSFT>(
        pfnCreateSpatialAnchorSpaceMSFT))(session, createInfo, space);
  }

  //! @brief Call xrCreateSpatialAnchorSpaceMSFT (const overload - does not
  //! populate function pointer)
  XrResult xrCreateSpatialAnchorSpaceMSFT(
      XrSession session, const XrSpatialAnchorSpaceCreateInfoMSFT *createInfo,
      XrSpace *space) const {

    return (reinterpret_cast<PFN_xrCreateSpatialAnchorSpaceMSFT>(
        pfnCreateSpatialAnchorSpaceMSFT))(session, createInfo, space);
  }

  //! @brief Call xrDestroySpatialAnchorMSFT, populating function pointer if
  //! required.
  XrResult xrDestroySpatialAnchorMSFT(XrSpatialAnchorMSFT anchor) {

    XrResult result =
        populate_("xrDestroySpatialAnchorMSFT", pfnDestroySpatialAnchorMSFT);
    if (XR_FAILED(result)) {
      return result;
    }

    return (reinterpret_cast<PFN_xrDestroySpatialAnchorMSFT>(
        pfnDestroySpatialAnchorMSFT))(anchor);
  }

  //! @brief Call xrDestroySpatialAnchorMSFT (const overload - does not populate
  //! function pointer)
  XrResult xrDestroySpatialAnchorMSFT(XrSpatialAnchorMSFT anchor) const {

    return (reinterpret_cast<PFN_xrDestroySpatialAnchorMSFT>(
        pfnDestroySpatialAnchorMSFT))(anchor);
  }

  //! @}
private:
  //! @brief Internal utility function to populate a function pointer if it is
  //! nullptr.
  XrResult populate_(const char *function_name, PFN_xrVoidFunction &pfn) {
    if (pfn == nullptr) {
      return reinterpret_cast<PFN_xrGetInstanceProcAddr>(
          pfnGetInstanceProcAddr)(m_instance.get(), function_name, &pfn);
    }
    return XR_SUCCESS;
  }
  Instance m_instance;
  PFN_xrVoidFunction pfnGetInstanceProcAddr{};
  PFN_xrVoidFunction pfnEnumerateApiLayerProperties{};
  PFN_xrVoidFunction pfnEnumerateInstanceExtensionProperties{};
  PFN_xrVoidFunction pfnCreateInstance{};
  PFN_xrVoidFunction pfnDestroyInstance{};
  PFN_xrVoidFunction pfnGetInstanceProperties{};
  PFN_xrVoidFunction pfnPollEvent{};
  PFN_xrVoidFunction pfnResultToString{};
  PFN_xrVoidFunction pfnStructureTypeToString{};
  PFN_xrVoidFunction pfnGetSystem{};
  PFN_xrVoidFunction pfnGetSystemProperties{};
  PFN_xrVoidFunction pfnEnumerateEnvironmentBlendModes{};
  PFN_xrVoidFunction pfnCreateSession{};
  PFN_xrVoidFunction pfnDestroySession{};
  PFN_xrVoidFunction pfnEnumerateReferenceSpaces{};
  PFN_xrVoidFunction pfnCreateReferenceSpace{};
  PFN_xrVoidFunction pfnGetReferenceSpaceBoundsRect{};
  PFN_xrVoidFunction pfnCreateActionSpace{};
  PFN_xrVoidFunction pfnLocateSpace{};
  PFN_xrVoidFunction pfnDestroySpace{};
  PFN_xrVoidFunction pfnEnumerateViewConfigurations{};
  PFN_xrVoidFunction pfnGetViewConfigurationProperties{};
  PFN_xrVoidFunction pfnEnumerateViewConfigurationViews{};
  PFN_xrVoidFunction pfnEnumerateSwapchainFormats{};
  PFN_xrVoidFunction pfnCreateSwapchain{};
  PFN_xrVoidFunction pfnDestroySwapchain{};
  PFN_xrVoidFunction pfnEnumerateSwapchainImages{};
  PFN_xrVoidFunction pfnAcquireSwapchainImage{};
  PFN_xrVoidFunction pfnWaitSwapchainImage{};
  PFN_xrVoidFunction pfnReleaseSwapchainImage{};
  PFN_xrVoidFunction pfnBeginSession{};
  PFN_xrVoidFunction pfnEndSession{};
  PFN_xrVoidFunction pfnRequestExitSession{};
  PFN_xrVoidFunction pfnWaitFrame{};
  PFN_xrVoidFunction pfnBeginFrame{};
  PFN_xrVoidFunction pfnEndFrame{};
  PFN_xrVoidFunction pfnLocateViews{};
  PFN_xrVoidFunction pfnStringToPath{};
  PFN_xrVoidFunction pfnPathToString{};
  PFN_xrVoidFunction pfnCreateActionSet{};
  PFN_xrVoidFunction pfnDestroyActionSet{};
  PFN_xrVoidFunction pfnCreateAction{};
  PFN_xrVoidFunction pfnDestroyAction{};
  PFN_xrVoidFunction pfnSuggestInteractionProfileBindings{};
  PFN_xrVoidFunction pfnAttachSessionActionSets{};
  PFN_xrVoidFunction pfnGetCurrentInteractionProfile{};
  PFN_xrVoidFunction pfnGetActionStateBoolean{};
  PFN_xrVoidFunction pfnGetActionStateFloat{};
  PFN_xrVoidFunction pfnGetActionStateVector2f{};
  PFN_xrVoidFunction pfnGetActionStatePose{};
  PFN_xrVoidFunction pfnSyncActions{};
  PFN_xrVoidFunction pfnEnumerateBoundSourcesForAction{};
  PFN_xrVoidFunction pfnGetInputSourceLocalizedName{};
  PFN_xrVoidFunction pfnApplyHapticFeedback{};
  PFN_xrVoidFunction pfnStopHapticFeedback{};
  PFN_xrVoidFunction pfnSetAndroidApplicationThreadKHR{};
  PFN_xrVoidFunction pfnCreateSwapchainAndroidSurfaceKHR{};
  PFN_xrVoidFunction pfnGetOpenGLGraphicsRequirementsKHR{};
  PFN_xrVoidFunction pfnGetOpenGLESGraphicsRequirementsKHR{};
  PFN_xrVoidFunction pfnGetVulkanInstanceExtensionsKHR{};
  PFN_xrVoidFunction pfnGetVulkanDeviceExtensionsKHR{};
  PFN_xrVoidFunction pfnGetVulkanGraphicsDeviceKHR{};
  PFN_xrVoidFunction pfnGetVulkanGraphicsRequirementsKHR{};
  PFN_xrVoidFunction pfnGetD3D11GraphicsRequirementsKHR{};
  PFN_xrVoidFunction pfnGetD3D12GraphicsRequirementsKHR{};
  PFN_xrVoidFunction pfnGetVisibilityMaskKHR{};
  PFN_xrVoidFunction pfnConvertWin32PerformanceCounterToTimeKHR{};
  PFN_xrVoidFunction pfnConvertTimeToWin32PerformanceCounterKHR{};
  PFN_xrVoidFunction pfnConvertTimespecTimeToTimeKHR{};
  PFN_xrVoidFunction pfnConvertTimeToTimespecTimeKHR{};
  PFN_xrVoidFunction pfnPerfSettingsSetPerformanceLevelEXT{};
  PFN_xrVoidFunction pfnThermalGetTemperatureTrendEXT{};
  PFN_xrVoidFunction pfnSetDebugUtilsObjectNameEXT{};
  PFN_xrVoidFunction pfnCreateDebugUtilsMessengerEXT{};
  PFN_xrVoidFunction pfnDestroyDebugUtilsMessengerEXT{};
  PFN_xrVoidFunction pfnSubmitDebugUtilsMessageEXT{};
  PFN_xrVoidFunction pfnSessionBeginDebugUtilsLabelRegionEXT{};
  PFN_xrVoidFunction pfnSessionEndDebugUtilsLabelRegionEXT{};
  PFN_xrVoidFunction pfnSessionInsertDebugUtilsLabelEXT{};
  PFN_xrVoidFunction pfnCreateSpatialAnchorMSFT{};
  PFN_xrVoidFunction pfnCreateSpatialAnchorSpaceMSFT{};
  PFN_xrVoidFunction pfnDestroySpatialAnchorMSFT{};
};

} // namespace OPENXR_HPP_NAMESPACE

/*
 * Inline implementations of all trampoline methods and free functions follow.
 * Prototypes may be found above, either in the associated handle class, or
 * immediately following the section of handle classes.
 */

namespace OPENXR_HPP_NAMESPACE {

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::getInstanceProcAddr(
    const char *name, PFN_xrVoidFunction *function, Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrGetInstanceProcAddr(this->get(), name, function));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Instance::getInstanceProcAddr(const char *name, PFN_xrVoidFunction *function,
                              Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrGetInstanceProcAddr(this->get(), name, function));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::getInstanceProcAddr");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result enumerateApiLayerProperties(
    uint32_t propertyCapacityInput, uint32_t *propertyCountOutput,
    XrApiLayerProperties *properties, Dispatch &&d) {
  Result result = static_cast<Result>(d.xrEnumerateApiLayerProperties(
      propertyCapacityInput, propertyCountOutput, properties));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE
    typename ResultValueType<std::vector<XrApiLayerProperties, Allocator>>::type
    enumerateApiLayerProperties(Dispatch &&d) {
  // Two-call idiom
  std::vector<XrApiLayerProperties, Allocator> properties;
  uint32_t propertyCountOutput = 0;
  uint32_t propertyCapacityInput = 0;

  XrApiLayerProperties empty{};
  empty.type = XR_TYPE_API_LAYER_PROPERTIES;

  Result result = static_cast<Result>(d.xrEnumerateApiLayerProperties(
      propertyCapacityInput, &propertyCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || propertyCountOutput == 0) {

    return impl::createResultValue(result, properties,
                                   OPENXR_HPP_NAMESPACE_STRING
                                   "::enumerateApiLayerProperties");
  }
  do {
    properties.resize(propertyCountOutput, empty);
    propertyCapacityInput = static_cast<uint32_t>(properties.size());
    result = static_cast<Result>(d.xrEnumerateApiLayerProperties(
        propertyCapacityInput, &propertyCountOutput, properties.data()));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(propertyCountOutput <= properties.size());
    properties.resize(propertyCountOutput, empty);
  }

  return impl::createResultValue(result, properties,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::enumerateApiLayerProperties");
}

template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE
    typename ResultValueType<std::vector<XrApiLayerProperties, Allocator>>::type
    enumerateApiLayerProperties(Allocator const &vectorAllocator,
                                Dispatch &&d) {
  // Two-call idiom
  std::vector<XrApiLayerProperties, Allocator> properties{vectorAllocator};
  uint32_t propertyCountOutput = 0;
  uint32_t propertyCapacityInput = 0;

  XrApiLayerProperties empty{};
  empty.type = XR_TYPE_API_LAYER_PROPERTIES;

  Result result = static_cast<Result>(d.xrEnumerateApiLayerProperties(
      propertyCapacityInput, &propertyCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || propertyCountOutput == 0) {

    return impl::createResultValue(result, properties,
                                   OPENXR_HPP_NAMESPACE_STRING
                                   "::enumerateApiLayerProperties");
  }
  do {
    properties.resize(propertyCountOutput, empty);
    propertyCapacityInput = static_cast<uint32_t>(properties.size());
    result = static_cast<Result>(d.xrEnumerateApiLayerProperties(
        propertyCapacityInput, &propertyCountOutput, properties.data()));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(propertyCountOutput <= properties.size());
    properties.resize(propertyCountOutput, empty);
  }

  return impl::createResultValue(result, properties,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::enumerateApiLayerProperties");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result enumerateInstanceExtensionProperties(
    const char *layerName, uint32_t propertyCapacityInput,
    uint32_t *propertyCountOutput, XrExtensionProperties *properties,
    Dispatch &&d) {
  Result result = static_cast<Result>(d.xrEnumerateInstanceExtensionProperties(
      layerName, propertyCapacityInput, propertyCountOutput, properties));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    std::vector<XrExtensionProperties, Allocator>>::type
enumerateInstanceExtensionProperties(const char *layerName, Dispatch &&d) {
  // Two-call idiom
  std::vector<XrExtensionProperties, Allocator> properties;
  uint32_t propertyCountOutput = 0;
  uint32_t propertyCapacityInput = 0;

  XrExtensionProperties empty{};
  empty.type = XR_TYPE_EXTENSION_PROPERTIES;

  Result result = static_cast<Result>(d.xrEnumerateInstanceExtensionProperties(
      layerName, propertyCapacityInput, &propertyCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || propertyCountOutput == 0) {

    return impl::createResultValue(result, properties,
                                   OPENXR_HPP_NAMESPACE_STRING
                                   "::enumerateInstanceExtensionProperties");
  }
  do {
    properties.resize(propertyCountOutput, empty);
    propertyCapacityInput = static_cast<uint32_t>(properties.size());
    result = static_cast<Result>(d.xrEnumerateInstanceExtensionProperties(
        layerName, propertyCapacityInput, &propertyCountOutput,
        properties.data()));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(propertyCountOutput <= properties.size());
    properties.resize(propertyCountOutput, empty);
  }

  return impl::createResultValue(result, properties,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::enumerateInstanceExtensionProperties");
}

template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    std::vector<XrExtensionProperties, Allocator>>::type
enumerateInstanceExtensionProperties(const char *layerName,
                                     Allocator const &vectorAllocator,
                                     Dispatch &&d) {
  // Two-call idiom
  std::vector<XrExtensionProperties, Allocator> properties{vectorAllocator};
  uint32_t propertyCountOutput = 0;
  uint32_t propertyCapacityInput = 0;

  XrExtensionProperties empty{};
  empty.type = XR_TYPE_EXTENSION_PROPERTIES;

  Result result = static_cast<Result>(d.xrEnumerateInstanceExtensionProperties(
      layerName, propertyCapacityInput, &propertyCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || propertyCountOutput == 0) {

    return impl::createResultValue(result, properties,
                                   OPENXR_HPP_NAMESPACE_STRING
                                   "::enumerateInstanceExtensionProperties");
  }
  do {
    properties.resize(propertyCountOutput, empty);
    propertyCapacityInput = static_cast<uint32_t>(properties.size());
    result = static_cast<Result>(d.xrEnumerateInstanceExtensionProperties(
        layerName, propertyCapacityInput, &propertyCountOutput,
        properties.data()));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(propertyCountOutput <= properties.size());
    properties.resize(propertyCountOutput, empty);
  }

  return impl::createResultValue(result, properties,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::enumerateInstanceExtensionProperties");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result createInstance(const XrInstanceCreateInfo *createInfo,
                                        Instance &instance, Dispatch &&d) {
  Result result =
      static_cast<Result>(d.xrCreateInstance(createInfo, instance.put()));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<Instance>::type
createInstance(const XrInstanceCreateInfo *createInfo, Dispatch &&d) {
  Instance handle;
  Result result =
      static_cast<Result>(d.xrCreateInstance(createInfo, handle.put()));
  return impl::createResultValue(
      result, handle, OPENXR_HPP_NAMESPACE_STRING "::createInstance");
}
#ifndef OPENXR_HPP_NO_SMART_HANDLE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    UniqueHandle<Instance, impl::RemoveRefConst<Dispatch>>>::type
createInstanceUnique(const XrInstanceCreateInfo *createInfo, Dispatch &&d) {
  Instance handle;
  Result result =
      static_cast<Result>(d.xrCreateInstance(createInfo, handle.put()));
  ObjectDestroy<impl::RemoveRefConst<Dispatch>> deleter{d};
  return impl::createResultValue<Instance, impl::RemoveRefConst<Dispatch>>(
      result, handle, deleter,
      OPENXR_HPP_NAMESPACE_STRING "::createInstanceUnique");
}

#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::destroy(Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrDestroyInstance(this->get()));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Instance::destroy(Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrDestroyInstance(this->get()));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::destroy");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::getInstanceProperties(
    XrInstanceProperties *instanceProperties, Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrGetInstanceProperties(this->get(), instanceProperties));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Instance::getInstanceProperties(XrInstanceProperties *instanceProperties,
                                Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrGetInstanceProperties(this->get(), instanceProperties));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::getInstanceProperties");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::pollEvent(XrEventDataBuffer *eventData,
                                             Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrPollEvent(this->get(), eventData));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::pollEvent(XrEventDataBuffer *eventData,
                                             Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrPollEvent(this->get(), eventData));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING "::Instance::pollEvent",
      {Result::Success, Result::EventUnavailable});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_PROVIDE_DISCOURAGED_FUNCTIONS

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::resultToString(
    Result value, char buffer[XR_MAX_RESULT_STRING_SIZE], Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrResultToString(
      this->get(), OPENXR_HPP_NAMESPACE::get(value), buffer));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Instance::resultToString(Result value, char buffer[XR_MAX_RESULT_STRING_SIZE],
                         Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrResultToString(
      this->get(), OPENXR_HPP_NAMESPACE::get(value), buffer));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::resultToString");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif //  OPENXR_HPP_PROVIDE_DISCOURAGED_FUNCTIONS

#ifdef OPENXR_HPP_PROVIDE_DISCOURAGED_FUNCTIONS

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::structureTypeToString(
    StructureType value, char buffer[XR_MAX_STRUCTURE_NAME_SIZE],
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrStructureTypeToString(
      this->get(), OPENXR_HPP_NAMESPACE::get(value), buffer));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Instance::structureTypeToString(StructureType value,
                                char buffer[XR_MAX_STRUCTURE_NAME_SIZE],
                                Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrStructureTypeToString(
      this->get(), OPENXR_HPP_NAMESPACE::get(value), buffer));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::structureTypeToString");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif //  OPENXR_HPP_PROVIDE_DISCOURAGED_FUNCTIONS

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::getSystem(const XrSystemGetInfo *getInfo,
                                             XrSystemId *systemId,
                                             Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrGetSystem(this->get(), getInfo, systemId));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Instance::getSystem(const XrSystemGetInfo *getInfo, XrSystemId *systemId,
                    Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrGetSystem(this->get(), getInfo, systemId));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::getSystem");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::getSystemProperties(
    XrSystemId systemId, XrSystemProperties *properties, Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrGetSystemProperties(this->get(), systemId, properties));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type Instance::getSystemProperties(
    XrSystemId systemId, XrSystemProperties *properties, Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrGetSystemProperties(this->get(), systemId, properties));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::getSystemProperties");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::enumerateEnvironmentBlendModes(
    XrSystemId systemId, ViewConfigurationType viewConfigurationType,
    uint32_t environmentBlendModeCapacityInput,
    uint32_t *environmentBlendModeCountOutput,
    EnvironmentBlendMode &environmentBlendModes, Dispatch &&d) const {
  XrEnvironmentBlendMode environmentBlendModes_tmp;
  Result result = static_cast<Result>(d.xrEnumerateEnvironmentBlendModes(
      this->get(), systemId, OPENXR_HPP_NAMESPACE::get(viewConfigurationType),
      environmentBlendModeCapacityInput, environmentBlendModeCountOutput,
      environmentBlendModes_tmp));
  environmentBlendModes =
      static_cast<EnvironmentBlendMode>(environmentBlendModes_tmp);
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Instance::enumerateEnvironmentBlendModes(
    XrSystemId systemId, ViewConfigurationType viewConfigurationType,
    uint32_t environmentBlendModeCapacityInput,
    uint32_t *environmentBlendModeCountOutput,
    EnvironmentBlendMode &environmentBlendModes, Dispatch &&d) const {
  XrEnvironmentBlendMode environmentBlendModes_tmp;
  Result result = static_cast<Result>(d.xrEnumerateEnvironmentBlendModes(
      this->get(), systemId, OPENXR_HPP_NAMESPACE::get(viewConfigurationType),
      environmentBlendModeCapacityInput, environmentBlendModeCountOutput,
      environmentBlendModes_tmp));
  environmentBlendModes =
      static_cast<EnvironmentBlendMode>(environmentBlendModes_tmp);
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::enumerateEnvironmentBlendModes");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result
Instance::createSession(const XrSessionCreateInfo *createInfo, Session &session,
                        Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrCreateSession(this->get(), createInfo, session.put()));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<Session>::type
Instance::createSession(const XrSessionCreateInfo *createInfo,
                        Dispatch &&d) const {
  Session handle;
  Result result = static_cast<Result>(
      d.xrCreateSession(this->get(), createInfo, handle.put()));
  return impl::createResultValue(
      result, handle, OPENXR_HPP_NAMESPACE_STRING "::Instance::createSession");
}
#ifndef OPENXR_HPP_NO_SMART_HANDLE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    UniqueHandle<Session, impl::RemoveRefConst<Dispatch>>>::type
Instance::createSessionUnique(const XrSessionCreateInfo *createInfo,
                              Dispatch &&d) const {
  Session handle;
  Result result = static_cast<Result>(
      d.xrCreateSession(this->get(), createInfo, handle.put()));
  ObjectDestroy<impl::RemoveRefConst<Dispatch>> deleter{d};
  return impl::createResultValue<Session, impl::RemoveRefConst<Dispatch>>(
      result, handle, deleter,
      OPENXR_HPP_NAMESPACE_STRING "::Instance::createSessionUnique");
}

#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::destroy(Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrDestroySession(this->get()));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Session::destroy(Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrDestroySession(this->get()));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::destroy");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::enumerateReferenceSpaces(
    uint32_t spaceCapacityInput, uint32_t *spaceCountOutput,
    ReferenceSpaceType &spaces, Dispatch &&d) const {
  XrReferenceSpaceType spaces_tmp;
  Result result = static_cast<Result>(d.xrEnumerateReferenceSpaces(
      this->get(), spaceCapacityInput, spaceCountOutput, spaces_tmp));
  spaces = static_cast<ReferenceSpaceType>(spaces_tmp);
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE ResultValue<std::vector<ReferenceSpaceType, Allocator>>
Session::enumerateReferenceSpaces(Dispatch &&d) const {
  // Two-call idiom
  std::vector<ReferenceSpaceType, Allocator> spaces;
  uint32_t spaceCountOutput = 0;
  uint32_t spaceCapacityInput = 0;

  XrReferenceSpaceType spaces_tmp;
  Result result = static_cast<Result>(d.xrEnumerateReferenceSpaces(
      this->get(), spaceCapacityInput, &spaceCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || spaceCountOutput == 0) {

    return impl::createResultValue(
        result, spaces,
        OPENXR_HPP_NAMESPACE_STRING "::Session::enumerateReferenceSpaces",
        {Result::Success, Result::SessionLossPending});
  }
  do {
    spaces.resize(spaceCountOutput);
    spaceCapacityInput = static_cast<uint32_t>(spaces.size());
    result = static_cast<Result>(d.xrEnumerateReferenceSpaces(
        this->get(), spaceCapacityInput, &spaceCountOutput, spaces.data()));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(spaceCountOutput <= spaces.size());
    spaces.resize(spaceCountOutput);
  }
  spaces = static_cast<ReferenceSpaceType>(spaces_tmp);
  return impl::createResultValue(result, spaces,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::enumerateReferenceSpaces",
                                 {Result::Success, Result::SessionLossPending});
}

template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE ResultValue<std::vector<ReferenceSpaceType, Allocator>>
Session::enumerateReferenceSpaces(Allocator const &vectorAllocator,
                                  Dispatch &&d) const {
  // Two-call idiom
  std::vector<ReferenceSpaceType, Allocator> spaces{vectorAllocator};
  uint32_t spaceCountOutput = 0;
  uint32_t spaceCapacityInput = 0;

  XrReferenceSpaceType spaces_tmp;
  Result result = static_cast<Result>(d.xrEnumerateReferenceSpaces(
      this->get(), spaceCapacityInput, &spaceCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || spaceCountOutput == 0) {

    return impl::createResultValue(
        result, spaces,
        OPENXR_HPP_NAMESPACE_STRING "::Session::enumerateReferenceSpaces",
        {Result::Success, Result::SessionLossPending});
  }
  do {
    spaces.resize(spaceCountOutput);
    spaceCapacityInput = static_cast<uint32_t>(spaces.size());
    result = static_cast<Result>(d.xrEnumerateReferenceSpaces(
        this->get(), spaceCapacityInput, &spaceCountOutput, spaces.data()));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(spaceCountOutput <= spaces.size());
    spaces.resize(spaceCountOutput);
  }
  spaces = static_cast<ReferenceSpaceType>(spaces_tmp);
  return impl::createResultValue(result, spaces,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::enumerateReferenceSpaces",
                                 {Result::Success, Result::SessionLossPending});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result
Session::createReferenceSpace(const XrReferenceSpaceCreateInfo *createInfo,
                              Space &space, Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrCreateReferenceSpace(this->get(), createInfo, space.put()));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValue<Space>
Session::createReferenceSpace(const XrReferenceSpaceCreateInfo *createInfo,
                              Dispatch &&d) const {
  Space handle;
  Result result = static_cast<Result>(
      d.xrCreateReferenceSpace(this->get(), createInfo, handle.put()));
  return impl::createResultValue(result, handle,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::createReferenceSpace",
                                 {Result::Success, Result::SessionLossPending});
}
#ifndef OPENXR_HPP_NO_SMART_HANDLE

template <typename Dispatch>
OPENXR_HPP_INLINE
    ResultValue<UniqueHandle<Space, impl::RemoveRefConst<Dispatch>>>
    Session::createReferenceSpaceUnique(
        const XrReferenceSpaceCreateInfo *createInfo, Dispatch &&d) const {
  Space handle;
  Result result = static_cast<Result>(
      d.xrCreateReferenceSpace(this->get(), createInfo, handle.put()));
  ObjectDestroy<impl::RemoveRefConst<Dispatch>> deleter{d};
  return impl::createResultValue<Space, impl::RemoveRefConst<Dispatch>>(
      result, handle, deleter,
      OPENXR_HPP_NAMESPACE_STRING "::Session::createReferenceSpaceUnique",
      {Result::Success, Result::SessionLossPending});
}

#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result
Session::getReferenceSpaceBoundsRect(ReferenceSpaceType referenceSpaceType,
                                     XrExtent2Df *bounds, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetReferenceSpaceBoundsRect(
      this->get(), OPENXR_HPP_NAMESPACE::get(referenceSpaceType), bounds));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result
Session::getReferenceSpaceBoundsRect(ReferenceSpaceType referenceSpaceType,
                                     XrExtent2Df *bounds, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetReferenceSpaceBoundsRect(
      this->get(), OPENXR_HPP_NAMESPACE::get(referenceSpaceType), bounds));
  return impl::createResultValue(
      result,
      OPENXR_HPP_NAMESPACE_STRING "::Session::getReferenceSpaceBoundsRect",
      {Result::Success, Result::SpaceBoundsUnavailable,
       Result::SessionLossPending});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result
Session::createActionSpace(const XrActionSpaceCreateInfo *createInfo,
                           Space &space, Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrCreateActionSpace(this->get(), createInfo, space.put()));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValue<Space>
Session::createActionSpace(const XrActionSpaceCreateInfo *createInfo,
                           Dispatch &&d) const {
  Space handle;
  Result result = static_cast<Result>(
      d.xrCreateActionSpace(this->get(), createInfo, handle.put()));
  return impl::createResultValue(result, handle,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::createActionSpace",
                                 {Result::Success, Result::SessionLossPending});
}
#ifndef OPENXR_HPP_NO_SMART_HANDLE

template <typename Dispatch>
OPENXR_HPP_INLINE
    ResultValue<UniqueHandle<Space, impl::RemoveRefConst<Dispatch>>>
    Session::createActionSpaceUnique(const XrActionSpaceCreateInfo *createInfo,
                                     Dispatch &&d) const {
  Space handle;
  Result result = static_cast<Result>(
      d.xrCreateActionSpace(this->get(), createInfo, handle.put()));
  ObjectDestroy<impl::RemoveRefConst<Dispatch>> deleter{d};
  return impl::createResultValue<Space, impl::RemoveRefConst<Dispatch>>(
      result, handle, deleter,
      OPENXR_HPP_NAMESPACE_STRING "::Session::createActionSpaceUnique",
      {Result::Success, Result::SessionLossPending});
}

#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Space::locateSpace(Space baseSpace, XrTime time,
                                            XrSpaceLocation *location,
                                            Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrLocateSpace(this->get(), baseSpace.get(), time, location));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result Space::locateSpace(Space baseSpace, XrTime time,
                                            XrSpaceLocation *location,
                                            Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrLocateSpace(this->get(), baseSpace.get(), time, location));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING "::Space::locateSpace",
      {Result::Success, Result::SessionLossPending});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Space::destroy(Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrDestroySpace(this->get()));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Space::destroy(Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrDestroySpace(this->get()));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Space::destroy");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::enumerateViewConfigurations(
    XrSystemId systemId, uint32_t viewConfigurationTypeCapacityInput,
    uint32_t *viewConfigurationTypeCountOutput,
    ViewConfigurationType &viewConfigurationTypes, Dispatch &&d) const {
  XrViewConfigurationType viewConfigurationTypes_tmp;
  Result result = static_cast<Result>(d.xrEnumerateViewConfigurations(
      this->get(), systemId, viewConfigurationTypeCapacityInput,
      viewConfigurationTypeCountOutput, viewConfigurationTypes_tmp));
  viewConfigurationTypes =
      static_cast<ViewConfigurationType>(viewConfigurationTypes_tmp);
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Instance::enumerateViewConfigurations(
    XrSystemId systemId, uint32_t viewConfigurationTypeCapacityInput,
    uint32_t *viewConfigurationTypeCountOutput,
    ViewConfigurationType &viewConfigurationTypes, Dispatch &&d) const {
  XrViewConfigurationType viewConfigurationTypes_tmp;
  Result result = static_cast<Result>(d.xrEnumerateViewConfigurations(
      this->get(), systemId, viewConfigurationTypeCapacityInput,
      viewConfigurationTypeCountOutput, viewConfigurationTypes_tmp));
  viewConfigurationTypes =
      static_cast<ViewConfigurationType>(viewConfigurationTypes_tmp);
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::enumerateViewConfigurations");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::getViewConfigurationProperties(
    XrSystemId systemId, ViewConfigurationType viewConfigurationType,
    XrViewConfigurationProperties *configurationProperties,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetViewConfigurationProperties(
      this->get(), systemId, OPENXR_HPP_NAMESPACE::get(viewConfigurationType),
      configurationProperties));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Instance::getViewConfigurationProperties(
    XrSystemId systemId, ViewConfigurationType viewConfigurationType,
    XrViewConfigurationProperties *configurationProperties,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetViewConfigurationProperties(
      this->get(), systemId, OPENXR_HPP_NAMESPACE::get(viewConfigurationType),
      configurationProperties));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::getViewConfigurationProperties");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::enumerateViewConfigurationViews(
    XrSystemId systemId, ViewConfigurationType viewConfigurationType,
    uint32_t viewCapacityInput, uint32_t *viewCountOutput,
    XrViewConfigurationView *views, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrEnumerateViewConfigurationViews(
      this->get(), systemId, OPENXR_HPP_NAMESPACE::get(viewConfigurationType),
      viewCapacityInput, viewCountOutput, views));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    std::vector<XrViewConfigurationView, Allocator>>::type
Instance::enumerateViewConfigurationViews(
    XrSystemId systemId, ViewConfigurationType viewConfigurationType,
    Dispatch &&d) const {
  // Two-call idiom
  std::vector<XrViewConfigurationView, Allocator> views;
  uint32_t viewCountOutput = 0;
  uint32_t viewCapacityInput = 0;

  XrViewConfigurationView empty{};
  empty.type = XR_TYPE_VIEW_CONFIGURATION_VIEW;

  Result result = static_cast<Result>(d.xrEnumerateViewConfigurationViews(
      this->get(), systemId, OPENXR_HPP_NAMESPACE::get(viewConfigurationType),
      viewCapacityInput, &viewCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || viewCountOutput == 0) {

    return impl::createResultValue(
        result, views,
        OPENXR_HPP_NAMESPACE_STRING
        "::Instance::enumerateViewConfigurationViews");
  }
  do {
    views.resize(viewCountOutput, empty);
    viewCapacityInput = static_cast<uint32_t>(views.size());
    result = static_cast<Result>(d.xrEnumerateViewConfigurationViews(
        this->get(), systemId, OPENXR_HPP_NAMESPACE::get(viewConfigurationType),
        viewCapacityInput, &viewCountOutput, views.data()));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(viewCountOutput <= views.size());
    views.resize(viewCountOutput, empty);
  }

  return impl::createResultValue(result, views,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::enumerateViewConfigurationViews");
}

template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    std::vector<XrViewConfigurationView, Allocator>>::type
Instance::enumerateViewConfigurationViews(
    XrSystemId systemId, ViewConfigurationType viewConfigurationType,
    Allocator const &vectorAllocator, Dispatch &&d) const {
  // Two-call idiom
  std::vector<XrViewConfigurationView, Allocator> views{vectorAllocator};
  uint32_t viewCountOutput = 0;
  uint32_t viewCapacityInput = 0;

  XrViewConfigurationView empty{};
  empty.type = XR_TYPE_VIEW_CONFIGURATION_VIEW;

  Result result = static_cast<Result>(d.xrEnumerateViewConfigurationViews(
      this->get(), systemId, OPENXR_HPP_NAMESPACE::get(viewConfigurationType),
      viewCapacityInput, &viewCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || viewCountOutput == 0) {

    return impl::createResultValue(
        result, views,
        OPENXR_HPP_NAMESPACE_STRING
        "::Instance::enumerateViewConfigurationViews");
  }
  do {
    views.resize(viewCountOutput, empty);
    viewCapacityInput = static_cast<uint32_t>(views.size());
    result = static_cast<Result>(d.xrEnumerateViewConfigurationViews(
        this->get(), systemId, OPENXR_HPP_NAMESPACE::get(viewConfigurationType),
        viewCapacityInput, &viewCountOutput, views.data()));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(viewCountOutput <= views.size());
    views.resize(viewCountOutput, empty);
  }

  return impl::createResultValue(result, views,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::enumerateViewConfigurationViews");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::enumerateSwapchainFormats(
    uint32_t formatCapacityInput, uint32_t *formatCountOutput, int64_t *formats,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrEnumerateSwapchainFormats(
      this->get(), formatCapacityInput, formatCountOutput, formats));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE ResultValue<std::vector<int64_t, Allocator>>
Session::enumerateSwapchainFormats(Dispatch &&d) const {
  // Two-call idiom
  std::vector<int64_t, Allocator> formats;
  uint32_t formatCountOutput = 0;
  uint32_t formatCapacityInput = 0;

  Result result = static_cast<Result>(d.xrEnumerateSwapchainFormats(
      this->get(), formatCapacityInput, &formatCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || formatCountOutput == 0) {

    return impl::createResultValue(
        result, formats,
        OPENXR_HPP_NAMESPACE_STRING "::Session::enumerateSwapchainFormats",
        {Result::Success, Result::SessionLossPending});
  }
  do {
    formats.resize(formatCountOutput);
    formatCapacityInput = static_cast<uint32_t>(formats.size());
    result = static_cast<Result>(d.xrEnumerateSwapchainFormats(
        this->get(), formatCapacityInput, &formatCountOutput, formats.data()));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(formatCountOutput <= formats.size());
    formats.resize(formatCountOutput);
  }

  return impl::createResultValue(result, formats,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::enumerateSwapchainFormats",
                                 {Result::Success, Result::SessionLossPending});
}

template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE ResultValue<std::vector<int64_t, Allocator>>
Session::enumerateSwapchainFormats(Allocator const &vectorAllocator,
                                   Dispatch &&d) const {
  // Two-call idiom
  std::vector<int64_t, Allocator> formats{vectorAllocator};
  uint32_t formatCountOutput = 0;
  uint32_t formatCapacityInput = 0;

  Result result = static_cast<Result>(d.xrEnumerateSwapchainFormats(
      this->get(), formatCapacityInput, &formatCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || formatCountOutput == 0) {

    return impl::createResultValue(
        result, formats,
        OPENXR_HPP_NAMESPACE_STRING "::Session::enumerateSwapchainFormats",
        {Result::Success, Result::SessionLossPending});
  }
  do {
    formats.resize(formatCountOutput);
    formatCapacityInput = static_cast<uint32_t>(formats.size());
    result = static_cast<Result>(d.xrEnumerateSwapchainFormats(
        this->get(), formatCapacityInput, &formatCountOutput, formats.data()));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(formatCountOutput <= formats.size());
    formats.resize(formatCountOutput);
  }

  return impl::createResultValue(result, formats,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::enumerateSwapchainFormats",
                                 {Result::Success, Result::SessionLossPending});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result
Session::createSwapchain(const XrSwapchainCreateInfo *createInfo,
                         Swapchain &swapchain, Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrCreateSwapchain(this->get(), createInfo, swapchain.put()));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValue<Swapchain>
Session::createSwapchain(const XrSwapchainCreateInfo *createInfo,
                         Dispatch &&d) const {
  Swapchain handle;
  Result result = static_cast<Result>(
      d.xrCreateSwapchain(this->get(), createInfo, handle.put()));
  return impl::createResultValue(
      result, handle, OPENXR_HPP_NAMESPACE_STRING "::Session::createSwapchain",
      {Result::Success, Result::SessionLossPending});
}
#ifndef OPENXR_HPP_NO_SMART_HANDLE

template <typename Dispatch>
OPENXR_HPP_INLINE
    ResultValue<UniqueHandle<Swapchain, impl::RemoveRefConst<Dispatch>>>
    Session::createSwapchainUnique(const XrSwapchainCreateInfo *createInfo,
                                   Dispatch &&d) const {
  Swapchain handle;
  Result result = static_cast<Result>(
      d.xrCreateSwapchain(this->get(), createInfo, handle.put()));
  ObjectDestroy<impl::RemoveRefConst<Dispatch>> deleter{d};
  return impl::createResultValue<Swapchain, impl::RemoveRefConst<Dispatch>>(
      result, handle, deleter,
      OPENXR_HPP_NAMESPACE_STRING "::Session::createSwapchainUnique",
      {Result::Success, Result::SessionLossPending});
}

#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Swapchain::destroy(Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrDestroySwapchain(this->get()));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Swapchain::destroy(Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrDestroySwapchain(this->get()));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Swapchain::destroy");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Swapchain::enumerateSwapchainImages(
    uint32_t imageCapacityInput, uint32_t *imageCountOutput,
    XrSwapchainImageBaseHeader *images, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrEnumerateSwapchainImages(
      this->get(), imageCapacityInput, imageCountOutput, images));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result Swapchain::enumerateSwapchainImages(
    uint32_t imageCapacityInput, uint32_t *imageCountOutput,
    XrSwapchainImageBaseHeader *images, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrEnumerateSwapchainImages(
      this->get(), imageCapacityInput, imageCountOutput, images));
  return impl::createResultValue(result,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Swapchain::enumerateSwapchainImages",
                                 {Result::Success, Result::SessionLossPending});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result
Swapchain::acquireSwapchainImage(const XrSwapchainImageAcquireInfo *acquireInfo,
                                 uint32_t *index, Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrAcquireSwapchainImage(this->get(), acquireInfo, index));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result
Swapchain::acquireSwapchainImage(const XrSwapchainImageAcquireInfo *acquireInfo,
                                 uint32_t *index, Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrAcquireSwapchainImage(this->get(), acquireInfo, index));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING "::Swapchain::acquireSwapchainImage",
      {Result::Success, Result::SessionLossPending});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Swapchain::waitSwapchainImage(
    const XrSwapchainImageWaitInfo *waitInfo, Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrWaitSwapchainImage(this->get(), waitInfo));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result Swapchain::waitSwapchainImage(
    const XrSwapchainImageWaitInfo *waitInfo, Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrWaitSwapchainImage(this->get(), waitInfo));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING "::Swapchain::waitSwapchainImage",
      {Result::Success, Result::TimeoutExpired, Result::SessionLossPending});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Swapchain::releaseSwapchainImage(
    const XrSwapchainImageReleaseInfo *releaseInfo, Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrReleaseSwapchainImage(this->get(), releaseInfo));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result Swapchain::releaseSwapchainImage(
    const XrSwapchainImageReleaseInfo *releaseInfo, Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrReleaseSwapchainImage(this->get(), releaseInfo));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING "::Swapchain::releaseSwapchainImage",
      {Result::Success, Result::SessionLossPending});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result
Session::beginSession(const XrSessionBeginInfo *beginInfo, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrBeginSession(this->get(), beginInfo));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result
Session::beginSession(const XrSessionBeginInfo *beginInfo, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrBeginSession(this->get(), beginInfo));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING "::Session::beginSession",
      {Result::Success, Result::SessionLossPending});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::endSession(Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrEndSession(this->get()));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::endSession(Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrEndSession(this->get()));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING "::Session::endSession",
      {Result::Success, Result::SessionLossPending});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::requestExitSession(Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrRequestExitSession(this->get()));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::requestExitSession(Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrRequestExitSession(this->get()));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING "::Session::requestExitSession",
      {Result::Success, Result::SessionLossPending});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result
Session::waitFrame(const XrFrameWaitInfo *frameWaitInfo,
                   XrFrameState *frameState, Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrWaitFrame(this->get(), frameWaitInfo, frameState));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result
Session::waitFrame(const XrFrameWaitInfo *frameWaitInfo,
                   XrFrameState *frameState, Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrWaitFrame(this->get(), frameWaitInfo, frameState));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING "::Session::waitFrame",
      {Result::Success, Result::SessionLossPending});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::beginFrame(
    const XrFrameBeginInfo *frameBeginInfo, Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrBeginFrame(this->get(), frameBeginInfo));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::beginFrame(
    const XrFrameBeginInfo *frameBeginInfo, Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrBeginFrame(this->get(), frameBeginInfo));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING "::Session::beginFrame",
      {Result::Success, Result::SessionLossPending, Result::FrameDiscarded});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::endFrame(const XrFrameEndInfo *frameEndInfo,
                                           Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrEndFrame(this->get(), frameEndInfo));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::endFrame(const XrFrameEndInfo *frameEndInfo,
                                           Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrEndFrame(this->get(), frameEndInfo));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING "::Session::endFrame",
      {Result::Success, Result::SessionLossPending});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::locateViews(
    const XrViewLocateInfo *viewLocateInfo, XrViewState *viewState,
    uint32_t viewCapacityInput, uint32_t *viewCountOutput, XrView *views,
    Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrLocateViews(this->get(), viewLocateInfo, viewState, viewCapacityInput,
                      viewCountOutput, views));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE ResultValue<std::vector<XrView, Allocator>>
Session::locateViews(const XrViewLocateInfo *viewLocateInfo,
                     XrViewState *viewState, Dispatch &&d) const {
  // Two-call idiom
  std::vector<XrView, Allocator> views;
  uint32_t viewCountOutput = 0;
  uint32_t viewCapacityInput = 0;

  XrView empty{};
  empty.type = XR_TYPE_VIEW;

  Result result = static_cast<Result>(
      d.xrLocateViews(this->get(), viewLocateInfo, viewState, viewCapacityInput,
                      &viewCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || viewCountOutput == 0) {

    return impl::createResultValue(
        result, views, OPENXR_HPP_NAMESPACE_STRING "::Session::locateViews",
        {Result::Success, Result::SessionLossPending});
  }
  do {
    views.resize(viewCountOutput, empty);
    viewCapacityInput = static_cast<uint32_t>(views.size());
    result = static_cast<Result>(
        d.xrLocateViews(this->get(), viewLocateInfo, viewState,
                        viewCapacityInput, &viewCountOutput, views.data()));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(viewCountOutput <= views.size());
    views.resize(viewCountOutput, empty);
  }

  return impl::createResultValue(
      result, views, OPENXR_HPP_NAMESPACE_STRING "::Session::locateViews",
      {Result::Success, Result::SessionLossPending});
}

template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE ResultValue<std::vector<XrView, Allocator>>
Session::locateViews(const XrViewLocateInfo *viewLocateInfo,
                     XrViewState *viewState, Allocator const &vectorAllocator,
                     Dispatch &&d) const {
  // Two-call idiom
  std::vector<XrView, Allocator> views{vectorAllocator};
  uint32_t viewCountOutput = 0;
  uint32_t viewCapacityInput = 0;

  XrView empty{};
  empty.type = XR_TYPE_VIEW;

  Result result = static_cast<Result>(
      d.xrLocateViews(this->get(), viewLocateInfo, viewState, viewCapacityInput,
                      &viewCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || viewCountOutput == 0) {

    return impl::createResultValue(
        result, views, OPENXR_HPP_NAMESPACE_STRING "::Session::locateViews",
        {Result::Success, Result::SessionLossPending});
  }
  do {
    views.resize(viewCountOutput, empty);
    viewCapacityInput = static_cast<uint32_t>(views.size());
    result = static_cast<Result>(
        d.xrLocateViews(this->get(), viewLocateInfo, viewState,
                        viewCapacityInput, &viewCountOutput, views.data()));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(viewCountOutput <= views.size());
    views.resize(viewCountOutput, empty);
  }

  return impl::createResultValue(
      result, views, OPENXR_HPP_NAMESPACE_STRING "::Session::locateViews",
      {Result::Success, Result::SessionLossPending});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::stringToPath(const char *pathString,
                                                XrPath *path,
                                                Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrStringToPath(this->get(), pathString, path));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Instance::stringToPath(const char *pathString, XrPath *path,
                       Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrStringToPath(this->get(), pathString, path));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::stringToPath");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::pathToString(XrPath path,
                                                uint32_t bufferCapacityInput,
                                                uint32_t *bufferCountOutput,
                                                char *buffer,
                                                Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrPathToString(
      this->get(), path, bufferCapacityInput, bufferCountOutput, buffer));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE
    typename ResultValueType<string_with_allocator<Allocator>>::type
    Instance::pathToString(XrPath path, Dispatch &&d) const {
  // Two-call idiom
  std::vector<char, Allocator> buffer;
  uint32_t bufferCountOutput = 0;
  uint32_t bufferCapacityInput = 0;

  std::basic_string<char, std::char_traits<char>, Allocator> str{{}};
  Result result = static_cast<Result>(d.xrPathToString(
      this->get(), path, bufferCapacityInput, &bufferCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || bufferCountOutput == 0) {

    return impl::createResultValue(
        result, str, OPENXR_HPP_NAMESPACE_STRING "::Instance::pathToString");
  }
  do {
    buffer.resize(bufferCountOutput);
    bufferCapacityInput = static_cast<uint32_t>(buffer.size());
    result = static_cast<Result>(
        d.xrPathToString(this->get(), path, bufferCapacityInput,
                         &bufferCountOutput, buffer.data()));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(bufferCountOutput <= buffer.size());
    buffer.resize(bufferCountOutput);
  }

  str.assign(buffer.begin(), buffer.end());
  return impl::createResultValue(
      result, str, OPENXR_HPP_NAMESPACE_STRING "::Instance::pathToString");
}

template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE
    typename ResultValueType<string_with_allocator<Allocator>>::type
    Instance::pathToString(XrPath path, Allocator const &vectorAllocator,
                           Dispatch &&d) const {
  // Two-call idiom
  std::vector<char, Allocator> buffer{vectorAllocator};
  uint32_t bufferCountOutput = 0;
  uint32_t bufferCapacityInput = 0;

  std::basic_string<char, std::char_traits<char>, Allocator> str{
      vectorAllocator};
  Result result = static_cast<Result>(d.xrPathToString(
      this->get(), path, bufferCapacityInput, &bufferCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || bufferCountOutput == 0) {

    return impl::createResultValue(
        result, str, OPENXR_HPP_NAMESPACE_STRING "::Instance::pathToString");
  }
  do {
    buffer.resize(bufferCountOutput);
    bufferCapacityInput = static_cast<uint32_t>(buffer.size());
    result = static_cast<Result>(
        d.xrPathToString(this->get(), path, bufferCapacityInput,
                         &bufferCountOutput, buffer.data()));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(bufferCountOutput <= buffer.size());
    buffer.resize(bufferCountOutput);
  }

  str.assign(buffer.begin(), buffer.end());
  return impl::createResultValue(
      result, str, OPENXR_HPP_NAMESPACE_STRING "::Instance::pathToString");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result
Instance::createActionSet(const XrActionSetCreateInfo *createInfo,
                          ActionSet &actionSet, Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrCreateActionSet(this->get(), createInfo, actionSet.put()));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<ActionSet>::type
Instance::createActionSet(const XrActionSetCreateInfo *createInfo,
                          Dispatch &&d) const {
  ActionSet handle;
  Result result = static_cast<Result>(
      d.xrCreateActionSet(this->get(), createInfo, handle.put()));
  return impl::createResultValue(result, handle,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::createActionSet");
}
#ifndef OPENXR_HPP_NO_SMART_HANDLE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    UniqueHandle<ActionSet, impl::RemoveRefConst<Dispatch>>>::type
Instance::createActionSetUnique(const XrActionSetCreateInfo *createInfo,
                                Dispatch &&d) const {
  ActionSet handle;
  Result result = static_cast<Result>(
      d.xrCreateActionSet(this->get(), createInfo, handle.put()));
  ObjectDestroy<impl::RemoveRefConst<Dispatch>> deleter{d};
  return impl::createResultValue<ActionSet, impl::RemoveRefConst<Dispatch>>(
      result, handle, deleter,
      OPENXR_HPP_NAMESPACE_STRING "::Instance::createActionSetUnique");
}

#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result ActionSet::destroy(Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrDestroyActionSet(this->get()));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
ActionSet::destroy(Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrDestroyActionSet(this->get()));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::ActionSet::destroy");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result ActionSet::createAction(
    const XrActionCreateInfo *createInfo, Action &action, Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrCreateAction(this->get(), createInfo, action.put()));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<Action>::type
ActionSet::createAction(const XrActionCreateInfo *createInfo,
                        Dispatch &&d) const {
  Action handle;
  Result result = static_cast<Result>(
      d.xrCreateAction(this->get(), createInfo, handle.put()));
  return impl::createResultValue(
      result, handle, OPENXR_HPP_NAMESPACE_STRING "::ActionSet::createAction");
}
#ifndef OPENXR_HPP_NO_SMART_HANDLE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    UniqueHandle<Action, impl::RemoveRefConst<Dispatch>>>::type
ActionSet::createActionUnique(const XrActionCreateInfo *createInfo,
                              Dispatch &&d) const {
  Action handle;
  Result result = static_cast<Result>(
      d.xrCreateAction(this->get(), createInfo, handle.put()));
  ObjectDestroy<impl::RemoveRefConst<Dispatch>> deleter{d};
  return impl::createResultValue<Action, impl::RemoveRefConst<Dispatch>>(
      result, handle, deleter,
      OPENXR_HPP_NAMESPACE_STRING "::ActionSet::createActionUnique");
}

#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Action::destroy(Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrDestroyAction(this->get()));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Action::destroy(Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrDestroyAction(this->get()));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Action::destroy");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::suggestInteractionProfileBindings(
    const XrInteractionProfileSuggestedBinding *suggestedBindings,
    Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrSuggestInteractionProfileBindings(this->get(), suggestedBindings));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Instance::suggestInteractionProfileBindings(
    const XrInteractionProfileSuggestedBinding *suggestedBindings,
    Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrSuggestInteractionProfileBindings(this->get(), suggestedBindings));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING
      "::Instance::suggestInteractionProfileBindings");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::attachSessionActionSets(
    const XrSessionActionSetsAttachInfo *attachInfo, Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrAttachSessionActionSets(this->get(), attachInfo));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::attachSessionActionSets(
    const XrSessionActionSetsAttachInfo *attachInfo, Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrAttachSessionActionSets(this->get(), attachInfo));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING "::Session::attachSessionActionSets",
      {Result::Success, Result::SessionLossPending});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::getCurrentInteractionProfile(
    XrPath topLevelUserPath, XrInteractionProfileState *interactionProfile,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetCurrentInteractionProfile(
      this->get(), topLevelUserPath, interactionProfile));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::getCurrentInteractionProfile(
    XrPath topLevelUserPath, XrInteractionProfileState *interactionProfile,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetCurrentInteractionProfile(
      this->get(), topLevelUserPath, interactionProfile));
  return impl::createResultValue(result,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::getCurrentInteractionProfile",
                                 {Result::Success, Result::SessionLossPending});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::getActionStateBoolean(
    const XrActionStateGetInfo *getInfo, XrActionStateBoolean *state,
    Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrGetActionStateBoolean(this->get(), getInfo, state));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::getActionStateBoolean(
    const XrActionStateGetInfo *getInfo, XrActionStateBoolean *state,
    Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrGetActionStateBoolean(this->get(), getInfo, state));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING "::Session::getActionStateBoolean",
      {Result::Success, Result::SessionLossPending});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result
Session::getActionStateFloat(const XrActionStateGetInfo *getInfo,
                             XrActionStateFloat *state, Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrGetActionStateFloat(this->get(), getInfo, state));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result
Session::getActionStateFloat(const XrActionStateGetInfo *getInfo,
                             XrActionStateFloat *state, Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrGetActionStateFloat(this->get(), getInfo, state));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING "::Session::getActionStateFloat",
      {Result::Success, Result::SessionLossPending});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::getActionStateVector2f(
    const XrActionStateGetInfo *getInfo, XrActionStateVector2f *state,
    Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrGetActionStateVector2f(this->get(), getInfo, state));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::getActionStateVector2f(
    const XrActionStateGetInfo *getInfo, XrActionStateVector2f *state,
    Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrGetActionStateVector2f(this->get(), getInfo, state));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING "::Session::getActionStateVector2f",
      {Result::Success, Result::SessionLossPending});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result
Session::getActionStatePose(const XrActionStateGetInfo *getInfo,
                            XrActionStatePose *state, Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrGetActionStatePose(this->get(), getInfo, state));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result
Session::getActionStatePose(const XrActionStateGetInfo *getInfo,
                            XrActionStatePose *state, Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrGetActionStatePose(this->get(), getInfo, state));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING "::Session::getActionStatePose",
      {Result::Success, Result::SessionLossPending});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::syncActions(const XrActionsSyncInfo *syncInfo,
                                              Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrSyncActions(this->get(), syncInfo));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::syncActions(const XrActionsSyncInfo *syncInfo,
                                              Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrSyncActions(this->get(), syncInfo));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING "::Session::syncActions",
      {Result::Success, Result::SessionLossPending, Result::SessionNotFocused});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::enumerateBoundSourcesForAction(
    const XrBoundSourcesForActionEnumerateInfo *enumerateInfo,
    uint32_t sourceCapacityInput, uint32_t *sourceCountOutput, XrPath *sources,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrEnumerateBoundSourcesForAction(
      this->get(), enumerateInfo, sourceCapacityInput, sourceCountOutput,
      sources));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE ResultValue<std::vector<XrPath, Allocator>>
Session::enumerateBoundSourcesForAction(
    const XrBoundSourcesForActionEnumerateInfo *enumerateInfo,
    Dispatch &&d) const {
  // Two-call idiom
  std::vector<XrPath, Allocator> sources;
  uint32_t sourceCountOutput = 0;
  uint32_t sourceCapacityInput = 0;

  Result result = static_cast<Result>(d.xrEnumerateBoundSourcesForAction(
      this->get(), enumerateInfo, sourceCapacityInput, &sourceCountOutput,
      nullptr));
  if (!unqualifiedSuccess(result) || sourceCountOutput == 0) {

    return impl::createResultValue(
        result, sources,
        OPENXR_HPP_NAMESPACE_STRING "::Session::enumerateBoundSourcesForAction",
        {Result::Success, Result::SessionLossPending});
  }
  do {
    sources.resize(sourceCountOutput);
    sourceCapacityInput = static_cast<uint32_t>(sources.size());
    result = static_cast<Result>(d.xrEnumerateBoundSourcesForAction(
        this->get(), enumerateInfo, sourceCapacityInput, &sourceCountOutput,
        sources.data()));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(sourceCountOutput <= sources.size());
    sources.resize(sourceCountOutput);
  }

  return impl::createResultValue(result, sources,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::enumerateBoundSourcesForAction",
                                 {Result::Success, Result::SessionLossPending});
}

template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE ResultValue<std::vector<XrPath, Allocator>>
Session::enumerateBoundSourcesForAction(
    const XrBoundSourcesForActionEnumerateInfo *enumerateInfo,
    Allocator const &vectorAllocator, Dispatch &&d) const {
  // Two-call idiom
  std::vector<XrPath, Allocator> sources{vectorAllocator};
  uint32_t sourceCountOutput = 0;
  uint32_t sourceCapacityInput = 0;

  Result result = static_cast<Result>(d.xrEnumerateBoundSourcesForAction(
      this->get(), enumerateInfo, sourceCapacityInput, &sourceCountOutput,
      nullptr));
  if (!unqualifiedSuccess(result) || sourceCountOutput == 0) {

    return impl::createResultValue(
        result, sources,
        OPENXR_HPP_NAMESPACE_STRING "::Session::enumerateBoundSourcesForAction",
        {Result::Success, Result::SessionLossPending});
  }
  do {
    sources.resize(sourceCountOutput);
    sourceCapacityInput = static_cast<uint32_t>(sources.size());
    result = static_cast<Result>(d.xrEnumerateBoundSourcesForAction(
        this->get(), enumerateInfo, sourceCapacityInput, &sourceCountOutput,
        sources.data()));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(sourceCountOutput <= sources.size());
    sources.resize(sourceCountOutput);
  }

  return impl::createResultValue(result, sources,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::enumerateBoundSourcesForAction",
                                 {Result::Success, Result::SessionLossPending});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::getInputSourceLocalizedName(
    const XrInputSourceLocalizedNameGetInfo *getInfo,
    uint32_t bufferCapacityInput, uint32_t *bufferCountOutput, char *buffer,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetInputSourceLocalizedName(
      this->get(), getInfo, bufferCapacityInput, bufferCountOutput, buffer));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE ResultValue<string_with_allocator<Allocator>>
Session::getInputSourceLocalizedName(
    const XrInputSourceLocalizedNameGetInfo *getInfo, Dispatch &&d) const {
  // Two-call idiom
  std::vector<char, Allocator> buffer;
  uint32_t bufferCountOutput = 0;
  uint32_t bufferCapacityInput = 0;

  std::basic_string<char, std::char_traits<char>, Allocator> str{{}};
  Result result = static_cast<Result>(d.xrGetInputSourceLocalizedName(
      this->get(), getInfo, bufferCapacityInput, &bufferCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || bufferCountOutput == 0) {

    return impl::createResultValue(
        result, str,
        OPENXR_HPP_NAMESPACE_STRING "::Session::getInputSourceLocalizedName",
        {Result::Success, Result::SessionLossPending});
  }
  do {
    buffer.resize(bufferCountOutput);
    bufferCapacityInput = static_cast<uint32_t>(buffer.size());
    result = static_cast<Result>(d.xrGetInputSourceLocalizedName(
        this->get(), getInfo, bufferCapacityInput, &bufferCountOutput,
        buffer.data()));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(bufferCountOutput <= buffer.size());
    buffer.resize(bufferCountOutput);
  }

  str.assign(buffer.begin(), buffer.end());
  return impl::createResultValue(result, str,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::getInputSourceLocalizedName",
                                 {Result::Success, Result::SessionLossPending});
}

template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE ResultValue<string_with_allocator<Allocator>>
Session::getInputSourceLocalizedName(
    const XrInputSourceLocalizedNameGetInfo *getInfo,
    Allocator const &vectorAllocator, Dispatch &&d) const {
  // Two-call idiom
  std::vector<char, Allocator> buffer{vectorAllocator};
  uint32_t bufferCountOutput = 0;
  uint32_t bufferCapacityInput = 0;

  std::basic_string<char, std::char_traits<char>, Allocator> str{
      vectorAllocator};
  Result result = static_cast<Result>(d.xrGetInputSourceLocalizedName(
      this->get(), getInfo, bufferCapacityInput, &bufferCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || bufferCountOutput == 0) {

    return impl::createResultValue(
        result, str,
        OPENXR_HPP_NAMESPACE_STRING "::Session::getInputSourceLocalizedName",
        {Result::Success, Result::SessionLossPending});
  }
  do {
    buffer.resize(bufferCountOutput);
    bufferCapacityInput = static_cast<uint32_t>(buffer.size());
    result = static_cast<Result>(d.xrGetInputSourceLocalizedName(
        this->get(), getInfo, bufferCapacityInput, &bufferCountOutput,
        buffer.data()));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(bufferCountOutput <= buffer.size());
    buffer.resize(bufferCountOutput);
  }

  str.assign(buffer.begin(), buffer.end());
  return impl::createResultValue(result, str,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::getInputSourceLocalizedName",
                                 {Result::Success, Result::SessionLossPending});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::applyHapticFeedback(
    const XrHapticActionInfo *hapticActionInfo,
    const XrHapticBaseHeader *hapticFeedback, Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrApplyHapticFeedback(this->get(), hapticActionInfo, hapticFeedback));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::applyHapticFeedback(
    const XrHapticActionInfo *hapticActionInfo,
    const XrHapticBaseHeader *hapticFeedback, Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrApplyHapticFeedback(this->get(), hapticActionInfo, hapticFeedback));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING "::Session::applyHapticFeedback",
      {Result::Success, Result::SessionLossPending});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::stopHapticFeedback(
    const XrHapticActionInfo *hapticActionInfo, Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrStopHapticFeedback(this->get(), hapticActionInfo));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::stopHapticFeedback(
    const XrHapticActionInfo *hapticActionInfo, Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrStopHapticFeedback(this->get(), hapticActionInfo));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING "::Session::stopHapticFeedback",
      {Result::Success, Result::SessionLossPending});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#if defined(XR_USE_PLATFORM_ANDROID)

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::setAndroidApplicationThreadKHR(
    AndroidThreadTypeKHR threadType, uint32_t threadId, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrSetAndroidApplicationThreadKHR(
      this->get(), OPENXR_HPP_NAMESPACE::get(threadType), threadId));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::setAndroidApplicationThreadKHR(
    AndroidThreadTypeKHR threadType, uint32_t threadId, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrSetAndroidApplicationThreadKHR(
      this->get(), OPENXR_HPP_NAMESPACE::get(threadType), threadId));
  return impl::createResultValue(result,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::setAndroidApplicationThreadKHR",
                                 {Result::Success, Result::SessionLossPending});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_PLATFORM_ANDROID)

#if defined(XR_USE_PLATFORM_ANDROID)

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::createSwapchainAndroidSurfaceKHR(
    const XrSwapchainCreateInfo *info, Swapchain &swapchain, jobject *surface,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrCreateSwapchainAndroidSurfaceKHR(
      this->get(), info, swapchain.put(), surface));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValue<jobject>
Session::createSwapchainAndroidSurfaceKHR(const XrSwapchainCreateInfo *info,
                                          Swapchain &swapchain,
                                          Dispatch &&d) const {
  jobject handle;
  Result result = static_cast<Result>(d.xrCreateSwapchainAndroidSurfaceKHR(
      this->get(), info, swapchain.put(), handle.put()));
  return impl::createResultValue(result, handle,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::createSwapchainAndroidSurfaceKHR",
                                 {Result::Success, Result::SessionLossPending});
}
#ifndef OPENXR_HPP_NO_SMART_HANDLE

template <typename Dispatch>
OPENXR_HPP_INLINE
    ResultValue<UniqueHandle<jobject, impl::RemoveRefConst<Dispatch>>>
    Session::createSwapchainAndroidSurfaceUniqueKHR(
        const XrSwapchainCreateInfo *info, Swapchain &swapchain,
        Dispatch &&d) const {
  jobject handle;
  Result result = static_cast<Result>(d.xrCreateSwapchainAndroidSurfaceKHR(
      this->get(), info, swapchain.put(), handle.put()));
  ObjectDestroy<impl::RemoveRefConst<Dispatch>> deleter{d};
  return impl::createResultValue<jobject, impl::RemoveRefConst<Dispatch>>(
      result, handle, deleter,
      OPENXR_HPP_NAMESPACE_STRING
      "::Session::createSwapchainAndroidSurfaceUniqueKHR",
      {Result::Success, Result::SessionLossPending});
}

#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_PLATFORM_ANDROID)

#if defined(XR_USE_GRAPHICS_API_OPENGL)

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::getOpenGLGraphicsRequirementsKHR(
    XrSystemId systemId, XrGraphicsRequirementsOpenGLKHR *graphicsRequirements,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetOpenGLGraphicsRequirementsKHR(
      this->get(), systemId, graphicsRequirements));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Instance::getOpenGLGraphicsRequirementsKHR(
    XrSystemId systemId, XrGraphicsRequirementsOpenGLKHR *graphicsRequirements,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetOpenGLGraphicsRequirementsKHR(
      this->get(), systemId, graphicsRequirements));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING
      "::Instance::getOpenGLGraphicsRequirementsKHR");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_GRAPHICS_API_OPENGL)

#if defined(XR_USE_GRAPHICS_API_OPENGL_ES)

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::getOpenGLESGraphicsRequirementsKHR(
    XrSystemId systemId,
    XrGraphicsRequirementsOpenGLESKHR *graphicsRequirements,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetOpenGLESGraphicsRequirementsKHR(
      this->get(), systemId, graphicsRequirements));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Instance::getOpenGLESGraphicsRequirementsKHR(
    XrSystemId systemId,
    XrGraphicsRequirementsOpenGLESKHR *graphicsRequirements,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetOpenGLESGraphicsRequirementsKHR(
      this->get(), systemId, graphicsRequirements));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING
      "::Instance::getOpenGLESGraphicsRequirementsKHR");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_GRAPHICS_API_OPENGL_ES)

#if defined(XR_USE_GRAPHICS_API_VULKAN)

template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::getVulkanInstanceExtensionsKHR(
    XrSystemId systemId, uint32_t bufferCapacityInput,
    uint32_t *bufferCountOutput, char *buffer, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetVulkanInstanceExtensionsKHR(
      this->get(), systemId, bufferCapacityInput, bufferCountOutput, buffer));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE
    typename ResultValueType<string_with_allocator<Allocator>>::type
    Instance::getVulkanInstanceExtensionsKHR(XrSystemId systemId,
                                             Dispatch &&d) const {
  // Two-call idiom
  std::vector<char, Allocator> buffer;
  uint32_t bufferCountOutput = 0;
  uint32_t bufferCapacityInput = 0;

  std::basic_string<char, std::char_traits<char>, Allocator> str{{}};
  Result result = static_cast<Result>(d.xrGetVulkanInstanceExtensionsKHR(
      this->get(), systemId, bufferCapacityInput, &bufferCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || bufferCountOutput == 0) {

    return impl::createResultValue(
        result, str,
        OPENXR_HPP_NAMESPACE_STRING
        "::Instance::getVulkanInstanceExtensionsKHR");
  }
  do {
    buffer.resize(bufferCountOutput);
    bufferCapacityInput = static_cast<uint32_t>(buffer.size());
    result = static_cast<Result>(d.xrGetVulkanInstanceExtensionsKHR(
        this->get(), systemId, bufferCapacityInput, &bufferCountOutput,
        buffer.data()));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(bufferCountOutput <= buffer.size());
    buffer.resize(bufferCountOutput);
  }

  str.assign(buffer.begin(), buffer.end());
  return impl::createResultValue(result, str,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::getVulkanInstanceExtensionsKHR");
}

template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE
    typename ResultValueType<string_with_allocator<Allocator>>::type
    Instance::getVulkanInstanceExtensionsKHR(XrSystemId systemId,
                                             Allocator const &vectorAllocator,
                                             Dispatch &&d) const {
  // Two-call idiom
  std::vector<char, Allocator> buffer{vectorAllocator};
  uint32_t bufferCountOutput = 0;
  uint32_t bufferCapacityInput = 0;

  std::basic_string<char, std::char_traits<char>, Allocator> str{
      vectorAllocator};
  Result result = static_cast<Result>(d.xrGetVulkanInstanceExtensionsKHR(
      this->get(), systemId, bufferCapacityInput, &bufferCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || bufferCountOutput == 0) {

    return impl::createResultValue(
        result, str,
        OPENXR_HPP_NAMESPACE_STRING
        "::Instance::getVulkanInstanceExtensionsKHR");
  }
  do {
    buffer.resize(bufferCountOutput);
    bufferCapacityInput = static_cast<uint32_t>(buffer.size());
    result = static_cast<Result>(d.xrGetVulkanInstanceExtensionsKHR(
        this->get(), systemId, bufferCapacityInput, &bufferCountOutput,
        buffer.data()));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(bufferCountOutput <= buffer.size());
    buffer.resize(bufferCountOutput);
  }

  str.assign(buffer.begin(), buffer.end());
  return impl::createResultValue(result, str,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::getVulkanInstanceExtensionsKHR");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_GRAPHICS_API_VULKAN)

#if defined(XR_USE_GRAPHICS_API_VULKAN)

template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::getVulkanDeviceExtensionsKHR(
    XrSystemId systemId, uint32_t bufferCapacityInput,
    uint32_t *bufferCountOutput, char *buffer, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetVulkanDeviceExtensionsKHR(
      this->get(), systemId, bufferCapacityInput, bufferCountOutput, buffer));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE
    typename ResultValueType<string_with_allocator<Allocator>>::type
    Instance::getVulkanDeviceExtensionsKHR(XrSystemId systemId,
                                           Dispatch &&d) const {
  // Two-call idiom
  std::vector<char, Allocator> buffer;
  uint32_t bufferCountOutput = 0;
  uint32_t bufferCapacityInput = 0;

  std::basic_string<char, std::char_traits<char>, Allocator> str{{}};
  Result result = static_cast<Result>(d.xrGetVulkanDeviceExtensionsKHR(
      this->get(), systemId, bufferCapacityInput, &bufferCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || bufferCountOutput == 0) {

    return impl::createResultValue(result, str,
                                   OPENXR_HPP_NAMESPACE_STRING
                                   "::Instance::getVulkanDeviceExtensionsKHR");
  }
  do {
    buffer.resize(bufferCountOutput);
    bufferCapacityInput = static_cast<uint32_t>(buffer.size());
    result = static_cast<Result>(d.xrGetVulkanDeviceExtensionsKHR(
        this->get(), systemId, bufferCapacityInput, &bufferCountOutput,
        buffer.data()));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(bufferCountOutput <= buffer.size());
    buffer.resize(bufferCountOutput);
  }

  str.assign(buffer.begin(), buffer.end());
  return impl::createResultValue(result, str,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::getVulkanDeviceExtensionsKHR");
}

template <typename Allocator, typename Dispatch>
OPENXR_HPP_INLINE
    typename ResultValueType<string_with_allocator<Allocator>>::type
    Instance::getVulkanDeviceExtensionsKHR(XrSystemId systemId,
                                           Allocator const &vectorAllocator,
                                           Dispatch &&d) const {
  // Two-call idiom
  std::vector<char, Allocator> buffer{vectorAllocator};
  uint32_t bufferCountOutput = 0;
  uint32_t bufferCapacityInput = 0;

  std::basic_string<char, std::char_traits<char>, Allocator> str{
      vectorAllocator};
  Result result = static_cast<Result>(d.xrGetVulkanDeviceExtensionsKHR(
      this->get(), systemId, bufferCapacityInput, &bufferCountOutput, nullptr));
  if (!unqualifiedSuccess(result) || bufferCountOutput == 0) {

    return impl::createResultValue(result, str,
                                   OPENXR_HPP_NAMESPACE_STRING
                                   "::Instance::getVulkanDeviceExtensionsKHR");
  }
  do {
    buffer.resize(bufferCountOutput);
    bufferCapacityInput = static_cast<uint32_t>(buffer.size());
    result = static_cast<Result>(d.xrGetVulkanDeviceExtensionsKHR(
        this->get(), systemId, bufferCapacityInput, &bufferCountOutput,
        buffer.data()));
  } while (result == xr::Result::ErrorSizeInsufficient);
  if (result == xr::Result::Success) {
    OPENXR_HPP_ASSERT(bufferCountOutput <= buffer.size());
    buffer.resize(bufferCountOutput);
  }

  str.assign(buffer.begin(), buffer.end());
  return impl::createResultValue(result, str,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::getVulkanDeviceExtensionsKHR");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_GRAPHICS_API_VULKAN)

#if defined(XR_USE_GRAPHICS_API_VULKAN)

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::getVulkanGraphicsDeviceKHR(
    XrSystemId systemId, VkInstance vkInstance,
    VkPhysicalDevice *vkPhysicalDevice, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetVulkanGraphicsDeviceKHR(
      this->get(), systemId, vkInstance, vkPhysicalDevice));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Instance::getVulkanGraphicsDeviceKHR(XrSystemId systemId, VkInstance vkInstance,
                                     VkPhysicalDevice *vkPhysicalDevice,
                                     Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetVulkanGraphicsDeviceKHR(
      this->get(), systemId, vkInstance, vkPhysicalDevice));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::getVulkanGraphicsDeviceKHR");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_GRAPHICS_API_VULKAN)

#if defined(XR_USE_GRAPHICS_API_VULKAN)

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::getVulkanGraphicsRequirementsKHR(
    XrSystemId systemId, XrGraphicsRequirementsVulkanKHR *graphicsRequirements,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetVulkanGraphicsRequirementsKHR(
      this->get(), systemId, graphicsRequirements));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Instance::getVulkanGraphicsRequirementsKHR(
    XrSystemId systemId, XrGraphicsRequirementsVulkanKHR *graphicsRequirements,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetVulkanGraphicsRequirementsKHR(
      this->get(), systemId, graphicsRequirements));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING
      "::Instance::getVulkanGraphicsRequirementsKHR");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_GRAPHICS_API_VULKAN)

#if defined(XR_USE_GRAPHICS_API_D3D11)

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::getD3D11GraphicsRequirementsKHR(
    XrSystemId systemId, XrGraphicsRequirementsD3D11KHR *graphicsRequirements,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetD3D11GraphicsRequirementsKHR(
      this->get(), systemId, graphicsRequirements));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Instance::getD3D11GraphicsRequirementsKHR(
    XrSystemId systemId, XrGraphicsRequirementsD3D11KHR *graphicsRequirements,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetD3D11GraphicsRequirementsKHR(
      this->get(), systemId, graphicsRequirements));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::getD3D11GraphicsRequirementsKHR");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_GRAPHICS_API_D3D11)

#if defined(XR_USE_GRAPHICS_API_D3D12)

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::getD3D12GraphicsRequirementsKHR(
    XrSystemId systemId, XrGraphicsRequirementsD3D12KHR *graphicsRequirements,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetD3D12GraphicsRequirementsKHR(
      this->get(), systemId, graphicsRequirements));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Instance::getD3D12GraphicsRequirementsKHR(
    XrSystemId systemId, XrGraphicsRequirementsD3D12KHR *graphicsRequirements,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetD3D12GraphicsRequirementsKHR(
      this->get(), systemId, graphicsRequirements));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::getD3D12GraphicsRequirementsKHR");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_GRAPHICS_API_D3D12)

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::getVisibilityMaskKHR(
    ViewConfigurationType viewConfigurationType, uint32_t viewIndex,
    VisibilityMaskTypeKHR visibilityMaskType,
    XrVisibilityMaskKHR *visibilityMask, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetVisibilityMaskKHR(
      this->get(), OPENXR_HPP_NAMESPACE::get(viewConfigurationType), viewIndex,
      OPENXR_HPP_NAMESPACE::get(visibilityMaskType), visibilityMask));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::getVisibilityMaskKHR(
    ViewConfigurationType viewConfigurationType, uint32_t viewIndex,
    VisibilityMaskTypeKHR visibilityMaskType,
    XrVisibilityMaskKHR *visibilityMask, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrGetVisibilityMaskKHR(
      this->get(), OPENXR_HPP_NAMESPACE::get(viewConfigurationType), viewIndex,
      OPENXR_HPP_NAMESPACE::get(visibilityMaskType), visibilityMask));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING "::Session::getVisibilityMaskKHR",
      {Result::Success, Result::SessionLossPending});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#if defined(XR_USE_PLATFORM_WIN32)

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::convertWin32PerformanceCounterToTimeKHR(
    const LARGE_INTEGER *performanceCounter, XrTime *time, Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrConvertWin32PerformanceCounterToTimeKHR(
          this->get(), performanceCounter, time));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Instance::convertWin32PerformanceCounterToTimeKHR(
    const LARGE_INTEGER *performanceCounter, XrTime *time, Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrConvertWin32PerformanceCounterToTimeKHR(
          this->get(), performanceCounter, time));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING
      "::Instance::convertWin32PerformanceCounterToTimeKHR");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_PLATFORM_WIN32)

#if defined(XR_USE_PLATFORM_WIN32)

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::convertTimeToWin32PerformanceCounterKHR(
    XrTime time, LARGE_INTEGER *performanceCounter, Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrConvertTimeToWin32PerformanceCounterKHR(
          this->get(), time, performanceCounter));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Instance::convertTimeToWin32PerformanceCounterKHR(
    XrTime time, LARGE_INTEGER *performanceCounter, Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrConvertTimeToWin32PerformanceCounterKHR(
          this->get(), time, performanceCounter));
  return impl::createResultValue(
      result, OPENXR_HPP_NAMESPACE_STRING
      "::Instance::convertTimeToWin32PerformanceCounterKHR");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_PLATFORM_WIN32)

#if defined(XR_USE_TIMESPEC)

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::convertTimespecTimeToTimeKHR(
    const struct timespec *timespecTime, XrTime *time, Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrConvertTimespecTimeToTimeKHR(this->get(), timespecTime, time));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Instance::convertTimespecTimeToTimeKHR(const struct timespec *timespecTime,
                                       XrTime *time, Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrConvertTimespecTimeToTimeKHR(this->get(), timespecTime, time));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::convertTimespecTimeToTimeKHR");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_TIMESPEC)

#if defined(XR_USE_TIMESPEC)

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::convertTimeToTimespecTimeKHR(
    XrTime time, struct timespec *timespecTime, Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrConvertTimeToTimespecTimeKHR(this->get(), time, timespecTime));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Instance::convertTimeToTimespecTimeKHR(XrTime time,
                                       struct timespec *timespecTime,
                                       Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrConvertTimeToTimespecTimeKHR(this->get(), time, timespecTime));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::convertTimeToTimespecTimeKHR");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#endif // defined(XR_USE_TIMESPEC)

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::perfSettingsSetPerformanceLevelEXT(
    PerfSettingsDomainEXT domain, PerfSettingsLevelEXT level,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrPerfSettingsSetPerformanceLevelEXT(
      this->get(), OPENXR_HPP_NAMESPACE::get(domain),
      OPENXR_HPP_NAMESPACE::get(level)));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::perfSettingsSetPerformanceLevelEXT(
    PerfSettingsDomainEXT domain, PerfSettingsLevelEXT level,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrPerfSettingsSetPerformanceLevelEXT(
      this->get(), OPENXR_HPP_NAMESPACE::get(domain),
      OPENXR_HPP_NAMESPACE::get(level)));
  return impl::createResultValue(
      result,
      OPENXR_HPP_NAMESPACE_STRING
      "::Session::perfSettingsSetPerformanceLevelEXT",
      {Result::Success, Result::SessionLossPending});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::thermalGetTemperatureTrendEXT(
    PerfSettingsDomainEXT domain,
    PerfSettingsNotificationLevelEXT &notificationLevel, float *tempHeadroom,
    float *tempSlope, Dispatch &&d) const {
  XrPerfSettingsNotificationLevelEXT notificationLevel_tmp;
  Result result = static_cast<Result>(d.xrThermalGetTemperatureTrendEXT(
      this->get(), OPENXR_HPP_NAMESPACE::get(domain), notificationLevel_tmp,
      tempHeadroom, tempSlope));
  notificationLevel =
      static_cast<PerfSettingsNotificationLevelEXT>(notificationLevel_tmp);
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::thermalGetTemperatureTrendEXT(
    PerfSettingsDomainEXT domain,
    PerfSettingsNotificationLevelEXT &notificationLevel, float *tempHeadroom,
    float *tempSlope, Dispatch &&d) const {
  XrPerfSettingsNotificationLevelEXT notificationLevel_tmp;
  Result result = static_cast<Result>(d.xrThermalGetTemperatureTrendEXT(
      this->get(), OPENXR_HPP_NAMESPACE::get(domain), notificationLevel_tmp,
      tempHeadroom, tempSlope));
  notificationLevel =
      static_cast<PerfSettingsNotificationLevelEXT>(notificationLevel_tmp);
  return impl::createResultValue(result,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::thermalGetTemperatureTrendEXT",
                                 {Result::Success, Result::SessionLossPending});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::setDebugUtilsObjectNameEXT(
    const XrDebugUtilsObjectNameInfoEXT *nameInfo, Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrSetDebugUtilsObjectNameEXT(this->get(), nameInfo));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Instance::setDebugUtilsObjectNameEXT(
    const XrDebugUtilsObjectNameInfoEXT *nameInfo, Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrSetDebugUtilsObjectNameEXT(this->get(), nameInfo));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::setDebugUtilsObjectNameEXT");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::createDebugUtilsMessengerEXT(
    const XrDebugUtilsMessengerCreateInfoEXT *createInfo,
    DebugUtilsMessengerEXT &messenger, Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrCreateDebugUtilsMessengerEXT(
      this->get(), createInfo, messenger.put()));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<DebugUtilsMessengerEXT>::type
Instance::createDebugUtilsMessengerEXT(
    const XrDebugUtilsMessengerCreateInfoEXT *createInfo, Dispatch &&d) const {
  DebugUtilsMessengerEXT handle;
  Result result = static_cast<Result>(
      d.xrCreateDebugUtilsMessengerEXT(this->get(), createInfo, handle.put()));
  return impl::createResultValue(result, handle,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::createDebugUtilsMessengerEXT");
}
#ifndef OPENXR_HPP_NO_SMART_HANDLE

template <typename Dispatch>
OPENXR_HPP_INLINE typename ResultValueType<
    UniqueHandle<DebugUtilsMessengerEXT, impl::RemoveRefConst<Dispatch>>>::type
Instance::createDebugUtilsMessengerUniqueEXT(
    const XrDebugUtilsMessengerCreateInfoEXT *createInfo, Dispatch &&d) const {
  DebugUtilsMessengerEXT handle;
  Result result = static_cast<Result>(
      d.xrCreateDebugUtilsMessengerEXT(this->get(), createInfo, handle.put()));
  ObjectDestroy<impl::RemoveRefConst<Dispatch>> deleter{d};
  return impl::createResultValue<DebugUtilsMessengerEXT,
                                 impl::RemoveRefConst<Dispatch>>(
      result, handle, deleter,
      OPENXR_HPP_NAMESPACE_STRING
      "::Instance::createDebugUtilsMessengerUniqueEXT");
}

#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result DebugUtilsMessengerEXT::destroy(Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrDestroyDebugUtilsMessengerEXT(this->get()));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
DebugUtilsMessengerEXT::destroy(Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrDestroyDebugUtilsMessengerEXT(this->get()));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::DebugUtilsMessengerEXT::destroy");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Instance::submitDebugUtilsMessageEXT(
    XrDebugUtilsMessageSeverityFlagsEXT messageSeverity,
    XrDebugUtilsMessageTypeFlagsEXT messageTypes,
    const XrDebugUtilsMessengerCallbackDataEXT *callbackData,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrSubmitDebugUtilsMessageEXT(
      this->get(), messageSeverity, messageTypes, callbackData));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
Instance::submitDebugUtilsMessageEXT(
    XrDebugUtilsMessageSeverityFlagsEXT messageSeverity,
    XrDebugUtilsMessageTypeFlagsEXT messageTypes,
    const XrDebugUtilsMessengerCallbackDataEXT *callbackData,
    Dispatch &&d) const {
  Result result = static_cast<Result>(d.xrSubmitDebugUtilsMessageEXT(
      this->get(), messageSeverity, messageTypes, callbackData));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::Instance::submitDebugUtilsMessageEXT");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::sessionBeginDebugUtilsLabelRegionEXT(
    const XrDebugUtilsLabelEXT *labelInfo, Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrSessionBeginDebugUtilsLabelRegionEXT(this->get(), labelInfo));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::sessionBeginDebugUtilsLabelRegionEXT(
    const XrDebugUtilsLabelEXT *labelInfo, Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrSessionBeginDebugUtilsLabelRegionEXT(this->get(), labelInfo));
  return impl::createResultValue(
      result,
      OPENXR_HPP_NAMESPACE_STRING
      "::Session::sessionBeginDebugUtilsLabelRegionEXT",
      {Result::Success, Result::SessionLossPending});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result
Session::sessionEndDebugUtilsLabelRegionEXT(Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrSessionEndDebugUtilsLabelRegionEXT(this->get()));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result
Session::sessionEndDebugUtilsLabelRegionEXT(Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrSessionEndDebugUtilsLabelRegionEXT(this->get()));
  return impl::createResultValue(
      result,
      OPENXR_HPP_NAMESPACE_STRING
      "::Session::sessionEndDebugUtilsLabelRegionEXT",
      {Result::Success, Result::SessionLossPending});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::sessionInsertDebugUtilsLabelEXT(
    const XrDebugUtilsLabelEXT *labelInfo, Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrSessionInsertDebugUtilsLabelEXT(this->get(), labelInfo));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::sessionInsertDebugUtilsLabelEXT(
    const XrDebugUtilsLabelEXT *labelInfo, Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrSessionInsertDebugUtilsLabelEXT(this->get(), labelInfo));
  return impl::createResultValue(result,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::sessionInsertDebugUtilsLabelEXT",
                                 {Result::Success, Result::SessionLossPending});
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::createSpatialAnchorMSFT(
    const XrSpatialAnchorCreateInfoMSFT *createInfo, SpatialAnchorMSFT &anchor,
    Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrCreateSpatialAnchorMSFT(this->get(), createInfo, anchor.put()));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValue<SpatialAnchorMSFT>
Session::createSpatialAnchorMSFT(
    const XrSpatialAnchorCreateInfoMSFT *createInfo, Dispatch &&d) const {
  SpatialAnchorMSFT handle;
  Result result = static_cast<Result>(
      d.xrCreateSpatialAnchorMSFT(this->get(), createInfo, handle.put()));
  return impl::createResultValue(result, handle,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::createSpatialAnchorMSFT",
                                 {Result::Success, Result::SessionLossPending});
}
#ifndef OPENXR_HPP_NO_SMART_HANDLE

template <typename Dispatch>
OPENXR_HPP_INLINE
    ResultValue<UniqueHandle<SpatialAnchorMSFT, impl::RemoveRefConst<Dispatch>>>
    Session::createSpatialAnchorUniqueMSFT(
        const XrSpatialAnchorCreateInfoMSFT *createInfo, Dispatch &&d) const {
  SpatialAnchorMSFT handle;
  Result result = static_cast<Result>(
      d.xrCreateSpatialAnchorMSFT(this->get(), createInfo, handle.put()));
  ObjectDestroy<impl::RemoveRefConst<Dispatch>> deleter{d};
  return impl::createResultValue<SpatialAnchorMSFT,
                                 impl::RemoveRefConst<Dispatch>>(
      result, handle, deleter,
      OPENXR_HPP_NAMESPACE_STRING "::Session::createSpatialAnchorUniqueMSFT",
      {Result::Success, Result::SessionLossPending});
}

#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

template <typename Dispatch>
OPENXR_HPP_INLINE Result Session::createSpatialAnchorSpaceMSFT(
    const XrSpatialAnchorSpaceCreateInfoMSFT *createInfo, Space &space,
    Dispatch &&d) const {
  Result result = static_cast<Result>(
      d.xrCreateSpatialAnchorSpaceMSFT(this->get(), createInfo, space.put()));
  return result;
}
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValue<Space> Session::createSpatialAnchorSpaceMSFT(
    const XrSpatialAnchorSpaceCreateInfoMSFT *createInfo, Dispatch &&d) const {
  Space handle;
  Result result = static_cast<Result>(
      d.xrCreateSpatialAnchorSpaceMSFT(this->get(), createInfo, handle.put()));
  return impl::createResultValue(result, handle,
                                 OPENXR_HPP_NAMESPACE_STRING
                                 "::Session::createSpatialAnchorSpaceMSFT",
                                 {Result::Success, Result::SessionLossPending});
}
#ifndef OPENXR_HPP_NO_SMART_HANDLE

template <typename Dispatch>
OPENXR_HPP_INLINE
    ResultValue<UniqueHandle<Space, impl::RemoveRefConst<Dispatch>>>
    Session::createSpatialAnchorSpaceUniqueMSFT(
        const XrSpatialAnchorSpaceCreateInfoMSFT *createInfo,
        Dispatch &&d) const {
  Space handle;
  Result result = static_cast<Result>(
      d.xrCreateSpatialAnchorSpaceMSFT(this->get(), createInfo, handle.put()));
  ObjectDestroy<impl::RemoveRefConst<Dispatch>> deleter{d};
  return impl::createResultValue<Space, impl::RemoveRefConst<Dispatch>>(
      result, handle, deleter,
      OPENXR_HPP_NAMESPACE_STRING
      "::Session::createSpatialAnchorSpaceUniqueMSFT",
      {Result::Success, Result::SessionLossPending});
}

#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
template <typename Dispatch>
OPENXR_HPP_INLINE Result SpatialAnchorMSFT::destroy(Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrDestroySpatialAnchorMSFT(this->get()));
  return result;
}
#else  /* OPENXR_HPP_DISABLE_ENHANCED_MODE */

template <typename Dispatch>
OPENXR_HPP_INLINE ResultValueType<void>::type
SpatialAnchorMSFT::destroy(Dispatch &&d) const {
  Result result =
      static_cast<Result>(d.xrDestroySpatialAnchorMSFT(this->get()));
  return impl::createResultValue(result, OPENXR_HPP_NAMESPACE_STRING
                                 "::SpatialAnchorMSFT::destroy");
}
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

} // namespace OPENXR_HPP_NAMESPACE

#endif
