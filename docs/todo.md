# TODO

> **Authoritative on:** open work. What's NEXT, not what's done.
> Completed milestones live in [`changelog.md`](changelog.md).
> Per-subject deep dives live in this `docs/` directory.

Roughly ordered by leverage. "Mid" priority items below the line
are not blocking; pick from the top of the list when starting a
new session.

---

## bbp dedup -- Phase 1 DONE (2026-05-10)

`better-backpack` consumes ueforge for every piece of generic
infrastructure. Net -930 LoC: deleted `cpp/shim.cpp`,
`src/rpg/ffi.rs`, `src/log.rs`, `src/sdk/`, `src/hook/`,
`winhttp.def`, custom DllMain + `better_backpack_start/stop`
exports, `DLL_HMODULE` static. Replaced with
`ueforge::ue4ss_mod!(MOD_INFO)`, a Rust ImGui render in
`src/rpg/tab.rs`, and a 1-line `build.rs`. Build-clean
validated; in-game smoke test pending.

**Phase 2 -- remaining promotions (next sessions):**

- [ ] **Promote the RPG framework to `ueforge::rpg`.**
  Generic `SkillEffect`, `Skills<T>`, sqrt curve, per-slot JSON
  persistence with a `slot_key()` closure, world_loader, disabled-
  skill set, `RpgTab` widget. After this lands, bbp's `rpg/`
  shrinks to catalog content + game-specific hook arms. Multi-
  session lift; unlocks RPG mods on any UE game.
- [ ] **Cached `&UFunction` identity dispatch helper.** Thin layer
  over `ProcessEventHook` so games stop reading function names on
  the hot path. Pattern lives in bbp `inv_hook` today.
- [ ] **Trampoline-as-drain-site helper.** `Queue::drain_in_trampoline`
  + doc the canonical drain-site choice. Pattern lives in bbp
  `kill_hook` today.
- [ ] **`patch::run` -> `ClassFieldTweak<T>`.** Live-UObject sibling
  of `FieldTweak<T>` -- one primitive replaces every "walk every X,
  mutate field at offset, filter by Y" pattern in any UE game.

## ueforge hardening (kovarex review, 2026-05-09)

End-to-end review of the framework against the 10-year / 100-user
bar. Items are ordered by criticality: P0 will crash users in the
field, P1 is silent rot or measurable resource bleed, P2 is
maintainability / future-proofing.

### P0 -- will crash users

- [x] **Address-relative freezes (kill raw-address freeze).**
  `ueforge/src/scanner.rs:415-426` writes blindly to `addr as *mut u8`
  every `1/hz` seconds with no check that the page is still mapped or
  still owned by the source object. UE recycles allocations; a
  multi-minute freeze on a stale address will fault the game. Replace
  the `freeze { addr, ... }` op with `freeze { selector, offset, type,
  value }`, resolve the selector each tick, log-and-skip on resolve
  failure. Also cache + recheck `VirtualQuery` page protection before
  every write.
- [x] **Mutex `unwrap()` density + `panic = "abort"` = hard crash on any
  poison.** `ueforge/src/scanner.rs:267,290,371,391,407,428,443,454`
  and `ueforge/src/hook/process_event.rs:109,117,136`. With
  `Cargo.toml:30 panic = "abort"`, one poisoned mutex on a worker
  thread aborts the game DLL with no log. Migrate to
  `parking_lot::Mutex` (no poison concept) across the framework. Also
  set `[profile.dev] panic = "unwind"` so research crashes leave a
  backtrace.
- [x] **`runtime().expect("sdk runtime not initialized")` on hot paths.**
  `ueforge/src/ue/uobject.rs:399`. Called from `UObject::name`,
  `process_event`, `iter_native_properties`, name resolution -- any
  of which can fire before `init_runtime` has set the OnceLock if a
  hook lands early. Replace consumer call sites with `try_runtime`
  + log-and-skip. Document the init ordering at the top of `ue/mod.rs`.

### P1 -- silent rot / resource bleed

- [x] **`FString` buffer leak on every FName -> String.**
  Capped via FName-keyed string cache in `NameResolver`. Each unique
  FName leaks one buffer, bounded by the game's name pool. Full
  `FMemory::Free` binding still available as future work.
- [~] **OLD bullet text below kept for traceability:**
  `ueforge/src/ue/fstring.rs:1-10` documents the leak. Every
  `find_class_fast`, `find_by_short_name`, `UObject::name`,
  `full_name`, `is_default_object` leaks ~`2 * len` bytes per call.
  Long sessions bleed MB. Bind UE4SS-exported `FMemory::Free` (already
  in `UE4SS.lib`) or call `delete[]` from a tiny helper compiled into
  `ueforge_ui.cpp`, and free the buffer in `FString`'s drop / after
  `as_string()`.
- [x] **`find_class_fast` cache.** Hits cached on first resolve; misses
  re-walk so a later call after the class loads still finds it.
  (`find_by_short_name` is a separate concern -- DataTable lookups by
  short name still walk; that's lower-impact since DTs resolve once at
  init in the on_first_sight pattern. Track separately if it shows up.)
- [ ] **`find_by_short_name` (DataTable) cache.** Same shape as the
  class cache; do when actually a hot path.
  `ueforge/src/ue/uobject.rs:424-440`,
  `ueforge/src/ue/datatable.rs:263-285`,
  `ueforge/src/selector.rs:59-81`. ~150K objects on OWS; every selector
  resolve walks the full array and calls `name()` (which leaks an
  FString -- see above). Add a lazy FName-keyed
  `OnceLock<HashMap<u64, &'static UClass>>` cache; UClasses are stable
  forever once seen.
- [x] **`inspect_address` allocates a `Vec<NativeProperty>` per
  super-class per call.** UClass now exposes `cached_native_properties`
  returning `Arc<[NativeProperty]>`; `locate_property` uses it. `ueforge/src/ue/uobject.rs:181-216` +
  `ueforge/src/ops.rs:206-229`. Click 20 rows in the Scanner UI =
  100-300 heap allocs and FName resolves on the render thread.
  Cache the property list per UClass in
  `OnceLock<HashMap<*const UClass, Arc<[NativeProperty]>>>`.
- [x] **`read_bytes` / `write_bytes` have no bounds vs the resolved
  object.** `ueforge/src/ops.rs:90-134`. The 1MiB cap bounds size,
  not location -- a malformed selector + offset reads from any
  address. When the class is known, clamp `offset + length <=
  class.properties_size()`.
- [ ] **PE hook trampoline does linear search per dispatch.**
  `ueforge/src/hook/process_event.rs:155-158`. Engine fires
  ProcessEvent thousands of times per second; the `.find()` over
  `SNAPSHOT` is fine for 2-3 hooks, measurable at 6+. Index by
  vtable pointer.
- [x] **Replace hand-rolled `SNAPSHOT` + `Box::leak` with
  `arc_swap::ArcSwap`.** `ueforge/src/hook/process_event.rs:46-64`.
  Each install/drop leaks a previous snapshot; standard answer is
  one well-tested crate. ~5 lines vs ~30, no leak.
- [x] **Stop panicking in test client / perf log.**
  `ueforge/src/client/perf.rs:83`,
  `ueforge/src/client/mod.rs:90,108,110`. A library shouldn't
  `panic!` on POST or file-open failure -- return `Result`. Test
  callers can `.unwrap()` themselves.
- [x] **`tmap::slots` / `MAX_LINEAR_SCAN = 8192` magic cap.**
  `ueforge/src/ue/tmap.rs:40-45`,
  `ueforge/src/ue/offsets.rs:157`. Real-game DataTables can exceed
  8192 rows; the iterator silently truncates. Either lift the cap
  and trust the engine header, or surface a "truncated" flag.
- [x] **Long scans hold `SESSIONS` mutex across the walk.**
  `ueforge/src/scanner.rs:264-273`. Multi-second scans block every
  other scanner op behind the listener thread. Take the snapshot
  of regions outside the lock; only re-acquire to insert the
  finished session.

### P2 -- future-proofing / maintainability

- [ ] **No unit tests on framework primitives.** Hex codec
  (`hex.rs`), arg parsers (`args.rs`), `Val::from_json`
  (`scanner.rs`), `tmap::slots` parsing, `FieldTweak` idempotency,
  queue drain stats / re-entrance. The TDD doctrine in
  `ueforge/README.md` is aspirational; the framework itself has zero
  `#[test]`. Land the obvious round-trip + boundary tests.
- [ ] **UE-version-aware offset tables.** `ueforge/src/ue/offsets.rs`
  `ffield`, `fproperty`, `ustruct` constants are hardcoded for UE
  5.4. UE 5.5/5.6 are shipping; the property walker will return
  *wrong* names silently on those builds. Add `enum UeVersion` on
  `PlatformOffsets` and dispatch.
- [ ] **`#[non_exhaustive]` on public structs.** `ModInfo`, `Tab`,
  `PlatformOffsets`, `server::Config`. Today, adding a field is a
  breaking change for every downstream mod.
- [ ] **`FName` `transmute_copy<u64>` assumes layout forever.**
  `ueforge/src/ops.rs:194`,
  `ueforge/src/ue/datatable.rs:39`. UE has changed FName before;
  document or guard.
- [ ] **Replace hand-rolled hex codec with the `hex` crate.**
  `ueforge/src/hex.rs`. ~30 lines saved; one less surface for bugs.
- [ ] **Op latency + scan duration metrics.** `counters.rs` already
  ships the primitives; nothing in the framework uses them. Add
  per-op time + queue depth counters.
- [ ] **Cancellation token on `scan_memory` / long ops.** No way to
  cancel a multi-second scan today -- it monopolizes the listener
  thread.
- [ ] **`DLL_HMODULE` happens-before `dll_dir()` callers.**
  `ueforge/src/log.rs:62-63`. Worker threads that start before
  `set_dll_module` runs in `DllMain` see `dll_dir() = None` and the
  log file lands in CWD. Document the ordering, or guard with a
  one-shot wait.
- [ ] **Plan a `tiny_http` / `ureq 2` migration window.** Both are
  on a 2-5 year support horizon. `ureq 3` is already a rewrite. Not
  urgent, but pin a quarter to do it before the upstream drops
  security fixes for v2.

## RPG: catalog expansion

The next batch of skills to add. Each entry is one
[`skills.rs::CATALOG`](../better-backpack/src/rpg/skills.rs) row of
an existing `SkillEffect` shape (no new variants required).
Registry refactor done; adding a skill is now ~5 lines.

- [ ] **Critical Chance + Critical Damage.** `Runtime` effect
  (rolled in the kill_hook on each player-dealt hit). Multiply
  damage by 1 + crit_damage on a successful crit roll. Need a
  damage-path hook in kill_hook (see "Live damage hook" below).
- [ ] **Evasion / Dodge.** `Runtime` effect on player-taken hits.
  Roll on incoming damage, zero it out on success. Same hook
  surface as crit + lifesteal.
- [ ] **Lifesteal runtime.** Catalog entry exists; the live hook
  in kill_hook to actually heal the player by a fraction of
  damage dealt was queued behind the registry refactor. Pick up
  next: extend the existing kill_hook trampoline to also act on
  player-as-instigator events (not just KillingBlow), heal the
  player's live HealthComponent (write `CurrentDamage` at +0x32C,
  clamped at 0).
- [x] **Max Health.** Landed via new
  `SkillEffect::PlayerHealthCompAdditive` (offset +0x328). Captures
  vanilla once, writes `vanilla + max_bonus * progress` on CDOs +
  live pawn so the player stacks +HP additively. +200 HP at level
  100. Untested in-game.
- [x] **Health Regen.** Landed via new `SkillEffect::GlobalDataMult`
  pointed at `UGlobalCombatData` (offsets 0x010C tick percentage,
  0x0110 tick rate). Tick % scales with the bonus, tick rate scales
  inversely (more frequent ticks). Combat-regen delay left untouched.
  Untested in-game.
- [ ] **Leap Distance (DONE, untested).** Landed in the catalog via
  `PlayerMovementMult` over `AirControl` / `AirControlBoostMultiplier`
  / `AirControlBoostVelocityThreshold`. +500% at level 100.
  Untested in-game.
- [ ] **Auto-pickup (range).** Quality-of-life skill: the player
  automatically picks up nearby loose items (plants, fibers,
  resources on the ground) without needing to look at them and
  press E. Pickup radius scales with skill level: level 0 = 0
  (vanilla), level 100 = several meters. Open questions:
  - **Mechanism**: per-frame proximity scan that calls the
    existing PickupItem path on each eligible item, or a write
    to whatever proximity-pickup field already exists on
    ASurvivalCharacter / ItemPickupComponent? Check the SDK
    for an existing `AutoPickupRadius` or similar before adding
    a per-frame scan.
  - **Filter**: which items qualify? Open-world clutter (plant
    fibers, sap, resin) yes; equipped items / quest items / a
    just-dropped weapon a player chose to throw -- probably no.
    A blacklist on item-class or item-tag is the cheap version.
  - **Performance**: a tick that walks all loose items in N
    meters can be expensive in dense areas. Cap items-per-tick
    or sample radially from a few angles.
  - **Surface**: probably a new `Runtime` SkillEffect (no CDO
    write); kill_hook-equivalent trampoline reads the level
    each tick.
  - **Test plan**: spawn an item near the player ->
    snapshot.inventory contents before -> tick -> contents
    after. Drive via debug endpoint with new ops:
    `place_item_at_player_offset`, `read_inventory_contents`.
- [ ] **Stamina Pool + Stamina Regen.** `UStaminaComponent` on
  ASurvivalCharacter at +0x1358; offsets need a Dumper-7 dive.
- [ ] **Gear Hardiness.** Find the durability-loss-per-use field;
  per-item durability scaling. Possibly a damage-multiplier surface
  on the equipment component.
- [ ] **Thorns.** % of damage taken reflected. Same hook surface
  as evasion / lifesteal.
- [ ] **Climb Speed.** May or may not exist as a separate
  CharMovement field; check before adding.
- [ ] **Collision / Impact Damage Resistance.** New skill to
  reduce or negate the lethal self-damage from slamming into
  plants / terrain at very high movement speed. May share hook
  surface with other player-taken damage effects, but likely needs
  a specific classification path so normal enemy hits are not
  affected.

Catalog target: ~25 skills. Today: 13. War3FT had ~17, we collapse
to a flat menu so 25 is comfortable.

## RPG: live-instance writes

Some combat-side skills still write only to player CDOs.
Movement now mirrors onto the live player pawn, but the remaining
combat effects still need the same treatment so spending a point
feels immediate. Walk the live player pawn(s) on each apply and
write the same fields:

```text
World->GameState->PlayerArray[i]->PawnPrivate (APawn*)
  -> downcast to ABP_SurvivalPlayerCharacter_C*
  -> CharMovementComponent / HealthComponent / ...
  -> field at offset
```

This is the R4 follow-up that was deferred. With the registry
refactor, each `SkillEffect` variant grows a "live walk" arm
analogous to the CDO walk it already has. Movement already does
this now; combat still needs it.

## RPG: pkg(0) instigator bug

Some legitimate player kills attribute to `/Script/CoreUObject (Package)`
because `LastDamageInfo.InstigatorController` is an unset
FWeakObjectPtr (index=0 -> Package object). User loses XP for
those kills. See the Spike A section in
[`changelog.md`](changelog.md) for context.

Investigation:

1. Sample more kills with different weapons. Identify which
   attack types fail vs which succeed.
2. Hook `Maine.HealthComponent.ApplyDamageFromInfo`
   (`Maine_functions.cpp:138302`) to read the `FDamageInfo` parm
   at function entry and cache the instigator per HealthComponent.
   When `MulticastHandleEffectsWithDamageFlags` fires with
   KillingBlow, use the cached value if `LastDamageInfo` is null.
3. Failing that, fall back heuristically: if instigator is
   pkg(0) and the local player is within attack range of the
   dying actor + has swung a weapon recently, credit the player.

## RPG: live damage hook

Required by lifesteal / crit / evasion / thorns. Extend
`kill_hook`'s existing trampoline (which already runs on every
`MulticastHandleEffectsWithDamageFlags` call) to handle
non-killing hits too:

- Read `Damage` parm at +0x18.
- Classify via `LastDamageInfo.InstigatorController`:
  - Player dealt: trigger Lifesteal (heal player by `damage *
    fraction`), Critical (multiply outgoing damage on roll).
  - Player took: trigger Evasion (zero out damage on roll),
    Thorns (deal % back to attacker).

Healing path: walk the live player pawn (R4 path), follow the
HealthComponent ptr at +0x1340, decrement `CurrentDamage` at
+0x32C, clamp at 0.

This hook surface is also the likely home for collision / impact
damage mitigation. Plant / terrain collision uses
`DamageType = BP_EnvironmentalDamage_C` on `LastDamageInfo` (filterable
on the existing multicast hook), distinct from fall damage which has
its own pipeline -- see `rpg.md` for both internals.

## RPG: Impact Damage Resistance (FIXED 2026-05-09 evening)

Bug: with the previous binary mask, bandages were blocked. Now
fixed: impact_resistance is a `Runtime` effect that intercepts
`ApplyDamageFromInfo` on the player HC and scales damage by
`(1 - reduction * progress)` only when `FDamageInfo.DamageType`
is environmental. Bandages, creature combat, and fall damage are
all untouched. Per-level scaling. See `docs/damage.md` "LANDED
2026-05-09: impact_resistance is now Runtime + ApplyDamageFromInfo
intercept".



`SKILL_IMPACT_RESISTANCE` landed via a write to
`UHealthComponent.RequiredDamageTypeFlags` (+0x00FC, uint32) =
`0xFFFFFFFF` on player CDOs and the live pawn. Native ApplyDamage
gate consults the field, sees incoming `type_flags = 0` for fall /
environmental / hazard damage, no bit matches, damage rejected
before `CurrentDamage` is written. Validated in-game: rock
collision multicasts report `damage=0.00`.

**Caveat: the gate is binary.** Any level > 0 = full immunity,
level 0 = full damage. Does not scale on the `sqrt(level/100)`
curve the rest of the catalog uses. Migration to the proper
mechanism (status effects) tracked below.

## Status-effect migration: row inventory verified (2026-05-09)

Discovery test (`tests/explore_status_effect_rows.rs`) confirmed
every `EStatusEffectType` we need exists in `Table_StatusEffects`
with multiple candidate rows. Counts:

| Type | Name | Rows | Skill that wants it |
| ---- | ---- | ---- | ------------------- |
| 5    | MaxHealth | 18 | max_health |
| 14   | FallDamage | 7  | impact_resistance, fall_resistance |
| 23   | AttackDamage | 168 | attack_damage |
| 24   | Health | 116 | health_regen, AddHealth-equivalents |
| 29   | DamageReduction | 157 | armor |
| 30   | DamageReductionMultiplier | 4 | impact_resistance alt |
| 38   | LifeSteal | 11 | lifesteal |

We don't need to inject new rows; we'll reuse an existing one
per stat (mutating its `Value` at apply time before calling
`CreateAndAddEffect`).

Concrete next steps to land the fix:

- [ ] Optimize the discovery test: batch read_bytes (one big
  chunk) so it runs in seconds not minutes; capture FName for
  each row.
- [ ] Pick target row per stat type (lowest-impact / most-clearly-
  reservable name for our mod).
- [ ] Implement `SkillEffect::PlayerStatusEffect { row_name,
  base_value, max_value, ... }` variant in `skills.rs`.
- [ ] One generic apply arm in `apply.rs` that:
   1. Resolves Table_StatusEffects.
   2. Looks up the row by FName.
   3. Mutates the row's Value field to (max_value * progress).
   4. Calls `UStatusEffectComponent::CreateAndAddEffect` on the
      player's component with the row handle.
   5. On disable / level=0: removes the effect (or sets
      Value=0 then re-adds).
- [ ] Migrate `impact_resistance` first as proof of concept.
- [ ] Validate via the regression test: bandages must heal even
  with impact_resistance enabled. That's the bug fix.
- [ ] Migrate the rest of the catalog row-by-row.

## RPG: bandage HoT teaches us the canonical heal pattern (2026-05-09)

Research traced bandages to a status effect `BandageHoTTier1`:
`Type = EStatusEffectType::Health (24)`, `Value = 1.25` per tick,
modulated by `HealingReceived = 57` (1.15) for ~1.44 HP per
~250ms tick over ~3.5 seconds. Native code applies the HP gain
via the same pipeline that consults `RequiredDamageTypeFlags` --
which is why our binary mask blocks bandages.

This is the canonical Grounded 2 heal mechanism. Every skill we
add that grants HP should ride the same surface (apply a
`UStatusEffect` with `Type=Health` for HoT, `Type=MaxHealth=5`
for raw cap bumps, etc.) instead of poking native fields
directly. Beneficial side-effects: HealingReceived multipliers
auto-apply, gear/perk synergy works, multiplayer replication is
correct, no singleton-asset mutation.

**Concrete refactors** (each becomes a one-skill migration once
the status-effect apply path lands):

- [ ] `health_regen`: stop mutating `UGlobalCombatData`; apply a
  `UStatusEffect{Type=Health, Value=scaled_per_tick}` per slot
  activation, refreshed periodically. Detail in
  `docs/damage.md` "Reuse the same pattern for our health_regen
  skill".
- [ ] `max_health`: stop direct-writing `HC.MaxHealth`; apply
  `Type=MaxHealth (5)` status effect.
- [ ] `impact_resistance`: stop the binary
  `RequiredDamageTypeFlags = 0xFFFFFFFF`; apply
  `Type=DamageReductionMultiplier (30)` or `FallDamage (14)`.
  This is the bug-fix migration -- bandages stop being blocked
  the moment this lands.
- [ ] `lifesteal`: kill the runtime no-op; apply
  `Type=LifeSteal (38)`.
- [ ] `attack_damage`: stop direct-writing
  `ASC.CustomDamageMultiplier`; apply `Type=AttackDamage (23)`.
- [ ] `armor`: stop direct-writing `HC.BaseDamageReduction`;
  apply `Type=DamageReduction (29)` or
  `DamageReductionMultiplier (30)`.
- [ ] `fall_resistance`: keep the velocity-stomp (it's the
  validated mechanism); ALSO apply `Type=FallDamage (14)` for
  consistency and so the value is visible to anything that
  introspects player stats.

Movement skills (`move_speed`, `jump_height`, `glide_speed`,
`leap_distance`) stay on direct CMC field writes -- the
status-effect surface doesn't expose movement-component
parameters with the granularity we use.

Survival drains (`hunger`, `thirst`) similarly stay on the
SurvivalComponent CDO writes -- the status effect types
`HungerRate (17)` and `ThirstRate (18)` exist and could be used,
but the CDO write is simpler and battle-tested. Optional later
parity if convenient.

## RPG: Status-effect-backed skill rewrite (IN PROGRESS -- A1)

**Active work.** Migrating Impact Damage Resistance and Lifesteal
to the canonical status-effect surface first; the rest of the
catalog migrates after that pattern lands and is validated.



The canonical Grounded 2 surface for proportional, type-filtered,
stackable damage modifiers is `UStatusEffectComponent` on
`ASurvivalCharacter` at +0x1378. Native damage code calls
`GetValueForStatForDamageTypeFlags(StatType, Flags)` on every
damage event and uses the returned float as a multiplier. Every
skill in our catalog has a matching `EStatusEffectType` enum
value. See [`docs/damage.md`](damage.md) "Status Effect system"
for the full reference.

Migration plan:

1. **Locate `UStatusEffect` field layout** -- need offsets for the
   stat type field (`EStatusEffectType`) and the value float. Walk
   any default status effect on a live actor at runtime to derive.
2. **Add `SkillEffect::PlayerStatusEffect { stat_type, max_value,
   format }`** variant in `skills.rs`.
3. **`apply.rs` walks the live player `StatusEffectComponent`**,
   finds or creates a `UStatusEffect` for the given stat type, sets
   its value to `max_value * sqrt(level / 100)`.
4. **Migrate skills one at a time:**
   - `fall_resistance` -> `EStatusEffectType::FallDamage` (= 14)
   - `impact_resistance` -> `EStatusEffectType::DamageReductionMultiplier`
     (= 30) filtered by `type_flags = 0` (or use the same FallDamage
     entry if it covers all impact paths)
   - `lifesteal` -> `EStatusEffectType::LifeSteal` (= 38), removing
     the `Runtime` no-op
   - `armor` -> `EStatusEffectType::DamageReduction` (= 29) or
     `DamageReductionMultiplier` (= 30), removing the
     `BaseDamageReduction` write
   - `attack_damage` -> `EStatusEffectType::AttackDamage` (= 23),
     removing the `CustomDamageMultiplier` write
   - Future: crit (`CriticalHitChance` = 31, `CriticalDamage` =
     62), thorns (`ReflectDamage` = 37), max health
     (`MaxHealth` = 5), stun resist, etc.
5. **Remove the interim hacks** once each skill is migrated:
   `RequiredDamageTypeFlags` write from `apply.rs`, velocity-stomp
   from `fall_hook.rs`, the `Runtime` no-op for Lifesteal.

### Status-effect implementation choice (next decision point)

`UStatusEffect` is row-driven: it holds a `FDataTableRowHandle` at
+0x58 and reads `Type` / `Value` / etc. from the row each time the
component is queried. We cannot just allocate one and set its
value -- value is determined by the row. Implementation paths
(detail in `docs/damage.md` "UStatusEffect is row-driven"):

1. **Mutate an existing data-table row's `Value` field at runtime,
   then `CreateAndAddEffect(rowHandle)`**. Cheapest. Risk: row is
   shared, vanilla mods/items using the same row are affected.
2. **Find a benign / unused row to repurpose**. Same as (1) with
   smaller blast radius if such a row exists in the data tables.
3. **Inject a brand-new row into the `UDataTable`'s row map**.
   Most invasive, also most stable -- no collision with vanilla.
4. **Manual `UStatusEffect` subclass with overridden getters**.
   Heaviest; UE class manipulation at runtime.

**Validation done.** Probe ran in-game, returning both runtime
values and combine semantics (`/add` or `/mul`) per stat:

```
FallDamage(14)=1.000/mul        DamageReduction(29)=1.000/mul
DamageReductionMultiplier(30)=0.000/add
AttackDamage(23)=1.210/mul      LifeSteal(38)=0.000/add
CriticalHitChance(31)=0.060/add CriticalDamage(62)=0.000/add
ReflectDamage(37)=0.000/add     MaxHealth(5)=30.000/add
```

`EStatusEffectValueType` is `{None=0, Add=1, Multiply=2}`. Vanilla
baseline is `1.0` for `mul` stats and `0.0` for `add` stats. Per-stat
write formulas are in `docs/damage.md` "Stat semantics table".

**Vanilla data table identified.** Probe of the player's
StatusEffects array shows every status effect in the game flows
through `/Game/Blueprints/Attacks/Table_StatusEffects.Table_StatusEffects`.
~10 active rows visible on a mid-game player (PlayerUpgradeHealth1,
WeaponClub, MaxHealthSmall, etc., per `damage.md` "Vanilla data
table identified").

**Concrete next step: implement the apply step.** Plan in
`damage.md` "Implementation plan":

1. Resolve `Table_StatusEffects` (follow any existing row handle
   on the player; no GObjects scan needed).
2. Enumerate rows via `UDataTableFunctionLibrary::GetDataTableRowNames`
   + `GetDataTableRowFromName`, find or pick a row per skill's
   target stat.
3. Mutate the row's `Value` to skill-scaled value, build a row
   handle, call `CreateAndAddEffect` on the player's
   `UStatusEffectComponent` via `process_event`.
4. On level change, rewrite Value. On slot deactivate, RemoveEffect.

Migrate one skill first as a proof of concept --
`fall_resistance` is the lowest-risk because we already have the
velocity-stomp as a fallback if anything misbehaves. If the
status-effect contribution drives `FallDamage` from `1.0` toward
`0.0` and we observe reduced damage in the multicast trace, the
pattern is proven and the rest of the catalog follows.

## RPG: tuning

Open until we play more.

- XP curve: is `100 * N^1.8` (cap 50) too steep / too flat?
- Per-creature XP table: today ~20 species with placeholder
  values. Expand and balance.
- Skill `max_bonus` per skill: are the level-100 caps right?
  Backpack +460 slots feels right; Attack Damage / Move Speed /
  Jump Height / Glide Speed now all cap at +300%, Fall Damage
  Resistance at 100%, Lifesteal at 90%. Validate those against
  real play.
- Level-up frequency vs catalog size: 50 levels = 50 points,
  catalog max-everything = ~225 points (9 skills * 25 avg).
  Roughly 22% of catalog at max level. Too generous? Too tight?
  Tune.

## Distribution

- [ ] **Vortex / Nexus packaging.** `deploy.ps1`'s
  `-Package` mode produces a Vortex-installable zip with the
  right `Augusta/Binaries/WinGRTS/ue4ss/Mods/BetterBackpack/`
  layout. Need a Nexus listing (description, screenshots, mod
  page metadata). UE4SS for Grounded 2 is a Vortex mod, so
  ours rides on that.
- [ ] **Project rename.** "better-backpack" / "BetterBackpack" /
  Vortex zip name no longer fits when the mod is an RPG /
  level-up system. Candidates: `grounded-rpg`, `g2-rpg`,
  `groundlevel`, `instar`, `huntmaster`. Touches: Cargo.toml
  package name, workspace dir, settings file path, BetterBackpackMod
  C++ class name, log header, README, Vortex zip name.
- [x] **Archive winhttp proxy.** `better-backpack-cpp/` moved to
  `archive/winhttp-proxy/`. Unique Grounded 2 internals were
  ported into the authoritative subject docs first
  (`docs/inventory.md`, `docs/grounded-engine.md`). Kept as a
  reference / fallback if UE4SS ever turns out unstable.

## Integration testing (debug HTTP endpoint + Rust tests)

The bandage regression took multiple in-game cycles to find because
we had no way to drive the mod programmatically and assert state.
Build a debug surface so future bugs of this shape get caught by a
test, not by the player noticing.

### Design

- **One generic command-shaped endpoint**: `POST /debug` taking
  `{op, args}`, always returning `{ok, state, result}` where `state`
  is the **full game-state snapshot** (skills, toggle flags,
  captured vanilla baselines, live HC field reads at the offsets
  we touch, sfx-list, recent dmg-trace ring).
- **Rust integration tests** in `better-backpack/tests/integration/`,
  one file per scenario, each a separate `#[test]` binary. Shared
  `common::Api` wrapper over reqwest blocking client. Runs against
  a live game (user launches Grounded 2 + loads a save first).
- **Settings flag**: `debug.http_port: Option<u16>` (None disables).
  Production builds ship with the port off.
- **Thread safety**: HTTP server on its own worker thread. Reads
  pull from the snapshot path (UObject memory reads, already safe
  off-thread). Writes that need ProcessEvent get queued onto a
  game-thread surface -- drain inside `kill_hook`'s trampoline
  (fires every damage tick, guaranteed game thread). HTTP handler
  blocks on the queue draining before returning so callers see
  post-op state.

### Op set (initial)

| op | args | purpose |
| --- | --- | --- |
| `snapshot` | -- | no-op, just returns state |
| `skill_spend` | `{id, count}` | mirror the +N button |
| `skill_refund` | `{id, count}` | mirror the -N button |
| `skill_toggle` | `{id, enabled}` | mirror the on checkbox |
| `simulate_damage` | `{amount, type_flags}` | fire ApplyDamage on player HC |
| `simulate_heal` | `{amount}` | sugar: simulate_damage with negative amount + type_flags=0; the bandage repro |
| `reload_slot` | -- | re-trigger world_loader activate |

Adding an op = one more match arm + one more test scenario.

### Test coverage principle

**Every user-facing interaction and expectation gets an integration
test.** The control plane is what makes this affordable; the
discipline is the point. See
`~/.claude/skills/runtime-control-http/SKILL.md` "Test coverage
principle" for the cross-project rule.

For this mod, that means tests for:

- For EACH catalog skill: spend 1 -> max -> assert effect grows
  on the live target field(s).
- For EACH catalog skill: spend then refund -> assert effect
  reverts to vanilla.
- For EACH catalog skill: spend then toggle off -> assert effect
  reverts to vanilla.
- For EACH catalog skill: spend then toggle on -> assert effect
  is back.
- For EACH catalog skill: spend, simulate slot reload -> assert
  state persists.
- For EACH catalog skill: leave at 0 -> assert no effect.
- INTERACTIONS:
  - impact_resistance + bandage (the regression). Active blocks
    healing; off lets it through. **Critical fence.**
  - armor + bandage. BaseDamageReduction must not block heals.
  - Every other skill that touches HC fields: confirm bandages
    still work with it enabled.
  - fall_resistance + impact_resistance + falls onto rocks.
- USER INPUTS:
  - simulate creature kill -> XP awarded, level transitions
    correct, skill_points incremented.
  - simulate fall onto rock -> impact gate behavior.
  - simulate damage from each EDamageType bit -> resistance gating.
  - simulate consume bandage -> heal applied.
- ERROR PATHS: unknown skill id, spend 0, refund below 0, op
  while no slot, port collision.
- PERSISTENCE: save schema round-trip across each skill.

A bug is a missing test. When a regression is found, the test
goes in BEFORE the fix. The test stays as a fence forever.

### First regression test (this is the gating shape)

```rust
#[test]
fn impact_resistance_does_not_block_bandages() {
    let api = common::Api::connect();
    api.op("skill_spend", json!({"id": "impact_resistance", "count": 100}));
    api.op("skill_toggle", json!({"id": "impact_resistance", "enabled": true}));
    let before = api.snapshot().player.hp;
    let r = api.op("simulate_heal", json!({"amount": 20}));
    assert!((r.state.player.hp - before - 20.0).abs() < 0.5);
}
```

That test fails today (mask blocks heal) and is the regression
fence for the status-effect migration -- whoever reintroduces a
binary mask without type-filtering trips it immediately.

### Architectural shift: generic primitive, not domain ops (2026-05-09)

The endpoint moved from "one op per scenario" to "one generic
`call` op + test-side parm structs". The skill
`runtime-control-http` now codifies this rule across projects.
Practical consequence: 1000% parity stops meaning "implement N
domain ops" and starts meaning "the test side has structs and
helpers for the SDK functions you want to call." The mod
provides the surface; the tests provide the experiments.

Read surface still needs the two remaining items below. Drive
surface is now ~done in the generic sense; the per-domain rows
below are reframed as test-side `tests/<name>.rs` deliverables
(each one is a Rust struct + a few `call_ufunction` invocations
+ assertions, no mod work).

### Endpoint parity gap (target: 1000%)

Per `~/.claude/skills/runtime-control-http/SKILL.md`, the endpoint
must be able to:

> - **Read** any state worth introspecting, in one round-trip.
> - **Drive** any operation the process can perform internally.
> - **Provoke** events that wouldn't normally occur on demand.

We do NOT have parity yet. Audit table below; each ✗ is a thing
that has to land before we declare the endpoint done. The
research / TDD loop only works if the answer to "can I do X
through the endpoint" is yes for EVERY X the user can do in-game.

#### Read surface (snapshot fields)

- [x] skill levels + points
- [x] disabled-skills (toggle state)
- [x] vanilla baselines (hunger/thirst/fall/max_health/hc masks)
- [x] live HC fields (RequiredDmgFlags, Immunity, BDR, Max, CurrentDmg)
- [x] live CMC fields (12 movement)
- [x] live ASC fields (combat mult + fall trio)
- [x] CDO state (survival, GlobalCombatData, GMS, SMMC)
- [x] inventory.current_slot_count
- [x] **player StatusEffects array** -- exposed in snapshot via
  `fall_hook::snapshot_player_status_effects` (lifted from the
  fall_hook probe).
- [ ] **recent dmg-trace ring buffer** -- last N multicast events
  with damage/flags/type_flags/instigator. Currently log-only.
- [x] settings echo (what was loaded from settings.json)
- [x] catalog dump (server-authoritative skill list so tests don't
  hardcode ids)
- [ ] player world location + equipped weapon (context for
  fall / item-use simulation)

#### Drive surface (ops)

- [x] snapshot
- [x] skill_toggle / skill_spend / skill_refund
- [x] reload_slot
- [x] simulate_add_health (canonical heal path; PE-queued)
- [x] simulate_set_current_health (direct setter; PE-queued)
- [x] **simulate_apply_damage** -- DEPRECATED. Replaced by the
  generic `call` primitive (2026-05-09). Tests build the parm
  struct themselves, hex-encode, send through `call`. Re-entrance
  guard added to drain_pending so `call` is safe even when the
  invoked UFunction triggers PE fan-out.
- [x] **`call` generic primitive** (2026-05-09). Single op
  invokes any UFunction on any object with arbitrary parm
  bytes. Replaces every `simulate_*` op below -- tests build
  their own parm struct, hex-encode, send. New research
  scenarios are now test-file-only changes (no mod rebuild).
  Selectors: `live_player_hc`, `live_player`,
  `first_class:<Name>`.
- [ ] **High-frequency drain site for the PE queue.**
  `kill_hook`'s trampoline only fires when the engine calls a
  UFunction on a player's `UHealthComponent` vtable. With
  `impact_resistance` mask = 0xFFFFFFFF, the gate rejects most
  type_flags=0 events and multicast traffic drops near zero,
  starving the drain. `call` ops time out at 5s instead of
  executing. Options:
  - **A**: install a hook on `ASurvivalCharacter::ReceiveTick`
    or a similar high-frequency UFunction. Tick fires every
    frame regardless of damage state.
  - **B**: use UE4SS's `RegisterProcessEventPreCallback` (global
    PE pre-callback fires for every UFunction on every object
    in the process). Already on the roadmap as "Future infra"
    below; this is the canonical drain site.
  - **C**: have the test drive activity (move, attack) to
    incidentally fire the trampoline. Workaround only.
  Recommendation: B; A as fallback. Until fixed, research that
  uses `call` while the mask is on must run with the player
  active in-world.
- [~] **simulate_consume_item** -- can be done test-side via
  `call` once we know which UFunction handles bandage consume
  (TryUseItem on the player controller, takes a UItem*; getting
  a UItem* needs a `walk_class` primitive or inventory walk).
- [~] **simulate_kill** -- test-side via `call` with the right
  function on the kill_hook surface. Doable today; nobody has
  written it yet.
- [~] **simulate_fall** -- test-side via `call`. Same shape.
- [~] **simulate_status_effect_add / _remove** -- test-side via
  `call` on `UStatusEffectComponent::CreateAndAddEffect` once
  the row handle layout is captured in a `#[repr(C)]` struct.
- [x] **set_skill_points** -- maps to `tracker::debug_grant_skill_points`.
- [~] **set_xp / set_level** -- test-side via `call` if a setter
  UFunction exists, or via direct field-write (need a
  `write_field` primitive, still on roadmap).
- [~] **clear_status_effects** -- test-side via `call` on the
  appropriate UFunction or via direct TArray write.

#### Test coverage (per the per-skill principle)

For EACH catalog skill (×13):

- [x] spend -> effect grows (covered)
- [ ] refund -> reverts (only ~half the skills tested explicitly)
- [ ] toggle off -> reverts to vanilla (only for variants that
  honor the flag; others should error or be marked N/A)
- [ ] toggle on -> effect restored (move_speed only; fill in)
- [ ] **persist across slot reload** -- NOT covered for any skill
- [ ] level 0 -> no effect (implicit; make explicit per skill)

Interaction matrix (every pair touching a shared subsystem):

- [x] impact_resistance + bandage (the fence)
- [ ] armor + heal
- [ ] max_health + fall onto rocks
- [ ] fall_resistance + impact_resistance + rock collision
- [ ] every other pair touching HC fields, damage gate, regen

Error paths:

- [x] unknown skill id, spend 0, refund below 0
- [ ] op while no slot (only reload_slot covers this today)
- [ ] malformed args (wrong type)
- [ ] port collision / second instance

#### Anti-pattern audit (skill says NO)

- [x] Multiple endpoints -- one /debug
- [x] Quick GET routes -- only POST
- [x] CLI bypassing endpoint -- none exists
- [x] Mocked test fixtures -- endpoint is the fixture
- [ ] **Logs instead of state** -- status effects now in snapshot;
  dmg-trace ring still log-only. Last item to land for parity.

### Build sequence

- [x] **Crate deps + settings flag.** `tiny_http` (mod-side),
  `ureq` (dev-dep for tests). `settings.debug.http_port: Option<u16>`,
  default None. `settings.example.json` updated.
- [x] **`src/debug.rs`**: HTTP server (single POST /debug handler),
  `Snapshot` struct, `build_snapshot()` walking live UObjects. Spawn
  on a named worker thread when `settings.debug.http_port` is set.
- [x] **First op**: `snapshot` (read-only). Vanilla baselines, captured
  HC u32 masks, disabled-skills list, live player HC field reads
  (RequiredDamageTypeFlags, ImmunityFlags, BaseDamageReduction,
  MaxHealth, CurrentDamage).
- [x] **Test scaffolding**: `tests/common/mod.rs` (Api wrapper over ureq,
  response types) + `tests/debug_snapshot.rs` (smoke test). Tests skip
  with a clear note when `BBP_DEBUG_PORT` env var is unset.
- [x] **`docs/testing.md`**: how to enable the port, run tests, read
  the snapshot.
- [ ] **PE-thread command queue**: `Mutex<VecDeque<DebugCmd>>` in
  `debug.rs`; drain from `kill_hook` PE trampoline. `simulate_damage`
  / `simulate_heal` / `skill_spend` / `skill_toggle` / `reload_slot`
  push onto this.
- [ ] **First write op**: `skill_toggle`. Easiest -- already
  thread-safe (mutex on DISABLED_SKILLS).
- [ ] **`simulate_damage` op**: queue a `process_event` on
  `UHealthComponent.ApplyDamageFromInfo` with crafted FDamageInfo.
  HTTP handler blocks on the queue draining before returning so
  callers see post-op state, not a race.
- [ ] **`simulate_heal` op**: sugar for `simulate_damage` with negative
  amount + type_flags=0. The bandage repro.
- [ ] **`bandage_regression.rs` test**: the gating shape from the
  design (enable impact_resistance, simulate_heal, assert HP
  delta == amount). Fails today; passes after status-effect
  migration.
- [ ] **Per-skill test family**: `tests/skill_<id>.rs` for every
  catalog entry, exercising spend / refund / toggle-on /
  toggle-off / persist / level-0 against the live target field.
  This is the primary test layer; the control plane exists
  precisely to make this cheap. See `runtime-control-http` skill
  "Test coverage principle".
- [ ] **Interaction matrix**: `tests/interactions/<a>_<b>.rs` for
  every pair of skills that touches a shared subsystem (HC
  fields, damage gate, regen). Catches the bandage class of bug
  before the user sees it.
- [ ] **User-input scenarios**: `simulate_kill`, `simulate_fall`,
  `simulate_consume_item` ops + tests that drive each one.
- [ ] **CI**: tests already skip when env var is unset, so default
  `cargo test` stays green. Document the opt-in env var in CI docs
  if/when the project gets a CI pipeline.

### Why this catches bugs that today's logs don't

Logs are write-only history; you have to read them, eyeball
patterns, hope you catch the right line. The snapshot endpoint
gives a queryable, structured view of *current* state -- "what is
the mask right now on the live HC", "what's the HP", "what's in
the deferred queue" -- and tests assert against it deterministically.
The bandage regression would have surfaced as a one-line failure
the first time impact_resistance went out as a binary mask.

## Feature ideas (not yet scoped)

- [ ] **Auto-farming buildings.** Player can place a custom
  building that periodically yields a configured material (or
  list of materials) into a connected storage. Removes the
  farming grind for late-game players who already know the
  loops. Open design questions:
  - **Surface**: a new buildable that registers as a normal
    building (so it integrates with build mode + saves), or a
    Lua-style overlay that ticks externally and posts items
    into a target chest? Built-in surface is more invasive but
    feels native.
  - **Item source**: which materials are eligible? Plant fibers
    + resin always; rarer mats (boss drops, ant parts) gated by
    tier or by a player-set policy.
  - **Throttle**: yield/min as a function of building tier so
    upgrades have a place. Avoid trivializing the chase.
  - **Power / cost**: needs an input (water, electricity, food
    for a captured creature?) so it isn't a free ratchet.
  - **Multiplayer**: single-host vs replicated. Yield needs to
    be authority-side or it's a dupe.
  - **Reference**: vanilla Grounded 2 may already have a
    "production" building class; check `UProductionBuilding`,
    `BP_Building*` subclasses for an existing skeleton we can
    extend rather than building one from scratch.
  - **Test plan**: place building -> tick for N seconds ->
    verify storage has +M of the right item. All driven via the
    debug endpoint (need ops: `simulate_advance_time`,
    `place_building`, `read_storage_contents`).

## Hot-reload the DLL while the game is running

Editing the mod and seeing the change requires close-game ->
deploy DLL -> launch-game right now. Slow. UE4SS supports
hot-reloading CPPMods in some configurations; need to research
whether our shim shape is compatible:

- Check UE4SS's "reload mods" hotkey / chat command for cpp
  mods specifically (it's well-supported for Lua mods; cpp
  support is partial).
- Our mod installs vtable patches via `ProcessEventHook` and
  forgets the handles for life-of-process. Hot-reload would
  need to re-install those on load AND properly unhook the
  old DLL's vtable patches before the new DLL installs its
  own. Otherwise we corrupt the vtable.
- If UE4SS doesn't reload cpp mods cleanly, alternatives:
  build a tiny "loader" mod that mmaps our actual mod DLL on
  demand and provides install / uninstall hooks; or use
  Windows-side detour-redirect tricks.
- Investigate whether the inv_hook / kill_hook / fall_hook
  install paths are idempotent (i.e. handle "already
  installed" by no-op, so a reload that re-runs init doesn't
  double-hook).

This would dramatically speed up the iteration loop. Worth a
spike.

## Future infra

- [ ] **Global ProcessEvent hook.** Per-vtable hooking is fine
  for the current setup but will hit walls when we want to
  catch BP events that fire on enemy / npc vtables we don't
  hook. UE4SS exposes
  `RC::Unreal::Hook::RegisterProcessEvent[Pre|Post]Callback`
  in its Hooks header; ~20 lines of shim glue + a registry on
  the Rust side. Right call for the next round of player-state
  signals (level-up confirm, recipe learned, dialog start, save
  fired). Not blocking anything today.

## Out of scope (kept for reference)

- Visible 6-row inventory grow. Replaced by paged 4x10 viewport
  with mouse-wheel scroll. Working.
- Multiplayer correctness for hunger/thirst. Stats almost
  certainly replicate server-authoritatively, so non-host
  clients won't see the effect. Document, don't fight.
- In-world UMG HUD overlay (always-visible XP bar). Out of v1
  scope; would need a custom DX11 hook or a BPModLoader-shipped
  widget. ImGui tab is sufficient.
