# The save system

> **Authoritative on:** how the game saves and loads (SaveController,
> SavableScript, the save files, the save and load phases and their
> order), which scripts save player state, DestructibleList, and the load
> steps that create objects. A door's steps, which use these:
> [`doors.md`](doors.md).
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

## A door's save and load

A door saves into an autosave, then loads it into the new area
(SaveGame, then LoadGameWithMigration and LoadSaveGameDifferentScene,
SaveController.cs:416-478, 618-666, 1205-). The steps in order, with
lines and measured times: [`doors.md`](doors.md).

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
