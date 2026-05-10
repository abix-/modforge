# UE4SS port plan

> **Authoritative on:** the pivot to UE4SS C++ mod (CPPMod) shape.
> Why we ride on UE4SS, the C++ shim design, the
> CppUserModBase mirror, the build setup. The pivot is complete;
> this is kept as design history.

Replaced the original winhttp.dll proxy + custom Vortex packaging
approach. The proxy is preserved at
[`../archive/winhttp-proxy/`](../archive/winhttp-proxy/) as a tested
fallback if UE4SS ever turns out unstable for Grounded 2.

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
  `performance.md`, this mod is invisible to a frame profile. We
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

UE4SS for Grounded 2 lives at:

```
<game>\Augusta\Binaries\WinGRTS\
  dwmapi.dll                  (UE4SS proxy itself)
  ue4ss\
    UE4SS.dll
    UE4SS-settings.ini
    Mods\
      mods.txt                (registration list)
      BPModLoaderMod\         (existing builtin mods)
      ConsoleEnablerMod\
      ...
```

Note the path is `WinGRTS` (the Steam platform identifier, matching
`Grounded2-WinGRTS-Shipping.exe`), not `Win64`. Earlier drafts of
this doc had `Win64`; corrected.

Mod registration is via `mods.txt` (one line per mod, `ModName : 1`
to enable). UE4SS does not use per-mod `enabled.txt` files.

Our zip needs the path mirror so Vortex deploys correctly:

```
zip-root/
  Augusta/
    Binaries/
      WinGRTS/
        ue4ss/
          Mods/
            BetterBackpack/
              dlls/
                main.dll
              dlls/settings.json
```

`mods.txt` registration is handled by Vortex's UE4SS extension on
deploy (it merges entries from each installed mod). For manual
installs the README instructs the user to append
`BetterBackpack : 1` to `mods.txt`.
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
  (`<DLL_dir>\better_backpack.log`, next to `main.dll`).
- Performance characteristics. `performance.md` numbers don't move
  meaningfully, we're still doing one CDO patch + one ProcessEvent
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
3. `on_unreal_init()`, earliest point safe for UE reflection
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

That's the entire C++ surface. ~30 lines, no logic in it, it's
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

### Linking against UE4SS.dll

UE4SS.dll itself is shipped to end users with **all** `CppUserModBase`
symbols exported (verified via `dumpbin /exports` against
`<vortex_install>\ue4ss\UE4SS.dll`):

- `??0CppUserModBase@RC@@QEAA@XZ`, constructor
- `??1CppUserModBase@RC@@UEAA@XZ`, virtual destructor
- `?on_update@CppUserModBase@RC@@UEAAXXZ`, and similar for every
  base virtual

So we don't need to build UE4SS at all. We generate an import library
from the live `UE4SS.dll`:

```
dumpbin /exports UE4SS.dll > exports.txt   # extract names
lib /def:UE4SS.def /out:UE4SS.lib /machine:x64
```

The `.def` is auto-generated from the `dumpbin` output. We commit
both `UE4SS.def` and `UE4SS.lib` to the repo (the lib is small;
mostly a name table). Build script regenerates them when the user
points at a fresh UE4SS.dll.

Our shim then `#include <Mod/CppUserModBase.hpp>` normally and
inherits. No `RC_UE4SS_API` games. No layout-stub workaround. The
linker resolves the imports at our DLL build time; Windows resolves
them against the running UE4SS.dll at game load time.

The earlier "define RC_UE4SS_API to empty + provide stubs" plan is
abandoned, it would have worked but it's strictly worse than
linking against the real DLL.

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

- [x] **1.** Cloned `https://github.com/UE4SS-RE/RE-UE4SS.git` to
  `C:\code\RE-UE4SS` for the headers (out-of-band; submodule attempt
  failed because UE4SS's own `.gitmodules` references a 404'd
  `Re-UE4SS/UEPseudo.git`). We don't need UE4SS's nested submodules
 , only the headers under `UE4SS/include/` and the live
  `UE4SS.dll` for the import library. Document the expected path in
  building.md and skip vendoring.
- [x] **2.** Generated `UE4SS.lib` from the live UE4SS.dll at
  `<vortex>\grounded2\mods\UE4SS_Grounded2-52-1-0-2-1771968923\Augusta\Binaries\WinGRTS\ue4ss\UE4SS.dll`
  via `dumpbin /exports` -> `.def` -> `lib /def:`. 3756 mangled
  symbols total, 1.9 MB lib. Committed both `UE4SS.def` and
  `UE4SS.lib` to `better-backpack/ue4ss/`.
- [x] **3.** Added `cpp/shim.cpp` (~110 lines including comments,
  ~30 lines of actual code). Forward-declares `GUI::GUITab` and
  `LuaMadeSimple::Lua` so the shim doesn't pull in imgui or the full
  UE4SS header tree. Mirrors `RC::CppUserModBase` layout exactly,
  marks the constructor + virtual destructor + 12 inline base
  virtuals with `__declspec(dllimport)` so they resolve from
  UE4SS.lib. Subclasses as `BetterBackpackMod`, overrides
  `on_unreal_init` to call into Rust, exports `start_mod` and
  `uninstall_mod`. `build.rs` compiles the shim via `cc::Build` and
  links against UE4SS.lib.
- [x] **4.** Renamed cdylib `winhttp` -> `main` (so the artifact is
  `main.dll`, the path UE4SS expects under
  `Mods/<ModName>/dlls/main.dll`). Replaced the winhttp forwarder
  generation in `build.rs`. Added `extern "C" fn
  better_backpack_start()` / `better_backpack_stop()` to `lib.rs`.
  `DllMain` shrunk to just capture HMODULE. Worker spawned from
  `better_backpack_start` instead of DllMain. `wait_for_gobjects`
  retry loop deleted, UE4SS calls `on_unreal_init` only after
  the engine has finished initializing.
  **Verified `main.dll` (244 KB) builds clean, exports `DllMain`,
  `better_backpack_start`, `better_backpack_stop`, `start_mod`,
  `uninstall_mod` (per `dumpbin /exports`).**
- [x] **5.** Rewrote `deploy.ps1` for the UE4SS mod folder layout.
  Three modes:
  - Default `-Package`: produces a Vortex-installable zip at
    `dist\better-backpack-v<version>.zip` with the contents at
    `Augusta/Binaries/WinGRTS/ue4ss/Mods/BetterBackpack/{dlls/main.dll,
    dlls/settings.json, README.txt}`. Generated zip is 132 KB.
  - `-Install`: auto-detects the local Steam install, verifies UE4SS
    is present, copies `main.dll` and `dlls/settings.json` into the live
    Mods folder, appends `BetterBackpack : 1` to `mods.txt` if it
    isn't already there.
  - `-Uninstall`: removes the BetterBackpack folder and strips its
    line from `mods.txt`.
- [ ] **6.** Update `building.md`, `README.md`, `features.md`,
  `performance.md` to reflect the UE4SS load model. The capability
  comparison table stays accurate, only the distribution shape
  changed.
- [/] **7.** In-game smoke test under UE4SS. **Partially done.**
  - UE4SS DOES recognize our mod, `UE4SS.log` shows
    `Starting C++ mod 'BetterBackpack'` cleanly.
  - But the game **crashes** during early init when our mod is
    loaded. With `deploy.ps1 -Uninstall`, the game launches fine,
    so the crash is in our mod, not UE4SS or Grounded.
  - **Suspected cause:** layout mismatch between our hand-rolled
    `RC::CppUserModBase` mirror in `cpp/shim.cpp` and UE4SS's
    actual class layout. We mirror the vtable + member fields, but
    UE4SS's `CppUserModBase::CppUserModBase()` (imported from
    UE4SS.lib) writes through the parent layout when we
    `new BetterBackpackMod()`. If our mirror has wrong virtual
    count, wrong field order, or wrong-sized STL types, the parent
    ctor corrupts adjacent memory.
  - **Open suspects** (debug next session):
    - Our mirror declares 12 virtuals; the real header has 14
      (we're probably missing two of the `Lua*` pointer overloads
      and/or `on_cpp_mods_loaded`).
    - Field order / sizes in our mirror.
    - C++ runtime config, `cc::Build` may default to `/MT`
      while UE4SS ships built against `/MD`. CRT mismatch could
      explain heap corruption when the parent ctor's `std::wstring`
      members are constructed.
  - **Debug plan:**
    1. Write to a debug log at the very top of `start_mod()` before
       the `new` to confirm we reach the export.
    2. Wrap `new BetterBackpackMod()` in try/catch.
    3. Audit the mirror against the real header byte-for-byte.
    4. Force `/MD` in `cc::Build` if not already.
    5. As a last resort, include UE4SS's real headers (resolve the
       imgui dep by stubbing or vendoring).
- [ ] **8.** Archive the winhttp proxy material (winhttp.def,
  forwarder build.rs, winhttp section of features.md) into a
  `archive/winhttp-proxy/` directory in case we ever want it back as
  a UE4SS-less fallback. Don't delete, it's correct, working code.

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
6. **Lua is fine for our perf profile.** Per `performance.md` we're
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
