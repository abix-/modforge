# graveyardkeeper2-mod research

Game: Graveyard Keeper 2 Demo
Developer: Lazy Bear Games
Engine: Unity 6000.3.9f1 (Mono)
Steam path: `C:\Games\Steam\steamapps\common\Graveyard Keeper 2 Demo`

## Notable assemblies

- `Assembly-CSharp.dll`: game logic
- `Assembly-CSharp-firstpass.dll`: first-pass scripts
- `LazyBearTechnology.dll`: shared Lazy Bear engine/framework code
- `AstarPathfindingProject.dll`: A* Pathfinding Project (navigation)
- `NodeCanvas.dll` / `FlowCanvas.dll` / `ParadoxNotion.dll`: behavior trees and visual scripting (AI)
- `Rewired_Core.dll` / `Rewired_Windows.dll`: input
- `DOTween.dll` / `DOTweenPro.dll`: tweening/animation
- `Sirenix.OdinInspector.Attributes.dll` / `Sirenix.Serialization.dll`: Odin serializer
- `GalaxyCSharp.dll`: GOG Galaxy SDK
- `Clipper2Lib.dll`: polygon clipping (likely used for terrain or UI)

## Mod setup

- BepInEx 6.0.0-pre.2 (Unity.Mono win-x64)
- C# shim built with `-p:BepInExVersion=6`
- Control plane on port 17178
- Restart script: `graveyardkeeper2-mod/scripts/restart.ps1`
- Steam App ID: 5075680

## Key classes

### MainGame (singleton MonoBehaviour)

The central hub. Holds references to every major system.
Game state is exposed via `gameState` property (observed: `InGame`).

Fields:

| Field | Type | Notes |
|---|---|---|
| playerController | PlayerController | on GameObject "PlayerPhysicalBody" |
| craftSystem | CraftSystem | crafting |
| fightingLevelSystem | FightingLevelSystem | combat levelling |
| perkSystem | PerkSystem | perks/skills |
| questSystem | QuestSystem | quests |
| zombieSystem | ZombieSystem | zombie workers |
| zombiePorterSystem | ZombiePorterSystem | zombie porters |
| conveyorSystem | ConveyorSystem | conveyor belts |
| riverDropSystem | RiverDropSystem | river drops |
| npcLifeSimulator | NPCLifeSimulator | NPC daily schedules |
| movementSystem | MovementSystem | movement |
| dropSystem | DropSystem | item drops |
| gameLogicsSystem | GameLogicsSystem | game logic events |
| wgoCustomDeathSystem | WgoCustomDeathSystem | custom death handling |
| wgoDelayedEventsSystem | WgoDelayedEventsSystem | delayed event queue |
| wgoDelayedSpawnSystem | WgoDelayedSpawnSystem | delayed spawning |
| graphHelper | GraphHelper | A* pathfinding, on "AStar" |
| gameSave | GameSave | save system |
| saveSlotData | SaveSlotData | current save slot |
| guiElements | GUIElements | UI root |
| updateManager | UpdateManager | tick scheduling |
| gameSceneConfigs | List | scene configs |
| startingNewGame | bool | false when in existing save |
| continueGame | bool | false |
| gameSceneLoadProgress | float | 1.0 when fully loaded |
| conveyorPresetLoadOnNewGame | string | "ev_3_defence_workshop" |

### FlowScriptController (AI/scripting)

NodeCanvas FlowScript controllers drive NPC behavior and world interactions.
Observed instances (from walk_class):

NPCs: npc_donkey, npc_city_guard_* (multiple), npc_village_guard_01/02,
npc_city_guard_03/02, npc_head_of_the_guards, npc_scout, npc_larry,
npc_prapor, npc_town_barracks_mercenary_1, npc_looter_05,
npc_goddess_statue

World: battle_camp_town_1/3/4, battle_camp_sewer_1, bathhouse_bench,
basement_resurrection_door, goddess_tears_spawner

Teleports: teleport_milestone_1_town through teleport_milestone_14_bathhouse
(town, port_area, well, graveyard, village, home, career,
warehouse, swamp, flooded_quarter, sluice_area, bathhouse)

### PlayerController

On "PlayerPhysicalBody". The player character controller.

### GUIElements

On "UI". Root of the game's UI system.

### GraphHelper

On "AStar". Wraps the A* Pathfinding Project for game navigation.

## Energy, stamina, HP

Energy and stamina are stored as GameRes atoms on `PlayerData.res` (a
`LazyBearTechnology.GameRes` containing 67 `GameResAtom` entries). Each
atom is a `{type: string, value: float}` pair.

### Energy (index 5)

- Resource key: `energy`
- Observed value: 80.0 (out of unknown max)
- Managed by `PlayerData.energySystem` (EnergySystem)
- EnergySystem tracks `timeWithoutSleep` (float, time awake in game days)
- Sleep restores energy via `RestoreEnergyWhileSleeping(dt)`
- `TrackTimeWithoutSleep(dt)` increments the fatigue counter
- At some threshold `ActivateLackOfSleep()` fires (debuff)
- `DeactivateLackOfSleep()` clears it (after sleeping)
- `StartSleeping` takes 6 params, `StopSleeping` takes 0
- Sleep is gated by `IsSleeping` and `IsInTransitionBetweenSleep` flags
- EnergySystem also reads PerkSystemData (perks modify energy costs/regen)

Energy is spent by performing work actions (crafting, digging, chopping).
The cost comes from the action, not from EnergySystem directly. EnergySystem
only handles sleep and the fatigue penalty.

### Stamina (index 60)

- Resource key: `stamina`
- Observed value: 100.0
- Managed by `PlayerData.staminaSystem` (StaminaSystem)
- Used for combat attacks (`CanPerformAttack`, `ConsumeStamina`)
- Regenerates passively: 40.0/sec normal, 70.0/sec in stance
- Regeneration has a 0.65 sec delay after last consumption
- `OnNotEnoughStamina` event fires when attack is blocked

### HP (on PlayerData.hpComponent)

- `hp: 100`, `maxHpValue: 100`
- `IsImmuneToDamage: false`
- `HasFullHp: true` (computed property)
- Events: `OnHpChanged`, `OnFirstDamageDealt`, `OnFullHpRestored`
- Delayed death support (`isDeathDelayed`, `onDelayedDeadAction`)

### Other notable resources

| Key | Value | Notes |
|---|---|---|
| money | 100.0 | coins |
| insanity | 11.1 | sanity/madness meter |
| happiness | 9.0 | town happiness |
| tech_red | 0.0 | red tech points |
| tech_green | 5.0 | green tech points |
| tech_blue | 1.0 | blue tech points |
| global_ppl | 4.0 | parishioners for sermons |
| sermon_ready | 10.0 | sermon readiness |
| bodies_tier | 0.0 | body quality tier |
| cur_bodies_count | 0.0 | current bodies in graveyard |
| battle_ready | 1.0 | combat availability flag |
| milestones_activated | 1.0 | teleport milestones |
| donkey_body_drop_chance | 100.0 | donkey delivery chance |

### World zone scores (wz_*)

Negative values appear to be decoration/quality debt in each zone.
Observed: wz_yard = -116, wz_garden = -74, wz_church = -33,
wz_vineyard_basement = -34, wz_basement_writing = -20,
wz_alchemy_lab = -20, wz_carrier = -13, wz_mine = -10,
wz_workshop_conveyor = -10, wz_vineyard = -7, wz_graveyard = -6.

### GameRes API (LazyBearTechnology.GameRes)

The resource bag supports: `Get(type, ?)`, `GetInt(type)`, `Set(type, val)`,
`Add(type, val)`, `Sub(type, val)`, `Multiply(type, val)`, `Has(type)`,
`IsEnough(cost)`, `Clone()`, arithmetic operators (+, -, *, /), and
comparison operators.

## Tech tree (KnowledgeSystem)

On `GameSave.knowledgeSystem`. Tracks all technology unlock state.

Three lists control what the player sees on the tech tree:

| List | Count | Role |
|---|---|---|
| unlockedTechs | 25 | researched and available |
| hiddenTechs | 37 | shown as "?" until prerequisites are met |
| revealedTechs | 0 | prerequisites met, not yet purchased |

Flow: hidden -> revealed (prerequisite met) -> unlocked (tech points spent).

The "?" entries on the tech tree are real techs, not placeholders.

### Unlocked techs (observed)

wood_basic, work_with_wood_1, chooping, stone_basic, tool_rack,
autopsy_1, autopsy_soft, autopsy_skin_bones, autopsy_skull_teeth,
body_places_1, grave_top_wd_0, grave_buildings_wood_1, modules_grave_1,
garden_bed, graden_trees, bronze_works, bronze_ingot_scrap,
pottery_basic, fishing_1, millstone_and_flour, bread_and_pie,
fertilizer_1, garden_improve_1, bronze_details, bronze_ingots

### Hidden techs (the "?" items)

tech_town_building_1, zombie_wood, zombie_stone, zombie_marble,
zombie_wood_2, tech_zombie_digging, zombie_mining, garden_improve_2,
fishing_3, kitchen_table_2, kitchen_oven_2, alchemy_battle_potions_1,
autopsy_resurection, quest_paint, lacquer, dynamite, resurrection_liquid,
cooking_wild, cooking_fire, cooking_pastries, cooking_vegetables,
cooking_carrot, cooking_beet, cooking_cabbage, cooking_onion,
cooking_pumpkin, cooking_meat, cooking_meat_minced, cooking_fish_river,
cooking_fish_sea, cooking_fish_myst, cooking_soldier,
cooking_fish_leg_kraken, cooking_fish_leg_carp, cooking_fish_leg_salmon,
cooking_fish_leg_catfish, cooking_chocolate

### Other KnowledgeSystem lists

| List | Notes |
|---|---|
| unlockedCrafts | recipes the player can use |
| unlockedBuildings / lockedBuildings | placeable structures |
| unlockedTownBuildings / lockedTownBuildings | town structures |
| unlockedPhrases / blackListPhrases | dialogue phrases |
| hiddenTalentLevelUps / revealedTalentLevelUps / unknownTalentLevelUps | talent tree visibility |
| unlockedTalentIds | talent unlocks |
| hiddenInspirations | hidden inspiration nodes |
| lockedTechTabs / lockedCharacterWindowTabs | UI tab visibility |
| unlockedTutorials / viewedTutorials | tutorial tracking |
| hiddenAlchemyFormulas / unlockedAlchemyFormulas | alchemy recipes |
| knownMixCrafts | discovered mix recipes |
| oneTimeCompletedCrafts / blackListCrafts | craft completion tracking |
| unlockedOrgans | autopsy organ unlocks |
| knownMapZones / visitedWorldZones | map discovery |
| activeMapFightIcons | combat encounter markers |
| unlockedVendorsForOrders | vendor order availability |
| freeZombieNames | available zombie names |

### TalentSystemData (on GameSave.talentSystemData)

5 talent colors, each a TalentData entry:

| ID | Notes |
|---|---|
| talent_orange | curExp=0, curTalentLevel=1 |
| talent_red | curExp=0, curTalentLevel=1 |
| talent_green | curExp=0, curTalentLevel=1 |
| talent_yellow | curExp=0, curTalentLevel=1 |
| talent_blue | curExp=0, curTalentLevel=1 |

Each talent tracks: curExp, curTalentLevel, talentExpPoints,
studiedLevelUps, inspirationsProgression, activeInspirations.

## Farming (garden system)

Farming runs entirely through the craft system. There is no separate garden
system. Garden beds are WGOs (world game objects) that cycle through states
via craft replacements.

### Flow

1. Start with a `garden_empty` WGO (an empty garden bed).
2. **Planting craft** (e.g. `garden_carrot_planting`): consumes a seed item
   (e.g. `carrot_seed`), replaces the WGO with a crop-specific one
   (e.g. `garden_carrot`). Planting is manual and marked as a "star craft"
   (quality-sensitive).
3. **Growing craft** (e.g. `garden_carrot_growing`): runs automatically
   (`isAuto: true`, `isHidden: true`) on the crop WGO. When complete,
   replaces it with a ready WGO (e.g. `garden_carrot_ready`).
4. **Harvest** the ready WGO to collect the crop and return to `garden_empty`.

Both planting and growing crafts set `transferDataOnReplace: true`, so
quality and other data carry through the WGO replacements.

### Crops

27 garden crafts in GameBalance.gardenCraftsPerItemCache, covering these
crops:

| Crop | Tiers | Seed | WGO chain |
|---|---|---|---|
| wheat | 1 | wheat_seed | garden_empty -> garden_wheat -> garden_wheat_ready |
| carrot | 1 | carrot_seed | garden_empty -> garden_carrot -> garden_carrot_ready |
| linum (flax) | 1 | linum_seed | garden_empty -> garden_linum -> garden_linum_ready |
| beet | 1 | beet_seed | garden_empty -> garden_beet -> garden_beet_ready |
| cabbage | 3 | cabbage_seed | garden_empty -> garden_cabbage -> garden_cabbage_ready |
| onion | 3 | onion_seed | garden_empty -> garden_onion -> garden_onion_ready |
| pumpkin | 3 | pumpkin_seed | garden_empty -> garden_pumpkin -> garden_pumpkin_ready |
| hop | 1 | hop_seed | garden_empty -> garden_hop -> garden_hop_ready |
| grape | 3 | grape_seed | garden_empty -> garden_grape -> garden_grape_ready |

Tiered crops (cabbage, onion, pumpkin, grape) have separate planting and
growing craft defs per tier (e.g. `garden_cabbage_planting_1/2/3`). The
tier likely corresponds to seed quality or an upgrade.

### Related crafts

- `seed_oil`, `seed_oil_wheat`, `seed_oil_beet`, etc.: press seeds into oil
- `well_garden_water_respawn`: garden water well refill
- `miracle_growing_elixir`, `grow_potion_scroll`: growth speed items
- Cooking recipes use harvested crops as ingredients

### GameBalance

All craft definitions live in `GameBalance.craftDefs` (825 total).
`GameBalance.gardenCraftsPerItemCache` maps seed ItemDef to its garden
CraftDef list (27 entries).

## Inventory

The player inventory is an `Item` object at
`MainGame.playerController.playerData.inventory.inventoryItem`.

| Field | Type | Vanilla | Notes |
|---|---|---|---|
| inventorySize | int | 20 | total slot count (5x4 grid) |
| inventoryFillSize | int | varies | slots currently occupied |
| inventory | List | varies | the actual item list |
| id | string | "inventory" | item id |

### Expanding inventory

Writing `inventorySize` to a larger value (e.g. 40) works at runtime.
The InventoryWidget dynamically creates cells from this field during
Redraw. The game's built-in UI already handles scrolling when the grid
exceeds the visible area. No ScrollRect patching or UI modification
needed.

Tested: setting `inventorySize` from 20 to 40 via `write_field` on
the live inventoryItem. Opening the inventory showed 40 slots with
the game handling the scroll automatically.

The field must be set after the save loads (the Item is part of save
data). Setting it at the main menu has no effect.

## Movement speed

Player movement speed is controlled by two values:

| Location | Field | Type | Vanilla | Notes |
|---|---|---|---|---|
| PlayerPhysicsConfig | speed | float | 50.0 | base speed (ScriptableObject) |
| PlayerPhysicalBody | SpeedMultiplier | float | 1.0 | runtime multiplier |

`SpeedMultiplier` is the clean way to adjust speed. Writing the backing
field `<SpeedMultiplier>k__BackingField` on the PlayerPhysicalBody works
at runtime with immediate effect.

Access chain: `MainGame.playerController.get_PhysicalBody()` (property
getter, not a field).

PlayerPhysicsConfig also has: jumpForce (333), attackDashForce (15),
attackDashDuration (0.2), attackDashCooldown (0.5).

## Tweaks op

The `tweaks` op reads and writes all player tweaks in one call:

    POST /op {"op":"tweaks","args":{}}
    -> {"inventory_size":40,"speed":1.5,"energy":100}

    POST /op {"op":"tweaks","args":{"speed":2.0}}
    -> {"inventory_size":40,"speed":2.0,"energy":100}

Accepts: `inventory_size` (int, min 20), `speed` (float, min 0.1),
`energy` (float). Omitted fields are left unchanged. No args reads all.

## Systems to research

- PlayerController: inventory, stats, position, interaction
- CraftSystem: recipes, stations, crafting flow
- FightingLevelSystem: combat stats, levelling
- PerkSystem: perk tree, unlocks
- QuestSystem: quest state, progression
- ZombieSystem: zombie worker management
- NPCLifeSimulator: NPC schedules, daily routines
- GameSave/SaveSlotData: save/load flow
