# TODO

Current state: UE4SS C++ mod loads cleanly in-game (2026-05-05).
Backpack + hunger/thirst patches working. Distribution path
through UE4SS / Vortex is settled.

**New direction (2026-05-05): turn this into an RPG / level-up
mod.** Inspired by Factorio's RPG-style level-up mods. Grounded 2
has no native leveling system, so we add one: kill enemies -> earn
XP -> level up -> spend points on upgrades that surface as our
existing CDO patches (backpack capacity, hunger/thirst rate, glide
speed, gear durability, etc.). The current "everything is a slider
in settings.json" model becomes the *output* of the level system,
not the user-facing knob.

## 0. RPG / level-up system (NEW HEADLINE FEATURE)

This is now the project. Items 3-7 below (gear durability, enemy
health/damage, glide speed, Player Tweaks ports) become *upgradeable
stat surfaces* that level perks drive, instead of independent
sliders.

### Vision

- Player kills enemies -> XP awarded based on enemy type / difficulty.
- XP threshold per level (curve TBD: linear, polynomial, etc.).
- On level-up, player gets N perk points.
- Spend perk points on upgrades. Each upgrade = a function of level
  applied to one of our existing CDO-patch surfaces:
  - Backpack capacity (40 base, +5 per rank, max rank 12 -> 100).
  - Hunger drain rate (1.0 base, -5%/rank, max rank 10 -> 0.5x).
  - Thirst drain rate (same shape).
  - Glide speed (1.0 base, +5%/rank).
  - Gear durability loss (1.0 base, -5%/rank).
  - Damage dealt by player (later -- needs more research).
  - Damage taken from enemies (later).
  - Stamina regen / sprint speed / swim speed (later, from Player
    Tweaks port queue).
- Persist XP / level / perk allocation per save slot.
- Show level / XP / next-perk in a UE4SS imgui tab (start). Later:
  in-world UMG overlay.

### Research questions (BLOCKING -- must answer before coding)

These are unknowns. Each one has to be answered in-game with
Dumper-7 + UE4SS Live View + ProcessEvent traces before we write
RPG code. None are speculative; they're concrete things to look up.

**R1. Kill detection.**
  - Which UFunction fires on enemy death? Candidates from typical
    UE5 survival games:
    - `OnDeath` / `OnDied` event on a `UHealthComponent`.
    - `Die` / `HandleDeath` method on the enemy character class.
    - A damage-dispatch function on `BP_SurvivalNonPlayerCharacter`
      (or whatever Grounded 2's enemy base is named -- need to
      confirm via SDK dump).
  - Does the death event carry a "killer" reference? If yes, we
    filter to player-killed events directly. If no, we have to
    correlate with the last damage instigator (more fragile).
  - In multiplayer: does the host get every kill event, or only
    its own? Document the limitation.
  - Method: install a ProcessEvent trace gated to UFunction names
    matching `*Death*|*Died*|*Kill*` on `BP_SurvivalNonPlayer*`,
    play 5 minutes of combat, grep the log.

**R2. Enemy class hierarchy.**
  - What's the enemy base class actually named in Grounded 2?
    (`BP_SurvivalNonPlayerCharacter_C`? `BP_Bug_Base_C`? etc.)
  - Is there one base or several disjoint trees (creatures vs
    BURG.L bots vs bosses)?
  - Do enemies carry a "tier" or "difficulty" property we can use
    for XP weighting, or do we hardcode a table per-class?
  - Method: dump-7, search for "NonPlayerCharacter", walk
    super_class chain.

**R3. XP / level persistence.**
  - The game has multiple save slots. We need a stable per-slot
    key. Options:
    - Save file name (read from game's `USaveGame` system if
      reachable -- need to find the function/object that exposes
      current slot name).
    - World seed / PlayerState GUID -- if exposed, more reliable
      across renames.
    - Single global file (simpler, breaks for users with multiple
      characters; ship this first, upgrade later).
  - Where to store: `<DLL_dir>/saves/<slot>.json` is fine; the mod
    folder is writeable.
  - Method: dump-7, search for "SaveGame", "SlotName", "PlayerState".

**R4. Stat re-application.**
  - Current CDO patches happen once at mod load. With levels,
    every level-up changes the multiplier. We need to either:
    - (a) Re-walk the CDO tree on every level-up and re-patch
      (cheap; a few ms once per level-up).
    - (b) Patch only the live player's components (not the CDO);
      requires finding the local `PlayerController` /
      `PlayerCharacter`, walking its instance components.
    - (a) is simpler and matches our existing infra. Newly-spawned
      instances inherit the latest CDO. Already-spawned enemies
      keep stale values, but for *player* stats this is fine
      because the player character is the one we're tweaking and
      it reads CDO at component construction.
  - Open question: does the player's max-backpack-size get cached
    at character spawn, or read live from the inventory component?
    If cached, we may need an instance patch on level-up.
  - Method: experimentally, set capacity at runtime on a live
    component and check whether the inventory UI updates without
    a save reload.

**R5. UI surface.**
  - UE4SS supports imgui tabs via `register_tab` on the C++ mod
    base. We already have the vtable slot wired. Confirm the
    rendering path works in our shim (does the C++ shim need to
    actually call `register_tab` from Rust? what's the UE4SS
    convention?).
  - Imgui is the cheap MVP: shows level, XP/next-level bar, list
    of perks with clickable +1 buttons.
  - In-world UMG (a custom widget rendered alongside the survival
    HUD) is a separate, much harder project. Defer.
  - Open question: can imgui receive input while game has focus,
    or do we need a hotkey to summon it? UE4SS's default behavior
    is to bind `~` (or similar) to toggle the UE4SS console, which
    also surfaces tabs.

**R6. XP curve + perk economy design.**
  - Not a code question -- a game-design question. But we need an
    answer before plumbing values:
    - Max level: 50? 100?
    - XP curve: linear / quadratic / exponential?
    - Perk points per level: 1? Or 1 every N levels?
    - Per-perk cap: every perk maxes at rank 10? Different caps
      per perk?
    - Respec: free, paid (with what?), or none?
  - Reasonable starting numbers (placeholder until tuned):
    - Levels 1-50, quadratic XP curve (level N requires
      `100 * N^1.8` total XP).
    - 1 perk point per level.
    - Each perk maxes at rank 10.
    - Respec: free for now (settings flag).

### Architecture sketch (post-research)

Modules (Rust side, all in `better-backpack/src/`):
```
rpg/
  mod.rs            entry: glue init, level-up event loop
  xp.rs             XP awarding, level threshold table, on_kill
  perks.rs          perk catalog, rank -> stat-multiplier function
  state.rs          struct PlayerState { level, xp, perk_ranks }
                    serde, load/save to <DLL_dir>/saves/<slot>.json
  ui.rs             UE4SS imgui tab wiring (level/XP/perks)
  events.rs         hooks: enemy-death ProcessEvent hook,
                    player-load detection
```

Existing modules (`survival.rs`, `inv_hook.rs`, the future
`combat.rs`, `gear.rs`, `movement.rs`) become **stat surfaces**
driven by `perks.rs::current_multipliers(state)`.

Lifecycle:
1. `on_unreal_init`: load PlayerState from disk (key = save slot).
   Apply current multipliers to all CDOs.
2. Install ProcessEvent hook on enemy-death UFunction.
3. On kill: award XP to PlayerState, check threshold, on level-up
   bump perk-points.
4. On perk allocation (UI click): update PlayerState, recompute
   multipliers, re-apply CDO patches, save to disk.
5. On exit / save event: flush PlayerState to disk.

### Build sequence (DO NOT START BEFORE R1-R5 ANSWERED)

- [ ] Spike A: kill detection. Hook the suspected death function,
  log every fire with the killer reference, play in-game, confirm
  the "player killed enemy X" signal is reliable. **One evening.**
- [ ] Spike B: persistence. Find the current save slot name from
  the game. If too hard, fall back to single global file with a
  TODO. **One evening.**
- [ ] Spike C: live stat re-apply. Confirm we can change backpack
  capacity at runtime without a save reload. **One evening.**
- [ ] Once A+B+C are green: write `state.rs`, `xp.rs`, `perks.rs`
  with the placeholder curve from R6. Wire up.
- [ ] UE4SS imgui tab. Read the UE4SS samples in
  `C:\code\RE-UE4SS\` for the canonical pattern.
- [ ] Tune XP curve and perk economy through actual play.
- [ ] Polish: respec, settings.json overrides for the curve,
  per-enemy XP table.

### What we keep from the old direction

The "stat surfaces" sections below (#3-7) are still the right
implementations -- we just don't ship them as user-facing sliders.
They become the math behind perks. Sequence:
- Get gear durability (#3) and enemy health (#4) found in the SDK
  during R2 anyway, since those CDOs live on the same enemy tree.
- Glide speed (#6) is a pure player-stat, bundled with backpack
  capacity for the player-side perks.

The settings.json schema flips inside out: instead of
`{ "thirst_multiplier": 0.5 }`, we have
`{ "rpg": { "starting_level": 1, "xp_curve": "quadratic" } }`,
and per-perk live values are in `<save-slot>.json`, not user
settings.

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
- [x] Step 7: In-game smoke test under UE4SS. **Working as of
  2026-05-05.** start_mod returns valid instance, on_unreal_init
  fires, Rust side takes over.
- [ ] Step 8: Archive the winhttp proxy material to
  `archive/winhttp-proxy/`. Keep it as a tested fallback in case
  UE4SS turns out unstable for Grounded 2.

The current winhttp.dll proxy work (already shipped, commits
514e2b1..bfb3447) is **not wasted**: it's the tested fallback.
Archive, not delete.

## 2. Rename the project

`better-backpack` no longer describes what we're building. The new
direction is an RPG / level-up mod (see #0). Pick a name that
reflects "kill stuff -> level up -> perks".

Candidates to consider (final pick TBD):
- `grounded-rpg` -- explicit about the game and the mechanic.
- `g2-rpg` -- short.
- `groundlevel` -- pun: ground level + leveling up.
- `bug-hunter` / `huntmaster` -- emphasizes combat/kills.
- `instar` -- the bug term for a developmental stage between molts;
  thematic with Grounded's "you-are-tiny" framing and matches the
  level-up loop. Niche but fitting.
- `groundwork` -- pun on Grounded, generic enough to cover future
  scope creep.

Old "everything is a slider" candidates archived for context:
~~g2-sandbox, g2-tweaks, grounded2-tweaks, bigger-better~~.

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

- UE4SS C++ mod load works (2026-05-05). Crash on load was a vtable
  mismatch in `cpp/shim.cpp`'s `RC::CppUserModBase` mirror -- six
  virtuals missing vs upstream header (`on_ui_init`, four `Lua*`
  overloads of `on_lua_start`/`on_lua_stop`, `on_cpp_mods_loaded`).
  UE4SS dispatched past our vtable into garbage. Fixed by mirroring
  the header virtual list verbatim. `on_cpp_mods_loaded` is NOT
  marked `RC_UE4SS_API` because UE4SS.lib doesn't export it; using
  the local inline body works.
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
