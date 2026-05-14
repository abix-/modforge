# Polish ladder (post r2sleigh migration)

> Phase 5 of [`../../falcon-printer/docs/strategy.md`](../../falcon-printer/docs/strategy.md).
> Most of the old falcon-printer ladder (loops / switches /
> SSA / type inference) is now upstream's responsibility in
> r2sleigh. This ladder is what's left between current
> shipping state and "great" for `decomp`.

## Status today (2026-05-14)

Working: lift + SSA + decompile + Rust emit for **13 of 18
documented Horsey key-funcs**. Built in WSL (libsla-sys
doesn't build on Windows MSVC). CLI parity with
falcon-printer: `print` / `batch` / `dump-il`. Names
recovered from `horseygame/decompiled/INDEX.md` plus
`horseygame/decompiled/key-funcs/*.c` filename slugs.

## 1. Windows build (libsla-sys POSIX shims)

**Symptom:** `cargo build` on Windows MSVC fails because
Ghidra's C++ libsla source uses POSIX `<unistd.h>` headers
not present in MSVC's stdlib.

**Fix:** upstream PR to `libsla-sys` adding Windows
compat shims:
- `unistd.h` -> `io.h` + Win32 equivalents for read/write
  semantics.
- `pthread.h` -> Win32 threading or std::thread inside
  the C++ source.
- Path separator handling.
- The actual sleigh decoder logic is platform-neutral;
  the surface code that wraps it is what needs the
  shims.

**Effort:** moderate. Multi-engineer-week of C++ work
on libsla-sys. Most realistic path: contribute upstream.

**Unblocks:** Phase 4 cutover. Once libsla-sys builds on
Windows, decomp becomes a regular workspace member and
the falcon-printer crate retires.

## 2. libsla-internal stack overflows

**Symptom:** 5 of 18 key-funcs (`simulation_paused_status`,
`save_path_writer_1`, `genome_clipboard_copy_paste`,
`genes_dat_handler`, `horse_is_dead_handler`) crash with
"thread '\<unknown\>' has overflowed its stack". The
overflow happens in a libsla-internal thread our 1GB Rust
stack doesn't reach.

**Fix:** two paths:
1. **Basic-block splitting before lift**: instead of
   passing the whole function as one `R2ILBlock` of
   ~1000 IL ops, split at branches and feed many small
   `R2ILBlock`s to SSA construction. SSA depth drops
   linearly; structurer happier. Requires us to do CFG
   analysis on the function bytes BEFORE lift, since
   r2sleigh assumes radare2 did that.
2. **Upstream patch**: add stack guards inside r2sleigh's
   own recursion (region analyzer, SSA builder).

**Effort:** option 1 is medium (port basic-block discovery
from Falcon to operate on Sleigh-lifted IL); option 2
needs upstream coordination.

## 3. Sweep subcommand

**Symptom:** falcon-printer had `sweep` to measure lift
rate across 10k+ addresses. decomp doesn't yet.

**Fix:** port the sweep loop. Each call into r2sleigh
takes hundreds of ms; full 10k sweep is hours, not
minutes. Likely need parallel workers + progress
reporting.

**Effort:** small for naive serial; medium for
parallel with sane error handling.

## 4. Argument recovery + parameter types

**Symptom:** today r2sleigh recovers some parameter
arguments (e.g., `pub unsafe fn price_or_score_formula(arg1: i64, arg2: i64)`)
but most functions still show as `()`. The arg recovery
seems related to whether r2sleigh's type inference
found a calling-convention match.

**Fix:** investigate r2sleigh's `r2types` constraint-based
inference. Better function signatures upstream means
better Rust output for free. May involve helping it find
more signatures by passing better hints from our
naming layer.

**Effort:** depends on r2types' state; small if it's a
configuration tweak, medium if it needs new fact-flow.

## 5. Struct shape recovery

**Symptom:** field accesses still show as
`*(rdi_1 + 592_i64) = 13_i64`. We'd want
`(*dialog).counter = 13` where the type is known.

**Fix:** per-binary YAML schema (same idea as the
falcon-printer ladder item, just now feeding r2types
instead of our own printer). Schema lives at
`horseygame/structs.yaml`; printer pass consumes
when rendering.

**Effort:** medium. The schema population is per-struct
RE labor.

## 6. Rust-idiom polish

The current emit produces Rust *syntax* but not
particularly *idiomatic* Rust. Items here are quality of
life:

- Recover Rust-style enum patterns where switch cases
  match a tag field.
- Emit `Option<*const T>` for nullable pointers (recover
  from `if p == 0` patterns).
- Use `core::ptr::read_volatile` / `write_volatile` for
  what looks like MMIO.
- Inline trivial single-use temps the way falcon-printer
  did. r2dec's SSA usually keeps temps; we could trim.

**Effort:** small per item; ladder of mini-passes.

## 7. Comment passthrough from Ghidra annotated C

Same idea as falcon-printer's ladder item: read
Ghidra's annotated C output from
`horseygame/decompiled/annotated/`, lift the leading
`/* ... */` comments, emit as Rust docstrings above the
`unsafe fn`.

**Effort:** small. Drop-in.

## 8. Workspace integration + cutover

Once item 1 (Windows build) lands:

- Move decomp/ into the cargo workspace `[members]`.
- Delete falcon-printer/ (commit its source + docs to
  git history is the archive).
- Repoint repo README.md, workspace todo.md.
- Rename `horseygame/decompiled/rust-r2sleigh/` to
  `horseygame/decompiled/rust/` (replacing the
  falcon-printer artifacts there).

**Effort:** small mechanical work once unblocked.
