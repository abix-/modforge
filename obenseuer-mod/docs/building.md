# Building and furniture

> **Authoritative on:** the building system (BuildingSystem, build spaces
> as FurnitureManager and BuildingArea, placed furniture) and what of it
> is per area.
>
> Index of every game system's doc: [`research.md`](research.md).

## Per area (2026-10-03, from the code)

BuildingSystem is game-wide (saves into Globals, BuildingSystem.cs:
507-541). Each area's build space is a `FurnitureManager` (area content,
saves per area): it adds itself to `BuildingSystem.furnitureManagers` in
Start and removes itself in OnDestroy (FurnitureManager.cs:201-209), so
in the game the list holds the current area's managers only. Placed
furniture finds its manager in that list by GUID: when loaded
(FurnitureInfo.LoadFromPath, BuildingSystem.cs:313-322, the last match
wins) and after load (FurniturePlaceable.OnLoadDelay,
FurniturePlaceable.cs:201-215). With kept areas the list holds the
managers of every kept area; if two areas' managers share a GUID,
furniture loaded on a first visit can go under the other area's manager
(not measured).

- The build space the player is in: `BuildingSystem.activeManager` is set
  by walking into a `BuildingArea` (BuildingArea.cs:45-80) and on load from
  the manager's saved `isActive` (FurnitureManager.cs:170-178), and
  cleared with `inBuildingArea` by OnMapChanging (BuildingSystem.cs:569-575).
  `BuildingArea.currentManager` (static) is never cleared on an area
  change. With kept areas the door runs OnMapChanging (kept-areas.md,
  rule 3) but the load steps only on a first visit, so on a later visit
  `activeManager` comes back only by walking into the build space.
- Connection indicators look up `FindObjectsOfType<CraftingBase>` and
  `<CraftingUpgrade>` (BuildingSystem.cs:721, 732), which skip switched-off
  objects: the same as the game with kept areas.
