# Time

> **Authoritative on:** the game clock (TimeOfDayAzure), its events and
> their listeners, and how an area catches up on the time it was not
> loaded.
>
> Index of every game system's doc: [`research.md`](research.md).

## TimeOfDayAzure

Singleton `TimeOfDayAzure.instance`. Uses Azure Sky for day/night.

| Field | Default | What it does |
|---|---|---|
| dayLenghtInMinutes | 24 | real minutes per in-game day |
| timeSpeedOverrideFactor | 1 | multiplier on time speed |
| currentTimeAndDay | TimeAndDay | seconds, minutes, hours, weekDay, day, month, year, currentDay |
| timers | List\<Timer\> | in-game-time callbacks with remaining seconds |

`actualSpeed` = `dayLenghtInMinutes * (1 / timeSpeedOverrideFactor)`.
Fires `OnSecondsPassed` and `OnMinutePassed` delegates. All stat
systems subscribe to seconds ticks. `WaitForIngameSeconds` and
`WaitForIngameMinutes` are custom yield instructions for coroutines.
Its events: SecondsPassed, MinutePassed, DayChanged
(TimeOfDayAzure.cs:313-317) and CurrentTimeAndDay.

## Clock listeners

64 handlers on SecondsPassed, MinutePassed, DayChanged and
CurrentTimeAndDay. Those that act beyond their own object: Prison
(lowers every crime record each second while subscribed),
RelayPlayerDistance (fires its outputs on a new day when the player is
far), Trade (restocks money, opens and closes by schedule, checks player
distance), Sauna and TriggerRadiation (act on the player only while the
player is inside), Clock (plays its sound), SoundscapeGlobal (sets the
game-wide sound); the rest tick their own object, or are the player's own
managers.

## Time while an area is not loaded

Nothing in it runs; the load catches it up. A class records the time in
its OnSavingGame (`savedTimeAndDay.SetToCurrentTimeAndDay()`) and, from
its OnLoadingGame, starts a coroutine that applies the time since
(`savedTimeAndDay.GetDifferenceToCurrentTimeInSeconds()`): grow.LoadDelay
(`UpdateGrow`), Storage.LoadDelay (restock `SpawnItems` when due, power,
outputs), Spawner.LoadDelay (`timetospawn`), and AnimalBreeder,
AnimalStats, BaseShop, BatteryPowerSource, Collectible
(OnLoadingGameDelay), GasStation, InteractableItemGiver,
InteractableShower (OnLoadingGameDelay), LiquidStorage, logic_gauge,
NPCInfo (OnLoadDelay: needs after more than 6000 s and 30000 s), Trade,
VendingMachine, WorkableResourceSource; Fuel (a plain class) catches up in
`LoadedGame`, called by its owner. Timers that catch up in OnMapChanged:
RelayTimer, RelayOnDayChange, Spawner.
