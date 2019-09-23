#!/usr/bin/env bash
set -e

(
cd $(dirname $0)
if [ ! "$OPENXR_REPO" ]; then
    export OPENXR_REPO=$(cd .. && pwd)/OpenXR-SDK-Source
fi
scripts/hpp_genxr.py -registry $OPENXR_REPO/specification/registry/xr.xml -o include/openxr openxr.hpp
clang-format-6.0 -style=file -i include/openxr/openxr.hpp

)
