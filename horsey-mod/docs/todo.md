# horsey-mod TODO

> **Major prior art (2026-05-15):** [NickPetrone/HorseyLiveTweaks](https://github.com/NickPetrone/HorseyLiveTweaks) by Nick Petrone (Twisternick) is an independent Horsey Game modding framework with ~4500 lines of C++, in-game ImGui UI, and pattern-scan address resolution. Cross-validates our `horse+0x2b8` working-genome model and our `FUN_1400b3070` regen function. **Different scope** (they tweak the vanilla 240; we extend to 480). Full credit + comparison in [`PRIOR-ART-HorseyLiveTweaks.md`](PRIOR-ART-HorseyLiveTweaks.md). Their pattern-scan approach is the reference we should port for our R1/R2 address-resolution work.


> **Authoritative on:** open work and feature wishlist for the `horsey-mod` crate (native-PE binding for Horsey Game) AND for Horsey-Game content mods shipping alongside it. Workspace-wide framework work lives in [`../../docs/todo.md`](../../docs/todo.md).

Roughly ordered by leverage.

---

## Table of contents

- [Current status (2026-05-15, after commit `352daed`)](#current-status-2026-05-15-after-commit-352daed)
- [P0. `sleep_safe_no_tire` patch site discovery](#p0-sleep_safe_no_tire-patch-site-discovery)
- [P0. Bestiary Expansion: double the species count](#p0-bestiary-expansion-double-the-species-count)
- [P0. Gene Table Doubling: 240 -> 480 implementation plan](#p0-gene-table-doubling-240---480-implementation-plan)
- [Other open work](#other-open-work)
- [Done (recent)](#done-recent)
- [Active blocker](#active-blocker)
- [High-priority features](#high-priority-features)
- [Mod foundations](#mod-foundations)
- [Content-design ideas (for after foundations are in place)](#content-design-ideas-for-after-foundations-are-in-place)
- [Open research questions](#open-research-questions)
- [Long-term: open the platform](#long-term-open-the-platform)
- [Known control-plane issues (carried over from first-injection milestone)](#known-control-plane-issues-carried-over-from-first-injection-milestone)
- [Open next reads (priority order)](#open-next-reads-priority-order)
- [Working principle](#working-principle)
- [User's gameplay goal (the original motivator)](#users-gameplay-goal-the-original-motivator)
- [Address resolution (R1-R5 phased plan)](#address-resolution-r1-r5-phased-plan)
- [External-knowledge verification gaps](#external-knowledge-verification-gaps)
- [Bestiary viability research](#bestiary-viability-research)
- [Content-creation verification gaps](#content-creation-verification-gaps)
- [Gene system open questions](#gene-system-open-questions)
- [Decompilation next steps](#decompilation-next-steps)
- [Save format research](#save-format-research)

---

## Current status (2026-05-15, after commit `5ff0cfc`)

### Test suite

| Category | Count | Status |
|---|---|---|
| Unit (modforge::patterns + sleuth) | 20 | green |
| Unit (horsey: genes / xml / sidecar) | 30 | green |
| Harness (smoke + dryruns + arm + r2 + catalog + build_info) | 14 | 13 green + 1 expected-red (save dryrun = R2 contract for stale save addresses) |
| **Total** | **64** | **63 green + 1 contract-red** |

Live Horsey.exe build hash (this session): `742a6222ba73c99f757bd5576535e623106129fa08bf7aefd3af0da359cb7f71`. Stable across runs; changes when Steam ships an update.

Each harness test does full Steam relaunch + inject + HTTP + assert + taskkill, with timestamped logs at `target/test-runs/<name>-<ts>.log`. Average 7-20s per harness test.

### Commits this session (latest first)

| Hash | What |
|---|---|
| `574beb0` | arm_render_trampoline + arm_full_safe_stack. 4-subsystem stack survives arm/idle/disarm |
| `fe74e6b` | R1 finish: game.build_info HTTP op + r1_build_identification tests |
| `0b5bc96` | todo status r2_catalog green |
| `74846de` | r2_catalog: 4 green targets resolve identically via sleuth |
| `e1af9cf` | todo status sync after R1 + R2 |
| `5ff0cfc` | todo iter 6 R2 + migration proven |
| `f1ad5d5` | r2_migration_combinator: legacy + sleuth converge |
| `54d1c90` | **R2 ships**: modforge::patterns::sleuth wraps patternsleuth crate |
| `c22778e` | R2 plan locked in ADDRESS-RESOLUTION.md |
| `d0cbd27` | **R1 ships**: modforge::patterns + pattern_scan_runtime |
| `291d37e` | 16 new tests: combinator math, BXSAVEXT codec, D1/D5 prologues, arm_combinator |
| `e8f6c89` | dryrun_d3_d4 catches stale save addresses |
| `f0abb2a` | modforge::harness + horsey-mod test infrastructure |

### Open follow-ups (test-first, in priority order)

1. **Signature catalog: hand-author unique signatures.** Catalog `r2_catalog_resolves_all_green_targets` is green for 4 targets using 32-byte derived signatures (read from the runtime image). For production address resolution that survives game updates, replace those with hand-authored signatures that include body bytes + hand-picked wildcards so a single MSVC reorder doesn't break the match. Extending the catalog also needs to cover `EVAL_DIPLOID_BLEND_A/B` + `GENE_ALLELE_SWAP` (their dryrun returns multi-target arrays; the `CatalogEntry` shape needs a `legacy_path_pick` variant).
2. **Retire hardcoded `fn_addr::*` consts.** Switch from `pub const NAME: usize = 0x...` to lazy `pub fn name() -> usize` reading from a resolved catalog. Test asserts every detour arms via the resolved address and behaves identically. Larger refactor.
3. **Re-derive the 4 stale save addresses.** Needs fresh decomp pass OR string-xref tracing (the byte sequences at the original Ghidra RVAs are mid-function code, not entries). Once signatures exist, plug into catalog and `dryrun_d3_d4::save_*` goes green automatically.
4. ~~R1 build identification.~~ DONE (`fe74e6b`). `game.build_info` op shipped; image SHA-256 cached + exposed. r1_build_identification (2 tests) green.
5. ~~Arm-and-observe tests for D5 + lifecycle + full-stack.~~ DONE (`574beb0`). 4 arm tests green: combinator, lifecycle, render trampoline, full-stack. Lifecycle in isolation captured 550 ctor / 3 dtor calls in 5s of menu idle. Full-stack arms 4 subsystems together; game survives.

## Prior status (pre-R1) (2026-05-15, after commit `352daed`)

**480-gene project: infrastructure complete, untested in-game.**

Built, clean, zero warnings:

| Phase | What | Module |
|---|---|---|
| D0 | Sidecar buffers + 12 HTTP ops | `genes.rs` |
| D1 | 3 of 5 detours (eval_a/b, allele_swap) | `patches/ext_genes.rs` |
| D3.1 | Horse-ctor post-hook (`FUN_1400aac60`) | `patches/lifecycle.rs` |
| D3.2 | Horse-dtor pre-hook (`FUN_1400bf1f0`) | `patches/lifecycle.rs` |
| D3.4 | Combinator post-hook (`FUN_1400a2d80`) | `patches/combinator.rs` |
| D4.1-D4.3 | Save sidecar (BXSAVEXT format) | `patches/save_sidecar.rs` |
| D5 | Render trampoline post-hook | `patches/render_trampoline.rs` |
| D7.2 | `genes-extended.xml` parser + live reload | `genes_xml.rs` |

Research closed:
- D3.0 horse-struct allocator: `FUN_1400aac60` ctor, `FUN_1400bf1f0` dtor, 0x498 bytes
- D3.4 combinator: `FUN_1400a2d80(pA + 0x2b8, pB + 0x2b8, child + 0x2b8)`, Mendelian + 3 linked-inheritance cluster ranges
- D4.4 horse_id: no dedicated field; roster slot position is the id
- Save pipeline: `FUN_14006ee10` writer + `FUN_14006f150` loader, both via `gamestate[+0x130]` iteration order

Cross-validated against [HorseyLiveTweaks](PRIOR-ART-HorseyLiveTweaks.md). Every offset matches; their independent RE confirms ours.

Testing infrastructure + test-first rule + live test inventory: see [`TESTING.md`](TESTING.md).

### Scope and non-conflict with HorseyLiveTweaks

User-locked 2026-05-15: **horsey-mod is a CONTENT + QoL mod. We do NOT overlap with HorseyLiveTweaks.**

**In scope (ours):**
- **Content:** new genes beyond vanilla's 240 (the 480-gene extension), new species (`genes-extended.xml` bestiary), new visual modes via D5 render trampoline, sidecar persistence of all new state.
- **QoL:** smart hotkeys that reduce repetitive clicking (HK1 Shift+Click smart-transfer is the v1 example), bulk operations, anything that makes 50+ horse households tolerable. QoL means "make the existing game less tedious," NOT "tweak existing gameplay numbers."

**Out of scope (theirs):**
- Anything HorseyLiveTweaks already ships. Terrain replacement, fence-tool overrides, wild-horse cleanup, neighbor-sim tuning, money/race-bet editing, scene helpers, VAT CRISPR editor for the vanilla 240. Use their mod for those.
- Anything that "tweaks vanilla state" without adding content or removing tedium. If it's "edit a vanilla knob," it belongs in HorseyLiveTweaks.

**Co-existence rules:**
- Test that horsey-mod + HorseyLiveTweaks installed simultaneously work. Both should arm cleanly.
- Where both mods could hook the same function (combinator `FUN_1400a2d80`, regen `FUN_1400b3070`), we use post-hook trampolines that ONLY touch the ext range; vanilla data stays HorseyLiveTweaks' domain.
- Prefer entry-detour patches (broad, all callers, ext-only data). AVOID call-site rel32 patching (their preferred mechanism) so we don't clobber a site they hook.

**Default answer to overlap requests:** "Use HorseyLiveTweaks for that. We add X on top." Bundle, don't duplicate.

### Known limitations / risks

- Untested against the live binary. -16 prologue adjustment is convention but not verified for the 5 new addresses.
- `LOAD_GAME = 0x14006e480` was already in `targets.rs` but the entry-point hasn't been prologue-verified.
- Save-loader detour writes ext alleles BEFORE the vanilla loader runs. If vanilla zeros `EXT_HORSE_GENOMES` keys (horse pointers) by re-allocating horses during load, the entries get orphaned. Lifecycle anchors should drop them on dtor, but order-of-operations needs in-game confirmation.
- `+0x690` ActiveGeneCount (HorseyLiveTweaks finding) might need updating for ext range. Unclear; not in v1.

---

## P0. `sleep_safe_no_tire` patch site discovery

Wip in [`a31246f`](.). Patch infrastructure works
(VirtualProtect / write / FlushInstructionCache + revert on
detach), but `find_patch_site` cannot uniquely identify the
`+0x206` zero-store inside the no_tire loop at
`FUN_1400ceb60`.

Three iterations tried; all ambiguous on the user's build:
- v1: RAX-only -> 0 matches
- v2: all regs -> 2 candidates, can't pick
- v3: proximity ("`+0x206` store with `+0x205` sibling
  within 64 bytes") -> still failing

Next idea (verified against decomp at
[`horsey-mod/research/decompiled/funcs/1400c/1400ceb60_FUN_1400ceb60.c:612`](../../horsey-mod/research/decompiled/funcs/1400c/1400ceb60_FUN_1400ceb60.c)):
anchor on the `DAT_1403d95c5` RIP-relative read at line 612,
then take the first `mov byte ptr [reg+0x206], 0` after it.
Only one other `+0x206` store exists in the function (at
:382) and it has no nearby `DAT_1403d95c5` read, so this
should disambiguate.

If the RIP-relative scan is too much work, fall back to a
hand-disassembled per-build offset baked into a constant.

Until this lands, the split-flag suppressor (50ms Rust
worker zeroing only `+0x205`) is the shipping path.

---

## P0. Bestiary Expansion: double the species count

**Goal:** double spawnable pops from 28 -> 56 with creatures
that are both visually AND genetically distinct. Adding
new gene types is in scope from day one; the vanilla 242
genes are not enough to express the species we want.

**Modding posture (user direction 2026-05-14):** the base
game is a substrate, like a C# class or Rust trait. We
override anything we need to override. Pop.xml, genes.xml,
horsey.tmx, gene-table allocation, gene-by-index consumers,
save format. Binary patching is a normal tool, not a last
resort.

**Plan posture:** research first, decisions second, build
third. We do NOT lock the species list, the new-gene list,
or the build order until viability research clears the
core technical questions.

Vanilla baseline (verified in
[`horsey-mod/docs/CONTENT-CREATION.md:515`](CONTENT-CREATION.md#12-reference-vanilla-populations)):
28 pops, of which roughly half are real horse-shaped
creatures and the rest are oddities (cars, plants, humans,
microbes, helix, freaks).

---

### Phase 0: Viability research. CLOSED 2026-05-14

All blocking questions answered with file:line cites in [`VIABILITY.md`](VIABILITY.md). 5 gene-system questions, 4 pop questions, 3 save questions, 3 renderer questions, 2 reload questions. Two stay open but DEFERRED (`Q-render-1` per-pop oddity decomposition; `Q-reload-1` reentrant chromomap loader); neither blocks downstream work.

See VIABILITY.md for the full Q&A.

---

### Phase 1: Decisions (post-research)

Phase 1 starts ONLY after Phase 0 is complete. Inputs:
the answered viability questions. Outputs: a locked plan
that drives Phase 2 build work.

- [ ] Lock the species list (count + names + flavor mix).
      The 9 normal / 10 weird / 9 other split below is a
      candidate, not a commitment.
- [ ] Lock the new-gene list. For each new gene: name,
      what it controls, which patch sites enable it.
- [ ] Lock the build order. Likely "patches first, then
      content," but the answers from Q-render-3 and
      Q-save-2 might invert that.
- [ ] Lock the save-compat policy.
- [ ] Lock the iteration loop (manual restart vs.
      Gene Editor live reload).

---

### Phase 2: Build (post-decisions)

Concrete sub-phases TBD by Phase 1 decisions. The bullets
below are candidates carried over from earlier drafts;
none of them are committed yet.

#### Phase 2A (candidate): smoke-test the content pipeline

Pick the simplest possible new pop (e.g. `spaceparrot` from
the existing example). Goal: confirm end-to-end that an
edit to `pop.xml` + a spawner in `horsey.tmx` produces a
visible new creature in-game without crashing the loader.

- [x] **DONE.** Game install path locked at
      `C:\Games\Steam\steamapps\common\Horsey Game`.
      See "Locked decisions (2026-05-14)" below.
- [ ] Back up vanilla `pop.xml`, `horsey.tmx`, and
      `genes.dat` (the cache).
- [ ] Add one `<pop name="smoketest">` block under
      `<pop name="default">` with extreme gene weights so
      it's visually unmistakable.
- [ ] Place one spawner in `horsey.tmx` near the start area
      with `class="smoketest"`, `count=3`, `radius=4`.
- [ ] Delete `genes.dat` to force regen.
- [ ] Launch, confirm spawn, screenshot.
- [ ] If it fails: read `FUN_1400a3eb0` neighbors for the
      pop loader and figure out what's hardcoded.

#### Phase 2B (candidate): species list and gene tweaks

User direction 2026-05-14: balanced split across vanilla's
three flavor buckets (normal / weird / other), every new
pop must be **both visually AND genetically distinct**
(max effort), and **new gene types are in scope**. If
a species needs a gene vanilla doesn't have, we add it.

Candidate target: 9 normal + 10 weird + 9 other = 28. The
exact list is locked in Phase 1 after viability research.

#### Normal (9): real horse breeds + believable animals

Each rides existing genes (`SIZE`, `BONES`, `LEG_LENGTH`,
color channels, tail shape) into a recognizable real-world
silhouette. These should not look weird.

- [ ] `bx_arabian`. Small head, dished face, high tail
- [ ] `bx_draft`. Huge `SIZE`, thick `BONES`, short legs
- [ ] `bx_mini`. Tiny `SIZE`, short everything
- [ ] `bx_wolf`. Canine proportions, long body
- [ ] `bx_sheep`. Compact, fluffy palette
- [ ] `bx_goat`. Short, horned, agile build
- [ ] `bx_kangaroo`. Big hind legs, tiny front, long tail
- [ ] `bx_ostrich`. Biped, long legs, no front
- [ ] `bx_elephant`. Max `SIZE`, max `BONES`, gray

#### Weird (10): "X is now a horse"

Same energy as vanilla `pepper` / `yeast` / `helix` /
`appletree`. Push gene weights to extremes; abuse
`OSTODERM`, `SPLAY`, `GUT`, `SKINNY`, color channels.

- [ ] `bx_mushroom`. Short body, huge cap-shaped head
- [ ] `bx_kelp`. Tall, skinny, swaying, green
- [ ] `bx_slime`. Max `SKINNY` off, high `GUT`, jiggly
- [ ] `bx_worm`. No legs (QUADRUPED off), elongated body
- [ ] `bx_skeleton`. Min `GUT`, max `BONES`, pale palette
- [ ] `bx_ghost`. Semi-transparent palette, no legs
- [ ] `bx_virus`. Tiny, spiky `OSTODERM`, vivid color
- [ ] `bx_mold`. Low body, fuzzy palette, blotchy
- [ ] `bx_crystal`. Angular `OSTODERM` extremes, shiny
- [ ] `bx_balloon`. Huge `GUT`, tiny legs, bright color

#### Other (9): mythical / vehicular / humanoid

Sits between "normal" and "weird," matches vanilla
`centaur test` / `car` / `human` / `jockey` / `leprechaun`
/ `freak`.

- [ ] `bx_unicorn`. Horse base + single-spike `OSTODERM`
- [ ] `bx_pegasus`. Horse base + wing-shaped extras
- [ ] `bx_kelpie`. Dark horse + aquatic palette
- [ ] `bx_motorcycle`. Vehicle pop variant of `car`
- [ ] `bx_tractor`. Bigger / boxier vehicle pop
- [ ] `bx_shopping_cart`. Small wheeled-thing pop
- [ ] `bx_robot`. Humanoid but rigid, metallic palette
- [ ] `bx_clown`. Humanoid variant under `human`
- [ ] `bx_pirate`. Humanoid variant under `human`

#### Per-pop deliverable

Before authoring XML, each entry above must have:

- 1-line description of the silhouette goal
- The 3-7 gene tweaks (`gene name`, `p0..p3`, `m`, `s`)
  that achieve it
- Parent pop choice (under `default`, `human`, `car`, etc.)

Park the full table in this file before moving to Phase
1C. The table replaces the bullet stubs above.

#### Phase 2C (candidate): patches for new gene types and table extension

- [ ] Implement the chosen table-extension strategy from
      Q-gene-4 in `horsey-mod/src/patches.rs`. The patch
      infra (revert-on-detach) already works.
- [ ] For each gene-by-INDEX consumer flagged in Q-gene-3,
      patch it to go through a name lookup OR re-bake its
      index for the new layout.
- [ ] If save format needs patching per Q-save-2, do it.
- [ ] For each new visual mode flagged in Q-render-1 that
      has no vanilla equivalent, patch the renderer
      handler to recognize the new gene.
- [ ] Add `genes.add {name, m, s, p0..p3, ...}` HTTP op
      to stage new gene definitions live for testing.

#### Phase 2D (candidate): pop.xml + genes.xml authoring

- [ ] Author all new gene definitions in `genes.xml` (or
      a sidecar `genes-extended.xml` if Q-render-3 makes
      that cleaner).
- [ ] Author one pop block per species in `pop.xml`,
      nested under the right parent (`default`, `human`,
      `car`, etc.).
- [ ] Convention: prefix our pops with `bx_` and our new
      gene names with `BX_` so they sort together and
      don't collide with future vanilla additions.

#### Phase 2E (candidate): spawner placement

- [ ] Place spawners in `horsey.tmx` for each new species.
      Decide per species: dense in one biome, or scattered.
- [ ] Avoid stomping on the demo / tutorial spawn area
      for the first build to keep verification clean.
- [ ] Reuse vanilla animal tiles (7 available) plus the
      two unused (bunny, dinosaur) where they fit
      visually.

#### Phase 2F (candidate): Gene Editor HTTP ops

Build live-tweak ops in `horsey-mod` so species design is
interactive. May happen earlier (before Phase 2D
authoring) if Q-reload-2 says it's cheap and high-value.

- [ ] `pops.list` -> all currently loaded pops.
- [ ] `pop.read {name}` -> all gene weights for that pop.
- [ ] `pop.gene.set {pop, gene, p0..p3, m, s}` -> mutate
      live (if Q-reload-1 confirms the chromomap is
      mutable post-load).
- [ ] `pop.xml.reload` -> re-parse `pop.xml` from disk
      without restarting the game.
- [ ] `genes.xml.reload` -> same for genes.xml.
- [ ] `spawner.preview {pop, x, y, count}` -> spawn N
      creatures of that pop at a coord.

#### Phase 2G (candidate): ship as a data + patch overlay

- [ ] Ship as a folder the user drops into `Horsey/data/`
      plus the existing `horsey-mod` DLL for the binary
      patches. One-line uninstall (restore backups +
      delete `genes.dat` + don't inject the DLL).
- [ ] Optional: PowerShell installer / uninstaller.
- [ ] Document save-compat policy from Q-save-3.

#### Phase 2H (candidate): in-game verification

- [ ] Walk the map, screenshot every new species.
- [ ] Confirm none of them break breeding, racing, or
      save load.
- [ ] If a species crashes the renderer, narrow which
      gene pushed it over the edge and document the safe
      range.

---

## P0. Gene Table Doubling: 240 -> 480 implementation plan

### D0 / architecture / locked-decisions: SHIPPED 2026-05-14

Sidecar buffers, the architecture diagram, locked design decisions (install path, layered design, authoring format, save compat, phase order), HTTP control-plane ops, and the `genes-extended.xml` authoring workflow are all documented in [`GENE-CATALOG.md`](GENE-CATALOG.md) "Part 3: Extended (480-gene) layer".

D0.5 (heap-redirect helper) was deferred during D1 and remains OPEN; not blocking.

### Phase D1 + D3 + D5 (detours): SHIPPED 2026-05-15

Strategy + implementation status documented in [`HOOKING-STRATEGY.md`](HOOKING-STRATEGY.md) §8 "Implementation status." Includes per-target RVAs, dispatch logic, deferred items (D1.3 mid-function death-drift mutator + D1.8 CRISPR UI), and the in-game verification numbers.

In summary:
- **D1 (ext_genes):** 3 of 5 detours shipped (`EVAL_DIPLOID_BLEND_A`/`B`, `GENE_ALLELE_SWAP`). 2 deferred (death drift, CRISPR UI). Loop-bound patches `D1.5/6/7` not needed (sidecar loaders cover the ext range).
- **D3.1/D3.2 (lifecycle):** shipped; `tests/arm_lifecycle` captured 550 ctor + 3 dtor calls in 5s of menu idle.
- **D3.4 (combinator):** shipped; 6 unit tests in `genes::tests` lock the Mendelian algorithm. Vanilla combinator + linked-inheritance details in [`GENE-CATALOG.md`](GENE-CATALOG.md) Part 1 Step 1.
- **D5 (render trampoline):** shipped; in-game proof via slot 0 visual effect 2026-05-14.

### Phase D2 (per-pop weight extension): OPEN

Pop records currently hold 240 genes x 4 alleles = 3840 bytes of weights at offset `+0x28`. Extending to N genes means each pop needs more weight space. Strategy: leave vanilla pop record layout alone; store extended weights in `EXT_POP_WEIGHTS[pop_id]`.

- [ ] **D2.1.** Detour `FUN_1400a5ee0` (pop processor). When it writes to a pop record, also create an `EXT_POP_WEIGHTS[pop_id]` entry inheriting from the parent pop's extended weights (inherit-then-override mirrored).
- [ ] **D2.2.** When parsing `pop-extended.xml`, look up the named pop's `pop_id` and apply per-gene weight overrides into `EXT_POP_WEIGHTS[pop_id]`.
- [ ] **D2.3.** When the spawn function picks alleles for a new horse, also pick alleles for genes 240..479 using the pop's extended weights. Write the picks to `EXT_HORSE_GENOMES[horse_ptr]`.
- [ ] **D2.4.** Sync `FUN_1400c03a0` swaps across `EXT_POP_WEIGHTS` entries.

### Phase D4 (save sidecar): code SHIPPED, addresses STALE

Implementation lives in `horsey-mod/src/patches/save_sidecar.rs`. Pipeline, BXSAVEXT binary format, horse-id field investigation, and detour table all documented in [`SAVE-FORMAT.md`](SAVE-FORMAT.md) "Save pipeline functions" + "Horse-id field" + "Sidecar format `save<N>.dat.ext`".

The 4 detour target RVAs are mid-function in the current shipping build; `genes.ext.save.arm` is UNSAFE to arm until re-derived via pattern-scan. Tracked under R2 in [`ADDRESS-RESOLUTION.md`](ADDRESS-RESOLUTION.md). The failing harness test `dryrun_d3_d4::save_dryrun_prologues_ok` is the locking contract.

### Phase D6: Save-compat strategy for the population
mutation drift

`FUN_1400c0660` mutates gene-table mutation rates by
±5 on horse death. For extended genes, our detour at
D1.3 already directs those writes to `EXT_GENE_TABLE`.
But: vanilla's mutation drift on genes 0..239 only
gets persisted if we can find where it's saved.

- [ ] **D6.1.** Find the function that serializes the
      gene-table mutation rates back to disk. The
      `FUN_1400a4880` XML round-tripper is the obvious
      candidate. Confirm by tracing its call site (does
      it run during save, or only on a manual "export
      genes.xml" debug command?).
- [ ] **D6.2.** If vanilla DOES persist the drift to
      genes.xml on save, our extended drift goes to
      `genes-extended.xml` via mirror logic. If vanilla
      does NOT persist the drift, we have nothing to
      mirror.
- [ ] **D6.3.** Document the drift-persistence behavior
      in [`GENE-CATALOG.md` (Part 1: Conceptual model)](GENE-CATALOG.md) once
      confirmed.

### Phase D7: Iteration and testing infrastructure

Without a fast feedback loop, debugging the patches is
painful.

- [ ] **D7.1.** Implement the `genes.xml.reload` and
      `pop.xml.reload` HTTP ops (Q-reload-1 still open;
      may not be feasible if vanilla doesn't expose a
      reentrant loader).
- [x] **D7.2.** DONE. `genes-extended.xml` parser in
      `horsey-mod/src/genes_xml.rs`. Auto-loaded on
      DLL attach (worker_main reads
      `<DLL_DIR>/genes-extended.xml` if present). Live
      reload via `genes.ext.reload {path?}` op. 5/5
      parser tests pass. Format documented in the
      module docstring. Conflict detection skips slots
      already populated with a different name.
- [x] **D7.3.** DONE. `genes.ext.dump` op shipped in
      D0.6 returns full extended-gene snapshot. Vanilla
      side dump deferred (would require reading
      `DAT_1403ee4a4` via process memory; nice-to-have
      not blocker).
- [ ] **D7.4.** Deferred. Per-horse full dump op needs
      a stable horse_id (open in D4.4) before it's
      meaningful.

### Phase D8: Verification

Run the full pipeline end to end on a real save before
declaring victory.

- [ ] **D8.1.** Boot the game with horsey-mod attached
      and no extended genes defined. Confirm vanilla
      behavior is unchanged (regression check).
- [ ] **D8.2.** Add ONE extended gene (e.g.
      `BX_WING_SIZE` mapping to an unused param_1
      slot). Spawn a horse of a pop that uses it.
      Confirm the slot value matches the diploid
      blend math.
- [ ] **D8.3.** Save and reload. Confirm the extended
      gene's allele picks survive the save round trip.
- [ ] **D8.4.** Breed two horses with different
      extended-gene alleles. Confirm the child's
      alleles follow the expected combinator behavior.
- [ ] **D8.5.** Add 100 extended genes at once. Stress-
      test the save format size and the trampoline's
      per-frame cost. Profile.
- [ ] **D8.6.** Hot-reload extended genes via HTTP
      while the game is running. Confirm visual
      changes apply without restart.

### Phase D9: Documentation and rollout

- [ ] **D9.1.** Update `GENE-CATALOG.md` (Part 1: Conceptual model) to document
      the extended layout: how `EXT_*` buffers are
      laid out, where they're stored, how gene
      indices map to vanilla vs extended.
- [ ] **D9.2.** Write a "How to author a new gene"
      guide aimed at non-engineers: the
      `genes-extended.xml` format, the `extends="..."`
      mapping, the `mode="..."` options, working
      examples.
- [ ] **D9.3.** Decide rollout: ship the patch infra
      with zero extended genes by default, and let
      authors add them via XML. Or ship a starter
      pack of 20-50 useful new genes.
- [ ] **D9.4.** Document the sidecar file format
      (`save<N>.dat.ext`) in case anyone wants to
      write external tools.

### Risks and unknowns

| Risk | Mitigation |
|---|---|
| ~~Breeding combinator unfound~~ RESOLVED 2026-05-15: `FUN_1400a2d80`. See D3.4. |
| `FUN_1400a5d20`'s detour may be hot enough that the per-call branch costs measurable frame time. | Profile in D8.5. If it's a problem, JIT-patch the detour to skip vanilla frames where no extended genes are defined. |
| ~~Stable horse_id field not located~~ PARTIAL 2026-05-15: no dedicated field; roster slot position IS the id. Sidecar uses positional ordering (iteration order matches save order). See D4.4. |
| ~~horse-struct allocator unfound~~ RESOLVED 2026-05-15. Horse struct is 0x498 bytes. Constructor `FUN_1400aac60`, destructor `FUN_1400bf1f0`. 40+ call sites alloc via `FUN_1402c704c(0x498)` and ALL route through the single constructor. See D3.0. |
| **NEW: working genome misidentified as `+0x78`.** Real working genome is inline at `horse + 0x2b8` (engine + consumer + save all use it). `+0x78` is pop-seed / archive only. Original D3.1-D3.3 plan was wrong; revised plan in D3 section. | Done: docs updated. |
| Vanilla's `genes.dat` cache format may include the gene table in a way that doesn't survive our patches. | Recommend deleting `genes.dat` on attach to force regen. Document. |
| `FUN_14009f680` runs on a non-render thread (audio? AI?) and our trampoline triggers thread-safety issues. | Audit the calling thread context for each of the 4 caller sites in D5.1. |

---

## Other open work

### Hot-reload crash hardening

`horsey-inject.exe --reload` swap reports success but the
game crashes a few seconds later. See
[`horsey-mod/docs/ROADMAP.md`](ROADMAP.md) for the
research-side investigation.

### Save sidecar

Persist `horsey-mod` state across game restarts. Pre-req for
the RPG layer.

### Roster UI / hotkeys / RPG layer

Tracked at the framework level for now; will graduate to
this todo once the bestiary mod is shipping.

---

## Done (recent)

- 2026-05-13: native-PE binding ([`e9d3345`](.))
- 2026-05-13: hot reload via staged DLLs ([`91f79f5`](.))
- 2026-05-14: `no_tire` enabled by default ([`c37fa54`](.))
- 2026-05-14: split-flag fatigue suppressor
  ([`608f994`](.))
- 2026-05-14: binary-patch infra (revert-on-detach)
  ([`a31246f`](.))

---

# Appendix: Feature wishlist (merged from ROADMAP.md, 2026-05-15)

Originally a separate feature-wishlist doc; merged here to keep todo.md authoritative on all open work and feature ideas. The status-table content at the top of the original duplicated this doc; only the feature/idea sections are kept below.

## Active blocker

### Hot-reload crash

`horsey-inject.exe --reload` performs the swap and reports success, but
the game crashes a few seconds later. The post-reload state is briefly
visible (verified: `no_tire: true` was readable after the swap before crash).

Most likely cause: helper threads inside the old DLL haven't fully unwound
their stack when `FreeLibrary` is called. The `_shutdown` op spawns a
`horsey-shutdown` thread that lives inside the old DLL; if that thread
hasn't exited, the FreeLibrary returns "successfully" but the next time
that thread tries to return into freed code: crash.

Fix candidates:
1. Make `_shutdown` synchronous: stop the server in the request handler,
   wait until `shutdown_all()` has truly returned (all listeners joined),
   then return the HTTP response.
2. Injector polls port 33077 after `_shutdown` until it's closed, then
   waits another 500ms for in-flight helper threads, then `FreeLibrary`.
3. From the last remaining thread, call `FreeLibraryAndExitThread`.

Recommended: try (1) first (simplest, no injector change). If that's
insufficient, add (2). Use (3) only if both fail.

Workaround until fixed: relaunch Horsey + re-inject fresh on each rebuild.

---

## High-priority features

### Hotkeys

User-locked scope 2026-05-15: **`Shift+Click` (on horse) = transfer to current location.** That's the first and only hotkey in v1. Everything else stays out of scope until that one ships and gets real use.

- [ ] **HK1. Shift+Click smart-transfer.** Vanilla forces a click-and-drag every time you move a horse between the three locations:
      - **Vehicle** (truck the player drives around)
      - **Pasture** (home / corral)
      - **Race line** (starting position at the track, "ready to race")
      And these transfers happen constantly: load truck before going to a race, unload at the track to put horses on the line, reload to truck after the race, unload back to pasture at home, repeat. Every transfer is a manual click-drag of one horse at a time.

      HK1 collapses each transfer to a single Shift+Click on the horse. The mod **infers the right destination from context**:
      - At the track? Vehicle horse -> race line. Race-line horse -> vehicle.
      - At the pasture? Vehicle horse -> pasture. Pasture horse -> vehicle.
      - Anywhere else? Pasture <-> vehicle, since pasture is the implicit "home" target.

      Effect: every routine "load up for race day" / "put horses on starting line" / "bring everyone home" loop becomes Shift+Click per horse instead of click-drag per horse. Future bulk variants (Shift+Click on a group, hotkey to transfer ALL eligible) are out of v1.

#### Groundwork that ships alongside HK1

Build the foundation so future hotkeys are cheap to add. Don't add any hotkeys beyond HK1 in v1.

- [ ] SDL input hook. Intercept mouse/keyboard events before the engine handles them. Single dispatch point inside `horsey-mod`.
- [ ] Modifier-key state tracker. Reusable for any future modifier-click binding.
- [ ] "Currently hovered/selected horse" resolver. Given mouse position + game state, return the horse pointer under the cursor. Reusable for any horse-targeted hotkey.
- [ ] "Where is this horse now?" + "Where should it go from here?" resolvers. Read the horse's current container (vehicle / pasture / race line) and the player's current scene to pick the destination.
- [ ] "Move horse to <destination>" op. Wraps whatever vanilla function the click-drag flow calls when the player releases a dragged horse on a valid drop target. Find it via the existing transfer-menu code; reuse rather than re-implement so the move keeps all side effects vanilla expects (fatigue clearing on race-line drop, etc.).
- [ ] Settings entry for enabling/disabling HK1 (so users can opt out).

#### Deferred (NOT in v1)

Originally listed but never asked for; revisit only if HK1 ships and the user explicitly asks for more. Kept as a parking-lot list so we don't lose the ideas:

- `Ctrl+Click` favorite toggle, `Alt+Click` stats panel
- `Shift+Click` (item) bulk-buy, `Shift+Click` (roster) quick-feed
- Keyboard hotkeys: `R` race, `F` feed all, `S` sleep all, `B` breed, `T` transfer menu
- `Esc+1..9` save-slot switch, `Numpad +` / `Numpad -` sim speed

---

### Horse-crowd management (CRITICAL for 50+ horse households)

When many horses are at the same location (e.g. all your horses parked at
home), they stack on top of each other. Vanilla problems:

- Horses overlap pixel-for-pixel; you can't see how many are there.
- Clicking one horse is a lottery (you get whichever is rendered last).
- No way to tell at a glance which horses are hungry / tired / sick.
- Breeding setup is painful: you can't easily pick two specific parents.
- Counting "how many horses do I own?" requires moving the camera to find
  every stack.

#### Sub-features

**1. Auto-spread overlapping horses**

When N >= 2 horses share a tile, render them in a small fan/circle around
the actual position so each is individually clickable. Hover one horse to
"lift" it forward for emphasis.

Implementation: hook the per-horse render call. Detect overlap by
quantizing positions to half-tile buckets. For each bucket with >1
horse, offset each horse's render position by a deterministic angle
(`horse_id % N * 360/N`) and a small radius. The actual game-state
position stays unchanged; only the render position is offset.

**2. Roster panel overlay**

A side-panel UI showing ALL horses with one row each, columns sortable:

| Name | Loc | Age | Hunger | Tired | Breed-Ready | Skill | Status |

Click a row to focus camera + select that horse. Filter chips at top:
"Hungry only", "Tired only", "Old", "At home", "On track", etc.

Backend: the data already lives in our `horses.count`/`horse.read` ops.
Front-end:
- **ImGui overlay in MODFORGE** (locked 2026-05-15). Same approach
  HorseyLiveTweaks ships (see
  [`PRIOR-ART-HorseyLiveTweaks.md`](PRIOR-ART-HorseyLiveTweaks.md))
  and the same one we use in other game-mod projects. Build it
  ONCE in `modforge` as a reusable in-game-window primitive so
  every per-game mod (horsey-mod, schedule1, grounded2, etc.)
  gets it for free. horsey-mod is the first consumer.
- Web UI served from `modforge::server` stays as the secondary /
  scripting surface (browser tab + curl), not the primary UX.

**3. Status badges on stacked horses**

Above each horse, render small icons matching what the engine already
draws (`StatusHungry`, `StatusTired`, `StatusOld`) but ENLARGED and
ALWAYS-VISIBLE (not just on hover). Color-coded:

- Red dot = needs food urgently
- Yellow dot = tired
- Blue dot = ready to breed
- Skull = imminent death from old age

Hook the existing `render_horse_thought_bubble` family (we annotated
those at `0x1400bd820` etc.) and always-draw the badges instead of
gating on hover state.

**4. Hotkey horse cycling**

When multiple horses are stacked, pressing `Tab` cycles selection
through them. Useful when auto-spread is off or when zoomed out.

**5. Count display**

Floating "N" badge above a stack of overlapping horses, showing the
count. Disappears when you mouse-over (so it doesn't block the spread
view).

**6. Breeding picker**

A dedicated overlay: pick parent A from the roster, pick parent B,
preview the predicted offspring stats (using our knowledge of the
breeding formula: `litter = min(parentA.litter, parentB.litter) +
rng_bonus`). Click "Breed" to drag both horses to the barn
automatically.

**7. Smart auto-feeding**

A toggle: "auto-feed hungry horses from inventory hay". When on, any
horse whose hunger crosses the threshold gets fed automatically as
long as hay is in stock. Removes the manual feeding chore entirely.

**8. Group operations**

Select multiple horses (Ctrl+click or via the roster panel), then:
- Move them all to a location
- Feed them all
- Put them all to sleep
- Retire them all
- Bulk-sell at the glue factory

#### Why this matters

The user explicitly identified this as the second-biggest tedium source
after fatigue/aging. Without these features the late-game experience
(50+ horses) is dominated by UI friction, not gameplay.

#### Implementation path

This entire feature stack rides on `horsey-mod`:

| Sub-feature | Backend | Frontend |
|---|---|---|
| Auto-spread | Hook per-horse render | none (positions just shift) |
| Roster panel | Existing `horses.*` ops | modforge ImGui panel |
| Status badges | Hook status-bubble render | none (badge always-on) |
| Hotkey cycling | SDL input hook (modforge primitive) | none |
| Count display | Hook overlap detection | rendered via render hook |
| Breeding picker | New `breed.preview` op | modforge ImGui panel |
| Auto-feed | New `auto_feed` toggle setting | none (runs automatically) |
| Group ops | New `horses.bulk_*` ops | modforge ImGui panel |

Build the ImGui shell in `modforge` once (D-X-style swap-chain hook +
window/panel API) so horsey-mod, schedule1, grounded2 and future
per-game mods all get the same in-game control window. horsey-mod is
the first consumer and drives the API shape. The web UI on
`modforge::server` remains as the secondary scripting/automation
surface; ImGui is the primary user-facing UX.

This split is also how serious modders ship overlays in 2026: the
external-tool-via-localhost pattern is friction-free vs. embedding a
full UI library into the game's render path.

---

## Mod foundations

All shipped or designed; details in [`MODFORGE-INTEGRATION.md`](MODFORGE-INTEGRATION.md):

- §1 `horsey-mod` crate + HTTP control plane: SHIPPED 2026-05-13. See MODFORGE-INTEGRATION "Implementation status (2026-05-15)".
- §3 Save-edit tool: design + reuse of BXSAVEXT codec in MODFORGE-INTEGRATION "Other modforge-consumer plans".
- §4 RPG layer: skill list + Effect/Trigger/Skill mapping in MODFORGE-INTEGRATION "Other modforge-consumer plans".
- §5 Hotkey system: SDL3 input hook design in MODFORGE-INTEGRATION "Other modforge-consumer plans".

---

## Content-design ideas (for after foundations are in place)

### Genetic complexity beyond 240 genes

- **Extension gene table** in horsey-mod (sidecar to vanilla's chromoMap).
- New axes: personality matrix (16-dim), lineage drift, environmental
  adaptation, social temperament.
- Display via custom UI panel (web frontend or imgui overlay).

### Dynasty tracking

- Build an ancestry graph from horse-parent pointers.
- Track which "dynasty" wins races, breeds successfully, etc.
- Display dynasty trees in a web UI.

### Custom locations

- Hook the world-action dispatcher.
- Add a "Repurposed Building" overlay on an unused-feeling vanilla building
  (e.g. Pawn shop) that triggers custom logic.
- Eventually: a fully scripted location built entirely in horsey-mod.

### Procedural events

- Weekly random events: "An inspector arrives", "A storm damages fences",
  "A rival breeder challenges you".
- Injected into the daily-event scheduler (we annotated this at
  `0x14002fe00`).

---

## Open research questions

These could change the modding architecture; worth investigating early:

- [ ] Does Horsey have an existing ImGui integration we can reuse? (Probably no.)
- [ ] Is the SDL3 input layer hookable cleanly via DLL? (Probably yes via SDL3
      public API forwarding.)
- [ ] How does the game integrate with Steam. Does it call SteamAPI_Init,
      SteamUtils, etc.? (Yes; we have `SteamUtils010` reference at
      `0x1400c35b0`.)
- [ ] Are there per-frame update hooks we can hijack cleanly? (`0x1400dbe10`
      post_race_wrapup is one; there's a global per-frame tick somewhere.)
- [ ] What does the engine do when DLL load order is wrong? (Test by injecting
      a no-op DLL first.)

---

## Long-term: open the platform

Goal: Horsey modding becomes a real ecosystem. Required steps:

1. Publish `horsey-mod` to crates.io (or git URL).
2. Write a tutorial: "Build your first Horsey mod in 30 minutes".
3. Reference mod (e.g. a clean RPG layer) for new modders to copy.
4. Steam Workshop integration? (Unclear if SDK supports custom uploads.)
5. Auto-updater for horsey-mod itself (so mod authors don't pin to ancient
   game versions).

---

## Known control-plane issues (carried over from first-injection milestone)

Recorded 2026-05-13 during the first successful injection (proof-of-life). These are bugs/refinements to the HTTP control plane, distinct from the mod-feature TODOs above.

1. **Snapshot in WRITE responses captures pre-write state.** The `result` field reflects the new value (correct), but the `state` sub-object is captured a moment before the write commits. Cosmetic; the next readback shows correct state. Fix: capture snapshot after the handler runs.
2. **No state-change broadcasting.** Clients have to poll `game.read` to see updates. A websocket or SSE upgrade is on the medium-term roadmap.
3. **Write-op gating.** Bot operators have run write cheats (e.g. $100k money) unprompted during smoke tests. Going forward, write-ops should be user-approved only.

---

## Open next reads (priority order)

Targets for the next decomp-and-document passes, in order of expected payoff:

1. `FUN_1400df280` retirement handler. Pinpoint the age threshold for "horse is too old to race".
2. `FUN_1400a3eb0` chromomap loader. Confirm how `genes.xml` attributes map to runtime behavior, esp. `OLD_AGE` direction.
3. `FUN_140089510` save-file open/write. Get the save struct layout.
4. `FUN_14008ffc0` genome clipboard copy. Get the human-readable genome format.
5. `FUN_140033a10` price formula. Confirm the `* years` factor and the age field offset on the horse struct.

## Working principle

Every claim in any horsey-mod doc must be backed by either:

1. Decompiled code from `Horsey.exe`, with the function address cited.
2. An in-game observation that directly tests the claim (save-diff after a known action).

Anything else is labelled `(INFERRED, NOT VERIFIED)` or removed.

## User's gameplay goal (the original motivator)

User wants to mod out the tedium loop:

1. Horse stamina / fatigue: a horse can only run ONE race before it's tired and needs to sleep. Want this much higher, or remove fatigue entirely.
2. Horse lifespan: horses die too quickly, forcing constant breeding/killing/swapping. Want longer lifespans (or much slower aging).

Complaint is FREQUENCY, not the mechanics. Goal is to dial knobs down, not delete mechanics. Target outcome: play sessions focused on racing and farming, not constant rotation of dying horses.


---

# Appendix: Action items consolidated from subject docs (2026-05-15)

Each subsection below was extracted from the doc named in its header. The source doc now keeps the narrative/plan structure but the actionable checkboxes live here as the single source of truth.

## Address resolution (R1-R5 phased plan)

_Source: [`ADDRESS-RESOLUTION.md`](ADDRESS-RESOLUTION.md)._

- [ ] Add `targets::image_sha256()`: read the running Horsey.exe
      bytes from the loaded module, hash the .text + .data
      sections (skip the .reloc table that changes per-load),
      log the result at attach.
- [ ] Add an HTTP op `game.build_info` returning hash + mtime +
      `image_base()` + a "known build name" if the hash matches
      one we've recorded.
- [ ] Add `horsey-mod/research/known-builds.toml`: a per-build manifest
      with `{ hash: "...", date: "...", decomp_index_path: "..." }`
      so future sessions can be told "you're on build X, decomp
      at Y" without guessing.
- [ ] Add a `targets::resolved` module. For each function we
      hook, define a patternsleuth signature. A sequence of
      bytes from the function's prologue, with `?` wildcards
      for compiler-shifted instructions (RIP-relative LEA
      displacements, immediate constants that the linker
      adjusts).
- [ ] At DLL attach (before any patch / detour), run a single
      patternsleuth scan over the .text section for all
      registered patterns. Populate a static map
      `(symbol, resolved_addr)`.
- [ ] `targets::fn_addr::APPLY_GENE_TO_HORSE` (and friends)
      become lookups into the map instead of `const usize`
      values. Pre-existing fixed-address callers keep working
      via accessor functions.
- [ ] HTTP op `targets.scan_report` returns
      `{ symbol: "...", resolved_addr: "0x...", matched_via:
      "pattern_id", confidence: "exact" | "fuzzy" }` so we can
      diff against the previous run.
- [ ] `horsey-mod/research/extract-signatures.py`. Inputs: the
      `decompiled/INDEX.md` + the function-body files. Output:
      a TOML / Rust constants file with prologue bytes and
      suggested wildcards for each function we care about.
      Wildcards picked by diffing the same function across
      multiple known builds. Bytes that differ across builds
      become `?`.
- [ ] CI / pre-merge check: run the extractor on the latest
      decomp, diff against the committed signatures, fail if
      any drift > threshold.
- [ ] Per-function comment in `targets/resolved.rs` cites the
      decomp file the signature was derived from
      (e.g. "from 1400a/1400a5d20.c lines 1-15").
- [ ] If a critical-path function fails resolution (e.g.
      EVAL_DIPLOID_BLEND_A), `arm()` for the related detour
      refuses to install and logs a clear "function not found
      in this build; re-extract signatures or extend wildcards"
      message.
- [ ] If a non-critical function (CRISPR UI dispatcher) fails,
      log + continue. The mod still works minus that feature.
- [ ] `dryrun` HTTP ops report `resolved: bool` per target so
      the operator can see what's missing before arming.
- [ ] At attach: compare `image_sha256()` to the hash that
      generated the current `decompiled/INDEX.md`. If different,
      print a big-yellow log line: "Game updated since last
      decomp; addresses MAY be stale."
- [ ] Optional: a `tools/refresh-decomp.ps1` wrapper that
      runs `horsey-mod/research/decompile.py` + `extract-signatures.py`
      back-to-back, commits the diff under a `chore:` prefix.
- [ ] Optional: a GitHub Actions job triggered manually that
      runs the same on a Windows runner with Ghidra installed.

## External-knowledge verification gaps

_Source: [`EXTERNAL-KNOWLEDGE.md`](EXTERNAL-KNOWLEDGE.md)._

- [ ] Confirm pop.xml `p0`/`p1`/`p2`/`p3` are INVERSE weights (read the spawn code in chromomap loader or similar).
- [ ] Confirm "press 5 in balloon" = x300 speed by reading the balloon controller / pause input handler.
- [ ] Find the buried-item ID -> item-type table in code (offsets 0-47).
- [ ] Find the building-uniqueness check (first-instance-wins logic).
- [ ] Find the CRISPR-Lab world-swap logic (vial sub-map teleport).

## Bestiary viability research

_Source: [`VIABILITY.md`](VIABILITY.md)._

- [ ] `FUN_1400c0660` (±5 mutator). Find callers,
      check for literal indices.
- [ ] `FUN_1400c03a0` (allele swap). Find callers.
- [ ] `FUN_1400c1cf0` (CRISPR?). Find callers.
- [ ] Is there unused padding after `DAT_1403ee4a4` we
      could exploit for in-place expansion? Check the
      symbol immediately following in the binary.
- [ ] How much headroom do we want? 256 = double, 512 =
      quadruple, 1024 = future-proof.
- [ ] Cross-reference vanilla `pop.xml` against the 233
      referenced indices to find genes that exist in code
      but no pop authors at non-default weights. Those
      are "soft-free" and may be safely repurposed by
      having our trampoline override their effect.
- [ ] Read each of the 7 hard-free slots (56, 57, 107,
      183, 184, 209, 216) and confirm they're really
      effect-free (the regex extracted only direct
      `FUN_1400a5d20(local_508, N)` calls; the gene
      might be read by other paths I haven't grepped).
- [~] Q-render-1: `pop.xml` checked in at
      [`vanilla-pop.xml`](vanilla-pop.xml). Per-oddity
      decomposition (which genes drive `car` wheels,
      `helix` shape, etc.) partially captured in
      GENE-CATALOG.md Part 2 "Vanilla pops"; full
      breakdown still pending per-species.
- [x] **DONE.** Map each of the 61 consumer-read
      slots to its horse-struct destination offset.
      `research/extract-consumer-map.py` auto-derives:
      23 direct-copy slots map to `+0x58..+0xa4`,
      `+0x200`, `+0x254`, `+0x2a8`. 38 are
      conditional/intermediate (not direct copies).
      Output: GENE-CATALOG.md Part 2.
- [ ] Confirm the 91 fully-unused slots are not
      touched by other consumer chains (e.g. the
      breeding compatibility check
      `FUN_1400b78d0` calls `FUN_1400c5c10` with two
      buffers but uses different stack offsets, so it
      may consume more slots).
- [ ] For each "new visual mode" we want (wings, wheels,
      transparency, etc.), determine if any vanilla
      pop already exhibits it (specifically: does `car`
      reuse some gene to drive wheel rendering?). Need
      live `pop.xml` to answer.

## Content-creation verification gaps

_Source: [`CONTENT-CREATION.md`](CONTENT-CREATION.md)._

- [ ] **`p0..p3` are inverse weights** - read the gene-allele selection code.
- [ ] **Adding new gene NAMES** - read `FUN_1400a3eb0` (chromomap loader). Does it accept arbitrary names or only the 242 enum'd ones?
- [ ] **First-instance-wins building rule** - find the building-placement scan code.
- [ ] **Item ID 48+ bug** - find the item table.
- [ ] **400x225 map size** - find the tmx parser.

## Gene system open questions

_Source: [`GENE-CATALOG.md`](GENE-CATALOG.md) Part 1: Conceptual model._

- [x] **DONE 2026-05-15.** Breeding combinator is
      `FUN_1400a2d80(parent_a + 0x2b8, parent_b + 0x2b8,
      child + 0x2b8)`. Called from `FUN_1400b2e30:104367`.
      Plain Mendelian (one strand per parent, each strand
      picks one of the parent's two strands at random)
      plus linked inheritance across 3 cluster ranges
      (Neck 72..86, Head/Face/Hat 97..174, palette base
      183..197). See GENE-CATALOG.md Part 1 Step 1 for
      the algorithm.
- [ ] Confirm the runtime mutation-during-breeding
      behavior: does the child get random allele
      flips beyond the parent picks?
      (Not seen in `FUN_1400a2d80` body; pure parent
      copy. Mutation may be applied elsewhere, e.g. in
      `FUN_1400b2e30` after the combinator + engine
      run, or it may not exist for child-creation and
      drift only happens via `FUN_1400c0660` death
      handler.)

## Decompilation next steps

_Source: [`DECOMPILATION-STATUS.md`](DECOMPILATION-STATUS.md)._

- [ ] Read and document each of the 20 extracted key functions. Curated names + descriptions land in [`ALL-FUNCTIONS.md`](ALL-FUNCTIONS.md) (the merged function index).
- [ ] Reconstruct the `Horse` struct (offsets like `+0x350`, `+0x39c`, `+0x3a0` from `interact_dispatch_or_status_check` are all fields of the same horse struct).
- [ ] Identify the fatigue counter byte and the age field. Mod targets.
- [ ] Walk callers and callees of named functions; document those too. Expand outward.
- [ ] Use `Function ID` Ghidra analyzer with public SDL3/MSVC signature databases to bulk-name vendor functions and exclude them from manual work.

## Save format research

_Source: [`SAVE-FORMAT.md`](SAVE-FORMAT.md)._

Find the two fields needed to address the user's complaints, both presumably in one of the big binary blocks of `save1.dat` (most likely the 55KB block at 0x0d4f, possibly the 188KB tail):

- [ ] **Fatigue counter** (post-race tiredness). Save-diff procedure: save (state A), race a horse exactly once, save (state B), byte-diff. The bytes that changed are: race counter, fatigue, timestamp, RNG state, horse position, audience state. The fatigue counter should be at the same offset relative to the raced horse's record.
- [ ] **Age field** (and the retirement threshold). Save-diff procedure: save A, let many in-game days pass (no race/breed), save B. Bytes that monotonically increased = age candidates.
- [ ] **Identify genome location**. 242 genes x ~4 bytes = ~970 bytes per horse; 55KB block / 85 horses = 646 bytes/horse. Close enough to test. Per-horse genome may be variable length depending on which genes apply to that pop.
- [ ] **Confirm pop_id mapping** in the roster. Cross-reference observed pop_id values (1, 2, 3, 4, 5, 7, 12, 255) against `pop.xml` ordering. If it matches we have a free byte to mod a horse's apparent population without re-rolling its genome.
- [ ] **Decode flag_a..flag_e** in the 22-byte trailer. Could be sex, gender-marker, pregnant state, current location, breed sub-type, color.
