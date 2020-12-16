#!/usr/bin/env bash
set -e

(
cd $(dirname $0)
if [ ! "$OPENXR_REPO" ]; then
    export OPENXR_REPO=$(cd .. && pwd)/OpenXR-SDK-Source
fi
for fn in openxr.hpp openxr_version.hpp openxr_static_dispatch.hpp openxr_dynamic_dispatch.hpp openxr_time.hpp openxr_duration.hpp openxr_enums.hpp; do
    scripts/hpp_genxr.py -registry $OPENXR_REPO/specification/registry/xr.xml -o include/openxr $fn
    clang-format-6.0 -style=file -i include/openxr/*.hpp
done

)
