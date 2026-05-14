# falcon-printer docs

> **Authoritative on:** the falcon-printer crate. Per-subject deep
> dives. The crate-level `../README.md` is the one-page intro;
> these files are the "why this and not that" rationale, the
> implementation walkthrough, and the open polish ladder.

## Contents

| File | Subject |
|---|---|
| [survey.md](survey.md) | Decompiler primer (what a lifter is, what a printer is). Survey of Rust binary-analysis options (Falcon, libsla, Fission, rsleigh, GhidRust, yaxpeax, iced-x86, c2rust) + the second-pass audit that surfaced r2sleigh, ReOxide, and LLM4Decompile. |
| [strategy.md](strategy.md) | Three paths to Rust output (falcon-printer / r2sleigh fork / LLM pipeline). When to use each. Why multi-path beats picking one. |
| [architecture.md](architecture.md) | The pipeline diagram. What Falcon owns vs what falcon-printer owns. The Falcon IL shape. |
| [passes.md](passes.md) | One section per middle-end pass: temp folding, flag-pattern recognition, cross-block flag propagation, synth-block collapse, condition simplification, call recovery, ret recovery, dead-flag cleanup. With before/after IL snippets. |
| [coverage.md](coverage.md) | Lift-rate measurement methodology. Current numbers: 88.8% on 10,332 Horsey functions. Failure-class breakdown. What we'd need to push higher. |
| [usage.md](usage.md) | How to drive `falcon-printer` (the single binary) and its four subcommands (`print`, `batch`, `sweep`, `dump-il`). Sample command lines. Reading the output. |
| [building.md](building.md) | Build deps (LLVM + CMake), winget install steps, env vars, common build failures. |
| [polish-ladder.md](polish-ladder.md) | What's still missing for the output to be "great" instead of "usable". Priority-ordered with rationale. |
| [non-goals.md](non-goals.md) | What we explicitly are NOT building. Useful when scope creep tempts. |

## Where to look first

| Symptom | First file to read |
|---|---|
| "Why does this exist at all?" | [survey.md](survey.md) |
| "Should we even keep building this, or use r2sleigh / LLM pipeline?" | [strategy.md](strategy.md) |
| "How does the pipeline work?" | [architecture.md](architecture.md) |
| "Why does my output look weird?" | [passes.md](passes.md) (then `falcon-printer dump-il` to inspect pre-printer IL, see [usage.md](usage.md)) |
| "Build fails on bad64-sys or capstone" | [building.md](building.md) |
| "How do I run this against my binary?" | [usage.md](usage.md) |
| "What's the next thing to work on?" | [polish-ladder.md](polish-ladder.md) |
| "Should I add feature X?" | [non-goals.md](non-goals.md) first |

## Cross-references

- Workspace TODO entry: [`../../docs/todo.md`](../../docs/todo.md)
  "RE-to-Rust pipeline (falcon-printer)".
- Source: [`../src/main.rs`](../src/main.rs) (single binary, four subcommands).
- Sample artifacts produced by this crate:
  [`../../horseygame/decompiled/rust/`](../../horseygame/decompiled/rust/).
- The Ghidra C output we use as ground truth:
  [`../../horseygame/decompiled/all_functions.c`](../../horseygame/decompiled/all_functions.c)
  (18.3 MB; one fn per Ghidra-discovered address).
