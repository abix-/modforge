<#
.SYNOPSIS
Rebuild, redeploy, and restart The Walking Trade with the current mod.

.DESCRIPTION
The one path for getting the working tree into the live game.
Steps, in order:
  1. Build thewalkingtrade-mod (Rust, via k3sc cargo-lock).
  2. Build the MelonLoader shim (dotnet, against the game's refs).
  3. Close the game if it is running and wait for it to exit.
  4. Deploy: shim dll + fresh base mod dll into Mods/, and delete
     stale hot-reload generation dlls (a restart resets to gen 0).
  5. Launch the game through Steam.
  6. Wait until the mod's control plane answers on port 17181.

.PARAMETER SkipBuild
Skip steps 1-2 and deploy whatever is already built.

.EXAMPLE
pwsh -NoProfile -File thewalkingtrade-mod/scripts/restart.ps1

.NOTES
MelonLoader must already be installed and have run once in the
game folder: the shim build reads its references from
<game>\MelonLoader and <game>\MelonLoader\Il2CppAssemblies.
#>
[CmdletBinding()]
param (
    [switch]$SkipBuild
)

$Repo = Resolve-Path (Join-Path $PSScriptRoot "..\..")
$GameDir = "C:\Games\Steam\steamapps\common\The Walking Trade"
$Mods = Join-Path $GameDir "Mods"
$AppId = "3398110"
$Port = 17181

if (-not (Test-Path (Join-Path $GameDir "MelonLoader\Il2CppAssemblies"))) {
    throw "MelonLoader has not generated Il2CppAssemblies in $GameDir; launch the game once first"
}

if (-not $SkipBuild) {
    Write-Host "[build] thewalkingtrade-mod (Rust)" -ForegroundColor Cyan
    Push-Location $Repo
    k3sc cargo-lock build --release -p thewalkingtrade-mod
    if ($LASTEXITCODE -ne 0) { Pop-Location; throw "cargo build failed" }
    Pop-Location

    Write-Host "[build] MelonLoader shim (C#, NoSchedule1)" -ForegroundColor Cyan
    Push-Location (Join-Path $Repo "unityforge\cs-shim-melonloader")
    dotnet build -c Release -p:MelonLoaderDir="$GameDir\MelonLoader" -p:NoSchedule1=true
    if ($LASTEXITCODE -ne 0) { Pop-Location; throw "shim build failed" }
    Pop-Location
}

$game = Get-Process "The Walking Trade" -ErrorAction SilentlyContinue
if ($game) {
    Write-Host "[stop] closing The Walking Trade (pid $($game.Id))" -ForegroundColor Cyan
    $game.CloseMainWindow() | Out-Null
    if (-not $game.WaitForExit(20000)) {
        Write-Warning "no clean exit after 20s; killing"
        Stop-Process -Id $game.Id -Force
        $game.WaitForExit()
    }
    Start-Sleep -Seconds 2  # let file locks drop
}

Write-Host "[deploy] shim + mod into Mods/" -ForegroundColor Cyan
Copy-Item (Join-Path $Repo "unityforge\cs-shim-melonloader\bin\Release\net6.0\Unityforge.Shim.Melon.dll") `
    (Join-Path $Mods "Unityforge.Shim.Melon.dll") -Force
Copy-Item (Join-Path $Repo "target\x86_64-pc-windows-msvc\release\thewalkingtrade_mod.dll") `
    (Join-Path $Mods "thewalkingtrade_mod.unityforge.dll") -Force
Get-ChildItem $Mods -Filter "thewalkingtrade_mod.unityforge.gen*.dll" | Remove-Item -Force

Write-Host "[launch] steam://rungameid/$AppId" -ForegroundColor Cyan
Start-Process "steam://rungameid/$AppId"

Write-Host "[wait] control plane on port $Port (up to 180s)" -ForegroundColor Cyan
$deadline = (Get-Date).AddSeconds(180)
while ((Get-Date) -lt $deadline) {
    try {
        Invoke-RestMethod -Uri "http://127.0.0.1:$Port/op" -Method Post `
            -Body '{"op":"ping","args":{}}' -ContentType "application/json" -TimeoutSec 2 | Out-Null
        Write-Host "[ready] control plane answering" -ForegroundColor Green
        exit 0
    }
    catch {
        Start-Sleep -Seconds 3
    }
}
Write-Warning "control plane not answering after 180s; check the MelonLoader console"
exit 1
