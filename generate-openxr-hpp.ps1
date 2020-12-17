[CmdletBinding()]
param (
    [Parameter()]
    [string]
    $OpenXRRepo = (Join-Path (Get-Item "$PSScriptRoot").parent "OpenXR-SDK-Source"),

    
    [Parameter()]
    [string]
    $Python = "python3",
    
    [Parameter()]
    [string]
    $ClangFormat = "clang-format"
)
$Headers = "openxr.hpp", "openxr_version.hpp", "openxr_static_dispatch.hpp", "openxr_dynamic_dispatch.hpp", "openxr_time.hpp", "openxr_duration.hpp", "openxr_enums.hpp"

# if ($OpenXRRepo.Length == 0) {
#     $OpenXRRepo = Join-Path "$PSScriptRoot" ".." ".." "OpenXR-SDK-Source"
# }

$Registry = Join-Path "$OpenXRRepo" "specification" "registry" "xr.xml"
$OutputLocation = Join-Path "$PSScriptRoot" "include" "openxr"
$Script = Join-Path "$PSScriptRoot" "scripts" "hpp_genxr.py"

foreach ($header in $Headers) {
    $OutFile = (Join-Path $OutputLocation $header)
    if (Test-Path $OutFile) {
        Remove-Item $OutFile
    }
    & $Python "$Script" -registry "$Registry" -o "$OutputLocation" $header
}
& $ClangFormat -style=file -i (Get-ChildItem $OutputLocation -Filter "*.hpp")