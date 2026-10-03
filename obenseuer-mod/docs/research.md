# Obenseuer research

Everything known about modding Obenseuer, gathered from the installed
game files. Facts here are read from disk unless marked unverified.

## 1. The game

| Property | Value |
|---|---|
| Install path | `C:\Games\Steam\steamapps\common\Obenseuer\` |
| Steam app id | 951240 |
| Developer | Loiste Interactive |
| Engine | **Unity 2019.4.41f2** (LTS) |
| Scripting backend | **Mono** (MonoBleedingEdge present, no IL2CPP) |
| Main exe | `Obenseuer.exe` |
| Main assembly | `Obenseuer_Data/Managed/Assembly-CSharp.dll` (~3 MB) |
| First-pass assembly | `Assembly-CSharp-firstpass.dll` |
| Native plugins | `lib_burst_generated.dll` (Burst jobs), `steam_api64.dll` |
| Asset pipeline | Unity Addressables (`StreamingAssets/aa/catalog.json`) |
| Levels | 78 level files (level0 through level77) |
| Game version | 0.4.17 (from globalgamemanagers) |

## 2. Third-party libraries in Managed/

| DLL | Purpose |
|---|---|
| AstarPathfindingProject | A* pathfinding for NPCs |
| BehaviorDesignerRuntime | behavior tree AI |
| DOTween | animation tweening |
| SALSA-LipSync | lip sync for dialogue |
| Cinemachine | camera system |
| BakeryRuntimeAssembly | lightmap baking |
| Ookii.Dialogs | native file dialogs |
| Newtonsoft.Json | JSON serialization |

## 3. JSON data files (StreamingAssets/)

All loaded at runtime. Mod surface even without code patches.

| File | Content |
|---|---|
| Items.json | item definitions: ID, title, categories, base value, description, stackable count, appearance (material, sprite, prefab), actions, attachments, meta |
| Recipes.json | crafting recipes: ID, name, type (Mashing, etc.), inputs with item refs and amounts, conditions, tags, variant items. UTF-16 LE encoded |
| Characters.json | NPC definitions: ID, name, gender, age, relationship, job, body params (weight, muscle, height, etc.), appearance slots (glasses, beard, hair, hat, jacket). UTF-16 LE encoded |
| CharactersRent.json | rent information per character |
| NPCBehavior.json | NPC schedules: ID, start scene, start position, scheduler (timetable, random activities), prefab path |
| Wearables.json | wearable item definitions |
| StoragePrefabs.json | storage container prefab paths |
| StorageSpawnCategory.json | storage spawn categories |

## 4. Item structure (from Items.json)

```json
{
    "ID": 0,
    "Title": "Open Sewer Coin",
    "Categories": ["Money"],
    "BaseValue": 1,
    "Description": "It's a local coin",
    "Stackable": 99,
    "Appearance": {
        "Material": "Coins",
        "SpritePath": "Sprites/Items/Open Sewer coin",
        "ColorValue": "",
        "EmissionStrength": 0.0,
        "PrefabPath": "Prefabs/Items/Open Sewer coin",
        "PrefabPathMany": "Prefabs/Items/Open Sewer Coin 50",
        "SkinSpritePaths": []
    },
    "Actions": [],
    "Attachments": { "Name": "", "Attachment1": "none", "Attachment2": "none" },
    "Meta": []
}
```

## 5. NPC behavior structure (from NPCBehavior.json)

```json
{
    "ID": 12,
    "startScene": null,
    "startPosition": { "x": 0.0, "y": 0.0, "z": 0.0 },
    "schedulerDisabledAtStart": false,
    "scheduler": {
        "Name": "",
        "Timetable": [],
        "RandomActivities": []
    },
    "prefabPath": "Prefabs/Characters/Speakeasy/Ville Skoldgangster"
}
```

## 6. Character structure (from Characters.json)

Fields: ID, Name, GenderString, Age, Relationship, Job,
FurnitureType, Sprite, Gender (float), Weight, Muscle, Height,
Advanced, ShoulderWidth, HeadSize, FaceSize, NeckLength, BreastSize,
HipWidth, HandSize, FootSize, EyeSize, plus appearance slots
(Glasses, Beard, Hair, Hat, Jacket, etc.).

## 7. Modding ecosystem

The community uses BepInEx as the mod loader. The Lavender library
(github.com/leonarudo/Lavender) provides helper functions. Nexus Mods
hosts published mods. The Stalburg Wiki documents the modding process.

No BepInEx is installed in this copy yet. Install path would be the
game root, with plugins in `BepInEx/plugins/`.

## 8. Modforge integration

This is a Unity Mono game, which is the exact target of unityforge.
The bootstrap path is:

1. BepInEx loads `Unityforge.Shim.dll` into the Obenseuer process.
2. The shim locates `obenseuer_mod.unityforge.dll`, LoadLibrary's it,
   and calls `unityforge_init(bridge)`.
3. The `unityforge_mod!` macro stores the bridge, calls `on_init`.
4. `on_init` registers generic ops, selectors, and game-specific hooks.
5. The shim's MonoBehaviour.Update calls `unityforge_tick` each frame.

The JSON data files in StreamingAssets are a large modding surface
that does not require Harmony patches. Intercepting the JSON load
or replacing files directly can add/modify items, recipes, NPCs,
and schedules.

For deeper changes (game mechanics, player stats, survival systems,
addiction, economy), Harmony patches against Assembly-CSharp.dll are
needed. The assembly is Mono, so all methods are patchable.

## 9. Decompiled class map (from Assembly-CSharp.dll via ilspycmd)

### 9.1 PlayerStats (singleton, GUID "PlayerStats")

Central hub for all player state. All sub-systems are fields on
this singleton, accessed via `PlayerStats.instance`.

| Field | Type | What it holds |
|---|---|---|
| health | PlayerStatsHealth | HP (0..100), bleeding, regen rate |
| hungerAndThirst | PlayerStatsHungerAndThirst | hunger, thirst, bowel, bladder |
| mentalHealth | PlayerStatsMentalHealth | depression (0..100), expectation level |
| tiredness | PlayerStatsTiredness | exhaustion (0..100), sleep debt |
| mushrooms | PlayerStatsMushrooms | mushroom high, SMV progression |
| addictions | PlayerStatsAddictions | alcohol, mushroom, smoking, gambling |
| alcohol | PlayerStatsAlcohol | blood alcohol |
| sauna | PlayerStatsSauna | sauna stat |
| duck | PlayerStatsDuck | duck stat |
| hygiene | PlayerStatsHygiene | cleanliness |
| radiation | PlayerStatsRadiation | radiation exposure |
| gambling | PlayerStatsGambling | gambling state |
| conditions | PlayerStatsDiseasesAndConditions | diseases and conditions |
| Skills | PlayerSkill[] | array of all player skills |
| Godmode | bool | disables damage and stat drain |
| Active | bool | whether stats tick |
| StatsProgressDisabled | bool | freezes stat progression |

### 9.2 Player skills (PlayerStats.PlayerSkillType)

Lockpicking, Drinking, Cooking, Mashing, Brewing, Distilling,
Farming, Malting, Manufacturing, Paperwork, Chemistry, Carpentry,
Machining, Engineering, Bribery, Cleaning, Sewing, Electronics,
Mining, Music, Smithing, Medical, Computers.

Each skill is a `PlayerSkill` with a float `Skill` field and an
int `Level` property (`Math.Floor(Skill)`).

### 9.3 Hunger and thirst (PlayerStatsHungerAndThirst)

| Field | Default | Unit |
|---|---|---|
| Hunger | 0 | 0..100, higher = more hungry |
| HungerRate | 10 | per in-game hour |
| Thirst | 0 | 0..100 |
| ThirstRate | 15 | per in-game hour |
| Bowel | 0 | 0..100, fills from eating |
| Bladder | 0 | 0..100, fills from drinking |
| ThristStarvationDamage | 25 | HP damage per hour at max thirst |
| SleepHungerThristRateFactor | 0.33 | multiplier while sleeping |

Rates are scaled by `DifficultyController.currentDifficultyInfo
.GetGeneralNeedsSpeed()`. Mushroom high and alcohol addiction both
reduce effective hunger rate.

### 9.4 Addictions (PlayerStatsAddictions)

Four addiction types, all with the same structure:

| Addiction | Need baserate | Addiction decay |
|---|---|---|
| Alcohol | 40/hr | -1.25/hr |
| Mushroom | 40/hr | -1.25/hr |
| Smoking | 40/hr | -1.25/hr |
| Gambling | 6/hr | -0.5/hr |

Each has an `Addiction` float (0..100) and a `Need` float (0..100).
Need grows based on addiction level. Withdrawal at high need deals
mental health damage (`WithdrawalsymptomMentalhealthLoss = 50`).
All rates scaled by difficulty.

### 9.5 Mental health (PlayerStatsMentalHealth)

`currentStatus` (0..100) drifts toward `mentalHealthTarget` at
`mentalHealthChangeRate` (0.5/hr). Effective mental health is
reduced by alcohol in blood and boosted by hygiene. Mushroom SMV
progression above 50 scales it down. `expectationLevel` (default
25) modulates how strongly bad conditions affect depression.
Can be disabled entirely by difficulty setting.

### 9.6 Health (PlayerStatsHealth)

`currentStatus` (0..100), `bleeding` (0..100),
`HealthRegenerationRate` (1/min). Damage sources identified:
hunger starvation, thirst starvation, bleeding.

### 9.7 Tiredness (PlayerStatsTiredness)

`currentStatus` (0..100), `Exhaustionrate` (6/hr), `RestRate` (10),
`SleepTimeSpeed` (150). At 100 tiredness, the game forces a
pass-out via `WaitingController.instance.PassOut()`. Sleep debt
accumulates when tiredness goes negative.

### 9.8 Difficulty system (DifficultyController + DifficultyInfo)

Singleton `DifficultyController.instance`. All stat rates go
through difficulty multipliers:

| Knob | Affects |
|---|---|
| generalNeedsSpeed | hunger rate, thirst rate |
| addictionNeedsSpeed | how fast addiction need grows |
| addictionRecoverySpeed | how fast addiction decays |
| smvProgressionRateSpeed | mushroom disease progression |
| renovationCost | building upgrade money cost |
| renovationResourceCosts | building upgrade material cost |
| renovationSpeed | how fast upgrades complete |
| rentIncome | rent from tenants |
| prices | shop prices |
| respawningTime | item respawn timer |
| traderWealth | how much money traders carry |
| mentalHealthDisabled | skip mental health entirely |
| userSavesDisabled | disable manual saves |
| mandatoryStartingAddictionsDisabled | skip forced addictions |

Multiplier values: 0.25x through 10x in steps, plus Disabled.
Supports Custom difficulty where all knobs are individually set.

### 9.9 Crafting (CraftingBase)

All crafting stations inherit from `CraftingBase`, which is an
`Interactable` requiring a `Storage` component. Key fields:
`EquipmentQuality` (affects batch success), `Recipes` (array of
RecipeType), `Modifiers` (conditions like power, water),
`SkillGainFactor`, power/fuel settings. Recipes reference items
by ID with input amounts and output definitions.

### 9.10 Trade system (Trade)

Traders are `Interactable` components with `Storage`. They have
money ranges (`traderMoneyAmountMin`/`Max`, defaults 5000/10000),
opening times (`autoOpenClose`), price mode (Real Money only or
Open Sewer Coins only), and spawn settings for restocking.

### 9.11 Serialization

The game uses FullSerializer (`fsProperty`, `fsIgnore`,
`fsCheckChildFields`) for save/load. `SaveController.SerializeData`
and `DeSerializeData` handle persistence. `SavableScript` is the
base class for MonoBehaviours that participate in saves.

### 9.12 Time system (TimeOfDayAzure)

Singleton `TimeOfDayAzure.instance`. Uses Azure Sky for day/night.

| Field | Default | What it does |
|---|---|---|
| dayLenghtInMinutes | 24 | real minutes per in-game day |
| timeSpeedOverrideFactor | 1 | multiplier on time speed |
| currentTimeAndDay | TimeAndDay | seconds, minutes, hours, weekDay, day, month, year, currentDay |
| timers | List\<Timer\> | in-game-time callbacks with remaining seconds |

`actualSpeed` = `dayLenghtInMinutes * (1 / timeSpeedOverrideFactor)`.
Fires `OnSecondsPassed` and `OnMinutePassed` delegates. All stat
systems subscribe to seconds ticks. `WaitForIngameSeconds` and
`WaitForIngameMinutes` are custom yield instructions for coroutines.

### 9.13 Item consumption (OS.Items.ItemConsumable)

Items with consumable actions carry these float fields, applied
on use:

| Field | Target stat |
|---|---|
| Food | reduces hunger |
| Drink | reduces thirst |
| Nicotine | smoking addiction |
| Intoxication | alcohol |
| SMV | mushroom high |
| SMVProgressionRate | mushroom disease progression |
| Depression | mental health target |
| Health | HP change |
| Bleeding | bleeding reduction |
| High | mushroom high (green) |
| HighOrange | mushroom high (orange normal) |
| HighOrangeBad | mushroom high (orange bad) |
| Tiredness | tiredness change |
| Hygiene | cleanliness |
| AlcoholAddiction | alcohol addiction level |
| MushroomAddiction | mushroom addiction level |
| SmokingAddiction | smoking addiction level |

ConsumableType: Food, Drink, Smoke, Medicine, Bandage, Container,
Slaughter, Hygiene. Special effects: Coffee (reduces tiredness),
SleepingPills, Laxative, Radiation.

### 9.14 Item data model (OS.Items namespace)

Items are composed via ItemAction subclasses attached to the base
Item. The OS.Items namespace holds all data components:

| Class | Purpose |
|---|---|
| ItemConsumable | food/drink/medicine stats (section 9.13) |
| ItemPerishabledata | spoilage, age, freshness |
| ItemLiquidData | liquid contents |
| ItemFueldata | fuel value |
| ItemGrowdata | plant growth stages |
| ItemEquipable | wearable equipment |
| ItemReadable | books, notes |
| ItemWritable / ItemWritableData | writable text |
| ItemStolenData | stolen flag, original owner |
| ItemQualityData | quality level |
| ItemFurnitureData | furniture placement data |
| ItemSkinData | appearance variants |
| ItemShopData | shop sale data |
| ItemGroupData | batch/group crafting values |
| ItemAnimalData | animal-related item data |
| ItemElectronic | electronic device data |
| ItemReloadable | ammo/reload data |
| ItemTrapData | trap configuration |

### 9.15 Inventory (Inventory)

Singleton, 35 inventory slots plus 8 character slots (equipped).
Character slots: index 3 = head, 4 = face, 5 = backpack,
6 = right hand, 7 = left hand. Uses `SlotController` for each
slot. Starting items configurable. `ItemDatabase` is the static
item registry loaded from Items.json.

### 9.16 Data loading paths

| Data file | Loader class | Method | Encoding |
|---|---|---|---|
| Items.json | ItemDatabase | Awake() / OnEnable() / Reload() | UTF-8 |
| Recipes.json | RecipeDatabase | LoadDatabase() | UTF-16 (Encoding.Unicode) |
| Characters.json | (not traced yet) | | UTF-16 |
| NPCBehavior.json | (not traced yet) | | UTF-8 |

ItemDatabase reads `Application.dataPath + "/StreamingAssets/Items.json"`
using `File.ReadAllText`, deserializes with FullSerializer, loads
sprites and prefabs. Has a public `Reload()` method.

RecipeDatabase reads `Recipes.json` with `Encoding.Unicode`,
wraps in a `RecipesHeader` object. Also has `AddRecipe()`,
`RemoveRecipe()`, `EditRecipe()`, `Reload()`.

Both databases have public `Reload()` methods, so a mod can
modify the JSON and call Reload to hot-swap data.

### 9.17 Crime system (Crime)

Singleton. Crime types: Theft, Violence, Fraud, PrisonEscape,
Administrative, AnimalCruelty, Trespassing, Burglary, Harassment,
Vandalism. Each crime is a `CrimeRecord` with type, victim, and
amount. Fine multiplier = 1.5x. Prison costs 250 per hour.
Max prison time = 100 hours. Bribery is tracked.
`Act_Police` NPCs enforce crimes.

### 9.18 NPC system (NPC namespace)

**NPCController** is the central NPC MonoBehaviour.
**NPCStats** holds per-NPC stats: Health, SMV, Intoxication,
Hunger, Thirst, Bowel, Bladder, Depression, Aggressiveness,
Cowardice, PlayerDisposition (-100..100), MoneyOS, MoneyRM.
Each stat has ActivityTrigger arrays that fire NPC activities
when thresholds are hit.

**Schedule** drives NPC behavior via `Timetable` (list of
ScheduledAction) and `RandomActivities`. Subscribes to
`TimeOfDayAzure.CurrentTimeAndDay` delegate and checks against
`TotalMinutes`.

**NpcBehavior** handles player detection with reaction types:
None, Chase, Talk. Reactions have conditions (via DialogueVariable),
delays, cooldowns, and optional dialogue.

Activity types: Act_Follow, Act_Patrol, Act_Police, Act_Sleep,
Act_Stand, Act_Tenement, Act_Wander, Act_sit.

Pathfinding uses NodeNetwork / Node / Waypoint system with
inter-scene support (NodeChangeLevel, Waypoint_LevelChange).

### 9.19 Tenement management (TenementController)

Singleton. Manages the player's tenement building. Contains
`TenementGeneral` (building-wide state), list of
`TenementApartment` (individual units), upgrade progress tracking.
Uses `TenementContractor` for renovations, `TenementResident`
for tenants. Upgrade types cover electricity, water, bathroom,
heating, wall type, balcony, kitchen (all in `UpgradeType` enums).
`TenementResourceStorage` tracks building materials.

### 9.20 Storage system (Storage)

`Interactable` with NPC ownership, lock support, permissions
(PermissionToTake, PermissionToUse), power state, refrigeration
level (0..1 = fridge, >1 = freezer), and spawn settings for
restocking. Taking from a locked/owned storage without permission
triggers the crime system.

### 9.21 Banking (Bank)

Two currencies: OC (Open Sewer Coins, local) and RM (Real Money).
Exchange rates: OC to RM = 0.06, RM to OC = 9.8.
Banks track total supply, daily income/spending averages,
corruption, interest rate (1.5%), and lending confidence.

### 9.22 Lock and lockpicking (Lock)

Locks have difficulty (0..2): effortless = 0.1, easy = 0.2,
moderate = 0.3, challenging = 0.8, difficult = 1.9.
`Lockpickable` flag controls whether the player can attempt it.
`increaseLockDifficulty` makes re-locking harder after a pick.
Difficulty increase amount = 0.33.

### 9.23 Waiting/sleeping (WaitingController)

Handles all time-skip activities: Sleeping, Passout, Waiting,
Working, HavingFun, Reading, Playing, StaringWall, Arrest,
WatchingTV, Talking. Sleep events can interrupt (crazy neighbor).
Arrest chance during sleep = 10% if crimes pending. Has alarm
clock support.

### 9.24 Special item effects (ItemSpecialEffects)

Caffeine (reduces tiredness), Laxative (adds bowel), Methanol
(reduces SMV progression), PiggyBank (spawns money), SleepingPill
(adds tiredness), ScratchCard (gambling).

### 9.25 Save system (SaveController)

Multi-phase save/load: Primary, Secondary, Tertiary, Special,
DestructibleList phases. Save header stores: SaveName, LevelName,
NewlevelEntrypoint, CharacterName, Date, ApplicationVersion.
Each SavableScript has a GUID for serialization targeting.
Global data (crime, difficulty, player stats) saves separately
from per-scene data.

Files, in `persistentDataPath/Saves/<CharacterName>/<SaveName>/`:
`Info.tnmt`, `Globals.tnmt` (scripts saved with
`SerializeData(this, global: true)`), `<Level>.tnmt` per area
(`SerializeData(this)`), `Globals.dialogue` (the Dialogue System's
data). UTF-8 with a byte order mark (the game's reader drops it; its
parser rejects it). `CharacterName` and `SaveName` are private statics
(SaveController.cs:185-187). `SaveGame` copies the last save folder into
the new one first (469-472), so areas not visited keep their files.
An `ObjectDataHeader` holds a live object and is serialized at write
time; `SaveDataHeader(list, save, level, character, entrypoint)`.

`ExecuteSaveLoadFunctions(roots, phase, includeInactive)` calls the
phase on every SavableScript under the given top objects whose object
is on, unless `includeInactive` (1113-1131). Each SavableScript finds its
saved entry by `GUID` and takes it out of the list (`DeSerializeData`,
707-).

**A door, step by step** (`Changelevel.ChangeLevel`, Changelevel.cs:72-87,
then `SaveController.ChangeLevel` 270 and `ChangeLevelDelay` 344-359):

1. `PlayerWillChangeLevel` (270): InteractableChair and
   InteractableLadder stop sitting and climbing.
2. Fade to the loading screen, wait for it (347-355).
3. `SaveGame(GetOldestAutosave(), newLevel, entrypoint)` (356-357), into
   the older of Autosave and Autosave2, which sets `SaveName` to it:
   OnMapChanging on the active area's top objects and the
   kept-through-loads objects (446-447); new temp lists (449-450);
   `SavingStarted` (452); save phases Primary, Secondary, Tertiary
   (453-455); `DestructibleList.instance.OnSavingGameDestructibleList()`
   (456); kept-through-loads OnSavingGameSpecial (457); OnSavingGame,
   OnSavingGameLatePrimary (458-459); files written (460-476);
   OnSavingFile (477); `SavingDone` (478). `LevelName` is the active
   scene's name (438).
4. `LoadGameWithMigration(CharacterName, autosave)` (1205-): sets
   `CharacterName`, `SaveName` (1208-1209), `PlayerWillLoadGame`,
   `Loading = true`, reads `Globals.tnmt` and `<level>.tnmt` into
   `tempSavedata_Global` and `tempSavedata_Level`, then
   `LoadSaveGameDifferentScene` (618-666):
5. The scene loads in single mode (624-639): every object of the old
   area gets OnDisable then OnDestroy; the new area's objects Awake and
   OnEnable, Start on the next frame.
6. `LoadingStarted` (640); load phases Primary, Secondary, Tertiary
   (641-643); kept-through-loads OnLoadingGameSpecial (644);
   `DestructibleList.instance.OnLoadingGameDestructibleList()` (645);
   OnLoadingGameDestructibleListCheck including switched-off objects
   (646); next frame (647); OnLoadingGame, OnLoadingGameLatePrimary, the
   check again (648-650); OnMapChanged on the active area only when the
   area changed (651-654); player to the arrival point (655); dialogue
   data applied (656-659); temp lists cleared, `Loading = false`,
   `LoadingDone`, fade out (660-664).

Measured order in a normal load (frame numbers): the area's objects run
Start one frame before its saved data goes in (load phases); scripts that
need the data wait (Relay fires its start events 3 frames after Start,
Relay.cs:88-93). Times on one trip: save 0.58s, scene load 4.25s,
restore about 1.0s, fade back 0.6s; the bar fills at 1 per second
(LoadingScreen.cs:85), so even an instant load waits about 1s.

The menu loads a save with `StartCoroutine(LoadGameWithMigration(
folder, save, fromMenu: true))` on its LoadMenu (LoadMenu.cs:539);
`SaveController.Loading` is not on until the coroutine runs.

### 9.26 Weather (Weather)

ScriptableObject with weatherName, probability, duration range,
precipitation type (None, Snow, Rain), particle systems.
WeatherManager controls transitions.

### 9.27 Dialogue (PixelCrushers.DialogueSystem)

Uses the third-party Dialogue System for Unity. DialogueController
manages active conversations. DialogueVariable stores persistent
state checked by NPC reactions and quest conditions.

### 9.28 Assembly class count

1148 decompiled classes total across the global namespace, OS.Items
(37 classes), and NPC (41 classes).

### 9.29 Areas: what each area's scene holds

Every area is one scene. Each carries its own copy of the player setup,
so a normal load replaces all of it (a trip measured: Inventory,
PlayerStats, TimeOfDayAzure, Crime, Money, GameUIController,
InteractObjects and the camera all new objects; SaveController and
LoadingScreen kept). Top objects of an area: `Game_Logic`, `Player` (or
`Player And Camera`), `Pause Menu(Clone)`, `__MAIN`, the area's own
content (named per area), `___Screenshot Taking Stuff` (screenshot
cameras, on in outdoor areas), and objects the game keeps off itself
(`Test`, `_LIGHT_BLOCKERS` in the player's building).

`Game_Logic` has 9 children (Open Sewer Tenement, research_game_logic.rs):

| Child | Holds |
|---|---|
| Controllers | GameController, GameUIController, NPCManager (`NPC/NPCManager`), WaitingController (with `SleepEventController` under it), TenementController, LightsController, TaskController, the panels' controllers, ... |
| Other | DestructibleList (object `LoadSavegame`), PlayerLevelEntrypoints, Crime, PlayerIdentity, RelationshipController, RecipeDatabase, MailController, ... |
| Globals | TimeOfDayAzure, WeatherManager, WindowNaturalLight, GlobalState (the sky) |
| Game UI | Inventory, Money, every UI panel, BlackCanvas, WhiteCanvas, ItemDatabase |
| Effects | SMVEffects and the screen effects |
| Backpack Storage, Dialogue Manager, Mouse blocker | as named |

`__MAIN` holds `info_game_logic`, `info_map`, SoundscapeGlobal, AstarPath
and RVOSimulator (NPC pathfinding).

Kept through scene changes (DontDestroyOnLoad): SaveController,
LoadingScreen (its Awake destroys any second copy, LoadingScreen.cs:83),
InputManager, SteamManager, Achievements, NPCDirector,
InterScenePathfindingGraph, NPCPathfinding, WaypointGraph,
LoadOnLevelIni, ReadSceneNames, the settings savers.

### 9.30 Managers (one copy)

A manager is a class whose Awake (or OnEnable) sets a public static of
its own type to itself: `instance = this` (GameController,
TimeOfDayAzure also in Start, PauseMenu, ThirdPersonCameraController),
`identity` (PlayerIdentity), `active` (AstarPath field, RVOSimulator
property). 199 classes in Assembly-CSharp. A static of its own type that
nothing sets on waking is a "current" pointer, not a manager:
`Storage.active` / `currentStorage` (the box open), `LiquidStorage`,
`VendingMachine.active`, `ItemData.currentHoverItemData`,
`InteractableTalk.CurrentInteractableTalk`,
`CraftingBase.currentCraftingBase`, `Toilet.currentToilet`.

`info_game_logic` (`__MAIN/info_game_logic`) owns its area's player
setup: Awake and OnEnable destroy their own object when `instance` is
another copy (info_game_logic.cs:73-95); OnDestroy destroys `Main`, the
setup (177-183). Its Start applies the area's settings: sky (`DelaySet`),
`RadiationController` background radiation (97-115). It holds the
prison area (`prisonLevelName`, read by Crime.TeleportToPrison) and
`baseSafetyFactor` (read by SleepEventController.cs:68).

`info_game_logic` values per area (research_area_settings.rs, 2026-10-03):

| Area | overrideSky / profile | disableOverrideSkyOnPlay | backgroundRadiation | prisonLevelName |
|---|---|---|---|---|
| Open Sewer Tenement | false / Obenseuer Default (sky on) | false | 0.0004 | Interior Tenement Gatehouse |
| Open Sewer Bazaar | false / none (sky on) | false | 0.0004 | Interior Bazaar Police and Jail |
| Interior Tenement Gatehouse | true / none (no sky) | false | 0.0004 | Interior Tenement Gatehouse |
| Interior Tenement B | true / Obenseuer No Sky Deekula | true (Start leaves the sky as it is) | 0.0004 | Interior Tenement Gatehouse |
| Under Map | true / Obenseuer Under Map | false | 89.0 (wasteland 89.0) | Interior Tenement Gatehouse |

All five: baseSafetyFactor 0, itemExpirationTimeMinutes 600, hideMainMap
false, _3dSkybox false, backgroundRadiationWasteland 25 (Under Map 89).

Per-area managers (their data is the area's): PlayerLevelEntrypoints,
DestructibleList, SleepEventController (saved in the area's file),
NPCManager, `info_map`, `info_water_source`. Each sits alone on its own
object with no children (research_area_owned.rs).

### 9.31 Arrival points (PlayerLevelEntrypoints)

Each area's `PlayerLevelEntrypoints` holds a list of `Entrypoint`
(Name, Location transform, OtherEntyPoint), built in the editor from
every `Entrypoint` field in the scene (PlayerLevelEntrypoints.cs:121-151;
Awake sets `instance`, 60-63). Every door's Awake also inserts its own
entry into the current `instance`'s list (`Changelevel.cs:44-50`); a
door re-created during play inserts a fresh one. Readers:
SaveController.MovePlayerToEntrypoint (688-697), Teleport.cs:93,
Prison.cs:127. A door: `OtherLevel` (area), `OtherEntrypoint` (arrival
name), `ThisEntrypoint`; `DoorChangelevel.OpenDoor` disables the
controls before ChangeLevel (DoorChangelevel.cs:206).

### 9.32 DestructibleList

GUID "DestructibleList", saved in the area's file (DestructibleList.cs:
11-25): `DestroyedGuids` (map items destroyed) and `prefabs` (items
dropped, re-spawned on load from `Resources`, parented 2 frames later,
68-86). Its Awake resets `Collectible.allCollectibles` (91). Called
directly by SaveGame (456) and the load (645).

### 9.33 NPCManager.ActiveScene

A name cached in Start (`activeScene = GetActiveScene()`,
NPCManager.cs:60; empty until then, when it reads the active scene
live). Read by 20 NPC code paths to tell which NPCs are in the player's
area: spawning (info_NPCSpawn, NPCSpawnUtilities), schedules
(Schedule.cs:140), the NPC director (NPCDirector.cs:108-277), scene
utilities, pathfinding between areas (InterScenePathfindingGraph.cs:98,
NPCController.cs:420). `levelChangeWaypoints` holds the area's waypoints
to other areas.

### 9.34 Game-wide events and their listeners

| Event | Listeners |
|---|---|
| SaveController.PlayerWillChangeLevel | InteractableChair (subscribes in Awake, unsubscribes in OnDestroy), InteractableLadder |
| SaveController.PlayerWillLoadGame | Act_Police, Act_Robber |
| SaveController.SavingStarted / SavingDone | FadeGameObjectController (ShowAll so hidden objects are saved), SMVHierarchy (subscribes in OnEnable) |
| SaveController.LoadingStarted | none found |
| SaveController.LoadingDone | BlackoutController, ItemAchievementList, NaturalLightSourceChecker |
| OnMapChanging phase | NPCDirector (every NPC's state, NPCDirector.cs:91-104), AnimalController, BuildingSystem, Teleport |
| OnMapChanged phase | NPCDirector, AnimalController, Collectible, Spawner, RelayTimer, RelayOnDayChange, TenementEventController |
| TimeOfDayAzure time events | `SecondsPassed`: Spawner (subscribes in Start's coroutine, Spawner.cs:175; unsubscribes only in OnDestroy, 388). Also called from TimeOfDayAzure's time update (seen in stacks, subscriptions not read): Trade.DeltaSeconds, VendingMachine.MinutePassed, RelayWeekdays.Check, Clock.CurrentTime |
| Unity sceneLoaded | LoadOnLevelIni (only after a load from the menu, leaves after the first area), SalsaConfigGuard (every load, again 1s later: checks every Salsa, Emoter, Eyes in every loaded scene, inactive too) |

### 9.35 Lifecycle patterns that matter when objects outlive their area

- Lists of all copies kept in OnEnable/OnDisable (AlarmClock,
  ToiletPaperHolder, AlarmClock.cs:15-41): a switched-off copy leaves the
  list. Every OnEnable subscription in the game (17) is undone in the
  class's OnDisable.
- Awake subscribes, OnDestroy unsubscribes: InteractableChair
  (InteractableChair.cs:181, 228-235).
- Start sets what OnDestroy or OnDisable uses: LavaLamp (Start clones
  its material; OnDestroy destroys `material`, the shared asset if Start
  never ran), MoneyPanel (OnDisable reads text lists only Start fills),
  NPCController, cakeslice.OutlineEffect, Cull_light, LightController,
  InteractableCashRegister, OnNPCStateChange.
- Start subscribes, OnDestroy unsubscribes (Spawner, RelayWeekdays,
  VendingMachine, Clock, Trade): a destroyed one whose OnDestroy did not
  run stays subscribed and throws every tick.
- Intros run from Start: `StartOpenSewer.Start` (StartOpenSewer.cs:50-87)
  in "Interior Start" disables controls and sets
  `BlackCanvas.instance.canvasGroup.alpha = 1` unless the save says the
  intro ran.
- Shared static array: SlotMachineGameplay's Awake replaces
  `_runResults` (148) for every machine.
- Whole-game searches (FindObjectOfType, FindObjectsOfType,
  GameObject.Find, Camera.main) skip switched-off objects.
- The game's own errors: LightController.Awake NullReferenceException on
  a LightController with no Light (`cullLight.intensity`), logged when
  such an area loads; DifficultyUI.OnEnable and
  ItemAchievementList.Start NullReferenceExceptions at start.

### 9.36 What area objects do in Start, and undo only in OnDestroy

The game's 28 public static events include SaveController's six
(PlayerWillChangeLevel, PlayerWillLoadGame, SavingStarted, SavingDone,
LoadingStarted, LoadingDone, SaveController.cs:221-231), TimeOfDayAzure's
SecondsPassed, MinutePassed, DayChanged (313-317), WeatherManager's
WeatherUpdated, WeatherTransitioning (74-76), WindowNaturalLight's
SourcesChanged (34).

Area objects whose Start writes to or calls a manager (scan of every
Start for `X.instance.` writes and calls, 31 classes):

- Pushes the area's settings into the live managers: `info_game_logic`
  (sky, radiation), `SoundscapeGlobal` (playAtStart: plays the area's
  sound; subscribes `TimeOfDayAzure.MinutePassed` and every minute sets
  the global soundscape to its own day or night sound,
  SoundscapeGlobal.cs, unsubscribes only in OnDestroy, 65-68),
  `SoundscapeArea` (playAtStart; adds itself to
  `SoundscapeController.soundscapeAreas`), `StartOpenSewer` (the intro).
- Registers in a manager's list in Start, removes only in OnDestroy:
  CullingController (Cull_light, LightController), WindowNaturalLight
  (LightController: it only sets each light's colour from the weather,
  WindowNaturalLight.cs:178-209), TrainController (TrackTrain,
  Track_Segment), JanitorController (RelayJanitor, StorageJanitorAction,
  keyed by level name), SMVEffects (WastelandMaterial), NPCManager
  (Waypoint_LevelChange).
- Registers and never removes: ShopController (one reference, the last
  FurnitureShopUI/TrainShopUI; each exists in one area), TradePanel
  (`marketShops`, found by owner id, TradePanel.cs:44-60),
  Money (`moneyPanels`; panels skip themselves when switched off,
  MoneyPanel.cs:102), BuildingAreaWalls, TenementController (apartment
  and general prefabs, resource storages), TenementEventController,
  ToolTip, SMVEffects (SMVHierarchy), NPCManager (NPCInfo).

### 9.38 Coroutines, manager instance events, NPC objects (what assumes one area)

- Unity stops a switched-off object's coroutines and does not restart
  them when it is switched on; Start does not run again. Coroutines
  started in Start that run for good: BottleRecyclingLights.Blinking,
  BottleRecyclingLightsUI.Blinking (`while (true)`), PulseLight.LightEffect,
  randomAnimation.randomAnims (until switched off),
  RagdollAnimation.StepTimer (restarts itself). Most others wait for
  `TimeOfDayAzure.instance.updateTimeDisabled` to clear, then initialize
  once (Storage, Spawner, Growing, VendingMachine, LiquidStorage, Bank,
  NPCManager, NPCDirector, PlayerStats, ...): cut short if the object is
  switched off before that.
- Events on a manager's instance, subscribed by area objects:
  StrictArea subscribes to `Inventory.instance.ItemConsumed` and
  `PlayerStats.instance.PlayerDefecatedInPublic` while the player is in
  it (OnTriggerStay) and unsubscribes on OnTriggerExit or OnDestroy
  (StrictArea.cs); its handlers commit an Administrative crime when
  smoking, alcohol, mushrooms or defecation is witnessed. Unity sends no
  trigger exit when the object is switched off. Others: FadeGameObject
  (FadeGameObjectController.UpdateFade), InteractableListItem (undone in
  OnDisable), InventoryNavigationHandler (panel PowerOnOffEvent),
  ItemAchievementList (Inventory.ItemConsumed), DefaultUIButton
  (InputManager.InputTypeChanged).
- NPCs: `NPCDirector` (kept through loads) holds every NPC's data
  (`globalDatabase`); an NPC in the player's area has an object
  (`NPCData.Controller`), the rest are simulated as data
  (NPCDirector.DeltaSeconds, NPCDirector.cs:245-290: an NPC whose
  `state.currentScene` is not `NPCManager.ActiveScene` moves along its
  path or schedule, NPCSceneUtilities.HandleNPCChangeScene). On a save,
  `NPCData.OnSavingGame` (NPCData.cs:113-121) writes, for every NPC that
  has an object, `currentScene = NPCManager.instance.ActiveScene` and the
  object's position. The game assumes only the current area's NPCs have
  objects; OnMapChanging only records a follow target
  (NPCDataState.OnMapChange).

### 9.37 Pathfinding (AstarPathfindingProject.dll)

`AstarPath.active` (field) and `Pathfinding.RVO.RVOSimulator.active`
(property, set in Awake and OnEnable, nulled in OnDestroy;
RVOSimulator.cs:30-74). `RVOController.OnEnable` takes the simulator
from `RVOSimulator.active` and adds its agent; with none it logs "No
RVOSimulator component found" and disables itself, whose OnDisable then
removes an agent never added ("The agent is not added to this
simulation", RVOController.cs:270-301).