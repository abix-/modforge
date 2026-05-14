# Bestiary Expansion: Viability Research

> **Status:** in progress (started 2026-05-14).
> **Owner:** horsey-mod.
> **Purpose:** answer every "is X possible?" question from
> [`todo.md`](todo.md) Phase 0 before locking the species
> list, the new-gene list, or the build order.
>
> Each question has a status: **OPEN** / **IN PROGRESS** /
> **ANSWERED**. Answered questions cite file:line.

---

## Design principle: layer on top of vanilla

**User direction 2026-05-14:** our code sits ON TOP of
vanilla. We do NOT rewrite vanilla functionality. We
only override vanilla where overriding is the only way
to accomplish the goal.

This principle ranks every strategy choice in this doc:

- Prefer a **trampoline / postfix patch** (let vanilla
  run, then add our effects on top) over a vanilla
  rewrite.
- Prefer a **sidecar file** for new save data over
  modifying the vanilla save format.
- Prefer **heap redirect** of vanilla data structures
  over inline table expansion (the readers stay
  vanilla; we just point them at bigger backing
  storage).
- Accept full vanilla rewrites ONLY where:
  - the goal genuinely cannot be achieved by layering
    (e.g. extending a fixed-cap loop bound), and
  - the rewrite is small and surgical (a few literal
    patches), not a logic re-implementation.

Concrete consequences elsewhere in this doc:

- Q-gene-3 / Q-gene-4: gene-effect engine. We add a
  trampoline that runs after `FUN_14009f680` and adds
  new gene effects on top of its `param_1[]` output
  array. We do NOT reimplement the 14KB function.
- Q-save-3: save format strategy. The sidecar-file
  option (write modded data to a `.ext` file
  alongside the vanilla save) becomes the LEADING
  candidate, not just one option among three.
- Per-horse genome: we leave the 480-byte vanilla
  block alone and store our extended alleles in a
  parallel buffer keyed by horse ID.

---

## Q-gene-1: every reader of the gene table

**Status:** ANSWERED.

### Record layout

The gene table is NOT a single symbol. It's a record-based
layout with three Ghidra symbols inside each record:

| Symbol | Offset within record | Field |
|---|---|---|
| `DAT_1403ee4a0` | +0x00 | gene index (uint32, self-check field) |
| `DAT_1403ee4a4` | +0x04 | mutation rate (uint32) |
| `DAT_1403ee4b0` | +0x10 | alleles g0..g3 (4 x uint32 = 16 bytes) |

Record size: 32 bytes (8 uint32). Confirmed by the
loader's `puVar11 = puVar11 + 8` stride at
[`funcs/1400a/1400a3eb0_FUN_1400a3eb0.c`](../../horseygame/decompiled/funcs/1400a/1400a3eb0_FUN_1400a3eb0.c)
and the readers' `[i*8]` indexing on `uint32*`.

Layout confirmed by the self-check in
[`funcs/1400a/1400a5d20_FUN_1400a5d20.c:24`](../../horseygame/decompiled/funcs/1400a/1400a5d20_FUN_1400a5d20.c):
`if ((&DAT_1403ee4a0)[lVar2 * 8] != param_2) FUN_1400c4340("Bad GX %d");`.
The function asserts that record N's index field equals N
and panics with `"Bad GX %d"` on mismatch. Important:
this assert means our extension code MUST keep the index
field self-consistent in any new records we add.

### Readers

The table is touched by **7 unique functions** across the
entire binary (after grepping all three record symbols):

| Function | Role | Mutates? | Access pattern | Cite |
|---|---|---|---|---|
| `FUN_1400a3eb0` | XML loader (`load_genes_xml`) | yes (init + per-XML write) | sequential init, then per-name lookup | [`funcs/1400a/1400a3eb0_FUN_1400a3eb0.c:134`](../../horseygame/decompiled/funcs/1400a/1400a3eb0_FUN_1400a3eb0.c) |
| `FUN_1400a4880` | XML serializer (writes attrs back) | reads | `*((longlong)&DAT_1403ee4a4 + uVar15)` | [`funcs/1400a/1400a4880_FUN_1400a4880.c:140`](../../horseygame/decompiled/funcs/1400a/1400a4880_FUN_1400a4880.c) |
| `FUN_1400a5d20` | gene-allele evaluator (formula 1) | reads | `[i*8]` indexed by gene id | [`funcs/1400a/1400a5d20_FUN_1400a5d20.c:60`](../../horseygame/decompiled/funcs/1400a/1400a5d20_FUN_1400a5d20.c) |
| `FUN_1400a5e00` | gene-allele evaluator (formula 2) | reads | same as above | [`funcs/1400a/1400a5e00_FUN_1400a5e00.c:62`](../../horseygame/decompiled/funcs/1400a/1400a5e00_FUN_1400a5e00.c) |
| `FUN_1400c0660` | runtime mutator (±5) | **yes (live)** | `[i*8] += 5` and `[i*8] += -5` | [`funcs/1400c/1400c0660_FUN_1400c0660.c:730`](../../horseygame/decompiled/funcs/1400c/1400c0660_FUN_1400c0660.c) |
| `FUN_1400c03a0` | allele swap (breeding?) | **yes (live)** | swaps `DAT_1403ee4b0[i]` with `DAT_1403ee4b0[j]` | [`funcs/1400c/1400c03a0_FUN_1400c03a0.c:40`](../../horseygame/decompiled/funcs/1400c/1400c03a0_FUN_1400c03a0.c) |
| `FUN_1400c1cf0` | unknown (CRISPR? mixing?) | likely yes | accesses `&DAT_1403ee4a8 + i*8` AND `&DAT_1403ee488 + j*4` | [`funcs/1400c/1400c1cf0_FUN_1400c1cf0.c:270`](../../horseygame/decompiled/funcs/1400c/1400c1cf0_FUN_1400c1cf0.c) |

### Key sub-findings

- **All accesses are by-variable, none by literal.** Every
  reader uses an index variable (`lVar2`, `iVar26`,
  `uVar15`, etc.). No reader does `[17]` or hardcodes a
  gene index. STRONG positive signal for table extension.
- **All record-based readers use 32-byte stride** (`[i * 8]`
  on `uint32*`). Consistent layout, no mixed strides.
- **The table mutates at runtime in 3 different ways.**
  - `FUN_1400c0660` adjusts mutation rate by ±5 (death
    handler? mutation rate drift?).
  - `FUN_1400c03a0` swaps allele values between two gene
    indices (looks like a Fisher-Yates partial shuffle or
    breeding-step crossover).
  - `FUN_1400c1cf0` reads sibling addresses (`DAT_1403ee4a8`
    = +8 = `scale` field; `DAT_1403ee488` = -0x18 from
    `DAT_1403ee4a0` = a 24-byte-earlier static area).
    Possibly the CRISPR mechanic, possibly a different
    table entirely. Needs deeper read.
- **Adjacent static area `DAT_1403ee488`.** `FUN_1400c1cf0`
  references a symbol 24 bytes BEFORE the gene table base.
  This may be a sibling header struct or a separate
  pre-table data block. Whatever it is, it constrains the
  in-place-expand strategy: there is NO unused padding
  before the gene table.
- **`FUN_1400a4880` likely round-trips the table to XML**
  (the `FUN_1400258d0(uVar11, &DAT_14030cc5c, ...)` call
  with the "name" string suggests writing
  `<gene name="..." attr=...>` back out). Means
  gene-table state IS persisted through some XML save
  path. Affects Q-save-1.

### Implications

- **Tiny patch surface for table extension.** Five functions
  is small enough to retarget by hand without risk.
- **All accesses use the same 32-byte stride** (`[i * 8]`
  on a `uint32 *`). No mixed strides to chase.
- **The table is not static config.** `FUN_1400c0660`
  mutates entries by ±5 at runtime (per the existing
  annotation file
  [`key-funcs/0x1400c0660_horse_is_dead_handler.c`](../../horseygame/decompiled/key-funcs/0x1400c0660_horse_is_dead_handler.c)
  this is the death handler). Means gene-table rows are
  game state, not just config. Affects:
  - save/load: the runtime drift may be persisted (need
    Q-save-1 to confirm).
  - hot-reload of `genes.xml`: a reload would clobber any
    runtime drift accumulated since the last load.
- **`FUN_1400a4880` looks like the XML round-tripper**
  (writes the in-memory table back out as XML). Useful
  hint: gene-table state IS persisted somewhere via XML
  serialization.

---

## Q-gene-2: literals `0xf0` and `0x1e00` (table bounds)

**Status:** ANSWERED (re-verified after Q-gene-1 added 2 readers).

`0xf0` (240, the slot count) appears as a **table loop
bound** in exactly **3 places** across the 7-function
reader set:

| Cite | Loop | Purpose |
|---|---|---|
| [`funcs/1400a/1400a3eb0_FUN_1400a3eb0.c:156`](../../horseygame/decompiled/funcs/1400a/1400a3eb0_FUN_1400a3eb0.c) | `while ((int)uVar21 < 0xf0)` | default-init loop |
| [`funcs/1400a/1400a3eb0_FUN_1400a3eb0.c:984`](../../horseygame/decompiled/funcs/1400a/1400a3eb0_FUN_1400a3eb0.c) | `while ((int)uVar21 < 0xf0)` | per-XML write loop |
| [`funcs/1400a/1400a4880_FUN_1400a4880.c:298`](../../horseygame/decompiled/funcs/1400a/1400a4880_FUN_1400a4880.c) | `while ((int)uVar17 < 0xf0)` | second writer loop |

The 5 non-loader readers (`a5d20`, `a5e00`, `c03a0`,
`c0660`, `c1cf0`) take the gene index as an argument and
do not iterate the whole table, so they do not contain
loop bounds at `0xf0`.

Other `0xf0` hits in the gene-table function set are NOT
table bounds:

- `FUN_1400a3eb0:920` `uStack_190 = 0xf0;`. Std::string
  SSO capacity flag (15 chars + 0xf0 marker), unrelated.
- `FUN_1400a5d20:38` / `FUN_1400a5e00:38`
  `lVar2 + 0xf0 + param_1`. Struct-offset arithmetic
  (offset 240 INTO a different struct), unrelated.
- `FUN_1400c0660:288` `param_1 + 0xf0`. Another
  struct-offset, unrelated.

`0x1e00` (7680 = 240 * 32, the full table byte size) does
not appear in code at all. The full-table-size literal is
not used directly; the loops walk by entry count, not by
byte count. Good news: no allocation literal to patch.

### Implications

- **Three loop-bound patches and we're done with bound
  patching.** Each is a small literal we can NOP / rewrite
  via the existing patch infra in
  `horsey-mod/src/patches.rs`.
- **No big-allocation patch needed.** The table is in
  `.data` (static), not heap-allocated. Extension strategy
  must redirect the base, not just grow in place. See
  Q-gene-4.

---

## Q-gene-3: gene-by-INDEX consumers (literal vs name-lookup)

**Status:** ANSWERED. Hard YES on literal-index baking,
but concentrated in ONE function.

### Direct table readers (Q-gene-1 set): all index by variable

The 7 reader functions in Q-gene-1 all use index
variables. None do `&DAT_1403ee4a4 + 17`. So the table
ITSELF is consumed generically.

### Allele evaluators have ONE caller. The gene-effect engine

The two allele evaluators (`FUN_1400a5d20` /
`FUN_1400a5e00`) are called from exactly one place across
the entire binary: **`FUN_14009f680`**. Verified by
grepping all of `decompiled/funcs/`.

This function is the gene-effect engine. It:

- decompiles to **3,298 lines** (original 14,074 bytes,
  one of the largest functions in the binary).
- contains **293 calls** to the allele evaluators.
- references **219 unique literal gene indices** (of the
  242 vanilla genes). Examples:
  `FUN_1400a5d20(local_508, 0)` reads gene 0,
  `FUN_1400a5d20(local_508, 0x53)` reads gene 83, etc.

Every gene's effect on the horse (size, color channels,
leg length, tail shape, all of it) is hardcoded in this
function by literal index.

### Implication

This is the killer finding for naive "just extend the
table" plans. Adding a gene at index 242 produces a
table entry with allele values that get computed and
stored, but NO ONE READS THEM. The new gene has zero
in-game effect because `FUN_14009f680` doesn't know about
it.

To make new genes do anything, we have to extend
`FUN_14009f680` too. Three strategies:

1. **Patch trampoline.** Hook the end of `FUN_14009f680`
   (or a postfix after each output write), then in our
   own Rust code add per-new-gene effects on top of the
   game's computed horse data. Doable: we already have
   the patch infra, and `FUN_14009f680`'s output is
   `param_1` (a `float *`) which is the horse's
   per-frame parameter array.
2. **Inline-replacement.** Replace `FUN_14009f680`
   wholesale with our own Rust port that reads ALL
   genes (vanilla + new) and writes the same output
   array. Maximum control, maximum work (we have to
   reimplement 14KB of compiled gene-effect logic).
3. **Hybrid.** Let vanilla `FUN_14009f680` run, then
   our trampoline modifies / overrides specific
   `param_1[N]` outputs based on new gene values.

Strategy 1 (patch trampoline) is the natural fit: it
preserves all vanilla behavior, only adds new effects on
top. The cost is figuring out which `param_1[N]` slots
correspond to which horse parameters (size, color, etc.)
so our new genes can drive them.

### Mutator callers: still to trace

- [ ] `FUN_1400c0660` (±5 mutator). Find callers,
      check for literal indices.
- [ ] `FUN_1400c03a0` (allele swap). Find callers.
- [ ] `FUN_1400c1cf0` (CRISPR?). Find callers.

### Genome-layout side-finding

Confirmed in `FUN_1400a5d20`: per-horse genome stores 2
alleles per gene at offsets `i` and `i + 0xf0` (240-byte
stride for the second copy). Save / load and breeding
inherit this stride. See Q-save-* below.

---

## Q-gene-4: table-extension strategy

**Status:** OPEN (depends on Q-gene-1, Q-gene-2 done; Q-gene-3 in progress).

What we know so far:

- 5 reader functions, 32-byte stride throughout.
- 3 loop bounds at `0xf0`. No allocation-size literal.
- Table is static (`.data`), not heap.

Three candidate strategies:

1. **In-place expand.** Impossible for a `.data`
   allocation (no slack between `DAT_1403ee4a4` and the
   next symbol). REJECTED unless we find unused padding.
2. **Heap redirect.** Allocate a new bigger table on the
   heap, patch each of the 5 readers to dereference
   through a pointer we own, patch loop bounds.
   - cost: 5 readers x (RIP-relative -> indirect) patch
     each. Not trivial but tractable with the existing
     patch infra.
   - upside: unbounded cap, future-proof.
3. **Fixed expand to e.g. 512 slots in heap, but keep
   `DAT_1403ee4a4` as a forwarding pointer.** This
   requires writing the heap-table base AT
   `DAT_1403ee4a4` itself, but since current code does
   `(&DAT_1403ee4a4)[i*8]` (treats the symbol as the
   table), this is actually identical to strategy 2; the
   only difference is whether we patch readers to
   dereference, or we patch the symbol's contents to be
   a pointer (which doesn't work because callers expect
   it to BE the table, not a pointer to it).

So the practical choice is strategy 2: **heap redirect
with reader patching.**

Open sub-questions:

- [ ] Is there unused padding after `DAT_1403ee4a4` we
      could exploit for in-place expansion? Check the
      symbol immediately following in the binary.
- [ ] How much headroom do we want? 256 = double, 512 =
      quadruple, 1024 = future-proof.

---

## Q-gene-5: how many vanilla gene slots are unused?

**Status:** ANSWERED. Only **7 free slots**, not the 23
we initially estimated.

### Method

Extracted every `(local_508, N)` literal from
`FUN_14009f680`'s 293 calls to the allele evaluators.
Normalized hex (`0x10`) and decimal (`200`) into ints.
Computed `set(range(240)) - referenced_indices`.

### Result

| Metric | Value |
|---|---|
| Total gene slots in table | 240 (`0xf0`) |
| Indices referenced by `FUN_14009f680` | 233 |
| Indices NOT referenced (free slots) | 7 |
| Unused indices | 56, 57, 107, 183, 184, 209, 216 |

### Implication

The "repurpose only" path tops out at **7 new genes** if
we use only completely-unused slots. That's far short of
what 28+ new species need for visual distinctness with
fresh genes per species.

But "unused by the gene-effect engine" is the strict
definition. A looser definition is "used by the engine
but unauthored by `pop.xml`": even genes that DO have
effect code may have no pop driving them at non-default
weights. Those become candidates for repurposing if we
accept that we're changing what the gene MEANS in the
engine, not just what its alleles are.

To do (folded into Phase 0 for completeness):

- [ ] Cross-reference vanilla `pop.xml` against the 233
      referenced indices to find genes that exist in code
      but no pop authors at non-default weights. Those
      are "soft-free" and may be safely repurposed by
      having our trampoline override their effect.
- [ ] Read each of the 7 hard-free slots (56, 57, 107,
      183, 184, 209, 216) and confirm they're really
      effect-free (the regex extracted only direct
      `FUN_1400a5d20(local_508, N)` calls; the gene
      might be read by other paths I haven't grepped).

### Net read

Repurpose-only gives us 7 hard-free + maybe 10-30
soft-free slots = enough for an interesting first wave
but not enough for the full 28-species ambition with
new-gene-per-species. **Hybrid is the realistic path:**
use the free slots for the easiest wins (where a single
extra knob enables a species), and commit to full table
extension for the species that need genuinely novel
mechanics (wings, transparency, etc.).

---

## Pop system (Q-pop-*)

**Status:** PARTIAL. Q-pop-1 and Q-pop-3 answered.
Q-pop-2 and Q-pop-4 still open.

### Q-pop-1: does the engine accept arbitrary new pop names?

**ANSWERED: yes, unbounded.**

Pop loader is `FUN_1400a4fe0`
([`funcs/1400a/1400a4fe0_FUN_1400a4fe0.c`](../../horseygame/decompiled/funcs/1400a/1400a4fe0_FUN_1400a4fe0.c)).
Identified by the `"pop.xml load fail"` error string at
:254. Function size: 889 bytes, 502 lines decompiled.

The pop-iteration loop at lines 300-466 is
`do { ... } while (lVar5 != 0)` where `lVar5` is the
result of `FUN_140025450()` (next-sibling fetch). It
walks the XML siblings until exhausted with **no count
cap**. Adding more `<pop>` elements just extends the
loop.

### Q-pop-3: pop in-memory data structure

**ANSWERED: heap-grown vector of 3840-byte records.**

Each pop record is 3840 bytes (`0xf00`), copied via
`FUN_1402f8e20(local_2040, &local_3060, 0xf00)` at :392.
Layout (inferred):

- variable: pop name (heap-allocated std::string)
- 240 x uint32 gene-weight fields (the per-gene
  `p0..p3` weights, the per-pop overrides), initialized
  to `1` at :290-298 in a `do { *puVar7 = 1; lVar10--; }
  while (lVar10 != 0)` loop with `lVar10 = 0xf0`.
- some header / metadata bytes that round it to 3840.

Storage: `FUN_1400285e0(uVar11 + 1)` at :382 allocates
on the heap with capacity tracking (`local_2048 = uVar11`
is the cap, `local_2050 = uVar3` is the count). Looks
like a `std::vector<Pop>`. Grows as more pops load.

### The 0xf0 reappears here

The pop-loader contains a `0xf0` literal at :278 that
sizes the per-pop gene-weight init loop. **This is a
fourth patch site for the gene-table extension story:**
extending the gene count means each pop record's
gene-weight array also grows, which means this loop
bound + the 3840-byte record size + the `0xefc`
memset at :276 all need to grow proportionally.

So the patch surface for "extend gene table to N slots"
is now:

| Site | Type |
|---|---|
| `FUN_1400a3eb0:156` | gene-table init loop |
| `FUN_1400a3eb0:984` | gene-table per-XML write loop |
| `FUN_1400a4880:298` | gene-table writer loop |
| `FUN_1400a4fe0:278` | per-pop gene-weight init loop |
| `FUN_1400a4fe0:276` | per-pop record memset (0xefc bytes) |
| `FUN_1400a4fe0:392` | per-pop record copy (0xf00 bytes) |

Six patch sites for bounds. Plus the gene-table heap
redirect (touches 7 reader functions). Plus the pop-
record-size change cascades to whatever else copies pop
records.

### Q-pop-2: unknown pop name behavior

**ANSWERED: hard crash with modal error dialog.**

Pop lookup happens in `FUN_1400a2ed0` and `FUN_1400a30c0`
(likely "lookup_pop_by_name" and a sibling). On miss, both
call `FUN_1400c4340("pop not found %s", name)`
([`funcs/1400a/1400a2ed0_FUN_1400a2ed0.c:106`](../../horseygame/decompiled/funcs/1400a/1400a2ed0_FUN_1400a2ed0.c)
and
[`funcs/1400a/1400a30c0_FUN_1400a30c0.c:70`](../../horseygame/decompiled/funcs/1400a/1400a30c0_FUN_1400a30c0.c)).

`FUN_1400c4340` is the panic helper
([`funcs/1400c/1400c4340_FUN_1400c4340.c`](../../horseygame/decompiled/funcs/1400c/1400c4340_FUN_1400c4340.c)):

```
MessageBoxA(NULL, formatted_msg, "Error", 0);
FUN_1402da254(0);
swi(3);  // INT 3, software interrupt -> abort
```

**Implication for the bestiary mod:** misspelled pop
names in `pop.xml`, `horsey.tmx`, or anywhere else are
detected loudly. We never get silent data corruption.
But mod-update churn that removes a pop while saves
reference it will crash existing saves with a modal
dialog. Need authoring discipline + a "lint pop refs"
script as part of the build.

Same `FUN_1400a2ed0` also has a `"Bad Pop %d"` panic at
:116. Probably the integer pop_id lookup (used at save
load time, when `horse.pop_id` byte resolves to a pop).
So unknown pop_id at load time also crashes hard.

### Q-pop-4: inheritance semantics

**OPEN.** The per-pop processor `FUN_1400a5ee0` (called
at :462 with depth marker `0xffffffff`) is the next
read target. Hypothesis: child pops inherit parent gene
weights and override only the genes they explicitly
name. Worth confirming by reading the function.

- [ ] Read `FUN_1400a5ee0` and document the inheritance
      mechanism.

---

## Save / load (Q-save-*)

**Status:** PARTIAL. Findings from existing
[`SAVE-FORMAT.md`](../../horseygame/SAVE-FORMAT.md) plus
the new gene-table reader analysis.

### Q-save-1: per-horse genome storage

**PARTIAL ANSWER: not in the horse roster record.**

The horse roster record is 22 bytes + variable name +
variable child list. Too small for 200+ alleles. Per
[`SAVE-FORMAT.md`](../../horseygame/SAVE-FORMAT.md) the
genome lives in one of the big binary blocks (probably
the 55KB block at 0x0d4f, hypothesis "76 horses x 720
bytes" or "114 horses x 480 bytes").

We now know from `FUN_1400a5d20` that per-horse alleles
are CHAR (1 byte each), stored at offsets `i` and `i +
0xf0` for the diploid pair. So 240 genes x 2 alleles x
1 byte = **480 bytes per horse** for alleles alone. The
"114 horses x 480 bytes = 54720" math fits the 55KB
block almost exactly.

**Critical implication:** extending the gene count
extends the per-horse byte count linearly. Old saves
will have 480 bytes per horse; modded saves will have
2N bytes per horse. Reading an old save with new code
is achievable (pad with default alleles). Reading a
modded save with old code will fail or load garbage.

### Q-save-2: literal table sizes in save / load code

**ANSWERED.** Save format hardcodes the 240-gene cap in
several places. Per-horse genome serialization
identified at `FUN_14006d470` (write) and `FUN_14006d580`
(read), called from the per-horse save record writer
`FUN_14006dbf0`.

#### Encoding scheme

Each diploid allele pair (2 alleles per gene) is packed
into one byte:

```
packed_byte = (allele_b + 1) * 8 | (allele_a + 1)
            = ((b+1) << 3) | (a+1)
```

3 bits per allele, range 0..6. So 240 genes x 2 alleles
= 480 alleles compress to 240 packed bytes per horse.
Top 2 bits of each byte are unused. Decode:
`a = (byte & 7) - 1; b = (byte >> 3 & 7) - 1`.

#### Patch sites for genome save / load

| Function | Cite | Literal | Meaning |
|---|---|---|---|
| `FUN_14006d470` (write) | [`funcs/14006/14006d470_FUN_14006d470.c:18`](../../horseygame/decompiled/funcs/14006/14006d470_FUN_14006d470.c) | `0x28` | Outer loop count (40 iter x 6 packed bytes) |
| `FUN_14006d470` (write) | :22-44 | `0xef..0xf4` | Offsets reaching into the second diploid half |
| `FUN_14006d470` (write) | :60 | `0xf0` | Bulk-write byte count = 240 |
| `FUN_14006d580` (read) | [`funcs/14006/14006d580_FUN_14006d580.c:18`](../../horseygame/decompiled/funcs/14006/14006d580_FUN_14006d580.c) | `0xf0` | Bulk-read byte count = 240 |
| `FUN_14006d580` (read) | :22 | `0x78` | Outer loop count (120 iter x 4 alleles) |
| `FUN_14006d580` (read) | :26-34 | `0xef`, `0xf0` | Same diploid-half offsets |

#### Patch sites for genome alloc / free / walk

| Function | Cite | Literal | Meaning |
|---|---|---|---|
| `FUN_14005cf70` (alloc-only) | [`funcs/14005/14005cf70_FUN_14005cf70.c:152`](../../horseygame/decompiled/funcs/14005/14005cf70_FUN_14005cf70.c) | `FUN_1402c704c(0x1e0)` | 480-byte heap alloc |
| `FUN_14005d190` (alloc + copy) | [`funcs/14005/14005d190_FUN_14005d190.c:40`](../../horseygame/decompiled/funcs/14005/14005d190_FUN_14005d190.c) | `FUN_1402c704c(0x1e0)` | Same |
| `FUN_14005d190` (copy loop) | :84, :88 | `0xf0`, `0x1e0` | Inner / outer copy stride |
| `FUN_14005cd00` (free) | [`funcs/14005/14005cd00_FUN_14005cd00.c:16`](../../horseygame/decompiled/funcs/14005/14005cd00_FUN_14005cd00.c) | `FUN_1402c7088(param_1[0xf], 0x1e0)` | 480-byte free |
| `FUN_140032ac0` (diploid walk) | [`funcs/14003/140032ac0_FUN_140032ac0.c:194`](../../horseygame/decompiled/funcs/14003/140032ac0_FUN_140032ac0.c) | `0xf0`, `0x1e0` | `uVar10 += 0xf0; while uVar10 < 0x1e0` |

### Genome lifecycle summary

| Stage | Function | Per-horse storage |
|---|---|---|
| Alloc (load / breed) | `FUN_14005cf70` / `FUN_14005d190` | 480 bytes at `horse[0x78]` |
| Copy (parent -> child) | `FUN_14005d190` |. |
| Walk (read for evaluation) | `FUN_1400a5d20` / `FUN_1400a5e00` | i and i+0xf0 stride |
| Mutate (live) | `FUN_1400c0660` / `FUN_1400c03a0` |. |
| Save | `FUN_14006d470` (via `FUN_14006dbf0`) | Packs 480 alleles into 240 bytes |
| Load | `FUN_14006d580` | Unpacks 240 bytes into 480 alleles |
| Free | `FUN_14005cd00` | 480-byte free |

### Patch surface for "extend gene count to N"

Total identified sites for the genome path alone:

| Layer | Sites |
|---|---|
| Static gene table (per Q-gene-1) | 7 reader functions + 3 loop bounds |
| Per-pop gene-weight array (per Q-pop-3) | 3 sites in `FUN_1400a4fe0` |
| Per-horse genome alloc / free / walk | 5 sites across 3 functions |
| Per-horse genome save / load | 6 sites across 2 functions |
| Gene-effect engine (per Q-gene-3) | `FUN_14009f680` trampoline (1 site, but big logic) |
| Runtime mutation (per Q-gene-1) | `FUN_1400c0660` already known |

Grand total: roughly **25 patch sites**, all identified
with file:line cites. Plus the gene-effect trampoline
which is a logic addition, not a literal patch.

### Save-compat strategy decision

Three options for the encoding (re-ranked per the
"layer on top of vanilla" design principle):

1. **(Recommended) Sidecar `.ext` file.** Vanilla
   save / load runs untouched, writing the first 240
   genes the vanilla way. Our patch layer writes a
   parallel `<save>.ext` file containing extra alleles
   for genes 240+, keyed by horse ID. On load, we
   read both, merge in memory. Vanilla saves remain
   readable; modded saves degrade gracefully if the
   `.ext` is missing (extra genes default to vanilla
   defaults). ZERO vanilla save-format patches required.
   Cost: save-management complexity (two files, one
   keyed by horse ID).
2. **Replace 3-bit packing with 4-bit.** Reworks both
   `FUN_14006d470` and `FUN_14006d580` to use values
   0..15. Doubles allele range AND increases save bytes
   per horse. Requires patching multiple vanilla
   functions. Violates "layer on top." Only consider if
   sidecar approach can't carry the design.
3. **Keep 3-bit packing, write more bytes.** Smallest
   vanilla rewrite (just bump byte counts in 5
   functions), but still rewrites vanilla rather than
   layering.

**Decision (pending Phase 1 lock-in):** go with sidecar.
Falls cleanly out of the design principle and gives
backwards compat for free.

### Q-save-3: pop_id field width

**ANSWERED: uint8 (1 byte), hard cap at 255 pops.**

Per [`SAVE-FORMAT.md`](../../horseygame/SAVE-FORMAT.md)
the horse roster record's `pop_id` field is uint8 with
observed values 1..12 and 255 (sentinel for "freak" or
"custom").

**Implication:** even though the in-memory pop container
is unbounded (Q-pop-3), the save format caps the total
pop set at 255 via this byte. 56 species (our doubling
goal) is fine. Tripling to 84 is fine. Going past ~250
total pops requires patching the save format pop_id
field too, plus every other place pop_id is referenced.

For the bestiary expansion (target 56), this is a
non-issue. Worth flagging for any future "100s of
species" ambition.

---

## Renderer / behavior (Q-render-*)

**Status:** OPEN. Not yet researched.

---

## Hot reload (Q-reload-*)

**Status:** OPEN. Not yet researched.

---

## Running summary

| Area | Status | Net assessment |
|---|---|---|
| Gene table reader surface (Q-gene-1) | ANSWERED | 7 funcs, tiny surface |
| Gene table loop bounds (Q-gene-2) | ANSWERED | 3 patch sites, no allocation literal |
| Gene-by-index consumers (Q-gene-3) | ANSWERED | 233 literal indices in ONE big function (`FUN_14009f680`) |
| Table extension strategy (Q-gene-4) | OPEN | Heap redirect + trampoline on `FUN_14009f680` |
| Unused gene slots (Q-gene-5) | ANSWERED | Only 7 hard-free slots; need soft-free count next |
| Pop Q-pop-1 (cap) | ANSWERED | Pops are unbounded, heap-grown vector |
| Pop Q-pop-2 (unknown name) | ANSWERED | Hard crash: MessageBox + INT3 abort |
| Pop Q-pop-3 (in-memory layout) | ANSWERED | 3840-byte records, std::vector grows freely |
| Pop Q-pop-4 (inheritance) | OPEN | Need to read `FUN_1400a5ee0` |
| Save Q-save-1 (genome location) | ANSWERED | 480 bytes at horse[0x78], packed to 240 in save |
| Save Q-save-2 (literal sizes) | ANSWERED | 11 patch sites identified across 5 functions |
| Save Q-save-3 (compat strategy) | OPEN | 4-bit pack vs more bytes vs sidecar file |
| Renderer (Q-render-*) | OPEN | covered by Q-gene-3 finding for now |
| Hot reload (Q-reload-*) | OPEN | needs runtime experiment |

### Early read (revised after Q-gene-3 landed)

Three layers of 240-baked-in code to deal with:

1. **Static gene table** at `DAT_1403ee4a4`. 240 records,
   32 bytes each. Patch surface: 7 reader functions + 3
   loop bounds. Tractable.
2. **Per-horse genome** at every horse's data block.
   Two alleles per gene at offsets `i` and `i + 0xf0`
   (240-byte stride). Extending the gene count means
   every horse genome grows, which means save format
   must change, which means save / load / breeding all
   need patches.
3. **Gene-effect engine `FUN_14009f680`.** Hardcodes
   the index-to-effect mapping for 219 of the 242
   vanilla genes. New genes get table slots + allele
   values but produce NO in-game effect unless we
   also extend this function via patch trampoline.

The good news: every layer's patch surface is
identifiable and bounded. The bad news: layers 2 and 3
each add significant work beyond "flip three loop
bounds."

Honest re-scoping: gene-table extension is no longer
"a small patch project." It's a **multi-week binary
modding project** covering:

- patch infra extensions (heap-redirect of gene table)
- save / load schema migration (per-horse allele array
  size change, with old-save compat)
- breeding code retargeting (Mendelian crossover over
  N+ genes instead of 240)
- gene-effect trampoline (call vanilla `FUN_14009f680`,
  then layer our new gene effects on top of the
  `param_1[]` output array)
- runtime mutation handling (`FUN_1400c0660`'s ±5 drift
  needs to apply to new genes too, or be excluded from
  them)

This is exactly the kind of thing the user signed off on
("binary patching is totally ok, we modify EVERYTHING").
But it's worth being explicit about the scope before
locking the plan in Phase 1.

### Possible alternative: "ride existing gene slots"

An option that wasn't on the table when we started:
**don't add new genes at all. Re-purpose unused vanilla
genes.** If any of the 242 vanilla genes are unused or
under-used, we can:

- author pop.xml entries that drive them to extreme
  values for our new species,
- if any are completely dead, redefine their semantics
  in our trampoline (add custom effects on top of
  `FUN_14009f680`'s output, gated on those gene values).

This sidesteps layers 1 and 2 entirely. Only the gene-
effect engine layer (3) remains, and only for the genes
we choose to redefine.

Worth investigating in Phase 0 before committing to
full table extension. Adds Q-gene-5: "how many of the
242 vanilla genes are unused / under-used?"
