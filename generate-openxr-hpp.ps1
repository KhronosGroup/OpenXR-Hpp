[CmdletBinding()]
param (
    [Parameter()]
    [string]
    $OpenXRRepo = (Join-Path (Get-Item "$PSScriptRoot").parent "OpenXR-SDK-Source"),


    [Parameter()]
    [string]
    $Python = "python3.exe",

    [Parameter()]
    [string]
    $ClangFormat = "clang-format.exe",

    [Parameter()]
    [switch]
    $Noisy = $false,

    [Parameter()]
    [switch]
    $Docs = $false,

    [Parameter()]
    [string]
    $Doxygen = "doxygen.exe"
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

# for progress bar
$Total = $Headers.Length + 1
$Counter = 0

foreach ($header in $Headers) {
    $Counter++
    $OutFile = (Join-Path $OutputLocation $header)
    if (Test-Path $OutFile) {
        Remove-Item $OutFile
    }
    $myArgs = "$Script","-registry","$Registry","-o","$OutputLocation","$header"
    if ($Noisy -eq $false) {
        $myArgs += "-quiet"
        Write-Progress -Activity "Generating Headers" -CurrentOperation $header -PercentComplete (($Counter / $Total) * 100)
    }
    $process = (Start-Process $Python -NoNewWindow -Wait -PassThru -ArgumentList $myArgs )
    if ($process.ExitCode -ne 0) {
        throw "Generation failed while generating ${header} : ${process.ExitCode}"
    }
    # & $ClangFormat -style=file -i $OutFile
}
Write-Host "Formatting generated files"
if ($Noisy -eq $false) {
    Write-Progress -Activity "Formatting Headers" -PercentComplete 100
}

& $ClangFormat -style=file -i ($Headers | ForEach-Object { Write-Output (Join-Path $OutputLocation $_) })

if ($Docs) {
    if ($Noisy -eq $false) {
        Write-Progress -Activity "Generating docs"
    }
    & $Doxygen Doxyfile
}
