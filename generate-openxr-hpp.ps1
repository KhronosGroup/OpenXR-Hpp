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

$Headers = foreach($line in Get-Content (Join-Path $PSScriptRoot headers.txt)) {
    $line = $line.Trim()
    # if (($line.Length -ne 0) -and ($line  -notmatch "^#")) {
    if ($line -match "^openxr") {
        Write-Output $line
    }
}

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
