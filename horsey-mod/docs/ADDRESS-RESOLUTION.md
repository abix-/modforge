# Address resolution across game updates

> **Authoritative on:** how horsey-mod resolves Horsey.exe addresses in a way that survives game updates. Living plan; promotes to implementation as pieces land.

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
