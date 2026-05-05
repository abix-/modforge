# TODO

Current state: Rust port of the mod is feature-complete on the runtime
side. Open work below is **distribution**, not features: switching from
"DLL + separate inject.exe" to a self-loading DLL proxy so the mod ships
through Vortex like every other actively-maintained UE-game DLL mod.

## 1. Repackage as a DLL proxy (winhttp.dll)

Why: our current shape doesn't fit Vortex. Users expect "install mod ->
launch game -> mod is active." Today we require a manual `inject.exe`
run every session. Pak-based mods solve that but inherit the
conflict/breakage hell visible in the Nexus comments on Player Tweaks.
DLL proxy is the standard third path: Windows auto-loads the DLL
because it shares a filename with a system DLL the game already
imports, and we forward the real exports to the system copy. UE4SS,
ReShade, ENB all do this.

Plan:

1. **Pick proxy target.** `winhttp.dll`. Low conflict risk vs other UE
   mods (ReShade owns dxgi.dll, UE4SS owns dwmapi.dll). Small export
   surface (~20 functions). Loaded early in process startup so our
   DllMain runs before the inventory UI ever spawns.
2. **Rename cdylib output.** Change `[lib] name` so cargo emits
   `winhttp.dll`.
3. **Generate forwarder exports.** `dumpbin /exports
   C:\Windows\System32\winhttp.dll` -> hand-edit a `winhttp.def` file
   that re-exports every name to the system copy via
   `EXPORTS  Foo = C:\Windows\System32\winhttp.Foo`. Commit the def
   file; Cargo invokes the linker with it.
4. **Verify game still talks to real winhttp.** Launch with our proxy
   in place, confirm the game's network/telemetry calls (if any) still
   work. If we drop a forwarder, those calls fail silently.
5. **Drop injector from user-facing distribution.** `inject.exe` stays
   in the repo as a dev-time iteration tool, not shipped.
6. **Write Vortex manifest** (`info.json` etc) so the user can
   one-click install via Vortex and the file lands in
   `Grounded2\Augusta\Binaries\Win64\winhttp.dll`.
7. **Ship a Nexus release** with: the proxy DLL, `settings.json`
   (defaults), README, and the Vortex installer metadata.

Risks / things to verify:
- Anti-cheat. Grounded 2 has none today. If that changes, proxy DLLs
  may trip detection; revisit then.
- DllMain TLS hazard. Already handled: our DllMain just spawns a
  thread, all std work happens in the worker.
- Forwarder correctness. A missing export means a missing function for
  the game -> potential crash. The `dumpbin` -> `.def` pipeline is
  well-trodden; we just need to keep it complete.

Effort: ~half a day. Mod logic is untouched.

## 2. (later) Port more Player Tweaks features

See `FEATURES.md` for the comparison table and the prioritized list.
Quick wins identified: stamina regen, sprint/walk/swim speed, hauling
stack size, death delay. Each is the same shape as the existing
hunger/thirst patch -- find the offset in the SDK, add a section to
`settings.json`, write a 50-line module. Order them by user demand.

## Out of scope (kept for context)

- Visible 6-row inventory grow. Replaced by paged 4x10 viewport. Working.
- Multiplayer correctness for hunger/thirst. Stats almost certainly
  replicate server-authoritatively, so non-host clients won't see the
  effect. Document, don't fight.

## Done

- Rust port of the mod (RUST_PORT_PLAN.md steps 1-8, 11).
- Backpack capacity patch -> 100 slots (settings-driven), validated
  in-game.
- `WBP_InventoryInterface_C` ProcessEvent hook + viewport rebind.
- Mouse-wheel scrolling preserves absolute slot positions (empty slots
  stay empty, no upward compaction).
- Worker thread terminates after init -- no recurring overhead.
- `inject.exe` writes its own log, exits without pausing.
- `inject.exe` auto-launches the game via Steam (or fallback exe) when
  it's not already running, then polls until the process appears, then
  injects. `--no-launch` to opt out. Configured via `inject.json` next
  to inject.exe (`inject.example.json` is the schema). Default Steam
  app id: `3104110`.
- `settings.json` next to the DLL controls slot count + thirst/hunger
  multipliers. `better-backpack/settings.example.json` is the schema.
  Defaults: slot_count=100, thirst/hunger multipliers=0.5.
- Hunger and thirst rate patch via `survival.rs` -- patches every
  SurvivalComponent CDO's `HungerSettings.AdjustmentPerSecond` and
  `ThirstSettings.AdjustmentPerSecond` floats by the configured
  multipliers.
- DLL log file moved from `%TEMP%\BetterBackpack.log` to
  `<DLL_dir>\better_backpack.log`. Both binaries now log next to
  themselves.
- `AllocConsole` gated behind a Cargo `console` feature. Default-on so
  development still gets the live window; `cargo build --release
  --no-default-features` produces a console-free shipping build.
- `BUILDING.md` + `PERFORMANCE.md` at repo root.
- ProcessEvent hot path is mutex-free: REGISTRY snapshot is published as
  a leaked `&'static [&'static Entry]` via `AtomicPtr`, trampoline does
  one atomic load + slice scan. `in_synthetic_refresh` is `AtomicBool`.
