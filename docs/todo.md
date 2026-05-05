# TODO

> **Authoritative on:** open work. What's NEXT, not what's done.
> Completed milestones live in [`changelog.md`](changelog.md).
> Per-subject deep dives live in this `docs/` directory.

Roughly ordered by leverage. "Mid" priority items below the line
are not blocking; pick from the top of the list when starting a
new session.

---

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
- [ ] **Max Health.** `PlayerHealthCompFloat`,
  `MaxHealth` at +0x328. Probably want additive, not
  multiplicative, so player can stack +HP rather than scaling a
  base.
- [ ] **Health Regen.** Field offset still TBD; UE4SS Live View
  will surface it in seconds. `PlayerHealthCompFloat` shape.
  This is now an explicit survivability skill we want in the near
  term, alongside fall / impact mitigation for high-mobility builds.
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

Catalog target: ~25 skills. Today: 9. War3FT had ~17, we collapse
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

## RPG: Impact Damage Resistance (DONE, but binary)

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
