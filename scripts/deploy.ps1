#requires -Version 7.0
<#
.SYNOPSIS
    Build, package, and optionally install the Better Backpack
    winhttp.dll proxy.

.DESCRIPTION
    Default behavior (-Package): builds the release cdylib and zips it
    up at `dist\better-backpack-<version>.zip` for upload to Nexus and
    install via Vortex. The zip also carries an INSTALL.txt and a
    setup.ps1 that the user (or Vortex's run-after-deploy hook) can
    execute to drop a copy of System32\winhttp.dll into the game
    folder as winhttp_orig.dll, which is required for the proxy's
    forwarders to resolve.

    -Install does a direct local install to the game folder instead of
    building a zip. Useful for iterating on the proxy without going
    through Vortex.

    -Uninstall removes the proxy from the local game install.

.PARAMETER Package
    Build a Vortex-installable zip in `dist\` (default mode).

.PARAMETER Install
    Skip packaging; deploy directly into the local game install.

.PARAMETER Uninstall
    Remove the proxy from the local game install.

.PARAMETER GamePath
    Override game folder auto-detection. Path to
    `<game>\Augusta\Binaries\Win64`. Used by -Install and -Uninstall.

.PARAMETER SkipBuild
    Skip the cargo build step. Use when iterating on this script
    against an already-built DLL.

.PARAMETER PurgeOrig
    With -Uninstall, also remove winhttp_orig.dll. Default leaves it
    so a future reinstall doesn't need the System32 copy step again.

.EXAMPLE
    .\scripts\deploy.ps1
    Build and produce `dist\better-backpack-<version>.zip` ready to
    upload to Nexus.

.EXAMPLE
    .\scripts\deploy.ps1 -Install
    Build and install directly into the local Grounded 2 install.

.EXAMPLE
    .\scripts\deploy.ps1 -Uninstall
    Remove the proxy from the local Grounded 2 install.
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
    [switch]$SkipBuild,
    [switch]$PurgeOrig
)

$ErrorActionPreference = 'Stop'
$RepoRoot = Split-Path -Parent $PSScriptRoot
$BuiltDll = Join-Path $RepoRoot 'target\x86_64-pc-windows-msvc\release\winhttp.dll'
$ExampleSettings = Join-Path $RepoRoot 'better-backpack\settings.example.json'
$DistDir = Join-Path $RepoRoot 'dist'

function Get-ModVersion {
    $cargoToml = Join-Path $RepoRoot 'Cargo.toml'
    $text = Get-Content $cargoToml -Raw
    if ($text -match '(?m)^\s*version\s*=\s*"([^"]+)"') {
        return $matches[1]
    }
    return '0.0.0'
}

function Find-GroundedPath {
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
        $candidate = Join-Path $lib 'steamapps\common\Grounded 2\Augusta\Binaries\Win64'
        if (Test-Path $candidate) { return $candidate }
    }
    throw "Grounded 2 install not found in any Steam library. Pass -GamePath explicitly."
}

function Resolve-GamePath {
    if ($GamePath) {
        if (-not (Test-Path $GamePath)) {
            throw "Provided -GamePath does not exist: $GamePath"
        }
        return (Resolve-Path $GamePath).Path
    }
    return Find-GroundedPath
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
        throw "winhttp.dll not produced at $BuiltDll"
    }
}

function Copy-OrigWinhttp {
    param([string]$Dest)

    $orig = Join-Path $Dest 'winhttp_orig.dll'
    if (Test-Path $orig) {
        Write-Host "    winhttp_orig.dll already in place, skipping" -ForegroundColor DarkGray
        return
    }
    $system = Join-Path $env:WINDIR 'System32\winhttp.dll'
    Write-Host "    copying $system -> $orig"
    Copy-Item -Path $system -Destination $orig -Force
}

function Copy-DefaultSettings {
    param([string]$Dest)

    $settings = Join-Path $Dest 'settings.json'
    if (Test-Path $settings) {
        Write-Host "    settings.json already present, leaving user edits in place" -ForegroundColor DarkGray
        return
    }
    if (-not (Test-Path $ExampleSettings)) {
        Write-Host "    no example settings file at $ExampleSettings, skipping" -ForegroundColor DarkYellow
        return
    }
    Write-Host "    seeding default settings.json from example"
    Copy-Item -Path $ExampleSettings -Destination $settings -Force
}

function Get-StagingContent {
    # Files that go into the zip / direct-install. Returns
    # @{ Source=<abs path>; Name=<filename in zip / dest> } pairs.
    $items = @(
        @{ Source = $BuiltDll;        Name = 'winhttp.dll' },
        @{ Source = $ExampleSettings; Name = 'settings.json' }
    )
    return $items
}

function Write-PackageReadme {
    param([string]$Path)

    $version = Get-ModVersion
    $body = @"
Better Backpack v$version
=========================

Grounded 2 runtime mod. Patches the player's main backpack capacity
and the per-second hunger / thirst drain rates. Configurable at
runtime via settings.json next to the DLL.

Install (Vortex)
----------------
1. Drop this archive into Vortex's mod list and deploy.
2. Run setup.ps1 from the deployed folder ONCE. It copies
   C:\Windows\System32\winhttp.dll alongside as winhttp_orig.dll so
   our proxy's WinHTTP forwarders resolve. (Vortex cannot do this
   step itself because it never touches system files.)
3. Launch Grounded 2 normally.

Install (manual)
----------------
1. Extract this archive into:
       <Grounded 2>\Augusta\Binaries\Win64\
   You should now have winhttp.dll and settings.json in that folder.
2. Right-click setup.ps1 -> Run with PowerShell.
3. Launch Grounded 2 normally.

Uninstall
---------
Delete winhttp.dll from <Grounded 2>\Augusta\Binaries\Win64\.
You can leave winhttp_orig.dll behind; it is harmless.

Defaults (with no settings.json edits)
--------------------------------------
- Player main backpack: 100 slots (vanilla 40), 4x10 viewport with
  mouse-wheel scrolling for the extra rows.
- Mount/saddlebag: untouched (vanilla 30).
- Hunger drain: 50% of vanilla.
- Thirst drain: 50% of vanilla.

Edit settings.json to change. See FEATURES.md in the source repo for
full documentation.

Source / issues
---------------
https://github.com/abix-/Grounded2Mods
"@
    Set-Content -Path $Path -Value $body -Encoding utf8
}

function Write-PackageSetup {
    param([string]$Path)

    $body = @'
# Better Backpack post-install setup. Run once after Vortex deploys
# the mod. Copies C:\Windows\System32\winhttp.dll alongside as
# winhttp_orig.dll so our proxy's WinHTTP forwarders resolve.

$ErrorActionPreference = 'Stop'
$here = $PSScriptRoot
$dest = Join-Path $here 'winhttp_orig.dll'
$src  = Join-Path $env:WINDIR 'System32\winhttp.dll'

if (Test-Path $dest) {
    Write-Host "winhttp_orig.dll already exists at $dest -- nothing to do."
    return
}
if (-not (Test-Path $src)) {
    throw "System winhttp.dll not found at $src. Are you on Windows?"
}
Write-Host "copying $src -> $dest"
Copy-Item -Path $src -Destination $dest -Force
Write-Host "done. Launch Grounded 2 to activate the mod."
'@
    Set-Content -Path $Path -Value $body -Encoding utf8
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

    Write-Host "==> staging files in $stageDir" -ForegroundColor Cyan
    foreach ($item in Get-StagingContent) {
        $dst = Join-Path $stageDir $item.Name
        Copy-Item -Path $item.Source -Destination $dst -Force
        Write-Host "    + $($item.Name)"
    }
    Write-PackageReadme  -Path (Join-Path $stageDir 'README.txt')
    Write-PackageSetup   -Path (Join-Path $stageDir 'setup.ps1')
    Write-Host "    + README.txt"
    Write-Host "    + setup.ps1"

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
    $dest = Resolve-GamePath
    Write-Host "==> deploying to: $dest" -ForegroundColor Cyan

    foreach ($item in Get-StagingContent) {
        $dst = Join-Path $dest $item.Name
        if ($item.Name -eq 'settings.json' -and (Test-Path $dst)) {
            Write-Host "    settings.json already present, leaving user edits" -ForegroundColor DarkGray
            continue
        }
        Write-Host "    copying $($item.Name)"
        Copy-Item -Path $item.Source -Destination $dst -Force
    }
    Copy-OrigWinhttp -Dest $dest

    Write-Host "==> done" -ForegroundColor Green
    Write-Host "Files in $dest :" -ForegroundColor DarkGray
    Get-ChildItem -Path $dest -Filter 'winhttp*.dll' | ForEach-Object { Write-Host "    $($_.Name)" }
    if (Test-Path (Join-Path $dest 'settings.json')) {
        Write-Host "    settings.json"
    }
}

function Invoke-Uninstall {
    $dest = Resolve-GamePath
    Write-Host "==> uninstalling from: $dest" -ForegroundColor Cyan

    $proxy = Join-Path $dest 'winhttp.dll'
    if (Test-Path $proxy) {
        Write-Host "    removing winhttp.dll"
        Remove-Item -Path $proxy -Force
    } else {
        Write-Host "    winhttp.dll not present" -ForegroundColor DarkGray
    }

    if ($PurgeOrig) {
        $orig = Join-Path $dest 'winhttp_orig.dll'
        if (Test-Path $orig) {
            Write-Host "    removing winhttp_orig.dll (-PurgeOrig)"
            Remove-Item -Path $orig -Force
        }
    }
    Write-Host "==> done" -ForegroundColor Green
}

switch ($PSCmdlet.ParameterSetName) {
    'Install'   { Invoke-Install }
    'Uninstall' { Invoke-Uninstall }
    default     { Invoke-Package }
}
