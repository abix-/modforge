# Architecture

> The pipeline diagram and the ownership split between Falcon
> and falcon-printer. Read this before touching `rust_print.rs`
> so you know which layer to modify.

## The pipeline

```
horsey.exe (PE bytes)
  |
  v
[Falcon] PE loader  (goblin under the hood)
  |  -> function_entries(), memory(), translator
  v
[Falcon] capstone disasm + x86-64 lift
  |  Options::set_unsupported_are_intrinsics(true)
  |  -> SSE/AVX become opaque Intrinsic nodes instead of errors
  v
[Falcon] il::Function (CFG of basic blocks of IL ops)
  |
  v
[Falcon] dead_code_elimination (drops never-used scalars)
  |
  v
[our] lower_to_rust_ir (Falcon IL -> RustIr)
  |  RustIr is our own Stmt/Expr enum, decoupled from Falcon
  v
[our pass] fold single-use temps
[our pass] x86 flag-pattern recognition         -- see passes.md
[our pass] cross-block flag propagation
[our pass] collapse Falcon's synth-junction blocks
[our pass] simplify conditions
[our pass] call recovery (rsp -= 8 + store + branch  =>  Call)
[our pass] ret recovery (load + rsp += 8 + branch    =>  Return)
[our pass] drop dead flag bindings
  |
  v
[our] print_rust (RustIr -> Rust syntax)
  |  - unsafe fn fn_<addr>() or friendly-name from INDEX.md
  |  - core::ptr::read / core::ptr::write for memory
  |  - if/else when two succ-conditions are inverses
  |  - block comments for non-inverse multi-edge dispatch
  v
*.rs file
```

## What Falcon owns

- **Loader**: PE / ELF parsing, function entry discovery from
  PE exception tables (returns 1,272 entries for Horsey;
  Ghidra finds ~10k more via code-flow heuristics that
  Falcon doesn't replicate).
- **Disassembler**: bundles Capstone via `falcon_capstone`.
  Capstone is the C disassembler from Aquynh; bundled source
  compiles into the falcon crate.
- **Lifter**: `falcon::translator::x86::Amd64` translates each
  Capstone instruction into Falcon IL ops. Hand-written in
  `falcon/lib/translator/x86/semantics.rs` (4,190 lines).
  Integer-side complete; SSE/AVX float ops fall through to
  `Intrinsic` markers (see below).
- **IL types**: `falcon::il::{Function, ControlFlowGraph,
  Block, Edge, Instruction, Operation, Expression, Scalar,
  Constant}`. 6 Operation variants, 23 Expression variants.
- **Analyses**: `dead_code_elimination`, basic constants
  propagation, fixed-point engine, def-use / use-def chains,
  calling-convention helpers, stack-pointer offset
  inference. No SSA, no structurizer, no call recovery, no
  type inference. Those are decompiler-specific concerns
  Falcon doesn't address.

## What falcon-printer owns

- **`RustIr`**: our own enum hierarchy in
  [`src/bin/rust_print.rs`](../src/bin/rust_print.rs). Block
  + Stmt + Expr that mirror Rust syntax shape, decoupled
  from Falcon IL. Lowering Falcon -> RustIr happens once,
  then passes operate on RustIr only.
- **Middle-end passes**: 8 passes, run in order. See
  [`passes.md`](passes.md). Each is a single function
  walking the RustIr.
- **Naming layer**: loads
  [`../../horseygame/decompiled/INDEX.md`](../../horseygame/decompiled/INDEX.md)
  (Ghidra address-to-name) and
  [`../../horseygame/decompiled/key-funcs/`](../../horseygame/decompiled/key-funcs/)
  (slug from filename) at startup. Overrides `fn_<addr>` with
  the friendly name where available.
- **Printer**: walks the post-passes RustIr, emits Rust syntax.
  Handles types (u1 -> bool, u8 / u16 / u32 / u64 / u128),
  signed/unsigned ops, casts, wrapping vs infix arithmetic,
  if/else for inverse-condition succs.

## The Falcon IL shape

Each x86 instruction becomes one or more IL operations. A
`cmp eax, 4` becomes four operations (one per flag):

```
ZF:1 = ((eax:32 - 4:32) == 0:32)
SF:1 = trun.1(((eax:32 - 4:32) >> 31:32))
OF:1 = trun.1((((eax:32 ^ 4:32) & (eax:32 ^ (eax:32 - 4:32))) >> 31:32))
CF:1 = (eax:32 <u (eax:32 - 4:32))
```

Conditional jumps (`jne label`) become CFG edges with their
condition being a boolean expression over the flags:

```
edge: head=this_block tail=label  cond=(ZF:1 == 0:1)
```

`call addr` decomposes to three ops:

```
rsp:64 = (rsp:64 - 8:64)
[rsp:64] = <return_addr_const>:64
branch <target>:64
```

`ret` decomposes to a load + add + branch:

```
temp:64 = [rsp:64]
rsp:64 = (rsp:64 + 8:64)
branch temp:64
```

Recognizing these multi-op patterns and reassembling them
into high-level constructs (cmp+jcc -> if, push+branch ->
call, etc.) is exactly what the middle-end passes do. See
[`passes.md`](passes.md).

## Synthetic junction blocks

Falcon sometimes inserts empty "junction" blocks
(`Block.address() == None`, no instructions, just routes a
condition to two destinations). These are useful for the
analysis side but useless for the printer side. The
`pass_collapse_synth_blocks` pass eliminates them after
flag-recognition has propagated through.

## Crate layout

```
falcon-printer/
  Cargo.toml             package = "falcon_printer"
  README.md              one-page intro
  ghidra_addrs.txt       10,332 hex addresses, one per line
  src/
    main.rs              legacy smoke test (prints arch + IL)
    bin/
      rust_print.rs      the printer + middle-end (single file)
      batch_print.rs     stdin -> rust_print -> .rs files
      sweep_ghidra.rs    coverage measurement
      sweep.rs           sanity sweep over Falcon PE entries
      dump_il.rs         raw IL dump (pre-printer)
  docs/                  you are here
```

## Why one big file for the printer + passes

`rust_print.rs` is ~700 lines and growing. It will eventually
split into modules (`ir.rs`, `passes/*.rs`, `print.rs`) but
the surface is small enough today that a single file is
faster to iterate on. Re-evaluate the split when passes
start needing shared utility traits.
