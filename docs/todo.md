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
> Roughly ordered by leverage. "Mid" priority items below the
> line are not blocking; pick from the top of the list when
> starting a new session.

---

## Open: priority 0

### Smoke-test the dedup wave in-game

The ~13-commit dedup session of 2026-05-10 (see
[changelog.md](changelog.md) "ueforge as full UE-mod framework")
is build-clean release but **not validated in-game yet**.

Acceptance gate (drive from your machine):

- Game launches; `grounded2_rpg.log` shows `ueforge` init lines.
- ImGui tab opens on `Insert`; RPG content renders.
- Load a save -> slot activate fires; tracker loads
  `<guid>.json`; backpack capacity reflects skill levels.
- Kill a creature -> kill_hook fires; XP increments; save updates.
- HTTP `/debug` endpoint responds to `op:snapshot` with non-empty state.

If any of that fails, triage from the log lines.

---

## Closed: ueforge hardening (kovarex P0) -- 2026-05-10

Save-data durability + shutdown safety. All four P0s shipped:

- [x] **`SlotStore::save -> io::Result<()>` + surface error.**
  Returns `Result`; tracker callers `let _ =` and rely on the
  store's cached `last_error` (exposed via
  `Tracker::last_save_error`) for snapshot surfaces. 4 unit
  tests on save/load/round-trip + parent creation.
- [x] **`fsync` the temp file before rename.** `save_atomic`
  now opens the temp explicitly, writes, calls `sync_all()`,
  then renames. Atomic rename is now also durable across
  power loss.
- [x] **Slot path validation.** Reject empty / leading dot /
  path separators (`/`, `\`, `:`, `\0`) in slot keys; route
  invalid keys to a sentinel `__invalid__.json` filename so
  malformed input is visible instead of silently writing
  somewhere unexpected. (Was P1; landed alongside the P0 fixes.)
- [x] **`SlotPoller::Handle` + shutdown-on-`on_shutdown`.**
  `SlotPoller::spawn` now returns `PollerHandle`. Worker is
  named `ueforge/rpg/slot-poller` (visible to debuggers via
  `thread::Builder::name`). Worker checks an `Arc<AtomicBool>`
  stop flag every interval tick; bbp's `on_shutdown` calls
  `world_loader::shutdown()` to flip it. Hot-reload safe.
- [x] **`SlotPoller` panic visibility.** Each tick wraps
  resolve / activate / deactivate in `catch_unwind`. Panics
  are counted (`PollerHandle::panic_count`), the most recent
  payload is exposed via `last_panic()`, and the worker keeps
  running. bbp surfaces both via `world_loader::panic_count()`
  / `last_panic()` for the snapshot endpoint. Tests cover
  panic-recovery + clean-handle paths.
- [x] **Spend/refund transactional with persistence.**
  Removed `SkillsState::spend` / `refund` from the public
  API. The only path now is `Tracker<A>::spend_skill_points`
  / `refund_skill_points`, which mutate state and call
  `store.save()` under the same lock. Closes the kovarex
  trapdoor where a sloppy caller could mutate in-memory and
  forget to persist.

## Open: ueforge hardening (kovarex P1)

- [x] **`DisabledSkills` reads -> `ArcSwap`.** Reads now lock-
  free: `ArcSwap<HashSet<&'static str>>` snapshot + Arc clone
  per call. Writers clone-modify-publish through the writer
  mutex. ImGui per-row + apply per-CDO calls stay on the fast
  path even with frequent toggles. 4 unit tests.
- [x] **`Curve::level_for_xp` upper guard.** Added
  `MAX_LEVEL_LIMIT = 1024` const + `assert!` in `Curve::new`.
  10K-level mistakes become const-eval failures (in `static`
  context) or runtime panics (in dynamic context); legitimate
  RPG curves up to 1024 levels still pass.
- [x] **`SlotStore` slot-path validation.** DONE alongside
  P0; see kovarex P0 entries above.
- [x] **`schema_version: u32` on `SkillsState`.** Added
  `SCHEMA_VERSION` const + `schema_version` field on
  `SkillsState` with `#[serde(default = "default_schema_version")]`
  so older save files (which lack the field) load as v1.
  Hand-rolled `Default` impl emits the current version on
  fresh state.
- [ ] **IO failure-injection tests for `SlotStore`.** Fill-disk,
  permission-denied, partial-write. The 4 unit tests cover
  happy-path + slot validation; failure-injection still pending.
- [ ] **HTTP per-launch auth token.** Generate at server spawn,
  require in request header. ~20 LoC. Stops cross-process
  localhost actors from hitting `write_bytes` / `call`.

## Open: ueforge hardening (kovarex P2)

- [ ] **UE-version-aware offset tables.**
  `ueforge/src/ue/offsets.rs::ffield/fproperty/ustruct` are
  hardcoded for UE 5.4. UE 5.5+ silently returns wrong names.
- [ ] **`#[non_exhaustive]` on public structs.** `ModInfo`,
  `Tab`, `PlatformOffsets`, `server::Config`. Adding a field is
  a breaking change today.
- [ ] **`static_assert` on `mem::size_of::<FName>() == 8`.**
  `transmute_copy::<_, u64>` is silent corruption when UE
  changes layout.
- [ ] **`process_event_idx: 0x4C` is hardcoded.** Make it
  required, not defaulted.
- [ ] **Fuzz / property tests on walkers.** `TArray`, `TMap`,
  `FieldTweak`, `inspect_address`, `Val::from_json`.
- [ ] **`UE4SS.lib` build-time symbol-presence check.** Parse
  `dumpbin /exports`, assert on the ~10 symbols we use.
- [ ] **Hex codec -> `hex` crate.** ~30 LoC saved.
- [ ] **`tiny_http` / `ureq 2` migration window.** Both on a
  2-5 year support horizon.
- [ ] **PE hook trampoline linear search.** Index by vtable
  pointer when 6+ hooks are installed.
- [ ] **`find_by_short_name` cache.** Same shape as
  `find_class_fast` cache.
- [ ] **Op latency + scan duration metrics.** `counters.rs` has
  the primitives; nothing in the framework uses them.
- [ ] **Cancellation token on `scan_memory` / long ops.**
- [ ] **`DLL_HMODULE` happens-before `dll_dir()` callers.**
  Worker threads starting before `set_dll_module` see CWD.

## Open: ueforge framework (Wave E, deferred until needed)

- [ ] **Global ProcessEvent pre-callback.**
  `RegisterProcessEventPreCallback` wrapper + `Queue::install_drain`
  helper. Land when status-effect migration needs the
  guaranteed drain site.
- [ ] **`AddUObjectCreateListener` integration.** Land when
  ows-tweaks or g2rpg's CDO-revert-replay scenario asks. ~100 LoC.
- [x] **Phase 3 wave 2: g2rpg catalog migration** -- 9 of 13
  catalog skills route through `ueforge::rpg::std_effect::
  StandardEffect`; `apply_skill` shrunk from 11 arms to 4;
  ~570 LoC of duplicated apply / format dispatch deleted.
  Closed 2026-05-10.
- [x] **`ueforge::rpg::Bestiary`** -- per-creature XP table.
  Closed 2026-05-10.
- [x] **`ueforge::ue::field`** -- generic untyped UObject byte
  ops. Closed 2026-05-10.
- [x] **`ueforge::ue::actor`** -- `class_chain_contains`,
  `controller_pawn`, `describe`, `A_CONTROLLER_PAWN_OFFSET`.
  Closed 2026-05-10.
- [x] **`FWeakObjectPtr::read` + `resolve`** -- index +
  GObjectsView walk folded into the existing struct.
  Closed 2026-05-10.
- [x] **`ueforge::debug` first wave** -- `PlayerStateView`,
  `CatalogEntry`, `catalog_view`, `STANDARD_OPS`. Closed
  2026-05-10.

## Open: more ueforge extraction candidates

- [x] **Settings hot-reload** -- `Settings::watch(interval, on_reload)`
  spawns an mtime-poller thread that re-reads + dispatches a
  callback on file change. `reload()` available standalone.
  Closed 2026-05-10.
- [x] **PE-call helper** -- `ueforge::ue::pe_call::call_ufunction`
  wraps "find UFunction or error -> process_event with parm
  pointer" in one safe-typed call. Health and inventory
  executors use it; future ops in any UE5 mod do too.
  Closed 2026-05-10.
- [x] **OpRouter (PE-ops half)** -- `ueforge::debug::dispatch_pe_ops`
  handles `call`/`read_bytes`/`write_bytes` (the three standard
  ops that need a per-game instance resolver). Combined with
  `dispatch_standard_op` already present, every standard op now
  routes through ueforge with one line per group.
  Closed 2026-05-10.

- [x] **Pillar 4: Inventory viewport-paging framework** --
  `ueforge::inventory::viewport::ViewportHook<B>` +
  `ViewportConfig` + `ViewportBinder` trait. Algorithm + state
  + hook trampoline + mouse-wheel handling + synthetic-refresh
  guard + post-refresh rebind all framework-side; game crate
  writes a thin binder + UFunction wiring. g2rpg's `inv_hook`
  shrank 396 -> 220 lines. Closed 2026-05-10.

Still open / deferred:

- Damage-hook framework (kill_hook install + per-fn parm-shape
  decoder scaffold). The Maine-specific KillerKind / FDamageInfo
  parsing stays game-side; defer the scaffold lift until a
  second UE5 game wants damage hooks.
- Status-effect discovery enumerators (`fall_hook` row-walking).
  `StandardEffect::StatusEffect` covers the apply path; the
  enumerators are research scaffolding and likely game-specific.
- HUD overlay drawing (DX11 hook for in-world rendering). Big
  lift, no second consumer today, defer.
- Inventory CRUD ops (add / remove / count / list). Pillar 4
  shape exists; CRUD lands when a second consumer materializes
  (g2rpg uses BPF helpers; another game's UFunction names will
  drive the trait surface).

---

## Open: g2rpg -- RPG catalog expansion

Each entry is one [`skills::CATALOG`](../grounded2-rpg/src/rpg/skills.rs)
row of an existing `SkillEffect` shape unless noted.

- [ ] **Critical Chance + Critical Damage.** `Runtime` effect
  (rolled in kill_hook on each player-dealt hit). Multiply
  damage by `1 + crit_damage` on success. Need the live-damage
  hook (below).
- [ ] **Evasion / Dodge.** `Runtime` on player-taken hits. Roll
  on incoming damage, zero on success.
- [ ] **Lifesteal runtime.** Catalog entry exists; live hook
  to actually heal the player by a fraction of damage dealt
  was queued behind the registry refactor.
- [ ] **Leap Distance** -- LANDED untested
  (`PlayerMovementMult` over AirControl trio).
- [ ] **Auto-pickup (range).** Per-frame proximity scan picks
  up loose items. Open design: mechanism (existing
  proximity-pickup field vs per-frame scan), filter (which
  items qualify), throttle, multiplayer authority.
- [ ] **Stamina Pool + Stamina Regen.** `UStaminaComponent` on
  ASurvivalCharacter at +0x1358; offsets need a Dumper-7 dive.
- [ ] **Gear Hardiness.** Find durability-loss-per-use field;
  per-item durability scaling.
- [ ] **Thorns.** % of damage taken reflected. Same hook
  surface as evasion / lifesteal.
- [ ] **Climb Speed.** May or may not exist as a separate
  CharMovement field; check before adding.
- [ ] **Collision / Impact Damage Resistance.** Reduce / negate
  the lethal self-damage from slamming into plants / terrain.

Catalog target: ~25 skills. Today: 13.

## Open: g2rpg -- RPG live-damage hook (framework done; catalog rows pending)

**Framework landed 2026-05-10 as Pillar 5: `ueforge::damage::DamageHook`.**
g2rpg's `kill_hook.rs` is now a `DamageBinder` impl with
`before` / `after` callbacks on every multicast damage event.

**Lifesteal landed live**: heal player by `damage * 0.90 *
sqrt(level/100)` after every player-dealt non-player hit, via
direct CurrentDamage decrement. Toggle-aware, tracker-driven.

Pending catalog rows that this surface unlocks:

- [ ] **Critical Chance + Critical Damage.** `before` returns
  `Some(damage * (1 + crit_damage_fraction))` on roll. RNG
  needs a per-mod seed; reuse `rand` crate.
- [ ] **Evasion / Dodge.** `before` returns `Some(0.0)` on roll
  for player-taken hits.
- [ ] **Thorns.** `after` resolves the attacker's HC (instigator
  -> controller -> possessed pawn -> HC at +0x1340) and writes
  `event.damage * thorns_fraction` to its CurrentDamage.

Healing path proven via Lifesteal: walk
`PLAYER.first_live_static` -> follow `+0x1340` (HC) -> read
`CurrentDamage` at `+0x32C` -> clamp + write back. Same
pattern for Thorns against the attacker.

This surface is also the likely home for collision / impact
damage mitigation. See
[`../grounded2-rpg/docs/damage.md`](../grounded2-rpg/docs/damage.md).

## Open: g2rpg -- RPG live-instance writes

Some combat-side skills still write only to player CDOs.
Movement now mirrors onto the live player pawn; remaining
combat effects need the same. Each `SkillEffect` variant grows
a "live walk" arm analogous to its CDO walk.

## Open: g2rpg -- RPG pkg(0) instigator bug

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
3. Failing that, fall back heuristically (player in attack
   range + recently swung).

## Open: g2rpg -- status-effect migration (in progress)

Migrate Impact Damage Resistance and Lifesteal to the canonical
status-effect surface first; rest of catalog follows. Detail in
[`../grounded2-rpg/docs/damage.md`](../grounded2-rpg/docs/damage.md).

Concrete next steps:

- [ ] **Optimize the discovery test.** `tests/explore_status_effect_rows.rs`
  -- batch read_bytes (one big chunk) so it runs in seconds.
  Capture FName for each row.
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

Movement skills stay on direct CMC field writes -- the
status-effect surface doesn't expose movement parameters with
the granularity we use. Survival drains stay on
SurvivalComponent CDO writes.

## Open: g2rpg -- RPG tuning

Open until we play more.

- XP curve: is `100 * N^1.8` (cap 50) too steep / flat?
- Per-creature XP table: ~20 species with placeholder values.
  Expand and balance.
- Skill `max_bonus`: are the level-100 caps right?
- Level-up frequency vs catalog size: 50 levels = 50 points;
  catalog max-everything = ~225 points (9 skills × 25 avg).

## Open: g2rpg -- distribution

- [ ] **Vortex / Nexus packaging.** `cargo deploy package`
  produces the right zip layout. Need a Nexus listing
  (description, screenshots, mod page).
- [ ] **Project rename.** "grounded2-rpg" no longer fits when
  the mod is an RPG / level-up system. Candidates:
  `grounded-rpg`, `g2-rpg`, `groundlevel`, `instar`,
  `huntmaster`. Touches: Cargo.toml package name, workspace
  dir, settings file path, log header, README, Vortex zip name.

---

## Open: g2rpg -- integration testing

Reference design + test coverage principle:
[`../grounded2-rpg/docs/testing.md`](../grounded2-rpg/docs/testing.md)
+ [`../ueforge/docs/RESEARCH.md`](../ueforge/docs/RESEARCH.md)
"Test coverage principle".

### Read surface (snapshot fields)

- [ ] **dmg-trace ring buffer in snapshot** -- last N multicast
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
- [~] **simulate_consume_item** -- via `call` once we know
  TryUseItem signature on the player controller.
- [~] **simulate_kill / simulate_fall** -- test-side via `call`.
  Doable today.
- [~] **simulate_status_effect_add / _remove** -- via `call` on
  `UStatusEffectComponent::CreateAndAddEffect` once row handle
  layout is captured in a `#[repr(C)]` struct.
- [~] **set_xp / set_level** -- via `call` if a setter
  UFunction exists, or via direct field-write.
- [~] **clear_status_effects** -- via `call` or direct TArray
  write.

### Test coverage (per-skill principle)

For EACH catalog skill (×13):

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

## Open: feature ideas (not yet scoped)

- [ ] **Auto-farming buildings.** Player places a custom
  building that periodically yields a configured material into
  connected storage. Removes the farming grind for late-game.
  Open design questions:
  - **Surface**: a new buildable that registers as a normal
    building (so it integrates with build mode + saves), or an
    external overlay that ticks and posts items into a target
    chest. Built-in is more invasive but feels native.
  - **Item source**: which materials qualify? Plant fibers /
    resin always; rarer mats (boss drops, ant parts) gated by
    tier or by a player-set policy.
  - **Throttle**: yield/min as a function of building tier so
    upgrades have a place. Avoid trivializing the chase.
  - **Power / cost**: needs an input (water, electricity, food
    for a captured creature?) so it isn't a free ratchet.
  - **Multiplayer**: single-host vs replicated. Yield needs to
    be authority-side or it's a dupe.
  - **Reference**: vanilla Grounded 2 may already have a
    "production" building class -- check `UProductionBuilding`
    / `BP_Building*` subclasses for an existing skeleton to
    extend rather than building one from scratch.
  - **Test plan**: place building -> tick for N seconds ->
    verify storage has +M of the right item. Drive via the
    debug `/call` op + new test-side helpers
    (`simulate_advance_time`, `place_building`,
    `read_storage_contents`).

## Open: hot-reload the mod DLL while the game is running

### Why

Editing a mod and seeing the change requires close-game -> cargo
build -> cargo deploy install -> launch -> walk to the test scenario.
That's 60-180s per iteration. Hot-reload would cut it to ~5-15s
(rebuild + signal). For active framework + skill-tuning work,
this saves **hours per day**.

Even partial hot-reload (e.g. tab-render-only, or "rebuild +
unload + load fresh state") is a big win.

### Phase A: UE4SS-side research -- COMPLETE 2026-05-10

**Verdict: UE4SS hot-reload is fully supported for cpp mods today.
The mechanism is `Ctrl+R` (default) -> `queue_reinstall_mods()`
which destroys every CppMod (firing our shim's `uninstall_mod` ->
`~UespyMod` -> `ueforge_mod_shutdown`), `FreeLibrary`s our DLL,
re-reads disk, `LoadLibraryExW`s the new DLL, and re-runs the
full lifecycle. The disk file `main.dll` IS replaced between
unload and reload, so `cargo deploy install` while the game is
running just works -- IF our shutdown path properly tears down
hooks + threads before UE4SS unloads us.**

Concrete findings (all verified in `c:\code\RE-UE4SS\UE4SS\src`):

- **Hot-reload entry point**: `UE4SSProgram::queue_reinstall_mods()`
  at `src/UE4SSProgram.cpp:1634`.
  - Triggered by `Ctrl+<HotReloadKey>` (default `R`), gated by
    `settings_manager.General.EnableHotReloadSystem`
    (`UE4SS-settings.ini` General section).
  - Also wired to "Restart All Mods" buttons in the GUI
    (`GUI.cpp:113`, `LuaDebugger.cpp:3980`).
  - Per-mod reload exists (`queue_reinstall_mod`) but is typed
    `LuaMod*` -- cpp mods can only reload as a group.

- **Reload flow** (`UE4SSProgram.cpp:1634-1701`):
  1. `m_pause_events_processing = true`
  2. `uninstall_mods()` (`UE4SSProgram.cpp:1556`):
     - For each cpp mod: `mod->uninstall()` -> calls our shim's
       exported `uninstall_mod(m_mod)` -> `delete mod` ->
       `~UespyMod()` -> **calls `ueforge_mod_shutdown()` (our Rust
       on_shutdown callback runs here)**.
     - `m_mods.clear()` -> drops `unique_ptr<CppMod>` ->
       `~CppMod()` (`CppMod.cpp:211`) -> **`FreeLibrary(m_main_dll_module)`**
       -> our DLL detaches.
  3. Clears Lua-side keybinds + custom properties.
  4. `m_pause_events_processing = false`.
  5. `setup_mods()` -> rescans `mods.txt` + reloads disk (this
     is where the new `main.dll` gets picked up).
  6. `start_cpp_mods()` -> calls our shim's `start_mod()` -> new
     `UespyMod`.
  7. `fire_unreal_init_for_cpp_mods()` (if engine inited).
  8. `fire_program_start_for_cpp_mods()` (if program started).

- **Thread context surprise**: `queue_reinstall_mods` runs on
  the UE4SS event-loop thread (`UE4SS-UpdateThread`), which is
  **distinct from the game's UE thread**. PE trampolines fire on
  the game thread. So when our `on_shutdown` runs, the game
  thread may be mid-trampoline. We can't safely FreeLibrary
  until in-flight trampolines drain.

- **Lifecycle hooks the shim already wires**:
  - `~UespyMod()` -> `ueforge_mod_shutdown()` -- this is our
    cleanup window. Runs synchronously on UE4SS-UpdateThread
    BEFORE FreeLibrary.
  - `start_mod()` -> `new UespyMod()` -> `on_unreal_init` ->
    `ueforge_mod_unreal_init()`.

- **HMODULE ownership**: each CppMod owns its `m_main_dll_module`
  via `LoadLibraryExW` with `LOAD_LIBRARY_SEARCH_DLL_LOAD_DIR |
  LOAD_LIBRARY_SEARCH_DEFAULT_DIRS`. `~CppMod()` calls
  `FreeLibrary` + `RemoveDllDirectory` (cookie tracked).

- **Static-lifetime references**: `ClassRef` / `PlayerRef` /
  cached `&UFunction` pointers all point INTO the game process
  (UE binary + GObjects), not into our DLL. Reload re-runs init,
  re-resolves the lookups -- the new DLL's caches start fresh.
  No carry-over needed.

### Phase B: ueforge-side requirements (concrete from Phase A)

**The cleanup window is `on_shutdown` on the UE4SS-UpdateThread.
We have ~unbounded time there, but every PE trampoline + every
spawned thread must be torn down before we return.**

Per-system requirements:

1. **ProcessEvent vtable patches** (BLOCKER -- mishandled = game crash).
   - All hook handles today are `mem::forget`-ed. Must change.
   - Install sites: `kill_hook` (1 hook), `fall_hook` (multiple),
     `inv_hook` via `inventory::viewport::ViewportHook` (1 hook).
   - On `on_shutdown`:
     a. Atomically swap each patched vtable slot back to the
        engine's original (existing `ProcessEventHook::Drop`
        already does this via `vtable::write_slot` +
        VirtualProtect).
     b. After all swaps, **wait for in-flight trampolines to
        drain**. Use a per-trampoline "active calls"
        AtomicUsize incremented at trampoline entry, decremented
        at exit. Spin (with a max timeout, e.g. 500ms) until all
        return to 0.
     c. Trampolines should also check a `static SHUTTING_DOWN`
        AtomicBool and bail to original.call early if set, to
        speed quiescence.
   - **New ueforge surface**: a `static HookRegistry` collecting
     install handles with a `shutdown_all()` method that does
     swap-back + wait-for-drain. `install_immediate_or_log`
     should register into it.

2. **Spawned threads** (BLOCKER -- DLL can't unload while any of
   its code is on a thread's stack).
   - **`SlotPoller`** already has stop flag, bounded by
     poll_interval (~1s). g2rpg calls it. ✓
   - **`server::spawn`** (HTTP listener) -- `tiny_http` Server
     blocks on `recv`. Need a `WatchHandle`-style
     `stop()` + a non-blocking listener path or a
     `Server::unblock`. Currently NO stop signal.
   - **`worker::spawn`** -- the init worker. Already exits
     naturally after `init complete; worker thread exiting`.
     If reload happens during init, we have a small race window;
     accept the risk for v1 (init is fast).
   - **`Settings::watch`** -- has `WatchHandle`, drops to stop.
     Not adopted by g2rpg yet; would be on the cleanup list when
     adopted.
   - **PE Queue drain workers** -- the `DrainSite` is drained
     from PE trampolines, no own thread. After hooks uninstall
     + drain, no more drains fire. ✓

3. **DllMain DLL_PROCESS_DETACH**: runs on the unloader thread
   under loader lock. Cannot do game-thread work, cannot block
   on threads (would deadlock). Cleanup MUST happen in
   `on_shutdown` (which fires before FreeLibrary).

4. **Static state**: cleared automatically when the DLL unloads.
   Only matters that no thread is mid-call. The previous two
   bullets ensure this.

5. **Idempotent install**: not strictly required if (1)+(2)
   guarantee full cleanup, but defense-in-depth: every `install`
   path should be a no-op if already installed.

### Phase B implementation tasks (in order)

- [x] **B0: Side-file deploy + on_shutdown swap** -- DONE
  2026-05-10. Verified empirically (PowerShell rename + reload
  test). Two pieces shipped:
  - `cargo deploy install` writes to `main-new.dll` if
    `main.dll` already exists; first deploy writes `main.dll`
    directly. (`ueforge/src/bin/ueforge_deploy.rs`)
  - `ueforge_mod_shutdown` runs the game's `on_shutdown` then
    calls `mod_main::finalize_hot_reload_swap`: renames
    `main.dll` -> `main-old.dll` (`SHARE_DELETE` permits) +
    `main-new.dll` -> `main.dll` (vacant target). Rolls back
    step 1 if step 2 fails. Logs the swap.
    (`ueforge/src/mod_main.rs`)
  - `ueforge_mod_unreal_init` calls
    `mod_main::cleanup_old_dll` once on the new image's first
    init -- best-effort `remove(main-old.dll)`.
  - Caveat: this is necessary but **not sufficient** for safe
    Ctrl+R while PE hooks are installed. B1-B5 below still
    needed before Ctrl+R is safe with kill / fall / inv hooks
    live. Until then: side-file deploy works (no need to close
    the game to deploy), but you still need to close + reopen
    the game between iterations to actually pick up the new
    DLL safely.
- [x] **B1: `ueforge::hook::registry`** -- `register(hook)` /
  `register_many(hooks)` / `shutdown_all()`. Hook handles live
  in a `static Mutex<Vec<ProcessEventHook>>` instead of being
  `mem::forget`-ed. `shutdown_all` drops every handle (Drop
  restores the vtable slot + drains in-flight trampolines).
  Closed 2026-05-10.
- [x] **B2: `SHUTTING_DOWN` flag + `active_calls` counter** --
  `process_event::SHUTTING_DOWN: AtomicBool` short-circuits new
  trampoline fires to engine's original ProcessEvent. Each
  `Entry` carries `active_calls: AtomicUsize` incremented at
  trampoline entry / decremented at exit. Drop spins up to
  500ms for drain. Closed 2026-05-10.
- [x] **B3: `server::SpawnHandle` + `shutdown_all`** --
  `spawn` registers a handle (Server Arc + JoinHandle); handle's
  `stop()` calls `Server::unblock` then joins the listener.
  `shutdown_all()` clears the registry, dropping every handle.
  Closed 2026-05-10.
- [x] **B4: Wire `ueforge_mod_shutdown`** -- macro path in
  `mod_main.rs` now runs:
  1. game's `on_shutdown` (game-specific cleanup)
  2. `hook::shutdown_all()` (uninstall + drain)
  3. `server::shutdown_all()` (stop listeners + join)
  4. `mod_main::finalize_hot_reload_swap` (side-file rename).
  Closed 2026-05-10.
- [x] **B5: g2rpg-side adoption** -- `mem::forget` calls in
  g2rpg's `lib.rs::worker` replaced with
  `ueforge::hook::register` / `register_many`. Existing
  `install_immediate_or_log` already routes through the
  registry. Closed 2026-05-10.

### Phase C: design -- LOCKED IN

UE4SS-native reload via Ctrl+R is the answer (Phase A confirmed).
Workflow: edit code -> `cargo deploy install` (file replace
while game runs) -> alt-tab to game -> Ctrl+R -> new DLL active
in ~1-2s. The `setup_mods()` step on UE4SS's side reads the new
`main.dll` from disk, so deploy + Ctrl+R is the complete cycle.

**No new ueforge UI / IPC surface needed for v1.** Phase B
implementation is the entire scope.

Optional Phase B+: ueforge ships a `cargo deploy install --hot`
that copies the DLL atomically + writes a sentinel file the mod
watches; on sentinel change the mod could trigger Ctrl+R
programmatically (UE4SS's `register_keydown_event` -- but
synthesizing keydown from a mod is a side trip; defer).

Optional Phase B++: drive Ctrl+R from the existing HTTP debug
endpoint (a `reload` op that calls
`UE4SSProgram::queue_reinstall_mods` directly via UE4SS's exposed
API). Smaller side trip. Defer.

### Phase D: acceptance criteria

For the first usable slice:

- `cargo deploy install` while the game is running replaces
  `main.dll` and re-applies the mod within ~5s.
- No game crash, no GPU hang, no leaked threads.
- All hooks re-installed cleanly (kill / fall / inv).
- Skill state preserved (read from disk on slot activate, like
  today).
- ImGui tab still renders.
- HTTP debug endpoint reachable on the same port.

### Open questions resolved (Phase A)

- ~~Static-lifetime references after reload~~: They point INTO
  the game process (UE binary + GObjects), not the DLL. Survive
  re-resolves on new DLL's first init. ✓
- ~~Rust panic + FreeLibrary~~: Phase B addresses via active-call
  counter. If a trampoline panics, the unwind runs to the
  trampoline boundary (the ProcessEventHook layer); the
  decrement-on-exit happens via Drop. We're fine as long as
  the hook layer's catch_unwind is in place (it is).
- ~~`function_table!` macro state~~: pure static per call site,
  re-inits on new DLL load. ✓ (no carry-over needed)

### Sequence

1. ~~Phase A research~~ -- DONE 2026-05-10.
2. ~~Update todo with concrete answers~~ -- DONE 2026-05-10.
3. Phase B implementation (B1-B5 above) -- next session.
4. ~~Phase C: pick an approach~~ -- DONE (UE4SS-native Ctrl+R).
5. Phase D: implement + smoke-test.

ROI: 60-180s -> ~5s per iteration. Hours per day on tuning
work. Very high.

---

## Out of scope (kept for reference)

- Visible 6-row inventory grow. Replaced by paged 4×10
  viewport with mouse-wheel scroll. Working.
- Multiplayer correctness for hunger/thirst. Stats almost
  certainly replicate server-authoritatively, so non-host
  clients won't see the effect. Document, don't fight.
- In-world UMG HUD overlay (always-visible XP bar). Out of v1
  scope; would need a custom DX11 hook or BPModLoader-shipped
  widget. ImGui tab is sufficient.
