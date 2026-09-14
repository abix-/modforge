# Persistent AI players and native NPC behavior

[Research index](abiotic-factor.md) | [Todo](todo.md)

[Sophia readiness table](todo.md#sophia-readiness-playing-alongside-the-human)
is the single category-by-category status, done criteria and score record.

Read from the live hosted save on 2026-09-12 with the permanent tests in
tests/research_npc_navigation.rs (npc_navigation_systems, npc_follow_behaviour,
exor_soldier_setup, npc_perception_configs, player_combat_functions) and the
class traces in tests/http_health.rs. Research findings are decoded or observed;
design sections distinguish intended behavior from implemented capabilities.

## Direction: persistent AI players

User direction, 2026-09-13: Sophia is the first persistent AI player.
Companion describes her current allied role, not the scope of the shared
system. After Sophia can operate independently, a persistent enemy should
use the same capabilities with different relationships and goals.

The shared design must support identity, memory, perception, goals and
actions without assuming every AI player serves the human. Sophia's current
assignments express human commands. Later autonomous goals should use the
same action capabilities for exploration and resource collection. An enemy
should be able to pursue its own goals and react to what the human and
Sophia actually do. Shared rules belong in modforge, Unreal execution in
ueforge, and Abiotic Factor integration in this mod.

Persistence should eventually preserve consequential experience and
progression across encounters. Returning enemies should remember prior
encounters and change their decisions based on that experience. This is a
design goal, not verified adaptive behavior or implemented learning.
Return-after-defeat rules, progression and memory-driven decisions remain
to be designed. The existing fair-play direction applies to both sides;
memory and perception must not grant undiscovered world knowledge.

Sequence: finish reliable assignments and combat stances, then establish
Sophia's independent exploration and resource collection, then introduce
the first persistent enemy using those shared capabilities. Current work
does not implement autonomous collection, enemy progression or resurrection.

### Shared code and role boundaries

An AI player's persistent identity is distinct from its current body, team,
assignment and action. Becoming an enemy must not require a second copy of
perception, movement, combat or memory. Relationships determine which actors
are hostile and whose commands are accepted; stance determines when eligible
hostiles are attacked. Aggressive is not another word for enemy.

| Concern | Current owner | Boundary |
|---|---|---|
| Persistent identity and recorded observations | modforge/src/persona.rs | Existing profile, journal and seen records; not yet adaptive goal selection |
| Assignment and combat decisions | modforge/src/ai_orders.rs | OrdersDef and OrdersTracker work from the acting AI player's observations; no human faction is assumed |
| Unreal movement and combat execution | ueforge/src/behavior_tree.rs | AiOrderExecution applies the selected action through native engine operations |
| Order UI | ueforge/src/ui_ai_orders.rs | Presents the AI players eligible for commands; grouping does not confer allegiance |
| Abiotic perception, hostility and damage | abioticfactor-mod/src/orders.rs | Supplies targets relative to the acting character and native melee tasks |
| Current allied spawn setup | abioticfactor-mod/src/ai_player.rs | Copies human faction and supplies Follow/Defensive defaults; these are current spawn policy, not shared AI rules |

The order adapter accepts an initial definition from the spawn policy and
restores saved orders when present. The existing abiotic-orders.json shape
and ai_player command API remain unchanged by the naming alignment.
Persistent enemies are not currently spawnable through this allied operation.
Before introducing one, command selection must exclude AI players that do
not accept the issuing player's commands, including broad all/group commands.

Autonomous goal selection is future work. It must submit actions through the
same execution path instead of competing with assignment movement. Existing
persona and working-memory integration must be resolved in their existing
owners before adding adaptive decisions. Persistence alone is not learning.

## Current custom NPC type

The requested hierarchy is NPC_Base_ParentBP_C -> Modforge_AIPlayer_C,
with Sophia configured on the custom type. Ueforge creates the empty derived
class through Unreal's native construction, SetSuperStruct, Bind, StaticLink,
default-object creation and default-property initialization. It retains the
base NPC's functions and fields rather than cloning Grunt or Zombie behavior.
The class is transient and rooted for the process lifetime, and contains no
Rust callbacks that would become invalid when the mod reloads.
Sight-source registration uses NPC inheritance so the custom class is included
without requiring an NPC_ name prefix. The custom body has no Grunt gun to hide.

Abiotic supplies human mesh parts, a human animation asset, native melee
montages and the base AI controller. The initial controller tree only waits;
the existing orders path owns follow and the small native melee tree. The
current configuration still selects the Grunt stats row and melee montage
assets explicitly. The melee map is copied once into our class defaults;
new bodies inherit it without requiring the donor class at respawn. Those
data choices are not inheritance from the Grunt
body or controller. Native knife hits passed.

### Appearance and animation (accepted by the user 2026-09-14)

Sophia's body is scientist parts on SK_Human_Skeleton, the one skeleton every
human head, torso, skirt and hair mesh in the game shares: head SK_Head_F_02
(the female head the game's own narrative NPC wears), torso SK_Torso_Jacket_M,
SK_Legs_Skirt and SK_Hair_RuggedPonytail, each attached to the head mesh and
following its pose. The game ships five female heads (SK_Head_F_01 to 05) and
eighteen female torsos under Models/Characters/Scientist/Female; hair and
glasses are shared. No female animation blueprint or animation sequence
exists, so the animation asset is the same for either sex. The inventory
comes from tests/scientist_assets.rs against the live asset registry.

Her animation asset is AnimBP_Pillager_C, the Pillager's. The Pillager is a
child of NPC_Base_ParentBP_C (the engine's class check, in the same test file)
that wears scientist parts and stands, walks and fights. The two other human
assets on base NPC children were rejected: NPC_Coworker_AnimBP made her crawl,
and ABF_NarrativeNPC_AnimBP crashed the game calling the player-only function
IsUsingVehicle on her (the narrative human is not a base NPC child).

Every animation blueprint fills its Speed variable in its own update event
from the owning pawn's velocity, and the Pillager's does so only after casting
the owner to a Pillager. On Sophia the update ran and Speed stayed at zero
while she walked at 260, so no walk pose played. The fix is the pattern UE4SS
mods use (PD3-ZF-Laser, meccamod, rot-radar-minimap: a hook on
BlueprintUpdateAnimation that writes the variables itself): body.rs installs
one ProcessEvent hook on AnimBP_Pillager_C, and after each update whose owner
is Modforge_AIPlayer_C writes Speed from the pawn's velocity length. Real
Pillagers are untouched. Verified live: she walks with the Pillager asset.

Normal ai_player.start and respawn use the custom class. Live acceptance on
2026-09-13 passed class inheritance, following within 150 units, walk speed
260, kitchen knife attachment, attributed Sharp damage, Passive, explicit
Attack, self-defense and Recall. Saved orders survive replacement, and a
destroy/garbage-collect/recreate test passed. Tests are in base_npc.rs,
companion_orders.rs and companion_weapon.rs. The first trials exposed
unreflected component method names and rejection of the valid empty FName;
the component API diagnostic and live body assembly now pass.

The aggressive-sight regression remains unresolved in the current multi-level
test location. Its Pest fell to a lower floor; the revised encounter did not
pass either. Human-protection regression is blocked by the human being dead;
normal respawn requests did not complete. The new Actor damage observer has
passed self-defense independently. These are limitations of the acceptance
evidence, not a claim that every control is verified. Remote-client replication
of the runtime class has not been tested.

## Earlier proof: human Grunt

The earlier Sophia prototype used NPCSpawn_SingleGrunt -> NPC_Soldier_Grunt_C
with AI_Controller_NPC_Soldier_Grunt_C. Companion control builds a small tree from
native MoveTo, BTT_DoMeleeAttack and Wait tasks. It uses the game's combat
entry and focus support without the full Soldier or Zombie tree. Her persistent persona
is registered in the mod's named session; this path does not create a player
body or claim full player features. The spawner supplies NPC initialization.

The spawn operation copies the human's Faction to Sophia in the same
game-thread job, before her first combat tick. Leaving the Grunt faction
unchanged caused her to kill the human. The corrected live test returned
Faction=2 and Friend=true and observed no human combat target for ten seconds.
Friend=true does not disable the game's friendly-fire damage multiplier.

The user verified following and successful fights against a Pest and an
Exor on 2026-09-13. These are user-observed combat results. The earlier
automated Exor-body trial below failed and does not describe the current
Grunt companion. No custom attack loop or forced setup flag is required.

tests/companion_live.rs contains the live operations. NPC replacement uses
ai_player.stop/start; placement uses Actor.K2_TeleportTo and follow uses the
shared assignment controller. Normal UI respawn now replaces the NPC and restores
saved orders. The old research-only place operation still needs NPC adaptation.
Spawn now doubles the NPC walking speed, 130 to 260 for the Grunt, on both
the NPC and its movement component.
Inventory and skill work is stopped. The later lifecycle crash is undiagnosed.

## Crew control model: ATLAS research and agreed Sophia controls

Research date: 2026-09-13. User wants the concepts of ATLAS crew control,
not its radial menus or keybindings. This section describes documented
gameplay and the agreed Sophia model. ATLAS source code and DevKit graphs
were not inspected; no internal class layout or scheduler is claimed.

### What ATLAS documents

- Hired NPCs work aboard ships and accompany players ashore. Food and pay
  are part of their upkeep. [Developer description](https://store.steampowered.com/app/834910/ATLAS/).
- Crew can hold station assignments. Assigned crew ignore broad follow
  whistles while still accepting individually targeted whistles. Equipment
  is placed in their inventory and equipped separately from assigning work.
  [Community crew reference](https://atlas.fandom.com/wiki/Crewmember).
- Follow/stop/move commands, aggression stance, follow distance and command
  groups are separate controls. Neutral retaliates; passive does not defend;
  attack-my-target differs from a one-off attack-this-target command.
  [Community controls reference](https://atlas.fandom.com/wiki/Controls).
- Red Alert can interrupt station duty, and canceling it returns crew to
  previous seats. The developer explicitly documented restoring this feature
  in v102.4. [Developer patch roundup](https://store.steampowered.com/news/posts/?appids=834910&enddate=1562036462&feed=steam_community_announcements).
- Assigning crew to a wheel enables ship autopilot commands, illustrating
  that a station adds capabilities to a crew member.
  [Community autopilot reference](https://atlas.fandom.com/wiki/Autopilot).

The community references are gameplay documentation, not developer source.
Some controls differ between platforms. Historical patch notes establish
intent at that version, not proof that every later version behaves identically.
No claim is made that ATLAS has the exact chase limits proposed below.

### Agreed state for each companion

Accepted by the user on 2026-09-13; implementation is now authorized.
The first release includes Follow and Hold assignments; Aggressive,
Defensive and Passive stances; explicit Attack, Recall and Cancel attack;
follow distance, hold radius, chase distance and pursuit timeout; current
action/reason; and commands to one, selected or all eligible companions.
Named groups are part of command selection. Work-at-station is an explicit
future capability, not a fabricated working station integration.
Aggressive attacks perceived enemies on sight. Defensive reacts to attacks
on Sophia or her protected player (within the assignment's permitted area).
Passive never automatically retaliates. An explicit Attack overrides Passive
for that target only and leaves stance unchanged. Cancel attack returns to
normal stance rules; Recall suppresses all pursuit until back at the assignment.
Hold radius controls repositioning around the post; chase distance separately
limits combat excursions from it. Defaults are implementation defaults and
remain adjustable, not hidden changes to the user's stance or assignment.

Implementation defaults: Follow the spawning human; Defensive; follow distance
150, hold radius 75, chase distance 1200 (game world units); pursuit timeout 20
seconds. Assignment, stance, limits and groups are atomically saved in the
persona directory as abiotic-orders.json and restored on NPC replacement.
Temporary targets are runtime identities and are not saved as actor addresses.
Combat accepts living hostile characters and rejects friends and deployable
furniture. Native NPC hostility alone is insufficient: it included a water cooler
in the live sight test.

| What is recorded | Examples | Lifetime |
|---|---|---|
| Assignment | Follow Abix; hold this position; operate this station | Until explicitly replaced or invalidated |
| Combat stance | Passive; Defensive; Aggressive | Independent of assignment |
| Temporary order | Attack this enemy; recall to assignment | Until completed, canceled, superseded or blocked |
| Limits | Follow distance; maximum chase distance from player/post; pursuit timeout | Explicit companion settings |
| Group and command eligibility | Landing party; station crew excluded from broad follow orders | Resolved when an order is issued |
| Current action and reason | Returning to Abix; defending Abix; blocked by a closed door | Derived from actual execution |

Equipment determines whether an action is possible. Assigning an attack
must not silently provide ammunition or replace missing gear. Work assignments
can later name a station and its allowed supply source; this research does
not add ship systems, inventory or wages to Abiotic Factor.

An assignment and the currently executing action are different facts. While
Sophia defends Abix, her assignment remains Follow Abix. Combat completion
returns to the current assignment, not a saved obsolete movement request.
If the user changes the assignment during combat, the new assignment wins.

### Decisions and transitions

One controller decision path selects one movement/interaction action:

1. A dead or unavailable body cannot execute orders. Retain persona/intent
   separately from transient actor pointers; apply the chosen respawn policy.
2. Apply the latest explicit command. Recall cancels pursuit and prevents
   immediately reacquiring that target until return completes. Hold replaces
   the assignment with a fixed post; changing stance alone does not move it.
3. A valid explicit attack overrides automatic target choice, stays within
   configured limits, and ends when its target dies, becomes invalid, or
   cannot be reached within the pursuit timeout.
4. Automatic defense/assistance is allowed only by the selected stance and
   assignment limits. Passive never adds defensive attacks. Defend protects
   the companion and designated player/post, not every ally in the world.
5. Otherwise execute the assignment, or wait when already in position.
   No unrelated wandering, investigation, corpse eating or scavenging.

For a station assignment, broad follow commands should exclude stationed
crew by default and visibly report exclusions. A direct reassignment releases
the station. Temporary leave permission must be explicit; reserve the post
while temporarily absent and release it on death or permanent reassignment.
If the station is destroyed, report the assignment blocked rather than
choosing unrelated work. These are proposed rules, not verified ATLAS internals.

For the immediate Sophia fix, implement Follow, Hold, Recall, Attack, Cancel
attack, Passive, Defensive and Aggressive with follow/hold/chase limits.
Reuse native perception, path
following and melee execution. Existing src/tree.rs already builds a tree
combining a combat branch and follow movement. Adapt that path, replace the
independent follow timer, and give the follow target its own state rather
than sharing the game's AllyTarget used by other NPC behaviors. Merely
running the complete Zombie tree behind a gate still retains unwanted
behaviors inside that subtree; select the required combat behavior explicitly.

### UI and acceptance

Use a crew list with selection for one companion or a named group. Show
Assignment, Combat stance, Current action and any blocked reason together.
For example: "Sophia | Follow Abix | Defend | Returning after combat".
Provide direct Follow, Hold, Attack and Recall actions. Show affected crew
and excluded station workers before a group command. Keep assignment and
stance visible after selection changes; issuing a command must not quietly
change both. Implementation is in progress; live acceptance is required before
marking it shipped.

Shared ownership: modforge/src/ai_orders.rs owns the assignment, stance,
pursuit and return rules. ueforge/src/behavior_tree.rs owns the transfer between
native combat and path following; ueforge/src/ui_ai_orders.rs renders the controls.
The Abiotic adapter supplies perception, hostility, damage attribution and native
melee task selection. No full Zombie tree runs during an assignment.

First live integration exposed spawn initialization ordering: the NPC spawner
can return before creating its brain. Initialize through RunBehaviorTree and stop
the template in the same game-thread job before installing companion control.
Do not assume a returned controller already has a brain or blackboard.

Live checks on 2026-09-13: Hold remained within 100 units for eight seconds;
Passive did not initiate attacks; explicit Attack retained Hold and Passive and
dealt attributed Sharp knife damage. Native damage-response tests applied point
damage attributed to a Pest to the human and Sophia separately: Passive ignored
it, Defensive selected the attacker, and Recall returned to Hold with the tree
stopped. Group selection, invalid-limit rejection and saved orders across NPC
replacement passed. Aggressive acquired a perceived Pest and released pursuit
when it moved beyond the chase limit. The subsequent furniture/friend filter
change still needs its final live regression run.

Those defense checks used health-loss sampling and LastPointDamage. Source
now uses the shared native Actor damage observer, but live acceptance of that
replacement is pending. Multiple attackers, armor-absorbed attacks and
simultaneous healing are not established by the earlier results. The final
event-path acceptance remains in todo.md. UI rendering is implemented;
automated tests exercise its command path, not the visible ImGui panel.

Acceptance for the first implementation:

2026-09-13 19:12 regression: damage observer initialization initially blocked
all orders with "Actor.ReceiveAnyDamage unavailable". The observer now resolves
the declaring Actor class rather than searching the concrete NPC class for an
inherited function. After release deployment and restart, the permanent
follows_human_after_damage_observer_initializes test measured Sophia following
Abix at 147.4 horizontal units against a radius of 150. Damage-response tests
are still pending on this observer; successful initialization is not hit evidence.

- Follow reaches the selected distance and stays nearby without idle drift.
- Defending against a nearby Pest preserves Follow and returns afterward.
- A fleeing enemy beyond the chase limit cannot draw her away indefinitely.
- Recall interrupts pursuit without immediately restarting it.
- Hold remains anchored during permitted defense and after it ends.
- Passive prevents automatic retaliation without clearing the assignment.
- A new assignment during combat replaces the old return destination.
- Invalid targets, blocked paths and death produce an explicit reason and
  no stale movement or actor access. UI and runtime report the same assignment.

## The parts of an NPC

### Grunt ammunition and melee

Read-only Blueprint trace on 2026-09-13: the Grunt class defaults specify
MaxAmmoCount=20 and a reload montage. NPC_Base_ParentBP's reload event enters
its graph at 33719. Its completion paths assign CurrentAmmoCount directly
from MaxAmmoCount (3604/3613 and 3688/3697), with no inventory withdrawal in
those refill paths. The original armed Grunt therefore has replenishing NPC
ammunition with reload delays, not a finite inventory-backed bullet supply.
The trace used tests/http_health.rs::class_blueprint_research.

The Grunt declares melee attack montages, and the NPC base owns the melee
attack/damage functions. Reusing that attack is supported by the class;
Sophia now defaults to the kitchen knife mesh SM_Knife_01 attached to the
item row's r_weapon_melee1 socket. The spawn hides her gun, sets the ranged
flag false, and copies damage and damage type from ItemTable_Global's knife
row into her native NPC melee settings. Live attachment and repeat-equip
verification passed; the knife row supplies base damage 3. This is NPC
melee with a held knife, without inventory ownership or durability consumption.
The soldier attack tree ignored the ranged flag: a live Pest received 35
bullet damage attributed to Sophia. TryRangedAttackCheck checks cooldown and
target validity, not HasRangedAttack. The current implementation instead selects
the game's BT_Main_Zombie melee tree on the same Grunt body/controller and lets
combat movement take priority over following. Live acceptance passed on
2026-09-13 at 16:45: Pest health fell from 25 to 22, DamageCauser was Sophia,
DamageType was Sharp and IncomingDamage was 3. The encounter paused an
interfering security robot and restored its brain afterward. This verifies a
native melee hit, not player inventory ownership or durability. A finite-ammo
integration should retain the native aiming/attack AI, consume real rounds
when reloading, cap the loaded count to available ammunition, and block
ranged attacks when empty. Test zero, partial and full reloads plus exact
item consumption before claiming resource parity. This is proposed work,
not part of the current combat implementation.

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

Earlier player-body experiment, superseded by the Grunt path above: Epic's Lyra (LyraBotCreationComponent::SpawnOneBot), OpenTournament and
ShooterGame spawn the AI controller with bWantsPlayerState, then run the game
mode's DispatchPostLogin and RestartPlayer for it: the game mode spawns the
ordinary player pawn class and the AI controller possesses it. Player features
come from the pawn and the PlayerState, NPC features from the AI controller.
The earlier `ai_player.start` in src/ai_player.rs did this with the game's own classes;
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

## What an AI player takes from this

### Confirmed combat blocker, 2026-09-13

Historical Exor-body combat test: ai_player.start used NPCSpawn_QuillExor and
registers its existing controller as Sophia. The deployed code spawned
NPC_Monster_Exor_C with AI_Controller_NPC_Exor_C. SetupComplete=true and MyPawn
pointed to her NPC body; BT_Main_Exor was running. After handing it a freshly
spawned Pest with ForceSpotTargetImmediately=true, the Pest remained at 25
health for 30 seconds and the controller retained zero combat targets.
tests/companion_live.rs::sophia_npc_combat failed its damage assertion. This resolves
the body-dependent initialization failure, but does not prove combat works.
The user subsequently selected the Grunt and verified its combat, as recorded
above. Inventory/skill work is outside the current scope.

GitHub source review, 2026-09-13: the failed controller setup below is
confirmed, but choosing the player body as the solution was premature.
The common Abiotic_Character_ParentBP_C declares CharacterInventory, and
the native AbioticCharacter declares SkillLevelMap. Both player and NPC
bodies inherit these. The current local FModel exports confirm the inventory
declaration (Abiotic_Character_ParentBP.cpp:246); the Modkit native header
confirms SkillLevelMap (AbioticCharacter.h:93), matching progression.md.
The player adds CharacterEquipSlotInventory and CharacterHotbarInventory.
These declarations prove shared storage, not that an NPC's inventory,
XP acquisition, perk effects, equipment or persistence are initialized.
The next comparison must test those existing systems on an NPC before
committing to controller adaptation.

Live capability inspection found an NPC Pest with CharacterInventory already
present, MaxSlots=0, InitialInventorySize=0, and no items. Its SkillLevelMap
and StatModifierMap were empty. Inventory insertion/transfer is still unproven:
the test stopped before mutation because even the human's 72 inventory slots
decoded as empty objects. The permanent npc_inventory_layout diagnostic
identified PropertiesSize at +0x58 (Object=40, RowHandle=32, inventory slot=152),
while the mod configured +0xB0. SkillRowHandle also inherits its fields from
RowHandle, which the struct decoder did not walk. Source corrections cover
the game-specific size offset, inherited fields, and UserDefinedStruct lookup.
They require deployment and live verification before capability testing resumes.

External source examples inspected through GitHub CLI:

- [ShooterGame bot](https://github.com/Noesis/UE4-ShooterGame/blob/e56eb85c51752045980f0e2818e82a912bf31f48/Source/ShooterGame/Public/Bots/ShooterBot.h)
  inherits the shared shooter character with inventory and weapons; its
  [AI controller](https://github.com/Noesis/UE4-ShooterGame/blob/e56eb85c51752045980f0e2818e82a912bf31f48/Source/ShooterGame/Private/Bots/ShooterAIController.cpp)
  calls the character's existing weapon-fire functions.
- [OpenTournament character](https://github.com/OpenTournament/OpenTournament/blob/2e5d2b886f97f4584064e37872829500f122e3bd/Source/OpenTournament/Character/UR_Character.h)
  has inventory and ability interfaces; its separate bot controller obtains
  a player state. This is shared character capability with AI control.
- [Lyra player state](https://github.com/BulkheadLtd/Lyra_5_4/blob/db8015cccd495fac10c863825c54c0a2914878a0/Source/LyraGame/Player/LyraPlayerState.cpp)
  creates the ability system and grants pawn-data ability sets; its bot
  creation invokes normal game-mode player initialization and restart.
- [Abiotic SDK common character](https://github.com/igromanru/AF-CXXHeader/blob/ac22c24ea1f4392f9857cdc4599697ca6bfa297c/Abiotic_Character_ParentBP.hpp)
  exposes CharacterInventory, while native AbioticCharacter in AbioticFactor.hpp
  exposes SkillLevelMap. These external headers may be older; local matching
  declarations support the ownership finding. No working Abiotic NPC with
  full player progression was established by this search.

During the live Pest encounter, the function watch showed Sophia's
AddOrUpdatePotentialTarget receiving the Pest repeatedly, but her combat
target count stayed zero. tests/npc_live.rs::sophia_combat_setup read
SetupComplete=false and MyPawn=null on her Exor controller.

The permanent class_blueprint_research test decoded the controller's
AddOrUpdatePotentialTarget: byte 0 jumps straight to return at byte 790
when SetupComplete is false. No target validation or hostility check runs.
The controller's ExecuteUbergraph_Abiotic_AI_Controller_ParentBP, range
2950:6342, explains why: it gets its possessed pawn, casts it to
NPC_Base_ParentBP_C, and only on success assigns MyPawn, initializes the
blackboard and decision timer, and sets SetupComplete=true. Sophia is
Abiotic_PlayerCharacter_C, so the cast fails. The fallback checks for a
narrative NPC, then prints a setup error and exits. Starting a behavior
tree separately does not complete this setup.

The controller's melee path also calls TryMeleeAttackCheck on MyPawn
(byte 7647 onward); that function belongs to the NPC body class. A player
body cannot be made compatible merely by forcing the setup flag. The
remaining work is to compare NPC-body inventory/progression initialization
against player-body controller adaptation, then verify live combat and the
required player capabilities together. No setup fields were forced.

2026-09-13 live encounter setup: tests/npc_live.rs spawned a Pest beside
Abix using NPCSpawn_Pest and TrySpawnNPC(IsNight=false,
ForceSuccessByTrigger=true, CheckOnlyNoSpawn=false). The call returned
Success=true and SpawnedNPC; the returned actor had 25 health and its own
Pest AI controller, and the user confirmed it appeared. DebugSpawn's decoded
body only enumerates existing spawned AI and draws debug lines. CurrentNPCs
stayed empty after success, so it is not valid spawn acceptance evidence.
The existing npc.spawn operation still calls DebugSpawn; the live setup
test supplies the actual spawn request without redeploying the mod.

(Written when Sophia, the first persistent named character, was the only AI
player; every point holds for any of them.)

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

## An AI player's perception, as built (2026-09-13, on Sophia)

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
