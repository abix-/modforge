# TODO

!!! info "Scope"
    Authoritative on open work across the workspace. What's NEXT,
    not what's done. Completed milestones live in
    [`changelog.md`](changelog.md). Per-subject deep dives live in
    each crate's `docs/` folder ([`../ueforge/docs/`](../ueforge/docs/)
    for the framework, [`../grounded2-rpg/docs/`](../grounded2-rpg/docs/)
    for the Grounded 2 mod). Read those FIRST when investigating a
    subject.

!!! tip "How to use"
    Roughly ordered by leverage. Pick from the top of the list when
    starting a new session.

---

## P0. In-game smoke test

The full 2026-05-10 wave is build-clean and unit-tested but not
yet validated in-game.

!!! warning "Acceptance gate"
    Drive from your machine. All checks must pass:

    - Game launches; `grounded2_rpg.log` shows `ueforge` init lines.
    - ImGui tab opens on `Insert`; RPG content renders.
    - Load a save -> slot activate fires; tracker loads
      `<guid>.json`; backpack capacity reflects skill levels.
    - Kill a creature -> kill_hook fires; XP increments; save updates.
    - HTTP `/debug` endpoint responds to `op:snapshot` with non-empty
      state.

    If any of that fails, triage from the log lines.

---

## P0. DataTable write surface (remaining)

The Phase 1 / Phase 2 surface shipped (see
[`../ueforge/docs/data-table.md`](../ueforge/docs/data-table.md)).
Two open follow-ups gated on real consumers:

- [ ] **Replicated-field respect**. Some row fields are
  replicated to clients; writes during a server's authority
  drop get desynced. Defer until we hit a real case.
- [ ] **Non-primitive field types**. Writing `FString` /
  `TArray` rows needs the engine's `FMemory` allocator (ABI
  work). Defer until a real consumer needs it.

## P1. Registry alignment (remaining)

- [ ] **`simulate_apply_damage` lift** (gated on Wave E1).
  `ApplyDamageFromInfo` from inside any current PE trampoline
  re-enters ProcessEvent through the engine's damage-replication
  path and crashes the host. Lift to `ueforge::rpg::health` once
  the safe drain site lands.

### Deferred (large lifts)

- [ ] **Parm decoders**. Every PE-hooking module knows
  "for UFunction X, the parm block has shape Y". Currently
  scattered across kill_hook / inv_hook / fall_hook as bespoke
  code. Could lift to `ParmDecoderDef { function_name, decode_fn
  }` + a per-class registry. Biggest payoff: a generic
  `walk_parms` debug op. Defer until a second consumer needs
  it.
- [ ] **`ClassRef` registry**. Every declared `static FOO:
  ClassRef = ClassRef::new("Foo")` could feed a workspace-wide
  `class_refs_list` op. Marginal; defer.

## P1. Ueforge durability (kovarex review wave 2, remaining)

Wave 2 keepers (patternsleuth, zerocopy first wave, schema
versioning, SAFETY annotation status, crate-shopping verdicts)
shipped; see [`../ueforge/docs/architecture.md`](../ueforge/docs/architecture.md)
"Wave 2 durability adoptions".

### Pending crate adoptions (ordered by gain)

Sorted by leverage, not alphabetical. Maintenance status
confirmed via `gh api` 2026-05-12.

1. **`zerocopy`** (IN PROGRESS). First wave shipped; still open
   are the dynamic-offset / dynamic-type sites where one zerocopy
   struct doesn't fit all callers:
   - `damage/mod.rs::on_event` (offsets configured at runtime
     via `DamageHookConfig`).
   - `data_table.rs::decode_field` (T chosen at runtime by
     FProperty class string).
   - kill_hook / fall_hook / inv_hook parm decoders (each could
     define one `#[repr(C)]` + zerocopy struct per UFunction
     shape; ~6 structs total).
   - `FDataTableRowHandle` (has a `*const UObject`; pointer
     rejects FromBytes; would need a split type).

2. **`proptest`** (IN PROGRESS). MEDIUM-HIGH gain. Two
   property tests landed: TArray garbage-header check +
   TMap `find_value_by_fname_key` correctness across random
   16-entry maps. Still open: FieldTweak decoder,
   `Val::from_json` round trips, `inspect_address` byte
   slabs.

3. **`insta`**. MEDIUM gain, ~1 hour to wire. Snapshot testing
   for op JSON responses. Each `.snap` file is one human review;
   refactor regressions surface as diffs without hand-writing
   `assert_eq!(json!(...))` per op. Apache-2.0 (Mitsuhiko), last
   commit 2026-05-02. <https://docs.rs/insta/>

### Open durability follow-ups

- [/] **Annotate the existing unsafe blocks**. Down to 50 from
  271; the remaining 50 are spread thinly across `ue/probe.rs`,
  `ue/status_effect.rs`, `ue/class_tweak.rs`, `ue/core_types.rs`,
  `ue/typed_field.rs`, `ue/fname.rs`, `ue/platform.rs`,
  `ue/player.rs`, `discovery.rs`, `selector.rs`,
  `damage_info.rs`, `pe_call.rs`, `parms.rs`, `fstring.rs`, and
  single-block files. Chip away during normal edits; bump the
  lint to `deny` when the count reaches zero.
- [ ] **Hot-reload torture test**. 1000x Ctrl+R loop with hooks
  installed; assert no thread leak, hook leak, slot regression.
  Path is "tested once" today. Requires running game; gated on
  in-game test harness.

## P2. Ueforge grooming (remaining)

- [ ] **UE-version-aware `ffield` / `fproperty` / `ustruct`
  offsets**. Hardcoded for UE 5.4 in `ue/offsets.rs`. UE 5.5+
  silently returns wrong names. Pair with the sig-scan work.
- [/] **Property tests on walkers**. Boundary tests shipped (5
  on `tarray`, 7 on `tmap`). Proptests landed on TArray
  (garbage headers) + TMap (find_value correctness). Still
  open: FieldTweak decoder, `Val::from_json`,
  `inspect_address` byte slabs.
- [ ] **`tiny_http` / `ureq 2` migration window**. Both on a 2-5
  year support horizon.
- [ ] **PE hook trampoline linear search**. Index by vtable
  pointer when 6+ hooks are installed.

## ueforge framework. Wave E (deferred until needed)

- [ ] **Global ProcessEvent pre-callback**.
  `RegisterProcessEventPreCallback` wrapper +
  `Queue::install_drain` helper. Land when status-effect
  migration needs a guaranteed drain site.
- [ ] **`AddUObjectCreateListener` integration**. Land when
  ows-tweaks or g2rpg's CDO-revert-replay scenario asks. ~100 LoC.

## ueforge framework. Still-open extractions

- [ ] **Leak-source helpers**. `explore_leak_source.rs` (350
  lines) uses g2-extension `top_packages` / `loaded_levels` /
  `process_regions` fields not in the framework's
  `gobjects_population` helper today. Lift those as separate
  `ueforge::ue::probe::*` extensions when a second consumer
  needs them.

Deferred extractions (no second consumer yet):

- Damage-hook framework scaffold beyond `DamageBinder`. Maine-
  specific KillerKind / FDamageInfo parsing stays game-side.
- Status-effect discovery enumerators (`fall_hook` row-walking).
  `StandardEffect::StatusEffect` covers the apply path.
- HUD overlay drawing (DX11 hook for in-world rendering). Big
  lift, no second consumer.
- Inventory CRUD ops (add / remove / count / list). Module shape
  exists; CRUD lands when a second game's UFunction names drive
  the trait surface.

---

## ueforge buildings module (planned, not started)

The next opinionated module. Lets a mod add custom content
(buildings, structures, placeables) to a UE5 game via UE4SS,
not via paks. Player-placeable buildings that yield resources,
tick logic, persist across saves, integrate with the host
game's build menu where one exists.

The sixth module after `rpg / stacks / difficulty / inventory /
damage`. Splits framework from game-specific surface: future
mods ship a new building with ~30 lines of catalog config + ~50
lines of game-side wiring.

### What's universal (-> `ueforge::buildings`)

| Surface | Why universal |
|---|---|
| `BuildingDef<S, C>` catalog row. Id + display_name + description + default per-instance state `S` + game-specific config `C` | Every game's mod-added buildings have the same shape: a typed catalog. Same pattern as `rpg::Skill<E>`. |
| `BuildingRegistry: &'static [BuildingDef<S, C>]` + lookup-by-id | One source of truth, same as RPG catalog. |
| Per-instance state store (`HashMap<Handle, S>`) | Every game tracks "what state is this placed building in". Stored items, level, last-tick timestamp. Shape `S` is game-supplied. |
| Per-slot JSON persistence (`<DLL_dir>/buildings/<playthrough-guid>.json`) | Same `SlotStore<S>` pattern from `ueforge::rpg`. Reuse, don't reinvent. |
| Tick scheduler (closure fires per-instance every `interval`) | Auto-farm, regen, decay. All "advance state by dt" patterns. Owned by the framework; rides on the existing `SlotPoller` shape. |
| Standard debug ops (`buildings_list` / `buildings_place` / `buildings_destroy` / `buildings_get` / `buildings_set_state`) | Same shape as `rpg::ops`. Universal testing surface. |
| ImGui tab template (catalog + placed-instance list + per-instance state viewer) | Same shape as `rpg::tab::render`. |

### What's game-specific (-> game crate via trait)

| Surface | Why game-specific |
|---|---|
| The UE5 game's build-menu data table / widget | Each game has its own UI; some have no native build mode at all. |
| Spawning a placed instance (BP class name + spawn UFunction + cost-charge logic + location/rotation parms) | Per-game BP classes + per-game economy system. |
| Resolving a handle to a live UObject for state reads | Per-game inventory / storage class shapes. |
| Yield-to-storage logic (find nearest storage, transfer items via game's inventory API) | Per-game storage class + per-game item-transfer UFunction. |
| Net authority / replication (which side owns yields) | Per-game multiplayer model. |

The seam: a `BuildingSpawner` trait similar in shape to
`DamageBinder` / `ViewportBinder`.

### Module surface (proposed)

??? example "Proposed Rust module surface"

    ```rust
    // ueforge::buildings (planned, not yet implemented)

    pub struct BuildingDef<S, C> {
        pub id: &'static str,
        pub display_name: &'static str,
        pub description: &'static str,
        pub default_state: S,
        pub config: C,
    }

    pub trait BuildingSpawner: Send + Sync + 'static {
        type Config: Copy + 'static;
        type Handle: Eq + std::hash::Hash + Clone + Send + 'static;

        fn spawn(&self, cfg: &Self::Config, loc: WorldLocation)
            -> Result<Self::Handle, String>;

        fn destroy(&self, handle: &Self::Handle) -> Result<(), String>;

        fn register_in_build_menu(&self, buildings: &[(&'static str, &'static str)])
            -> Result<(), String> { Ok(()) }
    }

    pub struct BuildingsTracker<S, C, Sp: BuildingSpawner> {
        catalog: &'static [BuildingDef<S, C>],
        spawner: Sp,
        instances: Mutex<HashMap<Sp::Handle, Instance<S>>>,
        store: SlotStore<PersistedState<S, Sp::Handle>>,
    }

    pub struct Instance<S> {
        pub building_id: &'static str,
        pub state: S,
        pub spawned_at: SystemTime,
        pub last_tick: Option<SystemTime>,
    }
    ```

Plus `ueforge::buildings::ops` (standard debug-op set),
`ueforge::buildings::tab::render` (ImGui template), and
`ueforge::buildings::tick::SchedulerHandle` (riding the
SlotPoller shape).

### Phased plan

#### Phase A: research (no code)

- [ ] **A1: Grounded 2**. Find the build system entry points
  via the SDK. Likely candidates: `UProductionBuilding`,
  `BP_Building*`, `UBuildingPlacementComponent`,
  `UCraftingComponent`. Identify which UClass defines a
  "placeable building", which UFunction spawns one, how the
  cost is charged, whether there's a build-menu data table to
  extend, how instance state replicates / persists, and the
  save shape.
- [ ] **A2: Outworld Station**. Same audit. The trait surface
  needs to fit both.
- [ ] **A3: Storage / inventory transfer**. For auto-farming
  to land items into a chest, identify the game's "add item to
  inventory" UFunction.

#### Phase B: design lock-in

Trait surface against the two games' constraints. Pick the
handle type (UObject address vs mod-generated FGuid), storage
location, tick model.

#### Phase C: framework implementation

- [ ] C1: `ueforge::buildings::BuildingDef<S, C>` + catalog row.
- [ ] C2: `BuildingsTracker<S, C, Sp>` with `activate_slot` /
  `deactivate_slot` + persistence via `SlotStore`.
- [ ] C3: `BuildingSpawner` trait + game-impl skeleton.
- [ ] C4: Tick scheduler.
- [ ] C5: `ueforge::buildings::ops` standard debug ops.
- [ ] C6: `ueforge::buildings::tab::render` ImGui template.

#### Phase D: g2rpg consumer (proof of concept)

- [ ] D1: One concrete buildable. The
  **auto-fiber-harvester** (yields plant fibers at a configured
  rate, per-instance `{accumulated_units, last_yield}` state,
  transfers to nearest storage on threshold).
- [ ] D2: Catalog row in `grounded2-rpg/src/buildings/catalog.rs`.
- [ ] D3: G2 spawner impl.
- [ ] D4: ImGui "Buildings" tab.

#### Phase E: tests

Pester-style scenario DSL extended for buildings (e.g.
`scenario::for_building(api, "auto_harvester").placed_at(loc).advanced_time(60s).should_yield_at_least(10, "plant_fiber")`).

### Open design questions (decide during Phase A/B)

- **Handle type**. UObject address (stable while game is running,
  invalid across saves) vs mod-generated FGuid (stable across
  saves, requires translation). Likely: FGuid for persistence +
  separate live UObject cache.
- **Asset references**. v1 reuses vanilla assets (less moving
  parts); pak-side custom assets land later.
- **Build-mode integration**. v1 ships ImGui-only spawn (lower
  risk). Vanilla-menu integration is Phase D+1.
- **Multiplayer**. Out of scope for v1. Single-player / host-only.
- **Tick clock**. Game-time vs real-time. Save-and-quit
  shouldn't run the farm for 8 hours when you reload. Use
  game-time OR clamp dt to `min(real_dt, configured_max_dt)`.
- **Network authority**. Yields go through the game's
  authoritative inventory API, not direct field writes.

### Estimated scope

Phase A: ~1 session per game. Phase B: 1 session.
Phase C: ~3-4 sessions (~500-700 lines). Phase D: ~2-3 sessions.
Phase E: ~1 session. Total: ~8-10 sessions. The framework piece
is the leverage point.

---

## g2rpg. Catalog expansion

Each entry is one [`skills::CATALOG`](../grounded2-rpg/src/rpg/skills.rs)
row of an existing `SkillEffect` shape unless noted.

- [ ] **Critical Chance + Critical Damage**. `before` callback
  on the live damage hook returns `Some(damage * (1 + crit))` on
  roll. RNG needs a per-mod seed; reuse `rand` crate.
- [ ] **Evasion / Dodge**. `before` returns `Some(0.0)` on roll
  for player-taken hits.
- [ ] **Thorns**. `after` resolves the attacker's HC (instigator
  -> controller -> possessed pawn -> HC at +0x1340) and writes
  `event.damage * thorns_fraction` to its CurrentDamage. Same
  healing pattern proven via Lifesteal.
- [ ] **Leap Distance**. LANDED untested
  (`PlayerMovementMult` over AirControl trio).
- [ ] **Auto-pickup (range)**. Per-frame proximity scan picks up
  loose items. Open design: mechanism (existing proximity-pickup
  field vs per-frame scan), filter (which items qualify),
  throttle, multiplayer authority.
- [ ] **Stamina Pool + Stamina Regen**. `UStaminaComponent` on
  ASurvivalCharacter at +0x1358; offsets need a Dumper-7 dive.
- [ ] **Gear Hardiness**. Find durability-loss-per-use field;
  per-item durability scaling.
- [ ] **Climb Speed**. May or may not exist as a separate
  CharMovement field; check before adding.
- [ ] **Collision / Impact Damage Resistance**. Reduce / negate
  the lethal self-damage from slamming into plants / terrain.
  Likely home: live damage hook surface.

!!! tip "Catalog target"
    ~25 skills. Today: 13.

## g2rpg. Live-instance writes

Some combat-side skills still write only to player CDOs.
Movement now mirrors onto the live player pawn; remaining
combat effects need the same. Each `SkillEffect` variant grows a
"live walk" arm analogous to its CDO walk.

## g2rpg. Pkg(0) instigator bug

!!! bug "Repro"
    Some legitimate player kills attribute to
    `/Script/CoreUObject (Package)` because
    `LastDamageInfo.InstigatorController` is an unset
    `FWeakObjectPtr` (index=0 -> Package). User loses XP.

Investigation:

1. Sample more kills with different weapons. Identify which
   attack types fail vs succeed.
2. Hook `ApplyDamageFromInfo` to read `FDamageInfo` parm at
   function entry and cache the instigator per HC. When
   multicast fires with KillingBlow, use cached value if
   `LastDamageInfo` is null.
3. Failing that, fall back heuristically (player in attack range
   + recently swung).

## g2rpg. Status-effect migration (in progress)

Migrate Impact Damage Resistance and Lifesteal to the canonical
status-effect surface first; rest of catalog follows. Detail in
[`../grounded2-rpg/docs/damage.md`](../grounded2-rpg/docs/damage.md).

Concrete next steps:

- [ ] **Optimize the discovery test**.
  `tests/explore_status_effect_rows.rs`. Batch read_bytes (one
  big chunk) so it runs in seconds. Capture FName for each row.
- [ ] **Pick target row per stat type**.
- [ ] **Implement `SkillEffect::PlayerStatusEffect` variant** in
  `skills.rs`.
- [ ] **One generic apply arm in `apply.rs`** that resolves the
  table, looks up row by FName, mutates Value, calls
  `UStatusEffectComponent::CreateAndAddEffect` via process_event.
- [ ] **Migrate `impact_resistance` first** as proof of concept.
- [ ] **Validate via the regression test**: bandages must heal
  even with impact_resistance enabled.
- [ ] **Migrate the rest** row-by-row:
    - `health_regen` -> `Type=Health (24)`, drop UGlobalCombatData
      mutation
    - `max_health` -> `Type=MaxHealth (5)`, drop direct HC.MaxHealth
    - `lifesteal` -> `Type=LifeSteal (38)`, drop Runtime no-op
    - `attack_damage` -> `Type=AttackDamage (23)`
    - `armor` -> `Type=DamageReduction (29)` or
      `DamageReductionMultiplier (30)`
    - `fall_resistance` -> ALSO apply `Type=FallDamage (14)` for
      consistency (keep velocity-stomp as the validated mechanism)

Movement skills stay on direct CMC field writes. The
status-effect surface doesn't expose movement parameters with
the granularity we use. Survival drains stay on
SurvivalComponent CDO writes.

## g2rpg. RPG tuning

Open until we play more.

- XP curve: is `100 * N^1.8` (cap 50) too steep / flat?
- Per-creature XP table: ~20 species with placeholder values.
  Expand and balance.
- Skill `max_bonus`: are the level-100 caps right?
- Level-up frequency vs catalog size: 50 levels = 50 points;
  catalog max-everything = ~225 points (9 skills x 25 avg).

## g2rpg. Distribution

- [ ] **Vortex / Nexus packaging**. `cargo deploy package`
  produces the right zip layout. Need a Nexus listing
  (description, screenshots, mod page).
- [ ] **Project rename**. "grounded2-rpg" no longer fits when
  the mod is an RPG / level-up system. Candidates:
  `grounded-rpg`, `g2-rpg`, `groundlevel`, `instar`,
  `huntmaster`. Touches: Cargo.toml package name, workspace
  dir, settings file path, log header, README, Vortex zip name.

## g2rpg. Feature ideas (not yet scoped)

- [ ] **Auto-farming buildings**. First concrete consumer of the
  buildings module above. Plant-fiber / resin auto-harvester as
  the first building.

---

## g2rpg. Integration testing

Reference design + test coverage principle:
[`../grounded2-rpg/docs/testing.md`](../grounded2-rpg/docs/testing.md)
+ [`../ueforge/docs/RESEARCH.md`](../ueforge/docs/RESEARCH.md)
"Test coverage principle".

### Read surface (snapshot fields)

- [ ] **dmg-trace ring buffer in snapshot**. Last N multicast
  events. Currently log-only.
- [ ] **player world location + equipped weapon** (context for
  fall / item-use simulation).

### Drive surface

- [ ] **High-frequency drain site for the PE queue**.
  `kill_hook`'s trampoline only fires on player HC vtable
  events. With `impact_resistance` mask = 0xFFFFFFFF, multicast
  traffic drops near zero, starving the drain. `call` ops time
  out at 5s. Land Wave E1 (global ProcessEvent pre-callback)
  to fix permanently.
- [~] **simulate_consume_item**. Via `call` once we know
  TryUseItem signature on the player controller.
- [~] **simulate_kill / simulate_fall**. Test-side via `call`.
  Doable today.
- [~] **simulate_status_effect_add / _remove**. Via `call` on
  `UStatusEffectComponent::CreateAndAddEffect` once row handle
  layout is captured in a `#[repr(C)]` struct.
- [~] **set_xp / set_level**. Via `call` if a setter UFunction
  exists, or via direct field-write.
- [~] **clear_status_effects**. Via `call` or direct TArray
  write.

### Test coverage (per-skill principle)

For EACH catalog skill (x13):

- [ ] refund -> reverts (only ~half tested explicitly)
- [ ] toggle off -> reverts to vanilla (only for variants that
  honor the flag)
- [ ] toggle on -> effect restored (move_speed only; fill in)
- [ ] persist across slot reload (NOT covered for any skill)
- [ ] level 0 -> no effect (make explicit per skill)

Interaction matrix:

- [ ] armor + heal
- [ ] max_health + fall onto rocks
- [ ] fall_resistance + impact_resistance + rock collision
- [ ] every other pair touching HC fields, damage gate, regen

Error paths:

- [ ] op while no slot (only reload_slot covers this today)
- [ ] malformed args (wrong type)
- [ ] port collision / second instance

---

## Out of scope (kept for reference)

- Visible 6-row inventory grow. Replaced by paged 4x10 viewport
  with mouse-wheel scroll. Working.
- Multiplayer correctness for hunger/thirst. Stats almost
  certainly replicate server-authoritatively, so non-host
  clients won't see the effect. Document, don't fight.
- In-world UMG HUD overlay (always-visible XP bar). Out of v1
  scope; would need a custom DX11 hook or BPModLoader-shipped
  widget. ImGui tab is sufficient.

## Open: hot-reload follow-ups

Phase B (in-DLL teardown of hooks / servers / settings watchers
+ side-file rename) shipped 2026-05-10. See
[`../ueforge/docs/lifecycle.md`](../ueforge/docs/lifecycle.md)
"Hot-reload (Ctrl+R)" for the implemented surface.

Optional follow-ups (defer until needed):

- [ ] **Phase B+: programmatic Ctrl+R from `cargo deploy install
  --hot`**. Mod watches a sentinel file; on change, synthesizes
  Ctrl+R via UE4SS's `register_keydown_event`.
- [ ] **Phase B++: HTTP `reload` op** that calls
  `UE4SSProgram::queue_reinstall_mods` directly. Smaller side
  trip.
