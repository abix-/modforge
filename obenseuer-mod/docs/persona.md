# A police NPC as a modforge person

> **Authoritative on:** which of Obenseuer's own calls a modforge
> PersonaBinder uses for one police NPC: what it reads for the person's
> Perception and what it calls to carry out the brain's actions. The
> facts about each class live in [`npcs.md`](npcs.md) and
> [`crime.md`](crime.md). Read from the decompiled Assembly-CSharp
> (0.4.17), not yet seen in the game.

Operator, 2026-11-20: "taking one of the existing NPCs in these games and
making it smart... enhancing the existing gameplay instead of adding
crazy new things." The NPC keeps its body and its job (its `Act_Police`
activity); its modforge Persona decides on top. Which parts are used is
Claude's reading, for the operator to change.

## The NPC

| Part | Class | Where |
|---|---|---|
| The NPC object | `NPCInfo` | [`npcs.md`](npcs.md), NPCInfo |
| Who it is | `NPCController.ID` (its `character.ID`), the `NPCData` from `NPCDirector.GetNPCDataByID` | [`npcs.md`](npcs.md), NPCController |
| What moves it | `NPCInfo.npcController` (`NPCController`, A* Pathfinding) | [`npcs.md`](npcs.md), NPCController |
| What it sees | `NPCInfo.npcFov` (`NPC_FOV`) | [`npcs.md`](npcs.md), NPC_FOV |
| Its job | `Act_Police`, its `CurrentActivity`, in `Crime.activePolices` | [`crime.md`](crime.md), Act_Police |

## Perception: what the binder reads

| Perception | From |
|---|---|
| where it is | the NPC object's `transform.position` |
| the player, seen | `NPC_FOV.PlayerDetected`, or `CheckIfPlayerIsDetected()` |
| other NPCs, seen | `NPC_FOV.CheckIfNPCsAreDetected(out ...)` (it tests its own head: game bug, [`npcs.md`](npcs.md), NPC_FOV) |
| things, seen | `NPC_FOV.TargetDetected` for `targetsToDetect` |
| the hostile | the player while `Act_Police.state` is ChasePlayer |
| where it is asked to be | its post, `Act_Police.center` |

## Actions: what the binder calls

| Brain action | Call |
|---|---|
| Go | `NPCController.SetTargetPosition(position, minDistance)` |
| follow the player | `NPCController.FollowPlayer(run, canBeInterrupted, visibilityTimeEnabled)` |
| stand at its post | `NPCController.StartStand(group)` |
| chase or question (its job) | `Act_Police.StartChase()`, `StartChaseQuestion()` |
| stop and start moving | `NPCController.DisableMoving(gameObject)`, `EnableMoving(gameObject)` |
| start or stop an activity | `NPCController.StartActivity(activity, interrupt)`, `ForceStartActivity`, `ForceStopActivity` |

Not found yet: its health and needs (the `Stats` an NPC carries), what
it carries, and how the brain's Attack becomes an arrest (Act_Police
arrests within 1.25 m while chasing, [`crime.md`](crime.md)).
