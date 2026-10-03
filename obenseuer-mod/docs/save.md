# The save system

> **Authoritative on:** how the game saves and loads (SaveController,
> SavableScript, the save files, the save and load phases and their
> order), the game's door step by step, which scripts save player state,
> DestructibleList, and the load steps that create objects.
>
> Index of every game system's doc: [`research.md`](research.md).

## Serialization

The game uses FullSerializer (`fsProperty`, `fsIgnore`,
`fsCheckChildFields`) for save/load. `SaveController.SerializeData`
and `DeSerializeData` handle persistence. `SavableScript` is the
base class for MonoBehaviours that participate in saves.

## SaveController

Multi-phase save/load: Primary, Secondary, Tertiary, Special,
DestructibleList phases. Save header stores: SaveName, LevelName,
NewlevelEntrypoint, CharacterName, Date, ApplicationVersion.
Each SavableScript has a GUID for serialization targeting.
Global data (crime, difficulty, player stats) saves separately
from per-scene data.

Files, in `persistentDataPath/Saves/<CharacterName>/<SaveName>/`:
`Info.tnmt`, `Globals.tnmt` (scripts saved with
`SerializeData(this, global: true)`), `<Level>.tnmt` per area
(`SerializeData(this)`), `Globals.dialogue` (the Dialogue System's
data). UTF-8 with a byte order mark (the game's reader drops it; its
parser rejects it). `CharacterName` and `SaveName` are private statics
(SaveController.cs:185-187). `SaveGame` copies the last save folder into
the new one first (469-472), so areas not visited keep their files.
An `ObjectDataHeader` holds a live object and is serialized at write
time; `SaveDataHeader(list, save, level, character, entrypoint)`.

`ExecuteSaveLoadFunctions(roots, phase, includeInactive)` calls the
phase on every SavableScript under the given top objects whose object
is on, unless `includeInactive` (1113-1131). Each SavableScript finds its
saved entry by `GUID` and takes it out of the list (`DeSerializeData`,
707-).

## A door, step by step

`Changelevel.ChangeLevel` (Changelevel.cs:72-87), then
`SaveController.ChangeLevel` (270) and `ChangeLevelDelay` (344-359):

1. `PlayerWillChangeLevel` (270): InteractableChair and
   InteractableLadder stop sitting and climbing.
2. Fade to the loading screen, wait for it (347-355).
3. `SaveGame(GetOldestAutosave(), newLevel, entrypoint)` (356-357), into
   the older of Autosave and Autosave2, which sets `SaveName` to it:
   OnMapChanging on the active area's top objects and the
   kept-through-loads objects (446-447); new temp lists (449-450);
   `SavingStarted` (452); save phases Primary, Secondary, Tertiary
   (453-455); `DestructibleList.instance.OnSavingGameDestructibleList()`
   (456); kept-through-loads OnSavingGameSpecial (457); OnSavingGame,
   OnSavingGameLatePrimary (458-459); files written (460-476);
   OnSavingFile (477); `SavingDone` (478). `LevelName` is the active
   scene's name (438).
4. `LoadGameWithMigration(CharacterName, autosave)` (1205-): sets
   `CharacterName`, `SaveName` (1208-1209), `PlayerWillLoadGame`,
   `Loading = true`, reads `Globals.tnmt` and `<level>.tnmt` into
   `tempSavedata_Global` and `tempSavedata_Level`, then
   `LoadSaveGameDifferentScene` (618-666):
5. The scene loads in single mode (624-639): every object of the old
   area gets OnDisable then OnDestroy; the new area's objects Awake and
   OnEnable, Start on the next frame.
6. `LoadingStarted` (640); load phases Primary, Secondary, Tertiary
   (641-643); kept-through-loads OnLoadingGameSpecial (644);
   `DestructibleList.instance.OnLoadingGameDestructibleList()` (645);
   OnLoadingGameDestructibleListCheck including switched-off objects
   (646); next frame (647); OnLoadingGame, OnLoadingGameLatePrimary, the
   check again (648-650); OnMapChanged on the active area only when the
   area changed (651-654); player to the arrival point (655); dialogue
   data applied (656-659); temp lists cleared, `Loading = false`,
   `LoadingDone`, fade out (660-664).

Measured order in a normal load (frame numbers): the area's objects run
Start one frame before its saved data goes in (load phases); scripts that
need the data wait (Relay fires its start events 3 frames after Start,
[`relays.md`](relays.md)). Times on one trip: save 0.58s, scene load
4.25s, restore about 1.0s, fade back 0.6s; the bar fills at 1 per second
(LoadingScreen.cs:85), so even an instant load waits about 1s.

The menu loads a save with `StartCoroutine(LoadGameWithMigration(
folder, save, fromMenu: true))` on its LoadMenu (LoadMenu.cs:539);
`SaveController.Loading` is not on until the coroutine runs.

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
Keypad and Sauna are objects in areas, not managers: their entries go to
Globals from whichever area they are in.

Order: the save phases in SaveGame's order (Primary, Secondary,
Tertiary, DestructibleList, kept-through-loads Special, OnSavingGame,
LatePrimary, OnSavingFile); within a phase, the order of the active
area's top objects and their children (ExecuteSaveLoadFunctions,
SaveController.cs:1113-1131), then the kept-through-loads objects for the
Special phases. Loading reads both files first, then runs the load phases
in the order above; each script takes its own entry by GUID.

## DestructibleList

GUID "DestructibleList", saved in the area's file (DestructibleList.cs:
11-25): `DestroyedGuids` (map items destroyed) and `prefabs` (items
dropped, re-spawned on load from `Resources`, parented 2 frames later,
68-86). Its Awake resets `Collectible.allCollectibles` (91). Called
directly by SaveGame (456) and the load (645).

## Load steps that create objects

These would duplicate objects that were not destroyed:
DestructibleList.OnLoadingGameDestructibleList (dropped items),
ParcelLocker.OnLoadingGame, RatFightArena.OnLoadingGameLatePrimary
(Instantiate), CollectibleItemSpawner.OnLoadingGame (SpawnItem); Relay's
OnLoadingGame restarts its delayed outputs (`delayTrigger`,
[`relays.md`](relays.md)).
