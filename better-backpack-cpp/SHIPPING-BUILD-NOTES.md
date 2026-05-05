# UE5 shipping-build notes (Grounded 2 specific)

What the SDK seems to promise vs. what the shipping binary actually delivers, when it comes to logging, console, and cheat infrastructure. Extracted from the parent inspection guide because it is referenced frequently by the mod's troubleshooting docs.

## Contents

- [What the SDK suggests is available](#what-the-sdk-suggests-is-available)
- [What the shipping binary actually does](#what-the-shipping-binary-actually-does)
- [Implications for verification](#implications-for-verification)
- [Pak-only diagnostics (no injection)](#pak-only-diagnostics-no-injection)
- [Vortex deployment gotcha](#vortex-deployment-gotcha)

## What the SDK suggests is available

The Dumper-7 SDK release for Grounded 2 v0.4.0.2 contains reflected types and methods that look like they prove the game ships with full UE logging infrastructure compiled in. Concrete evidence from the SDK headers:

| Symbol | Location | What it would prove if reflection equalled wired-up |
|---|---|---|
| `class UConsole final : public UObject` | `Engine_classes.hpp:41010` | The in-game text console class is compiled in. |
| `class UVisualLoggerKismetLibrary final : public UBlueprintFunctionLibrary` | `Engine_classes.hpp:41185` | Visual logger with Blueprint-callable `LogText`, `LogLocation`, `LogBox`, `LogCapsule`, `LogCone`, `LogCylinder`, `LogOrientedBox`, `LogSphere`. |
| `static class FString ProjectLogDir();` | `Engine_classes.hpp:32500` | UE resolves the log directory at runtime via this method. For Grounded 2 this returns the standard `<game>/Augusta/Saved/Logs/`. |
| `class UVisualLoggerAutomationTests final : public UObject` | `Engine_classes.hpp:29413` | VLog test fixtures shipped, supporting infra is present. |
| `class UConsoleSettings final : public UObject` | `EngineSettings_classes.hpp:22` | Console UI settings (MaxScrollbackSize, autocomplete list, colors) are config-driven. |
| `class USurvivalCheatManager final : public UCheatManager` | `Maine_classes.hpp:36524` | Game-specific cheat manager with explicit log-emitting commands: `LogActorAndFoliageCount`, `LogFactionReputations`, `PopulationMonitorDump`, `DumpGlobalVariables`, `DumpAlwaysReplicatedClasses`, `DumpMobileReplicatedActors`, `DumpOnlyRelevantToOwnerClasses`, `DumpPreplacedNotProxyableObjects`. |
| `enum class ELogTimes : uint8` | `CoreUObject_structs.hpp:299` | Log timestamp formatting enum. |

What the SDK does NOT directly prove:

- Whether the `-log` command-line flag actually enables file output in this shipping build. That is decided by the launcher's argument parser at runtime, which is not reflected metadata.
- The exact final path used by `ProjectLogDir()`. Static SDK reads cannot resolve it; only running the engine prints it. Standard UE convention is `<ProjectRoot>/Saved/Logs/<ProjectName>.log`, which would be `<game>/Augusta/Saved/Logs/Augusta.log`.
- Whether `DefaultEngine.ini` overrides log file output via `[Core.Log]` settings such as `bSuppressLogToFile`. Those config files live in `<game>/Augusta/Config/` and would need direct inspection.

## What the shipping binary actually does

**The hard truth:** UE5 shipping builds strip the dev console binary code entirely (`ALLOW_CONSOLE_IN_SHIPPING=0` is the default). The `UConsole` UClass survives in the SDK because reflection metadata is preserved, but runtime handling is compiled out. Confirmed for Grounded 2 by testing:

- `-log`, `-LogCmds=`, `-ExecCmds=`, `-EnableCheats`, `-cheats`, `-console` all do nothing in this shipping build.
- `Augusta.log` is never created.
- Tilde and backtick do not open a console even though `UInputSettings::ConsoleKeys` is populated in `DefaultInput.ini`.

This is not Grounded 2 being weird; it is the standard UE5 shipping configuration. See [Epic forums on the subject](https://forums.unrealengine.com/t/ue5-0-how-to-enable-console-command-in-shipping-build/541210).

What the SDK does and does not tell us:

- Reflection metadata is preserved in shipping. `UConsole`, `UVisualLoggerKismetLibrary`, `USurvivalCheatManager` all appear as real UClasses. This is misleading: their existence in the SDK does NOT prove they are runtime-callable in shipping.
- The `UCheatManager` subclass is the proof point. UE only instantiates `UCheatManager` on the player controller in non-shipping builds OR when `ALLOW_CHEAT_CHEATS_IN_SHIPPING` is defined at compile time. Just because `USurvivalCheatManager` exists as a reflected type does not mean it is wired in at runtime.
- Static analysis of cooked `.ini` files (e.g. `<game>/Augusta/Config/DefaultEngine.ini`, `DefaultInput.ini`) tells us configuration intent but not whether the corresponding runtime code path exists in this binary.

## Implications for verification

For log/console-based verification of any mod's effect, your options are:

1. **Universal Unreal Engine 5 Unlocker (UUU).** Third-party DLL injector that re-enables the console at runtime. Generic across UE5 games.
2. **[Cheat Manager and Console Unlocker](https://www.nexusmods.com/grounded2/mods/70)** on Nexus. A Grounded 2-specific runtime mod that unlocks the console.
3. **`x0reaxeax/Grounded2Minimal`** ([repo](https://github.com/x0reaxeax/Grounded2Minimal)). A debug DLL with its own embedded console, injected into the running game.
4. **Better Backpack** (this mod). Implemented as an injected DLL. Walks `GObjects`, dumps every loaded `UInventoryComponent` with its live `DefaultMaxSize`, bumps vanilla 40-slot ones owned by `BP_SurvivalPlayerCharacter*` to 60 at runtime, and patches `UI_InventoryGrid_C.MaxRows` (offset `0x0388`) on every CDO and instance. Ships its own injector (`inject.exe`) modeled on the Grounded2Minimal pattern. Replaces an earlier pak prototype precisely because pak-side mods cannot be verified without runtime injection in shipping.
5. **A pak-side mod that injects Kismet bytecode** to call `UVisualLoggerKismetLibrary::LogText` from BeginPlay. Heavy lift, requires UAssetGUI-level bytecode editing, and the resulting log goes nowhere unless one of (1)/(2)/(3)/(4) is also active to surface it.

## Pak-only diagnostics (no injection)

For "did my pak load?" without runtime injection, two pak-only diagnostics:

- **Read-back the deployed pak.** Convert the pak in `<game>/Augusta/Content/Paks/` back to legacy via `retoc to-legacy` and re-read property values via `scripts/read_property.py`. If the patched value is in the deployed bytes, the build pipeline is fine and any failure is on the runtime side (which we cannot diagnose without injection).
- **Indirect functional check.** Install another mod whose effect is visible (a known-good Bigger Stacks or recipe unlock). If that other mod's effect is also missing in-game, pak loading itself is broken (Vortex deploy, paths, priority). If the other mod works but ours does not, our specific patch is being rejected for a content reason.

## Vortex deployment gotcha

If a mod looks enabled and "deployed" in Vortex but does not take effect in-game, check Vortex's actual deployment target:

```bash
cat "$APPDATA/Vortex/<game>/snapshots/snapshot.json"
```

The `basePath` field is where Vortex thinks the game's Paks folder is. The Grounded 2 Vortex extension misidentified ours and pointed at Schedule 1's path during this session, which silently meant zero of the user's "Grounded 2 mods" were ever applied to Grounded 2. Verifying basePath = the correct game Paks dir is a 30-second sanity check that should be the first step on any "my mod is not loading" debug.

This is purely a Vortex configuration concern and not specific to any one mod. Worth doing before more elaborate debugging like reading game logs or inspecting cooked-asset internals.
