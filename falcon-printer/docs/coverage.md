# Coverage

> Lift-rate measurement methodology and current numbers.
> Re-run `sweep_ghidra` after any change that could touch
> Falcon coverage (version bump, new pass that mutates
> pre-lift state, etc.).

## Methodology

`sweep_ghidra` reads addresses from
[`../ghidra_addrs.txt`](../ghidra_addrs.txt) (one hex per
line, 10,332 entries pulled from Ghidra's INDEX.md), tries
`pe.function_extended(addr, &opts)` for each, and tallies:

- **ok**: Falcon returned a `Function` with a valid CFG.
- **err**: Falcon returned an error; classify by parsing the
  message.

Options used:
```rust
let mut opts = Options::new();
opts.set_unsupported_are_intrinsics(true);
```

`unsupported_are_intrinsics(true)` is critical. Without it,
the first unhandled instruction (commonly an SSE float op)
fails the WHOLE function. With it, those instructions
degrade to opaque `Intrinsic` IL nodes and the rest of the
function lifts cleanly.

## Current numbers (2026-05-14)

```
[sweep-ghidra] 10332 ghidra-discovered addresses
[sweep-ghidra] DONE: 9170/10332 lifted (88.8%)

[sweep-ghidra] top failure reasons:
   1037  DisasmFailureUnrecoverable     (sample: 0x140040ea0)
     84  Sort error, invalid bitness    (sample: 0x140016810)
     17  Could not find register X86_REG_RIZ
      8  Could not find register X86_REG_MM0
      6  Could not find register X86_REG_MM1
      3  Could not find register X86_REG_SPL
      3  Could not find register X86_REG_MM2
      1  Could not find register X86_REG_MM3
      1  unsupported rep prefix on `bnd jp`
      1  Could not find register X86_REG_MM7
      1  Could not find register X86_REG_MM4
```

Total reported failures: 1,162. Of those:

- **~1,037 (89%)** are `DisasmFailureUnrecoverable`: Capstone
  refuses to disassemble at the address. Almost always
  Ghidra over-discovery: padding bytes (0xCC chains), data
  embedded between functions (jump tables, vtables, string
  pools), or mid-instruction addresses Ghidra heuristically
  flagged as entries. NOT real game-function failures.
- **84** internal Falcon bitness mismatches (`Sort error`).
  These ARE real Falcon bugs but they happen on rare
  instruction encodings.
- **~36** MMX register failures. Falcon's x86 register
  table doesn't include MM0-MM7. MMX is dead in modern
  game code; impact is tiny.
- **1** weird `bnd jp` instruction (Intel MPX, basically
  unused in real binaries).

**Real game-function lift rate is effectively ~95%+.** The
remaining 5% is either MMX (irrelevant) or true Falcon
bugs worth filing upstream when we hit one in practice.

## Before the intrinsics flag

For posterity: the initial sweep (with default Options)
got **63.1%** lift rate. Failures were dominated by SSE/SSE2
float instructions:

```
   599  unhandled: movss
   549  unhandled: int3           (padding, false-positive)
   390  unhandled: xorps
   183  unhandled: retf           (far return, rare)
   110  unhandled: cvtdq2ps
   101  unhandled: sal
   ...
```

After flipping `unsupported_are_intrinsics(true)`, the
`unhandled:` class collapses to zero. Those instructions
now lift as `Intrinsic` nodes. The trade-off: the IL no
longer models what those SSE ops did to XMM registers, so
analyses that depend on XMM state lose precision. For our
use case (reading code to plan integer-side mod hooks),
that's acceptable.

## What would push higher

1. **Stop feeding Ghidra-over-discovered addresses.**
   Easy quick win: filter `ghidra_addrs.txt` to remove
   entries where Capstone refuses to decode. Drops the
   "DisasmFailureUnrecoverable" class from the denominator.
2. **Fix the 84 bitness mismatches in Falcon.** Worth a
   minimal repro per case, then upstream PR.
3. **Add MMX registers to Falcon's x86register table.**
   Trivial PR. Low impact (modern games don't use MMX).
4. **Replace `unsupported_are_intrinsics` fallback with
   real SSE semantics.** Falcon's `translator/x86/semantics.rs`
   would grow ~100 functions. Each is conceptually simple
   (load/store/arith on 32-bit floats in 128-bit XMMs).
   High effort, modest payoff: the integer side of game
   functions is what we want to read, and that side
   already lifts.

## How to run

```powershell
$env:LIBCLANG_PATH = "C:/Program Files/LLVM/bin"
$env:PATH += ";C:/Program Files/CMake/bin"
cargo build --release --bin sweep_ghidra -p falcon_printer
..\target\release\sweep_ghidra.exe `
    "C:/Games/Steam/steamapps/common/Horsey Game/Horsey.exe" `
    .\ghidra_addrs.txt
```

Wall time: ~30-60 seconds on a modern desktop. Per-function
lift is hundreds of microseconds.
