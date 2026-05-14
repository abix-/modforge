# falcon-printer (RETIRED 2026-05-14)

> **This crate has been retired** in favor of
> [`../decomp/`](../decomp/), which uses
> [r2sleigh](https://github.com/radareorg/r2sleigh)
> (SLEIGH-based, full SSE/AVX, multi-thousand-line
> structurer) instead of Falcon. Cargo.toml + src/ removed;
> docs preserved as a historical archive of the prototype
> and the migration reasoning.
>
> Look here for:
> - [`docs/strategy.md`](docs/strategy.md): the migration
>   plan + phase-by-phase status.
> - [`docs/survey.md`](docs/survey.md): the ecosystem
>   survey that surfaced r2sleigh as the right substrate.
> - [`docs/passes.md`](docs/passes.md): the middle-end
>   passes the falcon-printer prototype built. Most are
>   r2sleigh's responsibility upstream now, but the pass
>   names + patterns documented here may inform future
>   r2sleigh contributions.
> - [`docs/architecture.md`](docs/architecture.md): the
>   Falcon-based pipeline (now historical).
>
> For the active tool, see [`../decomp/`](../decomp/).
>
> What follows is the original README, preserved for
> historical context.
>
> ---
>
> Rust output backend for [Falcon](https://github.com/falconre/falcon).
> Takes a stripped PE binary, lifts each function to Falcon IL, runs
> a small set of middle-end passes, and prints `unsafe fn`-shaped Rust
> pseudocode. The output is for *reading*, not compiling: it gives us
> a Rust-syntax view of game functions so RE artifacts live in the
> same language as the mods that consume them.

## Why

We are doing a LOT of reverse engineering across the game-mod
workspace (~70% Rust). Reading Ghidra's C pseudocode then translating
it in our heads to Rust on every function wastes time and loses
information. The goal: emit Rust as the daily-driver notation for
decompiled code.

Output is *notation*. `unsafe fn` with raw-pointer reads/writes and
explicit `goto`-style block labels is the target shape. It will not
compile cleanly. That's fine; we read it, then write the mod against
the patterns we see.

Deep-dive lives in [`docs/`](docs/):

- [`docs/survey.md`](docs/survey.md). Why Falcon and not the
  alternatives (Fission, libsla, c2rust, LLM transpilers,
  Ghidra plugin).
- [`docs/architecture.md`](docs/architecture.md). The full
  pipeline, the Falcon-vs-falcon-printer ownership split,
  the Falcon IL shape.
- [`docs/passes.md`](docs/passes.md). One section per
  middle-end pass with input / output / examples.
- [`docs/coverage.md`](docs/coverage.md). Lift-rate
  measurement methodology and current numbers.
- [`docs/usage.md`](docs/usage.md). How to drive each binary.
- [`docs/building.md`](docs/building.md). Build deps,
  common failures.
- [`docs/polish-ladder.md`](docs/polish-ladder.md). Open
  work.
- [`docs/non-goals.md`](docs/non-goals.md). What we
  explicitly are NOT building.

## Pipeline

```
horsey.exe bytes
  -> Falcon: PE loader -> capstone disasm -> x86-64 lift -> Falcon IL
  -> Falcon: dead-code-elimination
  -> our pass: fold single-use temps
  -> our pass: x86 flag-pattern recognition (recover `X cmp Y` from ZF set)
  -> our pass: cross-block flag propagation through synth-junction blocks
  -> our pass: collapse Falcon's empty synth-junction blocks
  -> our pass: simplify conditions ((X == 0) == 0 -> X != 0)
  -> our pass: call recovery (rsp -= 8; [rsp] = ret; branch X  =>  Call(X))
  -> our pass: ret recovery (load [rsp]; rsp += 8; branch t   =>  Return)
  -> our pass: drop dead flag bindings
  -> Rust printer: emit unsafe fn with if/else for inverse-cond succ pairs
```

Falcon owns everything below the IL line. We own the middle-end
passes and the printer. SSE/AVX instructions fall through to
opaque `Intrinsic` IL nodes via
`Options::set_unsupported_are_intrinsics(true)`; the rest of the
function still lifts cleanly even when float-math interleaves with
integer game-state code.

## Subcommands

One binary, `falcon-printer.exe`, with four subcommands:

| Subcommand | What it does |
|---|---|
| `print --addr 0xADDR` | Lift one function, print Rust to stdout. |
| `batch [--out DIR]` | Read addresses from stdin, write one `.rs` per fn. |
| `sweep [--addrs FILE] [--falcon-entries]` | Lift many addresses; report pass/fail counts + failure breakdown. |
| `dump-il --addr 0xADDR` | Dump raw Falcon IL for one function (debug aid). |

Global flag: `--bin <PATH>` overrides the default
target binary (`Horsey.exe` at
`C:/Games/Steam/steamapps/common/Horsey Game/Horsey.exe`).

Default sweep address source: `falcon-printer/ghidra_addrs.txt`
(10,332 entries pulled from Ghidra's INDEX.md).

## Quick start

```powershell
cd C:\code\grounded2mods\falcon-printer

# print one function as Rust
..\target\release\falcon-printer.exe print --addr 0x140089510

# bulk lift everything Ghidra found, into ../horseygame/decompiled/rust/
Get-Content .\ghidra_addrs.txt `
    | ..\target\release\falcon-printer.exe batch

# measure current lift coverage
..\target\release\falcon-printer.exe sweep
```

## Status

- Lift rate: **88.8%** (9,170 / 10,332 Ghidra-discovered functions).
  Failures are dominated by `DisasmFailureUnrecoverable` on
  Ghidra-over-discovered padding/data addresses, not real game code.
- Sample artifacts shipped: 11 files in `../horseygame/decompiled/rust/`
  totalling 30,527 lines. Highlights:
  `save_filename_format`, `click_race_when_ready_dialog`
  (9k lines, UI event handler), `simulation_paused_status`,
  `price_or_score_formula`, `SDL_CloseSensor`.
- Function names pulled from
  `../horseygame/decompiled/INDEX.md` (Ghidra index) and
  `../horseygame/decompiled/key-funcs/` (slugs from documented
  filenames). Where neither is available, names default to
  `fn_<addr>`.

## Polish ladder

In priority order. Full details in
[`docs/polish-ladder.md`](docs/polish-ladder.md):

1. Tail-call recognition (Falcon currently inlines tail-called
   helpers).
2. SBB / ADC peephole (clean up x86 borrow chains).
3. Struct-shape recovery via a per-binary YAML side-table
   (`horseygame/structs.yaml`) so `*(rdi+0x124)` becomes
   `dialog.counter`.
4. Comment passthrough from Ghidra's annotated C output.
5. Mass function naming (today ~20 named; goal ~30%+).
6. Loop / switch structurization beyond if/else.
7. Bulk pass over all 9,170 lifted functions, output to
   `horseygame/decompiled/rust/`, rust-analyzer indexed.

## Build deps

Beyond the Rust toolchain, you need:

- **LLVM** (provides `libclang.dll` for `bad64-sys` bindgen).
  `winget install LLVM.LLVM`. Set
  `LIBCLANG_PATH=C:/Program Files/LLVM/bin` for cargo.
- **CMake** (Falcon bundles Capstone C source and builds via cmake).
  `winget install Kitware.CMake`. Add `C:/Program Files/CMake/bin`
  to PATH.

Both are one-time installs. Build:

```powershell
$env:LIBCLANG_PATH = "C:/Program Files/LLVM/bin"
$env:PATH += ";C:/Program Files/CMake/bin"
cargo build --release -p falcon_printer
```

First build is ~2 minutes from cold; incremental rebuilds of the
printer alone are seconds.

## What this is NOT

- **A decompiler.** Falcon does the lifting and IR. We add a small
  middle-end and a Rust printer. Without Falcon, none of this works.
- **A compilable-output transpiler.** No struct recovery, no
  ownership inference, no lifetimes. Emitting `let mut rax: u64 = ...`
  is fine; the borrow checker will hate it. We don't care.
- **A replacement for Ghidra.** Ghidra stays installed as ground
  truth. Its C output is what we cross-check Falcon against.
