# NPC AI: how enemies find targets and fight

[Research index](abiotic-factor.md) | [Todo](todo.md)

Read from the live hosted save on 2026-09-12 with the permanent tests in
tests/research_npc_navigation.rs (npc_navigation_systems, npc_follow_behaviour,
exor_soldier_setup, npc_perception_configs, player_combat_functions) and the
class traces in tests/http_health.rs. Everything below is decoded or observed;
guesses are marked.

## The parts of an NPC

| Part | Where it lives | Live count |
|---|---|---|
| Body: class, HP, speeds, damage, ranges, faction | DT_NPCList row | 120 rows |
| Perception: sight and hearing configs | AIPerceptionComponent on the NPC character | 49 components, 42 sight, 31 hearing configs |
| Target choice and memory | AI controller, parent Abiotic_AI_Controller_ParentBP_C | 23 controllers |
| Decisions | BehaviorTreeComponent + BlackboardComponent (BB_Main) | 12 each |
| Walking | PathFollowingComponent on the controller, over NavigationSystemV1 and 50 dynamic RecastNavMesh objects | 42 |

## Soldier rows (DT_NPCList)

| Row | Character class | Faction | HP | Walk / sprint | Melee dmg, range | Ranged dmg, range, cooldown | Doors |
|---|---|---|---|---|---|---|---|
| Exor | NPC_Monster_Exor | 5 | 175 | 180 / 400 | 70, 300 | 75, 50000, 1.4 s | opens, bashes |
| Exor_Armored | NPC_Monster_Exor_Armored | 5 | 600 | 200 / 600 | 50, 300 | 25, 50000, 1.4 s | opens, bashes |
| Exor_Monk | NPC_Exor_Monk | 5 | 85 | 180 / 700 | 50, 300 | 110, 50000, 1.0 s | opens, bashes |
| Exor_Pikeman | NPC_Exor_Pikeman | 5 | 325 | 180 / 570 | 50, 300 | 110, 50000, 8.0 s | opens, bashes |
| Grunt | NPC_Soldier_Grunt | 3 | 120 | 130 / 500 | 50, 150 | 35, 50000, 1.4 s | opens, bashes, downed state |
| Grunt_Captain | NPC_Soldier_Grunt (captain) | 3 | 120 | 130 / 500 | 50, 150 | ranged | as Grunt |

Exor damage type is DamageType_Sharp_C, Grunt DamageType_Blunt_Punching_C.
The row is read by tests/common/spawn_trace.rs table_rows, which walks the
table's row struct and row map directly; the generic dump op cannot decode
this build's Blueprint row structs.

## Perception numbers (live sense configs)

| NPC character | Sight radius | Lose sight | Field of view | Remember | Hearing |
|---|---|---|---|---|---|
| NPC_Monster_Pest_C | 800 | 1200 | 70 | 60 s | 400 |
| NPC_Monster_Peccary_C | 1600 | 2750 | 85 | 60 s | 750 |
| NarrativeNPC_Human_ParentBP_C | 3000 | 3500 | 90 | 10 s | none |
| class defaults, unnamed owners | 1000 to 2000 | 3000 to 3500 | 80 to 85 | 60 s | 500 |

The Exor's own numbers sit on its class defaults, not loaded in this save
area; the same test reads them once an Exor spawns or its class is loaded.

## Target acquisition (decoded)

1. The perception component fills the controller's
   LastSeenPotentialCombatTargetsList; the blackboard int
   PotentialCombatTargetCount says how many.
2. Tree service BTS_ChooseBestTarget_C runs on tick: if the count is above
   zero it calls the controller's BT_ChooseBestTarget.
3. BT_ChooseBestTarget reads blackboard TargetLocked and TargetActor, calls
   CheckForNewBestTarget, then for the current target casts to the
   I_Targetable interface, GetSpottablePoints, CheckLineOfSightToLocations,
   IsTargetInvisible, and writes blackboard LastKnownLocation,
   LastSawTargetTime, CanSeeTarget, HasHeardSound.
4. CheckForNewBestTarget calls CheckForBestTargetOnPerceptionList, then
   CheckCombatTargetValidity, then SetCurrentCombatTarget.
5. CheckForBestTargetOnPerceptionList scores every candidate: GetTargetPriority
   and GetDistanceTo divided by TargetPriorityMultiplier pick ClosestTarget;
   the AttackerList map (damage dealt per attacker) picks MostLethalTarget;
   FinalTarget is the most lethal when valid, otherwise the closest. A
   GrabbedByCharacter case wins outright.

## Fighting (decoded)

- Attack subtrees per NPC (BT_Attack_Pest, BT_Attack_Zombie, ...) use the
  shared tasks BTT_DoMeleeAttack_C, BTT_DoRangedAttack_C,
  BTT_DoCombatAbility_C, BTT_AttackCooldown_C, BTT_SetCombatState_C, and the
  chase subtree BT_MoveToTarget with the game's own BTTask_AbioticMoveTo and
  the BTS_CheckIfStuck_C service.
- The attack functions live on the character, so players and NPCs share
  them. On Abiotic_PlayerCharacter_C: DetermineMeleeSwingTarget,
  Request_MeleeAttackDamage (server, 5 params), Request_MeleeAttackFX,
  Request_FireProjectileWeapon (server, 4 params), Request_RangedAttack
  (server, 2 params), Local_DoMeleeAttack_Event, Try_AutoAttack (enters the
  character event graph at 141569: held item check, burst and fire delay
  timers, MeleeAttackSpeed_Multiply stat, then DetermineMeleeSwingTarget).

## The classes, read from the game's Blueprints (2026-09-13)

Exported with FModel (C:\code\FModel, mapping file AbioticFactor-1.4.0.usmap
from RevontuletCXVII/AbioticFactor-ModdingCommunity) from
pakchunk0-Windows.pak into C:\code\FModel\Output\Exports: Properties (.json)
and Decompiled Blueprints (.cpp, class layout only, no function bodies) for
the whole Blueprints/Characters tree.

```
AAbioticCharacter (native)
  Abiotic_Character_ParentBP_C   323 functions; AIPerception component; IsAI flag
    Abiotic_PlayerCharacter_C    784 functions; inventory, hotbar, skills, customization,
                                 Try_AutoAttack, Request_MeleeAttackDamage
    NPC_Base_ParentBP_C          306 functions; TryMeleeAttackCheck, FindBestMeleeAttack,
                                 ProcessMeleeHits, Server_DoMeleeAttack, NPCData stats
```

Abiotic_PlayerCharacter_C names Abiotic_AI_Controller_ParentBP_C as its
AIControllerClass with AutoPossessAI Disabled; NPC_Base_ParentBP_C names the
same controller with PlacedInWorldOrSpawned. Blueprints have one parent, so no
class can inherit both; the NPC attack functions exist only on
NPC_Base_ParentBP_C.

The published way to give one character player and NPC features is not a new
class. Epic's Lyra (LyraBotCreationComponent::SpawnOneBot), OpenTournament and
ShooterGame spawn the AI controller with bWantsPlayerState, then run the game
mode's DispatchPostLogin and RestartPlayer for it: the game mode spawns the
ordinary player pawn class and the AI controller possesses it. Player features
come from the pawn and the PlayerState, NPC features from the AI controller.
`ai_player.start` in src/ai_player.rs does this with the game's own classes;
the live test is tests/ai_player_live.rs. Live, 2026-09-13: the AI controller
gets a PlayerState (bWantsPlayerState set between begin and finish spawn)
carrying her name, so the players op lists her beside the human; its
PathFollowingComponent, which the controller Blueprint's defaults leave null,
is set through SetPathFollowingComponent before possession; RestartPlayer
spawns it an Abiotic_PlayerCharacter_C; and the character's own
TeleportPlayer, the call the decoded player spawn flow makes
(history/lan-spawn.md), places her at the first of the nine
Abiotic_WorldStart_C actors. The user saw the body at the world start.
`ai_player.follow` re-requests AIController::MoveToActor every two seconds;
the user watched her follow him around the facility ("it works. she follow
me around"). The character's possession handler casts its
controller to the player controller, so with an AI controller it leaves
MyPlayerState and MyPlayerController null and Request_SpawnMeInWorld never
runs: no player save loaded, no Client_SetupCharacter. The UDP client was
removed the same day; everything goes through the mod.

Two ueforge faults found on the way: a plain pointer write through an object
reference was dropped by the optimizer (write_class_bool now writes volatile
and checks the read-back), and the function parameter walker returned an
empty list for any Blueprint function with local variables, because it
required the field chain to end after the parameters (it now accepts the
declared parameter count).

A modkit for making new Blueprint classes in Unreal Editor 5.4 is cloned and
built at C:\code\AbioticModkit (AbioticExtended/AbioticModkit; UE 5.4 and
MSVC 14.38 installed for it). Not needed for the bot pattern; kept in case a
custom behavior tree task is needed later.

## What Sophia takes from this

- A perception component on her server-side character, where the enemies
  carry theirs, reading its currently perceived actors each cycle. No
  scans, no sphere queries; the perception system does the spatial work.
- A faction that Exor (5) and Grunt (3) treat as hostile, so their own target
  scoring picks her up and she picks them.
- Attacks through the character's own functions, called on the game thread
  on her server-side character, the way nav.find_path calls the navigation
  system. Whether a direct server-side attack call works on a UDP-owned body
  is untested; movement did not, attacks may, since they are events.
- Everything resolved once and cached, per docs/performance.md.

## Sophia's perception, as built (2026-09-13)

`ai_player.perceive` in src/perception.rs, all through the engine's own
callable functions:

1. `Actor::AddComponentByClass(AIPerceptionComponent, deferred)` on her
   server-side character. Deferred, because a perception component builds
   its sense filter and registers as a listener when it registers; senses
   added afterwards never enter the filter and the listener perceives
   nothing. That was the first, empty result.
2. For each sense config on a live NPC (the Exor when alive, otherwise the
   narrative human): `GameplayStatics::SpawnObject` creates her own config
   of the same class owned by her component, and every reflected field is
   copied over. `ConfigureSense` is not callable by name in this build.
3. `Actor::FinishAddComponent` registers the component; `OnRegister` sees
   the configs and registers the listener.
4. `ai_player.perceived` calls `GetCurrentlyPerceivedActors` and returns the
   engine's list. Live: the human's character and two cafeteria tables.

Affiliation: every live sense config detects enemies, neutrals and
friendlies (0b111). No controller carries a team id. Hostility is the
`Faction` byte on the character; the game's target choice reads it, the
perception system does not. So her perception reports everything in the
cone and the fight decision must filter by faction.

Known: cloning the monsters' configs (Pest, Peccary) crashed the game
three times; the narrative human's never did. Same class, same sense
implementation, ordinary values. Cause not established. Hearing therefore
still missing (only the monsters carry hearing configs). A plain actor
spawn of `NPC_Monster_Exor` killed the game within two seconds, twice; the
game's spawner Blueprints (`Abiotic_NPCSpawn_ParentBP_C`, `TrySpawnNPC`,
`DebugSpawn`) are the supported path and are the open row.
