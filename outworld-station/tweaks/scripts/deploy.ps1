#requires -Version 7.0
<#
.SYNOPSIS
    Build, package, and optionally install OWS Tweaks as a UE4SS
    C++ mod for Outworld Station.

.DESCRIPTION
    Default behavior (-Package): builds the release cdylib and zips
    a UE4SS-mod-folder-shaped archive at
    `dist\ows-tweaks-v<version>.zip` for upload / manual install.
    Zip layout (mirrors the path inside the game install):

        OutworldStation/Binaries/Win64/ue4ss/Mods/Tweaks/
            dlls/main.dll

    Manual install: extract over the game's root and add
    `Tweaks : 1` to mods.txt.

    -Install does a direct local install to the game folder instead
    of building a zip.

    -Uninstall removes the mod from the local game install.

.PARAMETER Package
    Build a installable zip in `dist\` (default mode).

.PARAMETER Install
    Skip packaging; copy the mod folder directly into the local
    game install's UE4SS Mods directory.

.PARAMETER Uninstall
    Remove the mod folder from the local game install.

.PARAMETER GamePath
    Override game install auto-detection. Path to the game's root
    (the folder containing `OutworldStation\Binaries\Win64\`).

.PARAMETER SkipBuild
    Skip the cargo build step. Use when iterating on this script
    against an already-built DLL.

.EXAMPLE
    .\scripts\deploy.ps1 -Install
    Build and install directly into the local Outworld Station install.
#>

[CmdletBinding(DefaultParameterSetName = 'Package')]
param(
    [Parameter(ParameterSetName = 'Package')]
    [switch]$Package,

    [Parameter(ParameterSetName = 'Install')]
    [switch]$Install,

    [Parameter(ParameterSetName = 'Uninstall')]
    [switch]$Uninstall,

    [string]$GamePath,
    [switch]$SkipBuild
)

$ErrorActionPreference = 'Stop'
# Repo root is three levels up from outworld-station/tweaks/scripts/
# (scripts -> tweaks -> outworld-station -> repo root).
$RepoRoot = Split-Path -Parent (Split-Path -Parent (Split-Path -Parent $PSScriptRoot))
# Per-crate target dir so tweaks's main.dll never collides with
# better-backpack's main.dll (both crates produce a lib named
# "main" so they share the same artifact path under target/release/
# without --target-dir).
$TargetDir = Join-Path $RepoRoot 'target\tweaks'
$BuiltDll = Join-Path $TargetDir 'x86_64-pc-windows-msvc\release\main.dll'
$DistDir = Join-Path $RepoRoot 'dist'

# Mod folder name + relative path inside the game install. UE4SS
# loads CPPMods from <ModParent>\<ModFolderName>\dlls\main.dll.
$ModFolderName = 'Tweaks'
$RelModParent = 'OutworldStation\Binaries\Win64\ue4ss\Mods'

function Get-ModVersion {
    $cargoToml = Join-Path $RepoRoot 'Cargo.toml'
    $text = Get-Content $cargoToml -Raw
    if ($text -match '(?m)^\s*version\s*=\s*"([^"]+)"') {
        return $matches[1]
    }
    return '0.0.0'
}

function Find-OwsRoot {
    $steamRoot = $null
    foreach ($key in @(
        'HKLM:\SOFTWARE\WOW6432Node\Valve\Steam',
        'HKLM:\SOFTWARE\Valve\Steam',
        'HKCU:\Software\Valve\Steam'
    )) {
        $val = Get-ItemProperty -Path $key -Name InstallPath -ErrorAction SilentlyContinue
        if ($val) { $steamRoot = $val.InstallPath; break }
    }
    if (-not $steamRoot) {
        throw "Steam install not found in registry. Pass -GamePath explicitly."
    }
    $vdf = Join-Path $steamRoot 'steamapps\libraryfolders.vdf'
    if (-not (Test-Path $vdf)) {
        throw "Steam library config not found at $vdf. Pass -GamePath explicitly."
    }
    $vdfText = Get-Content $vdf -Raw
    $libraries = [regex]::Matches($vdfText, '"path"\s*"([^"]+)"') |
        ForEach-Object { $_.Groups[1].Value -replace '\\\\', '\' }
    foreach ($lib in $libraries) {
        $common = Join-Path $lib 'steamapps\common'
        if (-not (Test-Path $common)) { continue }
        foreach ($dir in (Get-ChildItem $common -Directory -ErrorAction SilentlyContinue)) {
            if ($dir.Name -notmatch 'Outworld') { continue }
            if (Test-Path (Join-Path $dir.FullName 'OutworldStation\Binaries\Win64')) {
                return $dir.FullName
            }
        }
    }
    throw "Outworld Station install not found in any Steam library. Pass -GamePath explicitly."
}

function Resolve-GameRoot {
    if ($GamePath) {
        if (-not (Test-Path $GamePath)) {
            throw "Provided -GamePath does not exist: $GamePath"
        }
        return (Resolve-Path $GamePath).Path
    }
    return Find-OwsRoot
}

function Test-UE4SSInstalled {
    param([string]$GameRoot)
    $ue4ssDll = Join-Path $GameRoot 'OutworldStation\Binaries\Win64\ue4ss\UE4SS.dll'
    return Test-Path $ue4ssDll
}

function Update-ModsTxt {
    param([string]$ModsDir)
    $modsTxt = Join-Path $ModsDir 'mods.txt'
    if (-not (Test-Path $modsTxt)) {
        Write-Host "    mods.txt not found at $modsTxt; creating" -ForegroundColor DarkYellow
        Set-Content -Path $modsTxt -Value "$ModFolderName : 1"
        return
    }
    $content = Get-Content $modsTxt
    $entry = "$ModFolderName : 1"
    if ($content -match "^\s*$ModFolderName\s*:") {
        Write-Host "    mods.txt already registers $ModFolderName" -ForegroundColor DarkGray
        return
    }
    Write-Host "    appending '$entry' to mods.txt"
    Add-Content -Path $modsTxt -Value $entry
}

function Invoke-Build {
    if ($SkipBuild) { return }
    Write-Host "==> cargo build -p tweaks --release --target-dir $TargetDir" -ForegroundColor Cyan
    Push-Location $RepoRoot
    try {
        & cargo build -p tweaks --release --target-dir $TargetDir
        if ($LASTEXITCODE -ne 0) { throw "cargo build failed (exit $LASTEXITCODE)" }
    } finally {
        Pop-Location
    }
    if (-not (Test-Path $BuiltDll)) {
        throw "main.dll not produced at $BuiltDll"
    }
}

function Build-StageTree {
    param([string]$StageRoot)

    $modRoot = Join-Path $StageRoot $RelModParent | Join-Path -ChildPath $ModFolderName
    $dllsDir = Join-Path $modRoot 'dlls'
    New-Item -ItemType Directory -Path $dllsDir -Force | Out-Null
    Copy-Item -Path $BuiltDll -Destination (Join-Path $dllsDir 'main.dll') -Force
    Write-Host "    + $ModFolderName/dlls/main.dll"
    return $modRoot
}

function Invoke-Package {
    Invoke-Build
    if (-not (Test-Path $DistDir)) {
        New-Item -ItemType Directory -Path $DistDir | Out-Null
    }
    $version = Get-ModVersion
    $stageDir = Join-Path $DistDir "stage-tweaks-$version"
    if (Test-Path $stageDir) {
        Remove-Item -Recurse -Force $stageDir
    }
    New-Item -ItemType Directory -Path $stageDir | Out-Null

    Write-Host "==> staging $ModFolderName at $stageDir" -ForegroundColor Cyan
    Build-StageTree -StageRoot $stageDir | Out-Null

    $zipPath = Join-Path $DistDir "ows-tweaks-v$version.zip"
    if (Test-Path $zipPath) {
        Remove-Item -Force $zipPath
    }
    Write-Host "==> writing $zipPath" -ForegroundColor Cyan
    Compress-Archive -Path (Join-Path $stageDir '*') -DestinationPath $zipPath -CompressionLevel Optimal

    Remove-Item -Recurse -Force $stageDir
    $size = (Get-Item $zipPath).Length
    Write-Host ("==> done ({0:N0} bytes)" -f $size) -ForegroundColor Green
    Write-Host "Upload / manual install: $zipPath"
}

function Invoke-Install {
    Invoke-Build
    $gameRoot = Resolve-GameRoot
    if (-not (Test-UE4SSInstalled $gameRoot)) {
        throw @"
UE4SS is not installed at $gameRoot\OutworldStation\Binaries\Win64\ue4ss\
Install it first (drop UE4SS files into OutworldStation\Binaries\Win64\),
then re-run.
"@
    }

    $modsDir = Join-Path $gameRoot $RelModParent
    $modDir = Join-Path $modsDir $ModFolderName
    Write-Host "==> deploying to $modDir" -ForegroundColor Cyan

    $dllsDir = Join-Path $modDir 'dlls'
    New-Item -ItemType Directory -Path $dllsDir -Force | Out-Null
    try {
        Copy-Item -Path $BuiltDll -Destination (Join-Path $dllsDir 'main.dll') -Force
        Write-Host "    copied main.dll"
    } catch [System.IO.IOException] {
        throw "Failed to copy main.dll. The game is probably running and holding the DLL — quit Outworld Station, then re-run."
    }

    Update-ModsTxt -ModsDir $modsDir

    Write-Host "==> done. Launch Outworld Station to load the mod." -ForegroundColor Green
    Write-Host "Then test:"
    Write-Host "  set OWS_DEBUG_PORT=17172"
    Write-Host "  cargo test -p tweaks --test smoke -- --test-threads=1 --nocapture"
}

function Invoke-Uninstall {
    $gameRoot = Resolve-GameRoot
    $modsDir = Join-Path $gameRoot $RelModParent
    $modDir = Join-Path $modsDir $ModFolderName

    if (-not (Test-Path $modDir)) {
        Write-Host "==> no $ModFolderName folder at $modDir; nothing to remove" -ForegroundColor DarkGray
        return
    }

    Write-Host "==> removing $modDir" -ForegroundColor Cyan
    Remove-Item -Recurse -Force $modDir

    $modsTxt = Join-Path $modsDir 'mods.txt'
    if (Test-Path $modsTxt) {
        $lines = Get-Content $modsTxt
        $filtered = $lines | Where-Object { $_ -notmatch "^\s*$ModFolderName\s*:" }
        if ($filtered.Count -ne $lines.Count) {
            Write-Host "    removing $ModFolderName from mods.txt"
            Set-Content -Path $modsTxt -Value $filtered
        }
    }

    Write-Host "==> done" -ForegroundColor Green
}

switch ($PSCmdlet.ParameterSetName) {
    'Install'   { Invoke-Install }
    'Uninstall' { Invoke-Uninstall }
    default     { Invoke-Package }
}
