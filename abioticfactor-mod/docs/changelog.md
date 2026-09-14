# Abiotic Factor changelog

## 2026-09-14

- Sophia is a female scientist who walks: head SK_Head_F_02, skirt and rugged
  ponytail on SK_Human_Skeleton, animated by the Pillager's AnimBP_Pillager
  with a BlueprintUpdateAnimation hook that writes Speed from her velocity,
  since the Pillager asset only fills it for a Pillager owner. The Coworker
  asset crawled and the narrative human asset crashed on a player-only
  function. User accepted the look and the walk live.
- tests/scientist_assets.rs: the female scientist asset inventory from the
  live registry, the engine's class checks for the human NPCs, and a read of
  Sophia's animation instance around a follow order.

## 2026-09-13

- Sophia now spawns and respawns as Modforge_AIPlayer_C, directly derived from
  NPC_Base_ParentBP_C, with the base AI controller. Ueforge creates the class
  and Abiotic configures its human rendering and native melee assets. Follow,
  native knife hits, self-defense/Recall, saved orders across respawn and
  destruction/GC/replacement passed live. Aggressive-sight and human-protection
  regressions remain open in todo; full control acceptance is not claimed.
- Sophia defaults to a kitchen knife and doubled walking speed (130 to 260).
  Knife mesh, item socket and speed passed live readback on the custom body.
- Earlier Grunt prototype: the soldier tree ignored HasRangedAttack=false,
  so the knife loadout used the native BT_Main_Zombie melee tree with the human
  Grunt body and soldier controller. The custom type now uses its own minimal
  melee tree. Following yields to an active combat target. A controlled
  Pest encounter recorded 25 to 22 health, Sharp damage and Sophia as causer.
  Knife inventory ownership and durability consumption are not implemented.
- Session cleanup validates the controller's engine object index, address and
  name before using it. Destroying and collecting the companion's actors, then
  stopping the session, passed without a crash. This addresses a stale-object
  risk found after the 16:29 respawn crash; its complete caller remains unresolved.

- Earlier combat proof spawned Sophia as a human Grunt through NPCSpawn_SingleGrunt, keeping
  the game's soldier controller and combat tree. This replaces the player
  body that failed the NPC controller's initialization.
- Her faction is copied from the human during spawn. The live team test
  verified faction 2, Friend=true and no human combat target over ten seconds.
- Following and NPC replacement beside the human passed live tests. The user
  confirmed Sophia successfully fought both a Pest and an Exor.
- The initial live-only speed adjustment is now applied during every spawn.
- Permanent combat, team, follow, speed and encounter operations are in
  tests/companion_live.rs. Enemy creation uses TrySpawnNPC; DebugSpawn only
  draws debug information.
- Release build and deployment passed. The user-observed fights are combat
  acceptance; the older Exor-body automated test failed and is historical.
- A crash after the hostile Grunt encounter remains undiagnosed. Inventory,
  skills and player-body customization are outside the current combat scope.

## 2026-09-12

| Area | Shipped | Verification |
|---|---|---|
| AI player follow | `ai_player.follow` re-plans the walk to a named player every two seconds while farther than 300 units, one game-thread job per cycle; controllers and the path world context are cached; the follow loop exits when the session ends | User: "she's following me, pathing around stuff, getting hit by enemies". Two-second stutter traced to object scans per cycle and removed; performance rules in docs/performance.md |
| UDP client logging | One log sink; the mod routes every client message to its own log; send, receive and packet failures log the session state; the Windows pending-receive answer to a short read timeout is a missed tick, not a session death | Three session deaths with os error 997 mid-walk before; none after |
| NPC AI research | docs/npc-ai.md: soldier rows from DT_NPCList via a row reader that walks the row struct, live perception numbers per NPC, decoded target scoring, the character's attack functions | Permanent tests in research_npc_navigation.rs; Exor class defaults not loaded in this save area |
| AI player navigation | `ai_player.travel` walks the AI player to coordinates or to a named player: start is the host's copy of its character, the path comes from the host's navigation system (nav.find_path, the same NavigationSystemV1 and 50 dynamic RecastNavMesh objects the enemies use), partial paths are refused, and the UDP client follows the points with the shared route follower, height ignored | User validated in game: Sophia walked toward the human on both live runs |
| Players and research ops | `players` lists every player by the name on its player state with controller, character and location; `nav.simple_move_to` runs the engine's SimpleMoveToLocation on a named player's controller | Named lookup replaced a position-based guess that had moved the human's character instead of Sophia's |
| Sophia respawn | `respawn` command and `ai_player.respawn` op send character RPC 258 Request_RespawnPlayerCharacter(false, true, None) over UDP, the decoded respawn-at-player-start button. Non-bool RPC parameters carry a presence bit; None is one zero bit | First encoding disconnected with ObjectReplicatorReceivedBunchFail; corrected encoding accepted. Host diagnostic read IsDead=false at ground position. User confirmed "sophia respawned" |
| Saved world hosting | `host.saved_world` op writes ActiveWorldSaveName on the game instance and calls the Continue menu's HostMultiplayerGame(MaxPlayers, LAN, MapToHost) after IsLoggedIn passes; restart.ps1 `-Save` (default latest) hosts the save after the control plane answers | First run before login fell back to single player (Browse with no options). With the gate: world URL port 7777, listen, bIsLanMatch=1, MaxPlayers=6; Sophia joined and was possessed through the mod |
| Sophia coordinate location | `where` and automatic UDP-position reports name all map regions containing Sophia's coordinates; persistent local map/table data, no HTTP gameplay dependency | Live correction reports The Office Sector / Facility_Office1 at (-17111.80,13396.19,208.15). Build, 25 library tests and standalone location integration pass. Exact HUD-level selection remains separate |
| Sophia body observation | `state` retains timestamp, velocity and relative flag, optional body rotation/gravity, and packed movement mode from UDP corrections | Full pawn-RPC receiver test passes; live state reports zero absolute velocity and mode 1 |
| Sophia UDP position | Decode initial actor placement and absolute packed movement corrections; expose last received coordinates with `position` | Live two-second movement produced changing server coordinates. Build and 19 local tests pass, including truncated data and relative-position rejection |
| Sophia spawning | Corrected initial spawn ordering; automatic appearance update disabled after its parameter-read mismatch | User confirmed Sophia spawns successfully |
| Sophia movement | Two-second +X acceleration over UDP through native Character movement RPC 39; repeated commands use the same connection | User confirmed walking with animations. Client build and 17 local tests pass |
| Sophia commands | Interactive `forward`, `stop`, and `quit`; quit exits through the UDP disconnect path | Forward exercised live. Previous server logout confirmed before reconnect; interactive quit remains unverified live |
| LAN research | Topic documentation, permanent HTTP/PDB tests and standalone Rust Facility extraction | Map comparison matches 223 volume positions and checks 259 convex meshes; movement metadata research passes |
| `abioticfactor-client` | Standalone Rust UDP join, character initialization, spawn request, and loading completion | User confirmed seeing AIPlayer in-game |
| `abioticfactor-client` | Sophia profile with stable bot ID and a persistent local event journal | Build and 14 local tests pass, including reopening the saved profile and memory. Learned gameplay memory remains future work |
| `abioticfactor-client` | Female customization payload from offline game assets, currently disabled | Server rejected its parameter encoding. Female preference remains saved; application needs correction |

## 2026-09-11

| Area | Shipped | Verification |
|---|---|---|
| `abioticfactor-mod` | [x] New game crate for Abiotic Factor (UE 5.4.4, Steam app 427410) with UE4SS CPPMod, patternsleuth offset resolution, and HTTP control plane on port 31260 | Mod log shows `patternsleuth resolved: g_objects=0x8377740 g_names=0x82c0340 append_string=0x10c1510`, discovery finds 69 data tables / 4345 classes / 4334 structs, `list_ops` returns full op catalog over HTTP. |
| `abioticfactor-mod` | [x] AF-UE4SS community bundle (v1.22.0, UE4SS v3.0.1-1012-gc838a8ac) installed and working | Stock UE4SS v3.0.1 crashes on FName::StaticAlignment with UE 5.4.4. The AF-UE4SS bundle from github.com/igromanru/AF-UE4SS includes a compatible dwmapi.dll proxy and correct member offsets. UE4SS log shows successful initialization through ProcessEvent resolution. |
| `abioticfactor-mod` | [x] Key data tables and player character identified at runtime | DT_Skills (17 skills), DT_SkillPerks, DT_SkillRecipes, DT_BuffsDebuffs, DT_DamageDefinitions discovered. Player character `Abiotic_PlayerCharacter_C` found with skill XP functions (Server_TryAwardSkillXPOnTargetable, Server_Award XP Based On Recipe Category, UpdateSkillStat). Game state `Abiotic_Survival_GameState_C` found with FriendlyFireMode. |
| `docs` | [x] abiotic-factor.md research document with engine, binary, class, skill, difficulty, and data table findings | Document updated with runtime-confirmed data: UE 5.4.4, AF-UE4SS requirement, patternsleuth auto-resolve, 69 data tables listed by name. |
