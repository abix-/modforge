# RPG system

> **Authoritative on:** the RPG / level-up subsystem. XP, levels,
> skills, kill detection, persistence, the ImGui tab, and how the
> apply step writes skill values into the running game.

For the project's open work see [`todo.md`](todo.md). For the
distribution / loader story see [`ue4ss-port.md`](ue4ss-port.md).
For build instructions see [`building.md`](building.md).

## Vision

Inspired by Factorio's [RPG System](https://mods.factorio.com/mod/RPGsystem)
and the [War3CS / War3FT](https://war3cs2.wiki.gg/) line of
Counter-Strike Warcraft mods. **Classless, free-form skill spec.**
The catalog is a flat menu; the player decides what kind of player
they want to be by spending skill points on whatever combination
they like. There are no archetypes the mod enforces: a tank build
is "max armor + max health + max regen", a glass cannon is "max
attack damage + max crit + max move speed", a survivalist is "max
backpack + min hunger/thirst + max gather". The mod just provides
the levers.

## Player loop

```
   kill creature -> earn XP -> hit level threshold -> get skill point
   spend skill point -> skill level goes up -> stat changes -> kill better
```

XP comes from killing creatures (player kill or Buggy mount kill,
configurable scaling for Buggy). The player levels up via a
quadratic XP curve; each level grants one skill point. Skill points
are spent via the ImGui tab in UE4SS's debug overlay (default
`Insert` to summon).

## Vocabulary

Consistent across code, UI, logs, and docs:

| Term         | Meaning                                                    |
| ------------ | ---------------------------------------------------------- |
| skill        | An upgrade slot (Backpack, Lifesteal, Move Speed, etc).    |
| skill point  | The currency a player earns by leveling up.                |
| skill level  | How many points the player has spent on a given skill.    |
| level        | The player's character level (separate from skill levels).|
| XP           | Cumulative experience earned from kills.                   |

Match the Factorio RPG System / Diablo conventions.

## Catalog

The catalog lives in
[`better-backpack/src/rpg/skills.rs`](../better-backpack/src/rpg/skills.rs)
as the **single source of truth**. Each skill is one row in
`CATALOG` with:

| Field         | Notes                                                     |
| ------------- | --------------------------------------------------------- |
| id            | Stable string used as the persistence key.                |
| display_name  | Shown in the ImGui tab.                                   |
| max_level     | Caps at 100 for every skill.                              |
| effect        | A `SkillEffect` enum variant that drives apply + format.  |

Adding a new skill of an existing shape is one row. Adding a new
shape adds one variant to `SkillEffect` and one match arm in
`apply_skill` and `format_effect`.

### Current catalog (10 skills)

| Skill            | Domain     | Final value at level 100         |
| ---------------- | ---------- | -------------------------------- |
| Backpack         | survival   | +460 slots (40 vanilla -> 500)   |
| Hunger Resistance| survival   | -75% drain (1.0x -> 0.25x)       |
| Thirst Resistance| survival   | -75% drain                       |
| Attack Damage    | combat     | +300% damage (1.0x -> 4.0x)      |
| Armor            | combat     | -50% damage taken                |
| Move Speed       | movement   | +300% walk + sprint + swim       |
| Jump Height      | movement   | +300% jump-Z velocity            |
| Glide Speed      | movement   | +300% MaxFlySpeed                |
| Fall Damage Resistance | survival | targets fall mitigation; field writes are confirmed, but full immunity is not verified yet |
| Lifesteal        | combat     | +90% of damage dealt healed back |

### Per-level scaling

Every skill scales with diminishing returns. The progress curve is
`level_progress(level) = sqrt(level / 100)`, so:

| Level | Progress |
| ----- | -------- |
| 1     | 10%      |
| 10    | 32%      |
| 25    | 50%      |
| 50    | 71%      |
| 100   | 100%     |

Sqrt feels generous early (every level matters) and naturally
flattens near the end (99 -> 100 is a small gain). The "final"
value above is multiplied by `level_progress(level)` to get the
in-game value at any given level.

### Future catalog additions

Domains we expect to populate as time permits. Each row is a
catalog entry plus (when needed) a new SkillEffect variant.

- Survival: Gear Hardiness, Max Health, Health Regen, Stamina
  Pool, Stamina Regen.
- Combat: Critical Chance, Critical Damage, Evasion / Dodge,
  Thorns.
- Movement: Walk Speed (separate from Move Speed if we want),
  Climb Speed, Collision / Impact Damage Resistance.
- Utility: Gather Yield, Crafting Discount, Repair Discount,
  Hauling Capacity.

Targeting ~25 skills total when populated, similar to War3FT's
catalog scope (collapsed to a single flat menu).

## XP curve

Cumulative XP required to reach level N is `100 * N^1.8`, capped
at level 50. Per-creature XP is a small static lookup keyed on the
dying actor's BP class (Aphid 5, Weevil 15, Spider 75, Boss 750,
unknown 5). Lookup table in
[`xp.rs`](../better-backpack/src/rpg/xp.rs).

## Kill detection

We hook `Maine.HealthComponent`'s ProcessEvent slot. The kill
signal is `MulticastHandleEffectsWithDamageFlags`, a NetMulticast
RPC fired on every damage hit, whose `DamageFlags` int parameter
carries the `EDamageInfoFlags::KillingBlow = 2` bit when the hit
is lethal.

When the bit is set, we read `LastDamageInfo.InstigatorController`
(at +0x3B0 on the HealthComponent, +0x20 inside FDamageInfo) to
identify the killer, then classify into three buckets:

| Bucket | Match                                                         | Action            |
| ------ | ------------------------------------------------------------- | ----------------- |
| Player | Instigator class chain contains "PlayerController".           | Award full XP.    |
| Buggy  | Instigator (or its possessed Pawn at +0x308) class contains "Buggy". | Award `settings.rpg.buggy_kill_xp_multiplier * XP` (default 1.0). |
| Other  | Any other AIController; enemy-vs-enemy fights.                | No XP, no record. |

Filter: the dying actor must be an `ASurvivalCreature` subclass.
Buildings, props, and the player's own death go through different
code paths; this filter ensures we only award XP for creature
kills.

### Why not `HealthComponent.Kill`?

`Kill` is `Final|Native`. The engine's internal damage path calls
the C++ method directly, bypassing ProcessEvent. Hooking it
catches nothing. The multicast path was the right answer; see
[`changelog.md`](changelog.md) for the full investigation.

### Known issue: pkg(0) instigator

Some legitimate player kills resolve `InstigatorController` to
`/Script/CoreUObject (Package)` (object index 0, the
default-constructed FWeakObjectPtr). Player loses XP for those
kills. Tracked in [`todo.md`](todo.md). Investigation plan:
hook `ApplyDamageFromInfo` upstream and cache the killer per
HealthComponent before the multicast fires.

## Persistence

PlayerState is stored in
`<DLL_dir>/saves/<playthrough-guid>.json`. The guid comes from
`AInGameGameState.PlaythroughGuid` at +0x32C; it's stable across
save renames so the file follows the save reliably.

Schema (open shape via `#[serde(default)]` so older files load
into newer code without losing the player's progress):

```json
{
  "xp": 0,
  "level": 1,
  "skill_points": 0,
  "skill_levels": { "backpack": 5, "lifesteal": 3 },
  "kill_count": 0,
  "last_killed": ""
}
```

The save loader is `rpg/world_loader.rs`: a 1Hz poller that
watches `save_slot::current_slot_key()` and drives the
`tracker::activate_slot` / `deactivate_slot` transitions. When a
save activates, `apply::apply` runs immediately so skill levels
are reflected in CDOs from the moment the player is in-world.
Save-swap (Some(a) -> Some(b)) is handled too.

Why eager (not lazy) load: skill levels affect player stats from
spawn, not from the first kill. A lazy "load on first kill"
shortcut was used during Spike B but is gone.

## Apply step

The apply step writes skill-leveled values into the game. Lives
in `rpg/apply.rs`. Two public entry points:

| Function                                  | Use                                                      |
| ----------------------------------------- | -------------------------------------------------------- |
| `apply(state, settings)`                  | Walks every skill in the catalog. Called on `activate_slot`. |
| `apply_one(state, settings, skill_id)`    | Re-applies just one skill. Called from `spend_skill_point`. |

`apply_skill` matches on `SkillEffect` and dispatches:

| `SkillEffect` variant      | Does                                                      |
| -------------------------- | --------------------------------------------------------- |
| `BackpackSlots`            | `patch::run(settings.slot_count + skill_bonus)`.          |
| `SurvivalDrain`            | Walk SurvivalComponent CDO, write `vanilla * settings_mult * (1 - skill_red * progress)`. |
| `PlayerCharFloat`          | Walk player ASurvivalCharacter CDOs, write `base + max_bonus * progress` at offset. |
| `PlayerHealthCompFloat`    | Same but follow the HealthComponent ptr at +0x1340 first. |
| `PlayerMovementMult`       | Follow CharMovementComponent at +0x1380, scale captured-vanilla baselines at multiple offsets, including Grounded-specific custom movement multipliers, and mirror the same writes onto live player pawns. |
| `Runtime`                  | No CDO write. Live trampolines read the level on each event, e.g. Lifesteal from damage hooks. |

CDO writes propagate to newly-spawned instances. Movement skills
also mirror the same writes onto the *current* player pawn, so
Move Speed / Jump Height / Glide Speed can take effect without a
reload. Combat-side live-instance writes are still a TODO (see
[`todo.md`](todo.md)).

### Two distinct self-damage paths

The damage trace established that high-mobility builds in Grounded 2
get killed by two different things, through two different code paths.
Both fire `UHealthComponent::MulticastHandleEffectsWithDamageFlagsAtOwnerLocation`
on the player's HealthComponent, but `LastDamageInfo` (+0x3B0) is the
discriminator:

| Failure mode    | DamageType class            | src_type | Notes |
| --------------- | --------------------------- | -------- | ----- |
| Fall damage     | `<null>`                    | 0        | Whole `FDamageInfo` is empty. Engine writes `CurrentDamage` directly without populating the damage record. |
| Plant / terrain collision | `BP_EnvironmentalDamage_C`  | 2        | Standard `FDamageInfo` pipeline. Triggered by ramming foliage / world geometry at high speed. |

Treat them as separate skills with separate mitigation strategies:

- **Fall Damage Resistance** has to deal with the bypass-the-pipeline
  case (see below).
- **Collision / Impact Damage Resistance** is the cleaner of the two
  -- filter the existing multicast hook on
  `LastDamageInfo.DamageType == BP_EnvironmentalDamage_C` and zero or
  reduce damage at level 100. That makes high-speed ground travel
  survivable. Tracked in [`todo.md`](todo.md).

### Fall damage path

SDK review shows fall damage is not a generic "guess the damage type"
problem. `ASurvivalCharacter` has an explicit fall pipeline:

- `bTakeFallDamage` at `+0x1571`
- `MinimumFallDamageVelocity` at `+0x1574`
- `FallDamageRatio` at `+0x157C`
- native `ApplyFallDamage()`

Those fields live directly on `ASurvivalCharacter`, and the player BP
also exposes `OnLanded`. That makes Fall Damage Resistance a better fit
for direct player-character field writes than for a generic
`HealthComponent.ApplyDamageFromInfo` runtime hook.

Current state:
- the mod patches `FallDamageRatio`, `bTakeFallDamage`, and
  `MinimumFallDamageVelocity` on player CDOs and the live pawn
- logs confirm the write is happening
- the player can still take fall damage in practice

So the field-only approach is not sufficient. The first direct-hook
plan is now to hook the concrete player BP classes rather than the base
classes, because the current `ProcessEventHook` matches exact live
vtables and the in-game pawn is a concrete
`BP_SurvivalPlayerCharacter_*` subclass. That makes these the next
targets:

- `BP_SurvivalPlayerCharacter_C::OnLanded(const FHitResult&)`
- `BP_SurvivalPlayerCharacter_Female02_C::OnLanded(const FHitResult&)`
- other concrete player BP variants seen at runtime if needed

That direct concrete-BP hook pass did work: logs now show
`OnLanded` being suppressed on the live player pawn. But the player can
still take fall damage, which means `OnLanded` is not the damaging seam
or is too late in the sequence to stop the damage.

So the next investigation target is no longer "hook the right player
class" but "hook the right fall step." The most likely nearby surfaces
now are:

- `ASurvivalCharacter::MulticastFallEffects(...)`
- the player BP damaged delegate bound from `HealthComponent`
- other player BP fall-adjacent events such as `NotifyOnLandAnimBegin`

SDK review surfaced two more candidate seams and both were patched:

- `USurvivalGameModeSettings::FallDamageMultiplier` at +0x008C (CDO-side
  per-game-mode scalar)
- `FCustomGameModeSettings::FallDamageMultiplier` at +0x1C inside
  `USurvivalModeManagerComponent::CustomSettings` (+0x114 on the live
  component, absolute +0x130) -- the replicated runtime copy

In-game test at level 100 with all four field surfaces zeroed
(per-character ratio + take-flag + min-velocity boost, GMS multiplier,
SMMC replicated struct) plus BP `OnLanded` suppression: **fall damage
still applies**. Logs confirm every write landed and `OnLanded` was
suppressed on the live pawn.

Conclusion: Grounded 2's native fall-damage code does not read any of
the public BP-exposed fall-damage fields. `ApplyFallDamage` UFunction
also never fires via ProcessEvent during a natural fall (engine native
code calls the C++ function pointer directly, bypassing our dispatch
hook).

Tested both `UpdateCustomSettings` UFunction invocation (mimicking the
in-game difficulty UI) and the parallel raw memory writes. The call
dispatches cleanly and `OnRep_CustomSettings` runs as a side effect.
Player still takes fall damage at level 100. That ruled out the entire
field-write surface.

A live ProcessEvent trace on the player's `HealthComponent` then
captured fall damage and a separate plant-collision death:

```
# fall damage
fn=MulticastHandleEffectsWithDamageFlagsAtOwnerLocation damage=92.51 flags=0x0 type_flags=0x0
LastDamageInfo: DamageType=<null> src_type=0 flags=0x0 hit=(0,0,0)
instigator=<none> source=<none> attack=<none>

# plant collision (killing blow)
fn=MulticastHandleEffectsWithDamageFlagsAtOwnerLocation damage=134.88 flags=0x2 type_flags=0x0
LastDamageInfo: DamageType=BP_EnvironmentalDamage_C src_type=2 flags=0x0 hit=(0,0,0)
```

Two big findings:

1. **Fall damage bypasses the entire `FDamageInfo` pipeline.**
   `LastDamageInfo` (+0x3B0 on HealthComponent) is *empty* for fall
   damage -- DamageType, instigator, source, hit location, flags all
   zero. The engine writes straight to `CurrentDamage` without
   populating `LastDamageInfo`. So fall damage is not just bypassing
   ProcessEvent on the call site; it is bypassing the whole
   `ApplyDamageFromInfo` plumbing.
2. **Plant / environmental damage *does* go through the normal pipeline**
   with `DamageType=BP_EnvironmentalDamage_C`, `src_type=2`. Different
   path, different mitigation strategy entirely from fall damage. That
   becomes its own skill (Collision / Impact Damage Resistance).

The kill_hook now snapshots `CurrentDamage` before and after
`original.call` and logs the delta only when nonzero. One controlled
fall produced **no delta line at all** -- meaning
`(after - before).abs() <= 0.001`. Damage is therefore applied
*upstream* of the multicast call. That is also consistent with the
function's UFunction flags: `Net|Reliable|Native|Event|NetMulticast|Public|Const`
where `Const` explicitly forbids state changes. The multicast is
purely a replication notification and skipping `original.call` would
break only cosmetic effects, not damage.

So the multicast is a dead end for upstream interception. The damage
is committed to `CurrentDamage` (+0x32C) by some earlier native code
that runs without a ProcessEvent entry. The only way to stop it at
the source is to intercept that native call -- a native function
detour on `UFunction::native_func`.

### Walking the fall backwards (TRACE COMPLETE)

A broadened PE hook on `BP_SurvivalPlayerCharacter_*` filtered to
fall/land/damage names produced this sequence on one fall, with
`HealthComponent.CurrentDamage` (+0x32C) snapshotted before and after
each `original.call`:

```
OnLanded                                 CD=14.59  (suppressed)
MulticastFallEffects        pre/POST     14.59 / 14.59
ReceiveAnyDamage            pre/POST     14.59 / 14.59
                               <-- native damage write happens here, no PE entry
OnHitReact                  pre/POST     98.61 / 98.61
BndEvt__..._DamagedDelegate pre/POST     98.61 / 98.61
multicast (kill_hook)       damage=84.03
ReceiveHit                  pre/POST     98.61 / 98.61
```

Delta `98.61 - 14.59 = 84.02` ~= multicast `damage=84.03`. The damage
is committed natively in the gap between `ReceiveAnyDamage POST` and
`OnHitReact pre`. No PE-reachable surface lives in that gap, so no
ProcessEvent hook can intercept the write before it lands.

The remaining attack surface is the native function detour: replace
the `UFunction::native_func` slot for
`ASurvivalCharacter::ApplyFallDamage` or
`UHealthComponent::ApplyDamage` so the engine's direct C++ dispatch
lands in our trampoline. That intercepts upstream of the
`CurrentDamage` write.

Steps documented in [`todo.md`](todo.md). The earlier
broadened PE trace on the player BP class will be reverted now that
it has done its diagnostic job.

Known events during one fall, in actual call order, with whether each
is reachable via ProcessEvent:

| Step | Event | PE-reachable? | Source |
| ---- | ----- | ------------- | ------ |
| 1 | `UCharacterMovementComponent::PhysFalling` ticks | no (native virtual) | Engine |
| 2 | `UCharacterMovementComponent::ProcessLanded` | no (native virtual) | Engine |
| 3 | `ACharacter::Landed(Hit)` -> `OnLanded` BP event | YES (we suppress) | Maine SDK |
| 4 | `ASurvivalCharacter::ApplyFallDamage()` (Final, Native) | NO (called via direct C++ dispatch, not via PE) | Maine SDK |
| 5 | `UHealthComponent::ApplyDamage(...)` writes `CurrentDamage` | NO (Final, Native, called directly) | Maine SDK |
| 6 | `UHealthComponent::MulticastHandleEffectsWithDamageFlagsAtOwnerLocation` | YES (we hook) | Maine SDK |
| 7 | `ASurvivalCharacter::MulticastFallEffects(SurfaceType, VelocityZ)` | YES, untested | Maine SDK |
| 8 | `BndEvt__HealthComponent_..._DamagedDelegate` BP handler | YES, untested (fires on BP class vtable, not HealthComponent) | Maine SDK |

Step 4 (`ApplyFallDamage`) is the natural intercept point. Per SDK
hpp it is a UFunction, but our PE hook on its UFunction id never
fires for natural falls -- so the engine reaches the native function
pointer directly, bypassing the dispatch table. The same is true of
step 5.

The walk-backwards trace (above) confirmed there is no PE-reachable
surface in the window between damage computation and the
`CurrentDamage` write. The only remaining intercept upstream of the
write is a native function detour on `UFunction::native_func` for
`ApplyFallDamage` or `UHealthComponent::ApplyDamage`. Tracked in
[`todo.md`](todo.md).

Useful side observation kept on the radar: fall damage is uniquely
identifiable on the multicast (`DamageType == null` on
`LastDamageInfo`), which is what the `BP_EnvironmentalDamage_C`
filter does for the separate Collision / Impact Damage Resistance
skill.

Adjacent SDK surfaces still lower priority:

- `ASurvivalCharacter::MulticastFallEffects(EPhysicalSurface, float VelocityZ)`
- `AnimNotifyState_OverrideTakeFallDamage` /
  `AnimNotifyState_ReduceFallDamage`
- the player BP damaged delegate bound from `HealthComponent`

Adjacent fall-specific SDK surfaces still on the radar if neither path
is the seam:

- `ASurvivalCharacter::MulticastFallEffects(EPhysicalSurface, float VelocityZ)`
- `AnimNotifyState_OverrideTakeFallDamage`
- `AnimNotifyState_ReduceFallDamage`
- the player BP damaged delegate bound from `HealthComponent`

## ImGui tab

UE4SS exposes an ImGui debug overlay; we register an "RPG" tab via
`CppUserModBase::register_tab`. The tab shows level, XP progress
bar, unspent skill points, and a row per skill with left-anchored
`+1` / `+10` buttons and effect text ("level 5 / 100  +30 slots
 (next: +33 slots)").
Always-visible HUD overlay (e.g. XP bar in the corner during
gameplay) would need a custom UMG/HUD path; deferred.

The tab also has a debug footer with `+5 skill points` and
`+50 skill points` buttons so combat / movement skills can be
tested without grinding XP.

## Code map

| File                                    | Authority                                            |
| --------------------------------------- | ---------------------------------------------------- |
| `rpg/skills.rs`                         | Catalog + per-level math + format_effect.            |
| `rpg/apply.rs`                          | Apply step (CDO writes per SkillEffect).             |
| `rpg/state.rs`                          | PlayerState schema + JSON load/save.                 |
| `rpg/save_slot.rs`                      | Resolves the playthrough GUID for the active save.   |
| `rpg/tracker.rs`                        | In-memory state + spend_skill_point + record_kill.   |
| `rpg/world_loader.rs`                   | 1Hz poller for slot transitions.                     |
| `rpg/kill_hook.rs`                      | HealthComponent ProcessEvent hook for kill detection.|
| `rpg/xp.rs`                             | XP curve + per-creature XP table.                    |
| `rpg/ffi.rs`                            | C-ABI surface called by the ImGui lambda.            |
| `cpp/shim.cpp` (RPG section)            | ImGui render lambda + register_tab.                  |

## Settings

`rpg.buggy_kill_xp_multiplier` (default 1.0) scales XP awarded
when the player's Buggy mount makes the killing blow.

The two non-RPG settings (`inventory.slot_count`,
`survival.hunger_multiplier`, `survival.thirst_multiplier`) are
the **base** values that skills layer on top of. Defaults are
vanilla (40 / 1.0 / 1.0); user can override for a starter buff.
Skill levels then add (backpack) or further multiply (survival)
on top of the user's base.

## What's next

Open work tracked in [`todo.md`](todo.md). Highlights:

- Live-instance writes for remaining combat-side skills.
- Collision / Impact Damage Resistance so high-mobility builds stop
  dying when slamming into terrain and plants.
- Health Regen as the next survivability skill after the movement
  safety pass.
- pkg(0) instigator bug fix.
- Catalog expansion (Crit, Evasion, Max Health, Stamina, Gear
  Hardiness, etc.).
- XP curve / per-creature table tuning through real play.
- Optional: global ProcessEvent hook for richer event reach
  (level-up confirms, dialog events, etc.).
