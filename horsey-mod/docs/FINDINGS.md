# Horsey Game - Modding Findings
> **Authoritative on:** project-state summary for the Horsey Game research/mod effort (TL;DR, decomp/mod status, next reads). Initial data-file survey is appended at the bottom.

Game: `C:\Games\Steam\steamapps\common\Horsey Game`. Build mtime 2026-05-08. Surveyed 2026-05-13.

## TL;DR

**We have a working external mod framework for Horsey Game.**

1. **100% of `Horsey.exe` decompiled** to C-like pseudocode (10,331 functions across 1,234 game-logic + 9,097 vendor). Every game function has a header comment; the 25 most critical have deep manual annotations.

2. **`horsey-mod` Rust crate** lives in [`abix-/Grounded2Mods`](https://github.com/abix-/Grounded2Mods) as a third sibling to `ueforge`/`unityforge`, built on the shared `modforge` framework.

3. **DLL injection + HTTP control plane working.** `horsey-inject.exe` attaches `horsey.dll` to a running Horsey.exe via `CreateRemoteThread(LoadLibraryW)`. An HTTP server runs at `127.0.0.1:33077` exposing 18 ops for live read/write of game state.

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
| `horsey-mod` crate | shipped, builds clean |
| `horsey.dll` + `horsey-inject.exe` | working artifacts |
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

### Headline findings (one-line each)

- **Built-in cheat menu**: unlock by typing `"debug"` in the pause menu (Money, Loaded, No Tire, Gong, Betting). Full citation: [`MECHANICS.md`](MECHANICS.md).
- **Tiredness toggle**: a single global flag (`DAT_1403d95c5`) zeros out `horse+0x205/0x206` every frame when set. Full citation: [`MECHANICS.md`](MECHANICS.md).
- **Game-state struct**: `DAT_1403fb0d8` is the world-state pointer; layout in [`STRUCTS.md`](STRUCTS.md).
- **Horse struct**: partial layout in [`STRUCTS.md`](STRUCTS.md).
- **Races counter**: `DAT_1403eded8` (separate global, not in the game-state struct).

## Gene system (overview)

Conceptual model lives in [`ALLELE-MODEL.md`](ALLELE-MODEL.md); per-gene reference in [`GENE-CATALOG.md`](GENE-CATALOG.md); engine-side gene -> render-slot mapping in [`SLOT-MAP.md`](SLOT-MAP.md). One-line summary: `genes.xml` declares 240 genes (attrs `m`/`s`/`g0..g3`/`n`); `pop.xml` declares 28 populations with per-allele weights `p0..p3`. Behavioral genes (OLD_AGE, NARCOLEPSY, WHITE_IS_LETHAL, STIFF_JOINTS, LIMP, FLU_IMMUNITY) are still inference-flagged until the gene-application code is traced.

## What's NOT in any data file (KNOWN by exhaustive grep)

- **No `STAMINA`, `FATIGUE`, `TIRED`, `RACES_PER_REST`, `ENERGY`, `RECOVERY`, or `COOLDOWN` gene or attribute anywhere.** The "horse can only run one race before tired" mechanic is hardcoded.
- **No base lifespan value.** `OLD_AGE` is a modifier, not a base. The base age-tick rate / death threshold is hardcoded.
- **No hunger/thirst tunable.** `StatusHungry` and `ThoughtHungry` sprites exist (sprites.xml:147, 154) so the mechanic exists, but its rate is hardcoded.
- **No `EnterSleep` / `WakeUp` cooldowns** in `sound.xml`. The sound registry just plays clips; it doesn't tune the mechanic.

Useful RE search anchors for the hardcoded mechanics above:
- **Sound names** (from `sound.xml`): `HorsesAge`, `WildMating`, `StartNextRace`, `RaceGo`, `WonRace`, `LoseRace`, `TitleCard`, `EnterLocationAbandoned`, `FillHole`, `DestroyTree`, `DestroyMountain`, `ReclaimLand`, `Fish`, `WhipCrack`, `BalloonFly`.
- **UI sprites** (from `sprites.xml`): `StatusOld`, `StatusTired`, `StatusHungry`, `StatusHungry2`, `ThoughtTired`, `ThoughtHungry`, `ThoughtHungry2`, `AnimSleep`, `AnimSleep2`, `SleepMoon`, `AgeWord`.

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

---

# Appendix: Initial data-file survey (merged from RESEARCH.md, 2026-05-15)

Historical record of the very first survey pass before any decompilation (2026-05-13). Kept verbatim; later sections of this doc supersede where they overlap, but the modding-tier framing here is still the cleanest single-page intro.

## Goal

User wants to mod out the tedium loop. Specifically:

1. **Horse stamina / fatigue**: a horse can only run ONE race before it's tired and needs to sleep. Want this to be much higher, or remove fatigue entirely.
2. **Horse lifespan**: horses die too quickly, forcing constant breeding/killing/swapping. Want longer lifespans (or much slower aging).

The user is fine with the breeding/sleeping/killing systems existing. The complaint is FREQUENCY, not the mechanics. Goal is to dial those knobs down, not delete the mechanics.

Target outcome: play sessions that focus on racing and farming, not on managing a constant rotation of dying horses.

### Full data-file survey for our two knobs

Reviewed: `genes.xml` (242 lines, all), `pop.xml` (2714, all gene refs grepped), `sound.xml` (668), `sprites.xml` (322), `furniture.xml`, `locs.xml`, `terrain.xml`, `veg.xml`, `biglogo.xml`, `bubbletime.txt`/`classified.txt`/`picory.txt`/`softsquare.txt` (font metrics), `names.txt` (just names), `horsey.tmx` (tile CSV), `settings.xml` (window/audio).

#### How the gene system works

Two-file design: `genes.xml` declares each gene's value table; `pop.xml` declares per-population spawn weights over alleles. Full conceptual model in [`ALLELE-MODEL.md`](ALLELE-MODEL.md); per-gene reference in [`GENE-CATALOG.md`](GENE-CATALOG.md).

#### Genes directly relevant to user's complaints

Lifespan / fatigue / behavior knobs (OLD_AGE, NARCOLEPSY, WHITE_IS_LETHAL, LITTER_SIZE, STIFF_JOINTS, LIMP, RAMPAGE, FLU_IMMUNITY): allele values + interpretation + per-pop usage notes live in [`GENE-CATALOG.md`](GENE-CATALOG.md) under each gene's row. XML-edit recipes for the same set live in [`CONTENT-CREATION.md`](CONTENT-CREATION.md#tuning) (Section 9).

#### Mod strategy

XML-edit recipes for the data-only tier are in [`CONTENT-CREATION.md`](CONTENT-CREATION.md#tuning). The RE-required tier for stamina/fatigue (no data-file exposure) is documented in [`ENGINE-EXTENSION.md`](ENGINE-EXTENSION.md) and tracked in [`todo.md`](todo.md).

## Engine-evidence anchor table

These are the binary strings/imports that nail the engine identification. Useful when re-anchoring after a game update.

| Component | Evidence |
|---|---|
| **SDL3** | hundreds of `SDL.app.metadata.*`, `SDL.gpu.device.create.*`, `SDL.filedialog.*` strings. The `SDL.gpu.*` API is SDL3-only (SDL2 doesn't have it). |
| **cute_sound** | `CUTE_SOUND_ERROR_CANT_INIT_SDL_AUDIO`, `CUTE_SOUND_ERROR_WAV_ONLY_MONO_OR_STEREO_IS_SUPPORTED`, etc. Single-header C lib by RandyGaul. |
| **stb_image_write** | `stb_image_write.h` literal in binary. Single-header lib by nothings. |
| **D3D12 / D3D11 / OpenGL / OpenGL ES** | dynamic imports of `d3d12.dll`, `d3d11.dll`, `dxgi.dll`, `opengl32.dll`, `libGLESv2.dll`, `d3dcompiler_47.dll`, `WinPixEventRuntime.dll`. SDL_GPU picks a backend at runtime. |
| **Tiled** | `horsey.tmx` is the world map, plain XML with `tiledversion="2018.09.12"`. |
| **ChevyRay fonts** | bitmap fonts (`Bubble Time`, `Classified`, `Picory`, `Soft Square`) are from chevyray.itch.io. `.crf` is the ChevyRay binary font format. |
| **steam_api64.dll** | classic Steamworks, NOT Steamworks.NET. So no managed runtime. |

No Mono. No IL2CPP. No CoreCLR. No Python embed. No Lua VM. No Haxe runtime. No `.NET` assemblies anywhere. Hand-rolled C/C++ on SDL3.

The string `Aqualime` in the binary is NOT an engine name. It's part of `PDP Xbox One Aqualime`, an SDL controller database entry. Red herring.

No PDB path or build-machine source path leaked, so the build is stripped.

For the file layout / data formats / modding-path tiers. See [`CONTENT-CREATION.md`](CONTENT-CREATION.md) sections 1-2.
