# Better Backpack: troubleshooting

If something didn't work the way [INSTALL.md](INSTALL.md) describes, find your symptom below.

## Contents

- [Build problems](#build-problems)
- [Injector errors](#injector-errors)
- [DLL injected but inventory still 40 slots](#dll-injected-but-inventory-still-40-slots)
- [Patches applied but I can't pick up past 40](#patches-applied-but-i-cant-pick-up-past-40)
- [Reading the log](#reading-the-log)
- [Debug-output reference](#debug-output-reference)
- [Still stuck](#still-stuck)

## Build problems

### `'cl.exe' is not recognized`

Visual Studio 2022 isn't installed in the default location, or the C++ workload isn't installed. See [BUILDING.md](BUILDING.md#prerequisites).

### `ERROR: Dumper-7 SDK not found at C:\Tools\work\sdk\SDK`

The build script expects the Dumper-7 SDK headers under `C:\Tools\work\sdk\`. Download from the credited repo (or generate fresh via Dumper-7) and either extract there or edit `SDK_ROOT` at the top of `build.bat`. See [BUILDING.md](BUILDING.md#prerequisites).

### Build succeeds but `dist\BetterBackpack.dll` is missing

Look at the tail of `build.bat` output. Two failure paths exist (`:dll_failed` returns exit code 10, `:inject_failed` returns exit code 11). If exit code 10, the DLL compile failed and you'll see actual MSVC errors before the failure banner.

## Injector errors

### `[-] Grounded 2 not running.`

Launch the game first, load into a save, then re-run `inject.exe`. The injector scans the running process list for these names:

- `Grounded2-WinGRTS-Shipping.exe` (Steam)
- `Grounded2-WinGDK-Shipping.exe` (Xbox Game Pass)

If the game is launched and you still see this message, your install is using a different launcher build. Find the actual exe name (Task Manager > Details), then either rename the binary file to one of the expected names or edit `TARGET_PROCESSES[]` at the top of `inject.c` and rebuild.

### `[-] OpenProcess failed: E5 (try running this exe as Administrator)`

Access denied. Steam-launched games inherit the elevation level of the Steam launcher. If Steam was started elevated ("Run as administrator"), the injector also has to be elevated.

Easiest fix: right-click `cmd.exe`, "Run as administrator", `cd` to the project folder, run `dist\inject.exe`.

### `[-] DLL not found: '...'`

The injector looked for `BetterBackpack.dll` next to itself, didn't find it. Either:

- You ran `inject.exe` from a directory where `BetterBackpack.dll` isn't, or
- The DLL build failed (re-run `build.bat` and check the tail for errors).

Pass an explicit path to override: `inject.exe path\to\BetterBackpack.dll`.

### `[!] LoadLibraryA returned 0 in target process.`

The DLL got mapped but `DllMain` returned FALSE. Most common causes:

- **Wrong bitness**: must be 64-bit. Our build is. If you replaced the file by hand, verify with `dumpbin /headers BetterBackpack.dll | findstr machine` (expect `8664 machine (x64)`).
- **Unresolved import**: rare. The DLL only links `user32.lib` and `kernel32.lib`. If you added new dependencies, that could explain it.
- **DllMain itself crashed**: check `%TEMP%\BetterBackpack.log`. If the file isn't there at all, `DllMain` died before opening it. Run the game with a debugger attached, or strip the DLL down to a no-op `DllMain` and reintroduce code until you find the offender.

## DLL injected but inventory still 40 slots

Open `%TEMP%\BetterBackpack.log` and match against these symptoms:

### No `PATCH ... : 40 -> 60` lines at all

The player pawn wasn't spawned at scan time. Open the inventory in-game once, wait 10 seconds, check the log again. The rescan loop will have caught the spawned components.

### `widget: UI_InventoryGrid_C not loaded yet`

The grid widget class isn't in `GObjects` yet. Open the inventory once in-game. That forces the widget class to load, and the next 10 s rescan tick will patch it.

### `initial widget patch round: 0 UI_InventoryGrid_C objects bumped`

Either the grid class wasn't loaded (open the inventory; see above), or the offset `0x0388` no longer points at `MaxRows` because the game updated. Re-run Dumper-7 and update `kGridMaxRowsOffset` in `dllmain.cpp`. See [BUILDING.md](BUILDING.md#after-a-game-update).

### `DefaultMaxSize=40 still on the CDO after the patch round`

Either:

- The hard-coded offset `0x01E0` no longer matches `UInventoryComponent`. The game updated and reordered fields. Re-run Dumper-7 and update `kDefaultMaxSizeOffset` in `dllmain.cpp`. See [BUILDING.md](BUILDING.md#after-a-game-update).
- Or you replaced the DLL with a stale build. Re-run `build.bat`.

### Patches applied but UI still 40 (rare)

Could be a server-authoritative clamp in multiplayer. Check whether you're playing on a dedicated server; if so, the host's cap wins regardless of what your client patches. If you're the host, the host's cap is yours.

## Patches applied but I can't pick up past 40

The running player pawn was spawned with a snapshot of the cap before the DLL patched it. Either:

- Restart the game, inject **at the main menu** (before loading a save), then load the save. The player spawns reading the patched CDO.
- Or, drop excess items, save, quit to main menu, reload the save. This respawns the pawn with the new cap.

## Reading the log

The log file at `%TEMP%\BetterBackpack.log` is plain ASCII, line-buffered, written on every Log call. Open with any editor. It is overwritten every time the DLL is injected.

The DLL also opens its own console window (titled "Better Backpack"). Same content, but transient: closes when the game exits.

## Debug-output reference

What each line tells you, in the order it appears in a healthy run:

| Line | What it means |
|---|---|
| `=== Better Backpack DLL ===` | Worker thread started, log file open. |
| `target slot_count = 60` | Compile-time constant. Mismatch with what you expected? You're running a stale DLL. |
| `vanilla main = 40, vanilla mount = 30 (left untouched)` | Confirms the value-based filter. The DLL only patches components reading exactly 40. |
| `game exe base = 0x...` | Where the game module is loaded in memory. Different per-launch (ASLR). |
| `GObjects populated after N retries (M ms)` | UE's global object array has data. Latch onto this; it's the prerequisite for everything else. |
| `GObjects count = ~1500000` | Total reflected UObject count. Useful if you suspect a hung load. |
| `ProjectLogDir() = '...'` | Where UE *would* write `Augusta.log` if file logging weren't stripped. The file does not exist. See [SHIPPING-BUILD-NOTES.md](SHIPPING-BUILD-NOTES.md). |
| `ProjectSavedDir() = '...'` | The game's Saved/ root. |
| `ProjectModsDir() = '...'` | UE's intended mod directory (this is informational only; we don't use it). |
| `found N UInventoryComponent objects` | Total count for this scan. Includes CDOs and live instances. |
| `[CDO ] DefaultMaxSize=40 ...` | A class default. Patching this affects future spawns. |
| `[inst] DefaultMaxSize=40 ...` | A live instance. Patching this affects the running game right now. |
| `PATCH ... : 40 -> 60 (verify=60)` | Wrote 60, read back 60. The data-side patch took. |
| `widget PATCH UI_InventoryGrid_C.MaxRows: 3 -> 6 (verify=6)` | One grid CDO/instance patched. The DLL bumps every UI_InventoryGrid_C object whose MaxRows isn't already 6. |
| `initial widget patch round: N UI_InventoryGrid_C objects bumped to MaxRows=6` | First-pass count. N=0 means the grid class wasn't loaded yet (open the inventory and wait for the rescan). |
| `entering rescan loop (interval = 10 s)` | Worker enters its periodic re-check. |
| `RESET DETECTED ... : 40 -> 60 (re-patched)` | A component reverted to vanilla 40 (replication, hot reload), re-patched. |
| `rescan: N components (was M), K re-patched` | Periodic rescan summary. |

## Still stuck

If your symptom isn't listed, capture:

1. The full output of `inject.exe`.
2. The full contents of `%TEMP%\BetterBackpack.log`.
3. Your Grounded 2 build version (Steam menu > Properties > Updates).
4. Whether you're on Steam or Xbox Game Pass.

Open an issue with all four and paste them in. Without (1) and (2), nobody can tell whether the failure is in the injector, the DLL, the engine, or the game state.
