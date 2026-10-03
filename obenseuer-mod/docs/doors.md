# Doors and moving between areas

> **Authoritative on:** how the game moves the player between areas:
> `Changelevel` and its door classes, arrival points
> (`PlayerLevelEntrypoints`), `SaveController.ChangeLevel` and its
> coroutines, `LoadingScreen` loading, the game's early load
> (`LoadSceneAsyncTrigger`), teleports, every other caller of a level
> change, measured door times, and what the mod does when a level change
> is not a door. The save and load steps a door runs: [`save.md`](save.md).
> The mod's own door: [`kept-areas.md`](kept-areas.md).
>
> Index of every game system's doc: [`research.md`](research.md).

## Changelevel

`public class Changelevel : Interactable`, `[ExecuteInEditMode]`
(Changelevel.cs). Base of every door to another area. Not saved itself.

| Member | Type | Meaning |
|---|---|---|
| `OtherLevel` | `string` | Scene name of the destination |
| `OtherEntrypoint` | `string` | Arrival point name in the destination |
| `ThisEntrypoint` | `PlayerLevelEntrypoints.Entrypoint` | This door's own arrival point (where you arrive coming back) |
| `Delay` | `float`, -1 | Seconds before changing level (DoorChangelevel sets it from the open sound) |
| `_onChangeLevel` | `Action` protected | Called just before the level change |
| `entrypointNameEnter`, `entrypointNameExit`, `entrypointScene` | `static string` | Set on every change: this door's arrival name, destination arrival name, destination scene |
| `changeLevelDelayActive` | `static bool` | A delayed change is pending |
| `ChangeLevelActive` | `static bool` (get) | `changeLevelDelayActive && LoadingScreen.instance.Active` |

| Method | Does |
|---|---|
| `Awake()` virtual (44-51) | In play: `ThisEntrypoint.OtherEntyPoint = OtherEntrypoint`; **inserts `ThisEntrypoint` at index 0** of `PlayerLevelEntrypoints.instance.Entrypoints` |
| `Interact()` (53-56) | `ChangeLevel()` |
| `ChangeLevel()` (72-88) | Returns while `SaveController.Loading` or `WaitingController.waitingType != None`. Logs an error and returns when `!SaveController.CheckIfLevelExists(OtherLevel)` (`Application.CanStreamedLevelBeLoaded`). Sets the three statics, invokes `_onChangeLevel`, clears `changeLevelDelayActive`, calls `SaveController.ChangeLevel(OtherLevel, OtherEntrypoint)` |
| `ChangeLevelDelay()` protected (62-70) | `WaitForSecondsRealtime(Delay)`, then `ChangeLevel()` if not waiting/sleeping |
| `OnPlayerSpawn()` virtual (90-92) | Empty; DoorChangelevel overrides |

### DoorChangelevel

`public class DoorChangelevel : Changelevel` (DoorChangelevel.cs). A door
the player uses. Saves into the area's file (`SerializeData(this)`).

| Member | Saved | Meaning |
|---|---|---|
| `GUID` | no | Save key |
| `_Lock` (`Lock`, `fsCheckChildFields`) | yes | The lock ([`economy.md`](economy.md), locks) |
| `LockAfterUse` | no | Lock after going through (`OnChangelevel`, 286-292) |
| `DontSyncLocks` | no | Skip the lock sync below |
| `OnOpen` (`Relay`) | no | Fired on open |
| `OpenSound`, `CloseSound`, `LockedSound` | no | Sounds |
| `animator`, `closeAnimationLength` | no | Door animation |

| Method | Does |
|---|---|
| `Awake()` (96-103) | `base.Awake()`; `_onChangeLevel = OnChangelevel` |
| `Start()` (105-123) | `Delay = OpenSound.Clip.length + 0.1` when `Delay < 0`; default `title` "Door", `useMessage` "Enter"; `ThisEntrypoint._OnPlayerSpawn = OnPlayerSpawn` |
| `Interact()` -> `UseDoor()` (125-169) | `_Lock.Use(UnLock, gameObject)`: true -> `OpenDoor()`, false -> `LockedUse()` (sound, "Locked" animation, warning) |
| `OpenDoor()` (186-221) | Returns while waiting/sleeping. `OnOpen.triggerOutputs()`, open sound, ignores collisions with the player's collider, "Open" animation; checks the level exists; `GameController.instance.ControlsDisabled(gameObject)` and hides the game menu; with `Delay > 0`: `changeLevelDelayActive = true` and `ChangeLevelDelay()`, else `ChangeLevel()` |
| `OpenDoorNPC(changeNPCState, npcToDestroy, npcToSpawn)` (240-259) | NPC use: opens, after 1 s realtime calls `changeNPCState`, closes after 1 more s ([`npcs.md`](npcs.md)) |
| `OnPlayerSpawn()` (275-284) | Close sound 0.2 s after the player arrives here |
| `OnSavingGame()` (59-67) | `_Lock.OnSaving()`; unless `DontSyncLocks`: `GlobalState.SetState(OtherLevel + "_" + OtherEntrypoint, true, new DoorChangelevelGlobalState(_Lock.Locked))`; writes its entry |
| `OnLoadingGame()` (69-94) | Reads its entry; unless `DontSyncLocks`: reads `GlobalState[GetActiveScene().name + "_" + ThisEntrypoint.Name]` and locks or unlocks to match; `_Lock.OnLoading()` |

Lock sync: each side of a door pair writes the lock state under the key
of the other side's arrival point when its area saves; the other side
applies it when its area loads.

### TriggerChangelevel

`public class TriggerChangelevel : Changelevel` (TriggerChangelevel.cs).
A zone that changes level on entry.

| Member | Does |
|---|---|
| `active` (`bool`, true) | Trigger armed |
| `Awake()` (11-22) | If `active`: disarm, re-arm after 8 frames + 0.2 s (`ActivateLate`); `base.Awake()` |
| `OnTriggerEnter(Collider)` (48-62) | Player tag, armed, not yet `triggered`: `triggered = true`; `ChangeLevelDelay()` or `ChangeLevel()` |
| `EnableTrigger()`, `DisableTrigger()` | Arm, disarm |

## Arrival points (PlayerLevelEntrypoints)

`public class PlayerLevelEntrypoints : MonoBehaviour`, `[ExecuteInEditMode]`
(PlayerLevelEntrypoints.cs). One per area, in Game_Logic
([`areas.md`](areas.md)). Not saved.

| Member | Meaning |
|---|---|
| `static PlayerLevelEntrypoints instance` | Set in Awake (60-63) |
| `List<Entrypoint> Entrypoints` | Built in the editor (`BuildEntryPoints`, 121-151: every `Entrypoint` field of every MonoBehaviour in the scene); each door's Awake inserts its own at index 0 |
| `Entrypoint GetEntrypoint(string name)` (97-107) | First with that `Name` (a door's own copy, at the front, wins over the editor-built one) |
| `Entrypoint GetEntrypointByOtherEntyPoint(string name)` (109-119) | First whose `OtherEntyPoint` is `name` |
| `Entrypoint GetRandomEntrypoint()` (77-95) | Random one, not named "UnderMapDrop" |

`[Serializable] class Entrypoint` (12-54):

| Member | Meaning |
|---|---|
| `string Name` | Arrival point name (what a door's `OtherEntrypoint` names) |
| `string OtherEntyPoint` | The arrival name on the other side (set by the door's Awake) |
| `Transform Location` | Where the player is put |
| `output OnPlayerSpawn` | Fired after the player arrives |
| `Action _OnPlayerSpawn` | Called after the player arrives (DoorChangelevel: close sound) |
| `bool dontUseAsDefaultSpawn` | Skipped as the fallback spawn |
| `TeleportPlayer()` (32-38) | `Teleport.TeleportPlayerToTargetStatic(Location)`, then `_OnPlayerSpawn`, then `OnPlayerSpawn.Fire()` |
| `GetWaypointLevelChange()` (46-53) | The `Waypoint_LevelChange` on `Location` (NPC door waypoint) |

## Teleporting the player

`Teleport.TeleportPlayerToTargetStatic(Transform)` (Teleport.cs:86-89) ->
`PlayerLocator.instance.Teleport(location)` (PlayerLocator.cs:29-): sets
the player transform's position, rotation (`eulerAngles`), `localScale`;
its Rigidbody's position and rotation, zero velocities; the third-person
camera's `rotY = location.y + 180`, `rotX = 0`, `MoveToTarget()`; then
`PersistLocation` handling (54-).

`public class Teleport : SavableScript` (Teleport.cs): a scene teleport.
`target` (null = the player), `location`, `onTeleport` (Relay),
`playerTeleportDisabled`, `teleportDisabled` (`TeleportDisabled`),
`teleportOnMapChange`, `minTargetDistanceOfTheplayer`,
`minLocationDistanceOfTheplayer`. `TeleportTarget()` (49-63): the player,
or `target` moved to `location` when both distance checks pass.
`TeleportPlayer()` (65-72). `TeleportPlayerToEntrypoint(name)` (91-): by
arrival name. `OnMapChanging()` (40-47): `TeleportTarget()` when
`teleportOnMapChange`.

## SaveController.ChangeLevel

`public static void ChangeLevel(string newlevel, string newLevelEntrypoint = "NONE")`
(SaveController.cs:248-261). With `SaveController.instance` (always in
play): starts `ChangeLevelWhenReady` on it. Without: fade, save, load
directly.

`ChangeLevelWhenReady(newlevel, entrypoint)` (263-281):
1. Waits while `Loading`; sets `Loading = true`.
2. `PlayerWillChangeLevel` event (InteractableChair, InteractableLadder
   stop sitting and climbing).
3. Empty `newlevel`: `ChangeLevelSame` (fade, move to the arrival point,
   autosave, fade out, 362-388), then `Loading = false`. Else
   `ChangeLevelDelay`.

`ChangeLevelDelay(newlevel, entrypoint)` (344-360):
1. `LoadingScreen.instance.Fade(true, soundsMuted, 0, changeHint, newlevel)`;
   waits until `LoadingScreen.Fading` is false.
2. `SaveGame(GetOldestAutosave(), newlevel, entrypoint)`: the save phases
   on the active area, files written ([`save.md`](save.md)).
   `GetOldestAutosave()` (283-342): "Autosave" or "Autosave2", whichever
   `Info.tnmt` date is older.
3. `StartCoroutine(LoadGameWithMigration(CharacterName, autosave))`:
   reads the save back ([`save.md`](save.md)), then
   `LoadSaveGameDifferentScene`.

`LoadSaveGameDifferentScene(playerLevel, fromMenu, dialogueData, entrypoint)`
(618-666):
1. `Guids.Clear()`; `LoadingScreen.instance.LoadLevel(playerLevel, ...)`;
   waits for `LoadingScreen.LevelLoadDone`. (Without a LoadingScreen:
   `SceneManager.LoadSceneAsync(playerLevel, Single)`.) The single-mode
   load destroys every object of the old area (OnDisable, OnDestroy);
   the new area's objects Awake and OnEnable, Start on the next frame.
2. `LoadingStarted`; load phases Primary, Secondary, Tertiary on the
   active scene's top objects; `OnLoadingGameSpecial` on the
   kept-through-loads objects; `DestructibleList.instance
   .OnLoadingGameDestructibleList()`; `OnLoadingGameDestructibleListCheck`
   including inactive objects (640-646).
3. Next frame: `OnLoadingGame`, `OnLoadingGameLatePrimary`, the check
   again (647-650).
4. `OnMapChanged` on the active scene when `playerLevel != LevelName &&
   !fromMenu`, or the entrypoint is set and not "NONE" (651-654).
5. `MovePlayerToEntrypointDelayed(entrypoint)` (655): unless "NONE",
   after `WaitForSecondsRealtime(0.1)` `MovePlayerToEntrypoint`.
6. Dialogue data applied (`PersistentDataManager.ApplySaveData`), temp
   lists cleared, `Loading = false`, `LoadingDone`, fade out after 0.5 s
   (656-664).

`MovePlayerToEntrypoint(string entrypoint)` (682-705): the first entry in
`PlayerLevelEntrypoints.instance.Entrypoints` with that `Name` ->
`TeleportPlayer()`. Not found: logs "Entrypoint X not found!" and uses the
first entry not `dontUseAsDefaultSpawn`.

## LoadingScreen

`public class LoadingScreen : MonoBehaviour` (LoadingScreen.cs). Kept
through loads; Awake keeps the first copy (`DontDestroyOnLoad`) and
destroys others (85-98).

| Member | Does |
|---|---|
| `LevelLoadDone` (`bool`) | Set when the scene load finished |
| `Active` | The loading canvas is enabled |
| `Fading` | A fade is running |
| `LoadLevel(sceneName, soundsMuted, isWhiteScreen, manualFade, changeHint)` (118-140) | Shows the screen (hint, normal or white), starts `LoadAsynchronously` |
| `LoadAsynchronously(name, soundsMuted, manualFade)` (171-253) | Fade in (alpha +0.05 per frame) and audio mixer ("Load", "LoadScreen", "PauseMenu", "Sleeping"); underwater effect off. If `LoadSceneAsyncTrigger.currentAsyncScenes` holds the scene: takes that operation and sets `allowSceneActivation = true` (log "Allow Scene Activation..."), else `SceneManager.LoadSceneAsync(name)` (single mode; log "Load Scene Async..."). Each frame `UpdateLoadingBar()`. When done: `Time.timeScale = 1`, `AudioListener.pause = false`, `LevelLoadDone = true`; waits while `TimeOfDayAzure.updateTimeDisabled`; one frame; fade out |
| `UpdateLoadingBar()` (100-111) | Bar moves toward `operation.progress / 0.9` at 1 per second (`Mathf.MoveTowards`); `allowSceneActivation = true` only when the bar reaches 1 |
| `Fade(Fadein, soundsMuted, delay, changeHint, sceneName)` (255-) | Fade in or out (`FadeCoroutine`) |

## The game's early load (LoadSceneAsyncTrigger)

`public class LoadSceneAsyncTrigger : MonoBehaviour` (LoadSceneAsyncTrigger.cs).

| Member | Does |
|---|---|
| `Changelevel changelevel` | The door whose destination it loads |
| `static List<AsyncOperation> currentAsyncOperations`, `static List<string> currentAsyncScenes` | Early loads in progress; read by `LoadingScreen.LoadAsynchronously` |
| `OnTriggerEnter(Collider)` (18-49) | Player tag: `SceneManager.LoadSceneAsync(changelevel.OtherLevel, Additive)`, added to both lists. On completion: if the scene was taken off `currentAsyncScenes`, unloads it; removes it from both lists |
| `OnTriggerExit(Collider)` (51-61) | Removes `changelevel.name` (the door object's name, not `OtherLevel`) from `currentAsyncScenes` |

The early load is Additive and its `allowSceneActivation` is never set
false, so it finishes on its own and the completion handler takes it off
the lists; a door used after that does a full load. A door used while it
runs reuses it (additive; whether the old area is then unloaded is not
checked).

## Other callers of a level change

Every caller of `SaveController.ChangeLevel` in the decompiled code:

| Caller | Destination |
|---|---|
| `Changelevel.ChangeLevel` (Changelevel.cs:86) | The door's `OtherLevel` / `OtherEntrypoint` |
| `Crime.TeleportToPrison` (Crime.cs:322-330) | `info_game_logic.instance.prisonLevelName`, `prisonEntrypoint` ([`crime.md`](crime.md)) |
| `SleepEventController` (SleepEventController.cs:341) | "Interior Player Tenement", "CrazyPoint" |
| `BlackoutTrigger` (BlackoutTrigger.cs:123) | `sceneToChangeTo`, `entrypointName` or "NONE" |
| `ChangeScene.Change(string scene)` (ChangeScene.cs:9-31) | When `scene == NPCManager.instance.ActiveScene`: teleports to `GetEntrypoint(entrypoint)` and fires `onSceneChangeToCurrent`; else `ChangeLevel(scene, entrypoint)` |
| `DeveloperConsoleRoutines` (DeveloperConsoleRoutines.cs:33) | Console command |

Fast travel: `FastTravelController` (FastTravelController.cs) only opens
the menu (`ToggleMenu`, 12-15). No code calls a level change from fast
travel; the menu's buttons are wired in the scene (not read).

## Measured door times (2026-10-02)

Player.log lines (seconds from the start of the load):

| Destination | Bar done | Back in game |
|---|---|---|
| Interior Tenement Gatehouse | 2.4 | 3.3 |
| Interior Tenement Deekula A | 2.6 | 4.0 |
| Interior Tenement Deekula C | 14.9 | 17.5 |
| Open Sewer Tenement | 14.6 | 16.3 |
| Open Sewer Tenement (later trip) | 4.6 | 7.7 |
| (destination not in these lines) | 4.9 | 18.1 |

`research_loading.rs`, Open Sewer Tenement to Interior Player Tenement:
`fade 2.14s, save and read back 0.00s, bar 4.67s, restore 0.00s, total
6.81s, longest freeze 1.90s` (save and restore fell inside a freeze the
test could not see into; the freeze being the save is likely, not
proven).

`save_timing.rs` (Harmony prefix and postfix on `SaveGame`), one door to
Open Sewer Tenement:

| Part | Time |
|---|---|
| Save | 0.582 s |
| Bar (scene load) | 4.25 s ("Load scene async done (4.2537571s)") |
| Restore (load steps) | about 1.0 s ("After small delay (5.2849259s)") |
| Fade back in | about 0.6 s ("Fade out done (5.8932484s)") |

Player.log does not time the save or the fade to black before the bar.
The fade back in waits for the load steps: `TimeOfDayAzure` holds
`updateTimeDisabled` until `SaveController.Loading` is false
(TimeOfDayAzure.cs:345). Keeping one copy of the managers would remove
the save and part of the restore (about 1.5 s on this trip); the bar is
the largest part and only loading the area early removes it.

Fixed costs in code: the bar's 1 per second fill means at least about
1 s even for an instant load (LoadingScreen.cs:103); fades step alpha by
0.05 per frame, 20 frames each way.

`research_early_load.rs`, Open Sewer Tenement: 57 doors (`Changelevel`),
about 40 destinations, 6 with no destination (two elevator doors), 0
`LoadSceneAsyncTrigger`. Other areas not counted (todo).

## With areas kept loaded (the mod)

The mod's prefix is on `Changelevel.ChangeLevel` (kept_loaded.rs:61): a
door whose destination is kept loaded runs the mod's door
([`kept-areas.md`](kept-areas.md)); `PlayerLevelEntrypoints` is
area-owned, and the arrival point is read from the entered area's own
copy. Every other caller above calls `SaveController.ChangeLevel` directly
and takes the game's load. On such a load: the save before it also writes
the kept areas (postfix on `SaveGame`, kept_loaded.rs:52-55); the
single-mode load unloads every area; the mod's tick sees a new
GameController (126-135), forgets every kept area (`reset`, 87-104), takes
the loaded area as the one whose data the game applied (136-142), and
loads its door destinations alongside again, nearest door first (143,
171-194).

Door lock sync: `DoorChangelevel.OnLoadingGame` runs only on the first
visit to a kept area, so a lock changed on the other side of a door pair
after that is not applied while the area stays kept (todo).
