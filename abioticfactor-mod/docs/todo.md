# abioticfactor-mod open issues

Goal: play on Hard with scaled rewards, raise max skill level from 20 to 100.

Second goal: an AI player. A second player character that lives in the same world by the same rules as the human player, driven by the shared bot through player input. The first shipped state is one AI player that walks to a container and takes an item.

| Priority | System | Todo | Done when |
|---:|---|---|---|
| 1 | `tests/research_ai_player.rs` | [ ] Read the navigation data from a loaded save: the navigation mesh actor, its bounds and tile count, and every nav link object | The test prints the RecastNavMesh actor with bounds and tile count and the NavLinkProxy count from the live game. Live 2026-09-11: 50 RecastNavMesh actors, 1 NavMeshBoundsVolume, 0 NavLinkProxy; tile count not read yet |
| 1 | `tests/research_ai_player.rs` | [ ] Print agent radius, height, and step height for every RecastNavMesh and name the one whose agent matches the player capsule (radius 32, height 192) | The test prints the agent values of all 50 meshes and the matching mesh name, or reports that none matches |
| 1 | `tests/research_ai_player.rs` | [x] Read the player character's movement values that decide jump and crouch links: jump speed, gravity scale, capsule radius and half height, crouched half height, max step height, walkable floor angle | Live 2026-09-11: JumpZVelocity 425, GravityScale 1.0, MaxStepHeight 45, WalkableFloorAngle 44.77, CrouchedHalfHeight 60, CapsuleRadius 32, CapsuleHalfHeight 96 |
| 1 | `tests/research_ai_player.rs` | [ ] Read the legacy input bindings from the player's PlayerInput: action mapping names with their keys and axis mapping names with their keys | The test prints the mappings for move, look, jump, crouch, sprint, and interact from the live game. Live 2026-09-11: 0 InputMappingContext and 0 InputAction assets loaded, so the game does not use Enhanced Input for gameplay |
| 1 | `tests/research_ai_player.rs` | [ ] Read the image-relative address of APlayerController::InputKey and UPlayerInput::InputKey and the FInputKeyParams field layout from the shipped PDB | The test prints both addresses and the struct's field names, offsets, and sizes from `AbioticFactor-Win64-Shipping.pdb` |
| 1 | `src/ai_player.rs` | [ ] Press and release W through InputKey on the human player's controller, at the address read from the PDB | A live test calls InputKey with a W press, the human player's character moves at least 100 units, and the release stops it |
| 1 | `tests/research_ai_player.rs` | [x] Read the split-screen setting from the game maps settings object | Live 2026-09-11: bUseSplitscreen byte at +88 on the GameMapsSettings default object reads 1, so split-screen is on |
| 1 | `src/ai_player.rs` | [ ] Turn split-screen off by clearing bUseSplitscreen on the game maps settings object before a second local player exists | A live test reads the byte back as 0 after the write and the game keeps running |
| 1 | `tests/research_ai_player.rs` | [ ] Create a second local player through GameplayStatics CreatePlayer in a loaded save and record what appears | The test prints the second character and its controller after the call, the screen does not split, and the game still answers 60 seconds later |
| 1 | `src/ai_player.rs` | [ ] Move the AI player's character with W through InputKey on its own controller | A live test holds W for two seconds and the AI player's character moves at least 100 units while the human player's character does not move |
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
