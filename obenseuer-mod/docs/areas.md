# Areas

> **Authoritative on:** how the game is built from areas (one scene each):
> what each area's scene holds, managers (one copy) and per-area managers,
> info_game_logic, game-wide events and their listeners, what area
> objects do in Awake, OnEnable, Start, OnDisable and OnDestroy, and
> coroutines. Doors and moving between areas: [`doors.md`](doors.md). The
> mod's design for keeping areas loaded: [`kept-areas.md`](kept-areas.md).
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

`public class info_game_logic : MonoBehaviour`, `[ExecuteInEditMode]`
(info_game_logic.cs), at `__MAIN/info_game_logic`. The area's settings.
Not saved.

| Field | Default | Read by |
|---|---|---|
| `static info_game_logic instance` | | Many (5 files) |
| `bool overrideSky`, `AzureWeatherProfile overrideProfile`, `bool disableOverrideSkyOnPlay` | | Start's `DelaySet` ([`weather.md`](weather.md)); WeatherManager thunder |
| `bool _3dSkybox` | | |
| `bool hideMainMap` | | Map ([`map.md`](map.md)) |
| `string prisonLevelName`, `prisonEntrypoint` | "Interior Tenement Gatehouse", "prison" | `Crime.TeleportToPrison` |
| `float baseSafetyFactor` | 0 | SleepEventController.cs:68 |
| `int itemExpirationTimeMinutes` | 600 | |
| `float backgroundRadiation`, `backgroundRadiationWasteland` | 0.0004, 25 | Start -> `RadiationController` |
| `float timeline`, `int year`, `month`, `day`, `bool setTimeAtStart`, `float overrideTimeSpeed` | 9, 2026, 11, 16 | Start, editor only |
| `bool hideUI`, `ShowGameLogic` | | Editor |
| `GameObject Main` (private) | | The area's player setup |

| Method | Does |
|---|---|
| `Awake()`, `OnEnable()` (73-95) | `instance` null -> this; another live copy -> **destroys its own object** (and so, through OnDestroy, `Main`) |
| `Start()` (97-114) | `DelaySet` unless `disableOverrideSkyOnPlay`; `RadiationController.instance.backgroundRadiation` and `backgroundRadiationWasteland`; editor time settings |
| `DelaySet()` (116-127) | 0.1 s realtime: `overrideSky` -> `TimeOfDayAzure.DisableSky(overrideProfile)`, else `EnableSky()` |
| `OnDestroy()` (177-183) | `DestroyImmediate(Main)`: the area's player setup |

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

## Doors and arrival points

Each area has its own arrival points (PlayerLevelEntrypoints, a
per-area manager). Doors, arrival points and every other way the game
changes area: [`doors.md`](doors.md).

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

## Every area brings its own player and managers

Live game, `research_loading.rs`, one trip Open Sewer Tenement to
Interior Player Tenement (2026-10-02). Instance ids before and after the
trip; the same id means the object survived, a new id means it was
destroyed and built again.

```text
SaveController         KEPT         ids [852246] -> [852246]
LoadingScreen          KEPT         ids [852752] -> [852752]
Inventory              REBUILT      ids [6879408] -> [7119596]
BackpackStorage        REBUILT      ids [6879410] -> [7119598]
PlayerStats            REBUILT      ids [6874938] -> [7114958]
TimeOfDayAzure         REBUILT      ids [6839382] -> [7086676]
Crime                  REBUILT      ids [6871766] -> [7111538]
Money                  REBUILT      ids [6877460] -> [7117526]
DifficultyController   REBUILT      ids [6878464] -> [7118562]
WaitingController      REBUILT      ids [6872406] -> [7112096]
TenementController     REBUILT      ids [6839384] -> [7086678]
GameUIController       REBUILT      ids [6867236] -> [7106652]
Notifications          REBUILT      ids [6867052] -> [7106504]
InteractObjects        REBUILT      ids [6874246] -> [7114116]
main camera            REBUILT      ids [6655738] -> [6981904]
```

Code agrees: only a few objects call `DontDestroyOnLoad` (SaveController,
LoadingScreen, InputManager, SteamManager, Achievements, the NPC
pathfinding and NPCDirector, a few others). Inventory, PlayerStats,
TimeOfDayAzure and Crime set `instance = this` in Awake and are not kept
(Inventory.cs:189, PlayerStats.cs:171, TimeOfDayAzure.cs:354, Crime.cs:117).

The game already uses the keep-one-copy pattern for the loading screen:
`LoadingScreen.Awake` (LoadingScreen.cs:83) keeps itself through scene
changes and destroys any second copy.

## Links to managers

Text search of the decompiled code: how many files keep their own link
to a manager (a field of that type) against how many ask for the one copy
through `X.instance` each time.

| Manager | Files with their own link | Files using X.instance |
|---|---|---|
| Inventory | 3 | 88 |
| PlayerStats | 1 | 88 |
| TimeOfDayAzure | 2 | 81 |
| Money | 2 | 56 |
| Crime | 0 | 31 |
| BackpackStorage | 0 | 8 |
| GameUIController | 0 | 58 |
| WaitingController | 0 | 19 |

A search for fields declared as `public X name;` or
`[SerializeField] private X name;` on one line; links declared another
way would be missed. Not known: what each manager's own-link files are,
and whether the game sets those links in the level editor.

## One copy for the game, or one copy per area (2026-10-03)

Every area's scene carries its own managers; their Awake sets
`instance = this`. The game has one area at a time, so "the one copy" is
both the game's copy and the current area's copy. With areas kept loaded
those part, and the first-copy guard (first_copy_wins.rs) treats every
one-copy class as the game's: `instance` stays on the copy of the area the
save loaded into. For a class that belongs to an area, that is the wrong
copy in every other area:

- `PlayerLevelEntrypoints` holds its area's arrival points
  (PlayerLevelEntrypoints.cs:56-62, list built in the editor, 121-151).
- `DestructibleList` holds the items dropped in its area and the map items
  destroyed there, saved in the area's file (GUID "DestructibleList",
  DestructibleList.cs:11-25); with `instance` on another area's copy, drops
  in a kept area likely go into that area's list and file (not checked).

Where each one-copy class saves, from the decompiled source (a public
static field or property of its own type; `SerializeData(this, global:
true)` is the game's file, `SerializeData(this)` the area's):

| Saves | Count | Classes |
|---|---|---|
| Game's file | 41 | Inventory, PlayerStats, Money, Crime, TimeOfDayAzure, NPCDirector, PlayerIdentity, ... |
| Area's file | 3 | DestructibleList, SleepEventController, VendingMachine |
| Nothing | 171 | UI and player (PauseMenu, PlayerCamera, ...) and area (PlayerLevelEntrypoints, info_map, info_lighting_settings, WaterController, WaypointGraph, NodeNetwork, ...) mixed |

So where it saves does not sort the 171. Rule to measure next: a copy
under the top objects every area has for the player and managers
(Game_Logic, Player And Camera, Pause Menu(Clone), ...) is the game's; a
copy under the area's own top objects is the area's, and its `instance`
should follow the area the player is in, as the area's own Awake would
have set it on a normal load.

Which managers are area-owned (2026-10-03): of the game's 199 managers (a
class whose Awake or OnEnable sets its own static to `this`), 13 save
into the area's file or use the area's name. Read one by one:
JanitorController, SaveSceneManager, PlayerIdentity, WaterSourceController
read the active scene's name when they need it (right: the area entered
is the active scene); ReadSceneNames, LoadMenu, LoadOnLevelIni,
SaveController are kept through loads or menu only; Crime reads
info_game_logic. Area-owned: DestructibleList, SleepEventController (area
file), NPCManager (name cached in Start), and the per-area settings
`info_game_logic` (read in 5 files), `info_map` (4), `info_water_source`
(1), with PlayerLevelEntrypoints (the area's arrival points).

## Two areas loaded at once

`research_two_areas.rs` (2026-10-02): in Open Sewer Tenement, loaded
Interior Tenement Gatehouse alongside with
`SceneManager.LoadSceneAsync(area, Additive)` and kept both loaded. Full
output in `output/two-areas.txt` (local, [`testing.md`](testing.md)).

```text
memory before: allocated 2916 MB  reserved 3438 MB  managed 381 MB
loaded Interior Tenement Gatehouse alongside in 2.43s
memory after: allocated ?  reserved ?  managed 424 MB
  Inventory              copies 1 -> 1  [3223108] -> [3223108]  instance 3223108 -> 0 SWITCHED
  InteractObjects        copies 1 -> 2  [3217946] -> [3217946, 3339936]  instance 3217946 -> 3339936 SWITCHED
cameras 4 -> 9; main camera Some(2999438) -> Some(2999438)
doors: 57 in "Open Sewer Tenement", 6 new from Interior Tenement Gatehouse
"Open Sewer Tenement" doors span [-9.0, -500.0, -56.9] to [110.2, -84.8, 58.5]
Interior Tenement Gatehouse doors span [12.3, -108.7, -13.0] to [45.2, -97.4, 2.0]
```

- The interior loaded alongside in 2.43s; managed memory rose 381 MB to
  424 MB. The Unity memory readings after the load failed (`?`).
- The interior brought no second Inventory, PlayerStats, TimeOfDayAzure or
  other manager from the list: their copy counts stayed at 1. So on a door
  trip those are not rebuilt from the area scene itself; where they come
  from is not known yet.
- It brought a second `InteractObjects` (the looking-at and using code),
  and the game's `instance` switched to the new copy.
- It brought 5 cameras (4 -> 9); the main camera stayed the same.
- The "instance -> 0 SWITCHED" rows for the other 12 managers are likely
  failed reads, not switches: a live Unity object never has id 0 and
  their copy counts did not change. Not confirmed. (Later explained: see
  switching off after the load is not enough, in kept-areas.md.)
- The interior's doors lie inside the box around the outdoor area's
  doors. That box is coarse (it reaches y -500, likely the "Under Map"
  door), so whether the two areas really share space is not known.

What the player saw after the load:

- The HUD was gone.
- The player seemed to be in a different place than before.

Which of the interior's objects caused this is not known. Candidates: one
of its 5 cameras, its own interface objects, the switched
`InteractObjects`, or its arrival points (`PlayerLevelEntrypoints` sets
itself as the one copy in Awake, PlayerLevelEntrypoints.cs:62; no code
that moves the player on area start was found).

## What a second area brings that takes over

`research_area_takeover.rs` (2026-10-02), with the game's "run in
background" option on (the game answers while unfocused): in Interior
Player Tenement, loaded Interior Tenement Gatehouse alongside and compared
every Assembly-CSharp class with a static `instance` field (187 of 3182
types) plus Unity's cameras, canvases, audio listeners, event systems and
lights. Full output in `output/area-takeover.txt`.

```text
loaded Interior Tenement Gatehouse alongside in 2.86s
main camera now id 1809714 at {"x":99.4568,"y":-94.52959,"z":12.7817459}
  PlayerCamera: 1 before, 1 new; instance 1925248 -> 2054982
  InteractObjects: 1 before, 1 new; instance 1941926 -> 2065626
  FirstPersonHands: 1 before, 1 new; instance 1934716 -> 2061196
  PauseMenu: 1 before, 1 new; instance -7740 -> -151636
  SoundscapeGlobal: 1 before, 1 new; instance 1948148 -> 2069232
  UnityEngine.Camera: 7 before, 6 new
    Player Camera (id 1991106) active true enabled true depth -1.0 display 0 tag "MainCamera"
  UnityEngine.Canvas: 672 before, 1 new
    Pause Menu(Clone) (id -151630) ... renderMode "ScreenSpaceOverlay" sortingOrder 7
  UnityEngine.AudioListener: 6 before, 5 new
  UnityEngine.Light: 354 before, 151 new
```

The second area brings its own player setup, and each part takes over
the game's one copy (`instance` switched to the new copy):

- Player camera and controls on objects named "Player Camera" and "Player
  Camera Base": PlayerCamera, CameraRotate, CameraShake, SetControls,
  InteractObjects, ThirdPersonCameraCollision,
  ThirdPersonCameraController, FirstPersonSettings, PlayerAudioListener.
- FirstPersonHands, PlayerCameraAnimations.
- A second pause menu (PauseMenu, DeathMessage, PauseMenuGlow) with its
  own overlay canvas.
- SoundscapeGlobal, info_map.
- 6 cameras, one of them a second "Player Camera" tagged MainCamera; 5
  audio listeners; 151 lights.

Not duplicated: Inventory, PlayerStats, TimeOfDayAzure, Crime, Money and
about 100 other managers keep one copy.

Likely causes of what the player saw, not proven: the second area's own
Player Camera drawing (the main camera itself did not move), and its
pause menu overlay or switched player classes hiding the HUD.

Not explained: most unchanged classes read "instance ... -> 0"; a live
object never has id 0, so this is likely a reading problem in the test.
LightsController and four menu panels read "-> null", which may be real.

So for keeping several areas loaded, a mod switches off each newly loaded
area's own player setup so the first one stays in charge.

## Where an area's player setup sits

`research_area_player_setup.rs` (2026-10-02): loaded Interior Tenement
Gatehouse alongside Interior Player Tenement and followed every copy of
the duplicated classes up to its top parent object. Full output in
`output/area-player-setup.txt`.

```text
second: Player Camera Base (top object id 1974670), 11 parts:
second: Pause Menu(Clone) (top object id -141548), 5 parts:
second: __MAIN (top object id 1955252), 2 parts:
second: ___Screenshot Taking Stuff (top object id 1956678), 8 parts:
```

Each area brings the same four top objects, mirroring the first area's:

| Top object | Holds |
|---|---|
| `Player Camera Base` | the player view and controls: Player Camera, FirstPersonCamera, First person hands, InteractObjects, the camera controllers, PlayerAudioListener, Pause Menu Glow (11 parts) |
| `Pause Menu(Clone)` | PauseMenu, DeathMessage, KeyBindings, LoadMenu and the overlay canvas; "(Clone)" means something creates it at run time |
| `__MAIN` | Soundscapes, info_map; likely more not in the list checked |
| `___Screenshot Taking Stuff` | 4 screenshot cameras with audio listeners |

The first area also had `Furniture Shop UI` with its own camera; the
second did not.

So a mod switches off a short fixed list per area loaded alongside:
`Player Camera Base`, `Pause Menu(Clone)`, `___Screenshot Taking Stuff`.
`__MAIN` may hold what the area itself needs once the player is in it, so
it is not switched off blindly; what it holds is the next question.

## What an area's __MAIN holds

`research_area_main.rs` (2026-10-02), read-only, in Interior Player
Tenement: everything under `__MAIN`, 183 objects. Full list in
`output/area-main.txt`.

```text
__MAIN
  info_player_spawn  info_player_spawn
  info_navigation  info_navigation
    Navigation  AstarPath, RVOSimulator
  info_game_logic  info_game_logic
  Post Processing  PostProcessVolume
  Soundscapes  SoundscapeGlobal
    ... (day and night music, a sound zone per room: basement, stairs,
        17 apartments and balconies, reverb zone)
  info_map  info_map
```

| Under `__MAIN` | What it is |
|---|---|
| `info_player_spawn` | the area's player start; holds a link to the area's player object (`Player`, info_player_spawn.cs:9), likely the `Player Camera Base` setup; destroys it when destroyed |
| `info_navigation` | the area's NPC pathfinding grid (AstarPath, RVOSimulator) |
| `info_game_logic` | the area's settings: sky override and background radiation, applied in Start (info_game_logic.cs:97) |
| `Post Processing` | the area's image effects volume |
| `Soundscapes` | the area's music and sounds, 160 of the 183 objects |
| `info_map` | the area's map information |

From the code: `info_game_logic` already keeps one copy. A second area's
copy destroys its own object when one exists (info_game_logic.cs:73).
That fits the managers not being duplicated in an area loaded alongside;
whether they hang off it is not confirmed. Its sky and radiation settings
are applied only in Start, so moving into an area kept loaded would have
to apply them again.

So per area kept loaded alongside, a mod would:

- switch off `Player Camera Base`, `Pause Menu(Clone)`,
  `___Screenshot Taking Stuff`
- keep its `Soundscapes`, `Post Processing` and `info_navigation` off
  until the player is in that area, then switch them on (two pathfinding
  grids active at once would likely clash; not tested)
- on moving in, apply that area's sky and radiation settings again

None of this switching had been tried at the time; what was built is in
[`kept-areas.md`](kept-areas.md).

## Areas share one world space

With two areas on, the player's first trip from inside went "in", and
outside the building looked black with no door back: the building's
interior is built where the building stands in the outdoor area, so the
outdoor door sat on the inside door and answered the use key first. The
areas share one world space, so moving between them is a position change
(research_move.rs, in kept-areas.md).
