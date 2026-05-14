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
