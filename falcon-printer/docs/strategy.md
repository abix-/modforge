# Strategy: three paths to Rust output

> Goal: Rust as the daily-driver notation for game RE
> output. Three viable paths surfaced by the
> [`survey.md`](survey.md) second pass. This doc proposes
> a multi-path workflow that uses each where it's
> strongest rather than picking one and ignoring the
> others.

## The paths

### Path A: falcon-printer (the current crate)

Status: shipping v0.1, 88.8% lift rate, single-binary
CLI with `print` / `batch` / `sweep` / `dump-il`
subcommands.

When it wins:
- Need a fast Rust-shaped view of a function during
  active investigation.
- Want full Rust ownership end-to-end (no external
  runtime, no GPU, no Python in the loop).
- Doing many lifts in a tight RE loop where
  per-function latency matters more than output
  fidelity.
- Want to use Falcon's other analyses (concrete
  execution, symbolic execution, taint, def-use
  chains) alongside the decompilation.

When it doesn't:
- Function has heavy SSE/AVX float math the
  intrinsics-fallback drops on the floor.
- Function has complex control flow (nested loops,
  switches, computed gotos) our naive structurer
  can't recover.
- Function needs struct shape recovery to be readable
  (raw `wrapping_add(0x124)` offsets get old fast).

Owner: us. License: Apache-2.0 (workspace default).

### Path B: r2sleigh + Rust printer fork

Status: not built yet. r2sleigh + r2dec ships C output
through a mature structurer; we'd fork to replace the C
emit stage with our own Rust emit.

When it wins:
- Function uses SSE/AVX and we want real semantics
  (Sleigh has the full instruction model).
- Function has loops / switches our structurer can't
  handle.
- We're willing to spend engineering on the substrate
  in exchange for better output across the board.

When it doesn't:
- One-off RE pass where falcon-printer is good enough
  and fork maintenance overhead doesn't earn back.
- We want to redistribute the tool (GPL-3 viral).
- Building the Rust printer fork takes more time than
  just LLM-translating the C anyway.

Owner: would be us (fork). License: GPL-3.0 inherited.
The artifacts (decompiled Rust files) are ours;
distribution of the *tool* triggers GPL.

Engineering cost: medium-large. Fork r2sleigh, locate
the printer extension point, write the Rust emit
backend. Their C emit is multi-thousand lines; we'd
mirror only the parts the existing falcon-printer
already does, then grow over time.

### Path C: Ghidra C -> LLM4Decompile-Ref -> Claude Rust transform

Status: not built. Pipeline of existing tools.

Pipeline:
```
horsey.exe + ghidra_addrs.txt
  |
  v
Ghidra (decompile.py, already done)
  |  -> all_functions.c (18.3 MB)
  v
LLM4Decompile-Ref (open weights, MIT, GPU)
  |  -> refined-C per-function (cleaner names, recovered idioms)
  v
Claude / local LLM (Rust transform prompt)
  |  -> Rust pseudocode
  v
horseygame/decompiled/rust/fn_<addr>.rs
```

When it wins:
- Top-quality output is what matters more than speed.
- The function is too complex for falcon-printer's
  structurer.
- We want recovered variable names / idioms /
  comments that only LLM passes produce.
- One-shot work: render a few key functions for deep
  understanding, no need to do all 10k.

When it doesn't:
- No GPU available.
- We don't want a Python toolchain.
- Bulk pass: 9k functions through two LLM passes is
  cost-prohibitive at scale.

Owner: external tools (LLM4Decompile is MIT, Claude
is API). License: each piece independent; final
output is ours.

Engineering cost: low. Write a thin pipeline script
(`scripts/llm_decomp.py` or similar). Wire LLM4Decompile-Ref
via its Python API, hand-craft the Rust-transform
prompt for Claude, snapshot the output.

## The multi-path proposal

Use all three.

| Situation | Path |
|---|---|
| Bulk pre-rendering of 9k functions for grep/index | A (falcon-printer batch) |
| Quick "what does fn_X do" during RE | A (falcon-printer print) |
| Function that falcon-printer mangles (lots of SSE/loops) | B (when built) OR C (today) |
| Deep dive on a critical function before mod work | C (LLM pipeline) |
| Function in another arch (ARM64, MIPS) | A or B (falcon and r2sleigh both support) |
| Function whose output we want as compilable Rust | None (none of the paths target this; see [`non-goals.md`](non-goals.md)) |

The output formats are *additive*: a function can have
both a falcon-printer Rust file AND an LLM-pipeline
Rust file. The repo can carry both side-by-side. The
reader picks whichever reads better for the function
at hand.

## Concrete next steps

Phase A keeps progressing on falcon-printer (see
[`polish-ladder.md`](polish-ladder.md)).

Phase B (deferred): once falcon-printer hits its
ceiling on loop/switch heavy functions, evaluate the
r2sleigh fork. Spike: clone r2sleigh, get a sample
function output as C, sketch the Rust printer
extension point. Decision after spike.

Phase C (independent track, can start anytime): spike
the Ghidra->LLM4Decompile-Ref->Rust pipeline. Output
to `horseygame/decompiled/rust-llm/` to keep separate
from the falcon-printer output. Compare quality on the
documented key-funcs. If quality is meaningfully better
than falcon-printer for those functions, promote to
primary path for deep dives.

## Why not just pick one

We don't have to. Each path has a coverage envelope
where it's the right call:

- Path A is best for **speed and ownership**.
- Path B would be best for **mid-quality on a Rust
  stack** (if we build it).
- Path C is best for **quality on critical
  functions** (no extra dev cost; just runs the
  existing models).

Committing to one prematurely forces the user to wait
on whichever path's weakness is currently blocking
them. Maintaining three at once means we pay a thin
maintenance tax per path and gain coverage across the
problem space. Rust output remains the goal in all
three.

## What this doc replaces

This supersedes the simpler "build Falcon, treat libsla
as fallback" framing in [`survey.md`](survey.md) "Open
at decision time" section. That framing was true at
Phase 0 (before the second-pass audit); the wider
landscape makes a single-path plan the wrong shape.