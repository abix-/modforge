# Abiotic Factor changelog

## 2026-09-12

| Area | Shipped | Verification |
|---|---|---|
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
