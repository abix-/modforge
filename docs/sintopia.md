# sintopia: engine and modding research

Game: Sintopia (hell management sim, Steam)
Steam path: `C:\Games\Steam\steamapps\common\Sintopia`
Engine: Unreal Engine 5.2.1 (exe FileVersion 5.2.1.0, ProductVersion `UE5-CL-0`, source build)
Steam app ID: 2213700

## binary

- Launcher: `Sintopia.exe` (539 KB)
- Shipping exe: `Sintopia/Binaries/Win64/Sintopia-Win64-Shipping.exe` (142 MB)
- No PDB on disk. The Steam debug-file manifest lists one but Steam does not download it
- D3D12, OpenImageDenoise, EOS SDK, Steam, GOG and PlayFab online subsystems, DLSS, FSR, Streamline
- Nine Boost DLLs (including boost_python39) and TBB in the game binaries folder. Purpose not determined; the exe has no Python runtime strings
- Native game module `/Script/Sintopia` exists. Marketplace plugins compiled in: Prefabricator with ConstructionSystemRuntime, Twitch, AsyncLoadingScreen, UIWidgetsLib, SkeletalMeshMerger

## pak

- One file: `Sintopia/Content/Paks/Sintopia-Windows.pak` (10.25 GB)
- Pak version 11, encrypted flag 0
- No IoStore (`.utoc` / `.ucas` absent)
- Content folders by file count: Sound 24574, Environment 19192, Characters 13833, Effects 8704, UI 7513, L10N 6411, Generated 5292, Descriptors 2314, Maps 526

Descriptor groups (data assets under `Content/Descriptors`): Dialogues 688, GameSequences 254, HellBuildings 234, Baking 186, Maps 134, Demons 96, AlertsManager 86, Spellcasting 62, GPI 60, Animations 60, Settings 52, HummuBuildings 40, Squads 36, Wildlife 26, Guacas 24, WorldCrisis 20, Camera 20, Imps 18, Hummus 12, ConstructionMode 12, plus Technologies, ChallengeMode, SandboxMode, Campaign.

## mod infrastructure

- UE4SS: the MISERY install copied as-is (UE4SS.dll 16254976 bytes, dwmapi.dll proxy 61952 bytes)
- First launch with the MISERY settings file (every hook on) crashed the game thread inside a UE4SS frame about one second after the mod reported ready:

```
<ErrorMessage>Unhandled Exception: EXCEPTION_ACCESS_VIOLATION reading address 0x0000000000000112
<EngineVersion>5.2.1-0+UE5
<ThreadName>GameThread</ThreadName>
Sintopia-Win64-Shipping + 513411c
UE4SS 0x00007ffae7980000 + 3b0ba1
Sintopia-Win64-Shipping + 5113250
```

  The mod DLL appeared only in the loaded-module list, not in any stack. No UE4SS.pdb, so the UE4SS function is unnamed.
- Working settings (`ue4ss/UE4SS-settings.ini`): every `[Hooks]` entry 0 except `HookEngineTick = 1` and `HookUObjectProcessEvent = 1`; `GuiConsoleEnabled = 0`, `GuiConsoleVisible = 0`. With these the game stayed up through discovery and the research tests. The ProcessEvent hook is on because UE4SS only logs the ProcessEvent address with it, and the mod needs that address to measure the vtable slot
- Which single hook caused the crash was not isolated. Turn hooks back on one at a time only when a test needs one

## ueforge mod status

- Crate: `sintopia-mod` in the modforge workspace
- Deploy: `pwsh -NoProfile -File sintopia-mod/scripts/restart.ps1`
- HTTP control plane on port 31270, endpoint `/debug`
- Minimal on purpose: `resolve_and_init` plus the builtin ops. No ImGui tabs, no watchers
- GObjects layout: WrappedChunked (discovery walked 39120 entries with it)
- patternsleuth resolved on the live game (from `tests/research_engine.rs`, test `resolve_offsets`):

```
resolve_offsets ok=true result={"matches":{"append_string":true,"g_names":true,"g_objects":true},"resolved":{"append_string":"0x2ce7f20","g_names":"0x8130ac0","g_objects":"0x81d6b40","gmalloc":"0x80f6f70"}}
```

- ProcessEvent vtable slot: 0x4D, measured live 2026-09-11 (test `process_event_slot`). Same as MISERY and Abiotic Factor on UE 5.4, not the 0x4C the ueforge docs call typical:

```
ue4ss ProcessEvent = 0x7ff6b1d5fdb0
gameinstance BP_DiabolicalGameInstance_C_2147482377 @ 0x172e2a74d80 vtable 0x7ff6b54748d0
  slot[0x4c] = 0x7ff6af8e74c0
  slot[0x4d] = 0x7ff6b1d5fdb0
ProcessEvent vtable index = 0x4d
```

  Slot 0x4c on this game holds the same address as a dozen other slots (0x7ff6af8e74c0, a shared stub), so the placeholder 0x4C would have called a no-op. The game instance class is `BP_DiabolicalGameInstance_C`
- Discovery (test `discovery_counts`):

```
discover_classes: ok=true classes_found=4087
discover_structs: ok=true structs_found=5496
discover_data_tables: ok=true tables_found=43
```

## key classes (from runtime discovery)

The game's own nouns: Hummus (the mortals), Imps (workers), Demons (one per sin: Envy, Gluttony, Greed, Lust, Pride, Sloth, Wrath), Guacas (raiders with camps and squads), Hell buildings, Hummu buildings, spells, GPI (hell ground pieces).

| Family | Classes seen |
|---|---|
| Descriptors | DemonDescriptor, DemonCreepDescriptor, DemonsSquadDescriptor, ImpDescriptor, ImpLevelingDescriptor, ImpMovementDescriptor, HummusDescriptor, HummusDeviancyDescriptor, GuacaDescriptor, GuacaCampDescriptor, GuacaSquadDescriptor_Defense / _TempleAttack / _TempleRaid, SpellDescriptor, ProjectileSpellDescriptor, DragAndDropSpellDescriptor, HellExpansionDescriptor, HellSubLevelDescriptor, HellRoadDescriptor, HummuRoadDescriptor |
| Per-sin demons | EnvyDemonDescriptor, GluttonyDemonDescriptor, GreedDemonDescriptor, LustDemonDescriptor, PrideDemonDescriptor, SlothDemonDescriptor, WrathDemonDescriptor, each with an ADB variant |
| Hell buildings | HellBuildingDescriptor_ plus AccreditationOffice, AdvertisingAgency, BreakRoom1-4, CloningPod, CultistsHotline, Dispatcher, FaithcoinsGenerator1-2, FoodMaterialsGenerator, HROffice, HellGate, InfluenceGenerator, NatalityGenerator, OverflowGate, Punishment_ (one per sin plus Generalist1-2), ResurrectionPortal, ResurrectionRelay, SinLocker, SinSwapper, VaultOfWonder, WaitingBooth, WaitingRoom; matching HellBuildingAsset_*_Base classes |
| Hummu buildings | HummuBuildingDescriptor_ plus Barracks, Bridge, BuilderBuilding, Cemetery, Church, Farm, Fishery, Flag, GenericResourceNodeBuilding, Habitation, Hospital, Market, Mine, Plaza, RangerBuilding, Sawmill, Temple; HummuBuildingPart_* |
| Actors | HummusActor, HummuBuilding, GuacaCamp, GuacaCampPart, DemonCrater, GPIActor_SpellAltar, SpellcastingProjectileActor (+ _CollisionSphere, _Niagara, _StaticMesh), HellRoadHelper, PrebuiltHummuBuildingHelper, PreplacedHellGPIHelper |
| Widgets | DemonStatsUserWidget, DemonResourcesUserWidget, ImpCardUserWidget, ImpLevelBarUserWidget, ImpMotivationGaugeUserWidget, ImpRecruitmentUserWidget, SpellBarUserWidget, SpellWalletUserWidget, HummuBuffListUserWidget, ManagementStatsHummusUserWidget, PKDemonHealthBarUserWidget |

Class name suffixes: `ADBDescriptor` and `PDBDescriptor` recur on every creature type. What ADB and PDB stand for is not known yet.

## tests

- `sintopia-mod/tests/research_engine.rs`: `resolve_offsets`, `discovery_counts`, `process_event_slot`. Each skips with a message when the control plane on port 31270 is not answering

```
k3sc cargo-lock test -p sintopia-mod --test research_engine -- --test-threads=1 --nocapture
```
