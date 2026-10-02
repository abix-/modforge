<#
.SYNOPSIS
Rebuild the Rust mod and hot reload it into the running game.

.DESCRIPTION
For Rust-only changes; the game and the loaded save keep running.
The MelonLoader shim (GenerationLoader, cs-shim-common) checks Mods/
once a second for a higher `*.gen<N>.dll`, shuts the old generation
down (its Harmony hooks removed, HTTP server stopped), then loads and
starts the new one.
Steps, in order:
  1. Build thewalkingtrade-mod (Rust, via k3sc cargo-lock).
  2. Copy the dll into Mods/ as the next generation, under a temporary
     name first and then renamed, so the shim never loads a half
     copied file.
  3. Wait for the MelonLoader log to report the swap complete, then
     for the control plane to answer on port 17181.
  4. Exit 2 when the shim reports a method the new generation no
     longer patches: on IL2CPP it keeps its Harmony wrapper until the
     game restarts, so run restart.ps1.

A change to the C# shim still needs restart.ps1. Byte patches are
reverted at shutdown (modforge code_patch::revert_all) and made again
by the new generation.

.EXAMPLE
pwsh -NoProfile -File thewalkingtrade-mod/scripts/reload.ps1
#>
[CmdletBinding()]
param ()

$Repo = Resolve-Path (Join-Path $PSScriptRoot "..\..")
$GameDir = "C:\Games\Steam\steamapps\common\The Walking Trade"
$Mods = Join-Path $GameDir "Mods"
$Log = Join-Path $GameDir "MelonLoader\Latest.log"
$Port = 17181

if (-not (Get-Process "The Walking Trade" -ErrorAction SilentlyContinue)) {
    throw "The Walking Trade is not running; use restart.ps1"
}

Write-Host "[build] thewalkingtrade-mod (Rust)" -ForegroundColor Cyan
Push-Location $Repo
k3sc cargo-lock build --release -p thewalkingtrade-mod
if ($LASTEXITCODE -ne 0) { Pop-Location; throw "cargo build failed" }
Pop-Location

$gens = Get-ChildItem $Mods -Filter "thewalkingtrade_mod.unityforge.gen*.dll" |
    ForEach-Object { if ($_.Name -match '\.gen(\d+)\.dll$') { [int]$Matches[1] } }
$next = 1 + (($gens | Measure-Object -Maximum).Maximum ?? 0)
$target = Join-Path $Mods "thewalkingtrade_mod.unityforge.gen$next.dll"
$staging = "$target.tmp"

$logLines = (Get-Content $Log -ErrorAction SilentlyContinue | Measure-Object -Line).Lines

Write-Host "[deploy] generation $next" -ForegroundColor Cyan
Copy-Item (Join-Path $Repo "target\x86_64-pc-windows-msvc\release\thewalkingtrade_mod.dll") $staging -Force
Move-Item $staging $target -Force

Write-Host "[wait] shim swap to generation $next (up to 30s)" -ForegroundColor Cyan
$deadline = (Get-Date).AddSeconds(30)
$swapped = $false
while ((Get-Date) -lt $deadline) {
    $new = Get-Content $Log -ErrorAction SilentlyContinue | Select-Object -Skip $logLines
    if ($new -match "hot reload complete \(now generation $next;") { $swapped = $true; break }
    Start-Sleep -Seconds 1
}
if (-not $swapped) { throw "shim did not report the swap to generation $next; check $Log" }
Write-Host "[swap] $(($new -match 'hot reload generation') | Select-Object -Last 1)" -ForegroundColor Cyan

# A hook this generation dropped leaves the game's method wrapped
# until restart (the shim lists each one); the running game is then
# not what a fresh start of this build would be.
$wrapped = $new -match "keeps its Harmony wrapper"
if ($wrapped) {
    $wrapped | ForEach-Object { Write-Warning $_ }
    Write-Warning "hot reload dropped $(@($wrapped).Count) hook(s); run restart.ps1 before trusting any result"
    exit 2
}

Write-Host "[wait] control plane on port $Port (up to 30s)" -ForegroundColor Cyan
$deadline = (Get-Date).AddSeconds(30)
while ((Get-Date) -lt $deadline) {
    try {
        Invoke-RestMethod -Uri "http://127.0.0.1:$Port/op" -Method Post `
            -Body '{"op":"ping","args":{}}' -ContentType "application/json" -TimeoutSec 2 | Out-Null
        Write-Host "[ready] generation $next answering" -ForegroundColor Green
        exit 0
    }
    catch {
        Start-Sleep -Seconds 1
    }
}
Write-Warning "control plane not answering after 30s; check $Log"
exit 1
