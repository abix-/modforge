# Usage

> How to drive `falcon-printer`. All examples assume the
> workspace is at `C:\code\grounded2mods` and the release
> build has been done (see [`building.md`](building.md)).

## Subcommands at a glance

| Subcommand | Purpose | Inputs | Outputs |
|---|---|---|---|
| `print` | Lift one fn, print Rust | `--addr` | stdout |
| `batch` | Lift many fns from stdin | `--out`, stdin (addrs) | `<dir>/fn_<addr>.rs` per fn |
| `sweep` | Coverage measurement | `--addrs` or `--falcon-entries` | stdout summary |
| `dump-il` | Raw Falcon IL inspector | `--addr` | stdout |

Global flag (works on every subcommand):
- `--bin <PATH>`  override the default binary
  (`C:/Games/Steam/steamapps/common/Horsey Game/Horsey.exe`).

Release binary: `..\target\release\falcon-printer.exe`
after `cargo build --release -p falcon_printer`.

## print: one function at a time

```powershell
..\target\release\falcon-printer.exe print --addr 0x140089510
```

Optional `--bin` for a different binary:
```powershell
..\target\release\falcon-printer.exe `
    --bin "C:/path/to/some.exe" `
    print --addr 0x401000
```

Reading the output:

- File comment header notes the address and the pipeline
  stages that ran.
- `pub unsafe fn <friendly_name>()` opens the function.
  Names come from
  [`../../horseygame/decompiled/INDEX.md`](../../horseygame/decompiled/INDEX.md)
  and `key-funcs/` filenames; missing entries get
  `fn_<addr>`.
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

## batch: many functions

```powershell
# from a literal list:
@'
0x140089510
0x140094a20
0x140066200
'@ | ..\target\release\falcon-printer.exe batch

# all the documented key-funcs:
Get-ChildItem ..\horseygame\decompiled\key-funcs\*.c `
    | ForEach-Object { ($_.Name -split '_')[0] } `
    | ..\target\release\falcon-printer.exe batch

# everything Ghidra found:
Get-Content .\ghidra_addrs.txt `
    | ..\target\release\falcon-printer.exe batch
```

Output dir defaults to
`C:/code/grounded2mods/horseygame/decompiled/rust/`.
Override with `--out <DIR>`. One `fn_<addr>.rs` per
address that lifts successfully; failures are silently
skipped (counted in stderr).

## sweep: measure lift rate

```powershell
# default: Ghidra address list at ./ghidra_addrs.txt
..\target\release\falcon-printer.exe sweep

# Falcon's own PE-table entries (smaller; sanity check)
..\target\release\falcon-printer.exe sweep --falcon-entries

# custom address list
..\target\release\falcon-printer.exe sweep --addrs my_addrs.txt
```

Output shape:
```
[sweep] 10332 addresses from ghidra_addrs.txt
[sweep] DONE: 9170/10332 lifted (88.8%)
[sweep] top failure reasons:
   1037  DisasmFailureUnrecoverable    (sample: 0x140040ea0)
   ...
```

Use after a Falcon version bump or a pre-print pass
change to confirm no regression. Full breakdown in
[`coverage.md`](coverage.md).

## dump-il: pre-printer IL

```powershell
..\target\release\falcon-printer.exe dump-il --addr 0x140089510
```

Prints the raw Falcon IL for the function, one block at a
time, including the unmodified edges and conditions. Use
when `print` output looks wrong and you want to see what
the lifter produced before our middle-end passes touched
it.

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
the 32-bit counter at offset 0x254. Read the 8-bit flag
at offset 0x258; if it's zero, go one way, else the
other."

Enough to plan a mod hook: patch the load at 0x258 to
always return 1, or hook the write to 0x254 to multiply
the increment.
