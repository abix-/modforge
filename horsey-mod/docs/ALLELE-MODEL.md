# Horsey Game allele / gene model

Reference doc: how the gene system actually works in the
binary. Synthesized from decomp findings in
[`VIABILITY.md`](VIABILITY.md). Prerequisite reading
before any mod work that touches genes, alleles, pops,
or breeding.

---

## TL;DR

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

## Layer 1: gene definitions

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

## Layer 2: pop weights

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

### Pop inheritance

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

### Spawning a new horse

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

### Unknown pop name

Hard crash. `FUN_1400a2ed0` panics with
`MessageBoxA(NULL, "pop not found <name>", "Error", 0)`
then `INT 3` aborts. No silent fallback. Misspell a
pop in `pop.xml` or `horsey.tmx` and the game dies
on the spot.

---

## Layer 3: per-horse genome

Each horse has a 480-byte block allocated by
`FUN_14005cf70` / `FUN_14005d190`, freed by
`FUN_14005cd00`, pointer at `horse[0x78]`.

Layout: **diploid pair stored as two 240-byte halves.**

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

### Save encoding

Per `FUN_14006d470` (write) and `FUN_14006d580` (read):
each diploid pair is bit-packed into one byte:

```
packed_byte = (paternal_allele + 1) << 3 | (maternal_allele + 1)
```

So 480 bytes of in-memory alleles compress to 240
packed bytes per horse on disk. Top 2 bits of each
saved byte are unused.

---

## Per-frame: evaluating a gene's effect

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

### Why max/min?

The `max(m_allele, p_allele)` = dominant convention is
arbitrary engine choice. `g3` is always more dominant
than `g0`. So if you author allele payloads in
ascending strength (`g0 = small, g3 = huge`) the
engine will lean toward the bigger allele when both
parents disagree. Authoring tip: order alleles
intentionally; the engine treats higher index as
dominant.

---

## Population genetics: live mutation drift

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

## CRISPR Lab and runtime allele swap

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

## Breeding (combining two parents)

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

- [ ] Find the breeding combinator function. Probably
      called `FUN_14005d190` with one parent then
      again with the other, or a higher-level function
      that does both.
- [ ] Confirm the runtime mutation-during-breeding
      behavior: does the child get random allele
      flips beyond the parent picks?

---

## Worked examples

These walk through the math of what actually happens when
the engine evaluates a gene for a horse. All numbers are
illustrative; real allele values come from `genes.xml`.

### Example 1: homozygous dominant (parents agree on g3)

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

### Example 2: heterozygous (parents disagree, g0 vs g3)

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

### Example 3: weight-driven spawn (no genes involved)

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

### Example 4: extreme weight (close to deterministic)

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

### Example 5: drift over generations

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

---

## Allele indexing edge cases

### Allele 0..3 only (no extras)

The `& 0x3` mask in the diploid evaluator means stored
allele indices are masked to 0..3. Save format allows
0..6 storage (3 bits). The extra bits are reserved
slack, not meaningful.

If we store an allele index of 5 in the genome, it
gets masked to 1 at evaluation time. Quietly wrong.

### Sentinel value -1

Save unpack does `(byte_low & 7) - 1`. So a saved
value of 0 unpacks to -1 (sentinel for "no allele
set"?). Vanilla packing always adds 1 before saving
so 0..3 -> 1..4. The 0 saved value would be unusual
and probably indicates an uninitialized gene.

### What happens if gene table has fewer alleles than expected

A gene record could in theory have only g0 and g1
defined (g2, g3 = 0). If a horse's allele index is 2
or 3, it reads payload value 0. Probably interpreted
as "no effect" rather than crashing. Worth confirming
via experiment if we ever author genes with fewer
than 4 alleles.

---

## Pop record on-disk layout cheat sheet

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

## What this enables for modding

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
