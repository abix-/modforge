# Areas

> **Authoritative on:** how the game is built from areas (one scene each):
> what each area's scene holds, managers (one copy) and per-area managers,
> info_game_logic, arrival points, game-wide events and their listeners,
> what area objects do in Awake, OnEnable, Start, OnDisable and OnDestroy,
> coroutines, and every way the game changes area. The mod's design for
> keeping areas loaded: [`kept-areas.md`](kept-areas.md).
>
> Index of every game system's doc: [`research.md`](research.md).

## What each area's scene holds

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

## Managers (one copy)

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

Per-area managers (their data is the area's): PlayerLevelEntrypoints,
DestructibleList ([`save.md`](save.md)), SleepEventController (saved in
the area's file), NPCManager, `info_map` ([`map.md`](map.md)),
`info_water_source`. Each sits alone on its own object with no children
(research_area_owned.rs).

## info_game_logic

`info_game_logic` (`__MAIN/info_game_logic`) owns its area's player
setup: Awake and OnEnable destroy their own object when `instance` is
another copy (info_game_logic.cs:73-95); OnDestroy destroys `Main`, the
setup (177-183). Its Start applies the area's settings: sky (`DelaySet`),
`RadiationController` background radiation (97-115). It holds the
prison area (`prisonLevelName`, read by Crime.TeleportToPrison) and
`baseSafetyFactor` (read by SleepEventController.cs:68).

Values per area (research_area_settings.rs, 2026-10-03):

| Area | overrideSky / profile | disableOverrideSkyOnPlay | backgroundRadiation | prisonLevelName |
|---|---|---|---|---|
| Open Sewer Tenement | false / Obenseuer Default (sky on) | false | 0.0004 | Interior Tenement Gatehouse |
| Open Sewer Bazaar | false / none (sky on) | false | 0.0004 | Interior Bazaar Police and Jail |
| Interior Tenement Gatehouse | true / none (no sky) | false | 0.0004 | Interior Tenement Gatehouse |
| Interior Tenement B | true / Obenseuer No Sky Deekula | true (Start leaves the sky as it is) | 0.0004 | Interior Tenement Gatehouse |
| Under Map | true / Obenseuer Under Map | false | 89.0 (wasteland 89.0) | Interior Tenement Gatehouse |

All five: baseSafetyFactor 0, itemExpirationTimeMinutes 600, hideMainMap
false, _3dSkybox false, backgroundRadiationWasteland 25 (Under Map 89).

## Arrival points (PlayerLevelEntrypoints)

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

## Area changes

The game's door, step by step: [`save.md`](save.md).

Area changes other than doors (2026-10-03, from the code): the mod's door
prefix is on `Changelevel.ChangeLevel` (kept_loaded.rs:61), the door
component, which calls `SaveController.ChangeLevel` (Changelevel.cs:86).
These call `SaveController.ChangeLevel` directly, so they take the game's
normal save and load, not the kept door:

- Going to prison: `Crime.TeleportToPrison` (Crime.cs:322-330) to
  `info_game_logic.prisonLevelName`.
- A sleep event: SleepEventController.cs:341 to "Interior Player
  Tenement".
- A blackout: BlackoutTrigger.cs:123.
- `ChangeScene.Change` (ChangeScene.cs:9-31): teleports when the scene is
  `NPCManager.ActiveScene`, else a normal load.
- The developer console (DeveloperConsoleRoutines.cs:33).

Fast travel: FastTravelController only opens its menu
(FastTravelController.cs:12-15); no code calls a level change from it, so
the move is set on the menu's buttons in the scene (not read yet; likely
ChangeScene.Change).

What the mod does on such a normal load (kept_loaded.rs): the game's save
before the load also writes the kept areas, from the postfix on SaveGame
(52-55, on_save_done). The scene load in single mode unloads every area,
kept ones included. The mod's tick sees a new GameController (126-135),
forgets every kept area (reset, 87-104), takes the area loaded as the one
whose data the game applied (136-142), and loads its door destinations
alongside again, nearest door first (143, 171-194). So such a change
shows the game's loading screen as in the game, and the kept areas load
again in the background after it.

## Game-wide events and their listeners

The game's 28 public static events include SaveController's six
(PlayerWillChangeLevel, PlayerWillLoadGame, SavingStarted, SavingDone,
LoadingStarted, LoadingDone, SaveController.cs:221-231), TimeOfDayAzure's
SecondsPassed, MinutePassed, DayChanged (313-317), WeatherManager's
WeatherUpdated, WeatherTransitioning (74-76), WindowNaturalLight's
SourcesChanged (34).

| Event | Listeners |
|---|---|
| SaveController.PlayerWillChangeLevel | InteractableChair (subscribes in Awake, unsubscribes in OnDestroy), InteractableLadder |
| SaveController.PlayerWillLoadGame | Act_Police, Act_Robber |
| SaveController.SavingStarted / SavingDone | FadeGameObjectController (ShowAll so hidden objects are saved), SMVHierarchy (subscribes in OnEnable) |
| SaveController.LoadingStarted | none found |
| SaveController.LoadingDone | BlackoutController, ItemAchievementList, NaturalLightSourceChecker |
| OnMapChanging phase | NPCDirector (every NPC's state, NPCDirector.cs:91-104), AnimalController, BuildingSystem, Teleport |
| OnMapChanged phase | NPCDirector, AnimalController, Collectible, Spawner, RelayTimer, RelayOnDayChange, TenementEventController |
| TimeOfDayAzure time events | `SecondsPassed`: Spawner (subscribes in Start's coroutine, Spawner.cs:175; unsubscribes only in OnDestroy, 388). Also called from TimeOfDayAzure's time update (seen in stacks, subscriptions not read): Trade.DeltaSeconds, VendingMachine.MinutePassed, RelayWeekdays.Check, Clock.CurrentTime. All clock listeners: [`time.md`](time.md) |
| Unity sceneLoaded | LoadOnLevelIni (only after a load from the menu, leaves after the first area), SalsaConfigGuard (every load, again 1s later: checks every Salsa, Emoter, Eyes in every loaded scene, inactive too) |

Events on a manager's instance, subscribed by area objects: StrictArea
(Inventory.ItemConsumed, PlayerStats.PlayerDefecatedInPublic; see
[`crime.md`](crime.md)), FadeGameObject
(FadeGameObjectController.UpdateFade), InteractableListItem (undone in
OnDisable), InventoryNavigationHandler (panel PowerOnOffEvent),
ItemAchievementList (Inventory.ItemConsumed), DefaultUIButton
(InputManager.InputTypeChanged).

## Lifecycle patterns that matter when objects outlive their area

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
- OnEnable side effects besides subscriptions: UI refreshes, wieldable
  items adding their animator to FirstPersonHands, EventCamera
  (disables controls and the player camera while on), AlarmClock and
  ToiletPaperHolder connecting to nearby beds and toilets.
- The game's own errors: LightController.Awake NullReferenceException on
  a LightController with no Light (`cullLight.intensity`), logged when
  such an area loads; DifficultyUI.OnEnable and
  ItemAchievementList.Start NullReferenceExceptions at start.

## What area objects do in Start, and undo only in OnDestroy

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
  (Waypoint_LevelChange), BuildingSystem (FurnitureManager,
  [`building.md`](building.md)).
- Registers and never removes: ShopController (one reference, the last
  FurnitureShopUI/TrainShopUI; each exists in one area), TradePanel
  (`marketShops`, found by owner id, TradePanel.cs:44-60),
  Money (`moneyPanels`; panels skip themselves when switched off,
  MoneyPanel.cs:102), BuildingAreaWalls, TenementController (apartment
  and general prefabs, resource storages), TenementEventController
  ([`tenement.md`](tenement.md)), ToolTip, SMVEffects (SMVHierarchy),
  NPCManager (NPCInfo).

## Coroutines

Unity stops a switched-off object's coroutines and does not restart them
when it is switched on; Start does not run again. Coroutines started in
Start that run for good: BottleRecyclingLights and
BottleRecyclingLightsUI (Start only starts `Blinking`, `while (true)`),
PulseLight (Start records the light's current intensity as its maximum,
then starts `LightEffect`), RagdollAnimation (Start looks up its bones,
starts `StepTimer`, which restarts itself), randomAnimation.randomAnims
(until switched off; restarts its loop in OnEnable); Storage restarts
`Initialize` in OnEnable. Most others wait for
`TimeOfDayAzure.instance.updateTimeDisabled` to clear, then initialize
once (Storage, Spawner, Growing, VendingMachine, LiquidStorage, Bank,
NPCManager, NPCDirector, PlayerStats, ...): cut short if the object is
switched off before that.
