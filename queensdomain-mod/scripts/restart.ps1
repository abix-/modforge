<#
.SYNOPSIS
Rebuild, redeploy, and restart Queens' Domain with the current mod.

.DESCRIPTION
The one path for getting the working tree into the live game.
Steps, in order:
  1. Build queensdomain-mod (Rust release, via k3sc cargo-lock).
  2. Close the game if it is running and wait for it to exit.
  3. Ensure UE4SS is installed (copy from Alchemy Factory if missing).
     The settings are made minimal: every [Hooks] entry 0 except
     HookEngineTick.
  4. Deploy: copy the built DLL to the UE4SS mod directory,
     removing any stale main-new.dll.
  5. Launch the game through Steam.
  6. Wait until the control plane answers on port 31310.

.PARAMETER SkipBuild
Skip step 1 and deploy whatever is already built.

.PARAMETER InstallUE4SS
Force reinstall UE4SS even if already present.

.EXAMPLE
pwsh -NoProfile -File queensdomain-mod/scripts/restart.ps1

.EXAMPLE
pwsh -NoProfile -File queensdomain-mod/scripts/restart.ps1 -SkipBuild
#>
[CmdletBinding()]
param (
    [switch]$SkipBuild,
    [switch]$InstallUE4SS
)

$ErrorActionPreference = "Stop"

$Repo = Resolve-Path (Join-Path $PSScriptRoot "..\..")
$GameDir = "C:\Games\Steam\steamapps\common\QueensDomain"
$BinDir = Join-Path $GameDir "QueensDomain\Binaries\Win64"
$UE4SSDir = Join-Path $BinDir "ue4ss"
$ModDir = Join-Path $UE4SSDir "Mods\QueensDomainMod\dlls"
$BuildDll = Join-Path $Repo "target\x86_64-pc-windows-msvc\release\queensdomain_mod.dll"
$TargetDll = Join-Path $ModDir "main.dll"
$StaleDll = Join-Path $ModDir "main-new.dll"
$AppId = "1799840"
$Port = 31310
$ProcessNames = @("QueensDomain-Win64-Shipping", "QueensDomain")

# Reference UE4SS installation to copy from. Alchemy Factory carries
# UE4SS experimental-latest (UE4SS_v3.0.1-1133-gb4cefa18), recorded
# in docs/alchemyfactory.md. UE4SS supports UE 4.12 to 5.7.
$RefUE4SS = "C:\Games\Steam\steamapps\common\Alchemy Factory\AlchemyFactory\Binaries\Win64"

# --- step 1: build ---
if (-not $SkipBuild) {
    Write-Host "[build] queensdomain-mod (Rust release)" -ForegroundColor Cyan
    Push-Location $Repo
    try {
        k3sc cargo-lock build --release -p queensdomain-mod
        if ($LASTEXITCODE -ne 0) { throw "cargo build failed (exit $LASTEXITCODE)" }
    }
    finally { Pop-Location }
}

if (-not (Test-Path $BuildDll)) {
    throw "build output not found: $BuildDll"
}
$buildInfo = Get-Item $BuildDll
Write-Host "[build] output: $($buildInfo.Length) bytes, $($buildInfo.LastWriteTime)" -ForegroundColor Gray

# Identity check: prove this DLL belongs to queensdomain-mod
$marker = "queensdomain_mod.log"
$bytes = [System.IO.File]::ReadAllBytes($BuildDll)
$ascii = [System.Text.Encoding]::ASCII.GetString($bytes)
if ($ascii -notmatch [regex]::Escape($marker)) {
    throw "[build] IDENTITY FAILED: $BuildDll does not contain '$marker'; this is not the queens domain mod"
}
Write-Host "[build] identity ok: contains '$marker'" -ForegroundColor Green

# --- step 2: stop game ---
foreach ($pname in $ProcessNames) {
    $procs = Get-Process $pname -ErrorAction SilentlyContinue
    foreach ($proc in $procs) {
        Write-Host "[stop] closing $pname (pid $($proc.Id))" -ForegroundColor Cyan
        try { $proc.CloseMainWindow() | Out-Null } catch {}
        if (-not $proc.WaitForExit(15000)) {
            Write-Warning "no clean exit after 15s; killing pid $($proc.Id)"
            Stop-Process -Id $proc.Id -Force -Confirm:$false
            $proc.WaitForExit()
        }
    }
}
Start-Sleep -Seconds 2

# --- step 3: ensure UE4SS ---
$ue4ssDll = Join-Path $UE4SSDir "UE4SS.dll"
$proxyDll = Join-Path $BinDir "dwmapi.dll"
$settings = Join-Path $UE4SSDir "UE4SS-settings.ini"

if ($InstallUE4SS -or -not (Test-Path $ue4ssDll)) {
    Write-Host "[ue4ss] installing UE4SS from Alchemy Factory reference" -ForegroundColor Cyan

    $refDll = Join-Path $RefUE4SS "ue4ss\UE4SS.dll"
    $refProxy = Join-Path $RefUE4SS "dwmapi.dll"
    $refSettings = Join-Path $RefUE4SS "ue4ss\UE4SS-settings.ini"

    foreach ($ref in @($refDll, $refProxy, $refSettings)) {
        if (-not (Test-Path $ref)) {
            throw "reference UE4SS file not found: $ref"
        }
    }

    New-Item -ItemType Directory -Force -Path (Join-Path $UE4SSDir "Mods") | Out-Null
    Copy-Item $refDll $ue4ssDll -Force
    Copy-Item $refProxy $proxyDll -Force
    Write-Host "[ue4ss] copied UE4SS.dll and dwmapi.dll" -ForegroundColor Gray

    # Minimal settings: every hook off except EngineTick. Alchemy
    # Factory's file also has HookUObjectProcessEvent on.
    $ini = [string](Get-Content $refSettings -Raw)
    $ini = $ini -replace '(?m)^(Hook\w+\s*=\s*)1', '${1}0'
    $ini = $ini -replace '(?m)^(HookEngineTick\s*=\s*)0', '${1}1'
    $ini = $ini -replace '(?m)^(GuiConsoleEnabled\s*=\s*)1', '${1}0'
    Set-Content $settings $ini -NoNewline
    Write-Host "[ue4ss] wrote minimal UE4SS-settings.ini" -ForegroundColor Gray
    Write-Host "[ue4ss] installed" -ForegroundColor Green
}
else {
    Write-Host "[ue4ss] already installed" -ForegroundColor Gray
}

# --- step 4: deploy mod ---
Write-Host "[deploy] copying to $TargetDll" -ForegroundColor Cyan

if (-not (Test-Path $ModDir)) {
    New-Item -ItemType Directory -Force -Path $ModDir | Out-Null
}

if (Test-Path $StaleDll) {
    Remove-Item $StaleDll -Force -Confirm:$false
    Write-Host "[deploy] removed stale main-new.dll" -ForegroundColor Gray
}

Copy-Item $BuildDll $TargetDll -Force

$deployed = Get-Item $TargetDll
if ($deployed.Length -ne $buildInfo.Length) {
    throw "[deploy] VALIDATION FAILED: size mismatch (build=$($buildInfo.Length), deployed=$($deployed.Length))"
}
Write-Host "[deploy] validated: $($deployed.Length) bytes, $($deployed.LastWriteTime)" -ForegroundColor Green

# Ensure mods.txt enables QueensDomainMod
$modsTxt = Join-Path $UE4SSDir "Mods\mods.txt"
$modEntry = "QueensDomainMod : 1"
if (Test-Path $modsTxt) {
    # [string] so an empty file reads as "" (Get-Content -Raw returns
    # nothing for a 0-byte file, and -notmatch on nothing is false).
    $content = [string](Get-Content $modsTxt -Raw)
    if ($content -notmatch "QueensDomainMod") {
        Add-Content $modsTxt "`n$modEntry"
        Write-Host "[deploy] added QueensDomainMod to mods.txt" -ForegroundColor Gray
    }
}
else {
    Set-Content $modsTxt $modEntry
    Write-Host "[deploy] created mods.txt with QueensDomainMod" -ForegroundColor Gray
}

# --- step 5: launch ---
Write-Host "[launch] steam://rungameid/$AppId" -ForegroundColor Cyan
Start-Process "steam://rungameid/$AppId"

# --- step 6: wait for control plane ---
Write-Host "[wait] control plane on port $Port (up to 180s)" -ForegroundColor Cyan
$deadline = (Get-Date).AddSeconds(180)
$cpReady = $false
while ((Get-Date) -lt $deadline) {
    try {
        $r = Invoke-RestMethod -Uri "http://127.0.0.1:$Port/debug" -Method Post `
            -Body '{"op":"list_ops","args":{}}' -ContentType "application/json" -TimeoutSec 2
        if ($r.ok -eq $true) {
            Write-Host "[ready] control plane answering on port $Port" -ForegroundColor Green
            $cpReady = $true
            break
        }
    }
    catch {
        Start-Sleep -Seconds 3
    }
}
if (-not $cpReady) {
    Write-Warning "control plane not answering after 180s; check UE4SS.log"
    exit 1
}

Write-Host "[done] Queens' Domain running with mod loaded" -ForegroundColor Green
exit 0
