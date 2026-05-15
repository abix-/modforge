# Session log

Chronological commit history relocated from `todo.md`. Each entry preserves the verbatim summary written at commit time.

## Done (recent). Pre-session-log relocation

Originally in `todo.md` "Done (recent)":

- 2026-05-13: native-PE binding (`e9d3345`)
- 2026-05-13: hot reload via staged DLLs (`91f79f5`)
- 2026-05-14: `no_tire` enabled by default (`c37fa54`)
- 2026-05-14: split-flag fatigue suppressor (`608f994`)
- 2026-05-14: binary-patch infra (revert-on-detach) (`a31246f`)

## D-phase risks resolved 2026-05-15

Originally in `todo.md` "Risks and unknowns" table:

- **Breeding combinator unfound** RESOLVED 2026-05-15: `FUN_1400a2d80`. See D3.4 / GENE-CATALOG.md Part 1 Step 1.
- **Stable horse_id field not located** PARTIAL 2026-05-15: no dedicated field; roster slot position IS the id. Sidecar uses positional ordering (iteration order matches save order). See D4.4 / SAVE-FORMAT.md.
- **Horse-struct allocator unfound** RESOLVED 2026-05-15. Horse struct is 0x498 bytes. Constructor `FUN_1400aac60`, destructor `FUN_1400bf1f0`. 40+ call sites alloc via `FUN_1402c704c(0x498)` and ALL route through the single constructor. See D3.0 / GENE-CATALOG.md.
- **Working genome misidentified as `+0x78`** RESOLVED 2026-05-15: real working genome is inline at `horse + 0x2b8` (engine + consumer + save all use it). `+0x78` is pop-seed / archive only. Original D3.1-D3.3 plan was wrong; revised in D3 section + docs updated.

## D-phase shipped items 2026-05-14 / 2026-05-15

Originally in `todo.md` `## P0. Gene Table Doubling`:

- **D0 / architecture / locked-decisions: SHIPPED 2026-05-14.** Sidecar buffers, architecture diagram, locked design decisions (install path, layered design, authoring format, save compat, phase order), HTTP control-plane ops, and the `genes-extended.xml` authoring workflow documented in [`GENE-CATALOG.md`](GENE-CATALOG.md) "Part 3: Extended (480-gene) layer". D0.5 (heap-redirect helper) was deferred during D1 and remains OPEN; not blocking.
- **Phase D1 + D3 + D5 (detours): SHIPPED 2026-05-15.** Strategy + implementation status in [`HOOKING-STRATEGY.md`](HOOKING-STRATEGY.md) §8 "Implementation status." D1: 3 of 5 detours shipped (`EVAL_DIPLOID_BLEND_A`/`B`, `GENE_ALLELE_SWAP`); 2 deferred (death drift, CRISPR UI). D3.1/D3.2 (lifecycle): shipped; `tests/arm_lifecycle` captured 550 ctor + 3 dtor calls in 5s of menu idle. D3.4 (combinator): shipped; 6 unit tests in `genes::tests` lock the Mendelian algorithm. D5 (render trampoline): shipped; in-game proof via slot 0 visual effect 2026-05-14.
- **D7.2** (`genes-extended.xml` parser + live reload) shipped; documented in [`GENE-CATALOG.md`](GENE-CATALOG.md) Part 3 "XML authoring format".
- **D7.3** (`genes.ext.dump` op) shipped as part of D0.6; see GENE-CATALOG Part 3 "HTTP control-plane ops".
- **D9.1** (extended layout documented in GENE-CATALOG.md Part 3): SHIPPED.
- **D9.4** (sidecar file format documented in SAVE-FORMAT.md): SHIPPED.

## Session 2 (2026-05-15, latest commit `9fdeca9` at relocation)

### What shipped

| Commit | What |
|---|---|
| `d0f2f3c` | Phase A: standalone Win32 + D3D11 + ImGui backend in `modforge::ui::native`. Live test `tests/native_ui_lifecycle.rs` green. Sibling consumer for ueforge / horsey-mod / future native-PE mods, behind the `native-ui` Cargo feature. |
| `81f4bea` | `modforge::ui::api` (text/button/checkbox/slider/separator/spacing/same_line) + horsey-mod's first 3 in-game tabs (Overview / Horses / Cheats). |
| `ae50745` | Horses tab roster table (species, age/max, skill, tired_a/b, name_id, ptr; capped at 32 rows). |
| `4a7c73b` | Bestiary v1: `horsey-mod/bestiary/genes-extended.xml` with `BX_GIANT_BABY` at ext idx 0 (alleles `[0, 50, 100, 200]`, render `slot=0 mode=set`). `horsey-inject` auto-deploys it next to the staged DLL. 2 locking tests (`bestiary_v1.rs` unit, `bestiary_v1_live.rs` end-to-end through HTTP). |
| `5b5ad7a` | Cheats tab `no_tire` and `debug_mode` toggles via `api::checkbox`. HTTP `state` snapshot now captured AFTER op dispatch so write ops surface post-write state. |
| `d7a9501` | `gamestate::looks_loaded()` heuristic on roster vector at `+0x280/+0x288`. Snapshot returns null for money/year/sleeps when not loaded. UI Overview + Horses gate on the heuristic. 7 unit tests on the pure decision; 1 live regression. |
| `0f97176` | `gamestate.diag` HTTP op + `MODFORGE_ATTACH=1` harness mode so tests can attach to a manually-loaded save. `tests/gamestate_diag.rs` (consistency + env-gated in-save assertion). |
| `ca7edf2` | Docs: session-2 status update + global CLAUDE.md absolute rule banning ad-hoc curl / python / PowerShell probes. Everything goes through tests or test-invoked diagnostic ops. |
| `ae333c6` | **R3: GAMESTATE_PTR resolved via patternsleuth.** Three candidate signatures (cheat-money `+1000`, race-fee `<$50`, field_440 `=0x14`) each decode a RIP-relative `disp32` to recover the base. Resolved `0x7ff63d864c38`; hardcoded was `0x7ff63d88b0d8` (delta 0x264a0 == 156 KB). `gamestate::ptr()` now uses resolved with hardcoded fallback. Closes the in-save false-negative for GAMESTATE_PTR. |
| `ba96be8` | Docs: hardcoded -> resolved migration comparison table. Inventories every hardcoded address with current resolver status and a 5-batch migration plan. |
| `06839d4` | **R3 batch 1: cheat-globals validation framework.** New `mem.alias_check` op (writes 0xAB / 0xCD to addr A, reads B, restores; proves byte aliasing). New `resolve_data_global` wrapper with a 0x1000-byte sanity gate against the hardcoded RVA. `tests/r3_cheat_globals_resolve.rs` runs alias-check per global and fails loud on mismatch. Production wiring uses resolver-or-hardcoded for `no_tire` / `debug_mode`. First-pass sigs for the 3 cheat globals all rejected by the sanity gate on this build (production cleanly falls back to hardcoded). |
| `cac59c4` | Docs: P0 BLOCKER set. Every hardcoded address in `targets.rs` must be pattern-resolved before any more feature work. Feature backlog (bestiary v2, HK1, pasture, D2) is parked behind this. |
| `3553f50` | `mem.find_xrefs` op (HAND-ROLLED scanner). Found that the R3 GAMESTATE_PTR resolution is wrong: only 1 xref to the supposed `+0x308`, an SSE write, not gameplay code. Ripped out in `9fdeca9` per the patternsleuth rule. |
| `50fc2d0` | Docs: GAMESTATE_PTR resolution is wrong; next ticket is `mem.scan_data`. |
| `31e371b` | **P0 RULE locked**: use patternsleuth for ALL pattern / xref / data scans. NO hand-rolled scanners. Added to top of todo + as absolute rule in global CLAUDE.md alongside the no-curl rule. |
| `9fdeca9` | `mem.find_xrefs` re-implemented on patternsleuth. New `modforge::patterns::sleuth::scan_all_matches` returns all matches for one pattern (companion to `resolve_all`'s first-per-name). The op runs one anchored scan per common RIP-relative opcode prefix (mov, lea, add, cmp, mov-imm, byte-cmp, byte-xor, movzx, movdqa); each is terminated by patternsleuth's native `X<target_addr>` xref constraint. Reference implementation for the patternsleuth rule. |
| `e4de882` | **GAMESTATE_PTR deref fix.** Decomp re-read (`FUN_14009c6a0:46` heap-allocates + stores; `FUN_1400fd580:86` constructor stores; `FUN_14009c4e0:26` zeros) confirmed the slot is a pointer, not the struct. `gamestate::ptr()` now dereferences the slot and gates the result through pure helper `is_plausible_gamestate_pointer` (rejects null, sub-64KiB, kernel-space, misaligned). `resolve_gamestate_ptr_uncached` now sanity-gates resolver candidates at 0x1000 bytes so wrong-encoding sigs fall through to the (correct) hardcoded RVA. 6 new unit tests including a regression test pinning the exact `0x2400000000B` stale value the previous fix attempt observed. New `tests/gamestate_ptr_deref.rs` integration test (always-on shape check + `MODFORGE_EXPECT_LOADED`-gated bounded-value check). Unblocks Cheats tab, looks_loaded, every patch that reads gamestate offsets. Prior art [HorseyLiveTweaks `scene_resolver.cpp:11-33`](../research/prior-art/HorseyLiveTweaks/src/core/scene_resolver.cpp) shows the same store-site-anchor + structural-validate pattern in 20 lines; locked rule: read prior art before authoring address-resolution code. |
| `09da508` | `gamestate_ptr` resolver: constructor-anchored, no more wrong-encoding sigs. Anchor on `FUN_1400fd580`'s unique 1.0f@+0x114 store; scan 14 ModR/M variants of `mov [rip+disp32], reg` filtered to within 600 bytes preceding the anchor; expect exactly one. Same shape as HorseyLiveTweaks `kPatWorldRootStore` but split into anchor + proximity filter. |
| `34b4f82` | Cheat globals on patternsleuth: NO_TIRE_TOGGLE (cmp-sete-direct-to-same-byte), DEBUG_MODE_ACTIVE (unlock-block target1-target2 delta -0x79), DEBUG_LOG_GATE (3rd-4th-write init triplet + -0x72 relative offset). All three live-byte-derived. Hardcoded RVAs updated to true entries (-0x20 uniform `.data` drift). 3/3 alias-check the hardcoded byte. `patterns.sleuth.scan_all` op shipped; `find_xrefs` imm-suffix off-by-one fixed. |
| `32e7355` | RACES_COUNTER (-10.5f anchor + 0xffffffff bookend; `mov [rip+disp], edi` store) + SAVE_VERSION_GLOBAL (derived from GAMESTATE_PTR + 8). 6/6 data globals on R. |
| `3c0996c` | 8 R-parity function entries flipped to R: APPLY_GENE_TO_HORSE, HORSE_CONSTRUCTOR, HORSE_DESTRUCTOR, GENE_COMBINATOR, SAVE_WRITER, LOAD_GAME, HORSE_SAVE_WRITER, HORSE_SAVE_LOADER. 32-byte body sigs from live image; RIP-relative + call disp32s wildcarded. Production call sites in patches/combinator, patches/lifecycle, patches/render_trampoline, patches/save_sidecar now consult resolver first. arm_full_safe_stack still green through the new path. |
| `0f089ed` | 12 H function entries flipped to R (EVAL_DIPLOID_BLEND_A/B, GENE_DEATH_DRIFT, GENE_ALLELE_SWAP, GENE_TABLE_XML_WRITER, GENE_TABLE_LOADER, POP_XML_LOADER, GENE_ENGINE_CONSUMER, TMX_MAP_PARSER, DAILY_HORSE_EVENT, TRACK_STATE_MACHINE, CIRCUS_HANDLER). EVAL_DIPLOID_BLEND siblings disambiguated by literal disp32; GENE_TABLE_LOADER extended to 48 bytes after 32-byte collision. |
| `64d3df2` | Docs relocation: completed sections moved from `todo.md` to `ADDRESS-RESOLUTION.md` (gamestate ptr deref, P0 BLOCKER closed, migration table + R3 validation primitives + definition of done + recommended migration order, save-address re-derivation). Plus 5 generic env-var-driven `research_*.rs` tests (scan_pattern, dump_bytes, find_function_entry, find_xrefs, decode_disp32_pair) replacing the one-shot forensic tests, documented in `tests/RESEARCH.md`. 10 stale-RVA function entries re-derived via the probe tool (CHECK_HORSE_ELIGIBILITY, COMPUTE_HORSE_PRICE, CRISPR_LAB, BREEDING, DRAW_PAUSE_STATUS, POP_GENOME_BUILDER, SUMO_HANDLER, POWER_PLANT, WORLD_ACTION, BALLOON_CONTROLLER). |

### Known broken (closed)

GAMESTATE_PTR drift (in-game UI lying about save state) was misdiagnosed in `ae333c6`. The slot RVA was correct all along; `gamestate::ptr()` was missing a deref. Closed by `e4de882` + `09da508`. In-save live test still needs to be run user-side with `MODFORGE_EXPECT_LOADED=1` to lock the bounded-value contract.

## Session 1 (2026-05-15, after commit `5ff0cfc`)

### Test suite at end of session

| Category | Count | Status |
|---|---|---|
| Unit (modforge::patterns + sleuth) | 20 | green |
| Unit (horsey: genes / xml / sidecar) | 30 | green |
| Harness (smoke + dryruns + arm + r2 + catalog + build_info + save_sigs + save_find_entries + save_e2e_roundtrip) | 17 | all green; e2e proves ext alleles survive game restart |
| **Total** | **67** | **all green, no red contracts. 480-gene v1 is SHIPPABLE.** |

Live Horsey.exe build hash (this session): `742a6222ba73c99f757bd5576535e623106129fa08bf7aefd3af0da359cb7f71`. Stable across runs; changes when Steam ships an update.

Each harness test does full Steam relaunch + inject + HTTP + assert + taskkill, with timestamped logs at `target/test-runs/<name>-<ts>.log`. Average 7-20s per harness test.

### Commits (latest first)

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

### Completed (session 1)

- R1 build identification. DONE (`fe74e6b`). `game.build_info` op shipped; image SHA-256 cached + exposed. r1_build_identification (2 tests) green.
- Arm-and-observe tests for D5 + lifecycle + full-stack. DONE (`574beb0`). 4 arm tests green: combinator, lifecycle, render trampoline, full-stack. Lifecycle in isolation captured 550 ctor / 3 dtor calls in 5s of menu idle. Full-stack arms 4 subsystems together; game survives.
- R2 patternsleuth resolver shipped. DONE (`54d1c90`). `modforge::patterns::sleuth` wraps the crate; multi-target SIMD scan with first-match-wins per target. 3 harness tests green.
- R2 catalog parity proven. DONE (`74846de`). 4 known-good targets (GENE_COMBINATOR, APPLY_GENE_TO_HORSE, HORSE_CONSTRUCTOR, HORSE_DESTRUCTOR) resolve identically via sleuth as via legacy hardcoded RVAs. Migration pattern locked.

### Known limitations / risks (at end of session 1)

- Untested against the live binary. -16 prologue adjustment is convention but not verified for the 5 new addresses.
- `LOAD_GAME = 0x14006e480` was already in `targets.rs` but the entry-point hasn't been prologue-verified.
- Save-loader detour writes ext alleles BEFORE the vanilla loader runs. If vanilla zeros `EXT_HORSE_GENOMES` keys (horse pointers) by re-allocating horses during load, the entries get orphaned. Lifecycle anchors should drop them on dtor, but order-of-operations needs in-game confirmation.
- `+0x690` ActiveGeneCount (HorseyLiveTweaks finding) might need updating for ext range. Unclear; not in v1.
