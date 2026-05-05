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

`SKILL_IMPACT_RESISTANCE = "impact_resistance"`, `Runtime` effect,
`max_bonus = 1.0` (full immunity at level 100, sqrt curve below).

**Diagnostic phase (currently in build).** When the user puts at
least one point into `impact_resistance`, `fall_hook.rs` switches on
a walk-backwards PE trace on the player BP class. Each event logs
`CurrentDamage` (+0x32C on the player's HealthComponent at +0x1340)
before and after `original.call`. The trace stays silent for normal
users (no skill points = no logging).

#### Observed trace (hazard zone hit, fatal)

Running into a `BP_Hazard_PetRestriction_Labs_C` zone:

```
ReceiveTick                     CD=85.02
MulticastFallEffects            CD=85.02
ReceiveAnyDamage                CD=85.02
                                  <-- native CurrentDamage write here
BndEvt__..._OnHealthStateChangedDelegate  CD=110.00
OnHealthStateChanged            CD=110.00
BndEvt__..._DeathDelegate       CD=110.00
ReceiveUnpossessed              CD=100.00 (post-respawn clamp)
ReceiveControllerChanged        CD=100.00
BndEvt__..._DamagedDelegate     CD=100.00
multicast (kill_hook)           damage=165.18, flags=0x2 (kill)
                                LastDamageInfo: DamageType=SurvivalDamageType,
                                                src_type=2,
                                                source=BP_Hazard_PetRestriction_Labs_C
```

Same shape as fall damage. The damage write happens in the gap
between `ReceiveAnyDamage POST` and `OnHealthStateChangedDelegate
PRE`. No PE-reachable surface lives in that gap, so the native
write is upstream of every PE entry the engine fires on the player
BP class.

`MulticastFallEffects` firing here despite no actual fall is also
informative: that multicast is keyed on impact-velocity events
generally, not just landing after airtime. Confirms it is
cosmetic-only.

The reported `damage=165.18` does not match the on-disk delta
(`110 - 85 = 25`) because Grounded 2 clamps `CurrentDamage` to
`MaxHealth + overkill` at the death threshold; the multicast carries
the unclamped pre-clamp value.

#### Why velocity-stomp does NOT carry over from fall

Fall damage works because native `ApplyFallDamage()` reads
`CharMovementComponent.Velocity.Z` *live* at invocation time and
the fall path runs synchronously after `OnLanded` fires. We mutate
`Velocity.Z` during `OnLanded` and the native formula reads our
mutation.

Hazard / impact damage uses the standard `AActor::TakeDamage` ->
`UHealthComponent::ApplyDamageFromInfo` flow. By the time
`ReceiveAnyDamage` (a notification) fires, the damage value is
already a computed `float` baked into a native frame local. There
is no live field for us to mutate that affects the damage value.

#### Open intercept candidates (untested)

Listed in order of expected effort. Each requires its own diagnostic
pass.

1. **Mutate the `Damage` parm of `ReceiveAnyDamage`**. The parms
   struct slot is writable from our PE hook even though the parm is
   marked `ConstParm`. If Grounded 2's BP graph for the player
   actually applies damage in BP code via `ReceiveAnyDamage`, the
   modified parm would land. (We have weak evidence against this --
   our trace shows `CurrentDamage` does not change during
   `original.call(ReceiveAnyDamage)`.)
2. **Write `UHealthComponent::ImmunityFlags`** (uint32, +0x00F8,
   `Edit, Net`). Bitmask of damage types the actor is immune to.
   If the native pre-damage gate consults this, set it briefly during
   the `ReceiveAnyDamage` PE hook to mask out
   `ESurvivalDamageTypeFlags` bits matching the incoming damage.
   Restore after. Need to identify which bits map to environmental
   / hazard / collision damage in the enum.
3. **Write `UHealthComponent::BaseDamageReduction` to 1.0** during
   `ReceiveAnyDamage`. Armor skill already touches this field
   (writes 0.5 at level 100). Setting to 1.0 *might* zero damage in
   the native multiplier path -- but only if `BaseDamageReduction`
   is consulted for hazard damage and only if it is consulted *after*
   `ReceiveAnyDamage` returns. Untested. Risk: stacks badly with
   Armor skill.
4. **Native function detour** against
   `UHealthComponent::ApplyDamage` via PolyHook_2_0 (last resort,
   see "If the velocity-stomp regresses" above). Definitively
   suppresses damage but is the heaviest implementation.

The current build has only the diagnostic trace. The next change
will try option (1) and observe whether `CurrentDamage` is gated by
the parm we modify.

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
| +0x1380 | UCharacterMovementComponent* | `CharMovementComponent`                  |
| +0x12B8 | float            | `CustomDamageMultiplier` (Attack Damage skill writes) |
| +0x1571 | bool             | `bTakeFallDamage` (UNUSED by native fall code)        |
| +0x1574 | float            | `MinimumFallDamageVelocity` (UNUSED)                  |
| +0x157C | float            | `FallDamageRatio` (UNUSED)                            |

The "UNUSED" entries are SDK-exposed but not consulted by Grounded
2's native fall-damage code. Documented here so we do not retry
patching them.

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
