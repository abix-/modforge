# alchemy factory: engine and modding research

Game: Alchemy Factory (potion factory automation, Steam)
Steam path: `C:\Games\Steam\steamapps\common\Alchemy Factory`
Engine: Unreal Engine 5.7 (exe carries `++UE5+Release-5.7`; UE4SS pattern scan reports `Found EngineVersion: 5.7`)
Steam app ID: 3669570

The first UE 5.7 game in this workspace. Every other UE game here is 5.4, except Sintopia at 5.2.1.

## binary

- Launcher: `AlchemyFactory.exe` (199 KB)
- Shipping exe: `AlchemyFactory\Binaries\Win64\AlchemyFactory-Win64-Shipping.exe` (155 MB)
- No PDB on disk and no PDB path inside the exe
- Binaries folder holds only the exe, a `D3D12` folder, `tbb12.dll` and `tbbmalloc.dll`
- Engine third party: DbgHelp, MsQuic, NVIDIA, Ogg, Steamworks, Vorbis

## pak

- `AlchemyFactory\Content\Paks\AlchemyFactory-Windows.pak` plus IoStore (`AlchemyFactory-Windows.ucas` / `.utoc`, `global.ucas` / `.utoc`)

## mod infrastructure

- UE4SS: the build copied from Sintopia (MISERY's UE4SS v3.0.1 Beta, git 06474186) does NOT work on this game. Its pattern scan finds the engine version but not three signatures and dies before any mod code runs:

```
[PS] Found EngineVersion: 5.7
[PS] Found GUObjectArray: 0x7ff785412590
[PS] Failed to find FName::FName(wchar_t*): FNameCtorWchar: expected at least one value
[PS] Failed to find FUObjectHashTables::Get(): FUObjectHashTablesGet: expected at least one value
[PS] Failed to find GNatives: GNatives: expected at least one value
[PS] Scan failed
Fatal Error: PS scan timed out
```

- Working loader: UE4SS `experimental-latest` from github.com/UE4SS-RE/RE-UE4SS, asset `UE4SS_v3.0.1-1133-gb4cefa18.zip` (files dated 2026-09-12; the log reports git SHA 2bfa839f). Its release notes list "Added support for UE Version 5.7". With it the scan finishes in about one second, every signature resolves, and the C++ mod starts:

```
UE4SS - v3.0.1 Beta #0 - Git SHA #2bfa839f
Starting C++ mod 'AlchemyFactoryMod'
[PS] Scan finished in 1.0112726s
[PS] Found EngineVersion: 5.7
ProcessEvent address 0x7ff77dbc3de0
[HashTables] Self test passed (5334 classes with instances)
```

  Installed by hand into `AlchemyFactory\Binaries\Win64` (`ue4ss\UE4SS.dll` 20567040 bytes, `dwmapi.dll` 279552 bytes). `scripts/restart.ps1` still points its UE4SS reference at Sintopia; that reference is wrong for this game and only runs when `ue4ss\UE4SS.dll` is missing
- Settings (`ue4ss\UE4SS-settings.ini`): Sintopia's minimal file, every `[Hooks]` entry 0 except `HookEngineTick = 1` and `HookUObjectProcessEvent = 1`, GUI console off. The newer UE4SS logs "Failed to add hook, detour installation likely failed" for its own LoadMap / InitGameState / BeginPlay / EndPlay / ProcessConsoleExec hooks; the game keeps running through them

## ueforge mod status

- Crate: `alchemyfactory-mod` in the modforge workspace
- Deploy: `pwsh -NoProfile -File alchemyfactory-mod/scripts/restart.ps1`
- HTTP control plane on port 31290, endpoint `/debug`
- Minimal on purpose: `resolve_and_init` plus the builtin ops. No ImGui tabs, no watchers
- patternsleuth resolves on the live game, and its GObjects address agrees with UE4SS (`0x7ff785412590`):

```
image_base = 0x7ff77c6c0000, host = AlchemyFactory-Win64-Shipping.exe
patternsleuth resolved: g_objects=0x8d52590 g_names=0x8c84500 append_string=0x133d450
ue runtime ready, GObjects = 0x7ff785412590
```

  `append_string` (image base + 0x133d450 = 0x7ff77d9fd450) is the address UE4SS names `FName::ToString`
- BLOCKED 2026-09-13: the mod crashes right after "ue runtime ready", inside `discovery::run_at_load` (the GObjects walk ueforge runs at load), before the control plane thread is spawned. From the crash dump (`ue4ss\crash_2026_09_13_11_14_35.4766728.dmp`, read with `modforge --bin minidump`):

```
thread      6588
exception   0xc0000005  ACCESS_VIOLATION
address     0x7ffab4fb280c  main.dll + 0x4280c
function    ueforge::ue::uobject::UObject::name  (+0x5c into it)
fault       reading 0xffffffffffffffff
```

  So the object pointers the walk reads out of GObjects are wrong on this build. The FUObjectItem stride ueforge uses (0x18) and the chunked array layout are 5.4 numbers and have not been measured here. The control plane never comes up, so the research tests cannot measure them yet

## reflection offsets UE4SS reports for this build

UE4SS logs its member offsets at startup. These are UE4SS's own tables for engine version 5.7, not measurements of this exe, but they are the best prior art until the research tests run. Where they differ from ueforge's constants:

| Member | UE4SS for 5.7 | ueforge constant |
|---|---|---|
| UObjectBase::NamePrivate / ClassPrivate / OuterPrivate | 0x18 / 0x10 / 0x20 | same |
| UStruct::SuperStruct / Children / ChildProperties | 0x40 / 0x48 / 0x50 | same |
| UStruct::PropertiesSize | 0x58 | `StructLayout::UE5_4` 0xB0 (wrong), `UE5_2` 0x58 |
| UClass::ClassCastFlags / ClassDefaultObject | 0xD8 / 0x110 | same |
| UClass total size | 0x208 | 0x200 |
| UFunction::FunctionFlags / NumParms / ParmsSize | 0xB0 / 0xB4 / 0xB6 | same |
| FField::Next | 0x18 | 0x20 (wrong) |
| FField::NamePrivate | 0x20 | 0x28 (wrong) |
| FProperty::ArrayDim / ElementSize / PropertyFlags / RepIndex | 0x30 / 0x34 / 0x38 / 0x40 | same |
| FProperty::Offset_Internal | 0x44 | 0x4C (wrong) |

`ueforge::ue::offsets::ffield` and `fproperty::OFFSET_INTERNAL` are plain constants, not part of `StructLayout`, so a game crate cannot supply the 5.7 values today. That is the todo item "UE-version-aware ffield / fproperty / ustruct offsets" in docs/todo.md.

## tests

- `alchemyfactory-mod/tests/research_engine.rs`: `resolve_offsets`, `discovery_counts`, `process_event_slot`
- `alchemyfactory-mod/tests/research_ustruct_layout.rs`: `properties_size_slot`, `child_properties_slot`, `fproperty_slots`

Each skips with a message when the control plane on port 31290 is not answering. None has run yet against this game, because of the crash above.

```
k3sc cargo-lock test -p alchemyfactory-mod --test research_engine -- --test-threads=1 --nocapture
k3sc cargo-lock test -p alchemyfactory-mod --test research_ustruct_layout -- --test-threads=1 --nocapture
```
