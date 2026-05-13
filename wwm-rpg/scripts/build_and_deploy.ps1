# wwm-rpg build + deploy. Run from repo root or anywhere.
#
# Builds:
#   1. wwm_rpg.dll (Rust cdylib, release)
#   2. Unityforge.Shim.dll (C# BepInEx plugin, release)
#
# Deploys both into <WWM>/BepInEx/plugins/wwm-rpg/.
#
# Prerequisites:
#   - Cargo + rustc (workspace toolchain via rust-toolchain.toml).
#   - .NET SDK with netstandard2.1 support.
#   - BepInEx 5.x already installed in WWM. If not, see the
#     README for the one-time bootstrap.

[CmdletBinding()]
param(
    [string]$WwmDir = 'C:\Games\Steam\steamapps\common\Wild West Miner Simulator Demo',
    [string]$ShimBepInExDir = '',
    [switch]$NoCopy
)

$ErrorActionPreference = 'Stop'

$repoRoot = Split-Path -Parent (Split-Path -Parent $PSScriptRoot)
Set-Location $repoRoot

$wwmManaged = Join-Path $WwmDir 'Wild West Miner - Gold Rush_Data\Managed'
$wwmBep     = Join-Path $WwmDir 'BepInEx'
$pluginDir  = Join-Path $wwmBep 'plugins\wwm-rpg'

if (-not $ShimBepInExDir) {
    $ShimBepInExDir = $wwmBep
}

if (-not (Test-Path (Join-Path $ShimBepInExDir 'core\BepInEx.dll'))) {
    Write-Host "ShimBepInExDir does not contain core\BepInEx.dll: $ShimBepInExDir" -ForegroundColor Yellow
    Write-Host "Pass -ShimBepInExDir <path> to a BepInEx 5.x install to build the shim." -ForegroundColor Yellow
    exit 1
}

Write-Host "==> Build wwm_rpg.dll (Rust release)" -ForegroundColor Cyan
& cargo build --release -p wwm-rpg
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

Write-Host "==> Build Unityforge.Shim.dll (C# release)" -ForegroundColor Cyan
& dotnet build -c Release `
    -p:BepInExDir="$ShimBepInExDir" `
    -p:UnityDir="$wwmManaged" `
    (Join-Path $repoRoot 'unityforge\cs-shim\Unityforge.Shim.csproj')
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

if ($NoCopy) {
    Write-Host "==> Done (skipped deploy; -NoCopy set)" -ForegroundColor Green
    exit 0
}

if (-not (Test-Path $pluginDir)) {
    New-Item -ItemType Directory -Force -Path $pluginDir | Out-Null
}

$rustDll = Join-Path $repoRoot 'target\x86_64-pc-windows-msvc\release\wwm_rpg.dll'
$shimDll = Join-Path $repoRoot 'unityforge\cs-shim\bin\Release\netstandard2.1\Unityforge.Shim.dll'

Copy-Item -Force $rustDll (Join-Path $pluginDir 'wwm_rpg.unityforge.dll')
Copy-Item -Force $shimDll (Join-Path $pluginDir 'Unityforge.Shim.dll')

Write-Host "==> Deployed:" -ForegroundColor Green
Get-ChildItem $pluginDir | Select-Object Name, Length | Format-Table -AutoSize

Write-Host "Launch the game; BepInEx log lands at:" -ForegroundColor Green
Write-Host "  $wwmBep\LogOutput.log" -ForegroundColor Green
Write-Host "Once running, curl http://localhost:17172/op -d '{`"op`":`"ping`"}'" -ForegroundColor Green
