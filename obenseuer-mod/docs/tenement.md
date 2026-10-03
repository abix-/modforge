# The tenement

> **Authoritative on:** the player's tenement business:
> `TenementController` (apartments, residents, rent, upgrades, evictions,
> resource storages, Lua functions), `TenementEventController` and
> tenement events, `TenementContractor`, `TenementResourceStorage`, and
> what of it is per area.
>
> Index of every game system's doc: [`research.md`](research.md).

## TenementController

`public class TenementController : SavableScript` (TenementController.cs).
Game-wide manager in `Game_Logic/Controllers` ([`areas.md`](areas.md)).
`static string GUID = "TenementController"`; saves into Globals.

| Field | Saved | Meaning |
|---|---|---|
| `static TenementController instance` | no | Set in Awake (236-240), which also registers Lua |
| `TenementGeneral general` | yes | Building-wide state and upgrades |
| `List<TenementApartment> apartments` | yes | Units: `apartmentNumber`, `resident`, `prefabs`, `moveStarted`/`moveSecondsLeft`, `evictionStarted`/`evictionSecondsLeft`, `silentRent`, `deposit` |
| `List<TenementUpgradeProgress> currentUpgradeProgresses` | yes | Running upgrades (`TimeSecondsLeft`) |
| `List<TenementResident> allResidents`, `evictedResidents` | private (attributes not read) | Residents |
| `TimeAndDay lastPayment` | private (attributes not read) | Last rent payment |
| `int upgradesStarted`, `upgradesDone` | private (attributes not read) | Counters |
| `List<TenementUpgradeMarked> markedUpgrades` | private (attributes not read) | Upgrades marked for materials |
| `Dictionary<string, Dictionary<int, float>> resourceStorageSnapshotsByContractor` | private (attributes not read) | Item amounts per contractor's storages, at the last save |
| `List<Storage> tenementResourceStorages` | no | Storages added by `TenementResourceStorage.Start` |
| `TenementContractor currentContractor`, `bool contractorOpen` | | Contractor menu open (`AddContractor`, `RemoveContractor`, 454-465) |
| `TenementContractor currentSceneContractor` private | | Last contractor whose menu was opened (`AddContractor`) |
| `TenementResident currentResident`, `bool residentOpen` | | Resident menu |
| `Dictionary<TenementResident, NPCInfo> currentSceneResidents` | no | Resident NPC objects of the loaded area (added by `NPCInfo.ResidentCheck`, removed in `NPCInfo.OnDestroy`) |
| `EditTask` fields (`examineTask`, `startRenovation`, `rentApartment`, ...) | | Task objectives it advances |
| `bool ignoreUpgradePricesAndItems`, `completeUpgradesInstantly` | | Debug |

| Method | Does |
|---|---|
| `Start()` (230-234) | `TimeOfDayAzure.SecondsPassed += DeltaSeconds`; `DayChanged += OnCleaningTimerDayChanged` |
| `OnDestroy()` (242-247) | Unregister Lua; unsubscribe both |
| `OnSavingGame()` (168-177) | `general.SavePath()`, each apartment `SavePath()`; `RefreshResourceStorageSnapshot()`; writes its entry |
| `OnLoadingGamePrimary()` (179-220) | Reads its entry (keeping the scene's prefab links), `LoadFromPath` on general and apartments, updates prefabs; every resident's `tenementEvents` -> `TenementEventController.AddTenementEvents`; `HideResidentProperty.UpdateAll()` |
| `DeltaSeconds(int sec)` (349-361) | Every frame with game seconds: `UpdateRentPayment`, `UpdateProgesses`, `UpdateEvictions` |
| `UpdateRentPayment(sec)` (363-399) | When `DifficultyController.currentDifficultyInfo.GetRentPayment(lastPayment)`: sums `GetOcIncome()`/`GetRmIncome()` of all apartments, notification "Rent paid", `Money.AddMoney` |
| `UpdateProgesses(sec)` (401-422) | `TimeSecondsLeft -= sec`; at 0 `OnUpgradeDone` (sound, removed) |
| `UpdateEvictions(sec)` (424-452) | `moveSecondsLeft` -> `MoveResident`; `evictionSecondsLeft` -> `EvictResident` |
| `StartUpgrade(progress, silent)` (285-306) | Advances renovation objectives; adds to `currentUpgradeProgresses` |
| `RentApartment(resident, apartment or number, moveTimeInHours, silent)` (770-802) | Evicts a current tenant; `apartment.AddResident`; `allResidents.Add`; move timer; collateral `GetRentCollateral` paid in; achievements; `RentFade` |
| `RentFade(resident)` (804-831) | Black fade 5 s realtime; `currentSceneResidents[resident].HideRentedResident()`; `HideResidentProperty.UpdateForCharacter`; hides `otherResidents` found by `NPCManager.instance.FindNpcById`; objective; opens the tenement menu |
| `MoveResident(apartment)` (833-850) | Move done: prefabs, notification, `TenementEventController.AddTenementEvents` |
| `StartEviction`, `CancelEviction` (852-864), `EvictResident(apartment, silent, updatePrefabs, leaveFurniture)` (866-) | |
| `GetItemAmount(id, contractor)` (951-968), `CheckForItem(id, amount, contractor)` (970-995) | `contractor` null or `currentSceneContractor`: counts `tenementResourceStorages` live; another contractor: its snapshot. Plus the player's inventory |
| `RemoveRequiredItems(id, amount)` (1025-1033) | From `tenementResourceStorages`, then inventory |
| `AddTenementResourceStorage(Storage)` (1035-1038) | Adds; never removed |
| `ResidentRented(...)`, `ResidentRentedAmount()`, `ResidentApartmentLevel`, `GetGeneralUpgradeLevel`, `GetApartmentUpgradeLevel`, `GetApartmentByResidentId`, `GetTotalIncome`, `CanRentApartment`, `MarkUpgrade`, `IsMarkedUpgrade`, ... | Queries |
| `StartApartmentCleaningTimer(apartmentNumber, days)` (687-699), `OnCleaningTimerDayChanged(day)` (701-711) | Cleaning by day |

Lua functions (`RegisterDialogue`, 1186-): `CanRentApartment`,
`ResidentRentedAmount`, `UpgradesStarted`, `ResidentRented`,
`ResidentApartmentLevel`, `ResidentApartmentUpgradeLevel`,
`TenementGeneralUpgradeLevel`, `ApartmentUpgradeLevel`,
`StartApartmentCleaningTimer`.

Enums: `ApartmentUpgradeCategory`, `GeneralUpgradeCategory` (12-44).
Upgrade types: electricity, water, bathroom, heating, wall type, balcony,
kitchen (`UpgradeType`).

## TenementResourceStorage

`[RequireComponent(typeof(Storage))] public class TenementResourceStorage : MonoBehaviour`
(TenementResourceStorage.cs): Start ->
`TenementController.instance.AddTenementResourceStorage(GetComponent<Storage>())`.

## TenementContractor

`TenementContractor.ShowMenu()` (TenementContractor.cs:56-60):
`TenementController.instance.AddContractor(this)`, opens the tenement
menu. `Id` keys the storage snapshots.

## TenementEventController

`public class TenementEventController : SavableScript`
(TenementEventController.cs). Game-wide, in Game_Logic; saves into
Globals.

| Member | Does |
|---|---|
| `static instance` | Awake (66-69) |
| `Start()` / `OnDestroy()` (71-79) | `TimeOfDayAzure.SecondsPassed += / -= DeltaSeconds` |
| `DeltaSeconds(sec)` (85-109) | `currentTime += sec`; past `nextEventTime` (random between `minTenementEventTimeInHours` and `max...` hours): `TriggerRandomEvent()` on every registered `TenementEvents`; a loop over `currentSceneResidents.Count - tenementEvents.Count` with an empty body |
| `AddTenementEvents(int targetNPC, TenementEvents)` (111-), `RemoveTenementEvents(TenementEvents)` (124-) | Per resident |
| `AddTenementSceneEvent(TenementSceneEvents)` (143-157) | Adds to `tenementSceneEvents`; `targetNPC.ID <= 0` also sets `tenementSceneResidentEvents`; a second add logs "Tenement scene event was null!" |
| `FindAndTriggerTenementSceneEvent(int targetNpc, TenementEvent)` (159-) | The first entry whose `targetNPC.ID` matches -> `TriggerEvent(type)`; then the resident events entry |

`TenementEvent.cs:82` calls `FindAndTriggerTenementSceneEvent`.

`TenementSceneEvents : MonoBehaviour` (TenementSceneEvents.cs): placed in
an area; `NPCReference targetNPC`, `List<TenementEventRelay
tenementEvents>` (`TenementEvent.EventType type`, `Relay relay`,
`List<Spawner> spawners`). Start -> `AddTenementSceneEvent(this)` (never
removed). `TriggerEvent(type)` (28-56): the matching entry's
`relay.triggerOutputs()` and one random spawner's `TrySpawn()`.

## Per area, in the game

`TenementController` and `TenementEventController` are rebuilt by every
area load (Game_Logic, [`areas.md`](areas.md)), so their non-saved lists
hold only the loaded area's objects: `tenementResourceStorages`,
`currentSceneResidents`, `tenementSceneEvents`.

## With areas kept loaded

The live controllers are the copies from the area the save loaded; they
are not rebuilt at a kept door. Their lists collect the objects of every
kept area entered (each object's Start runs on its first visit; nothing
removes them, since nothing is destroyed):

- `tenementResourceStorages`: `GetItemAmount`, `CheckForItem` and
  `RemoveRequiredItems` count and take from the storages of every kept
  area entered, not only the current area's (from the code; not checked
  live).
- `currentSceneResidents`: keeps the residents of areas left; renting
  hides that resident's object even in another kept area.
- `tenementSceneEvents`: one entry per object; a tenement event for a
  resident whose area was left runs that area's entry: the relay does
  nothing while switched off (Relay.cs:106), but `Spawner.TrySpawn` has
  no switched-off check (Spawner.cs:206-) and can spawn into the area
  left.
