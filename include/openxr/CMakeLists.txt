# Copyright (c) 2017-2019 The Khronos Group Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# Author:
#

# Generate OpenXR header files.

set(HEADER_LIST_FILE "${CMAKE_CURRENT_SOURCE_DIR}/../../headers.txt")

# Re-run CMake if that file changes
set_property(
    DIRECTORY
    APPEND
    PROPERTY CMAKE_CONFIGURE_DEPENDS ${HEADER_LIST_FILE}
)
file(STRINGS ${HEADER_LIST_FILE} HEADER_FILENAMES REGEX "^openxr")
set(GENERATED_HEADER_FILENAMES
    "${HEADER_FILENAMES}"
    CACHE INTERNAL ""
)

set(SCRIPT_DIR ${PROJECT_SOURCE_DIR}/scripts)
set(XR_ROOT ${PROJECT_SOURCE_DIR}/../OpenXR-SDK-Source)
file(GLOB GENERATION_DEPS ${PROJECT_SOURCE_DIR}/scripts/*)

# Generate the header files and place it in the binary (build) directory.
foreach(FN ${HEADER_FILENAMES})
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${FN}
        COMMAND
            ${PYTHON_EXECUTABLE} ${PROJECT_SOURCE_DIR}/scripts/hpp_genxr.py
            -registry ${XR_ROOT}/specification/registry/xr.xml -o
            ${CMAKE_CURRENT_BINARY_DIR} -quiet ${FN}
        DEPENDS ${GENERATION_DEPS}
                ${XR_ROOT}/specification/registry/xr.xml
                ${XR_ROOT}/specification/scripts/conventions.py
                ${XR_ROOT}/specification/scripts/generator.py
                ${XR_ROOT}/specification/scripts/genxr.py
                ${XR_ROOT}/specification/scripts/reg.py
                ${XR_ROOT}/specification/scripts/xrconventions.py
                ${XR_ROOT}/src/scripts/automatic_source_generator.py
        COMMENT "Generating ${FN}"
    )

    set_source_files_properties(
        ${CMAKE_CURRENT_BINARY_DIR}/${FN} PROPERTIES GENERATED TRUE
    )
    list(APPEND GENERATED_HEADERS ${CMAKE_CURRENT_BINARY_DIR}/${FN})
endforeach()

# Define generate_headers target to generate the OpenXR header files. Other
# targets that need the OpenXR headers should use generate_openxr_header as a
# dependency.
add_custom_target(
    generate_headers
    SOURCES ${XR_ROOT}/specification/registry/xr.xml ${GENERATION_DEPS}
    DEPENDS ${GENERATED_HEADERS}
)
set_target_properties(generate_headers PROPERTIES FOLDER ${CODEGEN_FOLDER})

install(
    FILES ${GENERATED_HEADERS}
    DESTINATION include/openxr
)
