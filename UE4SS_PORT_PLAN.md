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

## How UE4SS actually loads CPPMods

There is **only one supported ABI**: a C++ class derived from
`RC::CppUserModBase`, with two `extern "C"` exports that allocate and
free instances. There is no free-function shortcut path; an earlier
draft of this doc claimed one existed and was wrong.

The contract:

```cpp
extern "C" __declspec(dllexport) RC::CppUserModBase* start_mod();
extern "C" __declspec(dllexport) void uninstall_mod(RC::CppUserModBase* mod);
```

`start_mod()` returns a pointer to a heap-allocated subclass instance.
UE4SS holds that pointer for the mod's lifetime and calls into its
vtable for lifecycle events. `uninstall_mod()` is invoked at unload
and is expected to call `delete mod` (which fires the virtual
destructor).

The vtable shape (in declaration order in
`UE4SS/include/Mod/CppUserModBase.hpp`):

1. virtual destructor
2. `on_update()`
3. `on_unreal_init()` -- earliest point safe for UE reflection
4. `on_ui_init()`
5. `on_program_start()`
6-9. four deprecated `on_lua_*` overloads
10. `on_dll_load(StringViewType)`
11. `render_tab()`
12-15. four current `on_lua_*` overloads
16. `on_cpp_mods_loaded()`

Plus member fields: a `std::vector<std::shared_ptr<GUI::GUITab>>` and
five `StringType` (MSVC `std::wstring`) fields for ModName, ModVersion,
ModDescription, ModAuthors, ModIntendedSDKVersion.

## How we bridge that to Rust

**Decision: tiny C++ shim, mod logic stays in Rust.**

The shim's entire job is to be the `CppUserModBase` subclass UE4SS
needs and forward lifecycle calls into the Rust cdylib via two
`extern "C"` symbols:

```cpp
// shim.cpp
#include <UE4SS/Mod/CppUserModBase.hpp>

extern "C" void better_backpack_start();   // implemented in Rust
extern "C" void better_backpack_stop();    // implemented in Rust

class BetterBackpackMod : public RC::CppUserModBase {
public:
    BetterBackpackMod() {
        ModName = STR("BetterBackpack");
        ModVersion = STR("0.1.0");
        ModDescription = STR("Bigger backpack + survival rate tweaks");
        ModAuthors = STR("abix");
    }
    void on_unreal_init() override { better_backpack_start(); }
    ~BetterBackpackMod() override { better_backpack_stop(); }
};

extern "C" __declspec(dllexport)
RC::CppUserModBase* start_mod() { return new BetterBackpackMod(); }

extern "C" __declspec(dllexport)
void uninstall_mod(RC::CppUserModBase* mod) { delete mod; }
```

That's the entire C++ surface. ~30 lines, no logic in it -- it's
loader handshake only. Every byte of mod behavior (CDO patches,
hooks, scroll viewport, settings, log) stays Rust.

Build shape:

- **Rust cdylib** (existing crate, renamed) exports
  `better_backpack_start` / `better_backpack_stop`.
- **C++ shim file** compiled via the `cc` build dep we already use,
  linked into the same DLL as the Rust code.
- **UE4SS headers** consumed from a separate clone at
  `C:\code\RE-UE4SS` (set up out-of-band by the developer). The
  build documents the expected path and the commit pin. Reason we
  don't vendor as a git submodule: UE4SS itself transitively
  references `Re-UE4SS/UEPseudo.git` which is currently a 404, so
  recursive submodule init breaks. We only need UE4SS's headers, not
  its build, so a flat clone is sufficient.

### Why we don't link against UE4SS.dll

Naive shim would `#include <Mod/CppUserModBase.hpp>` and inherit. The
header marks the constructor and destructor `RC_UE4SS_API`, which
expands to `__declspec(dllimport)` in consumer builds. Linking
requires UE4SS's import library, which would mean building UE4SS,
which is currently blocked by the UEPseudo submodule rot.

Workaround: in our shim's translation unit, define `RC_UE4SS_API` as
empty *before* including UE4SS's headers. The constructor and
destructor are then declared as plain functions. We provide our own
empty-body definitions in the same translation unit:

```cpp
namespace RC {
    CppUserModBase::CppUserModBase() = default;
    CppUserModBase::~CppUserModBase() = default;
}
```

The compiler emits the base class's vtable in our object (since the
destructor is virtual and now-defined-here), with our `=default`
destructor in the appropriate slot. Field layouts match UE4SS's
because we used UE4SS's actual headers. The class behaves
identically to a "real" UE4SS-linked subclass at the ABI level UE4SS
cares about: vtable virtual dispatch + direct field access on
`ModName`/`ModVersion`/etc.

Constraint: this works as long as we compile with the same MSVC
toolchain + same CRT linkage as UE4SS itself ships. Modders are
expected to build mods in Release mode against UE4SS Release, which
is also our default. Document this assumption in the build doc.

Why not the other options:

- **Hand-rolled vtable in Rust.** Mirroring MSVC's vtable layout +
  `std::vector` + `std::shared_ptr` + `std::wstring` byte-for-byte
  is small to write but enormous to maintain. UE4SS adds a new
  `on_xxx_init` virtual in the next release and our slot 4 silently
  becomes slot 5. We crash on innocent UE4SS updates.
- **`cxx` / `bindgen` bindings.** Same UE4SS-headers dependency as
  the shim, more build complexity, no real gain.

The 30 lines of C++ don't compete with the 1500 lines of Rust for any
property worth defending. They're plumbing.

## Cost

Option 1 (the chosen path):
- Vendor UE4SS as a git submodule, pin the release.
- Add the shim `.cpp` file, ~30 lines.
- Extend `build.rs` to compile the shim alongside the existing
  forwarder generation (delete the forwarder generation as part of
  this work).
- Add two `#[no_mangle] extern "C"` symbols to `lib.rs` that drive
  the worker.
- ~1 day total.

## Migration sequence

Numbered for tracking. Each step is its own commit.

- [ ] **1.** Vendor UE4SS as a git submodule under
  `vendor/RE-UE4SS`. Pin to a known release (latest stable at port
  time). The shim only needs the headers under `UE4SS/include/`;
  we're not building UE4SS itself.
- [ ] **2.** Smoke-test that UE4SS for Grounded 2 actually loads
  CPPMods today. Build a minimal "hello" mod (the C++ shim from this
  doc + a Rust function that writes one line to a log file), drop it
  into `<game>\Augusta\Binaries\Win64\Mods\HelloRust\dlls\main.dll`
  (plus an empty `enabled.txt`), launch, confirm the line appears.
  This is the gate; if UE4SS for Grounded 2 is broken today, fall
  back to the winhttp proxy plan.
- [ ] **3.** Add the C++ shim source to `better-backpack/src/`.
  Extend `build.rs` to compile it via `cc::Build` against the
  vendored UE4SS headers and link the resulting `.obj` into the
  cdylib. Delete the winhttp forwarder generation from `build.rs`.
- [ ] **4.** Rename cdylib output `winhttp` -> `main`. Delete
  `winhttp.def`. Add two `#[no_mangle] extern "C"` Rust functions
  (`better_backpack_start`, `better_backpack_stop`) that the C++
  shim calls. Move worker startup out of `DllMain` into
  `better_backpack_start`. Drop the `wait_for_gobjects` retry loop
  -- UE4SS calls `on_unreal_init` after engine init, so GObjects is
  already populated.
- [ ] **5.** Rewrite `deploy.ps1` to package the UE4SS mod folder
  layout. Default mode: zip whose root is `BetterBackpack/`
  containing `dlls/main.dll`, `enabled.txt`, `settings.json`.
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
2. **UE4SS releases drift the `CppUserModBase` shape.** New virtual
   methods or new member fields in a UE4SS update mean the shim has
   to be rebuilt against the new headers. Mitigation: vendor UE4SS
   as a submodule pinned to a specific release, document the pinned
   version, and bump deliberately.
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
