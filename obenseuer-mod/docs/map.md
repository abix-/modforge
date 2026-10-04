# The map

> **Authoritative on:** the in-game map: how an area's map is defined,
> how discovered landmarks are recorded and saved, how the map panel
> draws the map, the player marker and landmarks, and how the explored
> (revealed) part of the map is saved. Every class, field and method the
> map uses, with file:line in the decompiled Assembly-CSharp.
>
> Index of every game system's doc: [`research.md`](research.md).

## How it fits together

- Each area that has a map holds one `info_map` (under `__MAIN`). It
  defines the map: the image, the world area it covers, and an optional
  task item the player must own to see it.
- `MapController` (game-wide, saves into Globals) keeps the record of
  discovered landmarks, one `MapInfo` per map, keyed by the map id.
- A landmark is a `Landmark` asset. It is discovered by walking into a
  `LandmarkTrigger` in the area, or by a call to `Landmark.GiveLandmark()`
  (for example from a relay or dialogue).
- `Map` is the map panel's UI. It draws the area's map image, one marker
  per discovered landmark, and the player marker, positioned with
  `info_map.GetRelativePosition`.
- `RevealCamera` renders the explored part of the map into the area's
  `info_map.renderTexture` and saves it as a PNG in the save folder.

All of these read the area's map through `info_map.instance`, set in
`info_map.Awake`.

## The map id

`MapController.GetCurrentMapId()` (MapController.cs:196-211), private:

| `info_map.instance` | Map id |
|---|---|
| null | `""` (no map) |
| has `requiredTaskItem` | `requiredTaskItem.Id` |
| else has `mapImage` | `mapImage.name` |
| else | `""` |

Landmark records are kept per map id, not per area: two areas whose
`info_map` gives the same id share one record.

## info_map

`public class info_map : MonoBehaviour`, `[ExecuteInEditMode]`
(info_map.cs). One per area that has a map, at `__MAIN/info_map`
([`areas.md`](areas.md)). Not saved.

| Field | Type | Meaning |
|---|---|---|
| `instance` | `static info_map` | The area's map. Set in Awake (25-28); never cleared |
| `mapImage` | `Sprite` | The map picture. Its name is the map id when there is no `requiredTaskItem` |
| `revealingMaterial` | `Material` | Material that shows only the explored part; with it, the panel shows the reveal layer |
| `renderTexture` | `RenderTexture` | Target `RevealCamera` draws the explored part into; its name names the PNG in the save folder |
| `mapRadius` | `float`, default 100 | World size the map covers, in metres, centred on this object |
| `requiredTaskItem` | `TaskItem` | The player must own it to open the map (MapPanel); its `Id` is the map id |
| `resolution` | `int`, default 1024 | Editor screenshot size; not used in play |

| Method | Does |
|---|---|
| `Vector3 GetRelativePosition(Vector3 position)` (38-41) | `transform.InverseTransformPoint(position) / mapRadius`: a world position as a fraction of the map, x and z used. Every map position goes through it |
| `Awake()` (25-28) | `instance = this` |
| `Start()` (30-36) | Editor screenshot only; does nothing in play (`_takeScreenshot` false) |

Readers of `info_map.instance`: MapController.GetCurrentMapId, Map.Start,
Map.UpdatePlayerMarker, Map.AddLandmark, MapPanel.OnEnable,
RevealCamera.Start, OnSavingFile and OnLoadingGame.

## MapController

`public class MapController : SavableScript` (MapController.cs). Game-wide
manager in Game_Logic. GUID "MapController" (80). Saves into Globals:
`SerializeData(this, global: true)` in OnSavingGame (97-100).

| Field | Type | Saved | Meaning |
|---|---|---|---|
| `instance` | `static MapController` | no | Set in Awake (128-131) |
| `mapInfos` | `List<MapInfo>` | yes | Every map's discovered landmarks, one entry per map id |
| `currentSceneMapInfo` | `MapInfo` | no (`fsIgnore`) | The entry for the current map id. Set only by `GetCurrentSceneMap` |
| `map` | `Map` | no | The map panel, set in the scene |
| `loadingMap` | `bool` | no | True from OnLoadingGame until its delayed step ends; LandmarkTrigger waits on it |

| Method | Does |
|---|---|
| `void GetCurrentSceneMap()` private (147-171) | Finds the `mapInfos` entry whose `taskItemId` is the current map id, or adds a new one; sets `currentSceneMapInfo`; loads its landmark assets (`MapInfo.LoadFromPath`). Does nothing when the map id is `""` (leaves `currentSceneMapInfo` as it was) |
| `bool AddLandMark(Landmark landmark, Vector3 position, bool showNotification = true)` (173-194) | Returns false when the map id is `""` or the landmark is already in `currentSceneMapInfo`. Else adds a `LandmarkInfo` to `currentSceneMapInfo` and returns `map.AddLandmark(...)`. Calls `GetCurrentSceneMap` first only when `currentSceneMapInfo` is null |
| `string GetCurrentMapId()` private (196-211) | The map id (table above) |
| `Start()` (133-145) | `GetCurrentSceneMap`, then puts every recorded landmark of the current map on the panel (`map.AddLandmark`, no notification) |
| `OnLoadingGame()` (102-111) | Reads its Globals entry, sets `loadingMap`, starts `OnLoadingGameDelay` |
| `OnLoadingGameDelay()` (113-126) | After 0.7 s real time: `GetCurrentSceneMap`, puts the current map's landmarks on the panel, clears `loadingMap` |

Note: `currentSceneMapInfo` follows the current map only when Start or
OnLoadingGame runs. In the game both run on every area load, since
MapController is rebuilt with each area ([`areas.md`](areas.md)).

### MapController.MapInfo

`[Serializable] public class MapInfo` (10-29): one map's record.

| Member | Meaning |
|---|---|
| `string taskItemId` | The map id this record belongs to |
| `List<LandmarkInfo> landmarkInfos` | Landmarks discovered on this map |
| `bool Contains(string id)` | A landmark with this `Landmark.id` is recorded |
| `void LoadFromPath()` | Replaces each saved landmark reference with the loaded asset |

### MapController.LandmarkInfo

`[Serializable] public class LandmarkInfo` (31-76): one discovered
landmark.

| Member | Meaning |
|---|---|
| `Landmark landmark` | The landmark asset |
| `Vector3 position` | World position: the landmark's own `position` if not zero, else the position given when discovered (constructor, 45-56) |
| `List<string> pointsOfInterest` | Text lines; empty when created (the landmark's `startPointsOfInterest` are not copied here) |
| `Vector3 GetPosition()` | `position`, or `landmark.position` when `position` is zero |
| `void OnLoad()` | Replaces the saved landmark reference with the loaded asset |
| `string GetLandmarkDetails()` | The points of interest joined with the literal text `/n` (not a newline) |

## Landmark

`[CreateAssetMenu] public class Landmark : SavableScriptableObject`
(Landmark.cs). An asset; nothing in it is saved (every field `fsIgnore`).

| Field | Type | Meaning |
|---|---|---|
| `id` | `string` | Unique id; what `MapInfo.Contains` compares |
| `title` | `string` | Shown in the "Discovered" notification |
| `priority` | `int` | Draw order on the map: larger is on top |
| `image` | `Sprite` | Icon |
| `position` | `Vector3` | Fixed world position; zero means "where it was discovered" |
| `startPointsOfInterest` | `List<string>` | Not read by the map classes |
| `width`, `height` | `int` | Not read by the map classes |

| Method | Does |
|---|---|
| `void GiveLandmark()` (33-36) | `MapController.instance.AddLandMark(this, position)`, with notification. For calls from relays and dialogue; no caller in code |

## LandmarkTrigger

`public class LandmarkTrigger : SavableScript` (LandmarkTrigger.cs). A
trigger zone in an area. Saves into the area's file
(`SerializeData(this)`, 21-29); saved field: `triggered`.

| Member | Does |
|---|---|
| `Landmark landmark` | The landmark it gives |
| `Transform landmarkPosition` | Where the landmark goes; this object's position when null (`GetPosition`, 62-69) |
| `bool triggered` (saved) | Set when the landmark was added |
| `OnTriggerEnter(Collider)` (31-37) | On the Player tag, while enabled: starts `AddLandMarkDelay` |
| `AddLandMarkDelay()` (39-52) | Waits two end-of-frames. If `MapController.loadingMap`: waits 0.8 s and adds (even when `triggered`). Else adds only when not `triggered` |
| `void AddLandMark(bool showNotification = true)` (54-60) | `MapController.instance.AddLandMark(landmark, GetPosition(), showNotification)`; sets `triggered` when it returns true |

## Map (the map panel)

`public class Map : MonoBehaviour, IScrollHandler` (Map.cs). The map UI.
Not saved.

| Field | Type | Meaning |
|---|---|---|
| `instance` | `static Map` | Set in Awake (96-102), Start (73-75) and `SetInstance()` |
| `mapImage` | `Image` | Shows `info_map.mapImage` |
| `revealingImage` | `RawImage` | The reveal layer; switched on with `info_map.revealingMaterial` |
| `landmarks` | `List<GameObject>` | Landmark markers, sorted by priority |
| `selectedLandmarks` | `List<bool>` | One per marker; which one is selected |
| `playerMarker` | `GameObject` | The player arrow; switched off when the area has no map image |
| `mapsize` | `RectTransform` | Size the relative positions are scaled to |
| `zoomSpeed`, `maxZoom` | `float`, 0.5 and 5 | Zoom step and limit |

| Method | Does |
|---|---|
| `Start()` (73-94) | Sets `mapImage.sprite` from `info_map.mapImage` and the reveal layer from `revealingMaterial`; with no `info_map` or no image, switches the player marker off. Hides the map when `info_game_logic.hideMainMap`. Runs once: the image does not change after |
| `OnEnable()` (121-124) | `PlayerMarker.instance.FindMap()` |
| `void UpdatePlayerMarker(Transform playerTransform)` (126-139) | Places and turns the player arrow from the player's position through `info_map.GetRelativePosition`. Reads `info_map.instance` on every call |
| `bool AddLandmark(LandmarkInfo landmark, Vector3 position, bool showNotification = true)` (141-172) | False when the area has no map image. Else creates a marker from `LandmarkPrefab`, inserts it by priority, places it through `GetRelativePosition`, and shows the "Discovered" notification when asked. Markers are never removed |
| `HideMainMap()`, `ShowMainMap()` (109-119) | Hide or show the image and zoom buttons |
| `OnScroll`, `ZoomButton(bool minus)`, `ZoomSlider(float)` (174-209) | Zoom; `ZoomButton` is called by InventoryNavigationHandler.cs:1327-1347 (controller input) |
| `ChangeStatus(int num)` (239-250) | Selects one landmark marker; called by LandmarkUI |

## PlayerMarker

`public class PlayerMarker : MonoBehaviour` (PlayerMarker.cs). On the
player.

| Member | Does |
|---|---|
| `static PlayerMarker instance` | Set in Start (11-14) |
| `FindMap()` (16-20) | Takes `Map.instance`; called by `Map.OnEnable` |
| `Update()` (22-28) | Every frame while the map panel is on: `map.UpdatePlayerMarker(transform)` |

## MapPanel

`public class MapPanel : MonoBehaviour` (MapPanel.cs). The map page of the
game menu.

| Member | Does |
|---|---|
| `OnEnable()` (8-23) | Switches the map on, then off again when there is no `info_map`, when the player lacks `requiredTaskItem` (`TaskItemsManager.CheckIfPlayerHasTaskItem`), or when there is no map image. Checked every time the page opens |

## RevealCamera

`public class RevealCamera : SavableScript` (RevealCamera.cs). Draws the
explored part of the map.

| Member | Does |
|---|---|
| `Start()` (48-60) | When `info_map` has a map image, `revealingMaterial` and `renderTexture`: creates the reveal camera from `revealCameraPrefab`, unparented, 1000 m above `info_map`, looking down, orthographic size `mapRadius / 2`, drawing into `info_map.renderTexture`; sets `hasSaveableData` |
| `OnSavingFile()` (14-30) | When `hasSaveableData`: writes `info_map.renderTexture` to `<save folder>/<renderTexture.name>.png` |
| `OnLoadingGame()` (32-46) | When `hasSaveableData`: reads that PNG back into `info_map.renderTexture` |

The PNG is named after the render texture, so each map's reveal is its own
file in the save folder. `hasSaveableData` is set in Start, which runs
before the load steps on a load ([`doors.md`](doors.md)).

## Flows

Opening the map page: `MapPanel.OnEnable` checks the map exists and the
player owns `requiredTaskItem` -> `Map.OnEnable` -> `PlayerMarker.FindMap`
-> `PlayerMarker.Update` moves the arrow every frame.

Walking into a landmark zone: `LandmarkTrigger.OnTriggerEnter` -> two
frames -> `LandmarkTrigger.AddLandMark` -> `MapController.AddLandMark`
(record in `currentSceneMapInfo`) -> `Map.AddLandmark` (marker,
"Discovered" notification) -> `triggered = true`, saved in the area's file.

Loading an area (the game's load, [`doors.md`](doors.md)):
`info_map.Awake` sets the area's map -> Start: `Map.Start` sets the image,
`MapController.Start` picks the map's record and adds its markers,
`RevealCamera.Start` makes the reveal camera -> load steps:
`MapController.OnLoadingGame` reads the saved records and, 0.7 s later,
picks the map's record and adds its markers again, `RevealCamera
.OnLoadingGame` reads the explored PNG.

## With areas kept loaded

- `info_map` is area-owned (kept-areas.md, rule 1): entering a kept area
  points `info_map.instance` at its copy, so everything that reads it live
  follows the area: `UpdatePlayerMarker`, `AddLandmark` placement,
  `MapPanel`, `GetCurrentMapId`. An area without one (Under Map) leaves it
  empty, as in the game; an area loaded alongside never takes it
  (FirstCopyGuard.Newcomer).
- `MapController.currentSceneMapInfo` and `Map.Start` (the image) run only
  in Start and OnLoadingGame, which do not run again on a kept door. So on
  every kept door the mod sets the panel back to a fresh one (markers
  destroyed, reveal layer off, player arrow on, map shown) and runs
  `Map.Start` and `MapController.Start` again (`map_again`, kept_loaded.rs).
  The reveal layer off and the arrow on are assumed to be the panel's
  starting state, not read from the game.
- Checked by `research_kept_scenario.rs` after every door (2026-10-04): the
  panel's image and MapController's record are the area's map, and the
  panel's markers equal the record's landmarks (21 and 21 in Interior
  Player Tenement and Open Sewer Tenement, which share the Tenement Map;
  "none" in Under Map). Two areas with different map images not checked
  yet.
- Measured by `research_map.rs` (2026-10-04): Interior Player Tenement,
  Interior Tenement B and Open Sewer Tenement share map_tenement_001 (task
  item Tenement Map, radius 200); Under Map has no info_map. After a
  normal load in the player's tenement the panel held 28 markers for a
  record of 21: not checked whether the game does the same with kept
  areas off (todo).
- `RevealCamera.Start` runs once per area load. Its camera is made a top
  object of the area's scene (`parent = null`); whether it switches off
  with its kept area,
  or keeps drawing into that area's render texture while away, is not
  checked.
