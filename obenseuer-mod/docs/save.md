# The save system

> **Authoritative on:** `SaveController` (saving, loading, the save
> files, the save and load steps and how they are called, how saved
> fields are written back), `SavableScript`, which scripts save player
> state, `DestructibleList`, and the load steps that create objects.
> The door's use of these: [`doors.md`](doors.md).
>
> Index of every game system's doc: [`research.md`](research.md).

## Files

Folder: `Application.persistentDataPath + "/Saves/" + CharacterName + "/" + SaveName`
(`GetCurrentSavePath()`, SaveController.cs:935-942). `CharacterName` =
`SanitizeCharacterName(PlayerIdentity.identity.firstName, lastName)`:
`first_last` with non-word characters removed, "Esko_Virtanen" when
empty (486-509). `SaveName`: the name with non-word characters removed,
"Autosave" when empty (429-436).

| File | Content |
|---|---|
| `Info.tnmt` | `SaveDataHeader` with no data: SaveName, LevelName (= the destination on a door), NewlevelEntrypoint, CharacterName, Date, ApplicationVersion |
| `Globals.tnmt` | `SaveDataHeader` with every global entry; its `LevelName` and `NewlevelEntrypoint` decide where a load goes |
| `<LevelName>.tnmt` | `SaveDataHeader` with the active area's entries; `LevelName` = the active scene |
| `Globals.dialogue` | `PersistentDataManager.GetSaveData()` (Dialogue System) |
| `<renderTexture>.png` | Explored map, per map ([`map.md`](map.md)) |

Format: FullSerializer JSON (`Serialize`: `fsJsonPrinter.CompressedJson`,
1107-1111), written with `File.WriteAllText(path, content, UTF8)` (UTF-8
with a byte order mark; 537-547).

Types (SaveController.cs:53-94): `ObjectDataHeader { string GUID;
UnityEngine.Object Data }` (the live object, serialized at write time);
`SaveDataHeader { SaveName, LevelName, NewlevelEntrypoint, CharacterName,
DateTime Date, ApplicationVersion, List<ObjectDataHeader> Data }`.

## Static state

| Member | Meaning |
|---|---|
| `instance` | Kept through loads (Awake, 233-246) |
| `LevelName`, `SaveName`, `CharacterName` | private static |
| `LastSaveFolderPath` | public static; the folder last loaded |
| `tempSavedata_Global`, `tempSavedata_Level` | `List<ObjectDataHeader>`: filled by `SerializeData` while saving; filled from the files and emptied by `DeSerializeData` while loading |
| `Guids` | `Dictionary<string, Object>`: every object restored by `DeSerializeData`, by GUID; cleared at the start of a scene load |
| `DontDestroyOnLoadObjects` | `List<GameObject>`: the kept-through-loads objects the Special steps run on. Only `Achievements` (Achievements.cs:347-349) and `NPCDirector` (NPCDirector.cs:143-145) add themselves |
| `Loading` | `bool`, public get. Set true by `ChangeLevelWhenReady` and `LoadGameWithMigration`; `LoadGameWithMigration` sets it **false right after starting the scene load coroutine** (1381), so it is false while the scene loads |

Events (static, 221-231): `PlayerWillChangeLevel`, `PlayerWillLoadGame`,
`SavingStarted`, `SavingDone`, `LoadingStarted`, `LoadingDone`.

## SavableScript

`public class SavableScript : MonoBehaviour` (SavableScript.cs). Every
step is `public virtual bool`, default `return true`:

`OnMapChanging`, `OnSavingGamePrimary`, `OnSavingGameSecondary`,
`OnSavingGameTertiary`, `OnSavingGameDestructibleList`,
`OnSavingGameSpecial`, `OnSavingGame`, `OnSavingGameLatePrimary`,
`OnSavingFile`, `OnLoadingGamePrimary`, `OnLoadingGameSecondary`,
`OnLoadingGameTertiary`, `OnLoadingGameSpecial`,
`OnLoadingGameDestructibleList`, `OnLoadingGameDestructibleListCheck`,
`OnLoadingGame`, `OnLoadingGameLatePrimary`, `OnMapChanged`.

`OnLoadingGameDestructibleListCheck()` default (114-129): destroys its
game object when its public `GUID` field is in
`DestructibleList.instance.DestroyedGuids`.

`SavableObjectReference` (8-42): `[fsProperty] string GUID`; `GetObject<T>()`
finds the object by GUID with `SaveController.GetObjectByGUID(GUID, T)`
(`FindObjectsOfType`, active objects only) and caches it.

## Calling a step

`ExecuteSaveLoadFunctions(GameObject[] roots, LoadSaveType step, bool includeInactive = false)`
(1113-1122): for each root with no parent, `ExecuteChildSaveLoadFunctions`.

`ExecuteChildSaveLoadFunctions` (1124-1198): every `SavableScript` in
the root's children (`GetComponentsInChildren(includeInactive)`), in
hierarchy order; calls the step only when
`component.gameObject.activeInHierarchy`. So `includeInactive: true` has
no effect: switched-off objects are always skipped. A disabled component
on an active object is called. Exceptions are logged per component.

`ExecuteDontDestroyOnLoadSaveLoadFunctions(step)` (1200-1203): the same
on `DontDestroyOnLoadObjects`.

## Writing an entry

`public static bool SerializeData(Object data, bool global = false)`
(549-595): reads the public field or const named `GUID`
(`GetType().GetField("GUID")`); empty or missing: returns false, nothing
saved. Else adds `new ObjectDataHeader(data, GUID)` to
`tempSavedata_Global` or `tempSavedata_Level`. The object is serialized
when the file is written, later in `SaveGame`.

## Reading an entry back

`public static bool DeSerializeData(Object data, bool global = false)`
(707-766): finds the first entry in the matching temp list with the
object's `GUID`, copies its fields into the object (`ReplaceProperties`),
records it in `Guids`, **removes the entry from the list**, returns
true. Not found: false. A second object with the same GUID gets nothing.

`ReplaceProperties(original, replacement)` (768-778): only when both
have the same type. For each instance field (public and non-public)
`ReplaceProperty` (780-838):

| Field | Copied |
|---|---|
| `[fsIgnore]` | no |
| private, no `[fsProperty]` | no (a private `[SerializeField]` is not restored) |
| private with `[fsProperty]` | yes |
| public | yes, by value (reference replaced) |
| `[fsCheckChildFields]` | field by field into the existing value; arrays element by element up to the shorter length (`SetArrayField`, 840-883), same rules per field (`SetChildFields`, 885-) |

The serializer (FullSerializer) decides what is written; these rules
decide what is put back.

## SaveGame

`public static void SaveGame(string savename = "", string newLevel = "", string newLevelEntrypoint = "NONE")`
(416-484):

1. `SavingUI` shown; `instance.keepThis = true`.
2. `SaveName`, `CharacterName` set; `LevelName = GetActiveScene().name`.
3. `newLevel` given (a level change): `OnMapChanging` on the active
   scene's roots and on `DontDestroyOnLoadObjects`. Else `newLevel =
   LevelName`.
4. New temp lists; `SavingStarted`.
5. On the active scene's roots: `OnSavingGamePrimary`, `Secondary`,
   `Tertiary`; `DestructibleList.instance.OnSavingGameDestructibleList()`;
   `OnSavingGameSpecial` on `DontDestroyOnLoadObjects`; `OnSavingGame`,
   `OnSavingGameLatePrimary` on the roots.
6. Serialize the three headers (Info, Globals, the level).
7. Folder: if it exists and is not `LastSaveFolderPath`, deleted; created;
   if `LastSaveFolderPath` is set and different, **copied into it**
   (`CopyDirectory`, 511-535), so areas not visited keep their files.
8. Write `Info.tnmt`, `Globals.tnmt`, `<LevelName>.tnmt`,
   `Globals.dialogue`.
9. `OnSavingFile` on the roots; `SavingDone`; SavingUI hidden.

Callers: `ChangeLevelDelay` and `ChangeLevelSame` (doors, autosave slot),
`AutosaveDelay` (`SaveController.Autosave(mono)`: from
`logic_autosave` and `TriggerAutosave`; full-screen saving UI), the load
menu's save slot (`LoadMenu.Save`, LoadMenu.cs:550-554).

## LoadGameWithMigration

`public static IEnumerator LoadGameWithMigration(string characterName = "", string saveName = "", bool fromMenu = false)`
(1205-1393). Started by the load menu (`fromMenu: true`, LoadMenu.cs:539)
and by every level change.

1. Sets `CharacterName`, `SaveName`; `PlayerWillLoadGame`; `Loading = true`;
   new temp lists.
2. Folder: `persistentDataPath/Saves/<character>/<save>` when it holds
   `Globals.tnmt`, else the path as given. Missing: logs, `Loading =
   false`, fades out, ends.
3. `LastSaveFolderPath` = the folder. Reads `Globals.tnmt`; on a parse
   error runs `Migrate` (1409-); `MigrationController.RunMigrations` (empty
   in this version). `tempSavedata_Global` = its data. `playerLevel`,
   `entrypoint` from the Globals header.
4. Reads `<playerLevel>.tnmt` if it exists (log "Player been in this level
   before, loading data!"); migration as above; a failed migration resets
   the area (notification "Save data corrupted"). `tempSavedata_Level` =
   its data or empty.
5. Reads `Globals.dialogue`; for saves older than 0.3.40 renames actor
   keys.
6. Fades in if not fading. `PersistentDataManager.LevelWillBeUnloaded()`;
   starts `LoadSaveGameDifferentScene(playerLevel, fromMenu, dialogueData,
   entrypoint)` (the same for the same level). Scene missing from the
   build: logs, fades out.
7. `Loading = false`.

## LoadSaveGameDifferentScene

(618-666): the scene load (single mode), `LoadingStarted`, the load
steps on the new active scene's roots, OnMapChanged, the move to the
arrival point, dialogue data, `LoadingDone`. Step by step:
[`doors.md`](doors.md), SaveController.ChangeLevel.

Load step order: `OnLoadingGamePrimary`, `Secondary`, `Tertiary` (roots);
`OnLoadingGameSpecial` (`DontDestroyOnLoadObjects`);
`DestructibleList.instance.OnLoadingGameDestructibleList()`;
`OnLoadingGameDestructibleListCheck` (roots); next frame; `OnLoadingGame`,
`OnLoadingGameLatePrimary`, `OnLoadingGameDestructibleListCheck` (roots);
`OnMapChanged` (roots, when the level changed or an entrypoint is given).

Measured (temporary prefixes, one save load, 2026-10-02): the area's
objects run Start one frame before the load steps:

```text
save load begins at frame 17868
load phase pass at frame 18794; Relay.Start so far 105 (first at frame 18793)
load phase pass at frame 18795; Relay.Start so far 189 (first at frame 18793)
```

## DestructibleList

`public class DestructibleList : SavableScript` (DestructibleList.cs). One
per area, in Game_Logic (`Other/LoadSavegame`). `GUID` const
"DestructibleList"; saves into the area's file. Called directly by
`SaveGame` and the load, not through the step walk.

| Member | Meaning |
|---|---|
| `static DestructibleList instance` | Set in Awake (88-92), which also resets `Collectible.allCollectibles`; OnDestroy resets it again (139-142) |
| `List<string> DestroyedGuids` (saved) | Map objects destroyed; each `SavableScript` whose `GUID` is listed destroys itself in `OnLoadingGameDestructibleListCheck` |
| `[fsProperty] List<InstantiatedPrefab> prefabs` (saved) | Items spawned or dropped at run time |
| `OnSavingGameDestructibleList()` (27-45) | Drops entries whose object is gone or not `activeInHierarchy`; records position (`setpos`) and sets each `InstantiatedPrefabRef` data key "DestructibleList<n>"; writes its entry |
| `OnLoadingGameDestructibleList()` (47-72) | Reads its entry; for each prefab: `Resources.Load(PrefabPath)`, `Instantiate(prefab, pos, rot)` (no parent: into the active scene), scale, `InstantiatedPrefabRef.ApplyData`, adds the ref; 2 frames later parents it under the object with `parentGUID` (`GetObjectByGUID`) |
| `SpawnItem(GameObject GO, string prefabfolder = "Prefabs/Items/")` (94-109) | Registers a run-time item: adds `InstantiatedPrefabRef`, resolves its prefab path from the name, adds to `prefabs` |
| `DestroySpawnedItem(GameObject)` (111-121) | Removes it from `prefabs` |
| `DestroyMapItem(string GUID)`, `RemoveFromList(string GUID)` (123-137) | Add to / remove from `DestroyedGuids` |

## Player state in the save

The scripts that save into Globals.tnmt (`SerializeData(this, global:
true)`), 46 classes: Achievements, AnimalController, BlackoutController,
BuildingSystem, CharacterSlotController, Crime, DialogueCommonMethods,
DifficultyController, DrunkEffect, FurnitureBlueprintController,
GlobalState, Inventory, InvoiceController, ItemsUIPanel,
JanitorController, Keypad, LegalServicesController, MailController,
MapController, Money, MushroomEffect, NPCDirector (every NPC's state, in
OnSavingGameSpecial), NoteController, Notifications,
OrangeMushroomEffect, PlayerHandItems, PlayerIdentity, PlayerStatUI,
PlayerStats, PlayerSubscriptionsController, RandommailSender,
RecipeController, RelationshipController, Sauna, SaveSceneManager,
StartManager, StartOpenSewer, TaskController, TaskItemsManager,
TenementController, TenementEventController, ThirdPersonCameraCollision,
ThirdPersonCameraController, TimeOfDayAzure, Tutorial, WeatherManager.
Keypad and Sauna are objects in areas: their entries go to Globals from
whichever area they are in. Relay and the relay classes with `global`
set also save into Globals ([`relays.md`](relays.md)).

Each area's copies of these save under their own GUIDs
(`research_save_ids.rs`: SleepEventController a different GUID per area;
PersistLocation on the live player 79edc4c2..., on most areas' copies
c0f9412e...). The live top objects hold area-file scripts too
(`research_live_roots_saving.rs`: Game_Logic holds 38 global classes and
85 Relay, 13 EditTask, DestructibleList, the slot controllers,
SleepEventController, TriggerChangelevel, InteractableTalk in the area
file; Player holds PlayerStats and PlayerHandItems (global) and
PersistLocation and relays (area file); Pause Menu(Clone) 429 Relay, area
file).

## Load steps that create objects

These duplicate objects if run on an area whose objects were not
destroyed: `DestructibleList.OnLoadingGameDestructibleList` (dropped
items), `ParcelLocker.OnLoadingGame`, `RatFightArena
.OnLoadingGameLatePrimary` (Instantiate), `CollectibleItemSpawner
.OnLoadingGame` (SpawnItem). Relay's `OnLoadingGame` restarts its
delayed outputs ([`relays.md`](relays.md)).

## With areas kept loaded

The mod runs the save steps on the area left into memory and writes them
at the next game save ([`kept-areas.md`](kept-areas.md), rules 3 and 4).
Facts from this file that the mod relies on:

- Steps skip switched-off objects (1131), so a kept area's objects must
  be on when its steps run.
- `DeSerializeData` removes an entry once used: the area's temp list must
  be filled again for each application.
- `DestructibleList.OnSavingGameDestructibleList` drops prefabs whose
  object is not `activeInHierarchy`: it must run while the area is on.
- `DestructibleList.OnLoadingGameDestructibleList` instantiates into the
  active scene: the area must be the active scene when it runs.
- `SaveGame` saves only the active scene's roots into `<LevelName>.tnmt`
  with `LevelName` = the active scene.
