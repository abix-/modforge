# horsey-mod TODO

> **Authoritative on:** open work and feature wishlist for the `horsey-mod` crate (native-PE binding for Horsey Game) AND for Horsey-Game content mods shipping alongside it. Workspace-wide framework work lives in [`../../docs/todo.md`](../../docs/todo.md).

Roughly ordered by leverage.

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

### Phase 0: Viability research

Goal: answer every "is X possible?" question before we
commit to a species list, a new-gene list, or a build
order. No XML, no patches, no in-game work in this phase.
Pure decomp + Ghidra + (optional) live-process inspection
via the existing `horsey-mod` HTTP ops.

Outputs: a `VIABILITY.md` doc in this directory that
answers each question below with evidence + file:line
cites. The decisions in Phase 1 reference that doc.

#### Pop system (engine-level questions)

- [x] **Q-pop-1.** ANSWERED. Pops are unbounded
      heap-grown std::vector at
      `DAT_1403f2fc0/8/d0` (begin/end/cap triple).
      See [`VIABILITY.md`](VIABILITY.md) Q-pop-1.
- [x] **Q-pop-2.** ANSWERED. Unknown pop name -> hard
      crash via `FUN_1400c4340("pop not found %s")`
      (MessageBox + INT3 abort). No silent fallback.
- [x] **Q-pop-3.** ANSWERED. 4120-byte (`0x1018`)
      records in std::vector. Per-pop weight at offset
      `0x28 + (gene * 4 + allele) * 4`.
- [x] **Q-pop-4.** ANSWERED. Inherit-then-override.
      Child copies parent's full 480-pair gene-weight
      block, then patches by `<gene name="X">`. Loader
      at `FUN_1400a5ee0`.

#### Gene system (the table extension question)

- [x] **Q-gene-1.** ANSWERED. 7 reader functions touch
      the gene table. All by-variable indexing, none
      by literal. 32-byte stride throughout. 3 mutate
      live (death handler, allele swap, CRISPR UI).
- [x] **Q-gene-2.** ANSWERED. `0xf0` as table bound
      appears in 3 loops. `0x1e00` (full table size)
      doesn't appear. No allocation literal to patch.
- [x] **Q-gene-3.** ANSWERED. 233 of 240 indices baked
      LITERALLY in `FUN_14009f680` (gene-effect
      engine). One concentrated function, not
      scattered. Forces the trampoline strategy.
- [x] **Q-gene-4.** DECIDED. Detour-and-dispatch via
      D1 detours (NOT heap redirect of DAT_1403ee4a4).
      Sidecar `EXT_GENE_TABLE` for slots 240..480.
      Vanilla static table untouched. See D1 plan.
- [x] **Q-gene-5.** ANSWERED. Only 7 hard-free vanilla
      slots (56, 57, 107, 183, 184, 209, 216). Not
      enough to carry the bestiary on repurposing
      alone; full extension is the chosen path.

#### Save / load (compat question)

- [x] **Q-save-1.** ANSWERED. 480 bytes per horse at
      `horse[0x78]` (diploid, 240 alleles x 2). Save
      packs to 240 bytes per horse via 3-bit-per-allele
      encoding `(b+1)<<3 | (a+1)`. Allocator
      `FUN_14005cf70` / `FUN_14005d190`.
- [x] **Q-save-2.** ANSWERED. 11 patch sites for
      genome save / load + alloc / walk + 7 more for
      pop record layer. Full table in
      [`VIABILITY.md`](VIABILITY.md) Q-save-2.
- [x] **Q-save-3.** DECIDED. Sidecar `save<N>.dat.ext`.
      Vanilla save bytes never modified. See D4 plan.
      Locked in 2026-05-14 user direction.

#### Renderer / behavior (gene-effect question)

- [ ] **Q-render-1.** OPEN. Needs live vanilla `pop.xml`
      to determine which genes drive vanilla unusual
      modes (`car` wheels, `helix` shape). Not blocking
      D0/D1; deferred until specific bestiary species
      need it.
- [x] **Q-render-2.** ANSWERED. Per-horse render param
      array is 353 floats (1412 bytes). `FUN_14009f680`
      writes 258 unique slots. ~95 slots in [0..352]
      are touched by neither engine nor consumer:
      candidate trampoline outputs.
- [x] **Q-render-3.** ANSWERED (well enough for
      trampoline design). Pipeline is
      `FUN_14009f680(buf, horse) -> FUN_1400ab3d0(horse, buf)`.
      Consumer reads 61 of 258 slots. We hook between
      them OR after consumer to add new gene effects.

#### Hot reload (iteration speed question)

- [ ] **Q-reload-1.** OPEN. Needs runtime experiment
      (call vanilla loader twice and observe). Not
      blocking: D7 ops cover the modded-side reload
      via our own loader.
- [x] **Q-reload-2.** DONE. The HTTP ops shipped in
      D0.6 ARE the live editor: `genes.ext.set` /
      `pop.ext.weight.set` / `horse.ext.alleles.set`
      mutate sidecar state without restarting.

#### Phase 0 exit criteria

Phase 0 EXITED 2026-05-14. Every blocking research
question is answered with file:line cites in
[`VIABILITY.md`](VIABILITY.md). Q-render-1 and
Q-reload-1 remain open but deferred (don't block
D0..D5; will be revisited as needed during bestiary
authoring).

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

- [ ] Locate the user's installed Horsey Game `data/`
      directory. Document the path in
      [`MODFORGE-INTEGRATION.md`](MODFORGE-INTEGRATION.md)
      or a new `INSTALL-LAYOUT.md`.
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

### Locked decisions (2026-05-14)

These are sticky. Future sessions assume them.

- **Game install path:**
  `C:\Games\Steam\steamapps\common\Horsey Game`. Verified
  to contain `Horsey.exe`, `data/` (with `genes.xml`,
  `pop.xml`, `horsey.tmx`, `genes.dat`), `save/`,
  `sound/`, `steam_api64.dll`. Use this path for:
  - reading vanilla `genes.xml` / `pop.xml` /
    `horsey.tmx` during development
  - backing up vanilla data files before any test edits
  - writing sidecar files (`save<N>.dat.ext`,
    `genes-extended.xml`)
  - injecting via `horsey-inject.exe`
    (target process: `Horsey.exe`)
- **Layered design.** Code sits ON TOP of vanilla. Don't
  rewrite vanilla unless we MUST. Trampolines, sidecars,
  heap redirects preferred over inline rewrites. When
  designing any new patch, ask "can vanilla still run
  unchanged?" first.
- **Authoring format.** Extended genes are defined in a
  user-editable XML file (`genes-extended.xml`)
  mirroring vanilla `genes.xml` shape. Phase D5.3's
  per-gene metadata (`extends="..."` mapping) goes in
  this XML.
- **Save compat.** Sidecar `save<N>.dat.ext` next to
  vanilla save. Vanilla save bytes never modified. Old
  saves keep working when the mod is uninstalled. ALL
  extended state goes through the sidecar; never patch
  the vanilla save serializer.
- **Phase order.** Build infra first (D0 + D7) before
  any vanilla patches. Sidecar buffers, HTTP ops,
  reload tooling get built and verified before touching
  any binary. If tempted to start patching
  `FUN_1400a5d20` to test something, first check
  whether the same insight could come from a
  `genes.ext.dump` HTTP op.

---


> **Goal:** double the engine's gene capacity from 240
> to 480 so the bestiary expansion can introduce up to
> 240 brand-new gene types. Built per the "layer on
> top of vanilla" design principle in
> [`VIABILITY.md`](VIABILITY.md): vanilla functions stay
> intact wherever possible; we patch surgically and
> redirect to our own buffers for the extended range.
>
> **Status:** PLANNED, not started. Prereqs: Phase 0
> viability research is substantially complete (see
> [`VIABILITY.md`](VIABILITY.md)). Final go/no-go is
> Phase 1 lock-in.
>
> **Estimated scope:** ~25 patch sites, plus 2 new
> sidecar buffers, plus 1 trampoline. Roughly 1-2 weeks
> of focused work assuming each phase passes its
> verification step. Multiply by 2-3 if anything in
> Phase 0 was missed.

### Architecture in one diagram

```
                   vanilla 240 slots                     extended 240..479
                  --------------------                  --------------------
GENE TABLE        DAT_1403ee4a4 (static)        ---->   our_gene_table_ext (heap)
                  7 readers, 3 loop bounds              hooked into same readers

POP RECORDS       DAT_1403f2fc0 + i*0x1018      ---->   our_pop_weights_ext (heap)
                  std::vector grows freely              one entry per pop_id
                  per-pop weight at +0x28               240 extra gene weights x 4 alleles

PER-HORSE GENOME  horse[0x78], 480 bytes        ---->   our_horse_genome_ext (heap)
                  diploid, 240 alleles x 2              keyed by horse_id
                                                        diploid, 240 alleles x 2

SAVE FORMAT       save1.dat                     ---->   save1.dat.ext (sidecar)
                  vanilla untouched                     our buffers serialized

GENE EFFECT       FUN_14009f680 -> param_1[N]   ---->   our trampoline after
ENGINE            233 hardcoded indices                 evaluate genes 240..479
                                                        write to unused param_1 slots
                                                        OR new horse-struct fields
```

### Phase D0: Implementation prep

Pre-work before any patches go in. Builds the
infrastructure the later phases assume.

- [x] **D0.1.** Decide N (target gene count). DONE.
      Picked 240 (exactly double, total 480). Lives as
      `EXT_GENE_COUNT` constant in `horsey-mod/src/genes.rs`.
- [x] **D0.2.** Add sidecar gene-table buffer. DONE.
      `gene_table()` in `horsey-mod/src/genes.rs` returns
      a `RwLock<Vec<ExtGene>>` of `EXT_GENE_COUNT` entries,
      initialized to vanilla defaults (m=100, s=1,
      all-zero alleles, name `BX_RESERVED_NNN`).
- [x] **D0.3.** Add sidecar pop-weight buffer. DONE.
      `pop_weights()` returns
      `RwLock<HashMap<u32, ExtPopWeights>>`. Each entry
      is 240 genes x 4 alleles defaulting to weight 1.
      Auto-init via `get_or_init_pop_weights(pop_id)`.
- [x] **D0.4.** Add sidecar horse-genome buffer. DONE.
      `horse_genomes()` returns
      `RwLock<HashMap<u64, ExtHorseGenome>>`. Each entry
      is a flat `Vec<u8>` of length `2 * EXT_GENE_COUNT`
      with the same i / i+EXT_GENE_COUNT diploid layout
      vanilla uses. **Open follow-up:** the stable key
      (currently u64) needs to be wired to a real
      horse_id field once D4.4 finds it.
- [ ] **D0.5.** Heap-redirect helper in `patches.rs`.
      Deferred to D1 (the first reader we patch will
      determine the concrete instruction-rewrite shape).
- [x] **D0.6.** HTTP control-plane ops. DONE. 12 ops
      shipped in `horsey-mod/src/ops.rs`:
      `genes.ext.{count,list,get,set,find,dump}`,
      `pop.ext.{weights.get,weight.set}`,
      `horse.ext.{genome.get,genome.set,alleles.set,
      genome.drop,evaluate}`. Plus
      `genes::evaluate_ext_gene()` mirrors the vanilla
      diploid blend formula for the extended range.

### Phase D1: Static gene table extension

**STATUS: FULL PIPELINE PROVEN IN-GAME 2026-05-14.** All four
detours co-arm cleanly; an authored extended gene
(`BX_TEST_SLOT0` in `genes-extended.xml`) with a render
mapping + a default-allele setting writes the computed value
into the per-horse render buf on EVERY horse render. Visible
effect not yet confirmed because the slot-to-feature map is
unknown (see "Open follow-up" below).

Latest in-game numbers (player walked ~10s after arming with
`BX_TEST_SLOT0` authored at ext_idx 0, slot 0 set mode, default
alleles (3,3) = blend value 200.0):

| Target | Calls | Vanilla path | Ext path | Max idx seen |
|---|---|---|---|---|
| EVAL_DIPLOID_BLEND_A | 2233 | 2233 | 0 | 218 |
| EVAL_DIPLOID_BLEND_B | 2012 | 2012 | 0 | 213 |
| GENE_ALLELE_SWAP | 0 | 0 | 0 | n/a |
| APPLY_GENE_TO_HORSE (D5 post-hook) | 16 | 16 | n/a | n/a |
| Extended gene applications via D5 | n/a | n/a | 16 | n/a |

`max_idx_seen=239` across A+B confirms the full vanilla
[0..240) range is evaluated through our handler.
`genes_applied_total=16` matches `D5.call_count=16` exactly:
every horse render had our gene's blend value applied to its
target slot. **The visuals data path works.**
`ext_call_count=0` on the DI-A side is expected: no vanilla
caller drives idx>=240 in this scenario (the D5 trampoline
writes the buf directly without recursing through eval_a/b).
`allele_swap=0` is expected. It only fires on the rare
allele-renumber event.

#### Confirmed: slot 0 has a major visible effect

Test: `BX_TEST_SLOT0` -> slot 0 set 200.0, default alleles (3,3),
mated two horses, the resulting babies rendered "full screen
width." Slot 0 is **consumer-read** and drives some primary
scale-like parameter. Exact feature TBD; the visible result was
dramatic enough that we cleared the default alleles before
further iteration.

This proves the visuals pipeline writes effects the renderer
honors. It does NOT prove "slot 0 = body width" specifically;
without the slot-to-feature map below we can't assert that.

#### Next phase: systematic vanilla-gene research

Don't guess at slots; map them. From VIABILITY.md Q-render-3:

- 353 total float slots in the render buf
- 258 written by vanilla `FUN_14009f680` (the engine)
- 61 read by vanilla `FUN_1400ab3d0` (the consumer that
  transcribes into the horse struct at `+0x124`, `+0x128`,
  `+0x130`..`+0x154`)
- Only the 61 consumer-read slots produce visible effects

Research plan to derive the map:

1. **Dump vanilla `genes.xml`** from the game's `data/`
   directory. Inventory the 240 vanilla gene names and any
   metadata. Names like `SIZE`, `BONES`, `LEG_LENGTH`,
   `OSTODERM` are the human-readable handles.
2. **Read `FUN_14009f680`'s decomp** (14kB function in
   `horsey-mod/research/decompiled/all_functions.c`). For each of
   the 233 baked literal gene indices in that function,
   identify the buf slot it writes to. Build
   `(gene_idx, gene_name, buf_slot)` triples.
3. **Read `FUN_1400ab3d0`'s decomp** (8kB consumer).
   Enumerate which buf slots it reads
   (`param_2[X]` accesses) and which horse-struct fields
   it writes to (offsets `+0x124`..`+0x154`).
4. **Cross-reference**: for each consumer-read buf slot,
   the chain is "gene X writes to slot N which the
   consumer transcribes to horse-struct field +0xYY which
   the renderer reads as feature Z."
5. **Author the map** as
   `horsey-mod/docs/SLOT-MAP.md`: per-slot row with
   `{ slot, vanilla_gene_name, horse_struct_field,
   visible_feature, candidate_value_range }`.
6. **Validate** by editing one vanilla gene at a time via
   `genes.ext.set` and observing. The proven extension
   path is also a research instrument.

Output: a reliable map from "I want feature X" to "extend
gene G with render slot S, allele payload P0..P3, value
range R." That unblocks the bestiary authoring work in
Phase 2.

Caveat on existing horses: ext alleles are stored
per-horse-pointer with a default fallback. The "giant baby"
horses from the slot-0 test now have alleles 0,0 (cleared
default) but their LIVE render-struct fields will keep the
old computed value until the next gene-evaluation pass for
that horse. Save / reload reliably re-triggers eval.

Strategy DI-A approved 2026-05-14. Locked library:
`retour 0.3`. Lock-free `AtomicPtr<GenericDetour<T>>`
storage published at arm time; handlers do atomics +
acquire-load + indirect call only (no `format!`, no
`parking_lot`, no Rust TLS).

#### Lessons captured (all in DEBUGGING.md)

- **5 distinct "all-ones bad_addr" crash modes:**
  (a) double-deref of a non-pointer slot (`gamestate::ptr`
      was reading the gamestate struct's first 8 bytes as
      a pointer); (b) handler stack frame too big for
      game's nested call chain; (c) parking_lot Mutex
      accessing Rust TLS on a foreign game thread;
      (d) detour target was not a function entry;
      (e) Ghidra's pyghidra indexes function entries
      OFF-BY-16 (the real entry is at `ghidra_addr - 16`,
      where the MSVC register-save prologue lives).
- **Handler discipline rules** in
  [`DEBUGGING.md`](DEBUGGING.md) §4b. Every new handler
  must observe them. Reference impl: `eval_a_handler`.
- **Pre-arm prologue verification rule** in
  [`DEBUGGING.md`](DEBUGGING.md) §5: every new detour
  must have its prologue eyeballed against Win64
  function-entry patterns before arming. The two
  recognized shapes are documented.
- **Ghidra-off-by-16 was the dominant blocker.** It made
  EVAL_A/B appear to work and APPLY_GENE_TO_HORSE /
  ALLELE_SWAP crash, looking like a build-update issue
  for hours. The actual decomp pass against the current
  binary returned identical addresses; we just trusted
  Ghidra's entry-point attribution too much.

#### Immediate plan (next session)

1. Author one test extended gene in `genes-extended.xml`
   with a `<render slot="..." mode="add"/>` mapping;
   set a horse's extended alleles via HTTP
   (`horse.ext.alleles.set`); observe `genes_applied_total`
   climb on `genes.ext.render.stats`; verify the visible
   render effect in-game. **This is the v1 finish line.**
2. Implement Phase R1 from
   [`ADDRESS-RESOLUTION.md`](ADDRESS-RESOLUTION.md): image
   SHA-256 logging + `game.build_info` op, so future game
   updates show up loudly in the log.
3. Implement Phase R2 (patternsleuth runtime resolution)
   so future address drift gets resolved automatically
   without needing manual address bumps.
4. D1.3 (`GENE_DEATH_DRIFT`) and D1.8 (`CRISPR_LAB`) remain
   deferred: D1.3 needs a mid-function patch, D1.8 needs
   state-machine analysis. Not blocking v1.

Wired and arming via `genes.ext.arm` HTTP op:

- [x] **D1.1.** `EVAL_DIPLOID_BLEND_A` (FUN_1400a5d20).
      Signature: `unsafe extern "system" fn(*const u8, i32) -> f32`.
      Handler: idx<240 -> trampoline; idx>=240 ->
      `genes::evaluate_ext_gene(genome_ptr as u64, idx-240)`.
- [x] **D1.2.** `EVAL_DIPLOID_BLEND_B` (FUN_1400a5e00).
      Signature: returns `u32` (bit pattern is f32). Same
      dispatch as D1.1 but `.to_bits()` on the extended
      result so the caller's bit-cast still works.
- [x] **D1.4.** `GENE_ALLELE_SWAP` (FUN_1400c03a0).
      Signature: `(usize, i32, i32, i32) -> void`. Handler:
      idx<240 -> trampoline; idx>=240 ->
      `genes::swap_ext_alleles(idx-240, a, b)` which swaps
      the payload positions in `EXT_GENE_TABLE` AND every
      `EXT_POP_WEIGHTS` entry. Skips vanilla entirely for
      extended indices (vanilla would walk DAT_1403ee4b0
      with an out-of-range index and crash).

Deferred (not entry-point clean):

- [ ] **D1.3.** `GENE_DEATH_DRIFT` (FUN_1400c0660). The
      gene index is computed mid-function (~line :730 in
      decomp), not passed as a parameter. Needs a
      mid-function patch via `patch_bytes`, not an
      entry-point detour. Defer until we have a worked
      example of the +/-5 mutation site address.
- [ ] **D1.8.** `CRISPR_LAB` UI gene dispatch
      (FUN_1400c1cf0). Internal state machine, 5311 bytes.
      Need to map which states read which gene-indexed
      data before we know where to splice. Could be
      multiple sub-detours or a single mid-function patch.
      Defer until DI-A-3 ships and we have in-game UX
      validation of the existing 3 detours.

If profiling shows the per-call overhead of D1.1/D1.2
matters (they're hot, called per-horse-per-frame),
revisit DI-B (heap redirect) as a perf optimization for
THOSE TWO only. Other detours stay as DI-A.

Make the engine's 240-slot gene table behave as if it
has N slots, where slots 0..239 are vanilla
`DAT_1403ee4a4` and slots 240..N-1 live in our heap
buffer.

**Concrete decision: detour-and-dispatch, not heap
redirect.** The 7 readers do `(&DAT_1403ee4a4)[i*8]`
which the compiler turned into `lea reg, [DAT...]; mov reg, [reg + i*32]`.
Patching every reader to dereference through a pointer
variable is invasive (changes instruction sizes).
Instead we hook each reader at function entry via
detour, check the gene index, and dispatch to vanilla
or our buffer.

For functions that take the gene index as a parameter
(the 4 evaluators / mutators):

- [ ] **D1.1.** Detour `FUN_1400a5d20` (allele evaluator
      formula 1). At entry, if `param_2 >= 240`:
      compute the same blend formula against
      `EXT_GENE_TABLE[param_2 - 240]` and the
      per-horse extended genome at
      `EXT_HORSE_GENOMES[horse_id][param_2 - 240]` and
      `[..][param_2 - 240 + 240]`. Return that value.
      Else fall through to vanilla.
- [ ] **D1.2.** Detour `FUN_1400a5e00` (allele evaluator
      formula 2). Same structure as D1.1 but with the
      formula-2 math.
- [ ] **D1.3.** Detour `FUN_1400c0660:730` (death
      handler ±5 mutator). Inspect the index variable;
      if >= 240, mutate `EXT_GENE_TABLE[index - 240]`
      instead. Probably easier to just patch the
      specific ADD/SUB instructions to also branch on
      index range.
- [ ] **D1.4.** Detour `FUN_1400c03a0` (allele renumber
      sync). When called with gene index >= 240, swap
      values in `EXT_GENE_TABLE` and the extended pop
      weights, NOT vanilla.

For functions that iterate the whole table (the loops
at `0xf0`):

- [ ] **D1.5.** Patch `FUN_1400a3eb0:156` loop bound
      `0xf0` -> `N`. The default-init loop now writes
      defaults for ALL N slots. Wait. This loop writes
      to `&DAT_1403ee4a4 + i*32`, which is the static
      table only sized for 240. If we extend the loop
      bound, vanilla writes overflow into adjacent
      `.data`. Two options:
      - (a) Patch the loop body too to detour writes
        for `i >= 240` into `EXT_GENE_TABLE`.
      - (b) Leave the loop bound at 240; init
        `EXT_GENE_TABLE` separately at attach.
      Option (b) is cleaner and matches the design
      principle. **Choose (b).**
- [ ] **D1.6.** Patch `FUN_1400a3eb0:984` loop bound
      similarly. This is the per-XML-write loop. For
      each `<gene name="X">` in genes.xml, it looks up
      X by name in the chromomap. If we extend genes.xml
      with our own genes (or use a sidecar
      `genes-extended.xml`), the loader needs to
      populate `EXT_GENE_TABLE` for those. Two options:
      - (a) Inject our extended genes into the same
        chromomap so the vanilla loader handles them.
      - (b) Run a separate loader on attach that reads
        a sidecar XML and populates `EXT_GENE_TABLE`.
      Option (b) is cleaner. **Choose (b).** Loop bound
      stays at vanilla 0xf0.
- [ ] **D1.7.** Patch `FUN_1400a4880:298` (XML serializer
      loop). Same decision: leave vanilla bound, run our
      own serializer for `EXT_GENE_TABLE` to write a
      sidecar XML. Loop bound stays.
- [ ] **D1.8.** Detour `FUN_1400c1cf0` (CRISPR UI). When
      the player selects a gene index >= 240, read from
      `EXT_GENE_TABLE`. Optional in v1; can defer if
      CRISPR UI doesn't need to expose extended genes.

**Net for D1:** 4 detours (D1.1-D1.4), 0 loop-bound
patches (we use sidecar loaders / serializers), 1
optional UI detour (D1.8).

### Phase D2: Per-pop weight extension

Pop records currently hold 240 genes x 4 alleles = 3840
bytes of weights at offset +0x28. Extending to N genes
means each pop needs more weight space.

**Strategy:** leave vanilla pop record layout alone
(don't touch the 0x1018 stride). Store extended weights
in `EXT_POP_WEIGHTS[pop_id]`.

- [ ] **D2.1.** When `FUN_1400a5ee0` (pop processor)
      runs and writes to a pop record, also create an
      `EXT_POP_WEIGHTS[pop_id]` entry initialized from
      the parent's extended weights (the inherit-then-
      override pattern, mirrored for our extended
      data). Detour the function entry.
- [ ] **D2.2.** When parsing the sidecar
      `pop-extended.xml` (introduced in D1.6 (b)), look
      up the named pop's `pop_id` (vanilla side) and
      apply per-gene weight overrides into
      `EXT_POP_WEIGHTS[pop_id]`.
- [ ] **D2.3.** When the spawn function picks alleles
      for a new horse (need to find this function;
      probably `FUN_1400c0660` neighbors), detour to
      ALSO pick alleles for genes 240..N-1 using the
      pop's extended weights. Write the picks to
      `EXT_HORSE_GENOMES[horse_id]`.
- [ ] **D2.4.** Hook `FUN_1400c03a0` (the allele
      renumber sync) for genes >= 240. Sync the swap
      across all `EXT_POP_WEIGHTS` entries.

### Phase D3: Per-horse genome extension

Each horse gets a parallel 480-byte buffer in
`EXT_HORSE_GENOMES[horse_id]` for the extended genes'
diploid alleles.

- [ ] **D3.1.** Detour `FUN_14005cf70` and
      `FUN_14005d190` (genome alloc functions). When
      they create a new 480-byte block, also create
      an `EXT_HORSE_GENOMES[horse_id]` entry.
- [ ] **D3.2.** Detour `FUN_14005cd00` (genome free).
      When vanilla frees a horse's 480-byte block,
      also drop the matching `EXT_HORSE_GENOMES`
      entry.
- [ ] **D3.3.** Detour `FUN_14005d190` (the
      parent-to-child copy). Mirror the copy: when
      vanilla copies parent_h's 480-byte vanilla
      genome to child_h, ALSO copy
      `EXT_HORSE_GENOMES[parent_h]` to
      `EXT_HORSE_GENOMES[child_h]`.
- [ ] **D3.4.** Find and detour the breeding combinator
      (the function that picks one allele from each
      parent for the child). Currently un-located; see
      `ALLELE-MODEL.md` open question. Mirror its logic
      for the extended genes.

### Phase D4: Save format extension

Per the "layer on top" design principle: vanilla save
file stays untouched. Our extended state lives in a
sidecar `save<N>.dat.ext` next to the vanilla save.

- [ ] **D4.1.** Hook the save-write completion path.
      After `FUN_14006dc80` finishes writing
      `save<N>.dat`, write `save<N>.dat.ext` containing:
      - `EXT_GENE_TABLE` (full N-240 record dump)
      - `EXT_POP_WEIGHTS` (one entry per pop_id, only
        non-default weights)
      - `EXT_HORSE_GENOMES` (one 480-byte entry per
        live horse, keyed by stable horse_id)
- [ ] **D4.2.** Hook the save-read completion path.
      After vanilla finishes loading `save<N>.dat`,
      look for `save<N>.dat.ext`. If present, populate
      our sidecar buffers from it. If absent, leave
      sidecars at defaults (modded-aware game running
      a vanilla save degrades gracefully).
- [ ] **D4.3.** Pick a sidecar file format: simple
      length-prefixed binary, or a JSON / TOML doc.
      Binary is faster and matches vanilla style;
      JSON is debuggable. Recommend a simple binary
      with magic bytes "BXSAVEEXT" + version u32 +
      payload sections.
- [ ] **D4.4.** Determine the stable horse_id field.
      Inspect the horse struct around the offsets
      we already know (0x70, 0x78). The save header's
      "next horse ID" hint suggests an int32 ID is
      assigned at creation. Find it; that's our key.

### Phase D5: Gene-effect engine extension (trampoline)

**Strategy locked 2026-05-14: S2 from
[`HOOKING-STRATEGY.md`](HOOKING-STRATEGY.md).** One
post-hook trampoline on `FUN_14009f680` via
`retour::GenericDetour`. Senior eng approved; second-best
(S1, per-callsite detour at the 6 call pairs) explicitly
rejected for the reasons in
[`HOOKING-STRATEGY.md`](HOOKING-STRATEGY.md) §5. Library:
`retour = "0.3"` (Rust port of MS Detours, used in shipped
Rust mods for Diablo 2, SAMP, Zoo Tycoon, Garry's Mod,
Guild Wars 2).

Net for D5: 1 patch site (the entry of `FUN_14009f680`),
1 Rust handler, 1 sidecar module (`render_trampoline.rs`).

- [x] **D5.0.** DONE. `retour = "0.3"` added to workspace
      `Cargo.toml` and `horsey-mod/Cargo.toml`. Build picks
      up retour 0.3.1 + transitive deps (libudis86,
      mmap-fixed-fixed, slice-pool2, winapi). Compiles
      clean.
- [x] **D5.1.** DONE.
      `horsey-mod/src/patches/render_trampoline.rs` shipped.
      Holds `GenericDetour<unsafe extern "system" fn(*mut f32, *mut c_void)>`
      in a `OnceLock<Mutex<Option<...>>>`, with the same
      arm / revert / dryrun shape as ext_genes. Targets
      `fn_addr::APPLY_GENE_TO_HORSE` (0x14009f680).
- [x] **D5.2.** DONE. Post-hook handler implemented:
      runs trampoline first, computes
      `horse_ptr = ctx - HORSE_CTX_OFFSET (0x2b8)`, then
      calls `genes::apply_render_to_buf(buf, 353, horse_id)`.
      The helper acquires `gene_table().read()` and
      `horse_genomes().read()` ONCE per call (single lock
      acquisition for the whole gene walk, not per gene).
      Bounds-checks every slot write against the 353-float
      buffer.
- [x] **D5.3.** DONE in D7.2. `RenderMapping` parsed from
      `<render slot mode>` and stored in `ExtGene.render`.
      The D5.2 handler consumes it.
- [x] **D5.4.** DONE. HTTP ops shipped:
      `genes.ext.render.dryrun` (address + prologue),
      `genes.ext.render.arm` (install detour),
      `genes.ext.render.disarm` (revert),
      `genes.ext.render.stats` (`call_count` +
      `genes_applied_total`).
- [x] **D5.5.** DONE. `patches::revert_all` now calls
      `render_trampoline::revert()` BEFORE
      `ext_genes::revert()` (LIFO order: D5 was the most
      recently installed). DLL detach restores all prologues.
- [x] **D5.6.** DONE. `call_count` (every invocation of
      `FUN_14009f680` after arming) and `genes_applied_total`
      (sum of extended-gene render applications across all
      calls) surfaced via `genes.ext.render.stats`. The
      "buf bytes modified" counter from the original plan
      is the same number as genes_applied_total (one slot
      per applied gene), so it's not separately tracked.
- [ ] **D5.7.** Open. Horse-pointer-as-key works for a
      session; save/load needs D4.4 (stable horse-id field).
      Documented limitation; not blocking visual verification.
- [ ] **D5.8.** Re-entrancy audit deferred until D5
      validates in-game. The current design uses only
      `RwLock::read()` inside the post-hook handler;
      `genes.ext.reload` (which takes write) is operator-
      triggered, not vanilla-triggered, so re-entrancy
      from inside the engine is impossible. Lock-ordering
      audit can wait until concurrent stress shows up.

**D5.4 in the original plan is DROPPED from v1 scope.**
The "post-consumer trampoline writing to new horse struct
fields" was meant for visual modes the consumer doesn't
read (slots outside the 61 consumer-read set). Postpone:
if v1 authoring hits a wall on "this effect needs a slot
the consumer doesn't see," reopen as a sibling phase. We
have 61 consumer-read slots and roughly 10 v1 genes; the
pigeonhole says we won't hit the wall in v1.

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
      in [`ALLELE-MODEL.md`](ALLELE-MODEL.md) once
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

- [ ] **D9.1.** Update `ALLELE-MODEL.md` to document
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
| The breeding combinator function is unfound (ALLELE-MODEL.md open question). Without it, child horses get default-zero extended alleles. | Phase D3.4. Locate before D3 starts. If we cannot find it, hook the genome alloc path to populate extended alleles from parent picks at horse-creation time. |
| `FUN_1400a5d20`'s detour may be hot enough that the per-call branch costs measurable frame time. | Profile in D8.5. If it's a problem, JIT-patch the detour to skip vanilla frames where no extended genes are defined. |
| Stable horse_id field not located. | Phase D4.4. Without it, we can't key `EXT_HORSE_GENOMES`. Find this BEFORE D3 since D3 needs it. |
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

### Hotkey-driven actions (CRITICAL for ease-of-use)

Repetitive clicking is the second-biggest tedium source after fatigue/aging.
Implement modifier-click + keyboard hotkeys for common actions.

| Hotkey | Action |
|---|---|
| `Shift+Click` (on horse) | Transfer the horse to truck / corral / current location |
| `Ctrl+Click` (on horse) | Toggle "favorite" (excludes from retire/sell candidates) |
| `Alt+Click` (on horse) | Show full stats panel |
| `Shift+Click` (on item) | Auto-buy 10 (or the bulk-buy default) |
| `Shift+Click` (on horse in roster) | Quick-feed (uses inventory hay) |
| `R` | Race the currently-selected horse |
| `F` | Feed all hungry horses (drains hay from inventory) |
| `S` | Sleep all tired horses |
| `B` | Open breeding menu with currently-selected horse pre-filled |
| `T` | Open transfer menu |
| `Esc+1..9` | Quick-switch player slots / save slots |
| `Numpad +` / `Numpad -` | Increase / decrease sim speed |

**Why this matters**: vanilla forces you to click-by-click on every horse
for every action. Bulk hotkeys turn tedious chores into one keypress.

**Implementation path**: requires DLL injection (Tier 3+ from
`ENGINE-EXTENSION.md`) because the input handler is in `Horsey.exe`. The
DLL hooks SDL input events and short-circuits them to game actions before
the engine sees the raw click.

Probably easiest as a `horsey-mod` mod once that foundation exists (see
[`MODFORGE-INTEGRATION.md`](MODFORGE-INTEGRATION.md)).

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
Front-end is either:
- ImGui overlay (DX12-hook integration; significant work)
- **Web UI** served from `modforge::server` (much faster path; user
  has it open in a side browser window)

The web UI is the right first cut. ~200 lines of HTML/JS pulling from
our existing HTTP control plane.

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
| Roster panel | Existing `horses.*` ops | Web UI page (HTML + JS) |
| Status badges | Hook status-bubble render | none (badge always-on) |
| Hotkey cycling | SDL input hook | none |
| Count display | Hook overlap detection | rendered via render hook |
| Breeding picker | New `breed.preview` op | Web UI page |
| Auto-feed | New `auto_feed` toggle setting | none (runs automatically) |
| Group ops | New `horses.bulk_*` ops | Web UI page |

The web-UI approach is the unblocker: don't try to inject UI into the
SDL3 renderer right away. Use `modforge::server`'s HTTP plane plus a
single-page HTML app served from our DLL. The user keeps a Chrome tab
open on `http://localhost:33077/ui` with all the management features.
The IN-GAME view (auto-spread, status badges, count display) is the
in-game-rendered subset; the heavy UI lives in the browser.

This split is also how serious modders ship overlays in 2026: the
external-tool-via-localhost pattern is friction-free vs. embedding a
full UI library into the game's render path.

---

## Mod foundations

### 1. `horsey-mod` crate (per-engine binding for modforge) **SHIPPED**

Status: **working**. Lives in [`abix-/Grounded2Mods`](https://github.com/abix-/Grounded2Mods)
as a third sibling to `ueforge` and `unityforge`. Pivoted from the originally-planned
proxy-`steam_api64.dll` approach to a `CreateRemoteThread(LoadLibraryW)` injector
after MSVC link.exe's `.DEF` forwarder syntax failed for 1,089 Steam API exports.

What's done:
- `horsey-inject.exe` finds Horsey.exe and injects `horsey.dll`
- DllMain spawns a worker thread that initializes modforge logging, settings,
  HTTP server with auth
- 18 ops registered for read/write of game state + cheats + horse fields
- Staged-DLL pattern: each inject copies the cargo output to a fresh
  timestamped filename so cargo can rebuild while the game is running
- `_shutdown` op + `--reload` flag implement the hot-reload swap
- `no_tire = true` set at every DLL attach

What's pending:
- **Hot-reload hardening** (currently causes delayed crash). The `_shutdown`
  op acknowledges, the listener thread joins, but helper threads inside
  the old DLL may still have stack frames when `FreeLibrary` is called.
  Options under consideration:
  - Poll port 33077 in injector after `_shutdown` until truly closed, then
    wait another ~500ms before `FreeLibrary`
  - Have `_shutdown` itself call `FreeLibraryAndExitThread` from the last
    remaining thread (atomic self-unload)
  - Add a `_drain` op that returns only after all helper threads have exited
- MinHook integration (zero progress; foundational for everything else)
- `horses.live` walks the wrong list (track-manager's on-track horses, not the
  full roster). Need to find the right list pointer for the roster UI.

### 2. HTTP control plane **SHIPPED**

`modforge::server::spawn` is used directly. The 18 registered ops are in
`horsey-mod/src/ops.rs`. Auth is in `X-Ueforge-Auth` header; token is
written to `horsey.auth` next to the DLL on each launch.

Currently registered ops:
- Liveness: `ping`, `list_ops`
- State reads: `game.read`, `game.money.get`, `game.year.get`, `cheats.*`
- State writes: `game.money.set`, `game.money.add`, `game.year.set`,
  `cheats.no_tire.set`, `cheats.debug_mode.set`
- Horses: `horses.count`, `horses.roster_addr`, `horses.live`, `horse.read`,
  `horse.set_age`, `horse.set_max_age`, `horse.clear_tiredness`
- Hot reload: `_shutdown`

To add:
- `horses.list_full` walking the full roster (not just on-track)
- `save.export` / `save.import` for save backup ops
- `pop.spawn` and `pop.list` for population creation
- `genes.read` / `genes.write` for runtime gene editing (when MinHook lands)

### 3. Save-edit tool (in-progress, see `save_edit.py`)

Extend `save_edit.py` with set/write operations now that we have the full
save format documented in
`decompiled/annotated/0x14006dc80_save_game_writer.c`.

### 4. RPG layer for Horsey

Use modforge's RPG module (Effect/Trigger/Skill + XP curve + persistence).
First skills:
- "Stable Master" - reduces fatigue accumulation rate
- "Veterinarian" - increases lifespan
- "Breeder" - boosts litter sizes
- "Trainer" - boosts race speed
- "Geneticist" - unlocks faster CRISPR

Map each skill to a `StandardEffect` variant that adjusts the appropriate
horse-struct field or hooks the appropriate game function.

### 5. Hotkey system

After `horsey-mod` gets MinHook + SDL3 input hook, add a `hotkeys` module
that:
- Hooks SDL's keyboard/mouse input handlers in Horsey.exe
- Translates modifier+click into game actions
- Persists key bindings via modforge's settings system
- Live-reload bindings via `--reload` once hot-reload is hardened

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

### Social / herd mechanics

- Per-horse personality affects breeding compatibility.
- "Friends" / "rivals" relationships.
- Herd hierarchies (alpha / beta / etc.) affecting race outcomes.

### Procedural events

- Weekly random events: "An inspector arrives", "A storm damages fences",
  "A rival breeder challenges you".
- Injected into the daily-event scheduler (we annotated this at
  `0x14002fe00`).

### Multi-currency economy

- Add "research points", "fame", "favor" as separate currencies.
- Each tied to specific activities.
- Stored in horsey-mod sidecar state.

### Weather + seasons

- Per-day weather state.
- Affects horse hunger drain, breeding success, race times.
- Visible via a UI overlay.

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
