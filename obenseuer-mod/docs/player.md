# The player's stats

> **Authoritative on:** PlayerStats and its parts (skills, hunger and
> thirst, addictions, mental health, health, tiredness), the difficulty
> settings that scale them, and waiting and sleeping.
>
> Index of every game system's doc: [`research.md`](research.md).

## PlayerStats (singleton, GUID "PlayerStats")

Central hub for all player state. All sub-systems are fields on
this singleton, accessed via `PlayerStats.instance`.

| Field | Type | What it holds |
|---|---|---|
| health | PlayerStatsHealth | HP (0..100), bleeding, regen rate |
| hungerAndThirst | PlayerStatsHungerAndThirst | hunger, thirst, bowel, bladder |
| mentalHealth | PlayerStatsMentalHealth | depression (0..100), expectation level |
| tiredness | PlayerStatsTiredness | exhaustion (0..100), sleep debt |
| mushrooms | PlayerStatsMushrooms | mushroom high, SMV progression |
| addictions | PlayerStatsAddictions | alcohol, mushroom, smoking, gambling |
| alcohol | PlayerStatsAlcohol | blood alcohol |
| sauna | PlayerStatsSauna | sauna stat |
| duck | PlayerStatsDuck | duck stat |
| hygiene | PlayerStatsHygiene | cleanliness |
| radiation | PlayerStatsRadiation | radiation exposure |
| gambling | PlayerStatsGambling | gambling state |
| conditions | PlayerStatsDiseasesAndConditions | diseases and conditions |
| Skills | PlayerSkill[] | array of all player skills |
| Godmode | bool | disables damage and stat drain |
| Active | bool | whether stats tick |
| StatsProgressDisabled | bool | freezes stat progression |

## Player skills (PlayerStats.PlayerSkillType)

Lockpicking, Drinking, Cooking, Mashing, Brewing, Distilling,
Farming, Malting, Manufacturing, Paperwork, Chemistry, Carpentry,
Machining, Engineering, Bribery, Cleaning, Sewing, Electronics,
Mining, Music, Smithing, Medical, Computers.

Each skill is a `PlayerSkill` with a float `Skill` field and an
int `Level` property (`Math.Floor(Skill)`).

## Hunger and thirst (PlayerStatsHungerAndThirst)

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
reduce effective hunger rate.

## Addictions (PlayerStatsAddictions)

Four addiction types, all with the same structure:

| Addiction | Need baserate | Addiction decay |
|---|---|---|
| Alcohol | 40/hr | -1.25/hr |
| Mushroom | 40/hr | -1.25/hr |
| Smoking | 40/hr | -1.25/hr |
| Gambling | 6/hr | -0.5/hr |

Each has an `Addiction` float (0..100) and a `Need` float (0..100).
Need grows based on addiction level. Withdrawal at high need deals
mental health damage (`WithdrawalsymptomMentalhealthLoss = 50`).
All rates scaled by difficulty.

## Mental health (PlayerStatsMentalHealth)

`currentStatus` (0..100) drifts toward `mentalHealthTarget` at
`mentalHealthChangeRate` (0.5/hr). Effective mental health is
reduced by alcohol in blood and boosted by hygiene. Mushroom SMV
progression above 50 scales it down. `expectationLevel` (default
25) modulates how strongly bad conditions affect depression.
Can be disabled entirely by difficulty setting.

## Health (PlayerStatsHealth)

`currentStatus` (0..100), `bleeding` (0..100),
`HealthRegenerationRate` (1/min). Damage sources identified:
hunger starvation, thirst starvation, bleeding.

## Tiredness (PlayerStatsTiredness)

`currentStatus` (0..100), `Exhaustionrate` (6/hr), `RestRate` (10),
`SleepTimeSpeed` (150). At 100 tiredness, the game forces a
pass-out via `WaitingController.instance.PassOut()`. Sleep debt
accumulates when tiredness goes negative.

## Difficulty system (DifficultyController + DifficultyInfo)

Singleton `DifficultyController.instance`. All stat rates go
through difficulty multipliers:

| Knob | Affects |
|---|---|
| generalNeedsSpeed | hunger rate, thirst rate |
| addictionNeedsSpeed | how fast addiction need grows |
| addictionRecoverySpeed | how fast addiction decays |
| smvProgressionRateSpeed | mushroom disease progression |
| renovationCost | building upgrade money cost |
| renovationResourceCosts | building upgrade material cost |
| renovationSpeed | how fast upgrades complete |
| rentIncome | rent from tenants |
| prices | shop prices |
| respawningTime | item respawn timer |
| traderWealth | how much money traders carry |
| mentalHealthDisabled | skip mental health entirely |
| userSavesDisabled | disable manual saves |
| mandatoryStartingAddictionsDisabled | skip forced addictions |

Multiplier values: 0.25x through 10x in steps, plus Disabled.
Supports Custom difficulty where all knobs are individually set.

## Waiting and sleeping (WaitingController)

Handles all time-skip activities: Sleeping, Passout, Waiting,
Working, HavingFun, Reading, Playing, StaringWall, Arrest,
WatchingTV, Talking. Sleep events can interrupt (crazy neighbor).
Arrest chance during sleep = 10% if crimes pending. Has alarm
clock support. A sleep event can send the player to "Interior Player
Tenement" with a normal load (SleepEventController.cs:341; see
[`doors.md`](doors.md), area changes other than doors).
