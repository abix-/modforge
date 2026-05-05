# Damage system

> **Authoritative on:** Grounded 2's damage pipelines as observed at
> the SDK / runtime level. What goes through `FDamageInfo`, what
> bypasses it, where `CurrentDamage` is written, which surfaces are
> reachable via UE4SS ProcessEvent hooks and which are not. This is
> the reference any skill that mitigates or routes damage should
> read first.
>
> For skills that consume this surface see [`rpg.md`](rpg.md). For
> the build / loader story see [`ue4ss-port.md`](ue4ss-port.md) and
> [`building.md`](building.md).

## Three distinct self-damage paths

High-mobility players in Grounded 2 die to three different things,
and they are *not* the same code path:

| Failure mode    | DamageType class            | src_type | DamageSource example | Pipeline |
| --------------- | --------------------------- | -------- | -------------------- | -------- |
| Fall damage     | `<null>`                    | 0        | none populated        | Native, bypasses `FDamageInfo`. Engine writes `CurrentDamage` directly. |
| Plant / terrain collision | `BP_EnvironmentalDamage_C` | 2 | (foliage / world geo) | Standard `FDamageInfo` pipeline through `ApplyDamageFromInfo`. Triggered by ramming foliage at high speed. |
| Hazard zones | `SurvivalDamageType` (base class) | 2 | `BP_Hazard_*_C` (e.g. `BP_Hazard_PetRestriction_Labs_C`) | Standard `FDamageInfo` pipeline. Triggered by entering / standing in a damage volume (Lab restriction barriers, sizzle/chill zones, etc.). |

Both ultimately surface a
`UHealthComponent::MulticastHandleEffectsWithDamageFlagsAtOwnerLocation`
event for cosmetic effects. The discriminator is
`HealthComponent.LastDamageInfo` (+0x3B0): empty for fall damage,
fully populated for environmental and normal damage. So the two
paths share their final notification surface but diverge entirely
upstream.

## HealthComponent layout (relevant fields)

`UHealthComponent` (Maine_classes.hpp:42186), held by every damageable
actor. Player's pointer at `ASurvivalCharacter +0x1340`.

| Offset  | Type        | Field                                 |
| ------- | ----------- | ------------------------------------- |
| +0x00EC | float       | `BaseDamageReduction` (Armor skill)   |
| +0x0328 | float       | `MaxHealth`                           |
| +0x032C | float       | `CurrentDamage` (Net, RepNotify)      |
| +0x03B0 | FDamageInfo | `LastDamageInfo` (0xE8 bytes)         |

Player health = `MaxHealth - CurrentDamage`. The runtime updates
`CurrentDamage` on every hit, increases it for damage, decreases it
for heals.

## FDamageInfo layout

Standard damage record (Maine_structs.hpp:4810, 0xE8 bytes). When
populated, every field below is filled. When empty (fall damage), the
whole struct stays zeroed and the runtime still writes `CurrentDamage`
without it.

| Offset  | Type                          | Field                       |
| ------- | ----------------------------- | --------------------------- |
| +0x0008 | FVector                       | `HitLocation`               |
| +0x0020 | TWeakObjectPtr<AController>   | `InstigatorController`      |
| +0x0028 | TWeakObjectPtr<UObject>       | `DamageSource`              |
| +0x0030 | TWeakObjectPtr<AActor>        | `Target`                    |
| +0x0038 | EInflictDamageStyle (u8)      | `InflictStyle`              |
| +0x0040 | TSubclassOf<UDamageType>      | `DamageType` -- the discriminator |
| +0x004C | TWeakObjectPtr<UAttack>       | `OriginAttack`              |
| +0x006A | EDamageSourceType (u8)        | `DamageSourceType`          |
| +0x0070 | int32                         | `DamageFlags`               |
| +0x0078 | FDamageData                   | `OriginDamageData`          |

For damage that goes through `ApplyDamageFromInfo`, the struct is
populated *before* `CurrentDamage` is written. So reading
`LastDamageInfo` at any post-write PE event tells you what just hit.

## Multicast surfaces (PE-reachable)

`UHealthComponent` exposes three multicast variants for damage
effects, all `Net|NetMulticast|Native|Event|Const`. `Const` means
they cannot modify state -- they fire *after* the damage write as
client-side notifications.

| Function | Parm layout |
| -------- | ----------- |
| `MulticastHandleEffectsWithDamageFlags` | `HitLocation` +0x00 (FVector_NetQuantize 0x18), `Damage` +0x18 (f32), `DamageFlags` +0x1C (i32), `DamageTypeFlags` +0x20 (u32), `PlayEffectType` +0x24 (u8) |
| `MulticastHandleEffectsWithDamageFlagsAtOwnerLocation` | `Damage` +0x00 (f32), `DamageFlags` +0x04 (i32), `DamageTypeFlags` +0x08 (u32), `PlayEffectType` +0x0C (u8) |
| `MulticastHandleEffectsWithDamageFlagsAndInflictStyleAtOwnerLocation` | Same as above plus `InflictStyle` +0x0D (u8) |

Skipping `original.call` on any of these only suppresses cosmetic
effects, not damage -- the damage is already in `CurrentDamage` by
the time these fire. Confirmed by `before/after CurrentDamage`
snapshot around `original.call`: delta is zero across all three.

`DamageFlags` carries `EDamageInfoFlags::KillingBlow = 2` when the
hit is lethal; this is the bit `kill_hook` uses for kill detection.
`DamageTypeFlags` is the `ESurvivalDamageTypeFlags` bitmask --
empty for fall damage, application-specific for typed damage.

## Fall damage path

### Event order in one engine tick

| Step | Event | PE-reachable? |
| ---- | ----- | ------------- |
| 1 | `UCharacterMovementComponent::PhysFalling` ticks | no (native) |
| 2 | `UCharacterMovementComponent::ProcessLanded` | no (native) |
| 3 | `ACharacter::Landed(Hit)` -> `OnLanded` BP event | **YES** |
| 4 | `ASurvivalCharacter::ApplyFallDamage()` reads `CharMovementComponent.Velocity.Z` and computes damage | no (engine direct C++ dispatch from `Super::Landed` native frame) |
| 5 | `UHealthComponent::ApplyDamage(...)` writes `CurrentDamage` | no (engine direct C++ dispatch) |
| 6 | `MulticastHandleEffectsWithDamageFlagsAtOwnerLocation` fires (post-damage cosmetic) | YES |
| 7 | `MulticastFallEffects(SurfaceType, VelocityZ)` | YES (cosmetic) |
| 8 | `BndEvt__HealthComponent_..._DamagedDelegate` (on the BP class) | YES |

The native fall path runs entirely between step 3 and step 6 with no
PE entry. `ApplyFallDamage` and `ApplyDamage` are both
`Final+Native+BlueprintCallable` UFunctions, but the engine calls
their C++ implementations directly when invoked from a native frame.
The UFunction's `native_func` slot is consulted only for BP /
ProcessEvent calls.

### Observed trace (level 100 fall, pre-fix)

```
OnLanded                                 CD=14.59  (suppressed)
MulticastFallEffects        pre/POST     14.59 / 14.59
ReceiveAnyDamage            pre/POST     14.59 / 14.59
                               <-- native CurrentDamage write happens here
OnHitReact                  pre/POST     98.61 / 98.61
BndEvt__..._DamagedDelegate pre/POST     98.61 / 98.61
multicast (kill_hook)       damage=84.03
ReceiveHit                  pre/POST     98.61 / 98.61
```

Delta `98.61 - 14.59 = 84.02` ~= multicast `damage=84.03`. The damage
write is *between* `ReceiveAnyDamage POST` and `OnHitReact pre` and
no PE-reachable surface lives in that gap.

### LastDamageInfo on fall damage (proof of pipeline bypass)

```
fn=MulticastHandleEffectsWithDamageFlagsAtOwnerLocation damage=92.51 flags=0x0 type_flags=0x0
LastDamageInfo: DamageType=<null> src_type=0 flags=0x0 hit=(0,0,0)
instigator=<none> source=<none> attack=<none>
```

Every slot of `LastDamageInfo` is empty. The native code does not
construct an `FDamageInfo` for fall damage -- it just writes
`CurrentDamage` and fires the cosmetic multicast.

### Approaches that do not work (and why)

| Approach | Result |
| -------- | ------ |
| Patch `bTakeFallDamage` (+0x1571), `MinimumFallDamageVelocity` (+0x1574), `FallDamageRatio` (+0x157C) on `ASurvivalCharacter` CDO and live pawn | Writes land per logs, native code does not read these fields. |
| Patch `USurvivalGameModeSettings::FallDamageMultiplier` (+0x008C) on every CDO instance (8 settings classes for various difficulty modes) | Writes land. No effect. |
| Patch the replicated `FCustomGameModeSettings::FallDamageMultiplier` at +0x1C inside `USurvivalModeManagerComponent::CustomSettings` (CustomSettings is at +0x114 on the component, so absolute +0x130) | Writes land. No effect. |
| Call `USurvivalModeManagerComponent::UpdateCustomSettings` UFunction via ProcessEvent (mimics the in-game difficulty UI; runs `OnRep_CustomSettings` server-side) | Dispatch reported by UE4SS, no effect on damage. |
| ProcessEvent hook on `OnLanded` and skip `original.call` | OnLanded is BP-cosmetic. Engine does not gate damage on BP event return. |
| ProcessEvent hook on `ApplyFallDamage` UFunction directly | Hook never fires -- engine bypasses ProcessEvent for `Final+Native+BlueprintCallable` when called from native code. |
| UE4SS Lua `RegisterHook("/Script/Maine.SurvivalCharacter:ApplyFallDamage", ...)` | UE4SS reports `Registered native hook (1, 2)`, callbacks never fire. Hits [issue #626](https://github.com/UE4SS-RE/RE-UE4SS/issues/626). `RegisterPreHook` swaps `UFunction::native_func`, but the engine's direct C++ call from `Super::Landed` bypasses the slot. |
| Skip `original.call` on the post-damage multicast | Multicast is `Const`, fires *after* the damage write. `before/after CurrentDamage` delta around `original.call` is zero. Skipping breaks cosmetic effects only. |

Net: nothing reachable via ProcessEvent or any field write affects
the native fall damage formula directly. The damage is computed
inline from `CharMovementComponent.Velocity.Z` and written to
`CurrentDamage` in one native call frame between `OnLanded` and the
post-damage multicast.

### The fix: velocity stomp in `OnLanded`

The engine reads `CharMovementComponent.Velocity.Z` *live* at the
moment `ApplyFallDamage()` runs (step 4). `OnLanded` (step 3) fires
during `Super::Landed` from the same native call site, *before*
`ApplyFallDamage` is invoked. Mutating `Velocity.Z` inside our
`OnLanded` PE hook means the native formula sees the mutated value.

`fall_hook.rs` does this in one write:

```text
On player OnLanded with fall_resistance level > 0:
  reduction = sqrt(level / 100)
  Velocity.Z *= (1.0 - reduction)

At level 100  -> reduction = 1.0  -> Velocity.Z = 0   -> no damage.
At level 50   -> reduction ~ 0.71 -> Velocity.Z * 0.29 -> partial.
```

Field offsets:

- `ASurvivalCharacter.CharMovementComponent` ptr: `+0x1380`
- `UMovementComponent.Velocity` (FVector, doubles): `+0x00D8`
- `FVector.Z`: `+0x10` inside FVector -> abs `+0x00E8` on the CMC

The hook does *not* suppress `OnLanded` -- it forwards to the
original BP event so animations / sound / other landing logic still
runs. Validated in-game at level 100: -3431 cm/s landing -> zero
damage. Log line on each fall:

```
rpg/fall: stomped Velocity.Z -3431.07 -> -0.00 on BP_SurvivalPlayerCharacter_Female02_C_... (reduction=1.000)
```

### If the velocity-stomp regresses

If a future Grounded 2 patch changes `ApplyFallDamage` to read from
a captured local instead of live `Velocity.Z` (e.g. `ImpactVelocityZ`
member field, or a pre-captured value passed to a different seam),
the velocity stomp will silently no-op and fall damage will return.

Two fallbacks documented but not implemented:

1. **Detour the C++ method directly** via PolyHook_2_0 (already a
   UE4SS dep). Recover the C++ method address by decoding the first
   `call rel32` instruction inside the UFunction's `native_func`
   thunk -- UHT generates `execApplyFallDamage(UObject*, FFrame&, RESULT_DECL)`
   whose first call is to the actual C++ method.
2. **Pattern-signature scan** via UE4SS's `SinglePassSigScanner`.
   More fragile across patches but does not depend on thunk layout.

## Environmental / collision damage path

Triggered by ramming foliage or world geometry at high speed (very
common at +300% Move Speed).

### Trace evidence

```
fn=MulticastHandleEffectsWithDamageFlagsAtOwnerLocation damage=134.88 flags=0x2 type_flags=0x0
LastDamageInfo: DamageType=BP_EnvironmentalDamage_C src_type=2 flags=0x0 hit=(0,0,0)
```

Same multicast surface as fall damage, but `LastDamageInfo` is fully
populated:

- `DamageType = BP_EnvironmentalDamage_C` (the discriminator)
- `src_type = 2` (`EDamageSourceType::Environmental`)
- `DamageFlags = 0x2` -> KillingBlow set, the hit was lethal here

Unlike fall damage, this path *does* go through the standard
`FDamageInfo` pipeline, which means `ApplyDamageFromInfo` plumbing
is involved upstream. That is a much friendlier surface for
mitigation.

### Mitigation: Impact Damage Resistance skill

`SKILL_IMPACT_RESISTANCE = "impact_resistance"`. Implemented as a
write to `UHealthComponent.RequiredDamageTypeFlags` (+0x00FC,
uint32). At any level > 0 the apply step writes `0xFFFFFFFF` to the
field on every player CDO and on the live player pawn. The native
ApplyDamage gate consults this field as `if ((incoming.type_flags
& Required) == 0) reject`, and fall / environmental damage in
Grounded 2 carries `type_flags = 0`, so no bit matches and the
damage is rejected before `CurrentDamage` is written.

Validated in-game: rock collision and environmental damage both
report `damage=0.00` in the multicast trace; impact-trace POST line
(which fires only on actual `CurrentDamage` change) stays silent.

Creature attacks carry non-zero `type_flags` (`ESurvivalDamageTypeFlags`
bits encode physical / chill / sizzle / etc.) and pass the gate
normally, so the player still takes hostile damage as expected.

#### Observed traces (rock collision and hazard)

Running into a rock at high speed produces *two* consecutive damage
events:

```
# Event 1
MulticastFallEffects           CD=14.59
ReceiveAnyDamage               CD=14.59
                                 <-- native write
OnHitReact                     CD=48.58
BndEvt__..._DamagedDelegate    CD=48.58
multicast: damage=33.99 DamageType=<null> src_type=0          (fall path!)

# Event 2 (same second, same impact)
MulticastFallEffects           CD=48.58
ReceiveAnyDamage               CD=48.58
                                 <-- native write
OnHitReact                     CD=82.56
BndEvt__..._DamagedDelegate    CD=82.56
multicast: damage=33.99 DamageType=BP_EnvironmentalDamage_C   (env path)
```

Two findings:

1. **Rock impact triggers BOTH the fall-damage path AND the
   environmental path** for a single physical event. Each delivers
   the same damage value computed from impact velocity. Net damage
   is roughly double what a fall of equivalent velocity would
   inflict.
2. **`OnLanded` does NOT fire on rock impact.** The fall-damage path
   activates without a Landed event because there was no airtime to
   land from. So our existing `OnLanded` velocity-stomp covered
   actual falls but missed rock collisions entirely.

Why velocity-stomp does NOT carry over from fall: by the time any
PE event fires on a rock / hazard collision, the engine has already
zeroed `CharMovementComponent.Velocity.Z` as part of native
collision response. Confirmed by tracing V.Z at every PE event --
it reads 0.0 throughout. There is no PE-reachable surface with
live velocity for impact damage. The fix has to attack the damage
itself, not the input it was computed from.

#### Diagnostic trace (gated)

When `impact_resistance` level > 0, `fall_hook.rs` logs every
event during which `CurrentDamage` actually changed -- the POST
line fires only when delta > 0.001 to keep the log readable when
`ReceiveHit` etc. fire dozens of times per collision. This trace
is what identified the native-side gating field as the only
remaining intercept and stays silent for users who have not put a
point into the skill.

#### Fallback if `RequiredDamageTypeFlags` regresses

If a future game patch changes the native ApplyDamage gate to
ignore `RequiredDamageTypeFlags`, fall back to one of:

1. `ImmunityFlags` (uint32 at +0x00F8 on `UHealthComponent`,
   `Edit, Net`). Different gate, same idea -- if the runtime check
   is `(incoming & Immunity) != 0 -> reject`, set Immunity to a
   value that catches `type_flags = 0` damage.
2. Native function detour against `UHealthComponent::ApplyDamage`
   via PolyHook_2_0 (last resort, see "If the velocity-stomp
   regresses" above for the technique).

## Kill detection (already implemented)

`kill_hook.rs` hooks
`UHealthComponent::MulticastHandleEffectsWithDamageFlags` (the
non-AtOwnerLocation variant; the location-included form is what
fires on player damage; player kill detection only needs the
HealthComponent variant for creatures). Reads `DamageFlags & 2` for
the KillingBlow bit. On kill, walks
`HealthComponent.LastDamageInfo.InstigatorController` (FWeakObjectPtr
at `+0x3B0 + 0x20`) and classifies into Player / Buggy / Other for
XP attribution. Filters dying actors to `ASurvivalCreature`
subclasses only -- buildings and props also fire this event with
KillingBlow on destruction.

See [`rpg.md`](rpg.md) for the XP layer that consumes this signal.

## Related player-character offsets

`ASurvivalCharacter` (Maine_classes.hpp around line 5700).

| Offset  | Type             | Field                                                 |
| ------- | ---------------- | ----------------------------------------------------- |
| +0x1340 | UHealthComponent* | `HealthComponent`                                     |
| +0x1378 | UStatusEffectComponent* | `StatusEffectComponent` (the canonical extension surface for damage modifiers; see below) |
| +0x1380 | UCharacterMovementComponent* | `CharMovementComponent`                  |
| +0x12B8 | float            | `CustomDamageMultiplier` (Attack Damage skill writes) |
| +0x1571 | bool             | `bTakeFallDamage` (UNUSED by native fall code)        |
| +0x1574 | float            | `MinimumFallDamageVelocity` (UNUSED)                  |
| +0x157C | float            | `FallDamageRatio` (UNUSED)                            |

The "UNUSED" entries are SDK-exposed but not consulted by Grounded
2's native fall-damage code. Documented here so we do not retry
patching them.

## Status Effect system (the canonical extension surface)

Grounded 2 ships a full status-effect system as
`UStatusEffectComponent` on `ASurvivalCharacter` at +0x1378
(`Maine_classes.hpp:35888`). This is the *intended* extension point
for any per-stat / per-damage-type modifier the game can natively
support. Skills that should ultimately be backed by status effects:
fall damage, impact damage, lifesteal, crit chance, crit damage,
thorns, attack damage, stun resist -- nearly every entry in our
catalog has a matching `EStatusEffectType` enum value.

### Why this is the right surface

Our current implementations write scalar fields directly on
`UHealthComponent` (Armor's `BaseDamageReduction`, Impact
Resistance's `RequiredDamageTypeFlags`) or pre-stomp velocity on
`UCharacterMovementComponent` (Fall Resistance). These work but
they are binary or coarse, and they do not scale per-skill-level
along the `sqrt(level/100)` curve the rest of the catalog uses.
The status effect system is *built* for proportional, type-aware,
stackable scaling -- the engine reads it on every damage event.

### The component

`UStatusEffectComponent` (extends `UActorComponent`,
`Maine_classes.hpp:35888`):

| Field | Offset | Notes |
| ----- | ------ | ----- |
| `DefaultStatusEffects` | +0x0108 | `TArray<FDataTableRowHandle>` -- effects added at component init |
| `MountedDefaultStatusEffects` | +0x0118 | Effects added while riding a Buggy mount |
| `UnmountedDefaultStatusEffects` | +0x0128 | Effects added when not mounted |
| `StatusEffects` | +0x01C8 | `TArray<UStatusEffect*>` -- the live, replicated list (Net, RepNotify) |
| `HealthComponent` | +0x0248 | back-pointer to the actor's HC |

Public surface (UFunctions, callable via ProcessEvent):

```cpp
void AddEffect(UStatusEffect* StatusEffect);
UStatusEffect* CreateAndAddEffect(const FDataTableRowHandle& StatusEffectRowHandle);
void RemoveEffect(UStatusEffect* StatusEffect, bool bBroadcastChangedEvent);
bool CanAddEffect(const FDataTableRowHandle& StatusEffectRowHandle) const;

// the getters native damage code queries:
float GetValueForStat(EStatusEffectType StatType, bool bTemporaryEffectsOnly) const;
float GetValueForStatForApplicationTags(EStatusEffectType StatType, AActor* TargetToCheck) const;
float GetValueForStatForDamageTypeFlags(EStatusEffectType StatType, int32 Flags) const;
bool HasStatusEffectOfType(EStatusEffectType StatType) const;
int32 GetNumStatusEffectOfType(EStatusEffectType StatType) const;

// useful event taps:
TMulticastInlineDelegate<void(AActor* Owner, UStatusEffect* StatusEffect)> OnStatusEffectAdded;
TMulticastInlineDelegate<void(AActor* Owner, UStatusEffect* StatusEffect)> OnStatusEffectRemoved;
```

`GetValueForStatForDamageTypeFlags(StatType, Flags)` is the
"proportional, type-filtered" getter. Native damage code passes the
incoming damage's type flag bitmask (the same `DamageTypeFlags` we
read off the multicast parm) and gets back the summed modifier
across all matching status effects on the actor.

### `EStatusEffectType` enum (relevant subset)

`Maine_structs.hpp:136`, 90+ entries. Values that map directly to
skill ideas in our catalog:

| Stat | Value | Use |
| ---- | ----- | --- |
| `MoveSpeed` | 1 | (we currently write CMC fields directly; could replace) |
| `MaxHealth` | 5 | future Max Health skill |
| `MaxStun` | 7 | future stun-resist skill |
| `StunImmunity` | 8 | "" |
| `MaxHauling` | 13 | future hauling skill |
| `FallDamage` | **14** | Fall Damage Resistance |
| `WaterBreathing` | 15 | future skill |
| `HungerRate` | 17 | (we currently write SurvivalComponent directly) |
| `ThirstRate` | 18 | "" |
| `StaminaRegenRate` | 19 | future stamina skill |
| `AttackDamage` | 23 | (we currently write `CustomDamageMultiplier`) |
| `DamageReduction` | 29 | Armor (currently writes `BaseDamageReduction`) |
| `DamageReductionMultiplier` | **30** | proportional generic reduction |
| `CriticalHitChance` | 31 | future crit skill |
| `ApplyAttackEffect` | 33 | future on-hit skill |
| `ReflectDamage` | 37 | future thorns skill |
| `LifeSteal` | **38** | Lifesteal (currently a `Runtime` no-op) |
| `Sizzle` | 48 | sizzle (heat) resist |
| `CriticalDamage` | 62 | future crit-damage skill |
| `Luck` | 65 | future luck skill |
| `Chill` | 76 | chill (cold) resist |

The named values used by skills documented elsewhere in this file
are bolded. This is by far the cleanest mapping between our skill
catalog and the engine's native modifier surface.

### Implementation paths (cheapest to most work)

1. **`CreateAndAddEffect(FDataTableRowHandle)`**. UFunction we can
   call via ProcessEvent on the live `StatusEffectComponent`.
   Requires a data-table row handle that already encodes the stat
   type + value. If Grounded 2 ships rows for the modifiers we want
   (search the cooked content for status effect data tables), this
   is the lowest-effort path. Value is fixed per-row, so for
   skill-level scaling we either need multiple rows (one per
   level) or to mutate the resulting `UStatusEffect`'s value field
   after creation.
2. **Manual `UStatusEffect` instantiation**. Instantiate via
   `NewObject<UClass>` analog (typically reachable through a
   UFunction or a found-class CDO + clone), populate stat type +
   value fields, call `AddEffect(UStatusEffect*)`. Full control over
   the value, scaled by our skill curve. More implementation work
   (need to know `UStatusEffect` field layout).
3. **Mutate existing default status effects**. The component init
   loads `DefaultStatusEffects` rows into the `StatusEffects` array.
   On apply, walk the array, find an entry whose `StatType` matches
   our skill, mutate its value field. Lowest-risk if a default
   already exists for the stat we want.

### Why this beats the current implementations

- **Sqrt-curve scaling.** Status effect values are floats. Set
  `value = max_bonus * sqrt(level/100)` and the engine handles the
  rest.
- **Type filtering for free.** `GetValueForStatForDamageTypeFlags`
  natively skips non-matching damage. We do not have to write a
  separate gate (which is what `RequiredDamageTypeFlags = 0xFFFFFFFF`
  is doing today as a binary stand-in).
- **Stacks with vanilla mods, items, perks.** Other status-effect
  sources in the game add or remove entries on the same component.
  Our skill becomes one of many sources rather than a one-off
  field write that other systems do not see.
- **Save / load semantics handled by the engine.** Status effects
  are replicated and serialized through the existing UE pipeline.

### Migration plan (tracked in todo.md)

Current direct-field-write implementations are interim. The
migration:

1. Locate `UStatusEffect` field layout (StatType offset, Value
   offset, optional duration / source / tags).
2. Add `SkillEffect::PlayerStatusEffect { stat_type, max_value,
   format }` variant in `skills.rs`.
3. `apply.rs` walks live player `StatusEffectComponent`, finds or
   creates a `UStatusEffect` for the given stat type, sets its
   value to `max_value * sqrt(level/100)`.
4. Migrate skills one at a time: Fall, Impact, Lifesteal first
   (they are the ones we know native code consults). Then Armor,
   Attack Damage, etc. once parity is verified.
5. Remove `RequiredDamageTypeFlags` / direct-field hacks from
   `apply.rs` and the velocity-stomp from `fall_hook.rs` after
   each skill is migrated and validated.

## UE4SS hooking caveats observed in Grounded 2

Concrete failures encountered while building the damage system. All
relevant when you are tempted to ProcessEvent-hook a damage surface.

### Issue #626 (`Final+BlueprintCallable` UFunctions)

[GitHub issue #626](https://github.com/UE4SS-RE/RE-UE4SS/issues/626)
applies to Grounded 2 / UE5. UE4SS's `RegisterPreHook` /
`RegisterPostHook` register cleanly (logs report
`[RegisterHook] Registered native hook (N, N+1) for ...`) but the
callbacks silently never fire when the engine calls the C++
implementation directly from a native frame. The mechanism fix
(swap `UFunction::native_func`) only intercepts BP / ProcessEvent
calls, not direct C++ dispatch.

Confirmed broken on Grounded 2 for:

- `/Script/Maine.SurvivalCharacter:ApplyFallDamage`
- `/Script/Maine.HealthComponent:ApplyDamage`

Likely also broken for any other `Final+Native+BlueprintCallable`
UFunction the engine calls from native code. Probe with a Lua
RegisterHook + log before assuming.

### Concrete-BP class hooks vs base-class hooks

Our `ProcessEventHook` matches exact live vtables. Player pawns are
concrete `BP_SurvivalPlayerCharacter_*` subclasses (`_Female02_C`,
`_Gellarde_C`, etc), so a hook installed on the base
`SurvivalCharacter` or `Character` class never matches a real player
instance. `fall_hook.rs` enumerates known concrete subclasses by
name and installs on each.
