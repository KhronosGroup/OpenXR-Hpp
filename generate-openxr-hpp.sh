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


grep "^openxr" headers.txt | while read fn; do
    generate "$fn"
done

clang-format -style=file -i include/openxr/*.hpp include/openxr/*.inl
)
