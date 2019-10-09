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

# Note: This is the top-level CMake file for the OpenXR project.
# It should contain only definitions that are applicable to the
# entire project and includes for the sub-directories.

cmake_minimum_required(VERSION 3.12)

option(BUILD_TESTS "Build tests" ON)
MESSAGE(STATUS "Build tests:           " ${BUILD_TESTS})

if (BUILD_TESTS OR BUILD_TOOLS)
    include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/ezvcpkg.cmake)
    ezvcpkg_fetch(
        PACKAGES gtest
        OUTPUT EZVCPKG_DIR
        UPDATE_TOOLCHAIN
        USE_HOST_VCPKG
    )
endif()

project(OpenXR_hpp)

find_package(PythonInterp 3 REQUIRED)

# Enable IDE GUI folders.  "Helper targets" that don't have interesting source code should set their FOLDER property to this
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake predefined targets")
set(HELPER_FOLDER "Helpers")
set(CODEGEN_FOLDER "Generated")
set(TESTS_FOLDER "Tests")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
find_package(OpenXR REQUIRED)

add_subdirectory(include)

if (BUILD_TESTS)
    include(CTest)
    enable_testing()
    find_package(GTest REQUIRED)
    find_package(GTest MODULE REQUIRED)                                      
    add_subdirectory(tests)
endif()


#install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE" DESTINATION share/doc/openxr)




