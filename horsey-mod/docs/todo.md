# horsey-mod TODO

> **Scope:** authoritative on open work for the `horsey-mod`
> crate (native-PE binding for Horsey Game) AND for any
> Horsey-Game content mods that ship alongside it.
>
> Research / decomp tracking lives in
> [`../../horseygame/TODO.md`](../../horseygame/TODO.md).
> Workspace-wide framework work lives in
> [`../../docs/todo.md`](../../docs/todo.md).

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
[`horseygame/decompiled/funcs/1400c/1400ceb60_FUN_1400ceb60.c:612`](../../horseygame/decompiled/funcs/1400c/1400ceb60_FUN_1400ceb60.c)):
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
[`horseygame/CONTENT-CREATION.md:515`](../../horseygame/CONTENT-CREATION.md#12-reference-vanilla-populations)):
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

- [ ] **Q-pop-1.** Does the engine accept arbitrary new pop
      NAMES, or is the pop set bounded? Read the `pop.xml`
      loader (likely near `FUN_1400a3eb0`'s call site or
      a sibling `load_pop_xml`).
- [ ] **Q-pop-2.** What does a spawner do with a pop name
      it doesn't recognize? Silent fallback to `default`,
      log + skip, or hard-crash?
- [ ] **Q-pop-3.** Are pops stored in a fixed-size table
      (like genes) or a hashmap/vector? Find the in-memory
      data structure.
- [ ] **Q-pop-4.** Inheritance semantics: does a child pop
      override only the genes it names, or does it reset
      everything? Determines authoring strategy.

#### Gene system (the table extension question)

- [ ] **Q-gene-1.** Map every reader of `DAT_1403ee4a4`
      (the 240-slot gene table at
      [`horseygame/decompiled/annotated/0x1400a3eb0_load_genes_xml.c`](../../horseygame/decompiled/annotated/0x1400a3eb0_load_genes_xml.c)).
      Use Ghidra cross-refs. Document each access pattern
      (record copy, indexed read, offset arithmetic).
- [ ] **Q-gene-2.** Find every literal `0xf0` (240) and
      `0x1e00` (7680 = 240*32) in code. Each is a candidate
      loop bound or allocation size that must be patched
      to extend the table.
- [ ] **Q-gene-3.** For every gene-by-INDEX consumer
      (rendering, breeding, scoring, save, load),
      classify as:
      - (a) name-lookup-via-chromomap (safe to extend), or
      - (b) literal-index-baked-into-code (each one is a
        separate patch site).
      Count (b)s. If the count is small (single digits),
      patching them is normal. If huge, the strategy
      changes.
- [ ] **Q-gene-4.** Decide table-extension strategy
      candidates:
      - in-place: keep `DAT_1403ee4a4` as base, grow the
        static allocation if possible (likely impossible;
        confirm).
      - heap redirect: patch every reader to dereference
        through a pointer we own. Big patch surface,
        unbounded cap.
      - fixed expand: pick a new cap (e.g. 512), allocate
        once, patch loop bounds, leave readers alone.
        Small patch surface, bounded.
- [ ] **Q-gene-5.** How many of the 242 vanilla genes are
      unused or under-used? Triggered by Q-gene-3 finding
      that gene effects are baked in `FUN_14009f680` by
      literal index. If we can find vanilla genes that
      `FUN_14009f680` references but no `pop.xml` entry
      drives, we can repurpose them in our trampoline
      WITHOUT extending the table at all. Method:
      cross-reference `FUN_14009f680`'s 219 referenced
      indices against vanilla `pop.xml` to find genes
      that exist in the engine but no pop authors.

#### Save / load (compat question)

- [ ] **Q-save-1.** How are per-horse gene allele values
      stored? By gene index, by gene name, length-prefixed
      array? See
      [`horseygame/SAVE-FORMAT.md`](../../horseygame/SAVE-FORMAT.md).
- [ ] **Q-save-2.** Is the per-horse allele array sized by
      a literal (240) anywhere in save / load? If yes,
      extending the table breaks save compat unless we
      patch save / load too.
- [ ] **Q-save-3.** Decide: do we accept save-incompat for
      modded saves, or do we patch save / load to write a
      backwards-compatible extended record?

#### Renderer / behavior (gene-effect question)

- [ ] **Q-render-1.** For each "new visual mode" we want
      (wings, wheels, transparency, faceted body, etc.),
      figure out:
      - does any vanilla pop already exhibit it (e.g.
        `car` for wheels)? If yes, what gene drives it?
      - if no vanilla equivalent, what gene-handler code
        would we have to write or patch to make it work?
- [ ] **Q-render-2.** For each existing gene, document
      what it actually controls (the gene NAMES are
      suggestive but not always literal). Cross-reference
      against the renderer code.
- [ ] **Q-render-3.** Is the renderer driven by a
      gene-handler dispatch table we can extend, or is
      every gene's behavior hardcoded by index in the
      render loop?

#### Hot reload (iteration speed question)

- [ ] **Q-reload-1.** Can `pop.xml` and `genes.xml` be
      reparsed in-process without restarting the game?
      If yes, the iteration loop becomes 5 seconds
      instead of 30.
- [ ] **Q-reload-2.** Can we ship the Gene Editor HTTP ops
      (live `pop.gene.set`) before any species are
      authored, so authoring happens against a live
      target?

#### Phase 0 exit criteria

Phase 0 is complete when `VIABILITY.md` answers every Q
above with a file:line cite or a reasoned "unanswerable
without runtime experiment." At that point, Phase 1
(decisions) opens with full context.

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
      [`MODFORGE-INTEGRATION.md`](../../horseygame/MODFORGE-INTEGRATION.md)
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

- [ ] **D0.1.** Decide N (target gene count). Default
      480 (exactly double). Could go higher (512, 1024)
      with no extra patch sites; the cost is just bigger
      heap buffers. Document the chosen N in a constant
      `EXT_GENE_COUNT` at the top of
      `horsey-mod/src/genes.rs`.
- [ ] **D0.2.** Add a sidecar gene-table buffer to
      `horsey-mod`. `static EXT_GENE_TABLE: Mutex<Vec<GeneRecord>>`
      where `GeneRecord` matches the vanilla 32-byte
      layout. Initialize on attach with default values
      (m=100, s=1, all-zero alleles).
- [ ] **D0.3.** Add a sidecar pop-weight buffer.
      `static EXT_POP_WEIGHTS: Mutex<HashMap<u32, ExtPopRecord>>`
      where `ExtPopRecord` holds the extended 240
      genes' per-allele weights (240 * 4 * 4 = 3840
      bytes per pop). Keyed by vanilla pop_id.
- [ ] **D0.4.** Add a sidecar horse-genome buffer.
      `static EXT_HORSE_GENOMES: Mutex<HashMap<u64, [u8; 480]>>`
      keyed by some stable horse identifier. Need to
      determine the right key first: a horse's roster
      index can change between saves; the stable key is
      probably the int32 ID assigned at creation
      (stored in the horse struct, exact offset TBD).
- [ ] **D0.5.** Extend `horsey-mod/src/patches.rs` with
      a helper for the heap-redirect pattern: given a
      static address that vanilla code reads via a
      RIP-relative `lea`, patch the instruction to
      either (a) load from a different fixed address,
      or (b) detour through our trampoline. Concrete
      shape TBD by the disassembly of the first reader
      we patch.
- [ ] **D0.6.** Extend the existing HTTP control plane
      with `genes.ext.list`, `genes.ext.add`,
      `genes.ext.set`, `pop.ext.weight.set`, and
      `horse.ext.genome.{get,set}` ops. These are how
      we'll iterate on extended-gene definitions
      without rebuilding.

### Phase D1: Static gene table extension

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

Per Q-render-3 in
[`VIABILITY.md`](VIABILITY.md): hook the 4 caller sites
that follow the
`FUN_14009f680(buf, ...) -> FUN_1400ab3d0(horse, buf)`
pattern. After vanilla populates the temp buffer, our
trampoline modifies / extends it before
`FUN_1400ab3d0` consumes it.

- [ ] **D5.1.** Detour each of the 4 caller sites at
      the boundary between `FUN_14009f680` and
      `FUN_1400ab3d0`. Insert our trampoline between
      the two calls.
- [ ] **D5.2.** In the trampoline:
      - Identify which horse this call is for (read
        from caller's frame or from `FUN_14009f680`'s
        param_2 = `horse + 0x2b8`, back-compute the
        horse pointer).
      - Look up `EXT_HORSE_GENOMES[horse_id]` for the
        extended diploid alleles.
      - For each extended gene 240..N-1, evaluate the
        diploid blend (mirror `FUN_1400a5d20`'s logic)
        against `EXT_GENE_TABLE[gene_idx - 240]`.
      - For each extended gene, look up its
        "render output mapping" (which `param_1[X]`
        slot it should ADD to or OVERRIDE).
      - Write to those slots.
- [ ] **D5.3.** Define the render-output mapping.
      Each extended gene needs to know which existing
      `param_1[X]` slot it modifies. e.g.
      `BX_WING_SIZE` might add to whatever slot
      controls limb extents. This mapping is per-gene
      metadata, authored alongside the gene itself in
      `genes-extended.xml`:
      ```xml
      <gene name="BX_WING_SIZE" m="100" s="1"
            g0="0" g1="20" g2="50" g3="100"
            extends="param_1[0x42]" mode="add" />
      ```
- [ ] **D5.4.** For genuinely new visual modes that
      don't map to any existing `param_1[X]`, register
      them as "post-consumer hooks" instead. These run
      after `FUN_1400ab3d0` and write to NEW horse
      struct fields at offsets vanilla doesn't use.
      Requires identifying free offsets in the horse
      struct (open question, deferred to D5 work
      itself). Optional in v1.

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
- [ ] **D7.2.** Implement `genes.ext.reload` for our
      sidecar genes file. Easy: just re-parse and
      replace `EXT_GENE_TABLE`.
- [ ] **D7.3.** Add a `genes.dump` HTTP op that
      returns the full gene table state (vanilla 240 +
      our extended N-240) as JSON. Useful for sanity
      checks during dev.
- [ ] **D7.4.** Add a `horse.dump` HTTP op that
      returns one horse's full state (vanilla genome +
      our extended genome + computed render param
      array). Useful for verifying the trampoline did
      what we expected.

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
[`horseygame/TODO.md`](../../horseygame/TODO.md) for the
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
