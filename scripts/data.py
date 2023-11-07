#!/usr/bin/env python3 -i
# Copyright 2013-2023 The Khronos Group Inc.
#
# SPDX-License-Identifier: Apache-2.0
"""Collections of strings and names that affect the projection generation."""

EXCLUDED_EXTENSIONS = (
    # Atom not projecting right?
    "XR_MSFT_controller_model",
    # Projection of static string fails
    "XR_MSFT_spatial_graph_bridge",
    "XR_MSFT_spatial_anchor_persistence",
    "XR_MSFT_holographic_window_attachment",
    # Projection of UuidMSFT fails
    "XR_MSFT_scene_understanding",
    "XR_MSFT_scene_understanding_serialization",
)


VALID_FOR_NULL_INSTANCE = set((
    'xrEnumerateInstanceExtensionProperties',
    'xrEnumerateApiLayerProperties',
    'xrCreateInstance',
    'xrLoaderInitKHR',
))

# These break the projection right now.
SKIP = set((
    'xrGetSceneComputeStateMSFT',
    'xrGetSwapchainStateFB',
))

DISCOURAGED = set((
    'xrResultToString',
    'xrStructureTypeToString',
))

TEMPLATED_TWO_CALL = set([
    'xrEnumerateSwapchainImages'
])

MANUALLY_PROJECTED_SCALARS = set((
    "XrTime",
    "XrDuration",
))

MANUALLY_PROJECTED = set((
    "XrEventDataBuffer",
)).union(MANUALLY_PROJECTED_SCALARS)

SKIP_PROJECTION = set((
    "XrBaseInStructure",
    "XrBaseOutStructure",
    # Array of XrColor4f not getting initialized right
    "XrPassthroughColorMapMonoToRgbaFB",
))

UPPER_TOKENS = set((
    "API",
    "CV1",
    "EGL",
    "ES",
    "RGB",
    "CW",  # clockwise
    "CCW",  # counter-clockwise
))

SPECIAL_TOKENS = {
    "OPENGL": "OpenGL"
}
