# The map

> **Authoritative on:** the in-game map: the area's map (info_map),
> MapController's map records and landmarks, and the map panel.
>
> Index of every game system's doc: [`research.md`](research.md).

## The map (2026-10-03, from the code)

The area's map is `info_map` (area content; its `mapImage`,
`requiredTaskItem`, `GetRelativePosition`). `MapController` (a game-wide
manager in Game_Logic, saves into Globals) keeps a map record per map id
(`mapInfos`) and the current one (`currentSceneMapInfo`, the area's
landmarks), set only in its Start and in OnLoadingGame's delayed step
(GetCurrentSceneMap, MapController.cs:102-171; id from info_map.instance,
196-211); `AddLandMark` adds a discovered landmark to `currentSceneMapInfo`
(173-193). The map panel `Map` sets its image from info_map only in Start
(Map.cs:73-88); its player marker reads info_map live
(`UpdatePlayerMarker`, 128-139). In the game both run on every area load.
