# Kept areas: design

The authority for what obenseuer-mod does to make doors seamless. Evidence
and history are in [loading-research.md](loading-research.md); this file
says what the mod does and why, and nothing is built that is not here.

## Goal

Doors between areas move the player with no loading screen. The game must
behave as it does without the mod: same data, same events, same results.
Areas once loaded stay loaded (no limit by default); loading them happens
in the background and must never make the game stutter.

## The idea

The game has one area at a time. At a door it saves, unloads the area,
loads the next one, and loads the save into it (SaveController.cs:344-359).

The mod keeps areas loaded and does the same steps itself, on the area
left and the area entered, without unloading and without files. The
player's data never leaves memory: the player and managers the save loaded
stay the live ones in every area.

Every rule below copies a piece of the game. Anything the game does at a
door that the mod does not do, or does differently, is listed under
"Differences from the game".

## Rule 1: loading an area alongside

1. The area loads in the background (`LoadSceneAsync`, additive, low
   priority).
2. Unity's `sceneLoaded` runs after its objects' Awake and OnEnable and
   before any Start; there the shim switches its top objects off
   (`SceneTools.LoadQuietly`). Nothing in it starts until the player walks
   in.
3. Its copies of the game's managers do not take over, except the
   area-owned ones (below).

### Which copy the game uses

Every area brings its own copy of each manager. A manager is a class whose
Awake (or OnEnable) sets a public static field or property of its own type
to itself (`instance = this`). A static field of its own type that Awake
does not set is not a manager: `Storage.active` is the box open now.

- Game-wide managers (the player's: Inventory, PlayerStats, Money, the
  clock, the camera, the UI): the copies the save loaded stay the game's
  in every area. A copy from an area loaded alongside does not take over
  (its Awake and OnDestroy are skipped, first_copy_wins.rs).
- Area-owned managers: hold the area's own data, so they belong to the
  area's content, not to the player setup. This is Unity's standard
  pattern for levels loaded alongside a persistent scene: one persistent
  set of player and managers, and a level's own managers live and work in
  the level (loading-research.md, "One copy for the game, or one copy per
  area"). Obenseuer's scenes bundle them inside each area's copy of the
  player setup (`Game_Logic`), which the mod keeps switched off, so the
  mod separates them:
  - When the area has loaded alongside (in `sceneLoaded`, rule 1 step 2),
    each one's object is taken out of `Game_Logic` and made a top object
    of the same area. It is then the area's content: switched on and off
    with the area, saved and loaded with it by the game's own steps (rules
    2 and 3), and able to run its coroutines. Each sits alone on its own
    object with no children (research_area_owned.rs), so nothing else
    moves with it.
  - Its Awake is still held back at load (it would take over while the
    player is elsewhere). Entering the area sets its `instance` to the
    area's copy and switches the script on (rule 2, step 2), as its Awake
    would have on a normal load. `DestructibleList.Awake` also empties
    `Collectible.allCollectibles` (DestructibleList.cs:91): whether entering
    must do that too is not checked yet.
  - Known: `PlayerLevelEntrypoints` (`Game_Logic/Other/PlayerLevelEntrypoints`,
    arrival points), `DestructibleList` (`Game_Logic/Other/LoadSavegame`,
    dropped and destroyed items, saved in the area's file),
    `SleepEventController`
    (`Game_Logic/Controllers/WaitingController/SleepEventController`, saved
    in the area's file). Found by where they save and what they hold; a
    class shown to be area-owned later is added here first.

## Rule 2: entering an area

The game's own steps after a load (`LoadSaveGameDifferentScene`,
SaveController.cs:640-664), on the area entered, in this order:

| # | Game step | Line | Mod |
|---|---|---|---|
| 1 | Area loaded: Awake, OnEnable, then Start | 624-639 | Area switched on (Start runs now), made the active scene |
| 2 | Area-owned managers are the area's | (their Awake) | Their `instance` set to the area's copy (rule 1, which copy) |
| 3 | `LoadingStarted` | 640 | Fired |
| 4 | Load phases Primary, Secondary, Tertiary | 641-643 | First visit: from the area's saved file |
| 5 | Kept-through-loads OnLoadingGameSpecial | 644 | Not run: game-wide data, already live |
| 6 | `DestructibleList.OnLoadingGameDestructibleList`, the destroyed-objects check | 645-646 | First visit |
| 7 | Next frame | 647 | Next frame |
| 8 | OnLoadingGame, OnLoadingGameLatePrimary, the check again | 648-650 | First visit |
| 9 | OnMapChanged on the area | 651-654 | Every visit, on the area (and on the live player and managers' area) |
| 10 | Player to the arrival point | 655 | The door's arrival point in the area |
| 11 | Dialogue data applied | 656-659 | Not run: game-wide data, already live |
| 12 | Temp lists cleared, `Loading` false, `LoadingDone` | 660-663 | Lists cleared, `LoadingDone` fired |

"First visit" means the first time since the save was loaded. Later visits
keep what is live in the area: its data never left memory.

## Rule 3: leaving an area

The game's own steps at a door (`ChangeLevel` 270, `SaveGame` 416-478), on
the area left, in this order:

| # | Game step | Line | Mod |
|---|---|---|---|
| 1 | `PlayerWillChangeLevel` | 270 | Fired |
| 2 | OnMapChanging on the area and the kept-through-loads objects | 446-447 | The same |
| 3 | `SavingStarted` | 452 | Fired |
| 4 | Save phases Primary, Secondary, Tertiary | 453-455 | On the area, into memory |
| 5 | `DestructibleList.OnSavingGameDestructibleList` | 456 | The area's DestructibleList, into memory |
| 6 | Kept-through-loads OnSavingGameSpecial | 457 | Not run: game-wide data, stays live |
| 7 | OnSavingGame, OnSavingGameLatePrimary | 458-459 | On the area, into memory |
| 8 | Files written | 460-476 | Not now: kept for the next save (rule 4) |
| 9 | OnSavingFile | 477 | Not run: no file written |
| 10 | `SavingDone` | 478 | Fired |
| 11 | Area unloaded: OnDisable, OnDestroy | (scene swap) | Area switched off: OnDisable only |

## Rule 4: saving

When the game saves (`SaveGame`), the mod adds every visited area's data
captured in rule 3 to the save folder: each area's file from its own
captured entries, merged with what the file already held. The area the
player is in is saved by the game itself.

## The mod's own state

State about a loaded area belongs to that load (Unity's `Scene.handle`,
new on every load), never to the area's name, and is dropped when that
load unloads. Everything the mod keeps is cleared when the game does a
normal load.

## Differences from the game

| Difference | Why | Status |
|---|---|---|
| Areas left are switched off, not unloaded: their objects keep subscriptions to game-wide events (a switched-off Spawner still gets `TimeOfDayAzure.SecondsPassed`) | Unloading is what makes doors slow | Not measured; operator to decide |
| No autosave at a door | Writing files at a door stutters | Decided by the operator (2026-10-03): no autosave at doors; the player saves |
| Objects in an area never entered woke but never started; OnDestroy of a class with Start and no Awake is skipped for them, and an exception their OnDisable throws is swallowed | Nothing may start before the player walks in (an area's intro ran and left the screen black) | Built |

## Proof

`tests/research_kept_scenario.rs`, after every change: through a door and
back, save, load. With kept areas on and off (`OBENSEUER_KEPT_OFF=1`), it
must end with no error the game does not also log, every manager live, and
the player's identity intact. A second visit to an area that is not home
must also move without a loading screen.

## Status (2026-10-03)

| Rule | Built | Missing |
|---|---|---|
| 1 | Yes | |
| 2 | Yes: `enter_area`, the arrival point read from the area's own list first (`arrival_point`) | |
| 3 | Yes: `leave_area` | |
| 4 | Yes | |
| The mod's own state | Yes: shim state per load; Rust state cleared on every normal load (`tick`: a new GameController calls `reset()`, kept_loaded.rs:121-123) | |
