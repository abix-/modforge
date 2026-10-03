# The player's stats

> **Authoritative on:** `PlayerStats` and its parts (skills, health,
> hunger and thirst, addictions, mental health, tiredness, ...), the
> stat tick, `DifficultyController` and the difficulty knobs, and
> `WaitingController` (waiting, sleeping, passing out, sleep events).
>
> Index of every game system's doc: [`research.md`](research.md).

## PlayerStats

`public class PlayerStats : Stats` (PlayerStats.cs). On the player
(rebuilt by every load, [`areas.md`](areas.md)). Saves into Globals.

| Field | Type | Meaning |
|---|---|---|
| `static PlayerStats instance` | | Awake (169-180) |
| `health` | `PlayerStatsHealth` | `currentStatus` 0-100, `bleeding` 0-100, `HealthRegenerationRate` 1/min |
| `hungerAndThirst` | `PlayerStatsHungerAndThirst` | Hunger, Thirst, Bowel, Bladder |
| `mentalHealth` | `PlayerStatsMentalHealth` | Depression, target, expectation |
| `tiredness` | `PlayerStatsTiredness` | Exhaustion, sleep debt |
| `mushrooms` | `PlayerStatsMushrooms` | High, SMV progression |
| `addictions` | `PlayerStatsAddictions` | Alcohol, mushroom, smoking, gambling |
| `alcohol`, `sauna`, `duck`, `hygiene`, `radiation`, `gambling` | `PlayerStats<Name>` | |
| `conditions` | `PlayerStatsDiseasesAndConditions` | `OnSaving()`/`OnLoading()` with the stats |
| `PlayerSkill[] Skills` | | One per `PlayerSkillType`, `Skill` float starting at 1, `Level = floor(Skill)` |
| `bool Godmode` | | No damage, no drain |
| `bool Active` | | Stats tick (false during dialogue) |
| `bool StatsProgressDisabled` | | Freeze |
| `int LocalSeconds` | | Seconds collected toward the next minute |
| `event PlayerDefecatedInPublic` | | `OnPublicDefecation()`; StrictArea listens ([`crime.md`](crime.md)) |

`PlayerSkillType`: None, Lockpicking, Drinking, Cooking, Mashing,
Brewing, Distilling, Farming, Malting, Manufacturing, Paperwork,
Chemistry, Carpentry, Machining, Engineering, Bribery, Cleaning, Sewing,
Electronics, Mining, Music, Smithing, Medical, Computers, Sauna.

`StatsType`: None, Health, Depression, DepressionTarget, Mushrooms,
Addictions, Sauna, Hunger, Thirst, Tiredness, Duck, Skill, Toilet.

| Method | Does |
|---|---|
| `Awake()` (169-180) | `instance`; a skill per type at 1 |
| `Start()` (182-186) | `StartLate`; Lua `GetPlayerStatDialogue` |
| `StartLate()` (188-197) | After `updateTimeDisabled` clears: `TimeOfDayAzure.SecondsPassed += DeltaSeconds` |
| `DeltaSeconds(int sec)` (275-307) | While `Active` and not frozen: each game minute (`LocalSeconds > 59`) `UpdateStats` on health, mushrooms, mental health, hunger and thirst, tiredness, addictions, hygiene, radiation, conditions; every call alcohol, duck, sauna, item special effects; `BarUpdate()` |
| `OnSavingGame()` / `OnLoadingGame()` (129-167) | Conditions; after load, adds skills missing from an older save (at 1) |
| `UpdateValues(ItemData, ItemConsumable)` (199-), `ApplyItemSpecialEffect(...)` (218-), `ProcessItemSpecialEffects()` (231-) | Consuming items ([`items.md`](items.md)) |
| `int GetSkill(PlayerSkillType)`, `float GetSkillWithEffects(PlayerSkillType)`, `bool IncreaseSkill(type, amount, notification)` (325-) | Skills |
| `bool SkillSuccess(type, failChance, dontIncreaseSkill, skillGainFactor, crafttime)` (480-), `static float SkillQuality(...)` (503-) | Checks and quality |
| `death(DamageTypeNames)`, `death(int)`, `Damage(DamageType, float)`, `ShowDeathEffect` | |
| `ResetStats()`, `ClearAllNeeds()`, `GetPlayerStatDialogue(string)`, `BarUpdate()` | |
| `OnDestroy()` (693-) | Unsubscribes |

### Stat values

Hunger and thirst (`PlayerStatsHungerAndThirst`):

| Field | Default | Unit |
|---|---|---|
| Hunger | 0 | 0..100, higher = more hungry |
| HungerRate | 10 | per in-game hour |
| Thirst | 0 | 0..100 |
| ThirstRate | 15 | per in-game hour |
| Bowel | 0 | 0..100, fills from eating |
| Bladder | 0 | 0..100, fills from drinking |
| ThristStarvationDamage | 25 | HP damage per hour at max thirst |
| SleepHungerThristRateFactor | 0.33 | multiplier while sleeping |

Rates are scaled by `DifficultyController.currentDifficultyInfo
.GetGeneralNeedsSpeed()`. Mushroom high and alcohol addiction both
reduce the effective hunger rate.

Addictions (`PlayerStatsAddictions`): `Addiction` 0..100 and `Need`
0..100 each; withdrawal at high need costs mental health
(`WithdrawalsymptomMentalhealthLoss = 50`); scaled by difficulty.

| Addiction | Need baserate | Addiction decay |
|---|---|---|
| Alcohol | 40/hr | -1.25/hr |
| Mushroom | 40/hr | -1.25/hr |
| Smoking | 40/hr | -1.25/hr |
| Gambling | 6/hr | -0.5/hr |

Mental health (`PlayerStatsMentalHealth`): `currentStatus` 0..100 drifts
to `mentalHealthTarget` at `mentalHealthChangeRate` (0.5/hr); lowered by
blood alcohol, raised by hygiene; SMV progression above 50 scales it
down; `expectationLevel` (25) sets how strongly bad conditions weigh;
off with the difficulty setting.

Tiredness (`PlayerStatsTiredness`): `currentStatus` 0..100,
`Exhaustionrate` 6/hr, `RestRate` 10, `SleepTimeSpeed` 150; at 100 the
game passes the player out (`WaitingController.instance.PassOut()`);
sleep debt when it goes below 0.

## DifficultyController

`public class DifficultyController : SavableScript`
(DifficultyController.cs). Saves into Globals.

| Member | Meaning |
|---|---|
| `static instance` | |
| `DifficultyInfo currentDifficultyInfo` | Active knobs |
| `DifficultyInfo[] difficulties`, `customDifficultySettings`, `currentDifficulty`, `currentDifficultyIndex` | |
| `ChangeDifficulty(bool moveLeft)`, `ChangeDifficulty(Difficulty)`, `GetDifficulties()`, `ChangeDifficultyByName(string)` (72-) | |

`DifficultyInfo` knobs (multipliers 0.25x to 10x, or Disabled; Custom
sets each):

| Knob | Affects |
|---|---|
| generalNeedsSpeed | hunger rate, thirst rate |
| addictionNeedsSpeed | how fast addiction need grows |
| addictionRecoverySpeed | how fast addiction decays |
| smvProgressionRateSpeed | mushroom disease progression |
| renovationCost | building upgrade money cost |
| renovationResourceCosts | building upgrade material cost |
| renovationSpeed | how fast upgrades complete |
| rentIncome | rent from tenants ([`tenement.md`](tenement.md)) |
| prices | shop prices |
| respawningTime | item respawn timer |
| traderWealth | how much money traders carry |
| mentalHealthDisabled | skip mental health entirely |
| userSavesDisabled | disable manual saves |
| mandatoryStartingAddictionsDisabled | skip forced addictions |

## WaitingController

`public class WaitingController : MonoBehaviour` (WaitingController.cs).
In Game_Logic/Controllers, with `SleepEventController` under it.

| Member | Meaning |
|---|---|
| `static instance` | Awake (110-113) |
| `Type waitingType` | None, Sleeping, Passout, Waiting, Working, HavingFun, Reading, Playing, StaringWall, Arrest, WatchingTV, Talking (not None blocks doors, talking, opening doors) |
| `int timeToEventInSeconds`, `sleepingTimeSeconds` | Next sleep event; time slept |
| `bool hasAlarmClock`, `alarmEnabled` | |
| `SleepEvent` arrays (`passoutEvents`, `sleepingEvents`, `crazyNeighbor`, `currentSleepingEvents`), `comingSleepEvent` | Events that interrupt sleep |
| `OnWait(int sec)`, `CheckEvent(int sec)` (115-162) | Each waited second: counts down and runs the coming event (`ExecuteEvent`, 328-) |
| `PassOut(bool canBeArrested, Type type)` (193-) | Forced sleep |
| `ShowTimeSetUI(quality, canBeArrested, sleepingEvents, usePassoutEvents, crimeArrest = 0.1, onWakeup, hasAlarmClock)` (203-) | Sleep UI |
| `bool Sleep(int seconds)`, `StartSleep(...)` (218-290) | Arrest chance during sleep: 10% (`crimeArrest`) when crimes are pending |
| `Work(int)`, `Wait(int seconds, Type, float speedFactor, bool ignorePlayerNeeds, ...)` (292-326) | |
| `Wakeup(bool alarm, bool onlyClearWaiting)` (344-) | |
| `SetComingEvent(SleepEvent)`, `ClearComingEvent()`, `SetOnWakeUpCallback`, `SetTimeWaitedCallback`, `SetOnWaitingCallback` | |

A sleep event can send the player to "Interior Player Tenement"
("CrazyPoint") with a normal load (SleepEventController.cs:341,
[`doors.md`](doors.md)). `SleepEventController` is area-owned: it saves
into the area's file and reads `info_game_logic.baseSafetyFactor`
(SleepEventController.cs:68).

## With areas kept loaded

`PlayerStats`, `DifficultyController` and `WaitingController` are the
live copies from the area the save loaded (one copy; first_copy_wins).
`SleepEventController` is area-owned: on entering, its `instance` is the
entered area's copy (kept-areas.md, rule 1).
