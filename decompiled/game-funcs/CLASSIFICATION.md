# Game function classification

Total game-logic functions: 971

Categories detected by pattern matching on decompiled bodies.

| Category | Count | Description |
|---|---|---|
| `unclassified` | 673 | No idiom detected (needs manual reading) |
| `float_math_heavy` | 155 | Heavy floating-point math (geometry / physics / genetics) |
| `iterates_logic` | 93 | Large loop-containing function |
| `plays_sound` | 14 | Triggers a named sound by string |
| `repeated_call_helper` | 11 | Calls one function multiple times (vector init, copy) |
| `init_struct` | 8 | Zero-initializes consecutive struct fields (constructor-like) |
| `switch_dispatcher` | 7 | Multi-way switch / dispatch table |
| `getter` | 5 | Returns a struct field at a fixed offset |
| `thunk` | 4 | Tiny wrapper that forwards to another function |
| `iterates_horse_list` | 1 | Iterates the horse vector at obj+0xb8..obj+0xc0 |

## Sample for each category

### `float_math_heavy` (155 functions)

| Address | Name | Size | Evidence |
|---|---|---|---|
| 0x14009f680 | `FUN_14009f680` | 14074 | 897 float vars (geometry/physics/genetics?) |
| 0x140094a20 | `FUN_140094a20` | 13205 | 125 float vars (geometry/physics/genetics?) |
| 0x140107660 | `FUN_140107660` | 12134 | 268 float vars (geometry/physics/genetics?) |
| 0x140050ad0 | `FUN_140050ad0` | 11025 | 49 float vars (geometry/physics/genetics?) |
| 0x1400f6fe0 | `FUN_1400f6fe0` | 9683 | 34 float vars (geometry/physics/genetics?) |
| 0x1400ab3d0 | `FUN_1400ab3d0` | 8647 | 165 float vars (geometry/physics/genetics?) |
| 0x14008ffc0 | `FUN_14008ffc0` | 8565 | 123 float vars (geometry/physics/genetics?) |
| 0x1400b0740 | `FUN_1400b0740` | 7483 | 408 float vars (geometry/physics/genetics?) |
| 0x1400ba940 | `FUN_1400ba940` | 7179 | 210 float vars (geometry/physics/genetics?) |
| 0x1400e0aa0 | `FUN_1400e0aa0` | 6908 | 108 float vars (geometry/physics/genetics?) |
| 0x140039190 | `FUN_140039190` | 6047 | 90 float vars (geometry/physics/genetics?) |
| 0x1400c0660 | `FUN_1400c0660` | 5765 | 111 float vars (geometry/physics/genetics?) |
| 0x14007b2e0 | `FUN_14007b2e0` | 5750 | 107 float vars (geometry/physics/genetics?) |
| 0x14010a5e0 | `FUN_14010a5e0` | 5188 | 22 float vars (geometry/physics/genetics?) |
| 0x140092820 | `FUN_140092820` | 5156 | 19 float vars (geometry/physics/genetics?) |
| ... | ... | ... | +140 more |

### `getter` (5 functions)

| Address | Name | Size | Evidence |
|---|---|---|---|
| 0x140009de0 | `FUN_140009de0` | 9 | returns field at offset 0xb4 |
| 0x140009df0 | `FUN_140009df0` | 9 | returns field at offset 0xb8 |
| 0x140009e00 | `FUN_140009e00` | 8 | returns field at offset 0xc5 |
| 0x14000b290 | `FUN_14000b290` | 8 | returns field at offset 0xa0 |
| 0x14000b390 | `FUN_14000b390` | 8 | returns field at offset 0xac |

### `init_struct` (8 functions)

| Address | Name | Size | Evidence |
|---|---|---|---|
| 0x14004edb0 | `FUN_14004edb0` | 244 | zero-initializes 5 fields |
| 0x1400bf070 | `FUN_1400bf070` | 165 | zero-initializes 5 fields |
| 0x1402e08a8 | `FUN_1402e08a8` | 159 | zero-initializes 8 fields |
| 0x140067e60 | `FUN_140067e60` | 155 | zero-initializes 3 fields |
| 0x1400befd0 | `FUN_1400befd0` | 155 | zero-initializes 18 fields |
| 0x14004c9d0 | `FUN_14004c9d0` | 137 | zero-initializes 4 fields |
| 0x1400fb7f0 | `FUN_1400fb7f0` | 126 | zero-initializes 3 fields |
| 0x1400250c0 | `FUN_1400250c0` | 96 | zero-initializes 4 fields |

### `iterates_horse_list` (1 functions)

| Address | Name | Size | Evidence |
|---|---|---|---|
| 0x1400cd0f0 | `FUN_1400cd0f0` | 472 | iterates vector at param+0xb8..param+0xc0 (the horse list) |

### `iterates_logic` (93 functions)

| Address | Name | Size | Evidence |
|---|---|---|---|
| 0x140089510 | `FUN_140089510` | 8654 | contains a loop |
| 0x140058480 | `FUN_140058480` | 7589 | contains a loop |
| 0x140033a10 | `FUN_140033a10` | 6233 | contains a loop |
| 0x140061f40 | `FUN_140061f40` | 5304 | contains a loop |
| 0x1402f6c9c | `FUN_1402f6c9c` | 4734 | contains a loop |
| 0x14007c970 | `FUN_14007c970` | 3987 | contains a loop |
| 0x140060a80 | `FUN_140060a80` | 3713 | contains a loop |
| 0x1400c35b0 | `FUN_1400c35b0` | 3356 | contains a loop |
| 0x140086910 | `FUN_140086910` | 3007 | contains a loop |
| 0x1401035b0 | `FUN_1401035b0` | 2834 | contains a loop |
| 0x1400ca260 | `FUN_1400ca260` | 2646 | contains a loop |
| 0x1400463e0 | `FUN_1400463e0` | 2552 | contains a loop |
| 0x1400fd580 | `FUN_1400fd580` | 2159 | contains a loop |
| 0x14006dc80 | `FUN_14006dc80` | 2026 | contains a loop |
| 0x1400bfa90 | `FUN_1400bfa90` | 1970 | contains a loop |
| ... | ... | ... | +78 more |

### `plays_sound` (14 functions)

| Address | Name | Size | Evidence |
|---|---|---|---|
| 0x140076a10 | `FUN_140076a10` | 3488 | sound='Sweetie' |
| 0x1400379e0 | `FUN_1400379e0` | 850 | sound='Circus' |
| 0x14008f6e0 | `FUN_14008f6e0` | 804 | sound='Track' |
| 0x140088000 | `FUN_140088000` | 775 | sound='Crispr' |
| 0x140069ee0 | `FUN_140069ee0` | 590 | sound='Saloon' |
| 0x140030940 | `FUN_140030940` | 528 | sound='Biohacker' |
| 0x14005fad0 | `FUN_14005fad0` | 431 | sound='Paddock' |
| 0x14002cd80 | `FUN_14002cd80` | 379 | sound='Abandoned' |
| 0x140064590 | `FUN_140064590` | 306 | sound='Hutch' |
| 0x1400f4ea0 | `FUN_1400f4ea0` | 282 | sound='Sweetie' |
| 0x14005bad0 | `FUN_14005bad0` | 228 | sound='GifLand' |
| 0x14002f0f0 | `FUN_14002f0f0` | 225 | sound='Acres' |
| 0x14008de50 | `FUN_14008de50` | 115 | sound='CarLot' |
| 0x1402ec1dc | `FUN_1402ec1dc` | 92 | sound='AppPolicyGetProcessTerminationMethod' |

### `repeated_call_helper` (11 functions)

| Address | Name | Size | Evidence |
|---|---|---|---|
| 0x1400a6cb0 | `FUN_1400a6cb0` | 244 | calls FUN_1400cf540 x3 |
| 0x1402e01d4 | `FUN_1402e01d4` | 241 | calls FUN_1402e68b0 x3 |
| 0x1400a32c0 | `FUN_1400a32c0` | 224 | calls FUN_1400c6580 x6 |
| 0x140053730 | `FUN_140053730` | 218 | calls FUN_1402ce36c x3 |
| 0x14009c6a0 | `FUN_14009c6a0` | 207 | calls FUN_1402c704c x3 |
| 0x1402e9cd4 | `FUN_1402e9cd4` | 205 | calls FUN_1402f4f90 x4 |
| 0x1402e8544 | `FUN_1402e8544` | 181 | calls FUN_1402e9a80 x3 |
| 0x1402f8670 | `FUN_1402f8670` | 111 | calls FUN_1402f8850 x3 |
| 0x1400757e0 | `FUN_1400757e0` | 103 | calls FUN_1400764d0 x4 |
| 0x140070f90 | `FUN_140070f90` | 92 | calls FUN_1400c43c0 x3 |
| 0x1402cd4c0 | `FUN_1402cd4c0` | 22 | calls FUN_1402e8cc0 x6 |

### `switch_dispatcher` (7 functions)

| Address | Name | Size | Evidence |
|---|---|---|---|
| 0x140010540 | `FUN_140010540` | 1427 | 10 case branches |
| 0x1402f8e20 | `FUN_1402f8e20` | 1353 | 240 case branches |
| 0x1402f94c0 | `FUN_1402f94c0` | 725 | 240 case branches |
| 0x1400450b0 | `FUN_1400450b0` | 384 | 6 case branches |
| 0x140072a10 | `FUN_140072a10` | 378 | 6 case branches |
| 0x1402f08b0 | `FUN_1402f08b0` | 330 | 8 case branches |
| 0x140010b00 | `FUN_140010b00` | 227 | 10 case branches |

### `thunk` (4 functions)

| Address | Name | Size | Evidence |
|---|---|---|---|
| 0x140024130 | `FUN_140024130` | 16 | single delegated call -> FUN_140024130 |
| 0x14002f0d0 | `FUN_14002f0d0` | 16 | single delegated call -> FUN_14002f0d0 |
| 0x1400478f0 | `FUN_1400478f0` | 16 | single delegated call -> FUN_1400478f0 |
| 0x1400bf7d0 | `FUN_1400bf7d0` | 16 | single delegated call -> FUN_1400bf7d0 |

### `unclassified` (673 functions)

| Address | Name | Size | Evidence |
|---|---|---|---|
| 0x14007e030 | `FUN_14007e030` | 3320 |  |
| 0x1400cc1d0 | `FUN_1400cc1d0` | 2029 |  |
| 0x1402d0790 | `FUN_1402d0790` | 2022 |  |
| 0x14009c8c0 | `FUN_14009c8c0` | 1881 |  |
| 0x1402e4980 | `FUN_1402e4980` | 1386 |  |
| 0x1402d0f80 | `FUN_1402d0f80` | 1277 |  |
| 0x14005f1f0 | `FUN_14005f1f0` | 1125 |  |
| 0x1400db270 | `FUN_1400db270` | 1124 |  |
| 0x14010f7e0 | `FUN_14010f7e0` | 1050 |  |
| 0x1400fdee0 | `FUN_1400fdee0` | 1018 |  |
| 0x1402cd4e0 | `FUN_1402cd4e0` | 1018 |  |
| 0x1401046c0 | `FUN_1401046c0` | 1004 |  |
| 0x1400c4a10 | `FUN_1400c4a10` | 965 |  |
| 0x140057c20 | `FUN_140057c20` | 961 |  |
| 0x1400c9420 | `FUN_1400c9420` | 961 |  |
| ... | ... | ... | +658 more |
