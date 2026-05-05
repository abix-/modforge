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
damage mitigation if Grounded 2 reports high-speed self-hits through
the same damage path. Fall damage is now believed to be a separate
character-owned path: `ASurvivalCharacter` has explicit fall fields
(`bTakeFallDamage`, `MinimumFallDamageVelocity`, `FallDamageRatio`)
plus native `ApplyFallDamage()`. So collision / impact mitigation still
needs runtime-path investigation, but fall mitigation should be
implemented as direct character field writes instead.

Current finding: even the expanded field patch is not enough.
Logs confirm writes land on player CDOs and the live pawn for
`FallDamageRatio`, `bTakeFallDamage`, and
`MinimumFallDamageVelocity`, but the player still takes fall damage.
The direct `ApplyFallDamage()` / base `Character.OnLanded` hook attempt
installed cleanly but never fired in logs. Current best explanation:
our `ProcessEventHook` matches exact live vtables, while the player pawn
is a concrete `BP_SurvivalPlayerCharacter_*` subclass.

Next pass should hook the concrete player BP classes first:

- `BP_SurvivalPlayerCharacter_C::OnLanded(const FHitResult&)`
- `BP_SurvivalPlayerCharacter_Female02_C::OnLanded(const FHitResult&)`
- additional player BP variants observed at runtime if needed

Fallback after that: refactor the PE hook to support subclass matching,
or trace the BP player damaged delegate directly.

Latest result: the concrete player BP hook did install and fire.
Logs show:

- `rpg/fall: installed on BP_SurvivalPlayerCharacter_C`
- `rpg/fall: suppressed OnLanded on ...BP_SurvivalPlayerCharacter_Female02_C...`

But the player still took fall damage. So `OnLanded` is not enough to
prevent the damage and is likely not the real damaging seam.

Current build patches every fall-damage field surface known from the
SDK at level 100:

- per-character `FallDamageRatio = 0`, `bTakeFallDamage = false`,
  `MinimumFallDamageVelocity *= 100` (player CDOs + live pawn)
- `USurvivalGameModeSettings::FallDamageMultiplier` (+0x008C) zeroed
  on every CDO of the class
- `FCustomGameModeSettings::FallDamageMultiplier` (+0x1C) zeroed inside
  the replicated `USurvivalModeManagerComponent::CustomSettings`
  (+0x114 on the component, abs +0x130)
- BP `OnLanded` suppressed on concrete `BP_SurvivalPlayerCharacter_*`

Latest test result: every write lands per logs, `OnLanded` is suppressed
each fall, **player still takes fall damage**. So the native
fall-damage code does not consult any BP-exposed field we can find, and
`ApplyFallDamage` UFunction never fires via ProcessEvent during a
natural fall (engine calls the native function pointer directly).

Status (validated in-game):

- Every BP-exposed fall-damage field write lands but does nothing:
  per-character (`bTakeFallDamage`, `FallDamageRatio`,
  `MinimumFallDamageVelocity`), per-game-mode UObject
  (`FallDamageMultiplier` at +0x8C), replicated struct
  (`FCustomGameModeSettings.FallDamageMultiplier` at +0x1C inside
  `USurvivalModeManagerComponent::CustomSettings` +0x114).
- Calling the official setter `UpdateCustomSettings` UFunction via
  ProcessEvent (mimicking the in-game difficulty UI) also lands, runs
  `OnRep_CustomSettings`, and still does nothing.
- BP `OnLanded` ProcessEvent suppression on concrete
  `BP_SurvivalPlayerCharacter_*` works but is post-damage cosmetic.

Damage trace on the player's HealthComponent identified two distinct
damage paths:

- **Fall damage**: fires
  `MulticastHandleEffectsWithDamageFlagsAtOwnerLocation` with
  `LastDamageInfo` *entirely empty* -- DamageType=null, instigator=null,
  source=null, hit=(0,0,0), all flags zero. Native code writes directly
  to `CurrentDamage` (+0x32C) without going through the standard
  `FDamageInfo` / `ApplyDamageFromInfo` pipeline at all.
- **Plant / environmental collision damage** (e.g. running into a plant
  at +300% move speed): same multicast function, but
  `LastDamageInfo.DamageType = BP_EnvironmentalDamage_C`,
  `src_type = 2`. Different code path, separate mitigation strategy.

So fall damage is uniquely identifiable by `DamageType==null` on the
multicast, even though the parm flag fields are zero.

**Current diagnostic in the build**: the multicast hook now snapshots
`CurrentDamage` before and after `original.call` and logs the delta
when nonzero. One controlled fall tells us which side of the multicast
the damage is written on:

- `delta > 0` -> the multicast handler IS the damage-application path.
  Skip `original.call` for fall damage at level 100 and damage is
  suppressed cleanly with no HP flicker. Five-line implementation.
- `delta == 0` -> native code already wrote `CurrentDamage` upstream
  before the multicast fired. Forced into either heal-back (rejected
  for HP flicker) or a native function detour.

**Native detour fallback** (only if the delta is zero): replace the
`UFunction::native_func` slot for `ASurvivalCharacter::ApplyFallDamage`
or `UHealthComponent::ApplyDamage` so the engine's direct C++ dispatch
lands in our trampoline. Materially more code (executable trampoline
via `VirtualAlloc(PAGE_EXECUTE_READWRITE)`, register-preserving
prologue/epilogue, return-to-original path), kept on the table only
because it is the one option upstream of the `CurrentDamage` write.

Heal-back is the third fallback and rejected unless we run out of
options -- HP flicker is worse UX than just taking damage.

Separate skill: **Collision / Impact Damage Resistance** is a real
distinct mitigation now that we have evidence plant collision is its
own path through `BP_EnvironmentalDamage_C`. Filter the existing
multicast hook on `LastDamageInfo.DamageType` for that subclass.

Lower-priority adjacent surfaces still on the radar if everything
above stalls:

- `ASurvivalCharacter::MulticastFallEffects(...)`
- `BP_SurvivalPlayerCharacter_*::BndEvt__HealthComponent...DamagedDelegate...`
- `BP_SurvivalPlayerCharacter_*::NotifyOnLandAnimBegin`
- `AnimNotifyState_OverrideTakeFallDamage` /
  `AnimNotifyState_ReduceFallDamage`

Lower-priority seams kept on the radar:

- `ASurvivalCharacter::MulticastFallEffects(...)`
- `BP_SurvivalPlayerCharacter_*::BndEvt__HealthComponent...DamagedDelegate...`
- `BP_SurvivalPlayerCharacter_*::NotifyOnLandAnimBegin`
- `AnimNotifyState_OverrideTakeFallDamage` / `AnimNotifyState_ReduceFallDamage`

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
- [ ] **Archive winhttp proxy.** Move `better-backpack-cpp/` and
  the original winhttp.dll proxy material to `archive/` once
  the UE4SS path has been live for a while. Keep as a tested
  fallback if UE4SS ever turns out unstable.

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
