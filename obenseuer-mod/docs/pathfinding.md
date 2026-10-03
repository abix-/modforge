# Pathfinding

> **Authoritative on:** NPC pathfinding: the A* Pathfinding Project
> objects (`AstarPath`, `RVOSimulator`, `RVOController`), each area's
> navigation file (`info_navigation`), the waypoint graph
> (`WaypointGraph`), paths inside an area and across areas
> (`NPCPathfinding`), and the area connection graph
> (`InterScenePathfindingGraph`). NPC movement that uses them:
> [`npcs.md`](npcs.md).
>
> Index of every game system's doc: [`research.md`](research.md).

## Objects

| Object | Where | One copy |
|---|---|---|
| `AstarPath` (AstarPathfindingProject.dll) | Each area's `__MAIN/info_navigation/Navigation` | `AstarPath.active` (static field) |
| `Pathfinding.RVO.RVOSimulator` | Same object | `RVOSimulator.active` (static property: set in Awake and OnEnable, nulled in OnDestroy; RVOSimulator.cs:30-74) |
| `info_navigation` | Each area's `__MAIN/info_navigation` | private static `instance` |
| `WaypointGraph` | Kept through loads (Awake: first copy `DontDestroyOnLoad`, later copies destroyed) | `instance` |
| `NPCPathfinding` | Kept through loads (same) | `instance` |
| `InterScenePathfindingGraph` | Kept through loads (first copy, others destroyed) | `instance` |

`RVOController.OnEnable` takes the simulator from `RVOSimulator.active`
and adds its agent; with none it logs "No RVOSimulator component found"
and disables itself, whose OnDisable then removes an agent never added
("The agent is not added to this simulation", RVOController.cs:270-301).

## info_navigation

`public class info_navigation : MonoBehaviour`, `[ExecuteInEditMode]`
(info_navigation.cs).

| Member | Meaning |
|---|---|
| `private static info_navigation instance` | |
| `bool load` (true) | Load the area's navigation file |
| `bool scanOnStart` | Scan when not loading |
| `Vector3 boundsCenter`, `BoundsSize` | Recast bounds used by `Save()` |
| `bool loaded` private | Loaded once per object |
| `Awake()`, `OnEnable()` (29-66) | Another live copy -> destroys its own object. Else `Load()` (or `Scan()` when `scanOnStart` and not loading) |
| `Load()` (85-96) | Once: `StartCoroutine(LoadCO(StreamingAssets/NavigationData/<GetActiveScene().name>.nav))` |
| `LoadCO(path)` (98-112) | One frame; file exists and `AstarPath.active.data` set: `AstarPath.active.data.DeserializeGraphs(File.ReadAllBytes(path))` (log "Nav file loaded!"), `WaypointGraph.instance.MapWaypoints()`. Else `Scan()` (log "Nodegraph out of date. Rebuilding...") |
| `static Scan()` (76-83) | `AstarPath.active.Scan()`, `MapWaypoints()` |
| `static Save()` (114-) | Editor: writes the graphs with the recast bounds |

The file is chosen by the **active scene's** name when `Load()` runs.

## WaypointGraph

`public class WaypointGraph : MonoBehaviour` (NPC/WaypointGraph.cs). The
graph of waypoint chains NPCs walk along, joined through the A* graph's
regions.

| Member | Meaning |
|---|---|
| `List<WaypointConnection> waypointMap` | The graph |
| `MapWaypoints()` (321-380) | Rebuilds it under a lock from `FindObjectsOfType<Waypoint>()` (active objects only): each chain start (no previous, has next) -> a `WaypointConnection` to the chain's end; each `Waypoint_LevelChange` with a door -> a connection to the door's `OtherLevel`/`OtherEntrypoint`. Then for each connection and each A* region of its nodes, an `Interconnection` to every other connection sharing that region, with the A* distance (`CalculateDistance`, an `ABPath`) |
| `WaypointConnection` | `ConnectionNode[] waypointNodes` (`waypoint`, `_position`, `GraphNode graphNode`, `regionId`, `penalty`; `ConnectionNodeScene` adds `levelname`, `entrypoint`), `int[] connectsRegions`, `Interconnection[] connectsTo` (`toRegion`, `waypointConnection`, `startNode`, `endNode`, positions, `distance`, `ABPath cachedPath`) |

## NPCPathfinding

`public class NPCPathfinding : MonoBehaviour` (NPC/NPCPathfinding.cs).

| Member | Does |
|---|---|
| `SearchForPath(Vector3 start, Vector3 end, NPCReference npc, Action<Path> callback)` (257-283) | Copies `waypointMap` plus start and end nodes; A* over waypoint connections on a `Task.Run` thread; callback on the main thread |
| `Path SearchForPathSynchronous(start, end, npc)` (285-301) | Same, blocking |
| `SearchForPathToOtherMap(string currentScene, string targetScene, NPCReference npc, Action callback)` (471-492) | A* over `InterScenePathfindingGraph` (`AStarScenes`, connections the NPC may use) on a thread; sets the NPC's `state.activePath`; then `callback` |

`NPCPathfinding.Path` (13-119): `Node[] nodes` (`targetPosition` from its
`Waypoint` or a position, `cost`, `length`, `ABPath cachedPath`),
`currentStage`; `ArriveAtTarget(npc)` advances (a waypoint node enters its
chain, else `npc.ai.destination` and `SearchPath`), `FinishPath` at the
end; `GetPathLength()`.

`NPCPathfinding.InterScenePath` (121-214), saved in `NPCDataState.activePath`:
`Node[] nodes` (`Path pathToDoor`, `levelName`, `entryPointStart`,
`entryPointStartPosition`, `entryPointEnd`, `int distance`),
`currentStage`, `current`, `Scene` (current node's `levelName`).
`string CalculatePosition(name, time, speed, bool)`: `time * speed /
distance >= 1` advances the stage and returns that stage's `levelName`;
else "".

## InterScenePathfindingGraph

`public class InterScenePathfindingGraph : MonoBehaviour`
(NPC/InterScenePathfindingGraph.cs). Which area connects to which, through
which arrival points.

| Member | Meaning |
|---|---|
| `List<SceneConnections> graph` | Read from `Application.dataPath + "/Scenes/Scenegraph.nav"` (FullSerializer JSON) in `LoadGraph()` (79-85), on every Awake and OnEnable |
| `SceneConnections` | `SceneName`, `List<SceneConnection> connections` |
| `SceneConnection` | `otherScene`, `thisEntrypoint`, `thisEntrypointPosition`, `otherEntrypoint`, `cost` (1), `bypassByDefault`, `connectsTo` |
| `GetCurrentConnections()` (96-99) | Connections of `NPCManager.instance.ActiveScene` |
| `GetSceneConnections(string scene)` (101-104) | |
| `FindScenePath(source, target, targetEntrypoint, bool filterBypassByDefault)` (106-176) | Breadth-first search over scenes |
| `GenerateConnections`, `UpdateSceneInGraph`, `DeleteSceneFromGraph`, `SaveGraph` | Editor tools |

## With areas kept loaded

`AstarPath`, `RVOSimulator` and `info_navigation` live in each area's
`__MAIN`; there is one `AstarPath.active` and one `RVOSimulator.active`.
The mod counts `RVOSimulator.active` as a one-copy field
(first_copy_wins). `info_navigation` is area-owned: on entering an area,
before it switches on, the mod loads that area's `.nav` into
`AstarPath.active` with `DeserializeGraphs` and runs `MapWaypoints()`, as
`LoadCO` does, and marks the area's `info_navigation` loaded
(kept-areas.md). **Gap (from the code, not checked live):** `enter_area`
runs `load_navigation` (and so `MapWaypoints`) at kept_loaded.rs:619,
before `switch_area(area, true)` at 626; the area left is already
switched off. `MapWaypoints` uses `FindObjectsOfType<Waypoint>()`, which
skips switched-off objects, so after a kept door the waypoint graph likely
holds none of the entered area's waypoints. In the game `LoadCO` runs
one frame after the area's objects are on. `WaypointGraph`, `NPCPathfinding` and
`InterScenePathfindingGraph` are kept through loads and are not per area.
