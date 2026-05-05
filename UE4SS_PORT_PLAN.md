# Plan: ship as a UE4SS C++ mod (CPPMod), keep code in Rust

This doc replaces TODO #1 (winhttp.dll proxy + custom Vortex packaging).
Keeping the proxy plan as a fallback in case UE4SS turns out to be
unstable for Grounded 2 in practice.

## Why

Steelman in 11 points (long version below in "Steelman" section). The
short of it:

- **Distribution is solved.** Vortex extensions for UE5 games converge
  on UE4SS-aware install paths within the first year of any game's
  mod scene. We ride on that instead of inventing our own.
- **We're rebuilding what UE4SS has, badly.** Our hand-rolled SDK
  shim, vtable hooker, and `find_class_fast` are correct for our two
  features; UE4SS has correct equivalents for the entire UE5 surface,
  battle-tested across many games and engine versions.
- **Game patches break us harder than they break UE4SS users.** When
  Grounded 2 updates and offsets shift, every individual mod that
  ships its own offsets file (us today) is broken until that mod's
  author dumps a fresh SDK. UE4SS users get patched centrally.
- **Mod-author ecosystem.** UE5 modders read other UE5 mods to learn.
  A UE4SS Lua/CPP mod is something they can crib from. A standalone
  Rust DLL with a hand-rolled SDK is curiosity, not template.
- **The Vortex problem we just hit isn't a Vortex bug.** It's the
  cost of being unconventional. UE4SS is the convention.
- **Lua is good enough for our perf profile.** Per
  `PERFORMANCE.md`, this mod is invisible to a frame profile. We
  optimized to atomic-load on the inventory hot path. Lua handles
  that with margin to spare.
- **CDO patches are *better* in Lua because the user can read them.**
  `survival_cdo:GetPropertyByName("ThirstSettings"):GetPropertyByName("AdjustmentPerSecond"):SetValue(orig * 0.5)`
  is self-documenting in a way our Rust code isn't.

## What we keep

- The repo. The Rust code. The whole mod-feature set: backpack
  capacity, hunger / thirst rate multipliers, mouse-wheel viewport
  rebind, JSON settings, file logging.
- The Rust SDK shim (`UObject`, `UClass`, `UFunction`, `find_class_fast`,
  `GObjectsView`). Our shim is a working, correct subset of UE5
  reflection. It's not redundant just because UE4SS *also* has one --
  ours runs in our process without a UE4SS dependency for the
  fallback "standalone DLL" build.
- The injector (`inject.exe`). Stays as a dev-time tool for fast
  iteration that doesn't require restarting the game. Not a user
  distribution path.
- The settings.json schema and defaults.
- Most of the live test surface: layout asserts, clippy, the
  per-feature module split (patch.rs, survival.rs, inv_hook.rs).

## What changes (mod side)

- **Output filename.** `winhttp.dll` -> `main.dll` (UE4SS's
  convention for `<game>/.../Mods/<modname>/dlls/main.dll`).
- **Entry point.** `DllMain` no longer spawns the worker. Instead we
  export UE4SS's CPPMod entry points:
  - `start_mod()` -> spawn worker, return a non-null pointer (or a
    minimal `CppUserModBase`-shaped object if the modern API is
    required).
  - `uninstall_mod(mod)` -> signal worker shutdown.
  - DllMain becomes essentially a no-op.
- **Worker init order improvement.** UE4SS calls `start_mod` *after*
  the engine has finished initializing, so the `wait_for_gobjects`
  retry loop becomes unnecessary. We just initialize and patch.
- **Forwarder C file + winhttp.def + cc build dep go away.** No
  proxy mechanic needed; UE4SS handles the loading.

## What changes (packaging side)

- **Zip layout** changes from a flat drop to UE4SS's standard mod
  folder shape:
  ```
  BetterBackpack/
    enabled.txt          (empty file, UE4SS uses its presence as the
                          enable flag)
    dlls/
      main.dll
    settings.json
  ```
  The zip's root is `BetterBackpack/` so when extracted into the
  game's `<game>\Augusta\Binaries\Win64\Mods\` folder, everything
  ends up in the right place.
- **No setup.ps1.** No System32 winhttp copy. The user has already
  installed UE4SS once; that's the prerequisite.
- **deploy.ps1 modes:**
  - Default `-Package`: builds the mod folder, zips it.
  - `-Install`: builds and copies the mod folder into the game's
    UE4SS Mods directory.
  - `-Uninstall`: deletes the BetterBackpack folder from
    Mods.
- **Vortex.** When Grounded 2 gets a Vortex extension that's
  UE4SS-aware (most UE5 games eventually do), our mod auto-installs.
  In the interim, manual extraction into the Mods folder works.

## What stays the same

- Mod feature set, settings.json schema, defaults, log file location
  (`<DLL_dir>\better_backpack.log`).
- Performance characteristics. `PERFORMANCE.md` numbers don't move
  meaningfully -- we're still doing one CDO patch + one ProcessEvent
  hook. UE4SS adds maybe ~10us of additional latency at start (it
  calls `start_mod` slightly later than DllMain would have run), but
  that's not a frame-time concern.
- Steam/Xbox platform detection logic.

## What's the rewrite cost?

**Hard requirement: stay 100% Rust.** No C++ shim, no Lua port. UE4SS
loads our cdylib, we bridge whatever ABI it expects from Rust.

Three Rust-only paths in priority order:

1. **(preferred) Legacy free-function ABI.** Export `start_mod()` and
   `uninstall_mod()` as plain `extern "C"` symbols from the cdylib.
   No inheritance, no vtables. If current UE4SS still supports this
   path -- and it should, since changing it would break every existing
   CPPMod -- this is ~half-day of work. Implementation: 20 lines in
   `lib.rs`, drop the winhttp proxy plumbing, done.
2. **(fallback) Hand-rolled vtable in Rust to satisfy the modern
   `CppUserModBase` ABI.** UE4SS's modern API expects a C++ object
   pointer whose vtable matches `CppUserModBase`. We can construct
   one in Rust:
   ```rust
   #[repr(C)]
   struct CppUserModBaseVTable {
       destructor:        unsafe extern "C" fn(*mut Mod),
       on_dll_load:       unsafe extern "C" fn(*mut Mod, *const u16),
       on_program_start:  unsafe extern "C" fn(*mut Mod),
       on_unreal_init:    unsafe extern "C" fn(*mut Mod),
       /* ... one fn ptr per virtual UE4SS expects ... */
   }
   #[repr(C)]
   struct Mod { vtable: &'static CppUserModBaseVTable, /* fields */ }
   ```
   Each entry is a Rust `extern "C"` function. UE4SS calls via the
   vtable; we receive the `this` pointer and dispatch normally. Fragile
   if UE4SS adds new virtuals between releases (the slot count
   changes), but doable. ~1-2 days plus a vtable layout audit per
   UE4SS release.
3. **(last resort) `cxx` or `bindgen` against the UE4SS C++ headers.**
   Most idiomatic but adds a real build-time dep on the UE4SS source
   tree. Generates Rust bindings for `CppUserModBase` and friends so
   Rust can implement the trait via `cxx`'s shim machinery. ~3 days
   plus header maintenance. Avoid unless (1) and (2) both fail.

Recommendation: ship (1). If UE4SS rejects it at runtime, fall to
(2) and document the vtable layout in source comments so future
maintainers can audit it against UE4SS releases.

## Migration sequence

Numbered for tracking. Each step is its own commit.

- [ ] **1.** Verify UE4SS for Grounded 2 actually loads CPPMods today.
  Smoke-test with a minimal Rust cdylib that exports `start_mod` and
  writes a single line to a log file. Drop in
  `<game>\Augusta\Binaries\Win64\Mods\HelloRust\dlls\main.dll`,
  launch, confirm the line appears. This is the gate; if it fails
  the whole plan is moot and we keep winhttp.
- [ ] **2.** Confirm whether the legacy free-function ABI works in
  the current UE4SS for this game. If yes -> path (1) above. If no,
  build a Rust-only vtable shim to satisfy the modern ABI -> path
  (2).
- [ ] **3.** Add `start_mod`/`uninstall_mod` exports to
  `better-backpack/src/lib.rs`. Move worker startup out of DllMain
  into start_mod. Drop the `wait_for_gobjects` retry loop -- UE4SS
  calls start_mod after engine init, so GObjects is already
  populated.
- [ ] **4.** Rename cdylib output `winhttp` -> `main`. Drop
  `winhttp.def`, the cc build dep, and the forwarder C file
  generation in `build.rs`. Drop the C build-dep entirely so the
  mod stays pure Rust + linker.
- [ ] **5.** Rewrite `deploy.ps1` to package the UE4SS mod folder
  layout. Default mode: zip with `BetterBackpack/dlls/main.dll`,
  `BetterBackpack/enabled.txt`, `BetterBackpack/settings.json` at
  the root.
- [ ] **6.** Update `BUILDING.md`, `README.md`, `FEATURES.md`,
  `PERFORMANCE.md` to reflect the UE4SS load model. The capability
  comparison table stays accurate -- only the distribution shape
  changed.
- [ ] **7.** In-game smoke test of the full mod under UE4SS: drop
  the new mod folder into `<game>\Augusta\Binaries\Win64\Mods\`,
  launch, confirm log shows the mod started and the patches landed.
- [ ] **8.** Archive the winhttp proxy material (Cargo.toml lib name,
  build.rs, winhttp.def, the proxy section of FEATURES.md) into a
  `archive/winhttp-proxy/` directory in case we ever want it back as
  a UE4SS-less fallback. Don't delete -- it's correct, working code.

## Risks / what could go wrong

1. **UE4SS for Grounded 2 may not be stable.** If it crashes, we
   silently lose users. Step 1 of the migration is the gate; if it
   fails, we don't proceed.
2. **The CPPMod ABI may have changed since the docs we read.** The
   legacy free-function ABI may be deprecated, and the modern
   `CppUserModBase` inheritance may require synthesizing a vtable in
   Rust (path 2). Fragility: if UE4SS adds new virtual methods, our
   hand-rolled vtable's slot count goes out of sync and we miscall.
   Mitigation: pin the UE4SS version in our docs, audit the vtable
   on every UE4SS release, document the layout in source comments.
3. **Game patches still break us.** UE4SS itself dumps the SDK and
   exposes reflection helpers, but our specific offsets
   (`InventoryComponent + 0x01E0`, `SurvivalComponent + 0x0140`,
   `WBP_InventoryInterface_C + 0x0430`) may still need refreshing
   per game patch. UE4SS reduces but does not eliminate this.
4. **UE4SS adds an install dependency.** Some users won't want it.
   The fallback "standalone DLL" build (winhttp proxy) stays in
   `archive/` so we can resurrect it if demand exists.

## Steelman (long form)

Reproduced from the chat transcript dated 2026-05-05. Eleven points
total; abridged:

1. **Distribution is solved.** Every modern UE game's scene
   converges on UE4SS-centric distribution within ~12 months.
   Grounded 2 in 2026 is on that trajectory. Shipping there means
   our mod auto-rides whatever Vortex extensions and modlist tools
   the wider scene builds.
2. **We're rebuilding what UE4SS has, badly.** Our SDK shim is
   correct for our two use cases. UE4SS's is correct for the entire
   UE5 surface. Maintenance hours we spend, UE4SS users don't.
3. **Game patches break us, not UE4SS users.** Centralized SDK
   updates beat per-mod offsets refreshes.
4. **Mod-author network effect.** Modders learn from other mods.
   Being inside the UE4SS ecosystem makes us copy-able and
   discoverable.
5. **The Vortex problem we hit isn't a Vortex bug.** It's the cost
   of being unconventional. UE4SS is the convention.
6. **Lua is fine for our perf profile.** Per `PERFORMANCE.md` we're
   well below frame-time visibility. Lua handles CDO patches and a
   dozen ProcessEvent hooks per frame trivially.
7. **CDO patches are better in Lua because users can audit them.**
   `:SetValue(orig * 0.5)` is self-documenting in a way `1.0 * 0.5`
   in a JSON file isn't.
8. **Rust over C++ was a good call. UE4SS over self-hosted DLL
   proxy is a different decision.** They're orthogonal. We keep
   Rust by compiling into a UE4SS CPPMod.
9. **UE4SS already shipped the hard parts of "config-driven UE
   mod."** Live mod reload, AssetDumper, Lua scripting console, ini
   conventions. We're rolling our own and getting nothing for it.
10. **Counterfactual: Vortex never works.** Writing our own Vortex
    extension is a project. Convincing other modders to adopt our
    schema is impossible. UE4SS is the path of least friction.
11. **Ship where users live.** UE5 modders live in UE4SS-land.
    Optimizing for engineering elegance of a hand-rolled DLL is
    optimizing the wrong thing for the user.
