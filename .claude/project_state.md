# grounded2mods - project state

## Current focus
Porting the Better Backpack mod from C++ to a single Rust workspace
(cdylib + injector). C++ tree preserved at `better-backpack-cpp/` until the
Rust port reaches behavior parity. Plan in `RUST_PORT_PLAN.md`.

## Layout

```
grounded2mods/
  Cargo.toml                Workspace: better-backpack + injector
  rust-toolchain.toml       Stable, x86_64-pc-windows-msvc
  .cargo/config.toml        Target triple, target-dir override
  better-backpack/          cdylib + rlib (the mod itself)
    src/
      lib.rs                DllMain + worker entry
      sdk/                  Hand-written UE SDK shim
        offsets.rs          Steam/Xbox offset tables + field offsets
        fname.rs            FName + AppendString resolver
        fstring.rs          FString = TArray<u16>
        tarray.rs           TArray<T>
        uobject.rs          UObject/UClass/UFunction/GObjectsView/Runtime/find_class_fast
    tests/layout.rs         Static layout asserts
  injector/                 bin: standalone DLL injector (Rust port of inject.c)
  better-backpack-cpp/      OLD C++ tree, kept until Rust port hits parity
  RUST_PORT_PLAN.md         Migration plan (11 steps)
  better-backpack-cpp/PERFORMANCE_AUDIT.md   What we found in the C++ hot path
```

## Mod target (carried over from C++ port)
- Player main backpack capacity = `Maine.UInventoryComponent +0x01E0`
  (`int32 DefaultMaxSize`). Vanilla 40; target 100.
- Mount/saddlebag (vanilla 30) is left untouched.
- Viewport stays 4x10 in the live UI; we rebind 40 visible slots against
  shifting `ItemStartIndex` to scroll. The earlier 6-row growth path is
  retired.

## Key facts
- Game exes: Steam = `Grounded2-WinGRTS-Shipping.exe`, Xbox = `Grounded2-WinGDK-Shipping.exe`.
- Steam offsets (image-relative): GObjects=0x09F67028, AppendString=0x01252060, ProcessEventIdx=0x4C.
- Xbox offsets: GObjects=0x09F36F28, AppendString=0x01250F80, ProcessEventIdx=0x4C.
- UObject layout: vtable@0x00, flags@0x08, index@0x0C, class@0x10, name@0x18, outer@0x20, size=0x28.
- UClass: ClassDefaultObject@0x110. UFunction: FunctionFlags@0xB0.
- Build target dir overridden locally (~/.cargo/config.toml redirects to endless).

## Migration progress (RUST_PORT_PLAN.md)
- [x] 1. Rename C++ tree -> better-backpack-cpp.
- [x] 2. Workspace: Cargo.toml + rust-toolchain.toml + .cargo/config.toml.
- [x] 3. Injector crate (Rust port of inject.c). Builds.
- [x] 4. SDK module skeleton (UObject, UClass, UFunction, FName, FString,
     TArray, GObjectsView, Runtime, find_class_fast). Layout tests pass.
- [x] 5. Hook module: vtable.rs (VirtualProtect-guarded slot rewrite) +
     process_event.rs (RAII ProcessEventHook with registry-based dispatch
     and catch_unwind around the closure). Log module (file-only at
     %TEMP%\BetterBackpack.log).
- [x] 6. Patch loop wired in. **Validated in-game**: patch line
     `Default__BP_SurvivalPlayerCharacter_C.InventoryComponent: 40 -> 100,
     verify=100`. AllocConsole brought back so the live mod log surfaces
     in a "Better Backpack" console window the way the C++ build did.
- [x] 7. Inventory-interface hook + viewport rebind. inv_hook.rs +
     parms.rs. Cached UFunction* identity dispatch (no name compares).
     Trace gated by cfg!(debug_assertions). Single hook surface.
     **Hook installs in-game** -- log shows
     `inv hook: installed on WBP_InventoryInterface_C` once inventory UI
     loads.
- [x] 8. Trace surfaces in inv_hook.rs are already gated under
     cfg!(debug_assertions). Broader BPF/grid/menu trace coverage from
     the C++ build was intentionally not ported -- it was the dominant
     hot-path cost per the audit, and the cached UFunction* identity
     dispatch makes it unnecessary in normal operation.
- [ ] 9. Side-by-side parity test C++ vs Rust DLL.
- [ ] 10. Archive better-backpack-cpp/.
- [x] 11. Rust BUILDING.md at repo root. Prerequisites, build, run,
     quality gates, configuration knobs, retargeting via offsets.rs.

## Build commands
- `cargo build --release` builds both crates.
- `cargo test --release` runs layout tests.
- `cargo clippy --release --all-targets -- -D warnings` lint gate (clean today).
- Outputs: `target/x86_64-pc-windows-msvc/release/{winhttp.dll, inject.exe}`.
  The mod cdylib is named `winhttp.dll` so it doubles as a Windows DLL
  proxy at install time (drop into game's Binaries\Win64; Windows
  preferentially loads our copy via DLL search order; the 70 forwarder
  exports defined in `better-backpack/winhttp.def` redirect WinHTTP
  calls to `winhttp_orig.dll`, which is a copy of the system winhttp).
- The DLL is locked while the game holds it -- rebuild requires the game to
  be closed (or use a different output dir).
- inject.exe with no args looks for `winhttp.dll` next to itself
  (matches cdylib output name). Pass an explicit path to override.

## Logs
- Injector: `<inject.exe dir>/inject.log` -- truncated each run.
- Mod: `<DLL_dir>/better_backpack.log` -- truncated each DLL load.
  First-line tell for the Rust build is
  `=== Better Backpack DLL (rust) ===`.

## Settings
- `<DLL_dir>/settings.json` (optional). Schema in
  `better-backpack/settings.example.json`. Drives slot_count and
  thirst/hunger multipliers. Defaults baked in: slot_count=100,
  thirst_multiplier=0.5, hunger_multiplier=0.5. So out of the box
  (no settings file): 100-slot backpack + half-rate hunger and thirst.
- `<inject.exe dir>/inject.json` (optional). Schema in
  `injector/inject.example.json`. Drives auto-launch behavior:
  Steam app id (default 3104110), optional fallback exe path, poll
  interval and timeout for waiting on the game process.

## Cargo features (better-backpack)
- `console` (default on): spawns the "Better Backpack" console window
  via AllocConsole. Build with `--no-default-features` for a
  console-free shipping DLL. File log unaffected.

## Distribution plan (current, 2026-05-05)

Pivoted twice today. End state: ship as a **UE4SS C++ mod (CPPMod)**
with the source kept in Rust and a tiny C++ shim for UE4SS's
inheritance ABI. Plan + steelman in `UE4SS_PORT_PLAN.md`.

Why UE4SS over the winhttp.dll proxy approach we built earlier:

- UE4SS is the convention for UE5 game mods (UE4SS for Grounded 2 is
  Vortex mod #52, actively maintained). Riding on UE4SS gets us
  Vortex distribution out of the box, central SDK maintenance, and
  network effects with other modders.
- The winhttp proxy works (commits 514e2b1..bfb3447) but Vortex
  doesn't natively model "drop my custom proxy DLL into the game's
  Binaries dir" without a per-game extension.
- Pak distribution inherits the conflict/breakage problems we
  observed on Player Tweaks (Nexus #13).

Approach:

- Rust cdylib exports `better_backpack_start` / `better_backpack_stop`
  as `extern "C"`.
- ~30-line C++ shim derives from `RC::CppUserModBase`, forwards
  `on_unreal_init` and the destructor to the Rust extern functions,
  exports `start_mod` / `uninstall_mod`. Compiled via `cc::Build` and
  linked into the same cdylib.
- Headers consumed from `C:\code\RE-UE4SS` (cloned out-of-band; we
  don't vendor as a submodule because UE4SS's own `.gitmodules`
  references a 404'd repo).
- `UE4SS.lib` import library generated from the user's installed
  `UE4SS.dll` (located via Vortex at
  `<vortex>\grounded2\mods\UE4SS_Grounded2-...\Augusta\Binaries\WinGRTS\ue4ss\UE4SS.dll`)
  using `dumpbin /exports` -> `.def` -> `lib /def:`. Verified the
  DLL exports the symbols we need: `??0CppUserModBase@RC@@QEAA@XZ`
  (constructor), `??1CppUserModBase@RC@@UEAA@XZ` (virtual
  destructor), and every base virtual we'd override or inherit.

Distribution layout:

- Game's UE4SS path is `<game>\Augusta\Binaries\WinGRTS\ue4ss\` --
  note `WinGRTS` (Steam platform identifier in the exe name), not
  `Win64`. Earlier docs had `Win64`; corrected.
- C++ mods go in `ue4ss\Mods\<ModName>\dlls\main.dll`.
- Mod registration is via `ue4ss\Mods\mods.txt` (`ModName : 1` per
  line). Vortex's UE4SS extension merges entries on deploy.
- Our Vortex zip layout:
  ```
  Augusta/Binaries/WinGRTS/ue4ss/Mods/BetterBackpack/
    dlls/main.dll
    settings.json
  ```

The earlier winhttp.dll proxy work will be archived to
`archive/winhttp-proxy/` once the UE4SS path lands, kept as a
fallback if UE4SS turns out unstable for Grounded 2.

## Where we left off (2026-05-05, late-night)

**State (RESOLVED, working in-game 2026-05-05):**
- `main.dll` builds clean, exports `start_mod` / `uninstall_mod` /
  `DllMain` / `better_backpack_start` / `better_backpack_stop`.
- `deploy.ps1 -Install` works against the user's
  `C:\Games\Steam\steamapps\common\Grounded2\` install.
- UE4SS v3.0.1 Beta loads our mod, `on_unreal_init` fires, Rust
  side takes over. cpp_shim.log shows full lifecycle.

**Crash root cause:** vtable mismatch in `cpp/shim.cpp`'s
`RC::CppUserModBase` mirror. Data layout was fine (both shim and
UE4SS report sizeof=192). The vtable was missing six methods vs
`RE-UE4SS/UE4SS/include/Mod/CppUserModBase.hpp`: `on_ui_init`
(slot 4), four newer `on_lua_start`/`on_lua_stop` overloads taking
`Lua*` instead of `vector<Lua*>&` (slots 12-15), and
`on_cpp_mods_loaded` (slot 16). UE4SS dispatched through the later
slots during init -> jumped past our vtable -> crash.

**Fix:**
- Added all six missing virtuals in exact declaration order from
  the upstream header.
- Changed `on_dll_load` parameter from `std::wstring_view` to
  `StringViewType` to match the header verbatim.
- `on_cpp_mods_loaded` is NOT marked `RC_UE4SS_API` (dllimport):
  UE4SS.lib doesn't export this symbol. Using local inline body.

**Next:**
- TODO.md item 1 step 8 (archive winhttp proxy material).
- TODO.md item 2 (project rename) and items 3-7 (new feature
  multipliers).

## RPG pivot (2026-05-05)

Direction shift: turning the mod into a Factorio-RPG-style
level-up mod. Kills -> XP -> levels -> perks that drive the
existing CDO patches. Research questions R1-R5 answered against
the SDK at `C:\tools\work\sdk\` -- see TODO.md section 0.

### Spike A: DONE (2026-05-05)

Attempt 1 (Kill UFunction) failed because `Kill` is
`Final|Native` and the engine bypasses ProcessEvent on the
internal damage path.

Attempt 2 used Option A from the options doc (NOT the global
PE hook). Key insight: SDK has
`enum class EDamageInfoFlags { KillingBlow = 2, ... }` at
`Maine_structs.hpp:1769`. The
`MulticastHandleEffectsWithDamageFlags` UFunction on
HealthComponent fires via PE on every damage hit and carries
the DamageFlags parm. Mask with KillingBlow bit -> we know if
this hit was lethal.

In-game confirmed: kill a creature -> one log line with dying
actor + class + killer controller + killer class. No global PE
hook needed; per-vtable hook on HealthComponent is sufficient.

Implementation: `better-backpack/src/rpg/kill_hook.rs`. ~80
lines. Filters to `ASurvivalCreature` subclasses to exclude
buildings/props which also fire this function on destruction.

### Side issue noticed

Log shows `initial patch round: scanned=2, patched=0` and
`survival patch: scanned_classes=0, patched=0` -- the existing
backpack/hunger/thirst patches may be running before GObjects is
fully populated, or there's been an SDK shape change. Not
related to RPG track. Investigate when convenient.

## Bugs found and fixed during testing
- **GObjects extra indirection** (2026-05-04): GObjectsView::from_image was
  treating `image_base + g_objects` as a pointer-to-pointer and
  dereferencing once. The address IS the TUObjectArray struct directly.
  Symptom: log halted after platform detection. Fixed in sdk/uobject.rs.
- **find_class_fast missed Blueprint classes** (2026-05-04): meta-class
  filter only matched native `Class`. Blueprint-generated classes have
  meta-class `WidgetBlueprintGeneratedClass` (a subclass of `Class`).
  Symptom: inventory hook never installed. Fix: walk meta-class
  super_class chain.
- **Injector default DLL name PascalCase mismatch**: cdylib output is
  `better_backpack.dll`; injector default was `BetterBackpack.dll`. Fixed
  injector to match cdylib output.
- **Live console missing**: C++ DLL spawned a console via AllocConsole;
  Rust DLL had to too. Re-added with WriteConsoleA + file mirror.
- **Injector closed too fast**: added pause-before-exit (--no-pause to
  skip) and per-run inject.log.

## Known minor issues
- The CDO patch only reaches inventory instances constructed AFTER the
  DLL loads. If the player's inventory was constructed before injection,
  a save reload may be required to see 100 slots in-game.

## Worker thread lifecycle (revised 2026-05-04)
- Worker patches the CDO once, then installs the inv hook with backoff
  retry, then **exits**. No 10-second rescan loop. CDO patches are
  sticky for the lifetime of the DLL; UE does not re-load CDOs during a
  session. Save loads spawn fresh inventory instances that inherit from
  the patched CDO automatically.
- If a real CDO-revert scenario is ever observed, switch to
  `FUObjectArray::AddUObjectCreateListener` (canonical UE4SS pattern,
  ~100 lines) instead of bringing back the polling loop.

## Open questions
- Step 6 needs validation that calling `original` ProcessEvent from a Rust
  hook closure preserves UE's thiscall expectations on this platform.
- DllMain TLS hazard: keep DllMain to `CreateThread` only; all std work in
  the worker.
- Panic-in-hook: every hook closure wraps body in `catch_unwind`, falls
  through to original on panic.
