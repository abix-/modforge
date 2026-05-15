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
matches XML document order. Names like `SIZE`, `ASPECT`,
`SKINNY`, `BONES`, `BONES2`, `CHEST_BIG`, `CHEST_SMALL`,
`GIANT_DWARF`, `MUSCLE_USE`, `QUADRUPED` are the first 10.

## Gene-index -> buf-slot map (engine writes)

Auto-derived from `FUN_14009f680` decomp by
`horseygame/extract-slot-map.py`. 166 of 240 vanilla genes drive at least one buf slot.
`(via fVarX)` means the gene's value passes through a
temp variable. `(combined-with-others ...)` means the
slot's value is a multi-gene expression; the row is
a candidate, manual re-read recommended.

| Gene idx | Gene name | Buf slot(s) | How |
|---|---|---|---|
| 0 | `SIZE` | 152 (combined-with-others (fVar41 * fVar38)) | |
| 1 | `ASPECT` | 343 (via fVar39 (expr: (float)(int)fVar39)) | |
| 2 | `SKINNY` | 70 (via fVar33), 70 (via fVar33 (expr: fVar33 - param_1[5])), 106 (combined-with-others (fVar33 - fVar35)) | |
| 5 | `CHEST_BIG` | 2 (combined-with-others (fVar36 / fVar37)), 344 (via fVar37) | |
| 6 | `CHEST_SMALL` | 1 (via fVar36), 2 (combined-with-others (fVar36 / fVar37)), 3 (via fVar36) | |
| 7 | `GIANT_DWARF` | 173 (via fVar35), 174 (via fVar35) | |
| 8 | `MUSCLE_USE` | 132 (combined-with-others ((fVar41 * fVar35 * fVar40) / fVar39)), 154 (combined-with-others (fVar43 * fVar37)), 155 (combined-with-others (fVar43 * fVar37)), 209 (combined-with-others (fVar38 + fVar37 + fVar43)) | |
| 9 | `QUADRUPED` | 167 (combined-with-others (fVar35 / (float)iVar15)), 170 (via iVar15 (expr: (float)(iVar15 + -1))) | |
| 11 | `SPLAY` | 35 (via fVar33), 35 (via fVar35), 54 (combined-with-others ((float)(uVar44 ^ uVar25) - fVar43)), 54 (via fVar33 (expr: (float)((uint)fVar33 ^ uVar25))) | |
| 12 | `LEG_IN` | 33 (combined-with-others (param_1[0x7d] * fVar43 + fVar35)), 33 (via fVar35) | |
| 13 | `LEG_IN2` | 52 (combined-with-others (fVar35 - param_1[0x7d] * fVar43)), 52 (via fVar35) | |
| 14 | `GUT` | 4 (via fVar39) | |
| 15 | `GUT_IS_UDDER` | 6 (via fVar39) | |
| 16 | `OSTODERM` | 7 (via fVar39) | |
| 17 | `OSTO_SIZE` | 8 (via fVar39) | |
| 18 | `DERRIERE` | 5 (via fVar40), 10 (via fVar40) | |
| 19 | `SPEED_FACTOR` | 133 (via fVar39), 134 (via fVar39), 154 (combined-with-others (fVar43 * fVar37)), 155 (combined-with-others (fVar43 * fVar37)) | |
| 20 | `BREAK_FORCE` | 47 (via fVar35), 66 (via fVar35) | |
| 21 | `TAIL_TAG` | 18 (via fVar38) | |
| 22 | `TAIL_EXISTS` | 165 (via fVar37) | |
| 23 | `TAIL_SIZE` | 166 (combined-with-others (fVar40 * fVar39)) | |
| 25 | `TAIL_ASPECT` | 166 (combined-with-others (fVar40 * fVar39)) | |
| 26 | `TAIL_ANGLE` | 16 (via fVar38) | |
| 27 | `TAIL_JOINT_TYPE` | 24 (via fVar38) | |
| 29 | `TAIL_SPEED` | 167 (combined-with-others (fVar35 / (float)iVar15)), 175 (via fVar35), 176 (via fVar35) | |
| 30 | `TAIL_FLEXIBILITY` | 26 (via fVar38 (expr: (float)((uint)fVar38 ^ uVar25))), 27 (via fVar38) | |
| 31 | `TAIL_SHAPE` | 169 (via fVar37) | |
| 34 | `LEG_TAG` | 37 (via fVar35) | |
| 35 | `LEG_TYPE` | 123 (via iVar15 (expr: (float)(uint)(iVar15 != 0))) | |
| 36 | `LEG_LENGTH` | 125 (combined-with-others (fVar39 * (fVar37 + fVar35 + fVar43))) | |
| 37 | `LEG_STRETCH` | 125 (combined-with-others (fVar39 * (fVar37 + fVar35 + fVar43))), 146 (combined-with-others (fVar42 * (fVar41 + fVar40))), 146 (via fVar40 (expr: param_1[0x92] * fVar40)), 188 (combined-with-others (fVar37 + fVar43 * fVar40)) | |
| 38 | `LEG_STRETCH2` | 125 (combined-with-others (fVar39 * (fVar37 + fVar35 + fVar43))), 146 (combined-with-others (fVar42 * (fVar41 + fVar40))) | |
| 39 | `LEG_STRENGTH` | 124 (via fVar35), 124 (via fVar35 (expr: fVar35 + fVar35)), 125 (via fVar35 (expr: fVar35 + fVar35)), 131 (via fVar39 (expr: fVar39 * DAT_140304b30)), 132 (via fVar39) | |
| 41 | `LEG_JOINT_TYPE` | 43 (via fVar35) | |
| 42 | `LEG_FLEXIBILITY` | 35 (combined-with-others (fVar39 + fVar35)), 45 (combined-with-others (fVar35 - fVar39)), 45 (via fVar35), 46 (combined-with-others (fVar35 + fVar39)), 106 (via fVar39), 108 (via fVar39) | |
| 43 | `LEG_FLEX_BIAS` | 35 (combined-with-others (fVar39 + fVar35)), 45 (combined-with-others (fVar35 - fVar39)), 46 (combined-with-others (fVar35 + fVar39)) | |
| 46 | `LEG_COUNT` | 31 (via fVar35) | |
| 47 | `LEG_SKEW` | 126 (via fVar39) | |
| 48 | `LEG_PENCIL` | 124 (via fVar40), 125 (via fVar40 (expr: (param_1[0x7d] * fVar41) / fVar40)), 132 (combined-with-others ((fVar41 * fVar35 * fVar40) / fVar39)) | |
| 51 | `KNEE_MIN` | 139 (via fVar39) | |
| 52 | `KNEE_MAX` | 132 (combined-with-others ((fVar41 * fVar35 * fVar40) / fVar39)), 140 (via fVar39) | |
| 53 | `ARM_TAG` | 56 (via fVar35) | |
| 54 | `ARM_TYPE` | 144 (via iVar15 (expr: (float)(uint)(iVar15 != 0))) | |
| 55 | `ARM_LENGTH` | 146 (combined-with-others (fVar42 * (fVar41 + fVar40))) | |
| 58 | `ARM_STRENGTH` | 15 (via fVar41 (expr: fVar41 * param_1[1])), 71 (via fVar41), 145 (via fVar41 (expr: fVar41 * fVar43)), 152 (combined-with-others (fVar41 * fVar38)), 153 (via fVar41) | |
| 60 | `ARM_JOINT_TYPE` | 62 (via fVar35) | |
| 61 | `ARM_FLEXIBILITY` | 54 (combined-with-others (fVar35 + fVar43)), 64 (combined-with-others ((float)(uVar44 ^ uVar25) - fVar43)), 64 (via fVar43), 65 (combined-with-others (fVar43 - fVar35)) | |
| 62 | `ARM_FLEX_BIAS` | 54 (combined-with-others (fVar35 + fVar43)), 64 (combined-with-others ((float)(uVar44 ^ uVar25) - fVar43)), 65 (combined-with-others (fVar43 - fVar35)) | |
| 63 | `ARM_FORWARD` | 54 (combined-with-others ((float)(uVar44 ^ uVar25) - fVar43)) | |
| 64 | `ARM_SKEW` | 147 (via fVar43) | |
| 65 | `ARM_NODE_SCALE` | 55 (via fVar35) | |
| 67 | `ELBOW_RANGE` | 160 (via fVar43 (expr: (float)((uint)fVar43 ^ uVar25))), 161 (via fVar43) | |
| 68 | `UPARM_TAG` | 54 (via fVar43 (expr: param_1[0x48] + fVar43)), 71 (via fVar43), 74 (via fVar43) | |
| 70 | `UPARM_ANGLE` | 72 (via fVar35 (expr: fVar35 - DAT_140304038)) | |
| 72 | `NECK_TAG` | 106 (combined-with-others (fVar33 - fVar35)), 107 (via fVar35), 107 (via fVar35 (expr: fVar35 + param_1[0x6b])), 110 (via fVar35), 188 (via fVar35 (expr: fVar35 + param_1[0xbc])) | |
| 73 | `NECK_TYPE` | 186 (via iVar15 (expr: (float)(uint)(iVar15 != 0))) | |
| 74 | `NECK_LENGTH` | 33 (combined-with-others (param_1[0x7d] * fVar43 + fVar35)), 52 (combined-with-others (fVar35 - param_1[0x7d] * fVar43)), 188 (combined-with-others (fVar37 + fVar43 * fVar40)) | |
| 75 | `NECK_GIRAFFE` | 188 (combined-with-others (fVar37 + fVar43 * fVar40)) | |
| 76 | `NECK_THICKNESS` | 187 (via fVar37 (expr: fVar37 * local_324 * DAT_14030335c)) | |
| 77 | `NECK_ANGLE` | 108 (combined-with-others (fVar35 - fVar37)) | |
| 78 | `NECK_COCK` | 108 (combined-with-others (fVar35 - fVar37)) | |
| 79 | `NECK_JOINT_TYPE` | 116 (via fVar39) | |
| 80 | `NECK_FLEXIBILITY` | 108 (combined-with-others (fVar38 + fVar39)), 118 (combined-with-others (fVar39 - fVar38)), 118 (via fVar39), 119 (combined-with-others (fVar39 + fVar38)) | |
| 81 | `NECK_FLEX_BIAS` | 108 (combined-with-others (fVar38 + fVar39)), 118 (combined-with-others (fVar39 - fVar38)), 119 (combined-with-others (fVar39 + fVar38)) | |
| 82 | `NECK_SLOUCH` | 107 (via fVar40) | |
| 83 | `NECK_ONTOP` | 107 (via fVar34), 313 (via fVar34) | |
| 85 | `NECK_SPEED` | 196 (via fVar35), 197 (via fVar35) | |
| 87 | `FOOT_SIZE` | 209 (combined-with-others (fVar38 + fVar37 + fVar43)), 220 (via fVar38) | |
| 88 | `FOOT_CLOWN` | 209 (combined-with-others (fVar38 + fVar37 + fVar43)) | |
| 89 | `FOOT_THICKNESS` | 211 (via fVar43) | |
| 90 | `FOOT_TOE` | 12 (via fVar43), 210 (via fVar43 (expr: fVar43 * param_1[0xd3] + param_1[0xd1])), 219 (combined-with-others (fVar37 + fVar43)), 224 (via fVar43) | |
| 94 | `HAND_WIDTH` | 219 (combined-with-others (fVar37 + fVar43)) | |
| 95 | `HAND_LENGTH` | 221 (via fVar37) | |
| 96 | `HAND_FINGER` | 223 (via fVar37) | |
| 98 | `HEAD_THICK_SKULL` | 228 (combined-with-others ((fVar35 + fVar38) * (fVar37 / fVar40))) | |
| 99 | `HEAD_X_GROWTH` | 90 (via fVar40 (expr: param_1[0x5a] + fVar40)), 227 (via fVar40), 228 (combined-with-others ((fVar35 + fVar38) * (fVar37 / fVar40))) | |
| 100 | `HEAD_Y_GROWTH` | 228 (combined-with-others ((fVar35 + fVar38) * (fVar37 / fVar40))) | |
| 104 | `HEAD_GIANT` | 228 (combined-with-others ((fVar35 + fVar38) * (fVar37 / fVar40))) | |
| 108 | `EYE_STYLE` | 235 (via fVar35) | |
| 110 | `EYEBOX_X` | 236 (via fVar38) | |
| 111 | `EYEBOX_Y` | 237 (via fVar35), 239 (combined-with-others (fVar38 * fVar35 * DAT_14039ca34)) | |
| 113 | `EYE_SIZE` | 239 (combined-with-others (fVar38 * fVar35 * DAT_14039ca34)) | |
| 114 | `PUPIL_SIZE` | 240 (via fVar35) | |
| 116 | `BROW_SIZE` | 241 (via fVar35) | |
| 117 | `BROW_SLANT` | 238 (via fVar35), 242 (via fVar35) | |
| 118 | `EAR_STYLE` | 243 (via fVar35) | |
| 119 | `EAR_SHAPE` | 244 (via fVar35) | |
| 120 | `EAR_FLOP` | 245 (via fVar35) | |
| 121 | `EAR_X` | 246 (via fVar35) | |
| 122 | `EAR_SIZE` | 248 (via fVar35), 249 (combined-with-others (fVar38 * fVar35)) | |
| 123 | `EAR_ASPECT` | 249 (combined-with-others (fVar38 * fVar35)) | |
| 124 | `EAR_SLANT` | 250 (via fVar35) | |
| 125 | `EAR_INTERIOR` | 251 (via fVar35) | |
| 126 | `TEETH_SHAPE` | 252 (via fVar35) | |
| 128 | `MOUTH_Y` | 255 (via fVar35) | |
| 129 | `MOUTH_SIZE` | 253 (via fVar35), 254 (via fVar35 (expr: fVar35 * _DAT_14030cd20)) | |
| 130 | `JAW` | 257 (via fVar35) | |
| 133 | `TONGUE` | 258 (via fVar35) | |
| 134 | `TONGUE_SEGS` | 259 (via fVar35) | |
| 135 | `NOSE_STYLE` | 261 (via fVar35) | |
| 137 | `NOSE_Y` | 263 (via fVar35), 264 (via fVar35) | |
| 139 | `NOSE_INTERIOR` | 265 (via fVar35) | |
| 141 | `ANTLER_X` | 266 (via fVar33) | |
| 142 | `ANTLER_W` | 268 (via fVar33) | |
| 143 | `ANTLER_H` | 269 (via fVar33) | |
| 144 | `ANTLER_TAPER` | 270 (via fVar33) | |
| 145 | `ANTLER_POM` | 271 (via fVar33) | |
| 146 | `ANTLER_COLOR` | 275 (via fVar33) | |
| 147 | `POM_COLOR` | 276 (via fVar33) | |
| 149 | `ANTLER_REC` | 277 (via fVar33) | |
| 150 | `ANTLER_REC2` | 278 (via fVar33) | |
| 152 | `ANTLER_MOD` | 289 (via fVar33) | |
| 153 | `ANTLER_SCALEH` | 285 (via fVar33) | |
| 154 | `ANTLER_SCALEW` | 283 (via fVar33), 284 (via fVar33) | |
| 155 | `ANTLER_ANGLE` | 280 (via fVar33) | |
| 156 | `ANTLER_ANGLE2` | 281 (via fVar33) | |
| 157 | `ANTLER_ANGLE_RAND` | 282 (via fVar33) | |
| 158 | `ANTLER_T1` | 287 (via fVar33) | |
| 159 | `ANTLER_T2` | 288 (via fVar33) | |
| 161 | `HAT_SIZE` | 290 (via fVar33), 291 (combined-with-others (fVar43 * fVar33)) | |
| 162 | `HAT_RAKE` | 267 (via fVar33) | |
| 163 | `HAT_ASPECT` | 291 (combined-with-others (fVar43 * fVar33)), 315 (via fVar43) | |
| 164 | `HAT_TAPER` | 292 (via fVar33) | |
| 165 | `HAT_POM` | 293 (via fVar33), 298 (via fVar33) | |
| 167 | `HAT_CLONE` | 294 (via fVar33) | |
| 168 | `HAT_BACK_SCALE` | 307 (via fVar33) | |
| 169 | `HAT_FRONT_SCALE` | 308 (via fVar33) | |
| 170 | `HAT_BACK_ANGLE` | 302 (via fVar33) | |
| 171 | `HAT_FRONT_ANGLE` | 303 (via fVar33) | |
| 172 | `HAT_ANGLE_RAND` | 304 (via fVar33) | |
| 174 | `HAT_T` | 309 (via fVar33), 310 (via fVar33), 314 (via fVar33), 315 (via fVar33) | |
| 178 | `BASE_GREEN` | 316 (via iVar17 (expr: local_308[iVar17])) | |
| 186 | `SWAP_ALT_SPOT` | 317 (via iVar20 (expr: local_318[iVar20])) | |
| 197 | `RACCOON_EYE` | 231 (via fVar35) | |
| 198 | `EAR_COMP` | 233 (via fVar35) | |
| 200 | `PAT_SPLIT` | 333 (via fVar33) | |
| 201 | `PAT_BELLY` | 15 (via fVar35 (expr: param_1[1] - fVar35)), 334 (via fVar33) | |
| 202 | `PAT_STRIPE` | 336 (via fVar33) | |
| 203 | `PAT_SPOT` | 337 (via fVar33) | |
| 204 | `PAT_PERLIN` | 340 (via fVar33) | |
| 205 | `PAT_PERLIN2` | 341 (via fVar33), 350 (via fVar34 (expr: fVar34 + fVar34)) | |
| 206 | `PAT_PERLIN_SIZE` | 342 (via fVar33 (expr: (float)(int)fVar33)), 350 (via fVar33 (expr: param_1[0x15e] * fVar33)) | |
| 212 | `LITTER_SIZE` | 322 (via fVar33), 349 (via fVar33) | |
| 213 | `OLD_AGE` | 351 (via iVar15 (expr: (float)(iVar15 + 9))) | |
| 214 | `LIMP` | 132 (combined-with-others ((fVar41 * fVar35 * fVar40) / fVar39)), 194 (via fVar35 (expr: param_1[0xbb] * fVar35)), 195 (via fVar35 (expr: param_1[0xbb] * fVar35)) | |
| 218 | `STIFF_JOINTS` | 26 (via fVar33 (expr: fVar33 * param_1[0x1a])), 27 (via fVar33 (expr: fVar33 * param_1[0x1b])), 45 (via fVar33 (expr: fVar33 * param_1[0x2d])), 46 (via fVar33 (expr: fVar33 * param_1[0x2e])), 64 (via fVar33 (expr: fVar33 * param_1[0x40])), 65 (via fVar33 (expr: fVar33 * param_1[0x41])), 82 (via fVar33 (expr: fVar33 * param_1[0x52])), 83 (via fVar33 (expr: fVar33 * param_1[0x53])), 100 (via fVar33 (expr: fVar33 * param_1[100])), 101 (via fVar33 (expr: fVar33 * param_1[0x65])), 118 (via fVar33 (expr: fVar33 * param_1[0x76])), 119 (via fVar33 (expr: fVar33 * param_1[0x77])) | |
| 219 | `L_LEG_SIGNAL` | 38 (via fVar35) | |
| 220 | `L_LEG_FTOB_REACT` | 39 (via fVar35) | |
| 221 | `L_LEG_FTOB_EVENT` | 41 (via fVar35) | |
| 222 | `L_LEG_BTOF_REACT` | 40 (via fVar35) | |
| 223 | `L_LEG_BTOF_EVENT` | 42 (via fVar35) | |
| 224 | `L_ARM_SIGNAL` | 57 (via fVar35) | |
| 225 | `L_ARM_FTOB_REACT` | 58 (via fVar35) | |
| 226 | `L_ARM_FTOB_EVENT` | 60 (via fVar35) | |
| 227 | `L_ARM_BTOF_REACT` | 59 (via fVar35) | |
| 228 | `L_ARM_BTOF_EVENT` | 61 (via fVar35) | |
| 229 | `L_TAIL_SIGNAL` | 19 (via fVar35) | |
| 230 | `L_TAIL_FTOB_REACT` | 20 (via fVar35) | |
| 231 | `L_TAIL_FTOB_EVENT` | 22 (via fVar35) | |
| 232 | `L_TAIL_BTOF_REACT` | 21 (via fVar35) | |
| 233 | `L_TAIL_BTOF_EVENT` | 23 (via fVar35) | |
| 234 | `L_NECK_SIGNAL` | 111 (via fVar39) | |
| 235 | `L_NECK_FTOB_REACT` | 112 (via fVar39) | |
| 236 | `L_NECK_FTOB_EVENT` | 114 (via fVar39) | |
| 237 | `L_NECK_BTOF_REACT` | 113 (via fVar39) | |
| 238 | `L_NECK_BTOF_EVENT` | 115 (via fVar39) | |

## Buf-slot -> horse-struct field (consumer reads)

Auto-derived from `FUN_1400ab3d0` decomp by
`horseygame/extract-consumer-map.py`. Reads 61 distinct
buf slots; 23 are direct copies to a horse-struct field,
the rest feed conditionals or intermediate math.

| Buf slot | Horse struct field(s) | Note |
|---|---|---|
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

## Confirmed visible-effect slots

Empirically verified by setting the slot to an extreme
value via the D5 post-hook and observing in-game.

| Slot | Set value | Visible effect | Set via |
|---|---|---|---|
| 0 | 200.0 | "Full screen width" babies (mated 2 horses, offspring rendered enormously wide). Drives some primary scale-like parameter. | `BX_TEST_SLOT0` set mode (3,3) blend = 200.0 |
