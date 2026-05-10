# Changelog

> **Authoritative on:** chronological history of milestones,
> investigations, and design pivots. Things that are DONE.
> For what's next see [`todo.md`](todo.md). For per-subject
> deep dives see the other files in this directory.

Newest first.

## 2026-05-10

### Phase 3 (first wave) -- ueforge::rpg generic framework

The RPG-mod-shaped pieces every UE game needs land in ueforge:

- `ueforge::rpg::xp::Curve { base, exponent, max_level }` -- the
  classic `cumulative_xp_for_level` / `level_for_xp` math
  parameterized so any RPG mod plugs its own numbers.
- `ueforge::rpg::progress::sqrt_progress(level, max)` -- generous-
  early diminishing-returns curve.
- `ueforge::rpg::SkillsState` -- on-disk schema (xp / level /
  skill_points / `skill_levels: BTreeMap<String, u32>`) with
  `spend()` / `refund()` / `level_of()` methods.
- `ueforge::rpg::SlotStore<S>` -- per-slot JSON persistence under
  `<DLL_dir>/<subdir>/<slot>.json`. Generic over persisted struct.
  Atomic temp+rename save.
- `ueforge::rpg::DisabledSkills` -- thread-safe toggle set for
  "disable a skill without refunding its points".
- `ueforge::rpg::SlotPoller::spawn(interval, resolve, on_activate,
  on_deactivate)` -- 1Hz worker that drives activate / deactivate
  transitions on a consumer-supplied resolver closure.

5 unit tests on the curve + progress math (xp round-trip, max-level
cap, sqrt endpoints, quarter-is-half) -- the framework's first unit
tests, closes the kovarex P2 "no unit tests on framework
primitives" item.

bbp migrations: `src/rpg/state.rs` deleted entirely; `tracker.rs`
keeps a `static STORE: SlotStore<SkillsState>` and routes load /
save / spend / refund through ueforge; `world_loader.rs` shrinks
from 95 LoC of CreateThread plumbing to 30 LoC routed through
`SlotPoller::spawn`; `xp.rs` shrinks to a 3-line curve constant +
the per-creature XP table (game-specific bestiary); `apply.rs`
DISABLED_SKILLS swap; `skills::level_progress` becomes a 1-liner
forwarder. bbp's `PlayerState` is gone -- `kill_count` and
`last_killed` (diagnostic-only) dropped per "free to redesign"
scope.

Phase 3 second wave (catalog generic, apply dispatcher, RpgTab
widget) is next session.

### Phase 2 small promotions

Three Phase 2 items land before the big RPG promotion:

- **`ueforge::ue::class_tweak::ClassFieldTweak<T>`** -- live-UObject
  sibling of `FieldTweak<T>` (which is DataTable-row scoped). Two
  closure shape: `filter(&UObject) -> bool` (cheap, runs before
  the vanilla read) and `transform(T) -> Option<T>` (`None` =
  skip writing this instance). Captures vanilla keyed per-instance
  so re-applies don't compound.
- **bbp `patch.rs` + `survival.rs` migrated to `ClassFieldTweak<T>`.**
  Hand-rolled GObjects walks deleted; both files are now driven
  by `static SLOTS / HUNGER / THIRST: ClassFieldTweak<...> = ...;`
  and a single `.apply()` call. Net -150 LoC from bbp.
- **`ueforge::hook::function_ptr` / `function_ptr_required`** --
  small helper that returns `*const UFunction as usize`. Pattern
  is: stash in an `AtomicUsize` at hook install, dispatch by
  pointer identity in the trampoline.
- **`Queue::drain` canonical-site doc.** The `bbp::kill_hook` PE
  trampoline drain pattern (empty-check, re-entrance guard, peak
  counter, time scope) is now in the rustdoc so the next mod
  doesn't have to reverse-engineer it.

### bbp consumes ueforge for ALL infra (Phase 1 dedup)

better-backpack lost ~930 lines of duplicated framework. Every piece
of generic UE4SS / SDK / hook / log / settings / counter / ImGui /
build plumbing now lives in ueforge and is consumed (not mirrored)
by the mod.

Deleted from bbp:
- `cpp/shim.cpp` (357 LoC) -- CppUserModBase mirror + ImGui render lambda
- `src/rpg/ffi.rs` (340 LoC) -- C-ABI bridges that the shim called
- `src/log.rs` -- duplicate of ueforge::log
- `src/sdk/` -- thin re-export shim of ueforge::ue
- `src/hook/` -- thin re-export shim of ueforge::hook
- `winhttp.def` -- legacy
- Custom `DllMain` + `better_backpack_start` / `better_backpack_stop` exports
- `DLL_HMODULE` static

Replaced with:
- `ueforge::ue4ss_mod!(MOD_INFO)` -- one macro emits every extern "C"
  hook the shim invokes (factory, DllMain forwarding, tab dispatch)
- `src/rpg/tab.rs` -- Rust ImGui render. Calls `tracker` / `skills`
  / `xp` directly; uses ImGui `##id` label suffix instead of
  PushID/PopID for unique button instances per skill row
- 1-line `build.rs`: `ueforge::build::CppShim::new().compile()`

Settings struct shape unchanged on disk (back-compat preserved); IO
routes through `ueforge::settings::Settings<T>`. The legacy parent-dir
fallback for `settings.json` was dropped per "free to redesign"
scope; if anyone has a pre-Rust install pattern, move the file next
to main.dll.

Cumulative shape after Phase 1: bbp consumes ueforge for SDK, hook
framework, log, settings IO, ImGui bindings, counter primitives,
ring buffer, HTTP server, op envelope, generic ops, tab
registration, DllMain, factory exports, C++ shim. Zero duplication.

What stays in bbp (correct game-side): `inv_hook`, `kill_hook`,
`fall_hook`, `survival`, `patch`, `parms`, `debug`, the `counters`
domain statics, and the entire `rpg/` subsystem (catalog content,
apply dispatcher, persistence layer). `rpg/` is the Phase 2 promotion
candidate -- shape is generic for any UE game with the right
`slot_key()` resolver, so it lands in `ueforge::rpg` next.

### ueforge hardening (kovarex review landed)

Three P0 + six P1 items shipped. Crash vectors closed, FString /
GObjects walks bounded, dev profile unwinds.

**P0:**
- `parking_lot::Mutex` everywhere -- no more poison-then-abort hard
  crashes. `[profile.dev] panic = "unwind"` so research crashes
  leave a backtrace; release stays on abort for size + perf.
- Hot paths use `try_runtime` + soft fallback (empty name, dropped
  PE call + log) instead of `expect()` aborting if a hook fires
  before init_runtime sets the OnceLock.
- Address-validated freezes. `freeze { selector, offset }` resolves
  through `selector::resolve_generic` and re-resolves on staleness;
  `VirtualQuery` validates page protection on every write; 30
  consecutive failed validations stop the writer. Legacy
  `freeze { addr }` still works but has no recovery path.

**P1:**
- `NameResolver` caches FName u64 -> String. Caps the FString leak
  at one buffer per unique FName (was: per call). Bounded by the
  game's name pool (~50K) instead of unbounded.
- `find_class_fast` caches by name. Selector resolution drops from
  O(GObjects walk) -- ~150K objects on OWS -- to O(1) on the warm
  path.
- `UClass::cached_native_properties` returns `Arc<[NativeProperty]>`;
  `inspect_address` allocates zero per click after the first lookup.
- `ops::{read_bytes,write_bytes}` clamp `offset+length` to
  `class.properties_size()` when the class is known. Selectors that
  point at a UObject can no longer read/write past the instance.
- `arc_swap::ArcSwap` replaces hand-rolled `AtomicPtr<&'static [...]>`
  + `Box::leak` snapshot in PE hooks. No leak per install/drop.
- `tmap::MAX_LINEAR_SCAN` 8192 -> 65536 with one-line truncation log.
- `Api::try_op` + `perf::try_open` Result-returning variants
  alongside the panicking convenience wrappers.
- `scan_memory` builds JSON sample before taking sessions lock so
  multi-second scans don't block other ops.

### Three-way feature audit added

`ueforge/README.md` ships a 62-row matrix mapping every feature
across ueforge, better-backpack, and ows-tweaks. Each cell is
`live here / consumes ueforge / duplicates (delete) / should be
promoted / N/A`. Verdict column names the migration item.
Phase 1 status now marks 30+ rows done.

### Property walker on inspect_address

`ueforge::inspect_address` now resolves field names via the
UClass `ChildProperties` chain. Click an address in the Scanner
tab -> "DataTable::RowMap on DT_Materials" instead of
"DT_Materials @ +0x30 (size 0x60)". Walks the super-class chain.
Adds `ffield`, `fproperty`, and `ustruct::CHILD_PROPERTIES`
constants to `ue::offsets` (UE 5.4 verified; 5.5/5.6 may shift
`OFFSET_INTERNAL` -- track via the offsets-versioning P2 item).

## 2026-05-09 (evening)

### impact_resistance bug fix landed: ApplyDamageFromInfo intercept

Replaced the binary `RequiredDamageTypeFlags = 0xFFFFFFFF` mask
write with a Runtime effect that intercepts
`UHealthComponent::ApplyDamageFromInfo` on the player HC,
identifies environmental damage by
`FDamageInfo.DamageType` class name containing "Environmental",
and scales the `Damage` parm by `(1 - reduction * progress)`
before forwarding.

Why the change: the binary mask blocked bandages (and all
healing) by gating `type_flags=0` events at the native
ApplyDamage level. Bandage HoT applies a `Type=Health (24)`
status effect whose tick goes through that gate and was being
rejected. Research-as-code (`tests/explore_bandage_path.rs`,
`tests/explore_bandage_status_effects.rs`) characterized the
mechanism end-to-end before the fix landed.

The new mechanism uses the same shape as fall_resistance's
velocity-stomp on OnLanded: intercept-and-scale at the PE
surface, gated by a discriminator (DamageType class for
impact_resistance, "is fall" for fall_resistance).

Side-effects:
- Bandages now heal regardless of impact_resistance level
- Creature combat damage is untouched (different DamageType)
- Fall damage is untouched (different surface, handled by
  fall_resistance)
- Per-level sqrt scaling instead of binary all-or-nothing

## 2026-05-09

### Discovered: impact_resistance blocks bandages

Enabling `impact_resistance` at any level prevents bandages and
other healing items from working. Confirmed in-game by binary
isolation (only impact_resistance enabled -> repro; toggled off ->
heals fine). Mechanism: bandages route healing through
`ApplyDamage` with negative damage and `type_flags = 0`. The
`RequiredDamageTypeFlags = 0xFFFFFFFF` mask we set rejects any
event with type_flags=0, so heal events fail the gate before the
HP decrement. Detail in [`damage.md`](damage.md) "Critical
regression: bandages / healing items blocked".

Workaround until the canonical fix lands: keep impact_resistance
toggled off when healing is needed. The status-effect migration
in [`todo.md`](todo.md) replaces the binary mask with a
type-filtered DamageReductionMultiplier that won't touch healing.

### `PlayerHealthCompU32Mask` learned to disable cleanly

Previously the variant only wrote the mask at level > 0 and never
restored vanilla, so refunding the skill or toggling it off left
the mask set (mid-session and beyond). Apply step now captures the
vanilla mask on first sight, runs at level 0 / disabled too, and
writes the captured vanilla back when the skill is inactive. This
is what makes the toggle actually unblock bandages.

### Avoided ProcessEvent deadlock by deleting dead UFunction call

Toggling fall_resistance off used to freeze the game. Root cause:
`apply_skill` for fall_resistance was invoking
`USurvivalModeManagerComponent::UpdateCustomSettings` via
ProcessEvent. That UFunction triggers replication on the Net-flagged
`CustomSettings` field; calling it mid-session from any non-game
thread (ImGui callback, world_loader poller) hangs on the
replication marker.

Reading the SDK + the original commit (`6ad1df2`), the call was
dead code -- the changelog explicitly notes "Player still takes
fall damage" even with the UFunction firing, and the actual
mitigation that works is the velocity-stomp on `Velocity.Z` in
`fall_hook.rs` plus the `RequiredDamageTypeFlags` mask. Native
fall-damage code never reads the FallDamageMultiplier fields the
UFunction was meant to invalidate. Deleted the call and its helper
entirely; the GMS / SMMC field writes remain (harmless).

## 2026-05-08

### Catalog +3 skills (untested in-game)

Three new skills shipped, all using two new `SkillEffect` shapes.
Pending in-game witness.

- **Max Health** -- `PlayerHealthCompAdditive` (new variant). Captures
  the vanilla baseline at `UHealthComponent.MaxHealth` (+0x328) on
  first apply, then writes `vanilla + max_bonus * progress` on
  player CDOs and the live pawn. Additive so HP stacks rather than
  scaling, +200 HP at level 100.
- **Health Regen** -- `GlobalDataMult` (new variant). Walks every
  `UGlobalCombatData` instance and writes per-offset multipliers:
  CombatRegenTickPercentage (0x010C, exponent +1.0) scales up,
  CombatRegenTickRate (0x0110, exponent -1.0) scales down (more
  frequent ticks). Combat-regen delay (0x0108) intentionally
  untouched to preserve the post-combat feel. +500% / 6x at level
  100.
- **Leap Distance** -- existing `PlayerMovementMult` over three
  CharMovementComponent fields: AirControl (0x02C0),
  AirControlBoostMultiplier (0x02C4), AirControlBoostVelocityThreshold
  (0x02C8). Lets the player keep accelerating in their input
  direction through the arc -- a real "leap" feel rather than a
  taller jump. +500% at level 100.

### ImGui tab: refund + per-skill toggle

- `-1` / `-10` refund buttons next to the `+1` / `+10` spend
  buttons. Decrement the level, credit the points back, run the
  apply step, save. Disabled at level 0. Caveat: refund-to-0 on
  `PlayerHealthCompU32Mask` (Impact Damage Resistance) needs a
  reload to take effect because the apply step early-returns at
  level 0 and there is no vanilla mask captured.
- `on` checkbox per row. Disabling treats the skill as level 0
  without refunding the points -- drops a buff (e.g. Leap Distance)
  on demand without losing progress. Process-global, not persisted
  (cheap to reapply on launch). Toggling fires `apply_one`.

New FFI: `bbp_rpg_refund`, `bbp_rpg_refund_many`,
`bbp_rpg_is_skill_enabled`, `bbp_rpg_set_skill_enabled`.

## 2026-05-05 (single big day)

### Impact Damage Resistance (binary)

Landed via `apply.rs` writing
`UHealthComponent.RequiredDamageTypeFlags = 0xFFFFFFFF` (+0x00FC,
uint32) on player CDOs and the live pawn at any
`impact_resistance` level > 0. Native ApplyDamage gate consults
the field; incoming damage with `type_flags = 0` (fall,
environmental, hazard zones) fails the bitwise check and is
rejected before `CurrentDamage` is written. Creature attacks
carry non-zero flags and pass through. Validated in-game: rock
collision multicasts report `damage=0.00`, impact-trace POST line
silent (no `CurrentDamage` change). Same field-write pattern as
Armor's `BaseDamageReduction` write, just on a different gate.

The gate is **binary** (level 1 = full immunity, identical to
level 100). Status-effect-backed migration tracked below.

### Vanilla status-effect data table identified

`fall_hook.rs` extended with a probe that walks the player's
`UStatusEffectComponent.StatusEffects` array and logs each effect's
row handle. Result: every active status effect in the game flows
through one data table:

```
DataTable: /Game/Blueprints/Attacks/Table_StatusEffects.Table_StatusEffects
```

Sample active rows (mid-game player): `PlayerUpgradeHealth1`,
`WeaponClub`, `RogueFinisherCriticals`, `AntRedStaminaAttack`,
`FighterFinisherStun`, `MaxHealthSmall`, `PerkSpearTier1`,
`PerkSpearThrowAttackUpTier1`. Naming convention is
`<Source><Effect><Tier>`. Detail in `docs/damage.md` "Vanilla data
table identified".

This finalizes the migration plan: resolve the table (follow any
existing row handle), enumerate rows, mutate or inject one per
skill, AddEffect via `process_event`. Implementation step is
concrete now.

### Status Effect combine semantics decoded

Extended the sfx-probe to also call
`UUserInterfaceStatics::GetStatusEffectValueType(StatType)` for each
probed stat. `EStatusEffectValueType` enum is two-state plus None:
`Add=1`, `Multiply=2`. Per-stat semantics observed in-game:

- `FallDamage`, `DamageReduction`, `AttackDamage` -> `mul` (vanilla
  baseline 1.0; effects multiply).
- `LifeSteal`, `CriticalHitChance`, `CriticalDamage`, `ReflectDamage`,
  `MaxHealth`, `DamageReductionMultiplier` -> `add` (vanilla baseline
  0.0; effects sum).

Per-skill write formulas now fully determined; full table in
`damage.md` "Stat semantics table". This finishes the validation
phase of the A1 migration; next is picking an implementation path
(mutate existing row vs inject new row) and building the apply
step.

### Status Effect system validated (probe shipped, in-game readout)

`fall_hook.rs` now ships a probe (gated on `impact_resistance > 0`)
that calls `UStatusEffectComponent::GetValueForStat(StatType,
false)` on the player's component for damage-relevant stat types.
First in-game readout on a mid-game player:

```
FallDamage(14)=1.000  DamageReduction(29)=1.000  AttackDamage(23)=1.210
CriticalHitChance(31)=0.060  MaxHealth(5)=30.000  LifeSteal(38)=0.000
```

Confirmed:
1. The status-effect system is live and queryable.
2. Vanilla equipped gear / perks already populate it (the `+21%`
   attack and `+30` max health values come from existing items).
3. Stat semantics differ (multiplier vs additive vs probability),
   queryable via `USurvivalGameplayStatics::GetStatusEffectValueType`.

This validates the migration target. Next step is to probe the
combine semantic per stat, then implement the apply step using
one of the four implementation paths in `damage.md`.

### Status Effect system identified (canonical extension surface)

SDK review of `UStatusEffectComponent` on `ASurvivalCharacter` at
+0x1378: this is the proper Grounded 2 surface for proportional,
per-stat / per-damage-type modifiers. Native damage code calls
`GetValueForStatForDamageTypeFlags(StatType, Flags)` on every
damage event and uses the float result as a multiplier.
`EStatusEffectType` enum has matching values for nearly every
skill we plan: `FallDamage=14`, `DamageReductionMultiplier=30`,
`LifeSteal=38`, `ReflectDamage=37`, `AttackDamage=23`,
`CriticalHitChance=31`, `CriticalDamage=62`, `MaxHealth=5`, etc.

Current implementations (Armor's `BaseDamageReduction`, Impact's
`RequiredDamageTypeFlags`, Fall's velocity-stomp, Lifesteal's
`Runtime` no-op) are interim. Migration to status-effect-backed
skills gives sqrt-curve scaling, native type filtering, and
stacking with vanilla items / perks. Plan in [`todo.md`](todo.md);
full pipeline reference in [`damage.md`](damage.md).

### Fall Damage Resistance

Landed via velocity-stomp in `fall_hook.rs`'s `OnLanded` PE hook on
the player BP class. See [`damage.md`](damage.md) for the full
pipeline reference.

### Movement skill fix verified

Move Speed was initially wired only through generic UE movement caps and
player CDO writes, which was not enough for Grounded 2. The fix now
also patches Grounded-specific `UMaineCharMovementComponent` fields:

- `CustomGroundSpeedMultiplier` (+0x1198)
- `CustomFlySpeedMultiplier` (+0x119C)
- `CustomSwimSpeedMultiplier` (+0x11A0)
- `MaxSwimSprintSpeed` (+0x1164)

Movement writes are also mirrored onto live player pawns, not just
CDOs, so the effect can be validated immediately in-session. User
retest confirmed the run-speed skill now works.

### Skill registry refactor

`skills.rs` is now the single source of truth. Each skill is one
row in `CATALOG` carrying id, display_name, max_level, and a
`SkillEffect` variant. `apply.rs` is one function `apply_skill`
that pattern-matches on the effect. Adding a new skill of an
existing shape is one CATALOG row, no other code changes. Adding
a new shape is one variant + match arms in apply and format.
Catalog at 9 skills, ready to grow to 25+.

### Vocabulary and curve

Hard rename `rank -> level` everywhere. Schema field
`skill_ranks -> skill_levels`. Every skill now caps at level 100
with a `sqrt(level/100)` diminishing-returns curve.

### Combat + movement skills

- Attack Damage (max +300%): `ASurvivalCharacter.CustomDamageMultiplier` at +0x12B8.
- Armor (max -50% damage taken): `UHealthComponent.BaseDamageReduction` at +0xEC, via the player CDO's HealthComponent pointer.
- Move Speed (max +300% walk + sprint + swim): `MaxWalkSpeed` (+0x288), `MaxSprintSpeed` (+0x10EC), `MaxSwimSpeed` (+0x290), `MaxSwimSprintSpeed` (+0x1164), `CustomGroundSpeedMultiplier` (+0x1198), `CustomSwimSpeedMultiplier` (+0x11A0).
- Jump Height (max +300%): `JumpZVelocity` at +0x1B8.
- Glide Speed (max +300%): `MaxFlySpeed` (+0x294) plus `CustomFlySpeedMultiplier` (+0x119C).
- Lifesteal (max +90% of damage dealt): catalog entry only;
  runtime kill_hook integration was queued and pivoted to the
  registry refactor.

All movement skills capture vanilla baselines via `OnceLock`s on
first apply so re-apply doesn't compound.

### apply optimization

`apply_one(state, settings, skill_id)` runs just one skill. A
`+1` click in the tab now writes one CDO + produces one log
line, not five.

### ImGui tab

UE4SS `register_tab` for the "RPG" tab. Shows level, XP bar,
skills with rank/effect/+1 buttons. Vendored upstream
ocornut/imgui v1.92.1 (matches UE4SS) as
`better-backpack/cpp/imgui/`. Forward-declared
`UE4SSProgram::get_current_imgui_context` and
`get_current_imgui_allocator_functions` with `RC_UE4SS_API`
(dllimport via UE4SS.lib). Symbol mangling gotcha: `register_tab`
is `protected` on the real CppUserModBase. MSVC mangling encodes
access (Q=public, I=protected). First attempt with public failed
LNK2019; moved to a protected section of the mirror.

C-ABI in `rpg/ffi.rs` (8 functions wrapped in `catch_unwind` so
panics can't take down UE4SS's render thread). Lambda reads
state via getters and posts spends via `bbp_rpg_spend`.

UI also shows current effect + next-level preview per skill, e.g.
`Backpack level 5 / 100  +30 slots  (next: +33 slots)`. Debug
footer with `+5` / `+50` skill-point grant buttons for testing.

### Eager state load on world entry

`rpg/world_loader.rs`: 1Hz poller that watches
`save_slot::current_slot_key()` and drives tracker transitions
(`None -> Some(s)` activate, `Some(a) -> Some(b)` save-swap,
`Some -> None` deactivate). Replaces the lazy "load on first
kill" shortcut from Spike B.

### Skill catalog + apply step + settings layering

settings.json defines the BASE values for each stat. RPG skills
layer on top:

- backpack: target = `settings.slot_count + skill_bonus`.
- survival drain: target = `vanilla * settings_mult * skill_mult`.

Defaults flipped to vanilla (`slot_count=40`,
`hunger/thirst_mult=1.0`); user overrides settings.json for a
starter buff. Skill levels then layer.

apply.rs captures vanilla survival rates at init (before the
init-time survival::run modifies them) so re-apply uses a fixed
baseline.

### Buggy kill attribution

Three buckets in `kill_hook.rs::classify`:

- Player: instigator class chain contains "PlayerController".
- Buggy: instigator (or its possessed Pawn at +0x308) class
  chain contains "Buggy".
- Other: enemy AIC; logged + dropped, no kill_count bump.

Confirmed in-game: PLAYER on Grub kills, BUGGY on Spiderling
killed by `AIC_AntSoldier_Augusta_Buggy_C`. Single-player /
host case works; co-op ownership disambiguation deferred.

### XP / level math

`rpg/xp.rs`: cumulative XP curve `100 * N^1.8`, level cap 50,
per-creature XP lookup table (~20 species placeholders).
PlayerState schema bumped to `(xp, level, skill_points,
skill_levels)`.

### Spike A: kill detection

Hook on `Maine.HealthComponent` ProcessEvent slot. Match on
`MulticastHandleEffectsWithDamageFlags`. Read DamageFlags at
+0x1C in the parms struct, mask with `EDamageInfoFlags::KillingBlow = 2`.
On match, read `LastDamageInfo.InstigatorController` from
HealthComponent +0x3B0 (inside FDamageInfo at +0x20). Filter to
ASurvivalCreature subclasses to exclude buildings / props.

#### Attempt 1 (failed)

First attempt hooked the `Kill` UFunction directly. Did not fire:
`Kill` is `Final|Native`, the engine bypasses ProcessEvent on
the internal damage path. Diagnostic logging of all PE calls on
HealthComponent showed only `OnStatusEffectChanged`,
`MulticastHandleEffectsWithDamageFlags`, `OnCombatChanged` during
a Weevil kill.

#### Investigation

`OnDeath` multicast delegate's BP-bound handlers fire via PE on
each enemy's vtable, not HealthComponent's, so a per-vtable hook
on HealthComponent can't see them. Two paths considered: (A)
read `DamageFlags` from `MulticastHandleEffectsWithDamageFlags`
which DOES fire via PE on HealthComponent and includes a
KillingBlow bit, or (B) global ProcessEvent hook via UE4SS's
`RegisterProcessEventPreCallback`. SDK grep found
`EDamageInfoFlags::KillingBlow = 2`, which validated path A.
Implemented in ~10 lines, no architectural change.

Path B retained on the future-infra TODO; it's the right call
for any future PE-only signal we'll need (level-up confirms,
item crafted, dialog events, etc.).

### Spike B: persistence

PlayerState in `<DLL_dir>/saves/<playthrough-guid>.json`. First
attempt used `USaveLoadManager.SaveInProgressSaveGameHeaderData`
(at +0x90), but that's null except during an active save
operation. Switched to `AInGameGameState.PlaythroughGuid` at
+0x32C; populated for the duration of the active session.

### RPG pivot

Direction shift from "configurable tweaks toolkit" (settings.json
flat sliders) to "Factorio-style RPG / level-up mod" (skills earn
points, points buy ranks, ranks change game state). Inspired by
the Factorio
[RPG System](https://mods.factorio.com/mod/RPGsystem) plus
[War3CS / War3FT](https://war3cs2.wiki.gg/) for Counter-Strike.

The "everything is a slider" model became the *output* of the
level system, not the user-facing knob. Settings becomes base
values; skills layer on top.

### UE4SS C++ mod load works

Loader-side bug fixed: our `CppUserModBase` mirror was missing
six virtuals vs the upstream header (`on_ui_init`, four post-1.0
`on_lua_*` overloads, `on_cpp_mods_loaded`). UE4SS dispatched
through later vtable slots into garbage and crashed the game
during init. Mirror now matches the header virtual list verbatim.
`on_cpp_mods_loaded` is NOT marked `RC_UE4SS_API` because
UE4SS.lib doesn't export it; using local inline body works.

## Earlier

The Rust port of the original C++ Better Backpack mod is
documented in [`rust-port.md`](rust-port.md). The pivot to a
UE4SS C++ mod (CPPMod) shape is documented in
[`ue4ss-port.md`](ue4ss-port.md).

The original C++ implementation is preserved at
[`../archive/winhttp-proxy/`](../archive/winhttp-proxy/) for
reference.
