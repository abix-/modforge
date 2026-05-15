# Gene catalog (all 240 vanilla genes)
Auto-generated from `vanilla-genes.xml` plus a flow
analysis of `FUN_14009f680`. Regenerate via
`research/build-gene-catalog.py`.

Columns:
- **idx**: 0-based position in `vanilla-genes.xml`.
- **scale**: 1 = discrete int allele, 100 = continuous/percent.
- **g0..g3**: the four allele values (vanilla).
- **mut**: mutation % from the XML `m` attribute.
- **codon**: 4-letter ACGT mapping (XML `n` attribute).
- **slots written**: param_1[N] writes that reference
  the temp var receiving the gene value (most reliable).
- **slots gated**: param_1[N] writes inside an `if`
  block whose condition is the gene's temp var. The
  gene doesn't supply the value but does decide *whether*
  the write happens.
- **calls**: line numbers of `FUN_1400a5d20/e00` calls.


## 0..10: Body fundamentals

| idx | name | scale | g0 | g1 | g2 | g3 | mut | codon | slots written | slots gated | calls |
|---|---|---|---|---|---|---|---|---|---|---|---|
| 0 | `SIZE` | 100 | 100 | 50 | 35 | 75 | 95 | ATGC | - | - | L432, L634 |
| 1 | `ASPECT` | 100 | 200 | 310 | 150 | 250 | 95 | GCAT | 343 | - | L438, L632 |
| 2 | `SKINNY` | 100 | 100 | 200 | 100 | 75 | 100 | GACT | - | - | L436 |
| 3 | `BONES` | 100 | 0 | -14 | 14 | 0 | 95 | GCAT | - | - | L414 |
| 4 | `BONES2` | 100 | 0 | 16 | -16 | 0 | 60 | TGCA | - | - | L420 |
| 5 | `CHEST_BIG` | 100 | 104 | 102 | 108 | 102 | 100 | ATCG | - | - | L430, L442 |
| 6 | `CHEST_SMALL` | 100 | 95 | 100 | 90 | 95 | 100 | GCTA | - | - | L428, L440 |
| 7 | `GIANT_DWARF` | 100 | 100 | 66 | 133 | 100 | 100 | GACT | - | - | L426 |
| 8 | `MUSCLE_USE` | 100 | 100 | 50 | 80 | 100 | 100 | CTAG | 132, 154, 155 | - | L784, L894, L934 |
| 9 | `QUADRUPED` | 1 | 1 | 0 | 1 | 0 | 100 | CGAT | - | - | L446 |
| 10 | `BIPED` | 1 | 0 | 1 | 0 | 1 | 100 | TAGC | - | - | L450 |

## 11..20: Body shape modifiers

| idx | name | scale | g0 | g1 | g2 | g3 | mut | codon | slots written | slots gated | calls |
|---|---|---|---|---|---|---|---|---|---|---|---|
| 11 | `SPLAY` | 1 | 0 | 10 | -5 | 45 | 100 | ACTG | 35, 38, 39, 40, 41, 42, 43, 54 | - | L1592, L1766, L2188 |
| 12 | `LEG_IN` | 100 | 0 | 18 | 6 | 0 | 50 | CGAT | 33, 35, 38, 39, 41, 54 | - | L1578, L1752 |
| 13 | `LEG_IN2` | 100 | 0 | 13 | 0 | 1 | 100 | CGAT | - | - | L1574, L1748 |
| 14 | `GUT` | 100 | 0 | 25 | 45 | 0 | 100 | TGAC | 4, 6, 7, 8 | - | L578 |
| 15 | `GUT_IS_UDDER` | 1 | 0 | 1 | 0 | 2 | 100 | ACGT | 6, 7, 8 | 10 | L582 |
| 16 | `OSTODERM` | 1 | 1 | 0 | 1 | 2 | 100 | GATC | 7, 8 | 10 | L586 |
| 17 | `OSTO_SIZE` | 100 | 30 | 15 | 45 | 45 | 85 | TACG | 8 | 10 | L590 |
| 18 | `DERRIERE` | 100 | 0 | 40 | 70 | 10 | 85 | CTGA | 5, 10 | 10 | L602 |
| 19 | `SPEED_FACTOR` | 100 | 100 | 30 | 50 | 133 | 75 | GCAT | 126, 133, 134, 147, 154, 155, 350 | - | L808, L952, L3110 |
| 20 | `BREAK_FORCE` | 10 | 0 | 54 | 0 | 35 | 100 | GATC | 35, 45, 47, 57, 58, 59, 60, 61, 66 | - | L1620, L1708 |

## 21..33: Tail

| idx | name | scale | g0 | g1 | g2 | g3 | mut | codon | slots written | slots gated | calls |
|---|---|---|---|---|---|---|---|---|---|---|---|
| 21 | `TAIL_TAG` | 1 | 3 | 4 | 2 | 1 | 100 | TAGC | 16, 18, 24 | - | L1430 |
| 22 | `TAIL_EXISTS` | 1 | 1 | 0 | 1 | 2 | 100 | GCAT | 165, 169 | 347 | L658 |
| 23 | `TAIL_SIZE` | 100 | 100 | 80 | 120 | 140 | 60 | GCAT | 166 | - | L662 |
| 24 | `TAIL_SHORT` | 100 | 100 | 50 | 35 | 100 | 100 | CAGT | - | - | L674 |
| 25 | `TAIL_ASPECT` | 100 | 20 | 10 | 30 | 50 | 90 | AGCT | 166 | - | L668 |
| 26 | `TAIL_ANGLE` | 1 | 45 | 90 | 135 | 60 | 100 | GCAT | 16, 24, 26, 27 | - | L1444 |
| 27 | `TAIL_JOINT_TYPE` | 1 | 0 | 1 | 0 | 0 | 100 | ATGC | 24, 26, 27 | - | L1448 |
| 28 | `TAIL_STIFF` | 1 | 0 | 1 | 0 | 1 | 100 | ATGC | 6 | - | L1452 |
| 29 | `TAIL_SPEED` | 10 | 60 | 200 | 60 | 0 | 100 | GCAT | 167, 175, 176 | - | L710 |
| 30 | `TAIL_FLEXIBILITY` | 1 | 135 | 90 | 45 | 15 | 100 | GTAC | 26, 27 | - | L1460 |
| 31 | `TAIL_SHAPE` | 1 | 2 | 1 | 5 | 6 | 100 | AGTC | 169 | 169, 347 | L680 |
| 32 | `TAIL_BOTTOM` | 1 | 0 | 1 | 0 | 0 | 100 | GTCA | 10 | 15, 16, 24, 347 | L1520, L1928 |
| 33 | `TAIL_SEGMENTS` | 1 | 3 | 0 | 3 | 5 | 100 | GTCA | 123, 167, 169, 170 | - | L716 |

## 34..49: Legs

| idx | name | scale | g0 | g1 | g2 | g3 | mut | codon | slots written | slots gated | calls |
|---|---|---|---|---|---|---|---|---|---|---|---|
| 34 | `LEG_TAG` | 1 | 1 | 2 | 4 | 3 | 100 | ATGC | 33, 35, 37 | - | L1568 |
| 35 | `LEG_TYPE` | 1 | 1 | 2 | 0 | 1 | 100 | TACG | 123 | 124, 125 | L730 |
| 36 | `LEG_LENGTH` | 100 | 80 | 50 | 120 | 100 | 90 | CATG | 125 | - | L738 |
| 37 | `LEG_STRETCH` | 100 | 0 | 14 | -14 | 0 | 60 | GACT | 124, 125, 146 | - | L734, L904 |
| 38 | `LEG_STRETCH2` | 100 | 0 | -16 | 16 | 0 | 100 | ATCG | 125, 145, 146 | - | L736, L908 |
| 39 | `LEG_STRENGTH` | 100 | 95 | 120 | 80 | 104 | 60 | GCTA | 124, 125, 131, 132, 133, 134 | - | L742, L790 |
| 40 | `LEG_HAS_FOOT` | 1 | 1 | 1 | 0 | 0 | 100 | GACT | 35 | - | L758 |
| 41 | `LEG_JOINT_TYPE` | 1 | 0 | 1 | 2 | 0 | 100 | AGTC | 35, 43, 45, 47 | - | L1616 |
| 42 | `LEG_FLEXIBILITY` | 1 | 30 | 20 | 40 | 50 | 80 | GTCA | 35, 45, 46 | - | L1634, L1664, L1670 |
| 43 | `LEG_FLEX_BIAS` | 1 | 15 | 20 | 10 | -10 | 100 | CGAT | 35, 45, 46 | - | L1642, L1662, L1668 |
| 44 | `LEG_THRUST_BACK` | 1 | 0 | 1 | 0 | 2 | 100 | GCTA | - | 35, 45, 46, 54 | L1650, L2184 |
| 45 | `LEG_IS_CIRCLE` | 1 | 0 | 1 | 0 | 0 | 100 | ATGC | 35, 54 | 124, 125, 127, 208 | L864, L1040 |
| 46 | `LEG_COUNT` | 1 | 1 | 1 | 2 | 7 | 100 | CGTA | 31, 37, 55, 56 | - | L1680 |
| 47 | `LEG_SKEW` | 100 | 0 | 24 | -16 | 0 | 60 | TCGA | - | - | L826 |
| 48 | `LEG_PENCIL` | 100 | 0 | 10 | 0 | 0 | 100 | ATGC | 124, 125, 132 | - | L876 |
| 49 | `LEG_AND_ARM_LIMP` | 1 | 0 | 0 | 0 | 1 | 100 | TAGC | 11, 15 | - | L1624, L1712 |

## 50..66: Knee + Arm

| idx | name | scale | g0 | g1 | g2 | g3 | mut | codon | slots written | slots gated | calls |
|---|---|---|---|---|---|---|---|---|---|---|---|
| 50 | `HAS_KNEE` | 1 | 0 | 1 | 0 | 0 | 100 | TCGA | - | 127 | L832, L848 |
| 51 | `KNEE_MIN` | 1 | 0 | -90 | -15 | 0 | 100 | CGAT | - | - | L836 |
| 52 | `KNEE_MAX` | 1 | 20 | 90 | 45 | 20 | 100 | TAGC | - | - | L852 |
| 53 | `ARM_TAG` | 1 | 1 | 2 | 4 | 3 | 100 | GTAC | 56, 57, 58, 59, 60, 66 | - | L1704 |
| 54 | `ARM_TYPE` | 1 | 1 | 2 | 0 | 0 | 100 | CGAT | 144 | 146 | L900 |
| 55 | `ARM_LENGTH` | 100 | 80 | 50 | 120 | 25 | 90 | ATCG | 146 | - | L910 |
| 56 | `ARM_STRETCH` | 100 | 0 | 14 | -14 | 0 | 60 | GACT | _unread_ | _unread_ | - |
| 57 | `ARM_STRETCH2` | 100 | 0 | -16 | 16 | 0 | 100 | TCAG | _unread_ | _unread_ | - |
| 58 | `ARM_STRENGTH` | 100 | 95 | 120 | 80 | 104 | 60 | ATCG | 145, 152, 153 | - | L914, L936 |
| 59 | `ARM_HAS_HAND` | 1 | 1 | 0 | 1 | 0 | 100 | CGTA | 40 | - | L926 |
| 60 | `ARM_JOINT_TYPE` | 1 | 0 | 1 | 2 | 0 | 100 | GCTA | 52, 62 | - | L1736 |
| 61 | `ARM_FLEXIBILITY` | 1 | 30 | 20 | 40 | 30 | 100 | ACTG | 54, 64, 65 | - | L1778, L1796, L1800 |
| 62 | `ARM_FLEX_BIAS` | 1 | 15 | 20 | 10 | 0 | 100 | GCTA | 54, 64, 65 | - | L1786, L1794, L1802 |
| 63 | `ARM_FORWARD` | 1 | -20 | 0 | 60 | 40 | 100 | CTGA | 54, 64 | - | L1768 |
| 64 | `ARM_SKEW` | 100 | 0 | 20 | -20 | 0 | 100 | TCGA | - | - | L966 |
| 65 | `ARM_NODE_SCALE` | 100 | 100 | 70 | 130 | 100 | 50 | CTGA | 55, 56, 57, 58, 60, 66 | - | L1700 |
| 66 | `HAS_ELBOW` | 1 | 0 | 1 | 0 | 0 | 100 | CATG | 51 | - | L972 |

## 67..71: Upper arm

| idx | name | scale | g0 | g1 | g2 | g3 | mut | codon | slots written | slots gated | calls |
|---|---|---|---|---|---|---|---|---|---|---|---|
| 67 | `ELBOW_RANGE` | 1 | 30 | 90 | 10 | 30 | 100 | CTAG | - | - | L976 |
| 68 | `UPARM_TAG` | 1 | 0 | 2 | 1 | 4 | 100 | ATCG | 17, 74 | - | L1832 |
| 69 | `UPARM_Y` | 100 | 30 | 10 | 30 | 50 | 80 | CTAG | - | - | L1850 |
| 70 | `UPARM_ANGLE` | 1 | 0 | 30 | -30 | -45 | 100 | GCAT | 72 | - | L1864 |
| 71 | `UPARM_GOOFY` | 1 | 0 | 1 | 2 | 3 | 100 | ACGT | - | 17, 21, 88, 89, 90 | L1892 |

## 72..86: Neck

| idx | name | scale | g0 | g1 | g2 | g3 | mut | codon | slots written | slots gated | calls |
|---|---|---|---|---|---|---|---|---|---|---|---|
| 72 | `NECK_TAG` | 1 | 4 | 3 | 1 | 2 | 100 | AGTC | 107, 110, 188 | - | L1960 |
| 73 | `NECK_TYPE` | 1 | 1 | 1 | 2 | 0 | 100 | TACG | 186 | 106, 107, 188 | L1096, L1114, L1976, L2046 |
| 74 | `NECK_LENGTH` | 100 | 60 | 70 | 90 | 30 | 90 | ATGC | 188 | - | L1100 |
| 75 | `NECK_GIRAFFE` | 100 | 110 | 0 | 85 | 120 | 90 | TCAG | 187, 188 | - | L1104 |
| 76 | `NECK_THICKNESS` | 100 | 95 | 110 | 120 | 80 | 60 | CGTA | 187 | - | L1108 |
| 77 | `NECK_ANGLE` | 1 | 45 | 30 | 60 | 75 | 90 | TACG | 108, 110, 188 | - | L1952 |
| 78 | `NECK_COCK` | 1 | 0 | 30 | 20 | -25 | 100 | CGAT | 108 | - | L1956 |
| 79 | `NECK_JOINT_TYPE` | 1 | 1 | 0 | 2 | 0 | 100 | TGCA | 116, 118, 119 | - | L2090 |
| 80 | `NECK_FLEXIBILITY` | 1 | 23 | 10 | 40 | 0 | 100 | GTCA | 108, 118, 119 | - | L2108, L2114, L2126 |
| 81 | `NECK_FLEX_BIAS` | 1 | -8 | 0 | -25 | 30 | 100 | GATC | 108, 118, 119 | - | L2106, L2112, L2134 |
| 82 | `NECK_SLOUCH` | 100 | 0 | 50 | 20 | 0 | 60 | CTGA | 107 | 106 | L1994 |
| 83 | `NECK_ONTOP` | 100 | 0 | 50 | 70 | 20 | 100 | GTCA | - | - | L458, L1970 |
| 84 | `NECK_STIFF` | 1 | 0 | 1 | 0 | 1 | 100 | CATG | 29 | - | L2094 |
| 85 | `NECK_SPEED` | 10 | 60 | 25 | 50 | 10 | 100 | AGCT | 196, 197 | - | L1134 |
| 86 | `HAS_FOOT` | 1 | 1 | 0 | 1 | 0 | 100 | TACG | 51 | - | L992 |

## 87..96: Foot + Hand

| idx | name | scale | g0 | g1 | g2 | g3 | mut | codon | slots written | slots gated | calls |
|---|---|---|---|---|---|---|---|---|---|---|---|
| 87 | `FOOT_SIZE` | 100 | 0 | 20 | 12 | 30 | 60 | GTAC | 12, 209, 211 | - | L768, L998, L1014 |
| 88 | `FOOT_CLOWN` | 100 | 0 | 30 | 0 | 0 | 100 | GTAC | - | - | L1008 |
| 89 | `FOOT_THICKNESS` | 100 | 20 | 15 | 30 | 7 | 80 | TCAG | 12, 54, 210, 211 | - | L1018 |
| 90 | `FOOT_TOE` | 100 | 100 | 0 | 50 | 100 | 100 | AGCT | 12, 54, 210 | - | L770, L1022 |
| 91 | `FOOT_IS_CIRCLE` | 1 | 0 | 1 | 0 | 0 | 100 | GACT | 35, 54 | 208 | L868, L1042 |
| 92 | `FOOT_BACKWARDS` | 1 | 0 | 1 | 0 | 2 | 100 | AGCT | 54 | - | L1048 |
| 93 | `HAS_HAND` | 1 | 0 | 1 | 0 | 1 | 100 | CGTA | 54 | - | L1052 |
| 94 | `HAND_WIDTH` | 100 | 0 | 7 | 20 | 0 | 100 | GACT | 219, 221, 223 | - | L1062 |
| 95 | `HAND_LENGTH` | 100 | 20 | 30 | 15 | 20 | 90 | CGAT | 221, 223 | - | L1066 |
| 96 | `HAND_FINGER` | 100 | 0 | 100 | 0 | 50 | 80 | CTGA | 223 | - | L1076 |

## 97..117: Head + Eye + Brow

| idx | name | scale | g0 | g1 | g2 | g3 | mut | codon | slots written | slots gated | calls |
|---|---|---|---|---|---|---|---|---|---|---|---|
| 97 | `HEAD_SIZE` | 100 | 100 | 50 | 133 | 75 | 95 | GCTA | - | - | L1146 |
| 98 | `HEAD_THICK_SKULL` | 100 | 0 | 20 | 0 | 0 | 100 | TGAC | - | - | L1144 |
| 99 | `HEAD_X_GROWTH` | 100 | 0 | 5 | 10 | -5 | 100 | ACGT | 227, 228 | - | L1158 |
| 100 | `HEAD_Y_GROWTH` | 100 | 0 | 5 | -5 | 0 | 100 | TACG | 228, 231, 235, 237 | - | L1182 |
| 101 | `HEAD_ASPECT` | 100 | 200 | 175 | 250 | 300 | 85 | TCAG | - | - | L1154 |
| 102 | `HEAD_SQUARE` | 100 | 0 | 150 | 100 | 0 | 100 | CTAG | - | - | L1150 |
| 103 | `HEAD_HAS_BACK` | 1 | 11 | 0 | 0 | 1 | 100 | GTCA | 57 | - | L1224 |
| 104 | `HEAD_GIANT` | 100 | 100 | 200 | 180 | 100 | 90 | CTAG | - | - | L1142 |
| 105 | `HEAD_SHRUNK` | 100 | 100 | 70 | 50 | 100 | 90 | CATG | - | 347 | L1140, L3040 |
| 106 | `HEAD_JOINTED` | 1 | 0 | 1 | 0 | 0 | 100 | CATG | - | - | L1126 |
| 107 | `HEAD_CHIMERA` | 1 | 0 | 1 | 0 | 0 | 100 | ATCG | _unread_ | _unread_ | - |
| 108 | `EYE_STYLE` | 1 | 1 | 2 | 1 | 0 | 100 | CATG | 235, 237 | - | L1190 |
| 109 | `BUGEYE` | 1 | 0 | 1 | 0 | 2 | 100 | GACT | - | 58, 237, 238 | L1194, L1266 |
| 110 | `EYEBOX_X` | 100 | 33 | 0 | 50 | 15 | 90 | AGCT | - | - | L1198 |
| 111 | `EYEBOX_Y` | 100 | -100 | 0 | -50 | -25 | 100 | CGTA | 237 | - | L1204 |
| 112 | `EYEBOX_SIZE` | 100 | 25 | 15 | 33 | 50 | 60 | ATGC | 238 | - | L1208 |
| 113 | `EYE_SIZE` | 100 | 50 | 75 | 125 | 50 | 100 | ACTG | 239 | - | L1230 |
| 114 | `PUPIL_SIZE` | 100 | 66 | 80 | 40 | 40 | 100 | CAGT | - | - | L1248 |
| 115 | `HAS_PUPIL` | 1 | 1 | 0 | 0 | 0 | 100 | ATCG | - | - | L1236 |
| 116 | `BROW_SIZE` | 100 | 0 | 150 | 125 | 0 | 100 | GATC | 238, 241, 242 | - | L1256 |
| 117 | `BROW_SLANT` | 1 | 0 | -15 | 15 | 0 | 100 | GTAC | 238, 242, 243 | - | L1260 |

## 118..126: Ear + Teeth

| idx | name | scale | g0 | g1 | g2 | g3 | mut | codon | slots written | slots gated | calls |
|---|---|---|---|---|---|---|---|---|---|---|---|
| 118 | `EAR_STYLE` | 1 | 1 | 2 | 0 | 0 | 100 | TGCA | 243, 244, 245, 246, 248 | - | L1286 |
| 119 | `EAR_SHAPE` | 1 | 2 | 1 | 4 | 2 | 100 | CGAT | 244, 246, 248, 249, 250 | - | L1294 |
| 120 | `EAR_FLOP` | 1 | 0 | 30 | 60 | 200 | 100 | CTAG | 244, 245, 246, 248, 249 | - | L1290 |
| 121 | `EAR_X` | 100 | 0 | 100 | 50 | 0 | 90 | TAGC | - | - | L1306 |
| 122 | `EAR_SIZE` | 100 | 20 | 30 | 10 | 40 | 70 | TCGA | 233, 243, 248, 249, 250, 251, 252 | 233 | L1312 |
| 123 | `EAR_ASPECT` | 100 | 100 | 250 | 300 | 100 | 100 | ATCG | 249 | - | L1316 |
| 124 | `EAR_SLANT` | 100 | 0 | 100 | 50 | -33 | 70 | GACT | 233, 243, 250, 251, 252, 253, 255 | 233 | L1320 |
| 125 | `EAR_INTERIOR` | 100 | 5 | 0 | 0 | 0 | 100 | TAGC | 251, 252, 253, 254, 255 | - | L1334 |
| 126 | `TEETH_SHAPE` | 1 | 0 | 1 | 2 | 3 | 100 | TCGA | 252, 253, 254, 255, 257 | 208 | L1026, L1338 |

## 127..140: Mouth + Nose + Antler-precursor

| idx | name | scale | g0 | g1 | g2 | g3 | mut | codon | slots written | slots gated | calls |
|---|---|---|---|---|---|---|---|---|---|---|---|
| 127 | `HAS_MOUTH` | 1 | 1 | 1 | 0 | 1 | 100 | TCGA | - | 253, 254 | L1352 |
| 128 | `MOUTH_Y` | 100 | 70 | 84 | 50 | 100 | 80 | CGAT | 253, 254, 255, 257 | - | L1342 |
| 129 | `MOUTH_SIZE` | 100 | 20 | 30 | 10 | 40 | 70 | CTGA | 253, 254, 257 | - | L1346 |
| 130 | `JAW` | 100 | 0 | 15 | -8 | -13 | 50 | CAGT | 257, 258, 259 | - | L1362 |
| 131 | `TEETH_UPPER` | 1 | 1 | 0 | 0 | 0 | 100 | GATC | - | - | L1366 |
| 132 | `TEETH_UPPER2` | 1 | 1 | 0 | 0 | 0 | 100 | CATG | - | - | L1368 |
| 133 | `TONGUE` | 100 | 0 | 40 | 60 | 0 | 100 | CGAT | 258, 259, 261, 263, 264 | - | L1384 |
| 134 | `TONGUE_SEGS` | 1 | 0 | 1 | 2 | 0 | 100 | ACGT | 259, 261, 263, 264 | - | L1388 |
| 135 | `NOSE_STYLE` | 1 | 1 | 2 | 3 | 0 | 100 | GTCA | 261, 263, 264 | - | L1392 |
| 136 | `NOSE_INNY` | 1 | 0 | 1 | 0 | 0 | 100 | GCTA | 264 | - | L1412 |
| 137 | `NOSE_Y` | 100 | 0 | 100 | 50 | 0 | 90 | CTAG | 263, 264 | - | L1396 |
| 138 | `NOSE_SIZE` | 100 | 10 | 5 | 20 | 100 | 70 | AGCT | - | - | L1402 |
| 139 | `NOSE_INTERIOR` | 100 | 0 | 100 | 50 | 0 | 100 | ATGC | 265 | - | L1426 |
| 140 | `HAS_ANTLERS` | 1 | 1 | 0 | 1 | 1 | 100 | CTGA | - | 268, 290, 347 | L2402, L2940 |

## 141..159: Antlers

| idx | name | scale | g0 | g1 | g2 | g3 | mut | codon | slots written | slots gated | calls |
|---|---|---|---|---|---|---|---|---|---|---|---|
| 141 | `ANTLER_X` | 1 | 1 | 0 | 2 | 1 | 100 | TGAC | 266, 267, 268, 269, 270, 271, 275 | - | L2198 |
| 142 | `ANTLER_W` | 100 | 15 | 12 | 8 | 12 | 100 | TACG | 268, 269, 270, 271, 275 | - | L2206 |
| 143 | `ANTLER_H` | 100 | 65 | 45 | 100 | 25 | 80 | TACG | 269, 270, 271, 275 | - | L2210 |
| 144 | `ANTLER_TAPER` | 100 | 0 | 100 | 50 | 100 | 100 | CGAT | 270, 271, 275, 276 | - | L2214 |
| 145 | `ANTLER_POM` | 100 | 0 | 150 | 200 | 100 | 100 | CTGA | 271, 275, 276 | - | L2218 |
| 146 | `ANTLER_COLOR` | 1 | 2 | 8 | 1 | 3 | 100 | ACGT | 275, 276, 277, 278 | - | L2224 |
| 147 | `POM_COLOR` | 1 | 2 | 0 | 1 | 17 | 100 | GCTA | - | - | L2238 |
| 148 | `POM_USECOLOR` | 1 | 1 | 0 | 0 | 0 | 100 | GTAC | 69 | - | L2228 |
| 149 | `ANTLER_REC` | 1 | 2 | 1 | 3 | 0 | 100 | TAGC | 277, 278, 280, 283, 284, 285 | - | L2246 |
| 150 | `ANTLER_REC2` | 1 | 2 | 1 | 3 | 0 | 100 | CTGA | 278, 280, 281, 283, 284, 285 | - | L2250 |
| 151 | `ANTLER_FLIP` | 1 | 1 | 0 | 0 | 0 | 100 | TACG | 69 | - | L2254 |
| 152 | `ANTLER_MOD` | 1 | 3 | 2 | 1 | 3 | 100 | TCAG | - | - | L2298 |
| 153 | `ANTLER_SCALEH` | 100 | 100 | 75 | 40 | 100 | 80 | GCTA | 280, 281, 282, 283, 284, 285, 287 | - | L2258 |
| 154 | `ANTLER_SCALEW` | 100 | 100 | 75 | 50 | 100 | 100 | TCGA | 280, 281, 282, 283, 284, 287, 288 | - | L2262 |
| 155 | `ANTLER_ANGLE` | 1 | 45 | -45 | -25 | 25 | 100 | GATC | 280, 281, 282, 287, 288 | - | L2270 |
| 156 | `ANTLER_ANGLE2` | 1 | 45 | -45 | 90 | -90 | 100 | ACTG | 281, 282, 287, 288, 289 | - | L2274 |
| 157 | `ANTLER_ANGLE_RAND` | 1 | 0 | 5 | 45 | 15 | 100 | GTAC | 282, 287, 288, 289 | - | L2278 |
| 158 | `ANTLER_T1` | 100 | 0 | 100 | 40 | 25 | 100 | CGAT | 287, 288, 289 | - | L2282 |
| 159 | `ANTLER_T2` | 100 | 100 | 40 | 0 | 25 | 100 | ATGC | 288, 289 | - | L2286 |

## 160..174: Hat

| idx | name | scale | g0 | g1 | g2 | g3 | mut | codon | slots written | slots gated | calls |
|---|---|---|---|---|---|---|---|---|---|---|---|
| 160 | `HAT_EXISTS` | 1 | 1 | 0 | 0 | 0 | 100 | ACTG | - | - | L2306 |
| 161 | `HAT_SIZE` | 100 | 60 | 40 | 100 | 20 | 85 | CATG | - | - | L2316, L2946 |
| 162 | `HAT_RAKE` | 100 | 0 | 25 | -15 | 0 | 100 | AGTC | 267, 268, 269, 270, 271, 275 | - | L2202 |
| 163 | `HAT_ASPECT` | 100 | 100 | 300 | 200 | 100 | 85 | ATGC | 291 | - | L2322 |
| 164 | `HAT_TAPER` | 100 | 0 | 100 | 50 | 0 | 100 | TGCA | 292, 293, 294, 298 | - | L2326 |
| 165 | `HAT_POM` | 100 | 0 | 25 | 50 | 0 | 100 | TGAC | 293 | - | L2334 |
| 166 | `HAT_POM_IS_LID` | 1 | 0 | 1 | 0 | 0 | 100 | TAGC | - | 293 | L2330 |
| 167 | `HAT_CLONE` | 100 | 0 | 33 | 66 | 0 | 100 | CGTA | 294, 307, 308 | - | L2352 |
| 168 | `HAT_BACK_SCALE` | 100 | 100 | 0 | 60 | 100 | 100 | TAGC | 302, 303, 304, 307, 308, 309, 310 | - | L2368 |
| 169 | `HAT_FRONT_SCALE` | 100 | 100 | 0 | 60 | 100 | 100 | CGTA | 302, 303, 304, 308, 309, 310 | - | L2374 |
| 170 | `HAT_BACK_ANGLE` | 1 | 45 | 90 | 120 | 60 | 75 | ACGT | 302, 303, 304, 309, 310 | - | L2380 |
| 171 | `HAT_FRONT_ANGLE` | 1 | -45 | -90 | -120 | -60 | 100 | CGAT | 303, 304, 309, 310 | - | L2384 |
| 172 | `HAT_ANGLE_RAND` | 1 | 0 | 15 | 45 | 15 | 100 | TCGA | 304, 309, 310 | - | L2388 |
| 173 | `HAT_FLIP` | 1 | 0 | 1 | 0 | 0 | 100 | TACG | 75 | - | L2364 |
| 174 | `HAT_T` | 100 | 0 | 100 | 40 | 0 | 100 | GTAC | 309, 310 | - | L2392 |

## 175..188: Palette / coloration base

| idx | name | scale | g0 | g1 | g2 | g3 | mut | codon | slots written | slots gated | calls |
|---|---|---|---|---|---|---|---|---|---|---|---|
| 175 | `BASE_BROWN` | 1 | 0 | 1 | 2 | 0 | 100 | ATCG | - | - | L2412 |
| 176 | `BASE_BLACK` | 1 | 0 | 1 | 0 | 1 | 100 | TGCA | - | 137, 158, 179, 200, 215, 225, 230, 232, 312, 347 | L2734, L3050 |
| 177 | `BASE_RED` | 1 | 0 | 1 | 2 | 3 | 100 | GTCA | - | - | L2416 |
| 178 | `BASE_GREEN` | 1 | 0 | 1 | 2 | 3 | 70 | TCAG | - | - | L2422 |
| 179 | `GREEN_KNOCKOUT` | 1 | 0 | 1 | 0 | 0 | 100 | CAGT | - | - | L2418 |
| 180 | `BASE_CREAM` | 100 | 0 | 100 | 0 | 0 | 50 | AGCT | - | 315 | L2546 |
| 181 | `ALT_BLUE` | 1 | 0 | 1 | 2 | 3 | 100 | TAGC | - | 315 | L2556 |
| 182 | `SPOT_YELLOW` | 1 | 0 | 1 | 0 | 1 | 100 | TGCA | - | - | L2578 |
| 183 | `SKIN_HUE` | 1 | 0 | 1 | 2 | 3 | 100 | CGAT | _unread_ | _unread_ | - |
| 184 | `SKIN_HUE2` | 1 | 0 | 1 | 2 | 3 | 100 | TAGC | _unread_ | _unread_ | - |
| 185 | `SWAP_BASE_SPOT` | 1 | 0 | 1 | 0 | 1 | 100 | ATCG | - | 312, 313, 314, 315 | L2664 |
| 186 | `SWAP_ALT_SPOT` | 1 | 0 | 1 | 0 | 1 | 100 | TGCA | - | 314, 315 | L2680 |
| 187 | `WHITE` | 1 | 1 | 0 | 0 | 0 | 100 | TAGC | 313 | 314, 315 | L2616 |
| 188 | `WHITE_IS_LETHAL` | 1 | 0 | 1 | 0 | 0 | 100 | AGCT | 313 | - | L2618 |

## 189..218: Colors + patterns + behavioral

| idx | name | scale | g0 | g1 | g2 | g3 | mut | codon | slots written | slots gated | calls |
|---|---|---|---|---|---|---|---|---|---|---|---|
| 189 | `EYE_HUE` | 1 | 36 | 237 | 153 | 198 | 100 | GCTA | 252 | 347 | L2726, L3084 |
| 190 | `NOSE_HUE` | 1 | 0 | 1 | 2 | 3 | 100 | GACT | - | 347 | L3018 |
| 191 | `HOOF_COLOR` | 1 | 0 | 1 | 2 | 0 | 100 | CTAG | - | - | L2702 |
| 192 | `AGOUTI` | 1 | 1 | 0 | 0 | 1 | 100 | ATGC | - | 135, 137, 138, 158, 179, 200, 215, 225, 230, 232, 312 | L2738 |
| 193 | `BELLY_ALT` | 1 | 0 | 1 | 2 | 1 | 100 | TACG | 83 | 137, 158, 215, 225 | L2786, L2802, L2902 |
| 194 | `SKIN_HEAD` | 1 | 0 | 1 | 0 | 2 | 100 | GCAT | - | 136, 137, 157, 158, 200, 225, 230, 232, 312 | L2846, L2856 |
| 195 | `SKIN_HANDS` | 1 | 0 | 1 | 0 | 2 | 100 | GCAT | - | 136, 137, 157, 158, 178, 179, 215, 225 | L2866, L2874 |
| 196 | `FOOT_IS_HOOF` | 1 | 0 | 1 | 0 | 1 | 100 | GACT | - | 200, 208, 215, 230, 232, 312 | L1028, L2838 |
| 197 | `RACCOON_EYE` | 1 | 0 | 1 | 2 | 0 | 100 | GCAT | 231, 235, 237, 252 | 347 | L1186, L3092 |
| 198 | `EAR_COMP` | 1 | 0 | 0 | 2 | 1 | 100 | GTCA | 233, 243, 251, 252, 253, 254, 255 | 233 | L1324 |
| 199 | `TAIL_ALT` | 1 | 0 | 1 | 2 | 0 | 100 | CGTA | - | 179, 215 | L2818, L2828 |
| 200 | `PAT_SPLIT` | 100 | 0 | 100 | 65 | 0 | 100 | CGAT | 333, 334, 336, 337, 340 | - | L2894 |
| 201 | `PAT_BELLY` | 100 | 100 | 50 | 33 | 75 | 100 | ACTG | 334, 336, 337, 340, 341 | - | L1506, L2898 |
| 202 | `PAT_STRIPE` | 100 | 0 | 90 | 51 | 0 | 100 | CTAG | 336, 337, 340, 341, 342 | - | L2906 |
| 203 | `PAT_SPOT` | 100 | 0 | 90 | 51 | 0 | 100 | ACGT | 337, 340, 341, 342 | - | L2910 |
| 204 | `PAT_PERLIN` | 100 | 0 | 100 | 60 | 0 | 100 | TCAG | 340, 341, 342 | - | L2918 |
| 205 | `PAT_PERLIN2` | 100 | 0 | 100 | 60 | 0 | 100 | GTCA | 341, 342 | 347 | L2922, L3066 |
| 206 | `PAT_PERLIN_SIZE` | 1 | 8 | 2 | 4 | 4 | 100 | GACT | 342 | - | L2926 |
| 207 | `RAMPAGE` | 1 | 0 | 0 | 0 | 1 | 100 | GATC | 252 | - | L3100 |
| 208 | `SPINAL_LOCO` | 1 | 0 | 1 | 0 | 2 | 100 | CTGA | - | 45, 46, 64, 65, 82, 83, 100, 101, 134, 347, 350 | L2954, L3126 |
| 209 | `BRAIN_SPASTIC` | 1 | 0 | 1 | 2 | 0 | 100 | TGAC | _unread_ | _unread_ | - |
| 210 | `HIGH_INTELLECT` | 1 | 0 | 1 | 0 | 1 | 100 | CTAG | - | 347 | L2930 |
| 211 | `OMNIVORE` | 1 | 0 | 1 | 0 | 0 | 100 | CATG | 87, 351 | - | L3170 |
| 212 | `LITTER_SIZE` | 1 | 1 | 2 | 3 | 5 | 100 | CTAG | 349 | - | L3166 |
| 213 | `OLD_AGE` | 1 | 0 | 0 | -1 | 2 | 100 | TACG | 351 | - | L3174 |
| 214 | `LIMP` | 1 | 0 | 1 | 0 | 2 | 100 | AGTC | - | 347 | L764, L2964 |
| 215 | `NARCOLEPSY` | 1 | 0 | 0 | 1 | 0 | 100 | TCGA | - | 347 | L2972 |
| 216 | `FLU_IMMUNITY` | 1 | 0 | 0 | 0 | 1 | 100 | CATG | _unread_ | _unread_ | - |
| 217 | `TAIL_WAG` | 1 | 1 | 0 | 0 | 0 | 100 | CTGA | - | 347 | L2982 |
| 218 | `STIFF_JOINTS` | 100 | 0 | 18 | 50 | 0 | 100 | CGAT | 26, 27, 45, 46, 64, 65, 82, 83, 100, 101, 118, 119 | - | L3136 |

## 219..239: Animation signals

| idx | name | scale | g0 | g1 | g2 | g3 | mut | codon | slots written | slots gated | calls |
|---|---|---|---|---|---|---|---|---|---|---|---|
| 219 | `L_LEG_SIGNAL` | 1 | 1 | 1 | 1 | 2 | 100 | GTCA | 38, 39, 40, 41, 42, 43, 47 | - | L1596 |
| 220 | `L_LEG_FTOB_REACT` | 1 | 1 | 2 | 1 | 3 | 100 | TCAG | 39, 40, 41, 42, 43, 47 | - | L1600 |
| 221 | `L_LEG_FTOB_EVENT` | 1 | 3 | 1 | 2 | 4 | 100 | GATC | 40, 41, 42, 43, 47 | - | L1604 |
| 222 | `L_LEG_BTOF_REACT` | 1 | 2 | 1 | 2 | 3 | 100 | ACGT | 40, 42, 43, 45, 47 | - | L1608 |
| 223 | `L_LEG_BTOF_EVENT` | 1 | 2 | 3 | 1 | 4 | 100 | TGAC | 42, 43, 45, 47 | - | L1612 |
| 224 | `L_ARM_SIGNAL` | 1 | 2 | 2 | 2 | 1 | 100 | CGAT | 57, 58, 59, 60, 61, 62 | - | L1716 |
| 225 | `L_ARM_FTOB_REACT` | 1 | 2 | 1 | 2 | 3 | 100 | ACGT | 58, 59, 60, 61, 62 | - | L1720 |
| 226 | `L_ARM_FTOB_EVENT` | 1 | 3 | 1 | 2 | 4 | 100 | TGAC | 59, 60, 61, 62 | - | L1724 |
| 227 | `L_ARM_BTOF_REACT` | 1 | 1 | 2 | 1 | 3 | 100 | GATC | 52, 59, 61, 62 | - | L1728 |
| 228 | `L_ARM_BTOF_EVENT` | 1 | 2 | 3 | 1 | 4 | 100 | CATG | 52, 61, 62 | - | L1732 |
| 229 | `L_TAIL_SIGNAL` | 1 | 3 | 1 | 2 | 4 | 100 | ACTG | 19, 20, 21, 22, 23, 37 | - | L1544 |
| 230 | `L_TAIL_FTOB_REACT` | 1 | 0 | 1 | 3 | 2 | 100 | CGAT | 20, 21, 22, 23, 37 | - | L1548 |
| 231 | `L_TAIL_FTOB_EVENT` | 1 | 1 | 2 | 3 | 4 | 100 | TCGA | 21, 22, 23, 37 | - | L1552 |
| 232 | `L_TAIL_BTOF_REACT` | 1 | 0 | 1 | 3 | 2 | 100 | GTCA | 21, 23, 33, 37 | - | L1556 |
| 233 | `L_TAIL_BTOF_EVENT` | 1 | 2 | 1 | 3 | 4 | 100 | ATCG | 23, 33, 37 | - | L1560 |
| 234 | `L_NECK_SIGNAL` | 1 | 4 | 1 | 2 | 3 | 100 | TGAC | 111, 112, 113, 114, 115, 116 | - | L2070 |
| 235 | `L_NECK_FTOB_REACT` | 1 | 0 | 1 | 4 | 2 | 100 | GTAC | 112, 113, 114, 115, 116 | - | L2074 |
| 236 | `L_NECK_FTOB_EVENT` | 1 | 1 | 2 | 3 | 4 | 100 | CATG | 113, 114, 115, 116 | - | L2078 |
| 237 | `L_NECK_BTOF_REACT` | 1 | 0 | 1 | 4 | 2 | 100 | TCAG | 113, 115, 116, 118 | - | L2082 |
| 238 | `L_NECK_BTOF_EVENT` | 1 | 2 | 1 | 3 | 4 | 100 | TCAG | 115, 116, 118 | - | L2086 |
| 239 | `LOCO_SYNC` | 1 | 0 | 1 | 0 | 0 | 100 | CTGA | 15 | - | L1690 |

## Summary

- 167 genes drive a slot directly
- 24 genes only gate slot writes
- 42 genes are read but neither (likely flow through 2+ vars)
- 7 genes are never read by FUN_14009f680
