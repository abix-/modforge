# Strategy: switch the substrate to r2sleigh

> 2026-05-14 decision: migrate the Rust-output backend from
> Falcon onto [`radareorg/r2sleigh`](https://github.com/radareorg/r2sleigh).
> The Rust-output goal stays. The substrate underneath
> changes.
>
> This doc supersedes the earlier "three paths" framing.
> Path A (falcon-printer) becomes the prototype that
> taught us what passes to build. Paths B and C
> (LLM4Decompile-Ref pipeline) stay available as future
> options but are not the primary plan.

## Why we're switching

falcon-printer hit its ceiling fast. The honest tally
after one session of building:

| Dimension | falcon-printer | r2sleigh |
|---|---|---|
| Lifter coverage | ~88.8% (SSE/AVX via lossy `Intrinsic` fallback) | Full x86-64 via Sleigh specs; SSE/AVX have real semantics |
| IR | Falcon IL, 6 ops, 23 exprs | R2IL, 60+ opcodes from Sleigh, full SSA pipeline |
| Structurer | ~80 LoC of if/else for inverse-cond pairs | `structure.rs` is 2,500+ LoC: region analysis, dominator-based reduction, for-loop detection, switch recovery, break/continue inference |
| Type recovery | None | Constraint-based with struct / signature support |
| SSA / DCE / CSE / SCCP | DCE only | Full pipeline |
| Symbolic execution | None | Z3-backed with path exploration |
| Taint analysis | None | SSA-based |
| Tests | 0 | 200+ across 8 crates |
| Maintainers | 1 (this session) | radare2 community + Pancake; active Feb 2026 roadmap |
| License | Apache-2.0 | GPL-3.0 (we like GPL-3) |
| Output language | Rust (the goal) | C (becomes Rust when we fork the printer) |

r2sleigh's `structure.rs` alone is bigger than the entire
falcon-printer crate. Their stack ships everything on the
old polish ladder (loop / switch structurization,
SSA, type inference) plus things we hadn't even put on
the ladder.

The only structural objection was GPL-3 viral on tool
redistribution. The user is fine with GPL-3. So the
case for switching is unambiguous.

## What stays the same

- **The Rust-output goal.** r2sleigh emits C natively;
  we fork the printer stage to emit Rust instead. The
  entire pipeline below that stage we get for free.
- **The artifact shape.** Output lands in
  `horseygame/decompiled/rust/` per-function.
- **The CLI surface.** `print` / `batch` / `sweep` /
  `dump-il` subcommands still make sense; they just
  drive a different engine.
- **The workspace home.** Crate stays inside this
  repository. Rename TBD (see "Open questions").

## What changes

- **Substrate**: Falcon -> r2sleigh + r2dec (Sleigh
  P-code + their middle-end).
- **Crate name**: `falcon-printer` no longer
  accurate; rename during cutover. Candidates:
  `sleighprint`, `rdec-rust`, `rust-decomp`,
  `r2-rust`. Pick before cutover.
- **Output quality**: target jumps from "naive
  pseudocode with if/else and goto comments" to
  "structured Rust with for/while/match plus
  recovered types and names".
- **Dependency posture**: r2sleigh is grant-funded
  and actively developed; we move from carrying the
  substrate to being a downstream contributor.

## Migration plan

### Phase 1: spike and validate (DONE 2026-05-14, go)

- [x] Clone `radareorg/r2sleigh`. Cloned to
  `C:/code/r2sleigh/` (Windows) and `~/r2sleigh/`
  (WSL). Found r2sleigh depends on
  `libsla-sys 0.1.5` which compiles Ghidra's C++
  source. **Windows MSVC build fails** on
  `unistd.h` (Ghidra C++ uses POSIX headers).
  WSL build succeeds clean in ~2m. Conclusion:
  r2sleigh tooling lives in WSL for now;
  Horsey.exe is accessible via `/mnt/c/Games/...`.
- [x] Build r2sleigh-cli. Built `r2sleigh-cli`
  + `r2dec` + `r2ssa` + `r2sleigh-lift` in WSL.
- [x] Discover the API: r2sleigh-cli is
  per-instruction. The full-function path is
  `Disassembler::lift_block(bytes, addr, size)`
  -> R2ILBlock, then
  `SSAFunction::from_blocks_for_decompile(&[block], Some(&arch_spec))`,
  then `Decompiler::build_function(&ssa)` ->
  CFunction (public AST), then either
  `r2dec::codegen::generate(&c_func)` for C or
  walk the AST ourselves for Rust.
- [x] Build a spike at `~/r2sleigh-spike/` in WSL
  that drives the full pipeline programmatically.
  Uses goblin for PE parsing; depends on r2sleigh
  crates via path.
- [x] Run against documented key-funcs. Saved
  comparison artifacts:
  - `horseygame/decompiled/rust-r2sleigh-spike/`:
    raw r2dec C output for `save_filename_format`
    (173 lines), `click_race_when_ready_dialog`
    (157 lines truncated at 4kB). SSE-heavy
    functions (`price_or_score_formula`,
    `simulation_paused_status`) failed to
    complete decompile in <2 minutes. SSA
    construction on dense float-math code is
    slow. Will likely complete with longer
    timeout or proper basic-block-split input.

**Decision gate result: GO.** Quality of r2sleigh's
output is meaningfully better than falcon-printer's
on every dimension that matters:
- SSA versioning visible (`rdi_1`, `rdi_4`, `rdi_7`,
  ...) makes data flow legible.
- Struct field writes render as `*(rdi_1 + 592) = 13`
  instead of `core::ptr::write((rdi).wrapping_add(0x250) as *mut u64, 0xd_u64)`.
- Function calls show arguments where recoverable:
  `ram:140092110(rcx);` vs falcon-printer's argless
  `fn_140092110();`.
- No synthetic block dispatch noise (Falcon's
  empty junction blocks).
- No ZF/SF/OF/CF chain noise (the flag-recognition
  pass falcon-printer needs is upstream's
  problem in r2sleigh).

### Phase 2: printer-fork design (DONE 2026-05-14)

- [x] Read `r2dec/src/codegen.rs` (692 lines) and
  `r2dec/src/ast.rs` (822 lines). The AST is
  fully public via `r2dec::ast::{CType, CExpr,
  CStmt, CFunction, BinaryOp, UnaryOp,
  SwitchCase, CParam, CLocal}`.
- [x] Decide between fork / upstream PR / downstream
  crate. **Picked downstream new crate (option c)**.
  `Decompiler::build_function(&SSAFunction) ->
  CFunction` is public. We don't need to fork; we
  consume r2sleigh as a dep and walk the public
  AST in our own emit module.

### Phase 3: implementation (IN PROGRESS 2026-05-14)

Status: Rust emit working end-to-end in the
`r2sleigh-spike/` WSL crate. Open work is CLI
parity and workspace integration (Phase 4).

- [x] Stand up a spike crate
  (`~/r2sleigh-spike/`, WSL). Pinned to local
  r2sleigh path deps until cutover.
- [x] Implement the Rust emit. Walks
  `r2dec::ast::CFunction`, maps to Rust syntax:
  C ints -> Rust ints (`int64_t` -> `i64`, etc.);
  C pointers -> `*mut T`; `*(addr)` -> `*addr`;
  C `switch` -> Rust `match`; C `for` -> init+while;
  C `do-while` -> `loop { ... if !cond { break; } }`;
  function calls keep their argument lists; ram:HEX
  refs become `fn_HEX`. ~300 lines.
- [x] Generate sample artifacts.
  `horseygame/decompiled/rust-r2sleigh/`:
  `fn_140089510.rs` (176 lines), `fn_140094a20.rs`
  (160 lines), `fn_140122690.rs` (9 lines).
- [ ] CLI port: subcommands `print` / `batch` /
  `sweep` / `dump-il` matching falcon-printer's
  surface. Currently the spike has a positional
  `addr` + a `c | rust` mode flag.
- [ ] Naming layer port: load
  `horseygame/decompiled/INDEX.md` to override
  `fn_<addr>` with friendly names. Same logic as
  in falcon-printer, ported.
- [ ] Sweep coverage rerun. Target: ~100% lift
  rate on Horsey via Sleigh's full instruction
  semantics.
- [ ] Bulk-regenerate the 11 documented key-funcs
  with names. SSE-heavy ones may need longer
  timeouts or basic-block splitting.

### Phase 2: printer-fork design (1 session)

Goal: locate the printer extension point in r2dec
and design our Rust emit.

- [ ] Read `r2dec/src/codegen.rs` (the C emit) and
  `r2dec/src/ast.rs` (the AST it emits from).
  Understand the AST -> C pipeline.
- [ ] Decide between:
  - **(a) Upstream PR for a pluggable printer
    trait**: cleanest long-term; depends on
    Pancake accepting the design.
  - **(b) Fork r2sleigh, maintain a long-lived
    branch**: more control, more maintenance,
    GPL-3 means we have to publish source if we
    redistribute.
  - **(c) New crate downstream of r2sleigh that
    consumes its AST and emits Rust**: no upstream
    change; we depend on `r2dec` and re-export
    a parallel `r2dec-rust`. This is probably the
    right answer because it keeps us independent
    without forking.
- [ ] Sketch the new crate (`rdec-rust` or
  whatever) layout: takes r2dec's AST, walks it,
  emits Rust syntax. Mirrors `r2dec`'s codegen.rs
  but with Rust-specific peepholes (`int64_t` ->
  `u64`, `core::ptr::read` instead of `*`,
  `unsafe fn` wrapper, etc.).
- [ ] Decide naming. See "Open questions".

### Phase 3: implementation (2-3 sessions)

Goal: produce Rust output for every documented
key-func with the new substrate.

- [ ] Stand up the new crate as a workspace
  member. Pin `r2sleigh` as a git dependency at a
  specific commit until they publish on crates.io.
- [ ] Port the CLI (`print` / `batch` / `sweep` /
  `dump-il`) so subcommands feel identical.
  Implementation underneath is now r2sleigh +
  r2dec + our Rust printer instead of Falcon +
  our middle-end + our printer.
- [ ] Port the naming layer (load
  `horseygame/decompiled/INDEX.md` + `key-funcs/`
  slugs). Independent of substrate.
- [ ] Implement the Rust emit: walk the r2dec AST,
  produce `unsafe fn`-shaped Rust. Reuse the
  type-mapping logic from falcon-printer
  (u1 -> bool, etc.). Memory access through
  `core::ptr::read` / `core::ptr::write`.
- [ ] Regenerate the 11 sample artifacts. Diff
  against the falcon-printer outputs for the
  before/after record.
- [ ] Run the new sweep. Target: ~100% lift rate
  (Sleigh has full instruction semantics; remaining
  failures should be Ghidra-over-discovery noise
  only).

### Phase 4: cutover (1 session)

Goal: replace falcon-printer in the workspace.

- [ ] Rename the dir (`falcon-printer/` -> new
  name). Use `git mv` to preserve history.
- [ ] Update workspace `Cargo.toml` member list.
- [ ] Update the repo `README.md` "Research tooling"
  section.
- [ ] Update `docs/todo.md` pointer.
- [ ] Move falcon-printer's old `src/main.rs` to
  the new crate as `legacy/falcon_printer.rs` for
  reference, or delete cleanly. Decision: probably
  delete; git history is the archive.
- [ ] Delete `docs/falcon-printer.md` workspace
  doc if it still exists. (It was already moved to
  per-crate docs.)

### Phase 5: polish ladder reset (open)

Most of the old polish ladder (loops / switches /
SSA / type inference) is now upstream's
responsibility. New ladder items are Rust-idiom
polish:

- Recover Rust-style enum patterns where switch
  cases match a tag field.
- Emit `Option<*const T>` for nullable pointer
  parameters (recover from null checks).
- Pull `derive(Debug)`-style annotation onto
  recovered structs.
- Tail-call recognition (if r2sleigh doesn't
  already detect them).
- LLM-assisted naming (Phase 5+) for the
  ~9k functions that don't have a Ghidra symbol.

## Open questions

- **Crate name post-cutover.** Candidates:
  `sleighprint` (parallels falcon-printer), `rdec-rust`
  (mirrors `r2dec`), `rust-decomp` (boring/clear,
  matches `<game>-mod` convention),
  `r2-rust` (short, says-what-it-is). User
  preference welcome.
- **Upstream vs downstream crate.** Phase 2 picks
  one. Default: downstream new crate (option c)
  for independence.
- **r2sleigh pinning.** Git dep on a commit hash
  until they publish on crates.io. Update
  cadence: pull upstream weekly during active
  development; pin firmly when we cut a release.
- **Existing artifacts.** The 11 sample
  `horseygame/decompiled/rust/*.rs` files are
  falcon-printer output. Keep them as
  before/after evidence, or regenerate from
  r2sleigh in place? Likely: keep falcon-printer
  versions in `rust-falcon/` subdir as historical
  comparison; new output goes to `rust/`.

## What if the spike fails

If r2sleigh's C output is not meaningfully better
than falcon-printer's pseudocode on Horsey:

- The structurer-quality argument disappears.
- The substrate argument (Sleigh > Falcon for SSE)
  still holds and is enough to justify the switch
  by itself, just less dramatically.
- Alternative: re-evaluate Path C (LLM4Decompile-Ref
  + Claude Rust transform). The LLM pipeline output
  quality is the actual benchmark; if neither
  Falcon nor r2sleigh beats it, the right answer
  may be no custom decompiler at all.

We'll only know after the phase 1 spike.

## What this doc supersedes

- The "three paths" framing in the previous
  `strategy.md`. Path A (falcon-printer) is
  decommissioned after cutover. Path C (LLM
  pipeline) remains a future option but is not the
  primary plan.
- The implicit "polish falcon-printer for months"
  trajectory in `polish-ladder.md`. Most ladder
  items are now upstream's problem; the ladder
  gets rewritten after phase 4.
- The "Falcon vs libsla" decision criterion in
  `survey.md` "Open at decision time". Both are
  superseded by the r2sleigh substrate choice.