# Usage

> How to drive each binary. Examples assume the workspace is
> at `C:\code\grounded2mods` and the release build has been
> done (see [`building.md`](building.md)).

## Binaries at a glance

| Bin | Purpose | Inputs | Outputs |
|---|---|---|---|
| `rust_print` | Lift one fn, print Rust | binary path + addr | stdout |
| `batch_print` | Lift many fns from stdin | binary, out dir, stdin (addrs) | `<dir>/fn_<addr>.rs` per fn |
| `sweep_ghidra` | Coverage measurement | binary + addr list file | stdout summary |
| `dump_il` | Raw Falcon IL inspector | binary + addr | stdout |
| `sweep` | Lift Falcon PE entries (sanity) | binary | stdout summary |

All binaries default to Horsey at
`C:/Games/Steam/steamapps/common/Horsey Game/Horsey.exe`.
First positional arg overrides; second arg (where
applicable) is the function address.

Release binaries live at
`..\target\release\<binname>.exe` after `cargo build --release`.

## rust_print: one function at a time

```powershell
..\target\release\rust_print.exe `
    "C:/Games/Steam/steamapps/common/Horsey Game/Horsey.exe" `
    0x140089510
```

Default address is `0x140089510` (save_filename_format) if
omitted. Output goes to stdout; redirect to a file when
saving.

Reading the output:

- File comment header notes the address and the pipeline
  stages that ran.
- `pub unsafe fn <friendly_name>()` opens the function.
  Names come from
  [`../../horseygame/decompiled/INDEX.md`](../../horseygame/decompiled/INDEX.md)
  and key-funcs filenames; missing entries get `fn_<addr>`.
- Block separators `// ---- bb<idx> @ 0x<addr> ----`
  delimit basic blocks.
- Inline comments `/* 140089510 */` carry the source x86
  instruction address.
- `core::ptr::read(addr as *const T)` is a memory load.
- `core::ptr::write(addr as *mut T, val)` is a store.
- `fn_<addr>()` is a direct call recovered by
  pass_call_recovery.
- `return;` is a recovered `ret`.
- `if cond { /* -> bbA */ } else { /* -> bbB */ }` is a
  recovered cmp+jcc pair.
- `if cond { /* -> bbA */ }` (single-arm) is a
  non-canonical conditional, or a multi-edge dispatch
  where conditions aren't strict inverses.

## batch_print: many functions

```powershell
# from a literal list:
@'
0x140089510
0x140094a20
0x140066200
'@ | ..\target\release\batch_print.exe

# all the documented key-funcs:
Get-ChildItem ..\horseygame\decompiled\key-funcs\*.c `
    | ForEach-Object { ($_.Name -split '_')[0] } `
    | ..\target\release\batch_print.exe

# everything Ghidra found:
Get-Content .\ghidra_addrs.txt `
    | ..\target\release\batch_print.exe
```

Output dir defaults to
`C:/code/grounded2mods/horseygame/decompiled/rust/`.
One `fn_<addr>.rs` per address that lifts successfully;
failures are silently skipped (counted in stderr).

## sweep_ghidra: measure lift rate

```powershell
..\target\release\sweep_ghidra.exe
```

Reads `ghidra_addrs.txt` from the working dir by default
and prints:

```
[sweep-ghidra] DONE: 9170/10332 lifted (88.8%)
[sweep-ghidra] top failure reasons:
   1037  DisasmFailureUnrecoverable    (sample: 0x140040ea0)
   ...
```

Use after a Falcon version bump or a pre-print pass change
to confirm no regression. Full breakdown in
[`coverage.md`](coverage.md).

## dump_il: pre-printer IL

```powershell
..\target\release\dump_il.exe `
    "C:/Games/Steam/steamapps/common/Horsey Game/Horsey.exe" `
    0x140089510
```

Prints the raw Falcon IL for the function, one block at a
time, including the unmodified edges and conditions. Use
when `rust_print` output looks wrong and you want to see
what the lifter produced before our middle-end passes
touched it.

## sweep: sanity check

```powershell
..\target\release\sweep.exe
```

Iterates Falcon's own `function_entries()` (PE exception
table; ~1,272 entries for Horsey, mostly thunks and
exports). Should report 99.8%+ lift. If this drops, the
toolchain or Falcon version is broken; debug here before
running `sweep_ghidra`.

## Reading output: example

```rust
// bb18 @ 0x140094a69
let mut t = 0_u32;
core::ptr::write((rdi).wrapping_add(0x124) as *mut u32, t as u32);
let mut counter = core::ptr::read((rdi).wrapping_add(0x254) as *const u32);
core::ptr::write((rdi).wrapping_add(0x254) as *mut u32, counter.wrapping_add(1));
let mut flag = core::ptr::read((rdi).wrapping_add(0x258) as *const u8);
if (flag == (t as u8)) {
    /* -> bb25 */
} else {
    /* -> bb19 */
}
```

Reads as: "rdi points to a struct (probably a dialog
state). Zero the 32-bit field at offset 0x124. Increment
the 32-bit counter at offset 0x254. Read the 8-bit flag at
offset 0x258; if it's zero, go one way, else the other."

That's enough to plan a mod hook: patch the load at 0x258
to always return 1, for example, or hook the write to
0x254 to multiply the increment.
