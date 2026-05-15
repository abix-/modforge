## Authoritative on: every test in horsey-mod, the test harness primitive, and the test-first engineering rule that drives every change

This doc is the single source of truth for testing in horsey-mod (and, by extension, the shared `modforge::harness` primitive that every per-game mod consumes). Open work on testing lives in [`todo.md`](todo.md); the present file is the FINISHED record.

## The rule (locked 2026-05-15): TESTS FIRST

Every new feature, patch, or research finding ships as a test first. The test asserts the contract before the implementation exists. We confirm the test fails, write the code until the test passes, then commit both together.

This applies to:

- **New detours / patches:** a test asserting prologue bytes + post-arm `call_count > 0`.
- **New genome math:** unit tests covering the algorithm against hand-checked values.
- **New HTTP ops:** a test asserting wire shape + behavior.
- **Research findings** (e.g. "this offset is the genome"): a test that reads from that offset and asserts it matches the known-good value from a save.

No exceptions. Code that ships without a covering test is not finished.

## Test inventory (2026-05-15, post-commit `9e2e8d5`)

64 tests total. 63 green + 1 contract-red. The red one is `dryrun_d3_d4::save_dryrun_prologues_ok` and is the open contract for fixing the 4 stale save addresses.

### Unit tests (50 green, ~0.02s total)

| Suite | Count | Subject |
|---|---|---|
| `modforge::patterns::tests` | 17 | IDA-style parser + byte search + wildcards + known-Horsey regression fences |
| `modforge::patterns::sleuth::tests` | 3 | Resolution accessor + require + unresolved helpers |
| `horsey::genes::tests` | 19 | Default table, set/get, eval math, allele swap, render-buf writes, Mendelian inheritance properties, RNG nonce divergence |
| `horsey::genes_xml::tests` | 5 | XML parser edge cases |
| `horsey::patches::save_sidecar::tests` | 7 | BXSAVEXT codec round-trip, bad-magic + future-version rejection, allele masking, CRC32 IEEE standard test vector |

### Harness tests (14 total, ~7-20s per test)

Each harness test does the full Steam relaunch + inject + HTTP + assert + taskkill cycle. Logs flushed per-line to `target/test-runs/<test-name>-<ts>.log`.

| Test file | Count | What it asserts |
|---|---|---|
| `smoke.rs` | 1 | Full harness loop end-to-end. Ping returns OK. |
| `dryrun_d1_d5.rs` | 2 | Prologue regression fence for 5 shipped detours (eval_a/b, allele_swap, gene_death_drift, apply_gene_to_horse). |
| `dryrun_d3_d4.rs` | 3 | New patches; 2 green, 1 contract-red (save addresses stale). |
| `arm_combinator.rs` | 1 | D3.4 combinator arms / fires / disarms cleanly. |
| `arm_lifecycle.rs` | 1 | D3.1/D3.2 ctor+dtor arms. 550 ctor + 3 dtor calls in 5s of menu idle; counters consistent. |
| `arm_render_trampoline.rs` | 1 | D5 render trampoline arms / no runaway loop / disarms cleanly. |
| `arm_full_safe_stack.rs` | 1 | All 4 green subsystems armed simultaneously; game survives idle + reverse-order disarm. |
| `pattern_scan_runtime.rs` | 3 | `modforge::patterns::scan_loaded_image` runs in the GAME process (via HTTP op); self-derived signatures round-trip. |
| `r2_resolver.rs` | 3 | `modforge::patterns::sleuth::resolve_all` multi-target SIMD scan; missing-sig returns null; first-match-wins. |
| `r2_migration_combinator.rs` | 1 | Legacy hardcoded-RVA address equals patternsleuth-resolved address for `GENE_COMBINATOR`. |
| `r2_catalog_resolves_all_green_targets.rs` | 1 | 4 known-good targets (`GENE_COMBINATOR`, `APPLY_GENE_TO_HORSE`, `HORSE_CONSTRUCTOR`, `HORSE_DESTRUCTOR`) resolve identically via sleuth as via legacy. |
| `r1_build_identification.rs` | 2 | `game.build_info` op returns image SHA-256 (64 hex), image_base, text_size; stable within session. |

### Live Horsey build (this session)

`742a6222ba73c99f757bd5576535e623106129fa08bf7aefd3af0da359cb7f71`. Stable per Horsey.exe build. Tied into every test log via `game.build_info`. When Steam ships an update, this hash changes and every test log immediately tells us we're on new bytes.

## The `modforge::harness` primitive

Generic Steam-game launch + inject + HTTP-probe + taskkill loop. Shared by every per-game mod (horsey-mod, schedule1, grounded2, future).

Modules:

- `modforge/src/harness/mod.rs`. `GameSpec`, `HttpProbe`, `InjectorSpec`, `BuildSpec`.
- `modforge/src/harness/harness.rs`. `GameHarness::launch` / `attach_existing`, `RunningGame` with Drop taskkill.
- `modforge/src/harness/build.rs`. Wraps `cargo build -p <pkg>`.
- `modforge/src/harness/steam.rs`. `steam.exe -applaunch <id>` with `steam://rungameid` fallback.
- `modforge/src/harness/process.rs`. `tasklist`/`taskkill` helpers.
- `modforge/src/harness/injector.rs`. Runs the per-game injector exe.
- `modforge/src/harness/http_probe.rs`. POSTs the modforge envelope (`{op, args}`) to a single endpoint; polls until ready.
- `modforge/src/harness/log.rs`. Per-test log to `target/test-runs/<name>-<ts>.log` with timestamped events flushed per-line.

Per-game wiring lives at `<game-mod>/tests/common/mod.rs`. For horsey-mod that file declares the Horsey `GameSpec` (AppID 3602570, `Horsey.exe`, port 33077, `/op` endpoint), passes `--fresh` to the injector so stale state doesn't block, and exposes `launch(test_name)` which every test file calls.

Env vars honored:

- `MODFORGE_NO_GAME=1` skips live launch; tests return cleanly.
- `MODFORGE_SKIP_BUILD=1` skips `cargo build` for fast iteration.
- `MODFORGE_STEAM_EXE=<path>` overrides the Steam executable path (default `C:\Games\Steam\steam.exe`).

## How the harness was built: iteration log

Each iteration is one cycle of the test-first workflow: write a failing test, find out what breaks, fix, retest.

### Iteration 1: failed at stale injector state

Loop reached the injector step but failed at horsey-inject's stale-state guard (it saw the prior manual injection's `.injstate` file and refused). Fix: pass `--fresh` from the test wiring.

Lesson: injector binaries that maintain on-disk hot-reload state need a per-test clean-slate flag.

### Iteration 2: HTTP probe URL was wrong

After the inject fix, the probe hung on HTTP wait. Root cause: probe was POSTing to `<endpoint>/<op>` (e.g. `/op/ping`) but `modforge::server` accepts POST only at the literal `endpoint` URL (`/op`) with `{"op": "<name>", "args": {...}}` in the BODY. Fix: rewrote `harness::http_probe` to use envelope shape.

Lesson: the test harness is the right place to encode the wire shape. Tests should never hand-build URLs.

### Iteration 3: SMOKE PASSES end-to-end

`cargo test -p horsey-mod --test smoke -- --test-threads=1 --nocapture` -> **7.1s total**, ping returns OK, taskkill on Drop:

```
kill old Horsey       120ms
Steam launch          3.3s
horsey-inject --fresh 500ms
HTTP ping             ~1ms
teardown grace        3s
```

Test log written to `target/test-runs/smoke_ping_returns_ok-<ts>.log` with every step timestamped + flushed per-line.

### Iteration 4: dryrun_d3_d4 test catches TWO real bugs

`horsey-mod/tests/dryrun_d3_d4.rs` shipped as three tests asserting prologue bytes for combinator, lifecycle (ctor+dtor), and save (4 targets). After fixing the JSON parser (envelope payload lives in `result`), results split cleanly:

**Passing (3 targets):**

- `GENE_COMBINATOR` at `0x1400a2d70`, prologue `48 89 5c 24 08 ..` (shadow-space saves) OK
- `HORSE_CONSTRUCTOR` at `0x1400aac50`, prologue `48 89 5c 24 10 ..` OK
- `HORSE_DESTRUCTOR` at `0x1400bf1e0`, prologue `48 89 5c 24 08 ..` OK

**Failing (4 targets, all in `genes.ext.save`):**

- `SAVE_WRITER` 0x14006dc80 -> `7f 45 27 c6 ..` (JG + invalid; mid-function)
- `LOAD_GAME` 0x14006e480 -> `76 00 00 48 ..` (JBE; mid-function)
- `HORSE_SAVE_WRITER` 0x14006ee10 -> `48 8d 95 68 01 00 00 ..` (lea rdx; mid-function)
- `HORSE_SAVE_LOADER` 0x14006f150 -> `48 83 fa 0f ..` (cmp rdx, 0xf; mid-function. The classifier had a false positive that was tightened in this iteration.)

Both `-16` and `+0` placements were tested for all four save addresses; both land mid-function. The original Ghidra decomp's RVAs for the save-related functions are stale or mis-indexed for the current shipping build. Resolution: pattern-scan address resolution (R1/R2 work) is now critical-path for D4.

**Operational rule (locked):** `genes.ext.save.arm` is UNSAFE until the four save-function addresses are re-derived. The dryrun test enforces this; CI / pre-arm checks refuse if dryrun fails.

This is the entire point of test-first. The patch infrastructure is correct; the addresses are wrong; we know which ones; we know which patches are safe to arm (combinator + lifecycle) and which aren't (save).

### Iteration 5: pattern-scan primitive (R1) ships in modforge

Test-first workflow drove `modforge::patterns`. Failing test `horsey-mod/tests/pattern_scan_runtime.rs` referenced `modforge::patterns::scan_loaded_image` before it existed; compile failure was the contract. Implemented `parse` / `find_first` / `find_all` / `scan_loaded_image` over the loaded PE image. 17 unit tests + 3 harness tests all green.

Mid-implementation, the test caught a second architectural bug: scanning runs in the TEST process (wrong .text section). Refactored to expose `patterns.scan` + `patterns.read_bytes` HTTP ops that run inside the GAME process. Tests use those ops; round-trip from known function entries verified for `GENE_COMBINATOR` and `APPLY_GENE_TO_HORSE`.

This is the minimum primitive needed; R2 (full patternsleuth integration) followed. See [`ADDRESS-RESOLUTION.md`](ADDRESS-RESOLUTION.md) "Pattern-scan primitive" + "Phase R2" for the deeper plan.

### Iteration 6: R2 patternsleuth resolver + migration pattern proven

Two new test files drove R2 end to end:

- `tests/r2_resolver.rs` (3 green): multi-target single-pass resolution; missing-signature returns null; first-matching-sig-wins.
- `tests/r2_migration_combinator.rs` (1 green): legacy hardcoded-RVA address equals patternsleuth-resolved address for `GENE_COMBINATOR`. **Migration pattern proven.**

Implementation:

- `modforge::patterns::sleuth` wraps the patternsleuth crate. API: `Target{name, sigs}`, `Resolution{by_name}`, `resolve_all(&[Target])`.
- Per-target candidate-signature lists; first match wins.
- Scans restricted to `.text` section (caught a real bug: 16 bytes of `0xff` false-matched in `.rdata` before the filter).
- HTTP op `patterns.sleuth.resolve {patterns: [{name, sigs}]}` exposes it to tests + future attach-time use.

### Iteration 7: R2 catalog test + R1 build identification + arm-and-observe suite

- `r2_catalog_resolves_all_green_targets`: 4 known-good targets resolve identically via sleuth. Migration pattern locked in place across the green stack.
- `r1_build_identification` (2 tests): `game.build_info` op returns image SHA-256 + base + text_size. R1 phase complete.
- 4 arm-and-observe tests (combinator, lifecycle, render, full-stack). The lifecycle test captured 550 ctor / 3 dtor calls in 5s of menu idle; every horse create/destroy is intercepted. The full-stack test arms 4 subsystems together; game survives idle + reverse-order disarm.

Mid-implementation, the full-stack test caught a test-design issue: strict `ctor_calls == entries_created` only holds when armed BEFORE any horse is constructed. Relaxed to inequality; strict invariant covered by `arm_lifecycle.rs` in isolation.

## Architectural lessons (carry forward to other game-mods)

These are the durable findings from building the harness; reuse them when wiring a new per-game mod.

1. **Always derive signatures from runtime bytes, not from decomp.** Decomp RVAs drift between game builds. The pattern-scan primitive eliminates that drift entirely.
2. **Scan only the `.text` section.** Other PE sections produce false matches (16-byte runs of `0xff` are not uncommon in `.rdata`).
3. **Run pattern scans INSIDE the game process.** Test-process scanning is useless; the test process has its own image. Expose a `patterns.scan` HTTP op so tests can drive the live image.
4. **Tests must NEVER hand-build URLs / envelopes.** Wire shape belongs in the harness. If the envelope changes, only the harness changes.
5. **`--fresh` style injector flags.** Any injector with on-disk state needs a clean-slate flag for repeatable test launches.
6. **Per-test log files flushed per-line.** Cargo's stdout-buffering makes a long-running launch look hung. Always write a `target/test-runs/<name>-<ts>.log` and `tail -f` for live progress.
7. **Test invariants that DESCRIBE the system, not just OBSERVE it.** "call_count is finite" catches infinite loops. "entries_created <= ctor_calls" catches spurious inserts. Strict equalities catch slow-path drops.
8. **Failing tests catch real bugs even mid-implementation.** Every iteration above caught a distinct bug that would have shipped silently in a no-test workflow.
