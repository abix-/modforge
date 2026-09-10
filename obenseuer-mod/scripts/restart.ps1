<#
.SYNOPSIS
Rebuild, redeploy, and restart Obenseuer with the current mod.

.DESCRIPTION
Steps, in order:
  1. Build obenseuer-mod (Rust, via k3sc cargo-lock).
  2. Build the BepInEx shim (dotnet, against the game's refs).
  3. Close the game if it is running and wait for it to exit.
  4. Deploy: shim dll + mod dll into BepInEx/plugins/obenseuer-mod/.
  5. Launch the game through Steam.
  6. Wait until the mod's control plane answers on port 17175.

.PARAMETER SkipBuild
Skip steps 1-2 and deploy whatever is already built.

.EXAMPLE
pwsh -NoProfile -File obenseuer-mod/scripts/restart.ps1
#>
[CmdletBinding()]
param (
    [switch]$SkipBuild
)

$Repo = Resolve-Path (Join-Path $PSScriptRoot "..\..")
$GameDir = "C:\Games\Steam\steamapps\common\Obenseuer"
$PluginDir = Join-Path $GameDir "BepInEx\plugins\obenseuer-mod"
$AppId = "951240"
$Port = 17175
$ProcessName = "Obenseuer"

if (-not $SkipBuild) {
    Write-Host "[build] obenseuer-mod (Rust)" -ForegroundColor Cyan
    Push-Location $Repo
    k3sc cargo-lock build --release -p obenseuer-mod
    if ($LASTEXITCODE -ne 0) { Pop-Location; throw "cargo build failed" }
    Pop-Location

    Write-Host "[build] BepInEx shim (C#)" -ForegroundColor Cyan
    dotnet build -c Release `
        -p:BepInExDir="$GameDir\BepInEx" `
        -p:UnityDir="$GameDir\Obenseuer_Data\Managed" `
        (Join-Path $Repo "unityforge\cs-shim-mono\Unityforge.Shim.Mono.csproj")
    if ($LASTEXITCODE -ne 0) { throw "shim build failed" }
}

$game = Get-Process $ProcessName -ErrorAction SilentlyContinue
if ($game) {
    Write-Host "[stop] closing $ProcessName (pid $($game.Id))" -ForegroundColor Cyan
    $game.CloseMainWindow() | Out-Null
    if (-not $game.WaitForExit(20000)) {
        Write-Warning "no clean exit after 20s; killing"
        Stop-Process -Id $game.Id -Force
        $game.WaitForExit()
    }
    Start-Sleep -Seconds 2
}

Write-Host "[deploy] shim + mod into plugins/" -ForegroundColor Cyan
if (-not (Test-Path $PluginDir)) {
    New-Item -ItemType Directory -Force -Path $PluginDir | Out-Null
}
Copy-Item (Join-Path $Repo "unityforge\cs-shim-mono\bin\Release\netstandard2.1\Unityforge.Shim.Mono.dll") `
    (Join-Path $PluginDir "Unityforge.Shim.Mono.dll") -Force
Copy-Item (Join-Path $Repo "target\x86_64-pc-windows-msvc\release\obenseuer_mod.dll") `
    (Join-Path $PluginDir "obenseuer_mod.unityforge.dll") -Force
Get-ChildItem $PluginDir -Filter "obenseuer_mod.unityforge.gen*.dll" -ErrorAction SilentlyContinue | Remove-Item -Force

Write-Host "[launch] steam://rungameid/$AppId" -ForegroundColor Cyan
Start-Process "steam://rungameid/$AppId"

Write-Host "[wait] control plane on port $Port (up to 180s)" -ForegroundColor Cyan
$deadline = (Get-Date).AddSeconds(180)
$cpReady = $false
while ((Get-Date) -lt $deadline) {
    try {
        $r = Invoke-RestMethod -Uri "http://127.0.0.1:$Port/op" -Method Post `
            -Body '{"op":"ping","args":{}}' -ContentType "application/json" -TimeoutSec 2
        Write-Host "[ready] control plane answering" -ForegroundColor Green
        $cpReady = $true
        break
    }
    catch {
        Start-Sleep -Seconds 3
    }
}
if (-not $cpReady) {
    Write-Warning "control plane not answering after 180s; check BepInEx\LogOutput.log"
    exit 1
}
