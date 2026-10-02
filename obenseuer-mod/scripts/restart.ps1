<#
.SYNOPSIS
Rebuild and redeploy the mod into Obenseuer: hot reload when the game is
running and only the Rust changed, a full restart otherwise.

.DESCRIPTION
Steps, in order:
  1. Build obenseuer-mod (Rust, via k3sc cargo-lock).
  2. Build the BepInEx shim (dotnet, against the game's refs).
  3. Hot reload, when the game is running and the deployed shim is the
     one just built (only the Rust changed): copy the mod dll into
     BepInEx/plugins/obenseuer-mod/ as the next generation, under a
     temporary name first and then renamed so the shim never loads a
     half copied file. The shim's generation loader swaps it in within
     a second; the game and the loaded save keep running. Wait for
     "hot reload complete" in BepInEx/LogOutput.log and for the control
     plane on port 17175, then stop.
     If the swap is not reported in 30s, or the shim says a dropped
     hook keeps its Harmony wrapper, carry on with the full restart.
  4. Close the game if it is running and wait for it to exit.
  5. Deploy: shim dll + mod dll into BepInEx/plugins/obenseuer-mod/,
     removing every leftover generation.
  6. Launch the game through Steam.
  7. Wait until the mod's control plane answers on port 17175.

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
$Log = Join-Path $GameDir "BepInEx\LogOutput.log"
$ShimBuilt = Join-Path $Repo "unityforge\cs-shim-mono\bin\Release\netstandard2.1\Unityforge.Shim.Mono.dll"
$ShimDeployed = Join-Path $PluginDir "Unityforge.Shim.Mono.dll"
$RustBuilt = Join-Path $Repo "target\x86_64-pc-windows-msvc\release\obenseuer_mod.dll"

function Invoke-HotReload {
    <#
    .SYNOPSIS
    Step 3: swap the built mod dll into the running game. True when the
    new generation is in and answering; false when a full restart is
    needed instead.
    #>
    [CmdletBinding()]
    param ()

    if (-not (Get-Process $ProcessName -ErrorAction SilentlyContinue)) { return $false }
    if (-not (Test-Path $ShimDeployed)) { return $false }
    if ((Get-FileHash $ShimBuilt).Hash -ne (Get-FileHash $ShimDeployed).Hash) {
        Write-Host "[hot] the shim changed; a full restart is needed" -ForegroundColor Yellow
        return $false
    }

    $gens = Get-ChildItem $PluginDir -Filter "obenseuer_mod.unityforge.gen*.dll" |
        ForEach-Object { if ($_.Name -match '\.gen(\d+)\.dll$') { [int]$Matches[1] } }
    $next = 1 + (($gens | Measure-Object -Maximum).Maximum ?? 0)
    $target = Join-Path $PluginDir "obenseuer_mod.unityforge.gen$next.dll"
    $logLines = (Get-Content $Log -ErrorAction SilentlyContinue | Measure-Object -Line).Lines

    Write-Host "[hot] mod dll in as generation $next" -ForegroundColor Cyan
    Copy-Item $RustBuilt "$target.tmp" -Force
    Move-Item "$target.tmp" $target -Force

    Write-Host "[hot] waiting for the shim to swap to generation $next (up to 30s)" -ForegroundColor Cyan
    $deadline = (Get-Date).AddSeconds(30)
    $new = @()
    $swapped = $false
    while ((Get-Date) -lt $deadline) {
        $new = Get-Content $Log -ErrorAction SilentlyContinue | Select-Object -Skip $logLines
        if ($new -match "hot reload complete \(now generation $next;") { $swapped = $true; break }
        Start-Sleep -Seconds 1
    }
    if (-not $swapped) {
        Write-Warning "[hot] the shim did not report the swap to generation $next; restarting instead"
        return $false
    }
    Write-Host "[hot] $(($new -match 'hot reload complete') | Select-Object -Last 1)" -ForegroundColor Cyan

    # A hook this generation dropped leaves the game's method wrapped until
    # the game restarts; the running game would not be what this build is.
    $wrapped = $new -match "keeps its Harmony wrapper"
    if ($wrapped) {
        $wrapped | ForEach-Object { Write-Warning $_ }
        Write-Warning "[hot] $(@($wrapped).Count) dropped hook(s) still wrapped; restarting instead"
        return $false
    }

    $deadline = (Get-Date).AddSeconds(30)
    while ((Get-Date) -lt $deadline) {
        try {
            Invoke-RestMethod -Uri "http://127.0.0.1:$Port/op" -Method Post `
                -Body '{"op":"ping","args":{}}' -ContentType "application/json" -TimeoutSec 2 | Out-Null
            Write-Host "[ready] generation $next answering; the game kept running" -ForegroundColor Green
            return $true
        }
        catch {
            Start-Sleep -Seconds 1
        }
    }
    Write-Warning "[hot] generation $next not answering after 30s; restarting instead"
    return $false
}

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

if (Invoke-HotReload) { exit 0 }

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
