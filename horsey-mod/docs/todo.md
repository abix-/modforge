# horsey-mod TODO

> **Major prior art (2026-05-15):** [NickPetrone/HorseyLiveTweaks](https://github.com/NickPetrone/HorseyLiveTweaks) by Nick Petrone (Twisternick) is an independent Horsey Game modding framework with ~4500 lines of C++, in-game ImGui UI, and pattern-scan address resolution. Cross-validates our `horse+0x2b8` working-genome model and our `FUN_1400b3070` regen function. **Different scope** (they tweak the vanilla 240; we extend to 480). Full credit + comparison in [`PRIOR-ART-HorseyLiveTweaks.md`](PRIOR-ART-HorseyLiveTweaks.md). Their pattern-scan approach is the reference we should port for our R1/R2 address-resolution work.


> **Authoritative on:** open work and feature wishlist for the `horsey-mod` crate (native-PE binding for Horsey Game) AND for Horsey-Game content mods shipping alongside it. Workspace-wide framework work lives in [`../../docs/todo.md`](../../docs/todo.md).

Roughly ordered by leverage.

---

## Table of contents

- [P0 BLOCKER: pattern-resolve EVERY hardcoded address](#p0-blocker-pattern-resolve-every-hardcoded-address)
- [Ship status pointers](#ship-status-pointers)
- [P0. Bestiary Expansion: double the species count](#p0-bestiary-expansion-double-the-species-count)
- [P0. Gene Table Doubling: 240 -> 480 implementation plan](#p0-gene-table-doubling-240---480-implementation-plan)
- [Other open work](#other-open-work)
- [Appendix: Feature wishlist](#appendix-feature-wishlist-merged-from-roadmapmd-2026-05-15)

---

## P0 BLOCKER: pattern-resolve EVERY hardcoded address

User-locked 2026-05-15. Every address in `targets.rs` must be pattern-resolved. Authoritative migration tracker (data-globals + function-entries tables, R3 validation primitives, definition of done): [`ADDRESS-RESOLUTION.md`](ADDRESS-RESOLUTION.md#migration-hardcoded---resolved-authoritative-status).

**Current status (2026-05-15):**
- 6/6 data globals on **R**
- 31/31 function entries on **R** (RETIRE_HORSE_HANDLER re-derived 2026-05-15 via format-string xref method)
- Field offsets: **R4 in progress, 10/37 done.** Migrated via patternsleuth + in-process pattern decode: `gs_offset::year/sleeps/money/horses_begin/horses_end/live_horses_begin/live_horses_end`, `horse_offset::ctx_offset/tired_flag_a/tired_flag_b`. Remaining ~27 fields need anchors authored.

**Open work in this section:**
- [ ] **R4: Field-offset resolver tier.** Same model as R3 for data globals, except the disp32 to decode is the FIELD OFFSET (instruction's RIP-rel `disp8`/`disp32` operand) rather than the global's address. Workflow per field:
  - Anchor on a unique site that reads the field: e.g. for YEAR, the pause-menu printf `"< Simulation Paused - Year %d >"` (in `FUN_140066200` at decomp `FUN_14008d760(local_88, "< Simulation Paused - Year %d >", *(undefined4 *)(DAT_1403fb0d8 + 0x314))`). The MSVC instruction is `mov reg32, [rax + disp32]` where rax = dereffed GAMESTATE_PTR and disp32 = current YEAR offset.
  - Reuse the format-string-xref technique from `find_retire_horse_handler` to locate the printf site, then decode the `mov reg32, [rax + ??]` immediately preceding it.
  - Per field: one resolver `gs_offset::year() -> usize` cached in a `OnceLock`. Production reads go through it.
- [ ] Apply R4 to every gs_offset + horse_offset entry.
- [ ] Author second candidate signatures for every resolver so a single MSVC reorder between builds doesn't break it (current Definition of Done #2; one sig each today).
- [ ] CI / pre-commit refuses to ship any new `pub const usize = 0x140...;` outside `targets::resolve::*` candidate sigs (Definition of Done #4).

### Hardcoded-constants inventory (zero-hardcoding audit, 2026-05-15)

Every magic integer baked into Rust source code. User-locked: nothing is out of scope. Audit, classify, then decide what to migrate.

Status codes:
- **R**: pattern-resolved at runtime via patternsleuth.
- **H-gb**: hardcoded, GAME-BINARY DERIVED. Drift risk on Horsey updates. Target for migration.
- **H-alg**: hardcoded ALGORITHM CONSTANT. We control the algorithm; the value is fixed by definition (CRC polynomial, hash mixer). Migration value = none, but still audit so we know it's intentional.
- **H-os**: hardcoded HOST-OS CONSTANT. Windows ABI/exception codes. Migration value = none unless we ship on a non-Windows platform.
- **H-design**: hardcoded DESIGN CHOICE we own (sidecar version, UI row cap, gene-count target). Migration value = none; these are policy.
- **H-test**: hardcoded TEST FIXTURE. Migration value = none.

#### Game-binary derived (H-gb): MUST migrate

| Constant | File:line | Kind | Status | Notes |
|---|---|---|---|---|
| `GAMESTATE_PTR` 0x1403fb0d8 | targets.rs:26 | data global | **R** | constructor-anchored resolver |
| `SAVE_VERSION_GLOBAL` 0x1403fb0e0 | targets.rs:31 | data global | **R** | derived from GAMESTATE_PTR+8 |
| `RACES_COUNTER` 0x1403eded8 | targets.rs:35 | data global | **R** | -10.5f anchor |
| `NO_TIRE_TOGGLE` 0x1403d95a5 | targets.rs:44 | data global | **R** | cmp-sete pair sig |
| `DEBUG_MODE_ACTIVE` 0x1403d957b | targets.rs:51 | data global | **R** | unlock-block delta |
| `DEBUG_LOG_GATE` 0x1403d9506 | targets.rs:59 | data global | **R** | init-triplet sig |
| `fn_addr::*` (31 entries) | targets.rs:166-371 | function entry | **R** | 32-48 byte body sigs |
| `gs_offset::FRAME_TICK` 0x254 | targets.rs:66 | struct field offset | **H-gb** | needs R4 |
| `gs_offset::FIELD_268` 0x268 | targets.rs:67 | struct field offset | **H-gb** | needs R4 |
| `gs_offset::MONEY` 0x308 | targets.rs:68 | struct field offset | **H-gb** | anchor: cheat-money handler |
| `gs_offset::YEAR` 0x314 | targets.rs:69 | struct field offset | **H-gb DRIFT OBSERVED** | reads 336 on new game; anchor: "Year %d" printf |
| `gs_offset::SLEEPS` 0x318 | targets.rs:70 | struct field offset | **H-gb** | anchor: "Sleeps %d" printf |
| `gs_offset::SUPPLIES_START` 0x31c | targets.rs:76 | struct field offset | **H-gb** | needs R4 |
| `gs_offset::FIELD_37C/39C/410/414/415/418/41C/440` | targets.rs:77-84 | struct field offset (8) | **H-gb** | needs R4 |
| `gs_offset::HORSES_BEGIN/END` 0x280/0x288 | targets.rs:87,90 | struct field offset (2) | **H-gb** | roster pointer pair; looks_loaded reads these |
| `gs_offset::TRAILING_278/27C` | targets.rs:91-92 | struct field offset (2) | **H-gb** | needs R4 |
| `horse_offset::TYPE_OR_SPECIES/NAME_ID` 0x1c/0x1f8 | targets.rs:109,111 | struct field offset (2) | **H-gb** | needs R4 |
| `horse_offset::AGE/MAX_AGE` 0x1fc/0x200 | targets.rs:113,116 | struct field offset (2) | **H-gb** | needs R4 |
| `horse_offset::ON_TRACK_FLAG/BREEDING_FLAG` 0x204/0x207 | targets.rs:118,124 | struct field offset (2) | **H-gb** | needs R4 |
| `horse_offset::TIRED_FLAG_A/B` 0x205/0x206 | targets.rs:120,122 | struct field offset (2) | **H-gb** | anchor: sleep_safe_no_tire patch site |
| `horse_offset::SKILL/LITTER_SIZE_STAT` 0x21c/0x254 | targets.rs:126,129 | struct field offset (2) | **H-gb** | needs R4 |
| `LIVE_HORSES_BEGIN/END` 0x130/0x138 | gamestate.rs:428,430 | struct field offset (2) | **H-gb** | should move to gs_offset |
| Roster entry stride 0x24 | gamestate.rs:129,243,393,414 | struct stride | **H-gb** | repeated 4x; one resolver feeds all |
| `HORSE_CTX_OFFSET` 0x2b8 | combinator.rs:26, render_trampoline.rs:34 | struct field offset | **H-gb** | HORSE_SAVE_LOADER uses `add rcx, 0x2b8`; decode that instr's imm32 |
| `FN_RVA` 0x1400ceb60 + `FN_SIZE` 2502 | patches.rs:163,164 | function entry + size | **H-gb** | sleep_safe_no_tire patch site; FN_RVA needs body sig, FN_SIZE needs end-of-function detection |
| Patch-site offset 0x206 (TIRE_FLAG_B store) | patches.rs:195 | struct field offset | **H-gb** | duplicate of horse_offset::TIRED_FLAG_B; should reference R4 resolver |
| Patch-site offset 0x205 (TIRE_FLAG_A store) | patches.rs:199 | struct field offset | **H-gb** | duplicate of horse_offset::TIRED_FLAG_A |
| GameState alloc size 0x448 | resolver comments | struct size | **H-gb** | anchor for FUN_14009c6a0 |
| Horse alloc size 0x498 | resolver comments | struct size | **H-gb** | anchor for HORSE_CONSTRUCTOR |

**H-gb count: 32 struct-field offsets + 3 struct sizes + 1 stride + 1 patch-site fn pair + 2 duplicate field offsets in patches.rs = ~37 game-binary constants left to migrate.**

#### Algorithm constants (H-alg): we own; intentional

| Constant | File:line | Kind | Notes |
|---|---|---|---|
| CRC32 polynomial 0xEDB88320 | save_sidecar.rs:210 | algorithm | reflected zlib poly; sidecar format we define |
| splitmix64 mixer 0x9E3779B97F4A7C15 | genes.rs:455,488 | algorithm | seed-mixing constant for child-id RNG |
| splitmix64 mixer 0xBF58476D1CE4E5B9 | genes.rs:456,489 | algorithm | same |
| splitmix64 mixer 0x94D049BB133111EB | genes.rs:457,490 | algorithm | same |
| Initial RNG seed 0xa5a5_a5a5_a5a5_a5a5 | genes.rs:481 | algorithm | static counter seed |
| Increment 0x100000001b3 | genes.rs:482 | algorithm | FNV prime; fetch_add for RNG state |

#### Host-OS constants (H-os): Windows ABI

| Constant | File:line | Notes |
|---|---|---|
| EXCEPTION_ACCESS_VIOLATION 0xc000_0005 | lib.rs:187 | NT status code |
| EXCEPTION_ILLEGAL_INSTRUCTION 0xc000_001d | lib.rs:188 | NT status code |
| EXCEPTION_STACK_OVERFLOW 0xc000_00fd | lib.rs:189 | NT status code |
| EXCEPTION_INT_DIVIDE_BY_ZERO 0xc000_0094 | lib.rs:190 | NT status code |
| EXCEPTION_PRIV_INSTRUCTION 0xc000_0096 | lib.rs:191 | NT status code |
| DLL_PROCESS_ATTACH/THREAD_ATTACH/THREAD_DETACH/PROCESS_DETACH | lib.rs:297-300 | DllMain reason codes |
| Heap-pointer bounds 0x10000 / 0x7fff_ffff_ffff / & 0x7 alignment | gamestate.rs:74 | x64 Windows user-mode address space facts |

#### Design choices (H-design): policy we control

| Constant | File:line | Notes |
|---|---|---|
| EXT_GENE_COUNT 240 | genes.rs:33 | our target gene-table extension size |
| TOTAL_GENE_COUNT 240+EXT | genes.rs:36 | derived from above + vanilla 240 |
| DEFAULT_MUTATION_RATE 100 | genes.rs:40 | default for ext gene mutation rates |
| DEFAULT_SCALE 1 | genes.rs:43 | default ext-gene scale |
| Sidecar format VERSION 1 | save_sidecar.rs:54 | BXSAVEXT version we author |
| BUF_LEN_FLOATS 353 | render_trampoline.rs:38 | render trampoline buffer size (matches engine layout but ours to set) |
| MAX_ROWS 32 | ui.rs:68 | UI cap on Horses tab row count |
| alias_check sentinels 0xAB / 0xCD | ops.rs:392,393 | distinct sentinel bytes for byte-aliasing probe |

#### Test fixtures (H-test): not production

| Constant | File:line | Notes |
|---|---|---|
| 0x1234, 0x5678, 0xDEAD | genes.rs:795,818,822,844 | unit-test horse ids |
| 0x01010101 / 0x02020202 fill | gamestate.rs:561,562 | regression fixture for fill-pattern roster |
| 0xff / 0xfe bad-bytes | save_sidecar.rs:360,361 + genes.rs:999,1000 | corruption-handling fixtures |

#### Summary

- **Migrate (H-gb): 37 constants** -> R4 work below.
- **Not migrating (H-alg / H-os / H-design / H-test): ~25 constants**, all intentional. Audited and acknowledged.

## Ship status pointers

- **480-gene D0-D5 + D7 implementation status:** [`HOOKING-STRATEGY.md`](HOOKING-STRATEGY.md) §8 (summary) + §9 (full implementation log).
- **D0 sidecar buffers + locked design decisions + architecture diagram:** [`GENE-CATALOG.md`](GENE-CATALOG.md) Part 3.
- **D4 save sidecar + horse-id finding + BXSAVEXT format:** [`SAVE-FORMAT.md`](SAVE-FORMAT.md) "Save pipeline functions", "Horse-id field", "Sidecar format".
- **Test harness + test-first rule + live test inventory:** [`TESTING.md`](TESTING.md).
- **Cross-validation with HorseyLiveTweaks:** [`PRIOR-ART-HorseyLiveTweaks.md`](PRIOR-ART-HorseyLiveTweaks.md). Every offset matches.

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

D0 architecture / locked-decisions and D1+D3+D5 detours shipped 2026-05-14 / 2026-05-15. See [`CHANGELOG.md`](CHANGELOG.md#d-phase-shipped-items-2026-05-14--2026-05-15). D0.5 (heap-redirect helper) deferred but not blocking.

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

- [ ] **D7.1.** Implement the `genes.xml.reload` and `pop.xml.reload` HTTP ops (Q-reload-1 still open; may not be feasible if vanilla doesn't expose a reentrant loader).
- [ ] **D7.4.** Per-horse full dump op. Needs a stable horse_id resolution per D4.4 finding (roster slot position) before it's meaningful.

### Phase D8: Verification

Most D8 items are now covered by harness + unit tests; see [`TESTING.md`](TESTING.md) for the test inventory. Specifically:

- **D8.1** (vanilla regression check): covered by `tests/smoke` + `tests/dryrun_d1_d5` + `tests/arm_full_safe_stack`.
- **D8.4** (breeding inheritance): covered by 6 unit tests in `genes::tests::combinator_*`.

Still open (need a save loaded + per-test save fixtures):

- [ ] **D8.2.** Add ONE extended gene (e.g. `BX_WING_SIZE`); spawn a horse of a pop that uses it; confirm slot value matches diploid blend math.
- [ ] **D8.3.** Save / reload round-trip for a horse with ext alleles. Blocked on D4 stale save addresses.
- [ ] **D8.5.** Stress test: add 100 ext genes, profile per-frame cost of the D5 trampoline + sidecar file size.
- [ ] **D8.6.** Hot-reload genes-extended.xml via HTTP mid-game, confirm visual change without restart.

### Phase D9: Documentation and rollout

- [ ] **D9.2.** Write a "How to author a new gene" guide aimed at non-engineers: `genes-extended.xml` format, `mode="..."` options, working examples.
- [ ] **D9.3.** Decide rollout: ship the patch infra with zero extended genes by default and let authors add them via XML, OR ship a starter pack of 20-50 useful new genes.

### Risks and unknowns (open only; resolved entries relocated to [`CHANGELOG.md`](CHANGELOG.md#d-phase-risks-resolved-2026-05-15))

| Risk | Mitigation |
|---|---|
| `FUN_1400a5d20`'s detour may be hot enough that the per-call branch costs measurable frame time. | Profile in D8.5. If it's a problem, JIT-patch the detour to skip vanilla frames where no extended genes are defined. |
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

**5. Count display**

Floating "N" badge above a stack of overlapping horses, showing the
count. Disappears when you mouse-over (so it doesn't block the spread
view).

**7. Pasture auto-buy hay**

Horses already auto-eat from pasture hay; the actual chore is BUYING the hay from the store to keep the pasture stocked. Toggle: "auto-buy hay when the pasture stock drops below the threshold". On, the mod posts the buy at the store on the player's behalf. Off, you do it manually. Removes the trip-to-the-store loop.

Implementation: read pasture hay stock + price; when stock crosses a configurable low-water mark and the player has enough money, fire the in-game buy op for N units. Same buy primitive the player triggers; we just automate the trigger.

Group operations (multi-select move / sleep / retire / bulk-sell at glue factory) are folded into the roster UI; no separate sub-feature.

#### Why this matters

The user explicitly identified this as the second-biggest tedium source
after fatigue/aging. Without these features the late-game experience
(50+ horses) is dominated by UI friction, not gameplay.

#### Implementation path

This entire feature stack rides on `horsey-mod`:

| Sub-feature | Backend | Frontend |
|---|---|---|
| Roster panel | Existing `horses.*` ops | modforge ImGui panel |
| Count display | Hook overlap detection | rendered via render hook |
| Pasture auto-buy hay | New ops to read pasture hay stock + post a buy at the store on threshold | none (runs automatically) |

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

1. ~~**Snapshot in WRITE responses captures pre-write state.**~~ FIXED 2026-05-15. Snapshot moved AFTER the op dispatch in `lib.rs`'s HTTP handler so write ops surface the post-write game state in the `state` sub-object.
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
- [x] **DONE.** Map each of the 61 consumer-read slots to its horse-struct destination offset. Tool: `research/extract-consumer-map.py`. Result: 23 direct-copy slots, 38 conditional/intermediate. Output documented in [`GENE-CATALOG.md`](GENE-CATALOG.md) Part 2 "Buf-slot -> horse-struct field".
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

- [x] **DONE 2026-05-15.** Breeding combinator located + algorithm verified. Full details in [`GENE-CATALOG.md`](GENE-CATALOG.md) Part 1 Step 1 "Breeding combinator".
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
