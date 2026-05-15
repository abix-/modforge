# Address resolution across game updates

> **Authoritative on:** how horsey-mod resolves Horsey.exe addresses in a way that survives game updates. Living plan; promotes to implementation as pieces land.

## Table of contents

- [Why this exists](#why-this-exists)
- [What other shipping mods do](#what-other-shipping-mods-do)
- [The plan](#the-plan)
- [Tooling we already have](#tooling-we-already-have)
- [Ordering rationale](#ordering-rationale)
- [Open questions](#open-questions)
- [What's in the repo right now (state at 2026-05-14)](#whats-in-the-repo-right-now-state-at-2026-05-14)
- [Game install location (Steam)](#game-install-location-steam)

---

## Why this exists

Horsey is a live Steam game on the developer's update path. The
2026-05-14 session lost half a day to a build that shipped between
two decomp passes ~4 hours apart:

- Decomp at 20:44 (May 13). Function `FUN_14009f680` lives at
  RVA `0x14009f680`. We bake that into `targets::fn_addr`.
- Steam ships an update at ~00:25 (May 14).
- We inject the mod at ~22:00. The byte at RVA `0x14009f680` in
  the new build is mid-function code (`LEA EBP, [RAX-0x428]`).
  retour happily installs a JMP. Game crashes inside vanilla at
  offset +13 with `bad_addr=0xffffffffffffffff`.

This will keep happening. The plan below makes it cheap to
absorb. Ideally automatic at attach, with sub-second
re-resolution and a clear failure mode when a function has
genuinely moved (rename, rewrite) rather than just shifted.

## What other shipping mods do

- **SKSE Address Library** (Skyrim SE). Community-maintained
  database mapping stable per-symbol IDs to per-version offsets.
  Plugins reference `REL::ID(12345)` and a runtime loader picks
  the right offset for the loaded build. Survives updates
  cleanly as long as the symbol stays in the binary.
- **patternsleuth** (UE4SS-blessed, in our workspace deps
  already). Pattern-scans the loaded image at runtime against
  byte signatures defined per function. Survives updates as
  long as the prologue bytes don't change.
- **MinHook + Cheat Engine AOB**. Manual pattern scan via AOB
  ("array of bytes") with `?` wildcards for the bytes that
  shift between builds. Tedious to author by hand; cheap to
  run.
- **Reloaded-II SigScan**. Same shape as patternsleuth, with a
  curated lookup table maintained by mod authors.

For us, **patternsleuth** is the right pick: it's a Rust crate,
it's already pinned in `workspace.dependencies`, and the
problem shape matches (a few dozen functions, all single-shot
resolution at attach).

## The plan

### Phase R1: Build hash + identification (do FIRST)

Trivial; unblocks everything else. Goal: every attach logs the
exact build we're on, so when something breaks we can tell
"this is the build we tested" vs "this is a new build."

**Status 2026-05-15:** PARTIAL. Build identification (image SHA-256)
is open. But the underlying pattern-scan primitive is now SHIPPED at
the modforge level, see "Patterns module shipped" below.

### Pattern-scan primitive (modforge::patterns, shipped 2026-05-15)

A hand-rolled pattern scanner now lives in `modforge::patterns` as a
reusable primitive for every game-mod that depends on modforge. It is
NOT the full patternsleuth integration; it is the minimum surface to
prove the test-driven address-resolution workflow works end-to-end.

What ships:

- `modforge::patterns::parse(sig: &str)`. IDA-style `48 89 ?? 24 ??`
  parser. Two-hex-digit tokens or `??` wildcards.
- `modforge::patterns::find_first(&[u8], &str)` / `find_all`.
  byte search with wildcards over an arbitrary haystack.
- `modforge::patterns::scan_loaded_image(sig)`. Walks PE headers of
  the loaded `.exe` via `GetModuleHandleW(NULL)`, finds the `.text`
  section, scans it, returns the matched runtime address.
- 17 unit tests covering parser correctness, byte search at
  start/middle/end, wildcards, multiple matches, and regression
  fences against known Horsey prologues.

How tests drive it (horsey-mod):

- HTTP op `patterns.scan {sig}` runs `scan_loaded_image` INSIDE the
  game process and returns the match. Tests cannot scan from the
  test process (wrong image base + wrong .text bytes).
- HTTP op `patterns.read_bytes {addr, n}` returns hex-byte string;
  used by tests to derive signatures from known-good function entries.
- `horsey-mod/tests/pattern_scan_runtime.rs`: 3 green tests proving
  self-derived signatures round-trip for `GENE_COMBINATOR` and
  `APPLY_GENE_TO_HORSE`, and absent signatures return None.

### Phase R2: patternsleuth resolver

Promote the hand-rolled `modforge::patterns` to a full
`patternsleuth`-backed resolver. The `patternsleuth` crate is
already pinned in `workspace.dependencies` (git rev
`9573c52e8227af1d219782353e0ee6e9c6ec940c`, features
`process-internal` + `image-pe`).

Goal: replace fixed `targets::fn_addr::*` constants with a runtime
resolver that lives in modforge so every game-mod (horsey-mod,
schedule1, grounded2) uses the same API.

Concrete plan:

1. Add `modforge::patterns::sleuth` submodule wrapping the
   `patternsleuth` crate. Expose:
   - `Resolver` builder with `add_target(symbol, &[signatures])`
     (multiple signatures per symbol; first match wins).
   - `resolve_all() -> HashMap<&str, Option<usize>>` running all
     scans at once (patternsleuth does SIMD-accelerated multi-pass).
2. Add per-target signature catalog. Per game, a `targets/patterns.toml`
   (or hardcoded `&[(symbol, &[sigs])]`) is the source of truth.
3. Per game's `targets.rs` switches from `pub const SYMBOL: usize =
   0x...` to `pub fn symbol() -> usize` reading from a resolved map.
   Falls back to the hardcoded RVA when MODFORGE_NO_PATTERN_SCAN=1
   so tests can compare both paths.
4. Live `fn_addr::*` constants become a fallback layer used only when
   the resolver fails to find a match.
5. Failing-test-first contract: write
   `tests/r2_save_addresses_resolved_via_sleuth.rs` asserting that
   the 4 save addresses (currently red in `dryrun_d3_d4`) get found
   via patternsleuth signatures. Test stays red until R2 is done.


### Phase R3: Signature authoring workflow

Make it 1-command to derive a new signature after a decomp pass.


### Phase R4: Graceful degradation

When a pattern fails to match (function genuinely rewritten),
the mod must NOT silently install a detour at a stale address.


### Phase R5: Auto-decomp on detected build change

The expensive piece. Only worth it if game updates are weekly+.


## Tooling we already have

- **`horsey-mod/research/decompile.py`**. Pyghidra full-binary
  decompiler. ~30-60 min for a Horsey.exe-sized image. Outputs
  to `C:/code/horsey-mods/decompiled` (the sister repo); we
  mirror into `grounded2mods/horsey-mod/research/decompiled` after.
- **`patternsleuth` crate**. In `workspace.dependencies`,
  unused so far. Has `process-internal` + `image-pe` features
  enabled.
- **`targets::rebase`**. Already handles ASLR. Will keep
  working unchanged once the input is a resolved RVA instead
  of a baked-in one.
- **SEH + panic logging**. Already in. When a stale address
  causes a crash, we already get the diagnostic line; this
  plan just shortens the window before that diagnostic appears.

## Ordering rationale

R1 is the smallest unblock and gives us per-session "what
build am I on" awareness. We can do R1 in this session.

R2 is the main payoff. After R2 lands, a game update either
(a) doesn't move our hooked functions in a way the patterns
notice. We keep working with zero changes, or (b) does move
them, the scan fails loudly, we re-extract signatures and
ship a new DLL.

R3 makes R2 sustainable: deriving patterns by hand for ~10
functions is doable but the workflow gets sloppy fast. The
extractor codifies the "diff two builds, mark drift as
wildcards" routine.

R4 prevents the failure mode we just experienced (stale
address + retour install = crash). Comes free with R2.

R5 is automation gravy. Skip until update cadence proves it
worth it.

## Open questions

- Where do we host the signature TOML?
  Inline Rust constants are simplest; a separate TOML file is
  friendlier to non-Rust contributors but adds a parse path.
  Recommend: Rust constants for v1, TOML for v2 if we end up
  with more than ~30 patterns.
- How wide are wildcard regions? Each `?` weakens specificity.
  Recommend: keep them to bytes the linker actually adjusts
  (RIP-relative displacements, jump-table immediates) and audit
  by diffing builds.
- Do we ship the decomp output in the repo, or hash-pin it to
  an external store? Today's `horsey-mod/research/decompiled/` is
  ~hundreds of MB. Recommend: keep in repo since GitHub LFS
  isn't on; revisit if it bloats further.

## What's in the repo right now (state at 2026-05-14)

- `targets::fn_addr::*` are `const usize` values pinned to the
  2026-05-13 build.
- One arm-time guard exists: `render_trampoline::arm` refuses
  to install if it sees the specific mid-function pattern
  `8d a8 d8 fb ff ff` at `APPLY_GENE_TO_HORSE`'s old address.
  It's a stopgap, not a real resolver.
- `ext_genes::arm` skips ALLELE_SWAP unconditionally for the
  same reason.
- EVAL_A and EVAL_B happen to still land at function entries
  in the May 2026 build. They are PROVEN working in-game.
- A fresh decomp is running in the background as of this doc
  being written. Outputs land in
  `C:/code/horsey-mods/decompiled` and will be mirrored.

> **Action items** for this doc are tracked in [`todo.md`](todo.md#address-resolution-r1-r5-phased-plan).

## Game install location (Steam)

Horsey Game's **Steam AppID is `3602570`** (sourced from [`ZyonixGaming/Horsey-Game-Save-Manager`](https://github.com/ZyonixGaming/Horsey-Game-Save-Manager) `.ahk` script, MIT). Auto-detect the install folder from the registry:

```
SteamPath := RegRead("HKEY_CURRENT_USER\Software\Valve\Steam", "SteamPath")
# Parse SteamPath\steamapps\libraryfolders.vdf for the library containing appid 3602570.
# Install path: <library>\steamapps\common\Horsey Game
# Save dir:     <library>\steamapps\common\Horsey Game\save  (contains save1.dat, save1.dat.prev, settings.xml)
```

`horsey-mod`'s injector already takes `--dll <path>` so this isn't blocking, but it's the right pattern for any UI/tooling that wants to one-click "open my Horsey install". Credit ZyonixGaming for the AppID + the registry-walk recipe.

## Migration: hardcoded -> resolved (authoritative status)

> Relocated 2026-05-15 from `todo.md` for canonical reference.

Goal: every address the production hot path reads goes through `targets::resolve::*` (pattern-scan via `modforge::patterns::sleuth`) instead of a `pub const usize`. Hardcoded RVAs stay only as fallback inside the resolver functions, sourced from one decomp build. R3 in commit `ae333c6` was the first migration; the tables below track every entry.

### P0 rule: use patternsleuth (relocated from todo.md 2026-05-15)

User-locked 2026-05-15. Every pattern-scan, xref-find, or signature match in this repo MUST go through the `patternsleuth` crate via `modforge::patterns::sleuth`. NO exceptions. ZERO tolerance.

This includes:

- **Address resolution** (functions + data globals): use `Pattern::new("opcode bytes ?? ?? ?? ?? imm")` + `sleuth::resolve_all`. Already done for the 9 R-parity function entries via the existing catalog.
- **Xref scanning** (find every `.text` instruction whose `disp32` decodes to a target data address): use patternsleuth's built-in `X<target_addr>` xref constraint inside an anchored pattern (`<opcode prefix> X<target>`). `is_match` at `patternsleuth_scanner/src/lib.rs:232` does the `next_ip + disp32 == target` check natively. NEVER iterate `.text` byte-by-byte. NEVER write your own `i32::from_le_bytes` over instruction bytes. The find_xrefs op in `horsey-mod/src/ops.rs` is the reference consumer: enumerates the common RIP-relative opcode prefixes (mov, lea, add, cmp imm8/imm32, mov-imm, byte-cmp, byte-xor, movzx, movdqa), runs one anchored scan per prefix via `sleuth::scan_all_matches`, unions and dedupes the results.
- **Data scans** (find a value in `.data`): use patternsleuth with the value bytes as a literal pattern (e.g. `"b0 00 00 00"` for u32 == 176).

**Done so far:**
- `find_xrefs` shipped as a hand-rolled scanner in `3553f50` (rule violation), then ripped out and reimplemented on patternsleuth in `9fdeca9`. Reference implementation for any future scanning code.
- `modforge::patterns::sleuth::scan_all_matches(sig)` added in `9fdeca9` as the all-hits companion to `resolve_all` (which returns only first per name).

If a needed feature is missing from patternsleuth, add it to the upstream crate or to `modforge::patterns::sleuth` wrapper. Do not work around it in horsey-mod.

### Why this migration matters (P0 reasoning, locked 2026-05-15)

Every address in `targets.rs` must be pattern-resolved. Not optional, not negotiable.

- **Game updates break us.** The shipping Horsey build is a moving target. Save-target RVAs have already drifted -277 to -1548 bytes between builds (`bd95252` re-derivation). The same drift will hit every other hardcoded address eventually. Note: the 2026-05-15 "GAMESTATE_PTR returns 0x864c38" case was not version drift, it was wrong-sigs matching unrelated globals; see "Historical incidents" below.
- **Patches won't persist.** D1/D3/D4/D5 detours all install at fixed RVAs. When the next game update ships, every detour misses its target and arms either zero subsystems or, worse, patches a different function. Every patch becomes a latent crash bug. Pattern-resolved addresses move with the code.
- **No partial migration.** "Most are resolved" is not enough. A single hardcoded address in the hot path means the next game update bricks the mod for everyone. Either everything resolves or the mod's reliability story is "works on the 2026-05-08 build only."

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
| `CHECK_HORSE_ELIGIBILITY` | `0x1400de230` | **R** (re-derived; sig + RVA updated to true entry) | tired/old/young/hungry dispatch | unused in v1 |
| `RETIRE_HORSE_HANDLER` | `0x1400df675` | **R** (re-derived 2026-05-15 via format-string xref: scan .rdata for "%s retired %s (useless)..." literal, find_xrefs to the lea inside the function, walk back past cc-padding to the prologue) | once-per-year retirement scan | unused in v1 |
| `COMPUTE_HORSE_PRICE` | `0x1400dc785` | **R** (re-derived; sig + RVA updated to true entry) | `(rand+nice+record)*years+deco` | unused in v1 |
| `CRISPR_LAB` | `0x1400894bc` | **R** (re-derived; sig + RVA updated to true entry) | 13-state CRISPR machine | unused in v1 |
| `BREEDING` | `0x1400e0817` | **R** (re-derived; sig + RVA updated to true entry) | BarnMating state machine | unused in v1 |
| `SAVE_WRITER` | `0x14006d674` | **R** (body sig 32b live-captured) | save_signatures test locks 16-byte prologue | D4 sidecar |
| `LOAD_GAME` | `0x14006e350` | **R** (body sig 32b live-captured) | same as above | D4 sidecar |
| `DRAW_PAUSE_STATUS` | `0x1400660cc` | **R** (re-derived; sig + RVA updated to true entry) | contains the cheat-money write | unused in v1 |
| `TMX_MAP_PARSER` | `0x1400fe2e0` | **R** (body sig 32-48b live) | parses `<map`; reads `horsey.tmx` | unused in v1 |
| `POP_GENOME_BUILDER` | `0x1400927e7` | **R** (re-derived; sig + RVA updated to true entry) | runtime spawner | unused in v1 |
| `DAILY_HORSE_EVENT` | `0x14002fe00` | **R** (body sig 32-48b live) | per-day per-horse event log | unused in v1 |
| `TRACK_STATE_MACHINE` | `0x14002d7c0` | **R** (body sig 32-48b live) | race lifecycle | unused in v1 |
| `CIRCUS_HANDLER` | `0x140039190` | **R** (body sig 32-48b live) | circus event | unused in v1 |
| `SUMO_HANDLER` | `0x14007b28c` | **R** (re-derived; sig + RVA updated to true entry) | sumo match | unused in v1 |
| `POWER_PLANT` | `0x140069270` | **R** (re-derived; sig + RVA updated to true entry) | power-plant building | unused in v1 |
| `WORLD_ACTION` | `0x1401075a2` | **R** (re-derived; sig + RVA updated to true entry) | world-action dispatcher | unused in v1 |
| `BALLOON_CONTROLLER` | `0x14010a9e0` | **R** (re-derived; sig + RVA updated to true entry) | hot-air-balloon controller | unused in v1 |
| `HORSE_CONSTRUCTOR` | `0x1400aac50` | **R** (body sig 32b live-captured) | 32-byte body sig | D3.1 lifecycle |
| `HORSE_DESTRUCTOR` | `0x1400bf1e0` | **R** (body sig 32b live-captured) | 32-byte body sig | D3.2 lifecycle |
| `GENE_COMBINATOR` | `0x1400a2d70` | **R** (body sig 32b live-captured) | 32-byte body sig | D3.4 breeding |
| `HORSE_SAVE_WRITER` | `0x14006ecfb` | **R** (body sig 32b live-captured) | prologue + body sig | D4.1b sidecar |
| `HORSE_SAVE_LOADER` | `0x14006f031` | **R** (body sig 32b live-captured) | `add rcx, 0x2b8` is unique | D4.2b sidecar |

### Struct field offsets (N/A for pattern-scan)

`gs_offset::*` (20 fields) and `horse_offset::*` (10 fields) are not absolute addresses; they're integer constants compiled into accessor instructions. Drift is detected by reading nonsensical values, not by signature scan. Recovery is field-by-field through the same R3 trick: each field has a write site in the decomp; pattern-match the instruction, decode the displacement to get the field's current offset. Out of scope until a build is observed where a field offset has actually shifted.

### Definition of done (P0 BLOCKER from todo.md, 2026-05-15)

1. Every entry in the comparison table above is **R** (production reads through resolver), not **R-parity** (sig exists but production still uses hardcoded) and not **H** (hardcoded only).
2. Every resolver has at least 2 candidate signatures so a single MSVC reorder between builds doesn't break it.
3. Every resolver has an alias-check test (`tests/r3_*.rs`) that fails loud on the next build whose drift the sigs don't survive.
4. CI / pre-commit refuses to ship any new `pub const usize = 0x140...;` outside `targets::resolve::*` candidate sigs.

### Recommended migration order (historical, mostly done as of 2026-05-15)

1. **Cheat globals batch (NO_TIRE_TOGGLE, DEBUG_MODE_ACTIVE, DEBUG_LOG_GATE).** Three single-byte globals in `.data`. Each is written from a known site: the cheat-menu code writes 1 to NO_TIRE_TOGGLE, the typed-string handler writes 1 to DEBUG_MODE_ACTIVE, etc. Same R3 candidate-list shape. Why first: small surface, used by the Cheats tab right now.
2. **Lifecycle detour targets (HORSE_CONSTRUCTOR, HORSE_DESTRUCTOR, GENE_COMBINATOR, APPLY_GENE_TO_HORSE).** R-parity sigs (32-byte body); flip the production reads. Why second: the parity contract already locks correctness.
3. **Save targets (SAVE_WRITER, LOAD_GAME, HORSE_SAVE_WRITER, HORSE_SAVE_LOADER).** R-parity exists via `r2_save_signatures`. Same flip. Why third: D4 sidecar pipeline depends on these.
4. **D1 detour targets (EVAL_DIPLOID_BLEND_A/B, GENE_ALLELE_SWAP).** Need fresh body sigs from the live image. Why fourth: lower iteration risk; D1 detours work today and are loaded in the arm path.
5. **Unused-in-v1 functions (everything else).** Migrate as features land; no urgency.

The candidate-list pattern from R3 generalizes: each item gets 2-4 candidate signatures (so a single MSVC reorder between builds doesn't break it), cross-validate via warning when candidates disagree, cache the result in a `OnceLock`.

## Historical incidents

### GAMESTATE_PTR deref fix (2026-05-15)

> Relocated 2026-05-15 from `todo.md` "P0 RESOLVED" + "P0 BLOCKER (CLOSED)" sections.

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

- 6 new unit tests on `is_plausible_gamestate_pointer`, including a regression test pinning the exact `0x2400000000B` stale value the previous attempt observed.
- `tests/gamestate_ptr_deref.rs` (2 integration tests): an always-on shape check ("ptr is 0 or heap-shaped, and verdict matches") and a `MODFORGE_EXPECT_LOADED=1`-gated in-save check ("ptr is heap-shaped, looks_loaded is true, money/year/sleeps are within bounded real-save ranges"). The in-save bound is structural ("looks like a real save"), NOT exact-value matching (which is what burned the previous attempt).

The hardcoded slot RVA `0x1403fb0d8` was correct all along. `gamestate::ptr()` was returning the slot's address instead of the heap pointer it holds. The R3 resolver candidates were authored under a wrong mental model and now fall through to the (correct) hardcoded RVA via a sanity gate. `looks_loaded`, the Cheats tab toggles, and every patch that hooks gamestate offsets now operate on the correct address as soon as a save is loaded. The previous false-negative ("UI says no save loaded mid-save") cannot recur without the unit-test regression firing.

### Save-address re-derivation (DONE 2026-05-15, commit `bd95252`)

> Relocated 2026-05-15 from `todo.md` "Save-address re-derivation: DONE" section.

Test-first 6-step plan executed; suite went from 1 red contract to all green.

| Step | Status | Notes |
|---|---|---|
| 1. Write failing test contract | done | `tests/r2_save_signatures.rs`. |
| 2. Probe live image for true entries | done | `tests/r2_save_find_entries.rs` widened to +/-2048-byte window with a tight MSVC-entry classifier. |
| 3. Author signatures | done | All 4 sigs distinctive; `HORSE_SAVE_LOADER` uses `add rcx, 0x2b8` (genome offset) as its uniqueness anchor. |
| 4. Migrate `targets::fn_addr` | done | `SAVE_WRITER`, `LOAD_GAME`, `HORSE_SAVE_WRITER`, `HORSE_SAVE_LOADER` corrected to re-derived RVAs. Comments cite probe + signature test. |
| 5. `dryrun_d3_d4::save_*` green | done | All 4 prologues match the classifier. |
| 6. End-to-end save/restart/reload proof | done (`e6abcad`) | `tests/r2_save_e2e_roundtrip.rs` proves ext alleles set in game 1 survive a full taskkill + relaunch + read_now cycle in game 2. 4 deterministic alleles across 2 horses round-trip exactly. The sidecar file persists on disk through the restart and is cleaned up after. **480-gene v1: SHIPPABLE.** |

True entry RVAs:

| Target | Stale (Ghidra) | True (probe-derived) | Offset |
|---|---|---|---|
| `SAVE_WRITER` | `0x14006dc80` | `0x14006d674` | -1548 |
| `LOAD_GAME` | `0x14006e480` | `0x14006e350` | -304 |
| `HORSE_SAVE_WRITER` | `0x14006ee10` | `0x14006ecfb` | -277 |
| `HORSE_SAVE_LOADER` | `0x14006f150` | `0x14006f031` | -287 |

The shipping build's Ghidra-decomp RVAs were stale by -277 to -1548 bytes. Way past the -16 convention. The probe + tight-classifier tooling (`r2_save_find_entries`) is the standing tool for any future drift.
