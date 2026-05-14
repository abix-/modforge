# Survey: why Falcon, why not the others

> 2026-05-14 prior-art survey driving the decision to build
> falcon-printer on top of `falconre/falcon`. Captures the
> reasoning so we don't re-relitigate it.

## Decompiler primer

A decompiler is a pipeline:

```
bytes  ->  disassembler  ->  LIFTER  ->  IR (P-code / SSA)  ->  structurer  ->  printer
48 89 e5    mov rbp,rsp     <hard>      COPY rsp -> rbp         rbp = rsp;     "rbp = rsp;"
```

**Lifter** translates each machine instruction into
architecture-neutral IR. Hardest part of a decompiler. x86-64
has ~1500 instructions plus prefixes plus modes; modelling all
their semantics is a multi-engineer-year effort. Ghidra has 20
years of mature x86-64 lifting.

**Printer** is the easy part: walk the recovered AST and emit
text in the target syntax. Swap the printer to change the
output language. A Rust output backend is a printer change. It
is *useless* without a working lifter upstream.

## Why a Rust "view" of decomp output

- Reading Rust matches the rest of the workspace stack (~70%
  Rust). No per-function context switch.
- Assigning Rust types (`&mut Horse`, `*mut Horse`,
  `#[repr(C)]` struct fields) IS the act of understanding the
  function. C decomp lets vagueness hide.
- Struct + field names produced during RE drop straight into
  modforge / horsey-mod hook layer with zero translation.
- rust-analyzer gives jump-to-def / find-references /
  rename-symbol across 10k+ functions. Ghidra-C workflows do
  not.

Output is a *notation*, not compilable. `unsafe fn` with raw
pointers and `transmute` is fine.

## The 2026-05-14 ecosystem survey

| Project | Lifter? | Status | License | Notes |
|---|---|---|---|---|
| **[falconre/falcon](https://github.com/falconre/falcon)** | x86, x86-64, MIPS, ARM64 | Active (last push 2026-03-24, 587 stars, 451 commits, 9 yr) | Apache-2.0 | Expression-based IL inspired by RREIL + BNIL. ELF + PE via goblin. Abstract interpretation engine. **The pick.** |
| [mnemonikr/libsla](https://github.com/mnemonikr/libsla) | Whatever Ghidra supports | Active (last push 2025-11-16) | Apache-2.0 | Rust bindings to NSA Ghidra's actual `libsla` C++ library. Real Ghidra P-code via FFI. Best-of-both-worlds fallback if Falcon stalls. |
| [sjkim1127/Fission](https://github.com/sjkim1127/Fission) | x86-64 stub | Active but lifter incomplete | AGPL-3.0 | Pure-Rust Ghidra/Sleigh rewrite. We forked, cloned, built it. x86-64 lifter is documented as "ExecutableCandidate but incomplete". Every decode failed with `DecodeNoMatch`. Parked. |
| [ShaneBreazeale/rsleigh](https://github.com/ShaneBreazeale/rsleigh) | x86-64 in pure Rust | v0.4.1, single maintainer, experimental | Apache-2.0 | Too young. |
| [DMaroo/GhidRust](https://github.com/DMaroo/GhidRust) | n/a | "paused permanently", flaky | n/a | Dead. |
| [yaxpeax-x86](https://github.com/iximeow/yaxpeax-x86), [iced-x86](https://github.com/icedland/iced) | n/a (disasm only) | Active | n/a | Disassembly only; no IR. Wrong layer. |

## Why not the also-rans

- **c2rust** (immunant). C99-source-to-Rust. Ghidra pseudocode
  is not compilable C (`undefined8`, fabricated types, no
  `#include`s). Not a drop-in. Heavy preprocessing tax would
  be needed before c2rust could even parse.
- **LLM binary-decompilers** (c0ral1ne, Lami99, HKalbasi,
  several others). All emit C. Closest architectural match
  but wrong output target. Useful as a tactical fallback on
  top of Ghidra C, not as a primary pipeline.
- **Ghidra Java plugin** (replace `DecompilerPrinter`).
  Strongest fallback if Falcon doesn't pan out. Java, plugin
  API churn, NSA-owned; we don't write Java anywhere else.
- **Roll our own lifter from scratch**. 3-5 year project. Not
  happening.

## Decision

[falconre/falcon](https://github.com/falconre/falcon) ships
everything below the IL line: PE/ELF loading, function
discovery, x86-64 instruction decoding, semantic lift to
Falcon IL, fixed-point analyses, concrete execution. The IL
is expression-based (RREIL / BNIL style); each function is a
control-flow graph of basic blocks of IL operations.

falcon-printer owns: a small middle-end (flag recognition,
call/ret recovery, synth-block collapse, etc.) plus the Rust
printer. Both are tractable single-engineer scope.

Fallback if Falcon's IL turns out too low-level or has
coverage gaps we can't fix upstream: **libsla**. Same shape
(write a structurer + printer), different substrate (real
Ghidra P-code via Rust FFI).

## Open at decision time

- **Falcon vs libsla criterion**: Phase 0 sweep showed 63%
  lift rate, then 88.8% after enabling `unsupported_are_intrinsics(true)`
  (SSE/AVX gaps degrade to opaque intrinsic IR nodes
  instead of failing the whole function). Above the earlier
  "pivot if >20% fail" trigger, but the remaining failures
  are dominated by Ghidra over-discovery of non-code bytes,
  not real x86 gaps. Holding the Falcon bet.
- **Snapshot harness**: adopt the existing `insta` patterns
  from ueforge `envelope.rs` once printer output stabilizes.
- **Build deps not in CI yet**: LLVM (libclang) + CMake.
  Both winget one-time installs. Documented in
  [`building.md`](building.md).

## Second-pass survey 2026-05-14 (audit)

The original survey above was too narrow. Searching
`gh search repos "rust decompiler"` ranks by name match,
not by capability; a few load-bearing projects don't
surface because their names and descriptions are
generic. A second pass with `gh search code "fn
structure_loop"` and `gh search repos "decompile
binary"` surfaced the real landscape.

The Rust output goal stays. What changes is HOW we get
there: the alternatives below are now in scope as both
upstream substrates AND comparison targets.

### Missed in the first survey

**[radareorg/r2sleigh](https://github.com/radareorg/r2sleigh)**
+ `r2dec` (created 2026-01-12, GPL-3.0, 143 commits,
Rust 2024 edition). The radare2 org's pure-Rust SLEIGH
decompiler. "Typed intermediate language suitable for
binary analysis, SSA transformation, decompilation,
symbolic execution, and taint analysis." **x86-64
marked Working.** Has expression folding, control flow
structuring, for-loop/switch detection, string
literals, symbol resolution. Outputs C. The
structurer is multi-engineer-grade where ours is the
naive if/else-for-inverse-conds version.

If we built today on r2sleigh:
- Sleigh has SSE semantics (no intrinsics fallback
  needed).
- Their structurer detects loops and switches. Ours
  doesn't.
- GPL-3 means viral if we redistribute the tool;
  internal use and the artifacts we produce are
  unencumbered.
- They emit C. Replacing the C printer with a Rust
  printer is a localized fork.

**[ReOxide](https://reoxide.eu/)**
A Ghidra-decompiler plugin system "built for Rust
reverse engineering." **NLnet NGI0 Entrust grant
funded**. Multi-engineer effort with explicit funding
to improve "decompilation on Rust and other modern
languages." Their bet: extend the mature Ghidra
framework rather than re-implement. We should track
this one closely; if they ship Rust output, we
re-evaluate.

**[albertan017/LLM4Decompile](https://github.com/albertan017/LLM4Decompile)**
6,640 stars, MIT licensed, last push 2026-02-12.
Specialized open-weights LLM models for binary-to-C
decompilation. **64.9% re-executability rate** on
HumanEval-Decompile (their decompiled output is
*executable* code that passes test cases). Two
variants:
- `LLM4Decompile-End`: binary -> C directly
- `LLM4Decompile-Ref`: refines Ghidra C output into
  cleaner C

The `-Ref` variant is the pragmatic shipping path that
the first survey misclassified as "wrong output
target." We were right that LLM output is C, not Rust,
but wrong to dismiss the path: high-quality
LLM4Decompile-Ref C -> Claude Rust transform pass is a
shorter route to readable Rust than building the
middle-end ourselves.

**[Vector35 TypeOxidizer](https://github.com/Vector35/community-plugins)**
(Binary Ninja plugin). "Render layer that visually
replaces C-style numeric types in HLIL with their Rust
equivalents at zero runtime cost" (e.g., `int64_t`
displays as `i64`). Validates the "Rust as reading
notation" market exists, but it's a *render layer* on
existing C decomp, not a full pipeline. Different
scope from what we want.

**[Ghidra 11.0+ Rust support](https://www.nathansrf.com/blog/2024/ghidra-11-rust/)**
Improved Rust-binary analysis (demangling, string
analysis, RustPath awareness for trait parsing).
Explicitly *not* Rust output: NSA's roadmap is
"improve analysis, leave Rust output to plugins"
(filled by ReOxide).

### How the audit changes the plan

Three viable paths, all preserving the Rust-output
goal:

1. **Continue falcon-printer.** Pro: ours, fast,
   88.8% lift, no external deps. Con: structurer is
   naive vs r2sleigh / Ghidra; SSE is lossy
   intrinsic; loop and switch detection not built;
   type recovery not built.
2. **Fork r2sleigh, swap C printer for Rust printer.**
   Pro: Sleigh substrate (full SSE), mature
   structurer, x86-64 working. Con: GPL-3 viral on
   redistribution, abandons existing falcon-printer
   investment, less control over substrate.
3. **Ghidra C -> LLM4Decompile-Ref -> Claude Rust
   transform.** Pro: highest-quality output today,
   no custom-decompiler maintenance, MIT-licensed
   open weights, pluggable. Con: GPU/Python in the
   loop, external runtime deps, slower per-function.

See [`strategy.md`](strategy.md) for when to use each
and the multi-path proposal.

### Why the first survey missed these

Lessons for next time:

- `gh search repos "<topic>"` ranks by name / description match,
  not capability. Projects with generic names
  (r2sleigh) or framework-style descriptions
  (ReOxide) don't surface for narrow topic queries.
- `gh search code "<specific-function-name>"` is much
  more useful for finding active impls of a known
  algorithm. `fn structure_loop` surfaced r2sleigh's
  structurer in one query.
- "Smarter engineers have probably done this" needs
  to be a default mode of investigation BEFORE
  building, not after. We had 88.8% lift output
  before discovering r2sleigh emits structured C with
  the same coverage.
