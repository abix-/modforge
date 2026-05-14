# falcon-printer docs

> **Authoritative on:** the falcon-printer crate. Per-subject deep
> dives. The crate-level `../README.md` is the one-page intro;
> these files are the "why this and not that" rationale, the
> implementation walkthrough, and the open polish ladder.

## Contents

| File | Subject |
|---|---|
| [survey.md](survey.md) | Decompiler primer (what a lifter is, what a printer is). Survey of Rust binary-analysis options (Falcon, libsla, Fission, rsleigh, GhidRust, yaxpeax, iced-x86, c2rust). Why we picked Falcon. |
| [architecture.md](architecture.md) | The pipeline diagram. What Falcon owns vs what falcon-printer owns. The Falcon IL shape. |
| [passes.md](passes.md) | One section per middle-end pass: temp folding, flag-pattern recognition, cross-block flag propagation, synth-block collapse, condition simplification, call recovery, ret recovery, dead-flag cleanup. With before/after IL snippets. |
| [coverage.md](coverage.md) | Lift-rate measurement methodology. Current numbers: 88.8% on 10,332 Horsey functions. Failure-class breakdown. What we'd need to push higher. |
| [usage.md](usage.md) | How to use each binary (rust_print, batch_print, sweep_ghidra, dump_il, sweep). Sample command lines. Reading the output. |
| [building.md](building.md) | Build deps (LLVM + CMake), winget install steps, env vars, common build failures. |
| [polish-ladder.md](polish-ladder.md) | What's still missing for the output to be "great" instead of "usable". Priority-ordered with rationale. |
| [non-goals.md](non-goals.md) | What we explicitly are NOT building. Useful when scope creep tempts. |

## Where to look first

| Symptom | First file to read |
|---|---|
| "Why does this exist at all?" | [survey.md](survey.md) |
| "How does the pipeline work?" | [architecture.md](architecture.md) |
| "Why does my output look weird?" | [passes.md](passes.md) (then [dump_il](usage.md) to inspect pre-printer IL) |
| "Build fails on bad64-sys or capstone" | [building.md](building.md) |
| "How do I run this against my binary?" | [usage.md](usage.md) |
| "What's the next thing to work on?" | [polish-ladder.md](polish-ladder.md) |
| "Should I add feature X?" | [non-goals.md](non-goals.md) first |

## Cross-references

- Workspace TODO entry: [`../../docs/todo.md`](../../docs/todo.md)
  "RE-to-Rust pipeline (falcon-printer)".
- Source binaries: [`../src/bin/`](../src/bin/).
- Sample artifacts produced by this crate:
  [`../../horseygame/decompiled/rust/`](../../horseygame/decompiled/rust/).
- The Ghidra C output we use as ground truth:
  [`../../horseygame/decompiled/all_functions.c`](../../horseygame/decompiled/all_functions.c)
  (18.3 MB; one fn per Ghidra-discovered address).
