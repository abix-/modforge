# grounded2mods - project state

## Current focus
RPG / level-up mod for Grounded 2. Loaded by UE4SS as a CPPMod
(C++ shim + Rust cdylib). Skill catalog is the single source of
truth; apply step writes skill values to game CDOs.

For docs see `docs/` (each file is authority on one subject).
Open work in `docs/todo.md`. History in `docs/changelog.md`.

Immediate gameplay pressure after movement tuning: add mitigation for
the new self-damage failure modes. High-speed builds can currently die
to fall damage and to collision / impact damage when slamming into
plants or terrain. SDK review showed fall damage should be handled on
`ASurvivalCharacter` fall fields (`bTakeFallDamage`,
`MinimumFallDamageVelocity`, `FallDamageRatio`) rather than through the
generic health damage hook. Current field-based patch of
`FallDamageRatio`, `bTakeFallDamage`, and
`MinimumFallDamageVelocity` is confirmed to apply, but it still does
not fully suppress fall damage. A direct `ApplyFallDamage()` / base
`Character.OnLanded` hook attempt installed but never fired. Current
best explanation is that `ProcessEventHook` matches exact live vtables,
while the player pawn is a concrete `BP_SurvivalPlayerCharacter_*`
subclass. The concrete-BP hook pass works: logs show `OnLanded`
suppression on the live player pawn. But the player still takes fall
damage, so `OnLanded` is not the damaging seam.

Validated in-game: at level 100 every fall-damage field surface we
patch reports a successful write (3 player CDOs + 1 live pawn for the
per-character fields, 8 `USurvivalGameModeSettings` CDOs for the
per-game-mode multiplier, 3 `USurvivalModeManagerComponent` instances
for the replicated `FCustomGameModeSettings` struct at +0x130). BP
`OnLanded` is suppressed on each landing. **Player still takes fall
damage.** Native fall code does not read any BP-exposed field we have
located. `ApplyFallDamage` UFunction also never fires via ProcessEvent
during a natural fall (engine calls the native fn pointer directly).

Calling `UpdateCustomSettings` UFunction (the in-game difficulty UI's
own setter, `Final, Native, BlueprintCallable`) on the live mode-manager
component via ProcessEvent dispatched cleanly and ran
`OnRep_CustomSettings` -- still no effect on fall damage. So the entire
field-write surface is dead.

Damage trace findings:
- Fall damage fires `MulticastHandleEffectsWithDamageFlagsAtOwnerLocation`
  with `LastDamageInfo` entirely empty (DamageType=null, instigator=null,
  source=null, hit=(0,0,0), flags=0). Native code writes `CurrentDamage`
  directly, bypassing the standard `FDamageInfo` pipeline.
- Plant collision fires the same multicast but with
  `LastDamageInfo.DamageType = BP_EnvironmentalDamage_C`, `src_type=2`.
  That is the discriminator and gives us a clean filter for
  Collision / Impact Damage Resistance as a separate skill.
- `before/after CurrentDamage` snapshot around `original.call` produced
  no delta line on a controlled fall (delta == 0). Damage is committed
  upstream of the multicast. Multicast UFunction flags include `Const`,
  confirming it cannot apply damage. Multicast is purely a notification.

Next pass: walk the fall backwards. Broaden the `fall_hook` PE hook on
`BP_SurvivalPlayerCharacter_*` to log every PE event on the BP class
during one fall. Goal is to identify any PE-reachable surface between
`OnLanded` (we suppress) and the multicast (already hooked) -- e.g.
`MulticastFallEffects`, BP-bound damaged delegate handler,
`NotifyOnLandAnimBegin`. If anything fires in that window we may be
able to do a same-frame restore of `CurrentDamage` (no flicker -- UI
does not render between synchronous native calls in one tick).
Same-frame heal-back is back on the table; only deferred / next-frame
heal-back is rejected. If the window has no PE-reachable surface, the
fallback is the native function detour on
`ASurvivalCharacter::ApplyFallDamage` or `UHealthComponent::ApplyDamage`.

Collision / impact damage is now its own skill scoped behind the
`BP_EnvironmentalDamage_C` filter on `LastDamageInfo.DamageType`.

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
     **Hook installs in-game**, log shows
     `inv hook: installed on WBP_InventoryInterface_C` once inventory UI
     loads.
- [x] 8. Trace surfaces in inv_hook.rs are already gated under
     cfg!(debug_assertions). Broader BPF/grid/menu trace coverage from
     the C++ build was intentionally not ported, it was the dominant
     hot-path cost per the audit, and the cached UFunction* identity
     dispatch makes it unnecessary in normal operation.
- [ ] 9. Side-by-side parity test C++ vs Rust DLL.
- [ ] 10. Archive better-backpack-cpp/.
- [x] 11. Rust BUILDING.md at repo root. Prerequisites, build, run,
     quality gates, configuration knobs, retargeting via offsets.rs.

## Build commands
- `cargo build --release` builds both crates.
- `cargo test --release` runs layout tests.
- `cargo clippy --release --all-targets, -D warnings` lint gate (clean today).
- Outputs: `target/x86_64-pc-windows-msvc/release/{winhttp.dll, inject.exe}`.
  The mod cdylib is named `winhttp.dll` so it doubles as a Windows DLL
  proxy at install time (drop into game's Binaries\Win64; Windows
  preferentially loads our copy via DLL search order; the 70 forwarder
  exports defined in `better-backpack/winhttp.def` redirect WinHTTP
  calls to `winhttp_orig.dll`, which is a copy of the system winhttp).
- The DLL is locked while the game holds it, rebuild requires the game to
  be closed (or use a different output dir).
- inject.exe with no args looks for `winhttp.dll` next to itself
  (matches cdylib output name). Pass an explicit path to override.

## Logs
- Injector: `<inject.exe dir>/inject.log`, truncated each run.
- Mod: `<DLL_dir>/better_backpack.log`, truncated each DLL load.
  First-line tell for the Rust build is
  `=== Better Backpack DLL (rust) ===`.

## Settings
- `<DLL_dir>/settings.json` (optional; for UE4SS installs this is
  `Mods/BetterBackpack/dlls/settings.json`). Schema in
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
    dlls/settings.json
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
- docs/todo.md item 1 step 8 (archive winhttp proxy material).
- docs/todo.md item 2 (project rename) and items 3-7 (new feature
  multipliers).

## RPG pivot (2026-05-05)

Direction shift: turning the mod into a Factorio-RPG-style
level-up mod. Kills -> XP -> levels -> skills that drive the
existing CDO patches. Research questions R1-R5 answered against
the SDK at `C:\tools\work\sdk\`, see docs/todo.md section 0.

### Spike B: persistence working (2026-05-05)

PlaythroughGuid resolves at runtime. First attempt used
`USaveLoadManager.SaveInProgressSaveGameHeaderData` (+0x90) but
that's null except during an active save operation. Switched to
`AInGameGameState.PlaythroughGuid` at +0x32C
(`Maine_classes.hpp:28544`), populated for the duration of
the active session, exactly what we need.

Files:
- `rpg/save_slot.rs`: walks GObjects for an InGameGameState
  instance (skip CDO), reads PlaythroughGuid as 32-char hex.
- `rpg/state.rs`: PlayerState (kill_count, last_killed) with
  serde JSON load/save under `<DLL_dir>/saves/<guid>.json`.
- `rpg/tracker.rs`: in-process state with lazy slot resolution
  (since the save isn't loaded at worker startup).

In-game test confirmed: kill -> "no prior save for slot=06d9929b"
-> "saved kill #1" -> file written. Reload test pending.

### Eager state load on world entry: DONE (2026-05-05)

`rpg/world_loader.rs` spawns a 1Hz poller from worker init
that watches `save_slot::current_slot_key` and calls
`tracker::activate_slot` / `deactivate_slot` on transitions.
Handles save-swap (Some(a) -> Some(b)) too.

Tracker refactored: kill recording no longer lazy-resolves the
slot. If no slot is bound it logs+drops; in practice the
loader activates within 1s of world entry, well before the
player enters combat. State.rs collapsed to a simple
load_one(slot), loader owns slot resolution.

Future skill-driven CDO/instance reapply will plug into the
activation transition: when activate_slot fires with a freshly
loaded PlayerState, walk the player CDO + live pawn instances
and apply current skill multipliers. Stubbed until skills exist.

### Buggy kill attribution + XP layer: DONE (2026-05-05)

`kill_hook.rs::classify` returns three buckets via class-name
inspection (no UFunction calls; pure pointer-walks):
- Player: instigator class chain contains "PlayerController".
- Buggy: instigator (or its possessed Pawn at +0x308) class
  chain contains "Buggy".
- Other: enemy-vs-enemy AIC; logged + dropped.

Confirmed in-game: PLAYER on Grub kills,
BUGGY on Spiderling killed by `AIC_AntSoldier_Augusta_Buggy_C`,
no false positives. Multiplayer ownership question (other
players' Buggies) deferred, single-player works correctly.

XP layer landed alongside: `rpg/xp.rs` (100 * N^1.8 cumulative
curve, cap 50, ~20-species placeholder table). PlayerState
schema bumped to (xp, level, skill_points, skill_ranks)
backwards-compatibly via `#[serde(default)]`. tracker awards
XP on kill, recomputes level, grants skill points on level-up.
buggy_kill_xp_multiplier setting (default 1.0) scales Buggy
kills.

Open items for the loop:
- Apply step: BUILT 2026-05-05 in `rpg/apply.rs`. Captures
  vanilla survival rates at init; at activate_slot, writes
  skill-layered values (settings_base + skill_bonus, or
  vanilla * settings_mult * skill_mult) to CDOs.
- Skill catalog: BUILT 2026-05-05 in `rpg/skills.rs`. Three
  skills (backpack, hunger, thirst). Per-rank math:
  backpack +5/rank max 12, hunger/thirst -7.5%/rank max 10.
- ImGui tab via `register_tab` in the C++ shim: DONE
  (2026-05-05). Vendored upstream ocornut/imgui v1.92.1 into
  `better-backpack/cpp/imgui/` (matches UE4SS's version), wired
  into build.rs as 4 .cpp sources alongside shim.cpp. Forward-
  declared `RC::UE4SSProgram::get_current_imgui_context` and
  `get_current_imgui_allocator_functions` with `RC_UE4SS_API`
  (dllimport, resolves through UE4SS.lib at link). Lambda calls
  `rpg_enable_imgui()` to point our linked imgui at UE4SS's
  context, then renders Level / XP bar / skill rows with `+1` /
  `+10` buttons.

  C-ABI surface in `better-backpack/src/rpg/ffi.rs`: 8 functions
  the lambda calls (has_active_slot, get_level, get_xp,
  get_xp_for_current_level, get_xp_for_next_level,
  get_skill_points, get_skill_count, get_skill, spend).
  Each wrapped in catch_unwind so a Rust panic can't take down
  UE4SS's render thread.

  Symbol mangling gotcha (resolved): UE4SS exports
  `register_tab` as a *protected* method
  (`CppUserModBase.hpp:212`). MSVC C++ name mangling encodes
  access (Q=public, I=protected). First attempt with public
  caused LNK2019; moved to protected section of our mirror.

  In-game confirmed: tab visible, live XP updates after kills,
  Buggy attribution + persistence loop working across launches.

Settings as base, skills layered on top: settings.json defaults
flipped to vanilla (slot_count=40, hunger/thirst_mult=1.0).
User can override defaults if they want a starter buff. Skill
ranks then layer on top: backpack target = settings.slot_count
+ 5*rank; survival target = vanilla * settings_mult * skill_mult.

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
`survival patch: scanned_classes=0, patched=0`, the existing
backpack/hunger/thirst patches may be running before GObjects is
fully populated, or there's been an SDK shape change. Not
related to RPG track. Investigate when convenient.

### Movement skill fix verified

Manual test confirmed Move Speed now works in-game.

Fix was two parts:

- Retarget movement writes to include Grounded-specific fields on
  `UMaineCharMovementComponent`, including
  `CustomGroundSpeedMultiplier` (+0x1198),
  `CustomFlySpeedMultiplier` (+0x119C),
  `CustomSwimSpeedMultiplier` (+0x11A0), and
  `MaxSwimSprintSpeed` (+0x1164).
- Mirror movement writes onto live player pawns, not just player CDOs.

This closes the earlier suspicion that generic UE movement caps alone
were insufficient for Grounded 2 locomotion.

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
