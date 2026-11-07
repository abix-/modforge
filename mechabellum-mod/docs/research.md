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
- `dataDic` hands back each skill typed as its base `ConfigData`;
  until 2026-11-07 none of the skill getters were found. Fixed in
  `unityforge/cs-shim-il2cpp/Il2CppBridge.cs` (handles carry the
  object's runtime class, commit 793aab90). After it, three skills
  read (range, attack interval in seconds, splash range):

  | Skill | Class | Range | Interval | Splash | Targets |
  |---|---|---:|---:|---:|---|
  | 5031001 Vortex | SkillData | 85 | 1.5 | 0 | ground |
  | 5024001 Tarantula | ProjectileSkillData | 80 | 0.6 | 5 | ground |
  | 5010001 Crawler | SkillData | 6 | 0.6 | 0 | ground, melee |
  | 5030001 Void Eye | ProjectileSkillData | 100 | 3.0 | 0 | ground |
  | 5022001 Typhoon | ProjectileSkillData | 100 | 0.2 | 5 | air, ground (2 weapons) |
  | 5021001 Sabertooth | ProjectileSkillData | 95 | 3.4 | 5 | ground (2 weapons) |
  | 5028001 Hound | ProjectileSkillData | 70 | 2.4 | 6 | ground |
  | 5013001 Sledgehammer | ProjectileSkillData | 95 | 4.5 | 5 | ground |
  | 5015001 Arclight | ProjectileSkillData | 95 | 0.9 | 7 | ground |

  The second game's lineup choices: Tarantula x1 + Void Eye x2,
  Typhoon x1 + Void Eye x1, Sabertooth x1 + Hound x2, Sledgehammer
  x1 + Arclight x2. Whether the mech row's `damage` is per weapon or
  per attack is not yet known.

  `GetDamage(0)` returned 0 for all three; the damage that counts is
  still the mech row's `damage` until the skill's damage list is read.

## Deployment (2026-11-07)

From `tests/research_deploy.rs` on the deploy screen of round 1.

- `deploy_types` lists the deploy-related classes (GRFight 13, GRCore
  13, GRClient 60). `MechPositionManager` and `DeployStateController`
  are in `GameRiver` (GRCore) and are plain classes, not Unity
  objects, so the object search finds none.
- The match (`NormalMatch`) is reached from the recommended formation
  panel's `match` field. `battleInfo`: map 1102, 12 rounds, fight time
  120 s, game mode 5.
- Map 600 by 300 (`MapRegionGridView`); `GridView` is 60 by 62 cells
  of side 10.
- Each side's placed cards: `match.playerManager.playerControllers`,
  each controller's `unitManager.units`, one `CardElement` per card
  bought. A CardElement holds `unitData` (the card),
  `mapElement.bound` (x, y, width, height) and `mapElement.facing`
  (ours 0 with negative y, the enemy 2 with positive y), and a
  `mechPositionManager` with each unit's offset (`mechPositions`).
- **A lineup slot's "x2" is two purchases.** Hound x2 from the lineup
  is two Hound CardElements on the field.
- The recommended formations were 9 player plans ("from Bearlike");
  their `areas` lists were empty on that screen.

## Next

The live objects behind these names only exist inside a match. The
next research needs a single player match open: which state
controller is live, what the round loop holds, and where the
deploy phase keeps its units and money.
