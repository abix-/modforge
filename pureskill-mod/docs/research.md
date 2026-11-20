# Pure Skill: engine and modding research

Game: Pure Skill Demo (Kedy Games), Steam app 5503090
Steam path: `C:\Games\Steam\steamapps\common\Pure Skill Demo`
Engine: Unity 6000.3.13f1, IL2CPP, metadata version 39 (header `fab11baf 00000027`)

## binary

- Exe: `PureSkill.exe`, `GameAssembly.dll` (45 MB), `UnityPlayer.dll` (36 MB)
- `PureSkill_Data/il2cpp_data/Metadata/global-metadata.dat` 9 MB
- The game's own code is in `Assembly-CSharp.dll`, the only non-Unity, non-.NET scripting assembly
- Native plugins: `lib_burst_generated`, `libonigwrap`. No FMOD, no Addressables, no Steam API dll

## mod infrastructure

### MelonLoader does not work on this build

MelonLoader 0.7.3 (copied from the Schedule 1 install) crashed the game
on first launch, 2026-11-19, while generating interop assemblies. Cpp2IL
read metadata v39 fine; the crash came in Il2CppInterop's method
cross-reference scan:

```
[23:15:57.004] [Il2CppAssemblyGenerator] [Info] [Library] 	Using actual IL2CPP Metadata version 39
[23:16:07.299] [Il2CppAssemblyGenerator] Scanning method cross-references...
```

Windows Application log, 23:16:08: `.NET Runtime ... Application: PureSkill.exe ...
The process was terminated due to an internal error in the .NET Runtime ... with exit code c0000005.`

Known upstream: MelonLoader issue #1159 (newer Unity 6000 builds, open),
Il2CppInterop issue #213 (same crash in the xref scan; BepInEx does not
scan method refs by default). MelonLoader has no setting to skip the scan.

### BepInEx 6 works

- BepInEx 6.0.0-be.793+dbc82f0, Unity.IL2CPP win-x64, from builds.bepinex.dev
- Interop generation finished; the log warns
  `Class::Init signatures have been exhausted, using a substitute!`
  (as in Il2CppInterop issue #283) but the game kept running, unlike the
  Rust and Zero Parades reports
- Shim: `unityforge/cs-shim-il2cpp` (the BepInEx entry; first build ever
  on 2026-11-19, needed an `Il2Cppmscorlib` reference added). BepInEx
  does not ship Newtonsoft.Json, so the deploy copies it from the NuGet
  cache next to the shim
- Crate: `pureskill-mod`, control plane only, port 17187, endpoint `/op`
- Deploy: `pwsh -NoProfile -File pureskill-mod/scripts/restart.ps1`

First contact 2026-11-19 (`tests/research_engine.rs`):

```
[ready] control plane answering on port 17187
test ping_and_ops ... ping ok=true result={"pong":true}
find_instances(UnityEngine.Camera): 4 instance(s)
test result: ok. 2 passed; 0 failed
```

BepInEx log: `Registered mono type Unityforge.Shim.UnityforgeTickDriver in il2cpp domain`,
so class injection works on this build despite the substitute warning.
