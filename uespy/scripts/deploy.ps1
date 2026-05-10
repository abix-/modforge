#requires -Version 7.0
<#
.SYNOPSIS
    Build, package, and install any uespy-based UE4SS Rust mod
    in this workspace. Single framework-level deploy script —
    each mod opts in via `[package.metadata.uespy]` in its
    `Cargo.toml`.

.DESCRIPTION
    Game-specific config (mod folder name, game install regex,
    UE4SS subpath, etc.) lives in the mod's own `Cargo.toml`.
    This script reads it via `cargo metadata` and dispatches.

    Per-mod Cargo.toml block, all keys mandatory unless noted:

        [package.metadata.uespy]
        mod_folder_name = "Tweaks"             # subfolder under <ue4ss>/Mods/
        game_name_regex = "Outworld"           # Steam dir name match (regex)
        game_sub_path   = "OutworldStation/Binaries/Win64"
                                               # path under <game>/ where ue4ss/ lives
        zip_prefix      = "ows-tweaks"         # dist zip name: <prefix>-v<version>.zip
        target_dir      = "target/tweaks"      # optional; default: target/<package>
        example_settings = "<path/to/settings.example.json>"  # optional; seeds settings.json on first install

.PARAMETER Package
    Cargo workspace member to deploy. Required. Reads
    `<member>/Cargo.toml`'s `[package.metadata.uespy]` for
    game-specific config.

.PARAMETER Install
    Build + copy the cdylib into the local game install.

.PARAMETER Uninstall
    Remove the mod folder + its `mods.txt` entry.

.PARAMETER Package
    (Default mode if no -Install / -Uninstall) Build a
    dist zip of the mod folder for upload / manual install.

.PARAMETER GamePath
    Override game-install autodetection. Path to game's root
    (the dir containing `<game_sub_path>` from metadata).

.PARAMETER SkipBuild
    Skip cargo build. Use when iterating against an
    already-built DLL.

.EXAMPLE
    pwsh uespy/scripts/deploy.ps1 -Install -Package tweaks
    Build tweaks and install into the local Outworld Station.

.EXAMPLE
    pwsh uespy/scripts/deploy.ps1 -Install -Package better-backpack
    Same flow, different mod and different game.
#>

[CmdletBinding(DefaultParameterSetName = 'PackageMode')]
param(
    [Parameter(Mandatory)]
    [string]$Package,

    [Parameter(ParameterSetName = 'Install')]
    [switch]$Install,

    [Parameter(ParameterSetName = 'Uninstall')]
    [switch]$Uninstall,

    [string]$GamePath,
    [switch]$SkipBuild
)

$ErrorActionPreference = 'Stop'
$WorkspaceRoot = Split-Path -Parent (Split-Path -Parent $PSScriptRoot)

# --------------------------------------------------------------------------
# Resolve mod config from cargo metadata.
# --------------------------------------------------------------------------

function Get-ModConfig {
    param([string]$PackageName)

    Push-Location $WorkspaceRoot
    try {
        $metaJson = & cargo metadata --no-deps --format-version 1 2>$null
        if ($LASTEXITCODE -ne 0) { throw "cargo metadata failed (exit $LASTEXITCODE)" }
    } finally {
        Pop-Location
    }
    $meta = $metaJson | ConvertFrom-Json -Depth 32
    $pkg = $meta.packages | Where-Object { $_.name -eq $PackageName }
    if (-not $pkg) {
        throw "Package '$PackageName' not found in workspace at $WorkspaceRoot"
    }
    $u = $pkg.metadata.uespy
    if (-not $u) {
        throw @"
Package '$PackageName' is missing its [package.metadata.uespy] block.
Add to its Cargo.toml:

    [package.metadata.uespy]
    mod_folder_name = "<Name>"
    game_name_regex = "<regex>"
    game_sub_path   = "<path>"
    zip_prefix      = "<prefix>"
"@
    }
    foreach ($key in 'mod_folder_name', 'game_name_regex', 'game_sub_path', 'zip_prefix') {
        if (-not $u.$key) {
            throw "[package.metadata.uespy].$key is required (Package '$PackageName')"
        }
    }

    # Default per-package target dir keeps each mod's main.dll
    # isolated so two mods sharing [lib] name = "main" don't
    # overwrite each other. Override via metadata.target_dir.
    $targetDir = if ($u.target_dir) {
        Join-Path $WorkspaceRoot $u.target_dir
    } else {
        Join-Path $WorkspaceRoot "target/$PackageName"
    }
    $builtDll = Join-Path $targetDir 'x86_64-pc-windows-msvc/release/main.dll'

    $exampleSettings = if ($u.example_settings) {
        Join-Path $WorkspaceRoot $u.example_settings
    } else {
        $null
    }

    [PSCustomObject]@{
        PackageName     = $PackageName
        Version         = $pkg.version
        ManifestDir     = (Split-Path -Parent $pkg.manifest_path)
        TargetDir       = $targetDir
        BuiltDll        = $builtDll
        DistDir         = Join-Path $WorkspaceRoot 'dist'
        ModFolderName   = $u.mod_folder_name
        GameNameRegex   = $u.game_name_regex
        GameSubPath     = ($u.game_sub_path -replace '/', '\')
        ZipPrefix       = $u.zip_prefix
        ExampleSettings = $exampleSettings
    }
}

# --------------------------------------------------------------------------
# Steam install / game-install lookup.
# --------------------------------------------------------------------------

function Find-SteamRoot {
    foreach ($key in @(
        'HKLM:\SOFTWARE\WOW6432Node\Valve\Steam',
        'HKLM:\SOFTWARE\Valve\Steam',
        'HKCU:\Software\Valve\Steam'
    )) {
        $val = Get-ItemProperty -Path $key -Name InstallPath -ErrorAction SilentlyContinue
        if ($val) { return $val.InstallPath }
    }
    throw "Steam install not found in registry. Pass -GamePath explicitly."
}

function Find-GameRoot {
    param($Cfg)

    $steamRoot = Find-SteamRoot
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
            if ($dir.Name -notmatch $Cfg.GameNameRegex) { continue }
            if (Test-Path (Join-Path $dir.FullName $Cfg.GameSubPath)) {
                return $dir.FullName
            }
        }
    }
    throw "Game install matching '$($Cfg.GameNameRegex)' with subpath '$($Cfg.GameSubPath)' not found in any Steam library. Pass -GamePath explicitly."
}

function Resolve-GameRoot {
    param($Cfg)
    if ($GamePath) {
        if (-not (Test-Path $GamePath)) {
            throw "Provided -GamePath does not exist: $GamePath"
        }
        return (Resolve-Path $GamePath).Path
    }
    return Find-GameRoot $Cfg
}

function Test-UE4SSInstalled {
    param($Cfg, [string]$GameRoot)
    $ue4ssDll = Join-Path $GameRoot (Join-Path $Cfg.GameSubPath 'ue4ss\UE4SS.dll')
    return Test-Path $ue4ssDll
}

# --------------------------------------------------------------------------
# Build, mods.txt, copy.
# --------------------------------------------------------------------------

function Invoke-Build {
    param($Cfg)
    if ($SkipBuild) { return }
    Write-Host "==> cargo build -p $($Cfg.PackageName) --release --target-dir $($Cfg.TargetDir)" -ForegroundColor Cyan
    Push-Location $WorkspaceRoot
    try {
        & cargo build -p $Cfg.PackageName --release --target-dir $Cfg.TargetDir
        if ($LASTEXITCODE -ne 0) { throw "cargo build failed (exit $LASTEXITCODE)" }
    } finally {
        Pop-Location
    }
    if (-not (Test-Path $Cfg.BuiltDll)) {
        throw "main.dll not produced at $($Cfg.BuiltDll)"
    }
}

function Update-ModsTxt {
    param($Cfg, [string]$ModsDir)
    $modsTxt = Join-Path $ModsDir 'mods.txt'
    $entry = "$($Cfg.ModFolderName) : 1"
    if (-not (Test-Path $modsTxt)) {
        Write-Host "    creating $modsTxt with entry '$entry'" -ForegroundColor DarkYellow
        Set-Content -Path $modsTxt -Value $entry
        return
    }
    $content = Get-Content $modsTxt
    if ($content -match "^\s*$($Cfg.ModFolderName)\s*:") {
        Write-Host "    mods.txt already registers $($Cfg.ModFolderName)" -ForegroundColor DarkGray
        return
    }
    Write-Host "    appending '$entry' to mods.txt"
    Add-Content -Path $modsTxt -Value $entry
}

function Build-StageTree {
    param($Cfg, [string]$StageRoot)

    $modsRel = Join-Path $Cfg.GameSubPath 'ue4ss\Mods'
    $modRoot = Join-Path $StageRoot $modsRel | Join-Path -ChildPath $Cfg.ModFolderName
    $dllsDir = Join-Path $modRoot 'dlls'
    New-Item -ItemType Directory -Path $dllsDir -Force | Out-Null

    Copy-Item -Path $Cfg.BuiltDll -Destination (Join-Path $dllsDir 'main.dll') -Force
    Write-Host "    + $($Cfg.ModFolderName)/dlls/main.dll"

    if ($Cfg.ExampleSettings -and (Test-Path $Cfg.ExampleSettings)) {
        Copy-Item -Path $Cfg.ExampleSettings -Destination (Join-Path $dllsDir 'settings.json') -Force
        Write-Host "    + $($Cfg.ModFolderName)/dlls/settings.json"
    }
    return $modRoot
}

# --------------------------------------------------------------------------
# Mode entry points.
# --------------------------------------------------------------------------

function Invoke-PackageMode {
    param($Cfg)
    Invoke-Build $Cfg
    if (-not (Test-Path $Cfg.DistDir)) {
        New-Item -ItemType Directory -Path $Cfg.DistDir | Out-Null
    }
    $stageDir = Join-Path $Cfg.DistDir "stage-$($Cfg.PackageName)-$($Cfg.Version)"
    if (Test-Path $stageDir) { Remove-Item -Recurse -Force $stageDir }
    New-Item -ItemType Directory -Path $stageDir | Out-Null

    Write-Host "==> staging $($Cfg.ModFolderName) at $stageDir" -ForegroundColor Cyan
    Build-StageTree -Cfg $Cfg -StageRoot $stageDir | Out-Null

    $zipPath = Join-Path $Cfg.DistDir "$($Cfg.ZipPrefix)-v$($Cfg.Version).zip"
    if (Test-Path $zipPath) { Remove-Item -Force $zipPath }
    Write-Host "==> writing $zipPath" -ForegroundColor Cyan
    Compress-Archive -Path (Join-Path $stageDir '*') -DestinationPath $zipPath -CompressionLevel Optimal
    Remove-Item -Recurse -Force $stageDir
    Write-Host ("==> done ({0:N0} bytes)" -f (Get-Item $zipPath).Length) -ForegroundColor Green
    Write-Host "Upload / manual install: $zipPath"
}

function Invoke-InstallMode {
    param($Cfg)
    Invoke-Build $Cfg
    $gameRoot = Resolve-GameRoot $Cfg
    if (-not (Test-UE4SSInstalled $Cfg $gameRoot)) {
        throw @"
UE4SS is not installed at $gameRoot\$($Cfg.GameSubPath)\ue4ss\
Install it first (drop UE4SS files into $($Cfg.GameSubPath)),
then re-run.
"@
    }

    $modsDir = Join-Path $gameRoot (Join-Path $Cfg.GameSubPath 'ue4ss\Mods')
    $modDir = Join-Path $modsDir $Cfg.ModFolderName
    Write-Host "==> deploying to $modDir" -ForegroundColor Cyan

    $dllsDir = Join-Path $modDir 'dlls'
    New-Item -ItemType Directory -Path $dllsDir -Force | Out-Null
    try {
        Copy-Item -Path $Cfg.BuiltDll -Destination (Join-Path $dllsDir 'main.dll') -Force
        Write-Host "    copied main.dll"
    } catch [System.IO.IOException] {
        throw "Failed to copy main.dll. The game is probably running and holding the DLL — quit it, then re-run."
    }

    if ($Cfg.ExampleSettings -and (Test-Path $Cfg.ExampleSettings)) {
        $settingsDest = Join-Path $dllsDir 'settings.json'
        if (Test-Path $settingsDest) {
            Write-Host "    settings.json already present, leaving user edits" -ForegroundColor DarkGray
        } else {
            Copy-Item -Path $Cfg.ExampleSettings -Destination $settingsDest -Force
            Write-Host "    seeded settings.json from example"
        }
    }

    Update-ModsTxt -Cfg $Cfg -ModsDir $modsDir
    Write-Host "==> done. Launch the game to load the mod." -ForegroundColor Green
}

function Invoke-UninstallMode {
    param($Cfg)
    $gameRoot = Resolve-GameRoot $Cfg
    $modsDir = Join-Path $gameRoot (Join-Path $Cfg.GameSubPath 'ue4ss\Mods')
    $modDir = Join-Path $modsDir $Cfg.ModFolderName
    if (-not (Test-Path $modDir)) {
        Write-Host "==> no $($Cfg.ModFolderName) at $modDir; nothing to remove" -ForegroundColor DarkGray
        return
    }
    Write-Host "==> removing $modDir" -ForegroundColor Cyan
    Remove-Item -Recurse -Force $modDir

    $modsTxt = Join-Path $modsDir 'mods.txt'
    if (Test-Path $modsTxt) {
        $lines = Get-Content $modsTxt
        $filtered = $lines | Where-Object { $_ -notmatch "^\s*$($Cfg.ModFolderName)\s*:" }
        if ($filtered.Count -ne $lines.Count) {
            Write-Host "    removing $($Cfg.ModFolderName) from mods.txt"
            Set-Content -Path $modsTxt -Value $filtered
        }
    }
    Write-Host "==> done" -ForegroundColor Green
}

# --------------------------------------------------------------------------

$cfg = Get-ModConfig $Package
switch ($PSCmdlet.ParameterSetName) {
    'Install'   { Invoke-InstallMode $cfg }
    'Uninstall' { Invoke-UninstallMode $cfg }
    default     { Invoke-PackageMode $cfg }
}
