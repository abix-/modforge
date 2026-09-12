<#
.SYNOPSIS
Rebuild, redeploy, and restart Wanderburg with the current mod.

.DESCRIPTION
The one path for getting the working tree into the live game.
Steps, in order:
  1. Build wanderburg-mod (Rust, via k3sc cargo-lock).
  2. Ensure MelonLoader is installed (copied from the Schedule 1
     install if missing: version.dll plus the MelonLoader folder,
     minus the per-game generated parts).
  3. If MelonLoader has not yet generated this game's interop
     assemblies (MelonLoader\Il2CppAssemblies), launch the game
     once with no shim, wait for them, and close it. The shim
     build needs those references.
  4. Build the MelonLoader shim (dotnet, against the game's refs,
     with the Schedule 1 file left out).
  5. Close the game if it is running and wait for it to exit.
  6. Deploy: shim dll + fresh base mod dll into Mods/, and delete
     stale hot-reload generation dlls (a restart resets to gen 0).
  7. Launch the game through Steam.
  8. Wait until the mod's control plane answers on port 17177.

.PARAMETER SkipBuild
Skip steps 1 and 4 and deploy whatever is already built.

.PARAMETER InstallMelonLoader
Force reinstall MelonLoader even if already present.

.EXAMPLE
pwsh -NoProfile -File wanderburg-mod/scripts/restart.ps1

.EXAMPLE
pwsh -NoProfile -File wanderburg-mod/scripts/restart.ps1 -SkipBuild
#>
[CmdletBinding()]
param (
    [switch]$SkipBuild,
    [switch]$InstallMelonLoader
)

$ErrorActionPreference = "Stop"

$Repo = Resolve-Path (Join-Path $PSScriptRoot "..\..")
$GameDir = "C:\Games\Steam\steamapps\common\Wanderburg Game"
$Mods = Join-Path $GameDir "Mods"
$MelonDir = Join-Path $GameDir "MelonLoader"
$InteropDll = Join-Path $MelonDir "Il2CppAssemblies\Assembly-CSharp.dll"
$ShimDll = Join-Path $Repo "unityforge\cs-shim-melonloader\bin\Release\net6.0\Unityforge.Shim.Melon.dll"
$BuildDll = Join-Path $Repo "target\x86_64-pc-windows-msvc\release\wanderburg_mod.dll"
$AppId = "3624140"
$Port = 17177
$ProcessName = "Wanderburg"

# Reference MelonLoader installation to copy from (0.7.3 in the
# Schedule 1 install). Il2CppAssemblies, Logs and Latest.log are
# generated per game and are NOT copied.
$RefGame = "C:\Games\Steam\steamapps\common\Schedule I"

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
    Write-Host "[build] wanderburg-mod (Rust)" -ForegroundColor Cyan
    Push-Location $Repo
    try {
        k3sc cargo-lock build --release -p wanderburg-mod
        if ($LASTEXITCODE -ne 0) { throw "cargo build failed (exit $LASTEXITCODE)" }
    }
    finally { Pop-Location }
}

if (-not (Test-Path $BuildDll)) {
    throw "build output not found: $BuildDll"
}
$buildInfo = Get-Item $BuildDll
Write-Host "[build] output: $($buildInfo.Length) bytes, $($buildInfo.LastWriteTime)" -ForegroundColor Gray

# Identity check: prove this DLL belongs to wanderburg-mod
$marker = "wanderburg-mod: ready"
$bytes = [System.IO.File]::ReadAllBytes($BuildDll)
$ascii = [System.Text.Encoding]::ASCII.GetString($bytes)
if ($ascii -notmatch [regex]::Escape($marker)) {
    throw "[build] IDENTITY FAILED: $BuildDll does not contain '$marker'; this is not the wanderburg mod"
}
Write-Host "[build] identity ok: contains '$marker'" -ForegroundColor Green

# --- step 2: ensure melonloader ---
$melonDll = Join-Path $MelonDir "net6\MelonLoader.dll"
if ($InstallMelonLoader -or -not (Test-Path $melonDll)) {
    Write-Host "[melon] installing MelonLoader from Schedule 1 reference" -ForegroundColor Cyan
    $refMelon = Join-Path $RefGame "MelonLoader"
    $refProxy = Join-Path $RefGame "version.dll"
    if (-not (Test-Path (Join-Path $refMelon "net6\MelonLoader.dll"))) {
        throw "reference MelonLoader not found at $refMelon"
    }
    Stop-Game
    New-Item -ItemType Directory -Force -Path $MelonDir | Out-Null
    foreach ($entry in Get-ChildItem $refMelon -Force) {
        if ($entry.Name -in @("Il2CppAssemblies", "Logs", "Latest.log", "__folder_managed_by_vortex")) { continue }
        Copy-Item $entry.FullName (Join-Path $MelonDir $entry.Name) -Recurse -Force
    }
    Copy-Item $refProxy (Join-Path $GameDir "version.dll") -Force
    Write-Host "[melon] copied MelonLoader folder and version.dll proxy" -ForegroundColor Gray
}
else {
    Write-Host "[melon] already installed" -ForegroundColor Gray
}
New-Item -ItemType Directory -Force -Path $Mods | Out-Null

# --- step 3: first run to generate interop assemblies ---
if (-not (Test-Path $InteropDll)) {
    Write-Host "[melon] no Il2CppAssemblies yet; launching the game once to generate them" -ForegroundColor Cyan
    Stop-Game
    Start-Process "steam://rungameid/$AppId"
    $deadline = (Get-Date).AddSeconds(600)
    while ((Get-Date) -lt $deadline -and -not (Test-Path $InteropDll)) {
        Start-Sleep -Seconds 5
    }
    if (-not (Test-Path $InteropDll)) {
        throw "[melon] Il2CppAssemblies not generated after 600s; read $MelonDir\Latest.log"
    }
    Write-Host "[melon] interop assemblies generated" -ForegroundColor Green
    Start-Sleep -Seconds 10  # let the generator finish writing the rest
    Stop-Game
}

# --- step 4: build shim ---
if (-not $SkipBuild) {
    Write-Host "[build] MelonLoader shim (C#, NoSchedule1)" -ForegroundColor Cyan
    Push-Location (Join-Path $Repo "unityforge\cs-shim-melonloader")
    try {
        dotnet build -c Release -p:MelonLoaderDir="$MelonDir" -p:NoSchedule1=true
        if ($LASTEXITCODE -ne 0) { throw "shim build failed (exit $LASTEXITCODE)" }
    }
    finally { Pop-Location }
}
if (-not (Test-Path $ShimDll)) {
    throw "shim output not found: $ShimDll"
}

# --- step 5: stop game ---
Stop-Game

# --- step 6: deploy ---
Write-Host "[deploy] shim + mod into Mods/" -ForegroundColor Cyan
Copy-Item $ShimDll (Join-Path $Mods "Unityforge.Shim.Melon.dll") -Force
$TargetDll = Join-Path $Mods "wanderburg_mod.unityforge.dll"
Copy-Item $BuildDll $TargetDll -Force
Get-ChildItem $Mods -Filter "wanderburg_mod.unityforge.gen*.dll" | Remove-Item -Force -Confirm:$false
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
        $r = Invoke-RestMethod -Uri "http://127.0.0.1:$Port/op" -Method Post `
            -Body '{"op":"ping","args":{}}' -ContentType "application/json" -TimeoutSec 2
        Write-Host "[ready] control plane answering on port $Port" -ForegroundColor Green
        $cpReady = $true
        break
    }
    catch {
        Start-Sleep -Seconds 3
    }
}
if (-not $cpReady) {
    Write-Warning "control plane not answering after 180s; read $MelonDir\Latest.log"
    exit 1
}

Write-Host "[done] Wanderburg running with mod loaded" -ForegroundColor Green
exit 0
