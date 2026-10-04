# Building and furniture

> **Authoritative on:** the building system: `BuildingSystem` (the
> player's furniture inventory, placing and taking), build spaces
> (`FurnitureManager`, `BuildingArea`), placed furniture
> (`FurniturePlaceable`, `FurnitureInfo`), how each is saved, and what of
> it is per area.
>
> Index of every game system's doc: [`research.md`](research.md).

## BuildingSystem

`public class BuildingSystem : SavableScript` (BuildingSystem.cs).
Game-wide, in Game_Logic. GUID const "BuildingSystem"; saves into
Globals in the Secondary step.

| Field | Saved | Meaning |
|---|---|---|
| `static BuildingSystem instance` | no | Awake (577-580) |
| `List<FurnitureInfo> availableFurnitures` | yes | Furniture the player carries |
| `List<string> availableFurnituresGUIDS` | yes | "BuildingSystem<n>" ids given to carried furniture objects at save |
| `List<FurnitureInfo> blueprints` | yes | |
| `static FurnitureManager activeManager` | no | The build space the player is in |
| `string activeManagerGUID` | yes | `activeManager.GUID` at save |
| `bool inBuildingArea` | yes | The player is in a build space |
| `List<FurnitureManager> furnitureManagers` | public, not `fsIgnore` (what the serializer writes for it not checked) | Build spaces that ran Start (`FurnitureManager.Start` adds, `OnDestroy` removes) |
| `FurnitureInfo currentFurniture`, `Transform currentPreview`, `rotationMode`, `gridSize` (0.025), `offset` (1), `layersHit` | no | Placement state |
| `Transform inventoryLocation` | no | Parent of carried furniture objects |
| `List<FurnitureAttachmentPoint> attachmentPoints`, `lastAttachmentPoint` | no | Snap points |

| Method | Does |
|---|---|
| `OnSavingGameSecondary()` (507-527) | Gives each carried furniture's object GUID "BuildingSystem<n>", `SavePath()` each; `activeManagerGUID`; writes its entry |
| `OnLoadingGameSecondary()` (529-541) | Reads its entry; `LoadFromPath()` each; `OnLoadingGameDelay` |
| `OnLoadingGameDelay()` (543-567) | After `updateTimeDisabled` clears: `activeManager` = the `furnitureManagers` entry with `activeManagerGUID`; 0.1 s later shows build controls if `inBuildingArea` |
| `OnMapChanging()` (569-575) | Clears `activeManagerGUID`, `activeManager`, `inBuildingArea` |
| `Update()` (582-644) | Menu key while `BuildingArea.currentManager.notFullyExamined` -> warning; leaving a build space cleans up the preview; placement input |
| `Place()` (1386-1511) | Instantiates the furniture prefab **under `activeManager.transform`** (or reparents a carried object there); removes it from the carried list (`RemoveFurniture`) |
| `Take(...)` (983, 1520), `Move()` (1011) | Picks furniture up into `availableFurnitures` |
| `AddFurniture(Furniture, amount, meta)`, `AddFurniture(Furniture, GameObject, out saved, amount, meta)` (1585-1621), `RemoveFurniture(FurnitureInfo, amount, updateMenu)` (1644), `GetFurniture(Furniture, bool)`, `PlayerHasFurniture(Furniture, amount, bool)` | Carried furniture |
| `ToggleMenu()` (676), `ChangeCurrentObject(FurnitureInfo, ItemStack, int)` (752), `StartPreview()` (854), `ShowPreview(RaycastHit)` (1107) | Building UI |
| `UpdateConnectionIndicator()` (699-750) | `FindObjectsOfType<CraftingBase>` / `<CraftingUpgrade>` (active objects only) |

### BuildingSystem.FurnitureInfo

`[Serializable] public class FurnitureInfo` (13-384): one furniture
entry, carried or placed.

| Field | Meaning |
|---|---|
| `Furniture furniture`, `TaskItem taskItem`, `int amount`, `Meta meta`, `ItemStack itemStack` | What it is |
| `GameObject gameObject` (`fsIgnore`) | Its object |
| `string gameObjectGUID`, `bool gameObjectSaved` | Its object's save id |
| `string gameObjectFurnitureManagerGUID` | The build space it was placed in |
| `Vector3 gameObjectPosition`, `Quaternion gameObjectMainRotation`, `gameObjectFurnitureRotation`, `List<string> gameObjectSubGUIDs` | Where and what is inside |
| `SavePath(bool placedItem)` (189-) | Records the above |
| `LoadFromPath(bool placedItem, FurnitureManager currentManager)` (240-) | Re-creates the object: placed items are parented under the `furnitureManagers` entry whose `GUID == gameObjectFurnitureManagerGUID` (**the last match wins**, 313-322); carried items under `inventoryLocation` |
| `Meta` (16-109) | `currentSkin`, `currentAlternativePrefab`, `customImages`; `OnLoadGame()`, `RandomizedMeta`, `CompareMeta`, `Copy` |

## FurnitureManager

`public class FurnitureManager : SavableScript` (FurnitureManager.cs).
One build space; area content; saves into the area's file in the
Tertiary step.

| Field | Saved | Meaning |
|---|---|---|
| `string GUID` | key | Placed furniture's GUIDs are `GUID + index` |
| `bool isActive` | yes | The player was in it |
| `List<FurnitureInfo> placedFurniture` | yes | Furniture the player placed |
| `List<string> placedFurnitureGUIDS` | yes | |
| `preplacedFurniturePrimary`, `preplacedFurnitureSecondary` | no | Furniture placed in the scene (FurniturePlaceable.Start adds) |
| `TaskItem requiredTaskItem` | no | Needed to build here |
| `Relay onEditStarted` | no | |
| `Furniture.BuildingArea area`, `BuildingArea.AreaType areaType` | no | Kind of space |
| `bool managerDisabled`, `notFullyExamined` | no | `BuildMenuDisabled` = either |
| `BuildingArea currentBuildingArea` | no | Zone the player entered through |
| `SoundscapeArea soundscapeArea`, `PlayerShopManager Shop`, `TenementApartmentPrefabs tenementApartmentPrefabs` | no | Links |
| `float NetPower`, `List<FurnitureStats> StatsObjects` | NetPower yes | Power |
| `List<FurnitureInfo> AllFurnitures` | | placed + preplaced |
| `event FurniturePlaced(GameObject)`, `FurnitureTaken(GameObject)` | | |

| Method | Does |
|---|---|
| `Start()` / `OnDestroy()` (201-209) | `BuildingSystem.instance.furnitureManagers.Add(this)` / `.Remove(this)` |
| `OnSavingGameTertiary()` (91-168) | Drops entries whose object is gone, duplicated, or belongs to another manager; renames each placed object's GUID `GUID + n`, removes it from `DestructibleList` (`RemoveFromList`), `SavePath(true)`; writes its entry |
| `OnLoadingGameSecondary()` (170-199) | Reads its entry; `isActive` -> `BuildingSystem.activeManager = this`; `LoadFromPath(true, this)` each placed entry; `LoadDone` |
| `GetFurnitureFromGUID(string)` (211-) | Placed or preplaced furniture by GUID |
| `ContainsFurniture`, `ContainsFurnitureGameObject`, `RemovePlacedFurniture`, `RemovePreplacedFurniture` | |

## BuildingArea

`public class BuildingArea : MonoBehaviour` (BuildingArea.cs). Enter/exit
zone of a build space; layer 25 (Start).

| Member | Does |
|---|---|
| `bool isEnter`, `isExit` | Zone kind |
| `AreaType areaType` (Default, RemoveOnly) | |
| `FurnitureManager furnitureManager` | Its build space |
| `static FurnitureManager currentManager` | Last build space entered; never cleared on an area change |
| `OnTriggerEnter(Collider)` (30-43) | Player layer 10: `Enter()` or `Exit()` |
| `Enter()` (45-) | Requires `requiredTaskItem`; sets `currentManager`, `furnitureManager.currentBuildingArea`; switched-off or disabled manager -> `Exit()` and a tutorial; else `BuildingSystem.activeManager = furnitureManager`, `isActive = true`, `inBuildingArea = true`, previous manager `isActive = false`, tutorials and controls |
| `Exit()` (128-) | `inBuildingArea = false`, manager `isActive = false`, `activeManager = null`, menus closed, preview destroyed |
| `IsCurrentManager()` | `currentManager == furnitureManager` |

## FurniturePlaceable

`public class FurniturePlaceable : SavableScript` (FurniturePlaceable.cs).
On every furniture object. Saves with `SerializeData(this, global)` in
the LatePrimary step.

| Field | Saved | Meaning |
|---|---|---|
| `string GUID` | key | |
| `Furniture furniture`, `Meta meta` | yes | |
| `FurnitureManager manager`, `string managerGUID` | managerGUID | Its build space |
| `FurniturePlaceable parent`, `string parentGUID`; `childFurnitureGUIDs`; `attachedto`, `attachedtoGUID`; `attachedFurnitureGUIDs` | GUIDs | Stacking and attaching |
| `bool isPreplacedFurniture`, `preplacedFurnitureSecondary`, `dontAddToPreplacedFurnitureList`, `cantTake`, `decal`, `disableChildPlacement`, `disableSaving` | | |
| `ItemReference itemRequired` | | Needed to take |
| `Relay onTaken`, `onAttached`, `onAttachedTaken` | | |

| Method | Does |
|---|---|
| `OnSavingGameLatePrimary()` (140-175) | Records `managerGUID`, `parentGUID`, child and attached GUIDs |
| `OnLoadingGameLatePrimary()` (177-199) | Reads its entry; not a carried object: `OnLoadDelay` |
| `OnLoadDelay(bool)` (201-267) | 0.05 s: `manager` = the `furnitureManagers` entry with `managerGUID`; links parent, attached, children by GUID through the manager |
| `Start()` (286-306) | Preplaced furniture adds itself to its manager's preplaced list |
| `OnDestroy()` -> `Destroyed()` (308-331) | Removes itself from the manager; adds its GUID to `DestructibleList.instance.DestroyedGuids` |
| `Take(...)` (373), `CanTake(bool)` (509), `CanTakeItem(bool)`, `UseItem()`, `SetFurnitureInfo(info, manager)` (351) | |

## Per area, in the game

`BuildingSystem` is rebuilt by every load (Game_Logic), so
`furnitureManagers` holds the loaded area's build spaces only, and
GUID lookups in it (`FurnitureInfo.LoadFromPath`,
`FurniturePlaceable.OnLoadDelay`) find only that area's.

## With areas kept loaded

- `furnitureManagers` holds the build spaces of every kept area entered.
  If two areas' managers share a GUID, furniture loaded on a first visit
  can be parented under the other area's manager (last match wins); not
  measured (todo).
- The build space the player is in: the door runs `OnMapChanging` (rule
  3), clearing `activeManager`. On a later visit FurnitureManager's load
  step is skipped (it creates objects), so the mod does its `isActive`
  part only: the area's manager saved as active becomes `activeManager`
  (`build_space_again`, kept_loaded.rs). `BuildingArea.currentManager` is
  never cleared, as in the game.
- Checked by `research_kept_scenario.rs` after every door (2026-10-04):
  `activeManager` is the area's FurnitureManager with `isActive`, or none
  (Interior Player Tenement: 23 build spaces, one active, on the first and
  the later visit; Open Sewer Tenement and Under Map: none).
- `UpdateConnectionIndicator` searches active objects only: the same as
  the game.
