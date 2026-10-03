# Time

> **Authoritative on:** the game clock: `TimeOfDayAzure` (fields, events,
> update loop, save and load), `TimeAndDay`, `TimeOfDayAzure.Timer`, the
> game-time yield instructions, `OpeningTimes`, the clock's listeners,
> and how an area catches up on time it was not loaded.
>
> Index of every game system's doc: [`research.md`](research.md).

## TimeOfDayAzure

`public class TimeOfDayAzure : SavableScript`, `[ExecuteInEditMode]`
(TimeOfDayAzure.cs). In `Game_Logic/Globals` of every area (rebuilt by
every load, [`areas.md`](areas.md)). GUID const "TimeOfDayAzure"; saves
into Globals. Drives Azure Sky's `AzureTimeController`, which holds the
actual time of day and date.

| Field | Type | Saved | Meaning |
|---|---|---|---|
| `instance` | static | no | Set in Awake and Start (352-365) |
| `savedTimeAndDay` | `TimeAndDay`, `[fsProperty]` private | yes | Time at the save; copied into `currentTimeAndDay` on load |
| `currentTimeAndDay` | `TimeAndDay` | yes | The game time; refreshed every game minute |
| `startTimeAndDay` | `TimeAndDay` | yes | Reset in Start |
| `dayCounter` | `int` | yes | Days passed; `TimeAndDay.currentDay`; reset to 0 in Start, restored by load |
| `dayLenghtInMinutes` | `float`, 24 | yes | Real minutes per game day |
| `timeSpeedOverrideFactor` | `float`, 1 | yes | Speed factor (`SetSpeedFactor`) |
| `timers` | `List<Timer>` protected | no | Running game-time timers |
| `timeController` | `AzureTimeController` | no (private serialized) | Azure's clock |
| `overrideSky`, `overrideSkyZone`, `overrideSkyProfile`, `currentOverrideSkyProfile` | | no | Sky override (`DisableSky(profile)`, `EnableSky()`, `SkyEnabled()`, 614-629) |
| `_updateTimeDisabled` | `bool` private | no | True from load until the clock is restored |
| `updateEnabled` | `bool` private | no | Set 1 end-of-frame + 1 frame after Start (`UpdateDelay`, 387-392) |

| Property | Value |
|---|---|
| `bool updateTimeDisabled` (244-254) | `_updateTimeDisabled \|\| !updateEnabled`. Many scripts wait for it to clear before initializing |
| `float actualSpeed` (267) | `dayLenghtInMinutes / timeSpeedOverrideFactor` (passed to `SetNewDayLength`) |
| `CurrentHours`, `CurrentMinutes` (280-300) | `timeController.GetTimeOfDay()[0]`, `[1]` |
| `CurrentSeconds` (302-311) | `floor(timeline * 3600 % 60)` |
| `CurrentTimelineValue` | `timeController.GetTimeline()` (hours as float) |

### Events (static, 313-319)

| Event | Signature | Fired |
|---|---|---|
| `SecondsPassed` | `void (int seconds)` | Every frame the timeline advanced; argument = game seconds since the last frame (`deltaTime`) |
| `MinutePassed` | `void (int minute)` | When `CurrentMinutes` changed; argument always `60` |
| `DayChanged` | `void (int day)` | In `IncreaseDayCounter`; argument = `dayCounter` (days passed, not the date) |
| `CurrentTimeAndDay` | `void (TimeAndDay t)` | Every game minute, after `currentTimeAndDay` is refreshed |

### Update loop

`Update()` (394-402): when `actualSpeed != 0 && updateEnabled &&
!updateTimeDisabled`: `timeController.SetNewDayLength(actualSpeed)`,
`CalculateDeltaTime()`, `UpdateTimers()`.

`CalculateDeltaTime()` (437-456): `now = floor(timeline * 3600)`; first
call only records it. `deltaTime = now - prev` (wraps at 86400); on a
change calls `UpdateCurrentTimeAndDay()`.

`UpdateCurrentTimeAndDay()` (458-497): `SecondsPassed(deltaTime)`; then,
only when the minute changed: `MinutePassed(60)`; if the Azure day differs
from `currentTimeAndDay.day`, `IncreaseDayCounter()`;
`currentTimeAndDay.SetToCurrentTimeAndDay()`;
`CurrentTimeAndDay(currentTimeAndDay)`. Each invoke is in its own
try/catch: one throwing handler stops the rest of that event's list.

`IncreaseDayCounter()` (524-543): `dayCounter++`; `DayChanged(dayCounter)`;
date 1 -> set day 3 of the same month; Lua variable "Day"; survival
achievements (7, 30, 365).

`UpdateTimers()` (499-522): each timer not `stopped`:
`remainingInSeconds -= deltaTime`; when `< 0`: `Callback()`,
`Callback2(timer)`, removed.

### Save and load

| Method | Does |
|---|---|
| `OnSavingGame()` (321-325) | `savedTimeAndDay.SetToCurrentTimeAndDay()`; writes its entry |
| `OnLoadingGamePrimary()` (327-340) | Reads its entry; `_updateTimeDisabled = true`; copies `savedTimeAndDay` into `currentTimeAndDay` (unless its year is 0); `prevTime = 0`; `SetTimeline`, `SetDate` from it; starts `OnLoadingGameDelay` |
| `OnLoadingGameDelay()` (342-350) | Waits until Azure's time matches `currentTimeAndDay` (minutes, hours, `dayCounter`) and `SaveController.Loading` is false; clears `_updateTimeDisabled` |
| `Start()` (357-365) | `currentTimeAndDay = new`, `dayCounter = 0`, `SetToCurrentTimeAndDay()` from Azure; `UpdateDelay` |

Other methods: `IsItDay()` (hours 6 to 20), `SetSpeedFactor(float)`,
`SetSpeedFactorByProgressTime(processTime, targetRealTimeSeconds = 10)`
(706-713, used by waiting), `SecondsToRealTimeSeconds(int)`,
`GetDayOfWeek()` (0 = Monday), `GetDayOfWeekString()`, `GetDay()`,
`GetMonth()`, `GetYear()`, `SetTimeline(float)`, `SetDate(y, m, d)`,
`SetDay`, `SetMonth`, `SetYear`, `SetFollowTarget(Transform)`,
`static GetDayname(int)`, `static GetCurrentTime(float hoursLeft, bool
simple)` ("1d 2h 3m"), `static DebugDelegateCount()` (logs each event's
handler count).

## TimeOfDayAzure.Timer

`[Serializable] public class Timer` (80-187). A game-time countdown in
`TimeOfDayAzure.instance.timers`. Owners keep it and save it in their own
entry (RelayTimer, [`relays.md`](relays.md)).

| Member | Saved | Meaning |
|---|---|---|
| `Action Callback`, `Action<Timer> Callback2` | no (rebuilt from `_Callback`, `_Callback2` `ActionReference`) | Called when it runs out |
| `int timeInSeconds`, `remainingInSeconds` | yes | Length, left |
| `bool stopped` | yes | Not counted down |
| `bool timerStarted` | yes | Set by the first constructor |
| `TimeAndDay savedTime` (`fsProperty`) | yes | Time at save |
| `Timer(Action, int seconds)`, `Timer(Action, int seconds, int remaining)`, `Timer(Action<Timer>, int seconds)` | | Add themselves to `timers` |
| `UpdateTimerSettings(Action<Timer>)` | | New callback; `remaining < 0` -> 1; re-added if missing |
| `Reset()`, `Destroy()` | | Restart; remove from `timers` |
| `OnSaving()` (160-165) | | Stores callbacks as `ActionReference`, `savedTime` = now |
| `int OnLoading(int timeToExclude = 0, bool ignoreStopped = false)` (167-186) | | Rebuilds callbacks; unless stopped: subtracts the game time passed since `savedTime` (plus `timeToExclude`) from `remainingInSeconds`; returns the overshoot when below 0 (remaining set 0); re-adds itself to `timers` |
| `GetCurrentTime(bool simple)` | | "Finished" or the time left as text |

`WaitForIngameSeconds(int seconds)` (21-51): `CustomYieldInstruction`
backed by a Timer. `WaitForIngameMinutes(int minutes)` (54-77): waits
until `currentTimeAndDay.TotalMinutes` reaches now + minutes. Both stop
waiting when `instance` is null.

## TimeAndDay

`[Serializable] public class TimeAndDay` (TimeAndDay.cs).

| Field | Meaning |
|---|---|
| `float seconds`, `minutes`, `hours` | Time of day |
| `int weekDay` | 0 = Monday |
| `int day`, `month`, `year` | Date |
| `int currentDay` | `dayCounter` (days passed) |

| Member | Value |
|---|---|
| `TotalSeconds` (55) | `seconds + minutes*60 + hours*3600 + currentDay*86400` |
| `TotalMinutes` (41-53, get/set) | `minutes + hours*60 + currentDay*1440` |
| `TotalHours` (28-39, get/set) | `hours + currentDay*24` |
| `TotalMinutesWithWeekDay`, `TotalMinutesWithEverything`, `TotalMinutesWithoutcurrentDay` | Variants |
| `SetToCurrentTimeAndDay()` (116-126) | Copies the live time from `TimeOfDayAzure.instance` (seconds, minutes, hours, weekday, date, `dayCounter`) |
| `int GetDifferenceToCurrentTimeInSeconds()` (91-94) | `this.TotalSeconds - now.TotalSeconds`: **negative** when time has passed since this value |
| `CurrentTimeAndDayIsSame()` (128-143) | minutes, hours and `currentDay` equal the live ones |
| `CopyValues(TimeAndDay)`, `CopyValues()` | Copy |
| `GetTimeLine()` | `hours + minutes/60 + seconds/3600` |
| `operator +` (213-262) | Adds with carry |
| `ToString`, `ToDateString`, `ToDateTimeString`, `ToTimeString`, `GetDayName`, `GetDaynameShort`, `GetMonthNameShort`, `GetWeekday`, `static MinutesToTimeString(float)` | Formatting |

Game bugs: the constructor `TimeAndDay(seconds, minutes, hours)` sets
all three to `seconds` (57-62); `GetMonthNameShort` maps 8 -> "Sep",
9 -> "Oct", 10 -> "Sep" (180-183).

## OpeningTimes

`[Serializable] public class OpeningTimes` (OpeningTimes.cs): `int`
`opensOn<Day>` / `closesOn<Day>` per weekday, default 8 and 18.
`IsOpen()` (56-69) by `currentTimeAndDay.weekDay` and `hours`: equal ->
closed; `opens > closes` -> open across midnight. Used by RelayWeekdays
([`relays.md`](relays.md)) and shops.

## Clock listeners

64 handlers on SecondsPassed, MinutePassed, DayChanged and
CurrentTimeAndDay. Those that act beyond their own object: Prison
(lowers every crime record each second while subscribed),
RelayPlayerDistance (fires on a new day when the player is far), Trade
(restocks money, opens and closes by schedule, checks player distance),
Sauna and TriggerRadiation (act on the player only while the player is
inside), Clock (plays its sound), SoundscapeGlobal (sets the game-wide
sound), TenementController and TenementEventController
([`tenement.md`](tenement.md)); the rest tick their own object, or are
the player's own managers. Spawner subscribes to SecondsPassed in its
Start coroutine (Spawner.cs:175) and unsubscribes only in OnDestroy
(388).

## Time while an area is not loaded

Nothing in it runs; the load catches it up. A class records the time in
its OnSavingGame (`savedTimeAndDay.SetToCurrentTimeAndDay()`) and, from
its OnLoadingGame, starts a coroutine that applies
`savedTimeAndDay.GetDifferenceToCurrentTimeInSeconds()`: grow.LoadDelay
(`UpdateGrow`), Storage.LoadDelay (restock `SpawnItems` when due, power,
outputs), Spawner.LoadDelay (`timetospawn`), and AnimalBreeder,
AnimalStats, BaseShop, BatteryPowerSource, Collectible
(OnLoadingGameDelay), GasStation, InteractableItemGiver,
InteractableShower (OnLoadingGameDelay), LiquidStorage, logic_gauge,
NPCInfo (OnLoadDelay: needs after more than 6000 s and 30000 s), Trade,
VendingMachine, WorkableResourceSource; Fuel (a plain class) catches up
in `LoadedGame`, called by its owner. `TimeOfDayAzure.Timer` catches up
in `OnLoading` (above). Catch up in OnMapChanged: RelayTimer,
RelayOnDayChange, Spawner.

## With areas kept loaded

`TimeOfDayAzure` is the live one from the area the save loaded (one copy,
[`kept-areas.md`](kept-areas.md)); it keeps running through kept doors
(no `_updateTimeDisabled` period). Every timer in `timers` keeps counting,
including timers of kept areas away. In areas left, clock handlers stay
only for classes with a `savedTimeAndDay` field or holding one (Fuel);
the rest are taken out until the area is entered again (kept-areas.md,
time while away).
