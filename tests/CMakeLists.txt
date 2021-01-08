# Copyright (c) 2017-2021 The Khronos Group Inc.
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

find_package(Vulkan REQUIRED)

file(GLOB TEST_FILES *.cpp)

foreach(FILE_NAME ${TEST_FILES})
    get_filename_component(FN ${FILE_NAME} NAME_WE)
    file(READ ${FILE_NAME} TEST_SOURCE)
    if(TEST_SOURCE MATCHES "gtest.h")
        if(GTEST_FOUND)
            add_executable(${FN} ${FILE_NAME})
            target_link_libraries(${FN} PRIVATE GTest::GTest GTest::Main)
            gtest_add_tests(TARGET ${FN} AUTO)
        endif()
    else()
        add_library(${FN} STATIC ${FILE_NAME})
    endif()

    set_target_properties(${FN} PROPERTIES FOLDER "Tests")
    target_link_libraries(${FN} PRIVATE OpenXR::Headers)
    target_include_directories(${FN} PRIVATE ${PROJECT_BINARY_DIR}/include)
    add_dependencies(${FN} generate_headers)
    if(TEST_SOURCE MATCHES "XR_USE_GRAPHICS_API_VULKAN")
        target_link_libraries(${FN} PRIVATE Vulkan::Vulkan)
    endif()
endforeach()

# Make sure each .hpp file can compile cleanly on its own.
foreach(FN ${GENERATED_HEADER_FILENAMES})
    if(FN MATCHES "[.]hpp")
        string(REPLACE ".hpp" "" TARGET_NAME "buildcleanly_${FN}")
        configure_file(
            build_cleanly.cpp.in ${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME}.cpp
            @ONLY
        )
        add_library(
            ${TARGET_NAME} STATIC
            ${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME}.cpp
        )
        set_target_properties(${TARGET_NAME} PROPERTIES FOLDER "Tests")
        target_link_libraries(${TARGET_NAME} PRIVATE OpenXR::Headers)
        target_include_directories(
            ${TARGET_NAME} PRIVATE ${PROJECT_BINARY_DIR}/include
        )
        add_dependencies(${TARGET_NAME} generate_headers)
    endif()
endforeach()
