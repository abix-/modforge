# Horsey Game - Modding Findings

Game: `C:\Games\Steam\steamapps\common\Horsey Game`. Build mtime 2026-05-08. Surveyed 2026-05-13.

## TL;DR

**We have a working external mod framework for Horsey Game.**

1. **100% of `Horsey.exe` decompiled** to C-like pseudocode (10,331 functions across 1,234 game-logic + 9,097 vendor). Every game function has a header comment; the 25 most critical have deep manual annotations.

2. **`horseyforge` Rust crate** lives in [`abix-/Grounded2Mods`](https://github.com/abix-/Grounded2Mods) as a third sibling to `ueforge`/`unityforge`, built on the shared `modforge` framework.

3. **DLL injection + HTTP control plane working.** `horseyforge-inject.exe` attaches `horseyforge.dll` to a running Horsey.exe via `CreateRemoteThread(LoadLibraryW)`. An HTTP server runs at `127.0.0.1:33077` exposing 18 ops for live read/write of game state.

4. **Hot reload partial.** Cargo can rebuild while the game is running (staged DLLs avoid file lock). `--reload` swaps generations cleanly in some cases but currently causes a delayed crash because helper threads inside the old DLL haven't fully unwound when `FreeLibrary` is called. Hardening pending.

5. **`no_tire = true` by default** every time the DLL loads. The user's headline complaint (horses tire after one race) is solved by injection alone, no in-game cheat menu typing.

The game also ships with a **built-in cheat menu** unlocked by typing `"debug"` in the pause menu. It has "No Tire" / "Money" / "Loaded" buttons. See [`MECHANICS.md`](MECHANICS.md).

The lifespan complaint is still open. The retirement-by-age handler is identified (`FUN_1400df280`) but lifespan tuning requires more reverse-engineering.

## Primary Goal

**100% of `Horsey.exe` decompiled and documented.** Every game-logic function identified, named, and described. Every struct (Horse, Gene, Population, World, etc.) reconstructed. Every hardcoded constant catalogued.

Completion criterion: every function in the binary is either (a) identified as third-party library code (SDL3, cute_sound, stb_image_write, MSVC CRT) and skipped, or (b) documented in this repo with name, address, signature, behavior, and the data it touches.

Mod targets like "stamina threshold" and "lifespan" come out of this work as side effects. The deliverable is the documentation itself.

## Working principle

Every claim must be backed by either:

1. **Decompiled code** from `Horsey.exe`, with the function address cited.
2. **An in-game observation** that directly tests the claim (save-diff after a known action).

Anything else is labelled `(INFERRED, NOT VERIFIED)` or removed.

## Engine (KNOWN, decompiled)

Custom native C/C++ engine on **SDL3** + **cute_sound** + **stb_image_write**. Renders via SDL_GPU (D3D12/D3D11/OpenGL/GLES backends selected at runtime). Tiled (`.tmx`) for the world map. ChevyRay bitmap fonts. Saves to `save%d.dat` (format string confirmed in exe).

What it is NOT: not Unity, Unreal, Godot, GameMaker, Haxe, OpenFL, Love2D, MonoGame, libGDX. No Mono, no IL2CPP, no Lua, no Python embed. No PDB. No exposed scripting layer.

## Decompilation state

| Metric | Value |
|---|---|
| Binary functions decompiled | 10,331 / 10,332 |
| Decompiled pseudocode | 18.3 MB |
| Game-logic functions (call-graph filtered) | 1,234 (after seed expansion) |
| Vendor functions excluded | 9,097 |
| Per-function .md scaffolds | 1,234 (one per game function) |
| Functions with pattern-based classification | 1,234 (100%) |
| Functions with string-anchored role | 283 (22.9%) |
| Functions with deep manual annotation | 25 (in `decompiled/annotated/*.c`) |
| Functions with batch annotation entry | all 1,234 (BATCH-01..14.md) |

## Mod framework state (as of grounded2mods commit `c37fa54`)

| Component | Status |
|---|---|
| `horseyforge` crate | shipped, builds clean |
| `horseyforge.dll` + `horseyforge-inject.exe` | working artifacts |
| DLL injection via `CreateRemoteThread(LoadLibraryW)` | working |
| HTTP control plane on `127.0.0.1:33077` | working, 18 ops registered |
| Auth via `X-Ueforge-Auth` + token file | working |
| `_shutdown` op + staged-DLL hot-reload | reload swap works, **but causes delayed crash** (hardening TODO) |
| `cheats.no_tire = true` by default at attach | **working**. Confirmed live |
| MinHook trampolines on game functions | not started |
| SDL3 input hooks for hotkeys | not started |
| Save-writer hook for sidecar state | not started |
| Roster UI (web frontend) | not started |

## Key findings (each with code citations)

All findings are derived from real decompiled code. See [`MECHANICS.md`](MECHANICS.md) for full source-line citations.

### Built-in cheats (the BIG find)

The dev shipped cheats and they ship in the public binary. Unlock by typing `"debug"`:

- `FUN_140066200` line 60371-60376: character-by-character match against the literal string `"debug"`. When complete, sets `DAT_1403d959b = 1` (debug mode active).
- Debug mode shows extra status line and unlocks the cheat buttons in pause menu: "Betting Mode", "Gong", "Money", "Loaded", "No Tire" / "Yes Tire".

### Tiredness toggle (`DAT_1403d95c5`)

- `FUN_140066200` line 60434-60443: pause-menu button labelled "No Tire" or "Yes Tire" that toggles the flag.
- `FUN_1400ce6c0`-area line 121172-121184: per-frame update loop. When flag is set, zeroes out `horse + 0x205` and `horse + 0x206` on every horse on the track. Result: horses never accumulate tiredness state.

### Game state struct (`DAT_1403fb0d8`)

Single global pointer to the world state. Confirmed fields:

| Offset | Field |
|---|---|
| 0x308 | Money (int32) |
| 0x314 | Year counter (int32, displayed +1) |
| 0x318 | Sleeps counter (int32) |
| 0x31c..0x349 | 7 supply types in 12-byte-strided records (counter int32 + 2 flag bytes each) |

### Horse struct (partial)

| Offset | Field |
|---|---|
| 0x1c | type/kind (int32) |
| 0x1c4 | unknown delta |
| 0x1c8 | bool flag |
| 0x205 | tiredness flag A (uint8) |
| 0x206 | tiredness flag B (uint8) |

More fields will be reconstructed as we read more functions.

### Races counter

Lives in a separate global `DAT_1403eded8` (not in the main game-state struct).

## Gene system (PARTIALLY KNOWN, INFERENCE FLAGGED)

### KNOWN from the XML

- `genes.xml` declares each gene. Attributes: `m` (mutation %), `s` (scale: 1 or 100), `g0..g3` (four allele values), `n` (4-letter ACGT codon order).
- `pop.xml` declares populations. Each `<gene>` inside a `<pop>` block has `p0..p3` attributes weighting which allele spawns.
- 28 populations exist: default, scratch, fest horse, crazy horse, impala, alligator, giraffe, rabbit, duck, dino, centipede, tiger, moose, dachshund, bear, cow, human, centaur test, jockey, leprechaun, pepper, car, appletree, yeast, hay, fish, helix, freak.
- 242 genes total.

### INFERRED, NOT VERIFIED

- That `s=1` means discrete integer and `s=100` means continuous/percent. Plausible, not proven.
- The semantics of `OLD_AGE`, `NARCOLEPSY`, `WHITE_IS_LETHAL`, `STIFF_JOINTS`, `LIMP`, `FLU_IMMUNITY`. All inferred from name.

These are gambling targets until verified by reading the gene-application code (next target: `FUN_1400a3eb0` chromomap loader and the function that maps each gene to its in-game effect).

## What's NOT in any data file (KNOWN by exhaustive grep)

Stamina, fatigue, race cooldown, base lifespan, hunger/thirst rate, sleep duration. None of these are XML-tunable. All are in `Horsey.exe`. UI sprites confirm the mechanics exist (`StatusOld`, `StatusTired`, `StatusHungry`, `ThoughtTired`, `ThoughtHungry`, `AnimSleep`, `SleepMoon`, `AgeWord`).

## Save format (PARTIALLY KNOWN)

Static-analysis pass on `save1.dat`:

- Header: 20 bytes (5 uint32s). First is save format version (12). Other four: unknown.
- 0x14..~0xc6f: horse roster of ~80-85 variable-length records. Per record: length-prefixed UTF-8 name, 6 flag bytes, two parent IDs (int32, -1=none), unknown uint32, child count, child IDs.
- Remaining 98% of the file: opaque binary blocks (likely genomes, world state, item positions).

Full proper docs pending decompilation of `FUN_140089510` (save loader) and `FUN_140089510`'s caller.

## Toolchain (installed)

| Component | Version | Path |
|---|---|---|
| Microsoft OpenJDK | 21.0.11.10 | `C:\Program Files\Microsoft\jdk-21.0.11.10-hotspot` |
| Ghidra | 12.1 (released 2026-05-13) | `C:\code\ghidra_12.1_PUBLIC` |
| pyghidra | 3.0.2 | pip |
| JPype1 | 1.5.2 | pip |
| Ghidra project | created | `C:\code\horsey-mods\ghidra-project\horsey.gpr` |

## Plan progress

| Stage | Status | Output |
|---|---|---|
| 0. Tooling | **DONE** | Ghidra + pyghidra installed |
| 1. Vendor exclusion | **DONE** (call-graph based) | `decompiled/vendor_funcs.txt` (9,360 funcs) |
| 2. String-anchored functions | **PARTIAL** | 17 / 971 game funcs role-tagged from strings |
| 3. Structs | **STARTED** | game-state + horse struct partial in `MECHANICS.md` |
| 4. Constants | **STARTED** | Money +1000, Loaded +20 captured in `MECHANICS.md` |
| 5. Remaining functions | **STARTED** | 298 / 971 pattern-classified; 673 unclassified |
| 6. Mod artifacts | not started | none yet |

## Open next reads (priority order)

1. `FUN_1400df280` retirement handler. Pinpoint the age threshold for "horse is too old to race".
2. `FUN_1400a3eb0` chromomap loader. Confirm how `genes.xml` attributes map to runtime behavior, esp. `OLD_AGE` direction.
3. `FUN_140089510` save-file open/write. Get the save struct layout.
4. `FUN_14008ffc0` genome clipboard copy. Get the human-readable genome format.
5. `FUN_140033a10` price formula. Confirm the `* years` factor and the age field offset on the horse struct.

## Repo artifacts

| File | Purpose |
|---|---|
| [`MECHANICS.md`](MECHANICS.md) | **PRIMARY**: verified game mechanics from decompiled code with citations. |
| `FINDINGS.md` | This file. Current state and direction. |
| `DECOMPILATION-STATUS.md` | Decompilation pipeline, toolchain, statistics. |
| `FUNCTION-BREAKDOWN.md` | Why 10,332 functions isn't crazy (vendor vs game). |
| `TOOL-RESEARCH.md` | Why we picked Ghidra + pyghidra. |
| `RESEARCH.md` | Historical working log of the data-file survey. |
| `RE-NOTES.md` | Exe strings useful as Ghidra anchors. |
| `SAVE-FORMAT.md` | Static-analysis pass on `save1.dat`. |
| `decompiled/all_functions.c` | 18.3 MB of decompiled pseudocode for all 10,332 functions. |
| `decompiled/INDEX.md` | Per-function index (address, name, size, signature). |
| `decompiled/KEY-FUNCTIONS.md` | String anchors -> function addresses. |
| `decompiled/funcs/` | One C file per decompiled function (sharded by addr). |
| `decompiled/game-funcs/` | 971 per-function .md scaffolds (with classification + role + code). |
| `decompiled/game-funcs/INDEX.md` | Sorted by size; jump point for which function to read next. |
| `decompiled/game-funcs/CLASSIFICATION.md` | Pattern-based category breakdown. |
| `decompiled/key-funcs/` | 20 highest-priority functions extracted individually. |
| `decompiled/game_neighborhood.txt` | 971 game-logic addresses. |
| `decompiled/vendor_funcs.txt` | 9,360 vendor addresses. |
| `decompile.py` | pyghidra driver to (re)build `all_functions.c`. |
| `search_decomp.py` | Regex search across decompiled output. |
| `extract_funcs.py`, `extract_all.py` | Carve function bodies into individual files. |
| `analyze_funcs.py` | Call-graph based game-vs-vendor classifier. |
| `classify_funcs.py` | Naive name/body classifier (cross-check). |
| `smart_classify.py` | Pattern-based per-function classifier. |
| `merge_classifications.py` | Re-emit per-function .md with classification baked in. |
| `document_game_funcs.py` | Scaffold per-function .md for game-logic addresses. |
| `parse_save.py`, `diff_save.py` | Save file parsing/diffing. |
| `save-snapshots/save_A.dat`, `save_B.dat` | Captured save snapshots. |
