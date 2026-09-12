# abiotic factor: engine and modding research

Game: Abiotic Factor (Early Access, co-op survival)
Steam path: `C:\Games\Steam\steamapps\common\AbioticFactor`
Engine: Unreal Engine 5.4.4
Steam app ID: 427410

## binary

- Shipping exe: `AbioticFactor/Binaries/Win64/AbioticFactor-Win64-Shipping.exe` (138 MB)
- PDB included: `AbioticFactor-Win64-Shipping.pdb` (1.5 GB). Full debug symbols
- D3D12 renderer, OpenImageDenoise (raytracing), EOS SDK (Epic Online Services for multiplayer)
- TBB threading libraries (tbb, tbb12, tbbmalloc)
- Game is built entirely in Blueprints (no native C++ gameplay code)

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

## skill system

Data tables: `DT_Skills` and `DT_SkillPerks`

### skills (ECharacterSkills enum, 17 skills)
- Accuracy (ranged aim)
- Agriculture (farming)
- Blunt Melee (clubs, hammers)
- Construction (building)
- Cooking (food prep)
- Crafting (general crafting)
- Engineering (tech/electrical)
- First Aid (healing)
- Fortitude (health/resistance)
- Reloading (weapon reload speed)
- Repair (fixing items)
- Resilience (damage resistance/survival)
- Sharp Melee (blades, axes)
- Sneaking (stealth)
- Sprinting (movement/stamina)
- Strength (carry weight, melee power)
- Throwing (grenades, throwables)
- NoSkill (default/none)

### SkillData struct (from usmap)
- `DisplayName`: TextProperty
- `DisplayDescription`: TextProperty
- `Icon`: SoftObjectProperty
- `SkillType`: EnumProperty (ECharacterSkills)
- `StatModifierMap`: Map<StatModifierRowHandle, int>
- `Perks`: Array<SkillPerkRowHandle>
- NO MaxLevel field. Level cap (vanilla 20) is a Blueprint constant

### SkillPerk struct (from usmap)
- `DisplayName`: TextProperty
- `DisplayDescription`: TextProperty
- `RequiredLevel`: int (gates perk unlock)
- `BuffDebuff`: BuffDebuffRowHandle

### character skill tracking (AbioticCharacter, native C++ class)
- `SkillLevelMap` at offset 2016: TMap<SkillRowHandle, int32>, 80 bytes
  - TMap entry stride: 48 bytes
  - Entry layout: UDataTable* (8) + FName (8) + ptr (8) + i32,i32 (8) + level i32 (+32) + flags (4) + hash (8)
  - Skill level value at entry offset +32
  - 16 entries for the 15+ active skills
- `StatModifiers` at offset 1840: Array<StatModifierEntry>
- `StatModifierMap` at offset 1856: Map<StatModifierRowHandle, float>, 80 bytes
- `CheatStatModifierMap` at offset 1936: Map<StatModifierRowHandle, int>, 80 bytes
- `BuffComponent` at offset 1824: object pointer

### level cap analysis
- SkillData has no MaxLevel field (confirmed from usmap, all 39128 name entries searched)
- No MaxLevel, LevelCap, XPCurve, or XPNeeded field exists anywhere in the usmap
- The level cap of 20 is a literal constant in Blueprint bytecode
- Raising the cap requires either patching Blueprint bytecode or bypassing the check via PE hook

### function signatures (runtime confirmed)
- `Client_EventDispatch_SkillUp(Skill: u8, NewLevel: i32, GainedPerk: u8)` (9 bytes)
- `DoesAwardSkillXPWhenHit(MeleeXP: u8, RangedXP: u8, XPMultiplier: f64)` (16 bytes)
- `Server_Award XP Based On Recipe Category(Category: u8)` (1 byte)
- `Server_TryAwardSkillXPOnTargetable(6 params, 33 bytes)` (BP params, not decoded)
- `UpdateSkillStat(1 param, 1 byte)` (BP param, not decoded)

### XP system
- XP gained through skill-specific actions (combat, crafting, sneaking, etc.)
- `XPMultiplier` field (f64) on `DoesAwardSkillXPWhenHit` allows scaling
- XP gain can be boosted by traits (Wrinkly Brainmeat), consumables (Brain, Brainpower Tincture, soups)
- XP bonuses stack multiplicatively

### XP curve (vanilla + mod extension)

Levels 1-20: vanilla table. Levels 21-100: flat delta of 10,900 per level.

| Level | Total XP | Delta |
|-------|----------|-------|
| 1 | 200 | 200 |
| 2 | 500 | 300 |
| 3 | 940 | 440 |
| 4 | 1,572 | 632 |
| 5 | 2,464 | 892 |
| 6 | 3,699 | 1,235 |
| 7 | 5,379 | 1,680 |
| 8 | 7,587 | 2,208 |
| 9 | 10,417 | 2,830 |
| 10 | 13,950 | 3,533 |
| 11 | 18,242 | 4,292 |
| 12 | 23,307 | 5,065 |
| 13 | 29,101 | 5,794 |
| 14 | 35,776 | 6,675 |
| 15 | 43,310 | 7,534 |
| 16 | 51,631 | 8,321 |
| 17 | 60,608 | 8,977 |
| 18 | 70,354 | 9,746 |
| 19 | 80,755 | 10,401 |
| 20 | 91,655 | 10,900 |
| 21-100 | +10,900 each | 10,900 |

Level 100 total: ~963,655 XP (about 10.5x level 20).

## research and recipe system

- `GlobalRecipeSet`, `GlobalResearchSet` (server-wide unlocks)
- `PlayerRecipeSet`, `PlayerResearchArray` (per-player progression)
- `PlayerNewestRecipes` (recently unlocked)
- `BlacklistRecipes` (disabled recipes)
- Research unlocks recipes. Research categories exist

## difficulty system

- `bHardcoreMode` boolean flag
- `GameDifficulty` (type unknown, possibly enum or int)
- `FriendlyFireMode` on Abiotic_Survival_GameState_C
- No evidence of named presets (Easy/Normal/Hard) in binary strings
- May use custom server settings sliders instead of fixed presets
- Difficulty settings likely on GameMode or GameInstance, not GameState

## body part health

Separate tracking per limb:
- Head, Torso, LeftArm, RightArm, LeftLeg, RightLeg
- `MaxHealthModifier`, `MaxHeadHealthModifier`, `MaxTorsoHealthModifier`
- `DefaultMax_LimbHealthMap` for per-limb max health

## character stats

- `BaseWalkSpeed`, `BaseSprintSpeed`, `MinimumMovementSpeed`
- `GlobalSpeedModifier`, `GlobalSprintSpeedModifier`
- `GlobalSwimSpeedModifier`, `GlobalCrouchSpeedModifier`
- `CurrentStamina`, `MaxStamina`, `StaminaRequiredToSprint`
- Jetpack support (JetpackTimestamp)
- Ghost mode (GhostModeAIDebugState)

## multiplayer

- EOS SDK for cross-platform multiplayer
- Custom replication graph (UAbioticReplicationGraph) with:
  - Spatial cells (configurable bias and size)
  - Frequency buckets for actor update rates
  - Fast shared path with cull distance
  - Per-connection always-relevant nodes
  - Player state frequency limiter
- Platforms: Steam, EOS, GOG, Playstation, Xbox (EAbioticPlatform enum)
- Cross-play setting (EAbioticCrossplaySetting)
- Banned player list persistence

## save system

- UAbioticSave with version migration (OldVersion, NewVersion, ApplyVersionUpgrade)
- Save types: World, WorldBackup, Keybinds, Settings, UserSettings, Customization, Unlocks, UserSettingsBP, PlayerStats
- Per-player and per-level save maps
- Compression support (bHasBeenCompressed)

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

## player input (read from the shipped PDB, 2026-09-12)

The game does not use Enhanced Input for gameplay: with a save loaded,
0 InputMappingContext and 0 InputAction assets exist; the only hits are
6 legacy `InputActionDelegateBinding` objects (Blueprint input events).
Player input therefore goes through the legacy `PlayerInput` path and its
native `InputKey`, which is not a UFunction. The addresses and layouts
below come from `AbioticFactor-Win64-Shipping.pdb` through
`ueforge::symbols` (`tests/research_symbols.rs`), not from guessing.

| Function | Image-relative address | Decorated name |
|---|---|---|
| `APlayerController::InputKey(const FInputKeyParams&)` | `0x3AB2890` | `?InputKey@APlayerController@@UEAA_NAEBUFInputKeyParams@@@Z` |
| `APlayerController::InputKey(FKey, EInputEvent, float, bool)` | `0x3AB2BB0` | `?InputKey@APlayerController@@UEAA_NUFKey@@W4EInputEvent@@M_N@Z` |
| `UPlayerInput::InputKey(const FInputKeyParams&)` | `0x3DA2190` | `?InputKey@UPlayerInput@@UEAA_NAEBUFInputKeyParams@@@Z` |
| `UPlayerInput::InputKey(FKey, EInputEvent, float, bool)` | `0x3DA28F0` | `?InputKey@UPlayerInput@@UEAA_NUFKey@@W4EInputEvent@@M_N@Z` |
| `UGameViewportClient::InputKey(const FInputKeyEventArgs&)` | `0x3716C80` | `?InputKey@UGameViewportClient@@UEAA_NAEBUFInputKeyEventArgs@@@Z` |

`FInputKeyParams` is 72 bytes (UE 5.4, so the same layout applies to
MISERY; the earlier 64-byte guess in the workspace todo was wrong):

| Offset | Size | Field | Type |
|---:|---:|---|---|
| 0 | 24 | Key | FKey |
| 24 | 4 | InputDevice | FInputDeviceId |
| 28 | 4 | Event | EInputEvent |
| 32 | 4 | NumSamples | int32 |
| 36 | 4 | DeltaTime | float |
| 40 | 24 | Delta | TVector<double> |
| 64 | 8 | bIsGamepadOverride | bool (padded) |

`FKey` is 24 bytes: `KeyName` FName at 0, `KeyDetails` TSharedPtr at 8.
`FInputKeyEventArgs` is 56 bytes: Viewport pointer at 0, ControllerId
int32 at 8, InputDevice at 12, Key at 16, Event at 40, AmountDepressed
float at 44, bIsTouchEvent at 48.

## modding approach

Rust cdylib loaded by UE4SS as a CPPMod via the ueforge shim.
Uses patternsleuth for offset resolution (no hardcoded addresses, survives game patches).
AF-UE4SS community bundle required for UE 5.4.4 compatibility.

## next steps

1. Dump DT_SkillPerks to find perk unlock levels and effects
2. Dump DT_Skills with a refresh after world load (row struct may have more fields once Blueprint data is streamed)
3. Find difficulty settings on GameMode or GameInstance classes
4. Determine XP curve and scaling functions for the "harder difficulty, better rewards" mod
5. Research DT_DamageDefinitions for damage scaling on Hard
6. Research DT_BuffsDebuffs for potential reward buffs
