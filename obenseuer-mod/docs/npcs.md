# NPCs

> **Authoritative on:** NPC data and state (`NPCData`, `NPCDataState`,
> NPCBehavior.json, Characters.json), `NPCDirector` (the simulation of
> every NPC, with or without an object), `NPCManager` (the area's NPC
> objects, `ActiveScene`), `NPCInfo`, `NPCController`, `Schedule`,
> `Activity`, NPCs moving between areas (`NPCSceneUtilities`,
> `NPCSpawnUtilities`, `Waypoint_LevelChange`), followers. Pathfinding
> itself: [`pathfinding.md`](pathfinding.md). Police: [`crime.md`](crime.md).
>
> Index of every game system's doc: [`research.md`](research.md).

## Data files

`StreamingAssets/NPCBehavior.json`: `List<NPCData>`, read by
`NPCDirector.LoadDatabase` (FullSerializer, UTF-8):

```json
{
    "ID": 12,
    "startScene": null,
    "startPosition": { "x": 0.0, "y": 0.0, "z": 0.0 },
    "schedulerDisabledAtStart": false,
    "scheduler": { "Name": "", "Timetable": [], "RandomActivities": [] },
    "prefabPath": "Prefabs/Characters/Speakeasy/Ville Skoldgangster"
}
```

`StreamingAssets/Characters.json` (UTF-16 LE): `Character` per ID: ID,
Name, GenderString, Age, Relationship, Job, FurnitureType, Sprite, Gender
(float), Weight, Muscle, Height, Advanced, ShoulderWidth, HeadSize,
FaceSize, NeckLength, BreastSize, HipWidth, HandSize, FootSize, EyeSize,
appearance slots (Glasses, Beard, Hair, Hat, Jacket, ...). Read through
`CharacterDatabase.instance.FetchCharacterByID(id)`.

## NPCData

`[Serializable] public class NPCData` (NPC/NPCData.cs). One per NPC, in
`NPCDirector.globalDatabase`.

| Member | Meaning |
|---|---|
| `int ID` | Character ID |
| `string startScene`, `Vector3 startPosition`, `bool schedulerDisabledAtStart` | Initial state (`NPCDataState.SetStartData`) |
| `Schedule scheduler` (`fsCheckChildFields`) | Timetable |
| `NPCDataState state` (`fsIgnore`) | Live state; saved through `NPCDirector.savedData` |
| `NPCController controller` (`fsIgnore`) | Cached object |
| `NPCController Controller` (get, 39-53) | `controller`, else `NPCManager.instance.FindNpcControllerById(ID)`, else `scheduler.NPC` |
| `Character character`, `CharacterRent characterRent` | From the databases by ID |
| `string prefabPath`, `GameObject GetCharacterPrefab` | `character.prefab`, else `Resources.Load(prefabPath)`, else "Prefabs/Characters/NPC base" |
| `const float walkSpeed = 1.5` | m/s for simulated walking |
| `OnSavingGame()` (113-122) | `state.ID = ID`; **when the NPC has an object**: `state.currentScene = NPCManager.instance.ActiveScene`, `currentPosition`, `currentRotation` from the object |
| `OnLoadingGame()` (124-134) | With an object: `CurrentActivity.SetNPC(Controller)`, `Controller.ResumePoliceActivityWhenReady()` |
| `Spawn()` (136-149) | `GetLocation(...)`, then `character.Spawn(position, rotation)` (clears `activePath`) |
| `MoveToCurrentLocation(NPCInfo)` (160-181) | `GetLocation(...)`, moves the existing object |
| `SetInterScenePosition(scene, entrypoint)`, `SetInterSceneTransit(targetScene, targetEntrypoint, progress)` | Forward to state |
| `GetLocation(onResult, out spawnImmediately)` | `state.GetLocation(this, Controller, character, scheduler, 1.5, ...)` |

## NPCDataState

`[Serializable] public class NPCDataState` (NPC/NPCDataState.cs). Saved
(in Globals, through NPCDirector).

| Field | Meaning |
|---|---|
| `int ID` | |
| `string currentScene` | Area the NPC is in (or passing through) |
| `Vector3 currentPosition`, `Quaternion currentRotation` | Last position in that area (zero = none) |
| `string currentEntrypoint` | Arrival point it is at or came through |
| `string targetScene`, `targetEntrypoint`, `float interSceneProgress` | Transit between areas, 0-1 |
| `List<Vector3> transitionPath` | Walk path to the door in the current area |
| `NPCPathfinding.InterScenePath activePath` | Route across areas ([`pathfinding.md`](pathfinding.md)) |
| `uint timeInLevel` | Game seconds in the current stage |
| `bool schedulerDisabled` | Schedule off |
| `Activity currentActivity`, `lastActivity`, `List<Activity> queuedActivities` | Activities; setting `CurrentActivity` moves the old one to `lastActivity` |

| Method | Does |
|---|---|
| `OnMapChange(bool hasObject)` (67-73) | With an object and a follow target: `targetEntrypoint = Changelevel.entrypointNameExit` |
| `ResetTransition()` (88-96) | Clears path, target, progress, `timeInLevel`, `transitionPath` |
| `GetLocation(...)` (98-212) | Where to put the object: saved `currentPosition` when `currentScene == ActiveScene` and ground is below (raycast 25 m); else a point along `activePath` (arrival points, `NPCSpawnUtilities.GetPointAlongPath`, `pathToDoor` by `timeInLevel * walkSpeed`); else the scheduled activity's `GetLocationInfo()`; else the object's position; else the arrival point `currentEntrypoint` or a random one. Uses `PlayerLevelEntrypoints.instance` |

## NPCDirector

`public class NPCDirector : SavableScript`, namespace NPC (NPC/NPCDirector.cs).
Kept through loads (Awake: first copy `DontDestroyOnLoad`, later copies
destroyed; added to `SaveController.DontDestroyOnLoadObjects`, 124-149).
GUID const "NPCDirector"; saves into Globals in the Special step.

| Member | Meaning |
|---|---|
| `static List<NPCData> globalDatabase` | Every NPC |
| `List<NPCDataState> savedData` | Saved form of every state |
| `static NPCDirector instance` | |
| `LoadDatabase()` (192-204) | Reads NPCBehavior.json into `globalDatabase`, fresh state from start data. Skipped after a load (`dontLoadDatabase`) |
| `OnSavingGameSpecial()` (34-43) | Every NPC: `NPCData.OnSavingGame()`, state into `savedData`; writes its entry |
| `OnLoadingGameSpecial()` (45-89) | Reads its entry; each saved state replaces the NPC's `state` (a police activity no longer current is force-stopped; ID 107, the crazy neighbour, gets its schedule switched by rent state and day); then `OnLoadingGameDelay` (end of frame: `NPCData.OnLoadingGame()` for all). No entry: `LoadDatabase()` |
| `OnMapChanging()` (91-104) | Every NPC: `state.OnMapChange(Controller != null)`; re-subscribes `MinutePassed` |
| `OnMapChanged()` (106-113) | Destroys itself in "Main Menu" |
| `Start()` (151-158) | `TimeOfDayAzure.MinutePassed += DeltaSeconds`; after `updateTimeDisabled` clears and 3 end-of-frames, `DeltaSeconds(0)` |
| `GetNPCDataByID(int)`, `GetSchedulerById(int)` | Lookup |
| `SaveDatabase(...)` | Editor only: writes NPCBehavior.json |

`DeltaSeconds(int sec)` (245-291), every game minute (sec = 60), for each
NPC with a `character`:
1. `timeInLevel += sec`.
2. Not in `NPCManager.instance.ActiveScene`:
   `NPCSceneUtilities.UpdateNPCTransition`.
3. The current activity has a follow target:
   `NPCSceneUtilities.OnFollowingTarget(npc, target)`; else, schedule on:
   `Schedule.UpdateScheduler(npc)`.
4. No follow target and not in `ActiveScene`:
   `NPCSceneUtilities.HandleNPCChangeScene(npc)`.

## NPCManager

`public class NPCManager : MonoBehaviour` (NPCManager.cs). One per area,
at `Game_Logic/Controllers/NPC/NPCManager`. Not saved.

| Member | Meaning |
|---|---|
| `static NPCManager instance` | Set in Awake |
| `string ActiveScene` (25-35) | Name cached in Start (`GetActiveScene()`, 60); before Start, read live. Read by 20 NPC code paths as "the player's area" |
| `List<NPCInfo> npcs` private | NPC objects that ran Start (`AddNpcToList`), removed in their OnDestroy |
| `HashSet<int> pendingNpcSpawns` | IDs being spawned through a door (`MarkNpcSpawnPending`) |
| `List<Waypoint_LevelChange> levelChangeWaypoints` | Door waypoints of the area (`AddLevelChangeWaypoint` in their Start) |
| `LayerMask fovMasks` | NPC sight layers |
| `NPCInfo FindNpcById(int)` (141-145) | Active one first, else any |
| `NPCController FindNpcControllerById(int)` (147-157) | |
| `List<NPCInfo> GetAllNPCs()` | |
| `Awake()` / `OnDestroy()` | Register / unregister Lua: `ChangeInteractableTalk(id)`, `LookAtNamedTarget(id, name)`, `LookAtNPC(id, targetId)`, `LookAtPlayer(id)` (bound to this copy) |

`StartDelay()` (64-117), after `updateTimeDisabled` clears and 6
end-of-frames, for every NPC whose schedule is on and whose `NPCInfo`
does not set `ignoreNpcState`:
- `state.currentScene == ActiveScene`: an object exists ->
  `MoveToCurrentLocation`; none and not pending -> `Spawn()`.
- Elsewhere, with an object here and a scene set: fires the object's
  `onDisable` relay and switches the object off.

## NPCInfo

`public class NPCInfo : SavableScript` (NPCInfo.cs). On every NPC object.
Saves with `SerializeData(this, global)`.

| Member | Saved | Meaning |
|---|---|---|
| `Character character`, `characterModel`, `characterHeadController`, `interactableTalk`, `npcController`, `npcFov`, `salsa`, `emoter`, `eyes` | no | Parts |
| `bool ignoreNpcState` | no | NPCManager leaves it alone |
| `bool apartmentSpawn` | no | Spawned in an apartment (tenement) |
| `Relay onHit`, `onEnable`, `onDisable`, `onDestroy` | no | Fired on those events |
| `State state` (Any, Default, Sleeping, Dead), `event StateChanged` | no | |
| `TimeAndDay savedTimeAndDay` | yes | Time at save |
| `Act_Police policeActivity`, `Act_Robber robberActivity`, `TimeOfDayAzure.Timer timeUntilStateChange`, `string changeLevelEntrypointName` | yes | Police or robber state carried through a save |
| `OnSavingGame()` (139-168) | | Records a running police or robber activity and `Changelevel.entrypointNameEnter`; `savedTimeAndDay` |
| `OnLoadingGame()` (170-183) | | `ResidentCheck`, rent check, `OnLoadDelay` |
| `OnLoadDelay()` (193-271) | | After `updateTimeDisabled`: restores the police activity (new timer from saved time; more than 6000 s away -> searching or stand; more than 30000 s -> stand) and `StartStateOnLoad(changeLevelEntrypointName)`; same for robber |
| `Start()` (273-292) | | Appearance, `ResidentCheck`, rent check, `NPCManager.instance.AddNpcToList(this)` |
| `OnEnable()` / `OnDisable()` (294-316) | | Fire `onEnable` / `onDisable` relays (cancelling the other's delayed outputs); restart pending load and rent check / stop them |
| `OnDestroy()` (318-326) | | `RemoveNpcFromList`; removes itself from `TenementController.currentSceneResidents`; fires `onDestroy` |
| `HideRentedResident()` (382-) | | Destroys the object and its property (rented residents live in the tenement) |

## NPCController

`public class NPCController : VersionedMonoBehaviour` (NPCController.cs;
A* Pathfinding base class). Movement
and activities of an NPC object.

| Member | Meaning |
|---|---|
| `NPCData Data` | `NPCDirector.GetNPCDataByID(ID)` in Start (120) |
| `bool activityDisabled`, `updateEnabled`, `usingLevelChangeDoor` | |
| `bool isIdle` | No running activity |
| `Start()` (108-149) | Links `Data`, `scheduler.NPC = this`, `ResetNextCheck()`, `scheduler.Start()`; switches to the scheduled activity if the current one can be interrupted; `CurrentActivity.UpdateActivity(this)`; `UpdatePathToOtherMap()`; starts updating after `updateTimeDisabled` clears and the NPCInfo load finished (`StartDelay`, 199-216) |
| `Update()` (218-242) | Runs `CurrentActivity.OnActivity()` or starts the next queued one; pathfinding |
| `bool StartActivity(Activity, bool interrupt)` (263-290) | Same activity -> true; running and no interrupt -> false; lower priority (unless `force`) -> false; `InterruptActivity()` must succeed |
| `ForceStartActivity`, `ForceStopActivity` (303-328), `QueueActivity`, `EnableActivity`, `DisableActivity` | |
| `SetTargetNode`, `SetTargetPosition`, `SetFollowDestination`, `SetPath`, `MoveToPosition`, `MoveToNode` | Movement |
| `MoveToOtherLevel(string level)` (411-421) | `NPCPathfinding.SearchForPathToOtherMap(ActiveScene, level, ...)` then `UpdatePathToOtherMap` |
| `UpdatePathToOtherMap()` (556-582) | Walks to the door waypoint of `activePath.current.entryPointStart`, found with `FindObjectsByType<Waypoint_LevelChange>(FindObjectsInactive.Include)` (every loaded scene, switched-off objects too) by `LinkedDoor.ThisEntrypoint.Name` |
| `bool InCurrentLevel()` | `ActiveScene == Data.state.currentScene` |
| `OnDestroy()` (682-685) | `Data.scheduler.OnDestroy()` (unsubscribes the schedule) |
| `FollowPlayer(...)`, `StartFollowPlayer`, `StartPatrol`, `StartStand`, `StartDialogue`, `OnTalk`, `OnStopTalk`, `DisableMoving`, `EnableMoving` | Activity and talk helpers |

## Schedule

`[Serializable] public class Schedule` (NPC/Schedule.cs).

| Member | Meaning |
|---|---|
| `NPCController NPC` (`fsIgnore`) | Object it drives |
| `string Name` | |
| `List<ScheduledAction> Timetable`, `RandomActivities` | |
| `ScheduledAction currentScheduledAction` | |
| `event ScheduleChanged(string name)` | |
| `Start()` (34-42) | Once: `TimeOfDayAzure.CurrentTimeAndDay += CurrentTime`; then `CurrentTime(now)` |
| `CurrentTime(TimeAndDay)` (44-105) | With an object: skips while `activityDisabled`, or before `nextCheck` unless idle, or while the activity cannot be interrupted. First Timetable entry covering now (week minutes, wraps at 10080) -> `TryStartActivity`. None: one random entry by `chance`; sets `nextCheck` |
| `TryStartActivity(act, date)` (107-130) | By `act.chance`, `NPC.StartActivity(activity, interruptPrevious)`; `nextCheck` = end of the entry |
| `static UpdateScheduler(NPCData, bool)` (137-189) | In `ActiveScene` with an object: `CurrentTime`. Else `UpdateScheduleWithoutController` and sets the NPC's arrival point from `InterScenePathfindingGraph.GetSceneConnections(currentScene)` (matching `currentEntrypoint`, else the first not `bypassByDefault`) |
| `UpdateScheduleWithoutController(date, data)` (191-228) | Picks `currentScheduledAction` the same way, without starting anything |
| `GetActivitiesByDay(int)`, `GetActivitiesByDayAndHour(int, int)`, `ResetNextCheck()` | |
| `OnDestroy()` (275-278) | Unsubscribes. After an NPC's object is destroyed once, the schedule runs only from NPCDirector's tick (`started` stays true) |

`ScheduledAction` (NPC/ScheduledAction.cs): `name`, `disabled`,
`interruptPrevious` (true), `chance` (1), `TimeAndDay starts`, `TimeAndDay
duration` (both by week minutes), `Activity activity`.

## Activity

`[Serializable] public class Activity` (NPC/Activity.cs). Base of `Act_*`.

| Member | Meaning |
|---|---|
| `activityName`, `priority` (1), `force`, `loop`, `canBeInterrupted` (true) | |
| `bool running` | |
| `Action OnStart`, `OnFinish`, `OnInterupt`, `OnStopped` | |
| `StartActivity(NPCController)`, `UpdateActivity(NPCController)`, `SetNPC` | |
| `InterruptActivity()` | false when `force` or not interruptible; else stops |
| `ForceStopActivity()`, `OnStuck(bool)`, `OnActivity()` (per frame), `FinishActivity()`, `StopActivity()` | |
| `GetFollowTarget()` | Non-null makes NPCDirector treat the NPC as following |
| `GetLocationInfo()`, `InCurrentLevel()`, `GetTargetScene()` | Where the activity happens; its area (used by `HandleNPCChangeScene`) |

Activity classes: Act_Follow, Act_Patrol, Act_Police, Act_Robber,
Act_Sleep, Act_Stand, Act_Tenement, Act_Wander, Act_sit.

## Moving between areas

`NPCSceneUtilities` (NPC/NPCSceneUtilities.cs), static:

| Method | Does |
|---|---|
| `OnFollowingTarget(NPCData, GameObject target)` (11-20) | Target's area = `target.scene.name` (the only place the game reads an object's scene). Different from the NPC's and no path into `ActiveScene` yet: `CalculateNPCTransition(npc, thatScene, state.targetEntrypoint)` |
| `HandleNPCChangeScene(NPCData, bool)` (22-68) | With `activePath` and no progress yet: the area the path puts it in now; else the scheduled activity's `GetTargetScene()`. Different from `currentScene` and the NPC is not in `ActiveScene`: `CalculateNPCTransition` |
| `CalculateNPCTransition(npc, targetScene, targetEntrypoint)` (70-159) | No current scene: `ChangeNPCLevel`. Else `NPCSpawnUtilities.FindPathBetweenScenes`; with a path: walk path to its first door (`NPCPathfinding.SearchForPath`, or a straight line), `activePath`, `timeInLevel = 0`, `SetInterSceneTransit(targetScene, first entryPointEnd, 0.0001)`; no path: `ChangeNPCLevel` |
| `UpdateNPCTransition(npc, deltaSeconds, bool)` (179-306) | Advances `interSceneProgress` by `1.5 m/s * real seconds / path length`; forced to 1 after `timeInLevel > 3600`. At 1: next stage (`currentScene` = that stage's area, `currentEntrypoint`; if it is `ActiveScene`, `ChangeNPCLevel`), or final (`ChangeNPCLevel` into `ActiveScene`, else `currentScene = targetScene`; `ResetTransition`) |
| `ShouldNPCBeInCurrentScene(NPCData)` | Scheduled activity `InCurrentLevel()` |
| `const uint maxTransitionTimeInGameSeconds = 3600` | |

`NPCSpawnUtilities.ChangeNPCLevel(NPCData npc, string levelname)`
(NPC/NPCSpawnUtilities.cs:115-233): returns while a transit is under way.
When `levelname == ActiveScene`: with `activePath`, at the arrival point
`currentEntrypoint` (or the one whose `OtherEntyPoint` matches): no
object -> the arrival point's `Waypoint_LevelChange.OnSpawn(npc)` (door
opens, spawns; spawn marked pending) or `character.Spawn`; with an object
-> moved there and the door opened. Without a path: the area's
`levelChangeWaypoints` entry whose door leads to the NPC's `currentScene`
(else the first), the same way. Then `activePath = null`, `currentScene =
levelname`, `timeInLevel = 0`. Also: `FindPathBetweenScenes(source, target,
entrypoint)`, `GetPointAlongPath(start, end, percent, onResult)` (an A*
path), `FindValidSpawnPosition(...)`, `IsPositionObstructed(...)`.

`Waypoint_LevelChange : Waypoint` (NPC/Waypoint_LevelChange.cs): a door
waypoint, `DoorChangelevel LinkedDoor` (its parent door).

| Method | Does |
|---|---|
| `WaypointChain(dir, npc)` (10-33) | An NPC with an object reaching the door: waits while talked to; `DisableMoving`; `LinkedDoor.OpenDoorNPC(ChangeNPCState, npc)`; `currentEntrypoint = LinkedDoor.OtherEntrypoint`; `ChangeNPCLevel(npc.Data, LinkedDoor.OtherLevel)` |
| `ChangeNPCState(npcToDestroy, npcToSpawn)` (54-66) | Leaving: `activePath = null`, `currentScene = LinkedDoor.OtherLevel`, **destroys the object**. Arriving: `character.Spawn` at the waypoint |
| `OnSpawn(NPCData)` (88-98) | Door opens, then spawn |
| `Start()` / `OnDestroy()` | Add to / remove from `NPCManager.instance.levelChangeWaypoints` |

## With areas kept loaded

`NPCManager` is area-owned (kept-areas.md, rule 1): on entering, its
`instance` is the area's copy, and `ActiveScene` is that copy's cached
name. Leaving an area, the mod records its NPCs with
`NPCData.OnSavingGame()`, calls `scheduler.OnDestroy()` and clears the
cached controller, as destroying the objects would (kept-areas.md,
NPCs); `NPCManager.Start` runs again on later visits so `StartDelay`
reconciles the area's NPCs. Followers: a prefix gives
`OnFollowingTarget` the area the player is in when the follow target is
in another scene (kept_loaded.rs `on_following_target`).

Not checked: `NPCController.UpdatePathToOtherMap` searches door waypoints
in every loaded scene including switched-off ones, by arrival name; a
name shared by two kept areas could send an NPC to the wrong area's door.
