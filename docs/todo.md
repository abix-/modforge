# TODO

> **Authoritative on:** open work across the workspace. What's
> NEXT, not what's done.
>
> Completed milestones live in [`changelog.md`](changelog.md).
> Per-subject deep dives live in each crate's `docs/` folder
> ([`../ueforge/docs/`](../ueforge/docs/) for the framework,
> [`../grounded2-rpg/docs/`](../grounded2-rpg/docs/) for the
> Grounded 2 mod). Read those FIRST when investigating a subject.
>
> Roughly ordered by leverage. Pick from the top of the list when
> starting a new session.

---

## P0. DataTableDef + ImGui browser (read-only)

The architectural insight: stacks + difficulty + status effects
are all special cases of "typed-field operations on iterated
objects." The TABLES themselves (UDataTable + row schema) are
their own first-class concept that nothing has captured yet.

Step 1 (this todo entry): READ-only browser. Scan, schema-dump,
display in ImGui. Writes are a separate later step (the painful
part).

### Phase 1a: schema discovery + DataTableDef

The DISCOVERY path is the leverage point: a new game's bootstrap
is "launch + curl `discover_data_tables` + pick fields". Land
discovery before snapshot / browser / static catalog rows.

- [x] **`DataTableDef`**. Workspace-standard
  `<Subject>Def`. Shipped `ueforge/src/data_table.rs` with `id`,
  `table_name`, `row_struct: RowSchema { name, fields: &[RowField
  { name, offset, element_size }] }`. Mirrors `NativeProperty`
  for the field shape (no FieldKind enum for v1. Element_size
  is the discriminator, same as NativeProperty).
- [x] **`DataTableRegistry`**. Slice-of-refs registry mirroring
  `StackRegistry` / `StatusRegistry` (`def` / `entries` / `iter`
  / `len` / `is_empty` / `IntoIterator`).
- [x] **Dynamic discovery + cache** -- `ueforge::discovery`
  module: one GObjects pass populates a process-global
  `Arc<DiscoverySnapshot>` covering every live `UDataTable`,
  `UClass`, and `UScriptStruct`. `run_at_load()` runs from each
  mod's `on_unreal_init` worker (wired into g2rpg + ows-tweaks)
  and logs a one-line summary. Debug ops `discover_data_tables`
  / `discover_classes` / `discover_structs` read from the cache;
  pass `{refresh: true}` to re-walk after content streams in.
  Low-level walkers (`probe::describe_data_table`,
  `probe::walk_struct_fields`) stay pub for custom dump shapes.
  No JSON-on-disk; redirect curl if you want a file. Engine
  filter still open (deferred until noise is a real problem).

### Phase 1b: live snapshots

- [x] **`data_table::snapshot_table(table_name, max_rows)
  -> Option<Json>`** -- walks the table's `RowMap`, decodes each
  row per the live `FProperty` chain (FProperty class drives the
  decoder: `IntProperty`/`Int32Property`->i32,
  `FloatProperty`->f32, `BoolProperty`->bool,
  `NameProperty`->resolved string, `StrProperty`->FString,
  `ObjectProperty`->`{addr,name}`, unknown->raw_bytes_hex). Cold
  path. Data-driven (no DataTableDef needed); the static catalog
  is for browser organization / future TweakDef wiring, not for
  read access.

### Phase 1c: debug ops

- [x] **`dump_data_table { table_name, max_rows? }`**. Returns
  the live snapshot (rows + decoded fields) as JSON. Registered
  in `ueforge::ops::register_builtins`.
- [x] **`discover_data_tables` / `discover_classes` /
  `discover_structs`**. Read from the in-memory discovery
  cache; `{refresh: true}` re-walks GObjects.
- [x] **`list_data_tables` (registry-only)**. Enumerates the
  registered `DataTableRegistry` (declared static catalog),
  separate from the runtime `discover_data_tables` cache. Game
  crates opt in via `data_table::register(&MY_REGISTRY)` from
  their worker init; when no registry has been registered the op
  returns `{registered: false, ...}` so clients can tell. No
  game has populated this yet; discovery still covers the
  universe.

### Phase 1d: ImGui browser tab

- [x] **`ueforge::ui_data_table_browser::render`**. New ImGui
  tab. Lists every discovered UDataTable from the
  `ueforge::discovery` cache; click "Open" to load a snapshot
  (schema + first N rows); "Refresh discovery" re-walks
  GObjects; "max rows" slider controls per-table row count.
  Wired into both g2rpg and ows-tweaks `MOD_INFO.tabs` as
  "Tables".
- [x] Filter box on table name. `ueforge::ui::input_text` +
  `cstr_view` added; the browser tab now filters the table list
  by case-insensitive substring.
- [x] Row-FName filter on the selected table. Inside the
  rows tree, a `row filter` input box matches row_name
  case-insensitively + a `filtered: N rows matching '...'`
  footer.

### Phase 1e: validation

- [x] **Compare static-declared vs discovered**.
  `data_table::validate_registry(reg)` compares each
  `DataTableDef`'s field list against the live FProperty chain
  in the discovery cache and emits a JSON report + logs each
  drift line via `ueforge::log!`. Mods call it from their
  `on_unreal_init` worker after `discovery::run_at_load()`; the
  no-op case (empty registry) costs one HashMap allocation.
  Catches UE-version mismatches before any tweak runs.

### Phase 1f (bonus): name-based writes (shipped)

- [x] **`data_table::NamedFieldTweak<T>`**. A wrapper over
  `FieldTweak<T>` whose offset is resolved from the discovery
  cache on first apply. New-game bootstrap is now:
  declare `static FOO: NamedFieldTweak<i32> = NamedFieldTweak::new("DT_X", "Field")`
  + call `FOO.apply(...)`. No SDK header dive, no hand-typed
  offsets, no recompile after a UE patch that shifts the offset.
- [x] **`data_table::resolve_field(table, field)`**. Low-level
  lookup against the discovery cache. Returns
  `(offset, element_size, FProperty class)`. Useful for ad-hoc
  scripts + future generic tweak builders.

### Phase 2 (write surface)

- [x] **Runtime declare-and-apply ops**. `tweak_apply`,
  `tweak_list`, `tweak_revert` shipped 2026-05-11. Take
  `{table, field, kind, op, value}` JSON; resolve offset from
  discovery; capture vanilla per row on first apply; rewrite
  rows via `set` / `multiply` / `add`; idempotent on re-apply
  (always re-base on captured vanilla). Powers a hot-iteration
  loop (curl an op, change a field, curl `tweak_revert` to
  restore) without rebuilding.
- [x] **TweakDef unification**. `ueforge::tweak::TweakDef` ships
  with `TweakTarget` (DataTable | Class), `TweakKind` (i32 / f32
  / u32), `TweakOp` (set / multiply / add), atomic
  current_value_bits + default_value_bits, six const constructors
  (`data_table_i32`, `data_table_f32`, `data_table_u32`,
  `class_i32`, `class_f32`, `class_u32`), load/store helpers
  per kind, `apply` / `revert` / `reset_to_default` / `resolved`.
  Plus `TweakRegistry` slice-of-refs wrapper with `apply_all` /
  `revert_all`. Apply delegates to the existing
  `data_table::dynamic_apply_*` for DataTable targets and a new
  symmetric class-tweak dynamic registry (`DYN_CLASS_I32/F32/U32`)
  for Class targets, so captured vanilla survives across reapplies
  and shares with the runtime tweak surface.
- [x] **`stacks` + `difficulty` modules deleted**. Consumer
  sweep shipped: `outworld-station-tweaks/src/stacks.rs` now
  declares `static MATERIALS_TWEAK: TweakDef =
  TweakDef::data_table_i32(..., TweakOp::Multiply, 4)` with
  local `AtomicUsize` / `AtomicBool` for the status counters;
  `grounded2-rpg/src/survival.rs` now declares two
  `TweakDef::class_f32(..., TweakOp::Multiply, 1.0)` statics for
  hunger + thirst (field NAMES `HungerSettings.AdjustmentPerSecond`
  + `ThirstSettings.AdjustmentPerSecond` resolved from discovery).
  `ueforge/src/stacks.rs` + `ueforge/src/difficulty.rs` removed;
  `pub mod` declarations gone from `lib.rs`. The four deprecation
  warnings that flagged the consumer sites are now silent because
  the code paths are gone.
- [x] **Persisted-tweak surface**. `<DLL_dir>/tweaks.json`
  written atomically on every successful `tweak_apply`; cleared
  per-entry by `tweak_revert`. Schema 1 envelope:
  `{schema_version, tweaks: [{table, field, kind, op, value}]}`.
  Game crates call `data_table::restore_persisted_at_init()` from
  their `on_unreal_init` worker after `discovery::run_at_load` to
  reload + reapply on every boot (and every Ctrl+R). Three new
  ops: `tweak_persisted_list`, `tweak_persisted_load`,
  `tweak_persisted_reapply`. No game crate has wired the boot
  hook yet; revisit when in-game smoke test reaches the tweak
  surface.
- [ ] **Replicated-field respect**. Some row fields are
  replicated to clients; writes during a server's authority
  drop get desynced. Defer until we hit a real case.
- [ ] **Non-primitive field types**. Writing `FString` /
  `TArray` rows needs the engine's `FMemory` allocator (ABI
  work). Defer until a real consumer needs it.

## P0. In-game smoke test

The full 2026-05-10 wave is build-clean and unit-tested but not
yet validated in-game. Acceptance gate (drive from your machine):

- Game launches; `grounded2_rpg.log` shows `ueforge` init lines.
- ImGui tab opens on `Insert`; RPG content renders.
- Load a save -> slot activate fires; tracker loads
  `<guid>.json`; backpack capacity reflects skill levels.
- Kill a creature -> kill_hook fires; XP increments; save updates.
- HTTP `/debug` endpoint responds to `op:snapshot` with non-empty
  state.

If any of that fails, triage from the log lines.

---

## Triggers Phase 5c: event-driven dispatch (SHIPPED 2026-05-11)

Five commits land the lift (3516276..2b2c66d):

- [x] Real `KillEvent` / `FallEvent` types; drop the three
  `*EventStub` placeholders.
- [x] Four new framework TriggerDefs: `ON_DAMAGE_DEALT`,
  `ON_DAMAGE_TAKEN`, `ON_KILL`, `ON_FALL`. `TriggerCtx::
  DamageDealt / DamageTaken` reuse `damage::DamageEvent`.
- [x] `Tracker::fire(ctx)` dispatch. Walks catalog under one
  lock, snapshots `(skill, level)` pairs to a 32-slot stack
  array, drops the lock, then fires `Effect::apply` outside
  the lock so re-entry is safe. Zero heap allocs.
- [x] Framework `ueforge::fall::FallHook<B>` mirroring
  `damage::DamageHook`. PE-install + OnLanded filter + Velocity.Z
  snapshot. `FallEvent.cmc` exposed so binders/effects can
  write Velocity.Z without re-resolving offsets.
- [x] g2rpg/fall_hook.rs migrated to a thin G2FallBinder.
- [x] g2rpg/kill_hook.rs `G2DamageBinder` fires
  `TRACKER.fire(DamageDealt | DamageTaken | Kill)` at the
  pre/post slots; lost ~70 LoC of inline apply_lifesteal +
  apply_impact_resistance_reversal.
- [x] Catalog rows: `SKILL_LIFESTEAL` -> `trigger=ON_DAMAGE_DEALT`
  with `LifestealEffect`; `SKILL_IMPACT_RESISTANCE` ->
  `trigger=ON_DAMAGE_TAKEN` with `ImpactReversalEffect`. Drops
  two `RuntimeEffect` placeholders.
- [x] `Tracker::apply_one_unlocked` filters to OnSlotChange-
  kinded skills only. Event-driven Effects no longer get
  spurious SlotChange fires on activate / spend / refund /
  toggle.

Deferred from 5c:
- `TriggerCtx::Tick { dt }` has no firer (Periodic poller not
  yet built; defer until a periodic skill needs it).
- ueforge-side generic `FallVelocityStompEffect` for catalog
  use; G2's stomp lives in the binder because
  SKILL_FALL_RESISTANCE already uses ON_SLOT_CHANGE for CDO
  writes. Promoting to a second SkillDef is ugly UX; revisit
  if a second game wants the stomp.

In-game smoke test (P0 below) is the acceptance gate.

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

- [ ] **Sig-scan the four base offsets** instead of hardcoding.
  `ueforge/src/ue/offsets.rs` STEAM/XBOX blocks (`g_objects` /
  `g_names` / `g_world` / `process_event`). Every UE patch shifts
  these and ships a code update from us. UE4SS upstream has
  working signatures to copy. Highest-leverage 10-year-bar item
  in the framework.
- [ ] **Generic schema versioning baked into `SlotStore`**, not
  per-consumer. `SkillsState` carries `schema_version` today;
  the planned `BuildingsTracker` would re-invent it. Envelope:
  `{schema_version, payload}` with a `Migrate` trait the
  consumer implements.
- [ ] **Hot-reload torture test.** 1000x Ctrl+R loop with hooks
  installed; assert no thread leak, hook leak, slot regression.
  Path is "tested once" today. Requires running game; gated on
  in-game test harness.
- [ ] **Annotate the 271 existing unsafe blocks** with `// SAFETY:`
  comments. Lint is `warn` workspace-wide (`Cargo.toml`
  `[workspace.lints.clippy]`); flip to `deny` when the count
  reaches zero. Track via
  `cargo clippy --workspace 2>&1 | rg -c "unsafe block missing a safety comment"`.

## P2. Ueforge grooming

- [x] **Hex codec -> `hex` crate.** `ueforge/src/hex.rs` deleted;
  `hex = "0.4"` added to workspace deps; consumers map the new
  `FromHexError` to String via `.map_err`. ~30 LoC saved.
- [x] **Jittered backoff in `hook/install.rs`.** Inline +/-25%
  jitter on every retry sleep. Seed is `Instant::now().elapsed()
  .subsec_nanos()` passed through one xorshift; no rand-crate
  dep. Unit test asserts every sample over 500 trials stays in
  range.
- [x] **PE queue oneshot via `crossbeam_channel::bounded(1)`**.
  Swapped from `std::sync::mpsc::channel`. Bounded(1) is the
  canonical oneshot shape: drain side sends once, enqueue side
  recv's once, single-slot allocation.
- [x] **`region` crate** (partial). Three of the six VirtualQuery
  / VirtualProtect call sites migrated to the `region` crate:
  `hook/vtable.rs::write_slot` (`protect_with_handle` RAII guard
  replacing the two-step VirtualProtect dance),
  `winproc.rs::is_addr_readable` (cheap committed + not-guarded
  + not-NOACCESS check used on hot UE traversal paths), and
  `scanner.rs::is_writable` (range fits within committed
  writable region). The remaining three sites
  (`scanner.rs::iter_private_rw_regions` +
  `winproc.rs::process_regions_json` + the
  `hook/process_event.rs:208` log string) stay on raw
  VirtualQuery: they need MEM_PRIVATE vs MEM_IMAGE vs MEM_MAPPED
  distinctions which the `region` crate's public API does not
  surface in v3.
- [x] **Reentrance proof test.** `pe_queue` now ships four tests:
  drain_empty_is_noop, enqueue_then_drain_returns_result,
  reentrant_drain_is_skipped (the documented contract proof), and
  cancelled_jobs_are_skipped.
- [x] **Vendor SDK header / document Dumper-7 invocation.** The
  ue/offsets.rs header now documents how to regenerate offsets
  (run Dumper-7, read Basic.hpp + UE4SS Signatures.cpp) rather
  than referencing an author-machine path. Vendoring the actual
  Basic.hpp is deferred since it's a per-game artifact tied to
  Grounded 2's specific UE 5.4 build, not a framework asset.
- [ ] **UE-version-aware `ffield` / `fproperty` / `ustruct`
  offsets.** Hardcoded for UE 5.4 in `ue/offsets.rs`. UE 5.5+
  silently returns wrong names. Pair with the sig-scan work.
- [ ] **Fuzz / property tests on walkers.** `TArray`, `TMap`,
  `FieldTweak`, `inspect_address`, `Val::from_json`. Today's
  `MAX_LINEAR_SCAN = 65_536` is an iteration cap; bound time, not
  iterations.
- [ ] **`UE4SS.lib` build-time symbol-presence check.** Parse
  `dumpbin /exports`, assert on the ~10 symbols we use.
- [ ] **`tiny_http` / `ureq 2` migration window.** Both on a 2-5
  year support horizon.
- [ ] **PE hook trampoline linear search.** Index by vtable
  pointer when 6+ hooks are installed.
- [x] **`find_by_short_name` cache.** RwLock<HashMap> mirrors
  `find_class_fast`'s shape; UDataTable instances are stable in
  GObjects for the process lifetime so a hit is permanent. Misses
  are NOT cached.
- [x] **Op latency + scan duration metrics.** `OpRegistry::
  dispatch` now records `(calls, errors, total_ns, max_ns)` per
  op name; new `op_metrics` debug op returns the snapshot sorted
  by total_ns descending. Scan duration is implicitly covered
  (scan_memory routes through dispatch).
- [x] **Cancellation token on `scan_memory` / long ops.**
  `scanner::SCAN_CANCEL: AtomicBool` checked at every 64 KiB
  chunk boundary; new `scan_cancel` op flips it. Worst-case
  latency between op call and abort is one ReadProcessMemory
  call (typically sub-ms). scan returns `cancelled: bool` in
  its response.
- [x] **`DLL_HMODULE` happens-before `dll_dir()` callers.** New
  `log::dll_dir_wait(timeout)` polls the atomic every 1ms up to
  the configured timeout. Workers that may race DllMain call
  this instead of the non-blocking `dll_dir()`.

## ueforge framework. Wave E (deferred until needed)

- [ ] **Global ProcessEvent pre-callback.**
  `RegisterProcessEventPreCallback` wrapper +
  `Queue::install_drain` helper. Land when status-effect
  migration needs a guaranteed drain site.
- [ ] **`AddUObjectCreateListener` integration.** Land when
  ows-tweaks or g2rpg's CDO-revert-replay scenario asks. ~100 LoC.

## ueforge framework. Still-open extractions

- [ ] **Leak-source helpers** -- `explore_leak_source.rs` (350
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

The next opinionated module. Lets a mod add **custom content**
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

**Phase A: research (no code).**

- [ ] **A1: Grounded 2.** Find the build system entry points
  via the SDK. Likely candidates: `UProductionBuilding`,
  `BP_Building*`, `UBuildingPlacementComponent`,
  `UCraftingComponent`. Identify which UClass defines a
  "placeable building", which UFunction spawns one, how the
  cost is charged, whether there's a build-menu data table to
  extend, how instance state replicates / persists, and the
  save shape.
- [ ] **A2: Outworld Station.** Same audit. The trait surface
  needs to fit both.
- [ ] **A3: Storage / inventory transfer.** For auto-farming
  to land items into a chest, identify the game's "add item to
  inventory" UFunction.

**Phase B: design lock-in.** Trait surface against the two
games' constraints. Pick the handle type (UObject address vs
mod-generated FGuid), storage location, tick model.

**Phase C: framework implementation.**

- [ ] C1: `ueforge::buildings::BuildingDef<S, C>` + catalog row.
- [ ] C2: `BuildingsTracker<S, C, Sp>` with `activate_slot` /
  `deactivate_slot` + persistence via `SlotStore`.
- [ ] C3: `BuildingSpawner` trait + game-impl skeleton.
- [ ] C4: Tick scheduler.
- [ ] C5: `ueforge::buildings::ops` standard debug ops.
- [ ] C6: `ueforge::buildings::tab::render` ImGui template.

**Phase D: g2rpg consumer (proof of concept).**

- [ ] D1: One concrete buildable. The
  **auto-fiber-harvester** (yields plant fibers at a configured
  rate, per-instance `{accumulated_units, last_yield}` state,
  transfers to nearest storage on threshold).
- [ ] D2: Catalog row in `grounded2-rpg/src/buildings/catalog.rs`.
- [ ] D3: G2 spawner impl.
- [ ] D4: ImGui "Buildings" tab.

**Phase E: tests.** Pester-style scenario DSL extended for
buildings (e.g.
`scenario::for_building(api, "auto_harvester").placed_at(loc).advanced_time(60s).should_yield_at_least(10, "plant_fiber")`).

### Open design questions (decide during Phase A/B)

- **Handle type.** UObject address (stable while game is running,
  invalid across saves) vs mod-generated FGuid (stable across
  saves, requires translation). Likely: FGuid for persistence +
  separate live UObject cache.
- **Asset references.** v1 reuses vanilla assets (less moving
  parts); pak-side custom assets land later.
- **Build-mode integration.** v1 ships ImGui-only spawn (lower
  risk). Vanilla-menu integration is Phase D+1.
- **Multiplayer.** Out of scope for v1. Single-player / host-only.
- **Tick clock.** Game-time vs real-time. Save-and-quit
  shouldn't run the farm for 8 hours when you reload. Use
  game-time OR clamp dt to `min(real_dt, configured_max_dt)`.
- **Network authority.** Yields go through the game's
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

- [ ] **Critical Chance + Critical Damage.** `before` callback
  on the live damage hook returns `Some(damage * (1 + crit))` on
  roll. RNG needs a per-mod seed; reuse `rand` crate.
- [ ] **Evasion / Dodge.** `before` returns `Some(0.0)` on roll
  for player-taken hits.
- [ ] **Thorns.** `after` resolves the attacker's HC (instigator
  -> controller -> possessed pawn -> HC at +0x1340) and writes
  `event.damage * thorns_fraction` to its CurrentDamage. Same
  healing pattern proven via Lifesteal.
- [ ] **Leap Distance**. LANDED untested
  (`PlayerMovementMult` over AirControl trio).
- [ ] **Auto-pickup (range).** Per-frame proximity scan picks up
  loose items. Open design: mechanism (existing proximity-pickup
  field vs per-frame scan), filter (which items qualify),
  throttle, multiplayer authority.
- [ ] **Stamina Pool + Stamina Regen.** `UStaminaComponent` on
  ASurvivalCharacter at +0x1358; offsets need a Dumper-7 dive.
- [ ] **Gear Hardiness.** Find durability-loss-per-use field;
  per-item durability scaling.
- [ ] **Climb Speed.** May or may not exist as a separate
  CharMovement field; check before adding.
- [ ] **Collision / Impact Damage Resistance.** Reduce / negate
  the lethal self-damage from slamming into plants / terrain.
  Likely home: live damage hook surface.

Catalog target: ~25 skills. Today: 13.

## g2rpg. Live-instance writes

Some combat-side skills still write only to player CDOs.
Movement now mirrors onto the live player pawn; remaining
combat effects need the same. Each `SkillEffect` variant grows a
"live walk" arm analogous to its CDO walk.

## g2rpg. Pkg(0) instigator bug

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

- [ ] **Optimize the discovery test.**
  `tests/explore_status_effect_rows.rs`. Batch read_bytes (one
  big chunk) so it runs in seconds. Capture FName for each row.
- [ ] **Pick target row per stat type.**
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

- [ ] **Vortex / Nexus packaging.** `cargo deploy package`
  produces the right zip layout. Need a Nexus listing
  (description, screenshots, mod page).
- [ ] **Project rename.** "grounded2-rpg" no longer fits when
  the mod is an RPG / level-up system. Candidates:
  `grounded-rpg`, `g2-rpg`, `groundlevel`, `instar`,
  `huntmaster`. Touches: Cargo.toml package name, workspace
  dir, settings file path, log header, README, Vortex zip name.

## g2rpg. Feature ideas (not yet scoped)

- [ ] **Auto-farming buildings.** First concrete consumer of the
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

- [ ] **High-frequency drain site for the PE queue.**
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

## Open: hot-reload the mod DLL while the game is running

Phase B (in-DLL teardown of hooks / servers / settings watchers
+ side-file rename) shipped 2026-05-10. End-to-end:
edit -> `cargo deploy install` -> Ctrl+R in-game -> ~1-2s per
iteration. State on disk (save slots, settings, catalog
progress) survives. See
[`../ueforge/docs/lifecycle.md`](../ueforge/docs/lifecycle.md)
"Phase B complete".

Optional follow-ups (defer until needed):

- [ ] **Phase B+: programmatic Ctrl+R from `cargo deploy install
  --hot`.** Mod watches a sentinel file; on change, synthesizes
  Ctrl+R via UE4SS's `register_keydown_event`.
- [ ] **Phase B++: HTTP `reload` op** that calls
  `UE4SSProgram::queue_reinstall_mods` directly. Smaller side
  trip.
