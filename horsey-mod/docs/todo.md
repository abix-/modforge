# horsey-mod TODO

> **Major prior art (2026-05-15):** [NickPetrone/HorseyLiveTweaks](https://github.com/NickPetrone/HorseyLiveTweaks) by Nick Petrone (Twisternick) is an independent Horsey Game modding framework with ~4500 lines of C++, in-game ImGui UI, and pattern-scan address resolution. Cross-validates our `horse+0x2b8` working-genome model and our `FUN_1400b3070` regen function. **Different scope** (they tweak the vanilla 240; we extend to 480). Full credit + comparison in [`PRIOR-ART-HorseyLiveTweaks.md`](PRIOR-ART-HorseyLiveTweaks.md). Their pattern-scan approach is the reference we should port for our R1/R2 address-resolution work.


> **Authoritative on:** open work and feature wishlist for the `horsey-mod` crate (native-PE binding for Horsey Game) AND for Horsey-Game content mods shipping alongside it. Workspace-wide framework work lives in [`../../docs/todo.md`](../../docs/todo.md).

Roughly ordered by leverage.

---

## Current status (2026-05-15, after commit `352daed`)

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

### Engineering rule (locked 2026-05-15): TESTS FIRST

Every new feature, patch, or research finding ships as a test first. The test asserts the contract before the implementation exists. We confirm the test fails, write the code until the test passes, then commit both together.

This applies to:
- New detours / patches: a test asserting prologue bytes + post-arm `call_count > 0`.
- New genome math: unit tests covering the algorithm against hand-checked values.
- New HTTP ops: a test asserting wire shape + behavior.
- Research findings (e.g. "this offset is the genome"): a test that reads from that offset and asserts it matches the known-good value from a save.

No exceptions. Code that ships without a covering test is not finished.

### Test harness status (2026-05-15)

`modforge::harness` shipped today. Generic Steam-game launch + inject + HTTP-probe + taskkill loop. Modules:

- `modforge/src/harness/mod.rs`. `GameSpec`, `HttpProbe`, `InjectorSpec`, `BuildSpec`
- `modforge/src/harness/harness.rs`. `GameHarness::launch` / `attach_existing`, `RunningGame` with Drop taskkill
- `modforge/src/harness/build.rs`. Wraps `cargo build -p <pkg>`
- `modforge/src/harness/steam.rs`. `steam.exe -applaunch <id>` with `steam://rungameid` fallback
- `modforge/src/harness/process.rs`. `tasklist`/`taskkill` helpers
- `modforge/src/harness/injector.rs`. Runs the per-game injector exe
- `modforge/src/harness/http_probe.rs`. POST to `<endpoint>/<op>`, poll-until-ready

Per-game wiring shipped:

- `horsey-mod/tests/common/mod.rs`. `GameSpec` for Horsey (AppID 3602570, `Horsey.exe`, port 33077, `/op` endpoint), passes `--fresh` to injector so stale state doesn't block.
- `horsey-mod/tests/smoke.rs`. First test, asserts `ping` succeeds end-to-end.

Env vars honored: `MODFORGE_NO_GAME=1` skips live launch; `MODFORGE_SKIP_BUILD=1` skips `cargo build`; `MODFORGE_STEAM_EXE` overrides Steam path.

### First test runs (2026-05-15)

#### Iteration 1: failed at stale injector state

Loop reached the injector step but failed at horsey-inject's stale-state guard (it saw the prior manual injection's `.injstate` file and refused). Fix: pass `--fresh` from the test wiring.

Lesson: injector binaries that maintain on-disk hot-reload state need a per-test clean-slate flag.

#### Iteration 2: HTTP probe URL was wrong

After the inject fix, the probe hung on HTTP wait. Root cause: probe was POSTing to `<endpoint>/<op>` (e.g. `/op/ping`) but `modforge::server` accepts POST only at the literal `endpoint` URL (`/op`) with `{"op": "<name>", "args": {...}}` in the BODY. Fix: rewrote `harness::http_probe` to use envelope shape.

Lesson: the test harness is the right place to encode the wire shape. Tests should never hand-build URLs.

#### Iteration 3: SMOKE PASSES end-to-end

`cargo test -p horsey-mod --test smoke -- --test-threads=1 --nocapture` -> **7.1s total**, ping returns ok, taskkill on Drop:

```
kill old Horsey       120ms
Steam launch          3.3s
horsey-inject --fresh 500ms
HTTP ping             ~1ms
teardown grace        3s
```

Test log written to `target/test-runs/smoke_ping_returns_ok-<ts>.log` with every step timestamped + flushed per-line.

#### Iteration 5: pattern-scan primitive (R1) ships in modforge

Test-first workflow drove `modforge::patterns`. Failing test
`horsey-mod/tests/pattern_scan_runtime.rs` referenced
`modforge::patterns::scan_loaded_image` before it existed; compile
failure was the contract. Implemented `parse` / `find_first` /
`find_all` / `scan_loaded_image` over the loaded PE image. 17 unit
tests + 3 harness tests all green.

Mid-implementation, the test caught a second architectural bug:
scanning runs in the TEST process (wrong .text section). Refactored to
expose `patterns.scan` + `patterns.read_bytes` HTTP ops that run inside
the GAME process. Tests use those ops; round-trip from known function
entries verified for `GENE_COMBINATOR` and `APPLY_GENE_TO_HORSE`.

This is the minimum primitive needed; R2 (full patternsleuth
integration) is next. See `ADDRESS-RESOLUTION.md` "Pattern-scan
primitive" + "Phase R2" for the locked plan.

#### Iteration 4: dryrun_d3_d4 test catches TWO real bugs

`horsey-mod/tests/dryrun_d3_d4.rs` shipped as three tests asserting prologue bytes for combinator, lifecycle (ctor+dtor), and save (4 targets). After fixing the JSON parser (envelope payload lives in `result`), results split cleanly:

**Passing (3 targets):**
- `GENE_COMBINATOR` at `0x1400a2d70`, prologue `48 89 5c 24 08 ..` (shadow-space saves) ok
- `HORSE_CONSTRUCTOR` at `0x1400aac50`, prologue `48 89 5c 24 10 ..` ok
- `HORSE_DESTRUCTOR` at `0x1400bf1e0`, prologue `48 89 5c 24 08 ..` ok

**Failing (4 targets, all in `genes.ext.save`):**
- `SAVE_WRITER` 0x14006dc80 -> `7f 45 27 c6 ..` (JG + invalid; mid-function)
- `LOAD_GAME` 0x14006e480 -> `76 00 00 48 ..` (JBE; mid-function)
- `HORSE_SAVE_WRITER` 0x14006ee10 -> `48 8d 95 68 01 00 00 ..` (lea rdx; mid-function)
- `HORSE_SAVE_LOADER` 0x14006f150 -> `48 83 fa 0f ..` (cmp rdx, 0xf; mid-function. The classifier had a false positive that was tightened in this iteration.)

Both `-16` and `+0` placements were tested for all four save addresses; both land mid-function. The original Ghidra decomp's RVAs for the save-related functions are stale or mis-indexed for the current shipping build. Resolution: pattern-scan address resolution (R1/R2 work, already a queued item) is now critical-path for D4.

**Operational rule (locked):** `genes.ext.save.arm` is UNSAFE until the four save-function addresses are re-derived. The dryrun test enforces this; CI / pre-arm checks should refuse if dryrun fails.

This is the entire point of test-first. The patch infrastructure is correct; the addresses are wrong; we know which ones; we know which patches are safe to arm (combinator + lifecycle) and which aren't (save).

### Current test inventory (2026-05-15, post-iter-5)

53 tests, 52 green + 1 red. The red one is the contract that drives R2.

**Unit tests (48 green, ~0.02s total):**
- `modforge::patterns::tests` x 17. Parser + byte search + known-Horsey regression fences
- `horsey::genes::tests` x 19. Table init, eval math, combinator Mendelian properties, render-buf writes
- `horsey::genes_xml::tests` x 5. XML parser edge cases
- `horsey::patches::save_sidecar::tests` x 7. BXSAVEXT codec round-trip + CRC32

**Harness tests (5 green, 1 red, ~7-20s each):**
- `smoke::ping_returns_ok` green
- `dryrun_d1_d5` (D1 + D5 prologue fences) green
- `dryrun_d3_d4` (D3/D4 prologue fences) 2 green, **save** RED. Drives R2
- `arm_combinator` green
- `pattern_scan_runtime` (3 sub-tests) green

### Next action: R2. Patternsleuth at the modforge level

The hand-rolled `modforge::patterns::scan_loaded_image` works, but is
not the long-term answer. Reasons:

- Single-target, no concurrency. patternsleuth does SIMD-accelerated
  multi-target scans.
- No per-target multiple-signature fallback. patternsleuth supports
  "try sig A, then B, then C. First match wins" which is critical
  for surviving compiler-reordered prologues.
- No structured failure reporting. patternsleuth tells you "this
  target had N candidate matches" so we can detect ambiguity.

The `patternsleuth` crate is already pinned in
`workspace.dependencies`. Promote it to first-class modforge primitive
so every game-mod gets the same resolver.

Plan (locked):

1. **Failing test first.** Write
   `horsey-mod/tests/r2_save_addresses_resolved.rs` asserting the 4
   stale save addresses (currently red in `dryrun_d3_d4`) get
   resolved via patternsleuth signatures. Test stays red until R2
   ships.
2. **`modforge::patterns::sleuth` submodule.** Wraps the
   patternsleuth crate. Builder-style API:
   `Resolver::new().add(symbol, &[sig_a, sig_b]).resolve_all()`
   returns `HashMap<&str, Option<usize>>`.
3. **Per-game signature catalog.** Per game, a `targets/patterns.toml`
   declares `[symbol] sigs = ["..", ".."]`. modforge reads it at
   attach time.
4. **`targets::fn_addr` becomes a fallback layer.** Resolved
   addresses win when present; hardcoded constants are the failsafe.
   Tests can force the hardcoded path via env var to compare.
5. **Test goes green.** Then propagate to the live patches: D4 save
   sidecar can finally arm safely against re-derived addresses.
6. **Documentation pass on the API.** Once the shape is proven for
   horsey-mod, schedule1 + grounded2 + future mods all consume the
   same modforge primitive. Add an authoring guide alongside
   `ADDRESS-RESOLUTION.md`.

R2 is the LOAD-BEARING piece. It unblocks D4 save sidecar, retires
the hardcoded-RVA brittleness, and gives future per-game mods a
turnkey path from decomp address to resolved hook target.

### Older next-action notes (kept for context)

The pre-R1 "run dryruns then arm in order" plan below was written
before the test harness existed; today every dryrun + arm step is
covered by a test. Treat the next-action plan above (R2) as
authoritative.

### Next action: re-run smoke test with `--fresh` fix

`cargo test -p horsey-mod --test smoke -- --test-threads=1 --nocapture`

Expected: harness builds (or skips), kills any running Horsey, Steam launches a fresh instance, injector runs with `--fresh` and succeeds, HTTP plane comes up, `ping` returns OK, harness taskkills on Drop. End to end ~30-60s depending on Steam.

Once smoke passes, add the real test:

`horsey-mod/tests/dryrun_d3_d4.rs` calls each new dryrun op and asserts the returned prologue bytes match expected MSVC entry patterns:

```
genes.ext.combinator.dryrun
genes.ext.lifecycle.dryrun
genes.ext.save.dryrun
```

Acceptable prologues: `48 89 5c 24 ..` (shadow-space saves) or `48 8b c4 ..` (mov rax, rsp). Anything else means the -16 Ghidra adjustment is wrong for that target and arming would crash.

After dryruns pass, add `horsey-mod/tests/arm_full_stack.rs` that arms in order:
1. `genes.ext.arm` (D1)
2. `genes.ext.render.arm` (D5)
3. `genes.ext.lifecycle.arm`
4. `genes.ext.combinator.arm`
5. `genes.ext.save.arm`

Each step asserts `armed: true` and (after a brief settle) `call_count > 0` on the matching stats op. Failure mode: arming crashes the game, taskkill on Drop cleans up.

Save-round-trip test deferred until per-game test helpers learn to drive "load save N". Out of scope for the initial loop.

If smoke + dryrun + arm-full-stack all pass, the 480-gene system is **functionally complete for v1**.

### After v1 is verified

Priority order:
1. **R1/R2 pattern-scan address resolution** (port HorseyLiveTweaks pattern format to Rust). Survives game updates.
2. **ImGui-in-`modforge` primitive**. Shared in-game window for horsey-mod + schedule1 + grounded2. horsey-mod first consumer.
3. **HK1 Shift+Click smart-transfer** (vehicle <-> pasture <-> race line). User-locked hotkey v1 scope.
4. **Bestiary content** (real species in `genes-extended.xml` once we trust the system).
5. **D1.3 death-handler ±5 mutator** (mid-function patch). Low priority.
6. **D1.8 CRISPR UI dispatch** (show ext genes in CRISPR Lab). Low priority.

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

- [~] **Q-render-1.** PARTIAL. Vanilla `pop.xml` is
      now checked in at [`vanilla-pop.xml`](vanilla-pop.xml)
      (28 pops). Cross-reference work to map unusual
      modes (`car` wheels via `LEG_IS_CIRCLE`, `helix`
      shape, etc.) to specific gene weights is partially
      done in GENE-CATALOG.md Part 2 "Vanilla pops"
      section. Full per-pop oddity decomposition still
      open; deferred until specific bestiary species
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

1. [x] **DONE.** Vanilla `genes.xml` dumped to
   [`vanilla-genes.xml`](vanilla-genes.xml). 240 names
   indexed in document order matching the engine's
   gene_idx 0..239.
2. [x] **DONE.** Per-gene flow analysis on
   `FUN_14009f680` shipped via
   `research/build-gene-catalog.py`. Auto-derives
   `slots_written`, `slots_gated`, and `calls` for all
   240 genes. Output: [`GENE-CATALOG.md`](GENE-CATALOG.md)
   per-gene table.
3. [x] **DONE.** Consumer-map extractor
   `research/extract-consumer-map.py` enumerates 62
   `param_2[X]` reads in `FUN_1400ab3d0`. 23 are direct
   copies to horse-struct fields `+0x58..+0xa4`,
   `+0x200`, `+0x254`, `+0x2a8`. 38 feed conditionals /
   intermediate math. Output: GENE-CATALOG.md Part 2
   "Buf-slot -> horse-struct field" table.
4. [x] **DONE.** Cluster map authored in GENE-CATALOG.md
   Part 2 (gene_idx range -> feature area). Slots 0..3
   SQRT formula reverse-engineered from
   `FUN_14009f680:94066-94143`. The per-slot
   `{gene -> slot -> struct field}` chain is derivable
   by intersecting the per-gene table (step 2) with the
   consumer map (step 3).
5. [x] **DONE.** GENE-CATALOG.md Part 2 ships with
   cluster map + consumer map + engine internals
   (slots 0..3 formula) + modder workflow. The
   "Confirmed visible-effect slots" section is the
   live-validated subset.
6. [x] **EXTRACTION DONE, CLASSIFICATION OPEN.**
   `research/extract-field-readers.py` shipped. Greps
   `all_functions.c` for reads of all 23 direct-copy
   horse-struct offsets (`+0x58`, `+0x5c`, `+0x60`,
   `+0x64`, `+0x68`, `+0x6c`, `+0x70`, `+0x74`, `+0x78`,
   `+0x7c`, `+0x80`, `+0x84`, `+0x88`, `+0x8c`, `+0x90`,
   `+0x94`, `+0x98`, `+0x9c`, `+0xa0`, `+0xa4`, `+0x200`,
   `+0x254`, `+0x2a8`). Raw output: 2339
   function-occurrences, 3468 read sites.
   Horse-handler fingerprint (>= 3 of 23 offsets in one
   body) narrows to **218 likely handlers**. Top
   candidate `FUN_1401beac0` touches 20/23.
   Output: [`FIELD-READERS.md`](FIELD-READERS.md).

   First-pass classification done 2026-05-15. v1
   fingerprint "touches >= 3 offsets" produced 218
   functions, dominated by SDL/Vulkan feature-struct
   noise (`FUN_1401beac0` is the SDL_GPU Vulkan
   `VkPhysicalDeviceFeatures` checker, not a horse
   handler). Refined v2 fingerprint adds "must also
   touch one of `+0x200` / `+0x254` / `+0x2a8`" (rare
   high offsets the consumer writes). v2 narrows to
   **24 candidates**.

   Cross-referenced 24 candidates against
   [`ALL-FUNCTIONS.md`](ALL-FUNCTIONS.md):

   Confirmed horse-handlers (6):
   - `FUN_1400df280` retire_horse_handler (gameplay)
   - `FUN_140089510` copy_genome_to_clipboard (UI)
   - `FUN_14010ba40` debug_print_population_stats
   - `FUN_140094a20` show_race_ready_prompt (UI)
   - `FUN_1400dcab0` show_getting_old_sale_dialog (UI)
   - `FUN_1400e0aa0` show_all_rested_message (UI)

   Noise (10): auto-named `init_struct`,
   `batch_call_*`, `float_helper`, `float_math_main`
   patterns whose sequential field access collides
   with the regex.

   Unclassified (5): `FUN_14003d890`, `FUN_140155130`,
   `FUN_1401ef800`, `FUN_14003c8c0`, `FUN_1400e25b0`.

   **Open gap:** none of the confirmed horse-handlers
   are in the renderer call chain. The regex
   fingerprint isn't catching the renderer because it
   probably reads through a nested pointer
   (`horse->render_state->field`) rather than a direct
   `var + 0xNN` literal.

   **Forward-trace from consumer call sites, done
   2026-05-15:** all 6 known call sites of the
   consumer `FUN_1400ab3d0` (lines 104380, 104441,
   104585, 104614, 113025, 113052 in
   `all_functions.c`) are **regeneration events**, not
   per-frame render calls:
   - `FUN_1400b2e30`: child-from-parents setup (calls
     genome-merge `FUN_1400a2d80` first)
   - `FUN_1400b2ee0`: horse init with pop, sets
     `+0x234` and `+0x1fc=2` after
   - `FUN_1400b3070`: horse regen wrapping CRISPR-
     style flows; iterates entity list at 0xb8 stride
   - `FUN_1400c1xxx` (113025/113052): CRISPR genome
     mutate then regen, sets `+0x1fc=2`

   The consumer's job is to **persistently overwrite
   horse-struct fields whenever gene-derived
   attributes change** (birth, CRISPR, respawn). The
   renderer reads those fields independently, per
   frame, decoupled. Forward-tracing the consumer's
   callers leads to event triggers, not the renderer.

   **Implication: don't chase the renderer
   statically.** Finding it cleanly needs Ghidra
   struct propagation across the horse type, hours of
   skilled RE work for diminishing returns. The slot
   map we have is good enough to ship with:
   gene -> slot (per-gene table) + slot -> horse
   struct offset (consumer map) + working trampoline
   that puts arbitrary values into those slots + one
   empirically confirmed slot (slot 0).
   Per-feature classification of the remaining 22
   direct-copy slots can be populated as a side
   effect of bestiary authoring (each new species
   naturally probes a few slots). Trying to enumerate
   it ahead of demand is speculative work.

   Output: [`FIELD-READERS.md`](FIELD-READERS.md)
   with classified table + consumer call-site
   regeneration finding.

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

**Revised plan 2026-05-15:** Working genome is inline
at `horse + 0x2b8`, NOT at `horse[+0x78]`. The original
D3.1-D3.3 targets (`FUN_14005cf70/cd00/d190`) operate on
the heap blob at `+0x78`, which is a pop-seed / archive
buffer loosely coupled to rendering. They are NOT the
right anchors for `EXT_HORSE_GENOMES` lifecycle because:

- `FUN_14005cf70` bails early if `+0x78` already set,
  and breeding flow `FUN_1400b2e30` does NOT call it
  (combinator writes `+0x2b8` directly, never touches
  `+0x78`). Bred horses would skip the anchor.
- `FUN_14005d190` is a pop-seed copy (UI / CRISPR
  snapshot), not the breeding combinator.

The correct lifecycle anchor is the **horse-struct
allocator itself** (currently unfound). Open research
2026-05-15: `FUN_1400cc9d0` allocates 0x80 bytes and
pushes to `gamestate[+0xb8]` (the "track entity" list);
that's too small for the full horse with fields at
+0x800. There must be a separate `FUN_xxxxxxxx` that
allocates the full Horse struct and pushes to
`gamestate[+0x130]`. Need to find it.

- [x] **D3.0 (research).** ANSWERED 2026-05-15.
      Horse struct size is **0x498 bytes (1176)** =
      `0x2b8 + 0x1e0` (header up to +0x2b7, inline
      genome +0x2b8..+0x497). 40+ call sites alloc
      via `FUN_1402c704c(0x498)` followed by the
      single constructor `FUN_1400aac60`. Examples:
      lines 28589, 29161, 32559, 34040, 54169, 55517,
      59098, 62233, 64176, 65267 (save load), 76563,
      84065, 112352, 119180, 121872, 130208, 145756.
      Constructor `FUN_1400aac60`:
      - Sets vtable `&PTR_FUN_14030d660`
      - Zeros 50+ fields
      - Sets default `max_age = 0x1e` (30 years) at
        `+0x44`
      - Increments live-count global `_DAT_1403f311c`
      - Returns the same pointer it received
      Destructor `FUN_1400bf1f0`:
      - Resets vtable
      - Decrements `_DAT_1403f311c`
      - Releases sub-objects (`param_1[0x3e]` via
        `FUN_1402c7088(p, 0x1f48)`, and the std::string
        SSO buffers at `+0x51/+0x31/+0x2d`)
      - Frees the 0x498 buffer if delete-flag set
        (line 111549)
- [x] **D3.1.** SHIPPED 2026-05-15.
      `src/patches/lifecycle.rs`. Post-hook on
      `FUN_1400aac60`; calls
      `genes::ensure_horse_ext_genome(ret_ptr)`. HTTP:
      `genes.ext.lifecycle.{dryrun,arm,disarm,stats}`.
- [x] **D3.2.** SHIPPED 2026-05-15. Same module as D3.1.
      Pre-hook on `FUN_1400bf1f0`; calls
      `genes::drop_horse_ext_genome(param_1)`.
- [ ] **D3.3.** SKIPPED. The original plan to mirror
      `FUN_14005d190` (parent-to-child heap copy) is
      unnecessary: that function only writes the +0x78
      archive, not the working genome. Combinator
      (D3.4) handles the parent-to-child working-genome
      copy on its own.
- [x] **D3.4 (research).** ANSWERED 2026-05-15.
      Combinator is `FUN_1400a2d80(parent_a + 0x2b8,
      parent_b + 0x2b8, child + 0x2b8)`. Called from
      `FUN_1400b2e30:104367` (child-from-parents
      setup) before `FUN_14009f680` engine evaluates
      the new child.

      Algorithm: outer loop 2 strands × inner loop 240
      genes. Per (strand, gene): `FUN_1400c6580()` RNG
      coinflip selects which parent's strand to copy
      from, then `*(child + gene) = *(parent +
      coinflip * 0xf0 + gene)`. Advance child by 0xf0
      after each strand. Standard Mendelian: one
      strand per parent, each strand draws from one of
      that parent's two strands at random.

      **Linked inheritance:** a bitmask at lines
      95541-95551 forces the SAME parent across three
      gene-index ranges:
      - 72..86 (Neck cluster)
      - 97..174 (Head/Eye/Brow/Ear/Teeth/Mouth/Nose/
        Antlers/Hat)
      - 183..197 (palette base + colors)
      Plus exclusions at idx 83 and 107. Matches the
      GENE-CATALOG cluster map. Player can't get a
      giraffe head with a tiger jaw.

      **Bonus correction:** the working genome is
      INLINE at `horse + 0x2b8` (0x1e0 = 480 bytes,
      2 strands × 240 alleles), NOT at `horse[+0x78]`.
      The heap-alloc at `+0x78` is a separate pop-seed
      / snapshot blob. Engine `FUN_14009f680` and
      consumer `FUN_1400ab3d0` both take
      `param_1 + 0x2b8` as the genome input. **This
      changes D5.7 and D3 design assumptions: ext
      genomes should mirror the +0x2b8 inline layout,
      not the +0x78 heap-pointer pattern.**

      Patch plan (user decisions 2026-05-15):
      - Post-hook detour on `FUN_1400a2d80`. After
        vanilla returns, recover horse base pointers
        as `param_N - 0x2b8` (params are
        `parent_a + 0x2b8`, `parent_b + 0x2b8`,
        `child + 0x2b8`), then run our own combinator
        on `EXT_HORSE_GENOMES[parent_a_ptr]` +
        `EXT_HORSE_GENOMES[parent_b_ptr]` ->
        `EXT_HORSE_GENOMES[child_ptr]`.
      - Default inheritance: **independent per gene**
        (no cluster locking). Linked-inheritance is
        future XML extension via a `<linked-cluster>`
        element in `genes-extended.xml`; not in v1.
      - `horse[+0x78]` is **ignored entirely** for ext
        purposes (pop-seed / CRISPR snapshot only,
        not read for rendering). No parallel ext
        buffer at +0x78. Modders can't author effects
        riding on +0x78.

      **D3.4 patch SHIPPED 2026-05-15.** Implemented as
      `src/patches/combinator.rs`. Post-hook detour on
      `FUN_1400a2d80` via `retour::GenericDetour<unsafe
      extern "system" fn(*mut c_void, *mut c_void,
      *mut c_void)>`. Slow path delegates to
      `genes::combine_for_breeding(pa_id, pb_id,
      child_id)` which runs SplitMix64-seeded Mendelian
      over `EXT_HORSE_GENOMES`. HTTP ops:
      `genes.ext.combinator.{dryrun,arm,disarm,stats}`.

### Phase D4: Save format extension

Per the "layer on top" design principle: vanilla save
file stays untouched. Our extended state lives in a
sidecar `save<N>.dat.ext` next to the vanilla save.

**Revised plan 2026-05-15:** Per-horse hooks identified
via decomp pass. User decisions: dense per-horse records
(simple); orphan `.ext` files left in place on uninstall.

Per-horse save writer: `FUN_14006ee10`. Calls
`FUN_14006d470(horse + 0x2b8)` to pack the 480-byte
genome to 240 bytes. Also writes ~12 other small fields
(name_id, age, flags, etc.). Called per pointer from
roster iteration in `FUN_14006d610`.

Per-horse save loader: `FUN_14006f150`. Calls
`FUN_14006d580(horse + 0x2b8)` to unpack, then
`FUN_1400b3070(horse)` to regenerate render fields by
re-running engine + consumer. Our D1/D5 detours fire
during that regen, so ext alleles in `EXT_HORSE_GENOMES`
populated BEFORE `FUN_1400b3070` runs will be applied to
the render buf automatically.

Roster save order = `gamestate[+0x130]` vector order
(confirmed). Sidecar serializes per-horse records in
the same order; D4.4's roster-slot-index hypothesis is
implicit in the sequence.

**D4.1/D4.2/D4.3 SHIPPED 2026-05-15.** Single module
`src/patches/save_sidecar.rs` with 4 detours:
`SAVE_WRITER`, `LOAD_GAME`, `HORSE_SAVE_WRITER`,
`HORSE_SAVE_LOADER`. Loader detour writes
`EXT_HORSE_GENOMES` BEFORE calling the vanilla loader
trampoline so that vanilla's own `FUN_1400b3070` regen
call at the end picks up ext alleles via D1/D5
detours. Sidecar format implemented exactly as locked:

```
magic[8] = "BXSAVEXT"
version: u32 = 1
ext_count: u32 = EXT_GENE_COUNT (240)
horse_count: u32  (back-patched at close)
per_horse_record[horse_count]:
    ext_alleles: u8[2 * EXT_GENE_COUNT]
payload_crc: u32 (CRC32 IEEE)
```

HTTP ops: `genes.ext.save.{dryrun,arm,disarm,stats}`.
- [~] **D4.4.** Determine the stable horse_id field.
      **PARTIAL: probably no dedicated field exists;
      roster slot position IS the id.**

      Findings 2026-05-15:
      - `horse[+0xc]` = pop_id (verified: `FUN_14005cf70`
        indexes pop names "pepper"/"yeast" etc. by this
        field; `FUN_14005cf50` indexes a 0x58-stride
        table by it).
      - `horse[+0x18]` = increment counter (e.g.
        `FUN_14005d480` does `*(int*)(h+0x18) += 1`).
        Used for state ticks, not a stable id.
      - `horse[+0x40]` = genome hash (`FUN_14005d360`
        computes a deterministic hash of the genome
        bytes for freak pops; not an assigned id).
      - `horse[+0x78]` = genome pointer (0x1e0 bytes).
      - **Roster lives at `gamestate[+0x130]/+0x138`
        as a `std::vector<Horse*>` (stride 8).** Per
        `FUN_1400c0660:112458-112470`.
      - Save header `+0x10` holds a "next id" counter
        (value 93 vs 85 active records), suggesting
        monotonic id issuance. But no horse-struct
        field surveyed so far stores it.
      - Save record `parent_a`/`parent_b`/`child_ids[]`
        are int32s; the existing SAVE-FORMAT.md note
        ("Whirlwind Romance has p1=2, p2=3") describes
        them as cross-referencing **earlier record
        indices** in the roster, i.e. positional.

      Working hypothesis: **Horsey uses roster-slot
      position as the stable id.** When a horse is
      removed, either (a) the slot is kept with a "dead"
      flag (id preserved) or (b) the vector compacts and
      saved references rewrite. The save's "next id"
      counter `93 > 85` is consistent with (a): 93 slots
      ever issued, 85 live + 8 retained/dead.

      Implication for D4 sidecar: index extended state
      by roster slot position at save time. Compute the
      index by scanning `gamestate[+0x130]` for the
      horse pointer (O(N), N <= ~100). At load time,
      apply ext state in the same positional order.
      Vanilla save bytes still untouched.

      Open: confirm hypothesis (a) by save-diff
      experiment (kill a horse mid-save, observe whether
      the slot keeps existing or is removed). Until
      confirmed, treat the index as session-stable but
      sequence-fragile. D5.7 unchanged: pointer key
      works in-session; sidecar can use slot index.

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
