# Relays and triggers

> **Authoritative on:** the game's scene logic wiring: `Outputs.output`,
> `Outputs.triggerOutput`, `Relay` and every Relay class, `Trigger`,
> `TriggerMultiple`, `TriggerMultipleTrain`: fields, saved state, methods,
> when each fires, with file:line in the decompiled Assembly-CSharp.
>
> Index of every game system's doc: [`research.md`](research.md).

## Outputs.output

`[Serializable] public class output` (Outputs/output.cs). One wired call
list. Used by Relay and most relay classes.

| Field | Type | Saved | Meaning |
|---|---|---|---|
| `delay` | `float` | no | Seconds before firing |
| `fireOnceOnly` | `bool` | no | Fire once, then `firedOnce` blocks it |
| `disabled` | `bool` | yes | Blocks firing |
| `firedOnce` | `bool` | yes | Set after a fire when `fireOnceOnly` |
| `delayLeft` | `float` | yes | Countdown; used only by Relay's own delay (below) |
| `OnTrigger` | `outputEvent` (`UnityEvent`) | no | The calls wired in the editor |
| `outputCustomEvent` | `outputCustomEvent` | no | Optional `SendMessage(onTrigger, arg)` to one component |

| Method | Does |
|---|---|
| `Fire()`, `Fire(object f)` (41-77) | If not `disabled`/`firedOnce`: with `delay > 0` starts `delayTrigger` on **`GameController.instance`** (one frame, then `WaitForSeconds(delay)`), else invokes now. Sets `firedOnce` when `fireOnceOnly` |
| `onEventInvoke()` (93-110) | Invokes `OnTrigger` and `outputCustomEvent` |
| `onEventInvoke(object f)` (112-152) | For each persistent call: a ScriptableObject target gets `method.Invoke(obj, f)` (public instance method by name); a Component target gets `SendMessage(name, f)`. `outputCustomEvent.arg = f.ToString()` |

`UnityEvent.Invoke` and `SendMessage` call targets whether or not their
object is switched on (SendMessage needs the object active: Unity docs;
not checked here).

`Outputs.triggerOutput` (Outputs/triggerOutput.cs): TriggerMultiple's
output. Fields `onTrigger` (`OnTrigger` enum: OnTriggerEnter,
OnTriggerExit, OnTriggerStay, OnTriggerAllExit), `delay`, `fireOnceOnly`
(not saved); `delayLeft`, `disabled`, `firedOnce` (saved); `OnTrigger`
(`outputEvent`).

## Relay

`public class Relay : SavableScript` (Relay.cs). Saves with
`SerializeData(this, global)` (56-63): into Globals when `global`, else
the area's file; nothing when `disableSaving`.

| Field | Type | Saved | Meaning |
|---|---|---|---|
| `GUID` | `string` | no | Save key |
| `global` | `bool` | yes | Save into Globals |
| `triggerAtStart` | `bool` private | no | Fire from Start |
| `fireOnceOnly` | `bool` | no | Fire once |
| `ignoreArgument` | `bool` | no | Drop the argument passed in |
| `firedOnce` | `bool` | yes | Has fired |
| `outputs` | `output[]` (`fsCheckChildFields`) | yes (each output's saved fields) | What it fires |
| `requiredTaskItems` | `List<TaskItem>` | no | All must be owned (`TaskItemsManager.CheckIfPlayerHasTaskItem`) |
| `requiredObjectives` | `List<ObjectiveStatusInfo>` | no | `TaskController.CheckObjectiveStatusInfos` |
| `requiredDialogueVariables` | `List<DialogueVariable>` | no | `DialogueVariable.IsAllTrue` |
| `disableSaving` | `bool` | no | Skip save and load |
| `delaySpeedMultiplier` | `float` private | no | Scales `delay` (`ChangeDelaySpeedMultiplier`) |
| `cancelDelayedOutputs` | `bool` private | no | Set by `CancelPendingDelayedOutputs` |

| Method | Does |
|---|---|
| `Start()` virtual (83-86) | Starts `StartDelay`: 3 x `WaitForEndOfFrame`, then `triggerOutputs()` if `triggerAtStart` (88-97) |
| `triggerOutputs()`, `virtual triggerOutputs(object a)` (99-135) | Returns when the object is null or not `activeInHierarchy`, when `firedOnce && fireOnceOnly`, or when a requirement fails. Sets `firedOnce`. Each output not `disabled` and not `firedOnce`: `delay > 0` starts Relay's own `delayTrigger` coroutine, else invokes now. Does not set the output's `firedOnce` itself (the output's `onEventInvoke` does, when `fireOnceOnly`) |
| `delayTrigger(output, a, delayLeft)` private (218-237) | `output.delayLeft = delayLeft > 0 ? delayLeft : delay * delaySpeedMultiplier`; one frame; counts `delayLeft` down by `Time.deltaTime` each frame; fires unless cancelled. Runs on the relay itself |
| `OnLoadingGame()` (65-81) | Reads its entry; every output with `delayLeft > 0` restarts `delayTrigger` with the saved `delayLeft` |
| `OnSavingGame()` (56-63) | Writes its entry (`delayLeft` mid-count included) |
| `CancelPendingDelayedOutputs()` (137-148) | Sets `cancelDelayedOutputs`, zeroes every `delayLeft` |
| `disableOutputs()`, `disableOutput(int)`, `enableOutputs()`, `enableOutput(int)`, `toggleOutputs()`, `toggleOutput(int)` (150-211) | Set `output.disabled`; index -1 means all |
| `ChangeDelaySpeedMultiplier(float)` (213-216) | Sets the delay scale |

## Relay subclasses (`: Relay`)

| Class | File | Adds |
|---|---|---|
| `RelayOnEnable` | RelayOnEnable.cs | `OnEnable()` -> `triggerOutputs()` |
| `RelayOnDisable` | RelayOnDisable.cs | `OnDisable()` -> `triggerOutputs()` (the object is already inactive there, so the active check in `triggerOutputs` stops it unless only the component was disabled) |
| `RelayOnDestroy` | RelayOnDestroy.cs | `OnDestroy()` -> `triggerOutputs()` (same active check) |
| `RelayGoToPrison` | RelayGoToPrison.cs | Start: `Crime.OnGoingToPrison += triggerOutputs`; removed in OnDestroy and the finalizer |
| `RelayStartSelection` | RelayStartSelection.cs | `triggerOutputs` passes only when `StartManager.instance.HasSelectedStart(startSelectionId)` (inverted by `triggerWhenNotSelected`), or the id is empty |
| `RelayLookAt` | RelayLookAt.cs | `Update()`: fires while this object's position is inside `Camera.main`'s viewport (z > 0), unless fired once and `fireOnceOnly` |
| `RelayRandomDelay` | RelayRandomDelay.cs | Before firing sets each output's `delay` to `Random.Range(randomDelayMin, randomDelayMax)` (one value for all when `synchronous`) |
| `RelayOnDayChange` | RelayOnDayChange.cs | Saved `lastDay`, `active` (`active` is never read). `Update()` (unless `triggerOnlyOnMapChange`) and `OnMapChanged()` call `Trigger()` when `TimeOfDayAzure.currentTimeAndDay.currentDay > lastDay`; `Trigger()` fires and sets `lastDay` |
| `RelayTimer` | RelayTimer.cs | Below |
| `RelayLookProgress` | RelayLookProgress.cs | Below |

### RelayTimer

| Field | Saved | Meaning |
|---|---|---|
| `startActive`, `triggerOnlyOnMapChange`, `disableRetriggerOnLoad` | no | Settings |
| `time` (`TimeAndDay`) | yes | Duration: seconds, minutes, hours, current day used |
| `timer` (`TimeOfDayAzure.Timer`) | yes (`fsProperty`) | Game-time countdown, ticked by TimeOfDayAzure ([`time.md`](time.md)) |
| `done`, `triggered` | yes | Timer ran out; outputs fired |

| Method | Does |
|---|---|
| `Start()` (73-80) | `base.Start()`; `StartTimer()` when `startActive && !done` |
| `StartTimer()` (82-86) | Replaces `timer` with `new TimeOfDayAzure.Timer(OnTimer, (int)time.TotalSeconds)` |
| `OnTimer()` (106-115) | `done = true`, timer destroyed; `Trigger()` unless `triggerOnlyOnMapChange` |
| `Trigger()` (117-121) | `triggered = true`; `triggerOutputs()` |
| `OnSavingGame()` (32-40) | `timer.OnSaving()`, then Relay's save |
| `OnLoadingGame()` (42-58) | Relay's load, `timer.OnLoading()`, then `Trigger()` again if `triggered` (unless `disableRetriggerOnLoad`) |
| `OnMapChanged()` (60-71) | `Trigger()` when the timer ran out or `done` (unless `disableRetriggerOnLoad`) |
| `CancelTimer()`, `ResetState()`, `RestartTimer()` (88-104) | Destroy the timer; clear `done`/`triggered`; both |

### RelayLookProgress

Fires when the player has looked at it for `lookTime` seconds.
Saved: `progress` (0-1), `armed`. Settings (not saved):
`detectionMode` (`Crosshair`: ray from `Camera.main` hits `lookColliders`;
`ViewAngle`: within `viewAngle` degrees), `maxLookDistance` (20, 0 =
unlimited), `requireLineOfSight` with `obstructionMask`, `lookTime` (2),
`whenLookingAway` (`Decrease` at `decreaseSpeedMultiplier`, `Hold`,
`ResetInstantly`), `progressCurve`, `progressAnimator` +
`progressStateName` (animator scrubbed by progress, speed 0),
`onProgress` (`UnityEvent<float>`).

`Update()` (111-146): progress up while looking, else per
`whenLookingAway`; at 1 with `armed`: `armed = false`, `triggerOutputs()`;
at 0 re-arms. `ApplyProgress()` (212-221) on change, in Start and after
load. `ResetProgress()` (223-228).

## Other relay classes (not `: Relay`)

| Class | Base | Saved | Behaviour |
|---|---|---|---|
| `RelayAuto` (RelayAuto.cs) | MonoBehaviour | no | Start -> 3 frames -> reads `GlobalState.instance.GetState(globalStateKey)`: active -> `outputs`; missing and `initState` -> `outputs` and `SetState(key, stateOnInitIsTrue)`; else `outputsFalse`. `SetGlobalState(bool)`. Delays on its own coroutine with `WaitForSecondsRealtime`. No active check |
| `RelayDialogue` (RelayDialogue.cs) | MonoBehaviour | no | `RegisterDialogue()` registers Lua function `"Relay_" + relayName` -> `triggerOutputs`; `UnRegisterDialogue()`; OnDestroy unregisters. Registered by `InteractableTalk.OnDialogueStart` (InteractableTalk.cs:243-247), unregistered in `OnDialogueEnded` (335-339). Delays with `WaitForSecondsRealtime`. No active check |
| `RelayDialogueVariable` (RelayDialogueVariable.cs) | SavableScript (area file) | `firedOnce`, `outputs`, the expected values | Start -> 3 end-of-frames -> if `triggerOnStart`: reads `DialogueLua.GetActorField(actorName, varriableName)` or `DialogueLua.GetVariable(varriableName)`, compares by `valueType` (Boolean, Integer, Float within 0.0001, String), fires every output with `output.Fire()` |
| `RelayTaskStatus` (RelayTaskStatus.cs) | SavableScript (`global` chooses file) | `global`, `firedOnce`, `outputs` | **Awake** (when `automatic`): `TaskController.ObjectiveUpdated += Check`, `TaskController.TaskUpdated += Check`; removed in OnDestroy. Start (when `automatic` or `fireAtStart`) -> 4 frames -> `Check()`. `Check()`: `TaskController.instance.TaskIsStatus(task, taskStatus)` and, if any, `CheckObjectiveStatusInfos(objective)` -> `output.Fire()` each. No active check |
| `RelayRandom` (RelayRandom.cs) | SavableScript (`global`) | `global`, `firedOnce` | `TriggerRandomRelay()`: picks one `RandomRelay { Relay relay; float probability }` weighted by probability and calls `relay.triggerOutputs()`. `TriggerRandomRelays()`: `Random.Range(relaysToTrigger.x, relaysToTrigger.y + 1)` picks (the range is re-rolled each loop pass). `triggerAtStart` fires in Start (no delay) |
| `RelayRandomValue` (RelayRandomValue.cs) | SavableScript (`global`) | `global`, `firedOnce` | `Trigger()`: value = `Lerp(minValue, maxValue, probabilityCurve(Random 0-1))`; `IntOutput[i].Fire(RoundToInt(value))`, `FloatOutput[i].Fire(value)`. `triggerAtStart` fires in Start |
| `RelayPlayerDistance` (RelayPlayerDistance.cs) | SavableScript (area file) | `lastDay`, `startdone` | Start: `TimeOfDayAzure.DayChanged += DayChanged` (when `triggerOnDayChange`); `LoadDelay` unless `startdone`. OnLoadingGame: `LoadDelay`. `LoadDelay`: waits for `updateTimeDisabled` to clear, then fires `relayOnTriggered` (`triggerOnStart` only), or on a new day (`triggerOnStart && triggerOnDayChange`). `DayChanged(day)`: on a new day, fires when the player (`PlayerLocator.instance`) is at least `playerDistance` (40) away |
| `RelayWeekdays` (RelayWeekdays.cs) | MonoBehaviour | no | Start: `TimeOfDayAzure.MinutePassed += DeltaSeconds`; `StartDelay` -> `Check(ignoreDistance: true)`. Each game minute `Check()`: by `openingTimes.IsOpen()` fires `onOpen` or `onClosed` when the state changed (or on the first check), skipped while the player is within `playerDistanceOnOpen`/`OnClose` (40). `ForceCheck()` fires regardless. Removed in OnDestroy |
| `RelayJanitor` (RelayJanitor.cs) | SavableScript, `JanitorController.IJanitorable` | none written (no OnSavingGame) | Start and OnLoadingGameLatePrimary: `JanitorController.instance.AddJanitorAction(this)`; OnDestroy removes. `TriggerAction()`: `output.Fire()` each |
| `RelayBroadcast` (RelayBroadcast.cs) | MonoBehaviour | no | `Broadcast()`: for every MonoBehaviour under `target` whose type matches a wired call's target type, invokes that method by reflection (no argument). Actions cached after the first call; `ClearCache()` |
| `RelayOld`, `RelayApartment` | MonoBehaviour | no | `RelayOld.Trigger()`: `SendMessage(OnTrigger, Arg)` to one component. `RelayApartment`: empty marker |

## Trigger

`public class Trigger : MonoBehaviour` (Trigger.cs). Not saved. On
OnTriggerEnter/Exit/Stay from a collider whose tag is in `AllowedTags`:
`target.SendMessage(OnTriggerEnterCmd / ExitCmd / StayCmd)`; `target` is
`component` found on `gameObj` in Start. `triggerOnce`: `once` is set on
the first event of any kind, even one that does not match (49-53).

## TriggerMultiple

`public class TriggerMultiple : SavableScript` (TriggerMultiple.cs). A
trigger zone with `triggerOutput[] outputs`. Saves into the area's file.

| Field | Saved | Meaning |
|---|---|---|
| `triggerDisabled` | yes | Ignores all events (`TriggerDisabled` property) |
| `triggerOnce` | no | Each event kind fires once |
| `triggeredOnceEnter`, `Exit`, `Stay`, `AllExit` | yes | Which kinds fired |
| `triggerOnceFireOnLoad` | no | On load, fire again every kind already fired |
| `dontTriggerInWasteland` | no | Ignore while `SMVEffects.instance.IsWastelandIsActive()` |
| `allowedTags` | no | Default `{"Player"}` (Start also sets layer 25) |
| `requiredTaskItems`, `requiredObjectives` | no | Must pass |
| `delayedStart` | no | Ignore events for 5 frames after Start |
| `activeColliders` | no | Allowed colliders inside; the last one leaving fires `OnTriggerAllExit` |

| Method | Does |
|---|---|
| `OnTriggerEnter/Exit/Stay(Collider)` (146-173) | Track `activeColliders`; `ColliderTrigger(collider, kind)`; Exit of the last allowed collider also fires `OnTriggerAllExit` |
| `ColliderTrigger(...)` (197-235) | Checks disabled, init, wasteland, requirements, tag; with `triggerOnce` fires each kind once |
| `TriggerOutputs(kind)` private (237-256) | Each output of that kind (not fired when `fireOnceOnly`), while the component is enabled: `firedOnce = true`; delay -> `DelayTrigger` (own coroutine, `delayLeft` by `Time.deltaTime`), else invoke. **Does not check `triggerOutput.disabled`**: `disableOutput`/`enableOutput`/`toggleOutput` have no effect on firing (TriggerMultipleTrain does check it) |
| `OnLoadingGame()` (83-117) | Reads its entry; restarts delayed outputs with saved `delayLeft`; with `triggerOnce && triggerOnceFireOnLoad` fires again each kind already fired |
| `testOnTriggerEnter()` (293-297) | Treats the next event as Enter |

`TriggerMultipleTrain` (TriggerMultipleTrain.cs): the same for trains.
Fires only for a collider under a `TrackTrain` whose `|currentSpeed|` is
above `minumumSpeed` and at most `maximumSpeed` (-1 = no limit); no tags,
no task items, no AllExit, no fire on load; checks `disabled`.

## When things fire, in the game

| Moment | What fires |
|---|---|
| Area load, Start (+3 frames) | Relay/RelayTimer/RelayLookProgress with `triggerAtStart`; RelayDialogueVariable (`triggerOnStart`); RelayAuto (+3 frames); RelayTaskStatus (+4 frames); RelayRandom, RelayRandomValue (`triggerAtStart`, no delay); RelayPlayerDistance and RelayWeekdays (after `updateTimeDisabled` clears) |
| Area load, load steps | Relay and TriggerMultiple restart delayed outputs; RelayTimer re-fires if `triggered`; TriggerMultiple re-fires with `triggerOnceFireOnLoad`; RelayPlayerDistance `LoadDelay` |
| Area load, OnMapChanged | RelayTimer (ran out), RelayOnDayChange (new day) |
| Game clock | RelayTimer (`TimeOfDayAzure.Timer`), RelayPlayerDistance (DayChanged), RelayWeekdays (MinutePassed), RelayOnDayChange (Update) |
| Static events | RelayGoToPrison (`Crime.OnGoingToPrison`), RelayTaskStatus (`TaskController.ObjectiveUpdated`, `TaskUpdated`) |
| Lua | RelayDialogue (`Relay_<name>`, while its talk is open) |

## With areas kept loaded

The mod's steps: [`kept-areas.md`](kept-areas.md). Start runs on the
first visit, and on later visits only for the classes in `RUN_AGAIN`;
load steps on every visit, but on later visits not for classes with
`savedTimeAndDay` or that create objects; OnMapChanged on every visit;
coroutines stop when an area switches off; handlers on static events are
taken out on leaving (clock handlers kept only for classes with
`savedTimeAndDay`).

### Measured: relays fired on entering (2026-10-04)

`research_kept_scenario.rs` clears `firedOnce` on every relay of an area
that is not fire-once (every kind) while the area is away, goes through
the door, and lists the relays that fired; with `OBENSEUER_SAVE_AWAY=1`
it also clears them before a save in the area and lists what the game's
own load of that save fires. Tom_Tomato/Slot7:

| Area | Relays | Game's load | First kept door | Later kept door |
|---|---:|---:|---:|---:|
| Interior Player Tenement | 787 | 1 | 1 | 1 (the same one) |
| Open Sewer Tenement | 711 | 94 | 128 | 24 |

- The later kept door misses 74 of the game's 94: relays fired by the
  load of objects that keep the game's clock while away, so their load
  step is skipped on later visits: `Storage.LoadDelay` fires `onUpdate`
  and `onSpawnItems` (beer crates, bird nests, log storage, wine racks),
  `WorkableResourceSource.OnLoadingGame` fires `onStock` and
  `onCurrentStock` (breakable rocks' Relay1 to Relay4, wood piles'
  Stocklevel relays). It fires 4 the game's load did not (a kitchen oven,
  a bear trap's onload, a field kitchen, an electrical box's onTurnOn).
- The first kept door fires 105 the later one does not, more than the
  game's load: among them shop OnOpen and OnClose, the speakeasy's
  relay_start and relay_end, bridge doors, a RelayOnDayChange. Not
  explained yet (todo).
- The relays that fire at Start (`triggerAtStart`, plain Relay) fire on
  every kept door: 4 of 4 in Open Sewer Tenement on both doors; in the
  player's tenement the same 1 of 3 as the game's load (the other two
  are under switched-off objects).

| Class | Differs from the game |
|---|---|
| Relay, RelayDialogueVariable, RelayAuto, RelayRandom, RelayRandomValue, RelayTaskStatus (`fireAtStart`), TriggerMultiple (`triggerOnceFireOnLoad`), RelayTimer (re-fire on load) | Fire on the first visit only; the game fires them on every area load |
| Relay, TriggerMultiple delayed outputs (own coroutine) | Stop when the area switches off; never restarted (the game restarts them from `delayLeft` on load) |
| `output.Fire()` with a delay (RelayTaskStatus, RelayRandomValue, RelayDialogueVariable, RelayJanitor) | Runs on `GameController.instance`, which stays on: fires into the area left (not checked) |
| RelayTaskStatus | Subscribes in Awake, so areas loaded alongside and never entered are subscribed; `Check` has no active check: can fire outputs in an area the player never entered (not checked) |
| RelayOnEnable | OnEnable runs when an area loads alongside, before the mod switches it off in `sceneLoaded`: fires then (not checked); also on every kept door into the area, as on every game load |
| RelayOnDestroy | Never fires on leaving (nothing destroyed) |
| RelayPlayerDistance | `DayChanged` taken out while away (no `savedTimeAndDay`) and `LoadDelay` not re-run: day changes while away are not caught up |
| RelayWeekdays | `MinutePassed` taken out while away; back on entering, the first `Check` is not `ignoreDistance` (the game's load check is), so open/closed is not updated while the player is within 40 m |
| RelayTimer | Its `TimeOfDayAzure.Timer` is ticked by the live clock while away; `OnTimer` -> `triggerOutputs` does nothing in a switched-off area but sets `done`; `OnMapChanged` on the next visit fires it, as in the game |
| RelayOnDayChange | `OnMapChanged` on every visit catches up, as in the game |
