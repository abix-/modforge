<#
.SYNOPSIS
Rebuild, redeploy, and restart Abiotic Factor with the current mod.

.DESCRIPTION
The one path for getting the working tree into the live game.
Steps, in order:
  1. Build abioticfactor-mod (Rust release, via k3sc cargo-lock).
  2. Close the game if it is running and wait for it to exit.
  3. Ensure UE4SS is installed (copy from MISERY if missing).
  4. Deploy: copy the built DLL to the UE4SS mod directory,
     removing any stale main-new.dll.
  5. Launch the game through Steam.
  6. Wait until the control plane answers on port 31260.

.PARAMETER SkipBuild
Skip step 1 and deploy whatever is already built.

.PARAMETER BuildOnly
Build and validate the mod in the normal target directory, without deploying or restarting.

.PARAMETER InstallUE4SS
Force reinstall UE4SS even if already present.

.PARAMETER Save
World save folder to host as a LAN game once the main menu is up (step 7).
"latest" (the default) picks the most recently saved world. Pass an empty string to stop at the menu.

.PARAMETER MaxPlayers
Player slots for the hosted LAN game. Default 6.

.EXAMPLE
pwsh -NoProfile -File abioticfactor-mod/scripts/restart.ps1

.EXAMPLE
pwsh -NoProfile -File abioticfactor-mod/scripts/restart.ps1 -SkipBuild -Save september2026
#>
[CmdletBinding()]
param (
    [switch]$SkipBuild,
    [switch]$BuildOnly,
    [switch]$InstallUE4SS,
    [string]$Save = "latest",
    [int]$MaxPlayers = 6
)

$ErrorActionPreference = "Stop"
if ($SkipBuild -and $BuildOnly) { throw "BuildOnly cannot be combined with SkipBuild" }

$Repo = Resolve-Path (Join-Path $PSScriptRoot "..\..")
$GameDir = "C:\Games\Steam\steamapps\common\AbioticFactor"
$BinDir = Join-Path $GameDir "AbioticFactor\Binaries\Win64"
$UE4SSDir = Join-Path $BinDir "ue4ss"
$ModDir = Join-Path $UE4SSDir "Mods\AbioticFactorMod\dlls"
$BuildDll = Join-Path $Repo "target\x86_64-pc-windows-msvc\release\abioticfactor_mod.dll"
$TargetDll = Join-Path $ModDir "main.dll"
$StaleDll = Join-Path $ModDir "main-new.dll"
$AppId = "427410"
$Port = 31260
$ProcessNames = @("AbioticFactor-Win64-Shipping", "AbioticFactor")
$WorldsDir = Join-Path $env:LOCALAPPDATA "AbioticFactor\Saved\SaveGames\76561197960286790\Worlds"

function Invoke-ModOp([string]$Op, [hashtable]$OpArgs, [int]$TimeoutSec = 10) {
    $body = @{ op = $Op; args = $OpArgs } | ConvertTo-Json -Compress -Depth 4
    Invoke-RestMethod -Uri "http://127.0.0.1:$Port/debug" -Method Post -Body $body -ContentType "application/json" -TimeoutSec $TimeoutSec
}

if ($Save -eq "latest") {
    $latest = Get-ChildItem $WorldsDir -Directory | Sort-Object { (Get-Item (Join-Path $_.FullName "WorldSave_MetaData.sav")).LastWriteTime } -Descending | Select-Object -First 1
    if ($null -eq $latest) { throw "no world saves under $WorldsDir" }
    $Save = $latest.Name
}
if ($Save -ne "" -and -not (Test-Path (Join-Path $WorldsDir $Save))) {
    throw "world save '$Save' not found under $WorldsDir"
}

# Reference UE4SS installation to copy from
$RefUE4SS = "C:\Games\Steam\steamapps\common\MISERY\MISERY\Binaries\Win64"

# --- step 1: build ---
if (-not $SkipBuild) {
    Write-Host "[build] abioticfactor-mod (Rust release)" -ForegroundColor Cyan
    Push-Location $Repo
    try {
        k3sc cargo-lock build --release -p abioticfactor-mod --target-dir (Join-Path $Repo "target")
        if ($LASTEXITCODE -ne 0) { throw "cargo build failed (exit $LASTEXITCODE)" }
    }
    finally { Pop-Location }
}

if (-not (Test-Path $BuildDll)) {
    throw "build output not found: $BuildDll"
}
$buildInfo = Get-Item $BuildDll
Write-Host "[build] output: $($buildInfo.Length) bytes, $($buildInfo.LastWriteTime)" -ForegroundColor Gray

# Identity check: prove this DLL belongs to abioticfactor-mod
$marker = "abioticfactor_mod.log"
$bytes = [System.IO.File]::ReadAllBytes($BuildDll)
$ascii = [System.Text.Encoding]::ASCII.GetString($bytes)
if ($ascii -notmatch [regex]::Escape($marker)) {
    throw "[build] IDENTITY FAILED: $BuildDll does not contain '$marker'; this is not the abioticfactor mod"
}
Write-Host "[build] identity ok: contains '$marker'" -ForegroundColor Green

if ($BuildOnly) {
    Write-Host "[done] build validated: $BuildDll" -ForegroundColor Green
    exit 0
}

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

if ($InstallUE4SS -or -not (Test-Path $ue4ssDll)) {
    Write-Host "[ue4ss] installing UE4SS from MISERY reference" -ForegroundColor Cyan

    $refDll = Join-Path $RefUE4SS "ue4ss\UE4SS.dll"
    $refProxy = Join-Path $RefUE4SS "dwmapi.dll"
    $refSettings = Join-Path $RefUE4SS "ue4ss\UE4SS-settings.ini"

    if (-not (Test-Path $refDll)) {
        throw "reference UE4SS not found at $refDll; install UE4SS in MISERY first or provide a path"
    }

    if (-not (Test-Path $UE4SSDir)) {
        New-Item -ItemType Directory -Force -Path $UE4SSDir | Out-Null
    }

    Copy-Item $refDll $ue4ssDll -Force
    Write-Host "[ue4ss] copied UE4SS.dll ($((Get-Item $ue4ssDll).Length) bytes)" -ForegroundColor Gray

    if (Test-Path $refSettings) {
        Copy-Item $refSettings (Join-Path $UE4SSDir "UE4SS-settings.ini") -Force
        Write-Host "[ue4ss] copied UE4SS-settings.ini" -ForegroundColor Gray
    }

    if (-not (Test-Path $proxyDll)) {
        if (Test-Path $refProxy) {
            Copy-Item $refProxy $proxyDll -Force
            Write-Host "[ue4ss] copied dwmapi.dll proxy loader" -ForegroundColor Gray
        }
        else {
            Write-Warning "dwmapi.dll proxy not found in reference; UE4SS may not load"
        }
    }

    # Ensure Mods directory exists
    $modsRoot = Join-Path $UE4SSDir "Mods"
    if (-not (Test-Path $modsRoot)) {
        New-Item -ItemType Directory -Force -Path $modsRoot | Out-Null
    }

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

# Ensure mods.txt enables AbioticFactorMod
$modsTxt = Join-Path $UE4SSDir "Mods\mods.txt"
$modEntry = "AbioticFactorMod : 1"
if (Test-Path $modsTxt) {
    $content = Get-Content $modsTxt -Raw
    if ($content -notmatch "AbioticFactorMod") {
        Add-Content $modsTxt "`n$modEntry"
        Write-Host "[deploy] added AbioticFactorMod to mods.txt" -ForegroundColor Gray
    }
}
else {
    Set-Content $modsTxt $modEntry
    Write-Host "[deploy] created mods.txt with AbioticFactorMod" -ForegroundColor Gray
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
    Write-Warning "control plane not answering after 180s; check UE4SS console"
    exit 1
}

if ($Save -eq "") {
    Write-Host "[done] Abiotic Factor running with mod loaded; no save requested" -ForegroundColor Green
    exit 0
}

# --- step 7: host the save as a LAN game ---
# host.saved_world drives the main menu's own Continue path: it sets the game
# instance's ActiveWorldSaveName and calls HostMultiplayerGame(MaxPlayers, LAN, MapToHost).
Write-Host "[host] waiting for the main menu (up to 120s)" -ForegroundColor Cyan
$deadline = (Get-Date).AddSeconds(120)
$menuReady = $false
while ((Get-Date) -lt $deadline) {
    try {
        $r = Invoke-ModOp "resolve_selector" @{ selector = "first_class:W_MainMenu_ContinueGame_C" }
        if ($r.ok -eq $true) { $menuReady = $true; break }
    }
    catch {}
    Start-Sleep -Seconds 2
}
if (-not $menuReady) {
    Write-Warning "main menu Continue widget not found after 120s; host '$Save' by hand"
    exit 1
}

# Press anything to begin: the master menu widget's own splash handler, then
# the early-access notice. Without this the menu never reaches the login.
$splash = Invoke-ModOp "host.splash" @{}
Write-Host "[host] splash: $($splash | ConvertTo-Json -Compress)" -ForegroundColor Gray

Write-Host "[host] hosting '$Save' as a LAN game for $MaxPlayers players" -ForegroundColor Cyan
# The op refuses until the online login is complete; before that the menu's
# HostMultiplayerGame silently falls back to single player.
$deadline = (Get-Date).AddSeconds(120)
while ($true) {
    $r = Invoke-ModOp "host.saved_world" @{ save = $Save; max_players = $MaxPlayers }
    if ($r.ok -eq $true) { break }
    $reason = "$($r.error)"
    if ($reason -notmatch "login|player controller" -or (Get-Date) -ge $deadline) {
        Write-Warning "host.saved_world failed: $($r | ConvertTo-Json -Compress)"
        exit 1
    }
    Write-Host "[host] waiting: $reason" -ForegroundColor Gray
    Start-Sleep -Seconds 3
}
Write-Host "[host] $($r.result | ConvertTo-Json -Compress)" -ForegroundColor Gray

Write-Host "[wait] world load: player character (up to 180s)" -ForegroundColor Cyan
$deadline = (Get-Date).AddSeconds(180)
while ((Get-Date) -lt $deadline) {
    try {
        $r = Invoke-ModOp "resolve_selector" @{ selector = "first_class:Abiotic_PlayerCharacter_C" }
        if ($r.ok -eq $true) {
            Write-Host "[done] '$Save' hosted on LAN; player character present" -ForegroundColor Green
            exit 0
        }
    }
    catch {}
    Start-Sleep -Seconds 3
}
Write-Warning "no player character after 180s; check the game window"
exit 1
