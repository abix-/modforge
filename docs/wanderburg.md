# wanderburg: engine and modding research

Game: Wanderburg (rolling castle roguelite, Steam Early Access since 2026-09-08)
Steam path: `C:\Games\Steam\steamapps\common\Wanderburg Game`
Engine: Unity 6000.0.63f1, IL2CPP (UnityPlayer.dll ProductVersion `6000.0.63f1 (9438f9b77a46)`)
Steam app ID: 3624140
Publisher: Randwerk / Sidekick Publishing

## binary

- Exe: `Wanderburg.exe` (672 KB launcher), `GameAssembly.dll` (75 MB, the IL2CPP output), `UnityPlayer.dll` (34 MB)
- `Wanderburg_Data/il2cpp_data/Metadata/global-metadata.dat` 18.7 MB
- 179 scripting assemblies; the game's own code is in `Assembly-CSharp.dll`. Everything else is Unity, .NET, or asset store packages (FMOD, Heathen Steamworks, TextMeshPro effects, Febucci text animator, LeanPool, NaughtyAttributes, PathCreator, AllIn1Vfx, DitzelGames FastIK)
- Content through Addressables (`StreamingAssets/aa`), audio through FMOD banks, Steam through `steam_api64.dll` plus Steamworks.NET
- Native plugins: fmodstudio, resonanceaudio, lib_burst_generated, libonigwrap

## mod infrastructure

- MelonLoader 0.7.3, copied from the Schedule 1 install by the deploy script (`version.dll` proxy plus the `MelonLoader` folder minus the per-game generated parts). First launch generated `MelonLoader/Il2CppAssemblies` for this game without incident
- Shim: `unityforge/cs-shim-melonloader` built with `-p:NoSchedule1=true`, which drops the Schedule 1 only file and its three references. Same shim binary otherwise
- Crate: `wanderburg-mod` in the modforge workspace. Control plane only, port 17177, endpoint `/op`
- Deploy: `pwsh -NoProfile -File wanderburg-mod/scripts/restart.ps1`
- First contact 2026-09-11 (`tests/research_engine.rs`):

```
[ready] control plane answering on port 17177
test ping_and_ops ... ping ok=true result={"pong":true}
test walk_camera ... find_instances(UnityEngine.Camera): 6 instance(s)
```

## reading the game's type table over the control plane

`tests/research_types.rs` lists every class in Assembly-CSharp from the
live game: 1230 types, 731 after dropping compiler-generated names, 714
of them in the global namespace.

Two facts about the tooling, learned on this game:

- The shim only hands out handles for IL2CPP objects. Host-side .NET
  reflection objects (`System.Reflection.Assembly.Load` returned one)
  come back as a string and cannot be chained. Type walks go through
  the interop proxy `Il2CppSystem.AppDomain`: `get_CurrentDomain`, then
  `GetAssemblies`, then `GetTypes`, all IL2CPP objects with handles
- Interop proxy types carry an `Il2Cpp.` namespace prefix, so
  `list_methods` reports `declared_on` as `Il2Cpp.GM` for class `GM`.
  A declared-methods filter has to match on the suffix. The shared
  `print_declared_methods` helper compares the bare name and prints
  nothing on IL2CPP games

## what the classes are (measured 2026-09-11, `tests/research_castle.rs`)

All read-only: walk_class, inspect_object, list_methods. The game stayed
up and responding through every run.

### GM: the run

One instance, `GAMEMANAGER`. Mid-run values seen: `currentLevel` 23,
`currentTier` 3, `gameTime` 777.7, `_RunStartSilver_k__BackingField` 614,
`collectedSilver` 55, `accumulatedMaterial` 3543, `mapSize` 500,
`totalAgentCounter` 2352, `levelRequirementLegendary` 9.

Owns: `vm` (the player's castle, class VM), `ms` (ModuleSelection),
`am` (AM), `mc` (MC), `qs` (QuestSystem), `sm` (Soundmanager), `st`
(StatisticsManager), `currentWaveSpawner` and `endlessWaveSpawner`
(WaveSpawner), `ws` (WaveSpawner array), `upgradeQueue` (List of
Upgrade), `myProgressionGoal` (ProgressionGoals), and the transforms
that hold enemy units, enemy vehicles and neutral agents.

Events on it: `onEnterGameplay`, `onExitGameplay`, `onStartRound`,
`onPlayerTakeDamage`, `onEnterUpgradeMenu`, `onEnterPauseMenu`,
`onGameOver`. Flags: `gameOver`, `gameWon`, `gamePaused`,
`gameplayRoundStarted`, `upgradeMenuOpen`, `endlessPhase`.

### VM: the player's castle

One instance, `Vehicle_Functional`, reached from `GM.vm`. Every stat is
a field with a getter and setter pair on the proxy.

| Field | Value seen | Meaning |
|---|---|---|
| `currentHP` / `maxHP` | 216.7 / 330 | health |
| `currentNitro` / `maxNitro` | 98.4 / 100 | boost fuel |
| `nitroConsumptionRate` / `nitroRegenRate` | 10 / 6 | per second |
| `nitroSpeedFactor` | 2.0 | boost speed multiplier |
| `maxVelocity` / `maxVelocityReverse` | 25 / 12 | |
| `currentSpeed` | 24.3 | |
| `vehicleSizeRank` | 2 | how big the castle is |
| `canAbsorbVehiclesOfSizeRank` | 2 | what it can roll over |
| `currentArmor`, `currentShield` | 0, 0 | |
| `currentInputType` | 1 | VM+InputType |

Slots: one each of front, back, top, side (left and right), captain,
crew and ram, tracked as `<name>Slot`, `<name>Slots` and
`<name>SlotsTaken`. Mounted parts in `module1` to `module4` and
`activeModule1` to `activeModule4` (all Module2), plus `allModules2`
and `startModules2`. Base stats in `vmBaseStats` (VMBaseStats), `vs`
(VS) and `vp` (VP).

Methods worth knowing: `TakeDamage(3)`, `ApplyShieldDamage(1)`,
`Heal(1)`, `HealToMax()`, `GetShield(1)`, `Death()`, `GetAbsorbed()`,
`BecomeInvincible(1)`, `GrantTemporaryInvincibility(1)`,
`PushBackAllEnemies()`, `ResetAllCooldowns()`, `MountModules()`,
`DismountModules()`, `HasFreeModuleSlot(1)`, `GenerateVehicle(2)`,
`AddBonusStats(1)`, `ApplyArtifactMaxHealthDelta(1)`,
`ApplyArtifactMaxNitroDelta(1)`, `ApplyArtifactMaxSpeedDelta(1)`,
`AddSpeedBuff(1)`, `RecalculateSpeed()`, `StartBoost()`, `StopBoost()`.
Status effects: `OnGetStunned`, `OnGetSlowed`, `OnGetFeared`, `OnBurn`,
`KnockedUp`, `Cleanse`.

### Module2: a castle part

49 live instances. First seen: `Module2_SideCannon(Clone)`,
`moduleName` "Cannon", `mountedSlotIndex` 0, `generalModuleLevel` 0.

| Field | Value seen |
|---|---|
| `currentActiveBaseDamage` | 30 |
| `currentPassiveBaseDamage` | 15 |
| `activeAbilityBaseCooldown` / `currentActiveAbilityCooldown` | 15 / 15 |
| `autoAbilityBaseCooldown` / `currentAutoAttackCooldown` | 3 / 3 |
| `activeAbilityRange` | 50 |
| `abilityBaseSize` / `activeAbilityCurrentSize` / `abilityMaxSize` | 5 / 5 / 15 |
| `autoAttackBaseSize` / `autoAttackCurrentSize` / `autoAttackMaxSize` | 4 / 4 / 12 |
| `flatDamageAdded` | 0 |

Upgrade events per module: `OnUpgradeModule`, `OnUpgradeModuleActive`,
`OnUpgradeModulePassive`, `OnUpgradeModuleCooldown`,
`OnUpgradeModuleSize`, `OnUpgradeLegendaryA/B`, `OnUpgradeSpecial0A/0B/1A/1B`.

Methods: `InstallModule(2)`, `DeleteModule()`, `UpgradeModule(6)`,
`UpgradeModuleSize()`, `AdvanceUpgradeTypeLevel(1)`,
`RecalculateSize()`, `RecalculateSpeed()`, `RecalculateCooldowns()`,
`ActiveStart()`, `ActiveFire()`, `PassiveTick()`, `CancelActive()`,
`RefundActiveCooldownPercent(1)`, `TryFindFreeSlot(4)`,
`IsMountedOnVehicle(1)`.

Subclasses (from the type survey): Module2FrontCannon, Module2SideCannon,
Module2TopCannonTower, Module2TopMortar, Module2TopArcher,
Module2Ballista, Module2Barracks, Module2FrontBarracks,
Module2BackBarracks, Module2CrewArcher, Module2CrewFire,
Module2CrewMelee, Module2CrewRacing, Module2_CrewWizard,
Module2FireMage, Module2ElectricMage, Module2ForceMage,
Module2LaserMage, Module2_SideFlamethrower, Module2Ramme,
Module2Repair, Module2Teleporter, Module2BackDash,
Module2BackMineLayer, Module2BackTrail, Module2TurretLayer,
Module2Canoneer, Module2Arms. Active abilities are the `ActiveModule*`
classes (Archer, Cannon, DamageZone, Dash, Flamethrower, ForcePush,
MineLayer, Mortar, Ramme, Saw, Shield, Teleport, WallLayer).

`ModuleSlot` had zero live instances during a run: slot bookkeeping is
inside VM and Module2, not a separate object.

### Agent: everything on the map

`Agent` is the base, with `AgentVehicle` (castles, enemy and neutral),
`AgentUnit` (soldiers, riders, farmers, animals) and `AgentStructure`
(houses, churches, towers). 144 AgentVehicle instances were live at
once. First seen: `Agent_Enemy_Vehicle_Drill`, `currentHP` 1500,
`baseCalculatedMaxHP` 1500, `absorbable` true, `absorbtionSizeRank` 3,
`currentSpeed` 27, `aggroDistance` 99999, `ally` false,
`currentDropCount` 12, `attackModules` (AttackModuleV2 array).

Agents raise `Agent+OnAgentConsumed` and `Agent+OnAgentDeath`.
`AgentConsumedTracker` and `AgentKillTracker` count by tag, and
`ArtifactSystem` reacts to over a hundred named events (OnConsumeCow,
OnKillWindmill, OnEatSheep, OnFullFuel, OnLevelUp, OnKillBoss, ...).

### the rest, by name only

- `MC` (323 methods, nested `OnSwarm`), `AM` (148 methods): one
  instance each, held by GM. Not yet read
- `VP`: 17 instances, vehicle presets (`VP+AppliedVehicleChoiceBonus`)
- `VS`: one instance, 20 methods
- `WaveSpawner`, `EnemySpawner`, `EnemyWave` (spawn patterns, rarities),
  `EnemyType`
- Bosses: `BossMortarScript`, `BossPyramidScript`, `RocketCastleBossScript`,
  `BossKanoningen`, `BossRammeMortarPhases`, `BossCannonPhaseController`
- Movement helpers: `OverworldVehicleController` (zero instances in a
  run; the overworld map screen), `SpiderLegController`,
  `SimpleLegController`
- Progression: `VehicleUpgrade`, `VehicleUpgradeOption`, `ArtifactSystem`,
  `ArtifactTagSystem`, `RunBalancingRecorder`, `RunStatisticsData`,
  `QuestSystem`, `SaveGame`, `PlayerPrefList`

## open questions

- What `MC` and `AM` are (map controller and artifact manager by name)
- Whether writing `vehicleSizeRank` grows the castle or only its
  bookkeeping; growth visuals may hang off `tierBasedCollider` and
  `RecalculateSize` on each module
- Which of the GM events are plain `Action` fields (hookable by
  Harmony postfix on the invoker) versus UnityEvents
