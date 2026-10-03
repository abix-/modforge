# NPCs

> **Authoritative on:** NPC data (Characters.json, NPCBehavior.json),
> the NPC classes, NPCManager.ActiveScene, NPCDirector and NPCs simulated
> as data, the scheduler from timetable to movement, and followers.
> Pathfinding itself: [`pathfinding.md`](pathfinding.md).
>
> Index of every game system's doc: [`research.md`](research.md).

## NPC behavior structure (from NPCBehavior.json)

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

## Character structure (from Characters.json)

Fields: ID, Name, GenderString, Age, Relationship, Job,
FurnitureType, Sprite, Gender (float), Weight, Muscle, Height,
Advanced, ShoulderWidth, HeadSize, FaceSize, NeckLength, BreastSize,
HipWidth, HandSize, FootSize, EyeSize, plus appearance slots
(Glasses, Beard, Hair, Hat, Jacket, etc.).

## NPC classes (NPC namespace)

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

## NPCManager.ActiveScene

A name cached in Start (`activeScene = GetActiveScene()`,
NPCManager.cs:60; empty until then, when it reads the active scene
live). Read by 20 NPC code paths to tell which NPCs are in the player's
area: spawning (info_NPCSpawn, NPCSpawnUtilities), schedules
(Schedule.cs:140), the NPC director (NPCDirector.cs:108-277), scene
utilities, pathfinding between areas (InterScenePathfindingGraph.cs:98,
NPCController.cs:420). `levelChangeWaypoints` holds the area's waypoints
to other areas.

## NPC objects and NPC data

`NPCDirector` (kept through loads) holds every NPC's data
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

## The scheduler, timetable to movement

1. Each NPC's data (`NPCData`, NPCDirector.globalDatabase, kept through
   loads) has a `Schedule`: a `Timetable` of ScheduledActions (start, duration,
   activity with a target area).
2. Every game minute `NPCDirector.DeltaSeconds` (NPCDirector.cs:245-290)
   goes over every NPC: follow target first (OnFollowingTarget), else
   `Schedule.UpdateScheduler` (Schedule.cs:137): an NPC in the player's area
   with an object runs its schedule live (`scheduler.CurrentTime`: picks the
   timetable entry, starts its activity, the object walks); every other NPC
   runs on data (`UpdateScheduleWithoutController`), its area tracked through
   InterScenePathfindingGraph's area connections. Then, for an NPC not in
   the player's area, `NPCSceneUtilities.HandleNPCChangeScene` sets a path
   to the activity's target area (`CalculateNPCTransition`, a timed
   transit with `interSceneProgress`).
3. An NPC with an object leaving the player's area walks to a door
   waypoint; there `Waypoint_LevelChange.ChangeNPCState` sets its
   `currentScene` to the door's other area and destroys the object
   (Waypoint_LevelChange.cs:54-66).
4. An NPC whose data reaches the player's area gets an object:
   `NPCSpawnUtilities.ChangeNPCLevel` (NPCSpawnUtilities.cs:115-) spawns
   it at the arrival point of its entry (through the door waypoint's
   `OnSpawn`, which opens the door), or moves its existing object there.
5. On an area load, `NPCManager.StartDelay` moves or spawns the area's NPCs
   from their data and switches off placed NPCs that are elsewhere
   (NPCManager.cs:64-117).
6. A schedule subscribes to `TimeOfDayAzure.CurrentTimeAndDay` once
   (`started`) and unsubscribes in OnDestroy (Schedule.cs:34-42, 275-278):
   after an NPC's object is destroyed once, its schedule runs only from
   NPCDirector's tick.

## Followers

`NPCSceneUtilities.OnFollowingTarget` (NPCSceneUtilities.cs:11-20) takes
the player's area from the follow target's scene
(`followTarget.scene.name`), the only place the game reads an object's
scene; every game minute it moves a follower towards that scene.
