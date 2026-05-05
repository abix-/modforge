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

### Current catalog (9 skills)

| Skill            | Domain     | Final value at level 100         |
| ---------------- | ---------- | -------------------------------- |
| Backpack         | survival   | +60 slots (40 vanilla -> 100)    |
| Hunger Resistance| survival   | -75% drain (1.0x -> 0.25x)       |
| Thirst Resistance| survival   | -75% drain                       |
| Attack Damage    | combat     | +50% damage (1.0x -> 1.5x)       |
| Armor            | combat     | -50% damage taken                |
| Move Speed       | movement   | +50% walk + sprint + swim        |
| Jump Height      | movement   | +80% jump-Z velocity             |
| Glide Speed      | movement   | +50% MaxFlySpeed                 |
| Lifesteal        | combat     | +30% of damage dealt healed back |

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
  Climb Speed.
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
| `PlayerMovementMult`       | Same but follow CharMovementComponent at +0x1380, scale captured-vanilla baselines at multiple offsets. |
| `Runtime`                  | No-op. Live trampolines (kill_hook) read the level on every tick. |

CDO writes propagate to newly-spawned instances. Effect on the
*current* player session for combat / movement skills requires a
save reload; live-instance writes are a TODO (see
[`todo.md`](todo.md)).

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

- Live-instance writes for combat / movement skills (currently
  CDO-only, requires save reload to take effect on the active
  session).
- pkg(0) instigator bug fix.
- Catalog expansion (Crit, Evasion, Max Health, Stamina, Gear
  Hardiness, etc.).
- XP curve / per-creature table tuning through real play.
- Optional: global ProcessEvent hook for richer event reach
  (level-up confirms, dialog events, etc.).
