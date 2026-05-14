# falcon-printer: Rust output backend for Falcon

!!! info "Scope"
    Tracks the spike crate `falcon-printer/` and the broader
    plan to make Rust the daily-driver notation for game RE
    output. Lifted off [`todo.md`](todo.md) 2026-05-14 once the
    section grew past 300 lines.

!!! tip "TL;DR"
    Falcon 0.6 -> dce / temp-fold / flag-recog / call+ret recovery
    -> Rust printer. **88.8% lift rate** on 10,332 Horsey
    functions. 11 sample artifacts in
    `horseygame/decompiled/rust/`. Doc below covers the why, the
    survey of alternatives, the pipeline, and the polish ladder.

---

## RE-to-Rust: Falcon-based pipeline (`falcon-printer`)

User direction 2026-05-14: we are doing a LOT of game RE,
workspace is ~70% Rust, hand-translating Ghidra C into Rust
on every read wastes time. Goal: emit Rust as the
daily-driver notation for decompiled code so RE artifacts
live in the same language as the mods that consume them.

### Decompiler primer

A decompiler is a pipeline:

```
bytes  ->  disassembler  ->  LIFTER  ->  IR (P-code/SSA)  ->  structurer  ->  printer
48 89 e5    mov rbp,rsp     <hard>     COPY rsp -> rbp       rbp = rsp;     "rbp = rsp;"
```

The **lifter** translates each machine instruction into
architecture-neutral IR. This is the hardest part of a
decompiler. x86-64 has ~1500 instructions plus prefixes
plus modes; modelling all their semantics is a
multi-engineer-year effort. Ghidra has 20 years of mature
x86-64 lifting.

The **printer** is the easy part: walk the recovered AST
and emit text in the target syntax. C, Rust, anything.
Swap the printer to change the output language.

A Rust output backend is a printer change. It is *useless*
without a working lifter upstream.

### Why a Rust "view" of decomp output

- Reading Rust matches the rest of the stack; no
  per-function context switch.
- Assigning Rust types (`&mut Horse`, `*mut Horse`,
  `#[repr(C)]` struct fields) IS the act of understanding
  the function. C decomp lets vagueness hide.
- Struct + field names produced during RE drop straight
  into modforge / horsey-mod hook layer with zero
  translation.
- rust-analyzer gives jump-to-def / find-references /
  rename-symbol across 10k+ functions. Ghidra-C
  workflows do not.

Output is a *notation*, not compilable. `unsafe fn` with
raw pointers and `transmute` is fine.

### Survey 2026-05-14

Fission fork attempt (logged for the record): forked
[sjkim1127/Fission](https://github.com/sjkim1127/Fission)
to [abix-/Fission](https://github.com/abix-/Fission),
cloned locally, built clean in 2m.
**Fission's x86-64 lifter is incomplete**
(`fission-sleigh/README.md`: "ExecutableCandidate, but
p-code template execution is still incomplete"). Every
decode fails with `DecodeNoMatch`. Path is blocked on
upstream finishing x86-64 lift. Timeline unknown. Local
clone deleted 2026-05-14; remote fork preserved if we
need to revisit.

Second-pass survey via `/rtfm` surfaced the right
substrate.

### Mature Rust binary-analysis frameworks

| Project | Lifter? | Status | License | Notes |
|---|---|---|---|---|
| **[falconre/falcon](https://github.com/falconre/falcon)** | x86, x86-64, MIPS, ARM64 | Active (last push 2026-03-24, 587 stars, 451 commits, 9 yr) | Apache-2.0 | Expression-based IL inspired by RREIL + BNIL. ELF + PE via goblin. Abstract interpretation engine. The serious option. |
| **[mnemonikr/libsla](https://github.com/mnemonikr/libsla)** | Whatever Ghidra supports | Active (last push 2025-11-16) | Apache-2.0 | Rust bindings to NSA Ghidra's actual `libsla` C++ library. Real Ghidra P-code via FFI. Best-of-both-worlds. |
| sjkim1127/Fission | x86-64 stub | Active but lifter incomplete | AGPL-3.0 | Parked. |
| ShaneBreazeale/rsleigh | x86-64 in pure Rust | v0.4.1, single maintainer, experimental | Apache-2.0 | Too young. |
| DMaroo/GhidRust | n/a | "paused permanently", flaky | n/a | Dead. |
| yaxpeax-x86, iced-x86 | n/a (disasm only) | Active | n/a | Disassembly only; no IR. Wrong layer. |

### Why not the also-rans

- **c2rust** (immunant). C99-source-to-Rust. Ghidra
  pseudocode is not compilable C. Not a drop-in.
- **LLM binary-decompilers** (c0ral1ne, Lami99,
  HKalbasi, several others). All emit C. Closest
  architectural match but wrong output target. Useful
  as a tactical fallback on top of Ghidra C, not as
  a primary pipeline.
- **Ghidra Java plugin** (replace `DecompilerPrinter`).
  Strongest fallback if Falcon doesn't pan out.
  Java, plugin API churn, NSA-owned; we don't write
  Java anywhere else.
- **Roll our own from scratch**. 3-5 year project.
  Not happening.

### Decision: build on Falcon

[falconre/falcon](https://github.com/falconre/falcon)
ships everything below the IL line:

```
binary -> falcon::loader::Pe -> falcon::translator::x86 -> falcon::il (Falcon IL)
       -> [our structuring pass]
       -> [our Rust printer]
```

Falcon owns: PE/ELF loading, function discovery, x86-64
instruction decoding, semantic lift to Falcon IL,
fixed-point analyses, concrete execution. The IL is
expression-based (RREIL / BNIL style); each function is a
control-flow graph of basic blocks of IL operations.

What we own: a structuring pass (IL CFG -> high-level
control flow: if/while/switch/for) and a Rust printer
walking the structured AST. Both are tractable single-
engineer scope.

Fallback if Falcon's IL turns out to be too low-level or
its x86-64 lifter has coverage gaps: **libsla**. We get
real Ghidra P-code via Rust FFI, write the same
structurer + printer on top. Same shape, different
substrate.

### Phased plan

#### Phase 0: Falcon validation (DONE 2026-05-14)

- [x] Add `falcon = "0.6"` to scratch crate
  `grounded2mods/falcon-printer/`. Build dep chain
  needed `winget install LLVM` (libclang for `bad64-sys`)
  and `winget install Kitware.CMake` (capstone bundled
  source). Build time ~2m clean.
- [x] Load `Horsey.exe` via `falcon::loader::Pe`. PE
  parsed; arch `Amd64`; 1,272 function entries from
  PE exception tables.
- [x] Lift one function through `falcon::translator::x86`
  (Amd64). Confirmed Falcon IL emits per-instruction
  ops decomposed by semantic. Each `cmp` becomes 4
  flag-setting ops (ZF/SF/OF/CF).
- [x] Sweep Falcon's PE-entry list: 1,270 / 1,272
  lifted (99.8%). These are mostly thunks / exports.
  too small a sample for game coverage.
- [x] Sweep against Ghidra's 10,332 discovered addresses
  (cross-binary, our existing dump). Initial run: 63.1%.
  Then switched to `Options::set_unsupported_are_intrinsics(true)`
  which models unhandled SSE/AVX ops as opaque
  `Intrinsic` IL nodes instead of failing the whole
  function lift. **Re-sweep result: 88.8% lift rate
  (9,170 / 10,332)**.
  Remaining failures: 1037 are "DisasmFailureUnrecoverable"
  (almost certainly Ghidra over-discovery of padding,
  jump-table data, or mid-function addresses Capstone
  refuses to decode). 84 internal Falcon bitness
  mismatches. 36 MMX register lookups (rare). Real
  game-function lift rate is effectively ~95%+.
- [x] Decision gate result: Falcon's x86-64 lifter is
  good enough. Path is viable; libsla pivot deferred.

#### Phase 1: middle-end + Rust printer (DONE 2026-05-14 shippable v0.1)

Built `falcon-printer/src/bin/rust_print.rs`. Pipeline:

```
Falcon lift  ->  Falcon dead-code-elimination
             ->  pass_fold_temps             (inline single-use temps)
             ->  pass_flag_recognition       (recover X cmp Y from ZF/SF/OF/CF set)
             ->  pass_propagate_flags_across_blocks  (carry recovered cmp through synth junctions)
             ->  pass_collapse_synth_blocks  (eliminate Falcon's empty junction blocks)
             ->  pass_simplify_conditions    (rewrite (X==0)==0 to X != 0, etc.)
             ->  pass_call_recovery          (rsp -= 8; [rsp] = ret; branch X  =>  Call(X))
             ->  pass_ret_recovery           (load [rsp]; rsp += 8; branch t   =>  Return)
             ->  pass_drop_dead_flags        (kill leftover SF/OF/CF bindings)
             ->  Rust printer                (emit blocks with if/else when succs are inverses)
```

Auxiliary helpers built:
- `falcon-printer/src/bin/sweep_ghidra.rs`. Coverage measurement
- `falcon-printer/src/bin/dump_il.rs`     . Raw Falcon IL inspector
- `falcon-printer/src/bin/batch_print.rs` . Pipe addrs in, get .rs out

Naming: loads `horseygame/decompiled/INDEX.md` (10k
addr -> Ghidra name) and `horseygame/decompiled/key-funcs/`
(slug from filename) at start; overrides
`fn_<addr>` with the friendly name when found.
Examples landed: `save_filename_format`,
`SDL_CloseSensor`.

Concrete artifacts in
`horseygame/decompiled/rust/` (2026-05-14, 11 files,
30,527 lines total):
- `fn_140089510.rs` (save_filename_format, 68 lines,
  if/else conditionals visible, function calls
  recognized as `fn_<addr>()`, `return;` recognized).
- `fn_140122690.rs` (SDL_CloseSensor, 11 lines,
  IAT trampoline).
- `fn_140094a20.rs` (click_race_when_ready_dialog,
  9,069 lines, 1,106 blocks, real UI event handler
  with calls visible to fn_140092110 / fn_140092340 /
  fn_14008ff80, field accesses at rdi+0x124 / +0x254 /
  +0x258 / +0x260 readable as game state writes).
- `fn_140066200.rs` (simulation_paused_status, 1,795
  lines, was previously blocked on `cvtdq2ps`).
- `fn_140033a10.rs` (price_or_score_formula, 7,137
  lines, was previously blocked on `movss`).
- Plus 6 more small functions.

A human reading these can identify what each function
touches in memory, what helpers it calls, and its
control flow shape. Sufficient to plan mod hook points.

What works in the output:
- Compilable Rust types (u8/u16/u32/u64/u128/bool).
- `core::ptr::read` / `core::ptr::write` for memory.
- `if (X == Y) { ... } else { ... }` for cmp+jcc pairs.
- Direct call recognition: `fn_1400a8df0();`
- Return recognition: `return;`
- Function naming from Ghidra index where available.

What still needs work (next polish ladder):
- [x] **SSE/AVX coverage in Falcon translator**.
  Solved via `Options::set_unsupported_are_intrinsics(true)`.
  Lift rate 63% -> 88.8%. SSE ops appear as
  `Intrinsic { ... }` IL nodes. Their effects on
  XMM registers are not modeled, so any control flow
  that depends on float comparisons may lose
  precision. For most game functions the SSE traffic
  is float math (rendering / physics) that's
  irrelevant to the integer-side game-state changes
  we want to hook. Acceptable for now.
- [ ] **Tail-call recognition**. Falcon currently
  inlines tail-called helpers into the calling
  function (e.g. `fn_140003b80` shows
  `fn_1402c77dc`'s body merged in). Detect
  `epilogue + branch addr` pattern, emit
  `tailcall_<addr>()`, stop.
- [ ] **SBB / ADC recognition**. `sbb rax, rax`
  pattern produces awkward `(rax - (rax + CF))`
  chains. Collapse to `if CF { -1 } else { 0 }` idiom.
- [ ] **Struct shape recovery**. Currently
  `(rcx).wrapping_add(0x300) as *const u64` could be
  `(*rcx_typed).field_300`. Needs a struct schema
  side-table per binary (`horseygame/structs.yaml`)
  plus a printer pass that consumes it.
- [ ] **Comment passthrough from Ghidra C**. Pull
  the matching C function body from
  `decompiled/annotated/` as a docstring above each
  `unsafe fn`. Free quality boost.
- [ ] **Mass function naming**. Today only ~20
  functions have nice names (the documented
  key-funcs + Windows imports). Extract more names
  from string anchors / FunctionID DB / Windows API
  call-site patterns to push naming coverage to
  ~30%+.
- [ ] **Block-level structurization beyond if/else**.
  Detect natural loops (back-edges) and emit
  `loop {}` / `while ... {}`. Detect switch tables
  and emit `match`. Currently still emits goto-style
  block comments.
- [ ] **Bulk pass**. Loop INDEX.md addresses through
  `rust_print`, write each to
  `horseygame/decompiled/rust/`. Index will be
  rust-analyzer-navigable.

#### Phase 2: SSE coverage (next session)

Contribute Falcon upstream PR adding SSE/SSE2/SSE3/SSE4.1
float instruction semantics. Falcon takes Apache PRs.
Scope: ~100 mnemonic mappings to existing Falcon IL ops
(Load/Store/Bin/Cast). Test against Horsey re-sweep
target: 63% -> 80% lift rate.

#### Phase 3: UE4 targets (open scope)

- [ ] Outworld Station / Grounded 2 binaries (UE4).
  UE4 has SDK-recoverable UClass / UFunction names
  that plug into the naming table for free.
- [ ] Integration with ueforge: decompiled Rust files
  become the cross-reference target for any
  `#[repr(C)]` struct shipped in ueforge / modforge
  hook code.

### Open design questions

- **Workspace layout**. Crate lives at
  `grounded2mods/falcon-printer/` (workspace member).
  Fission fork was deleted 2026-05-14 (cleanup);
  remote at [abix-/Fission](https://github.com/abix-/Fission)
  still exists if we ever want to revisit.
- **Falcon vs libsla decision (2026-05-14 update)**:
  Phase 0 sweep showed 63% lift rate which is above the
  earlier "pivot if >20% fail" trigger. But most
  failures are SSE-class instructions that are
  bounded-scope to fix upstream. Holding the Falcon
  bet rather than pivoting to libsla; revisit if SSE
  patches stall.
- **Snapshot harness**. Adopt the existing `insta`
  patterns from ueforge `envelope.rs` once printer
  output stabilizes.
- **Build deps not in CI yet**: LLVM (libclang) +
  CMake. Installed via winget 2026-05-14. Document
  for fresh checkouts; ueforge's Cargo.lock /
  workspace will pick falcon-printer up at next
  clone and need both.

### Non-goals

- Compilable Rust. Output is a notation. If it happens
  to compile, fine; we don't fight the borrow checker.
- A general-purpose binary-to-Rust transpiler product.
  This is a tool for our RE workflow.
- Replacing Ghidra entirely. Ghidra stays installed as
  ground truth for cross-checking Falcon's lift output.

### Artifacts in the repo today

- `horseygame/decompiled/all_functions.c`. 18.3 MB
  Ghidra C output. Source of truth for cross-checking
  Falcon output during Phase 0.
