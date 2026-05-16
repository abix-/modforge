# Prior art: HorseyLiveTweaks by Nick Petrone (Twisternick)

> **Authoritative on:** the most significant piece of independent Horsey Game reverse-engineering and modding work in the wild. Cross-references their findings against ours, credits theirs, and documents what we learned from comparing.

**Repository:** [NickPetrone/HorseyLiveTweaks](https://github.com/NickPetrone/HorseyLiveTweaks)
**Author:** Nick Petrone (GitHub: NickPetrone, commits as Twisternick `twisternickp@yahoo.com`)
**License:** GPL-3.0
**Discovered (by us):** 2026-05-15
**Local clone:** `horsey-mod/research/prior-art/HorseyLiveTweaks/`

## Table of contents

- [The huge credit](#the-huge-credit)
- [Confirmed agreements (cross-validation)](#confirmed-agreements-cross-validation)
- [What they have that we don't (and should consider)](#what-they-have-that-we-dont-and-should-consider)
- [What we have that they don't](#what-we-have-that-they-dont)
- [Lessons we took from reading their code](#lessons-we-took-from-reading-their-code)
- [Honest assessment](#honest-assessment)
- [Going forward](#going-forward)
- [One-line thank you](#one-line-thank-you)

---

## The huge credit

Nick Petrone independently reverse-engineered the same `Horsey.exe` binary we did and shipped a working, polished modding framework before we did. ~4500 lines of C++, in-game ImGui control window, pattern-scan address resolution that survives game updates, and a working DLL injector that handles UAC elevation. The README says "honestly, this whole thing is like 85% vibecoded" but the work product is substantial regardless.

The overlap with our work is real and deep. **Every offset and call-site address we cross-checked between our `horsey-mod/docs/` and their `src/core/offsets.h` matched.** That's the single most valuable cross-validation we have. Anywhere our model agrees with theirs, both of us are almost certainly right. Anywhere they're more specific or have a name we don't, theirs is the better reference.

If you are reading our docs and want a second opinion on any RE claim, look at the matching file in their `src/core/` and compare. They are an independent witness on the same binary.

## Confirmed agreements (cross-validation)

| Address / offset | Their constant | Their value | Our usage | Confirmed |
|---|---|---|---|---|
| GameState pointer | `kWorldRootPtrRva` | `0x3FB0D8` | `targets::GAMESTATE_PTR` `0x1403fb0d8` | yes |
| GameState scene horse vector begin | `kOffSceneHorseVecBegin` | `0x130` | `gamestate[+0x130]` roster | yes |
| GameState scene horse vector end | `kOffSceneHorseVecEnd` | `0x138` | `gamestate[+0x138]` | yes |
| GameState money | `kRootMoney` | `776 (=0x308)` | `gs_offset::MONEY` | yes |
| GameState active scene id | `kRootActiveSceneId` | `0x25C` | (we had as frame tick; needs reconciling) | partial |
| GameState scene table | `kRootSceneTable` | `0x438` | (we didn't have this) | new info |
| Working genome offset on horse | `kOffVatBase` | `0x2B8` | `horse + 0x2b8` working genome | yes |
| Horse rebuild after gene change | `kRvaHorseRebuildEquipmentAndPhysics` | `0x0B3070` | `FUN_1400b3070` (post-load regen) | yes |
| RNG modulo | `kRvaRngNextModulo` | `0x0C6580` | `FUN_1400c6580` (combinator coinflip) | yes |
| RNG shuffle | `kRvaRngShuffleIntArray` | `0x0C5C80` | (we hadn't named this) | new info |
| Horse copy gene lane pairs | `kRvaHorseCopyGeneLanePairs` | `0x0B35F0` | (we hadn't surveyed this) | new info |

The agreement on `horse + 0x2b8` and `0x498` horse-struct lifetime is the load-bearing one for our 480-gene extension work. We were correct.

## What they have that we don't (and should consider)

### 1. Pattern-scan address resolution

Their `src/core/pattern_targets.cpp` defines IDA-style signature strings for every code site they hook, with multiple fallback patterns per target:

```cpp
constexpr const char* kPatChildBlendCall =
    "E8 ?? ?? ?? ?? C7 83 FC 01 00 00 01 00 00 00 8B 87 8C 02 00 00";
constexpr const char* kPatVatBurstCooldown =
    "C7 87 94 06 00 00 3C 00 00 00 0F 57 C0 0F 11 44 24";
```

They resolve all targets at DLL attach via `pattern_scan_first()` over the loaded image. If the game updates and the function moves, the pattern still finds it as long as the surrounding bytes are stable. This is exactly the R1/R2 work we have queued in [`ADDRESS-RESOLUTION.md`](ADDRESS-RESOLUTION.md). Their implementation is a clean reference design.

Recommendation: when we get to R1/R2, port their pattern format directly and adapt for Rust via `patternsleuth` or a hand-rolled scanner.

### 2. ActiveGeneCount field

Their `kOffActiveGeneCount = 0x690` on a SCENE pointer tracks how many of the 240 vanilla genes are "active" in the current VAT (CRISPR Lab availability map). We did not survey this. For our 240-to-480 extension, when extended genes are armed we may need to ensure this counter stays consistent. Needs investigation.

### 3. Call-site rel32 patching

Their hook mechanism rewrites the rel32 displacement inside a specific CALL instruction so that ONE call site redirects to their stub, leaving every other caller of the same function untouched. See their `src/hooks/child_blend_hook.cpp`:

```cpp
uint8_t* call_site = core::g_rt.targets.child_blend;
uint8_t* original_target = core::call_rel32_target(call_site);
core::g_original_child_blend_addr.store(reinterpret_cast<uint64_t>(original_target), ...);
uint8_t* stub = core::create_absolute_jump_stub_near(call_site, &our_handler);
core::rel32_from_call_to_target(call_site, stub, rel);
core::write_i32(call_site, 1, rel);
```

This is more surgical than our `retour::GenericDetour` approach (which patches the function entry, so every caller is intercepted). For features that should only fire from one path (e.g. "randomize children only when called from breeding, not from CRISPR clone"), call-site patching is the cleaner answer.

We use entry detours because we WANT all callers intercepted (extended genes should flow through every path that creates a child). Both approaches are right for their respective scopes.

### 4. In-game ImGui UI

They run a Dear ImGui control window inside the game's render loop via a DirectX swap-chain hook. Point-and-click sliders for every tweak. Polished UX.

We use HTTP control plane (`modforge::server`) reachable from a browser or CLI. Scriptable, but not in-game.

**Locked direction 2026-05-15:** adopt the in-game ImGui window as our primary UX too, but build it in our shared `modforge` crate (not per-game-mod) so every game-specific mod we ship (horsey-mod, schedule1, grounded2, etc.) gets the same in-game control window for free. horsey-mod is the first consumer and drives the API shape. The HTTP control plane stays as the secondary scripting/automation surface. HorseyLiveTweaks is the reference implementation we're matching at the user-experience level.

### 5. UAC-elevating injector

Their `injector_main.cpp` auto-relaunches as administrator when the target requires elevation. Worth porting to `horsey-inject.exe` so non-technical users don't have to right-click-as-administrator.

## What we have that they don't

This is our actual differentiation. They are a tweak/edit framework for the vanilla 240-gene system. We are an extension framework that adds NEW genes beyond vanilla.

| Feature | HorseyLiveTweaks | horsey-mod |
|---|---|---|
| Edit existing 240 genes in-game | yes (ImGui VAT editor) | yes (HTTP) |
| Randomize children at breed | yes (random lane pick) | no (we do Mendelian) |
| Extend gene table to 480 | **no** | **yes** (D1/D5/D7 shipped) |
| `genes-extended.xml` schema | no | yes |
| Render trampoline on `FUN_14009f680` | no | yes (D5 post-hook) |
| Breeding combinator hook for new genes | no | yes (D3.4 `FUN_1400a2d80` post-hook) |
| Save sidecar `save<N>.dat.ext` | no | yes (D4 BXSAVEXT format) |
| Horse-struct lifecycle anchors | no | yes (D3.1/D3.2 ctor/dtor hooks) |
| Pattern-scan address resolution | **yes** | no (we hardcode addresses) |
| In-game ImGui UI | **yes** | no (we use HTTP) |
| UAC-elevating injector | **yes** | no |
| Terrain / fence / scene editing | yes | no |
| Wild-horse cleanup | yes | no |
| Money / race-bet editing | yes | yes (partial) |

So we are NOT competing. We are complementary. Their mod could ship alongside ours: their tweaks operate on the vanilla 240, our extensions add slots 240..479 and route the engine through them. The CRISPR Lab UI they edit (the VAT availability map at `scene+0x2b8`, 960 bytes) is independent of the working genome we hook (at `horse+0x2b8`, 480 bytes). Different objects, same offset by coincidence.

## Lessons we took from reading their code

1. **Our `horse+0x2b8` interpretation is correct.** Independent witness confirms.
2. **Our `horse` struct size of `0x498` is correct.** Their hooks operate on the same layout.
3. **`FUN_1400b3070` is the canonical "rebuild after gene change" function.** They call it explicitly. We see it called by the save loader. Both agree it regenerates derived state from the working genome.
4. **`FUN_1400b35f0` exists as a higher-level "set a horse's genome from a 480-byte buffer" entry point.** We had not surveyed this. Our D4 save-load currently writes EXT_HORSE_GENOMES directly; if we ever want to mirror the change into vanilla data too, calling `FUN_1400b35f0` followed by `FUN_1400b3070` is the cleanest contract.
5. **Pattern scanning belongs in our future R1/R2 work.** Theirs is a finished reference design we can adapt.

## Honest assessment

If the goal is "play with existing genes in real time," HorseyLiveTweaks is more polished and probably what you want. Use it.

If the goal is "ship a mod that introduces species the base game can't express, with new visual modes that survive save/load," that's what we're building. Their framework can't do it because they don't extend the gene table or trampoline the render pipeline.

The right way to think about this: HorseyLiveTweaks proved the modding surface works. We are building the next layer on top. Their pattern-scan approach is the reference for our R1/R2 address-resolution work; their in-game ImGui window is the reference for the ImGui-in-modforge primitive we're now committing to build. Their VAT editor and tweak panels are features we can defer because they already exist (and credit them).

## Going forward

- **Save the clone.** It lives in `horsey-mod/research/prior-art/HorseyLiveTweaks/` and is git-tracked separately (their commit history). When we need to cross-check an offset or borrow a pattern signature, that is the source of truth.
- **Cite them in `CONTENT-CREATION.md` and `MECHANICS.md`** wherever a confirmed offset originated from a cross-check against their code.
- **Reach out if they're up for collaboration.** Their pattern targets and our extension infrastructure compose cleanly; a combined release would be larger than the sum of parts. Not promising it, but worth a polite ping from the maintainer.
- **GPL-3.0 awareness.** Their code is GPL-3.0. We are MIT-licensed. We will NOT copy their code verbatim into our tree. We can read it, learn from it, cite findings, and re-implement equivalents under our own license. The clone in `research/prior-art/` is a research artifact, not a build dependency, and is not redistributed by us as part of our binaries.

## One-line thank you

To Nick Petrone / Twisternick: thank you. Independent confirmation of the entire `horse + 0x2b8` model is the single most useful sanity check we got on this project, and your published code saved us multiple days of "is this right?" doubt. Hat tip.

---

## Deep cross-reference findings (2026-05-16)

Authoritative second pass over the HLT tree. Reads every file in `src/core/`, `src/hooks/`, and the bottom of `src/features/`, and cross-references each constant against our `horsey-mod/src/targets.rs`. Goal: a complete inventory of (a) RVAs and offsets we should adopt, (b) pattern signatures we should adopt as second candidates, (c) plausibility validators we should add, (d) semantic conflicts that need investigation.

### Full RVA cross-reference

Every function/global RVA published in `src/core/offsets.h`, mapped against ours:

| HLT constant | RVA | Our equivalent (in `targets.rs`) | Status |
|---|---|---|---|
| `kWorldRootPtrRva` | `0x3FB0D8` | `GAMESTATE_PTR` `0x1403fb0d8` | match |
| `kNeighborSceneVtableRva` | `0x3037D0` | none | new (vtable, useful for plausibility check) |
| `kRvaHorseCopyGeneLanePairs` | `0x0B35F0` | none | new (high-level "set genome from 480-byte buffer") |
| `kRvaHorseRebuildEquipmentAndPhysics` | `0x0B3070` | (FUN_1400b3070, hardcoded in patches) | match |
| `kRvaRngShuffleIntArray` | `0x0C5C80` | none | new (Fisher-Yates over int array) |
| `kRvaRngNextModulo` | `0x0C6580` | (FUN_1400c6580 referenced inline) | match |
| `kRvaSpriteNameGetOrCreateFrameId` | `0x06FE60` | none | new (sprite-name to frame-id resolver) |
| `kRvaNeighborRebuildGenepoolTargets` | `0x032610` | none | new (neighbor scene genepool refresh) |
| `kRvaWorldMapEnterScene` | `0x1046C0` | none | new (we have no world-map nav surface) |
| `kRvaWorldMapMarkBorderTilesPlain` | `0x0FFD00` | none | new (terrain editing) |
| `kRvaWorldMapResolveFenceTiles` | `0x0FFB10` | none | new (terrain editing) |
| `kRvaWorldMapDecorateTerrainSprites` | `0x0FFF40` | none | new (terrain editing) |
| `kRvaWorldMapRefreshLocationAndHoleSprites` | `0x0FF790` | none | new (terrain editing) |
| `kWildHorseVtableRva` | `0x310C90` | none | new (vtable, useful for plausibility check) |
| `kRvaMouseScreenX` | `0x3ED970` | none | new (input state) |
| `kRvaMouseScreenY` | `0x3ED978` | none | new (input state) |

The two **vtable RVAs** are the biggest unique find for us. Vtable equality (`*(scene_ptr) == exe_base + vtbl_rva`) is a near-zero-false-positive plausibility check, vastly stronger than range checks on integer fields. We should add a vtable-check primitive to `modforge::patterns::sleuth` and use it wherever HLT does.

### Full GameState offset cross-reference

Every `kRoot*` / `kOff*` on the world-root pointer:

| HLT name | Offset | Our equivalent | Status / note |
|---|---|---|---|
| `kRootActiveSceneId` | `0x25C` | none | new (sits between our FRAME_TICK and FIELD_268) |
| `kRootSceneTable` | `0x438` | none | new (256-entry ptr table at world root + 0x438) |
| `kRootMoney` | `776` (`0x308`) | `MONEY` `0x308` | match |
| `kOffProcessPhase` | `0x250` | none | new |
| `kOffProcessPhaseTimer` | `0x254` | `FRAME_TICK` `0x254` | match (we labeled it "frame tick", they call it phase timer; their name is probably more accurate) |
| `kOffSimHorsesBegin` | `0x260` | `sim_horses_begin()` 0x260 | match (resolved) |
| `kOffSimHorsesEnd` | `0x268` | `sim_horses_end()` 0x268 | match (resolved) |
| `kOffSimStatePhase` | `0x27C` | `TRAILING_27C` `0x27c` | match |
| `kOffSimPhaseTimer` | `640` (`0x280`) | `HORSES_BEGIN` `0x280` | **conflict** (see below) |
| `kOffVatBase` | `0x2B8` | `HORSE_CTX_OFFSET` `0x2b8` (on horse, not GS) | offset coincidence on different objects (already documented in main body) |
| `kOffActiveGeneCount` | `0x690` | none | new (240-VAT availability count) |
| `kOffSceneHorseVecBegin` | `0x130` | `live_horses_begin()` 0x130 | match |
| `kOffSceneHorseVecEnd` | `0x138` | `live_horses_end()` 0x138 | match |
| `kOffWorldMapSelectedTool` | `844` (`0x34C`) | none | new |
| `kOffWorldMapInteractionEntityIndex` | `0x350` | none | new |
| `kOffWorldMapPlacementPhase` | `860` (`0x35C`) | none | new |
| `kOffWorldMapFenceTargetTileX` | `880` (`0x370`) | none | new |
| `kOffWorldMapFenceTargetTileY` | `884` (`0x374`) | none | new |
| `kOffWorldMapFenceOrientation` | `888` (`0x378`) | none | new |
| `kOffRaceBetCurrent` | `704` (`0x2C0`) | none | new |
| `kOffRaceBetMax` | `708` (`0x2C4`) | none | new |
| `kOffRaceBetMinimum` | `712` (`0x2C8`) | none | new |
| `kOffRaceBetMode` | `980` (`0x3D4`) | none | new |
| `kOffWorldMapEntityVecBegin` | `0xB8` | none | new (entity table on a world-map scene, not GS root) |
| `kOffWorldMapEntityVecEnd` | `0xC0` | none | new |
| `kOffWorldMapHoveredEntityIndex` | `0xD0` | none | new |
| `kOffMapTiles` | `0x270` | none | new |
| `kOffMapWidth` | `0x278` | `map_width()` `0x278` | match (resolved) |
| `kOffMapHeight` | `0x27C` | `map_height()` `0x27c` | match (resolved) |
| `kOffGenerationCap` | `1704` (`0x6A8`) | none | new |
| `kOffPopulationCap` | `1708` (`0x6AC`) | none | new |
| `kOffRamInstalled` | `1712` (`0x6B0`) | none | new |

**Conflict 0x280**: HLT labels `0x280 = kOffSimPhaseTimer`. We label it `HORSES_BEGIN` (start of stride-0x24 roster). At the world-root level it cannot be both. Most plausible resolution: HLT and we are looking at the same vector pair in different contexts. Their `kOffSimHorsesBegin/End` at `0x260/0x268` is a *pointer pair* (8 bytes apart, 16 total). Our `HORSES_BEGIN/HORSES_END` at `0x280/0x288` is also an 8-byte pair. Two stride-0x24 horse vectors at different offsets is consistent with the engine maintaining both "sim horses" (per-day simulation list) and "scene horses" (visible roster). HLT's "phase timer" label at 0x280 is likely wrong, or applies to a different root object than we think. Action item: write a test that prints both pair values and confirms our 0x280/0x288 reads back as a valid (begin,end) pair pointing into stride-0x24 horse storage.

### Horse-struct offset cross-reference

| HLT name | Offset | Our equivalent | Status / note |
|---|---|---|---|
| `kOffHorseLifeStageOrAge` | `28` (`0x1C`) | `TYPE_OR_SPECIES` `0x1c` | **semantic conflict** |
| `kOffHorseStaminaTicks` | `508` (`0x1FC`) | `AGE` `0x1fc` | **semantic conflict** |
| `kOffHorseStaminaLimit` | `512` (`0x200`) | `MAX_AGE` `0x200` | **semantic conflict** |
| `kOffHorseHungryFlag` | `517` (`0x205`) | `TIRED_FLAG_A` `0x205` | **semantic conflict** |
| `kOffHorseTiredFlag` | `518` (`0x206`) | `TIRED_FLAG_B` `0x206` | partial match (HLT distinguishes hungry vs tired; we call both "tired") |
| `kVatGeneCount` | `240` | (matches our vanilla 240) | match |
| `kVatGeneLaneCount` | `4` | (matches our 4-lane diploid+ext) | match |

**Three semantic conflicts** on the horse struct are the highest-value finding here. We almost certainly have one or both names wrong on each.

- 0x1c: their "life stage or age" vs our "type or species". `TYPE_OR_SPECIES` is used for compare against 1/2/4/6 in dispatchers. HLT may have mislabeled (1/2/4/6 looks like species codes, not life stages). Worth confirming with a probe that prints `horse[0x1c]` for known horses of different species.
- 0x1fc / 0x200: their "stamina ticks/limit" vs our "age/max_age". This one we should resolve definitively. Probe: read both values on a young vs old horse, and on a fresh vs exhausted horse, and see which moves with which condition.
- 0x205 / 0x206: their "hungry/tired" vs our "tired_a/tired_b". The function we patch at the no-tire loop body writes BOTH bytes; if HLT is right these are two semantically different status flags (hunger and tiredness) and our no-tire patch is also acting as a no-hunger patch by accident. Worth confirming.

### Pattern signatures: second-candidate inventory

DoD #2 requires every resolver to have 2+ candidate signatures. HLT publishes 14 unique signatures. Of those:

**Directly adoptable as second candidates for existing resolvers:**

| HLT signature | Our resolver to extend |
|---|---|
| `kPatWorldRootStore = "48 89 1D ?? ?? ?? ?? 48 89 BB 70 02 00 00"` | `resolve::gamestate_ptr()` (currently has only one candidate that anchors on cheat-money; HLT's anchors on the constructor's store of the new world-root pointer + a follow-up `mov [rbx+0x270], rdi`. Completely different anchor, strong second opinion.) |
| `kPatChildBlendCall = "E8 ?? ?? ?? ?? C7 83 FC 01 00 00 01 00 00 00 8B 87 8C 02 00 00"` | (new resolver: child-blend call site, currently we don't pattern-resolve this) |
| `kPatGeneDriveRandomizeCall = "E8 ?? ?? ?? ?? 48 8B CB E8 ?? ?? ?? ?? 8B 8B F8 01 00 00"` | (new resolver: gene-drive randomize, currently we don't pattern-resolve this) |

**Adoptable as primary signatures for new resolvers** (we don't have the targets yet):

| Signature | Target |
|---|---|
| `kPatInitA/B` | generation/population cap init site |
| `kPatRamA/B` | RAM-installed init site |
| `kPatMainA/B` | sim burst count |
| `kPatWarmA/B` | sim warm-path burst count |
| `kPatCullA/B/C` | cull threshold |
| `kPatSurvivorPercent = "41 6B C8 ?? B8 1F 85 EB 51 F7 E9 44 8B F2"` | survivor percent (note: `41 6B C8 ??` is `imul r9d, r8d, imm8`, the percentage immediate) |
| `kPatSimSmokeEffectCall` | sim-smoke effect call site |
| `kPatVatBurstCooldown = "C7 87 94 06 00 00 3C 00 00 00 0F 57 C0 0F 11 44 24"` | VAT burst cooldown init (`mov [rdi+0x694], 60`) |
| `kPatFenceToolConsumeCall` | fence-tool consume call |

The pattern syntax (`??` for wildcard, hex bytes, IDA-style) is directly compatible with `patternsleuth` / `modforge::patterns::sleuth`. Drop-in port.

### Plausibility validators worth adopting

HLT's `is_probable_world_root`, `is_neighbor_scene_ptr_usable`, and `is_world_map_scene_ptr_usable` (see `src/core/scene_resolver.cpp`) compose multiple cheap structural checks before trusting a pointer:

1. **Vtable equality** against `exe_base + known_vtbl_rva`. Strongest signal. Adopt this for any pointer we resolve where the underlying object has a known vtable (scene, wild horse, possibly horse itself). We do not currently do this anywhere.

2. **Field-value range checks**: active scene id in `[-1, 256)`, map width/height in `[1, 4096]`, tile count `<= 16777216`, first tile terrain id in `[0, 64]`. Cheap, catches "we found the wrong global" mistakes.

3. **Nested pointer non-null + readable**: walk one level deep (`*(*p + table_offset)` must be readable) before declaring success. Catches off-by-one anchor errors.

These should compose into a helper `modforge::patterns::sleuth::is_plausible<T>(ptr, validator)` where validator is a closure. Then every resolver in our `targets::resolve::*` calls it before caching. Currently we have a single ad-hoc 0x1000-byte sanity gate for `gamestate_ptr` (see line 371 of ADDRESS-RESOLUTION.md). Generalize it.

### Call-site rel32 patching primitive

HLT's `call_rel32_target`, `rel32_from_call_to_target`, and `create_absolute_jump_stub_near` (see `src/core/memory_utils.h:20-23`) implement surgical CALL-redirect at a single call site. We use entry detours (`retour::GenericDetour`) which intercept every caller. For features that should fire from one path only (which is half of HLT's hooks), we'd need this primitive. Port to a Rust helper in `modforge` if/when we add a path-selective hook.

### Unique cross-validation evidence

Things that, after this deep read, are more likely correct than they were before:

1. Our `FUN_1400b3070` is canonically named `horse_rebuild_equipment_and_physics`. Confirmed by HLT calling it explicitly after gene-lane writes.
2. Our `FUN_1400a2d80` (gene combinator post-hook) sits next to HLT's `kRvaHorseCopyGeneLanePairs = 0x0B35F0`, which is the "set a horse's genome from a 480-byte buffer" entrypoint. Both deal with gene-lane writes; ours runs AFTER one specific call path, theirs is a generic setter.
3. The `FUN_1400c6580 = kRvaRngNextModulo` function we treat as a coinflip is actually a generic `rng_next() % modulus`. HLT uses it for arbitrary-range RNG too. Our "coinflip" name is too narrow.

### Work items derived from this pass

Numbered for tracking; should be folded into `docs/todo.md` and `docs/ADDRESS-RESOLUTION.md` next time they are updated.

1. **HLT-1: Add `kPatWorldRootStore` as second candidate for `gamestate_ptr`.** Highest leverage; this gets DoD #2 closer for our most load-bearing resolver.
2. **HLT-2: Investigate horse-struct semantic conflicts at 0x1c, 0x1fc, 0x200, 0x205.** Probe-based test in `tests/`, dumps values across known horses, decides which name is right (or whether both are layered on the same byte).
3. **HLT-3: Add vtable-check plausibility primitive** to `modforge::patterns::sleuth`. Resolve `kNeighborSceneVtableRva` and `kWildHorseVtableRva` once and expose them.
4. **HLT-4: Generalize the 0x1000-byte sanity gate** into a per-resolver plausibility hook taking a closure validator. Apply to every R1 resolver.
5. **HLT-5: Reconcile 0x280 conflict.** Either HLT or we are wrong about the meaning of GameState+0x280. Test that prints the value and tries to use it as both interpretations (vector base ptr vs i32 timer) and reports which is plausible.
6. **HLT-6: Adopt the 11 new RVAs as future named targets** when we tackle world-map / fence / wild-horse work. Even if we don't hook them yet, naming them in `targets::function_entry::*` with HLT as the source makes the symbol table richer.
7. **HLT-7: Port `call_rel32_target` + `create_absolute_jump_stub_near`** to Rust in `modforge` for path-selective hooking. Defer until we have a feature that demands it.
8. **HLT-8: Rename our "coinflip" references for `FUN_1400c6580`** to "rng_next_modulo" to match HLT (more accurate; coinflip is a 1-of-2 special case).

End of deep cross-reference. The HLT clone remains the single best independent witness on Horsey.exe internals, and re-reading it produced higher-confidence findings on every offset and at least 3 unambiguous wins (vtable validators, world-root-store second candidate, horse-struct semantic conflicts).
