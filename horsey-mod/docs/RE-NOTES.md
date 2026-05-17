# Horsey.exe - Reverse Engineering Notes
> **Authoritative on:** extracted strings from Horsey.exe useful as Ghidra anchors when navigating the decompilation.

Strings extracted 2026-05-13 from `Horsey.exe` (build mtime 2026-05-08). These are anchors to identify the fatigue / age / lifecycle code in Ghidra (or IDA / Cutter).

Stripped native PE x64. SDL3 + cute_sound + stb_image_write. No PDB. Source filenames leaked: at least `GeneEnum.h`.

## Table of contents

- [How to use these anchors](#how-to-use-these-anchors)
- [Tier 1 anchors - directly tied to user's complaints](#tier-1-anchors---directly-tied-to-users-complaints)
- [Tier 2 anchors - debug / format strings (extremely useful)](#tier-2-anchors---debug-format-strings-extremely-useful)
- [Tier 3 anchors - source identifiers](#tier-3-anchors---source-identifiers)
- [Tier 4 anchors - game state / mechanics](#tier-4-anchors---game-state-mechanics)
- [Calling convention and ABI](#calling-convention-and-abi)
- [Vtables (C++ virtual dispatch in disassembly)](#vtables-c-virtual-dispatch-in-disassembly)
- [Hooking strategies (when we get to patching)](#hooking-strategies-when-we-get-to-patching)
- [Per-update fragility](#per-update-fragility)
- [Order of operations for Phase 2](#order-of-operations-for-phase-2)
- [Engine-identification anchor table](#engine-identification-anchor-table)

---

## How to use these anchors

In Ghidra:
1. File -> Import -> `Horsey.exe`. Auto-analyze.
2. Window -> Defined Strings. Filter by the keyword.
3. Right-click the string -> References -> Show References to Address. That gives the function(s) that reference the string.
4. Walk those callers backward to find the comparison / counter.
5. The hardcoded threshold is almost always a numeric immediate in a `cmp` or `mov` instruction near the string load.

## Tier 1 anchors - directly tied to user's complaints

### Stamina / fatigue (one race then tired)

Exact match strings in the binary:

```
Horse is too tired!
That's a tired looking horse!
That horse is looking a bit rusty
Go home and rest your horse first
Why not go home and rest your horse
None of your horses are tired
I'm so tired!
I'm tired
I require rest
I require sleep
I require my beauty rest
Sleepy weepy time
Time for a power nap!
Sleep now
Wakey wakey
I'm awake
```

Strategy: find xrefs to `"Horse is too tired!"`. The function showing this dialog is the eligibility-check branch. The OTHER branch (the success path) increments the race counter. Look one level up for the actual fatigue value being compared.

### Lifespan / aging

```
Horse is too old!
Horse is too young!
That horse is too old to race
That horse is too old.
That horse is too old
But then I got stuck with it when it was too old to race
%s retired %s (old) ch %d races %d wins %d%s
%s retired %s (bails) age %d ch %d
%s retired %s (useless) age %d ch %d
%s%s retired %s
%s is getting old. I can only offer you $%d
Horse is dead!
Why that horse is deceased
They'll be fed and sheltered and taken good care of in retirement
HorsesAge
```

Strategy: the retirement format string `%s retired %s (old) ch %d races %d wins %d%s` is referenced exactly once, from the "retire-due-to-age" branch. Walk backward to find the age comparison.

### Hunger

```
Horse is too hungry!
%s is hungry!
That horse isn't hungry!
I'm so hungry!
I'm hungry
All your horses are hungry!
Your horse is hungry! Feed it first
I'm ready to touch grass
```

## Tier 2 anchors - debug / format strings (extremely useful)

These leak the internal data model. The functions that produce them have all the relevant counters as local variables.

```
< Simulation Paused - Year %d  Sleeps %d  Races %d >
< Simulation Paused - Year %d >
Race %d-%s  champs %d  aborts %d  time %d
%s = (%d rand + %d nice + %d record) * %d years + %d deco   gdist=%.3f
horses: %d   bails: %d   errors: %d
year %d  herb %d  %s %d  max %d  gendiv %d
%s%s foaled %s from %s%s and %s%s
```

The first one is decisive: a function exists that prints YEAR, SLEEPS, and RACES counters in one line. Find its xref, and we have the addresses of all three globals (or struct fields).

The third one (`(%d rand + %d nice + %d record) * %d years + %d deco`) is the **horse price/score formula**. The `* %d years` factor proves age is an integer field; the function reading the format string also reads the horse's age field.

## Tier 3 anchors - source identifiers

These prove there's a strict enum and a chromoMap mapping. Names from `genes.xml` line up with enum values internally.

```
GeneEnum.h
Gene %d exists twice in chromoMap
Gene %d not in chromoMap
8gene
log_races
StartGeneDrive
SwitchToGeneDrive
Engaging GENE DRIVE!
Gene Drive must have a target
CRISPR a gene
```

`log_races` is probably a debug flag. Worth checking - if it's a CLI argument or env var, we might enable extra debug logging that exposes the fatigue counter directly.

## Tier 4 anchors - game state / mechanics

```
Goal 1: get the horse population to %d
Goal 2: get genetic diversity to %d%%
Bring a horse here if you wanna race!
Click Race when ready!
Race!
%s ate some hay today
%s had a nice walk today
%s was a good horse today
%s%s is the latest champion horse!
Mate two horses
Biological mating is pointless and obsolete
Let's mate
BarnMating
```

The "%s was a good horse today" / "%s ate some hay today" pattern suggests a per-day per-horse event log. The day-tick handler is here.

## Calling convention and ABI

- Windows x64 MSVC ABI.
- First four integer args: RCX, RDX, R8, R9.
- First four float args: XMM0-XMM3.
- Stack-based for the rest, with shadow space.
- Pointers are 8 bytes. struct fields are commonly read with `mov rax, [rcx+offset]`.

## Vtables (C++ virtual dispatch in disassembly)

A vtable (virtual table) is how C++ implements polymorphism at runtime. We rely on this heavily for cross-Location code (HK1 transfer, scene-table classification, anything that walks `GS+0x438`).

### The mechanism

When a C++ class has `virtual` methods, the compiler emits ONE vtable per class: a contiguous array of function pointers, one slot per virtual method. Every instance of that class stores the vtable's address as its hidden first field (offset `+0x00`). The vtable itself lives in `.rdata` at a fixed RVA per build.

```
Location vtable @ image_base + 0x30f3d0:    Location instance (any one):
  [+0x00] -> ~Location() (destructor)         [+0x00] -> 0x30f3d0   (vtable ptr)
  [+0x08] -> some_method                      [+0x08] ... fields
  [+0x10] -> ...                              [+0x130] horses begin
  ...                                         [+0x138] horses end
  [+0x60] -> pickup_vfx                       ...
  [+0x68] -> ...
  [+0x70] -> begin_drag
  [+0x78] -> drop_commit  (= FUN_1400de2e0)
```

### What it looks like in disassembly

Calling `loc->drop_commit()` (a virtual call at vtable slot `+0x78`) compiles to:

```
mov rax, [rcx]                ; load vtable pointer (first field of *this)
call qword ptr [rax+0x78]     ; indirect call through slot 0x78
```

That `call qword ptr [rcx+0x78]` shape is exactly the pattern we matched at `FUN_1400d2ab0:1722` to identify the drop-commit slot. **Any time you see `call qword ptr [reg+disp8]` where `disp8 < 0x100`, that's almost certainly a virtual call**, and `disp8` is the vtable slot offset.

In decomp this surfaces as:
```c
cVar4 = (**(code **)(*param_1 + 0x78))(param_1);
//        ^^^^^^^^^^^^^^^^^^^^^^^^^
//        deref *this for vtable ptr, then deref vtable + 0x78 for the function ptr
```

### How we use vtables for RE

1. **Type identification.** Two objects with the same vtable pointer are instances of the same C++ class. The scene-table walk reports `vtable_rva` per slot precisely so we can group objects by class. See [`HORSE-PLACES.md`](HORSE-PLACES.md). E.g. slot 0x00 (Home) and slots 0x08..0x38 (race lanes) both have `vtable_rva = 0x30f3d0`, so they're the same Location class.

2. **One resolver, many destinations.** If two locations share a vtable, the same virtual-method resolver works for both. HK1's drop-commit resolver finds `vtable[+0x78]` once and reuses it for the pasture AND every race lane.

3. **Validation gate.** Reading a candidate pointer's first 8 bytes and comparing to the expected vtable RVA confirms the object's TYPE. HLT's `is_neighbor_scene_ptr_usable` (scene_resolver.cpp:72-81) is the canonical example; we should adopt it (see HLT pattern audit #2 in [`todo.md`](todo.md)).

4. **Pattern anchoring.** Vtable slot numbers are stable WITHIN a build (the C++ class layout doesn't shift mid-build), but can shift BETWEEN builds if MSVC re-orders virtual methods. Resolve vtable slots by anchoring on the CALLING SITE in `.text` (e.g. the `call [rcx+0x78]` inside `FUN_1400d2ab0`), then decoding the `disp8` operand. Do not hardcode slot numbers.

### Practical heuristics

- Different `vtable_rva` => different class => different resolvers needed.
- Same `vtable_rva` across slots => one class, batch-resolve once.
- First qword of any C++ object is suspicious-by-default for being a vtable pointer; if it points into `.rdata` and the bytes there are a run of `.text` addresses, that's a vtable.
- Destructor is conventionally slot `+0x00`. Useful when sanity-checking a candidate vtable.

## Hooking strategies (when we get to patching)

1. **Byte patch**: if the fatigue threshold is an immediate (`cmp [horse+0x80], 1` -> `cmp [horse+0x80], 100`). Smallest diff but breaks on every game update.
2. **NOP the check**: if the comparison is a branch we want to skip, NOP out the conditional jump. Quick and dirty.
3. **DLL hook with MinHook**: most flexible. Hijack via:
   - Proxy `steam_api64.dll` (rename real DLL, drop a proxy that loads it and our code).
   - Or delay-load DLL injection.
   - Inside the hook, replace the threshold read or the comparison outcome.
4. **Code cave + jump**: write fresh logic to a code cave, redirect with `jmp`. Most invasive but pattern-matches well across small updates.

## Per-update fragility

The binary is 4.4 MB and stripped. Every patch will shift function addresses. Two mitigations:

- Use **pattern signatures** (byte patterns with wildcards) instead of absolute offsets.
- Anchor on **string xrefs**, not addresses. A hook that finds `"Horse is too tired!"`, follows the xref, and pattern-matches the comparison instruction nearby survives minor refactors.

## Order of operations for Phase 2

1. Load `Horsey.exe` in Ghidra. Wait for analysis (5-15 min on first load).
2. Find the function referencing `"< Simulation Paused - Year %d  Sleeps %d  Races %d >"`. This single function exposes the YEAR, SLEEPS, RACES globals. Document their addresses.
3. Find the function referencing `"Horse is too tired!"`. Identify the field offset within the horse struct that holds the fatigue counter, and the immediate it's compared against.
4. Find the function referencing `"%s retired %s (old) ch %d races %d wins %d%s"`. Identify the age field and the retirement threshold.
5. Decide: byte patch vs DLL hook. Byte patch is fine for a single-user mod that doesn't need to survive patches.

## Engine-identification anchor table

Binary strings/imports that nail the engine identification. Useful when re-anchoring after a game update.

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

No PDB path or build-machine source path leaked into the binary, so the dev's build is stripped.
