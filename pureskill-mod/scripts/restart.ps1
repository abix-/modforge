<#
.SYNOPSIS
Rebuild, redeploy, and restart Pure Skill (demo) with the current mod.

.DESCRIPTION
The one path for getting the working tree into the live game.
The game is Unity 6000.3.13f1 IL2CPP (metadata v39). MelonLoader
0.7.3 crashes this build while generating interop assemblies (in
"Scanning method cross-references", MelonLoader issue #1159), so
the host is BepInEx 6 bleeding edge, which skips that scan.

Steps, in order:
  1. Build pureskill-mod (Rust, via k3sc cargo-lock).
  2. Ensure BepInEx 6 IL2CPP is installed (downloaded from
     builds.bepinex.dev if missing: BepInEx/, dotnet/, winhttp.dll,
     doorstop_config.ini).
  3. If BepInEx has not yet generated this game's interop
     assemblies (BepInEx\interop), launch the game once with no
     shim, wait for them, and close it. The shim build needs them.
  4. Build the BepInEx IL2CPP shim (dotnet, against the game's refs).
  5. Close the game if it is running and wait for it to exit.
  6. Deploy into BepInEx\plugins\unityforge\: the shim, Newtonsoft
     .Json (BepInEx does not ship it), and a fresh base mod dll;
     delete stale hot-reload generation dlls.
  7. Launch the game through Steam.
  8. Wait until the mod's control plane answers on port 17187.

.PARAMETER SkipBuild
Skip steps 1 and 4 and deploy whatever is already built.

.EXAMPLE
pwsh -NoProfile -File pureskill-mod/scripts/restart.ps1
#>
[CmdletBinding()]
param (
    [switch]$SkipBuild
)

$ErrorActionPreference = "Stop"

$Repo = Resolve-Path (Join-Path $PSScriptRoot "..\..")
$GameDir = "C:\Games\Steam\steamapps\common\Pure Skill Demo"
$BepDir = Join-Path $GameDir "BepInEx"
$PluginDir = Join-Path $BepDir "plugins\unityforge"
$InteropDll = Join-Path $BepDir "interop\Assembly-CSharp.dll"
$ShimDll = Join-Path $Repo "unityforge\cs-shim-il2cpp\bin\Release\net6.0\Unityforge.Shim.Il2Cpp.dll"
$JsonDll = Join-Path $env:USERPROFILE ".nuget\packages\newtonsoft.json\13.0.3\lib\net6.0\Newtonsoft.Json.dll"
$BuildDll = Join-Path $Repo "target\x86_64-pc-windows-msvc\release\pureskill_mod.dll"
$AppId = "5503090"
$Port = 17187
$ProcessName = "PureSkill"

# BepInEx 6 bleeding edge build proven on this game (2026-11-19).
$BepBuild = "793"
$BepZip = "BepInEx-Unity.IL2CPP-win-x64-6.0.0-be.793%2Bdbc82f0.zip"

function Stop-Game {
    $procs = Get-Process $ProcessName -ErrorAction SilentlyContinue
    foreach ($proc in $procs) {
        Write-Host "[stop] closing $ProcessName (pid $($proc.Id))" -ForegroundColor Cyan
        try { $proc.CloseMainWindow() | Out-Null } catch {}
        if (-not $proc.WaitForExit(20000)) {
            Write-Warning "no clean exit after 20s; killing pid $($proc.Id)"
            Stop-Process -Id $proc.Id -Force -Confirm:$false
            $proc.WaitForExit()
        }
    }
    if ($procs) { Start-Sleep -Seconds 2 }  # let file locks drop
}

# --- step 1: build rust ---
if (-not $SkipBuild) {
    Write-Host "[build] pureskill-mod (Rust)" -ForegroundColor Cyan
    Push-Location $Repo
    try {
        k3sc cargo-lock build --release -p pureskill-mod
        if ($LASTEXITCODE -ne 0) { throw "cargo build failed (exit $LASTEXITCODE)" }
    }
    finally { Pop-Location }
}

if (-not (Test-Path $BuildDll)) {
    throw "build output not found: $BuildDll"
}
$buildInfo = Get-Item $BuildDll
Write-Host "[build] output: $($buildInfo.Length) bytes, $($buildInfo.LastWriteTime)" -ForegroundColor Gray

# Identity check: prove this DLL belongs to pureskill-mod
$marker = "pureskill-mod: ready"
$bytes = [System.IO.File]::ReadAllBytes($BuildDll)
$ascii = [System.Text.Encoding]::ASCII.GetString($bytes)
if ($ascii -notmatch [regex]::Escape($marker)) {
    throw "[build] IDENTITY FAILED: $BuildDll does not contain '$marker'; this is not the pureskill mod"
}
Write-Host "[build] identity ok: contains '$marker'" -ForegroundColor Green

# --- step 2: ensure bepinex ---
if (-not (Test-Path (Join-Path $BepDir "core\BepInEx.Unity.IL2CPP.dll"))) {
    Write-Host "[bepinex] installing BepInEx 6 be.$BepBuild" -ForegroundColor Cyan
    Stop-Game
    $tmp = Join-Path ([System.IO.Path]::GetTempPath()) "bepinex-be$BepBuild-$PID"
    New-Item -ItemType Directory -Force -Path $tmp | Out-Null
    $zip = Join-Path $tmp "bepinex.zip"
    Invoke-WebRequest -Uri "https://builds.bepinex.dev/projects/bepinex_be/$BepBuild/$BepZip" -OutFile $zip
    Expand-Archive -Path $zip -DestinationPath (Join-Path $tmp "x") -Force
    foreach ($name in @("BepInEx", "dotnet", "winhttp.dll", "doorstop_config.ini")) {
        Copy-Item (Join-Path $tmp "x\$name") (Join-Path $GameDir $name) -Recurse -Force
    }
    Remove-Item $tmp -Recurse -Force -Confirm:$false
    Write-Host "[bepinex] installed" -ForegroundColor Gray
}
else {
    Write-Host "[bepinex] already installed" -ForegroundColor Gray
}

# --- step 3: first run to generate interop assemblies ---
if (-not (Test-Path $InteropDll)) {
    Write-Host "[bepinex] no interop assemblies yet; launching the game once to generate them" -ForegroundColor Cyan
    Stop-Game
    Start-Process "steam://rungameid/$AppId"
    $log = Join-Path $BepDir "LogOutput.log"
    $deadline = (Get-Date).AddSeconds(600)
    while ((Get-Date) -lt $deadline) {
        if ((Test-Path $log) -and (Select-String -Path $log -Pattern "Chainloader startup complete" -Quiet)) { break }
        Start-Sleep -Seconds 5
    }
    if (-not (Test-Path $InteropDll)) {
        throw "[bepinex] interop assemblies not generated after 600s; read $log"
    }
    Write-Host "[bepinex] interop assemblies generated" -ForegroundColor Green
    Stop-Game
}

# --- step 4: build shim ---
if (-not $SkipBuild) {
    Write-Host "[build] BepInEx IL2CPP shim (C#)" -ForegroundColor Cyan
    Push-Location (Join-Path $Repo "unityforge\cs-shim-il2cpp")
    try {
        dotnet build -c Release -p:BepInExDir="$BepDir"
        if ($LASTEXITCODE -ne 0) { throw "shim build failed (exit $LASTEXITCODE)" }
    }
    finally { Pop-Location }
}
if (-not (Test-Path $ShimDll)) {
    throw "shim output not found: $ShimDll"
}
if (-not (Test-Path $JsonDll)) {
    throw "Newtonsoft.Json not found: $JsonDll (restore the shim once with dotnet build)"
}

# --- step 5: stop game ---
Stop-Game

# --- step 6: deploy ---
Write-Host "[deploy] shim + Newtonsoft.Json + mod into $PluginDir" -ForegroundColor Cyan
New-Item -ItemType Directory -Force -Path $PluginDir | Out-Null
Copy-Item $ShimDll (Join-Path $PluginDir "Unityforge.Shim.Il2Cpp.dll") -Force
Copy-Item $JsonDll (Join-Path $PluginDir "Newtonsoft.Json.dll") -Force
$TargetDll = Join-Path $PluginDir "pureskill_mod.unityforge.dll"
Copy-Item $BuildDll $TargetDll -Force
Get-ChildItem $PluginDir -Filter "pureskill_mod.unityforge.gen*.dll" | Remove-Item -Force -Confirm:$false
$deployed = Get-Item $TargetDll
if ($deployed.Length -ne $buildInfo.Length) {
    throw "[deploy] VALIDATION FAILED: size mismatch (build=$($buildInfo.Length), deployed=$($deployed.Length))"
}
Write-Host "[deploy] validated: $($deployed.Length) bytes, $($deployed.LastWriteTime)" -ForegroundColor Green

# --- step 7: launch ---
Write-Host "[launch] steam://rungameid/$AppId" -ForegroundColor Cyan
Start-Process "steam://rungameid/$AppId"

# --- step 8: wait for control plane ---
Write-Host "[wait] control plane on port $Port (up to 180s)" -ForegroundColor Cyan
$deadline = (Get-Date).AddSeconds(180)
$cpReady = $false
while ((Get-Date) -lt $deadline) {
    try {
        $null = Invoke-RestMethod -Uri "http://127.0.0.1:$Port/op" -Method Post `
            -Body '{"op":"ping","args":{}}' -ContentType "application/json" -TimeoutSec 2
        Write-Host "[ready] control plane answering on port $Port" -ForegroundColor Green
        $cpReady = $true
        break
    }
    catch {
        if (-not (Get-Process $ProcessName -ErrorAction SilentlyContinue)) {
            Write-Warning "game exited before the control plane answered; read $BepDir\LogOutput.log"
            exit 1
        }
        Start-Sleep -Seconds 3
    }
}
if (-not $cpReady) {
    Write-Warning "control plane not answering after 180s; read $BepDir\LogOutput.log"
    exit 1
}

Write-Host "[done] Pure Skill running with mod loaded" -ForegroundColor Green
exit 0
