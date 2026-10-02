<#
.SYNOPSIS
Rebuild and get the current mod running in 7 Days To Die: hot reload
when the game is up and only Rust changed, otherwise a full restart.

.DESCRIPTION
Steps, in order:
  1. Build sevendaystodie-mod (Rust, via k3sc cargo-lock).
  2. Build the shim (dotnet, against the game's own DLLs).
  3. Hot reload, when the game is running AND the built shim is the
     one already deployed (a managed assembly cannot be swapped in a
     running game):
       - copy the Rust dll into Mods/Unityforge/native/ as the next
         `*.gen<N>.dll`, under a .tmp name first and then renamed, so
         the shim never loads a half copied file;
       - wait for the log to report the swap complete;
       - exit 2 if the shim reports a method the new generation no
         longer patches but that keeps its Harmony wrapper.
     Otherwise a full restart:
       - close the game if it is running and wait for it to exit;
       - deploy ModInfo.xml + shim into Mods/Unityforge/, the Rust dll
         into Mods/Unityforge/native/ (the game's loader loads every
         dll at the top of the mod folder; a native one there would
         fail the whole mod), and remove stale generations;
       - launch 7DaysToDie.exe directly: mods with code are skipped
         under EasyAntiCheat, which only 7DaysToDie_EAC.exe starts.
  4. Wait until the mod's control plane answers on port 17182.

.PARAMETER SkipBuild
Skip steps 1-2 and use whatever is already built.

.PARAMETER Full
Full restart even if a hot reload would do.

.EXAMPLE
pwsh -NoProfile -File sevendaystodie-mod/scripts/restart.ps1
#>
[CmdletBinding()]
param (
    [switch]$SkipBuild,
    [switch]$Full
)

$Repo = Resolve-Path (Join-Path $PSScriptRoot "..\..")
$GameDir = "C:\Games\Steam\steamapps\common\7 Days To Die"
$ModDir = Join-Path $GameDir "Mods\Unityforge"
$NativeDir = Join-Path $ModDir "native"
$Log = Join-Path $GameDir "7DaysToDie_Data\output_log.txt"
$Port = 17182
$ProcessName = "7DaysToDie"
$ShimName = "Unityforge.Shim.SevenDaysToDie.dll"
$ShimBuilt = Join-Path $Repo "unityforge\cs-shim-sevendaystodie\bin\Release\net48\$ShimName"
$ShimDeployed = Join-Path $ModDir $ShimName
$RustBuilt = Join-Path $Repo "target\x86_64-pc-windows-msvc\release\sevendaystodie_mod.dll"
$RustName = "sevendaystodie_mod.unityforge"

if (-not $SkipBuild) {
    Write-Host "[build] sevendaystodie-mod (Rust)" -ForegroundColor Cyan
    Push-Location $Repo
    k3sc cargo-lock build --release -p sevendaystodie-mod
    if ($LASTEXITCODE -ne 0) { Pop-Location; throw "cargo build failed" }
    Pop-Location

    Write-Host "[build] shim (C#)" -ForegroundColor Cyan
    dotnet build -c Release `
        -p:GameDir="$GameDir" `
        (Join-Path $Repo "unityforge\cs-shim-sevendaystodie\Unityforge.Shim.SevenDaysToDie.csproj")
    if ($LASTEXITCODE -ne 0) { throw "shim build failed" }
}

function Wait-ControlPlane([int]$Seconds) {
    Write-Host "[wait] control plane on port $Port (up to ${Seconds}s)" -ForegroundColor Cyan
    $deadline = (Get-Date).AddSeconds($Seconds)
    while ((Get-Date) -lt $deadline) {
        try {
            Invoke-RestMethod -Uri "http://127.0.0.1:$Port/op" -Method Post `
                -Body '{"op":"ping","args":{}}' -ContentType "application/json" -TimeoutSec 2 | Out-Null
            Write-Host "[ready] control plane answering" -ForegroundColor Green
            return $true
        }
        catch {
            Start-Sleep -Seconds 2
        }
    }
    Write-Warning "control plane not answering after ${Seconds}s; check $Log"
    return $false
}

$ConfigSrc = Join-Path $Repo "sevendaystodie-mod\Config"
$ConfigDeployed = Join-Path $ModDir "Config"

# The game reads Config XML only at startup, so a Config change
# needs a full restart just like a shim change.
function Get-ConfigHashes([string]$Dir) {
    if (-not (Test-Path $Dir)) { return "" }
    (Get-ChildItem $Dir -Recurse -File | Sort-Object FullName | ForEach-Object {
        $_.FullName.Substring($Dir.Length) + "=" + (Get-FileHash $_.FullName).Hash
    }) -join ";"
}

$game = Get-Process $ProcessName -ErrorAction SilentlyContinue
$shimSame = (Test-Path $ShimDeployed) -and
    ((Get-FileHash $ShimBuilt).Hash -eq (Get-FileHash $ShimDeployed).Hash)
$configSame = (Get-ConfigHashes $ConfigSrc) -eq (Get-ConfigHashes $ConfigDeployed)
# A running game is only hot-reloadable if the mod is loaded in it:
# started with EasyAntiCheat (Steam's default launch), the game
# skips the mod and nothing is there to swap.
$modLoaded = $false
if ($game) {
    try {
        Invoke-RestMethod -Uri "http://127.0.0.1:$Port/op" -Method Post `
            -Body '{"op":"ping","args":{}}' -ContentType "application/json" -TimeoutSec 2 | Out-Null
        $modLoaded = $true
    }
    catch {
        Write-Host "[check] game running but the mod is not answering (started with EasyAntiCheat?); full restart" -ForegroundColor Yellow
    }
}

if ($game -and $modLoaded -and $shimSame -and $configSame -and -not $Full) {
    $gens = Get-ChildItem $NativeDir -Filter "$RustName.gen*.dll" -ErrorAction SilentlyContinue |
        ForEach-Object { if ($_.Name -match '\.gen(\d+)\.dll$') { [int]$Matches[1] } }
    $next = 1 + (($gens | Measure-Object -Maximum).Maximum ?? 0)
    $target = Join-Path $NativeDir "$RustName.gen$next.dll"
    $logLines = (Get-Content $Log -ErrorAction SilentlyContinue | Measure-Object -Line).Lines

    Write-Host "[reload] generation $next" -ForegroundColor Cyan
    Copy-Item $RustBuilt "$target.tmp" -Force
    Move-Item "$target.tmp" $target -Force

    Write-Host "[wait] shim swap to generation $next (up to 30s)" -ForegroundColor Cyan
    $deadline = (Get-Date).AddSeconds(30)
    $swapped = $false
    while ((Get-Date) -lt $deadline) {
        $new = Get-Content $Log -ErrorAction SilentlyContinue | Select-Object -Skip $logLines
        if ($new -match "hot reload complete \(now generation $next;") { $swapped = $true; break }
        Start-Sleep -Seconds 1
    }
    if (-not $swapped) { throw "shim did not report the swap to generation $next; check $Log" }
    $new -match "shutdown: undo |hot reload" | ForEach-Object { Write-Host "  $_" }

    $wrapped = $new -match "keeps its Harmony wrapper"
    if ($wrapped) {
        $wrapped | ForEach-Object { Write-Warning $_ }
        Write-Warning "hot reload dropped $(@($wrapped).Count) hook(s); run with -Full before trusting any result"
        exit 2
    }
    if (-not (Wait-ControlPlane 30)) { exit 1 }
    exit 0
}

if ($game) {
    Write-Host "[stop] closing $ProcessName (pid $($game.Id))" -ForegroundColor Cyan
    $game.CloseMainWindow() | Out-Null
    if (-not $game.WaitForExit(30000)) {
        Write-Warning "no clean exit after 30s; killing"
        Stop-Process -Id $game.Id -Force
        $game.WaitForExit()
    }
    Start-Sleep -Seconds 2
}

Write-Host "[deploy] ModInfo.xml + Config/ + shim into Mods/Unityforge/, mod into native/" -ForegroundColor Cyan
New-Item -ItemType Directory -Force -Path $NativeDir | Out-Null
Copy-Item (Join-Path $Repo "sevendaystodie-mod\ModInfo.xml") (Join-Path $ModDir "ModInfo.xml") -Force
# Config/ is ours alone: replace it whole so a file removed from the
# repo is removed from the game too.
if (Test-Path $ConfigDeployed) { Remove-Item $ConfigDeployed -Recurse -Force }
Copy-Item $ConfigSrc $ConfigDeployed -Recurse -Force
Copy-Item $ShimBuilt $ShimDeployed -Force
Copy-Item $RustBuilt (Join-Path $NativeDir "$RustName.dll") -Force
Get-ChildItem $NativeDir -Filter "$RustName.gen*.dll*" -ErrorAction SilentlyContinue | Remove-Item -Force

Write-Host "[launch] 7DaysToDie.exe (no EasyAntiCheat), log at $Log" -ForegroundColor Cyan
Start-Process -FilePath (Join-Path $GameDir "7DaysToDie.exe") -WorkingDirectory $GameDir `
    -ArgumentList "-logfile", "`"$Log`""

if (-not (Wait-ControlPlane 240)) { exit 1 }
