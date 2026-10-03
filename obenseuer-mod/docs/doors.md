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
