# Crime and police

> **Authoritative on:** the crime system (`Crime`: crime records, fines,
> bribes, arrest, prison), police (`Act_Police`: states, chasing, what a
> police NPC does at a door and on a load), and area zones that commit
> crimes (`StrictArea`).
>
> Index of every game system's doc: [`research.md`](research.md).

## Crime

`public class Crime : SavableScript` (Crime.cs). Game-wide, in
Game_Logic. GUID const "Crime"; saves into Globals in OnSavingGame.

| Field | Saved | Meaning |
|---|---|---|
| `static Crime instance` | no | Awake (115-118) |
| `List<CrimeRecord> crimeRecord` | yes | One generic record per `CrimeType` (added in Start and after load) plus one per victim and type |
| `int timesInJail` | yes | |
| `float crimeFineMultiplier` (1.5), `crimePerPrisonHour` (250) | no | Fine = crimes x 1.5; prison hours = crimes / 250 |
| `const int maxPrisonTimeInHours = 100` | | |
| `[fsProperty] bool triedBribe` | yes | |
| `List<Act_Police> activePolices` private | no | Police activities running (`AddToActivePolices` in `Act_Police.SetStartSettings`, removed in its `StopActivity`) |
| `bool arrestInProgress` private, `ArrestInProgress` | no | Cleared in OnLoadingGame |
| `static event OnGoingToPrison` | | Fired by `GoToPrison`; RelayGoToPrison listens |

`CrimeType`: Unspecified, Theft, Violence, Fraud, PrisonEscape,
Administrative, AnimalCruelty, Trespassing, Burglary, None, Harassment,
Vandalism, Terrorism.

`[Serializable] CrimeRecord`: `bool generic`, `CrimeType type`,
`NPCReference victim`, `float amount`.

| Method | Does |
|---|---|
| `Start()` (120-140) | A generic record per type; registers Lua functions bound to this copy: `GetSentenceLengthPreArrest`, `GetSentenceLength`, `GetCrimeAmount`, `GetCrimeFineAmount`, `CountStolenGoodsValue`, `GoToPrison`, `TeleportToPrison`, `PayFine`, `CanPayFine`, ... (unregistered in OnDestroy, 591-) |
| `OnLoadingGame()` (100-113) | `arrestInProgress = false`; reads its entry; adds missing generic records |
| `CommitCrime(NPCReference victim, int severity, CrimeType type, bool silent)` (223-266) | Severity at least 1; notification (unless silent); no victim -> the generic record of that type; else the victim's record (added if missing) |
| `ClearCrime(victim)`, `ClearCrime(victim, type)`, `ClearCrime()` (268-297) | Zero records |
| `GoToPrison(double severityFactor)` (299-320) | Unless an arrest or a level change is under way: `StopPolicePursuits()`; scales records; passes the player out with the Arrest sleep event in 10 s; `timesInJail++`; `OnGoingToPrison` |
| `TeleportToPrison()` (322-330) | `StopPolicePursuits()`; speed 1; `SaveController.ChangeLevel(info_game_logic.instance.prisonLevelName, prisonEntrypoint)` (a normal load, [`doors.md`](doors.md)) |
| `StopPolicePursuits()` (332-347) | Every NPC whose activity is `Act_Police`: `ResetTransition()`; each such activity and each in `activePolices`: `OnPlayerArrested()` |
| `CallPolice(Transform caller, bool severe)` (559-577) | Every police in `activePolices` within 15 m of the caller: `StartChase()` (severe) or `StartChaseQuestion()` |
| `IsNPCPolicing(NPCReference)` (579-589) | Checks only the first entry of `activePolices` (game bug) |
| `CheckCrimesForArrest(float chancePer1000)`, `CountCrimes(...)`, `GetCrimeAmount`, `GetCrimeFineAmount`, `GetSentenceLengthInHours`, `CanPayFine`, `PayFine`, `CanBribe`, `TryToBribe`, `CalculateBribe`, `HasStolenGoods`, `CountStolenGoodsValue`, `ConfiscateItems(Storage, bool, Transform)` | Queries and actions |

Sleep arrest: `WaitingController` arrests with a 10% chance during sleep
when crimes are pending ([`player.md`](player.md)).

## Act_Police

`public class Act_Police : Activity` (NPC/Act_Police.cs). The activity of
a police NPC ([`npcs.md`](npcs.md), Activity).

| Member | Meaning |
|---|---|
| `enum State` | Idle, Stand, Patrol, Wander, ChasePlayer, QuestionPlayer, SearchingPlayer, SearchingPlayerAgressive |
| `State state` | |
| `TimeOfDayAzure.Timer timeUntilStateChange` (`fsIgnore`) | Next state change; `SuffleNewState` on expiry |
| `Vector2Int stateTime` (1000, 7200) | Game seconds per state |
| `center` | Its post (`levelname`, `InCurrentLevel()`) |

| Method | Does |
|---|---|
| `GetFollowTarget()` (117-124) | While running, chasing and the player not arrested: the player's object. So NPCDirector treats a chasing police NPC as a follower and moves its data towards the player's area ([`npcs.md`](npcs.md), moving between areas) |
| `StartActivity(npc)` (155-161) | `SetStartSettings()`, `SuffleNewState()` |
| `UpdateActivity(npc)` (163-173) | `SetStartSettings()`; new state timer if none; `StartState()` |
| `SetStartSettings()` (202-212) | Once: `SaveController.PlayerWillLoadGame += ForceStopActivity`; `Crime.AddToActivePolices(this)`; idle status |
| `StopActivity()` (245-) | Unsubscribes `PlayerWillLoadGame`; `RemoveFromActivePolices` |
| `InterruptActivity()` (175-182) | Refused while chasing or searching aggressively (unless `force`) |
| `InCurrentLevel()`, `GetTargetScene()` (184-200) | From `center` |
| `OnPlayerArrested()` (126-153) | Stops pursuing, `ResetTransition`, back to a normal state |
| `StartChase()`, `StartChaseQuestion()`, `SetState`, `StartNewState(state, seconds)`, `SuffleNewState()`, `StartState()`, `ChasingPlayer()`, `QuestionPlayer()`, `OnPlayerDetected`, `OnPlayerCommitingCrimeDetected` | State machine |
| `ChasingPlayer()` (679-) | Arrests within 1.25 m unless a level change is active (`Changelevel.ChangeLevelActive`) or a dialogue is open |
| `StartStateOnLoad(string lastSeenEntryPointName)` (549-565) | After a load: if the player left through a different door than the one the police saw (`!= Changelevel.entrypointNameExit`): QuestionPlayer -> SearchingPlayer, ChasePlayer -> SearchingPlayerAgressive; else `StartState()` |
| `MoveToMainScene()` (849-857) | Not in its `startScene`: `MoveToOtherLevel(startScene)` |
| `RegisterDialogue()`, `UnregisterDialogue()` (410-447) | Lua functions while talking |

### A police chase through a door, in the game

1. A chasing police NPC's activity returns the player as follow target.
2. At the door, `LoadGameWithMigration` fires `PlayerWillLoadGame`: every
   subscribed police activity runs `ForceStopActivity`.
3. The save before it recorded the police NPC's `NPCInfo.policeActivity`,
   its timer and `Changelevel.entrypointNameEnter` (NPCInfo.cs:139-168).
4. NPCDirector moves the NPC's data towards the player's area
   (`OnFollowingTarget`). When the NPC's area is loaded and its object
   exists, `NPCInfo.OnLoadDelay` restores the police activity and calls
   `StartStateOnLoad` (NPCInfo.cs:193-258); long absences (6000 s,
   30000 s) downgrade the state.

## StrictArea

`StrictArea` (StrictArea.cs): a zone. While the player is inside
(OnTriggerStay) subscribes to `Inventory.instance.ItemConsumed` and
`PlayerStats.instance.PlayerDefecatedInPublic`; unsubscribes on
OnTriggerExit or OnDestroy. Its handlers commit an Administrative crime
when smoking, alcohol, mushrooms or defecation is witnessed. Unity sends
no trigger exit when the object is switched off.

## With areas kept loaded

- The mod's kept door fires `PlayerWillChangeLevel`, not
  `PlayerWillLoadGame` (kept-areas.md, rule 3), so police activities are
  not force-stopped at a kept door; a chase continues as follower
  movement (not checked live).
- `Crime.activePolices` keeps police activities of kept areas that are
  away (their activity keeps running in data). `CallPolice` picks police
  within 15 m by position; areas share one world space
  ([`areas.md`](areas.md)), so a police NPC in a switched-off kept area
  can be within 15 m (not checked).
- `StrictArea`: the mod's door waits a physics step with the area left
  still on, so its zones see the player leave (kept-areas.md, the door).
