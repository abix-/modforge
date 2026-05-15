# Render-buf slot map (vanilla Horsey gene engine)
> **Authoritative on:** the buf-slot side of the gene engine. Pipeline overview, cluster table (which gene-index range drives which feature area), buf-slot -> horse-struct field mapping, the slots-0..3 SQRT formula, vanilla pop catalog, confirmed visible-effect slots, modder workflow. Per-gene "which slots does gene N write/gate" lives in [`GENE-CATALOG.md`](GENE-CATALOG.md). Each row here is evidence-cited to a line in `horsey-mod/research/decompiled/all_functions.c`.

## Pipeline

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

## Vanilla genes inventory

240 genes, full list in
[`vanilla-genes.xml`](vanilla-genes.xml). Gene index 0..239
matches XML document order.

### Cluster map (gene_idx -> feature area)

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

### Per-gene engine writes and gates

Authoritative per-gene table (which buf slots each gene writes directly, which it gates via conditionals, plus dead genes marked `_unread_`) lives in [`GENE-CATALOG.md`](GENE-CATALOG.md). This doc is authoritative on the slot side: clusters, slot -> horse-struct mapping, engine internals, modder workflow.

## Buf-slot -> horse-struct field (consumer reads)

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

## Engine internals (slots 0..3): the "horse fundamental size"

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

## Vanilla pops (28 species)

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

## Confirmed visible-effect slots

Empirically verified by setting the slot to an extreme
value via the D5 post-hook and observing in-game.

| Slot | Set value | Visible effect | Set via |
|---|---|---|---|
| 0 | 200.0 | "Full screen width" babies (mated 2 horses, offspring rendered enormously wide). Drives a primary scale parameter; consumer reads `*param_2` (slot 0) and compares with slot 1 to gate which write path runs. | `BX_TEST_SLOT0` set mode (3,3) blend = 200.0 |

## Modder workflow

### To make a new SPECIES (new pop)

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

### To make a new VISUAL EFFECT (extended gene)

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

### Which slot to target for which effect

The cluster table above tells you which vanilla genes
*should* feed slots related to that feature area. Cross-
reference with the "Buf-slot -> horse-struct field" table
to confirm the slot is consumer-read.

Worst-case empirical fallback: pick a candidate slot,
write an extreme value with `mode=set`, walk in-game,
observe. The 2026-05-14 giant-baby experiment is the
exemplar.

## What's still unknown

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