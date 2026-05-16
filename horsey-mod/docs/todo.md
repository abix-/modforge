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
- Field offsets: **R4 done, 29/37.** All `must` + `should` items resolved. Migrated via patternsleuth + in-process pattern decode: `gs_offset::year/sleeps/money/horses_begin/horses_end/live_horses_begin/live_horses_end/sim_horses_begin/sim_horses_end/map_width/map_height/alloc_size/roster_stride`, `horse_offset::ctx_offset/tired_flag_a/tired_flag_b/on_track_flag/breeding_flag/age/max_age/alloc_size/litter_size_stat/name_id/skill/no_tire_loop_entry/no_tire_loop_size/type_or_species`. Two duplicate patch-site hardcodes in patches.rs (0x205/0x206) now read the resolvers. Remaining 9 fields are `H-gb-low` (diag-only, no unique anchor, drift harmless).

**Open work in this section:**
- [x] **R4 toolkit + first 10 resolvers shipped.** `modforge::research` library (in-process + harness variants), 4 generic recipes (decode_field_offset_via_string, decode_imm_in_window, decode_disp_pair_with_delta, decode_imm_at_call_site). 10 field offsets migrated (see Hardcoded-constants inventory below for which).
- [ ] **Apply R4 to remaining ~12 field offsets.** Recipes proven; per-field work is authoring the right anchor (format string, allocator call site, surrounding xref) and decoding the operand. **Plan-of-attack:** see "R4 remaining: research plan" below.
- [ ] **Adopt 5 HLT patterns** (see "Learn from HorseyLiveTweaks" below): structural-plausibility validation, vtable check, direct vanilla-fn calls, SEH wrapping of vanilla calls, injector elevation auto-detect.
- [ ] Author second candidate signatures for every resolver so a single MSVC reorder between builds doesn't break it (current Definition of Done #2; one sig each today).
- [ ] CI / pre-commit refuses to ship any new `pub const usize = 0x140...;` outside `targets::resolve::*` candidate sigs (Definition of Done #4).

### R4 remaining: research plan (2026-05-15)

12 H-gb field offsets are left after this session's batch (25/37 done), but only **4 are on the production hot path or public surface** (3 `must`, 1 `should`). The remaining 9 are diagnostic-only (`gamestate.diag` dump) and can stay `H-gb-low`. Core insight: they fail not because they're hard to pattern-anchor, but because we don't know WHICH function accesses them. The decomp tells us. The HTTP gives us live verification. Once anchor function is identified, R4 recipe is mechanical.

We have: decompiled source in `horsey-mod/research/decompiled/`, running game, full HTTP introspection (`mem.scan_rdata`, `patterns.sleuth.scan_all`, `mem.find_xrefs`, `patterns.read_bytes`, `gamestate.diag`).

Remaining (by criticality):

- **must** (3): roster stride 0x24, no_tire FN_RVA, no_tire FN_SIZE
- **should** (1): TYPE_OR_SPECIES 0x1c
- **low** (9, deferred): FRAME_TICK gs+0x254, SUPPLIES_START 0x31c, 8x FIELD_* 0x37c..0x440

#### Phase A: decomp grep pass (no game; pure offline)

For each remaining target, grep `research/decompiled/all_functions.c` (and per-function files) for the offset literal. Goal: map field -> list of accessor functions, then pick the smallest / most-anchored one.

| Target | Grep term | Expected output |
|---|---|---|
| `TYPE_OR_SPECIES` 0x1c | `+ 0x1c)` / `[0x1c]` | dispatchers that cmp horse type |
| `FIELD_37C..0x440` (8 fields) | `+ 0x37c)` etc. | producer + consumer per field |
| `SUPPLIES_START` 0x31c | `+ 0x31c)` / `+ 0x344)` | supply-array loop entries |
| `FRAME_TICK` gs+0x254 | `+ 0x254)` in GameState ctx | per-frame increment site |
| roster stride 0x24 | `* 0x24` / `imul ... 0x24` | roster iterators |

Deliverable: a markdown table appended below listing each target's anchor candidates with confidence ranking. ~30 min of grep work.

#### Phase B: resolve missing anchor functions (R2 work)

Some anchor functions from Phase A won't already be in `targets::resolve::*`. For each new anchor:

1. Check decomp for unique prologue / body signature.
2. Author R2 sig in `targets::resolve::*` following the existing pattern (function entry sig with optional alias-check).
3. Validate via existing `r2_*` tests.

Likely new anchors needed: `roster_iterator` (`FUN_14006d610`), `frame_tick_handler` (unknown function), `supply_loop` (unknown).

#### Phase C: R4 resolvers (mechanical with anchor in hand)

Once anchored, each resolver is one of the four existing recipes:

- **Disp-load histogram** in function body window (already used 8x). For TYPE_OR_SPECIES, FIELD_*, SUPPLIES_START, FRAME_TICK.
- **Adjacent-pair delta** for stride if iterator does `lea r, [r+r*8+r*4]` or similar.
- **Call-site lookback** (already used 2x for alloc sizes). For stride `imul reg, reg, 0x24`.
- **Format-string xref** (already used 4x). Unlikely useful for remaining (no format strings reference these fields).

#### Phase D: `no_tire` FN_RVA + FN_SIZE (bootstrap improvement)

Self-contained. Doesn't depend on Phase A. Recipe:

1. Add `modforge::research::find_function_bounds_via_int3(addr_inside, lookback, lookahead) -> Option<(start, end)>`. Walks back/forward through `.text` until 2+ consecutive `0xcc` bytes (MSVC inter-function padding).
2. In `horse_offset::resolve_tired_pair`, capture the address of the matched pair (currently discarded after disp decoding).
3. New `resolve::no_tire_loop()` calls `find_function_bounds_via_int3(pair_addr, 4096, 4096)` -> (FN_RVA, FN_SIZE).
4. Migrate `patches::sleep_safe_no_tire::FN_RVA` and `horse_offset::NO_TIRE_LOOP_FN_RVA` to read the resolver.

Standalone test: assert resolved start/size match hardcoded.

#### Phase E: semantic discovery for unknown `FIELD_*` (8 mystery fields)

The hardest. Some may be transient render state without a useful semantic. Approach:

1. **Static**: per Phase A grep, classify each as { read-only consumed by X, written-only by Y, read-and-written in loop Z }.
2. **Dynamic**: use `gamestate.diag` HTTP op to dump these fields. Snapshot before/after specific game actions (race, sleep, save, load, day-tick). Diff identifies which field changes with which action -> semantic.
3. **Categorize**:
   - Sub-struct anchors (start of another array): pattern-resolve as ranges.
   - Policy/config fields written once during load: anchor on `LOAD_GAME` body.
   - No clear semantic: mark `H-unknown` and accept drift risk (low if not on hot path).

Realistic: 1-2 hours per field of mixed decomp + live observation.

#### Order of attack (recommended)

1. **Phase D first**. Self-contained, ships the no_tire bootstrap improvement (2 targets) in one session. Validates the `find_function_bounds_via_int3` helper, which we'll need elsewhere.
2. **Phase A**. 30 min grep gives the anchor map for everything else.
3. **Phase C** for already-anchored targets. Likely 3-4 quick wins from Phase A.
4. **Phase B + C** for new anchors. Each is ~30 min from sig to R4.
5. **Phase E**. Last; some `FIELD_*` will resolve naturally during Phase A (if found all written in one constructor, pattern-anchor on that). Truly-mystery ones get marked `H-unknown`.

Practical final coverage: **29/37** (all must + should resolved). The 9 `H-gb-low` diag-only fields stay tracked-but-not-migrated; upgrade their classification if they ever become hot-path consumers.

### Hardcoded-constants inventory (zero-hardcoding audit, 2026-05-15)

Every magic integer baked into Rust source code. User-locked: nothing is out of scope. Audit, classify, then decide what to migrate.

Status codes:
- **R**: pattern-resolved at runtime via patternsleuth.
- **H-gb-must**: hardcoded, GAME-BINARY DERIVED, ON HOT PATH. Drift breaks the mod (patch fails, corrupted reads/writes). Migration is required.
- **H-gb-should**: hardcoded, GAME-BINARY DERIVED, public surface (HTTP read ops). Drift gives wrong diagnostic value; no patch breaks. Migration is recommended.
- **H-gb-low**: hardcoded, GAME-BINARY DERIVED, diagnostic-only (dumped by `gamestate.diag` and nothing else). Drift is harmless. Migration deferred.
- **H-gb**: hardcoded, GAME-BINARY DERIVED, criticality not yet classified. Treat as `must` until reviewed.
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
| `gs_offset::FRAME_TICK` 0x254 | targets.rs:66 | struct field offset | **H-gb-low** | diag-only (`gamestate.rs:320`); drift = wrong diag value, no production impact |
| `gs_offset::sim_horses_begin/end()` 0x260/0x268 | targets.rs | struct field offset (2) | **R** | HLT labels `kOffSimHorsesBegin/End`; adjacent qword-load pair (delta 8) in `[0x250, 0x270]` window |
| `gs_offset::money()` 0x308 | targets.rs | struct field offset | **R** | cheat-money `add [base+disp], 1000` literal in DRAW_PAUSE_STATUS |
| `gs_offset::year()` 0x314 | targets.rs | struct field offset | **R** | "Year %d" pause-menu format string + `mov r8d, [base+disp]` |
| `gs_offset::sleeps()` 0x318 | targets.rs | struct field offset | **R** | debug pause-menu format string + `mov r9d, [base+disp]` |
| `gs_offset::SUPPLIES_START` 0x31c | targets.rs:76 | struct field offset | **H-gb-low** | diag-only (`gamestate.diag` dump); drift harmless |
| `gs_offset::FIELD_37C/39C/410/414/415/418/41C/440` | targets.rs:77-84 | struct field offset (8) | **H-gb-low** | diag-only (`gamestate.diag` dump, lines 181-188); semantic unknown; drift harmless |
| `gs_offset::horses_begin/end()` 0x280/0x288 | targets.rs | struct field offset (2) | **R** | adjacent qword-load pair (delta 8) in `[0x200, 0x300]` window |
| `gs_offset::map_width/map_height()` 0x278/0x27c | targets.rs | struct field offset (2) | **R** | HLT labels `kOffMapWidth/Height`; adjacent r32-load pair (delta 4) in `[0x270, 0x290]` window |
| `horse_offset::type_or_species()` 0x1c | targets.rs | struct field offset | **R** | `cmp dword [horse+disp8], imm8` dispatcher sites (`83 7? <disp8> <imm8>`) across `.text`; histogram across `imm in {1,2,4,6}` with modrm-filter (cmp /7, non-rsp/rbp base); top in `[0x10, 0x80]` |
| `horse_offset::name_id()` 0x1f8 | targets.rs | struct field offset | **R** | `(bails)` retire-handler format string + `8b 8? <disp32>` (mov ecx, [horse+disp32]) before `call name_resolve`; filter excludes age/max_age |
| `horse_offset::age()` 0x1fc | targets.rs | struct field offset | **R** | `(bails) age %d ch %d` format string + `44 8b` r9d-load (4th printf arg) |
| `horse_offset::max_age()` 0x200 | targets.rs | struct field offset | **R** | derived `age + 4` (adjacent int32 in release-to-wild cmp) |
| `horse_offset::on_track_flag()` 0x204 | targets.rs | struct field offset | **R** | derived `tired_flag_a - 1` from no_tire pair anchor |
| `horse_offset::breeding_flag()` 0x207 | targets.rs | struct field offset | **R** | derived `tired_flag_b + 1` from no_tire pair anchor |
| `horse_offset::tired_flag_a/b()` 0x205/0x206 | targets.rs | struct field offset (2) | **R** | adjacent byte-zero pair inside no_tire per-frame loop |
| `horse_offset::skill()` 0x21c | targets.rs | struct field offset | **R** | `(useless)` retire-handler format string + `8b` r32 loads in ±256B window; histogram top in `[0x210, 0x240]` |
| `horse_offset::litter_size_stat()` 0x254 | targets.rs | struct field offset | **R** | `8b` r32-from-disp32 loads within BREEDING body 8KB; histogram top in `[0x240, 0x270]` (both parents read it) |
| `gs_offset::live_horses_begin/end()` 0x130/0x138 | targets.rs | struct field offset (2) | **R** | adjacent qword-load pair (delta 8) in `[0x100, 0x200]` window |
| `gs_offset::roster_stride()` 0x24 | targets.rs / gamestate.rs | struct stride | **R** | call-site lookback at `e8 X<HORSE_SAVE_WRITER>`: `6b ?? <imm8>` (imul r32, imm8) inside iterator loop within 128 bytes; histogram top |
| `horse_offset::ctx_offset()` 0x2b8 | targets.rs | struct field offset | **R** | `add rcx, imm32` inside HORSE_SAVE_LOADER body (256-byte window) |
| `horse_offset::no_tire_loop_entry/size()` 0x1400ceb60 / 2502 | targets.rs / patches.rs | function entry + size | **R** | global scan for unique adjacent tired-pair byte-zero stores; `find_function_bounds_via_int3` walks back/forward through MSVC `0xcc` padding; bootstraps the no_tire patch + all 4 downstream tired-pair resolvers |
| Patch-site offset 0x206 (TIRE_FLAG_B store) | patches.rs | struct field offset | **R** | now reads `horse_offset::tired_flag_b()` resolver |
| Patch-site offset 0x205 (TIRE_FLAG_A store) | patches.rs | struct field offset | **R** | now reads `horse_offset::tired_flag_a()` resolver |
| `gs_offset::alloc_size()` 0x448 | targets.rs | struct size | **R** | anchor on unique `mov [rip+disp32], reg` store of GAMESTATE_PTR; lookback 256B for `b9 <imm32>`; histogram top |
| `horse_offset::alloc_size()` 0x498 | targets.rs | struct size | **R** | call-site lookback at `e8 X<HORSE_CONSTRUCTOR>`: `b9 <imm32>` (mov ecx, alloc size) within 32-byte preamble; histogram top |

**H-gb migration progress: 29 done / 9 remaining (all `H-gb-low`).**

Done: `gs_offset::year/sleeps/money/horses_begin/horses_end/live_horses_begin/live_horses_end/sim_horses_begin/sim_horses_end/map_width/map_height/alloc_size/roster_stride`, `horse_offset::ctx_offset/tired_flag_a/tired_flag_b/on_track_flag/breeding_flag/age/max_age/alloc_size/litter_size_stat/name_id/skill/no_tire_loop_entry/no_tire_loop_size/type_or_species`, patches.rs duplicate sites for 0x205/0x206 now read the resolvers.

**All `must` + `should` items done.** Remaining 9 are `H-gb-low`:

- FRAME_TICK (gs+0x254), SUPPLIES_START (0x31c), 8x FIELD_* (0x37c..0x440).

These are diag-only fields dumped by `gamestate.diag` and not used anywhere else. They have no unique pattern-anchor: each field's accessors are either (a) generic `mov reg, [ptr+disp32]` indistinguishable from any other field load, or (b) localized to one obscure handler we haven't resolved. Distinguishing them from sibling fields requires either:

1. A bespoke per-field signature based on a specific imm-write or distinctive context, OR
2. Resolving every accessor function to R2 first, then anchoring there.

Both have real cost. The fields drift harmlessly (wrong values in `gamestate.diag` dump, no patch breaks, no save corruption). Accepted drift risk: HIGH (these are exact-offset reads that WILL silently return wrong data on game updates), but BLAST RADIUS: LOW (consumers are diag-only).

**Decision: stop here at 29/37 = 100% of `must` + `should`.** Revisit if any `H-gb-low` field becomes a hot-path consumer.

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

- **Migrate (H-gb):** 10 done, ~27 remaining -> R4 work below.
- **Not migrating (H-alg / H-os / H-design / H-test):** ~25 constants, all intentional. Audited and acknowledged.

### Learn from HorseyLiveTweaks (audit 2026-05-15)

After reading all of HLT's `pattern_scan.cpp`, `pattern_targets.cpp`, `offsets.h`, `scene_resolver.cpp`, `child_blend_hook.cpp`, and `injector_main.cpp`, the following patterns are strictly better than what we have and worth porting.

#### License posture (HLT is GPL v3; we are GPL v3)

Both projects ship under GPL v3 (HLT's `LICENSE`; our workspace `LICENSE`). No collision: GPL v3 explicitly permits derivative works under the same license. We can lift code, pattern strings, offset values, or whole modules from HLT directly.

In practice we still PREFER reimplementing in Rust:
- Cross-language ports are usually cleaner than line-for-line translations.
- Our architecture (patternsleuth + xref constraint + multi-target scan) is materially different from HLT's hand-rolled byte loop; direct ports often regress on our infrastructure.
- Engineering hygiene: understand the algorithm before copying.

But direct ports are allowed and don't need clean-room hedging. CREDIT them in commit messages + the prior-art doc either way.

#### Patterns to port

##### 1. Structural-plausibility validation of dereffed pointers

HLT's `is_probable_world_root()` (scene_resolver.cpp:36-52) doesn't just check the pointer is heap-shaped. It reads multiple fields off the candidate object and checks bounded ranges:
- `active_scene_id` in `[-1, kMaxSceneSlots)` (i.e. -1..255).
- `scene_table` pointer non-null AND its `[neighbor_scene_id]` slot readable.

Only if BOTH pass is the candidate accepted as the live World Root. Catches the case where the slot deref returns a stale/dead heap object whose first 8 bytes happen to look like a pointer but whose later fields are garbage.

Our current `gamestate::is_plausible_gamestate_pointer()` only checks heap-shape. Necessary but not sufficient.

**Action items:**
- [ ] Add `gamestate::looks_like_live_gamestate(ptr)` that reads bounded structural invariants (year in `[1, 10000]`, roster pointer pair via `roster_span_looks_loaded`, money <= 100M).
- [ ] Promote `gamestate::ptr()` to call it. If the dereffed pointer fails structural checks, fall through to a re-scan or return 0.
- [ ] Same treatment for any future singleton pointer (e.g. world-root if/when we use it).

##### 2. Vtable-pointer validation for typed objects

HLT's `is_neighbor_scene_ptr_usable()` (scene_resolver.cpp:72-81) reads the candidate object's first 8 bytes as a vtable pointer and compares against the EXPECTED vtable RVA. C++ objects always have their vtable as field 0; matching it confirms the object's TYPE.

We don't do this. GameState is a C++ class with a vtable (`FUN_1400fd580:54` stores `&PTR_FUN_140313558` at `*param_1`).

**Action items:**
- [ ] Find the GameState vtable RVA (likely `0x140313558` per decomp; verify).
- [ ] Pattern-resolve it via R3 (anchor on the constructor's `mov [param_1], <vtable>` instruction; decode disp32).
- [ ] Add vtable check to `looks_like_live_gamestate`: dereffed pointer's first 8 bytes must equal the GameState vtable's runtime address.

##### 3. Direct-call vanilla functions via fn-pointer cast

HLT calls vanilla functions DIRECTLY without setting up a detour, just by casting `exe_base() + kRva*` to the function pointer type (child_blend_hook.cpp:31). Useful when we want to INVOKE vanilla logic (e.g. their `shuffle_int_array`, `copy_gene_lane_pairs`) rather than intercept it.

We already do this in `patches/save_sidecar.rs` (calling the original via the trampoline). But for vanilla helpers we just want to call (not hook), an explicit `targets::fn_addr::FOO as TyA = transmute(targets::resolve::foo()?)` pattern is cleaner than going through MinHook.

**Action items:**
- [ ] Add a tiny `modforge::vanilla::call_fn::<F: Function>(addr) -> F` helper that wraps the transmute safely.
- [ ] Use it when calling vanilla helpers from inside our patches/detours.

##### 4. SEH-wrap any call into vanilla code

HLT wraps vanilla-function calls in `__try` (child_blend_hook.cpp around `copy_gene_lanes` / `rebuild_horse`). A crash inside vanilla doesn't kill their DLL; the SEH filter logs + bails.

We have SEH wrappers in `modforge::winproc` for UI render callbacks but don't blanket-wrap our trampolines or vanilla-call sites. Worth auditing.

**Action items:**
- [ ] Audit all detour/trampoline call sites (`patches/combinator.rs`, `lifecycle.rs`, `render_trampoline.rs`, `save_sidecar.rs`) for SEH coverage.
- [ ] Wrap each call into vanilla with a `modforge::seh::guard(|| { ... })` helper that returns `Result<T, SehError>`.

##### 5. Injector elevation auto-detection + re-launch

HLT's injector (injector_main.cpp top) detects whether the target process needs elevation; if yes, the injector re-launches itself elevated via ShellExecute.

`horsey-inject` currently doesn't do this. If a user runs `horsey-inject` from a non-elevated shell and Horsey.exe is running elevated, the injection fails silently (or with a permission error).

**Action items:**
- [ ] Audit `horsey-inject/src/main.rs` (or wherever the injector lives). If it doesn't already re-launch on `OpenProcess(PROCESS_VM_WRITE)` failure, add the elevation check.

#### What HLT does WORSE than us (do not regress)

- Hand-rolled 94-line byte-loop scanner vs our SIMD patternsleuth (orders of magnitude faster on full-image scans).
- All 46 struct field offsets HARDCODED. No R4 migration. Game updates silently corrupt their writes.
- No xref-constraint scanning (`X<addr>`); literal-byte scan only.
- No `.rdata` scan; can't anchor on string literals.
- One-shot resolution only. No fallback chain, no sanity gate, no cross-validation between multiple sigs per target.

#### Cross-validation already done

`PRIOR-ART-HorseyLiveTweaks.md` confirms every offset we share with HLT matches their value (kWorldRootPtrRva = 0x3FB0D8 = our GAMESTATE_PTR, kOffSceneHorseVecBegin = 0x130 = our LIVE_HORSES_BEGIN, etc.). Good independent confirmation we're reading the same binary correctly.

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

### Findings session 2026-05-15/16: Horses tab live-count + Horsey binary update

Authoritative catalog of every horse-bearing memory location: [`HORSE-PLACES.md`](HORSE-PLACES.md). This section captures the chase that produced it.

#### 1. Horsey binary was updated between sessions

- `image_sha256 = 0a2689fe98232a50b9cf5c83c7c76dc179912bef246b1d8014d918a77d390253`
- `exe_size = 4374528`, `image_base = 0x7ff6ab0a0000` in this run.
- Decomp index references the older build. Re-decomp or accept drift on non-anchored consts.

#### 2. Resolver sanity-gate self-defeating bug (FIXED in this session)

Old `targets::resolve::resolve_gamestate_ptr_uncached`:
```
let delta = resolved.abs_diff(hardcoded); if delta > 0x1000 { return None; }
```
Hardcoded RVA was the cross-check. When Horsey ships an update that shifts the GameState slot more than 4 KB, the gate rejected the CORRECT new resolution and silently fell back to the stale hardcoded, which then pointed at unrelated `.data` (we observed tile data at the stale slot, raw value `0xfffffff90000000a` clearly not a heap ptr).

Fixed: replaced with `is_addr_readable(resolved) && (resolved & 7) == 0`. Pattern is well-anchored on the 1.0f literal write in the constructor, so a false match is unlikely.

Action items:
- [ ] Audit every OTHER `*_uncached` resolver in `targets.rs` for the same self-defeating "compare to hardcoded" pattern. Replace each with `is_addr_readable` + alignment.
- [ ] When the resolver succeeds, ALSO log `R3 GAMESTATE_PTR drift detected: hardcoded=X new=Y delta=Z` so we know the hardcoded is stale.
- [ ] Update the hardcoded `GAMESTATE_PTR` const to the new value once stable.
- [ ] Once we have a known-builds manifest, refuse to attach when the resolver delta says hardcoded is stale and no manifest entry matches the current SHA.

#### 3. Scene table layout decoded (cross-validated with HLT)

HLT prior art (`research/prior-art/HorseyLiveTweaks/src/core/offsets.h`):
```
kRootSceneTable      = 0x438   // on GameState: ptr to scene table
kRootActiveSceneId   = 0x25C   // on GameState: i32 active scene id, range [-1, 256)
kMaxSceneSlots       = 256
kOffSceneHorseVecBegin = 0x130 // on scene struct
kOffSceneHorseVecEnd   = 0x138
kNeighborSceneId     = 31
```

`*(GS+0x438)` is an array of 256 scene pointers, each pointing to a scene struct with a `vector<Horse*>` at `+0x130/+0x138`. The active scene is at index `active_scene_id`.

Our code now follows this chain (see `gamestate::owned_stable`).

#### 4. Slot 0x00 of the scene table holds the 3 owned horses

`gamestate.scan_438_slots` dump in user's save (3 horses owned, `active_scene_id = -1`):

| slot | count | likely role |
|---|---|---|
| 0x00 | **3** | **Owned-horse list (matches user's 3 owned)** |
| 0x08..0x38 | 5 each | Race lanes (per `FUN_140105260` decomp) |
| 0xb0 | 4 | unknown |
| 0xd0 | 3 | another 3-horse mirror (selection? scene?) |
| 0xe0 | 2 | unknown |
| 0x70..0xc8 (singletons) | 1 each | per-screen selected horse |
| 0x120 | 5 | "copy all horses" source per `FUN_140107550`; race-context, not stable |

Action items:
- [ ] Change `owned_stable` to read scene table slot 0x00 unconditionally (NOT `slot_offset = active_scene_id*8`). When `active_scene_id = -1` (overworld / no neighbor scene), the per-scene chain returns None even though the owned list IS available at slot 0x00.
- [ ] Verify by naming the 3 horses uniquely and confirming they all appear under slot 0x00. Test `tests/find_horse_tomtato.rs` exists but is parked.
- [ ] Re-validate slot 0xd0: is it the "owned horses in current scene" subset, or a redundant mirror?

#### 5. Horse name string is NOT inline in the Horse object

`tests/find_horse_tomtato.rs` searches the full 0x498 bytes of each Horse via `patterns.read_bytes`. ASCII "tomtato" not present in the object body. The `name_id` field at horse+0x1f8 (u32) indexes a global name table.

Action items:
- [ ] Find the global name table. Either via decomp (grep for `name_id` consumer function near horse format strings) or via memory scan with a unique horse name as ground truth.
- [ ] Add `horse::name_string(horse_ptr) -> Option<String>` that goes through the table.
- [ ] Surface the resolved name string in `gamestate.owned_horses` (replace `name_id: u32` with `name: String`).

#### 6. patterns.read_bytes can crash the game (PARTIALLY FIXED)

Calling `patterns.read_bytes` with a non-readable address used to fault, kill the HTTP worker, and disconnect every client. Added a `is_addr_readable` precheck on both endpoints. Kept the game alive across multiple subsequent runs.

Still vulnerable: any other op that does unguarded raw deref of caller-supplied addresses. Audit all `gamestate.*` / `horse.*` / `mem.*` ops.

#### 7. Old `live_horse_count/live_horse_ptr` was always wrong (SUPERSEDED)

Reading `*(GS+0x130)` directly on GameState returned 0 in every state. The real per-scene horse vector lives on a SUB-STRUCT reached via the `GS+0x438` table. Our `live_horse_*` functions are superseded by `owned_horse_*`. Remove old API once UI fully migrated.

#### 8. Roster (GS+0x280/+0x288) is the global horse POOL, not owned

26 entries in earlier save, 28-29 in this save. Inline 36-byte summary records (no Horse* pointers in entries). Stride 0x24 confirmed via decomp at `:53951` (`/0x24`). Likely contains all named horses ever encountered: player + NPCs + ancestors. Useful as global ID pool, not as owned-list.

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
