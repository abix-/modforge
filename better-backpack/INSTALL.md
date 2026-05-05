# Better Backpack: install and use

End-user guide. If you only want to play with a 100-slot backpack and a scrollable 4x10 inventory viewport, this is the only doc you need to read.

## Contents

- [Quickstart](#quickstart)
- [Where do the files go?](#where-do-the-files-go)
- [Step-by-step](#step-by-step)
- [Verifying it worked](#verifying-it-worked)
- [Uninstall](#uninstall)
- [Compatibility with other mods](#compatibility-with-other-mods)
- [Caveats](#caveats)
- [Next steps](#next-steps)

## Quickstart

```cmd
:: 1. one-time build (produces dist\BetterBackpack.dll + dist\inject.exe)
build.bat

:: 2. launch Grounded 2 and load into a save (not just the main menu)

:: 3. from anywhere, run the injector
dist\inject.exe
```

A new console window titled "Better Backpack" appears, the player inventory expands to 100 backing slots, and a log opens at `%TEMP%\BetterBackpack.log`. The visible inventory stays at 4 rows by 10 columns and scrolls with the mouse wheel. The DLL is unloaded automatically when the game exits.

If `build.bat` fails or you don't have Visual Studio installed, see [BUILDING.md](BUILDING.md) for prerequisites.

## Where do the files go?

**Nowhere special.** This is not a Vortex mod and does not get installed into the Grounded 2 folder. The two artifacts (`BetterBackpack.dll` and `inject.exe`) can sit anywhere on disk: the project's `dist/` folder, your desktop, `Downloads\`, a USB stick. The injector finds the running game by process name, then maps the DLL into the game from wherever the file lives.

The only co-location rule:

- `inject.exe` and `BetterBackpack.dll` should live in the **same folder as each other**, because `inject.exe` looks for the DLL next to itself by default.
- If you want them apart, use `inject.exe path\to\BetterBackpack.dll` to override the DLL path explicitly.

Nothing is written to the game's install directory. Nothing is written to the game's `Saved\`. The only on-disk artifact this mod creates is the diagnostic log at `%TEMP%\BetterBackpack.log`, which is overwritten on every injection.

## Step-by-step

1. **Build** (one-time, ~30 seconds; rebuild after editing the source):

   ```cmd
   build.bat
   ```

   Produces `dist\BetterBackpack.dll` and `dist\inject.exe`.

2. **Launch Grounded 2** normally. Steam or Xbox Game Pass both work.

3. **Load into a save**, not the main menu. `UInventoryComponent` instances don't exist until a player pawn is spawned, so injecting at the main menu means the data-side patch has nothing to bind to until the rescan loop's next tick (10 s).

4. **Inject the DLL** from a normal cmd window:

   ```cmd
   cd C:\code\grounded2mods\better-backpack
   dist\inject.exe
   ```

   You'll see:

   ```
   [+] DLL: C:\...\dist\BetterBackpack.dll
   [+] target: Grounded2-WinGRTS-Shipping.exe (PID NNNN)
   [+] LoadLibraryA fired in target process; waiting...
   [+] DLL mapped at HMODULE 0x... in target process.
       Look for the new console window or %TEMP%\BetterBackpack.log
   ```

5. **Verify in-game**: open inventory. You should see the normal 4 rows of 10 visible slots. Use the mouse wheel to scroll through the larger backpack.

If anything looks off, jump to [TROUBLESHOOTING.md](TROUBLESHOOTING.md). The console window and log file together tell you exactly which player inventory components were raised to the current target and whether the scroll viewport is responding.

## Verifying it worked

Two output streams: the allocated console (transient, gone when the game exits) and the persisted log file at `%TEMP%\BetterBackpack.log`.

Look for these lines on the first scan:

```
[hh:mm:ss.fff] === Better Backpack DLL ===
[hh:mm:ss.fff] target slot_count = 100
[hh:mm:ss.fff] vanilla main = 40, vanilla mount = 30 (left untouched)
[hh:mm:ss.fff] game exe base    = 0x...
[hh:mm:ss.fff] GObjects populated after N retries (M ms)
[hh:mm:ss.fff] GObjects count   = ~1500000
[hh:mm:ss.fff] ProjectLogDir()   = '...'
[hh:mm:ss.fff] ProjectSavedDir() = '...'
[hh:mm:ss.fff] ProjectModsDir()  = '...'
[hh:mm:ss.fff] found N UInventoryComponent objects:
[hh:mm:ss.fff]   [CDO ] DefaultMaxSize=40    obj=0x...  Default__BP_SurvivalPlayerCharacter_C ...
[hh:mm:ss.fff]   [CDO ] DefaultMaxSize=30    obj=0x...  ... mount ...
[hh:mm:ss.fff]   [inst] DefaultMaxSize=40    obj=0x...  ... live player main inventory ...
[hh:mm:ss.fff] PATCH ... : 40 -> 100 (verify=100)
[hh:mm:ss.fff] widget TRACE ... OnMouseWheel
[hh:mm:ss.fff] scroll refresh ... start=10 -> 20
[hh:mm:ss.fff] entering rescan loop (interval = 10 s)
```

In-game: open inventory, confirm the visible grid is still 4x10, then use the mouse wheel to page through the extra slots.

If the log shows PATCH lines but the mouse wheel does not page the inventory, see [TROUBLESHOOTING.md](TROUBLESHOOTING.md).

## Uninstall

Don't run `inject.exe`. The DLL only modifies the running process's memory; nothing on disk gets touched. Quitting the game wipes the patch.

If you want to be extra clean: delete `dist\BetterBackpack.dll` so nothing can map it. The injector will fail on the missing-DLL check.

Important: items placed in slots beyond vanilla 40 may become inaccessible if the DLL is not injected on the next session. Safest assumption: saves that use the expanded backpack should continue to be played with the mod enabled.

## Compatibility with other mods

- **AIO Player Tweaks (or any Player Tweaks variant): no conflict.** The pak version of Better Backpack would shadow the AIO BP override entirely. The DLL is different: it patches a single int32 in the live CDO/instance, leaving everything else AIO did to the BP intact. Run both, AIO's cheats still work.
- **Older 60-slot test builds:** if you previously used a 60-slot build, the current mod now upgrades those player inventories to 100 as well. If the log still shows only `40 -> 60` behavior, you are running a stale DLL.
- **Cheat Manager and Console Unlocker / Grounded2Minimal: compatible.** Different DLLs, different hooks, no overlap. They unlock the dev console; we patch inventory caps.
- **Multiplayer:** server-authoritative inventory caps may clamp client-side capacity in sessions where the host doesn't have the mod. Out of scope for v1.

## Caveats

- **Hard caps unknown.** The game may silently clamp very large `kSlotCount` values. Empirically test before committing to larger numbers; 100 is the current target.
- **Re-injection during one session is undefined.** The DLL holds an open log file handle and a worker thread; mapping it twice is not supported. If you injected and want to re-do it, restart the game.
- **Game updates may break the data-side patch.** If Obsidian reorders fields on `UInventoryComponent`, the hard-coded `0x01E0` offset writes to the wrong field. The widget patch is reflective and survives reorderings. To repair the data side after a game update, see [BUILDING.md](BUILDING.md) > "After a game update".
- **Anti-cheat:** Grounded 2 has none listed. If that ever changes, this DLL would trip it.

## Next steps

- Hit a problem? See [TROUBLESHOOTING.md](TROUBLESHOOTING.md).
- Want a different slot count, or to know how the patch works? See [BUILDING.md](BUILDING.md).
- Curious about the design and research? See [REQUIREMENTS.md](REQUIREMENTS.md).
- Want the broader Grounded 2 modding methodology? See [../inspection-guide.md](../inspection-guide.md).
