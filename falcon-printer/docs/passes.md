# Middle-end passes

> One section per pass in execution order. Each section
> describes the input shape, the recognition pattern, and the
> transformation. When a pass produces wrong output, this is
> the file to consult.

All passes live in
[`src/main.rs`](../src/main.rs). The
entry-point `main()` runs them in this exact order.

## 1. lower_to_rust_ir

Not technically a pass; the initial Falcon IL -> RustIr
translation. One Stmt per IL Operation, one Expr per IL
Expression. Scalar names are sanitized
(`temp_0x140089510` -> `t_140089510`). The first definition
of a scalar emits `Stmt::Let`; subsequent assignments emit
`Stmt::Reassign`. Successor edges are copied with their
conditions lowered to `Expr`.

## 2. pass_fold_temps

**Input pattern:**
```rust
let t_140089510: u32 = <expr>;
... no other use of t_140089510 except one read ...
```

**Output:**
```rust
... t_140089510 inlined at the unique use site ...
```

**Why:** Falcon emits one IL op per machine instruction.
Even simple things like "mov rcx, [rax+8]" become "load
into temp; assign temp to rcx". Without folding, every line
has a temp-then-assign chain that hides the actual data flow.

**Limits:** only folds names beginning with `t_` (Falcon's
own temps). Won't fold register renames. Won't fold if the
temp is read more than once (would duplicate side effects).
Won't fold across a redefinition.

## 3. pass_flag_recognition

**Input pattern (canonical x86 cmp):**
```rust
let ZF = ((X - Y) == 0);
let SF = trun.1(((X - Y) >> 31));
let OF = ...;
let CF = X < (X - Y);
```

Followed by a CFG successor whose condition reads ZF.

**Output:**
- The four flag let-bindings are removed from the block.
- The recovered `(X, Y)` pair is stored on
  `block.flag_src`.
- Successor conditions inside the same block that match
  `ZF == 0` / `ZF == 1` patterns get rewritten:
  - `ZF == 1`  -> `X == Y`
  - `ZF == 0`  -> `X != Y`

**Why:** Falcon faithfully models each flag bit but the
human-meaningful operation is "did this cmp succeed?".
Reading `ZF == 0` is harder than reading `t != 4`.

**Limits:** only recognizes the ZF arm of the
cmp-style pattern. SF/CF/OF reads are NOT rewritten into
"<" / ">" / signed comparisons yet; today they're just
dropped by `pass_drop_dead_flags` if unused. Conditional
jumps that branch on SF/CF (`jl`, `jb`, etc.) currently
print as raw bit comparisons. Ladder item.

## 4. pass_propagate_flags_across_blocks

**Input:** A block's `succs` reference `ZF` directly
(unrewritten by step 3) because the flag was set in a
parent block, then control flowed through a synth-junction.

**Output:** BFS over predecessors to find the closest
`block.flag_src`, then rewrite this block's succ conditions
with the same `(X, Y)` substitution.

**Why:** Falcon's CFG often has the shape:

```
parent block: sets flags, ends with succs [(ZF==0, A), (ZF==1, B)]
A is a synth junction with no instructions; its own succs
  re-dispatch on ZF for downstream blocks
```

Without cross-block propagation, the synth-junction's succs
keep their raw ZF read after pass 3.

**Limits:** one-shot BFS; doesn't handle re-defs of the
operands between parent and synth. Good enough for the
patterns Falcon actually emits.

## 5. pass_collapse_synth_blocks

**Input:** A block with `addr == None` and an empty
`stmts` list, just a `succs` vector dispatching on a
condition.

**Output:** The synth block is deleted. Every edge that
pointed to it is rewritten to dispatch directly to the
synth's onward targets. When the parent's condition and
the synth's condition are structurally identical, we pick
the matching arm and drop the redundant one; otherwise
we compose with `AND`.

**Why:** Falcon's synth junctions exist for analysis (they
make the graph regular) but they're noise for human
reading. The printer wants direct edges between
instruction-bearing blocks.

## 6. pass_simplify_conditions

**Input:** Successor conditions like
`((X == Y) == 0)`, `((X != Y) == 1)`, or nested
`((((X == Y) == 0) == 0)`.

**Output:** Simplified boolean form. `(b == 0)` becomes
the boolean negation of `b`. `(b == 1)` becomes `b`. `(b !=
0)` becomes `b`. Negation flips Eq <-> Ne.

**Why:** After the prior passes the conditions are
correct but tangled. The if/else recognizer later requires
two conditions to be exact inverses (`X == Y` vs `X != Y`);
without simplification the wrappers prevent the match.

## 7. pass_call_recovery

**Input pattern (anywhere in a block):**
```rust
rsp = rsp - 8;            // or Let if first def
core::ptr::write(rsp as *mut u64, <const>);
goto <target>;            // any Stmt::Branch
```

**Output:** The triple is replaced by a single
`Stmt::Call { callee: <target>, ip: <from branch> }`.

The printer renders this as `fn_<target>();` (or the
friendly name from INDEX.md). Direct calls (target is a
`Const`) become a named call; indirect calls (target is
any other expression, like a vtable load) print as
`(/* indirect */ <expr>)();`.

**Why:** x86 `call addr` is a macro for push-retaddr +
jump. Falcon faithfully expands the macro; we collapse it
back so the reader sees "this function calls fn_X" not
"this function pushes a stack frame and jumps to X".

**Limits:** scans whole block, not just last 3 stmts.
Doesn't recognize indirect calls through registers that
were just assigned a constant (e.g., `mov rax, addr; call
rax`); those still appear as raw pushes + branches.

## 8. pass_ret_recovery

**Input pattern (last two stmts of a block, post-fold):**
```rust
rsp = rsp + 8;
goto core::ptr::read(rsp as *const u64);
```

**Output:** Both stmts replaced by `Stmt::Return { ip }`.

**Why:** `ret` decomposes to "load return address from
stack; advance stack pointer; jump to loaded address". After
temp folding, the load gets inlined into the branch.

**Limits:** doesn't handle `ret N` (return + pop N bytes
of args) yet. Doesn't recognize tail-call returns
(`epilogue + branch to other function address` should
become `tailcall_X(); return;`).

## 9. pass_drop_dead_flags

Removes any leftover `let SF = ...` / `let CF = ...` etc.
bindings that pass_flag_recognition didn't touch because
the pattern wasn't fully canonical. Belt-and-suspenders; in
practice rare to fire.

## Printer

Walks the post-passes RustIr:

- Function header: `pub unsafe fn <name>()` where `<name>`
  comes from `INDEX.md` / `key-funcs/` lookup or falls back
  to `fn_<addr>`.
- Per block: `// ---- bb<idx> @ 0x<addr> ----` separator,
  then the statements, then the succ dispatch.
- Succ dispatch with exactly two conditions that are
  structural inverses emits `if X { /* -> bbA */ } else
  { /* -> bbB */ }`. All other shapes emit one
  `if cond { /* -> bbT */ }` line per edge.

## Adding a new pass

1. Define the input pattern as either a Stmt-sequence match
   or a single-Stmt predicate. Put the function near the
   existing ones in
   [`src/main.rs`](../src/main.rs).
2. Document the pattern + transformation here in
   `passes.md` before merging.
3. Add the pass call in `main()` AFTER any pass it depends
   on (e.g., call-recovery must run after temp-folding so
   the call-site triple is consecutive; ret-recovery must
   run after temp-folding so the load-rsp inlines into the
   branch).
4. Re-run `falcon-printer sweep` to check for regressions in lift
   coverage.
5. Regenerate at least one sample artifact and diff against
   the prior version to confirm the pass does what you
   think it does.
