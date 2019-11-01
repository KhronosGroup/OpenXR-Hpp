# OpenXR-HPP project

This repository contains build scripts and test files for the `openxr.hpp` header, providing a C++-friendly projection of the OpenXR API.

The authoritative public repository is located at
<https://github.com/KhronosGroup/OpenXR-HPP/>. It hosts the public Issue
tracker, and accepts patches (Pull Requests) from the general public.

If you want to simply write an application using OpenXR (the headers and
loader), with minimum dependencies, see
<https://github.com/KhronosGroup/OpenXR-SDK/>. That project will likely contain
the `openxr.hpp` artifact when it is ready for widespread production usage.

To build this project, you must have OpenXR-SDK-Source cloned in a peer
directory of this one.

## Directory Structure

- `README.md` - This file
- `COPYING.md` - Copyright and licensing information
- `CODE_OF_CONDUCT.md` - Code of Conduct
- `include/` - Build system to generate the openxr.hpp file
- `specification/` - xr.xml file
- `scripts/` - Source code for various projects
- `tests/` - some simple files that ensures the header is always compilable.

## Building

If you just want to generate the header, run `./generate-openxr-hpp.sh` or
`./generate-openxr-hpp.bat`. If your OpenXR-SDK-Source (or internal gitlab) repo
isn't in a directory named that parallel to this one, you can set OPENXR_REPO
environment variable before running. Requires clang-format, preferably 6.0.

If you'd like to build the tests (making sure the header can compile),
use CMake to generate a build system, like:

```sh
mkdir build
cd build
cmake ..
make
```
