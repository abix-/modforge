# Horsey Game - Modding Findings

Game: `C:\Games\Steam\steamapps\common\Horsey Game`. Build mtime 2026-05-08. Surveyed 2026-05-13.

## Primary Goal

**100% of `Horsey.exe` decompiled and documented.** Every game-logic function identified, named, and described. Every struct (Horse, Gene, Population, World, etc.) reconstructed. Every hardcoded constant catalogued. Behavior documented in this repo.

Completion criterion: every function in the binary is either (a) identified as third-party library code (SDL3, cute_sound, stb_image_write, MSVC CRT) and skipped, or (b) documented in this repo with name, address, signature, behavior, and the data it touches.

Mod targets like "stamina threshold" and "lifespan" come out of this work as side effects. The deliverable is the documentation itself.

## Scope reality check

`Horsey.exe` is 4.4 MB stripped PE x64. Estimate: 500-2000 game-logic functions after excluding vendor libraries. This is a multi-week project at minimum. We will work incrementally, documenting in chunks, and the docs are the source of truth as we go.

## Working principle

Inferring meaning from binary patterns or filenames is guessing in disguise. Any claim in our docs must be backed by either:

1. **Decompiled code** from `Horsey.exe` (Ghidra), with the function address cited.
2. **An in-game observation** that directly tests the claim (e.g. save-diff after a known action).

Anything else is labelled `(INFERRED, NOT VERIFIED)` or removed.

## Secondary goal (player motivation)

Reduce the tedium of swap/sleep/breed/kill cycles. Two complaints:

1. Horses can run only ONE race before they're tired.
2. Horses have a short life and die fast.

These mods fall out of the decompilation naturally.

## Engine (KNOWN)

Custom native C/C++ engine on **SDL3** + **cute_sound** + **stb_image_write**. Renders via SDL_GPU (D3D12/D3D11/OpenGL/GLES backends selected at runtime). Tiled (`.tmx`) for the world map. ChevyRay bitmap fonts. Saves to `save%d.dat` (format string confirmed in exe).

What it is NOT: not Unity, Unreal, Godot, GameMaker, Haxe, OpenFL, Love2D, MonoGame, libGDX. No Mono, no IL2CPP, no Lua, no Python embed. No PDB. No exposed scripting layer.

Consequence: no MelonLoader / BepInEx / Harmony equivalent exists. Code mods require native reverse engineering.

## File layout (KNOWN)

```
Horsey.exe         4.4 MB     stripped native PE x64
steam_api64.dll    312 KB
data/              1.9 MB     gameplay data + atlases
sound/              47 MB     402 .wav + .ogg music
save/                         save1.dat (~245 KB), settings.xml
```

### data/ inventory (KNOWN)

| File | Content |
|---|---|
| `genes.xml` (242 lines) | Gene definitions: name, mutation rate, scale, 4 allele values, codon order. |
| `pop.xml` (2714) | Per-population (default, human, freak, tiger, ...) per-gene spawn weights over 4 alleles. |
| `sound.xml` (668) | Sound + music registry. |
| `sprites.xml` (322) | UI sprite atlas. |
| `furniture.xml`, `locs.xml`, `terrain.xml`, `veg.xml`, `biglogo.xml` | Sprite atlases. |
| `horsey.tmx` | Tiled world map, 400x225 tiles at 32px. |
| `names.txt` | 4999 horse names. |
| `*.crf` + `*.png` + `*.txt` | ChevyRay bitmap fonts. |
| `genes.dat` | Binary cache of gene table. Regenerated from `genes.xml` (delete to force regen). |

## Gene system (PARTIALLY KNOWN, PARTIALLY INFERRED)

### KNOWN from the XML

- `genes.xml` declares each gene. Attributes: `m` (mutation %), `s` (scale: 1 or 100), `g0..g3` (four allele values), `n` (4-letter ACGT codon order).
- `pop.xml` declares populations. Each `<gene>` inside a `<pop>` block has `p0..p3` attributes weighting which allele spawns.
- 28 populations exist: default, scratch, fest horse, crazy horse, impala, alligator, giraffe, rabbit, duck, dino, centipede, tiger, moose, dachshund, bear, cow, human, centaur test, jockey, leprechaun, pepper, car, appletree, yeast, hay, fish, helix, freak.
- 242 genes total.

### INFERRED, NOT VERIFIED

- That `s=1` means discrete integer and `s=100` means continuous/percent. Plausible but not proven.
- That higher `OLD_AGE` value = dies sooner. Based on the name and human-population usage. Could be the opposite.
- The direction of `NARCOLEPSY`, `WHITE_IS_LETHAL`, `STIFF_JOINTS`, `LIMP`, `FLU_IMMUNITY` effects. All inferred from the name.

These inferences look reasonable but they could all be wrong. Editing them is gambling until verified.

## Gene/mechanic candidates found in `genes.xml`

Listed for completeness, NOT as a mod plan. Each row's "guess" column is exactly that.

| Gene | Line | Values (g0/g1/g2/g3) | Guess (NOT verified) |
|---|---|---|---|
| `OLD_AGE` | 215 | 0 / 0 / -1 / +2 | Aging modifier |
| `NARCOLEPSY` | 217 | 0 / 0 / 1 / 0 | Spontaneous sleep trait |
| `WHITE_IS_LETHAL` | 190 | 0 / 1 / 0 / 0 | Lethal-white death trigger |
| `LITTER_SIZE` | 214 | 1 / 2 / 3 / 5 | Babies per breeding |
| `FLU_IMMUNITY` | 218 | 0 / 0 / 0 / 1 | Immunity flag |
| `LIMP` | 216 | 0 / 1 / 0 / 2 | Limp severity |
| `STIFF_JOINTS` | 220 | 0 / 18 / 50 / 0 | Movement restriction |
| `RAMPAGE` | 209 | 0 / 0 / 0 / 1 | Rampage behavior |

## What's NOT in any data file (KNOWN by exhaustive grep)

Stamina, fatigue, race cooldown, base lifespan, hunger/thirst rate, sleep duration. None of these are XML-tunable. All are in `Horsey.exe`.

UI sprites confirm the mechanics exist: `StatusOld`, `StatusTired`, `StatusHungry`, `ThoughtTired`, `ThoughtHungry`, `AnimSleep`, `SleepMoon`, `AgeWord`. Sound name `HorsesAge` confirms an aging event.

## Save format (PARTIALLY KNOWN, MOSTLY UNKNOWN)

We did a static-analysis pass on `save1.dat` and walked enough records to confirm:

- Header is 20 bytes (5 uint32s). First field is the save version (12). Other fields' meanings: unknown.
- 0x14..~0xc6f is a horse roster of ~80-85 variable-length records. Each record has: name (length-prefixed UTF-8), 6 flag bytes, two parent IDs (int32, -1 = none), an unknown uint32, child count, and child ID list.
- The roster is small (~3KB of 245KB). The remaining 98% of the file is opaque binary blocks (likely genomes, world state, item positions).

This work is in `SAVE-FORMAT.md` and `parse_save.py`. It's good enough to walk the roster, but identifying which bytes are age, fatigue, race count, or genome would be guessing without the exe's loader code.

The save format will be properly documented after we decompile the loader in Ghidra.

## Plan

### Stage 0: tooling setup

- Install Ghidra (free, NSA-built). Auto-analyze `Horsey.exe`. First pass takes 15-30 min.
- Optional: IDA Free / Binary Ninja Cloud / Cutter as cross-check.
- Set up a Ghidra project that we can re-export to docs reproducibly.

### Stage 1: identify and exclude vendor libraries

Eliminate the noise so we focus only on game-logic functions. Vendor code we exclude:

- SDL3 (huge: thousands of functions across rendering, audio, input, threading, file I/O, window management).
- cute_sound (small, all functions prefixed `cs_` or `cute_sound_`).
- stb_image_write (single header, one function family).
- MSVC CRT runtime (memcpy, malloc, fopen, the C++ exception machinery).
- D3D12/D3D11/DXGI shim wrappers (SDL_GPU emits these).

Method: Ghidra's "Function ID" analyzer with public signature databases (SDL3 release symbols, MSVC version-specific), plus manual review of unmatched functions with vendor-looking patterns.

Deliverable: `VENDOR-FUNCTIONS.md` listing every address range identified as third-party so we never look at it again.

### Stage 2: bootstrap with string-anchored functions

For every "obviously game-logic" string in the binary (we already collected hundreds in `RE-NOTES.md`), find the function that references it. Name and document the function. This gives us a starting graph of ~100-300 named functions.

Anchors prioritized:
- `Horse is too tired!`, `Horse is too old!`, `Horse is too hungry!`
- `%s retired %s (old) ch %d races %d wins %d%s`
- `< Simulation Paused - Year %d  Sleeps %d  Races %d >`
- `%s = (%d rand + %d nice + %d record) * %d years + %d deco` (price formula)
- `Genome copied to clipboard!`, `Pasting genome from clipboard!`
- `Gene %d not in chromoMap`, `GeneEnum.h`
- `save%d.dat`, `genes.dat`, `settings.xml`

Deliverable: `FUNCTIONS.md` with one entry per identified game-logic function.

### Stage 3: reconstruct structs

Walk callers and callees of named functions. Identify struct accesses (`mov rax, [rcx+0x80]` patterns). Build up struct definitions one field at a time. Cross-reference with our save-format work.

Key structs to reconstruct:
- `Horse` (or whatever the game calls it).
- `Gene`, `GeneTable`, `chromoMap`.
- `Population`.
- `World`/`GameState`.
- `Race`, `Champion`, `Ribbon`.

Deliverable: `STRUCTS.md` with C-style struct definitions.

### Stage 4: catalogue constants

Every hardcoded number in the binary that affects gameplay. Fatigue thresholds, base lifespan, hunger depletion rate, race rewards, etc.

Deliverable: `CONSTANTS.md` with one row per tunable constant: address, default value, where it's used, what it affects, how to patch it.

### Stage 5: fill in the rest

Iterate through every remaining unnamed function. Some will be obvious from callers; some will need decompiler reading. Document each.

Done when every function is either vendor-excluded or game-documented.

### Stage 6: mod artifacts

With full understanding in hand, build the mods:
- Save-edit tool (Python): manipulate save fields directly.
- XML mod pack: tuned `genes.xml` / `pop.xml` with KNOWN effects.
- DLL hook: intercept any threshold check we can't reach via save/XML.

## Progress tracker

| Stage | Status | Output |
|---|---|---|
| 0. Tooling | not started | Ghidra installed |
| 1. Vendor exclusion | not started | `VENDOR-FUNCTIONS.md` |
| 2. String-anchored functions | not started | `FUNCTIONS.md` |
| 3. Structs | not started | `STRUCTS.md` |
| 4. Constants | not started | `CONSTANTS.md` |
| 5. Remaining functions | not started | `FUNCTIONS.md` complete |
| 6. Mod artifacts | not started | `mods/` |

Pre-Ghidra work completed: data-file survey (`RESEARCH.md`), exe string dump and anchor categorization (`RE-NOTES.md`), partial save-format walking (`SAVE-FORMAT.md`).

## Current artifacts in this repo

| File | Purpose |
|---|---|
| `FINDINGS.md` | This file. Current state and direction. |
| `RESEARCH.md` | Historical working log of the data-file survey. |
| `RE-NOTES.md` | All exe strings useful as Ghidra anchors. The starting point for Phase 2. |
| `SAVE-FORMAT.md` | Static-analysis pass on `save1.dat`. Identifies the roster format. The rest is TBD. |
| `parse_save.py` | Walks the horse roster. |
| `diff_save.py` | Byte-diff two saves. |
| `save-snapshots/save_A.dat` | Baseline save snapshot. |
| `save-snapshots/save_B.dat` | Post-action save snapshot. |
