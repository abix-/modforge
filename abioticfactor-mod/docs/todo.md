# abioticfactor-mod open issues

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

Current decision 2026-09-13: Sophia uses the human Grunt NPC body and its
own soldier AI, spawned through NPCSpawn_SingleGrunt. Her faction is copied
from the human before the first combat tick. The user verified following
and successful combat against both a Pest and an Exor. No UDP client or
RestartPlayer is used for this body. See npc-ai.md and changelog.md.
Inventory, skills and player customization are deferred, not combat prerequisites.

Goal: play on Hard with scaled rewards, raise max skill level from 20 to 100.

Second goal: an AI player. A second player character that lives in the same
world by the same rules as the human player. It knows the map layout and the
navigation mesh, but learns container contents and enemies only when it sees
them. Operator decision 2026-09-12: the AI player has no restrictions beyond
what breaks the game. Every action the human player can take, the AI player
can take, story triggers included. When it dies it respawns by the game's own
rules, and a bed it sleeps in moves its respawn point like anyone else's. It
levels its own skills by doing things. The first shipped state is one AI
player that walks to a container and takes an item.

| Priority | System | Todo | Done when |
|---:|---|---|---|
| 1 | AI player doors | [ ] Establish whether she can open doors while following | NPC door opening is CanOpenDoors on NPC_Base_ParentBP_C, a player opens doors by interaction; decide which she uses when a closed door is on her path |
| 1 | AI player explore | [ ] Re-accept explore and memory on the AI controller's path following | explore.rs now asks GetMoveStatus for arrived; live acceptance on the bot body not yet run. Earlier on the UDP body: 12 things remembered, 9 visited in 40 seconds |
| 1 | AI player respawn/place controls | [ ] Adapt normal UI operations to the NPC body | The player-body respawn and teleport calls are obsolete. The live companion test currently replaces the NPC through stop/start and uses Actor.K2_TeleportTo. UI operations must use the NPC path |
| 1 | AI player customization | [ ] Deferred: human appearance and voice on the Grunt body | Establish NPC-compatible customization when requested; player-character RPCs are not validated here |
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
| 2 | Companion speed persistence | [ ] Preserve configured walking speed across respawn | Current live Sophia uses 260 instead of 130; the live test changes this instance only |
| 1 | Companion finite ammo | [ ] Replace free NPC reloads with real ammunition consumption when implemented | Current reload assigns current ammo from maximum. Require zero, partial and full reload tests, exact round consumption and no firing when empty; reuse native combat AI |
| 2 | Companion melee equipment | [ ] Establish how to equip a player melee weapon on the Grunt | Built-in melee exists; weapon attachment, animations, damage and durability for player items are unverified |
