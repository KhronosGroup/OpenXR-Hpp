@echo off
if "%OPENXR_REPO%" == "" SET OPENXR_REPO=%cd%/../OpenXR-SDK-Source
if "%PYTHON_EXE%" == "" SET PYTHON_EXE=python.exe
if "%CLANG_FORMAT_EXE%" == "" SET CLANG_FORMAT_EXE=clang-format-6.0
%PYTHON_EXE% scripts/hpp_genxr.py -registry %OPENXR_REPO%/specification/registry/xr.xml -o include/openxr openxr.hpp
%CLANG_FORMAT_EXE% -style=file -i include/openxr/openxr.hpp
