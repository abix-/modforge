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

## Star Expedition (2026-11-07)

From `tests/research_star_expedition.rs` with the mode open:

- Live windows: `AsyncBattleWindow`, `AsyncBattleSoloWindow`,
  `AsyncBattleCoopWindow`, `AsyncBattleMapWindow` (10
  `AsyncBattleMapStarView`s), `AsyncBattlePluginsPanel`,
  `InterstellarExpeditionShow`. They hold UI only (buttons, round
  text, ship animation).
- The mode's state is in `AsyncBattleProxy` (PureMVC). Its methods
  are server requests and pushes (`RequestEnterScene`,
  `RequestTeamReady`, `RequestContinueAsyncMode`,
  `OnPushAsyncSceneSettlement`, ...) plus 1v1 and 2v2 rank points,
  so the server keeps the save and the results.
- Not yet read: the live proxy. `Facade.instance` and
  `Model.instance` come back typed as the interface (`IFacade`,
  `IModel`), and calling a class method on that handle returns no
  handle.

## Lineup screen (2026-11-07)

From `tests/research_lineup.rs`. The starting lineup is
`ChooseAdvanceTeamWindow` (the game calls it the advance team).
`chooseTime` 3600 s. Each choice (`AdvanceTeamIcon`) holds an
`openingData.advanceTeam` and two unit slots, each a `CardData`
with name, cost (`baseMoney`), and description. The first game
offered four choices, each 4 reactor core:

| Choice | Top | Bottom |
|---:|---|---|
| 0 | Tarantula x1 (200) | Vortex x2 (100) |
| 1 | Tarantula x1 (200) | Marksman x2 (100) |
| 2 | Mustang x1 (200) | Vortex x2 (100) |
| 3 | Sabertooth x1 (200) | Crawler x2 (100) |

## Unit stats (2026-11-07)

From `tests/research_units.rs`.

- The game's config is `GameRiver.Config`, a Unity object (base
  `GRSingletonMonoStatic<Config>`), found by the object search. Its
  `dataContainer` (`ConfigDataContainer`) holds every table:
  `get_cardDatas` (101 rows), `get_mechDatas` (101 rows), and the
  rest.
- A card (`CardData`) is what the player buys: `baseMoney` (cost),
  `mechCount` (units per purchase), `mechID`. A mech (`MechData`) is
  the unit: `life`, `damage` (per hit), `moveSpeed`, `isFly`,
  `mechType` (0 light, 1 medium, 2 giant, read off the subtitles),
  `mainSkillID`, `attackAngle`, `radius`.
- **Star Expedition has its own unit rows.** The lineup cards are ids
  5001 to 5203; normal play uses 1 to 32 and 2001, 2002. They
  differ: Vortex (31 / 5031) 8538 / 9723 life, 1633 / 1856 damage;
  Crawler (10 / 5010) x24 / x15 per purchase, 250 / 416 life.
- Fixed point (`FPoint`): value is `RawValue / 2^32` (attackAngle
  raw 85899345920 is 20, radius 8589934592 is 2).
- Attack range, interval, splash and air/ground targeting are on the
  unit's main skill, `SkillData` (`GetAttackRange`,
  `GetAttackInterval`, `GetSplashRange`, `GetDamageRate`,
  `IsAirAttack`, `IsGroundAttack`, ...), kept in
  `Config.mechSkillDatas.dataDic` (skill id to skill).
- Not yet read: the skill numbers. `dataDic` hands back each skill
  typed as its base `ConfigData`, so none of the skill getters are
  found. Same cause as the PureMVC proxy. Fix written in
  `unityforge/cs-shim-il2cpp/Il2CppBridge.cs` (handles carry the
  object's runtime class); not yet deployed.

## Next

The live objects behind these names only exist inside a match. The
next research needs a single player match open: which state
controller is live, what the round loop holds, and where the
deploy phase keeps its units and money.
