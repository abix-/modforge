# Changelog

> **Authoritative on:** chronological history of milestones,
> investigations, and design pivots. Things that are DONE.
> For what's next see [`todo.md`](todo.md). For per-subject
> deep dives see the other files in this directory.

Newest first.

## 2026-05-05 (single big day)

### Fall Damage Resistance

First attempt used a runtime `HealthComponent.ApplyDamageFromInfo`
hook, but log tracing showed fall damage never passed through that
ProcessEvent surface in practice.

SDK review gave the better answer: `ASurvivalCharacter` owns fall damage
directly via:

- `bTakeFallDamage` (+0x1571)
- `MinimumFallDamageVelocity` (+0x1574)
- `FallDamageRatio` (+0x157C)
- native `ApplyFallDamage()`

So the correct implementation path is to patch fall-related fields on
player CDOs and live pawns instead of guessing through generic health
damage hooks. Collision / impact damage from high-speed movement is
still tracked separately.

Latest result: the field-based path is definitely executing.
`fall_resistance` now patches `FallDamageRatio`,
`bTakeFallDamage`, and `MinimumFallDamageVelocity` on player CDOs and
the live pawn, and logs confirm those writes land. But the player can
still take fall damage, so the field-only approach is not sufficient.

The next plan is more specific now: hook the concrete
`BP_SurvivalPlayerCharacter_*` classes directly. The prior
`ApplyFallDamage()` / base `Character.OnLanded` hook attempt installed,
but never fired. The current `ProcessEventHook` implementation matches
exact live vtables, and the live player pawn is a concrete BP subclass,
so base-class hooks are likely missing the real object.

SDK context also shows `MulticastFallEffects` plus fall-specific anim
notify states (`OverrideTakeFallDamage`, `ReduceFallDamage`), which is
strong evidence the landing pipeline does more than read a single field.

Latest concrete-hook result:
- Hooking the concrete player BP class worked.
- Logs show `OnLanded` suppression on the live
  `BP_SurvivalPlayerCharacter_Female02_C` pawn.
- The player still took fall damage anyway.

So `OnLanded` is confirmed to be insufficient as the mitigation point.
The next likely seams are `MulticastFallEffects`, the player BP damaged
delegate, or another earlier native/BP fall step.

SDK review surfaced a separate per-game-mode scalar
`USurvivalGameModeSettings::FallDamageMultiplier` at +0x008C, plus a
replicated copy `FCustomGameModeSettings::FallDamageMultiplier` at +0x1C
inside `USurvivalModeManagerComponent::CustomSettings` (+0x114 on the
component, absolute +0x130). Both were added to the apply step so
fall_resistance now writes:

- per-character: `FallDamageRatio = 0`, `bTakeFallDamage = false`,
  `MinimumFallDamageVelocity = 100x` -- on player CDOs and the live pawn
- per-game-mode CDO: `FallDamageMultiplier *= (1 - reduction)` on every
  `USurvivalGameModeSettings` instance
- replicated runtime struct: `FallDamageMultiplier *= (1 - reduction)`
  on every live `USurvivalModeManagerComponent`
- BP-side suppression: ProcessEvent suppression of
  `OnLanded` / `ApplyFallDamage` on concrete
  `BP_SurvivalPlayerCharacter_C` and known subclasses

In-game test at level 100 confirmed all writes land:

```
fall_resistance level=100 reduction=1.000 written to 3 player CDO(s),
  1 live pawn(s), 8 game-mode setting(s), 3 mode-manager component(s)
```

`OnLanded suppressed on BP_SurvivalPlayerCharacter_Female02_C_2147481334`
also fires after each landing. **Player still takes fall damage.** So:

- `OnLanded` is purely cosmetic / post-damage. Suppressing it does not
  prevent damage.
- `ApplyFallDamage` UFunction never fires via ProcessEvent during a
  natural fall. The engine calls the native function pointer directly,
  bypassing the dispatch table our hook intercepts.
- The native fall-damage code is not reading any of the per-character
  or per-game-mode fields we patched. Even with `bTakeFallDamage =
  false` and `FallDamageRatio = 0`, damage still applies.

Conclusion: Grounded 2's fall damage path is implemented in native code
that does not read any of the public BP-exposed fall-damage fields, and
raw memory writes to the replicated `FCustomGameModeSettings` struct
also do not affect runtime damage. The native code is reading from a
cached value that ignores both surfaces.

Tested calling `UpdateCustomSettings` (the same `Final, Native,
BlueprintCallable` UFunction the in-game difficulty UI invokes) on the
live mode-manager component via `UObject::process_event`. The call
dispatches on 3 components, runs `OnRep_CustomSettings` server-side,
no crash. **Player still takes fall damage at level 100.**

So the entire field-write surface is dead -- per-character ratio,
take-flag, min velocity, GMS UObject multiplier, FCustomGameModeSettings
struct (raw write *and* through the official setter UFunction): nothing
the runtime fall-damage code reads.

Pivot: stop guessing where the runtime reads from, and instrument the
damage path directly. Extended the existing
`HealthComponent::MulticastHandleEffectsWithDamageFlags` hook with a
trace that logs every PE event arriving on the player's
HealthComponent, plus the parm layouts of the `AtOwnerLocation`
variants and `ApplyDamageFromInfo`. One controlled fall produced:

```
rpg/dmg-trace: player hit fn=MulticastHandleEffectsWithDamageFlagsAtOwnerLocation
               damage=83.63 flags=0x00000000 type_flags=0x00000000
```

So fall damage is delivered through the `AtOwnerLocation` variant
(parm layout: `Damage` at +0x00, `DamageFlags` at +0x04,
`DamageTypeFlags` at +0x08, `PlayEffectType` at +0x0C). Both flag
fields are zero -- no DamageType classification, so we cannot filter
fall damage by flags alone. `ApplyDamageFromInfo` did not appear in
the trace at all, confirming the native fall path bypasses ProcessEvent
on its way to applying damage to `CurrentDamage`.

Event order on one fall:
1. `OnLanded` BP event fires on the live player pawn (we suppress).
2. Native `ApplyFallDamage` runs (no PE entry).
3. Damage is written to `HealthComponent.CurrentDamage` (+0x32C).
4. `MulticastHandleEffectsWithDamageFlagsAtOwnerLocation` fires
   post-damage for cosmetic effects (this is what the trace catches).

Heal-back from the multicast hook (zero `CurrentDamage` after damage
applies) is the obvious code change but rejected as UX: the player
would visibly flicker each fall. Decision: don't pursue heal-back.

Remaining seam is to detour the native function pointer (the
`UFunction::native_func` slot) for `ASurvivalCharacter::ApplyFallDamage`
or `UHealthComponent::ApplyDamage`. That intercepts the engine's direct
C++ dispatch, which is the only point that runs *before* damage is
applied to `CurrentDamage`. Materially more involved than the current
ProcessEvent vtable hook (needs executable trampoline + return-to-
original path), but it is the one option that suppresses fall damage
at the source without HP flicker.

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
[`../better-backpack-cpp/`](../better-backpack-cpp/) for
reference.
