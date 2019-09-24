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


set(GENERATED_HEADER "${CMAKE_CURRENT_BINARY_DIR}/openxr.hpp")

set(SCRIPT_DIR ${PROJECT_SOURCE_DIR}/scripts)
set(XR_ROOT ${PROJECT_SOURCE_DIR}/../OpenXR-SDK-Source)
file(GLOB GENERATION_DEPS ${PROJECT_SOURCE_DIR}/scripts/*.py ${PROJECT_SOURCE_DIR}/scripts/*.hpp)
# Generate the header files and place it in the binary (build) directory.
add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/openxr.hpp
    COMMAND ${PYTHON_EXECUTABLE} ${PROJECT_SOURCE_DIR}/scripts/hpp_genxr.py
        -registry ${XR_ROOT}/specification/registry/xr.xml
        -o ${CMAKE_CURRENT_BINARY_DIR} openxr.hpp
    DEPENDS
        ${GENERATION_DEPS}
        ${XR_ROOT}/specification/registry/xr.xml
        ${XR_ROOT}/specification/scripts/conventions.py
        ${XR_ROOT}/specification/scripts/generator.py
        ${XR_ROOT}/specification/scripts/genxr.py
        ${XR_ROOT}/specification/scripts/reg.py
        ${XR_ROOT}/specification/scripts/xrconventions.py
        ${XR_ROOT}/src/scripts/automatic_source_generator.py
    COMMENT "Generating ${GENERATED_HEADER}"
)

set_source_files_properties(
    ${GENERATED_HEADER}
    PROPERTIES GENERATED TRUE
)

set(INSTALL_HEADERS
    ${GENERATED_HEADER})


# Define generate_openxr_header target to generate the OpenXR header files.
# Other targets that need the OpenXR headers should use generate_openxr_header as a dependency.
add_custom_target(generate_openxr_header
    SOURCES ${XR_ROOT}/specification/registry/xr.xml
    DEPENDS
    ${GENERATED_HEADER}
)
set_target_properties(generate_openxr_header PROPERTIES FOLDER ${CODEGEN_FOLDER})

INSTALL(FILES ${INSTALL_HEADERS}
    DESTINATION include/openxr
)
