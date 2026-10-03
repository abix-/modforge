# Storage, trade, money, banks, locks and crafting

> **Authoritative on:** `Storage` (containers, restocking, permissions),
> `Trade` (traders, prices, opening times, money restock), `Money`
> (currencies), `Bank`, `Lock` (locks and lockpicking), `CraftingBase`
> (crafting stations), and what of each differs with areas kept loaded.
>
> Index of every game system's doc: [`research.md`](research.md).

## Storage

`public class Storage : Interactable` (Storage.cs). Containers in areas;
saves with `SerializeData(this, global)`.

| Field | Saved | Meaning |
|---|---|---|
| `GUID`, `global` | key | |
| `TimeAndDay savedTimeAndDay` | yes | Time at save (catch-up) |
| `static Storage active` | no | The storage open |
| `NPCReference StorageOwner`, `bool PermissionToTake`, `PermissionToUse` | no | Taking without permission is theft ([`crime.md`](crime.md)) |
| `ItemStack[] storageSlots` | yes | Contents |
| `SpawnSettings spawnSettings` | yes (its saved fields) | Restock: `respawnEnabled`, `timetospawn`, `TimeToSpawn(sec, transform, ignorePlayerDistance)` |
| `List<ItemStackSpawn> nextItemsToSpawn` | yes | Next restock |
| `string StorageSettings`, `customStorageSlotAmount`, `RefigerationFactor` (0..1 fridge, above 1 freezer), `powerOff`, `_Lock` | | |
| `bool deltaSecondsEnabled` | | Restock tick on |

| Method | Does |
|---|---|
| `Start()` (362-402, public) | Once (`startDone`): slots from settings, permissions, `Initialize()` |
| `OnEnable()` (404-410) | `Initialize()` if started and not initialized |
| `Initialize()` (412-) | After `updateTimeDisabled` clears and 4 end-of-frames: start items, items to spawn |
| `OnSavingGame()` (282-294) | Spawn ids, lock, `savedTimeAndDay`; writes its entry |
| `OnLoadingGame()` (296-338) | **Calls `Start()`**; reads its entry (keeping `fsIgnore` spawn settings); rebuilds `Slots`; `LoadDelay` |
| `LoadDelay()` (340-360) | Restock tick on; restocks if due since `savedTimeAndDay`; power; `onUpdate`, `onSpawnItems` relays |
| `ChangeDeltaSecondsStatus(bool)` (811-825) | `TimeOfDayAzure.SecondsPassed += / -= DeltaSeconds` |
| `DeltaSeconds(int)` (827-855) | When due: tick off, `SpawnItems()` and/or `RemoveRandom()` |
| `SpawnItems()` (857-887) | Fills empty slots from `nextItemsToSpawn`; next list; `StartCoroutine(TriggerOutputsLate())` |
| `UseStorage()`, `EnterExternally(bool)`, `ExitExternally()`, `Lock()`, `Unlock()`, `UpdateSlots()`, `SetAsForeignController()` | |

## Trade

`public class Trade : Interactable` (Trade.cs). A trader (with a
`Storage` on the same object); saves into the area's file.

| Field | Saved | Meaning |
|---|---|---|
| `GUID` | key | |
| `TimeAndDay savedTimeAndDay` | yes | |
| `NPCReference owner` | no | |
| `int traderMoneyAmountMin` (5000), `traderMoneyAmountMax` (10000) | yes | Restock range |
| `[fsProperty] float currentMoney` | yes | Trader's money |
| `SpawnSettings traderMoneySpawnSettings` | yes | Money restock timing |
| `bool open`, `autoOpenClose`; `OpeningTimes openingTimes` | yes | Shop hours ([`time.md`](time.md)) |
| `Relay onOpen`, `onClosed`, `onStartTrade`, `onEndTrade` | no | |
| `float playerDistanceOnOpen`, `playerDistanceOnClose` | no | Don't switch while the player is this near |
| `float baseSellPrice` (0.9), `basePurchasePrice` (1.2), `bool fixedPrices`, `PriceMode sellPriceMode`, `purchasePriceMode` (OnlyOC, ...), `purchaseIgnoreContainerPrice` | yes | Prices |
| `string[] allowedCategories`, `forbiddenCategories` | no | |

| Method | Does |
|---|---|
| `Start()` (201-222) | Once: storage not directly usable, `MoneyRestock()`, `StartDelay` |
| `StartDelay()` (224-238) | 0.5 s: `open = openingTimes.IsOpen()`, fires `onOpen` or `onClosed`; 0.6 s: `TimeOfDayAzure.MinutePassed += DeltaSeconds` |
| `DeltaSeconds(int)` (240-281) | Each game minute: money restock when due; with `autoOpenClose`, on an hours change fires `onOpen`/`onClosed` and sets `open`, skipped while the player is near |
| `OnSavingGame()` / `OnLoadingGame()` (151-183) | `savedTimeAndDay`; load calls `Start()`, keeps `fsIgnore` settings, restocks if due (`LoadDelay`) |
| `StartTrade()`, `EndTrade()`, `MoneyRestock()`, `Buy`, `Sell`, `BuyAndMove`, `SellAndMove`, `TradeAndMove`, `MakeTrade`, `CanBuy`, `CanSell`, `IsStolen`, `CheckIfTraderHasMoney`, `CheckIfPlayerHasMoney` | |
| `static float GetItemPrice(Item, int owner, object[] meta, Currency, float basePrice, float stolenPriceFactor, bool ignoreContainers)` (586-), `GetItemStackPrice(...)` | Prices |

## Money

`public class Money : SavableScript` (Money.cs). Game-wide, Game UI;
saves into Globals.

| Member | Meaning |
|---|---|
| `static Money instance`; `int OCMoneyAmount`; private `rMoneyAmount` | Open Sewer Coins (OC), Real Money (RM) |
| `Start()` (239-) | `TimeOfDayAzure.CurrentTimeAndDay += CurrentTime` |
| `AddMoney(...)`, `CheckMoney(float, bool RM, bool show)`, `CheckMoney(float, Currency, bool)`, `CheckMoney(money)`, `CheckMoneyDialogue`, `Buy(int, bool RM, bool show)`, `Buy(int, Currency, bool)`, `Buy(money)` | |
| `OcToRmConvert(float)`, `RmToOcConvert(float)`, `RoundRM`, `DisplayRm`, `RoundMoneyValue` | OC to RM 0.06, RM to OC 9.8 |
| `AddMoneyPanel(MoneyPanel)`, `RefreshAmount()` | `moneyPanels` (registered, never removed; panels skip themselves when switched off, MoneyPanel.cs:102) |

## Bank

`public class Bank : SavableScript` (Bank.cs). Saves its entry.

| Member | Meaning |
|---|---|
| `GUID`, `BankName`, `BankPanel.Mode mode`, `Currencies currencies` | |
| `int TotalOCSupply`, `float TotalRMSupply`, `DailyAverageOcIncome/Spending`, `DailyAverageRmIncome/Spending`, `float Corruption` | Bank state |
| `Money.BankAccountData accountData` | The player's account |
| `requiredOC`, `requiredRM`, `requiredAccountItems` | To open an account |
| `Relay onOutOfFundsRM/OC`, `onReplenishedRM/OC` | |
| `InitDelay()` (119-130) | `TimeOfDayAzure.CurrentTimeAndDay += CurrentTime` |
| `CurrentTime(TimeAndDay)` (164-) | Daily bank update (interest 1.5%, lending confidence) |
| `OSAccountMoney()`, `RMAccountMoney()`, `AccountFrozen()` | |

## Lock

`[Serializable] public class Lock` (Lock.cs). Used by doors and storages.

| Member | Meaning |
|---|---|
| `bool Locked`, `Lockpickable` | |
| `TaskItem keyItem` | Key that opens it |
| difficulty | 0..2: effortless 0.1, easy 0.2, moderate 0.3, challenging 0.8, difficult 1.9; `increaseLockDifficulty` adds 0.33 after a pick |
| `string overrideLockMessage`, `Transform lockLocation`, sounds, `Animator animator` | |
| `Relay onUnlocked`, `onLocked`, `onLockpickingStart`, `onLockpickingEnd`, `onLockpickingFail`, `onLockedUse` | |
| `TimeOfDayAzure.Timer timer`, `Action afterTimeLockAction` | Timed relock |
| `OnSaving()`, `OnLoading()` (86-103) | Timer |
| `bool? Use(Action CallbackUnlock, GameObject parent)` (105-148) | true: open; false: locked; null: lockpicking started |
| `LockpickBroke()`, `LockpickSuccessCallback(bool)`, `AbortLockpicking()`, `GetUseMessage(string)`, `PlayerCanOpenOrUnlock()`, `PlayerCanUnlock()` | |
| `_Lock()`, `_Unlock()` | Used by DoorChangelevel ([`doors.md`](doors.md)) |

## CraftingBase

`public class CraftingBase : Interactable` (CraftingBase.cs). Every
crafting station; needs a `Storage`.

| Member | Meaning |
|---|---|
| `GUID`, `global` | Save |
| `RecipeType[] Recipes` | What it makes |
| `NPCReference owner`, `bool PermissionToTake` | |
| `PowerSource _Power`, `bool AlwaysOn` | Power |
| `bool lockOnExit`, `hideNoMatchRequirementsRecipes` | |
| `Storage OutputStorage`, `LiquidStorage OutputTank` | Outputs |
| `Relay onOpen`, `onClose`, `onLockedUse`, `onStartCreating`, `onDone`, `onCraftSuccess`, `onCraftFailed`, `onCraftStop`, `onActive`, `onInActive` | |
| `EquipmentQuality`, `Modifiers` (power, water), `SkillGainFactor` | Batch success and skill gain ([`player.md`](player.md), skills) |
| `static CraftingBase currentCraftingBase` | The station open (a "current" pointer, [`areas.md`](areas.md)) |

## With areas kept loaded

Storage and Trade have `savedTimeAndDay`, so their clock handlers stay
while their area is away (kept-areas.md, time while away):

- `Storage.DeltaSeconds` restocks while away; `SpawnItems` then calls
  `StartCoroutine` on a switched-off object, which Unity refuses: the
  `onSpawnItems` relay does not fire (from the code; not checked).
- `Trade.DeltaSeconds` flips `open` while away and fires `onOpen` /
  `onClosed`, which do nothing in a switched-off area (Relay.cs:106). On
  return `open` already matches the hours, so the relays never fire: the
  shop's doors and lights stay in the state they had when the player
  left. The game runs `StartDelay` on every load, firing the relay for the
  current state (from the code; not checked).
- `Bank` and `Money` have no `savedTimeAndDay`: an area's Bank's
  `CurrentTimeAndDay` handler is taken out while away; daily updates
  missed while away are not caught up (the game has no catch-up for
  them either; it does not run while the area is unloaded).
