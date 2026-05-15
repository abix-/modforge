# Polish ladder

> 2026-05-14: this ladder is **frozen** pending the
> r2sleigh migration described in
> [`strategy.md`](strategy.md). Most items below
> (loop / switch structurization, SSA, type inference,
> tail-call recognition) are r2sleigh's responsibility
> upstream; we don't build them ourselves anymore.
>
> The active work is now the migration itself:
> phase 1 spike, then phases 2-4 rewrite. See
> strategy.md for the phased plan and decision gates.
>
> Items below are preserved as the historical record
> of where falcon-printer was headed before the
> substrate switch. Re-evaluate each one against
> r2sleigh's actual output after phase 1 lands;
> only items r2sleigh DOESN'T already solve survive
> as new ladder items on the post-migration crate.

## 0. ~~Consolidate the five binaries into one~~ DONE 2026-05-14

Done. Single binary `falcon-printer` with four clap
subcommands (`print`, `batch`, `sweep`, `dump-il`).
`sweep_ghidra` and `sweep` merged into one subcommand with
`--falcon-entries` flag. Old binaries (`rust_print.exe`,
`batch_print.exe`, `sweep_ghidra.exe`, `sweep.exe`,
`dump_il.exe`) deleted; their code is consolidated into
`src/main.rs`. `Cargo.toml` declares
`[[bin]] name = "falcon-printer"`. See
[`../README.md`](../README.md) and
[`usage.md`](usage.md) for new invocations.

Batch is now in-process (no subprocess spawn per address)
which makes it dramatically faster for large lists.

## 1. Tail-call recognition

**Symptom:** functions sometimes show the body of a tail-callee
inlined. E.g., `fn_140003b80` ends with the body of
`fn_1402c77dc` after its own epilogue.

**Fix:** after pass_ret_recovery, look for the pattern:
- block ends with epilogue (sequence of pop-style loads + rsp +=N)
- final stmt is `Branch { target: Const(addr) }`

When matched, replace the branch with `Stmt::TailCall(addr)`.
The printer emits `tailcall_<name>(); return;` and stops
walking into the callee.

**Effort:** small. One new pass, ~40 LOC. The detection
pattern is well-defined.

## 2. SBB / ADC peephole

**Symptom:** `sbb rax, rax` (a common "set to -1 if CF
else 0" idiom) lifts to ugly chains like
`(rax - (rax + CF))`.

**Fix:** recognize the idiom in the Rust IR after
pass_fold_temps. Replace with `if CF { -1_i64 as u64 } else { 0 }`.
Same for `adc reg, 0` (add carry).

**Effort:** small. One pattern-match pass.

## 3. Struct shape recovery (YAML schema)

**Symptom:** memory access shows as
`(rdi).wrapping_add(0x124) as *mut u32`. A reader has to
know `rdi` is a DialogState and 0x124 is the counter field.

**Fix:** a per-binary side-table at
`horsey-mod/research/structs.yaml`:
```yaml
- name: DialogState
  size: 0x300
  fields:
    - { offset: 0x124, name: counter, type: u32 }
    - { offset: 0x254, name: tick_count, type: u32 }
    - { offset: 0x258, name: open, type: u8 }
```

Plus a hint table mapping function-name + register-arg to
struct (`click_race_when_ready_dialog: rcx=*DialogState`).

Printer pass: when emitting a memory access where the
base+offset matches a known field, render as
`(*dialog).counter = ...` instead of pointer arithmetic.

**Effort:** medium. The pass is ~100 LOC; populating the
YAML is the actual labor (per-binary, per-struct).

## 4. Comment passthrough from Ghidra annotated C

**Symptom:** the Rust output has no docstring per function;
all you get is the address.

**Fix:** read
`horsey-mod/research/decompiled/annotated/<name>.c`. Take the
`/* ... */` and `//` blocks above the function in Ghidra's
output. Emit as a `///` docstring above the `unsafe fn`.

**Effort:** small. Parse-and-emit step at print time.

## 5. Mass function naming

**Symptom:** today ~20 functions have friendly names. The
rest are `fn_<addr>`. After mass naming we'd see things like
`open_settings_dialog()` instead of `fn_14008a000()` in call
sites.

**Fix sources:**
- Ghidra FunctionID DB (signature-matched library functions).
- String anchors: "saveDir is %s" near a function -> name
  the function `save_dir_setter`.
- Windows API call patterns (CreateFileW + a string arg -> `open_file_<filename>`).

**Effort:** medium. Each technique is a separate analysis pass.
First win: just pull symbol names Ghidra already has into
INDEX.md and recheck the override layer; might give us 100+
named functions for free.

## 6. Loop / switch structurization

**Symptom:** today the only structure beyond a basic block
is if/else for inverse-condition pairs. Loops and switches
print as goto-style block comments.

**Fix:** classic decompiler middle-end work.
- Loop detection: find natural loops (Tarjan SCC over the
  reduced CFG, find back-edges).
- Loop body rewrite: emit `loop { ... break; }` or
  `while <cond> { ... }` based on the exit edge.
- Switch detection: pattern-match jump-table dispatch in
  the lifted IL. Recover `match` blocks.

**Effort:** large. This is the biggest single remaining
piece. Multi-week if done from scratch. Worth doing once
the smaller passes (1-5) are exhausted, because at that
point the output for non-loop functions is good enough
that the loop-heavy ones become the bottleneck.

## 7. Bulk pass over all 9,170 lifted functions

**Symptom:** today only 11 sample artifacts shipped. The
remaining ~9,100 successful lifts aren't on disk.

**Fix:** add a `regenerate.ps1` script that runs
`Get-Content ghidra_addrs.txt | falcon-printer.exe batch`.
Cost: ~30 minutes of wall time, ~50MB of `.rs` files.

**Effort:** trivial mechanically; but the output dir will
need to be gitignored or partitioned (we don't want a 50MB
diff in every commit). Decision deferred until after
tail-call recognition lands so the artifacts don't churn
on every pass change.

## 8. SSA conversion (deferred)

**Symptom:** without SSA, every register reassignment is
visible (`rsp = rsp + 8` appears 7 times in a function
epilogue).

**Fix:** Falcon doesn't ship SSA conversion. We'd implement
it ourselves over Falcon IL or use the def-use chain
helpers Falcon does provide. After SSA the printer could
emit unique names per def, making the data flow obvious.

**Effort:** medium-to-large. Real value but blocked behind
type recovery (#3). SSA without struct/type recovery
doesn't help reading much.

## What this list does NOT include

- SSE/AVX coverage in Falcon's translator. Solved by
  `unsupported_are_intrinsics(true)`; output loses precision
  on XMM state but reads cleanly. Only worth revisiting if
  we hit a game function where the integer side depends on
  SSE-computed values.
- Anything from [`non-goals.md`](non-goals.md).

## How to add to this list

Make the entry concrete:

1. **Symptom**: what does the user see today that's wrong?
2. **Fix**: what's the technical approach?
3. **Effort**: small / medium / large, and what blocks it.

Bullet points like "make it better" don't belong here.
