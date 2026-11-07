# Mechabellum research

What the game is made of, read from the live game over the mod's
control plane (port 17184). Every claim here names the test that
produced it, so it can be taken again after a game update.

## Game and loader (2026-11-07)

- Mechabellum, Steam app 669330, developer GameRiver.
- Unity 2022.3.62f3, IL2CPP (GameAssembly.dll, global-metadata.dat
  version 31).
- Loaded by MelonLoader 0.7.3 (copied from the Schedule 1 install by
  `scripts/restart.ps1`) through `Unityforge.Shim.Melon`.
- Proof: `tests/research_load.rs` passed; MelonLoader's Latest.log
  shows `mechabellum-mod: ready (runtime=Il2Cpp), http on port 17184`.

## Where the game's code is (2026-11-07)

From `tests/research_load.rs` (assembly list) and
`tests/research_types.rs` (types per assembly). The type walk takes
about 6 minutes.

| Assembly | Types | What is in it |
|---|---:|---|
| GRClient | 2717 | `GameRiver.Client`: menus, match flow, every game mode's controller, UI (`GameRiver.Client.UI`), AI (`GameRiver.Client.AI`) |
| GRCore | 1169 | `GameRiver`: shared game data and messages |
| GRFight | 789 | `GameRiver.Fight`: the battle itself (units, weapons, skills, teams, states) |
| BinNetwork | 599 | `Protos.Fight` and other network messages |
| ConfigDataProtocol | 186 | `GameRiver.Data.ConfigProtocol.*`: the game's data tables, one namespace per table (Mech, Card, Technology, Officer, SurviveUnit, TowerSkill, ...) |
| GRUtility | 161 | `FixedMath` (fixed-point numbers) and PureMVC |
| GRServer | 29 | `GameRiver.Server` |
| FightAuth | 16 | `GameRiver.FightAuth` |
| Assembly-CSharp, Assembly-CSharp-firstpass | | Read by the test; not yet looked at |

## What the names suggest (not yet proven)

These are read from class names only. None has been checked
against a live object yet.

- **The battle is a fixed-point simulation.** `FixedMath` in
  GRUtility, `FightRecord`, `BattleSyncError`, `MH_BattleSyncError`
  and `ReplaySimulateMatch` point to a deterministic simulation that
  both sides (or a replay) run from the same inputs. A change to
  battle numbers would then break replays and sync.
- **Battle flow is a state machine.** `FightPrepareState`,
  `FightingState`, `FightOverState`, `FightIdleState` in GRFight;
  `DeployStateController`, `FightStateController`,
  `FightOverStateController` in GRClient.
- **Single player modes each have a controller:**
  - Survive: `SurviveGameplayController`, `SurviveGameFactory`,
    `SurviveProxy`, `SurviveWindow`, data tables `SurviveUnit`,
    `SurviveTroop`, `SurviveDifficultySetting`.
  - The TD mode: `TDGameplayController`, `TDGameFactory`, `TDMainUI`,
    data tables `TDHandCard`, `TDDevice`, `TDOfficer`.
  - Levels: `LevelMatch`, `StartLevelCommand`, `RetryLevelCommand`,
    `LevelProxy`, `LevelWindow`, data tables `BasicLevel`,
    `AdvancedLevel`.
  - Offline async battles: `AsyncBattleSoloWindow`,
    `AsyncBattleUtility+OfflinePlugins`.
  - `SinglePlayerWindow`, `TestingGroundWindow`.
- **Speed and preview already exist in the game:**
  `FightSpeedUpController`, `SpeedUpPanel`, `ForecastAndSpeedUp`,
  `FastSimulationMatch`, `MH_SpeedUp`.
- **Deploying units:** `DeployJobModel`, `CreateMechInDeployment`,
  `DestroyMechInDeployment`, `DeployWarningTip`.

## Next

The live objects behind these names only exist inside a match. The
next research needs a single player match open: which state
controller is live, what the round loop holds, and where the
deploy phase keeps its units and money.
