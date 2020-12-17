#!/usr/bin/env bash
set -e


generate() {
    scripts/hpp_genxr.py -registry $OPENXR_REPO/specification/registry/xr.xml -o include/openxr $1

}
(
cd $(dirname $0)
if [ ! "$OPENXR_REPO" ]; then
    export OPENXR_REPO=$(cd .. && pwd)/OpenXR-SDK-Source
fi

generate openxr_duration.hpp
generate openxr_dynamic_dispatch.hpp
generate openxr_enums.hpp
generate openxr_static_dispatch.hpp
generate openxr_time.hpp
generate openxr_version.hpp
generate openxr.hpp

clang-format-6.0 -style=file -i include/openxr/*.hpp
)
