#!/bin/sh
set -e
(
cd $(dirname $0)
src/scripts/src_genxr.py -registry specification/registry/xr.xml -o include/openxr openxr.hpp
clang-format -style=file -i include/openxr/openxr.hpp

)
