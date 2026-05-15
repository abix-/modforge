# Render-buf slot map (vanilla Horsey gene engine)

> **Living doc.** Built incrementally as we trace
> `FUN_14009f680` (the gene engine) and `FUN_1400ab3d0`
> (the consumer). Each row is evidence-cited to a line in
> `horseygame/decompiled/all_functions.c`.

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

### Genes the engine never reads (free slots)

7 vanilla genes are defined in `genes.xml` but never queried
by `FUN_14009f680`:

| Idx | Name | Likely status |
|---|---|---|
| 56 | `ARM_STRETCH` | Removed sibling of `LEG_STRETCH` |
| 57 | `ARM_STRETCH2` | Same. |
| 107 | `HEAD_CHIMERA` | Removed feature placeholder |
| 183 | `SKIN_HUE` | Possibly orphaned palette gene |
| 184 | `SKIN_HUE2` | Same. |
| 209 | `BRAIN_SPASTIC` | Behavioral; possibly unfinished |
| 216 | `FLU_IMMUNITY` | Behavioral; possibly unfinished |

These slots are "free" in the sense that we could repurpose
them by adding handler logic in our DI-A detours, BUT
vanilla breeding / CRISPR UI / xml authoring still see them,
so they're not invisible. Extended slots 240..479 (our
sidecar) are cleaner for new genes.

## Gene-index -> buf-slot map (engine writes)

Auto-derived from `FUN_14009f680` decomp by
`horseygame/extract-slot-map.py`. 166 of 240 vanilla genes drive at least one buf slot.
`(via fVarX)` means the gene's value passes through a
temp variable. `(combined-with-others ...)` means the
slot's value is a multi-gene expression; the row is
a candidate, manual re-read recommended.

| Gene idx | Gene name | Buf slot(s) | How |
|---|---|---|---|
| 5 | `CHEST_BIG` | 2 (combined-with-others (fVar36 / fVar37)), 344 (via var) | |
| 7 | `GIANT_DWARF` | 1 (via var), 173 (via var), 174 (via var), 2 (combined-with-others (fVar36 / fVar37)), 3 (via var) | |
| 8 | `MUSCLE_USE` | 132 (via expr: (fVar41 * fVar35 * fVar40) / fVar39) | |
| 9 | `QUADRUPED` | 167 (via expr: fVar35 / (float)iVar15), 170 (via expr: (float)(iVar15 + -1)) | |
| 11 | `SPLAY` | 35 (via var), 54 (combined-with-others ((float)(uVar44 ^ uVar25) - fVar43)), 54 (via expr: (float)((uint)fVar33 ^ uVar25)) | |
| 12 | `LEG_IN` | 33 (via expr: param_1[0x7d] * fVar43 + fVar35), 33 (via var) | |
| 13 | `LEG_IN2` | 52 (via expr: fVar35 - param_1[0x7d] * fVar43), 52 (via var) | |
| 14 | `GUT` | 4 (via var) | |
| 15 | `GUT_IS_UDDER` | 6 (via var) | |
| 16 | `OSTODERM` | 7 (via var) | |
| 17 | `OSTO_SIZE` | 8 (via var) | |
| 18 | `DERRIERE` | 10 (via var) | |
| 19 | `SPEED_FACTOR` | 133 (via var), 134 (via var), 154 (via expr: fVar43 * fVar37), 155 (via expr: fVar43 * fVar37) | |
| 20 | `BREAK_FORCE` | 47 (via var), 66 (via var) | |
| 21 | `TAIL_TAG` | 18 (via var) | |
| 22 | `TAIL_EXISTS` | 165 (via var) | |
| 23 | `TAIL_SIZE` | 166 (combined-with-others (fVar40 * fVar39)), 167 (via var) | |
| 24 | `TAIL_SHORT` | 167 (via expr: fVar39 * fVar37) | |
| 25 | `TAIL_ASPECT` | 166 (combined-with-others (fVar40 * fVar39)) | |
| 26 | `TAIL_ANGLE` | 16 (via var) | |
| 27 | `TAIL_JOINT_TYPE` | 24 (via var) | |
| 28 | `TAIL_STIFF` | 6 (byte-offset 0x19) (via expr: iVar15 == 0) | |
| 29 | `TAIL_SPEED` | 175 (via var), 176 (via var) | |
| 30 | `TAIL_FLEXIBILITY` | 26 (via expr: (float)((uint)fVar38 ^ uVar25)), 27 (via var) | |
| 31 | `TAIL_SHAPE` | 169 (via var) | |
| 34 | `LEG_TAG` | 37 (via var) | |
| 35 | `LEG_TYPE` | 123 (via expr: (float)(uint)(iVar15 != 0)) | |
| 36 | `LEG_LENGTH` | 125 (combined-with-others (fVar39 * (fVar37 + fVar35 + fVar43))) | |
| 37 | `LEG_STRETCH` | 125 (combined-with-others (fVar39 * (fVar37 + fVar35 + fVar43))), 146 (combined-with-others (fVar42 * (fVar41 + fVar40))) | |
| 38 | `LEG_STRETCH2` | 125 (combined-with-others (fVar39 * (fVar37 + fVar35 + fVar43))), 146 (combined-with-others (fVar42 * (fVar41 + fVar40))) | |
| 39 | `LEG_STRENGTH` | 124 (via expr: fVar35 + fVar35), 124 (via var), 125 (via expr: fVar35 + fVar35), 131 (via expr: fVar39 * DAT_140304b30), 132 (via var) | |
| 40 | `LEG_HAS_FOOT` | 35 (byte-offset 0x8d) (via expr: iVar16 != 0) | |
| 41 | `LEG_JOINT_TYPE` | 43 (via var) | |
| 42 | `LEG_FLEXIBILITY` | 45 (combined-with-others (fVar35 - fVar39)), 45 (via var), 46 (combined-with-others (fVar35 + fVar39)) | |
| 43 | `LEG_FLEX_BIAS` | 35 (via expr: fVar39 + fVar35), 45 (combined-with-others (fVar35 - fVar39)), 46 (combined-with-others (fVar35 + fVar39)) | |
| 46 | `LEG_COUNT` | 31 (via var) | |
| 47 | `LEG_SKEW` | 126 (via var) | |
| 49 | `LEG_AND_ARM_LIMP` | 11 (byte-offset 0x2c) (via expr: iVar16 != 0), 15 (byte-offset 0x3f) (via expr: iVar16 != 0) | |
| 53 | `ARM_TAG` | 56 (via var) | |
| 54 | `ARM_TYPE` | 144 (via expr: (float)(uint)(iVar15 != 0)) | |
| 55 | `ARM_LENGTH` | 146 (combined-with-others (fVar42 * (fVar41 + fVar40))) | |
| 58 | `ARM_STRENGTH` | 145 (via expr: fVar41 * fVar43), 152 (via expr: fVar41 * fVar38), 153 (via var) | |
| 59 | `ARM_HAS_HAND` | 40 (byte-offset 0xa2) (via expr: iVar16 != 0) | |
| 60 | `ARM_JOINT_TYPE` | 62 (via var) | |
| 61 | `ARM_FLEXIBILITY` | 64 (combined-with-others ((float)(uVar44 ^ uVar25) - fVar43)), 64 (via var), 65 (combined-with-others (fVar43 - fVar35)) | |
| 62 | `ARM_FLEX_BIAS` | 54 (via expr: fVar35 + fVar43), 64 (combined-with-others ((float)(uVar44 ^ uVar25) - fVar43)), 65 (combined-with-others (fVar43 - fVar35)) | |
| 63 | `ARM_FORWARD` | 54 (combined-with-others ((float)(uVar44 ^ uVar25) - fVar43)) | |
| 64 | `ARM_SKEW` | 147 (via var) | |
| 65 | `ARM_NODE_SCALE` | 55 (via var) | |
| 68 | `UPARM_TAG` | 17 (byte-offset 0x45) (via expr: fVar43 != 0.0), 74 (via var) | |
| 70 | `UPARM_ANGLE` | 72 (via expr: fVar35 - DAT_140304038) | |
| 72 | `NECK_TAG` | 110 (via var) | |
| 73 | `NECK_TYPE` | 186 (via expr: (float)(uint)(iVar15 != 0)) | |
| 74 | `NECK_LENGTH` | 188 (combined-with-others (fVar37 + fVar43 * fVar40)) | |
| 75 | `NECK_GIRAFFE` | 188 (combined-with-others (fVar37 + fVar43 * fVar40)) | |
| 76 | `NECK_THICKNESS` | 187 (via expr: fVar37 * local_324 * DAT_14030335c) | |
| 77 | `NECK_ANGLE` | 108 (combined-with-others (fVar35 - fVar37)) | |
| 78 | `NECK_COCK` | 108 (combined-with-others (fVar35 - fVar37)) | |
| 79 | `NECK_JOINT_TYPE` | 116 (via var) | |
| 80 | `NECK_FLEXIBILITY` | 118 (combined-with-others (fVar39 - fVar38)), 118 (via var), 119 (combined-with-others (fVar39 + fVar38)) | |
| 81 | `NECK_FLEX_BIAS` | 108 (via expr: fVar38 + fVar39), 118 (combined-with-others (fVar39 - fVar38)), 119 (combined-with-others (fVar39 + fVar38)) | |
| 84 | `NECK_STIFF` | 29 (byte-offset 0x75) (via expr: iVar17 == 0) | |
| 85 | `NECK_SPEED` | 196 (via var), 197 (via var) | |
| 86 | `HAS_FOOT` | 51 (byte-offset 0xcf) (via expr: 0 < iVar16) | |
| 87 | `FOOT_SIZE` | 209 (combined-with-others (fVar38 + fVar37 + fVar43)) | |
| 88 | `FOOT_CLOWN` | 209 (combined-with-others (fVar38 + fVar37 + fVar43)) | |
| 89 | `FOOT_THICKNESS` | 211 (via var) | |
| 90 | `FOOT_TOE` | 12 (via var) | |
| 93 | `HAS_HAND` | 54 (byte-offset 0xd9) (via expr: 0 < iVar16) | |
| 94 | `HAND_WIDTH` | 219 (via expr: fVar37 + fVar43) | |
| 95 | `HAND_LENGTH` | 221 (via var) | |
| 96 | `HAND_FINGER` | 223 (via var) | |
| 99 | `HEAD_X_GROWTH` | 227 (via var), 228 (combined-with-others ((fVar35 + fVar38) * (fVar37 / fVar40))) | |
| 100 | `HEAD_Y_GROWTH` | 228 (combined-with-others ((fVar35 + fVar38) * (fVar37 / fVar40))) | |
| 103 | `HEAD_HAS_BACK` | 57 (byte-offset 0xe5) (via expr: iVar15 != 0) | |
| 104 | `HEAD_GIANT` | 228 (combined-with-others ((fVar35 + fVar38) * (fVar37 / fVar40))) | |
| 108 | `EYE_STYLE` | 235 (via var) | |
| 110 | `EYEBOX_X` | 236 (via var) | |
| 111 | `EYEBOX_Y` | 237 (via var) | |
| 113 | `EYE_SIZE` | 239 (via expr: fVar38 * fVar35 * DAT_14039ca34) | |
| 114 | `PUPIL_SIZE` | 240 (via var) | |
| 116 | `BROW_SIZE` | 241 (via var) | |
| 117 | `BROW_SLANT` | 242 (via var) | |
| 118 | `EAR_STYLE` | 243 (via var) | |
| 119 | `EAR_SHAPE` | 244 (via var) | |
| 120 | `EAR_FLOP` | 245 (via var) | |
| 121 | `EAR_X` | 246 (via var) | |
| 122 | `EAR_SIZE` | 248 (via var), 249 (combined-with-others (fVar38 * fVar35)) | |
| 123 | `EAR_ASPECT` | 249 (combined-with-others (fVar38 * fVar35)) | |
| 124 | `EAR_SLANT` | 250 (via var) | |
| 125 | `EAR_INTERIOR` | 251 (via var) | |
| 126 | `TEETH_SHAPE` | 252 (via var) | |
| 128 | `MOUTH_Y` | 255 (via var) | |
| 129 | `MOUTH_SIZE` | 253 (via var), 254 (via expr: fVar35 * _DAT_14030cd20) | |
| 130 | `JAW` | 257 (via var) | |
| 133 | `TONGUE` | 258 (via var) | |
| 134 | `TONGUE_SEGS` | 259 (via var) | |
| 135 | `NOSE_STYLE` | 261 (via var) | |
| 137 | `NOSE_Y` | 264 (via var) | |
| 139 | `NOSE_INTERIOR` | 265 (via var) | |
| 141 | `ANTLER_X` | 266 (via var) | |
| 142 | `ANTLER_W` | 268 (via var) | |
| 143 | `ANTLER_H` | 269 (via var) | |
| 144 | `ANTLER_TAPER` | 270 (via var) | |
| 145 | `ANTLER_POM` | 271 (via var) | |
| 146 | `ANTLER_COLOR` | 275 (via var) | |
| 147 | `POM_COLOR` | 276 (via var) | |
| 149 | `ANTLER_REC` | 277 (via var) | |
| 150 | `ANTLER_REC2` | 278 (via var) | |
| 151 | `ANTLER_FLIP` | 69 (byte-offset 0x117) (via expr: iVar15 != 0) | |
| 152 | `ANTLER_MOD` | 289 (via var) | |
| 153 | `ANTLER_SCALEH` | 285 (via var) | |
| 154 | `ANTLER_SCALEW` | 283 (via var), 284 (via var) | |
| 155 | `ANTLER_ANGLE` | 280 (via var) | |
| 156 | `ANTLER_ANGLE2` | 281 (via var) | |
| 157 | `ANTLER_ANGLE_RAND` | 282 (via var) | |
| 158 | `ANTLER_T1` | 287 (via var) | |
| 159 | `ANTLER_T2` | 288 (via var) | |
| 161 | `HAT_SIZE` | 290 (via var), 291 (combined-with-others (fVar43 * fVar33)) | |
| 162 | `HAT_RAKE` | 267 (via var) | |
| 163 | `HAT_ASPECT` | 291 (combined-with-others (fVar43 * fVar33)) | |
| 164 | `HAT_TAPER` | 292 (via var) | |
| 165 | `HAT_POM` | 293 (via var) | |
| 167 | `HAT_CLONE` | 294 (via var) | |
| 168 | `HAT_BACK_SCALE` | 307 (via var) | |
| 169 | `HAT_FRONT_SCALE` | 308 (via var) | |
| 170 | `HAT_BACK_ANGLE` | 302 (via var) | |
| 171 | `HAT_FRONT_ANGLE` | 303 (via var) | |
| 172 | `HAT_ANGLE_RAND` | 304 (via var) | |
| 173 | `HAT_FLIP` | 75 (byte-offset 0x12d) (via expr: iVar15 != 0) | |
| 174 | `HAT_T` | 309 (via var), 310 (via var) | |
| 191 | `HOOF_COLOR` | 317 (via expr: local_318[iVar20]) | |
| 193 | `BELLY_ALT` | 83 (byte-offset 0x14f) (via expr: iVar20 != 0) | |
| 197 | `RACCOON_EYE` | 231 (via var) | |
| 198 | `EAR_COMP` | 233 (via var) | |
| 200 | `PAT_SPLIT` | 333 (via var) | |
| 201 | `PAT_BELLY` | 15 (via expr: param_1[1] - fVar35), 334 (via var) | |
| 202 | `PAT_STRIPE` | 336 (via var) | |
| 203 | `PAT_SPOT` | 337 (via var) | |
| 204 | `PAT_PERLIN` | 340 (via var) | |
| 205 | `PAT_PERLIN2` | 341 (via var) | |
| 206 | `PAT_PERLIN_SIZE` | 342 (via expr: (float)(int)fVar33) | |
| 211 | `OMNIVORE` | 87 (byte-offset 0x15c) (via expr: iVar15 != 0) | |
| 212 | `LITTER_SIZE` | 349 (via var) | |
| 213 | `OLD_AGE` | 351 (via expr: (float)(iVar15 + 9)) | |
| 218 | `STIFF_JOINTS` | 100 (via expr: fVar33 * param_1[100]), 101 (via expr: fVar33 * param_1[0x65]), 118 (via expr: fVar33 * param_1[0x76]), 119 (via expr: fVar33 * param_1[0x77]), 26 (via expr: fVar33 * param_1[0x1a]), 27 (via expr: fVar33 * param_1[0x1b]), 45 (via expr: fVar33 * param_1[0x2d]), 46 (via expr: fVar33 * param_1[0x2e]), 64 (via expr: fVar33 * param_1[0x40]), 65 (via expr: fVar33 * param_1[0x41]), 82 (via expr: fVar33 * param_1[0x52]), 83 (via expr: fVar33 * param_1[0x53]) | |
| 219 | `L_LEG_SIGNAL` | 38 (via var) | |
| 220 | `L_LEG_FTOB_REACT` | 39 (via var) | |
| 221 | `L_LEG_FTOB_EVENT` | 41 (via var) | |
| 222 | `L_LEG_BTOF_REACT` | 40 (via var) | |
| 223 | `L_LEG_BTOF_EVENT` | 42 (via var) | |
| 224 | `L_ARM_SIGNAL` | 57 (via var) | |
| 225 | `L_ARM_FTOB_REACT` | 58 (via var) | |
| 226 | `L_ARM_FTOB_EVENT` | 60 (via var) | |
| 227 | `L_ARM_BTOF_REACT` | 59 (via var) | |
| 228 | `L_ARM_BTOF_EVENT` | 61 (via var) | |
| 229 | `L_TAIL_SIGNAL` | 19 (via var) | |
| 230 | `L_TAIL_FTOB_REACT` | 20 (via var) | |
| 231 | `L_TAIL_FTOB_EVENT` | 22 (via var) | |
| 232 | `L_TAIL_BTOF_REACT` | 21 (via var) | |
| 233 | `L_TAIL_BTOF_EVENT` | 23 (via var) | |
| 234 | `L_NECK_SIGNAL` | 111 (via var) | |
| 235 | `L_NECK_FTOB_REACT` | 112 (via var) | |
| 236 | `L_NECK_FTOB_EVENT` | 114 (via var) | |
| 237 | `L_NECK_BTOF_REACT` | 113 (via var) | |
| 238 | `L_NECK_BTOF_EVENT` | 115 (via var) | |

## Buf-slot -> horse-struct field (consumer reads)

Auto-derived from `FUN_1400ab3d0` decomp by
`horseygame/extract-consumer-map.py`. Reads 62 distinct
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
| 0 | 200.0 | "Full screen width" babies (mated 2 horses, offspring rendered enormously wide). Drives some primary scale-like parameter. | `BX_TEST_SLOT0` set mode (3,3) blend = 200.0 |
