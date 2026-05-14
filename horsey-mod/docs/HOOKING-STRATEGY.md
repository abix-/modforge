# Hooking strategy review: making 480 genes drive in-game visuals

> **Status:** REVIEW. Decision pending senior-eng signoff.
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

Concrete changes if S2 is approved:

- Replace D5.1 ("install detours at 6 caller sites") with
  D5.1' ("install one `retour::GenericDetour` on
  `FUN_14009f680`").
- Drop D5.4 (post-consumer hook) from v1 scope. Most new
  visual effects can be expressed via existing
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
