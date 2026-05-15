# Hooking strategy review: making 480 genes drive in-game visuals
> **Authoritative on:** the decision record for how we hook FUN_14009f680 + FUN_1400ab3d0 for gene-effect mods.

> **Status:** APPROVED 2026-05-14 with scope expansion.
> v1 ships both:
> (a) **S2** (post-hook trampoline on `FUN_14009f680` via
>     `retour::GenericDetour`) for visuals,
> (b) **integration layer for CRISPR UI + death-drift + allele
>     eval + swap**, using either D1 (per-function detours
>     via retour) or S6a (heap redirect of `DAT_1403ee4a4`).
>     The D1-vs-S6a sub-decision is OPEN; see §6.
>
> S2 is locked. S1, S3, S4, S5, S6b, S6c rejected outright.
> The integration sub-decision (D1 vs S6a) is now a v1
> blocker, not v2 deferred. See §5 for rejection reasoning,
> §6 for the resulting [`todo.md`](todo.md) deltas.
>
> **Author posture:** the problem is not novel. Function
> hooking in compiled game binaries is a 25-year-old practice.
> Every option below has shipped in production game mods. The
> question is which option fits our specific shape best.
>
> **Scope:** this doc evaluates how to make extended genes
> (slots 240..479) produce in-game visual effects. It does NOT
> cover save-format extension (D4), per-horse genome alloc /
> free (D3), or pop-weight inheritance (D2). Those are
> separate decisions that ride on top of whichever hook
> strategy we pick here.

## Table of contents

- [1. The problem in one paragraph](#1-the-problem-in-one-paragraph)
- [2. Glossary](#2-glossary)
- [3. Candidate strategies](#3-candidate-strategies)
- [4. Comparison table](#4-comparison-table)
- [5. Recommendation](#5-recommendation)
- [6. Plan delta for [`todo.md`](todo.md)](#6-plan-delta-for-todomdtodomd)
- [7. References (real shipped code, not theory)](#7-references-real-shipped-code-not-theory)

---

## 1. The problem in one paragraph

`FUN_14009f680` (14,074 bytes, the gene-effect engine) reads
a horse's diploid alleles, evaluates 233 hardcoded gene
indices, and writes 258 unique slots into a 353-float
`local_buf[353]` populated on the caller's stack. The
function is called from 6 sites across 5 outer functions,
always in the pair pattern
`FUN_14009f680(buf, horse+0x2b8); FUN_1400ab3d0(horse, buf);`.
The consumer reads 61 of those slots and transcribes them
into the persistent horse struct at offsets `+0x124`,
`+0x128`, `+0x130`, etc. Render code downstream reads from
the horse struct. Vanilla `FUN_14009f680` does not know about
gene indices >= 240. We need it to behave as if it did.

The decomp evidence for the above (verified file:line cites)
is in [`VIABILITY.md`](VIABILITY.md) Q-gene-3, Q-render-2,
Q-render-3.

## 2. Glossary

Sloppy terminology causes wrong-shaped arguments. Definitions
used in the rest of this doc:

- **Detour.** Generic term for replacing the first few bytes
  of a target function with a `JMP` to attacker code. The
  thing that's destructive unless paired with a trampoline.
- **Trampoline.** A small executable buffer that holds the
  original (overwritten) bytes plus a `JMP` back to the
  target's body. Lets the attacker call the original
  function from inside their hook.
- **Detour-with-trampoline.** The combination. MS Detours,
  MinHook, `retour`, PolyHook all ship this as their default
  primitive. When this doc says "trampoline hook" without
  qualifier, this is what's meant.
- **Pre-hook / post-hook.** Convention on top of a
  trampoline hook. Pre runs custom code BEFORE the
  trampoline (can mutate args, can skip the original).
  Post runs custom code AFTER the trampoline returns (sees
  the original's result, can mutate it). SourceHook's
  vocabulary; widely adopted.
- **Mid-function hook.** Hooks somewhere other than the
  function's entry. Requires a code cave (separate
  executable page) and careful register preservation
  because we're interrupting a function mid-execution.
- **Callsite patch.** Modify the caller, not the callee.
  Splice extension code between two adjacent function
  calls in a specific outer function. Many sites = many
  patches.
- **Heap redirect.** Replace a static-data address with a
  pointer to attacker-allocated heap. Works when readers
  load the table address via an indirection; doesn't work
  when readers bake the address into the instruction stream
  via RIP-relative LEAs (our case).
- **Inline replacement.** Reimplement the original function
  end-to-end in attacker code and detour every entry to it.
- **Vtable hook.** Replace function pointers in a C++ vtable
  with attacker functions. Not applicable: our target is a C
  function, not a C++ virtual method.

## 3. Candidate strategies

Six strategies considered. For each: what it does, the
strongest shipped precedent, fit to our problem.

### S1. Per-callsite detour (the original D5.1 plan)

Patch each of the 6 outer functions to splice our extension
code between the
`FUN_14009f680(...)` and `FUN_1400ab3d0(...)` calls.
Concretely: byte-pattern scan for the `CALL` to `_14009f680`
inside each outer function, install a 5-byte JMP after the
return-from-`_14009f680`, run our code in a code cave that
mutates `buf`, then JMP forward to the original `CALL` to
`_1400ab3d0`.

Precedent: rarely the chosen strategy when the callees are
identical. Used when sites have different semantics (e.g.
"this call is for the breeding pair check, not render").

### S2. Post-hook trampoline on `FUN_14009f680` itself

Install ONE detour-with-trampoline at the entry of
`FUN_14009f680`. Our handler signature mirrors the original
(`extern "system" fn(buf: *mut f32, ctx: *mut c_void)`). The
handler does:

1. Call the saved trampoline. This runs the entire vanilla
   function, populating `buf` with 258 slot writes.
2. Back-compute the horse pointer: `horse = ctx - 0x2b8`.
3. For each extended gene with a render mapping, evaluate
   the diploid blend against the horse's extended alleles,
   apply the gene's `RenderMode` (add / mul / set) to
   `buf[render.slot]`.
4. Return. The caller proceeds to `FUN_1400ab3d0(horse, buf)`
   which transcribes the modified buf into the horse struct.

Precedent: this IS the standard pattern. SourceHook calls it
a "post hook." MS Detours calls it `DetourAttach` + call-the
trampoline-yourself. Reloaded-II calls it `IHook<T>` with
`hook.OriginalFunction(...)`. Real Rust game-mod usage:
`rlabrecque/rl-diablo-2-hack`, `zottce/samp-cef` (SAMP),
`openzt1/openzt` (Zoo Tycoon), `vurvdev/Autorun-ng` (Garry's
Mod), `TaimiHUD/TaimiHUD` (Guild Wars 2), all use
`retour::GenericDetour`.

### S3. Pre-hook trampoline on `FUN_14009f680`

Same shape as S2 but the extension runs BEFORE the
trampoline call. Useful if we wanted to inject extended
genes into the vanilla evaluator's input data. We don't.
Vanilla's input is `horse + 0x2b8` (a pointer to the gene
table cursor), not the extended-allele buffer; our extension
runs on the OUTPUT, not the input.

Precedent: SourceHook pre-hooks; common for arg munging.

### S4. Mid-function hook at the tail of `FUN_14009f680`

Find the function's epilogue (a `RET` or the prologue of a
stack-restore sequence), install a JMP to a code cave, run
our extension, restore the stomped bytes, JMP back to the
RET. Equivalent in effect to S2 but reached differently:
S2 wraps the function from outside; S4 reaches in and
splices code at the exit point.

Precedent: `adamhlt/Easy-Mid-Hook` template, Cheat-Engine
auto-assembler "AOBScan + jmp" pattern. Common when you
CAN'T detour the entry (e.g. the prologue is too short to
fit a 5-byte JMP, or the function is virtual / vtable-only).

### S5. Inline replacement of `FUN_14009f680`

Reimplement the whole 14kB function in attacker code. Detour
the entry to JMP unconditionally to our reimplementation.
Never call the vanilla function again.

Precedent: rare. Only chosen for small functions (sub-100
bytes) or when behavior needs to differ in a way the
trampoline approach can't express. SKSE never replaces the
form loader; ENB never replaces the renderer; both wrap.

### S6. Heap redirect of `DAT_1403ee4a4`

Allocate a 480-slot extended gene table on the heap.
Arrange for every reader of `DAT_1403ee4a4` to dereference
through our heap pointer instead of the baked static
address.

Precedent: works beautifully when the original code loads
the table address indirectly: e.g. `g_GeneTable = LoadGenes();`
followed by call sites doing `mov reg, [g_GeneTable]; mov reg, [reg + idx*32]`.
In that shape we patch ONE location (`g_GeneTable`) and all
readers follow. The classic example is SKSE patching
`FormHeap` allocator pointers; the Skyrim engine reads the
allocator pointer from a global, so SKSE swaps the global
once and every allocation site picks up the new heap.

Three concrete sub-variants for our binary; honest
evaluation of each:

**S6a. Patch each LEA site.** Seven readers of
`DAT_1403ee4a4` use the pattern
`lea reg, [DAT_1403ee4a4]; mov reg, [reg + idx*32]` (7-byte
RIP-relative LEA). To redirect, each LEA must be rewritten
to load the table base from a global pointer:
`mov reg, [g_ExtTable]` (7 bytes RIP-relative load).
Same instruction length, RIP-relative displacement
adjusted to point at our pointer variable. **This is
feasible**: 7 same-size byte patches, one heap buffer,
one global pointer slot. Industry term:
"data-indirection retrofit." Used in Unreal IL2CPP mods
to redirect static method tables.

**S6b. JMP-out at each LEA site.** Replace each LEA with
a 5-byte `JMP rel32` to a code cave that loads our
pointer, does the indexed load, and JMPs back. Seven
patches, seven code caves. More complex than S6a, no
benefit. Skip.

**S6c. VirtualProtect + page-fault redirect.** Mark the
page containing `DAT_1403ee4a4` as no-access, install an
SEH / VEH handler that emulates the read against our
heap buffer. Microsoft's PageHeap and some anti-cheats
use this shape. **Catastrophic perf** for a hot path
(per-horse-per-frame gene reads = thousands of page
faults per second). Skip.

**S6a is the real candidate. Honest evaluation:**

The hard question is not "can we patch the readers"
(S6a says yes). The hard question is **does redirecting
the table actually deliver in-game visual effects for
extended genes?**

Answer: **no, not on its own.** The gene-effect engine
`FUN_14009f680` has 233 hardcoded gene indices baked in
as literal constants. Those literals are all in
`[0..239]`. The function never references index 240 or
above because the source code never did. Pointing the
table at a 480-slot heap buffer doesn't cause vanilla
code to evaluate slots 240..479; vanilla code doesn't
know they exist. We'd still need S2-equivalent work to
make the engine actually consume the extended slots.

So S6a's role is "storage layer for the extended gene
table," not "visuals delivery." It substitutes for our
existing `EXT_GENE_TABLE` sidecar (shipped in D0). The
sidecar already serves that role without patching
anything in the binary; if a senior reviewer wants the
extended gene table to live at the "natural" address
range adjacent to `DAT_1403ee4a4`, S6a is the way, but
the practical win is cosmetic. The two writers that
matter live INSIDE our DLL (`genes-extended.xml` loader
and live HTTP-op edits); they target the sidecar
directly with no game-binary interaction.

Where S6a WOULD pay for itself: if we later want the
vanilla CRISPR UI (`FUN_1400c1cf0`) or vanilla death-drift
mutator (`FUN_1400c0660`) to see and operate on extended
genes WITHOUT us detouring those functions individually,
S6a lets us avoid each of those detours. That's a v2
question (extended-gene CRISPR UI is not v1 scope).

**Verdict:** technically viable as a storage substrate,
strictly inferior to the sidecar for v1, plausibly
useful as a v2 simplification if extended-gene CRISPR /
mutation-drift becomes scope. Not a substitute for S2.

### Strategies considered and rejected without their own subsection

- **Bethesda ESL-style high-bit repurposing.** Their trick:
  reuse `0xFE` of a 32-bit form ID as a "this is a light
  master" sentinel, then encode load order in bits below.
  Doesn't apply: our gene indices aren't reused IDs, they
  are array offsets in `[0..240)`. Mod is purely additive
  (slots 240..479), there's no high bit to steal.
- **Vtable hook.** Target is a free function, not a virtual
  method.
- **Hooking the renderer directly.** Defeats the layered
  design principle (vanilla still does most of the work).
- **IAT / EAT hook.** Targets imported functions only;
  `FUN_14009f680` is internal.
- **Hardware breakpoints (DRn).** Limited to 4 sites,
  triggers debug exception every call. Catastrophic perf
  cost for a hot function called per-horse-per-frame.
- **Cheat-Engine .CT auto-assembler.** A delivery mechanism,
  not a different strategy. Underneath it's still S1-S4.

## 4. Comparison table

Scoring legend: + = good, - = bad, ~ = neutral / depends.

| Criterion | S1 callsite | S2 post-hook trampoline | S3 pre-hook | S4 mid-fn tail | S5 inline replace | S6a heap redirect |
|---|---|---|---|---|---|---|
| Solves the "extended slots produce visuals" problem on its own | yes | **yes** | yes | yes | yes | **no** (storage only) |
| Patch sites | 6 | **1** | **1** | 1 | 1 | 7 |
| Vanilla code path stays valid | + | + | + | + | - | + |
| Survives compiler-driven callsite reordering | - | + | + | + | + | + |
| Survives game-binary patches (version drift) | - (6 signatures) | + (1 signature) | + | ~ (1 signature, harder) | + (1 entry) | - (7 signatures) |
| Requires byte-pattern scan | yes, x6 | no (function entry) | no | yes (epilogue) | no | yes, x7 |
| Needs code cave | yes | no (handler is in our DLL) | no | yes | no | no (same-size patch) |
| Library support | none, hand-rolled | retour, MinHook, Detours | retour, MinHook | none, hand-rolled | none | none |
| Implementation LOC est. | ~600 | **~200** | ~200 | ~400 | ~3000+ | ~400 + still needs S2 for visuals |
| Reverts cleanly on detach | per-site, fragile | trivial (one site) | trivial | trivial-ish | trivial | per-site, OK |
| Risk: register / ABI mistake | high (raw asm) | **low** (Rust extern "system") | low | medium (mid-fn registers live) | low | low (same-size LEA-> MOV swap) |
| Risk: subtle behavior divergence | low | **low** (vanilla unchanged) | medium (args munged) | low | **high** (we wrote 14kB) | low |
| Risk: hot-loop perf overhead | low | low (one indirect call) | low | low | varies | low (extra indirection per read) |
| Thread-safety burden on us | per-site review | one site to audit | one | one | full reimpl | one (global pointer is atomic) |
| Hot-reload friendly | painful (6 sites) | **trivial** | trivial | trivial | trivial | OK |
| Industry shipped precedent in Rust | rare | **abundant** | abundant | uncommon | rare | rare for this shape; common where indirection already exists |
| Enables vanilla CRISPR / death-drift to see extended genes for free | no | no | no | no | no | **yes** (the only entry with this property) |

## 5. Recommendation

**Adopt S2: post-hook trampoline on `FUN_14009f680` using
`retour::GenericDetour`.** Consider adding S6a (heap
redirect) in v2 if extended-gene CRISPR / mutation-drift
becomes scope.

The score table on the "delivers visuals" row eliminates S6a
alone (it's a storage layer, not a visuals layer). Among the
remaining five, S2 wins on every other criterion except
"ties with S3/S4" on a few. The tiebreakers vs S3 and
S4:

- vs S3 (pre-hook): our extension needs the output buf, not
  the input. A post-hook gets us that for free; a pre-hook
  would need to call the trampoline then return to the
  caller, which is just S2 with extra steps.
- vs S4 (mid-fn tail): requires a byte-pattern scan for the
  epilogue plus careful register save/restore at a
  mid-function point. S2 hooks the entry where the ABI is
  well-defined. Same outcome, less risk.

S2 also leaves the door open: if a future use case needs
pre-hook semantics (e.g. forcing a specific horse's evaluation
to use a "preview" gene table for the live editor), we can
stack a pre-hook on the same detour without restructuring.

### Library choice: `retour` (Rust port of MS Detours)

- Actively maintained ([crates.io/crates/retour](https://crates.io/crates/retour)).
- Handles the gnarly bits we'd otherwise hand-roll: RIP-relative
  rewrites in the stolen prologue, NOP-padded prologues,
  >2GB JMP relays, hot-patch detection.
- Used in shipped Rust game mods across multiple engines:
  Diablo II, SAMP, Zoo Tycoon (custom thiscall ABI), Garry's
  Mod, Guild Wars 2, Godot CEF, Steam VR overlays.
- The alternative `minhook-sys` is a thinner FFI binding;
  fine if we'd rather link MinHook's audited C code than
  trust the Rust port. Default to retour for type-safety
  on the function-pointer signatures.

### Open risks if we adopt S2

1. **Threading.** The 6 callers may run on different
   threads (render / audio / AI / breeding logic). Our
   handler reads `EXT_HORSE_GENOMES` under a `RwLock`. If a
   hot caller contends on the lock, swap to `arc-swap`
   snapshots or a per-horse `DashMap`. Resolve by
   profiling in D8.5; budget 1d of work to swap the data
   structure if needed.
2. **Horse-pointer-as-key vs stable horse-id.** D4.4 is
   still open (we don't know the int32 horse-id field).
   S2 lets us key the per-horse extended genome by the
   horse POINTER (`ctx - 0x2b8`) during a session; this
   is fine for runtime evaluation but doesn't survive
   save / load. Save-format compat (D4) needs the
   stable id; runtime evaluation does not. We can ship
   S2 without resolving D4.4 first.
3. **Trampoline allocation near a low-2GB target.** Retour
   handles >2GB targets via its "relay" mechanism. Horsey's
   image base is in the high 64-bit address space, so the
   relay path will fire. Audited; not a blocker.
4. **Re-entrancy.** If our handler itself causes vanilla
   code to recursively call `FUN_14009f680` (e.g. a UI tick
   reads a horse), the trampoline must be re-entrant. MS
   Detours and retour both produce re-entrant trampolines
   by design (stateless instruction copies). Audit our
   handler does NOT take a re-entrant `RwLock` write lock
   under itself. Easy to enforce.

## 6. Plan delta for [`todo.md`](todo.md)

Applied 2026-05-14. Reflected in [`todo.md`](todo.md) D5.

### 6.1 D5 (visuals via S2): LOCKED

- Replace D5.1 ("install detours at 6 caller sites") with
  D5.1' ("install one `retour::GenericDetour` on
  `FUN_14009f680`").
- Drop the original D5.4 (post-consumer hook) from v1 scope.
  Most new visual effects can be expressed via existing
  consumer-read slots (61 of them, vs ~10 genes' worth of
  effects in v1). Revisit if v1 hits an effect the
  consumer doesn't read.
- D4.4 (stable horse_id) deferred until D4 save work; not
  blocking D5.
- Add `retour = "0.3"` to `horsey-mod/Cargo.toml`.
- Scaffold `horsey-mod/src/patches/render_trampoline.rs`
  with the same arm / revert / dryrun shape as
  `patches/ext_genes.rs`. Expose
  `genes.ext.render.dryrun` and `genes.ext.render.arm`
  HTTP ops.

### 6.2 D1 (integration): PROMOTED INTO v1, sub-strategy OPEN

User direction 2026-05-14: CRISPR UI and "all the normal
integration" (death-drift, allele eval, allele swap)
ship in v1, not v2. This means vanilla functions other
than `FUN_14009f680` must see extended genes too. Two
candidate strategies, both technically viable; pick
before D1 work starts.

#### Strategy DI-A: per-function detours (the original D1 plan)

Five `retour::GenericDetour` installs on the gene-table
reader / mutator functions:

| Target | Role | Detour behavior for index >= 240 |
|---|---|---|
| `FUN_1400a5d20` | Allele evaluator (formula 1) | Mirror formula against `EXT_GENE_TABLE` |
| `FUN_1400a5e00` | Allele evaluator (formula 2) | Mirror formula against `EXT_GENE_TABLE` |
| `FUN_1400c0660` | Death-handler ±5 mutator | Mutate `EXT_GENE_TABLE` |
| `FUN_1400c03a0` | Allele renumber sync | Sync swap in `EXT_GENE_TABLE` + extended pop weights |
| `FUN_1400c1cf0` | CRISPR UI | Display extended gene names / values |

Plus sidecar loaders for the 3 table-walking loops
(`FUN_1400a3eb0:156`, `:984`, `FUN_1400a4880:298`) which
stay at vanilla bound 0xf0; we run our own init /
loader / serializer for `EXT_GENE_TABLE`.

Pros: same library / pattern as S2, in-DLL dispatch logic
in Rust (typesafe), per-function instrumentation easy
(counters, debug hooks, selective disable for triage).

Cons: 5 entry-point signatures to maintain across game
updates, 5 separate detour-revert paths, each detour
adds an indirect call on a hot path.

#### Strategy DI-B: heap redirect (S6a from §3)

One conceptual change: place a 480-slot heap buffer at a
RIP-relative-reachable address (VirtualAlloc near image
base), then patch the 4-byte displacements of the 7
reader LEAs to point at the heap. Also patch the 3
loop-bound immediates (`0xf0` -> `0x1e0`) so vanilla
init / load / serialize loops iterate the full 480.

Pros: vanilla functions just work for 240..479 with zero
per-function dispatch. CRISPR UI iterates the table to
display names; now iterates 480 slots. Death-drift
writes through the normal path; now hits our extended
slots when its index is in range. Same-size byte patches,
mechanical to apply and revert. **No new hot-path
indirect calls.**

Cons: 7+3 = 10 byte-patch sites instead of 5 detours.
RIP-relative-reachable address requires VirtualAlloc
proximity gymnastics (not insurmountable; retour does
this already). Save format compat still needs sidecar
(unchanged from D4 plan). The 3 loop-bound bumps are
non-trivial: anything walking 0..240 expecting that
range now walks 0..480; if any of those loops have
side effects we missed in the decomp pass, we crash.
Audit risk concentrated in those 3 loops.

#### DI-A vs DI-B scoring

| Criterion | DI-A detours | DI-B heap redirect |
|---|---|---|
| Patch sites | 5 detours | 10 byte patches |
| Hot-path indirect call overhead | 5x indirect calls | 0 (just RIP+disp32) |
| Library leverage | retour, audited | hand-rolled byte patches |
| Same pattern as S2 (locked) | **yes** | no (mixed model) |
| Vanilla loop walks (table init / load / serialize) | run unmodified, we re-do in Rust | walk to 480, depend on loop body being safe at extended indices |
| Risk concentration | distributed across 5 detours | concentrated in 3 loop bumps + heap proximity |
| Reverts on detach | retour handles | we hand-roll byte restore (already have `patch_bytes`) |
| Save / load compat with v1 saves | sidecar (unchanged) | sidecar (unchanged) |
| Adds new behavior implementations in Rust | yes (5 mirror funcs) | no (vanilla does the work) |
| Affects unmodded performance when extended gene count is 0 | 5 indirect calls per evaluation | 0 (just reads zeros) |
| Failure mode if a loop body has unexpected side effects | falls through to vanilla (safe) | crash inside vanilla loop (unsafe) |

**Recommendation (subject to senior-eng signoff):
DI-A.** Rationale:

1. Pattern uniformity with the already-approved S2.
   Same library (retour), same install / revert
   primitive, same address-resolution discipline. The
   senior-eng team has already reviewed the S2 hook
   shape; DI-A is "do that 5 more times." DI-B
   introduces a second mechanism with its own failure
   modes.
2. Failure mode for DI-A is safe-by-default: a detour
   that fails to install means vanilla runs unmodified
   for that function (extended genes don't get
   CRISPR / death-drift integration, but the game
   doesn't crash). DI-B's failure mode is "vanilla
   loop walks into uncharted memory or writes garbage
   into the loop body's downstream state."
3. The 5-indirect-call cost of DI-A only matters if
   one of these functions is on the per-frame hot
   path. CRISPR UI is not (called on user click).
   Death-drift is not (called on horse death, rare).
   Allele eval IS hot. Called per render frame per
   horse. Profile-driven: if `FUN_1400a5d20` /
   `FUN_1400a5e00` cost shows up in D8.5 benchmarks,
   convert THOSE TWO to DI-B-style heap reads (the
   other 3 stay as detours). Hybrid is fine.
4. The 3 loop-bound bumps in DI-B are the genuinely
   scary part. We'd need a fresh decomp audit of every
   instruction in each loop body to confirm "0..240" is
   the only place that range appears. With DI-A we
   leave those loops alone and never have to answer
   that question.

The open follow-up before D1 starts: confirm by quick
disassembly pass that `FUN_1400a5d20` / `FUN_1400a5e00`
prologues fit a 5-byte JMP (retour handles longer needs
via relays, but cheaper if the prologue is already a
push-rbp / sub-rsp pair).

### 6.3 Lessons from first DI-A bring-up

First in-game arming exposed a class of failure that doesn't
show up in any unit test: `retour::GenericDetour::new()` will
HAPPILY install a detour at any disassemblable address, even
mid-function. ALLELE_SWAP at RVA 0x1400c03a0 in the May 2026
build started with `63 fa 48 be c1 d4 1c 42 29 8f a0 3f`. A
`movsxd; movabs rsi, <double bits>` pair, clearly inside a FP
routine, not a function entry. Arming succeeded; the game
crashed seconds later when a game thread fell through the
mangled basic block.

The mitigation is in [`DEBUGGING.md`](DEBUGGING.md) §5: every
new detour PR must verify the prologue matches a Win64
function-entry pattern before arming. ALLELE_SWAP install is
disabled in `ext_genes::arm` until the real entry address is
located.

## 7. References (real shipped code, not theory)

- [retour crate](https://crates.io/crates/retour). Chosen library
- Real-world Rust game-mod usage of retour:
  - [rlabrecque/rl-diablo-2-hack](https://github.com/rlabrecque/rl-diablo-2-hack)
  - [zottce/samp-cef](https://github.com/zottce/samp-cef)
  - [openzt1/openzt](https://github.com/openzt1/openzt)
  - [vurvdev/Autorun-ng](https://github.com/vurvdev/Autorun-ng)
  - [TaimiHUD/TaimiHUD](https://github.com/TaimiHUD/TaimiHUD)
  - [dsh0416/godot-cef](https://github.com/dsh0416/godot-cef)
- Pattern docs:
  - [Kyle Halladay, X64 Function Hooking by Example](https://kylehalladay.com/blog/2020/11/13/Hooking-By-Example.html)
  - [Microsoft Detours wiki](https://github.com/microsoft/detours/wiki)
  - [AlliedModders SourceHook (pre/post)](https://wiki.alliedmods.net/Sourcehook_Development)
  - [Reloaded-II calling/hooking guide](https://reloaded-project.github.io/Reloaded-II/CheatSheet/CallingHookingGameFunctions/)
  - [adamhlt/Easy-Mid-Hook (the mid-fn alternative)](https://github.com/adamhlt/Easy-Mid-Hook)
- Pattern we explicitly are NOT using (different problem
  shape, here for reviewer context):
  - [Bethesda ESL form-ID encoding](https://en.uesp.net/wiki/Skyrim:Form_ID)

## 8. Implementation status (locked 2026-05-15)

Every detour discussed above is either shipped, deferred with a reason, or address-broken.

### D5 (visuals via S2): SHIPPED

Module `horsey-mod/src/patches/render_trampoline.rs`. Post-hook on `FUN_14009f680` via `retour::GenericDetour<unsafe extern "system" fn(*mut f32, *mut c_void)>`. Runs vanilla, then calls `genes::apply_render_to_buf(buf, 353, horse_id)` which walks `EXT_GENE_TABLE`, evaluates each ext gene's blend, and writes to the buf slot per the `<render slot mode>` mapping in `genes-extended.xml`.

HTTP ops: `genes.ext.render.{dryrun, arm, disarm, stats}`. Counters: `call_count` + `genes_applied_total`. The shipped `tests/dryrun_d1_d5` + `tests/arm_render_trampoline` cover dryrun + arm; full proof against the live build is in [`TESTING.md`](TESTING.md).

In-game verification 2026-05-14: an authored `BX_TEST_SLOT0` ext gene with default alleles (3, 3) → blend value 200.0 → slot 0 set mode → rendered "full screen width" babies after breeding. **Visuals data path works.** The specific slot-to-feature map for the other 22 direct-copy slots is empirically derived from per-bestiary work in [`GENE-CATALOG.md`](GENE-CATALOG.md).

### D1 (DI-A per-function detours): 3 of 5 SHIPPED, 2 DEFERRED

Module `horsey-mod/src/patches/ext_genes.rs`. Per-target dispatch: `gene_idx < 240` → vanilla trampoline; `gene_idx >= 240` → sidecar path (read `EXT_GENE_TABLE` / write `EXT_HORSE_GENOMES`).

| Detour | RVA | Status | Notes |
|---|---|---|---|
| `EVAL_DIPLOID_BLEND_A` (`FUN_1400a5d20`) | `0x1400a5d10` (Ghidra -16) | SHIPPED | Returns blended `f32`; dispatch by `param_2` (gene_idx). |
| `EVAL_DIPLOID_BLEND_B` (`FUN_1400a5e00`) | `0x1400a5df0` (Ghidra -16) | SHIPPED | Returns `u32` bit-pattern; dispatch via `.to_bits()` on the ext result. |
| `GENE_ALLELE_SWAP` (`FUN_1400c03a0`) | `0x1400c0390` (Ghidra -16) | SHIPPED | When `gene_idx >= 240`, swaps via `genes::swap_ext_alleles` across `EXT_GENE_TABLE` + every `EXT_POP_WEIGHTS` entry. Skips vanilla entirely for ext indices (vanilla would walk `DAT_1403ee4b0` out-of-range and crash). |
| `GENE_DEATH_DRIFT` (`FUN_1400c0660`) | `0x1400c0650` (Ghidra -16) | DEFERRED | Mutator runs mid-function (gene_idx is a local, not a param). Needs a mid-function patch via `patch_bytes`, not an entry-point detour. Reopen with a worked example. |
| `CRISPR_LAB_UI` (`FUN_1400c1cf0`) | TBD | DEFERRED | State-machine function (5311 bytes); need to map which states read which gene-indexed data before splicing. Not blocking v1. |

Loop-bound patches `D1.5/6/7` (vanilla 0xf0 loops in `FUN_1400a3eb0` and `FUN_1400a4880`) are **NOT needed**: we use sidecar XML loaders / serializers for the ext range so the vanilla loops can stay at 240.

Full pipeline verified in-game 2026-05-14: vanilla path through `EVAL_A` saw `max_idx_seen=239` (full 0..240 range); ext path stays at 0 until an ext gene fires; `genes_applied_total` matches `call_count` 1:1 in the D5 post-hook.

Handler discipline + the 5 distinct "all-ones bad_addr" crash modes that bracketed bring-up are documented in [`DEBUGGING.md`](DEBUGGING.md) §4b, §5.

### D3.1 / D3.2 (lifecycle anchors): SHIPPED

Module `horsey-mod/src/patches/lifecycle.rs`. Post-hook on horse constructor `FUN_1400aac60` (true entry `0x1400aac50`, Ghidra -16) initializes `EXT_HORSE_GENOMES[ret_ptr]` via `genes::ensure_horse_ext_genome`. Pre-hook on horse destructor `FUN_1400bf1f0` (true entry `0x1400bf1e0`) drops the entry. Counters: `ctor_calls`, `dtor_calls`, `entries_created`, `entries_dropped`.

Verified 2026-05-15: `tests/arm_lifecycle` captured 550 ctor + 3 dtor calls in 5s of menu idle. Strict `ctor_calls == entries_created` invariant holds when armed before any horse construct; the relaxed `entries_created <= ctor_calls` invariant holds when armed mid-session (dtor fires for pre-arm horses with no entry).

Horse struct is 0x498 bytes; constructor + destructor + the genome layout discovery (working genome inline at `horse + 0x2b8`, not at the heap pointer at `+0x78`) are documented in [`SAVE-FORMAT.md`](SAVE-FORMAT.md) "Save pipeline functions" + [`GENE-CATALOG.md`](GENE-CATALOG.md) Layer 3.

### D3.4 (breeding combinator): SHIPPED

Module `horsey-mod/src/patches/combinator.rs`. Post-hook on `FUN_1400a2d80` (true entry `0x1400a2d70`, Ghidra -16). Recovers horse base pointers as `param - 0x2b8`, then calls `genes::combine_for_breeding(pa_id, pb_id, child_id)` which runs SplitMix64-seeded Mendelian over `EXT_HORSE_GENOMES`. 6 unit tests in `genes::tests` lock the algorithm contract (parent-strand picking, allele masking, RNG nonce divergence).

Vanilla combinator algorithm + the linked-inheritance cluster ranges (Neck, Head/Face/Hat, palette) are documented in [`GENE-CATALOG.md`](GENE-CATALOG.md) Part 1 Step 1.

### D4 (save sidecar): code SHIPPED, addresses STALE

Implementation lives in `horsey-mod/src/patches/save_sidecar.rs`; the BXSAVEXT codec is unit-tested in `patches::save_sidecar::tests`. The four detour target RVAs (`SAVE_WRITER`, `LOAD_GAME`, `HORSE_SAVE_WRITER`, `HORSE_SAVE_LOADER`) are mid-function in the current shipping build; `genes.ext.save.arm` is UNSAFE to arm until they're re-derived via pattern-scan. Full details in [`SAVE-FORMAT.md`](SAVE-FORMAT.md) "Sidecar format".

## 9. Full implementation log (D1 / D3 / D5)

Detailed sub-task records preserved from the original implementation plan. Use §8 above for the quick status summary; this section is the authoritative log of WHAT got built, the alternatives that were rejected, and the operational rules in force.

### Phase D1: Static gene table extension

**STATUS: FULL PIPELINE PROVEN IN-GAME 2026-05-14.** All four
detours co-arm cleanly; an authored extended gene
(`BX_TEST_SLOT0` in `genes-extended.xml`) with a render
mapping + a default-allele setting writes the computed value
into the per-horse render buf on EVERY horse render. Visible
effect not yet confirmed because the slot-to-feature map is
unknown (see "Open follow-up" below).

Latest in-game numbers (player walked ~10s after arming with
`BX_TEST_SLOT0` authored at ext_idx 0, slot 0 set mode, default
alleles (3,3) = blend value 200.0):

| Target | Calls | Vanilla path | Ext path | Max idx seen |
|---|---|---|---|---|
| EVAL_DIPLOID_BLEND_A | 2233 | 2233 | 0 | 218 |
| EVAL_DIPLOID_BLEND_B | 2012 | 2012 | 0 | 213 |
| GENE_ALLELE_SWAP | 0 | 0 | 0 | n/a |
| APPLY_GENE_TO_HORSE (D5 post-hook) | 16 | 16 | n/a | n/a |
| Extended gene applications via D5 | n/a | n/a | 16 | n/a |

`max_idx_seen=239` across A+B confirms the full vanilla
[0..240) range is evaluated through our handler.
`genes_applied_total=16` matches `D5.call_count=16` exactly:
every horse render had our gene's blend value applied to its
target slot. **The visuals data path works.**
`ext_call_count=0` on the DI-A side is expected: no vanilla
caller drives idx>=240 in this scenario (the D5 trampoline
writes the buf directly without recursing through eval_a/b).
`allele_swap=0` is expected. It only fires on the rare
allele-renumber event.

#### Confirmed: slot 0 has a major visible effect

Test: `BX_TEST_SLOT0` -> slot 0 set 200.0, default alleles (3,3),
mated two horses, the resulting babies rendered "full screen
width." Slot 0 is **consumer-read** and drives some primary
scale-like parameter. Exact feature TBD; the visible result was
dramatic enough that we cleared the default alleles before
further iteration.

This proves the visuals pipeline writes effects the renderer
honors. It does NOT prove "slot 0 = body width" specifically;
without the slot-to-feature map below we can't assert that.

#### Next phase: systematic vanilla-gene research

Don't guess at slots; map them. From VIABILITY.md Q-render-3:

- 353 total float slots in the render buf
- 258 written by vanilla `FUN_14009f680` (the engine)
- 61 read by vanilla `FUN_1400ab3d0` (the consumer that
  transcribes into the horse struct at `+0x124`, `+0x128`,
  `+0x130`..`+0x154`)
- Only the 61 consumer-read slots produce visible effects

Research plan to derive the map:

1. [x] **DONE.** Vanilla `genes.xml` dumped to
   [`vanilla-genes.xml`](vanilla-genes.xml). 240 names
   indexed in document order matching the engine's
   gene_idx 0..239.
2. [x] **DONE.** Per-gene flow analysis on
   `FUN_14009f680` shipped via
   `research/build-gene-catalog.py`. Auto-derives
   `slots_written`, `slots_gated`, and `calls` for all
   240 genes. Output: [`GENE-CATALOG.md`](GENE-CATALOG.md)
   per-gene table.
3. [x] **DONE.** Consumer-map extractor
   `research/extract-consumer-map.py` enumerates 62
   `param_2[X]` reads in `FUN_1400ab3d0`. 23 are direct
   copies to horse-struct fields `+0x58..+0xa4`,
   `+0x200`, `+0x254`, `+0x2a8`. 38 feed conditionals /
   intermediate math. Output: GENE-CATALOG.md Part 2
   "Buf-slot -> horse-struct field" table.
4. [x] **DONE.** Cluster map authored in GENE-CATALOG.md
   Part 2 (gene_idx range -> feature area). Slots 0..3
   SQRT formula reverse-engineered from
   `FUN_14009f680:94066-94143`. The per-slot
   `{gene -> slot -> struct field}` chain is derivable
   by intersecting the per-gene table (step 2) with the
   consumer map (step 3).
5. [x] **DONE.** GENE-CATALOG.md Part 2 ships with
   cluster map + consumer map + engine internals
   (slots 0..3 formula) + modder workflow. The
   "Confirmed visible-effect slots" section is the
   live-validated subset.
6. [x] **EXTRACTION DONE, CLASSIFICATION OPEN.**
   `research/extract-field-readers.py` shipped. Greps
   `all_functions.c` for reads of all 23 direct-copy
   horse-struct offsets (`+0x58`, `+0x5c`, `+0x60`,
   `+0x64`, `+0x68`, `+0x6c`, `+0x70`, `+0x74`, `+0x78`,
   `+0x7c`, `+0x80`, `+0x84`, `+0x88`, `+0x8c`, `+0x90`,
   `+0x94`, `+0x98`, `+0x9c`, `+0xa0`, `+0xa4`, `+0x200`,
   `+0x254`, `+0x2a8`). Raw output: 2339
   function-occurrences, 3468 read sites.
   Horse-handler fingerprint (>= 3 of 23 offsets in one
   body) narrows to **218 likely handlers**. Top
   candidate `FUN_1401beac0` touches 20/23.
   Output: [`FIELD-READERS.md`](FIELD-READERS.md).

   First-pass classification done 2026-05-15. v1
   fingerprint "touches >= 3 offsets" produced 218
   functions, dominated by SDL/Vulkan feature-struct
   noise (`FUN_1401beac0` is the SDL_GPU Vulkan
   `VkPhysicalDeviceFeatures` checker, not a horse
   handler). Refined v2 fingerprint adds "must also
   touch one of `+0x200` / `+0x254` / `+0x2a8`" (rare
   high offsets the consumer writes). v2 narrows to
   **24 candidates**.

   Cross-referenced 24 candidates against
   [`ALL-FUNCTIONS.md`](ALL-FUNCTIONS.md):

   Confirmed horse-handlers (6):
   - `FUN_1400df280` retire_horse_handler (gameplay)
   - `FUN_140089510` copy_genome_to_clipboard (UI)
   - `FUN_14010ba40` debug_print_population_stats
   - `FUN_140094a20` show_race_ready_prompt (UI)
   - `FUN_1400dcab0` show_getting_old_sale_dialog (UI)
   - `FUN_1400e0aa0` show_all_rested_message (UI)

   Noise (10): auto-named `init_struct`,
   `batch_call_*`, `float_helper`, `float_math_main`
   patterns whose sequential field access collides
   with the regex.

   Unclassified (5): `FUN_14003d890`, `FUN_140155130`,
   `FUN_1401ef800`, `FUN_14003c8c0`, `FUN_1400e25b0`.

   **Open gap:** none of the confirmed horse-handlers
   are in the renderer call chain. The regex
   fingerprint isn't catching the renderer because it
   probably reads through a nested pointer
   (`horse->render_state->field`) rather than a direct
   `var + 0xNN` literal.

   **Forward-trace from consumer call sites, done
   2026-05-15:** all 6 known call sites of the
   consumer `FUN_1400ab3d0` (lines 104380, 104441,
   104585, 104614, 113025, 113052 in
   `all_functions.c`) are **regeneration events**, not
   per-frame render calls:
   - `FUN_1400b2e30`: child-from-parents setup (calls
     genome-merge `FUN_1400a2d80` first)
   - `FUN_1400b2ee0`: horse init with pop, sets
     `+0x234` and `+0x1fc=2` after
   - `FUN_1400b3070`: horse regen wrapping CRISPR-
     style flows; iterates entity list at 0xb8 stride
   - `FUN_1400c1xxx` (113025/113052): CRISPR genome
     mutate then regen, sets `+0x1fc=2`

   The consumer's job is to **persistently overwrite
   horse-struct fields whenever gene-derived
   attributes change** (birth, CRISPR, respawn). The
   renderer reads those fields independently, per
   frame, decoupled. Forward-tracing the consumer's
   callers leads to event triggers, not the renderer.

   **Implication: don't chase the renderer
   statically.** Finding it cleanly needs Ghidra
   struct propagation across the horse type, hours of
   skilled RE work for diminishing returns. The slot
   map we have is good enough to ship with:
   gene -> slot (per-gene table) + slot -> horse
   struct offset (consumer map) + working trampoline
   that puts arbitrary values into those slots + one
   empirically confirmed slot (slot 0).
   Per-feature classification of the remaining 22
   direct-copy slots can be populated as a side
   effect of bestiary authoring (each new species
   naturally probes a few slots). Trying to enumerate
   it ahead of demand is speculative work.

   Output: [`FIELD-READERS.md`](FIELD-READERS.md)
   with classified table + consumer call-site
   regeneration finding.

Output: a reliable map from "I want feature X" to "extend
gene G with render slot S, allele payload P0..P3, value
range R." That unblocks the bestiary authoring work in
Phase 2.

Caveat on existing horses: ext alleles are stored
per-horse-pointer with a default fallback. The "giant baby"
horses from the slot-0 test now have alleles 0,0 (cleared
default) but their LIVE render-struct fields will keep the
old computed value until the next gene-evaluation pass for
that horse. Save / reload reliably re-triggers eval.

Strategy DI-A approved 2026-05-14. Locked library:
`retour 0.3`. Lock-free `AtomicPtr<GenericDetour<T>>`
storage published at arm time; handlers do atomics +
acquire-load + indirect call only (no `format!`, no
`parking_lot`, no Rust TLS).

#### Lessons captured (all in DEBUGGING.md)

- **5 distinct "all-ones bad_addr" crash modes:**
  (a) double-deref of a non-pointer slot (`gamestate::ptr`
      was reading the gamestate struct's first 8 bytes as
      a pointer); (b) handler stack frame too big for
      game's nested call chain; (c) parking_lot Mutex
      accessing Rust TLS on a foreign game thread;
      (d) detour target was not a function entry;
      (e) Ghidra's pyghidra indexes function entries
      OFF-BY-16 (the real entry is at `ghidra_addr - 16`,
      where the MSVC register-save prologue lives).
- **Handler discipline rules** in
  [`DEBUGGING.md`](DEBUGGING.md) §4b. Every new handler
  must observe them. Reference impl: `eval_a_handler`.
- **Pre-arm prologue verification rule** in
  [`DEBUGGING.md`](DEBUGGING.md) §5: every new detour
  must have its prologue eyeballed against Win64
  function-entry patterns before arming. The two
  recognized shapes are documented.
- **Ghidra-off-by-16 was the dominant blocker.** It made
  EVAL_A/B appear to work and APPLY_GENE_TO_HORSE /
  ALLELE_SWAP crash, looking like a build-update issue
  for hours. The actual decomp pass against the current
  binary returned identical addresses; we just trusted
  Ghidra's entry-point attribution too much.

#### Immediate plan (next session)

1. Author one test extended gene in `genes-extended.xml`
   with a `<render slot="..." mode="add"/>` mapping;
   set a horse's extended alleles via HTTP
   (`horse.ext.alleles.set`); observe `genes_applied_total`
   climb on `genes.ext.render.stats`; verify the visible
   render effect in-game. **This is the v1 finish line.**
2. Implement Phase R1 from
   [`ADDRESS-RESOLUTION.md`](ADDRESS-RESOLUTION.md): image
   SHA-256 logging + `game.build_info` op, so future game
   updates show up loudly in the log.
3. Implement Phase R2 (patternsleuth runtime resolution)
   so future address drift gets resolved automatically
   without needing manual address bumps.
4. D1.3 (`GENE_DEATH_DRIFT`) and D1.8 (`CRISPR_LAB`) remain
   deferred: D1.3 needs a mid-function patch, D1.8 needs
   state-machine analysis. Not blocking v1.

Wired and arming via `genes.ext.arm` HTTP op:

- [x] **D1.1.** `EVAL_DIPLOID_BLEND_A` (FUN_1400a5d20).
      Signature: `unsafe extern "system" fn(*const u8, i32) -> f32`.
      Handler: idx<240 -> trampoline; idx>=240 ->
      `genes::evaluate_ext_gene(genome_ptr as u64, idx-240)`.
- [x] **D1.2.** `EVAL_DIPLOID_BLEND_B` (FUN_1400a5e00).
      Signature: returns `u32` (bit pattern is f32). Same
      dispatch as D1.1 but `.to_bits()` on the extended
      result so the caller's bit-cast still works.
- [x] **D1.4.** `GENE_ALLELE_SWAP` (FUN_1400c03a0).
      Signature: `(usize, i32, i32, i32) -> void`. Handler:
      idx<240 -> trampoline; idx>=240 ->
      `genes::swap_ext_alleles(idx-240, a, b)` which swaps
      the payload positions in `EXT_GENE_TABLE` AND every
      `EXT_POP_WEIGHTS` entry. Skips vanilla entirely for
      extended indices (vanilla would walk DAT_1403ee4b0
      with an out-of-range index and crash).

Deferred (not entry-point clean):

- [ ] **D1.3.** `GENE_DEATH_DRIFT` (FUN_1400c0660). The
      gene index is computed mid-function (~line :730 in
      decomp), not passed as a parameter. Needs a
      mid-function patch via `patch_bytes`, not an
      entry-point detour. Defer until we have a worked
      example of the +/-5 mutation site address.
- [ ] **D1.8.** `CRISPR_LAB` UI gene dispatch
      (FUN_1400c1cf0). Internal state machine, 5311 bytes.
      Need to map which states read which gene-indexed
      data before we know where to splice. Could be
      multiple sub-detours or a single mid-function patch.
      Defer until DI-A-3 ships and we have in-game UX
      validation of the existing 3 detours.

If profiling shows the per-call overhead of D1.1/D1.2
matters (they're hot, called per-horse-per-frame),
revisit DI-B (heap redirect) as a perf optimization for
THOSE TWO only. Other detours stay as DI-A.

Make the engine's 240-slot gene table behave as if it
has N slots, where slots 0..239 are vanilla
`DAT_1403ee4a4` and slots 240..N-1 live in our heap
buffer.

**Concrete decision: detour-and-dispatch, not heap
redirect.** The 7 readers do `(&DAT_1403ee4a4)[i*8]`
which the compiler turned into `lea reg, [DAT...]; mov reg, [reg + i*32]`.
Patching every reader to dereference through a pointer
variable is invasive (changes instruction sizes).
Instead we hook each reader at function entry via
detour, check the gene index, and dispatch to vanilla
or our buffer.

For functions that take the gene index as a parameter
(the 4 evaluators / mutators):

- [ ] **D1.1.** Detour `FUN_1400a5d20` (allele evaluator
      formula 1). At entry, if `param_2 >= 240`:
      compute the same blend formula against
      `EXT_GENE_TABLE[param_2 - 240]` and the
      per-horse extended genome at
      `EXT_HORSE_GENOMES[horse_id][param_2 - 240]` and
      `[..][param_2 - 240 + 240]`. Return that value.
      Else fall through to vanilla.
- [ ] **D1.2.** Detour `FUN_1400a5e00` (allele evaluator
      formula 2). Same structure as D1.1 but with the
      formula-2 math.
- [ ] **D1.3.** Detour `FUN_1400c0660:730` (death
      handler ±5 mutator). Inspect the index variable;
      if >= 240, mutate `EXT_GENE_TABLE[index - 240]`
      instead. Probably easier to just patch the
      specific ADD/SUB instructions to also branch on
      index range.
- [ ] **D1.4.** Detour `FUN_1400c03a0` (allele renumber
      sync). When called with gene index >= 240, swap
      values in `EXT_GENE_TABLE` and the extended pop
      weights, NOT vanilla.

For functions that iterate the whole table (the loops
at `0xf0`):

- [ ] **D1.5.** Patch `FUN_1400a3eb0:156` loop bound
      `0xf0` -> `N`. The default-init loop now writes
      defaults for ALL N slots. Wait. This loop writes
      to `&DAT_1403ee4a4 + i*32`, which is the static
      table only sized for 240. If we extend the loop
      bound, vanilla writes overflow into adjacent
      `.data`. Two options:
      - (a) Patch the loop body too to detour writes
        for `i >= 240` into `EXT_GENE_TABLE`.
      - (b) Leave the loop bound at 240; init
        `EXT_GENE_TABLE` separately at attach.
      Option (b) is cleaner and matches the design
      principle. **Choose (b).**
- [ ] **D1.6.** Patch `FUN_1400a3eb0:984` loop bound
      similarly. This is the per-XML-write loop. For
      each `<gene name="X">` in genes.xml, it looks up
      X by name in the chromomap. If we extend genes.xml
      with our own genes (or use a sidecar
      `genes-extended.xml`), the loader needs to
      populate `EXT_GENE_TABLE` for those. Two options:
      - (a) Inject our extended genes into the same
        chromomap so the vanilla loader handles them.
      - (b) Run a separate loader on attach that reads
        a sidecar XML and populates `EXT_GENE_TABLE`.
      Option (b) is cleaner. **Choose (b).** Loop bound
      stays at vanilla 0xf0.
- [ ] **D1.7.** Patch `FUN_1400a4880:298` (XML serializer
      loop). Same decision: leave vanilla bound, run our
      own serializer for `EXT_GENE_TABLE` to write a
      sidecar XML. Loop bound stays.
- [ ] **D1.8.** Detour `FUN_1400c1cf0` (CRISPR UI). When
      the player selects a gene index >= 240, read from
      `EXT_GENE_TABLE`. Optional in v1; can defer if
      CRISPR UI doesn't need to expose extended genes.

**Net for D1:** 4 detours (D1.1-D1.4), 0 loop-bound
patches (we use sidecar loaders / serializers), 1
optional UI detour (D1.8).

### Phase D3: Per-horse genome extension

Each horse gets a parallel 480-byte buffer in
`EXT_HORSE_GENOMES[horse_id]` for the extended genes'
diploid alleles.

**Revised plan 2026-05-15:** Working genome is inline
at `horse + 0x2b8`, NOT at `horse[+0x78]`. The original
D3.1-D3.3 targets (`FUN_14005cf70/cd00/d190`) operate on
the heap blob at `+0x78`, which is a pop-seed / archive
buffer loosely coupled to rendering. They are NOT the
right anchors for `EXT_HORSE_GENOMES` lifecycle because:

- `FUN_14005cf70` bails early if `+0x78` already set,
  and breeding flow `FUN_1400b2e30` does NOT call it
  (combinator writes `+0x2b8` directly, never touches
  `+0x78`). Bred horses would skip the anchor.
- `FUN_14005d190` is a pop-seed copy (UI / CRISPR
  snapshot), not the breeding combinator.

The correct lifecycle anchor is the **horse-struct
allocator itself** (currently unfound). Open research
2026-05-15: `FUN_1400cc9d0` allocates 0x80 bytes and
pushes to `gamestate[+0xb8]` (the "track entity" list);
that's too small for the full horse with fields at
+0x800. There must be a separate `FUN_xxxxxxxx` that
allocates the full Horse struct and pushes to
`gamestate[+0x130]`. Need to find it.

- [x] **D3.0 (research).** ANSWERED 2026-05-15.
      Horse struct size is **0x498 bytes (1176)** =
      `0x2b8 + 0x1e0` (header up to +0x2b7, inline
      genome +0x2b8..+0x497). 40+ call sites alloc
      via `FUN_1402c704c(0x498)` followed by the
      single constructor `FUN_1400aac60`. Examples:
      lines 28589, 29161, 32559, 34040, 54169, 55517,
      59098, 62233, 64176, 65267 (save load), 76563,
      84065, 112352, 119180, 121872, 130208, 145756.
      Constructor `FUN_1400aac60`:
      - Sets vtable `&PTR_FUN_14030d660`
      - Zeros 50+ fields
      - Sets default `max_age = 0x1e` (30 years) at
        `+0x44`
      - Increments live-count global `_DAT_1403f311c`
      - Returns the same pointer it received
      Destructor `FUN_1400bf1f0`:
      - Resets vtable
      - Decrements `_DAT_1403f311c`
      - Releases sub-objects (`param_1[0x3e]` via
        `FUN_1402c7088(p, 0x1f48)`, and the std::string
        SSO buffers at `+0x51/+0x31/+0x2d`)
      - Frees the 0x498 buffer if delete-flag set
        (line 111549)
- [x] **D3.1.** SHIPPED 2026-05-15.
      `src/patches/lifecycle.rs`. Post-hook on
      `FUN_1400aac60`; calls
      `genes::ensure_horse_ext_genome(ret_ptr)`. HTTP:
      `genes.ext.lifecycle.{dryrun,arm,disarm,stats}`.
- [x] **D3.2.** SHIPPED 2026-05-15. Same module as D3.1.
      Pre-hook on `FUN_1400bf1f0`; calls
      `genes::drop_horse_ext_genome(param_1)`.
- [ ] **D3.3.** SKIPPED. The original plan to mirror
      `FUN_14005d190` (parent-to-child heap copy) is
      unnecessary: that function only writes the +0x78
      archive, not the working genome. Combinator
      (D3.4) handles the parent-to-child working-genome
      copy on its own.
- [x] **D3.4 (research).** ANSWERED 2026-05-15.
      Combinator is `FUN_1400a2d80(parent_a + 0x2b8,
      parent_b + 0x2b8, child + 0x2b8)`. Called from
      `FUN_1400b2e30:104367` (child-from-parents
      setup) before `FUN_14009f680` engine evaluates
      the new child.

      Algorithm: outer loop 2 strands × inner loop 240
      genes. Per (strand, gene): `FUN_1400c6580()` RNG
      coinflip selects which parent's strand to copy
      from, then `*(child + gene) = *(parent +
      coinflip * 0xf0 + gene)`. Advance child by 0xf0
      after each strand. Standard Mendelian: one
      strand per parent, each strand draws from one of
      that parent's two strands at random.

      **Linked inheritance:** a bitmask at lines
      95541-95551 forces the SAME parent across three
      gene-index ranges:
      - 72..86 (Neck cluster)
      - 97..174 (Head/Eye/Brow/Ear/Teeth/Mouth/Nose/
        Antlers/Hat)
      - 183..197 (palette base + colors)
      Plus exclusions at idx 83 and 107. Matches the
      GENE-CATALOG cluster map. Player can't get a
      giraffe head with a tiger jaw.

      **Bonus correction:** the working genome is
      INLINE at `horse + 0x2b8` (0x1e0 = 480 bytes,
      2 strands × 240 alleles), NOT at `horse[+0x78]`.
      The heap-alloc at `+0x78` is a separate pop-seed
      / snapshot blob. Engine `FUN_14009f680` and
      consumer `FUN_1400ab3d0` both take
      `param_1 + 0x2b8` as the genome input. **This
      changes D5.7 and D3 design assumptions: ext
      genomes should mirror the +0x2b8 inline layout,
      not the +0x78 heap-pointer pattern.**

      Patch plan (user decisions 2026-05-15):
      - Post-hook detour on `FUN_1400a2d80`. After
        vanilla returns, recover horse base pointers
        as `param_N - 0x2b8` (params are
        `parent_a + 0x2b8`, `parent_b + 0x2b8`,
        `child + 0x2b8`), then run our own combinator
        on `EXT_HORSE_GENOMES[parent_a_ptr]` +
        `EXT_HORSE_GENOMES[parent_b_ptr]` ->
        `EXT_HORSE_GENOMES[child_ptr]`.
      - Default inheritance: **independent per gene**
        (no cluster locking). Linked-inheritance is
        future XML extension via a `<linked-cluster>`
        element in `genes-extended.xml`; not in v1.
      - `horse[+0x78]` is **ignored entirely** for ext
        purposes (pop-seed / CRISPR snapshot only,
        not read for rendering). No parallel ext
        buffer at +0x78. Modders can't author effects
        riding on +0x78.

      **D3.4 patch SHIPPED 2026-05-15.** Implemented as
      `src/patches/combinator.rs`. Post-hook detour on
      `FUN_1400a2d80` via `retour::GenericDetour<unsafe
      extern "system" fn(*mut c_void, *mut c_void,
      *mut c_void)>`. Slow path delegates to
      `genes::combine_for_breeding(pa_id, pb_id,
      child_id)` which runs SplitMix64-seeded Mendelian
      over `EXT_HORSE_GENOMES`. HTTP ops:
      `genes.ext.combinator.{dryrun,arm,disarm,stats}`.

### Phase D5: Gene-effect engine extension (trampoline)

**Strategy locked 2026-05-14: S2 from
[`HOOKING-STRATEGY.md`](HOOKING-STRATEGY.md).** One
post-hook trampoline on `FUN_14009f680` via
`retour::GenericDetour`. Senior eng approved; second-best
(S1, per-callsite detour at the 6 call pairs) explicitly
rejected for the reasons in
[`HOOKING-STRATEGY.md`](HOOKING-STRATEGY.md) §5. Library:
`retour = "0.3"` (Rust port of MS Detours, used in shipped
Rust mods for Diablo 2, SAMP, Zoo Tycoon, Garry's Mod,
Guild Wars 2).

Net for D5: 1 patch site (the entry of `FUN_14009f680`),
1 Rust handler, 1 sidecar module (`render_trampoline.rs`).

- [x] **D5.0.** DONE. `retour = "0.3"` added to workspace
      `Cargo.toml` and `horsey-mod/Cargo.toml`. Build picks
      up retour 0.3.1 + transitive deps (libudis86,
      mmap-fixed-fixed, slice-pool2, winapi). Compiles
      clean.
- [x] **D5.1.** DONE.
      `horsey-mod/src/patches/render_trampoline.rs` shipped.
      Holds `GenericDetour<unsafe extern "system" fn(*mut f32, *mut c_void)>`
      in a `OnceLock<Mutex<Option<...>>>`, with the same
      arm / revert / dryrun shape as ext_genes. Targets
      `fn_addr::APPLY_GENE_TO_HORSE` (0x14009f680).
- [x] **D5.2.** DONE. Post-hook handler implemented:
      runs trampoline first, computes
      `horse_ptr = ctx - HORSE_CTX_OFFSET (0x2b8)`, then
      calls `genes::apply_render_to_buf(buf, 353, horse_id)`.
      The helper acquires `gene_table().read()` and
      `horse_genomes().read()` ONCE per call (single lock
      acquisition for the whole gene walk, not per gene).
      Bounds-checks every slot write against the 353-float
      buffer.
- [x] **D5.3.** DONE in D7.2. `RenderMapping` parsed from
      `<render slot mode>` and stored in `ExtGene.render`.
      The D5.2 handler consumes it.
- [x] **D5.4.** DONE. HTTP ops shipped:
      `genes.ext.render.dryrun` (address + prologue),
      `genes.ext.render.arm` (install detour),
      `genes.ext.render.disarm` (revert),
      `genes.ext.render.stats` (`call_count` +
      `genes_applied_total`).
- [x] **D5.5.** DONE. `patches::revert_all` now calls
      `render_trampoline::revert()` BEFORE
      `ext_genes::revert()` (LIFO order: D5 was the most
      recently installed). DLL detach restores all prologues.
- [x] **D5.6.** DONE. `call_count` (every invocation of
      `FUN_14009f680` after arming) and `genes_applied_total`
      (sum of extended-gene render applications across all
      calls) surfaced via `genes.ext.render.stats`. The
      "buf bytes modified" counter from the original plan
      is the same number as genes_applied_total (one slot
      per applied gene), so it's not separately tracked.
- [ ] **D5.7.** Open. Horse-pointer-as-key works for a
      session; save/load needs D4.4 (stable horse-id field).
      Documented limitation; not blocking visual verification.
- [ ] **D5.8.** Re-entrancy audit deferred until D5
      validates in-game. The current design uses only
      `RwLock::read()` inside the post-hook handler;
      `genes.ext.reload` (which takes write) is operator-
      triggered, not vanilla-triggered, so re-entrancy
      from inside the engine is impossible. Lock-ordering
      audit can wait until concurrent stress shows up.

**D5.4 in the original plan is DROPPED from v1 scope.**
The "post-consumer trampoline writing to new horse struct
fields" was meant for visual modes the consumer doesn't
read (slots outside the 61 consumer-read set). Postpone:
if v1 authoring hits a wall on "this effect needs a slot
the consumer doesn't see," reopen as a sibling phase. We
have 61 consumer-read slots and roughly 10 v1 genes; the
pigeonhole says we won't hit the wall in v1.


## 10. `sleep_safe_no_tire` patch (shipped 2026-05-14)

Module `horsey-mod/src/patches.rs::sleep_safe_no_tire`. NOPs the `mov byte ptr [reg+0x206], 0` zero-store inside the per-frame `no_tire` loop at `FUN_1400ceb60`, leaving the `+0x205` store intact. Race eligibility (`+0x205`) is still bypassed; sleep eligibility (`+0x206`) keeps working so the player can advance the day cycle.

### Patch-site discovery: three iterations before shipping

The instruction the patch targets is `mov byte ptr [<reg> + 0x206], 0` (7 or 8 bytes depending on REX prefix). The challenge: identifying THIS specific store, not the other `+0x206` writes in the function.

- **v1: RAX-only.** Matched `mov byte ptr [rax+0x206], 0`. Zero matches on user build (compiler picked a different reg).
- **v2: all regs.** Matched any `mov byte ptr [reg+0x206], 0`. Two candidates in the function; can't pick.
- **v3 (shipped): proximity anchor.** Picks the `+0x206` zero-store that has a sibling `+0x205` zero-store within 64 bytes. The compiler emits both stores back-to-back in the no_tire loop, but never anywhere else, so this disambiguates.

If v3 ever fails on a future build (e.g. compiler reorders so the stores aren't within 64 bytes), the fallback plan is to anchor on the `DAT_1403d95c5` RIP-relative read at `FUN_1400ceb60:612` and take the first `+0x206` store after it. Only one other `+0x206` store exists in the function (at `:382`) and it has no nearby `DAT_1403d95c5` read.

If both fail: hand-disassemble per-build and bake the offset as a constant. Or migrate to pattern-scan via `modforge::patterns::sleuth` (see [`ADDRESS-RESOLUTION.md`](ADDRESS-RESOLUTION.md) R2).

Until v3 was wired, the shipping path was a 50ms Rust worker zeroing only `+0x205` (`horsey-mod/src/fatigue.rs`); that remained as a fallback in case the patch reverted.

### Patch infrastructure (shared across all binary patches)

`horsey-mod/src/patches.rs::patch_bytes(name, addr, new_bytes)` is the workhorse: `VirtualProtect` to RW, `copy_nonoverlapping`, restore protect, `FlushInstructionCache`. Records original bytes in `APPLIED` so `revert_all()` puts them back on DLL detach. Used by `sleep_safe_no_tire` today; will be used by `D1.3` if/when we re-derive the mid-function death-drift mutator.
