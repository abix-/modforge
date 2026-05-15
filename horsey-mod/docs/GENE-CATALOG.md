# Gene catalog (all 240 vanilla genes)
> **Authoritative on:** EVERYTHING gene-related for Horsey. Conceptual model (alleles, breeding, mutation, diploid genome), engine pipeline (gene engine `FUN_14009f680` -> render buf -> consumer `FUN_1400ab3d0` -> horse-struct fields), cluster map (gene-index ranges to feature areas), buf-slot -> horse-struct mapping, the slots-0..3 SQRT formula, vanilla pops (28 species), confirmed visible-effect slots, modder workflow, and the per-gene reference for all 240 vanilla genes. Merged 2026-05-15 from former SLOT-MAP.md + ALLELE-MODEL.md.

Auto-derived columns (idx, alleles, slots written, slots gated, calls) come from `research/build-gene-catalog.py` running flow analysis on `FUN_14009f680`. Manual semantic notes are merged into the `notes` column and persist across regenerations (the script preserves them).

Columns:
- **idx**: 0-based position in `vanilla-genes.xml`.
- **scale**: 1 = discrete int allele, 100 = continuous/percent.
- **g0..g3**: the four allele values (vanilla).
- **mut**: mutation % from the XML `m` attribute.
- **codon**: 4-letter ACGT mapping (XML `n` attribute).
- **slots written**: param_1[N] writes that reference
  the temp var receiving the gene value.
- **slots gated**: param_1[N] writes inside an `if`
  block whose condition is the gene's temp var. The gene
  doesn't supply the value but decides *whether* the write
  happens.
- **calls**: line numbers of `FUN_1400a5d20/e00` calls in
  `decompiled/funcs/14009/14009f680_FUN_14009f680.c`.
- **notes**: hand-derived semantic notes (multi-step flows,
  palette buffers, gate-vs-value chains, dead-gene status).



---

## Table of contents

- [Part 1: Conceptual model](#part-1-conceptual-model)
- [Part 2: Engine pipeline + slot map](#part-2-engine-pipeline-slot-map)
- [Part 3: Per-gene reference (all 240 vanilla genes)](#part-3-per-gene-reference-all-240-vanilla-genes)
- [0..10: Body fundamentals](#010-body-fundamentals)
- [11..20: Body shape modifiers](#1120-body-shape-modifiers)
- [21..33: Tail](#2133-tail)
- [34..49: Legs](#3449-legs)
- [50..66: Knee + Arm](#5066-knee-arm)
- [67..71: Upper arm](#6771-upper-arm)
- [72..86: Neck](#7286-neck)
- [87..96: Foot + Hand](#8796-foot-hand)
- [97..117: Head + Eye + Brow](#97117-head-eye-brow)
- [118..126: Ear + Teeth](#118126-ear-teeth)
- [127..140: Mouth + Nose + Antler-precursor](#127140-mouth-nose-antler-precursor)
- [141..159: Antlers](#141159-antlers)
- [160..174: Hat](#160174-hat)
- [175..188: Palette / coloration base](#175188-palette-coloration-base)
- [189..218: Colors + patterns + behavioral](#189218-colors-patterns-behavioral)
- [219..239: Animation signals](#219239-animation-signals)
- [Summary](#summary)
- [Part 4: Helix layout (in-game CRISPR Lab DNA)](#part-4-helix-layout-in-game-crispr-lab-dna)

---

## Part 1: Conceptual model

> Was previously a separate doc (`ALLELE-MODEL.md`). Folded in 2026-05-15 to keep all gene knowledge in one place.


Reference doc: how the gene system actually works in the
binary. Synthesized from decomp findings in
[`VIABILITY.md`](VIABILITY.md). Prerequisite reading
before any mod work that touches genes, alleles, pops,
or breeding.

---

### TL;DR

Three layers stacked on top of each other:

1. **Gene definitions** (engine-wide, 240 fixed slots).
   Each gene has 4 possible allele values + a mutation
   rate + a scale.
2. **Pop weights** (per-species, in pop.xml). Per-pop
   probabilities that each of the 4 alleles is chosen
   when a horse of that pop is born. Weights are
   INVERSE: lower number = more likely.
3. **Per-horse genome** (one per horse, diploid).
   Stores 2 allele indices per gene (mom's pick + dad's
   pick).

Each frame, the renderer evaluates each gene's effect
as a mutation-blended mix of the dominant and recessive
allele values. The resulting floats drive size, color,
limb lengths, tail shape, etc.

---

### Layer 1: gene definitions

Stored in the 240-slot table at `DAT_1403ee4a4`. Each
record is 32 bytes:

| Offset | Size | Field | Default |
|---|---|---|---|
| +0x00 | uint32 | gene index (self-check, must equal slot index) | i |
| +0x04 | uint32 | mutation rate `m` | 100 |
| +0x08 | uint64 | scale `s` | 1 |
| +0x10 | 4 x uint32 | allele values g0, g1, g2, g3 | 0 |

Loaded from `data/genes.xml` by `FUN_1400a3eb0` at
startup. `m`, `s`, and `g0..g3` come from XML
attributes. Vanilla ships ~241 gene definitions filling
the table to capacity.

Think of a gene as a 4-payload enum:

```
gene SIZE:
  m = 100, s = 1
  g0 = 10   (small)
  g1 = 20   (medium)
  g2 = 40   (large)
  g3 = 80   (huge)
```

Numbers above are illustrative. Real gene values come
from `genes.xml` and the engine itself; we have not
mapped every gene's meaning yet (see Q-render-3 in
[`VIABILITY.md`](VIABILITY.md)).

---

### Layer 2: pop weights

Each pop record at `DAT_1403f2fc0 + pop_id * 0x1018`
contains 240 genes x 4 alleles x 4 bytes of weights at
offset +0x28.

```
pop default:
  SIZE:  p0 = 1   p1 = 1   p2 = 1   p3 = 1     (any size equally likely)

pop bx_mini (nested inside default):
  SIZE:  p0 = 1   p1 = 20  p2 = 20  p3 = 20    (almost always picks g0 = small)

pop bx_elephant (nested inside default):
  SIZE:  p0 = 20  p1 = 20  p2 = 20  p3 = 1     (almost always picks g3 = huge)
```

Critical gotcha: **weights are INVERSE.** Higher number
= less likely. p=1 is dominant. p=20 is rare. Same as
the existing
[`CONTENT-MODDING.md`](CONTENT-MODDING.md)
documentation. Confirmed by the JumboDS64 community
guide; engine-side confirmation pending (see
Q-gene-3 in `VIABILITY.md`).

#### Pop inheritance

Per `FUN_1400a5ee0`: child pops **inherit then
override**. When `pop.xml` defines:

```xml
<pop name="default">
  <gene name="SIZE" p0="1" p1="1" p2="1" p3="1" />
  <gene name="COLOR_R" p0="3" p1="3" p2="3" p3="3" />
  <pop name="bx_mini">
    <gene name="SIZE" p0="1" p1="20" p2="20" p3="20" />
  </pop>
</pop>
```

`bx_mini` starts with the FULL parent weight set
(SIZE + COLOR_R + everything else default touches),
then patches only `SIZE`. Authoring rule of thumb:
nest under the closest sensible parent and only
override what makes your pop distinctive.

#### Spawning a new horse

When the game spawns a horse of a given pop:

1. For each of the 240 genes:
2. Randomly pick allele index 0..3 weighted by the
   pop's `1/p0, 1/p1, 1/p2, 1/p3` (inverse weights).
3. Do this TWICE (once for each diploid copy).
4. Store both picks in the horse's 480-byte genome
   block at `horse[0x78]` (one at offset `g`, one
   at offset `g + 240`).

So pop weights determine the SHAPE of the random pick,
not the value. The value comes from the gene
definition's allele payload (g0..g3).

#### Unknown pop name

Hard crash. `FUN_1400a2ed0` panics with
`MessageBoxA(NULL, "pop not found <name>", "Error", 0)`
then `INT 3` aborts. No silent fallback. Misspell a
pop in `pop.xml` or `horsey.tmx` and the game dies
on the spot.

---

### Layer 3: per-horse genome

The **working genome** is inline at `horse + 0x2b8`,
a 480-byte block (2 strands x 240 alleles). This is
what the engine `FUN_14009f680` and consumer
`FUN_1400ab3d0` read (both take `param_2 = horse + 0x2b8`),
and what the breeding combinator `FUN_1400a2d80` writes
into.

There is also a separate heap-allocated 480-byte blob
referenced from `horse[+0x78]`, allocated by
`FUN_14005cf70`/`FUN_14005d190` and freed by
`FUN_14005cd00`. Based on `FUN_14005cf70` populating it
from per-pop initial allele data via `FUN_1400a2ed0`,
this looks like a pop-seed / snapshot blob, not the
live working genome. Treat it as secondary.

Layout (same for both blocks): **diploid pair stored as two 240-byte halves.**

```
horse->genome:
  [0]   maternal allele index for gene 0   (0..3)
  [1]   maternal allele index for gene 1
  ...
  [239] maternal allele index for gene 239
  [240] paternal allele index for gene 0   (0..3)
  [241] paternal allele index for gene 1
  ...
  [479] paternal allele index for gene 239
```

Each byte stores an allele INDEX (0..3, which of g0..g3
to use), not an allele VALUE. The save format actually
allows 3 bits per byte (range 0..6 with -1 sentinel)
giving slack in the save encoding.

#### Save encoding

Per `FUN_14006d470` (write) and `FUN_14006d580` (read):
each diploid pair is bit-packed into one byte:

```
packed_byte = (paternal_allele + 1) << 3 | (maternal_allele + 1)
```

So 480 bytes of in-memory alleles compress to 240
packed bytes per horse on disk. Top 2 bits of each
saved byte are unused.

---

### Per-frame: evaluating a gene's effect

`FUN_1400a5d20` is the diploid evaluator. Called by
`FUN_14009f680` (the gene-effect engine) 293 times per
horse per frame, with literal gene indices spanning
233 of the 240 slots.

Pseudocode:

```rust
fn evaluate_diploid_gene(horse: &Horse, gene_idx: usize) -> f32 {
    let m_allele = horse.genome[gene_idx]       & 0x3;  // maternal pick (0..3)
    let p_allele = horse.genome[gene_idx + 240] & 0x3;  // paternal pick (0..3)

    let dom_idx = max(m_allele, p_allele);
    let rec_idx = min(m_allele, p_allele);

    let dom_value = gene_table[gene_idx].alleles[dom_idx];  // dominant payload
    let rec_value = gene_table[gene_idx].alleles[rec_idx];  // recessive payload

    let m = gene_table[gene_idx].mutation_rate as f32;
    let s = gene_table[gene_idx].scale as f32;

    // DAT_14039ca44 and DAT_14039ca5c are runtime constants.
    let base = DAT_14039ca44;
    let norm = DAT_14039ca5c;

    (base - m / norm) * dom_value + (m / norm) * rec_value
}
```

So the gene's expressed value each frame is a
**mutation-rate-weighted blend** of the two parent
alleles, not just one of them. High mutation rate
shifts the blend toward the recessive allele. Low
mutation rate makes the dominant allele dominate.

#### Why max/min?

The `max(m_allele, p_allele)` = dominant convention is
arbitrary engine choice. `g3` is always more dominant
than `g0`. So if you author allele payloads in
ascending strength (`g0 = small, g3 = huge`) the
engine will lean toward the bigger allele when both
parents disagree. Authoring tip: order alleles
intentionally; the engine treats higher index as
dominant.

---

### Population genetics: live mutation drift

`FUN_1400c0660` (the death handler) mutates the
gene-table mutation rate `m` of specific genes by
**±5 per horse death**. So as horses live and die,
the gene-table itself drifts. Genes whose mutation
rate climbs produce more recessive-leaning
expressions in future generations; genes whose rate
falls become more deterministic.

This is real population genetics in code, not just
config. Implications:

- A long-running save will diverge from the genes.xml
  starting state.
- The XML round-trip serializer at `FUN_1400a4880`
  (which writes table state back out as
  `<gene name="..." m="..." s="..." />`) preserves
  the drifted state somewhere. Need to find where.
- Hot-reloading `genes.xml` would clobber the drift.
  Mod tooling that does this should warn the user.

---

### CRISPR Lab and runtime allele swap

`FUN_1400c1cf0` is the in-game gene inspector / CRISPR
UI. Reads the currently-selected gene's table fields
(scale, name) and the current pop's per-allele weights
for that gene. Lets the player view and (probably)
edit allele picks directly.

`FUN_1400c03a0` is the **allele-renumber sync**: when
alleles X and Y of gene N are reordered (probably for
display sorting or normalization), this function
swaps:

- `gene_table[N].alleles[X]` <-> `gene_table[N].alleles[Y]`
- AND for every pop in the global pop array,
  `pop.weights[N][X]` <-> `pop.weights[N][Y]`

So allele identity is consistent across the whole game
state at all times. This is non-trivial code that we
must NOT break when extending the table.

---

### Breeding (combining two parents)

`FUN_14005d190` is the genome copy function. Takes a
source genome block and copies it byte-by-byte into
another horse's genome block, in 6-byte chunks within
a 240-byte stride loop (so the diploid layout is
preserved).

Plus a version-12 conditional fixup (lines 90+ of
that function) that swaps adjacent bytes when
`*(int*)(param_1 + 0xc) == 0xc`. Probably normalizes
the diploid to put the dominant allele in a canonical
position. Not yet fully understood.

We have NOT yet found the function that computes the
CHILD's genome from two parents (likely an actual
"for each gene, pick one allele from each parent at
random" function). Worth tracking down before
designing extended breeding logic.

To do:


---

### Worked examples

These walk through the math of what actually happens when
the engine evaluates a gene for a horse. All numbers are
illustrative; real allele values come from `genes.xml`.

#### Example 1: homozygous dominant (parents agree on g3)

Setup. Gene `SIZE`:
- m = 100, s = 1, g0 = 10, g1 = 20, g2 = 40, g3 = 80
- horse genome[SIZE] = 3 (maternal pick = g3)
- horse genome[SIZE + 240] = 3 (paternal pick = g3)

Eval. `m_allele = 3, p_allele = 3`. Then
`dom_idx = max(3,3) = 3`, `rec_idx = min(3,3) = 3`. So
`dom_value = rec_value = 80`.

Blend (assume DAT_14039ca44 = 1.0, DAT_14039ca5c = 100):

```
result = (1.0 - 100/100) * 80 + (100/100) * 80
       = 0.0 * 80 + 1.0 * 80
       = 80
```

When parents agree, mutation rate doesn't matter. The
horse expresses the agreed allele cleanly. Makes sense.

#### Example 2: heterozygous (parents disagree, g0 vs g3)

Same gene, but now:
- horse genome[SIZE] = 0 (maternal g0 = small)
- horse genome[SIZE + 240] = 3 (paternal g3 = huge)

Eval. `dom_idx = max(0,3) = 3`, `rec_idx = min(0,3) = 0`.
`dom_value = 80`, `rec_value = 10`.

Blend at vanilla mutation rate m=100:

```
result = (1.0 - 100/100) * 80 + (100/100) * 10
       = 0.0 * 80 + 1.0 * 10
       = 10
```

Wait, that's pure recessive. With m=100 the engine fully
expresses the SMALLER allele. That's counter-intuitive
unless `DAT_14039ca44` is NOT 1.0 in vanilla. The constant
`DAT_14039ca44 - m/s` controls dominance balance. If
vanilla has `DAT_14039ca44 = 2.0` and `DAT_14039ca5c = 100`
then the blend would be `(2 - 1) * dom + 1 * rec = dom + rec`,
giving an additive effect rather than blend.

**Caveat:** the actual vanilla values of `DAT_14039ca44`
and `DAT_14039ca5c` are not yet documented. Worth dumping
them at runtime via the `horsey-mod` HTTP control plane.
The qualitative behavior holds: when parents disagree,
mutation rate decides how much each contributes.

#### Example 3: weight-driven spawn (no genes involved)

Setup. New horse spawning into pop `bx_mini` whose SIZE
weights are `p0=1, p1=20, p2=20, p3=20`.

Inverse weight math: relative probabilities are
`1/p0 : 1/p1 : 1/p2 : 1/p3 = 1.000 : 0.050 : 0.050 : 0.050`.

Sum = 1.150. So allele 0 gets picked
`1.000 / 1.150 = 87%` of the time. The other three each
get `0.050 / 1.150 = 4.3%`.

Result: ~87% of `bx_mini` foals get a "small" allele
from each parent. Probability of a foal being homozygous
small is `0.87 * 0.87 = 76%`. So the pop is
overwhelmingly small but not strictly so. Variation
comes through.

#### Example 4: extreme weight (close to deterministic)

Setup. Pop `bx_giant_strict` with SIZE weights
`p0=255, p1=255, p2=255, p3=1`.

Inverse weights: `0.0039 : 0.0039 : 0.0039 : 1.000`.

Sum = 1.012. Allele 3 gets picked
`1.000 / 1.012 = 98.8%`. Each other allele gets 0.4%.
Probability of homozygous huge: `0.988 * 0.988 = 97.6%`.

Practical takeaway: max weight 255 (uint8) on three
alleles makes the fourth nearly deterministic but not
guaranteed. If you want absolute determinism (every
foal of this pop is huge, no exceptions), you can't get
it through weights alone; you'd need to override the
gene's allele payloads to make all four payloads equal
for that pop.

#### Example 5: drift over generations

Setup. Gene SIZE starts with m=100. Over 100 in-game
horse deaths, `FUN_1400c0660` adjusts SIZE.m by ±5
per death (probably ±5 weighted by some game event,
maybe the dying horse's own SIZE).

If drift averages -5 per death, after 100 deaths
m = 100 - 500 = drops past 0. Probably clamped (the
function probably has bounds). The blend formula
`(base - m/norm) * dom + (m/norm) * rec` shifts:
- High m: rec contribution dominates (recessive
  alleles get expressed more often).
- Low m: dom contribution dominates (cleaner Mendelian
  inheritance).

So a save where lots of horses died with small SIZE
would over time make even heterozygous foals lean
small. Real population genetics, real evolutionary
pressure.

#### Example 6: end-to-end breeding event (the whole picture)

The most-asked question: **how does a foal actually get its 240 genes from two parents?** Here's the whole flow.

**How many genes per horse.** Every horse carries the full **240-gene catalog** (see Part 3). Horses are **diploid**: for each of the 240 genes the horse stores TWO picks, one inherited from mom and one from dad. Each pick is just an index 0..3 (which of the gene's four `g0..g3` values applies to this strand). So:

- **240 genes** per horse (the gene list is universal. Every horse has the same genes).
- **2 picks per gene** (maternal strand + paternal strand).
- **240 + 240 = 480 picks total** stored per horse genome.

Same shape as real biology: 240 gene loci, two alleles per locus, 480 allele picks total.

On disk in `save1.dat` the 240 pairs are stored as ~240 bytes per horse (one byte per gene encodes the PAIR via the `0x09 + rank(s2)*8 + rank(s1)` rank-formula from [`SAVE-FORMAT.md`](SAVE-FORMAT.md)). In the CRISPR Lab UI those 240 byte-pairs render as **20 helices** (Part 4); each helix position shows one gene's diploid pair as two stacked bases (one strand from each parent).

**Setup.** Two parents, picked from the player's stable:

- **Honky Tonk Tonky** (a mare, pop `default`, default-pop horse).
- **Dale** (a stallion, pop `default`, also default-pop).

Each has a 240-gene genome with 480 alleles. We'll trace a foal across THREE genes to keep the table readable, but the same logic applies to all 240.

Maternal (Honky) and paternal (Dale) genomes at three illustrative positions:

| Gene | g0 | g1 | g2 | g3 | Honky's strand A pick | Honky's strand B pick | Dale's strand A pick | Dale's strand B pick |
|---|---|---|---|---|---|---|---|---|
| `SIZE` (helix 6 pos 0, mut=95, scale=100) | 100 | 50 | 35 | 75 | 0 (=100) | 0 (=100) | 0 (=100) | 2 (=35) |
| `OLD_AGE` (helix 0 pos 10, mut=100, scale=1) | 0 | 0 | -1 | 2 | 0 (=0) | 0 (=0) | 3 (=+2) | 0 (=0) |
| `LITTER_SIZE` (helix 0 pos 9, mut=100, scale=1) | 1 | 2 | 3 | 5 | 1 (=2) | 0 (=1) | 2 (=3) | 1 (=2) |

So Honky is `SIZE: 100/100` (homozygous 100, big mom), `OLD_AGE: 0/0` (homozygous neutral aging), `LITTER_SIZE: 2/1` (heterozygous, two-baby litter expressed). Dale is `SIZE: 100/35` (heterozygous big+small), `OLD_AGE: +2/0` (heterozygous, carrying short-life allele), `LITTER_SIZE: 3/2`.

**Step 1: breeding combinator (the part the engine does).** Verified 2026-05-15 in `FUN_1400a2d80` (lines 95511-95571). Called from `FUN_1400b2e30:104367` (child-from-parents setup) with `(parent_a + 0x2b8, parent_b + 0x2b8, child + 0x2b8)` before the engine + consumer re-evaluate the new child:

```text
for strand in 0..2:                                 # child gets 2 strands
    for g in 0..240:
        coin = rand()                               # FUN_1400c6580()
        parent = parent_a if (strand_pick == 0) else parent_b
        child.strand[strand][g] = parent.strand[coin][g]
```

Plus a **linked-inheritance override**: for the gene-index ranges 72..86 (Neck), 97..174 (Head/Eye/Brow/Ear/Teeth/Mouth/Nose/Antlers/Hat), and 183..197 (palette base + colors). Minus exclusions at idx 83 and 107. The picker forces the SAME parent across the whole cluster. So a foal can't get a giraffe head with a tiger jaw. The bitmask `(uVar5 < 0x61 || 0xae < uVar5) && (0xe < uVar5 - 0x48) && (0xe < uVar5 - 0xb7 || ...)` at lines 95541-95551 encodes this. The ranges match the cluster boundaries documented in Part 2's cluster map.

Mutation during breeding (the `m` attribute's runtime role) is still being traced. See Part 1 "Population genetics: live mutation drift" for what `FUN_1400c0660` does to the table across deaths. The child-generation step is straight Mendelian + linked inheritance.

Say the RNG rolls (one coin flip per gene per parent):

| Gene | Honky's contribution | Dale's contribution | Child's diploid pair |
|---|---|---|---|
| `SIZE`        | strand A → 0 (=100) | strand B → 2 (=35) | 0 / 2 |
| `OLD_AGE`     | strand B → 0 (=0)   | strand A → 3 (=+2) | 0 / 3 |
| `LITTER_SIZE` | strand A → 1 (=2)   | strand A → 2 (=3)  | 1 / 2 |

**Step 2: the diploid blend (per-frame engine math).** The engine then evaluates each gene to a single float. Per the formula above:

- `SIZE` 0/2: `dom_idx = max(0,2) = 2`, `rec_idx = min(0,2) = 0`. `dom = 35, rec = 100`. With vanilla `m=95, scale=100`:
  ```
  result = (1 - 95/100) * 35 + (95/100) * 100 = 0.05*35 + 0.95*100 = 1.75 + 95.0 = 96.75
  ```
  Foal expresses **SIZE ≈ 97**. Almost as big as mom; the rare small allele only nudges it down slightly.

- `OLD_AGE` 0/3: `dom_idx = 3`, `rec_idx = 0`. `dom = +2, rec = 0`. With `m=100, scale=1`:
  ```
  result = (1 - 100/1) * 2 + (100/1) * 0 = -99 * 2 + 100 * 0 = -198
  ```
  That blows past the realistic range; the engine clamps internally. Operationally what happens: with `m=100` and `scale=1` the recessive allele FULLY DOMINATES. So foal expresses **OLD_AGE = 0** (the recessive/neutral allele wins). Foal carries the short-life g3 but doesn't express it. And could pass it to its own offspring.

- `LITTER_SIZE` 1/2: `dom_idx = 2`, `rec_idx = 1`. `dom = 3, rec = 2`. `m=100, scale=1`:
  ```
  result = 0 * 3 + 1 * 2 = 2
  ```
  Foal expresses **LITTER_SIZE = 2** (recessive allele wins, again).

**Step 3: the gene engine writes the render buf.** `FUN_14009f680` reads the foal's resolved gene values and writes ~258 slots into a `float[353]` buf (Part 2). `SIZE = 97` feeds the slot-0..3 SQRT formula along with ASPECT, SKINNY, BONES, BONES2, CHEST_SMALL, GIANT_DWARF. The consumer `FUN_1400ab3d0` then copies 23 of those slots directly into the foal's horse-struct fields (`+0x58..+0x2a8`), which the renderer reads each frame.

**Step 4: visible result.** Foal renders as a near-mom-sized horse. Its OLD_AGE is neutral so it ages normally. Litter_size of 2 means when IT eventually breeds, expect 2 babies per litter.

**Big-picture summary.**

```text
+-------------------+        +-------------------+
| Mom: 240 genes    |        | Dad: 240 genes    |
| 480 alleles (dip) |        | 480 alleles (dip) |
+--------+----------+        +----------+--------+
         |                              |
         | breed (Mendelian): for each  |
         | of 240 genes, child gets one |
         | random allele from each      |
         | parent (50/50 strand pick)   |
         v                              v
       +----------------------------------+
       | Child: 240 genes, 480 alleles    |
       | (one maternal + one paternal     |
       |  pick per gene)                  |
       +----------------+-----------------+
                        |
                        | per-frame engine math
                        | (diploid blend per gene)
                        v
       +----------------------------------+
       | 240 resolved gene values         |
       | -> 258 buf-slot writes           |
       | -> 23 horse-struct fields        |
       | -> renderer + physics            |
       +----------------------------------+
```

**Pop weights vs breeding.** Pop weights (`p0..p3`) only matter when a NEW horse spawns into the world (not from breeding). See Example 3/4. Bred foals inherit STRICTLY from their parents' alleles, never from the pop weights. This is why a `freak` pop's spawn weights bias new wild freaks toward weird alleles, but a freak's foal with a default-pop mate produces a hybrid drawn from each parent's actual genome.

**Modder takeaways.**

- To affect ONLY new-spawn horses, edit `pop.xml` per-allele weights.
- To affect ALL horses (incl. existing + bred), edit `genes.xml` allele values (`g0..g3`).
- To affect a single horse already in the game, edit its diploid pair in `save1.dat` (per [`SAVE-FORMAT.md`](SAVE-FORMAT.md)) or use the CRISPR Lab in-game to change one strand at a time.
- To unlock a NEW behavior (e.g. stamina), neither alleles nor pop weights help. The relevant constant is hardcoded in `Horsey.exe`. See [`ENGINE-EXTENSION.md`](ENGINE-EXTENSION.md).

---

### Allele indexing edge cases

#### Allele 0..3 only (no extras)

The `& 0x3` mask in the diploid evaluator means stored
allele indices are masked to 0..3. Save format allows
0..6 storage (3 bits). The extra bits are reserved
slack, not meaningful.

If we store an allele index of 5 in the genome, it
gets masked to 1 at evaluation time. Quietly wrong.

#### Sentinel value -1

Save unpack does `(byte_low & 7) - 1`. So a saved
value of 0 unpacks to -1 (sentinel for "no allele
set"?). Vanilla packing always adds 1 before saving
so 0..3 -> 1..4. The 0 saved value would be unusual
and probably indicates an uninitialized gene.

#### What happens if gene table has fewer alleles than expected

A gene record could in theory have only g0 and g1
defined (g2, g3 = 0). If a horse's allele index is 2
or 3, it reads payload value 0. Probably interpreted
as "no effect" rather than crashing. Worth confirming
via experiment if we ever author genes with fewer
than 4 alleles.

---

### Pop record on-disk layout cheat sheet

| Offset | Size | Contents |
|---|---|---|
| 0x000 | 4 | pop_id |
| 0x004 | 4 | parent_id |
| 0x008 | 32 | name (std::string SSO buffer) |
| 0x028 | 3840 | gene weights: 240 genes x 4 alleles x 4 bytes |
| 0xfa8 | 240 | per-gene secondary block (codon order or "is set" flags) |

For gene `g`, allele `a`:
`weight = pop[0x28 + (g * 4 + a) * 4]`

Pop record total size: 0x1018 = 4120 bytes.

---

### What this enables for modding

Without ANY binary patching:

- **Add a new pop** that picks extreme alleles of
  existing genes. (`bx_elephant` with `SIZE` weight
  `p3=1`, all others `p=20` -> almost every horse
  of that pop gets the huge size payload.)
- **Tweak existing pop weights** to widen or narrow
  a vanilla pop's variety.
- **Edit allele payloads in genes.xml** to change
  the actual numeric outputs (`SIZE g3 = 80 -> 200`
  -> giants get gigantic).

With binary patching (the bestiary expansion project):

- **Add new gene definitions** beyond slot 240
  (extend the table; layered via heap redirect of
  the 7 reader functions).
- **Add new gene-effect logic** for those new genes
  via a trampoline on `FUN_14009f680` writing to
  the per-horse render param array.
- **Persist new alleles in saves** via a sidecar
  `.ext` file keyed by horse ID.

Cannot be done at all without massive rework:

- **Add allele #5 to a gene** (the `*4` indexing is
  baked into pop record layout, save encoding, and
  the diploid evaluator's `& 0x3` mask). Would
  require widening every gene record AND every pop
  record AND the save format simultaneously.

---

## Part 2: Engine pipeline + slot map

> Was previously a separate doc (`SLOT-MAP.md`). Folded in 2026-05-15.


### Pipeline

```
FUN_14009f680(buf, ctx)             // gene engine
   reads horse alleles (240 slots)
   writes ~258 unique slots into buf (float[353])

FUN_1400ab3d0(horse, buf)           // consumer
   reads ~61 of those slots
   writes them into horse struct fields at +0x124..+0x154

renderer / physics                  // downstream
   reads horse-struct fields, produces visible features
```

Only slots in the **consumer-read** subset produce visible
in-game effects. Engine-written slots that the consumer
ignores are dead computation.

### Vanilla genes inventory

240 genes, full list in
[`vanilla-genes.xml`](vanilla-genes.xml). Gene index 0..239
matches XML document order.

#### Cluster map (gene_idx -> feature area)

Vanilla genes are arranged in functional clusters that
match contiguous code blocks inside `FUN_14009f680`.

| Range | Genes | Cluster | What it controls |
|---|---|---|---|
| 0..10 | 11 | **Body fundamentals** | Overall size, scale, body type. Feeds slots 0..3 via the SQRT formula in "Engine internals." `SIZE`, `ASPECT`, `SKINNY`, `BONES`, `BONES2`, `CHEST_BIG`, `CHEST_SMALL`, `GIANT_DWARF`, `MUSCLE_USE`, `QUADRUPED`, `BIPED`. |
| 11..20 | 10 | **Body shape modifiers** | `SPLAY`, `LEG_IN`, `LEG_IN2`, `GUT`, `GUT_IS_UDDER`, `OSTODERM`, `OSTO_SIZE`, `DERRIERE`, `SPEED_FACTOR`, `BREAK_FORCE`. |
| 21..33 | 13 | **Tail** | All `TAIL_*` (size, joints, speed, shape, segments). |
| 34..49 | 16 | **Legs** | `LEG_TYPE`, `LEG_LENGTH`, `LEG_STRETCH*`, `LEG_STRENGTH`, `LEG_JOINT_TYPE`, `LEG_FLEXIBILITY`, `LEG_COUNT`, `LEG_HAS_FOOT`, etc. |
| 50..66 | 17 | **Knee + Arm** | `HAS_KNEE`, `KNEE_MIN`, `KNEE_MAX`, all `ARM_*`, `HAS_ELBOW`. |
| 67..71 | 5 | **Upper arm** | `ELBOW_RANGE`, `UPARM_TAG`, `UPARM_Y`, `UPARM_ANGLE`, `UPARM_GOOFY`. |
| 72..86 | 15 | **Neck** | All `NECK_*` (length, thickness, angle, joints, flexibility) plus a stray `HAS_FOOT`. |
| 87..96 | 10 | **Foot + Hand** | `FOOT_SIZE`, `FOOT_CLOWN`, `FOOT_THICKNESS`, `FOOT_TOE`, `HAND_*`. |
| 97..117 | 21 | **Head + Eye + Brow** | `HEAD_*`, `EYE_*`, `EYEBOX_*`, `BROW_*`, `PUPIL_SIZE`. |
| 118..126 | 9 | **Ear + Teeth** | `EAR_*` (8 genes) + `TEETH_SHAPE`. |
| 127..140 | 14 | **Mouth + Nose + Antler-precursor** | `MOUTH_*`, `JAW`, `TEETH_UPPER*`, `TONGUE*`, `NOSE_*`, `HAS_ANTLERS`. |
| 141..159 | 19 | **Antlers** | `ANTLER_*` (full geometry + colors). |
| 160..174 | 15 | **Hat** | `HAT_*` (size, rake, taper, pom, angles). |
| 175..188 | 14 | **Palette / coloration base** | `BASE_BROWN`, `BASE_BLACK`, `BASE_RED`, `BASE_GREEN`, `BASE_CREAM`, `ALT_BLUE`, `SPOT_YELLOW`, `SKIN_HUE*`, `WHITE`, `WHITE_IS_LETHAL`. |
| 189..218 | 30 | **Colors + patterns + behavioral traits** | `EYE_HUE`, `NOSE_HUE`, `HOOF_COLOR`, `AGOUTI`, `BELLY_ALT`, `SKIN_HEAD`, `SKIN_HANDS`, `RACCOON_EYE`, `PAT_*` (8 pattern genes), behavioral: `RAMPAGE`, `SPINAL_LOCO`, `BRAIN_SPASTIC`, `HIGH_INTELLECT`, `OMNIVORE`, `LITTER_SIZE`, `OLD_AGE`, `LIMP`, `NARCOLEPSY`, `FLU_IMMUNITY`, `TAIL_WAG`, `STIFF_JOINTS`. |
| 219..239 | 21 | **Animation signals** | `L_LEG_*`, `L_ARM_*`, `L_TAIL_*`, `L_NECK_*` (locomotion signals + reaction events), plus `LOCO_SYNC`. |

#### Per-gene engine writes and gates

Authoritative per-gene table (which buf slots each gene writes directly, which it gates via conditionals, plus dead genes marked `_unread_`) lives in [`GENE-CATALOG.md`](GENE-CATALOG.md). This doc is authoritative on the slot side: clusters, slot -> horse-struct mapping, engine internals, modder workflow.

### Buf-slot -> horse-struct field (consumer reads)

Auto-derived from `FUN_1400ab3d0` decomp by
`horsey-mod/research/extract-consumer-map.py`. Reads 62 distinct
buf slots; 23 are direct copies to a horse-struct field,
the rest feed conditionals or intermediate math.

| Buf slot | Horse struct field(s) | Note |
|---|---|---|
| 0 (0x0) | _(reads only)_ | conditional / intermediate |
| 1 (0x1) | _(reads only)_ | conditional / intermediate |
| 2 (0x2) | _(reads only)_ | conditional / intermediate |
| 3 (0x3) | _(reads only)_ | conditional / intermediate |
| 6 (0x6) | _(reads only)_ | conditional / intermediate |
| 7 (0x7) | _(reads only)_ | conditional / intermediate |
| 15 (0xf) | _(reads only)_ | conditional / intermediate |
| 31 (0x1f) | _(reads only)_ | conditional / intermediate |
| 33 (0x21) | _(reads only)_ | conditional / intermediate |
| 37 (0x25) | _(reads only)_ | conditional / intermediate |
| 43 (0x2b) | _(reads only)_ | conditional / intermediate |
| 52 (0x34) | _(reads only)_ | conditional / intermediate |
| 62 (0x3e) | _(reads only)_ | conditional / intermediate |
| 107 (0x6b) | _(reads only)_ | conditional / intermediate |
| 124 (0x7c) | _(reads only)_ | conditional / intermediate |
| 125 (0x7d) | _(reads only)_ | conditional / intermediate |
| 127 (0x7f) | _(reads only)_ | conditional / intermediate |
| 145 (0x91) | _(reads only)_ | conditional / intermediate |
| 166 (0xa6) | _(reads only)_ | conditional / intermediate |
| 170 (0xaa) | _(reads only)_ | conditional / intermediate |
| 187 (0xbb) | _(reads only)_ | conditional / intermediate |
| 188 (0xbc) | _(reads only)_ | conditional / intermediate |
| 208 (0xd0) | _(reads only)_ | conditional / intermediate |
| 210 (0xd2) | _(reads only)_ | conditional / intermediate |
| 211 (0xd3) | _(reads only)_ | conditional / intermediate |
| 227 (0xe3) | _(reads only)_ | conditional / intermediate |
| 228 (0xe4) | _(reads only)_ | conditional / intermediate |
| 230 (0xe6) | _(reads only)_ | conditional / intermediate |
| 243 (0xf3) | _(reads only)_ | conditional / intermediate |
| 248 (0xf8) | _(reads only)_ | conditional / intermediate |
| 249 (0xf9) | _(reads only)_ | conditional / intermediate |
| 251 (0xfb) | _(reads only)_ | conditional / intermediate |
| 258 (0x102) | _(reads only)_ | conditional / intermediate |
| 268 (0x10c) | _(reads only)_ | conditional / intermediate |
| 312 (0x138) | _(reads only)_ | conditional / intermediate |
| 313 (0x139) | +0x58 | direct copy |
| 314 (0x13a) | +0x5c | direct copy |
| 315 (0x13b) | +0x60 | direct copy |
| 316 (0x13c) | +0x64 | direct copy |
| 317 (0x13d) | +0x68 | direct copy |
| 318 (0x13e) | +0x6c | direct copy |
| 319 (0x13f) | +0x70 | direct copy |
| 320 (0x140) | +0x74 | direct copy |
| 321 (0x141) | +0x78 | direct copy |
| 322 (0x142) | +0x7c | direct copy |
| 323 (0x143) | +0x80 | direct copy |
| 324 (0x144) | +0x84 | direct copy |
| 325 (0x145) | +0x88 | direct copy |
| 326 (0x146) | +0x8c | direct copy |
| 327 (0x147) | +0x90 | direct copy |
| 328 (0x148) | +0x94 | direct copy |
| 329 (0x149) | +0x98 | direct copy |
| 330 (0x14a) | +0x9c | direct copy |
| 331 (0x14b) | +0xa0 | direct copy |
| 332 (0x14c) | +0xa4 | direct copy |
| 336 (0x150) | _(reads only)_ | conditional / intermediate |
| 337 (0x151) | _(reads only)_ | conditional / intermediate |
| 347 (0x15b) | _(reads only)_ | conditional / intermediate |
| 349 (0x15d) | +0x254 | direct copy |
| 350 (0x15e) | _(reads only)_ | conditional / intermediate |
| 351 (0x15f) | +0x200 | direct copy |
| 352 (0x160) | +0x2a8 | direct copy |

### Engine internals (slots 0..3): the "horse fundamental size"

Slots 0..3 are computed VERY early in `FUN_14009f680` from a
fixed set of 7 base genes. They aren't directly copied by
the consumer for the most part, but slot 0 is read by
`FUN_1400ab3d0` via `*param_2` (the bare-dereference syntax
our extractor v1 missed; v2 catches it).

Evidence: `decompiled/all_functions.c` lines 94066-94143
(inside `FUN_14009f680`).

```
fVar35 =   2 * gene_0 (SIZE)
         * (gene_3 (BONES) + gene_4 (BONES2) + 1)
         *  gene_5 (CHEST_BIG)
         *  gene_6 (CHEST_SMALL)
         *  gene_7 (GIANT_DWARF)

fVar37 = (gene_6 (CHEST_SMALL) * gene_2 (SKINNY)
          * gene_1 (ASPECT)) / gene_5 (CHEST_BIG)

slot[0] = SQRT(fVar35 * fVar37)
        = SQRT( 2 * SIZE * (BONES+BONES2+1)
              * CHEST_SMALL^2 * SKINNY * ASPECT * GIANT_DWARF )

slot[1] = fVar35 / slot[0]       // derived height / aspect-corrected size
slot[2] = slot[1] / fVar37       // depends on iVar15 (gene_9 = QUADRUPED) branch
slot[3] = fVar35 / slot[0]       // (set in some branches; see line 94137)
```

The conditional branches at lines 94086-94118 select
different formulas based on `local_31c` (gene_10 = BIPED)
and `iVar15` (gene_9 = QUADRUPED). This is why slot 0's
value couples to four genes at once for biped horses vs.
seven for quadrupeds.

**Slot 0's indirect path through the consumer.** The
consumer reads `*param_2` (slot 0) at line 494 and
compares it to `param_2[1]` (slot 1) to drive
`local_2f8 = slot1 <= slot0 && slot1 != slot0`. That
boolean later gates which code path writes which struct
fields. Our slot-0 = 200.0 override flipped this flag,
making the consumer take a different write path that
produced visually wider horses.

**Implication for modding.** If a new gene wants to
adjust overall horse size, the cleanest options are:

1. Add to slot 0 with `mode=add` (not set), so the
   underlying SQRT product is preserved and the comparison
   stays consistent.
2. Pick an unused slot in the consumer's direct-copy set
   (the slots in the table above that map to a horse
   struct field) and target a specific subsystem instead.

Writing `mode=set` to slot 0 with a large value is too
heavy-handed and will produce extreme effects. That's the
giant-baby case from 2026-05-14.

### Vanilla pops (28 species)

Vanilla ships 28 pop definitions in
[`vanilla-pop.xml`](vanilla-pop.xml). Each pop is a named
weight-table over the 240 genes; weights are per-allele
(`p0`..`p3`) and biased by inverse: lower = more likely.

```
default, hay, scratch, fest horse, crazy horse,
appletree, helix, yeast, pepper, freak, jockey,
leprechaun, car, centaur test, human, dachshund,
bear, tiger, moose, alligator, impala, giraffe,
duck, cow, fish, centipede, rabbit, dino
```

Inheritance: every pop inherits from `default` and patches
specific genes by name. The car pop sets `QUADRUPED p2=12`
(extreme bias for quadruped), `LEG_IS_CIRCLE p1=1` (wheels),
extreme `OSTODERM` / `HAT_*` values; the result is a
boxy four-wheeled "horse." See
[`vanilla-pop.xml`](vanilla-pop.xml) for the full template
to imitate when authoring new pops.

### Confirmed visible-effect slots

Empirically verified by setting the slot to an extreme
value via the D5 post-hook and observing in-game.

| Slot | Set value | Visible effect | Set via |
|---|---|---|---|
| 0 | 200.0 | "Full screen width" babies (mated 2 horses, offspring rendered enormously wide). Drives a primary scale parameter; consumer reads `*param_2` (slot 0) and compares with slot 1 to gate which write path runs. | `BX_TEST_SLOT0` set mode (3,3) blend = 200.0 |

#### Per-feature classification of the other 22 direct-copy slots: deliberately deferred

We tried to derive `slot -> visible feature` statically.
What we found:

- Direct field-reader regex (`research/extract-field-readers.py`) pulled 2339 candidate readers across the 23 direct-copy offsets, narrowed by horse-handler fingerprint (>= 3 offsets + one of the rare high offsets `+0x200`/`+0x254`/`+0x2a8`) to 24 candidates, then cross-referenced against `ALL-FUNCTIONS.md`. **None are renderers.** Confirmed handlers are gameplay/UI/debug only (`retire_horse_handler`, `copy_genome_to_clipboard`, `debug_print_population_stats`, etc.).
- Forward-trace from `FUN_1400ab3d0`'s 6 known call sites (2026-05-15) showed every call site is a **regeneration event** (birth, CRISPR, pop-respawn), not a per-frame render call. The consumer writes horse-struct fields persistently; the renderer reads them per-frame in a decoupled path. Forward-tracing leads to event triggers, not the renderer.
- The renderer almost certainly reads through nested pointers (`horse->subsystem->field`) or vtable dispatch into a render subsystem, so the `*(T*)(var + 0xNN)` regex never matches it. Finding it cleanly needs Ghidra struct propagation across the horse type. Hours of skilled RE work.

**Decision: ship with the slot map as-is.** We have gene -> slot (per-gene table) + slot -> horse-struct offset (consumer map) + working D5 trampoline + one confirmed slot. Per-feature classification of the other 22 will be populated as a side effect of bestiary authoring (each new species naturally probes a few slots) rather than enumerated speculatively. See [`FIELD-READERS.md`](FIELD-READERS.md) for the static analysis output.

### Modder workflow

#### To make a new SPECIES (new pop)

The standard vanilla path is to add a `<pop>` block to
`pop.xml`. Inheritance: every pop inherits from
`default` and patches by gene name.

1. Pick the species concept ("clown horse").
2. Find gene clusters that bias toward that concept:
   - For a HEAD-driven oddity, weight up `HEAD_GIANT`
     (idx 104) `p3` for "big-head" allele, weight down
     `HEAD_SQUARE` to bias against the boxy variant.
   - For PATTERN-driven looks, weight `PAT_*` genes
     (idx 199..205) toward your desired spot/perlin
     pattern alleles.
3. Each `<gene name="X" pN="weight">` line sets that
   allele's inverse weight (lower = more likely).
4. Reload via `pop.xml.reload` (TODO: not yet shipped;
   today this requires restart).

#### To make a new VISUAL EFFECT (extended gene)

If vanilla can't express the effect you want, add an
extended gene via our sidecar:

1. Add a `<gene>` entry to
   `<dll_dir>/genes-extended.xml` with `<render slot=N mode=M />`.
2. Reload via `genes.ext.reload` HTTP op (live, no restart).
3. Decide whether to target a known consumer-read slot
   from the table above (visible) or an unused slot
   (dead computation, no effect).
4. Test by setting `horse.ext.default_alleles.set` so
   every horse picks up your effect.
5. Once dialed in, set per-horse alleles via
   `horse.ext.alleles.set` (need stable horse-id, D4.4)
   or fall back to the default-allele path.

#### Which slot to target for which effect

The cluster table above tells you which vanilla genes
*should* feed slots related to that feature area. Cross-
reference with the "Buf-slot -> horse-struct field" table
to confirm the slot is consumer-read.

Worst-case empirical fallback: pick a candidate slot,
write an extreme value with `mode=set`, walk in-game,
observe. The 2026-05-14 giant-baby experiment is the
exemplar.

### What's still unknown

The map is good enough to author content but not 100%
complete. Open gaps:

1. **74 of 240 genes have no engine->slot row** in the
   auto-extracted table. They're processed in conditional
   branches the simple regex can't trace cleanly. Each is
   probably 1-3 slot writes; manual decomp reading would
   resolve.
2. **Conditional formulas.** Slots 0..3 have a BIPED
   branch and a QUADRUPED branch with different formulas;
   the doc shows the common case. Edge species (`car`,
   `helix`, `centipede`) likely hit branches not yet
   traced.
3. **Horse struct field -> visible feature.** We know
   23 buf slots are direct-copied to specific
   `+0xNN` offsets in the horse struct. We don't know
   which renderer code reads which offset to produce
   which visible thing. That's another full decomp pass
   over the render path.
4. **Animation signal genes (idx 219..239).** The L_*
   cluster appears unused in `FUN_14009f680` but is
   referenced by `pop.xml` weights. They likely feed
   into a separate animation system. Not blocking
   visual modding.
5. **CRISPR UI extension** for new genes (D1.8 in
   horsey-mod todo). The UI iterates the gene table to
   show editable names; extended genes 240..479 won't
   appear there until we detour `FUN_1400c1cf0`.

---

## Part 3: Per-gene reference (all 240 vanilla genes)

## 0..10: Body fundamentals

| idx | name | scale | g0 | g1 | g2 | g3 | mut | codon | slots written | slots gated | calls | notes |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 0 | `SIZE` | 100 | 100 | 50 | 35 | 75 | 95 | ATGC | 152 | - | L432, L634 | Body size primary input. Feeds slots 0..3 via SQRT(2*SIZE*(BONES+BONES2+1)*CHEST_SMALL^2*SKINNY*ASPECT*GIANT_DWARF). See SLOT-MAP "Engine internals". |
| 1 | `ASPECT` | 100 | 200 | 310 | 150 | 250 | 95 | GCAT | 343 | - | L438, L632 |   |
| 2 | `SKINNY` | 100 | 100 | 200 | 100 | 75 | 100 | GACT | - | - | L436 | Multi-step input to overall-size SQRT formula (slots 0..3). Lateral thinness factor. |
| 3 | `BONES` | 100 | 0 | -14 | 14 | 0 | 95 | GCAT | - | - | L414 | Skeletal bones count. Adds via (BONES+BONES2+1) term in size formula. Multi-step into slots 0..3. |
| 4 | `BONES2` | 100 | 0 | 16 | -16 | 0 | 60 | TGCA | - | - | L420 | Skeletal bones secondary. Pairs with BONES in (BONES+BONES2+1) of size formula. |
| 5 | `CHEST_BIG` | 100 | 104 | 102 | 108 | 102 | 100 | ATCG | 2, 344 | - | L430, L442 |   |
| 6 | `CHEST_SMALL` | 100 | 95 | 100 | 90 | 95 | 100 | GCTA | 1, 2, 3 | - | L428, L440 |   |
| 7 | `GIANT_DWARF` | 100 | 100 | 66 | 133 | 100 | 100 | GACT | 173, 174 | - | L426 |   |
| 8 | `MUSCLE_USE` | 100 | 100 | 50 | 80 | 100 | 100 | CTAG | 132, 154, 155, 209 | - | L784, L894, L934 |   |
| 9 | `QUADRUPED` | 1 | 1 | 0 | 1 | 0 | 100 | CGAT | 167, 169, 170 | - | L446 |   |
| 10 | `BIPED` | 1 | 0 | 1 | 0 | 1 | 100 | TAGC | - | - | L450 | Toggle. Gates a large block at L454-L518 selecting biped vs quadruped formulas for slots 0..3. |

## 11..20: Body shape modifiers

| idx | name | scale | g0 | g1 | g2 | g3 | mut | codon | slots written | slots gated | calls | notes |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 11 | `SPLAY` | 1 | 0 | 10 | -5 | 45 | 100 | ACTG | 35, 54 | - | L1592, L1766, L2188 |   |
| 12 | `LEG_IN` | 100 | 0 | 18 | 6 | 0 | 50 | CGAT | 33 | - | L1578, L1752 |   |
| 13 | `LEG_IN2` | 100 | 0 | 13 | 0 | 1 | 100 | CGAT | 52 | - | L1574, L1748 |   |
| 14 | `GUT` | 100 | 0 | 25 | 45 | 0 | 100 | TGAC | 4 | - | L578 |   |
| 15 | `GUT_IS_UDDER` | 1 | 0 | 1 | 0 | 2 | 100 | ACGT | 6 | - | L582 |   |
| 16 | `OSTODERM` | 1 | 1 | 0 | 1 | 2 | 100 | GATC | 7 | - | L586 |   |
| 17 | `OSTO_SIZE` | 100 | 30 | 15 | 45 | 45 | 85 | TACG | 8 | 10 | L590 |   |
| 18 | `DERRIERE` | 100 | 0 | 40 | 70 | 10 | 85 | CTGA | 5, 10 | 10 | L602 |   |
| 19 | `SPEED_FACTOR` | 100 | 100 | 30 | 50 | 133 | 75 | GCAT | 133, 134, 154, 155, 350 | - | L808, L952, L3110 |   |
| 20 | `BREAK_FORCE` | 10 | 0 | 54 | 0 | 35 | 100 | GATC | 47, 66 | - | L1620, L1708 |   |

## 21..33: Tail

| idx | name | scale | g0 | g1 | g2 | g3 | mut | codon | slots written | slots gated | calls | notes |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 21 | `TAIL_TAG` | 1 | 3 | 4 | 2 | 1 | 100 | TAGC | 18 | - | L1430 |   |
| 22 | `TAIL_EXISTS` | 1 | 1 | 0 | 1 | 2 | 100 | GCAT | 165, 347 | - | L658 |   |
| 23 | `TAIL_SIZE` | 100 | 100 | 80 | 120 | 140 | 60 | GCAT | 166, 347 | - | L662 |   |
| 24 | `TAIL_SHORT` | 100 | 100 | 50 | 35 | 100 | 100 | CAGT | 347 | - | L674 |   |
| 25 | `TAIL_ASPECT` | 100 | 20 | 10 | 30 | 50 | 90 | AGCT | 166 | - | L668 |   |
| 26 | `TAIL_ANGLE` | 1 | 45 | 90 | 135 | 60 | 100 | GCAT | 16 | - | L1444 |   |
| 27 | `TAIL_JOINT_TYPE` | 1 | 0 | 1 | 0 | 0 | 100 | ATGC | 24 | - | L1448 |   |
| 28 | `TAIL_STIFF` | 1 | 0 | 1 | 0 | 1 | 100 | ATGC | 6 | - | L1452 |   |
| 29 | `TAIL_SPEED` | 10 | 60 | 200 | 60 | 0 | 100 | GCAT | 167, 175, 176 | - | L710 |   |
| 30 | `TAIL_FLEXIBILITY` | 1 | 135 | 90 | 45 | 15 | 100 | GTAC | 26, 27 | - | L1460 |   |
| 31 | `TAIL_SHAPE` | 1 | 2 | 1 | 5 | 6 | 100 | AGTC | 169 | 169, 347 | L680 |   |
| 32 | `TAIL_BOTTOM` | 1 | 0 | 1 | 0 | 0 | 100 | GTCA | 10 | 15, 16, 24, 347 | L1520, L1928 |   |
| 33 | `TAIL_SEGMENTS` | 1 | 3 | 0 | 3 | 5 | 100 | GTCA | 167, 170 | - | L716 |   |

## 34..49: Legs

| idx | name | scale | g0 | g1 | g2 | g3 | mut | codon | slots written | slots gated | calls | notes |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 34 | `LEG_TAG` | 1 | 1 | 2 | 4 | 3 | 100 | ATGC | 37 | - | L1568 |   |
| 35 | `LEG_TYPE` | 1 | 1 | 2 | 0 | 1 | 100 | TACG | 123 | 124, 125, 132 | L730 |   |
| 36 | `LEG_LENGTH` | 100 | 80 | 50 | 120 | 100 | 90 | CATG | 125 | - | L738 |   |
| 37 | `LEG_STRETCH` | 100 | 0 | 14 | -14 | 0 | 60 | GACT | 54, 125, 146, 188 | - | L734, L904 |   |
| 38 | `LEG_STRETCH2` | 100 | 0 | -16 | 16 | 0 | 100 | ATCG | 125, 146 | - | L736, L908 |   |
| 39 | `LEG_STRENGTH` | 100 | 95 | 120 | 80 | 104 | 60 | GCTA | 124, 125, 131, 132 | - | L742, L790 |   |
| 40 | `LEG_HAS_FOOT` | 1 | 1 | 1 | 0 | 0 | 100 | GACT | 35 | - | L758 |   |
| 41 | `LEG_JOINT_TYPE` | 1 | 0 | 1 | 2 | 0 | 100 | AGTC | 43 | - | L1616 |   |
| 42 | `LEG_FLEXIBILITY` | 1 | 30 | 20 | 40 | 50 | 80 | GTCA | 35, 45, 46, 106, 108 | - | L1634, L1664, L1670 |   |
| 43 | `LEG_FLEX_BIAS` | 1 | 15 | 20 | 10 | -10 | 100 | CGAT | 35, 45, 46 | - | L1642, L1662, L1668 |   |
| 44 | `LEG_THRUST_BACK` | 1 | 0 | 1 | 0 | 2 | 100 | GCTA | - | 35, 45, 46, 54 | L1650, L2184 |   |
| 45 | `LEG_IS_CIRCLE` | 1 | 0 | 1 | 0 | 0 | 100 | ATGC | 35 | 208 | L864, L1040 |   |
| 46 | `LEG_COUNT` | 1 | 1 | 1 | 2 | 7 | 100 | CGTA | 31, 37 | - | L1680 |   |
| 47 | `LEG_SKEW` | 100 | 0 | 24 | -16 | 0 | 60 | TCGA | 126 | - | L826 |   |
| 48 | `LEG_PENCIL` | 100 | 0 | 10 | 0 | 0 | 100 | ATGC | 124, 125, 132 | - | L876 |   |
| 49 | `LEG_AND_ARM_LIMP` | 1 | 0 | 0 | 0 | 1 | 100 | TAGC | 11, 15 | 17, 21, 54, 56, 71, 88, 106, 107, 108 | L1624, L1712 |   |

## 50..66: Knee + Arm

| idx | name | scale | g0 | g1 | g2 | g3 | mut | codon | slots written | slots gated | calls | notes |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 50 | `HAS_KNEE` | 1 | 0 | 1 | 0 | 0 | 100 | TCGA | - | - | L832, L848 | Boolean. Gates fVar39 = KNEE_MIN or 0 at L834, and the KNEE_MAX path at L850. Co-drives slot 139 (and slot 132/140 via KNEE_MAX). |
| 51 | `KNEE_MIN` | 1 | 0 | -90 | -15 | 0 | 100 | CGAT | 139 | - | L836 |   |
| 52 | `KNEE_MAX` | 1 | 20 | 90 | 45 | 20 | 100 | TAGC | 132, 140 | - | L852 |   |
| 53 | `ARM_TAG` | 1 | 1 | 2 | 4 | 3 | 100 | GTAC | 56 | - | L1704 |   |
| 54 | `ARM_TYPE` | 1 | 1 | 2 | 0 | 0 | 100 | CGAT | 144 | 146, 153, 224 | L900 |   |
| 55 | `ARM_LENGTH` | 100 | 80 | 50 | 120 | 25 | 90 | ATCG | 146 | - | L910 |   |
| 56 | `ARM_STRETCH` | 100 | 0 | 14 | -14 | 0 | 60 | GACT | _unread_ | _unread_ | - | DEAD. Defined but never read by engine. Removed sibling of LEG_STRETCH. Free slot for sidecar gene repurposing. |
| 57 | `ARM_STRETCH2` | 100 | 0 | -16 | 16 | 0 | 100 | TCAG | _unread_ | _unread_ | - | DEAD. Defined but never read by engine. Removed sibling of LEG_STRETCH2. Free slot. |
| 58 | `ARM_STRENGTH` | 100 | 95 | 120 | 80 | 104 | 60 | ATCG | 145, 152, 153 | - | L914, L936 |   |
| 59 | `ARM_HAS_HAND` | 1 | 1 | 0 | 1 | 0 | 100 | CGTA | 40 | - | L926 |   |
| 60 | `ARM_JOINT_TYPE` | 1 | 0 | 1 | 2 | 0 | 100 | GCTA | 62 | - | L1736 |   |
| 61 | `ARM_FLEXIBILITY` | 1 | 30 | 20 | 40 | 30 | 100 | ACTG | 54, 64, 65 | - | L1778, L1796, L1800 |   |
| 62 | `ARM_FLEX_BIAS` | 1 | 15 | 20 | 10 | 0 | 100 | GCTA | 54, 64, 65 | - | L1786, L1794, L1802 |   |
| 63 | `ARM_FORWARD` | 1 | -20 | 0 | 60 | 40 | 100 | CTGA | 54 | - | L1768 |   |
| 64 | `ARM_SKEW` | 100 | 0 | 20 | -20 | 0 | 100 | TCGA | 147 | - | L966 |   |
| 65 | `ARM_NODE_SCALE` | 100 | 100 | 70 | 130 | 100 | 50 | CTGA | 55 | - | L1700 |   |
| 66 | `HAS_ELBOW` | 1 | 0 | 1 | 0 | 0 | 100 | CATG | - | - | L972 | Boolean. Same pattern as HAS_KNEE: gates whether ELBOW_RANGE writes its slot, else 0.0. |

## 67..71: Upper arm

| idx | name | scale | g0 | g1 | g2 | g3 | mut | codon | slots written | slots gated | calls | notes |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 67 | `ELBOW_RANGE` | 1 | 30 | 90 | 10 | 30 | 100 | CTAG | 160, 161 | - | L976 |   |
| 68 | `UPARM_TAG` | 1 | 0 | 2 | 1 | 4 | 100 | ATCG | 17, 54, 71, 74 | - | L1832 |   |
| 69 | `UPARM_Y` | 100 | 30 | 10 | 30 | 50 | 80 | CTAG | - | - | L1850 | Read at L1850 into auVar47 for upper-arm Y placement. Indirect into upper-arm slots. |
| 70 | `UPARM_ANGLE` | 1 | 0 | 30 | -30 | -45 | 100 | GCAT | 72 | - | L1864 |   |
| 71 | `UPARM_GOOFY` | 1 | 0 | 1 | 2 | 3 | 100 | ACGT | - | 17, 21, 89, 90 | L1892 |   |

## 72..86: Neck

| idx | name | scale | g0 | g1 | g2 | g3 | mut | codon | slots written | slots gated | calls | notes |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 72 | `NECK_TAG` | 1 | 4 | 3 | 1 | 2 | 100 | AGTC | 106, 107, 110, 188, 347 | - | L1960 |   |
| 73 | `NECK_TYPE` | 1 | 1 | 1 | 2 | 0 | 100 | TACG | 186 | 106, 107, 188 | L1096, L1114, L1976, L2046 |   |
| 74 | `NECK_LENGTH` | 100 | 60 | 70 | 90 | 30 | 90 | ATGC | 33, 188 | - | L1100 |   |
| 75 | `NECK_GIRAFFE` | 100 | 110 | 0 | 85 | 120 | 90 | TCAG | 188 | - | L1104 |   |
| 76 | `NECK_THICKNESS` | 100 | 95 | 110 | 120 | 80 | 60 | CGTA | 187 | - | L1108 |   |
| 77 | `NECK_ANGLE` | 1 | 45 | 30 | 60 | 75 | 90 | TACG | 108 | - | L1952 |   |
| 78 | `NECK_COCK` | 1 | 0 | 30 | 20 | -25 | 100 | CGAT | 108 | - | L1956 |   |
| 79 | `NECK_JOINT_TYPE` | 1 | 1 | 0 | 2 | 0 | 100 | TGCA | 116 | - | L2090 |   |
| 80 | `NECK_FLEXIBILITY` | 1 | 23 | 10 | 40 | 0 | 100 | GTCA | 108, 118, 119 | - | L2108, L2114, L2126 |   |
| 81 | `NECK_FLEX_BIAS` | 1 | -8 | 0 | -25 | 30 | 100 | GATC | 108, 118, 119 | - | L2106, L2112, L2134 |   |
| 82 | `NECK_SLOUCH` | 100 | 0 | 50 | 20 | 0 | 60 | CTGA | 107 | 71, 106, 108 | L1994 |   |
| 83 | `NECK_ONTOP` | 100 | 0 | 50 | 70 | 20 | 100 | GTCA | - | 71, 106, 107, 108 | L458, L1970 |   |
| 84 | `NECK_STIFF` | 1 | 0 | 1 | 0 | 1 | 100 | CATG | 29 | - | L2094 |   |
| 85 | `NECK_SPEED` | 10 | 60 | 25 | 50 | 10 | 100 | AGCT | 196, 197 | - | L1134 |   |
| 86 | `HAS_FOOT` | 1 | 1 | 0 | 1 | 0 | 100 | TACG | 51 | - | L992 |   |

## 87..96: Foot + Hand

| idx | name | scale | g0 | g1 | g2 | g3 | mut | codon | slots written | slots gated | calls | notes |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 87 | `FOOT_SIZE` | 100 | 0 | 20 | 12 | 30 | 60 | GTAC | 132, 194, 195, 209, 220 | - | L768, L998, L1014 |   |
| 88 | `FOOT_CLOWN` | 100 | 0 | 30 | 0 | 0 | 100 | GTAC | 209 | - | L1008 |   |
| 89 | `FOOT_THICKNESS` | 100 | 20 | 15 | 30 | 7 | 80 | TCAG | 211 | - | L1018 |   |
| 90 | `FOOT_TOE` | 100 | 100 | 0 | 50 | 100 | 100 | AGCT | 12, 54, 132, 194, 195, 210, 219, 224 | - | L770, L1022 |   |
| 91 | `FOOT_IS_CIRCLE` | 1 | 0 | 1 | 0 | 0 | 100 | GACT | - | - | L868, L1042 | Boolean. Gates foot-shape branches at L868 and L1042. Co-drives foot geometry slots. |
| 92 | `FOOT_BACKWARDS` | 1 | 0 | 1 | 0 | 2 | 100 | AGCT | - | - | L1048 | Boolean. Gates foot orientation block at L1048. |
| 93 | `HAS_HAND` | 1 | 0 | 1 | 0 | 1 | 100 | CGTA | 54 | - | L1052 |   |
| 94 | `HAND_WIDTH` | 100 | 0 | 7 | 20 | 0 | 100 | GACT | 219 | - | L1062 |   |
| 95 | `HAND_LENGTH` | 100 | 20 | 30 | 15 | 20 | 90 | CGAT | 221 | - | L1066 |   |
| 96 | `HAND_FINGER` | 100 | 0 | 100 | 0 | 50 | 80 | CTGA | 223 | - | L1076 |   |

## 97..117: Head + Eye + Brow

| idx | name | scale | g0 | g1 | g2 | g3 | mut | codon | slots written | slots gated | calls | notes |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 97 | `HEAD_SIZE` | 100 | 100 | 50 | 133 | 75 | 95 | GCTA | - | - | L1146 | L1146 fVar40 = gene; L1148 fVar37 = (HEAD_THICK_SKULL + HEAD_SIZE) * scale-product. Feeds head sizing slots indirectly. |
| 98 | `HEAD_THICK_SKULL` | 100 | 0 | 20 | 0 | 0 | 100 | TGAC | 228 | - | L1144 |   |
| 99 | `HEAD_X_GROWTH` | 100 | 0 | 5 | 10 | -5 | 100 | ACGT | 227, 228 | - | L1158 |   |
| 100 | `HEAD_Y_GROWTH` | 100 | 0 | 5 | -5 | 0 | 100 | TACG | 228 | - | L1182 |   |
| 101 | `HEAD_ASPECT` | 100 | 200 | 175 | 250 | 300 | 85 | TCAG | - | - | L1154 | Fallback at L1154 when HEAD_SQUARE (gene 102) is 0. Multi-step into head aspect slots. |
| 102 | `HEAD_SQUARE` | 100 | 0 | 150 | 100 | 0 | 100 | CTAG | - | - | L1150 | L1150 read; if 0 the code falls back to HEAD_ASPECT (gene 101) at L1154. Drives head aspect/square slots. |
| 103 | `HEAD_HAS_BACK` | 1 | 11 | 0 | 0 | 1 | 100 | GTCA | 57 | - | L1224 |   |
| 104 | `HEAD_GIANT` | 100 | 100 | 200 | 180 | 100 | 90 | CTAG | 228 | - | L1142 |   |
| 105 | `HEAD_SHRUNK` | 100 | 100 | 70 | 50 | 100 | 90 | CATG | - | 347 | L1140, L3040 |   |
| 106 | `HEAD_JOINTED` | 1 | 0 | 1 | 0 | 0 | 100 | CATG | - | - | L1126 | Boolean. Gates head joint behavior at L1126. |
| 107 | `HEAD_CHIMERA` | 1 | 0 | 1 | 0 | 0 | 100 | ATCG | _unread_ | _unread_ | - | DEAD. Defined but never read by engine. Removed feature placeholder. Free slot. |
| 108 | `EYE_STYLE` | 1 | 1 | 2 | 1 | 0 | 100 | CATG | 235 | - | L1190 |   |
| 109 | `BUGEYE` | 1 | 0 | 1 | 0 | 2 | 100 | GACT | - | 58, 237, 238 | L1194, L1266 |   |
| 110 | `EYEBOX_X` | 100 | 33 | 0 | 50 | 15 | 90 | AGCT | 236 | - | L1198 |   |
| 111 | `EYEBOX_Y` | 100 | -100 | 0 | -50 | -25 | 100 | CGTA | 237, 239 | - | L1204 |   |
| 112 | `EYEBOX_SIZE` | 100 | 25 | 15 | 33 | 50 | 60 | ATGC | 238 | - | L1208 |   |
| 113 | `EYE_SIZE` | 100 | 50 | 75 | 125 | 50 | 100 | ACTG | 239 | - | L1230 |   |
| 114 | `PUPIL_SIZE` | 100 | 66 | 80 | 40 | 40 | 100 | CAGT | 240 | - | L1248 |   |
| 115 | `HAS_PUPIL` | 1 | 1 | 0 | 0 | 0 | 100 | ATCG | - | - | L1236 | Boolean. Gates pupil geometry block at L1236. |
| 116 | `BROW_SIZE` | 100 | 0 | 150 | 125 | 0 | 100 | GATC | 241 | - | L1256 |   |
| 117 | `BROW_SLANT` | 1 | 0 | -15 | 15 | 0 | 100 | GTAC | 238, 242 | - | L1260 |   |

## 118..126: Ear + Teeth

| idx | name | scale | g0 | g1 | g2 | g3 | mut | codon | slots written | slots gated | calls | notes |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 118 | `EAR_STYLE` | 1 | 1 | 2 | 0 | 0 | 100 | TGCA | 243 | - | L1286 |   |
| 119 | `EAR_SHAPE` | 1 | 2 | 1 | 4 | 2 | 100 | CGAT | 244 | - | L1294 |   |
| 120 | `EAR_FLOP` | 1 | 0 | 30 | 60 | 200 | 100 | CTAG | 245 | - | L1290 |   |
| 121 | `EAR_X` | 100 | 0 | 100 | 50 | 0 | 90 | TAGC | 246 | - | L1306 |   |
| 122 | `EAR_SIZE` | 100 | 20 | 30 | 10 | 40 | 70 | TCGA | 248, 249 | - | L1312 |   |
| 123 | `EAR_ASPECT` | 100 | 100 | 250 | 300 | 100 | 100 | ATCG | 249 | - | L1316 |   |
| 124 | `EAR_SLANT` | 100 | 0 | 100 | 50 | -33 | 70 | GACT | 250 | - | L1320 |   |
| 125 | `EAR_INTERIOR` | 100 | 5 | 0 | 0 | 0 | 100 | TAGC | 251 | - | L1334 |   |
| 126 | `TEETH_SHAPE` | 1 | 0 | 1 | 2 | 3 | 100 | TCGA | 252 | - | L1026, L1338 |   |

## 127..140: Mouth + Nose + Antler-precursor

| idx | name | scale | g0 | g1 | g2 | g3 | mut | codon | slots written | slots gated | calls | notes |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 127 | `HAS_MOUTH` | 1 | 1 | 1 | 0 | 1 | 100 | TCGA | - | 253, 254 | L1352 |   |
| 128 | `MOUTH_Y` | 100 | 70 | 84 | 50 | 100 | 80 | CGAT | 255 | - | L1342 |   |
| 129 | `MOUTH_SIZE` | 100 | 20 | 30 | 10 | 40 | 70 | CTGA | 253, 254 | - | L1346 |   |
| 130 | `JAW` | 100 | 0 | 15 | -8 | -13 | 50 | CAGT | 257 | - | L1362 |   |
| 131 | `TEETH_UPPER` | 1 | 1 | 0 | 0 | 0 | 100 | GATC | 264 | - | L1366 |   |
| 132 | `TEETH_UPPER2` | 1 | 1 | 0 | 0 | 0 | 100 | CATG | 264 | - | L1368 |   |
| 133 | `TONGUE` | 100 | 0 | 40 | 60 | 0 | 100 | CGAT | 258 | - | L1384 |   |
| 134 | `TONGUE_SEGS` | 1 | 0 | 1 | 2 | 0 | 100 | ACGT | 259 | - | L1388 |   |
| 135 | `NOSE_STYLE` | 1 | 1 | 2 | 3 | 0 | 100 | GTCA | 261 | - | L1392 |   |
| 136 | `NOSE_INNY` | 1 | 0 | 1 | 0 | 0 | 100 | GCTA | - | - | L1412 | Boolean. Gates nose-style variant at L1412. |
| 137 | `NOSE_Y` | 100 | 0 | 100 | 50 | 0 | 90 | CTAG | 263, 264 | - | L1396 |   |
| 138 | `NOSE_SIZE` | 100 | 10 | 5 | 20 | 100 | 70 | AGCT | - | - | L1402 | Read at L1402 into fVar38; contributes to nose-size composite expression downstream. |
| 139 | `NOSE_INTERIOR` | 100 | 0 | 100 | 50 | 0 | 100 | ATGC | 265 | - | L1426 |   |
| 140 | `HAS_ANTLERS` | 1 | 1 | 0 | 1 | 1 | 100 | CTGA | - | 268, 290 | L2402, L2940 |   |

## 141..159: Antlers

| idx | name | scale | g0 | g1 | g2 | g3 | mut | codon | slots written | slots gated | calls | notes |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 141 | `ANTLER_X` | 1 | 1 | 0 | 2 | 1 | 100 | TGAC | 266 | - | L2198 |   |
| 142 | `ANTLER_W` | 100 | 15 | 12 | 8 | 12 | 100 | TACG | 268 | - | L2206 |   |
| 143 | `ANTLER_H` | 100 | 65 | 45 | 100 | 25 | 80 | TACG | 269 | - | L2210 |   |
| 144 | `ANTLER_TAPER` | 100 | 0 | 100 | 50 | 100 | 100 | CGAT | 270 | - | L2214 |   |
| 145 | `ANTLER_POM` | 100 | 0 | 150 | 200 | 100 | 100 | CTGA | 271 | - | L2218 |   |
| 146 | `ANTLER_COLOR` | 1 | 2 | 8 | 1 | 3 | 100 | ACGT | 275 | - | L2224 |   |
| 147 | `POM_COLOR` | 1 | 2 | 0 | 1 | 17 | 100 | GCTA | 276 | - | L2238 |   |
| 148 | `POM_USECOLOR` | 1 | 1 | 0 | 0 | 0 | 100 | GTAC | - | - | L2228 | Boolean. Gates pom color branch at L2228. |
| 149 | `ANTLER_REC` | 1 | 2 | 1 | 3 | 0 | 100 | TAGC | 277 | - | L2246 |   |
| 150 | `ANTLER_REC2` | 1 | 2 | 1 | 3 | 0 | 100 | CTGA | 278 | - | L2250 |   |
| 151 | `ANTLER_FLIP` | 1 | 1 | 0 | 0 | 0 | 100 | TACG | 69 | - | L2254 |   |
| 152 | `ANTLER_MOD` | 1 | 3 | 2 | 1 | 3 | 100 | TCAG | 289 | - | L2298 |   |
| 153 | `ANTLER_SCALEH` | 100 | 100 | 75 | 40 | 100 | 80 | GCTA | 285 | - | L2258 |   |
| 154 | `ANTLER_SCALEW` | 100 | 100 | 75 | 50 | 100 | 100 | TCGA | 283, 284 | - | L2262 |   |
| 155 | `ANTLER_ANGLE` | 1 | 45 | -45 | -25 | 25 | 100 | GATC | 280 | - | L2270 |   |
| 156 | `ANTLER_ANGLE2` | 1 | 45 | -45 | 90 | -90 | 100 | ACTG | 281 | - | L2274 |   |
| 157 | `ANTLER_ANGLE_RAND` | 1 | 0 | 5 | 45 | 15 | 100 | GTAC | 282 | - | L2278 |   |
| 158 | `ANTLER_T1` | 100 | 0 | 100 | 40 | 25 | 100 | CGAT | 287 | - | L2282 |   |
| 159 | `ANTLER_T2` | 100 | 100 | 40 | 0 | 25 | 100 | ATGC | 288 | - | L2286 |   |

## 160..174: Hat

| idx | name | scale | g0 | g1 | g2 | g3 | mut | codon | slots written | slots gated | calls | notes |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 160 | `HAT_EXISTS` | 1 | 1 | 0 | 0 | 0 | 100 | ACTG | - | - | L2306 | Boolean. At L2306-2320 gates whether HAT_SIZE (gene 161) value or 0.0 lands in slot 290. Co-drives slot 290. |
| 161 | `HAT_SIZE` | 100 | 60 | 40 | 100 | 20 | 85 | CATG | 290, 291 | - | L2316, L2946 |   |
| 162 | `HAT_RAKE` | 100 | 0 | 25 | -15 | 0 | 100 | AGTC | 267 | - | L2202 |   |
| 163 | `HAT_ASPECT` | 100 | 100 | 300 | 200 | 100 | 85 | ATGC | 291, 315 | - | L2322 |   |
| 164 | `HAT_TAPER` | 100 | 0 | 100 | 50 | 0 | 100 | TGCA | 292 | - | L2326 |   |
| 165 | `HAT_POM` | 100 | 0 | 25 | 50 | 0 | 100 | TGAC | 293, 298 | - | L2334 |   |
| 166 | `HAT_POM_IS_LID` | 1 | 0 | 1 | 0 | 0 | 100 | TAGC | - | 293 | L2330 |   |
| 167 | `HAT_CLONE` | 100 | 0 | 33 | 66 | 0 | 100 | CGTA | 294 | - | L2352 |   |
| 168 | `HAT_BACK_SCALE` | 100 | 100 | 0 | 60 | 100 | 100 | TAGC | 307 | - | L2368 |   |
| 169 | `HAT_FRONT_SCALE` | 100 | 100 | 0 | 60 | 100 | 100 | CGTA | 308 | - | L2374 |   |
| 170 | `HAT_BACK_ANGLE` | 1 | 45 | 90 | 120 | 60 | 75 | ACGT | 302 | - | L2380 |   |
| 171 | `HAT_FRONT_ANGLE` | 1 | -45 | -90 | -120 | -60 | 100 | CGAT | 303 | - | L2384 |   |
| 172 | `HAT_ANGLE_RAND` | 1 | 0 | 15 | 45 | 15 | 100 | TCGA | 304 | - | L2388 |   |
| 173 | `HAT_FLIP` | 1 | 0 | 1 | 0 | 0 | 100 | TACG | 75 | - | L2364 |   |
| 174 | `HAT_T` | 100 | 0 | 100 | 40 | 0 | 100 | GTAC | 309, 310, 314, 315 | - | L2392 |   |

## 175..188: Palette / coloration base

| idx | name | scale | g0 | g1 | g2 | g3 | mut | codon | slots written | slots gated | calls | notes |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 175 | `BASE_BROWN` | 1 | 0 | 1 | 2 | 0 | 100 | ATCG | - | - | L2412 | Allele selector into base-color palette via FUN_1400c6df0(_, 4) at L2414 plus DAT_1403daXXX color constants. Multi-step into color slots downstream. |
| 176 | `BASE_BLACK` | 1 | 0 | 1 | 0 | 1 | 100 | TGCA | - | 347 | L2734, L3050 |   |
| 177 | `BASE_RED` | 1 | 0 | 1 | 2 | 3 | 100 | GTCA | - | - | L2416 | Same palette-selector mechanism as BASE_BROWN (allele index into color constants). |
| 178 | `BASE_GREEN` | 1 | 0 | 1 | 2 | 3 | 70 | TCAG | - | - | L2422 | Same palette-selector; gated by GREEN_KNOCKOUT at L2420 (only read when GREEN_KNOCKOUT == 0). |
| 179 | `GREEN_KNOCKOUT` | 1 | 0 | 1 | 0 | 0 | 100 | CAGT | - | - | L2418 | Boolean. Gates whether BASE_GREEN (gene 178) contributes: `if (iVar17 == 0)` at L2420 wraps the BASE_GREEN read. |
| 180 | `BASE_CREAM` | 100 | 0 | 100 | 0 | 0 | 50 | AGCT | - | - | L2546 | Continuous palette blend input at L2546 (fVar36). Feeds cream-color mixing into downstream palette buffer. |
| 181 | `ALT_BLUE` | 1 | 0 | 1 | 2 | 3 | 100 | TAGC | - | 315 | L2556 |   |
| 182 | `SPOT_YELLOW` | 1 | 0 | 1 | 0 | 1 | 100 | TGCA | - | - | L2578 | Boolean. Gates yellow-spot palette branch at L2578. |
| 183 | `SKIN_HUE` | 1 | 0 | 1 | 2 | 3 | 100 | CGAT | _unread_ | _unread_ | - | DEAD. Defined but never read by engine. Possibly orphaned palette gene. Free slot. |
| 184 | `SKIN_HUE2` | 1 | 0 | 1 | 2 | 3 | 100 | TAGC | _unread_ | _unread_ | - | DEAD. Same as SKIN_HUE: never read by engine. Free slot. |
| 185 | `SWAP_BASE_SPOT` | 1 | 0 | 1 | 0 | 1 | 100 | ATCG | - | 312, 313, 314 | L2664 |   |
| 186 | `SWAP_ALT_SPOT` | 1 | 0 | 1 | 0 | 1 | 100 | TGCA | 317 | 314, 315 | L2680 |   |
| 187 | `WHITE` | 1 | 1 | 0 | 0 | 0 | 100 | TAGC | 313 | 314, 315 | L2616 |   |
| 188 | `WHITE_IS_LETHAL` | 1 | 0 | 1 | 0 | 0 | 100 | AGCT | 313 | - | L2618 | Real-horse genetics analogue: white-coat horses die. Setting all four alleles to 0 removes the lethal mechanic entirely. |

## 189..218: Colors + patterns + behavioral

| idx | name | scale | g0 | g1 | g2 | g3 | mut | codon | slots written | slots gated | calls | notes |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 189 | `EYE_HUE` | 1 | 36 | 237 | 153 | 198 | 100 | GCTA | - | 347 | L2726, L3084 |   |
| 190 | `NOSE_HUE` | 1 | 0 | 1 | 2 | 3 | 100 | GACT | - | 347 | L3018 |   |
| 191 | `HOOF_COLOR` | 1 | 0 | 1 | 2 | 0 | 100 | CTAG | - | - | L2702 | L2702 reads gene, L2704 maps to palette index, L2706 `param_1[0x13d] = local_318[iVar20]` writes slot 317. Also seeds neighboring color slots 318..332 from DAT_1403daXXX constants. |
| 192 | `AGOUTI` | 1 | 1 | 0 | 0 | 1 | 100 | ATGC | - | 137, 158, 179, 200, 215, 225, 230, 232, 312 | L2738 |   |
| 193 | `BELLY_ALT` | 1 | 0 | 1 | 2 | 1 | 100 | TACG | 83 | 137, 158, 215, 225 | L2786, L2802, L2902 |   |
| 194 | `SKIN_HEAD` | 1 | 0 | 1 | 0 | 2 | 100 | GCAT | - | 200, 230, 232, 312 | L2846, L2856 |   |
| 195 | `SKIN_HANDS` | 1 | 0 | 1 | 0 | 2 | 100 | GCAT | - | 136, 137, 157, 158, 178, 179, 215, 225 | L2866, L2874 |   |
| 196 | `FOOT_IS_HOOF` | 1 | 0 | 1 | 0 | 1 | 100 | GACT | - | 215 | L1028, L2838 |   |
| 197 | `RACCOON_EYE` | 1 | 0 | 1 | 2 | 0 | 100 | GCAT | 231, 252 | 347 | L1186, L3092 |   |
| 198 | `EAR_COMP` | 1 | 0 | 0 | 2 | 1 | 100 | GTCA | 233, 243 | 233 | L1324 |   |
| 199 | `TAIL_ALT` | 1 | 0 | 1 | 2 | 0 | 100 | CGTA | - | 179 | L2818, L2828 |   |
| 200 | `PAT_SPLIT` | 100 | 0 | 100 | 65 | 0 | 100 | CGAT | 333 | - | L2894 |   |
| 201 | `PAT_BELLY` | 100 | 100 | 50 | 33 | 75 | 100 | ACTG | 15, 334, 347 | - | L1506, L2898 |   |
| 202 | `PAT_STRIPE` | 100 | 0 | 90 | 51 | 0 | 100 | CTAG | 336 | - | L2906 |   |
| 203 | `PAT_SPOT` | 100 | 0 | 90 | 51 | 0 | 100 | ACGT | 337 | - | L2910 |   |
| 204 | `PAT_PERLIN` | 100 | 0 | 100 | 60 | 0 | 100 | TCAG | 340 | - | L2918 |   |
| 205 | `PAT_PERLIN2` | 100 | 0 | 100 | 60 | 0 | 100 | GTCA | 341, 350 | 347 | L2922, L3066 |   |
| 206 | `PAT_PERLIN_SIZE` | 1 | 8 | 2 | 4 | 4 | 100 | GACT | 342, 350 | - | L2926 |   |
| 207 | `RAMPAGE` | 1 | 0 | 0 | 0 | 1 | 100 | GATC | - | - | L3100 | Boolean. Conditional at L3100 (`if (param_1[0xfc] == 4.2039e-45 && RAMPAGE != 0)`) gates a behavioral-effect block. |
| 208 | `SPINAL_LOCO` | 1 | 0 | 1 | 0 | 2 | 100 | CTGA | - | 134, 347, 350 | L2954, L3126 |   |
| 209 | `BRAIN_SPASTIC` | 1 | 0 | 1 | 2 | 0 | 100 | TGAC | _unread_ | _unread_ | - | DEAD. Behavioral, never read by engine. Likely unfinished. Free slot. |
| 210 | `HIGH_INTELLECT` | 1 | 0 | 1 | 0 | 1 | 100 | CTAG | - | 347 | L2930 |   |
| 211 | `OMNIVORE` | 1 | 0 | 1 | 0 | 0 | 100 | CATG | 87 | - | L3170 |   |
| 212 | `LITTER_SIZE` | 1 | 1 | 2 | 3 | 5 | 100 | CTAG | 322, 349 | - | L3166 | Babies per breeding. Bump alleles to 5/8/10/15 to drastically cut breeding upkeep sessions. |
| 213 | `OLD_AGE` | 1 | 0 | 0 | -1 | 2 | 100 | TACG | 351 | - | L3174 | Aging modifier per horse. g3=+2 dies faster, g2=-1 lives longer. Default pop spawns only g0=0 (neutral baseline). `human` pop spawns g3 (line 1536 of pop.xml); `freak` pop mostly g2/g3 (line 2685). Caveat: very large negative values risk instant death if the base lifespan is small. Test with -5 first. |
| 214 | `LIMP` | 1 | 0 | 1 | 0 | 2 | 100 | AGTC | 132, 194, 195 | 347 | L764, L2964 | g1/g3 give limping severity. Set all to 0 to remove the trait. |
| 215 | `NARCOLEPSY` | 1 | 0 | 0 | 1 | 0 | 100 | TCGA | - | 347 | L2972 | g2=1 means "has narcolepsy". Default pop has p0=1 (no narcolepsy). Some pops (line 604, 2687 of pop.xml) have narcoleptic alleles. Set g2=0 globally to remove the trait. |
| 216 | `FLU_IMMUNITY` | 1 | 0 | 0 | 0 | 1 | 100 | CATG | _unread_ | _unread_ | - | DEAD. Behavioral, never read by engine. Likely unfinished. Free slot. Theoretical mod: setting all alleles to 1 would grant universal immunity if the engine ever wires it up. |
| 217 | `TAIL_WAG` | 1 | 1 | 0 | 0 | 0 | 100 | CTGA | - | 347 | L2982 |   |
| 218 | `STIFF_JOINTS` | 100 | 0 | 18 | 50 | 0 | 100 | CGAT | 26, 27, 45, 46, 64, 65, 82, 83, 100, 101, 118, 119 | - | L3136 | Probably reduces joint flexibility/movement. Multiplies 12 joint-flex slots simultaneously (tail, legs, arms, neck flex bias). |

## 219..239: Animation signals

| idx | name | scale | g0 | g1 | g2 | g3 | mut | codon | slots written | slots gated | calls | notes |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 219 | `L_LEG_SIGNAL` | 1 | 1 | 1 | 1 | 2 | 100 | GTCA | 38 | - | L1596 |   |
| 220 | `L_LEG_FTOB_REACT` | 1 | 1 | 2 | 1 | 3 | 100 | TCAG | 39 | - | L1600 |   |
| 221 | `L_LEG_FTOB_EVENT` | 1 | 3 | 1 | 2 | 4 | 100 | GATC | 41 | - | L1604 |   |
| 222 | `L_LEG_BTOF_REACT` | 1 | 2 | 1 | 2 | 3 | 100 | ACGT | 40 | - | L1608 |   |
| 223 | `L_LEG_BTOF_EVENT` | 1 | 2 | 3 | 1 | 4 | 100 | TGAC | 42 | - | L1612 |   |
| 224 | `L_ARM_SIGNAL` | 1 | 2 | 2 | 2 | 1 | 100 | CGAT | 57 | - | L1716 |   |
| 225 | `L_ARM_FTOB_REACT` | 1 | 2 | 1 | 2 | 3 | 100 | ACGT | 58 | - | L1720 |   |
| 226 | `L_ARM_FTOB_EVENT` | 1 | 3 | 1 | 2 | 4 | 100 | TGAC | 60 | - | L1724 |   |
| 227 | `L_ARM_BTOF_REACT` | 1 | 1 | 2 | 1 | 3 | 100 | GATC | 59 | - | L1728 |   |
| 228 | `L_ARM_BTOF_EVENT` | 1 | 2 | 3 | 1 | 4 | 100 | CATG | 61 | - | L1732 |   |
| 229 | `L_TAIL_SIGNAL` | 1 | 3 | 1 | 2 | 4 | 100 | ACTG | 19 | - | L1544 |   |
| 230 | `L_TAIL_FTOB_REACT` | 1 | 0 | 1 | 3 | 2 | 100 | CGAT | 20 | - | L1548 |   |
| 231 | `L_TAIL_FTOB_EVENT` | 1 | 1 | 2 | 3 | 4 | 100 | TCGA | 22 | - | L1552 |   |
| 232 | `L_TAIL_BTOF_REACT` | 1 | 0 | 1 | 3 | 2 | 100 | GTCA | 21 | - | L1556 |   |
| 233 | `L_TAIL_BTOF_EVENT` | 1 | 2 | 1 | 3 | 4 | 100 | ATCG | 23 | - | L1560 |   |
| 234 | `L_NECK_SIGNAL` | 1 | 4 | 1 | 2 | 3 | 100 | TGAC | 111 | - | L2070 |   |
| 235 | `L_NECK_FTOB_REACT` | 1 | 0 | 1 | 4 | 2 | 100 | GTAC | 112 | - | L2074 |   |
| 236 | `L_NECK_FTOB_EVENT` | 1 | 1 | 2 | 3 | 4 | 100 | CATG | 114 | - | L2078 |   |
| 237 | `L_NECK_BTOF_REACT` | 1 | 0 | 1 | 4 | 2 | 100 | TCAG | 113 | - | L2082 |   |
| 238 | `L_NECK_BTOF_EVENT` | 1 | 2 | 1 | 3 | 4 | 100 | TCAG | 115 | - | L2086 |   |
| 239 | `LOCO_SYNC` | 1 | 0 | 1 | 0 | 0 | 100 | CTGA | - | - | L1690 | Boolean. Gates a locomotion-signal branch at L1690. |

## Summary

- 184 genes drive a slot directly
- 22 genes only gate slot writes
- 27 genes are read but neither (likely flow through 2+ vars)
- 7 genes are never read by FUN_14009f680

## Part 4: Helix layout (in-game CRISPR Lab DNA)

> Sourced from [`hikazey/horseygamegm`](https://github.com/hikazey/horseygamegm) (Horsey Genome Mapper, MIT). They reverse-engineered the gene-to-helix-position table directly from the executable. Independent confirmation of our 240-gene catalog AND adds the user-facing in-game DNA layout we don't have on the engine side.

### How 240 genes map onto 20 helices

The 20 helices are just **UI buckets** the dev chose to organize the 240 genes for the in-game CRISPR Lab. Each helix is one X-shape with two strands; **each position on a helix is one gene**; the two strands at that position are the gene's two diploid picks (maternal + paternal).

The 240 genes are NOT split evenly across the 20 helices. Different helices hold different counts (8 to 16 genes each). Per-helix counts:

```
helix:  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
genes: 10 13 13 15 11  8 11  8 11 11 13 15 13 11 11 13 15 11 11 16   = 240 total
```

(Sums verified independently in [`hikazey/horseygamegm`](https://github.com/hikazey/horseygamegm) and [`ZyonixGaming/crispr`](https://github.com/ZyonixGaming/crispr)'s `FIXED_LENGTHS` array.)

The bucketing is **thematic**. The dev grouped related genes onto the same helix so the CRISPR Lab UI reads coherently. Quick tour:

| Helix | Theme | Example genes |
|---|---|---|
| 0 | Skeleton-fundamentals | BONES, BONES2, OSTODERM, GIANT_DWARF |
| 1 | Belly / behavior triggers | GUT, LITTER_SIZE, OLD_AGE, LIMP |
| 2 | Flex / strength | LEG_FLEXIBILITY, TAIL_SPEED, ARM_STRENGTH |
| 3 | Joints | KNEE, ELBOW, STIFF_JOINTS, joint types |
| 4 | Counts / tags | LEG_COUNT, ARM_HAS_HAND, NECK_SLOUCH |
| 5 | Limb posture | QUADRUPED, BIPED, UPARM_* |
| 6 | Torso + neck | ASPECT, SKINNY, CHEST_*, NECK_* |
| 7 | Tail geometry | TAIL_TAG/EXISTS/SIZE/SHAPE/WAG |
| 8 | Leg + arm shape | LEG_LENGTH/STRETCH/STRENGTH, ARM_* |
| 9 | Foot + hand | FOOT_*, HAND_*, SKIN_HANDS |
| 10 | Head | HEAD_*, EYEBOX_*, SKIN_HEAD |
| 11 | Eyes + ears | EYE_*, BROW_*, EAR_* |
| 12 | Mouth + nose | TEETH_*, NOSE_*, MOUTH_*, FLU_IMMUNITY |
| 13 | Antlers (group A) | ANTLER_X/W/H/TAPER/COLOR, POM_* |
| 14 | Antlers (group B) | ANTLER_REC/FLIP/ANGLE/T1/T2 |
| 15 | Hat | HAT_* |
| 16 | Base coloration | BASE_BROWN/BLACK/RED/GREEN/CREAM, WHITE |
| 17 | Patterns + agouti | AGOUTI, PAT_SPLIT/STRIPE/SPOT/PERLIN |
| 18 | Behavior + locomotion signals | NARCOLEPSY, SPEED_FACTOR, RAMPAGE, L_*_SIGNAL |
| 19 | Locomotion reactions/events | L_LEG_FTOB_REACT, L_ARM_BTOF_EVENT, etc |

So the 240 genes -> 20 helices mapping is just **a labeled list of 20 sub-lists** of gene names. The dev wrote it into the binary; we read it out. Nothing magical about the helices. They're a presentation layer for the player to find and edit genes in groups.

The full per-helix gene list is in the table below.

### In-game CRISPR Lab workflow (critical UI fact)

**Yes, all 240 genes are visible** in the CRISPR Lab. **But you have to navigate through 20 separate helix displays** to reach them all. Each X-shape on screen = one helix = one of those 20 sub-lists = 8 to 16 gene positions on each of its two strands.

The vanilla workflow:

1. Sequence the horse at the CRISPR Lab. You get the genome readout.
2. Pick which helix you want (1 of 20).
3. View that helix's X-shape: 8 to 16 stacked positions visible at once, two bases per position (the diploid pair, mat strand + pat strand).
4. Edit one base on one strand to change one allele pick.
5. Want to touch another gene? It may live on a different helix entirely. Navigate to that helix and repeat.

That friction is exactly why the prior-art tools exist:

- [`hikazey/horseygamegm`](https://github.com/hikazey/horseygamegm) flattens all 20 helices into one searchable view so you don't have to remember which helix `OLD_AGE` is on (helix 1, position 10) or `WHITE_IS_LETHAL` (helix 5, position 7). The tool runs out-of-game next to your screen.
- [`ZyonixGaming/crispr`](https://github.com/ZyonixGaming/crispr) (`biohack.html` + `dna-encoder.js`) lets you paste a 40-line genome (2 strands x 20 helices, one line each) and round-trip to a shareable URL. Confirms that "20 helix displays" is just how the dev chose to lay out the underlying 240-gene array. The same data, different representation.

In-game color coding for bases: **A = yellow**, **T = red**, **C = blue**, **G = green**. Which base picks which allele depends on each gene's `n` codon-order attribute (e.g. `n="ATGC"` means base A picks allele g0, T picks g1, G picks g2, C picks g3). See Part 1 (Conceptual model) for the diploid blend formula that turns those picks into a single rendered value.

### Helix to gene table

| Helix | Genes (top to bottom, position 0 first) |
|---|---|
| 0 | `BONES`, `BONES2`, `OSTODERM`, `OSTO_SIZE`, `GIANT_DWARF`, `TAIL_BOTTOM`, `LEG_STRETCH2`, `ARM_STRETCH2`, `HEAD_THICK_SKULL`, `NECK_STIFF` |
| 1 | `GUT`, `GUT_IS_UDDER`, `DERRIERE`, `LEG_IS_CIRCLE`, `FOOT_IS_CIRCLE`, `TONGUE`, `TONGUE_SEGS`, `BELLY_ALT`, `PAT_BELLY`, `LITTER_SIZE`, `OLD_AGE`, `OMNIVORE`, `LIMP` |
| 2 | `MUSCLE_USE`, `TAIL_STIFF`, `LEG_FLEXIBILITY`, `LEG_FLEX_BIAS`, `TAIL_FLEXIBILITY`, `TAIL_SPEED`, `LEG_AND_ARM_LIMP`, `ARM_STRENGTH`, `ARM_FLEXIBILITY`, `ARM_FLEX_BIAS`, `NECK_FLEXIBILITY`, `NECK_FLEX_BIAS`, `BRAIN_SPASTIC` |
| 3 | `SPLAY`, `LEG_IN`, `LEG_IN2`, `TAIL_ANGLE`, `TAIL_JOINT_TYPE`, `LEG_JOINT_TYPE`, `HAS_KNEE`, `KNEE_MIN`, `KNEE_MAX`, `ARM_JOINT_TYPE`, `HAS_ELBOW`, `ELBOW_RANGE`, `NECK_JOINT_TYPE`, `HEAD_JOINTED`, `STIFF_JOINTS` |
| 4 | `LEG_TAG`, `LEG_HAS_FOOT`, `LEG_COUNT`, `LEG_THRUST_BACK`, `ARM_TAG`, `ARM_HAS_HAND`, `NECK_TAG`, `NECK_SLOUCH`, `NECK_ONTOP`, `BREAK_FORCE`, `EAR_X` |
| 5 | `QUADRUPED`, `BIPED`, `UPARM_TAG`, `UPARM_Y`, `UPARM_GOOFY`, `ARM_FORWARD`, `UPARM_ANGLE`, `WHITE_IS_LETHAL` |
| 6 | `ASPECT`, `SKINNY`, `CHEST_BIG`, `CHEST_SMALL`, `NECK_TYPE`, `NECK_LENGTH`, `NECK_GIRAFFE`, `NECK_THICKNESS`, `NECK_ANGLE`, `NECK_COCK` |
| 7 | `TAIL_TAG`, `TAIL_EXISTS`, `TAIL_SIZE`, `TAIL_SHORT`, `TAIL_ASPECT`, `TAIL_SHAPE`, `TAIL_SEGMENTS`, `TAIL_WAG` |
| 8 | `LEG_TYPE`, `LEG_LENGTH`, `LEG_STRETCH`, `LEG_SKEW`, `LEG_STRENGTH`, `LEG_PENCIL`, `ARM_TYPE`, `ARM_LENGTH`, `ARM_STRETCH`, `ARM_SKEW`, `ARM_NODE_SCALE` |
| 9 | `HAS_FOOT`, `FOOT_SIZE`, `FOOT_CLOWN`, `FOOT_THICKNESS`, `FOOT_TOE`, `FOOT_BACKWARDS`, `HAS_HAND`, `HAND_WIDTH`, `HAND_LENGTH`, `HAND_FINGER`, `SKIN_HANDS` |
| 10 | `HEAD_SIZE`, `HEAD_X_GROWTH`, `HEAD_Y_GROWTH`, `HEAD_ASPECT`, `HEAD_SQUARE`, `HEAD_HAS_BACK`, `HEAD_GIANT`, `HEAD_SHRUNK`, `HEAD_CHIMERA`, `EYEBOX_X`, `EYEBOX_Y`, `EYEBOX_SIZE`, `SKIN_HEAD` |
| 11 | `EYE_STYLE`, `BUGEYE`, `EYE_SIZE`, `PUPIL_SIZE`, `HAS_PUPIL`, `BROW_SIZE`, `BROW_SLANT`, `EYE_HUE`, `EAR_STYLE`, `EAR_SHAPE`, `EAR_SIZE`, `EAR_ASPECT`, `EAR_SLANT`, `EAR_INTERIOR`, `EAR_FLOP` |
| 12 | `TEETH_SHAPE`, `HAS_MOUTH`, `MOUTH_Y`, `MOUTH_SIZE`, `JAW`, `TEETH_UPPER`, `TEETH_UPPER2`, `NOSE_STYLE`, `NOSE_INNY`, `NOSE_Y`, `NOSE_SIZE`, `NOSE_INTERIOR`, `FLU_IMMUNITY` |
| 13 | `HAS_ANTLERS`, `ANTLER_X`, `ANTLER_W`, `ANTLER_H`, `ANTLER_TAPER`, `ANTLER_POM`, `ANTLER_COLOR`, `POM_COLOR`, `POM_USECOLOR`, `HAT_POM`, `HAT_POM_IS_LID` |
| 14 | `ANTLER_REC`, `ANTLER_REC2`, `ANTLER_FLIP`, `ANTLER_MOD`, `ANTLER_SCALEH`, `ANTLER_SCALEW`, `ANTLER_ANGLE`, `ANTLER_ANGLE2`, `ANTLER_ANGLE_RAND`, `ANTLER_T1`, `ANTLER_T2` |
| 15 | `HAT_EXISTS`, `HAT_SIZE`, `HAT_RAKE`, `HAT_ASPECT`, `HAT_TAPER`, `HAT_CLONE`, `HAT_BACK_SCALE`, `HAT_FRONT_SCALE`, `HAT_BACK_ANGLE`, `HAT_FRONT_ANGLE`, `HAT_ANGLE_RAND`, `HAT_FLIP`, `HAT_T` |
| 16 | `BASE_BROWN`, `BASE_BLACK`, `BASE_RED`, `BASE_GREEN`, `GREEN_KNOCKOUT`, `BASE_CREAM`, `ALT_BLUE`, `SPOT_YELLOW`, `SKIN_HUE`, `SKIN_HUE2`, `SWAP_BASE_SPOT`, `SWAP_ALT_SPOT`, `WHITE`, `NOSE_HUE`, `HOOF_COLOR` |
| 17 | `AGOUTI`, `FOOT_IS_HOOF`, `COON_EYE`, `EAR_COMP`, `TAIL_ALT`, `PAT_SPLIT`, `PAT_STRIPE`, `PAT_SPOT`, `PAT_PERLIN`, `PAT_PERLIN2`, `PAT_PERLIN_SIZE` |
| 18 | `NARCOLEPSY`, `SPEED_FACTOR`, `NECK_SPEED`, `RAMPAGE`, `SPINAL_LOCO`, `HIGH_INTELLECT`, `L_LEG_SIGNAL`, `L_ARM_SIGNAL`, `L_TAIL_SIGNAL`, `L_NECK_SIGNAL`, `LOCO_SYNC` |
| 19 | `L_LEG_FTOB_REACT`, `L_LEG_FTOB_EVENT`, `L_LEG_BTOF_REACT`, `L_LEG_BTOF_EVENT`, `L_ARM_FTOB_REACT`, `L_ARM_FTOB_EVENT`, `L_ARM_BTOF_REACT`, `L_ARM_BTOF_EVENT`, `L_TAIL_FTOB_REACT`, `L_TAIL_FTOB_EVENT`, `L_TAIL_BTOF_REACT`, `L_TAIL_BTOF_EVENT`, `L_NECK_FTOB_REACT`, `L_NECK_FTOB_EVENT`, `L_NECK_BTOF_REACT`, `L_NECK_BTOF_EVENT` |

Notes:
- 240 genes spread across 20 helices.
- The `SIZE` gene has no explicit helix-position assignment in the executable. The Genome Mapper team speculates it fills Helix 6 position 0 by default and evaluates at baseline (95) independently.
- Both strands at the same position store independent allele picks; the diploid blend in Part 1 combines them.## Part 5: Per-gene semantic descriptions (community-sourced)

> Sourced from [`alexjthomson/horsey-crispr`](https://github.com/alexjthomson/horsey-crispr) (`index.html`, `GENE_DESCRIPTIONS` constant). 153 hand-written descriptions of what each gene does in-game, with the best/worst base for behavior- and stat-relevant genes. Many cite the [Horsey Game wiki at horseygame.miraheze.org](https://horseygame.miraheze.org) - community-verified knowledge we should incorporate where it doesn't conflict with our decomp findings.

Confidence note: these descriptions are community wiki + reading the gene tables, NOT direct decomp citations. Treat as **medium confidence** unless cross-validated by our gene engine trace (Part 2).

| Gene | Description |
|---|---|
| `NARCOLEPSY` | Horse randomly falls asleep when idle if nonzero. Keep A, T, or C to avoid random sleep; G is the only narcoleptic value. |
| `RAMPAGE` | Rampage/aggression state value. Wiki mapping places C as active value 1; A, T, and G are 0. During rampage, locomotion signals may be overridden and the horse may fight, bolt, and flee. |
| `HIGH_INTELLECT` | Enables progression to genius behaviour. T and G are active; A and C are inactive. Required for philosophical/refusal states. |
| `BRAIN_SPASTIC` | Applies random positional jitter each tick, causing twitching and erratic movement. A is the strongest spasm value, G is mild, T/C are none. When active, it may suppress visible old-age perturbation effects. |
| `WHITE_IS_LETHAL` | If active and WHITE coat is expressed in a foal, a lethal check may be applied at birth. G is the active lethal-white value according to the wiki table. |
| `FLU_IMMUNITY` | Grants immunity to the flu mechanic. G is immune; A/T/C are susceptible. This appears tied to the sickness/immunity mechanic sometimes referred to as Sweetie. |
| `LIMP` | Affects gait asymmetry. C produces the strong limp value, G the slight limp value, A/T are normal. Likely worsens with age. |
| `LEG_AND_ARM_LIMP` | Applies limp to all limbs simultaneously instead of just an asymmetric gait. C is active in the wiki table. |
| `OMNIVORE` | Enables carnivorous/omnivorous behaviour. A is active in the wiki table; T/C/G are inactive. When active, the horse may chase and eat NPCs or other horses instead of grazing normally. |
| `LITTER_SIZE` | Directly controls number of offspring per birth. A=3, T=2, C=1, G=5. G is the high-litter allele. |
| `SPINAL_LOCO` | Controls locomotion mode: 0 = legs only, 1 = mild spinal undulation, 2 = full serpentine/worm-like movement. A gives the maximum serpentine mode; C/G are safest for normal racing movement. |
| `LOCO_SYNC` | Global locomotion synchronisation flag. T enables coordinated limb timing; A/C/G leave limbs free-running, which can produce chaotic motion. |
| `BREAK_FORCE` | Controls stamina/rest drain behaviour. T or G gives 0, which may help speed because lower values reduce braking/rest pressure. |
| `MUSCLE_USE` | Global body-wide force multiplier used throughout movement physics. C/G give maximum output; higher values give more power but can make movement more erratic. |
| `STIFF_JOINTS` | Reduces joint flexibility. A is the stiffest value in the wiki table; T/C are 0 and G is moderate. |
| `OSTODERM` | Adds bony skin plates/osteoderms. Related to OSTO_SIZE, which controls their scale. |
| `TAIL_BOTTOM` | Controls tail attachment/bottom setting visually and appears to serve as an internal structural anchor/sentinel in game data. |
| `NECK_STIFF` | Disables or reduces neck flexibility. A and G are stiff values; T/C are flexible values. May suppress NECK_FLEXIBILITY and related neck motion. |
| `GUT_IS_UDDER` | Transforms the body mesh into an udder-like shape by offsetting ventral geometry. Visual effect only. |
| `GIANT_DWARF` | Applies a body scale preset: A=66 dwarf, C=133 giant, T/G=100 normal. Stacks with other body proportion genes. |
| `WHITE` | Activates white coat expression. T is active in the wiki table. If WHITE_IS_LETHAL is also active, white foals may die at birth. |
| `AGOUTI` | Restricts pigment to the extremities, producing a bay-like pattern with darker points and lighter body/belly regions. |
| `COON_EYE` | Applies a dark eye-mask marking. A is strongest, C is partial, T/G are off. |
| `EAR_COMP` | Applies alternate/complementary colour to the ears. C is the strongest value, A is lower, T/G are off. |
| `SWAP_BASE_SPOT` | Swaps the base coat colour with the spot/pattern colour, inverting the colour distribution. |
| `SWAP_ALT_SPOT` | Swaps the alternate colour layer with the spot colour layer. Can combine with SWAP_BASE_SPOT. |
| `OLD_AGE` | Applies progressive physical degradation over time through visible body-coordinate perturbations. C=-1, G=2, A/T=0. Retirement age itself appears hardcoded. |
| `TAIL_ALT` | Selects between different prebuilt tail meshes. This is a mode selector, not a continuous adjustment. |
| `TAIL_SHAPE` | Controls tail curvature by bending the currently selected tail mesh. Higher values produce stronger curve. |
| `TAIL_ASPECT` | Controls tail thickness/roundness in cross-section. Lower values make it flatter/thinner; higher values thicker/rounder. |
| `OSTO_SIZE` | Controls spike size if dorsal spikes/osteoderms are present. Most relevant when OSTODERM is active. |
| `CHEST_SMALL` | Affects body size and chest shape. Likely complements or opposes CHEST_BIG depending on expression. |
| `SPEED_FACTOR` | Primary movement speed multiplier. T=133 is the highest-value allele for speed-focused builds. |
| `LEG_STRENGTH` | Controls leg force output. C=120 is the highest-value allele for raw leg force; useful for racing if stable locomotion is preserved. |
| `LEG_LENGTH` | Controls leg length. T=120 is the longest-leg allele and can improve stride length. |
| `HEAD_SIZE` | Controls head scale. Values are additive across both strands: A=75, T=133, C=50, G=100. |
| `EYE_STYLE` | Selects eye type/style variant. Treated as a discrete style selector rather than a continuous physical parameter. |
| `BUGEYE` | Controls eye protrusion. T=2 is most bulging, A=1 is partial, C/G are flat. |
| `EYE_SIZE` | Controls eye size. Values are additive across both strands: A=50, T=125, C=75, G=50. |
| `PUPIL_SIZE` | Controls pupil diameter. A=80 is largest; T/G=40 are smallest; C=66 is mid-sized. |
| `LEG_IS_CIRCLE` | Changes leg geometry into a circular/wheel-like form. T is active. |
| `FOOT_IS_CIRCLE` | Changes foot geometry into a circular/wheel-like form. A is active. |
| `HAS_MOUTH` | Controls whether a mouth exists. G disables the mouth; A/T/C keep it present. |
| `TEETH_SHAPE` | Selects tooth form/style. May affect whether the horse behaves more like a herbivore, carnivore, or omnivore in addition to visible tooth shape. |
| `LEG_COUNT` | Controls number of legs. A=7 is the high-leg-count setting. |
| `HEAD_ASPECT` | Controls the aspect ratio of the head. Works alongside HEAD_SIZE. |
| `HEAD_GIANT` | Additional head enlargement modifier. A/T are large; C/G are normal. |
| `HEAD_SHRUNK` | Additional head reduction modifier. T=50 is most shrunken, A=70 partial, C/G normal. |
| `HEAD_X_GROWTH` | Directional scaling along head X axis. T narrows, C/G widen. |
| `HEAD_Y_GROWTH` | Directional scaling along head Y axis. A increases, C compresses, T/G neutral. |
| `HEAD_SQUARE` | Biases the head toward a square/block-like form. T is strongest, A partial, C/G off. |
| `HEAD_HAS_BACK` | Controls rear/back-of-head geometry. G=11 is extended, A=1 is present, T/C are off. |
| `HEAD_CHIMERA` | Enables mixed or blended head structure. T is active. |
| `EYEBOX_X` | Controls horizontal eye-box placement/spacing. |
| `EYEBOX_Y` | Controls vertical eye-box offset. |
| `EYEBOX_SIZE` | Controls the size of the eye socket region containing the eyes. |
| `HAS_PUPIL` | Toggles pupils. A is active; T/C/G disable pupils. |
| `BROW_SIZE` | Controls brow ridge size. A/T are prominent; C/G are off. |
| `BROW_SLANT` | Controls brow ridge angle. A and T tilt in opposite directions. |
| `EYE_HUE` | Controls primary eye colour/hue. |
| `EAR_STYLE` | Selects discrete ear type/style. |
| `EAR_SHAPE` | Controls general ear form within the selected style. |
| `EAR_SIZE` | Controls overall ear scale. |
| `EAR_ASPECT` | Controls ear aspect ratio. |
| `EAR_SLANT` | Controls ear angle/tilt relative to the head. |
| `EAR_INTERIOR` | Controls inner-ear detail. T is active. |
| `EAR_FLOP` | Controls how much the ears droop or flop downward. G is very floppy. |
| `NECK_FLEXIBILITY` | Controls how freely the neck can bend during movement. C is high, G/A/T are lower depending on desired stiffness. |
| `NECK_FLEX_BIAS` | Directional bias for neck bending. |
| `ARM_FLEXIBILITY` | Controls how freely the arms/front limbs bend. |
| `ARM_FLEX_BIAS` | Directional bias for arm bending. |
| `LEG_FLEXIBILITY` | Controls how freely the legs bend during locomotion. |
| `LEG_FLEX_BIAS` | Directional bias for leg bending. |
| `TAIL_FLEXIBILITY` | Controls tail bending range. G is highest, C is lowest. |
| `TAIL_STIFF` | Binary/low-range modifier that reduces or disables tail flexibility. T and C are stiff values. |
| `TAIL_SPEED` | Controls tail movement speed. C=200 is fastest; T=0 is still. |
| `ARM_STRETCH` | Applies stretching to arm length beyond base ARM_LENGTH. |
| `LEG_STRETCH` | Applies stretching to leg length beyond base LEG_LENGTH. |
| `ARM_SKEW` | Applies positional/angular skew to arms. |
| `LEG_SKEW` | Applies positional/angular skew to legs. |
| `ARM_NODE_SCALE` | Controls scaling of internal arm segments/nodes. |
| `LEG_TYPE` | Selects leg structural type/configuration. |
| `ARM_TYPE` | Selects arm structural type/configuration. |
| `HAS_FOOT` | Toggles whether feet are present. T/C present, A/G absent. |
| `FOOT_SIZE` | Controls foot size. |
| `FOOT_THICKNESS` | Controls how thick or bulky feet are. |
| `FOOT_TOE` | Controls toe size/prominence. |
| `FOOT_BACKWARDS` | Reverses/flips foot orientation. T=2, G=1. |
| `HAS_HAND` | Toggles whether hands are present on arms. A/G present, T/C absent. |
| `HAND_WIDTH` | Controls horizontal hand size. |
| `HAND_LENGTH` | Controls hand length. |
| `HAND_FINGER` | Controls finger length/count/prominence. |
| `SKIN_HANDS` | Controls whether hands use skin-like rendering/material. |
| `SKIN_HEAD` | Controls whether head uses skin-like rendering/material. |
| `BASE_BROWN` | Controls contribution of brown pigment to base coat colour. |
| `BASE_BLACK` | Controls contribution of black pigment to base coat colour. |
| `BASE_RED` | Controls contribution of red pigment to base coat colour. |
| `BASE_GREEN` | Controls contribution of green pigment to base coat colour. |
| `GREEN_KNOCKOUT` | Suppresses/removes green pigment from final coat colour. A is active. |
| `BASE_CREAM` | Adds cream/light pigment into base coat colour. G=100 is active. |
| `ALT_BLUE` | Controls blue tint in alternate/secondary colour layers. |
| `SPOT_YELLOW` | Controls yellow pigmentation in spot/pattern regions. |
| `SKIN_HUE` | Controls primary skin hue. |
| `NOSE_HUE` | Controls nose colour independently of overall skin tone. |
| `HOOF_COLOR` | Controls colour of hooves or hoof-like structures. |
| `PAT_SPLIT` | Controls split between coat colour regions. |
| `PAT_STRIPE` | Controls stripe pattern intensity/presence. |
| `PAT_SPOT` | Controls spot pattern intensity/presence. |
| `PAT_PERLIN` | Applies noise-based coat patterning. |
| `PAT_PERLIN_SIZE` | Controls scale of Perlin/noise patterns. |
| `TAIL_JOINT_TYPE` | Selects tail joint type. |
| `LEG_JOINT_TYPE` | Selects leg joint type and articulation. |
| `ARM_JOINT_TYPE` | Selects arm/front-limb joint type. |
| `NECK_JOINT_TYPE` | Selects neck joint type. |
| `HEAD_JOINTED` | Controls whether head is jointed or rigidly fixed. A is active. |
| `HAS_KNEE` | Toggles knee joint presence. C is active. |
| `KNEE_MIN` | Controls minimum knee angle limit. |
| `KNEE_MAX` | Controls maximum knee angle limit. |
| `HAS_ELBOW` | Toggles elbow joint presence. A is active. |
| `ELBOW_RANGE` | Controls elbow angular range. |
| `BIPED` | Enables bipedal locomotion mode. A/C are active according to the wiki table. |
| `QUADRUPED` | Enables quadrupedal locomotion mode. A/C are active according to the wiki table. |
| `TAIL_EXISTS` | Controls whether a tail is present. C disables; A/G present; T has value 2. |
| `LEG_HAS_FOOT` | Controls whether legs terminate with feet. A/G present; T/C absent. |
| `ARM_HAS_HAND` | Controls whether arms terminate with hands. T/C present; A/G absent. |
| `FOOT_IS_HOOF` | Switches feet to hoof-like structures. A/T active; C/G off. |
| `UPARM_Y` | Controls vertical placement of upper arms relative to the body. |
| `EAR_X` | Controls horizontal ear placement relative to head center. |
| `LEG_TAG` | Selects leg style/type preset. |
| `ARM_TAG` | Selects arm/front-limb style/type preset. |
| `NECK_TAG` | Selects neck style/type preset. |
| `TAIL_TAG` | Selects tail style/type preset. |
| `UPARM_TAG` | Selects upper-arm style/type preset. |
| `L_LEG_SIGNAL` | Broadcast signal ID emitted by legs during locomotion. |
| `L_ARM_SIGNAL` | Broadcast signal ID emitted by arms/front limbs during locomotion. |
| `L_TAIL_SIGNAL` | Tail synchronisation signal. |
| `L_NECK_SIGNAL` | Neck synchronisation signal. |
| `L_LEG_FTOB_REACT` | Leg listener for forward-to-back power stroke. |
| `L_LEG_FTOB_EVENT` | Signal emitted by leg after forward-to-back stroke. |
| `L_LEG_BTOF_REACT` | Leg listener for back-to-forward recovery stroke. |
| `L_LEG_BTOF_EVENT` | Signal emitted by leg after back-to-forward stroke. |
| `L_ARM_FTOB_REACT` | Arm listener for forward-to-back power stroke. |
| `L_ARM_FTOB_EVENT` | Signal emitted by arm after forward-to-back stroke. |
| `L_ARM_BTOF_REACT` | Arm listener for back-to-forward recovery stroke. |
| `L_ARM_BTOF_EVENT` | Signal emitted by arm after back-to-forward stroke. |
| `L_TAIL_FTOB_REACT` | Tail listener for forward movement phase. |
| `L_TAIL_FTOB_EVENT` | Signal emitted by tail after forward phase. |
| `L_TAIL_BTOF_REACT` | Tail listener for recovery movement phase. |
| `L_TAIL_BTOF_EVENT` | Signal emitted by tail after recovery phase. |
| `L_NECK_FTOB_REACT` | Neck listener for forward movement phase. |
| `L_NECK_FTOB_EVENT` | Signal emitted by neck after forward phase. |
| `L_NECK_BTOF_REACT` | Neck listener for recovery movement phase. |
| `L_NECK_BTOF_EVENT` | Signal emitted by neck after recovery phase. |

_Credit: 153 descriptions by [alexjthomson](https://github.com/alexjthomson) (MIT license). Many descriptions reference the [Horsey Game miraheze wiki](https://horseygame.miraheze.org)._
## Part 3: Extended (480-gene) layer

This part documents the architecture, sidecar buffers, and locked design decisions for horsey-mod's gene-table extension from 240 to 480 slots. Code lives in `horsey-mod/src/genes.rs` (sidecar state) + `horsey-mod/src/patches/` (vanilla detours). The strategy + per-detour status is in [`HOOKING-STRATEGY.md`](HOOKING-STRATEGY.md) §8 (summary) and §9 (full implementation log).

### Architecture in one diagram

```
                   vanilla 240 slots                     extended 240..479
                  --------------------                  --------------------
GENE TABLE        DAT_1403ee4a4 (static)        ---->   our_gene_table_ext (heap)
                  7 readers, 3 loop bounds              hooked into same readers

POP RECORDS       DAT_1403f2fc0 + i*0x1018      ---->   our_pop_weights_ext (heap)
                  std::vector grows freely              one entry per pop_id
                  per-pop weight at +0x28               240 extra gene weights x 4 alleles

PER-HORSE GENOME  horse + 0x2b8 (inline, 480B)  ---->   our_horse_genome_ext (heap)
                  diploid, 240 alleles x 2              keyed by horse pointer (session)
                                                        or roster slot (cross-save)
                                                        diploid, 240 alleles x 2

SAVE FORMAT       save1.dat                     ---->   save1.dat.ext (sidecar)
                  vanilla untouched                     BXSAVEXT v1 with CRC32

GENE EFFECT       FUN_14009f680 -> param_1[N]   ---->   D5 post-hook trampoline
ENGINE            233 hardcoded indices                 evaluates genes 240..479,
                                                        writes to unused param_1 slots
                                                        OR new horse-struct fields
```

**Goal:** double the engine's gene capacity from 240 to 480 so the bestiary expansion can introduce up to 240 brand-new gene types. Built per the "layer on top of vanilla" design principle in [`VIABILITY.md`](VIABILITY.md): vanilla functions stay intact wherever possible; we patch surgically and redirect to our own buffers for the extended range.

### Locked design decisions (2026-05-14)

These are sticky. Future sessions assume them.

**Game install path:** `C:\Games\Steam\steamapps\common\Horsey Game`. Verified to contain `Horsey.exe`, `data/` (with `genes.xml`, `pop.xml`, `horsey.tmx`, `genes.dat`), `save/`, `sound/`, `steam_api64.dll`. Use this path for:

- Reading vanilla `genes.xml` / `pop.xml` / `horsey.tmx` during development.
- Backing up vanilla data files before any test edits.
- Writing sidecar files (`save<N>.dat.ext`, `genes-extended.xml`).
- Injecting via `horsey-inject.exe` (target process: `Horsey.exe`).

**Layered design.** Code sits ON TOP of vanilla. Don't rewrite vanilla unless we MUST. Trampolines, sidecars, heap redirects preferred over inline rewrites. When designing any new patch, ask "can vanilla still run unchanged?" first.

**Authoring format.** Extended genes are defined in a user-editable XML file (`genes-extended.xml`) mirroring vanilla `genes.xml` shape. Per-gene metadata (e.g. `extends="..."` mapping, `<render slot mode>` element) goes in this XML.

**Save compat.** Sidecar `save<N>.dat.ext` next to vanilla save. Vanilla save bytes never modified. Old saves keep working when the mod is uninstalled. ALL extended state goes through the sidecar; never patch the vanilla save serializer. Full BXSAVEXT format in [`SAVE-FORMAT.md`](SAVE-FORMAT.md) "Sidecar format `save<N>.dat.ext`".

**Phase order.** Build infra first (D0 + D7) before any vanilla patches. Sidecar buffers, HTTP ops, reload tooling get built and verified before touching any binary. If tempted to start patching `FUN_1400a5d20` to test something, first check whether the same insight could come from a `genes.ext.dump` HTTP op.

### Sidecar buffers (D0 implementation prep, shipped)

All buffers live in `horsey-mod/src/genes.rs`. Each is a `RwLock`-protected static initialized lazily via `OnceLock`.

`EXT_GENE_COUNT` is the target gene count. Picked 240 (exactly double vanilla, total 480). Lives as a `pub const` in `genes.rs`. Code that needs both totals refers to `EXT_GENE_COUNT` (just the extended range, indices 240..479 in the combined space).

**Gene table** (`gene_table()`): `RwLock<Vec<ExtGene>>` of `EXT_GENE_COUNT` entries, initialized to vanilla defaults (`m=100`, `s=1`, all-zero alleles, name `BX_RESERVED_NNN`). Modders populate by editing `<DLL_DIR>/genes-extended.xml` and reloading via the `genes.ext.reload` op.

**Pop weight extension** (`pop_weights()`): `RwLock<HashMap<u32, ExtPopWeights>>`. Each entry is 240 genes x 4 alleles defaulting to weight 1. Auto-init via `get_or_init_pop_weights(pop_id)`. Modders populate either by editing a future `pop-extended.xml` (D2.2 open) or via `pop.ext.weight.set` HTTP ops.

**Per-horse genome extension** (`horse_genomes()`): `RwLock<HashMap<u64, ExtHorseGenome>>`. Each entry is a flat `Vec<u8>` of length `2 * EXT_GENE_COUNT` (480 bytes) with the same `i / i+EXT_GENE_COUNT` diploid layout vanilla uses. Currently keyed by horse pointer (session-local); cross-save persistence uses roster-slot position per [`SAVE-FORMAT.md`](SAVE-FORMAT.md) "Horse-id field".

### HTTP control-plane ops (D0.6, shipped)

12 ops in `horsey-mod/src/ops.rs` cover the full surface of the sidecar buffers:

- `genes.ext.count` / `list` / `get` / `set` / `find` / `dump` for the ext gene table.
- `pop.ext.weights.get` / `pop.ext.weight.set` for per-pop ext weights.
- `horse.ext.genome.get` / `genome.set` / `alleles.set` / `genome.drop` / `evaluate` for per-horse ext alleles.

Plus `genes::evaluate_ext_gene()` mirrors the vanilla diploid blend formula for the extended range; the D5 render trampoline calls it per ext gene per horse per render. Combinator (`genes::combine_for_breeding`) implements Mendelian recombination on the ext range; see Part 1 Step 1 for the algorithm.

### XML authoring format (D7.2, shipped)

`<DLL_DIR>/genes-extended.xml` is auto-loaded at DLL attach (parser in `horsey-mod/src/genes_xml.rs`, 5 unit tests). Live reload via the `genes.ext.reload` op (no game restart needed). The 5/5 parser tests cover the standard `<gene name="..." m="..." s="..." g0..g3="...">` attributes plus the `<render slot="N" mode="add|set|mul"/>` child for slot mapping. Conflict detection skips ext slots already populated with a different name.

Modder workflow:

1. Add a `<gene>` entry to `<DLL_DIR>/genes-extended.xml` with a `<render slot=N mode=M />` mapping.
2. Reload via the `genes.ext.reload` HTTP op (live, no restart).
3. Decide whether to target a known consumer-read slot (visible) or an unused slot (dead computation, no effect). Cluster map + consumer map in Part 2 of this doc.
4. Test by setting `horse.ext.default_alleles.set` so every horse picks up your effect.
5. Once dialed in, set per-horse alleles via `horse.ext.alleles.set`.

### Historical planning notes

Preserved verbatim from the original implementation plan (before D0 / D1 / D3 / D5 shipped):

> **Status:** PLANNED, not started. Prereqs: Phase 0 viability research is substantially complete (see [`VIABILITY.md`](VIABILITY.md)). Final go/no-go is Phase 1 lock-in.
>
> **Estimated scope:** ~25 patch sites, plus 2 new sidecar buffers, plus 1 trampoline. Roughly 1-2 weeks of focused work assuming each phase passes its verification step. Multiply by 2-3 if anything in Phase 0 was missed.

Actual scope at shipping (2026-05-15): 6 detour modules (`patches/ext_genes.rs` + `combinator.rs` + `lifecycle.rs` + `render_trampoline.rs` + `save_sidecar.rs` + `sleep_safe_no_tire`), 3 sidecar buffers (`EXT_GENE_TABLE` + `EXT_POP_WEIGHTS` + `EXT_HORSE_GENOMES`), 30+ HTTP ops, 64 tests. Took ~1 calendar week of focused work; phase verification mostly held but ate detours discovering Ghidra's -16 entry-point offset convention and the stale save-function addresses.
