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

Two-file design:

- **`genes.xml`** declares each gene. Attributes:
  - `m` = mutation rate (%).
  - `s` = scale (`1` = discrete integer, `100` = continuous/percent).
  - `g0`, `g1`, `g2`, `g3` = the FOUR possible allele values. A horse's actual trait is some combination of inherited alleles.
  - `n` = codon order (the 4-letter ACGT permutation used to encode this gene in the DNA).
- **`pop.xml`** declares each population (`default`, `human`, `freak`, `tiger`, ...) and per-gene SPAWN WEIGHTS over the four alleles: `<gene name="X" p0="1" p2="18" />` means at spawn, allele g0 is weight 1 and g2 is weight 18 (heavily favored).

So genes.xml says what the trait VALUES are; pop.xml says how often each allele spawns per population.

#### Genes directly relevant to user's complaints

| Gene | Where | Values g0/g1/g2/g3 | What it likely controls |
|---|---|---|---|
| `OLD_AGE` | genes.xml:215 | 0 / 0 / -1 / +2 | Aging modifier per horse. g3 = die faster, g2 = live longer. Default pop spawns ONLY g0 (=0), so baseline horse is neutral. `human` pop spawns g3 (`p3="1"`, line 1536), `freak` pop spawns mostly g2 and g3 (line 2685). Worth testing: change all four to large negatives. |
| `NARCOLEPSY` | genes.xml:217 | 0 / 0 / 1 / 0 | g2 means "has narcolepsy". Default pop has p0=1 (none). Some pops (line 604, 2687) have narcoleptic alleles. Setting g2=0 globally removes the trait. |
| `RAMPAGE` | genes.xml:209 | 0 / 0 / 0 / 1 | Behavior flag. g3 = rampage trait. |
| `LIMP` | genes.xml:216 | 0 / 1 / 0 / 2 | g1/g3 give limping severity. |
| `FLU_IMMUNITY` | genes.xml:218 | 0 / 0 / 0 / 1 | g3 = immune. Setting all to 1 = universal flu immunity. |
| `WHITE_IS_LETHAL` | genes.xml:190 | 0 / 1 / 0 / 0 | LETHAL white. This is real horse genetics: white-coat horses die. Setting all four to 0 removes the lethal mechanic entirely. |
| `LITTER_SIZE` | genes.xml:214 | 1 / 2 / 3 / 5 | Babies per breeding. Bump for less breeding upkeep. |
| `STIFF_JOINTS` | genes.xml:220 | 0 / 18 / 50 / 0 | Probably reduces movement. |

#### What's NOT in any data file

- **No `STAMINA`, `FATIGUE`, `TIRED`, `RACES_PER_REST`, `ENERGY`, `RECOVERY`, or `COOLDOWN` gene or attribute anywhere**. The "horse can only run one race before tired" mechanic is hardcoded.
- **No base lifespan value**. `OLD_AGE` is a modifier, not a base. The base age-tick rate / death threshold is hardcoded.
- **No hunger/thirst tunable**. `StatusHungry` and `ThoughtHungry` sprites exist (sprites.xml:147, 154) so the mechanic exists, but its rate is hardcoded.
- **No `EnterSleep` / `WakeUp` cooldowns** in `sound.xml`. The sound registry just plays clips; it doesn't tune the mechanic.

#### Sound names that confirm mechanics exist (useful as RE search anchors later)

`HorsesAge`, `WildMating`, `StartNextRace`, `RaceGo`, `WonRace`, `LoseRace`, `TitleCard`, `EnterLocationAbandoned`, `FillHole`, `DestroyTree`, `DestroyMountain`, `ReclaimLand`, `Fish`, `WhipCrack`, `BalloonFly`.

UI sprites confirming the same: `StatusOld`, `StatusTired`, `StatusHungry`, `StatusHungry2`, `ThoughtTired`, `ThoughtHungry`, `ThoughtHungry2`, `AnimSleep`, `AnimSleep2`, `SleepMoon`, `AgeWord`.

### Mod strategy

**Tier 1 (data-only, try first, no RE):** Edit `genes.xml` to neutralize the bad alleles. This won't change BASE rates but will guarantee every horse has the LONGEST-LIVED and LEAST-NARCOLEPTIC alleles. Specifically:

1. `OLD_AGE`: change `g0="0" g1="0" g2="-1" g3="2"` -> some large negative like `g0="-100" g1="-100" g2="-100" g3="-100"`. If `OLD_AGE` is added to a fixed base age threshold to compute "time until death", every horse now lives much longer regardless of inherited alleles.
2. `NARCOLEPSY`: change all four to `0` to eliminate the trait entirely.
3. `WHITE_IS_LETHAL`: change all four to `0` to stop white-coat deaths.
4. `LITTER_SIZE`: bump to e.g. `g0="5" g1="8" g2="10" g3="15"` to drastically cut breeding sessions.
5. Delete `genes.dat` before launching so the game rebuilds the binary cache from the edited XML.

**Caveat:** if `OLD_AGE` is the trait modifier with a hardcoded BASE of e.g. 100 (game days till death), and `OLD_AGE` value adds on top, then `-100` makes lifespan 0 and horses die immediately. We must test with a SMALL negative first (e.g. `-10`) before going extreme. Save before testing.

**Tier 3 (RE, required for stamina/fatigue):** The "one race then tired" mechanic has no data exposure. To fix this:

1. Open `Horsey.exe` in Ghidra. Search strings: `Tired`, `Sleep`, `WakeUp`, `Energy`, `Stamina`, `RaceComplete`, `WonRace`.
2. The XML loader is a likely entry point - any function reading `OLD_AGE` likely lives next to the function reading the (hardcoded) fatigue threshold.
3. Best-case: the fatigue threshold is a numeric immediate (`cmp eax, 1`) - patch to e.g. `cmp eax, 100`.
4. Worst-case: it's a float or stored elsewhere - DLL with MinHook to override the read.

### Concrete next steps

1. **Test Tier-1 mods in order:** start with `WHITE_IS_LETHAL` (safest, lowest risk of breaking sim). Then `LITTER_SIZE`. Then `NARCOLEPSY`. Save game first. Verify each works before moving to the next.
2. **OLD_AGE test:** try `g3="-5"` first (just make the worst allele harmless). If the game keeps working and horses live longer, push further.
3. **RE prep for stamina:** once Tier-1 verified, dump `Horsey.exe` strings filtered for "Tired"/"Sleep"/"Energy" and bring offsets back here. That's the RE entry point.

## Top-level layout

```
Horsey.exe         4.4 MB   game binary (native PE x64)
steam_api64.dll    312 KB   Steamworks SDK
data/              1.9 MB   all gameplay data + assets
sound/              47 MB   402 .wav files + .ogg music
save/                       save1.dat, save1.dat.prev, settings.xml, steam_autocloud.vdf
```

No installer, no `_Data` folder, no `*.pak`/`*.assets`/`*.uasset`/`*.gd`/`*.json` manifest files. Plain folder with plain files.

## Engine

Custom native C/C++ engine. NOT Unity, Unreal, Godot, GameMaker, Haxe/OpenFL, Love2D, or anything with a known modding scene.

Evidence from imports and strings in `Horsey.exe`:

| Component | Evidence |
|---|---|
| **SDL3** | hundreds of `SDL.app.metadata.*`, `SDL.gpu.device.create.*`, `SDL.filedialog.*` strings. The `SDL.gpu.*` API is SDL3-only (SDL2 doesn't have it). |
| **cute_sound** | `CUTE_SOUND_ERROR_CANT_INIT_SDL_AUDIO`, `CUTE_SOUND_ERROR_WAV_ONLY_MONO_OR_STEREO_IS_SUPPORTED`, etc. Single-header C lib by RandyGaul. |
| **stb_image_write** | `stb_image_write.h` literal in binary. Single-header lib by nothings. |
| **D3D12 / D3D11 / OpenGL / OpenGL ES** | dynamic imports of `d3d12.dll`, `d3d11.dll`, `dxgi.dll`, `opengl32.dll`, `libGLESv2.dll`, `d3dcompiler_47.dll`, `WinPixEventRuntime.dll`. SDL_GPU picks a backend at runtime. |
| **Tiled** | `horsey.tmx` is the world map, plain XML with `tiledversion="2018.09.12"`. |
| **ChevyRay fonts** | bitmap fonts (`Bubble Time`, `Classified`, `Picory`, `Soft Square`) are from chevyray.itch.io. Format is the standard ChevyRay `.txt` + `.png` pair. `.crf` is the ChevyRay binary font format. |
| **steam_api64.dll** | classic Steamworks, NOT Steamworks.NET. So no managed runtime. |

No Mono. No IL2CPP. No CoreCLR. No Python embed. No Lua VM. No Haxe runtime. No `.NET` assemblies anywhere. This is hand-rolled C/C++ on SDL3.

The string `Aqualime` in the binary is NOT an engine name. It's part of `PDP Xbox One Aqualime`, an SDL controller database entry for a specific PDP-brand Xbox controller color. Red herring.

No PDB path or build-machine source path leaked into the binary, so the dev's build is stripped. That makes RE harder than e.g. a typical Unity build that ships with full symbols.

## Data formats

### Plain XML (easy to mod by hand)

| File | Content | Lines |
|---|---|---|
| `data/genes.xml` | Trait/gene table: name, mutation rate, scale, four allele values, allele codon order. | 242 |
| `data/pop.xml` | Per-population gene weight tables (which alleles spawn in which population). | 2714 |
| `data/sound.xml` | Sound + music registry. Maps logical name to `.wav`/`.ogg` filename, with vol/pitch/pitchlow/pitchhigh attributes. | 668 |
| `data/sprites.xml` | UI sprite atlas (Pointer, GrabHand, etc). `<sprite n="..." x=".." y=".." w=".." h=".." c=".."/>`. `c` is frame count for animations. | 322 |
| `data/furniture.xml` | Furniture sprite atlas (Bar, TV, BeerTap, SumoRing, etc). | 140 |
| `data/locs.xml` | Location/building sprite atlas (LocStable, LocTrack, LocCircus, etc). | 36 |
| `data/terrain.xml` | Terrain tile atlas (Plain, Grass, Water, Mountain, etc). | 45 |
| `data/veg.xml` | Vegetation atlas. | 9 |
| `data/biglogo.xml` | Logo metadata. | 4 |
| `data/horsey.tmx` | World map. Standard Tiled XML, 400x225 tiles at 32px. Two tilesets: terrain.tsx (firstgid 1) and locs.tsx (firstgid 97). `.tsx` files appear to be missing from the install, only `.tmx` ships. Tiled would refuse to open without them, so the dev likely bakes the tilesets in or only edits in-house. |

### Plain text

| File | Content |
|---|---|
| `data/names.txt` | 4999 horse names, one per line. UTF-8 with BOM. |
| `data/bubbletime.txt`, `classified.txt`, `picory.txt`, `softsquare.txt` | ChevyRay font metric files (size/ascent/descent/chars/advance/offset_x/offset_y/kerning). |
| `data/n64.fnt` | Bitmap font (probably AngelCode/BMFont format). |

### Binary

| File | Notes |
|---|---|
| `data/genes.dat` | Gene name table cache. Confirmed binary contains length-prefixed ASCII strings ("SIZE", "ASPECT", "SKINNY", ...) matching `genes.xml` order. Probably a baked-on-load lookup; editing `genes.xml` may invalidate it, or the game may regenerate it. |
| `data/*.crf` | ChevyRay binary font (companion of the `.png`). Format documented at chevyray.itch.io/font-toolkit. |
| `save/save1.dat` | 245 KB binary save. Header: 4-byte count, 4-byte unknown, then repeating records. Visible plain-text horse names (Dale, Honky Tonk Tonky, Born To Be Wild, Lucky) confirm it stores the population. Length-prefixed strings, looks straightforward to reverse. |
| `save/settings.xml` | Plain XML: sound, volume, music, fullscreen, window pos/size, vsync, background_draw, background_sim. |

### PNGs and atlases

Every `.xml` atlas has a sibling `.png` of the same name (e.g. `furniture.xml` <-> `furniture.png`). Replace the PNG and the sprite rects stay valid as long as you keep the same dimensions/positions. Easy art reskin path.

### Sound

- `sound/*.wav`: 402 files, ~47 MB total. Plain PCM/RIFF WAV (cute_sound only supports mono/stereo WAV).
- `sound/Music_*.ogg`: music tracks referenced from `sound.xml`.
- Replacing audio is trivial: drop a file with the same name. Adding new sounds means editing `sound.xml` AND having the engine actually reference the new key (which requires code changes).

## Modding surface, ranked by effort

### Tier 1: zero-code mods (minutes)

What you can change with just a text editor or image editor, no RE needed:

- **Horse name pool**: edit `data/names.txt`.
- **Genetics tuning**: edit `data/genes.xml` and `data/pop.xml` (mutation rates, allele effects, population weights). Caveat: `genes.dat` may need to be deleted to force regen if the gene table changes.
- **Sound mod / music replacement**: drop replacement WAVs/OGGs into `sound/` with the same filenames. Tweak vol/pitch in `sound.xml`.
- **Art reskin**: edit any `.png` in `data/`. Keep dimensions; the `.xml` atlas points at fixed pixel rects.
- **Settings tweaks**: `save/settings.xml`.
- **Font swap**: replace the ChevyRay `.png` + `.txt`/`.crf` pair.

### Tier 2: data-only behavior mods (hours, no RE)

- **World map**: `horsey.tmx` is plain Tiled XML with a 400x225 CSV tile grid. You can edit the CSV directly. Adding NEW locations probably requires the engine to know about new sprite indices and behaviors, so additions are bounded.
- **Sprite atlas additions**: extend the `.png` and add `<sprite>` entries. New sprites that no code references are dead though.
- **Save editor**: the binary save format (`save1.dat`) is reverse-engineerable. Length-prefixed strings, fixed-size records. A custom Python parser is a weekend project.

### Tier 3: native code mods (serious project)

Anything that changes game logic requires reverse-engineering `Horsey.exe`:

- **Tools**: IDA Pro / Ghidra / Cutter / Binary Ninja. The `assembly` skill in this environment is built for exactly this workflow.
- **Hook framework**: write a DLL, load via DLL hijack (proxy `steam_api64.dll` or a delay-loaded DLL) or inject. Use MinHook or Microsoft Detours for inline hooks.
- **No symbols**: 4.4 MB exe, stripped. You'll be naming functions by hand. Tractable but tedious for a single dev.
- **No community**: zero existing offset tables, zero existing modding tools, zero existing patches. You'd be establishing the scene.
- **Per-update fragility**: every patch shifts function addresses. Offset-based hooks rebreak. Pattern-based hooks (byte signatures) survive minor updates but not major refactors.

What this enables: trainers (god mode, infinite money), gameplay tweaks (race speed, breeding rules), full custom features. Realistic scope for one person.

## Game content hints (from data spelunking)

This is a horse-breeding/racing/farming sim with multiple locations:
- Stable, Track, Sweetie, Hermit, Crispr (CRISPR gene-editing?), Glue, CarLot, Lab, Supply, Ecologist, Hutch, Circus, Zoo, Acres, Saloon, PowerPlant, Paddock, Sumo, Pawn.
- Genes include `QUADRUPED`/`BIPED`, `SPLAY`, `LEG_COUNT`, `TAIL_*`, `CHEST_BIG/SMALL`, `MUSCLE_USE`, `OSTODERM`, `BREAK_FORCE`, `SPEED_FACTOR`. Procedural creature generation with gene weights.
- Mechanics referenced in `sound.xml` comments: FillHole, DestroyTree, DestroyMountain, ReclaimLand (surround water tiles with fences), Fish, WhipCrack, BalloonFly, Dung in cart, betting/racing loop.

## Open questions / next research

- Where are `terrain.tsx` and `locs.tsx`? Not in the install. The `.tmx` references them by relative path. Either baked into the exe, or the dev keeps them in-tree and only ships the resolved `.tmx`. Probably baked - explains why no Tiled `.tsx` file ships.
- `genes.dat` regen behavior: does the game rebuild it from `genes.xml` on startup, or is it authoritative? Delete-and-reload test needed.
- Save format full reverse: 245 KB is small enough to map out in a couple of sessions.
- Is there a hidden debug console / dev hotkey? Search the exe for `printf`/`console` markers and unbound key handlers.
- Find the dev/publisher to know how patch cadence will affect mod stability. (PDP Aqualime is a red herring.)
- Confirm the game ships with cute_framework, not just cute_sound (cute_framework is RandyGaul's full game framework around SDL). Look for `cf_` prefix functions.

## Recommended starting point

Pick one of these and we'll go deep:

1. **Tweak mod**: edit `pop.xml`/`genes.xml` to make freak horses spawn often. Verify the game loads the change. Establishes the data-mod pipeline.
2. **Save reverse**: build a Python save reader/writer. Unlocks save-edit mods cheaply.
3. **Static RE pass**: load `Horsey.exe` in Ghidra, identify the XML loader and the main loop, name 10-20 functions. Foundation for any future native mod.
