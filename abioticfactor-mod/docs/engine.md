# Engine and modding

[Research index](abiotic-factor.md) | [Todo](todo.md)

The original research priorities at the end are historical. Current work is tracked in [todo](todo.md).

## Game

Game: Abiotic Factor (Early Access, co-op survival)
Steam path: `C:\Games\Steam\steamapps\common\AbioticFactor`
Engine: Unreal Engine 5.4.4
Steam app ID: 427410

## binary

- Shipping exe: `AbioticFactor/Binaries/Win64/AbioticFactor-Win64-Shipping.exe` (138 MB)
- PDB included: `AbioticFactor-Win64-Shipping.pdb` (1.5 GB). Full debug symbols
- D3D12 renderer, OpenImageDenoise (raytracing), EOS SDK (Epic Online Services for multiplayer)
- TBB threading libraries (tbb, tbb12, tbbmalloc)
- Gameplay combines native AbioticFactor classes and cooked Blueprints. The shipped PDB contains native controller, character, game mode, session, save, and movement code; Blueprint graphs provide additional gameplay sequencing.

## mod infrastructure

- UE4SS: AF-UE4SS bundle v1.22.0 (UE4SS v3.0.1-1012-gc838a8ac) from https://github.com/igromanru/AF-UE4SS
  - The stock UE4SS v3.0.1 stable does NOT work (FName::StaticAlignment crash on UE 5.4.4)
  - Must use the community AF-UE4SS bundle which includes correct dwmapi.dll proxy (71KB, not 279KB)
  - Settings: HookAActorTick=0, HookGameViewportClientTick=0 (crash prevention), HookEngineTick=1 (required for FName constructor verification)
  - Known instability: crashes on menu transitions and occasionally on level load, stable during gameplay
- Vortex managing pak mods in `Content/Paks/~mods/`
- Existing mod installed: "Better Backpacks (up to 72 slots)" as IoStore pak mod

## ueforge mod status

- Crate: `abioticfactor-mod` in modforge workspace
- HTTP control plane on port 31260, endpoint `/debug`
- Uses `resolve_and_init` (patternsleuth auto-resolve, no hardcoded offsets)
- ProcessEvent vtable index: 0x4D, GObjects layout: WrappedChunked
- patternsleuth resolves: g_objects, g_names, append_string, gmalloc
- Discovery: 69 data tables, 4345 classes, 4334 structs (at startup, before world load streams more)

## key classes (from binary strings and runtime discovery)

| Class | Purpose |
|---|---|
| AAbioticCharacter | Player/NPC character base |
| AAbioticGameMode | Server game mode |
| AAbioticGameStatep | Game state replication |
| AAbioticPlayerController | Player input and control |
| AAbioticWorldSettings | World configuration |
| UAbioticGameInstance | Persistent game instance |
| UAbioticGameUserSettings | User settings (graphics, controls) |
| UAbioticCharacterMovementComponent | Custom movement |
| UAbioticProjectileComponent | Projectile physics |
| UAbioticReplicationGraph | Multiplayer replication |
| UAbioticTargetingSubsystem | AI and player targeting |
| UAbioticSave | Save system |

## data tables (69 discovered at runtime)

Key tables for modding:
- `DT_Skills` (17 skill rows: Sprinting, Accuracy, Reloading, Sneaking, SharpMelee, BluntMelee, Fishing, Crafting, Construction, FirstAid, Agriculture, Cooking, Engineering, plus Fortitude, Resilience, Strength, Throwing, Repair)
- `DT_SkillPerks` (perks unlocked at skill levels)
- `DT_SkillRecipes` (recipes gated by skill level)
- `DT_BuffsDebuffs` (buff/debuff definitions)
- `DT_DamageDefinitions` (damage type definitions)
- `DT_Traits` / `CDT_AllTraits` (character traits)
- `DT_PhDs` (PhD specializations)
- `DT_Levels` (level/map definitions)
- `DT_WeatherEvents` (weather system)
- `DT_Quests` / `DT_StoryProgression` (quest system)

## modding approach

Rust cdylib loaded by UE4SS as a CPPMod via the ueforge shim.
Uses patternsleuth for offset resolution (no hardcoded addresses, survives game patches).
AF-UE4SS community bundle required for UE 5.4.4 compatibility.

## Original research priorities (historical)

1. Dump DT_SkillPerks to find perk unlock levels and effects
2. Dump DT_Skills with a refresh after world load (row struct may have more fields once Blueprint data is streamed)
3. Find difficulty settings on GameMode or GameInstance classes
4. Determine XP curve and scaling functions for the "harder difficulty, better rewards" mod
5. Research DT_DamageDefinitions for damage scaling on Hard
6. Research DT_BuffsDebuffs for potential reward buffs
