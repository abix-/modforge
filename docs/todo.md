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

## Open: g2rpg -- RPG live-damage hook

Required by lifesteal / crit / evasion / thorns. Extend
`kill_hook`'s existing trampoline to handle non-killing hits:

- Read `Damage` parm at +0x18.
- Classify via `LastDamageInfo.InstigatorController`:
  - Player dealt: trigger Lifesteal (heal player by `damage *
    fraction`), Critical (multiply outgoing damage on roll).
  - Player took: trigger Evasion (zero damage on roll), Thorns
    (deal % back to attacker).

Healing path: walk live player pawn (R4 path), follow HC
ptr at +0x1340, decrement `CurrentDamage` at +0x32C, clamp 0.

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

## Open: hot-reload the DLL while game is running

Editing the mod and seeing the change requires
close-game -> deploy -> launch. UE4SS supports hot-reload in
some configurations; needs research:

- UE4SS's "reload mods" support for cpp mods (well-supported
  for Lua; cpp partial).
- Vtable patches via `ProcessEventHook` need to re-install on
  load AND properly unhook the old DLL's vtable patches before
  the new DLL installs its own.
- Idempotent install paths -- handle "already installed" by
  no-op so a reload that re-runs init doesn't double-hook.

Worth a spike. Dramatically speeds up iteration.

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
