# Pathfinding

> **Authoritative on:** NPC pathfinding: AstarPathfindingProject (AstarPath,
> RVOSimulator, RVOController) and each area's navigation file
> (info_navigation). NPC movement between areas: [`npcs.md`](npcs.md).
>
> Index of every game system's doc: [`research.md`](research.md).

## AstarPathfindingProject.dll

`AstarPath.active` (field) and `Pathfinding.RVO.RVOSimulator.active`
(property, set in Awake and OnEnable, nulled in OnDestroy;
RVOSimulator.cs:30-74). `RVOController.OnEnable` takes the simulator
from `RVOSimulator.active` and adds its agent; with none it logs "No
RVOSimulator component found" and disables itself, whose OnDisable then
removes an agent never added ("The agent is not added to this
simulation", RVOController.cs:270-301). AstarPath and RVOSimulator sit
in each area's `__MAIN` ([`areas.md`](areas.md)).

## The area's navigation (info_navigation)

`info_navigation` (private static `instance`) loads its area's
navigation file `StreamingAssets/NavigationData/<active scene>.nav` into
the one pathfinder (`AstarPath.active.data.DeserializeGraphs`) and maps
the waypoints, once per object (`loaded`), from Awake and OnEnable; a
second copy destroys itself (info_navigation.cs:29-111).
