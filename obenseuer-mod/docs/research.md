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
