# Doors and moving between areas

> **Authoritative on:** how the game moves the player between areas: the
> door step by step, arrival points, every other way the game changes
> area (prison, sleep events, blackouts, ChangeScene, fast travel, the
> console), and what the mod does when one of them takes the game's normal
> load. The save and load steps a door runs are in [`save.md`](save.md);
> the mod's own door (areas kept loaded) is designed in
> [`kept-areas.md`](kept-areas.md).
>
> Index of every game system's doc: [`research.md`](research.md).

## A door

A door: `OtherLevel` (area), `OtherEntrypoint` (arrival name),
`ThisEntrypoint`; `DoorChangelevel.OpenDoor` disables the controls before
ChangeLevel (DoorChangelevel.cs:206).

Step by step: `Changelevel.ChangeLevel` (Changelevel.cs:72-87), then
`SaveController.ChangeLevel` (270) and `ChangeLevelDelay` (344-359):

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
[`relays.md`](relays.md)). Times on one trip: save 0.58s, scene load
4.25s, restore about 1.0s, fade back 0.6s; the bar fills at 1 per second
(LoadingScreen.cs:85), so even an instant load waits about 1s.

## Arrival points (PlayerLevelEntrypoints)

Each area's `PlayerLevelEntrypoints` holds a list of `Entrypoint`
(Name, Location transform, OtherEntyPoint), built in the editor from
every `Entrypoint` field in the scene (PlayerLevelEntrypoints.cs:121-151;
Awake sets `instance`, 60-63). Every door's Awake also inserts its own
entry into the current `instance`'s list (`Changelevel.cs:44-50`); a
door re-created during play inserts a fresh one. Readers:
SaveController.MovePlayerToEntrypoint (688-697), Teleport.cs:93,
Prison.cs:127.

## Area changes other than doors

Doors reach `SaveController.ChangeLevel` through `Changelevel.ChangeLevel`
(Changelevel.cs:86). These call it directly (2026-10-03, from the code;
every caller found by a search of the decompiled code):

- Going to prison: `Crime.TeleportToPrison` (Crime.cs:322-330) to
  `info_game_logic.prisonLevelName` ([`areas.md`](areas.md),
  info_game_logic).
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

## With areas kept loaded (the mod)

The mod's door prefix is on `Changelevel.ChangeLevel` (kept_loaded.rs:61),
the door component, so only doors take the kept door; the area changes
above take the game's normal load. What the mod does on such a normal
load (kept_loaded.rs): the game's save before the load also writes the
kept areas, from the postfix on SaveGame (52-55, on_save_done). The scene
load in single mode unloads every area, kept ones included. The mod's
tick sees a new GameController (126-135), forgets every kept area (reset,
87-104), takes the area loaded as the one whose data the game applied
(136-142), and loads its door destinations alongside again, nearest door
first (143, 171-194). So such a change shows the game's loading screen as
in the game, and the kept areas load again in the background after it.

## A door in short (2026-10-02)

Code: `SaveController.ChangeLevelDelay` (SaveController.cs:344).

1. The screen fades to the loading screen (`LoadingScreen.Fade`).
2. The game writes a full save into the older of the two autosave slots
   (`SaveGame`).
3. It loads that save back (`LoadGameWithMigration`, SaveController.cs:1205).
   This swaps in the new area's scene with `SceneManager.LoadSceneAsync`
   in single mode, which destroys the old area
   (`LoadingScreen.LoadAsynchronously`).
4. It restores what was saved for the new area: boxes, NPCs, the clock.
   The fade back in waits until this is done: `TimeOfDayAzure` holds
   `updateTimeDisabled` until `SaveController.Loading` is false
   (TimeOfDayAzure.cs:345).

The save in step 2 is how the player's state reaches the next area: the
objects holding it are destroyed with the old area and rebuilt from the
save in the new one ([`areas.md`](areas.md), every area brings its own
player and managers).

## Where a door's time goes (2026-10-02)

Sources: the game's own timing lines in Player.log, and the research test
`tests/research_loading.rs` run against the live game.

Game's own Player.log lines (seconds from the start of the load):

| Destination | Bar done | Back in game |
|---|---|---|
| Interior Tenement Gatehouse | 2.4 | 3.3 |
| Interior Tenement Deekula A | 2.6 | 4.0 |
| Interior Tenement Deekula C | 14.9 | 17.5 |
| Open Sewer Tenement | 14.6 | 16.3 |
| Open Sewer Tenement (later trip) | 4.6 | 7.7 |
| (destination not in these lines) | 4.9 | 18.1 |

Player.log does not time the save before the bar.

`research_loading.rs`, one trip Open Sewer Tenement to Interior Player
Tenement:

```text
fade   2.14s  save and read back   0.00s  bar   4.67s  restore   0.00s  total   6.81s  longest freeze 1.90s
```

The fade, bar and total are measured. The save and restore parts read
0.00s because the game froze for 1.90s once during the trip and the test
cannot ask the game anything while it is frozen; both parts fell inside
freezes. That the 1.90s freeze is the save is likely but not proven.

The save itself, timed by a Harmony prefix and postfix on
`SaveController.SaveGame` (`src/save_timing.rs`), one door trip to Open
Sewer Tenement (2026-10-02), with the game's own lines for that trip:

```text
obenseuer-mod: save took 0.582s
Load scene async done (4.2537571s)...
After small delay (5.2849259s)...
Fade out done (5.8932484s)...
```

| Part | Time |
|---|---|
| Save | 0.58s |
| Bar (the area's scene loading) | 4.25s |
| Restore (boxes, NPCs, clock) | about 1.0s |
| Fade back in | about 0.6s |

The fade to black before the save is not in these lines; the test
measured 2.14s on an earlier trip.

So keeping one copy of the managers would remove the save and part of the
restore, about 1.5s at most on this trip. The bar is the largest part and
keeping the managers does not touch it; loading the next area early does.

Other costs in the code:

- The bar fills at a fixed speed (`Mathf.MoveTowards` at 1 per second,
  LoadingScreen.cs:85) and the new area is only shown once it is full, so
  even an instant load waits about 1 second.
- Fades step the alpha by 0.05 per frame, 20 frames each way.

Running the test: [`testing.md`](testing.md).

## The game already loads some areas early

`LoadSceneAsyncTrigger` starts loading the next area alongside the
current one when the player walks into a trigger near some doors. When
the door is used, `LoadingScreen.LoadAsynchronously` reuses that load if
it is in `LoadSceneAsyncTrigger.currentAsyncScenes`.

The early load only helps if the door is used before it finishes: when
the load completes, its `completed` handler removes the area from
`currentAsyncScenes` (LoadSceneAsyncTrigger.cs:33-41), so a door used
after that loads the area again from scratch. The early-loaded area then
seems to stay loaded alongside the current one until the door's load
replaces everything (not confirmed live).

Live game, `research_early_load.rs`, in Open Sewer Tenement (the main
outdoor area, 2026-10-02):

```text
area "Open Sewer Tenement", scenes loaded now 1
57 doors to other areas (Changelevel):
0 early-load triggers (LoadSceneAsyncTrigger):
```

- All 57 doors are active and lead to about 40 different areas (shops,
  tenements, bars, the metro). 6 have no destination (`to ""`), among
  them two elevator doors.
- No door in this area loads early: every door here does the full load.
- Other areas were not checked; the test sees only the area the player
  is in.

A door's early load tried by the mod: [`kept-areas.md`](kept-areas.md),
how the design was reached.
