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

## P0 RESOLVED 2026-05-15: gamestate ptr was missing a deref

The root cause of the multi-session GAMESTATE_PTR thrash was a 30-line bug, not an address-resolution problem.

**What was happening.** `DAT_1403fb0d8` in the decomp is a `.data` POINTER SLOT (8 bytes) whose value is the heap address of a `FUN_1402c704c(0x448)`-allocated GameState. Every read site in the decomp does `*(int *)(DAT_1403fb0d8 + N)`: pointer + offset, not struct + offset. The slot is written by:

- `FUN_14009c6a0:46` allocates 0x448 bytes, constructs in place via `FUN_1400fd580`, then stores the heap pointer.
- `FUN_1400fd580:86` (the in-place constructor) does `DAT_1403fb0d8 = param_1` (the freshly-allocated buffer).
- `FUN_14009c4e0:26` zeros the slot on destruction.

A 2026-05-14 fix attempt observed a stale value (`0x2400000000B`) at the slot during main-menu state and concluded the slot WAS the struct (no deref). That hid the crash but made every field read pull `.data` bytes adjacent to the slot, which is why money writes didn't stick, the in-game UI lied about save state, and the snapshot returned zeros.

The R3 candidate sigs (`cheat_money_add_1000`, `race_fee_cmp_50`, `field_440_set_20`) were authored under the same wrong mental model: they expected `add [rip+disp32], imm` (direct write to a struct embedded in `.data`). The actual MSVC encoding for `DAT_1403fb0d8 + 0x308 += 1000` is `mov reg, [rip+slot]; add [reg+0x308], imm` (two instructions, the second referring to a heap address that can't be RIP-rel-anchored at all). The sigs that matched in the live image were anchoring on unrelated globals with similar opcode shapes; that's why two candidates resolved 156 KB apart.

**Fix.** Three small changes:

1. `src/gamestate.rs`: `ptr()` dereferences the slot and gates the result through a pure helper `is_plausible_gamestate_pointer` (rejects null, sub-64KiB, kernel-space, misaligned). Callers' existing `if p == 0 { return None }` guards short-circuit cleanly when no save is loaded.
2. `src/targets.rs`: `resolve_gamestate_ptr_uncached` wraps `resolve_via(CANDIDATES)` in the same 0x1000-byte sanity gate the cheat-globals use. The bogus candidate sigs are now rejected and production falls through to the (correct) hardcoded RVA `0x1403fb0d8`.
3. The misleading "CRITICAL CORRECTION (2026-05-14)" comment block in `gamestate.rs` was replaced with the correct lifecycle description.

**Prior art that ended this faster.** [HorseyLiveTweaks](https://github.com/NickPetrone/HorseyLiveTweaks) (Nick Petrone, the game's own modder) resolves the equivalent World Root singleton in ~20 lines via the same pattern: anchor on a STORE site (`mov [rip+disp32], rbx` immediately followed by a distinctive field write `mov [rbx+0x270], rdi`), decode the disp32 to recover the `.data` slot, deref, then validate structurally (active scene id in `[-1, 32)`, scene table non-null). No env vars, no on-screen-value scans, no fabricated discriminators. Reading [`scene_resolver.cpp:11-33`](../research/prior-art/HorseyLiveTweaks/src/core/scene_resolver.cpp) before authoring more sigs would have prevented two sessions of thrash. Locked rule going forward: read prior art before authoring address-resolution code.

**Tests.**

- 6 new unit tests on `is_plausible_gamestate_pointer`, including a regression test pinning the exact `0x2400000000B` stale value the previous attempt observed. 13/13 unit tests in `gamestate::tests` green.
- `tests/gamestate_ptr_deref.rs` (2 integration tests): an always-on shape check ("ptr is 0 or heap-shaped, and verdict matches") and a `MODFORGE_EXPECT_LOADED=1`-gated in-save check ("ptr is heap-shaped, looks_loaded is true, money/year/sleeps are within bounded real-save ranges"). The in-save bound is structural ("looks like a real save"), NOT exact-value matching (which is what burned the previous attempt).

**Status.** Unit tests green. In-save live test pending: run `k3sc cargo-lock test -p horsey-mod --test gamestate_ptr_deref -- --test-threads=1 --nocapture` with `MODFORGE_EXPECT_LOADED=1` and a save loaded to lock it.

**What's still open.** The R3 candidate sigs are still wrong but harmless (sanity gate rejects them). Re-authoring against `FUN_1400fd580`'s distinctive shape (the constructor stores `0x3f800000` at +0x114 and `mov [rip+slot], param_1` is its only RIP-rel qword write) is the right next step but not blocking: feature work can resume now.

## P0 RULE: USE PATTERNSLEUTH. NO HAND-ROLLED SCANNERS

User-locked 2026-05-15. Every pattern-scan, xref-find, or signature match in this repo MUST go through the `patternsleuth` crate via `modforge::patterns::sleuth`. NO exceptions. ZERO tolerance.

This includes:

- **Address resolution** (functions + data globals): use `Pattern::new("opcode bytes ?? ?? ?? ?? imm")` + `sleuth::resolve_all`. Already done for the 9 R-parity function entries via the existing catalog.
- **Xref scanning** (find every `.text` instruction whose `disp32` decodes to a target data address): use patternsleuth's built-in `X<target_addr>` xref constraint inside an anchored pattern (`<opcode prefix> X<target>`). `is_match` at `patternsleuth_scanner/src/lib.rs:232` does the `next_ip + disp32 == target` check natively. NEVER iterate `.text` byte-by-byte. NEVER write your own `i32::from_le_bytes` over instruction bytes. The find_xrefs op in `horsey-mod/src/ops.rs` is the reference consumer: enumerates the common RIP-relative opcode prefixes (mov, lea, add, cmp imm8/imm32, mov-imm, byte-cmp, byte-xor, movzx, movdqa), runs one anchored scan per prefix via `sleuth::scan_all_matches`, unions and dedupes the results.
- **Data scans** (find a value in `.data`): use patternsleuth with the value bytes as a literal pattern (e.g. `"b0 00 00 00"` for u32 == 176).

**Done so far:**
- `find_xrefs` shipped as a hand-rolled scanner in `3553f50` (rule violation), then ripped out and reimplemented on patternsleuth in `9fdeca9`. Reference implementation for any future scanning code.
- `modforge::patterns::sleuth::scan_all_matches(sig)` added in `9fdeca9` as the all-hits companion to `resolve_all` (which returns only first per name).

If a needed feature is missing from patternsleuth, add it to the upstream crate or to `modforge::patterns::sleuth` wrapper. Do not work around it in horsey-mod.

## P0 BLOCKER (CLOSED 2026-05-15): GAMESTATE_PTR was a missing deref, not a wrong address

See "P0 RESOLVED" above for the full diagnosis. Summary: the hardcoded slot RVA `0x1403fb0d8` was correct all along. `gamestate::ptr()` was returning the slot's address instead of the heap pointer it holds. The R3 resolver candidates were authored under a wrong mental model and now fall through to the (correct) hardcoded RVA via a sanity gate.

`looks_loaded`, the Cheats tab toggles, and every patch that hooks gamestate offsets now operate on the correct address as soon as a save is loaded. The previous false-negative ("UI says no save loaded mid-save") cannot recur without the unit-test regression firing.

## P0 BLOCKER: pattern-resolve EVERY hardcoded address

User-locked 2026-05-15. Every address in `targets.rs` must be pattern-resolved before any more feature work lands. This is not optional and not negotiable. The reasoning:

- **Game updates break us.** The shipping Horsey build is a moving target. Save-target RVAs have already drifted -277 to -1548 bytes between builds (`bd95252` re-derivation). The same drift will hit every other hardcoded address eventually. Note: the 2026-05-15 "GAMESTATE_PTR returns 0x864c38" case was not version drift, it was wrong-sigs matching unrelated globals; see "P0 RESOLVED" above.
- **Patches won't persist.** D1/D3/D4/D5 detours all install at fixed RVAs. When the next game update ships, every detour misses its target and arms either zero subsystems or, worse, patches a different function. Every patch becomes a latent crash bug. Pattern-resolved addresses move with the code.
- **No partial migration.** "Most are resolved" is not enough. A single hardcoded address in the hot path means the next game update bricks the mod for everyone. Either everything resolves or the mod's reliability story is "works on the 2026-05-08 build only."

**Definition of done:**
1. Every entry in the comparison table below is **R** (production reads through resolver), not **R-parity** (sig exists but production still uses hardcoded) and not **H** (hardcoded only).
2. Every resolver has at least 2 candidate signatures so a single MSVC reorder between builds doesn't break it.
3. Every resolver has an alias-check test (`tests/r3_*.rs`) that fails loud on the next build whose drift the sigs don't survive.
4. CI / pre-commit refuses to ship any new `pub const usize = 0x140...;` outside `targets::resolve::*` candidate sigs.

**Order of attack:**
1. ~~Tooling first: `mem.find_xrefs`.~~ DONE in `9fdeca9` (patternsleuth-backed, multi-prefix anchored scan).
2. ~~Re-resolve GAMESTATE_PTR.~~ NO LONGER URGENT. The slot RVA was correct all along; the bug was a missing deref in `gamestate::ptr()` (closed 2026-05-15, see "P0 RESOLVED" at top). Re-authoring its sigs against `FUN_1400fd580` is still valuable for build-drift resilience but isn't blocking.
3. Author sigs for the remaining 5 data globals (NO_TIRE_TOGGLE, DEBUG_MODE_ACTIVE, DEBUG_LOG_GATE, RACES_COUNTER, SAVE_VERSION_GLOBAL). Each is single-writer (constructor / init code stores the value); anchor on the store site plus a discriminator instruction, decode the disp32 of the RIP-rel store to recover the slot. This is the HorseyLiveTweaks pattern from `scene_resolver.cpp:11-33`.
4. Flip the 9 R-parity function entries to **R** (the sigs already exist via `r2_catalog` and `r2_save_signatures`; production reads need to consult the resolver). Mostly mechanical.
5. Author sigs for the remaining 20 H function entries. Most are unused-in-v1 today but matter the moment any future feature lands on them.
6. Field offsets (`gs_offset::*`, `horse_offset::*`) get their own R3-style tooling: scan a write site, decode the displacement, recover the offset. Defer until a build is observed where a field offset has actually shifted.

**Feature backlog gate.** With GAMESTATE_PTR fixed, the in-save UI lies are gone and feature work CAN proceed in parallel with the broader migration. The strict "no features until everything is resolved" lock was justified when we couldn't trust state reads at all; that's no longer true. Items 3-6 above stay urgent for build-update resilience but don't block bestiary v2, HK1 Shift+Click, pasture auto-buy hay, or D2 pop-weight extension.

## Hardcoded -> resolved migration: comparison table

Goal: every address the production hot path reads goes through `targets::resolve::*` (pattern-scan via `modforge::patterns::sleuth`) instead of a `pub const usize`. Hardcoded RVAs stay only as fallback inside the resolver functions, sourced from one decomp build. R3 in commit `ae333c6` is the first migration; the table below tracks the rest.

Status legend: **R** = resolved (production reads through resolver), **R-parity** = resolved sig exists + tested, but production still uses the hardcoded const, **H** = hardcoded only, **N/A** = struct field offset (not an absolute address; drift handled differently).

### Data globals

| Item | Hardcoded RVA | Status | Decomp anchor for sig | Leverage |
|---|---|---|---|---|
| `GAMESTATE_PTR` | `0x1403fb0d8` | **R (constructor-anchored, sanity-gated)** | resolved via `resolve_gamestate_ptr_via_constructor`: 1.0f@+0x114 anchor inside `FUN_1400fd580`, scan 14 ModR/M variants of `mov [rip+disp32], reg` filtered to within 600 bytes preceding the anchor, expect exactly one. 0x1000 sanity gate vs hardcoded; falls back to hardcoded on miss. `tests/r3_gamestate_resolves.rs` locks the contract (slot near hardcoded + heap-shaped deref in-save) | very high; every state read + write |
| `RACES_COUNTER` | `0x1403eded8` | **R** (-10.5f anchor + 0xffffffff bookend) | sig `c7 ?? 0c 01 00 00 00 00 28 c1 89 3d .. c7 ?? 50 02 00 00 ff ff ff ff`. MSVC stores 0 via `mov [rip+disp], edi` (edi pre-zeroed), bracketed by the -10.5f init at +0x10c and the 0xffffffff init at +0x250. RVA unchanged on this build (delta 0) | low; one read per snapshot |
| `NO_TIRE_TOGGLE` | `0x1403d95a5` | **R** (cmp-sete-direct-to-same-byte) | sig `80 3d ?? ?? ?? ?? 00 0f 94 05 ?? ?? ?? ??`; both disp32s validated equal. RVA -0x20 from old decomp 0x3d95c5 | medium; every Cheats tab toggle |
| `DEBUG_MODE_ACTIVE` | `0x1403d957b` | **R** (unlock-block delta) | bespoke resolver: scan `c6 05 .. 01 c6 05 .. 00`, filter to matches where target2 - target1 == -0x79 (decomp distance from DAT_1403d9522). RVA -0x20 from old | medium; gates cheat menu |
| `DEBUG_LOG_GATE` | `0x1403d9506` | **R** (init-triplet, anchored on adjacent 3rd-4th write) | bespoke resolver: scan `c7 05 .. 00 01 00 00 c7 05 .. ff ff ff ff` (3rd write = 0x100, 4th = 0xffffffff), apply decomp's -0x72 relative offset. The 5th write (DEBUG_LOG_GATE init) isn't adjacent in this build; MSVC reordered | low |
| `SAVE_VERSION_GLOBAL` | `0x1403fb0e0` | **R** (derived from GAMESTATE_PTR + 8) | the version slot lives 8 bytes after the GameState pointer slot in `.data` by struct construction; no independent scan needed | low; one read per load |

### R3 validation primitives (locked)

- `mem.alias_check { addr_a, addr_b }`: writes 0xAB then 0xCD to A, reads B after each, restores A. `same_byte: true` iff both reads matched both writes. Proves two addresses point at the same byte.
- `targets::resolve::resolve_data_global(candidates, hardcoded_rva)`: runs the sleuth scan, then sanity-gates the result against the rebased hardcoded RVA. Rejects any resolution > 0x1000 bytes from hardcoded. Caller falls back to hardcoded on `None`.
- `tests/r3_cheat_globals_resolve.rs`: per global, if the resolver returned non-null, runs `mem.alias_check(hardcoded, resolved)` and FAILS LOUD on mismatch. The user can re-run this test against any future build to detect drift on first contact.

### Function entries

| Item | Hardcoded RVA | Status | Sig anchor candidate | Used by |
|---|---|---|---|---|
| `APPLY_GENE_TO_HORSE` | `0x14009f670` | **R** (body sig 32b live-captured) | 32-byte body from live image | D5 render trampoline |
| `EVAL_DIPLOID_BLEND_A` | `0x1400a5d10` | **R** (body sig 32-48b live) | called 233x in APPLY_GENE_TO_HORSE | D1 detour |
| `EVAL_DIPLOID_BLEND_B` | `0x1400a5df0` | **R** (body sig 32-48b live) | sibling of A; same record layout | D1 detour |
| `GENE_DEATH_DRIFT` | `0x1400c0650` | **R** (body sig 32-48b live) | `+/- 5` mutation rate writes | D1 detour (deferred) |
| `GENE_ALLELE_SWAP` | `0x1400c0390` | **R** (body sig 32-48b live) | iterates pop records, swaps slot[i] / slot[j] | D1 detour |
| `GENE_TABLE_XML_WRITER` | `0x1400a4880` | **R** (body sig 32-48b live) | string-builds gene XML, calls `<gene name=` | unused in v1 |
| `GENE_TABLE_LOADER` | `0x1400a3eb0` | **R** (body sig 32-48b live) | parses `<gene name=`; reads `genes.xml` | unused in v1 |
| `POP_XML_LOADER` | `0x1400a4fe0` | **R** (body sig 32-48b live) | parses `<pop name=`; reads `pop.xml` | unused in v1 |
| `GENE_ENGINE_CONSUMER` | `0x1400ab3c0` | **R** (body sig 32-48b live) | called immediately after APPLY_GENE | D5 trampoline |
| `CHECK_HORSE_ELIGIBILITY` | `0x1400dde40` | **H-stale** (hardcoded RVA points mid-function; needs re-derivation) | tired/old/young/hungry dispatch | unused in v1 |
| `RETIRE_HORSE_HANDLER` | `0x1400df280` | **H-stale** (hardcoded RVA points mid-function; needs re-derivation) | once-per-year retirement scan | unused in v1 |
| `COMPUTE_HORSE_PRICE` | `0x1400dcab0` | **H-stale** (hardcoded RVA points mid-function; needs re-derivation) | `(rand+nice+record)*years+deco` | unused in v1 |
| `CRISPR_LAB` | `0x140089510` | **H-stale** (hardcoded RVA points mid-function; needs re-derivation) | 13-state CRISPR machine | unused in v1 |
| `BREEDING` | `0x1400e0aa0` | **H-stale** (hardcoded RVA points mid-function; needs re-derivation) | BarnMating state machine | unused in v1 |
| `SAVE_WRITER` | `0x14006d674` | **R** (body sig 32b live-captured) | save_signatures test locks 16-byte prologue | D4 sidecar |
| `LOAD_GAME` | `0x14006e350` | **R** (body sig 32b live-captured) | same as above | D4 sidecar |
| `DRAW_PAUSE_STATUS` | `0x140066200` | **H-stale** (hardcoded RVA points mid-function; needs re-derivation) | contains the cheat-money write | unused in v1 |
| `TMX_MAP_PARSER` | `0x1400fe2e0` | **R** (body sig 32-48b live) | parses `<map`; reads `horsey.tmx` | unused in v1 |
| `POP_GENOME_BUILDER` | `0x140092820` | **H-stale** (hardcoded RVA points mid-function; needs re-derivation) | runtime spawner | unused in v1 |
| `DAILY_HORSE_EVENT` | `0x14002fe00` | **R** (body sig 32-48b live) | per-day per-horse event log | unused in v1 |
| `TRACK_STATE_MACHINE` | `0x14002d7c0` | **R** (body sig 32-48b live) | race lifecycle | unused in v1 |
| `CIRCUS_HANDLER` | `0x140039190` | **R** (body sig 32-48b live) | circus event | unused in v1 |
| `SUMO_HANDLER` | `0x14007b2e0` | **H-stale** (hardcoded RVA points mid-function; needs re-derivation) | sumo match | unused in v1 |
| `POWER_PLANT` | `0x1400693b0` | **H-stale** (hardcoded RVA points mid-function; needs re-derivation) | power-plant building | unused in v1 |
| `WORLD_ACTION` | `0x140107660` | **H-stale** (hardcoded RVA points mid-function; needs re-derivation) | world-action dispatcher | unused in v1 |
| `BALLOON_CONTROLLER` | `0x14010a5e0` | **H-stale** (hardcoded RVA points mid-function; needs re-derivation) | hot-air-balloon controller | unused in v1 |
| `HORSE_CONSTRUCTOR` | `0x1400aac50` | **R** (body sig 32b live-captured) | 32-byte body sig | D3.1 lifecycle |
| `HORSE_DESTRUCTOR` | `0x1400bf1e0` | **R** (body sig 32b live-captured) | 32-byte body sig | D3.2 lifecycle |
| `GENE_COMBINATOR` | `0x1400a2d70` | **R** (body sig 32b live-captured) | 32-byte body sig | D3.4 breeding |
| `HORSE_SAVE_WRITER` | `0x14006ecfb` | **R** (body sig 32b live-captured) | prologue + body sig | D4.1b sidecar |
| `HORSE_SAVE_LOADER` | `0x14006f031` | **R** (body sig 32b live-captured) | `add rcx, 0x2b8` is unique | D4.2b sidecar |

### Struct field offsets (N/A for pattern-scan)

`gs_offset::*` (20 fields) and `horse_offset::*` (10 fields) are not absolute addresses; they're integer constants compiled into accessor instructions. Drift is detected by reading nonsensical values, not by signature scan. Recovery is field-by-field through the same R3 trick: each field has a write site in the decomp; pattern-match the instruction, decode the displacement to get the field's current offset. Out of scope until a build is observed where a field offset has actually shifted.

### Recommended migration order (next batch)

1. **Cheat globals batch (NO_TIRE_TOGGLE, DEBUG_MODE_ACTIVE, DEBUG_LOG_GATE).** Three single-byte globals in `.data`. Each is written from a known site: the cheat-menu code writes 1 to NO_TIRE_TOGGLE, the typed-string handler writes 1 to DEBUG_MODE_ACTIVE, etc. Same R3 candidate-list shape. Why first: small surface, used by the Cheats tab right now.
2. **Lifecycle detour targets (HORSE_CONSTRUCTOR, HORSE_DESTRUCTOR, GENE_COMBINATOR, APPLY_GENE_TO_HORSE).** Already have R-parity sigs (32-byte body); flip the production reads. Why second: the parity contract already locks correctness.
3. **Save targets (SAVE_WRITER, LOAD_GAME, HORSE_SAVE_WRITER, HORSE_SAVE_LOADER).** R-parity exists via `r2_save_signatures`. Same flip. Why third: D4 sidecar pipeline depends on these.
4. **D1 detour targets (EVAL_DIPLOID_BLEND_A/B, GENE_ALLELE_SWAP).** Need fresh body sigs from the live image. Why fourth: lower iteration risk; D1 detours work today and are loaded in the arm path.
5. **Unused-in-v1 functions (everything else).** Migrate as features land; no urgency.

The candidate-list pattern from R3 generalizes: each item gets 2-4 candidate signatures (so a single MSVC reorder between builds doesn't break it), cross-validate via warning when candidates disagree, cache the result in a `OnceLock`.

## Current status (2026-05-15 session 2, latest commit `9fdeca9`)

### What shipped this session

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
| (pending commit) | **GAMESTATE_PTR deref fix.** Decomp re-read (`FUN_14009c6a0:46` heap-allocates + stores; `FUN_1400fd580:86` constructor stores; `FUN_14009c4e0:26` zeros) confirmed the slot is a pointer, not the struct. `gamestate::ptr()` now dereferences the slot and gates the result through pure helper `is_plausible_gamestate_pointer` (rejects null, sub-64KiB, kernel-space, misaligned). `resolve_gamestate_ptr_uncached` now sanity-gates resolver candidates at 0x1000 bytes so wrong-encoding sigs fall through to the (correct) hardcoded RVA. 6 new unit tests including a regression test pinning the exact `0x2400000000B` stale value the previous fix attempt observed. New `tests/gamestate_ptr_deref.rs` integration test (always-on shape check + `MODFORGE_EXPECT_LOADED`-gated bounded-value check). Unblocks Cheats tab, looks_loaded, every patch that reads gamestate offsets. Prior art [HorseyLiveTweaks `scene_resolver.cpp:11-33`](../research/prior-art/HorseyLiveTweaks/src/core/scene_resolver.cpp) shows the same store-site-anchor + structural-validate pattern in 20 lines; locked rule: read prior art before authoring address-resolution code. |

### Known broken: closed by deref fix

GAMESTATE_PTR drift (in-game UI lying about save state) was misdiagnosed in `ae333c6`. The slot RVA was correct all along; `gamestate::ptr()` was missing a deref. Closed by the pending-commit fix above. In-save live test still needs to be run user-side with `MODFORGE_EXPECT_LOADED=1` to lock the bounded-value contract.

## Current status (2026-05-15 session 1, after commit `5ff0cfc`)

### Test suite

| Category | Count | Status |
|---|---|---|
| Unit (modforge::patterns + sleuth) | 20 | green |
| Unit (horsey: genes / xml / sidecar) | 30 | green |
| Harness (smoke + dryruns + arm + r2 + catalog + build_info + save_sigs + save_find_entries + save_e2e_roundtrip) | 17 | all green; e2e proves ext alleles survive game restart |
| **Total** | **67** | **all green, no red contracts. 480-gene v1 is SHIPPABLE.** |

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

### Save-address re-derivation: DONE 2026-05-15 (`bd95252`)

Test-first 6-step plan executed; suite went from 1 red contract to all green.

| Step | Status | Notes |
|---|---|---|
| 1. Write failing test contract | ✓ done | `tests/r2_save_signatures.rs`. |
| 2. Probe live image for true entries | ✓ done | `tests/r2_save_find_entries.rs` widened to +/-2048-byte window with a tight MSVC-entry classifier. |
| 3. Author signatures | ✓ done | All 4 sigs distinctive; `HORSE_SAVE_LOADER` uses `add rcx, 0x2b8` (genome offset) as its uniqueness anchor. |
| 4. Migrate `targets::fn_addr` | ✓ done | `SAVE_WRITER`, `LOAD_GAME`, `HORSE_SAVE_WRITER`, `HORSE_SAVE_LOADER` corrected to re-derived RVAs. Comments cite probe + signature test. |
| 5. `dryrun_d3_d4::save_*` green | ✓ done | All 4 prologues match the classifier. |
| 6. End-to-end save/restart/reload proof | ✓ done (`e6abcad`) | `tests/r2_save_e2e_roundtrip.rs` proves ext alleles set in game 1 survive a full taskkill + relaunch + read_now cycle in game 2. 4 deterministic alleles across 2 horses round-trip exactly. The sidecar file persists on disk through the restart and is cleaned up after. **480-gene v1: SHIPPABLE.** |

True entry RVAs:

| Target | Stale (Ghidra) | True (probe-derived) | Offset |
|---|---|---|---|
| `SAVE_WRITER` | `0x14006dc80` | `0x14006d674` | -1548 |
| `LOAD_GAME` | `0x14006e480` | `0x14006e350` | -304 |
| `HORSE_SAVE_WRITER` | `0x14006ee10` | `0x14006ecfb` | -277 |
| `HORSE_SAVE_LOADER` | `0x14006f150` | `0x14006f031` | -287 |

The shipping build's Ghidra-decomp RVAs were stale by -277 to -1548 bytes. Way past the -16 convention. The probe + tight-classifier tooling (`r2_save_find_entries`) is the standing tool for any future drift.

### Next action

**480-gene v1 is SHIPPABLE.** All 6 steps of the save-address plan are done. The bestiary thesis is now real: a modder can author an ext gene, set it on a horse, restart the game, and the allele survives.

Pick from the queue (in priority order):

1. ~~**ImGui-in-modforge primitive.**~~ DONE 2026-05-15 (Phase A of [`docs/UI-CENTRALIZATION.md`](../../docs/UI-CENTRALIZATION.md)). Standalone Win32 + D3D11 + ImGui window in `modforge::ui::native` behind the `native-ui` Cargo feature. Live integration test `tests/native_ui_lifecycle.rs` green against Horsey.exe; `ui.native.spawn`/`shutdown`/`is_visible`/`stats` ops shipped. Tab render fns are SEH-wrapped. Roster UI + future QoL panels can now be authored as `TabDef`s with `modforge_ui_*` primitives.
2. **HK1 Shift+Click smart-transfer.** First user-locked QoL feature. Needs SDL input hook + horse-under-cursor resolver + transfer primitive (all new modforge primitives).
3. ~~**First bestiary species.**~~ DONE 2026-05-15. Ships `horsey-mod/bestiary/genes-extended.xml` with `BX_GIANT_BABY` at ext idx 0 (alleles `[0, 50, 100, 200]`, render `slot=0, mode=set`). Auto-deployed by `horsey-inject` next to the staged DLL; `worker_main` auto-loads at attach. Two locking tests: `tests/bestiary_v1.rs` (unit-level parse contract) and `tests/bestiary_v1_live.rs` (end-to-end through inject + HTTP, green against Horsey.exe). Authors flip every horse to allele 3 via `horse.ext.default_alleles.set { ext_gene_idx: 0, maternal: 3, paternal: 3 }` for the giant-baby effect. v2 needs Phase D2 (per-pop weights) or per-horse alleles via stable horse-id (D4.4) to scope effects per species rather than globally.
4. **Pasture auto-buy hay.** Real user-stated tedium. Needs store-buy + pasture-stock-read ops we don't have yet.
5. **Hand-author unique short signatures** for the existing green targets (replace 32-byte derived sigs in `r2_catalog` with body-byte + hand-picked-wildcard sigs that survive MSVC reorders).
6. **Retire hardcoded `fn_addr::*` consts** in favor of resolver-backed accessors. Mechanical refactor; parity test already in place.
7. **D6 mutation drift persistence.** Find whether vanilla persists `FUN_1400c0660` drift to genes.xml; mirror for the ext range if so.

### Completed this session

- ~~R1 build identification.~~ DONE (`fe74e6b`). `game.build_info` op shipped; image SHA-256 cached + exposed. r1_build_identification (2 tests) green.
- ~~Arm-and-observe tests for D5 + lifecycle + full-stack.~~ DONE (`574beb0`). 4 arm tests green: combinator, lifecycle, render trampoline, full-stack. Lifecycle in isolation captured 550 ctor / 3 dtor calls in 5s of menu idle. Full-stack arms 4 subsystems together; game survives.
- ~~R2 patternsleuth resolver shipped~~ DONE (`54d1c90`). `modforge::patterns::sleuth` wraps the crate; multi-target SIMD scan with first-match-wins per target. 3 harness tests green.
- ~~R2 catalog parity proven~~ DONE (`74846de`). 4 known-good targets (GENE_COMBINATOR, APPLY_GENE_TO_HORSE, HORSE_CONSTRUCTOR, HORSE_DESTRUCTOR) resolve identically via sleuth as via legacy hardcoded RVAs. Migration pattern locked.

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

### Known limitations / risks

- Untested against the live binary. -16 prologue adjustment is convention but not verified for the 5 new addresses.
- `LOAD_GAME = 0x14006e480` was already in `targets.rs` but the entry-point hasn't been prologue-verified.
- Save-loader detour writes ext alleles BEFORE the vanilla loader runs. If vanilla zeros `EXT_HORSE_GENOMES` keys (horse pointers) by re-allocating horses during load, the entries get orphaned. Lifecycle anchors should drop them on dtor, but order-of-operations needs in-game confirmation.
- `+0x690` ActiveGeneCount (HorseyLiveTweaks finding) might need updating for ext range. Unclear; not in v1.

---

## `sleep_safe_no_tire` patch: SHIPPED 2026-05-14

Patch-site discovery iterations (v1 RAX-only -> v2 all regs -> v3 proximity-anchor), the fallback plan (RIP-relative anchor + per-build constant), and the shared `patches::patch_bytes` infrastructure are all documented in [`HOOKING-STRATEGY.md`](HOOKING-STRATEGY.md) §10 "`sleep_safe_no_tire` patch".

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
      See [`GENE-CATALOG.md`](GENE-CATALOG.md) Part 3 "Locked design decisions".
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

D7.2 (`genes-extended.xml` parser + live reload) shipped; documented in [`GENE-CATALOG.md`](GENE-CATALOG.md) Part 3 "XML authoring format". D7.3 (`genes.ext.dump` op) shipped as part of D0.6; see GENE-CATALOG Part 3 "HTTP control-plane ops".

Open:

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

D9.1 (extended layout documented in GENE-CATALOG.md Part 3): SHIPPED.
D9.4 (sidecar file format documented in SAVE-FORMAT.md): SHIPPED.

Open:

- [ ] **D9.2.** Write a "How to author a new gene" guide aimed at non-engineers: `genes-extended.xml` format, `mode="..."` options, working examples.
- [ ] **D9.3.** Decide rollout: ship the patch infra with zero extended genes by default and let authors add them via XML, OR ship a starter pack of 20-50 useful new genes.

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
