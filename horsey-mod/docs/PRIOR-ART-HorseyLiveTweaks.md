# Prior art: HorseyLiveTweaks by Nick Petrone (Twisternick)

> **Authoritative on:** the most significant piece of independent Horsey Game reverse-engineering and modding work in the wild. Cross-references their findings against ours, credits theirs, and documents what we learned from comparing.

**Repository:** [NickPetrone/HorseyLiveTweaks](https://github.com/NickPetrone/HorseyLiveTweaks)
**Author:** Nick Petrone (GitHub: NickPetrone, commits as Twisternick `twisternickp@yahoo.com`)
**License:** GPL-3.0
**Discovered (by us):** 2026-05-15
**Local clone:** `horsey-mod/research/prior-art/HorseyLiveTweaks/`

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
