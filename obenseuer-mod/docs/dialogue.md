# Dialogue

> **Authoritative on:** the game's glue around the Pixel Crushers Dialogue
> System: `DialogueController` (UI, input, open and close),
> `InteractableTalk` (talking to an NPC), `DialogueVariable`,
> `DialogueCondition`, `DialogueCommonMethods` (Lua functions, dialogue
> timers), `DialogueEventSystem`, `CharacterBarkStarter`, the Lua
> functions the game registers, and where dialogue state is saved.
> The Dialogue System's own classes (DialogueManager, ConversationTrigger,
> DialogueSystemTrigger, BarkStarter) are in its own assembly and not read
> here.
>
> Index of every game system's doc: [`research.md`](research.md).

## Dialogue state

Variables and actor fields live in the Dialogue System's Lua environment
(`DialogueLua.GetVariable(name)`, `GetActorField(actor, field)`,
`SetVariable`). Saved as `Globals.dialogue` (`PersistentDataManager
.GetSaveData()`) by `SaveGame`, applied at the end of a load with
`PersistentDataManager.ApplySaveData` ([`save.md`](save.md)). Game time
writes the Lua variable "Day" each day ([`time.md`](time.md)).

## DialogueController

`public class DialogueController : MonoBehaviour` (DialogueController.cs).
Its place in the scene is not read; Game_Logic has a "Dialogue Manager"
child ([`areas.md`](areas.md)).

| Member | Meaning |
|---|---|
| `static DialogueController instance` | Awake (58-61) |
| `bool DialogueActive` | A conversation is open |
| `DialogueSystemController dialogueSystem` | The Dialogue System |
| `InteractableTalk currentInteractableTalk` | Who the player talks to (`SetCurrentInteractableTalk`) |
| `Action onDialogueClosed` | Called on close |
| `CheckDialogueStatus()` (194-204) | Opens or closes to match `dialogueSystem.IsConversationActive` |
| `OnDialogueOpen()` (206-218) | Hides the game menu, `PlayerStats.Active = false`, controls disabled, use text off, UI shown |
| `OnDialogueClosed()` (220-231) | Reverse; `onDialogueClosed()`; `DialogueActive = false` 0.01 s realtime later |
| `DisableContinue`, `EnableContinue`, `SetContinueDisabled`, `SetCharacterSound`, `SetSalsaAudio`, `SetSalsaTextSync` | UI and lip sync |

`DeleteOtherDialogueManagers` (DeleteOtherDialogueManagers.cs): in Awake
and Start destroys every other `DialogueSystemController` found with
`FindObjectsOfType` (active only), then removes itself. Where it sits is
not read.

## InteractableTalk

`public class InteractableTalk : Interactable` (InteractableTalk.cs). On
NPCs and talkable objects.

| Member | Meaning |
|---|---|
| `static List<InteractableTalk> interactableTalks` | Every talk that ran Start; removed in OnDestroy (81-110); read by `Character` (Character.cs:271-371) |
| `static InteractableTalk CurrentInteractableTalk` | |
| `bool talkDisabled`, `allowSmvTalk`, `onlySmvTalk`, `hideName`, `hasToKnowTheName`, `dontLookAtPlayer`, `dontLookAtTarget`, `disableLookAt` | Options |
| `Relay onStartTalk`, `onEndTalk`, `onVoiceClip`; `Action onStartTalkCallback`, `onEndTalkCallback` | |
| `RelayDialogue[] dialogueRelays`, `DialogueCondition[] dialogueConditions` | Registered while talking |
| `ConversationTrigger conversationTrigger` | Dialogue System trigger on the same object |
| `CanTalk()` (147-178) | Not disabled, no contest, wasteland rules, player on ground, not waiting or sleeping, the NPC not using a door |
| `Interact()`, `StartDialogue(string)`, `ForseStartDialogue(string)`, `CheckStartDialogue`, `StartDialogueInterrupt`, `CheckStartDialogueInterrupt(string, bool force, bool ignoreMenuState)` | Start a conversation |
| `OnDialogueStart(string, bool)` (236-298) | Returns when not `activeInHierarchy`; registers `dialogueRelays` ("Relay_<name>") and `dialogueConditions` ("Condition_<name>") and the item manager; fires `onStartTalk` |
| `OnDialogueEnded()` (332-) | `PlayerStats.Active = true`; unregisters them |

## DialogueVariable

`[Serializable] public class DialogueVariable` (DialogueVariable.cs). A
condition or setter on one Lua variable, used by Relay requirements and
NPC reactions.

| Member | Meaning |
|---|---|
| `string actorName`, `variableName` | Empty actor: a variable; else an actor field |
| `CompareType compareType` | Default, LessThanFloatValue, MoreThanFloatValue, BoolAsFalse, LessOrEqualFloatValue, MoreOrEqualFloatValue, EqualFloatValue, NotEqualFloatValue, BoolEqualsValue, BoolNotEqualsValue, EqualStringValue, NotEqualStringValue |
| `float compareFloatValue`, `string compareStringValue` | |
| `FloatCompareType floatCompareType` | Default, subtractVariableFromCurrentDay, subtractCurrentDayFromVariable, addToCurrentDay, absoluteDifferenceWithCurrentDay |
| `VariableType variableType` (Bool, Int, Float, String), `boolValue`, `intValue`, `floatValue`, `stringValue` | For setting |
| `bool IsTrue()` (66-73), `static bool IsAllTrue(List)` (143-) | Compare |
| `ChangeValue()` (163-), `static ChangeAllValues(List)` (155-) | Set |

## DialogueCondition

`[Serializable] public class DialogueCondition` (DialogueCondition.cs):
`name`, `DialogueConditionStatus status`, `TaskItem taskItem`, `int
taskItemAmount`. `Check()`; `Register()` registers Lua
"Condition_<name>" -> `Check`; `Unregister()`.

## DialogueCommonMethods

`public class DialogueCommonMethods : SavableScript`
(DialogueCommonMethods.cs). GUID const "DialogueCommonMethods"; saves into
Globals.

| Member | Meaning |
|---|---|
| `Dictionary<string, DialogueTimer> timers` | Named game-time timers (`name`, `minutes`, `completed`, `TimeOfDayAzure.Timer timer`) |
| `OnSavingGame()` / `OnLoadingGame()` (35-61) | `timer.OnSaving()` / `timer.OnLoading()` for each |
| Lua (74-90) | `GenerateRandom(r)`, `GetGeneratedRandom()`, `GetRandom(r)`, `SkillCheck(skill, failChance)`, `GetSkillLevel(skill)`, `CreateTimer(name, minutes)`, `RemoveTimer(name)`, `CheckTimer(name)`, `SetWaveEffect(bool)`, `SetWaveEffectIntensity(double)` |
| `CreateTimer(name, minutes)` (166-182) | New timer, or resets an existing one |
| `TimerExpired(Timer)` (218-) | Marks it `completed` |

## DialogueEventSystem

`public class DialogueEventSystem : ScriptableObject`
(DialogueEventSystem.cs): methods wired from dialogue events:
`GiveRecipe(id)`, `TaskGiveStartRenovation5(bool)`, `AddMoneyOC/RM`,
`RemoveMoneyOC/RM`, `GoToPrison(float)`, `Commit<Harassment, Violence,
Trespassing, Vandalism, Terrorism, Administrative>Crime(int)`,
`GiveItem(int)`, `RemoveTaskItem(TaskItem)`, `DamagePlayerViolence(float)`,
`TriggerAchievement(string)`, `GiveStolenItemsAndReturnHalfOfOC(owner)`,
`SellReceipts...`, `ChangeInteractableTalk(int)`.

## Barks

`CharacterBarkStarter : BarkStarter` (CharacterBarkStarter.cs):
`TryToComment(conversation)`, `TryToCommentLookAtPlayer(conversation)`,
`TryToCommentLookAtPlayer5s(conversation)`: optional head turn, then
`TryBark(transform)`.

## Lua functions registered by game classes

| Class | Functions | Bound to |
|---|---|---|
| Crime | `GetSentenceLengthPreArrest`, `GetSentenceLength`, `GetCrimeAmount`, `GetCrimeFineAmount`, `CountStolenGoodsValue`, `GoToPrison`, `TeleportToPrison`, `PayFine`, `CanPayFine`, ... | The live Crime ([`crime.md`](crime.md)) |
| TenementController | `CanRentApartment`, `ResidentRentedAmount`, `UpgradesStarted`, `ResidentRented`, `ResidentApartmentLevel`, `ResidentApartmentUpgradeLevel`, `TenementGeneralUpgradeLevel`, `ApartmentUpgradeLevel`, `StartApartmentCleaningTimer` | The live TenementController ([`tenement.md`](tenement.md)) |
| NPCManager | `ChangeInteractableTalk`, `LookAtNamedTarget`, `LookAtNPC`, `LookAtPlayer` | The copy whose Awake ran last ([`npcs.md`](npcs.md)) |
| DialogueCommonMethods | listed above | |
| RelayDialogue | `Relay_<relayName>` | While its talk is open ([`relays.md`](relays.md)) |
| DialogueCondition | `Condition_<name>` | While its talk is open |
| JanitorController, Act_Police, CharacterItemManager | their own | |

## With areas kept loaded

- `Lua.RegisterFunction` binds an instance; NPCManager's functions stay
  bound to the copy whose Awake registered them. With area-owned
  NPCManagers (kept-areas.md, rule 1), whether `LookAtNPC` etc. search
  the entered area's NPC list is not checked.
- `InteractableTalk.interactableTalks` keeps the talks of every kept area
  entered (nothing destroyed).
- `DeleteOtherDialogueManagers` searches active objects only; an area
  loaded alongside wakes while active; what it destroys then is not
  checked.
- Dialogue System triggers that fire on Start (in its own assembly) run
  on the first visit only (Start runs once); not read.
