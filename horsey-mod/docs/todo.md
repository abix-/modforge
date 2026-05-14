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
