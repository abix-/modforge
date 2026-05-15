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
  `horsey-mod/research/decompiled/rust/` per-function.
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
  - `horsey-mod/research/decompiled/rust-r2sleigh-spike/`:
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

### Phase 3: implementation (DONE 2026-05-14, substantively)

Status: Rust emit working end-to-end. CLI parity
(`print` / `batch` / `dump-il`), naming layer, and
1GB-stack guard all shipped. 13 of 18 documented
Horsey key-funcs decompile cleanly with friendly
names. The remaining 5 hit libsla-internal stack
overflows; logged in
[`../../decomp/docs/polish-ladder.md`](../../decomp/docs/polish-ladder.md)
item 2. The `sweep` subcommand is deferred to the
post-cutover ladder.

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
  `horsey-mod/research/decompiled/rust-r2sleigh/`: 16 files,
  including 13 of the 18 documented key-funcs
  (`save_filename_format`, `price_or_score_formula`,
  `click_race_when_ready_dialog`,
  `tired_looking_horse_dialog`,
  `rest_your_horse_or_too_young`,
  `settings_xml_handler`, `settings_xml_handler_2`,
  `chromomap_loader`, `getting_old_buy_horse`,
  `interact_dispatch_or_status_check`,
  `retirement_branch`,
  `none_of_horses_are_tired`,
  `found_chromosomes_log`,
  `horse_is_deceased_handler`,
  `SDL_CloseSensor`).
- [x] CLI port: `decomp print` / `decomp batch` /
  `decomp dump-il` shipping, clap derive. Matches
  falcon-printer's surface (sans `sweep`, which is
  more complex to port; deferred to phase 5).
- [x] Naming layer port: loads INDEX.md plus
  `key-funcs/*.c` filename slugs at startup;
  overrides r2dec's `sub_<addr>` default. Examples
  shipped:
  `pub unsafe fn price_or_score_formula(arg1: i64, arg2: i64) {`
  instead of `pub unsafe fn sub_140033a10(...)`.
- [x] Large-stack guard: r2sleigh's internal
  recursion (Sleigh lift through libsla, SSA
  construction, structurer) overflows the default
  8MB Rust thread stack on dense functions. Spike
  spawns the whole pipeline on a 1GB-stack thread,
  mirroring r2sleigh's plugin
  `run_full_decompile_on_large_stack`.
- [/] 5 of 18 key-funcs still fail with internal
  libsla stack overflows (the overflow happens in
  a libsla-internal thread our 1GB Rust stack
  doesn't reach):
  `simulation_paused_status`,
  `save_path_writer_1`,
  `genome_clipboard_copy_paste`,
  `genes_dat_handler`, `horse_is_dead_handler`.
  Out of scope for phase 3; needs upstream fix in
  libsla-sys or basic-block-splitting on our side
  (single big R2ILBlock builds deeper SSA than
  per-bb input).
- [ ] Sweep coverage rerun on all 10,332
  Ghidra-discovered addresses. Deferred: a full
  sweep through libsla is hours given the
  per-function cost; better done after r2sleigh
  gains a faster sweep entry point or basic-block
  splitting lands.

### Phase 4: cutover (DONE 2026-05-14)

- [x] Standup `decomp/` crate at workspace top-level
  (NOT a workspace member; libsla-sys Windows
  blocker. See polish ladder item 1).
- [x] Update workspace `Cargo.toml` member list:
  removed `falcon-printer`. `decomp` deliberately
  not added until Windows build works.
- [x] Update the repo `README.md` "Research tooling"
  section: now leads with `decomp`, lists
  falcon-printer as retired prototype.
- [x] Update `docs/todo.md` pointer: points at
  decomp; migration history references falcon-printer
  archive.
- [x] Delete falcon-printer's `Cargo.toml` + `src/`.
  Docs at `falcon-printer/docs/` preserved as
  historical archive (strategy, survey, passes,
  architecture). README.md updated with a "RETIRED"
  banner.
- [x] `ghidra_addrs.txt` moved from `falcon-printer/`
  to `decomp/`.
- [x] Workspace `docs/falcon-printer.md` was already
  removed earlier; the per-crate docs at
  `falcon-printer/docs/` are the survivors.

### Phase 5: polish ladder reset (DONE 2026-05-14)

New ladder lives at
[`../../decomp/docs/polish-ladder.md`](../../decomp/docs/polish-ladder.md).
8 prioritized items, ordered by leverage:

1. Windows build (libsla-sys `_WINDOWS` define
   + cxx-bridge double-include; investigated this
   session, partial fix proven).
2. libsla-internal stack overflows on 5 dense
   functions (basic-block splitting before lift
   would fix).
3. `sweep` subcommand port.
4. Argument recovery + parameter types (lean on
   r2types upstream).
5. Struct shape recovery (per-binary YAML schema).
6. Rust-idiom polish (`Option<*const T>` for
   nullable pointers, etc.).
7. Comment passthrough from Ghidra annotated C.
8. Workspace integration + final cutover (gated on
   item 1).

## Open questions (resolved)

- **Crate name post-cutover.** Settled on `decomp`
  (boring + clear, matches the `<game>-mod` naming
  convention). Top-level `decomp/` dir.
- **Upstream vs downstream crate.** Settled on
  downstream: r2sleigh stays as path/registry dep,
  we consume `r2dec::ast::CFunction` public AST and
  emit Rust in our own crate. No fork required.
- **r2sleigh pinning.** Today: path dep to local
  `~/r2sleigh/` clone in WSL. Promote to git dep on
  a fixed commit when the workspace integration
  lands (gated on the Windows build).
- **Existing artifacts.** Resolved by keeping
  falcon-printer outputs in
  `horsey-mod/research/decompiled/rust/` as before/after
  evidence, and the new r2sleigh-based outputs in
  `horsey-mod/research/decompiled/rust-r2sleigh/`. Once the
  workspace cutover lands, the directories swap
  (r2sleigh becomes `rust/`, falcon becomes
  `rust-falcon-archive/`).

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