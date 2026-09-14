# abioticfactor-mod status and open issues

## Sophia readiness: playing alongside the human

Updated 2026-09-13. This is the single readiness table for Sophia. Scores are
engineering assessments of demonstrated capability against each row's done
condition, not percentages, time estimates or a claim that the latest source
is deployed. 0 = no working capability established; 1-2 = intent/research;
3-4 = partial implementation; 5-6 = limited live proof; 7-8 = broad live proof;
9 = acceptance met with extended play pending; 10 = acceptance met repeatedly
in normal play. No overall average: strong combat cannot compensate for missing
resource collection or unresolved crashes.

Evidence: [current NPC body and design](npc-ai.md#current-custom-npc-type),
[control acceptance and limitations](npc-ai.md#ui-and-acceptance), and
[shared ownership and future work](npc-ai.md#shared-code-and-role-boundaries).
Earlier live results are retained below, but the latest damage observer and
friend filter still need live regression. Six shared decision tests and the
mod build pass; that does not establish full gameplay readiness.

| Category | Score | Current evidence / gap | Done when |
|---|---:|---|---|
| Join you in the world | 6/10 | Custom base-derived NPC spawn, replacement and destruction/GC/recreation passed; broader lifecycle reliability remains open | She joins beside you with one valid body and controller, repeatedly without duplicates or crashes |
| Be on your team | 6/10 | Copied faction and native friendship passed; latest friend-filter regression pending | She consistently distinguishes allies from enemies and never deliberately selects teammates as combat targets |
| Follow and keep up | 6/10 | Following and doubled walk speed observed; unrestricted travel and obstacle recovery unproven | She keeps the chosen distance across normal travel, resumes after combat and handles or reports blocked routes without wandering away |
| Hold, recall and pursuit limits | 6/10 | Fixed post, recall and chase-limit scenarios passed on earlier implementation | Hold stays fixed; recall ends pursuit; distance and timeout limits reliably return her to the current assignment |
| See and identify threats | 6/10 | Earlier native sight acquired a Pest; custom-body aggressive regression remains unresolved in the multi-level test location | Real perceived threats drive decisions; friends and fixtures are excluded; hearing and lost-sight behavior are verified |
| Fight with melee | 6/10 | User observed Pest/Exor fights; attributed native Sharp knife damage passed | She repeatedly approaches, hits and finishes reachable enemies, then resumes her assignment without operator setup |
| Passive, defensive and aggressive behavior | 5/10 | Custom-body Passive, explicit Attack, native-event self-defense and Recall passed; human protection is blocked by dead human and aggressive regression remains open | Passive ignores attacks, defensive protects self/designated player and aggressive engages perceived enemies, including multiple attackers and recall |
| In-game commands and status | 4/10 | UI exists and command API scenarios passed; visible panel not verified | You can join, assign, change stance, attack, recall and read blocked/dead status through the normal UI without diagnostic commands |
| Selection and groups | 4/10 | Group resolution tested; one named AI tested live | Selected/all/group commands affect only eligible AI players, tested with multiple bodies; future enemies reject human crew commands |
| Doors and world traversal | 2/10 | Native door capability identified; current body not accepted through closed doors | She opens permitted doors and navigates the routes needed to accompany you, with visible failure when passage is impossible |
| Explore independently | 3/10 | Earlier exploration prototype recorded visits; current assignments deliberately block the separate exploration loop | She chooses reachable unexplored destinations, travels and observes through the shared action path without conflicting movement |
| Collect and bring resources | 1/10 | Container travel and transfer milestones remain open | She reaches a resource/container, takes actual items and brings or deposits them at the assigned destination with exact counts |
| Own and manage inventory | 1/10 | NPC body does not yet have verified player-style item ownership | She holds, transfers and saves her own items without duplication or taking items from the human's save |
| Equip and maintain weapons fairly | 4/10 | Default knife mesh/socket and melee settings passed; ownership, swapping and durability absent | She equips owned weapons, swaps them correctly and applies the game's durability rules; ranged weapons consume real ammunition if enabled |
| Meet survival needs | 1/10 | Health participates in combat; hunger, thirst, fatigue and self-care remain unestablished | She recognizes needs and uses real food, water, rest and healing supplies to survive alongside you |
| Learn skills through play | 2/10 | Game progression research exists; Sophia's own skill progression is unimplemented | Her actions award her own XP and skills, persist correctly and affect her actual capabilities |
| Craft, build and station work | 0/10 | No working Sophia capability established; station assignments are future design | She performs assigned supported work through real game operations, consuming materials and retaining her assignment across interruptions |
| Participate in story and interactions | 1/10 | Intended scope recorded; progression ownership still needs research | Supported interactions and story triggers work for her without corrupting or silently substituting the human's progression |
| Remember observations | 4/10 | Profile, journal and seen records exist; current-body decision integration/restart proof remains incomplete | Observed knowledge survives restart and informs her decisions without granting knowledge she never acquired |
| Save and return as the same Sophia | 4/10 | Persona files and saved-order replacement exist; full character save identity is unresolved | Identity, knowledge, items and progression survive a game restart separately from the human's save |
| Recover from death | 4/10 | NPC replacement and restored orders passed; game-rule respawn/bed behavior is unimplemented | Death cleans up safely and respawn follows agreed game rules, preserving only the state those rules permit |
| Choose goals and adapt | 1/10 | Vision recorded; no accepted autonomous resource goals or experience-driven adaptation | She chooses useful goals from needs, assignments and remembered events, and changes decisions in response to outcomes |
| Stability during normal play | 3/10 | Targeted cleanup passed; historical crashes and last host-start disconnect remain unresolved | An extended ordinary session including travel, combat, death, replacement and restart completes without mod-caused crashes or orphaned actors |
| Later: persistent enemy AI player | 1/10 | Shared order code is role-neutral; enemy spawn, return and progression rules are future work | After Sophia's autonomy, an enemy reuses the same capabilities, retains encounter consequences and returns under agreed rules without accepting your commands |

Immediate priority: finish live acceptance of the latest combat/control changes
and resolve lifecycle failures. Then integrate exploration and real resource
collection. Later rows describe the agreed vision, not authorization to start
every feature at once. Keep scores here; use the backlog below for individual tasks.

## Project scope and backlog

What this is (operator, 2026-09-13): a system for adding AI players to any
Unreal game. The engine-generic parts live in ueforge (the AI player join,
reflection, loops, behavior trees from descriptions, blackboard access,
function watching); the engine-agnostic parts in modforge (persona: a
persistent named character with identity, journal and memory on disk under
Modforge/<name>, existing across games). This mod holds only what is
Abiotic Factor: class names, world starts, the character's own calls, the
hand-off into the game's controller. Sophia is the first persistent named
character; Charles and others follow. Sessions are kept by name and every
op takes `player`; more than one AI player in the world at once is
supported by the code and not yet exercised live.

Current decision 2026-09-13: Sophia uses our custom class derived directly
from the NPC base, with explicit human rendering and the base controller.
Her faction is copied from the human before the first combat tick. Follow,
native knife damage, self-defense and replacement passed. The earlier Grunt
prototype established combat against Pest and Exor; custom-body Exor combat
has not been rerun. See npc-ai.md and changelog.md.
Inventory, skills and player customization are deferred, not combat prerequisites.

Goal: play on Hard with scaled rewards, raise max skill level from 20 to 100.

Second goal: persistent AI players. Sophia is the first, currently an ally;
a recurring enemy follows after she operates independently. Both must reuse
identity, memory, perception and action capabilities, with different relationships
and goals. The long-term intent is a world that reacts to player actions and
retains consequences across encounters. See npc-ai.md for ownership and sequence.

An AI player lives in the same
world by the same rules as the human player. It knows the map layout and the
navigation mesh, but learns container contents and enemies only when it sees
them. Operator decision 2026-09-12: the AI player has no restrictions beyond
what breaks the game. Every action the human player can take, the AI player
can take, story triggers included. When it dies it respawns by the game's own
rules, and a bed it sleeps in moves its respawn point like anyone else's. It
levels its own skills by doing things. The next resource milestone is one AI
player that walks to a container and takes an item.

| Priority | System | Todo | Done when |
|---:|---|---|---|
| 1 | Custom-body control acceptance | [ ] Finish aggressive sight/chase and human-protection regression | Follow, native knife damage, self-defense, Recall, saved orders across respawn and destruction/GC/replacement pass. Aggressive fixture loses the intended enemy in the multi-level location; human is dead and normal respawn requests did not complete |
| 1 | Loaded class cache lifetime | [ ] Validate shared class cache entries against engine lifetime | Repeated custom-body spawn exposed an unavailable Grunt CDO after it was used only as an asset donor. Custom defaults now own the needed assets; separately audit the permanent-reference assumption in find_class_fast against unload/GC evidence |
| 2 | Persistent AI players | [ ] After reliable controls, develop Sophia's independent exploration and resource collection using shared actions | Sophia chooses and completes a resource goal from perceived or remembered information; world resources and her holdings change through verified game operations |
| 3 | Persistent enemy AI player | [ ] After Sophia's independent operation, reuse shared capabilities for a recurring enemy | A distinct identity retains encounter experience and reacts to player actions across encounters; return and progression rules are designed and tested before being claimed. Human all/group commands cannot control enemies |
| 2 | AI player memory and goals | [ ] Integrate existing persona records and working memory before autonomous decisions | One observation path supplies remembered knowledge to goal selection; decisions use existing actions and retain encounter consequences without a parallel memory store |
| 1 | AI player orders and following | [ ] Complete live verification of the approved model from npc-ai.md | Hold, Passive, explicit native Sharp damage, Recall, groups, saved-order respawn, defense and aggressive sight/chase limits passed on the earlier implementation. Final damage-event and furniture/friend-filter regressions remain pending. Artificial spawners request one NPC only |
| 1 | AI player defensive damage events | [ ] Verify the shared native damage-event replacement | Observer is implemented and builds. Live acceptance must cover attributed attacks on Sophia or her protected player, multiple attackers between ticks and armor-absorbed hits; earlier health-sampling results do not establish the new path |
| 1 | AI player doors | [ ] Establish whether she can open doors while following | NPC door opening is CanOpenDoors on NPC_Base_ParentBP_C, a player opens doors by interaction; decide which she uses when a closed door is on her path |
| 1 | AI player explore | [ ] Re-accept explore and memory on the AI controller's path following | explore.rs now asks GetMoveStatus for arrived; live acceptance on the bot body not yet run. Earlier on the UDP body: 12 things remembered, 9 visited in 40 seconds |
| 1 | AI player respawn/place controls | [ ] Adapt normal UI operations to the NPC body | The player-body respawn and teleport calls are obsolete. The live companion test currently replaces the NPC through stop/start and uses Actor.K2_TeleportTo. UI operations must use the NPC path |
| 1 | AI player customization | [x] Female scientist body and standing walk | 2026-09-14: head SK_Head_F_02, skirt, rugged ponytail on the human skeleton; AnimBP_Pillager with a BlueprintUpdateAnimation hook feeding Speed. User accepted the look and the walk live. Voice not done |
| 1 | AI player save | [ ] Her own player save: the game mode's native PostLogin derives the save id from the unique net id, which an AI controller lacks | Read what LoadPlayerSaveData and SavePlayerData need; do not collide with the human's save; preserve her existing character if one exists |
| 1 | AI player in-game controls | [ ] Join, respawn, follow, eyes, explore, memory, leave from the Sophia tab | Buttons dispatch ai_player.start/respawn/follow/perceive/perceived/explore/memory/stop. User has not yet confirmed the window and buttons |
| 1 | NPC AI research | [x] How enemies find targets and fight, and how a real NPC is defined | 2026-09-12: docs/npc-ai.md. Soldier rows from DT_NPCList, live perception numbers, decoded target scoring on Abiotic_AI_Controller_ParentBP_C, attack functions on the character |
| 1 | Monsters visible to sight | [x] Register loaded NPCs as sight stimuli sources | 2026-09-13: the game registers furniture, containers, corpses and players as sources, never monsters. ai_player.sources and every perception read call RegisterPerceptionStimuliSource once per NPC |
| 1 | AI player perception | [x] Give Sophia the enemies' perception component | 2026-09-13: ai_player.perceive adds AIPerceptionComponent to her character through AddComponentByClass with deferred finish, copies a live NPC's sense configs, then FinishAddComponent. ai_player.perceived returns GetCurrentlyPerceivedActors. Re-acceptance on the bot body pending |
| 1 | AI player senses from the Exor | [x] Sight and hearing on Sophia, the enemies' config classes | 2026-09-13: sight cloned from a live NPC (the Exor when alive, otherwise the narrative human); hearing built from the class defaults with the Peccary's numbers, because cloning the monsters' own config objects crashed the game three times |
| 1 | AI player affiliation | [x] Establish who her perception reports | 2026-09-13: every live sense config detects enemies, neutrals and friendlies; hostility is the Faction byte on the character read by the game's target choice. Perception reports everything in the cone; the fight decision filters by faction |
| 1 | AI player memory | [x] Remember everything she perceives, persistently | 2026-09-13: profile::Seen in seen.json next to her journal: per actor name, class, last location, first/last seen, times seen, visited. Written only from her perception rows |
| 1 | Saved world restart | [x] restart.ps1 hosts the existing local save | 2026-09-12: host.saved_world drives the decoded Continue menu path after IsLoggedIn passes; restart.ps1 -Save hosts the latest save |
| 1 | Host splash | [x] restart.ps1 gets past "press anything to begin" and the early-access notice | 2026-09-13: host.splash calls the master menu widget's own SplashKeyDown and Continue_EarlyAccess |
| 1 | `tests/research_ai_player.rs` | [x] Read the player character's movement values | Live 2026-09-11: JumpZVelocity 425, GravityScale 1.0, MaxStepHeight 45, WalkableFloorAngle 44.77, CrouchedHalfHeight 60, CapsuleRadius 32, CapsuleHalfHeight 96 |
| 1 | `src/ai_player.rs` | [ ] The AI player walks to a chosen container: a path from her character through the game's navigation | A live test names one container; she reaches it within interaction range |
| 2 | `src/ai_player.rs` | [ ] The AI player opens the reached container and takes one item | The container's item count falls by one and her inventory count rises by one |
| 2 | `tests/research_ai_player.rs` | [ ] Read the AI player's needs: hunger, thirst, fatigue, and health, with their offsets on the character | The test prints each value from her live character |
| 2 | `tests/research_ai_player.rs` | [ ] Read how story progression is keyed: game state or player state, and which player fired the last step | Decides how "story triggers included" behaves with two players |
| 3 | `tests/ai_player_live.rs` | [ ] Prove the AI player survives a restart of this game: same name, memory reload from her files | After a restart her first event references a container she opened before the restart |
| 1 | research | [x] Dump DT_SkillPerks: perk unlock levels and effects per skill | 101 perk rows confirmed, RequiredLevel field found via usmap |
| 1 | research | [x] Find max skill level and where it lives | No MaxLevel field in any struct. Level cap is a BP constant (20). SkillLevelMap at offset 2016, 48-byte entry stride, level at entry+32 |
| 1 | research | [x] Find XP curve: what XP is needed per level, how to extend it to level 100 | Vanilla table from wiki, flat 10,900 delta for 21-100. Documented in progression.md |
| 1 | research | [ ] Find difficulty settings on GameMode or GameInstance | Difficulty fields listed with their types, offsets, and current values on a Hard save |
| 1 | mod | [ ] Raise skill cap to 100: hook XP award, bypass BP level cap check, write levels to SkillLevelMap | Skills can level past 20, confirmed by reading SkillLevelMap after XP gain |
| 2 | research | [ ] Find XP gain functions: what calls Server_TryAwardSkillXPOnTargetable, base rates | XP award call chain documented, base XP amounts per action type identified |
| 2 | research | [ ] Dump DT_DamageDefinitions: damage types and scaling values | Damage table rows documented, relationship to difficulty understood |
| 2 | research | [ ] Dump DT_BuffsDebuffs: buff/debuff values for potential reward scaling | Buff table rows documented, viable candidates for Hard reward buffs identified |
| 3 | mod | [ ] XP multiplier: scale XP gains on Hard to reward the challenge | XP gains on Hard are measurably higher than Normal |
| 3 | mod | [ ] Loot/reward scaling: better drops or crafting yields on Hard | Crafting or loot yields on Hard are measurably better |
| 3 | mod | [ ] Persist tweaks via tweaks.json (survives hot reload) | Tweaks survive Ctrl+R reload without manual re-apply |
| 1 | NPC lifecycle crash | [ ] Diagnose the 2026-09-13 15:54:33 crash | Access violation occurred after the hostile Grunt encounter, before the stop-AI diagnostic started. Cause is unconfirmed; faction assignment is not a proven crash fix |
| 1 | Companion finite ammo | [ ] Replace free NPC reloads with real ammunition consumption when implemented | Current reload assigns current ammo from maximum. Require zero, partial and full reload tests, exact round consumption and no firing when empty; reuse native combat AI |
| 2 | Companion melee equipment | [ ] Implement knife ownership and durability when requested | Default knife attachment, doubled spawn speed and a native sharp melee hit passed. Inventory ownership and durability consumption remain unimplemented |
