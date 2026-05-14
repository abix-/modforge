# decomp

> Successor to [`../falcon-printer/`](../falcon-printer/). Same goal
> (Rust output as RE notation) on a much better substrate: builds on
> [r2sleigh](https://github.com/radareorg/r2sleigh) (radare2 org's
> SLEIGH-based decompiler stack) and walks the public `r2dec::ast::CFunction`
> AST to emit Rust syntax instead of C.
>
> **Read [`docs/retrospective.md`](docs/retrospective.md) before
> investing further.** The honest 2026-05-14 assessment is that this
> project was mostly a waste of time relative to the Ghidra C decomp
> we already had. The crate still works as a spike; the artifacts are
> proof-of-concept, not deliverables. If you're here to use the tool,
> proceed below. If you're here to extend it, read the retrospective
> first.

## Build

**Not a workspace member yet.** libsla-sys (which wraps Ghidra's C++
libsla) does not build on Windows MSVC because Ghidra C++ uses POSIX
`<unistd.h>` headers. Build inside WSL:

```bash
# In WSL Ubuntu:
cd ~
git clone https://github.com/radareorg/r2sleigh.git
# Mirror this crate to ~/decomp/ (or just symlink):
ln -s /mnt/c/code/grounded2mods/decomp ~/decomp
cd ~/decomp
cargo build --release
```

First build: ~2 minutes (Ghidra C++ compilation via libsla-sys).
Incremental: seconds.

## Run

```bash
~/decomp/target/release/decomp \
    "/mnt/c/Games/Steam/steamapps/common/Horsey Game/Horsey.exe" \
    0x140089510 \
    4096 \
    rust
```

Args: `<binary>` `<addr>` `<size>` `<emit>`. `emit` is `c` (raw r2dec
output) or `rust` (our Rust emitter). Output goes to stdout.

## Pipeline

```
PE file (goblin) -> raw function bytes
  -> r2sleigh-lift Disassembler::lift_block -> R2ILBlock
  -> r2ssa SSAFunction::from_blocks_for_decompile -> SSAFunction
  -> r2dec Decompiler::build_function -> r2dec::ast::CFunction
  -> our emit_rust() -> Rust pseudocode
```

Everything below `emit_rust()` is r2sleigh's responsibility. We own
the AST walk + Rust syntax mapping (~300 lines).

## Output (sample)

Input: `0x140089510` (`save_filename_format` per Ghidra's INDEX.md).

```rust
#[allow(non_snake_case, ...)]
pub unsafe fn fn_140089510() {
    fn_1403ed558 = 0_i64;
    *(rdi_1 + 592_i64) = 13_i64;
    fn_1400ca670();
    fn_1400cef70();
    fn_1400ca560();
    *(rdi_5 + 224_i64) = 13_i64;
    *(rdi_5 + 224_i64) = 14_i64;
    *(rdi_5 + 596_i64) = *(rdi_5 + 596_i64) + 1_i64;
    *(rdi_5 + 1172_i64) = *(rdi_5 + 1172_i64) - 1_i64;
    ...
}
```

Vs falcon-printer's previous output for the same function: identical
function name (from Ghidra INDEX.md), but where falcon-printer wrote

```rust
core::ptr::write((rdi).wrapping_add(0x250) as *mut u64, 0xd_u64);
```

decomp writes:

```rust
*(rdi_1 + 592_i64) = 13_i64;
```

SSA versions visible (`rdi_1` vs `rdi_5`); struct offsets in decimal
(0x250 == 592); no synth-block dispatch noise; no ZF/SF/OF/CF chain
noise. The full r2sleigh substrate (SSA, type inference,
loop/switch structurer) is upstream and we get it for free.

Sample artifacts checked in at
[`../horseygame/decompiled/rust-r2sleigh/`](../horseygame/decompiled/rust-r2sleigh/).

## What's still on the ladder

- **CLI subcommands**: port falcon-printer's `print` / `batch` /
  `sweep` / `dump-il` shape over to this crate.
- **Naming layer**: load `horseygame/decompiled/INDEX.md` to
  override `fn_<addr>` with friendly names. Lift the existing
  falcon-printer logic.
- **Basic-block splitting**: today we lift the whole function as
  one R2ILBlock; SSA gets one block. With proper basic-block
  boundary detection (Falcon-style) the structurer gets to recover
  loops and switches.
- **Compile-on-Windows**: libsla-sys needs Windows compatibility
  shims (Win32 equivalents for `unistd.h` POSIX calls). Upstream
  PR territory; until then, WSL-only build.
- **Workspace integration**: once Windows builds work, promote to
  workspace member and retire `falcon-printer/`.

## Why GPL-3.0

Inherited from r2sleigh (GPL-3.0). Output artifacts we produce
(decompiled Rust files) are ours; GPL viral applies to redistribution
of the tool, not its output. The user is fine with GPL-3.0.
