#!/usr/bin/env python3 -i
# Copyright 2013-2023 The Khronos Group Inc.
#
# SPDX-License-Identifier: Apache-2.0
"""Collections of strings and names that affect the projection generation."""

EXCLUDED_EXTENSIONS = (
)


VALID_FOR_NULL_INSTANCE = set((
    'xrEnumerateInstanceExtensionProperties',
    'xrEnumerateApiLayerProperties',
    'xrCreateInstance',
    'xrLoaderInitKHR',
))

# These break the projection right now.
SKIP = set((
))

DISCOURAGED = set((
    'xrResultToString',
    'xrStructureTypeToString',
))

MANUALLY_PROJECTED_SCALARS = set((
    "XrTime",
    "XrDuration",
    "XrBool32",
))

MANUALLY_PROJECTED = set((
    "XrEventDataBuffer",
    "XrFutureCompletionBaseHeaderEXT",
)).union(MANUALLY_PROJECTED_SCALARS)

PROJECTED_NATIVE_C_TYPE = set((
    "int8_t",
    "int32_t",
    "int64_t",
    "uint8_t",
    "uint32_t",
    "uint64_t",
    "float",
    "XrSpaceUserIdFB",
))

SKIP_PROJECTION = set((
    "XrBaseInStructure",
    "XrBaseOutStructure",
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
