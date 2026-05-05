#requires -Version 7.0
<#
.SYNOPSIS
    Build, package, and optionally install the Better Backpack mod
    as a UE4SS C++ mod.

.DESCRIPTION
    Default behavior (-Package): builds the release cdylib and zips
    a UE4SS-mod-folder-shaped archive at
    `dist\better-backpack-<version>.zip` for upload to Nexus and
    install via Vortex. Zip layout (mirrors the path Vortex deploys
    to inside the game install):

        Augusta/Binaries/WinGRTS/ue4ss/Mods/BetterBackpack/
            dlls/main.dll
            settings.json

    Vortex's UE4SS extension knows about that path and merges the
    mods.txt registration entry on deploy. Manual install: extract
    over the game's root and add `BetterBackpack : 1` to mods.txt.

    -Install does a direct local install to the game folder instead
    of building a zip. Useful for iterating on the mod without going
    through Vortex.

    -Uninstall removes the mod from the local game install.

.PARAMETER Package
    Build a Vortex-installable zip in `dist\` (default mode).

.PARAMETER Install
    Skip packaging; copy the mod folder directly into the local game
    install's UE4SS Mods directory.

.PARAMETER Uninstall
    Remove the mod folder from the local game install. Leaves
    settings.json.

.PARAMETER GamePath
    Override game install auto-detection. Path to the game's root
    (the folder containing `Augusta\Binaries\WinGRTS\`).

.PARAMETER SkipBuild
    Skip the cargo build step. Use when iterating on this script
    against an already-built DLL.

.EXAMPLE
    .\scripts\deploy.ps1
    Build and produce `dist\better-backpack-<version>.zip`.

.EXAMPLE
    .\scripts\deploy.ps1 -Install
    Build and install directly into the local Grounded 2 install.

.EXAMPLE
    .\scripts\deploy.ps1 -Uninstall
    Remove the mod from the local Grounded 2 install.
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
$RepoRoot = Split-Path -Parent $PSScriptRoot
$BuiltDll = Join-Path $RepoRoot 'target\x86_64-pc-windows-msvc\release\main.dll'
$ExampleSettings = Join-Path $RepoRoot 'better-backpack\settings.example.json'
$DistDir = Join-Path $RepoRoot 'dist'

# Inside the zip / inside the game install, the mod folder is named
# this and lives at the path below relative to the game root.
$ModFolderName = 'BetterBackpack'
$RelModParent = 'Augusta\Binaries\WinGRTS\ue4ss\Mods'

function Get-ModVersion {
    $cargoToml = Join-Path $RepoRoot 'Cargo.toml'
    $text = Get-Content $cargoToml -Raw
    if ($text -match '(?m)^\s*version\s*=\s*"([^"]+)"') {
        return $matches[1]
    }
    return '0.0.0'
}

function Find-GroundedRoot {
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
        $candidate = Join-Path $lib 'steamapps\common\Grounded 2'
        if (Test-Path (Join-Path $candidate 'Augusta\Binaries\WinGRTS')) {
            return $candidate
        }
    }
    throw "Grounded 2 install not found in any Steam library. Pass -GamePath explicitly."
}

function Resolve-GameRoot {
    if ($GamePath) {
        if (-not (Test-Path $GamePath)) {
            throw "Provided -GamePath does not exist: $GamePath"
        }
        return (Resolve-Path $GamePath).Path
    }
    return Find-GroundedRoot
}

function Test-UE4SSInstalled {
    param([string]$GameRoot)
    $ue4ssDll = Join-Path $GameRoot 'Augusta\Binaries\WinGRTS\ue4ss\UE4SS.dll'
    return Test-Path $ue4ssDll
}

function Update-ModsTxt {
    param([string]$ModsDir)
    $modsTxt = Join-Path $ModsDir 'mods.txt'
    if (-not (Test-Path $modsTxt)) {
        Write-Host "    mods.txt not found at $modsTxt; skipping registration" -ForegroundColor DarkYellow
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
    Write-Host '==> cargo build --release' -ForegroundColor Cyan
    Push-Location $RepoRoot
    try {
        & cargo build --release
        if ($LASTEXITCODE -ne 0) { throw "cargo build failed (exit $LASTEXITCODE)" }
    } finally {
        Pop-Location
    }
    if (-not (Test-Path $BuiltDll)) {
        throw "main.dll not produced at $BuiltDll"
    }
}

function Write-PackageReadme {
    param([string]$Path)

    $version = Get-ModVersion
    $body = @"
Better Backpack v$version
=========================

Grounded 2 mod loaded by UE4SS. Patches the player's main backpack
capacity, hunger / thirst drain rates, and (planned) other player /
combat / movement tweaks. Configurable at runtime via settings.json
next to the DLL.

Prerequisite
------------
You need UE4SS for Grounded 2 installed first. Get it from Nexus
(https://www.nexusmods.com/grounded2/mods/52). Easiest path: install
via Vortex.

Install (Vortex)
----------------
1. Drop this archive into Vortex's mod list and deploy. Vortex's
   UE4SS extension will:
   - Copy BetterBackpack/ into the game's UE4SS Mods directory.
   - Add 'BetterBackpack : 1' to mods.txt.
2. Launch Grounded 2.

Install (manual)
----------------
1. Extract this archive over the game's root, so the contents land
   at:
       <Grounded 2>\Augusta\Binaries\WinGRTS\ue4ss\Mods\BetterBackpack\
2. Open
       <Grounded 2>\Augusta\Binaries\WinGRTS\ue4ss\Mods\mods.txt
   and add a new line:
       BetterBackpack : 1
3. Launch Grounded 2.

Uninstall
---------
Delete the BetterBackpack folder. Optional: remove its line from
mods.txt.

Defaults (with no settings.json edits)
--------------------------------------
- Player main backpack: 100 slots (vanilla 40), 4x10 viewport with
  mouse-wheel scrolling for the extra rows.
- Mount/saddlebag: untouched (vanilla 30).
- Hunger drain: 50% of vanilla.
- Thirst drain: 50% of vanilla.

Edit BetterBackpack/settings.json to change. See FEATURES.md in the
source repo for full documentation.

Source / issues
---------------
https://github.com/abix-/Grounded2Mods
"@
    Set-Content -Path $Path -Value $body -Encoding utf8
}

function Build-StageTree {
    param([string]$StageRoot)

    # Stage layout matches the path Vortex / manual install expects
    # inside the game folder.
    $modRoot = Join-Path $StageRoot $RelModParent | Join-Path -ChildPath $ModFolderName
    $dllsDir = Join-Path $modRoot 'dlls'
    New-Item -ItemType Directory -Path $dllsDir -Force | Out-Null
    Copy-Item -Path $BuiltDll -Destination (Join-Path $dllsDir 'main.dll') -Force
    Write-Host "    + $ModFolderName/dlls/main.dll"

    Copy-Item -Path $ExampleSettings -Destination (Join-Path $modRoot 'settings.json') -Force
    Write-Host "    + $ModFolderName/settings.json"

    return $modRoot
}

function Invoke-Package {
    Invoke-Build
    if (-not (Test-Path $DistDir)) {
        New-Item -ItemType Directory -Path $DistDir | Out-Null
    }
    $version = Get-ModVersion
    $stageDir = Join-Path $DistDir "stage-$version"
    if (Test-Path $stageDir) {
        Remove-Item -Recurse -Force $stageDir
    }
    New-Item -ItemType Directory -Path $stageDir | Out-Null

    Write-Host "==> staging $ModFolderName at $stageDir" -ForegroundColor Cyan
    $modRoot = Build-StageTree -StageRoot $stageDir
    Write-PackageReadme -Path (Join-Path $modRoot 'README.txt')
    Write-Host "    + $ModFolderName/README.txt"

    $zipPath = Join-Path $DistDir "better-backpack-v$version.zip"
    if (Test-Path $zipPath) {
        Remove-Item -Force $zipPath
    }
    Write-Host "==> writing $zipPath" -ForegroundColor Cyan
    Compress-Archive -Path (Join-Path $stageDir '*') -DestinationPath $zipPath -CompressionLevel Optimal

    Remove-Item -Recurse -Force $stageDir
    $size = (Get-Item $zipPath).Length
    Write-Host ("==> done ({0:N0} bytes)" -f $size) -ForegroundColor Green
    Write-Host "Upload to Nexus: $zipPath"
}

function Invoke-Install {
    Invoke-Build
    $gameRoot = Resolve-GameRoot
    if (-not (Test-UE4SSInstalled $gameRoot)) {
        throw @"
UE4SS is not installed at $gameRoot\Augusta\Binaries\WinGRTS\ue4ss\
Install it first from https://www.nexusmods.com/grounded2/mods/52
(easiest via Vortex), then re-run.
"@
    }

    $modsDir = Join-Path $gameRoot $RelModParent
    $modDir = Join-Path $modsDir $ModFolderName
    Write-Host "==> deploying to $modDir" -ForegroundColor Cyan

    $dllsDir = Join-Path $modDir 'dlls'
    New-Item -ItemType Directory -Path $dllsDir -Force | Out-Null
    Copy-Item -Path $BuiltDll -Destination (Join-Path $dllsDir 'main.dll') -Force
    Write-Host "    copied main.dll"

    $settingsDest = Join-Path $modDir 'settings.json'
    if (Test-Path $settingsDest) {
        Write-Host "    settings.json already present, leaving user edits" -ForegroundColor DarkGray
    } else {
        Copy-Item -Path $ExampleSettings -Destination $settingsDest -Force
        Write-Host "    seeded settings.json"
    }

    Update-ModsTxt -ModsDir $modsDir

    Write-Host "==> done. Launch Grounded 2 to load the mod." -ForegroundColor Green
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

    # Strip the mods.txt entry too. Leaves other mods alone.
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
