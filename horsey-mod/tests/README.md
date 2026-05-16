# horsey-mod tests

Authoritative on: how we write tests in this project. Read this before
adding a new test file.

## Design principle: tests are research AND assertion, in one artifact

Every test in this directory is built to do two jobs at once:

1. **Research.** Answer "what does this byte / function / call site
   do?" by driving the running game and observing its reaction.
2. **Assertion.** Encode the answer as a check that fails if the game
   changes shape. The test ships, runs in CI, and protects the finding
   forever.

The two jobs share a single source file. Mode is picked by which env
vars are set. Discovery sessions start with the env vars unset (raw
observation), end with them set to encode the discovered semantic as
an assertion, and the same test file ships unchanged.

This pattern subsumes both "I need to figure something out" and "we
need regression coverage." We do not have separate scratch / ad-hoc /
exploratory tooling for the research half. Every probe is a test in
the tree.

**Why:** offset names, function semantics, and field meanings change
across game updates. A note in a doc rots; an asserting test fails
loudly on the regression run that breaks. The probe that found the
fact and the assertion that defends the fact should be the same file.

## Corollary: every research session ships TWO artifacts

A discovery cycle ends with:

1. A **driver** (a cmdlet in `src/ops.rs` that can trigger the
   in-game action). Permanent control surface, reusable by every
   future test.
2. An **assertion test** that uses the driver to fire the trigger,
   reads the affected memory, and asserts the observed transition.

If you find yourself reaching for a UI panel to twiddle a value
manually, stop. The right move is to add the cmdlet that drives the
action and the test that asserts the reaction. The UI is human-in-loop
for both drive and observe; tests are human-out-of-loop for both. Tests
are strictly faster in our setup because Claude can run them in a
loop without any "user does the thing and reports back" round-trip.

## Generic test conventions

All tests in this directory follow these rules:

- **Env-driven parameterization.** No hardcoded target names, offsets,
  or addresses. Inputs come from `HORSEY_*` env vars with sensible
  defaults so a bare `cargo test` runs cleanly.
- **Harness via `common::launch()`.** Each test launches a fresh
  game (or attaches to a running one via `MODFORGE_ATTACH=1`),
  injects `horsey.dll`, waits for HTTP ready. Auto-skips when
  `MODFORGE_NO_GAME=1`.
- **Helpers in `common/mod.rs`.** Shared resolution (`target_horse`,
  `wait_for_target_horse`, `env_or`) so per-test code stays focused
  on the experiment.
- **HTTP cmdlets are the only test surface.** Tests never poke memory
  directly; they go through the HTTP control plane. This makes every
  test reproducible by hand with curl, and forces driver coverage to
  live in `src/ops.rs` where it's permanently available.
- **Run with `--test-threads=1`.** Single game process; tests can't
  share it concurrently.

## Test families

### Where tests live: modforge vs. consumer mod

The split between `modforge/src/testkit/` unit tests and consumer-mod
integration tests:

- **Pure-logic unit tests live in `modforge`** (under each testkit
  module's `#[cfg(test)] mod tests`). These cover:
  - Byte matchers (`is_msvc_x64_prologue` + loose variant, int3 walkers).
  - JSON / hex parsers (`u64_at_key`, `parse_u64_hex_or_dec`).
  - MSVC `std::string` parser (`MsvcStdString::parse`).
  - File / diff logic (`snapshot::diff_bytes`, `snapshot::snapshot_path`,
    `snapshot::parse_offset_csv`, `assets::find_asset_in_dirs`).
  - Env-string parsers (`watch::parse_expect`).

  No game needed. 97 unit tests pass in modforge today.

- **HTTP-touching integration tests live in the consumer mod** (here, in
  `horsey-mod/tests/`). These prove the testkit's HTTP layer + the full
  loop (env parse -> resolve base -> call cmdlet -> assert response)
  works AGAINST A REAL native-PE BINARY. The thin-wrapper tests are
  irreplaceable as this coverage; they can't run in modforge because
  modforge has no game to target.

  When grounded2-mod or schedule1 adopts the testkit, they get the same
  thin-wrapper shape and the same integration coverage for free (each
  consumer runs its own copy against its own game).

When in doubt: **extract the pure logic into a helper, unit-test it in
modforge, and leave the HTTP-driven thin wrapper here**. This is what
`snapshot::diff_bytes` and `assets::find_asset_in_dirs` did most
recently.

### modforge::testkit (cross-game, shared)

Generic primitives extracted to [`modforge/src/testkit/`](../../modforge/src/testkit/)
so every native-PE mod target gets them for free. The horsey-mod test
files for these primitives are now thin wrappers (~10 LOC each) that
just launch the harness, resolve the horsey-specific base address, and
call into modforge. See the workspace-level `docs/todo.md` entry
"Extract cross-game research testkit to modforge" for the design.

Thin-wrapper tests (game-specific bits: launch + base resolver only):

- [`watch_region.rs`](watch_region.rs) -> `testkit::watch::run_region`
- [`watch_until_change.rs`](watch_until_change.rs) -> `testkit::watch::run_single`
- [`dump_diag.rs`](dump_diag.rs) -> `testkit::op::run`
- [`dump_apply_gene.rs`](dump_apply_gene.rs) -> `testkit::fn_entry::verify_fn_entry`
- [`dump_build.rs`](dump_build.rs) -> `testkit::build_info::run`
- [`find_xrefs.rs`](find_xrefs.rs) -> `testkit::xrefs::run`
- [`find_genes_xml.rs`](find_genes_xml.rs) -> `testkit::assets::run`
- [`find_retire_horse_handler.rs`](find_retire_horse_handler.rs) -> `testkit::recipes::find_fn_by_rdata_string`
- [`hk1_dump_horse_bytes.rs`](hk1_dump_horse_bytes.rs) -> `testkit::snapshot::take` + `diff_against`
- [`dump_name_table_heap.rs`](dump_name_table_heap.rs) -> `testkit::msvc::MsvcStdString`

When adding a new offset-discovery test, write it against testkit, not
against ad-hoc HTTP. The pattern is documented in the testkit module
rustdoc.

### Watch tests (offset semantic discovery)

Generic byte-watching tests that close the loop between trigger and
observation. Use these to figure out what a memory offset means.

- [`watch_region.rs`](watch_region.rs) - poll a window, log every byte
  that flickers, optionally drive via cmdlet and assert a specific
  transition.
- [`watch_until_change.rs`](watch_until_change.rs) - poll a single
  value, log every transition, optionally drive and assert a max
  latency from trigger to change.

Three modes, auto-detected by env-var presence:

| Mode | TRIGGER | EXPECT | Use case |
|---|---|---|---|
| Assertion | set | set | Closed-loop regression test. Ship it. |
| Discovery-trigger | set | unset | Find which byte responds to a known action. |
| Manual | unset | n/a | Passive watch. Only when no driving cmdlet exists yet (work item: add one). |

Example: confirm 0x205 is the hungry flag (HLT's claim) by feeding a
horse and asserting the transition:

```
HORSEY_WATCH_BASE=horse_ptr \
HORSEY_WATCH_OFFSET=0x200 \
HORSEY_WATCH_LEN=16 \
HORSEY_WATCH_TRIGGER=horse.feed \
HORSEY_WATCH_EXPECT=0x205:01->00 \
HORSEY_WATCH_MAX_LATENCY_MS=500 \
k3sc cargo-lock test -p horsey-mod --test watch_region -- --nocapture
```

If `horse.feed` doesn't exist yet, that's the first work item.

### Binary-research tests (`research_*`)

Pattern-scan, xref-find, and operand-decode tools that route through
patternsleuth via HTTP. Used to derive new sigs, find call sites, and
decode immediates. See [`RESEARCH.md`](RESEARCH.md) for the full
catalog.

### Feature-assertion tests

The bulk of files in this directory. Each one drives a specific
horsey-mod feature (gene arm/disarm, save/load, allele get/set,
lifecycle hooks) through its cmdlets and asserts the expected effect.
These started life as research tests and were promoted once the
behavior was understood.

Examples:
- [`horse_allele_get.rs`](horse_allele_get.rs) / `horse_allele_set.rs`
  - generic allele read/write across the 0..=479 address space.
- [`bestiary_v1_live.rs`](bestiary_v1_live.rs) - bestiary arm + live
  spawn validation.
- [`arm_*.rs`](.) - lifecycle / combinator / render trampoline arming.

### Probe tests

Single-purpose investigations (`probe_*.rs`, `hk1_probe_*.rs`,
`find_*.rs`, `dump_*.rs`). Same env-driven pattern, narrower scope.
Many of these existed before the dual-purpose principle was
articulated and have not yet been promoted to either a research
generic or a feature assertion.

## When you find yourself wanting a UI

You don't. Add the cmdlet and write the watch test. Picture an
example: a slider in an ImGui panel that drags 0..255 over offset
0x205 while you watch the game. Equivalent test: a loop that calls
`mem.poke` with each value, calls `watch_region` to read the reaction,
and prints a table. The test is reusable, regressible, and shippable.
The UI is a one-time visualization.

The one place a UI might still win is "I want to see a value update in
real time on the game window." A test can't do that. But it also
doesn't need to - it just needs to detect the transition, which it
does deterministically. If the human-visible game state is the only
way to validate something, that's a sign we don't yet have the right
cmdlet to observe it. Add the cmdlet.

## Inventory: what every test in this directory does today

Audited 2026-05-16 against the 68 `*.rs` files in this dir. Three columns
that matter:

- **Pattern**: which family the test fits in.
- **Drives?**: does it invoke a cmdlet to change game state (closed loop)? Or is it passive read-only?
- **Asserts?**: does the test fail on regression, or just print state for human inspection?

Dual-purpose target: **drives = yes, asserts = yes, env-driven, generic.**

### Pattern catalog (by family)

| Family | Examples | Drives? | Asserts? | Generic? | Status | Action |
|---|---|---|---|---|---|---|
| **Watch** (new) | `watch_region`, `watch_until_change` | yes (via TRIGGER) | yes (via EXPECT) | yes | exemplar | use this shape for new field-semantic discovery |
| **Generic feature** | `horse_allele_get`, `horse_allele_set` | yes | yes | yes (`HORSEY_HORSE` / `HORSEY_IDX`) | exemplar | model for "one cmdlet, exhaustive coverage" |
| **Arming + counters** | `arm_combinator`, `arm_lifecycle`, `arm_render_trampoline`, `arm_full_safe_stack` | yes (arm/disarm) | yes (call_count >= 0, parity invariants) | partly | exemplar | model for hook-lifecycle assertion |
| **Bestiary** | `bestiary_v1`, `bestiary_v1_live` | yes (live variant) | yes (slot 0 = BX_GIANT_BABY etc.) | no (locks specific contract) | exemplar | model for "ship XML contract" |
| **Dryrun stats** | `dryrun_d1_d5`, `dryrun_d3_d4` | no (read-only) | yes | partly | exemplar | model for arming preflight |
| **Resolver R-tier** | `r1_*`, `r2_*`, `r3_*`, `r4_field_offsets`, `chromosome_table_resolves`, `pattern_scan_runtime` | no | yes (resolved == hardcoded) | yes (table-driven from op response) | exemplar | model for "registry walk = coverage" |
| **Save round-trip** | `r2_save_e2e_roundtrip` | yes | yes | yes (`HORSEY_HORSE`) | exemplar | model for full-feature E2E |
| **Snapshot stability** | `snapshot_stability` | no | yes (main menu null contract) | yes | exemplar | model for negative assertions |
| **Smoke / harness** | `smoke`, `attach`, `wait_for_horse` | no | yes (ping ok, attach ok) | yes | exemplar | model for pipeline / pre-test gates |
| **Generic binary research** | `research_decode_*`, `research_scan_*`, `research_dump_bytes`, `research_find_*` | no | no (output IS the value) | yes (env-driven sigs) | exemplar (research-only by design) | keep as toolkit (see `RESEARCH.md`) |
| **Hypothesis probe** | `probe_paired_genome`, `vanilla_gene_names`, `render_stats`, `overlay_lifecycle` | mixed | yes | yes | exemplar | model for "hypothesis verified, locked" |
| **Forensic asserting probe** | `gamestate_diag`, `gamestate_ptr_deref` | no | yes (deref semantics) | yes | exemplar | model for "regression-protect a hard-won fact" |
| **One-shot dump** | `dump_apply_gene`, `dump_build`, `dump_cmp_neg1`, `dump_diag`, `dump_name_*`, `hk1_dump_horse_bytes` | no | no | partly | not-promoted | triage: most are superseded by cmdlets, DELETE; rest convert to assertion |
| **Discovery probe** | `find_gamestate_via_money`, `find_genes_xml`, `find_owned_horses`, `find_retire_horse_handler`, `find_xrefs`, `hk1_probe_*`, `hk1_find_tomtato_slot`, `investigate_horse_count`, `scan_438_slots`, `probe_sig_hits`, `probe_table_at` | partly | no (or weak) | partly | not-promoted | promote: each one's finding is load-bearing; encode as assertion + delete the discovery scaffolding |

### Promotion backlog

Last audited 2026-05-16.

#### Promoted: first batch (2026-05-16, 9 tests)

Each was discovery-only; now exposes a `HORSEY_EXPECT_*` env var that
flips the test into strict assertion mode while preserving the
discovery printouts.

| Test | Strict-mode env vars |
|---|---|
| `find_owned_horses` | `HORSEY_EXPECT_OWNED=<N>` |
| `investigate_horse_count` | `HORSEY_EXPECT_OWNED=<N>` |
| `scan_438_slots` | `HORSEY_EXPECT_OWNED=<N>`, `HORSEY_EXPECT_OWNED_SLOT=<hex>` |
| `hk1_probe_loc_field_layout` | `HORSEY_EXPECT_OWNED=<N>`, `HORSEY_EXPECT_LOC_VTABLE_RVA=<hex>` |
| `hk1_probe_scene_slot_vtables` | `HORSEY_EXPECT_VTABLE_RVA=<hex>`, `HORSEY_EXPECT_VTABLE_SLOT=<hex>` |
| `hk1_probe_mouse_globals` | `HORSEY_EXPECT_FINITE=1`, `HORSEY_EXPECT_X_RANGE=<lo..hi>`, `HORSEY_EXPECT_Y_RANGE=<lo..hi>` |
| `hk1_find_tomtato_slot` | `HORSEY_HORSE=<name>`, `HORSEY_EXPECT_SLOT=<hex>` |
| `hk1_dump_horse_bytes` | `HORSEY_DUMP_DIFF=<other_tag>` (diff vs saved snapshot), `HORSEY_EXPECT_DIFF_OFFSETS=<csv hex>` |
| `dump_name_entry_deref` | `HORSEY_NAME_ID=<n>`, `HORSEY_EXPECT_NAME=<string>` |

#### Promoted: second batch (2026-05-16, 8 tests; one deletion)

Genericized away from one-shot probes. File names retained so commit
history follows; the test fn name and contract are now generic.

| File | What it now does | Env vars |
|---|---|---|
| `dump_diag.rs` -> `dump_op` | invoke any cmdlet, dump response, assert success contract | `HORSEY_DUMP_OP`, `HORSEY_DUMP_ARGS`, `HORSEY_EXPECT_FIELD`, `HORSEY_EXPECT_VALUE` |
| `dump_apply_gene.rs` -> `verify_fn_entry_bytes` | dump + assert MSVC prologue at any function RVA | `HORSEY_FN_RVA`, `HORSEY_FN_LOOKBEHIND`, `HORSEY_FN_LOOKAHEAD`, `HORSEY_EXPECT_PROLOGUE` |
| `dump_build.rs` -> `build_info_is_well_formed` | assert build_info contract | `HORSEY_EXPECT_EXE_SIZE`, `HORSEY_EXPECT_EXE_SHA256` |
| `dump_name_diag.rs` -> `dump_name_diag` | resolve a list of name ids, assert each readable | `HORSEY_NAME_IDS`, `HORSEY_EXPECT_READABLE` |
| `dump_name_table_heap.rs` -> `dump_name_table_heap` | scan heap for any string, parse as MSVC `std::string` entries, assert SSO match | `HORSEY_HEAP_NEEDLE`, `HORSEY_HEAP_MAX_HITS`, `HORSEY_HEAP_STRIDE`, `HORSEY_EXPECT_HITS` |
| `find_xrefs.rs` -> generic xref-count | scan xrefs to any target, assert min-hit count | `HORSEY_XREF_TARGET`, `HORSEY_XREF_MIN_HITS` |
| `find_genes_xml.rs` -> `find_asset_next_to_exe` | find any asset file next to the exe | `HORSEY_ASSET`, `HORSEY_EXPECT_PATH`, `HORSEY_EXPECT_MIN_SIZE` |
| `find_retire_horse_handler.rs` -> `locate_fn_by_rdata_string` | string-anchored fn-entry locator for any function | `HORSEY_FN_STRING_HEX`, `HORSEY_FN_STRING_LOOKBACK`, `HORSEY_FN_READ_BACK`, `HORSEY_EXPECT_FN_RVA` |

Deleted (subsumed by another generic):
- `dump_cmp_neg1.rs` -> covered by `dump_op` (`HORSEY_DUMP_OP=diag.scan_cmp_neg1`).

#### Promoted: third batch (2026-05-16, 7 tests + 1 new testkit module)

Final sweep across the "exemplar" families looking for residual non-generic patterns. Output:

| File | What changed |
|---|---|
| `arm_combinator.rs` | rewritten as ~30 LOC wrapper over new `modforge::testkit::arm_lifecycle::run`. Pattern (dryrun precheck -> arm -> idle -> stats -> disarm -> ping) is now shared. |
| `arm_render_trampoline.rs` | same; ~30 LOC wrapper. |
| `dryrun_d3_d4.rs` | duplicated `looks_like_msvc_entry` (~40 LOC) replaced by `testkit::fn_entry::is_msvc_x64_prologue_loose`. |
| `dryrun_d1_d5.rs` | same. |
| `r2_save_signatures.rs` | same. |
| `r2_save_find_entries.rs` | duplicated tight matcher replaced by `testkit::fn_entry::is_msvc_x64_prologue` (strict variant). |
| `render_stats.rs` | print-only -> env-driven assertion (asserts every named stats/dryrun op responds without error). New env vars: `HORSEY_STATS_OPS`, `HORSEY_DRYRUN_OPS`, `HORSEY_EXPECT_ARMED`. |
| `probe_paired_genome.rs` | added strict assertion mode `HORSEY_EXPECT_PAIRED=1` that asserts paired bank holds real allele data + agreement >= 100/240. |
| `vanilla_gene_names.rs` | hardcoded SIZE/ASPECT/SKINNY anchors made env-driven via `HORSEY_EXPECT_COUNT` + `HORSEY_EXPECT_NAMES=<idx:name,...>`. |

New testkit module:
- `modforge::testkit::arm_lifecycle` (`SubsystemOps`, `Config`, `CounterBound`, `run`) - shared hook-lifecycle test flow. Covers single-subsystem arm/idle/stats/disarm. Multi-subsystem variants (lifecycle's ctor+dtor pair, full_safe_stack) keep their custom orchestration since they're not common across games.

Audit-complete status: spot-checked `gamestate_diag`, `gamestate_ptr_deref`, `pattern_scan_runtime`, `horse_allele_set`, `r4_field_offsets`, `r2_function_resolvers`, `r2_save_e2e_roundtrip`, `r3_cheat_globals_resolve`, `research_dump_bytes`, `research_find_xrefs`, `snapshot_stability`, `bestiary_v1`, `chromosome_map`, `chromosome_table_resolves`, `overlay_lifecycle`, `attach`, `smoke`, `wait_for_horse`. All already conform to the env-driven + asserting standard. The `r2_*`, `r3_*`, `r4_*` families are table-driven from the resolver registry response and self-extend when new resolvers are added.

#### Promoted: fourth batch (2026-05-16, 1 test + 2 testkit additions, 7 dedupes)

| File | What changed |
|---|---|
| `arm_lifecycle.rs` | rewritten as ~40 LOC wrapper. Drove the testkit extension below. |
| `arm_combinator.rs` | updated to use `Config::defaults(...)` constructor. |
| `arm_render_trampoline.rs` | same. |
| `r2_rederived_function_resolvers.rs`, `r2_h_function_resolvers.rs`, `r2_function_resolvers.rs`, `r3_races_and_save_version_resolve.rs`, `r3_gamestate_resolves.rs`, `r3_cheat_globals_resolve.rs`, `find_gamestate_via_money.rs` | each had a hand-rolled `fn u64_of` (5 LOC of identical hex parsing). All now `use modforge::testkit::json::u64_at_key as u64_of;`. ~35 LOC of duplication eliminated. |

New testkit additions:
- `modforge::testkit::arm_lifecycle::Config::defaults` constructor + `prologue_paths` / `armed_paths` fields. Supports multi-target subsystems (e.g. lifecycle's `ctor`+`dtor` pair) by walking dot-separated paths into the response JSON instead of hardcoding `prologue_bytes` / `armed`.
- `modforge::testkit::json` module: `u64_at_key`, `parse_u64_hex_or_dec`, `parse_usize_hex_or_dec` (with unit tests).

Audit-complete status (updated): all 7 not-yet-deep-read tests (4x `r2_*`, 1x `r3_*`, 7x `research_*`) confirmed exemplar. Env-driven, asserting, table-driven where applicable. The remaining `arm_full_safe_stack.rs` is a multi-subsystem orchestration that sequences 4 testkit-able subsystems with cross-subsystem invariants; not worth abstracting for 1 test, the per-subsystem flow already uses the testkit indirectly via the underlying ops.

#### Still to do

None in the original backlog. The two untracked candidates from the
session-start git status (`probe_sig_hits`, `probe_table_at`) don't
exist on disk and have been dropped.

The remaining KEEP-AS-TOOL test (`find_gamestate_via_money`) is already
fully generic + asserting; no work needed.

The principle: a test that only prints state for a human to read is a
half-finished test. Once the finding is encoded as an assertion, the
discovery scaffolding can come out.

## Adding a new test

Follow this checklist:

1. **Env vars.** What inputs does the test take? Default each one so a
   bare `cargo test` works.
2. **Harness.** `let Some(game) = common::launch("name") else { return };`
3. **Target resolution.** `common::target_horse(&game)` or
   `wait_for_target_horse(...)` if the save may not be loaded yet.
4. **HTTP cmdlets only.** If the action you need isn't a cmdlet, add
   it to `src/ops.rs` first. Don't reach for unsafe direct-memory
   shortcuts in the test.
5. **Both modes.** If discovery and assertion are both meaningful,
   support both via env-var presence checks. Don't write a "discovery"
   test that has no assertion path; you'll have to rewrite it the
   moment you know what to assert.
6. **`--nocapture` friendly.** Print enough so a human running the test
   manually can diagnose what happened.
