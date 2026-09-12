# abioticfactor-mod open issues

Goal: play on Hard with scaled rewards, raise max skill level from 20 to 100.

Second goal: an AI player. A second player character that lives in the same world by the same rules as the human player, driven by the shared bot through player input. The first shipped state is one AI player that walks to a container and takes an item.

| Priority | System | Todo | Done when |
|---:|---|---|---|
| 1 | `tests/research_ai_player.rs` | [ ] Read the navigation data from a loaded save: the navigation mesh actor, its bounds and tile count, and every nav link object | The test prints the RecastNavMesh actor with bounds and tile count and the NavLinkProxy count from the live game |
| 1 | `tests/research_ai_player.rs` | [ ] Read the player character's movement values that decide jump and crouch links: jump speed, gravity scale, capsule radius and half height, crouched half height, max step height, walkable floor angle | The test prints each value with its offset from the live character movement component and capsule |
| 1 | `tests/research_ai_player.rs` | [ ] Read the Enhanced Input setup: the count of EnhancedInputLocalPlayerSubsystem instances and the input action names for move, look, jump, crouch, sprint, and interact | The test prints one subsystem and the six action names from the live game |
| 1 | `tests/research_ai_player.rs` | [ ] Read the split-screen setting from the game maps settings object | The test prints the bUseSplitscreen value from the live game |
| 1 | `tests/research_ai_player.rs` | [ ] Create a second local player through GameplayStatics CreatePlayer in a loaded save and record what appears | The test prints the second character, its controller, and the subsystem count after the call, and the game still answers 60 seconds later |
| 1 | `src/ai_player.rs` | [ ] Move the AI player's character with W through its own Enhanced Input subsystem | A live test holds W for two seconds and the AI player's character moves at least 100 units while the human player's character does not move |
| 1 | `src/ai_player.rs` | [ ] Travel the AI player's character to a chosen container through the shared route and player input | A live test names one container, the route reaches it within interaction range, and every held key is released |
| 2 | `src/ai_player.rs` | [ ] Open the reached container and take one item with the AI player's own interact input | The container's item count falls by one and the AI player's inventory count rises by one |
| 2 | `tests/research_ai_player.rs` | [ ] Read the AI player's needs: hunger, thirst, fatigue, and health, with their offsets on the character | The test prints each value from the live second character |
| 3 | `src/ai_player.rs` | [ ] Keep the AI player's event log in a file per save: kills, deaths, containers opened, items taken, each with place and time | After a restart the test reads the file back and the last entry matches the last live event |
| 1 | research | [x] Dump DT_SkillPerks: perk unlock levels and effects per skill | 101 perk rows confirmed, RequiredLevel field found via usmap |
| 1 | research | [x] Find max skill level and where it lives | No MaxLevel field in any struct. Level cap is a BP constant (20). SkillLevelMap at offset 2016, 48-byte entry stride, level at entry+32 |
| 1 | research | [x] Find XP curve: what XP is needed per level, how to extend it to level 100 | Vanilla table from wiki, flat 10,900 delta for 21-100. Documented in abiotic-factor.md |
| 1 | research | [ ] Find difficulty settings on GameMode or GameInstance | Difficulty fields listed with their types, offsets, and current values on a Hard save |
| 1 | mod | [ ] Raise skill cap to 100: hook XP award, bypass BP level cap check, write levels to SkillLevelMap | Skills can level past 20, confirmed by reading SkillLevelMap after XP gain |
| 2 | research | [ ] Find XP gain functions: what calls Server_TryAwardSkillXPOnTargetable, base rates | XP award call chain documented, base XP amounts per action type identified |
| 2 | research | [ ] Dump DT_DamageDefinitions: damage types and scaling values | Damage table rows documented, relationship to difficulty understood |
| 2 | research | [ ] Dump DT_BuffsDebuffs: buff/debuff values for potential reward scaling | Buff table rows documented, viable candidates for Hard reward buffs identified |
| 3 | mod | [ ] XP multiplier: scale XP gains on Hard to reward the challenge | XP gains on Hard are measurably higher than Normal |
| 3 | mod | [ ] Loot/reward scaling: better drops or crafting yields on Hard | Crafting or loot yields on Hard are measurably better |
| 3 | mod | [ ] Persist tweaks via tweaks.json (survives hot reload) | Tweaks survive Ctrl+R reload without manual re-apply |
