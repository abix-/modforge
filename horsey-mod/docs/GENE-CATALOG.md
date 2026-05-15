# Gene catalog (all 240 vanilla genes)
> **Authoritative on:** per-gene reference for all 240 vanilla genes (alleles, slots written, slots gated, semantic notes).

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
| 188 | `WHITE_IS_LETHAL` | 1 | 0 | 1 | 0 | 0 | 100 | AGCT | 313 | - | L2618 |   |

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
| 212 | `LITTER_SIZE` | 1 | 1 | 2 | 3 | 5 | 100 | CTAG | 322, 349 | - | L3166 |   |
| 213 | `OLD_AGE` | 1 | 0 | 0 | -1 | 2 | 100 | TACG | 351 | - | L3174 |   |
| 214 | `LIMP` | 1 | 0 | 1 | 0 | 2 | 100 | AGTC | 132, 194, 195 | 347 | L764, L2964 |   |
| 215 | `NARCOLEPSY` | 1 | 0 | 0 | 1 | 0 | 100 | TCGA | - | 347 | L2972 |   |
| 216 | `FLU_IMMUNITY` | 1 | 0 | 0 | 0 | 1 | 100 | CATG | _unread_ | _unread_ | - | DEAD. Behavioral, never read by engine. Likely unfinished. Free slot. |
| 217 | `TAIL_WAG` | 1 | 1 | 0 | 0 | 0 | 100 | CTGA | - | 347 | L2982 |   |
| 218 | `STIFF_JOINTS` | 100 | 0 | 18 | 50 | 0 | 100 | CGAT | 26, 27, 45, 46, 64, 65, 82, 83, 100, 101, 118, 119 | - | L3136 |   |

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
