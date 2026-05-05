# TODO

Current state: Rust port of the mod is feature-complete on the runtime
side. Open work is **distribution**: switching from "drop a winhttp.dll
proxy in the game folder" to "ship as a UE4SS C++ mod, but keep the
mod source 100% Rust." Plan in [UE4SS_PORT_PLAN.md](UE4SS_PORT_PLAN.md).

## 0. URGENT: fix UE4SS load crash

**Current bug.** `main.dll` builds, deploys, UE4SS loads it
(`UE4SS.log` line 9: `Starting C++ mod 'BetterBackpack'`), then
the game crashes during early init. Without our mod
(`deploy.ps1 -Uninstall`) the game launches fine. The crash is in
our mod, not UE4SS or Grounded.

Suspect: our hand-rolled `RC::CppUserModBase` mirror in
`cpp/shim.cpp` doesn't match UE4SS's actual class layout.
`RC::CppUserModBase::CppUserModBase()` is imported from UE4SS.lib
(verified via `dumpbin`). When we `new BetterBackpackMod()` runs
`new`, the parent constructor inside UE4SS.dll writes through what
it thinks is the parent layout. If our mirror has the wrong virtual
count, wrong field order, or wrong-sized STL types, UE4SS's ctor
scribbles past where it should and we crash later when something
touches that memory.

### Top suspects, in order of likelihood

1. **Virtual count mismatch.** Our mirror declares 12 virtuals
   (`on_update`, `on_unreal_init`, `on_program_start`, four
   `on_lua_*` overloads, `on_dll_load`, `render_tab` -- plus the
   destructor). The real header at
   `C:\code\RE-UE4SS\UE4SS\include\Mod\CppUserModBase.hpp` has 14
   virtuals. We're missing at least:
   - `on_ui_init()`
   - `on_cpp_mods_loaded()`
   - possibly the `Lua*` (pointer, single) overloads of
     `on_lua_start` / `on_lua_stop`.
   Wrong virtual count means our derived class's vtable doesn't
   line up with UE4SS's expectations: a virtual call UE4SS makes at
   slot N hits the wrong function in our class. Re-read the source
   header verbatim and reproduce all 14 virtuals in declaration
   order.

2. **CRT config mismatch.** `cc::Build` defaults to dynamic CRT on
   MSVC release builds (`/MD`), but verify. UE4SS itself was built
   with the same MSVC release CRT. Mismatched CRT = mismatched
   `std::wstring`, `std::vector`, `std::shared_ptr` layouts =
   immediate corruption when UE4SS's ctor initializes our parent
   members. Add an explicit `.flag("/MD")` or
   `.static_crt(false)` to the `cc::Build` invocation in
   `build.rs` to force.

3. **Field order or STL type size drift.** Even with matching CRTs,
   if our mirror has the fields in the wrong order or uses
   different types (e.g., `std::wstring` vs UE4SS's `StringType`
   when `FORCE_U16` is set in their build), UE4SS writes wrong
   addresses. Verify our protected `vector<shared_ptr<GUITab>>`
   comes BEFORE the public `StringType` fields, in the same order
   as the real header.

### Debug sequence

1. **Confirm we reach `start_mod()`.** Add an `OutputDebugStringW`
   at the very top of the exported function (before the `new`).
   Run with DebugView (sysinternals) attached and confirm the
   string fires. If it doesn't, the export isn't getting called and
   the problem is earlier (mod folder layout, mods.txt, DLL load).
2. **Wrap `new BetterBackpackMod()` in try/catch.** If the parent
   ctor throws (e.g., bad alloc when corrupted), we'll log it
   instead of crashing silently.
3. **Audit the mirror byte-for-byte** against the real header. Diff
   the virtual list, member fields, and field order.
4. **Force CRT linkage.** Add `.flag("/MD")` to the `cc::Build`
   call in `build.rs`. Verify the resulting object linked
   `MSVCRT.lib` not `LIBCMT.lib` via `dumpbin /imports`.
5. **`sizeof(CppUserModBase)` cross-check.** Have the shim's
   `start_mod()` print `sizeof(RC::CppUserModBase)` to a log file
   on first call. Compare against a known-good value computed from
   UE4SS's header.
6. **Last resort: include UE4SS's real headers.** Resolve the
   imgui transitive include by either downloading imgui to a known
   path (UE4SS pulls `deps/third` which we don't have) or stubbing
   the imgui types we don't use.

**Fix this before any other UE4SS work.** Without it the mod
literally doesn't run -- everything else in this TODO is blocked.

## 1. Repackage as a UE4SS CPPMod

Why: see `UE4SS_PORT_PLAN.md` (steelman in 11 points). Short
version: UE4SS is the convention for UE5 game mods, distribution
via Vortex is already solved on that path (UE4SS for Grounded 2 is
Vortex mod #52), and we delete our winhttp proxy forwarders +
setup.ps1 + winhttp_orig.dll dance.

Source language stays Rust. UE4SS's CPPMod ABI is C++ inheritance,
so we add a ~30-line C++ shim that derives from
`RC::CppUserModBase` and forwards lifecycle calls to two
`extern "C"` Rust functions. Mod logic stays Rust.

Earlier drafts of this plan claimed there was a "legacy free-function
CPPMod ABI" we could use to stay 100% Rust. There isn't. The
inheritance ABI is the only path. The 30 lines of C++ are loader
handshake -- they don't compete with the 1500+ lines of Rust mod
logic for any meaningful property.

Sequence (full detail in `UE4SS_PORT_PLAN.md`):

- [x] Step 1: Clone RE-UE4SS to `C:\code\RE-UE4SS` for headers.
  (Submodule attempt blocked by upstream's broken UEPseudo
  reference.)
- [ ] Step 2: Generate `UE4SS.lib` import library from the user's
  installed `UE4SS.dll` via `dumpbin /exports` -> `.def` ->
  `lib /def:`. Verified the DLL exports the symbols we need
  (`??0CppUserModBase@RC@@QEAA@XZ`, virtual destructor, all base
  virtuals).
- [ ] Step 3: Add the C++ shim source. Extend `build.rs` to compile
  it via `cc::Build` against the headers in `C:\code\RE-UE4SS` and
  link against `UE4SS.lib`. Drop the winhttp forwarder generation.
- [ ] Step 4: Rename cdylib output from `winhttp` to `main`. Add
  two `#[no_mangle] extern "C"` Rust entry points
  (`better_backpack_start`, `better_backpack_stop`). Move worker
  startup out of `DllMain` into `better_backpack_start`. Drop
  `wait_for_gobjects` -- UE4SS calls our `on_unreal_init` after
  the engine has finished initializing.
- [ ] Step 5: Rewrite `deploy.ps1` for the UE4SS mod folder layout.
  Default mode produces a zip mirroring
  `Augusta/Binaries/WinGRTS/ue4ss/Mods/BetterBackpack/`.
- [ ] Step 6: Update `BUILDING.md`, `README.md`, `FEATURES.md`,
  `PERFORMANCE.md` to reflect the UE4SS load model.
- [ ] Step 7: In-game smoke test under UE4SS.
- [ ] Step 8: Archive the winhttp proxy material to
  `archive/winhttp-proxy/`. Keep it as a tested fallback in case
  UE4SS turns out unstable for Grounded 2.

The current winhttp.dll proxy work (already shipped, commits
514e2b1..bfb3447) is **not wasted**: it's the tested fallback.
Archive, not delete.

## 2. Rename the project

`better-backpack` no longer describes what we're building. The mod is
turning into a sandbox-tweaks toolkit -- backpack capacity is one of
many JSON-configurable knobs, alongside hunger/thirst rates,
upcoming gear durability, and the queue of Player-Tweaks-style
features below. Pick a name that reflects "everything is a slider".

Candidates to consider (final pick TBD):
- `g2-sandbox` -- implies the configurable, save-the-game-yourself feel.
- `g2-tweaks` -- accurate, generic.
- `grounded2-tweaks` -- explicit about the game.
- `bigger-better` / `bigger-better-grounded` -- callback to the
  original Bigger Backpack lineage.
- `groundwork` -- pun on Grounded.

When the rename happens, update:
- Repo name (rename on GitHub, update remote in local clones).
- Crate package name (`Cargo.toml` -> `[package] name`).
- Workspace member dir (`better-backpack/` -> new name).
- Settings file is fine to keep as `settings.json` (next to the DLL).
- Branding strings inside the DLL (`ModName`, console title, log
  header).
- All docs (README, BUILDING, FEATURES, PERFORMANCE, TODO,
  UE4SS_PORT_PLAN, project_state).

## 3. Gear durability tweak

User-facing: a multiplier on how fast equipped gear takes damage from
use. Same shape as the existing thirst / hunger multipliers. Default
0.5 means gear lasts twice as long; 0.0 means gear never breaks.

Lives in `settings.json`:

```json
{
  "survival": {
    "gear_durability_multiplier": 0.5
  }
}
```

Implementation outline:

- Find the relevant CDO field. Search Dumper-7 SDK for "Durability",
  "DurabilityRate", "DurabilityLoss", "WearRate" or similar floats on
  weapon / tool / armor item classes. Likely one of:
  - `UItemComponent` or `UEquipableComponent` with a per-second wear
    rate
  - A multiplier on attack/use that decrements item durability
  - Something in a survival or crafting subsystem
- If the field is a single float on a base class, patch it the same
  way `survival.rs` patches `ThirstSettings.AdjustmentPerSecond`.
- If it's a per-item-type table (each weapon defining its own rate),
  walk every CDO that has the field and apply the multiplier.
- Add a `gear.rs` module mirroring `survival.rs`. Plumb the new
  multiplier through `settings.rs`.

Open question: does the game even use a per-second decay model, or
is durability purely per-use (each swing, each block)? If per-use,
we may need to scale the per-action damage instead of a per-second
rate.

## 4. Enemy health multiplier

User-facing: scale the max health of every enemy in the world.
Default 1.0 = vanilla; 0.5 = half-health (faster kills); 2.0 =
twice as tanky (harder fights). Settings.json key:

```json
{
  "combat": {
    "enemy_health_multiplier": 1.0
  }
}
```

Implementation outline:

- Find the health-component CDO field. Search Dumper-7 SDK for
  "Health", "MaxHealth" floats on enemy character base classes.
  Likely candidates:
  - A `UHealthComponent` or `UDamageComponent` on
    `BP_SurvivalNonPlayerCharacter` (or similar enemy base).
  - `MaxHealth` directly on the character class.
  - A health curve indexed by level.
- Critical decision: scale `MaxHealth` *only*, or also scale
  `CurrentHealth` to keep ratio? Game probably initializes
  `CurrentHealth = MaxHealth` at spawn, so patching CDO's MaxHealth
  is enough for newly-spawned enemies.
- Player must be excluded. Use the same pattern as `patch.rs`'s
  player-only filter: walk only CDOs whose full name does NOT
  contain `BP_SurvivalPlayerCharacter`.
- Add `combat.rs` module. Plumb through `settings.rs`.

Open questions:
- Does enemy health replicate from server? In multiplayer this only
  takes effect for hosts (same caveat as hunger/thirst).
- Does the game scale enemy health by player level / progression? If
  so, our static multiplier interacts non-linearly. May need to
  document or tune.

## 5. Enemy damage multiplier

User-facing: scale how much damage enemies deal to the player.
Default 1.0 = vanilla; 0.5 = enemies hit half as hard (forgiving);
2.0 = enemies hit twice as hard (challenge run). Settings.json key:

```json
{
  "combat": {
    "enemy_damage_multiplier": 1.0
  }
}
```

Implementation outline:

- Find the damage source. Likely candidates:
  - A per-enemy `BaseDamage` or `AttackDamage` float on attack
    components (one per attack type).
  - A per-attack-spec field on attack data tables.
  - A global damage multiplier in a survival config.
- The most surgical approach is a *per-enemy* attack-component CDO
  patch -- walk enemies, find their attack-component CDO, multiply
  the damage field. Keeps player attacks untouched.
- Add to `combat.rs` (same module as enemy health from item #4 -- they
  scan the same CDO tree).

Open questions:
- Some attacks compute damage via the gameplay-ability system rather
  than a static field. Those may need a different approach (e.g.
  hooking the damage application function via ProcessEvent).
- Attribute-vs-flat: most UE games store base damage as a float and
  apply multipliers from buffs / level. Patching base only is the
  cleanest -- multipliers stay vanilla.

## 6. Flying / gliding speed

User-facing: scale how fast the player moves while gliding (the
dandelion / leaf glider mechanic in Grounded 2). Default 1.0 = vanilla;
higher = faster flight; lower = slower. Settings.json key:

```json
{
  "movement": {
    "glide_speed_multiplier": 1.0
  }
}
```

Implementation outline:

- Caites' Player Tweaks already touches `MaxFlySpeed` (1600 -> 1900),
  so the field exists and is reachable. Find it in the SDK:
  - Search Dumper-7 dump for "FlySpeed", "MaxFlySpeed", "GlideSpeed",
    "AirSpeed".
  - Likely on a `UCharacterMovementComponent` subclass owned by the
    player character, OR on a glider-specific component.
- Apply multiplier the same way as the existing patches: walk player
  CDOs, multiply the field, log before/after.
- May need to also touch acceleration / velocity caps if the visible
  effect is gated by something other than the raw speed.
- Add a `movement.rs` module. Plumb through `settings.rs`.

If the field is the same one Caites uses (sprint / walk / swim live
on the same component), tackle this together with the other movement
multipliers from #6 below to avoid scanning the same CDOs twice.

## 7. (later) Port more Player Tweaks features

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
