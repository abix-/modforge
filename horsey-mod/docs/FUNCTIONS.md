# Horsey.exe game-function naming table
> **Authoritative on:** the curated 971-function table with proposed names organized by domain. For the broader 1234-function auto-summarized index, see [ALL-FUNCTIONS.md](ALL-FUNCTIONS.md).

All 971 game-logic functions with a proposed name and description.

`source = string` means the function was identified by a string it references; high confidence.
`source = pattern` means the function's idiom was matched but the specific purpose is still inferred.

## domain: `fatigue` (5 functions)

| Addr | Size | Proposed name | Description | Source | Category |
|---|---|---|---|---|---|
| [0x1400e0aa0](decompiled/game-funcs/1400e0aa0_FUN_1400e0aa0.md) | 6908 | `show_all_rested_message` | Empty-state message when no horses need rest | string | repeated_op |
| [0x1400dde40](decompiled/game-funcs/1400dde40_FUN_1400dde40.md) | 5159 | `check_horse_not_tired` | Eligibility check that rejects too-tired horses with a popup message | string | repeated_op |
| [0x140060a80](decompiled/game-funcs/140060a80_FUN_140060a80.md) | 3713 | `show_rest_at_home_prompt` | Prompt the player to go home and rest the horse | string | repeated_op |
| [0x1400d1f20](decompiled/game-funcs/1400d1f20_FUN_1400d1f20.md) | 350 | `struct_handler` | Reads/writes many fields on a struct (10 field accesses on param_1) | pattern | struct_handler |
| [0x1400dc2d0](decompiled/game-funcs/1400dc2d0_FUN_1400dc2d0.md) | 183 | `destructor_like` | Calls delete/free helpers; likely a destructor | pattern | destructor_like |

## domain: `aging` (11 functions)

| Addr | Size | Proposed name | Description | Source | Category |
|---|---|---|---|---|---|
| [0x1400dcab0](decompiled/game-funcs/1400dcab0_FUN_1400dcab0.md) | 4986 | `show_getting_old_sale_dialog` | Buyer dialog: offers low price for old horses | string | struct_init |
| [0x1400df280](decompiled/game-funcs/1400df280_FUN_1400df280.md) | 4364 | `retire_horse_handler` | Pick-and-retire-one-horse-per-year scanner. Decides retirement reason: (old) had records, (bails) tried but failed, (useless) never had skill | string | repeated_op |
| [0x1400e3670](decompiled/game-funcs/1400e3670_FUN_1400e3670.md) | 1319 | `batch_call_0e35f0` | Calls FUN_1400e35f0 5 times in a loop | pattern | repeated_op |
| [0x1401107d0](decompiled/game-funcs/1401107d0_FUN_1401107d0.md) | 571 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1401057b0](decompiled/game-funcs/1401057b0_FUN_1401057b0.md) | 455 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400e35f0](decompiled/game-funcs/1400e35f0_FUN_1400e35f0.md) | 128 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140112100](decompiled/game-funcs/140112100_FUN_140112100.md) | 125 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400b5f80](decompiled/game-funcs/1400b5f80_FUN_1400b5f80.md) | 78 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c78c0](decompiled/game-funcs/1400c78c0_FUN_1400c78c0.md) | 65 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14005e230](decompiled/game-funcs/14005e230_FUN_14005e230.md) | 18 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x14005e270](decompiled/game-funcs/14005e270_FUN_14005e270.md) | 18 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |

## domain: `race` (40 functions)

| Addr | Size | Proposed name | Description | Source | Category |
|---|---|---|---|---|---|
| [0x140094a20](decompiled/game-funcs/140094a20_FUN_140094a20.md) | 13205 | `show_race_ready_prompt` | Track UI prompt to start the next race | string | struct_init |
| [0x14002d7c0](decompiled/game-funcs/14002d7c0_FUN_14002d7c0.md) | 4033 | `trigger_won_race_sound` | Play the won-race sound | string | struct_init |
| [0x14007c970](decompiled/game-funcs/14007c970_FUN_14007c970.md) | 3987 | `batch_call_086570` | Calls FUN_140086570 9 times in a loop | pattern | repeated_op |
| [0x1400ad5c0](decompiled/game-funcs/1400ad5c0_FUN_1400ad5c0.md) | 3254 | `batch_call_0a9360` | Calls FUN_1400a9360 10 times in a loop | pattern | repeated_op |
| [0x1400cacd0](decompiled/game-funcs/1400cacd0_FUN_1400cacd0.md) | 2454 | `render_sleep_moon` | Render the moon icon over a sleeping horse | string | repeated_op |
| [0x1400aa2b0](decompiled/game-funcs/1400aa2b0_FUN_1400aa2b0.md) | 1183 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x1400c86f0](decompiled/game-funcs/1400c86f0_FUN_1400c86f0.md) | 1167 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x1400d2740](decompiled/game-funcs/1400d2740_FUN_1400d2740.md) | 869 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x1400b6fd0](decompiled/game-funcs/1400b6fd0_FUN_1400b6fd0.md) | 849 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x1400d4f50](decompiled/game-funcs/1400d4f50_FUN_1400d4f50.md) | 747 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400aa760](decompiled/game-funcs/1400aa760_FUN_1400aa760.md) | 711 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x140071150](decompiled/game-funcs/140071150_FUN_140071150.md) | 710 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x1400d5d90](decompiled/game-funcs/1400d5d90_FUN_1400d5d90.md) | 597 | `batch_call_071ed0` | Calls FUN_140071ed0 5 times in a loop | pattern | repeated_op |
| [0x140094540](decompiled/game-funcs/140094540_FUN_140094540.md) | 574 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140092150](decompiled/game-funcs/140092150_FUN_140092150.md) | 552 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140094810](decompiled/game-funcs/140094810_FUN_140094810.md) | 467 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x140064380](decompiled/game-funcs/140064380_FUN_140064380.md) | 420 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x14007da00](decompiled/game-funcs/14007da00_FUN_14007da00.md) | 418 | `batch_call_2f8e20` | Calls FUN_1402f8e20 5 times in a loop | pattern | repeated_op |
| [0x1400c8b90](decompiled/game-funcs/1400c8b90_FUN_1400c8b90.md) | 404 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140105980](decompiled/game-funcs/140105980_FUN_140105980.md) | 374 | `announce_latest_champion` | Announce the latest champion horse | string | helper |
| [0x1400b5fe0](decompiled/game-funcs/1400b5fe0_FUN_1400b5fe0.md) | 357 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400924b0](decompiled/game-funcs/1400924b0_FUN_1400924b0.md) | 356 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140055c30](decompiled/game-funcs/140055c30_FUN_140055c30.md) | 323 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140092380](decompiled/game-funcs/140092380_FUN_140092380.md) | 290 | `struct_handler` | Reads/writes many fields on a struct (21 field accesses on param_1) | pattern | struct_handler |
| [0x14009c7d0](decompiled/game-funcs/14009c7d0_FUN_14009c7d0.md) | 225 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400641d0](decompiled/game-funcs/1400641d0_FUN_1400641d0.md) | 164 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14000e340](decompiled/game-funcs/14000e340_FUN_14000e340.md) | 148 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400fb2b0](decompiled/game-funcs/1400fb2b0_FUN_1400fb2b0.md) | 115 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400985e0](decompiled/game-funcs/1400985e0_FUN_1400985e0.md) | 107 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c68d0](decompiled/game-funcs/1400c68d0_FUN_1400c68d0.md) | 100 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140070f90](decompiled/game-funcs/140070f90_FUN_140070f90.md) | 92 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14008ff60](decompiled/game-funcs/14008ff60_FUN_14008ff60.md) | 88 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140064530](decompiled/game-funcs/140064530_FUN_140064530.md) | 84 | `destructor_like` | Calls delete/free helpers; likely a destructor | pattern | destructor_like |
| [0x14000f890](decompiled/game-funcs/14000f890_FUN_14000f890.md) | 61 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c66c0](decompiled/game-funcs/1400c66c0_FUN_1400c66c0.md) | 50 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400cf9d0](decompiled/game-funcs/1400cf9d0_FUN_1400cf9d0.md) | 40 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140027b00](decompiled/game-funcs/140027b00_FUN_140027b00.md) | 29 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1400b4990](decompiled/game-funcs/1400b4990_FUN_1400b4990.md) | 23 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x140040fc0](decompiled/game-funcs/140040fc0_FUN_140040fc0.md) | 17 | `wrap_040fc0` | Wrapper that delegates to FUN_140040fc0 | pattern | wrapper |
| [0x1400cd560](decompiled/game-funcs/1400cd560_FUN_1400cd560.md) | 15 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |

## domain: `breeding` (1 functions)

| Addr | Size | Proposed name | Description | Source | Category |
|---|---|---|---|---|---|
| [0x1400816b0](decompiled/game-funcs/1400816b0_FUN_1400816b0.md) | 1610 | `trigger_wild_mating_event` | Trigger wild-mating event (sound + breeding) | string | loop_heavy |

## domain: `genetics` (3 functions)

| Addr | Size | Proposed name | Description | Source | Category |
|---|---|---|---|---|---|
| [0x140033a10](decompiled/game-funcs/140033a10_FUN_140033a10.md) | 6233 | `sample_dna` | Take a DNA sample from a horse | string | repeated_op |
| [0x1400fd3e0](decompiled/game-funcs/1400fd3e0_FUN_1400fd3e0.md) | 375 | `scan_for_chromosomes` | CRISPR vial: scan environment for collectible chromosome horses | string | iterates_horse_list_0xb8 |
| [0x1400372c0](decompiled/game-funcs/1400372c0_FUN_1400372c0.md) | 95 | `destructor_like` | Calls delete/free helpers; likely a destructor | pattern | destructor_like |

## domain: `save_io` (65 functions)

| Addr | Size | Proposed name | Description | Source | Category |
|---|---|---|---|---|---|
| [0x14006e480](decompiled/game-funcs/14006e480_FUN_14006e480.md) | 2439 | `compute_save_path` | Builds the save file path 'save<N>.dat' | string | repeated_op |
| [0x14006dc80](decompiled/game-funcs/14006dc80_FUN_14006dc80.md) | 2026 | `compute_save_path` | Builds the save file path 'save<N>.dat' | string | repeated_op |
| [0x1400fdee0](decompiled/game-funcs/1400fdee0_FUN_1400fdee0.md) | 1018 | `batch_call_2c704c` | Calls FUN_1402c704c 24 times in a loop | pattern | repeated_op |
| [0x140060710](decompiled/game-funcs/140060710_FUN_140060710.md) | 855 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x14006ee10](decompiled/game-funcs/14006ee10_FUN_14006ee10.md) | 816 | `batch_call_075690` | Calls FUN_140075690 8 times in a loop | pattern | repeated_op |
| [0x14006f150](decompiled/game-funcs/14006f150_FUN_14006f150.md) | 772 | `batch_call_075c60` | Calls FUN_140075c60 8 times in a loop | pattern | repeated_op |
| [0x14006d790](decompiled/game-funcs/14006d790_FUN_14006d790.md) | 746 | `batch_call_2c704c` | Calls FUN_1402c704c 6 times in a loop | pattern | repeated_op |
| [0x1400c7d80](decompiled/game-funcs/1400c7d80_FUN_1400c7d80.md) | 639 | `batch_call_075690` | Calls FUN_140075690 5 times in a loop | pattern | repeated_op |
| [0x1400c8010](decompiled/game-funcs/1400c8010_FUN_1400c8010.md) | 513 | `batch_call_075c60` | Calls FUN_140075c60 5 times in a loop | pattern | repeated_op |
| [0x1400760f0](decompiled/game-funcs/1400760f0_FUN_1400760f0.md) | 424 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x14006f840](decompiled/game-funcs/14006f840_FUN_14006f840.md) | 403 | `helper_with_7_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14006fb70](decompiled/game-funcs/14006fb70_FUN_14006fb70.md) | 403 | `helper_with_7_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140076550](decompiled/game-funcs/140076550_FUN_140076550.md) | 403 | `helper_with_7_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14006f9e0](decompiled/game-funcs/14006f9e0_FUN_14006f9e0.md) | 397 | `helper_with_7_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140076790](decompiled/game-funcs/140076790_FUN_140076790.md) | 378 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14006f6c0](decompiled/game-funcs/14006f6c0_FUN_14006f6c0.md) | 373 | `batch_call_2f8e20` | Calls FUN_1402f8e20 6 times in a loop | pattern | repeated_op |
| [0x1400c4e20](decompiled/game-funcs/1400c4e20_FUN_1400c4e20.md) | 373 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14006d610](decompiled/game-funcs/14006d610_FUN_14006d610.md) | 368 | `iter_horses_0xb8` | Iterates the horse list at obj+0xb8..0xc0 (one of the multiple horse lists) | pattern | iterates_horse_list_0xb8 |
| [0x1400d6a40](decompiled/game-funcs/1400d6a40_FUN_1400d6a40.md) | 335 | `iter_horses_0x26` | Iterates a horse list at param[0x26..0x27] | pattern | iterates_horse_list_0x26 |
| [0x14006f590](decompiled/game-funcs/14006f590_FUN_14006f590.md) | 298 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140075fd0](decompiled/game-funcs/140075fd0_FUN_140075fd0.md) | 271 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14006d470](decompiled/game-funcs/14006d470_FUN_14006d470.md) | 259 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140076910](decompiled/game-funcs/140076910_FUN_140076910.md) | 255 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140075a80](decompiled/game-funcs/140075a80_FUN_140075a80.md) | 243 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140075850](decompiled/game-funcs/140075850_FUN_140075850.md) | 220 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400762a0](decompiled/game-funcs/1400762a0_FUN_1400762a0.md) | 220 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14006f4e0](decompiled/game-funcs/14006f4e0_FUN_14006f4e0.md) | 173 | `struct_handler` | Reads/writes many fields on a struct (11 field accesses on param_1) | pattern | struct_handler |
| [0x1402d185c](decompiled/game-funcs/1402d185c_FUN_1402d185c.md) | 161 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140075f20](decompiled/game-funcs/140075f20_FUN_140075f20.md) | 158 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402d15ac](decompiled/game-funcs/1402d15ac_FUN_1402d15ac.md) | 156 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140075940](decompiled/game-funcs/140075940_FUN_140075940.md) | 146 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14006d580](decompiled/game-funcs/14006d580_FUN_14006d580.md) | 129 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400fb7f0](decompiled/game-funcs/1400fb7f0_FUN_1400fb7f0.md) | 126 | `struct_handler` | Reads/writes many fields on a struct (11 field accesses on param_1) | pattern | struct_handler |
| [0x1400764d0](decompiled/game-funcs/1400764d0_FUN_1400764d0.md) | 117 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400757e0](decompiled/game-funcs/1400757e0_FUN_1400757e0.md) | 103 | `batch_call_0764d0` | Calls FUN_1400764d0 4 times in a loop | pattern | repeated_op |
| [0x1400755f0](decompiled/game-funcs/1400755f0_FUN_1400755f0.md) | 89 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140076480](decompiled/game-funcs/140076480_FUN_140076480.md) | 69 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140075bd0](decompiled/game-funcs/140075bd0_FUN_140075bd0.md) | 68 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140075790](decompiled/game-funcs/140075790_FUN_140075790.md) | 67 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400755a0](decompiled/game-funcs/1400755a0_FUN_1400755a0.md) | 66 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14006fd10](decompiled/game-funcs/14006fd10_FUN_14006fd10.md) | 65 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140075e80](decompiled/game-funcs/140075e80_FUN_140075e80.md) | 65 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140075d50](decompiled/game-funcs/140075d50_FUN_140075d50.md) | 64 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140075ed0](decompiled/game-funcs/140075ed0_FUN_140075ed0.md) | 64 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140075cb0](decompiled/game-funcs/140075cb0_FUN_140075cb0.md) | 63 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140075c60](decompiled/game-funcs/140075c60_FUN_140075c60.md) | 62 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140075b80](decompiled/game-funcs/140075b80_FUN_140075b80.md) | 61 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140075e30](decompiled/game-funcs/140075e30_FUN_140075e30.md) | 59 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140075c20](decompiled/game-funcs/140075c20_FUN_140075c20.md) | 58 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140075da0](decompiled/game-funcs/140075da0_FUN_140075da0.md) | 53 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14005c970](decompiled/game-funcs/14005c970_FUN_14005c970.md) | 47 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401012c0](decompiled/game-funcs/1401012c0_FUN_1401012c0.md) | 45 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14010dde0](decompiled/game-funcs/14010dde0_FUN_14010dde0.md) | 34 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14010de10](decompiled/game-funcs/14010de10_FUN_14010de10.md) | 34 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140075750](decompiled/game-funcs/140075750_FUN_140075750.md) | 22 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140075770](decompiled/game-funcs/140075770_FUN_140075770.md) | 21 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400756b0](decompiled/game-funcs/1400756b0_FUN_1400756b0.md) | 20 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400756d0](decompiled/game-funcs/1400756d0_FUN_1400756d0.md) | 20 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140075670](decompiled/game-funcs/140075670_FUN_140075670.md) | 19 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140075690](decompiled/game-funcs/140075690_FUN_140075690.md) | 19 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140075710](decompiled/game-funcs/140075710_FUN_140075710.md) | 19 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140075730](decompiled/game-funcs/140075730_FUN_140075730.md) | 19 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140110750](decompiled/game-funcs/140110750_FUN_140110750.md) | 18 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x140075650](decompiled/game-funcs/140075650_FUN_140075650.md) | 13 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1400c4df0](decompiled/game-funcs/1400c4df0_FUN_1400c4df0.md) | 8 | `empty_stub` | Tiny <=8 byte stub (likely a `ret`) | pattern | empty_stub |

## domain: `settings_io` (1 functions)

| Addr | Size | Proposed name | Description | Source | Category |
|---|---|---|---|---|---|
| [0x140076a10](decompiled/game-funcs/140076a10_FUN_140076a10.md) | 3488 | `tmx_map_loader` | Load the horsey.tmx Tiled world map | string | repeated_op |

## domain: `debug` (35 functions)

| Addr | Size | Proposed name | Description | Source | Category |
|---|---|---|---|---|---|
| [0x1400c0660](decompiled/game-funcs/1400c0660_FUN_1400c0660.md) | 5765 | `debug_print_horse_stats` | Debug: print roster horse stats | string | struct_init |
| [0x14010ba40](decompiled/game-funcs/14010ba40_FUN_14010ba40.md) | 4610 | `debug_print_population_stats` | Debug: print population stats (year, herb count, gen diversity) | string | repeated_op |
| [0x140066200](decompiled/game-funcs/140066200_FUN_140066200.md) | 4188 | `draw_pause_status` | Draws the pause-screen status line (year, sleeps, races in debug mode) | string | struct_init |
| [0x1400a4880](decompiled/game-funcs/1400a4880_FUN_1400a4880.md) | 1397 | `batch_call_025900` | Calls FUN_140025900 4 times in a loop | pattern | repeated_op |
| [0x1400a65d0](decompiled/game-funcs/1400a65d0_FUN_1400a65d0.md) | 920 | `batch_call_025900` | Calls FUN_140025900 4 times in a loop | pattern | repeated_op |
| [0x1400a4e00](decompiled/game-funcs/1400a4e00_FUN_1400a4e00.md) | 468 | `helper_with_14_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140067330](decompiled/game-funcs/140067330_FUN_140067330.md) | 343 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140067560](decompiled/game-funcs/140067560_FUN_140067560.md) | 333 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400676c0](decompiled/game-funcs/1400676c0_FUN_1400676c0.md) | 324 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c03a0](decompiled/game-funcs/1400c03a0_FUN_1400c03a0.md) | 235 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140027470](decompiled/game-funcs/140027470_FUN_140027470.md) | 202 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140025490](decompiled/game-funcs/140025490_FUN_140025490.md) | 201 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140067490](decompiled/game-funcs/140067490_FUN_140067490.md) | 193 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400262c0](decompiled/game-funcs/1400262c0_FUN_1400262c0.md) | 163 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402db0a8](decompiled/game-funcs/1402db0a8_FUN_1402db0a8.md) | 152 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140072ed0](decompiled/game-funcs/140072ed0_FUN_140072ed0.md) | 120 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400267d0](decompiled/game-funcs/1400267d0_FUN_1400267d0.md) | 107 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400276e0](decompiled/game-funcs/1400276e0_FUN_1400276e0.md) | 98 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14003f2c0](decompiled/game-funcs/14003f2c0_FUN_14003f2c0.md) | 95 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400b35f0](decompiled/game-funcs/1400b35f0_FUN_1400b35f0.md) | 89 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140025930](decompiled/game-funcs/140025930_FUN_140025930.md) | 65 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140025980](decompiled/game-funcs/140025980_FUN_140025980.md) | 65 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400258d0](decompiled/game-funcs/1400258d0_FUN_1400258d0.md) | 44 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140025900](decompiled/game-funcs/140025900_FUN_140025900.md) | 44 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c02b0](decompiled/game-funcs/1400c02b0_FUN_1400c02b0.md) | 44 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14009c7a0](decompiled/game-funcs/14009c7a0_FUN_14009c7a0.md) | 39 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140071120](decompiled/game-funcs/140071120_FUN_140071120.md) | 37 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14003f290](decompiled/game-funcs/14003f290_FUN_14003f290.md) | 35 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140082410](decompiled/game-funcs/140082410_FUN_140082410.md) | 23 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1400c6500](decompiled/game-funcs/1400c6500_FUN_1400c6500.md) | 20 | `wrap_0c6500` | Wrapper that delegates to FUN_1400c6500 | pattern | wrapper |
| [0x1400c42f0](decompiled/game-funcs/1400c42f0_FUN_1400c42f0.md) | 13 | `wrap_0c42f0` | Wrapper that delegates to FUN_1400c42f0 | pattern | wrapper |
| [0x1400cd580](decompiled/game-funcs/1400cd580_FUN_1400cd580.md) | 12 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c42e0](decompiled/game-funcs/1400c42e0_FUN_1400c42e0.md) | 8 | `empty_stub` | Tiny <=8 byte stub (likely a `ret`) | pattern | empty_stub |
| [0x1400c4310](decompiled/game-funcs/1400c4310_FUN_1400c4310.md) | 8 | `empty_stub` | Tiny <=8 byte stub (likely a `ret`) | pattern | empty_stub |
| [0x1400c4e00](decompiled/game-funcs/1400c4e00_FUN_1400c4e00.md) | 8 | `empty_stub` | Tiny <=8 byte stub (likely a `ret`) | pattern | empty_stub |

## domain: `world_event` (1049 functions)

| Addr | Size | Proposed name | Description | Source | Category |
|---|---|---|---|---|---|
| [0x14009f680](decompiled/game-funcs/14009f680_FUN_14009f680.md) | 14074 | `bad_gene_index_error` | Reports a bad gene index | string | struct_init |
| [0x140107660](decompiled/game-funcs/140107660_FUN_140107660.md) | 12134 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 11 fields) | pattern | struct_init |
| [0x140050ad0](decompiled/game-funcs/140050ad0_FUN_140050ad0.md) | 11025 | `batch_call_04cb40` | Calls FUN_14004cb40 71 times in a loop | pattern | repeated_op |
| [0x1400f6fe0](decompiled/game-funcs/1400f6fe0_FUN_1400f6fe0.md) | 9683 | `prize_appear_sound` | Plays prize-appear sound | string | struct_init |
| [0x1400d2ab0](decompiled/game-funcs/1400d2ab0_FUN_1400d2ab0.md) | 9349 | `prize_appear_sound` | Plays prize-appear sound | string | struct_init |
| [0x140089510](decompiled/game-funcs/140089510_FUN_140089510.md) | 8654 | `copy_genome_to_clipboard` | Serialize a horse genome to clipboard text | string | struct_init |
| [0x1400ab3d0](decompiled/game-funcs/1400ab3d0_FUN_1400ab3d0.md) | 8647 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 7 fields) | pattern | struct_init |
| [0x14008ffc0](decompiled/game-funcs/14008ffc0_FUN_14008ffc0.md) | 8565 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 15 fields) | pattern | struct_init |
| [0x140058480](decompiled/game-funcs/140058480_FUN_140058480.md) | 7589 | `show_population_goal` | Tutorial goal 1: population target | string | struct_init |
| [0x1400b0740](decompiled/game-funcs/1400b0740_FUN_1400b0740.md) | 7483 | `batch_call_0a9360` | Calls FUN_1400a9360 24 times in a loop | pattern | repeated_op |
| [0x1400ba940](decompiled/game-funcs/1400ba940_FUN_1400ba940.md) | 7179 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 3 fields) | pattern | struct_init |
| [0x140039190](decompiled/game-funcs/140039190_FUN_140039190.md) | 6047 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 4 fields) | pattern | struct_init |
| [0x14007b2e0](decompiled/game-funcs/14007b2e0_FUN_14007b2e0.md) | 5750 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 10 fields) | pattern | struct_init |
| [0x140061f40](decompiled/game-funcs/140061f40_FUN_140061f40.md) | 5304 | `batch_call_0d0c80` | Calls FUN_1400d0c80 15 times in a loop | pattern | repeated_op |
| [0x1400fe2e0](decompiled/game-funcs/1400fe2e0_FUN_1400fe2e0.md) | 5277 | `batch_call_2c704c` | Calls FUN_1402c704c 26 times in a loop | pattern | repeated_op |
| [0x14010a5e0](decompiled/game-funcs/14010a5e0_FUN_14010a5e0.md) | 5188 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 4 fields) | pattern | struct_init |
| [0x140092820](decompiled/game-funcs/140092820_FUN_140092820.md) | 5156 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 5 fields) | pattern | struct_init |
| [0x1400b9540](decompiled/game-funcs/1400b9540_FUN_1400b9540.md) | 5110 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 3 fields) | pattern | struct_init |
| [0x1402f6c9c](decompiled/game-funcs/1402f6c9c_FUN_1402f6c9c.md) | 4734 | `batch_call_2f94c0` | Calls FUN_1402f94c0 8 times in a loop | pattern | repeated_op |
| [0x1401c10d0](decompiled/game-funcs/1401c10d0_FUN_1401c10d0.md) | 4690 | `batch_call_1c97e0` | Calls FUN_1401c97e0 17 times in a loop | pattern | repeated_op |
| [0x14004dc90](decompiled/game-funcs/14004dc90_FUN_14004dc90.md) | 4047 | `batch_call_04cf80` | Calls FUN_14004cf80 5 times in a loop | pattern | repeated_op |
| [0x1400d0c80](decompiled/game-funcs/1400d0c80_FUN_1400d0c80.md) | 4008 | `batch_call_2c7088` | Calls FUN_1402c7088 10 times in a loop | pattern | repeated_op |
| [0x1402d8d60](decompiled/game-funcs/1402d8d60_FUN_1402d8d60.md) | 3443 | `batch_call_2f08b0` | Calls FUN_1402f08b0 22 times in a loop | pattern | repeated_op |
| [0x14003f810](decompiled/game-funcs/14003f810_FUN_14003f810.md) | 3359 | `batch_call_2f8e20` | Calls FUN_1402f8e20 6 times in a loop | pattern | repeated_op |
| [0x1400c35b0](decompiled/game-funcs/1400c35b0_FUN_1400c35b0.md) | 3356 | `batch_call_0c5f50` | Calls FUN_1400c5f50 6 times in a loop | pattern | repeated_op |
| [0x14007e030](decompiled/game-funcs/14007e030_FUN_14007e030.md) | 3320 | `suggest_paddock` | Suggestion: go to the Paddock | string | repeated_op |
| [0x1400da2f0](decompiled/game-funcs/1400da2f0_FUN_1400da2f0.md) | 3290 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x140006950](decompiled/game-funcs/140006950_FUN_140006950.md) | 3264 | `batch_call_2cdc50` | Calls FUN_1402cdc50 6 times in a loop | pattern | repeated_op |
| [0x140016c70](decompiled/game-funcs/140016c70_FUN_140016c70.md) | 3150 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x1401acec0](decompiled/game-funcs/1401acec0_FUN_1401acec0.md) | 3099 | `batch_call_1841f0` | Calls FUN_1401841f0 14 times in a loop | pattern | repeated_op |
| [0x140053a40](decompiled/game-funcs/140053a40_FUN_140053a40.md) | 3042 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x140086910](decompiled/game-funcs/140086910_FUN_140086910.md) | 3007 | `batch_call_2c7088` | Calls FUN_1402c7088 11 times in a loop | pattern | repeated_op |
| [0x14006b040](decompiled/game-funcs/14006b040_FUN_14006b040.md) | 2987 | `batch_call_2c7088` | Calls FUN_1402c7088 8 times in a loop | pattern | repeated_op |
| [0x140082640](decompiled/game-funcs/140082640_FUN_140082640.md) | 2966 | `batch_call_080cc0` | Calls FUN_140080cc0 6 times in a loop | pattern | repeated_op |
| [0x14001f7b0](decompiled/game-funcs/14001f7b0_FUN_14001f7b0.md) | 2954 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x1400a74e0](decompiled/game-funcs/1400a74e0_FUN_1400a74e0.md) | 2941 | `welcome_dialog` | Welcome dialog | string | struct_init |
| [0x1401035b0](decompiled/game-funcs/1401035b0_FUN_1401035b0.md) | 2834 | `batch_call_2f8e20` | Calls FUN_1402f8e20 10 times in a loop | pattern | repeated_op |
| [0x14004b960](decompiled/game-funcs/14004b960_FUN_14004b960.md) | 2740 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 6 fields) | pattern | struct_init |
| [0x1400ca260](decompiled/game-funcs/1400ca260_FUN_1400ca260.md) | 2646 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 4 fields) | pattern | struct_init |
| [0x1400aed30](decompiled/game-funcs/1400aed30_FUN_1400aed30.md) | 2595 | `batch_call_0a9360` | Calls FUN_1400a9360 9 times in a loop | pattern | repeated_op |
| [0x1400b3dc0](decompiled/game-funcs/1400b3dc0_FUN_1400b3dc0.md) | 2575 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 4 fields) | pattern | struct_init |
| [0x1400463e0](decompiled/game-funcs/1400463e0_FUN_1400463e0.md) | 2552 | `loop_handler` | Large loop-based handler | pattern | loop_heavy |
| [0x1400d98f0](decompiled/game-funcs/1400d98f0_FUN_1400d98f0.md) | 2517 | `batch_call_2d8d60` | Calls FUN_1402d8d60 8 times in a loop | pattern | repeated_op |
| [0x1400ceb60](decompiled/game-funcs/1400ceb60_FUN_1400ceb60.md) | 2502 | `batch_call_2c7088` | Calls FUN_1402c7088 5 times in a loop | pattern | repeated_op |
| [0x1400a3eb0](decompiled/game-funcs/1400a3eb0_FUN_1400a3eb0.md) | 2491 | `chromomap_lookup` | Look up a gene by index in chromoMap; aborts if missing | string | repeated_op |
| [0x140106140](decompiled/game-funcs/140106140_FUN_140106140.md) | 2405 | `batch_call_2c7088` | Calls FUN_1402c7088 8 times in a loop | pattern | repeated_op |
| [0x140196db0](decompiled/game-funcs/140196db0_FUN_140196db0.md) | 2291 | `switch_dispatch` | Multi-way switch; dispatches by enum/state value | pattern | switch_dispatcher |
| [0x1400bd820](decompiled/game-funcs/1400bd820_FUN_1400bd820.md) | 2270 | `render_sleep_animation` | Render sleep animation on horse | string | float_math_complex |
| [0x1400d52c0](decompiled/game-funcs/1400d52c0_FUN_1400d52c0.md) | 2253 | `batch_call_0c7520` | Calls FUN_1400c7520 8 times in a loop | pattern | repeated_op |
| [0x1400fd580](decompiled/game-funcs/1400fd580_FUN_1400fd580.md) | 2159 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 11 fields) | pattern | struct_init |
| [0x1400b2490](decompiled/game-funcs/1400b2490_FUN_1400b2490.md) | 2096 | `batch_call_0b2cd0` | Calls FUN_1400b2cd0 4 times in a loop | pattern | repeated_op |
| [0x1400b4b10](decompiled/game-funcs/1400b4b10_FUN_1400b4b10.md) | 2053 | `batch_call_2f8e20` | Calls FUN_1402f8e20 6 times in a loop | pattern | repeated_op |
| [0x140097dd0](decompiled/game-funcs/140097dd0_FUN_140097dd0.md) | 2046 | `batch_call_0c6580` | Calls FUN_1400c6580 7 times in a loop | pattern | repeated_op |
| [0x140013d80](decompiled/game-funcs/140013d80_FUN_140013d80.md) | 2038 | `batch_call_2cdc50` | Calls FUN_1402cdc50 4 times in a loop | pattern | repeated_op |
| [0x1400cc1d0](decompiled/game-funcs/1400cc1d0_FUN_1400cc1d0.md) | 2029 | `batch_call_0d0c80` | Calls FUN_1400d0c80 15 times in a loop | pattern | repeated_op |
| [0x1402d0790](decompiled/game-funcs/1402d0790_FUN_1402d0790.md) | 2022 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x140080e40](decompiled/game-funcs/140080e40_FUN_140080e40.md) | 1972 | `batch_call_080cc0` | Calls FUN_140080cc0 7 times in a loop | pattern | repeated_op |
| [0x1400bfa90](decompiled/game-funcs/1400bfa90_FUN_1400bfa90.md) | 1970 | `batch_call_2c6760` | Calls FUN_1402c6760 7 times in a loop | pattern | repeated_op |
| [0x140093d90](decompiled/game-funcs/140093d90_FUN_140093d90.md) | 1956 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x1400bcb00](decompiled/game-funcs/1400bcb00_FUN_1400bcb00.md) | 1924 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x1400cba60](decompiled/game-funcs/1400cba60_FUN_1400cba60.md) | 1894 | `batch_call_0cc9d0` | Calls FUN_1400cc9d0 4 times in a loop | pattern | repeated_op |
| [0x140017910](decompiled/game-funcs/140017910_FUN_140017910.md) | 1887 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x14009c8c0](decompiled/game-funcs/14009c8c0_FUN_14009c8c0.md) | 1881 | `batch_call_2c704c` | Calls FUN_1402c704c 11 times in a loop | pattern | repeated_op |
| [0x1400cddd0](decompiled/game-funcs/1400cddd0_FUN_1400cddd0.md) | 1833 | `batch_call_2f8e20` | Calls FUN_1402f8e20 8 times in a loop | pattern | repeated_op |
| [0x14001eae0](decompiled/game-funcs/14001eae0_FUN_14001eae0.md) | 1832 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x14000eef0](decompiled/game-funcs/14000eef0_FUN_14000eef0.md) | 1814 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x1400b78d0](decompiled/game-funcs/1400b78d0_FUN_1400b78d0.md) | 1787 | `batch_call_0c5c10` | Calls FUN_1400c5c10 11 times in a loop | pattern | repeated_op |
| [0x140012ba0](decompiled/game-funcs/140012ba0_FUN_140012ba0.md) | 1765 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x14005d710](decompiled/game-funcs/14005d710_FUN_14005d710.md) | 1728 | `batch_call_0c6580` | Calls FUN_1400c6580 7 times in a loop | pattern | repeated_op |
| [0x140015c30](decompiled/game-funcs/140015c30_FUN_140015c30.md) | 1718 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x140047cd0](decompiled/game-funcs/140047cd0_FUN_140047cd0.md) | 1675 | `loop_handler` | Large loop-based handler | pattern | loop_heavy |
| [0x1400afc20](decompiled/game-funcs/1400afc20_FUN_1400afc20.md) | 1664 | `batch_call_0a9360` | Calls FUN_1400a9360 4 times in a loop | pattern | repeated_op |
| [0x1400ae6b0](decompiled/game-funcs/1400ae6b0_FUN_1400ae6b0.md) | 1656 | `batch_call_0a9360` | Calls FUN_1400a9360 8 times in a loop | pattern | repeated_op |
| [0x14002fe00](decompiled/game-funcs/14002fe00_FUN_14002fe00.md) | 1630 | `batch_call_2c7088` | Calls FUN_1402c7088 5 times in a loop | pattern | repeated_op |
| [0x1401112f0](decompiled/game-funcs/1401112f0_FUN_1401112f0.md) | 1624 | `batch_call_110ef0` | Calls FUN_140110ef0 4 times in a loop | pattern | repeated_op |
| [0x140102df0](decompiled/game-funcs/140102df0_FUN_140102df0.md) | 1621 | `iter_horses_0xb8` | Iterates the horse list at obj+0xb8..0xc0 (one of the multiple horse lists) | pattern | iterates_horse_list_0xb8 |
| [0x1400e0420](decompiled/game-funcs/1400e0420_FUN_1400e0420.md) | 1610 | `batch_call_0c6580` | Calls FUN_1400c6580 5 times in a loop | pattern | repeated_op |
| [0x14009d750](decompiled/game-funcs/14009d750_FUN_14009d750.md) | 1577 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x140013290](decompiled/game-funcs/140013290_FUN_140013290.md) | 1575 | `batch_call_012a20` | Calls FUN_140012a20 4 times in a loop | pattern | repeated_op |
| [0x1400d03f0](decompiled/game-funcs/1400d03f0_FUN_1400d03f0.md) | 1539 | `loop_handler` | Large loop-based handler | pattern | loop_heavy |
| [0x1400fa910](decompiled/game-funcs/1400fa910_FUN_1400fa910.md) | 1539 | `batch_call_2c7088` | Calls FUN_1402c7088 5 times in a loop | pattern | repeated_op |
| [0x14006a420](decompiled/game-funcs/14006a420_FUN_14006a420.md) | 1505 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 6 fields) | pattern | struct_init |
| [0x1400449e0](decompiled/game-funcs/1400449e0_FUN_1400449e0.md) | 1493 | `loop_handler` | Large loop-based handler | pattern | loop_heavy |
| [0x140106bc0](decompiled/game-funcs/140106bc0_FUN_140106bc0.md) | 1463 | `batch_call_2c7088` | Calls FUN_1402c7088 4 times in a loop | pattern | repeated_op |
| [0x14001f210](decompiled/game-funcs/14001f210_FUN_14001f210.md) | 1430 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x140010540](decompiled/game-funcs/140010540_FUN_140010540.md) | 1427 | `batch_call_012630` | Calls FUN_140012630 10 times in a loop | pattern | repeated_op |
| [0x14010d7e0](decompiled/game-funcs/14010d7e0_FUN_14010d7e0.md) | 1413 | `batch_call_0c6940` | Calls FUN_1400c6940 28 times in a loop | pattern | repeated_op |
| [0x1402e4980](decompiled/game-funcs/1402e4980_FUN_1402e4980.md) | 1386 | `batch_call_2ecfa0` | Calls FUN_1402ecfa0 5 times in a loop | pattern | repeated_op |
| [0x1400b3070](decompiled/game-funcs/1400b3070_FUN_1400b3070.md) | 1367 | `batch_call_2f94c0` | Calls FUN_1402f94c0 4 times in a loop | pattern | repeated_op |
| [0x1400063f0](decompiled/game-funcs/1400063f0_FUN_1400063f0.md) | 1364 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 3 fields) | pattern | struct_init |
| [0x1402f8e20](decompiled/game-funcs/1402f8e20_FUN_1402f8e20.md) | 1353 | `switch_dispatch` | Multi-way switch; dispatches by enum/state value | pattern | switch_dispatcher |
| [0x1400d72f0](decompiled/game-funcs/1400d72f0_FUN_1400d72f0.md) | 1342 | `batch_call_0b6150` | Calls FUN_1400b6150 16 times in a loop | pattern | repeated_op |
| [0x140049630](decompiled/game-funcs/140049630_FUN_140049630.md) | 1339 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x1400cd5a0](decompiled/game-funcs/1400cd5a0_FUN_1400cd5a0.md) | 1326 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x140020bb0](decompiled/game-funcs/140020bb0_FUN_140020bb0.md) | 1306 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x1402d0f80](decompiled/game-funcs/1402d0f80_FUN_1402d0f80.md) | 1277 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x140048e90](decompiled/game-funcs/140048e90_FUN_140048e90.md) | 1264 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x1400155f0](decompiled/game-funcs/1400155f0_FUN_1400155f0.md) | 1250 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x1400d5ff0](decompiled/game-funcs/1400d5ff0_FUN_1400d5ff0.md) | 1241 | `loop_handler` | Large loop-based handler | pattern | loop_heavy |
| [0x14001e5e0](decompiled/game-funcs/14001e5e0_FUN_14001e5e0.md) | 1229 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x140102060](decompiled/game-funcs/140102060_FUN_140102060.md) | 1225 | `batch_call_0c5c20` | Calls FUN_1400c5c20 4 times in a loop | pattern | repeated_op |
| [0x140105260](decompiled/game-funcs/140105260_FUN_140105260.md) | 1223 | `batch_call_0c6580` | Calls FUN_1400c6580 15 times in a loop | pattern | repeated_op |
| [0x14000bfe0](decompiled/game-funcs/14000bfe0_FUN_14000bfe0.md) | 1221 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x1400693b0](decompiled/game-funcs/1400693b0_FUN_1400693b0.md) | 1207 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x1400138c0](decompiled/game-funcs/1400138c0_FUN_1400138c0.md) | 1203 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x140020700](decompiled/game-funcs/140020700_FUN_140020700.md) | 1199 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x1400d7830](decompiled/game-funcs/1400d7830_FUN_1400d7830.md) | 1181 | `batch_call_0b6150` | Calls FUN_1400b6150 32 times in a loop | pattern | repeated_op |
| [0x1400a5400](decompiled/game-funcs/1400a5400_FUN_1400a5400.md) | 1178 | `batch_call_2f8e20` | Calls FUN_1402f8e20 5 times in a loop | pattern | repeated_op |
| [0x1402edc48](decompiled/game-funcs/1402edc48_FUN_1402edc48.md) | 1171 | `loop_handler` | Large loop-based handler | pattern | loop_heavy |
| [0x1402de160](decompiled/game-funcs/1402de160_FUN_1402de160.md) | 1164 | `loop_handler` | Large loop-based handler | pattern | loop_heavy |
| [0x1400af790](decompiled/game-funcs/1400af790_FUN_1400af790.md) | 1158 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x1401005b0](decompiled/game-funcs/1401005b0_FUN_1401005b0.md) | 1157 | `loop_handler` | Large loop-based handler | pattern | loop_heavy |
| [0x140018070](decompiled/game-funcs/140018070_FUN_140018070.md) | 1141 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x1400b87e0](decompiled/game-funcs/1400b87e0_FUN_1400b87e0.md) | 1137 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x1402d5aec](decompiled/game-funcs/1402d5aec_FUN_1402d5aec.md) | 1133 | `loop_handler` | Large loop-based handler | pattern | loop_heavy |
| [0x14005f1f0](decompiled/game-funcs/14005f1f0_FUN_14005f1f0.md) | 1125 | `batch_call_2c7088` | Calls FUN_1402c7088 4 times in a loop | pattern | repeated_op |
| [0x1400db270](decompiled/game-funcs/1400db270_FUN_1400db270.md) | 1124 | `batch_call_0cf540` | Calls FUN_1400cf540 8 times in a loop | pattern | repeated_op |
| [0x1400b02b0](decompiled/game-funcs/1400b02b0_FUN_1400b02b0.md) | 1116 | `batch_call_0a9360` | Calls FUN_1400a9360 4 times in a loop | pattern | repeated_op |
| [0x1401c97e0](decompiled/game-funcs/1401c97e0_FUN_1401c97e0.md) | 1105 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 17 fields) | pattern | struct_init |
| [0x1400a9c80](decompiled/game-funcs/1400a9c80_FUN_1400a9c80.md) | 1093 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x1400b7fe0](decompiled/game-funcs/1400b7fe0_FUN_1400b7fe0.md) | 1073 | `loop_handler` | Large loop-based handler | pattern | loop_heavy |
| [0x140054630](decompiled/game-funcs/140054630_FUN_140054630.md) | 1065 | `batch_call_2e9a80` | Calls FUN_1402e9a80 29 times in a loop | pattern | repeated_op |
| [0x1400ae280](decompiled/game-funcs/1400ae280_FUN_1400ae280.md) | 1059 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x14000da90](decompiled/game-funcs/14000da90_FUN_14000da90.md) | 1057 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x14010f7e0](decompiled/game-funcs/14010f7e0_FUN_14010f7e0.md) | 1050 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x1400c8e70](decompiled/game-funcs/1400c8e70_FUN_1400c8e70.md) | 1049 | `loop_handler` | Large loop-based handler | pattern | loop_heavy |
| [0x1400b5b50](decompiled/game-funcs/1400b5b50_FUN_1400b5b50.md) | 1048 | `batch_call_2f8e20` | Calls FUN_1402f8e20 4 times in a loop | pattern | repeated_op |
| [0x1400cfda0](decompiled/game-funcs/1400cfda0_FUN_1400cfda0.md) | 1047 | `loop_handler` | Large loop-based handler | pattern | loop_heavy |
| [0x1400b39b0](decompiled/game-funcs/1400b39b0_FUN_1400b39b0.md) | 1034 | `batch_call_0a5370` | Calls FUN_1400a5370 4 times in a loop | pattern | repeated_op |
| [0x14009e2f0](decompiled/game-funcs/14009e2f0_FUN_14009e2f0.md) | 1027 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x1400d9010](decompiled/game-funcs/1400d9010_FUN_1400d9010.md) | 1018 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x1402cd4e0](decompiled/game-funcs/1402cd4e0_FUN_1402cd4e0.md) | 1018 | `batch_call_2e8cc0` | Calls FUN_1402e8cc0 8 times in a loop | pattern | repeated_op |
| [0x14004c420](decompiled/game-funcs/14004c420_FUN_14004c420.md) | 1017 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x14001b740](decompiled/game-funcs/14001b740_FUN_14001b740.md) | 1014 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x140011cb0](decompiled/game-funcs/140011cb0_FUN_140011cb0.md) | 1012 | `loop_handler` | Large loop-based handler | pattern | loop_heavy |
| [0x1401046c0](decompiled/game-funcs/1401046c0_FUN_1401046c0.md) | 1004 | `struct_handler` | Reads/writes many fields on a struct (19 field accesses on param_1) | pattern | struct_handler |
| [0x1400113e0](decompiled/game-funcs/1400113e0_FUN_1400113e0.md) | 1002 | `loop_handler` | Large loop-based handler | pattern | loop_heavy |
| [0x140071420](decompiled/game-funcs/140071420_FUN_140071420.md) | 993 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140073c30](decompiled/game-funcs/140073c30_FUN_140073c30.md) | 989 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x1400c4a10](decompiled/game-funcs/1400c4a10_FUN_1400c4a10.md) | 965 | `batch_call_2c7088` | Calls FUN_1402c7088 5 times in a loop | pattern | repeated_op |
| [0x140057c20](decompiled/game-funcs/140057c20_FUN_140057c20.md) | 961 | `batch_call_0c9c30` | Calls FUN_1400c9c30 12 times in a loop | pattern | repeated_op |
| [0x1400c9420](decompiled/game-funcs/1400c9420_FUN_1400c9420.md) | 961 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 7 fields) | pattern | struct_init |
| [0x140020340](decompiled/game-funcs/140020340_FUN_140020340.md) | 948 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x14004d8d0](decompiled/game-funcs/14004d8d0_FUN_14004d8d0.md) | 946 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x1400c43d0](decompiled/game-funcs/1400c43d0_FUN_1400c43d0.md) | 935 | `batch_call_2c7088` | Calls FUN_1402c7088 5 times in a loop | pattern | repeated_op |
| [0x140086570](decompiled/game-funcs/140086570_FUN_140086570.md) | 919 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x14010d260](decompiled/game-funcs/14010d260_FUN_14010d260.md) | 918 | `batch_call_0c6940` | Calls FUN_1400c6940 12 times in a loop | pattern | repeated_op |
| [0x1402cf520](decompiled/game-funcs/1402cf520_FUN_1402cf520.md) | 916 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1402eef9c](decompiled/game-funcs/1402eef9c_FUN_1402eef9c.md) | 915 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400168e0](decompiled/game-funcs/1400168e0_FUN_1400168e0.md) | 904 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x140105da0](decompiled/game-funcs/140105da0_FUN_140105da0.md) | 904 | `iter_horses_0xb8` | Iterates the horse list at obj+0xb8..0xc0 (one of the multiple horse lists) | pattern | iterates_horse_list_0xb8 |
| [0x1400aac60](decompiled/game-funcs/1400aac60_FUN_1400aac60.md) | 902 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 11 fields) | pattern | struct_init |
| [0x1400dbe10](decompiled/game-funcs/1400dbe10_FUN_1400dbe10.md) | 896 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 4 fields) | pattern | struct_init |
| [0x1400ff790](decompiled/game-funcs/1400ff790_FUN_1400ff790.md) | 886 | `iter_horses_0xb8` | Iterates the horse list at obj+0xb8..0xc0 (one of the multiple horse lists) | pattern | iterates_horse_list_0xb8 |
| [0x1402eb6f0](decompiled/game-funcs/1402eb6f0_FUN_1402eb6f0.md) | 882 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x1402d4650](decompiled/game-funcs/1402d4650_FUN_1402d4650.md) | 878 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 8 fields) | pattern | struct_init |
| [0x1400d23d0](decompiled/game-funcs/1400d23d0_FUN_1400d23d0.md) | 873 | `iter_horses_0xb8` | Iterates the horse list at obj+0xb8..0xc0 (one of the multiple horse lists) | pattern | iterates_horse_list_0xb8 |
| [0x1402d42e8](decompiled/game-funcs/1402d42e8_FUN_1402d42e8.md) | 871 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 8 fields) | pattern | struct_init |
| [0x1400bea50](decompiled/game-funcs/1400bea50_FUN_1400bea50.md) | 869 | `iter_horses_0xb8` | Iterates the horse list at obj+0xb8..0xc0 (one of the multiple horse lists) | pattern | iterates_horse_list_0xb8 |
| [0x1400fce70](decompiled/game-funcs/1400fce70_FUN_1400fce70.md) | 860 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400164b0](decompiled/game-funcs/1400164b0_FUN_1400164b0.md) | 854 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x14004d3b0](decompiled/game-funcs/14004d3b0_FUN_14004d3b0.md) | 851 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x1400b3650](decompiled/game-funcs/1400b3650_FUN_1400b3650.md) | 851 | `batch_call_0a53b0` | Calls FUN_1400a53b0 4 times in a loop | pattern | repeated_op |
| [0x1400379e0](decompiled/game-funcs/1400379e0_FUN_1400379e0.md) | 850 | `trigger_event` | Triggers the 'event' sound or event | pattern | plays_sound_or_event |
| [0x140067ad0](decompiled/game-funcs/140067ad0_FUN_140067ad0.md) | 850 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400c8220](decompiled/game-funcs/1400c8220_FUN_1400c8220.md) | 831 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1402cf1e0](decompiled/game-funcs/1402cf1e0_FUN_1402cf1e0.md) | 830 | `batch_call_2e8c20` | Calls FUN_1402e8c20 5 times in a loop | pattern | repeated_op |
| [0x1401bbf50](decompiled/game-funcs/1401bbf50_FUN_1401bbf50.md) | 828 | `batch_call_1749e0` | Calls FUN_1401749e0 5 times in a loop | pattern | repeated_op |
| [0x1400d2090](decompiled/game-funcs/1400d2090_FUN_1400d2090.md) | 821 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x140088990](decompiled/game-funcs/140088990_FUN_140088990.md) | 817 | `batch_call_0c6580` | Calls FUN_1400c6580 11 times in a loop | pattern | repeated_op |
| [0x1402ee62c](decompiled/game-funcs/1402ee62c_FUN_1402ee62c.md) | 815 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400a5950](decompiled/game-funcs/1400a5950_FUN_1400a5950.md) | 810 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140102530](decompiled/game-funcs/140102530_FUN_140102530.md) | 805 | `iter_horses_0xb8` | Iterates the horse list at obj+0xb8..0xc0 (one of the multiple horse lists) | pattern | iterates_horse_list_0xb8 |
| [0x1401b5d50](decompiled/game-funcs/1401b5d50_FUN_1401b5d50.md) | 805 | `float_math_main` | Heavy float math with many constants (a main computation routine) | pattern | float_math_complex |
| [0x14008f6e0](decompiled/game-funcs/14008f6e0_FUN_14008f6e0.md) | 804 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 5 fields) | pattern | struct_init |
| [0x1400479b0](decompiled/game-funcs/1400479b0_FUN_1400479b0.md) | 800 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x140101990](decompiled/game-funcs/140101990_FUN_140101990.md) | 799 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x1400293d0](decompiled/game-funcs/1400293d0_FUN_1400293d0.md) | 790 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 3 fields) | pattern | struct_init |
| [0x1402cdc50](decompiled/game-funcs/1402cdc50_FUN_1402cdc50.md) | 785 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x1400119a0](decompiled/game-funcs/1400119a0_FUN_1400119a0.md) | 780 | `batch_call_2e9a80` | Calls FUN_1402e9a80 4 times in a loop | pattern | repeated_op |
| [0x1402ebab0](decompiled/game-funcs/1402ebab0_FUN_1402ebab0.md) | 778 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x140088000](decompiled/game-funcs/140088000_FUN_140088000.md) | 775 | `batch_call_0c9c30` | Calls FUN_1400c9c30 6 times in a loop | pattern | repeated_op |
| [0x140024220](decompiled/game-funcs/140024220_FUN_140024220.md) | 766 | `helper_with_9_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140080730](decompiled/game-funcs/140080730_FUN_140080730.md) | 766 | `struct_handler` | Reads/writes many fields on a struct (32 field accesses on param_1) | pattern | struct_handler |
| [0x140048b90](decompiled/game-funcs/140048b90_FUN_140048b90.md) | 765 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400b56d0](decompiled/game-funcs/1400b56d0_FUN_1400b56d0.md) | 761 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400120b0](decompiled/game-funcs/1400120b0_FUN_1400120b0.md) | 754 | `batch_call_0124f0` | Calls FUN_1400124f0 4 times in a loop | pattern | repeated_op |
| [0x140055060](decompiled/game-funcs/140055060_FUN_140055060.md) | 753 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x14008d460](decompiled/game-funcs/14008d460_FUN_14008d460.md) | 752 | `helper_with_8_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14009b7b0](decompiled/game-funcs/14009b7b0_FUN_14009b7b0.md) | 751 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x14000f8d0](decompiled/game-funcs/14000f8d0_FUN_14000f8d0.md) | 740 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x1400b9250](decompiled/game-funcs/1400b9250_FUN_1400b9250.md) | 740 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1402efaac](decompiled/game-funcs/1402efaac_FUN_1402efaac.md) | 740 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400886a0](decompiled/game-funcs/1400886a0_FUN_1400886a0.md) | 739 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x14008cc80](decompiled/game-funcs/14008cc80_FUN_14008cc80.md) | 736 | `batch_call_2f94c0` | Calls FUN_1402f94c0 5 times in a loop | pattern | repeated_op |
| [0x1400cdae0](decompiled/game-funcs/1400cdae0_FUN_1400cdae0.md) | 733 | `iter_horses_0x26` | Iterates a horse list at param[0x26..0x27] | pattern | iterates_horse_list_0x26 |
| [0x1402d8688](decompiled/game-funcs/1402d8688_FUN_1402d8688.md) | 731 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1402d83ac](decompiled/game-funcs/1402d83ac_FUN_1402d83ac.md) | 729 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400297b0](decompiled/game-funcs/1400297b0_FUN_1400297b0.md) | 728 | `batch_call_2c704c` | Calls FUN_1402c704c 5 times in a loop | pattern | repeated_op |
| [0x1400cce00](decompiled/game-funcs/1400cce00_FUN_1400cce00.md) | 728 | `iter_horses_0xb8` | Iterates the horse list at obj+0xb8..0xc0 (one of the multiple horse lists) | pattern | iterates_horse_list_0xb8 |
| [0x140005a10](decompiled/game-funcs/140005a10_FUN_140005a10.md) | 725 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 7 fields) | pattern | struct_init |
| [0x1402f94c0](decompiled/game-funcs/1402f94c0_FUN_1402f94c0.md) | 725 | `switch_dispatch` | Multi-way switch; dispatches by enum/state value | pattern | switch_dispatcher |
| [0x140074020](decompiled/game-funcs/140074020_FUN_140074020.md) | 722 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x1400581a0](decompiled/game-funcs/1400581a0_FUN_1400581a0.md) | 715 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x14000fd50](decompiled/game-funcs/14000fd50_FUN_14000fd50.md) | 698 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x1402d1e3c](decompiled/game-funcs/1402d1e3c_FUN_1402d1e3c.md) | 692 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140008030](decompiled/game-funcs/140008030_FUN_140008030.md) | 688 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x140049380](decompiled/game-funcs/140049380_FUN_140049380.md) | 688 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400b6360](decompiled/game-funcs/1400b6360_FUN_1400b6360.md) | 682 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x1400c9980](decompiled/game-funcs/1400c9980_FUN_1400c9980.md) | 680 | `iter_horses_0x26` | Iterates a horse list at param[0x26..0x27] | pattern | iterates_horse_list_0x26 |
| [0x1400d83f0](decompiled/game-funcs/1400d83f0_FUN_1400d83f0.md) | 680 | `batch_call_0b6150` | Calls FUN_1400b6150 4 times in a loop | pattern | repeated_op |
| [0x1400d7fe0](decompiled/game-funcs/1400d7fe0_FUN_1400d7fe0.md) | 673 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140102b40](decompiled/game-funcs/140102b40_FUN_140102b40.md) | 673 | `struct_handler` | Reads/writes many fields on a struct (14 field accesses on param_1) | pattern | struct_handler |
| [0x140101dc0](decompiled/game-funcs/140101dc0_FUN_140101dc0.md) | 663 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x140105b00](decompiled/game-funcs/140105b00_FUN_140105b00.md) | 661 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140049b70](decompiled/game-funcs/140049b70_FUN_140049b70.md) | 655 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x140010ce0](decompiled/game-funcs/140010ce0_FUN_140010ce0.md) | 653 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140084060](decompiled/game-funcs/140084060_FUN_140084060.md) | 653 | `batch_call_009e60` | Calls FUN_140009e60 4 times in a loop | pattern | repeated_op |
| [0x1400cd2d0](decompiled/game-funcs/1400cd2d0_FUN_1400cd2d0.md) | 640 | `batch_call_071ed0` | Calls FUN_140071ed0 4 times in a loop | pattern | repeated_op |
| [0x140032320](decompiled/game-funcs/140032320_FUN_140032320.md) | 639 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140043810](decompiled/game-funcs/140043810_FUN_140043810.md) | 638 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401c9f60](decompiled/game-funcs/1401c9f60_FUN_1401c9f60.md) | 637 | `batch_call_12e0b0` | Calls FUN_14012e0b0 8 times in a loop | pattern | repeated_op |
| [0x1400b8f90](decompiled/game-funcs/1400b8f90_FUN_1400b8f90.md) | 636 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 3 fields) | pattern | struct_init |
| [0x140048360](decompiled/game-funcs/140048360_FUN_140048360.md) | 634 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400d86a0](decompiled/game-funcs/1400d86a0_FUN_1400d86a0.md) | 632 | `batch_call_0b6150` | Calls FUN_1400b6150 8 times in a loop | pattern | repeated_op |
| [0x140048910](decompiled/game-funcs/140048910_FUN_140048910.md) | 630 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140110bf0](decompiled/game-funcs/140110bf0_FUN_140110bf0.md) | 625 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400bf3c0](decompiled/game-funcs/1400bf3c0_FUN_1400bf3c0.md) | 623 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140042b70](decompiled/game-funcs/140042b70_FUN_140042b70.md) | 608 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 3 fields) | pattern | struct_init |
| [0x1400820a0](decompiled/game-funcs/1400820a0_FUN_1400820a0.md) | 607 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140047690](decompiled/game-funcs/140047690_FUN_140047690.md) | 603 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1402e6268](decompiled/game-funcs/1402e6268_FUN_1402e6268.md) | 602 | `batch_call_2e8664` | Calls FUN_1402e8664 4 times in a loop | pattern | repeated_op |
| [0x14000e0e0](decompiled/game-funcs/14000e0e0_FUN_14000e0e0.md) | 601 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x1402d6bc0](decompiled/game-funcs/1402d6bc0_FUN_1402d6bc0.md) | 601 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x14004d150](decompiled/game-funcs/14004d150_FUN_14004d150.md) | 600 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x1402d7d00](decompiled/game-funcs/1402d7d00_FUN_1402d7d00.md) | 593 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140073780](decompiled/game-funcs/140073780_FUN_140073780.md) | 592 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x140069ee0](decompiled/game-funcs/140069ee0_FUN_140069ee0.md) | 590 | `batch_call_0c9c30` | Calls FUN_1400c9c30 5 times in a loop | pattern | repeated_op |
| [0x1400fb050](decompiled/game-funcs/1400fb050_FUN_1400fb050.md) | 589 | `struct_handler` | Reads/writes many fields on a struct (9 field accesses on param_1) | pattern | struct_handler |
| [0x14003f340](decompiled/game-funcs/14003f340_FUN_14003f340.md) | 575 | `helper_with_13_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c7910](decompiled/game-funcs/1400c7910_FUN_1400c7910.md) | 566 | `helper_with_10_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400ffd00](decompiled/game-funcs/1400ffd00_FUN_1400ffd00.md) | 565 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140026080](decompiled/game-funcs/140026080_FUN_140026080.md) | 562 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400c31e0](decompiled/game-funcs/1400c31e0_FUN_1400c31e0.md) | 555 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140005eb0](decompiled/game-funcs/140005eb0_FUN_140005eb0.md) | 554 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140053810](decompiled/game-funcs/140053810_FUN_140053810.md) | 553 | `batch_call_04c8a0` | Calls FUN_14004c8a0 5 times in a loop | pattern | repeated_op |
| [0x1400b6aa0](decompiled/game-funcs/1400b6aa0_FUN_1400b6aa0.md) | 551 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x1400ccbd0](decompiled/game-funcs/1400ccbd0_FUN_1400ccbd0.md) | 551 | `iter_horses_0xb8` | Iterates the horse list at obj+0xb8..0xc0 (one of the multiple horse lists) | pattern | iterates_horse_list_0xb8 |
| [0x14005bc30](decompiled/game-funcs/14005bc30_FUN_14005bc30.md) | 548 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400b54a0](decompiled/game-funcs/1400b54a0_FUN_1400b54a0.md) | 546 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x140041900](decompiled/game-funcs/140041900_FUN_140041900.md) | 544 | `batch_call_054630` | Calls FUN_140054630 4 times in a loop | pattern | repeated_op |
| [0x14009bea0](decompiled/game-funcs/14009bea0_FUN_14009bea0.md) | 543 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400ab1b0](decompiled/game-funcs/1400ab1b0_FUN_1400ab1b0.md) | 535 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x140100a40](decompiled/game-funcs/140100a40_FUN_140100a40.md) | 535 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x14005cf70](decompiled/game-funcs/14005cf70_FUN_14005cf70.md) | 534 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140030940](decompiled/game-funcs/140030940_FUN_140030940.md) | 528 | `trigger_event` | Triggers the 'event' sound or event | pattern | plays_sound_or_event |
| [0x1400bedc0](decompiled/game-funcs/1400bedc0_FUN_1400bedc0.md) | 528 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x14007dbf0](decompiled/game-funcs/14007dbf0_FUN_14007dbf0.md) | 518 | `batch_call_0cb670` | Calls FUN_1400cb670 8 times in a loop | pattern | repeated_op |
| [0x1400b6610](decompiled/game-funcs/1400b6610_FUN_1400b6610.md) | 518 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x1402e6d50](decompiled/game-funcs/1402e6d50_FUN_1402e6d50.md) | 518 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1401b52b0](decompiled/game-funcs/1401b52b0_FUN_1401b52b0.md) | 517 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x1402d285c](decompiled/game-funcs/1402d285c_FUN_1402d285c.md) | 515 | `struct_handler` | Reads/writes many fields on a struct (30 field accesses on param_1) | pattern | struct_handler |
| [0x1402d2c6c](decompiled/game-funcs/1402d2c6c_FUN_1402d2c6c.md) | 515 | `struct_handler` | Reads/writes many fields on a struct (30 field accesses on param_1) | pattern | struct_handler |
| [0x1402d307c](decompiled/game-funcs/1402d307c_FUN_1402d307c.md) | 515 | `struct_handler` | Reads/writes many fields on a struct (30 field accesses on param_1) | pattern | struct_handler |
| [0x1400d8e00](decompiled/game-funcs/1400d8e00_FUN_1400d8e00.md) | 511 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402eda40](decompiled/game-funcs/1402eda40_FUN_1402eda40.md) | 510 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140111a50](decompiled/game-funcs/140111a50_FUN_140111a50.md) | 508 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140046e50](decompiled/game-funcs/140046e50_FUN_140046e50.md) | 506 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400a9360](decompiled/game-funcs/1400a9360_FUN_1400a9360.md) | 502 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x1402cfda0](decompiled/game-funcs/1402cfda0_FUN_1402cfda0.md) | 502 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x1400a33b0](decompiled/game-funcs/1400a33b0_FUN_1400a33b0.md) | 501 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x14009ebd0](decompiled/game-funcs/14009ebd0_FUN_14009ebd0.md) | 499 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140025120](decompiled/game-funcs/140025120_FUN_140025120.md) | 497 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140040ca0](decompiled/game-funcs/140040ca0_FUN_140040ca0.md) | 497 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c5d10](decompiled/game-funcs/1400c5d10_FUN_1400c5d10.md) | 497 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400fd1e0](decompiled/game-funcs/1400fd1e0_FUN_1400fd1e0.md) | 495 | `iter_horses_0xb8` | Iterates the horse list at obj+0xb8..0xc0 (one of the multiple horse lists) | pattern | iterates_horse_list_0xb8 |
| [0x140011000](decompiled/game-funcs/140011000_FUN_140011000.md) | 494 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400111f0](decompiled/game-funcs/1400111f0_FUN_1400111f0.md) | 493 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400749b0](decompiled/game-funcs/1400749b0_FUN_1400749b0.md) | 486 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400a9560](decompiled/game-funcs/1400a9560_FUN_1400a9560.md) | 486 | `batch_call_0a9360` | Calls FUN_1400a9360 4 times in a loop | pattern | repeated_op |
| [0x14005de20](decompiled/game-funcs/14005de20_FUN_14005de20.md) | 485 | `helper_with_8_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400a2ed0](decompiled/game-funcs/1400a2ed0_FUN_1400a2ed0.md) | 485 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400ffb10](decompiled/game-funcs/1400ffb10_FUN_1400ffb10.md) | 484 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1402ecb70](decompiled/game-funcs/1402ecb70_FUN_1402ecb70.md) | 483 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400d6d50](decompiled/game-funcs/1400d6d50_FUN_1400d6d50.md) | 482 | `batch_call_0b6150` | Calls FUN_1400b6150 4 times in a loop | pattern | repeated_op |
| [0x1402ef434](decompiled/game-funcs/1402ef434_FUN_1402ef434.md) | 480 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x14008fce0](decompiled/game-funcs/14008fce0_FUN_14008fce0.md) | 477 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 3 fields) | pattern | struct_init |
| [0x140111f20](decompiled/game-funcs/140111f20_FUN_140111f20.md) | 477 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140110a10](decompiled/game-funcs/140110a10_FUN_140110a10.md) | 473 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x14005c9b0](decompiled/game-funcs/14005c9b0_FUN_14005c9b0.md) | 472 | `struct_handler` | Reads/writes many fields on a struct (13 field accesses on param_1) | pattern | struct_handler |
| [0x1400aa0d0](decompiled/game-funcs/1400aa0d0_FUN_1400aa0d0.md) | 472 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x1400cd0f0](decompiled/game-funcs/1400cd0f0_FUN_1400cd0f0.md) | 472 | `iter_horses_0xb8` | Iterates the horse list at obj+0xb8..0xc0 (one of the multiple horse lists) | pattern | iterates_horse_list_0xb8 |
| [0x14010d600](decompiled/game-funcs/14010d600_FUN_14010d600.md) | 472 | `batch_call_0c6940` | Calls FUN_1400c6940 4 times in a loop | pattern | repeated_op |
| [0x140037710](decompiled/game-funcs/140037710_FUN_140037710.md) | 467 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400117d0](decompiled/game-funcs/1400117d0_FUN_1400117d0.md) | 459 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x14008f130](decompiled/game-funcs/14008f130_FUN_14008f130.md) | 459 | `welcome_dialog` | Welcome dialog | string | struct_handler |
| [0x1402e06dc](decompiled/game-funcs/1402e06dc_FUN_1402e06dc.md) | 457 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 10 fields) | pattern | struct_init |
| [0x140012630](decompiled/game-funcs/140012630_FUN_140012630.md) | 456 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400c9c30](decompiled/game-funcs/1400c9c30_FUN_1400c9c30.md) | 456 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140048740](decompiled/game-funcs/140048740_FUN_140048740.md) | 455 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x1400d6f40](decompiled/game-funcs/1400d6f40_FUN_1400d6f40.md) | 455 | `batch_call_0b6150` | Calls FUN_1400b6150 8 times in a loop | pattern | repeated_op |
| [0x1402dff58](decompiled/game-funcs/1402dff58_FUN_1402dff58.md) | 455 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 19 fields) | pattern | struct_init |
| [0x14001d240](decompiled/game-funcs/14001d240_FUN_14001d240.md) | 454 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x1401003e0](decompiled/game-funcs/1401003e0_FUN_1401003e0.md) | 454 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140072100](decompiled/game-funcs/140072100_FUN_140072100.md) | 453 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x14004cf80](decompiled/game-funcs/14004cf80_FUN_14004cf80.md) | 452 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x1400cf620](decompiled/game-funcs/1400cf620_FUN_1400cf620.md) | 451 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x14005d190](decompiled/game-funcs/14005d190_FUN_14005d190.md) | 450 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1402d7b3c](decompiled/game-funcs/1402d7b3c_FUN_1402d7b3c.md) | 449 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140006230](decompiled/game-funcs/140006230_FUN_140006230.md) | 446 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1402f0198](decompiled/game-funcs/1402f0198_FUN_1402f0198.md) | 445 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140087c70](decompiled/game-funcs/140087c70_FUN_140087c70.md) | 442 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140110ef0](decompiled/game-funcs/140110ef0_FUN_140110ef0.md) | 442 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140055360](decompiled/game-funcs/140055360_FUN_140055360.md) | 441 | `batch_call_04cb40` | Calls FUN_14004cb40 4 times in a loop | pattern | repeated_op |
| [0x1402d05a0](decompiled/game-funcs/1402d05a0_FUN_1402d05a0.md) | 441 | `batch_call_2ed0a0` | Calls FUN_1402ed0a0 5 times in a loop | pattern | repeated_op |
| [0x1400c7320](decompiled/game-funcs/1400c7320_FUN_1400c7320.md) | 438 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1401017d0](decompiled/game-funcs/1401017d0_FUN_1401017d0.md) | 437 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1402f0444](decompiled/game-funcs/1402f0444_FUN_1402f0444.md) | 437 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x14004d710](decompiled/game-funcs/14004d710_FUN_14004d710.md) | 434 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x140104c00](decompiled/game-funcs/140104c00_FUN_140104c00.md) | 433 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402ec028](decompiled/game-funcs/1402ec028_FUN_1402ec028.md) | 433 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400d6b90](decompiled/game-funcs/1400d6b90_FUN_1400d6b90.md) | 432 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x14012e880](decompiled/game-funcs/14012e880_FUN_14012e880.md) | 432 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1402efd94](decompiled/game-funcs/1402efd94_FUN_1402efd94.md) | 432 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14005fad0](decompiled/game-funcs/14005fad0_FUN_14005fad0.md) | 431 | `trigger_event` | Triggers the 'event' sound or event | pattern | plays_sound_or_event |
| [0x1402d1af8](decompiled/game-funcs/1402d1af8_FUN_1402d1af8.md) | 431 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400b6cd0](decompiled/game-funcs/1400b6cd0_FUN_1400b6cd0.md) | 430 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14004a250](decompiled/game-funcs/14004a250_FUN_14004a250.md) | 423 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1402eb470](decompiled/game-funcs/1402eb470_FUN_1402eb470.md) | 421 | `helper_with_7_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140100230](decompiled/game-funcs/140100230_FUN_140100230.md) | 419 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400753f0](decompiled/game-funcs/1400753f0_FUN_1400753f0.md) | 418 | `helper_with_11_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140071d20](decompiled/game-funcs/140071d20_FUN_140071d20.md) | 417 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400b47e0](decompiled/game-funcs/1400b47e0_FUN_1400b47e0.md) | 417 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 3 fields) | pattern | struct_init |
| [0x1400be740](decompiled/game-funcs/1400be740_FUN_1400be740.md) | 416 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140027c80](decompiled/game-funcs/140027c80_FUN_140027c80.md) | 415 | `batch_call_2f8e20` | Calls FUN_1402f8e20 4 times in a loop | pattern | repeated_op |
| [0x140049f80](decompiled/game-funcs/140049f80_FUN_140049f80.md) | 411 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140197820](decompiled/game-funcs/140197820_FUN_140197820.md) | 407 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x1402e0a58](decompiled/game-funcs/1402e0a58_FUN_1402e0a58.md) | 406 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 15 fields) | pattern | struct_init |
| [0x140032610](decompiled/game-funcs/140032610_FUN_140032610.md) | 402 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400c9290](decompiled/game-funcs/1400c9290_FUN_1400c9290.md) | 400 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400d7cd0](decompiled/game-funcs/1400d7cd0_FUN_1400d7cd0.md) | 399 | `batch_call_0b6150` | Calls FUN_1400b6150 4 times in a loop | pattern | repeated_op |
| [0x14000fbc0](decompiled/game-funcs/14000fbc0_FUN_14000fbc0.md) | 398 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140074da0](decompiled/game-funcs/140074da0_FUN_140074da0.md) | 392 | `helper_with_7_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402d50cc](decompiled/game-funcs/1402d50cc_FUN_1402d50cc.md) | 391 | `struct_handler` | Reads/writes many fields on a struct (11 field accesses on param_1) | pattern | struct_handler |
| [0x1402cee24](decompiled/game-funcs/1402cee24_FUN_1402cee24.md) | 390 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400d1c40](decompiled/game-funcs/1400d1c40_FUN_1400d1c40.md) | 386 | `helper_with_8_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402e6bc0](decompiled/game-funcs/1402e6bc0_FUN_1402e6bc0.md) | 385 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400153e0](decompiled/game-funcs/1400153e0_FUN_1400153e0.md) | 383 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140025f00](decompiled/game-funcs/140025f00_FUN_140025f00.md) | 383 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400b8420](decompiled/game-funcs/1400b8420_FUN_1400b8420.md) | 383 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400b2ee0](decompiled/game-funcs/1400b2ee0_FUN_1400b2ee0.md) | 382 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400d7e60](decompiled/game-funcs/1400d7e60_FUN_1400d7e60.md) | 382 | `batch_call_0b6150` | Calls FUN_1400b6150 8 times in a loop | pattern | repeated_op |
| [0x140007610](decompiled/game-funcs/140007610_FUN_140007610.md) | 381 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 4 fields) | pattern | struct_init |
| [0x140049e00](decompiled/game-funcs/140049e00_FUN_140049e00.md) | 381 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x14002cd80](decompiled/game-funcs/14002cd80_FUN_14002cd80.md) | 379 | `trigger_event` | Triggers the 'event' sound or event | pattern | plays_sound_or_event |
| [0x140100e30](decompiled/game-funcs/140100e30_FUN_140100e30.md) | 379 | `helper_with_10_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140071810](decompiled/game-funcs/140071810_FUN_140071810.md) | 378 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140072a10](decompiled/game-funcs/140072a10_FUN_140072a10.md) | 378 | `switch_dispatch` | Multi-way switch; dispatches by enum/state value | pattern | switch_dispatcher |
| [0x140163ac0](decompiled/game-funcs/140163ac0_FUN_140163ac0.md) | 378 | `batch_call_138fe0` | Calls FUN_140138fe0 4 times in a loop | pattern | repeated_op |
| [0x140065a90](decompiled/game-funcs/140065a90_FUN_140065a90.md) | 376 | `struct_handler` | Reads/writes many fields on a struct (20 field accesses on param_1) | pattern | struct_handler |
| [0x1400bf7f0](decompiled/game-funcs/1400bf7f0_FUN_1400bf7f0.md) | 376 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402eff44](decompiled/game-funcs/1402eff44_FUN_1402eff44.md) | 376 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140012a20](decompiled/game-funcs/140012a20_FUN_140012a20.md) | 374 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x1402ee300](decompiled/game-funcs/1402ee300_FUN_1402ee300.md) | 372 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140027f50](decompiled/game-funcs/140027f50_FUN_140027f50.md) | 369 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140030680](decompiled/game-funcs/140030680_FUN_140030680.md) | 366 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14000d4e0](decompiled/game-funcs/14000d4e0_FUN_14000d4e0.md) | 365 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 3 fields) | pattern | struct_init |
| [0x140057a60](decompiled/game-funcs/140057a60_FUN_140057a60.md) | 365 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401041f0](decompiled/game-funcs/1401041f0_FUN_1401041f0.md) | 365 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 4 fields) | pattern | struct_init |
| [0x14010de70](decompiled/game-funcs/14010de70_FUN_14010de70.md) | 365 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x1402cd188](decompiled/game-funcs/1402cd188_FUN_1402cd188.md) | 365 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401427d0](decompiled/game-funcs/1401427d0_FUN_1401427d0.md) | 364 | `helper_with_11_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140064060](decompiled/game-funcs/140064060_FUN_140064060.md) | 363 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400aaa30](decompiled/game-funcs/1400aaa30_FUN_1400aaa30.md) | 363 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x140080cc0](decompiled/game-funcs/140080cc0_FUN_140080cc0.md) | 362 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 4 fields) | pattern | struct_init |
| [0x140075120](decompiled/game-funcs/140075120_FUN_140075120.md) | 359 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x140016340](decompiled/game-funcs/140016340_FUN_140016340.md) | 356 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402daf2c](decompiled/game-funcs/1402daf2c_FUN_1402daf2c.md) | 356 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14003ee40](decompiled/game-funcs/14003ee40_FUN_14003ee40.md) | 354 | `sound_xml_loader` | Parse sound.xml sound registry | string | helper |
| [0x140036850](decompiled/game-funcs/140036850_FUN_140036850.md) | 352 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401300a0](decompiled/game-funcs/1401300a0_FUN_1401300a0.md) | 352 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140027b20](decompiled/game-funcs/140027b20_FUN_140027b20.md) | 348 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400485e0](decompiled/game-funcs/1400485e0_FUN_1400485e0.md) | 348 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140074f80](decompiled/game-funcs/140074f80_FUN_140074f80.md) | 348 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1402cecc8](decompiled/game-funcs/1402cecc8_FUN_1402cecc8.md) | 347 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14017c930](decompiled/game-funcs/14017c930_FUN_14017c930.md) | 345 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402ebe30](decompiled/game-funcs/1402ebe30_FUN_1402ebe30.md) | 345 | `batch_call_2e68b0` | Calls FUN_1402e68b0 4 times in a loop | pattern | repeated_op |
| [0x1400739e0](decompiled/game-funcs/1400739e0_FUN_1400739e0.md) | 344 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x1402c793c](decompiled/game-funcs/1402c793c___scrt_common_main_seh.md) | 343 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400d8290](decompiled/game-funcs/1400d8290_FUN_1400d8290.md) | 342 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400be8f0](decompiled/game-funcs/1400be8f0_FUN_1400be8f0.md) | 341 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400b7770](decompiled/game-funcs/1400b7770_FUN_1400b7770.md) | 340 | `struct_handler` | Reads/writes many fields on a struct (12 field accesses on param_1) | pattern | struct_handler |
| [0x1400d7190](decompiled/game-funcs/1400d7190_FUN_1400d7190.md) | 339 | `batch_call_0b6150` | Calls FUN_1400b6150 12 times in a loop | pattern | repeated_op |
| [0x140184320](decompiled/game-funcs/140184320_FUN_140184320.md) | 339 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402ef840](decompiled/game-funcs/1402ef840_FUN_1402ef840.md) | 338 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400a8890](decompiled/game-funcs/1400a8890_FUN_1400a8890.md) | 337 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x1400cb760](decompiled/game-funcs/1400cb760_FUN_1400cb760.md) | 337 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402ceb78](decompiled/game-funcs/1402ceb78_FUN_1402ceb78.md) | 336 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14010cd90](decompiled/game-funcs/14010cd90_FUN_14010cd90.md) | 335 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140103450](decompiled/game-funcs/140103450_FUN_140103450.md) | 334 | `iter_horses_0xb8` | Iterates the horse list at obj+0xb8..0xc0 (one of the multiple horse lists) | pattern | iterates_horse_list_0xb8 |
| [0x1402ef6f0](decompiled/game-funcs/1402ef6f0_FUN_1402ef6f0.md) | 333 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140015ae0](decompiled/game-funcs/140015ae0_FUN_140015ae0.md) | 332 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x140174e70](decompiled/game-funcs/140174e70_FUN_140174e70.md) | 332 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x14004cb40](decompiled/game-funcs/14004cb40_FUN_14004cb40.md) | 330 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1402f08b0](decompiled/game-funcs/1402f08b0_FUN_1402f08b0.md) | 330 | `switch_dispatch` | Multi-way switch; dispatches by enum/state value | pattern | switch_dispatcher |
| [0x14004ec60](decompiled/game-funcs/14004ec60_FUN_14004ec60.md) | 328 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400409d0](decompiled/game-funcs/1400409d0_FUN_1400409d0.md) | 326 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400060e0](decompiled/game-funcs/1400060e0_FUN_1400060e0.md) | 324 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x14012e110](decompiled/game-funcs/14012e110_FUN_14012e110.md) | 323 | `helper_with_7_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140179150](decompiled/game-funcs/140179150_FUN_140179150.md) | 323 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1402eca20](decompiled/game-funcs/1402eca20_FUN_1402eca20.md) | 323 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140007dd0](decompiled/game-funcs/140007dd0_FUN_140007dd0.md) | 321 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x140084370](decompiled/game-funcs/140084370_FUN_140084370.md) | 321 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400a2d80](decompiled/game-funcs/1400a2d80_FUN_1400a2d80.md) | 321 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x14005c5d0](decompiled/game-funcs/14005c5d0_FUN_14005c5d0.md) | 320 | `welcome_dialog` | Welcome dialog | string | medium_loop |
| [0x1402e8f40](decompiled/game-funcs/1402e8f40_FUN_1402e8f40.md) | 320 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400d8ab0](decompiled/game-funcs/1400d8ab0_FUN_1400d8ab0.md) | 319 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400535f0](decompiled/game-funcs/1400535f0_FUN_1400535f0.md) | 318 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 3 fields) | pattern | struct_init |
| [0x140009ca0](decompiled/game-funcs/140009ca0_FUN_140009ca0.md) | 315 | `struct_handler` | Reads/writes many fields on a struct (14 field accesses on param_1) | pattern | struct_handler |
| [0x1400123b0](decompiled/game-funcs/1400123b0_FUN_1400123b0.md) | 314 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140047420](decompiled/game-funcs/140047420_FUN_140047420.md) | 314 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1401c4180](decompiled/game-funcs/1401c4180_FUN_1401c4180.md) | 314 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14006fe60](decompiled/game-funcs/14006fe60_FUN_14006fe60.md) | 309 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400b6e90](decompiled/game-funcs/1400b6e90_FUN_1400b6e90.md) | 307 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402e8e00](decompiled/game-funcs/1402e8e00_FUN_1402e8e00.md) | 307 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140064590](decompiled/game-funcs/140064590_FUN_140064590.md) | 306 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 3 fields) | pattern | struct_init |
| [0x1402c6b54](decompiled/game-funcs/1402c6b54_FUN_1402c6b54.md) | 306 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1402f6830](decompiled/game-funcs/1402f6830_FUN_1402f6830.md) | 304 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140007ca0](decompiled/game-funcs/140007ca0_FUN_140007ca0.md) | 302 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400279c0](decompiled/game-funcs/1400279c0_FUN_1400279c0.md) | 302 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402c9210](decompiled/game-funcs/1402c9210_FUN_1402c9210.md) | 302 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140010010](decompiled/game-funcs/140010010_FUN_140010010.md) | 301 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x140071f00](decompiled/game-funcs/140071f00_FUN_140071f00.md) | 301 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1402d0130](decompiled/game-funcs/1402d0130_FUN_1402d0130.md) | 298 | `batch_call_2ece80` | Calls FUN_1402ece80 6 times in a loop | pattern | repeated_op |
| [0x14004c8a0](decompiled/game-funcs/14004c8a0_FUN_14004c8a0.md) | 295 | `batch_call_2ce36c` | Calls FUN_1402ce36c 4 times in a loop | pattern | repeated_op |
| [0x1400184f0](decompiled/game-funcs/1400184f0_FUN_1400184f0.md) | 294 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140047560](decompiled/game-funcs/140047560_FUN_140047560.md) | 293 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140027540](decompiled/game-funcs/140027540_FUN_140027540.md) | 292 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401750b0](decompiled/game-funcs/1401750b0_FUN_1401750b0.md) | 292 | `helper_with_9_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402e0d04](decompiled/game-funcs/1402e0d04_FUN_1402e0d04.md) | 292 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401ab630](decompiled/game-funcs/1401ab630_FUN_1401ab630.md) | 290 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140083480](decompiled/game-funcs/140083480_FUN_140083480.md) | 289 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x14009c390](decompiled/game-funcs/14009c390_FUN_14009c390.md) | 289 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400b2cd0](decompiled/game-funcs/1400b2cd0_FUN_1400b2cd0.md) | 288 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c6bd0](decompiled/game-funcs/1400c6bd0_FUN_1400c6bd0.md) | 288 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402eada0](decompiled/game-funcs/1402eada0_FUN_1402eada0.md) | 286 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 3 fields) | pattern | struct_init |
| [0x140010310](decompiled/game-funcs/140010310_FUN_140010310.md) | 285 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401cb240](decompiled/game-funcs/1401cb240_FUN_1401cb240.md) | 285 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402ee50c](decompiled/game-funcs/1402ee50c_FUN_1402ee50c.md) | 285 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 3 fields) | pattern | struct_init |
| [0x140027e30](decompiled/game-funcs/140027e30_FUN_140027e30.md) | 284 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14003e600](decompiled/game-funcs/14003e600_FUN_14003e600.md) | 284 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400b8c60](decompiled/game-funcs/1400b8c60_FUN_1400b8c60.md) | 283 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402ee1e4](decompiled/game-funcs/1402ee1e4_FUN_1402ee1e4.md) | 283 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400f4ea0](decompiled/game-funcs/1400f4ea0_FUN_1400f4ea0.md) | 282 | `batch_call_0cf540` | Calls FUN_1400cf540 4 times in a loop | pattern | repeated_op |
| [0x1400bf970](decompiled/game-funcs/1400bf970_FUN_1400bf970.md) | 281 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140082430](decompiled/game-funcs/140082430_FUN_140082430.md) | 280 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400cb8c0](decompiled/game-funcs/1400cb8c0_FUN_1400cb8c0.md) | 280 | `prize_appear_sound` | Plays prize-appear sound | string | helper |
| [0x1400c57a0](decompiled/game-funcs/1400c57a0_FUN_1400c57a0.md) | 277 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402ce36c](decompiled/game-funcs/1402ce36c_FUN_1402ce36c.md) | 275 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140077ae0](decompiled/game-funcs/140077ae0_FUN_140077ae0.md) | 274 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140086450](decompiled/game-funcs/140086450_FUN_140086450.md) | 274 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c6ab0](decompiled/game-funcs/1400c6ab0_FUN_1400c6ab0.md) | 274 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c7c60](decompiled/game-funcs/1400c7c60_FUN_1400c7c60.md) | 274 | `helper_with_7_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140071000](decompiled/game-funcs/140071000_FUN_140071000.md) | 272 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402f6b8c](decompiled/game-funcs/1402f6b8c_FUN_1402f6b8c.md) | 272 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c7600](decompiled/game-funcs/1400c7600_FUN_1400c7600.md) | 270 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402e0948](decompiled/game-funcs/1402e0948_FUN_1402e0948.md) | 269 | `struct_handler` | Reads/writes many fields on a struct (9 field accesses on param_1) | pattern | struct_handler |
| [0x1401c7e90](decompiled/game-funcs/1401c7e90_FUN_1401c7e90.md) | 267 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400272d0](decompiled/game-funcs/1400272d0_FUN_1400272d0.md) | 264 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140055b20](decompiled/game-funcs/140055b20_FUN_140055b20.md) | 263 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400a9180](decompiled/game-funcs/1400a9180_FUN_1400a9180.md) | 263 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402ee0dc](decompiled/game-funcs/1402ee0dc_FUN_1402ee0dc.md) | 263 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140083c30](decompiled/game-funcs/140083c30_FUN_140083c30.md) | 262 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140184480](decompiled/game-funcs/140184480_FUN_140184480.md) | 262 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140005cf0](decompiled/game-funcs/140005cf0_FUN_140005cf0.md) | 260 | `batch_call_2e9a80` | Calls FUN_1402e9a80 5 times in a loop | pattern | repeated_op |
| [0x140007f20](decompiled/game-funcs/140007f20_FUN_140007f20.md) | 260 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140104df0](decompiled/game-funcs/140104df0_FUN_140104df0.md) | 260 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402ef330](decompiled/game-funcs/1402ef330_FUN_1402ef330.md) | 260 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140072fe0](decompiled/game-funcs/140072fe0_FUN_140072fe0.md) | 259 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400d1e10](decompiled/game-funcs/1400d1e10_FUN_1400d1e10.md) | 259 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401c0ba0](decompiled/game-funcs/1401c0ba0_FUN_1401c0ba0.md) | 259 | `switch_dispatch` | Multi-way switch; dispatches by enum/state value | pattern | switch_dispatcher |
| [0x1401749e0](decompiled/game-funcs/1401749e0_FUN_1401749e0.md) | 257 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401ab100](decompiled/game-funcs/1401ab100_FUN_1401ab100.md) | 257 | `helper_with_8_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402e8cf0](decompiled/game-funcs/1402e8cf0_FUN_1402e8cf0.md) | 257 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400ab0a0](decompiled/game-funcs/1400ab0a0_FUN_1400ab0a0.md) | 255 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140179a30](decompiled/game-funcs/140179a30_FUN_140179a30.md) | 255 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400bf2c0](decompiled/game-funcs/1400bf2c0_FUN_1400bf2c0.md) | 253 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400cfa00](decompiled/game-funcs/1400cfa00_FUN_1400cfa00.md) | 253 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140092710](decompiled/game-funcs/140092710_FUN_140092710.md) | 252 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400b6990](decompiled/game-funcs/1400b6990_FUN_1400b6990.md) | 252 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c9e00](decompiled/game-funcs/1400c9e00_FUN_1400c9e00.md) | 251 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402ce864](decompiled/game-funcs/1402ce864_FUN_1402ce864.md) | 250 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c85f0](decompiled/game-funcs/1400c85f0_FUN_1400c85f0.md) | 249 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400457f0](decompiled/game-funcs/1400457f0_FUN_1400457f0.md) | 247 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402ee95c](decompiled/game-funcs/1402ee95c_FUN_1402ee95c.md) | 247 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402cf0e0](decompiled/game-funcs/1402cf0e0_FUN_1402cf0e0.md) | 246 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14004edb0](decompiled/game-funcs/14004edb0_FUN_14004edb0.md) | 244 | `struct_handler` | Reads/writes many fields on a struct (14 field accesses on param_1) | pattern | struct_handler |
| [0x1400a6cb0](decompiled/game-funcs/1400a6cb0_FUN_1400a6cb0.md) | 244 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400b6260](decompiled/game-funcs/1400b6260_FUN_1400b6260.md) | 244 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401746e0](decompiled/game-funcs/1401746e0_FUN_1401746e0.md) | 242 | `helper_with_10_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402e01d4](decompiled/game-funcs/1402e01d4_FUN_1402e01d4.md) | 241 | `struct_handler` | Reads/writes many fields on a struct (14 field accesses on param_1) | pattern | struct_handler |
| [0x140071990](decompiled/game-funcs/140071990_FUN_140071990.md) | 239 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14004a120](decompiled/game-funcs/14004a120_FUN_14004a120.md) | 236 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400b6890](decompiled/game-funcs/1400b6890_FUN_1400b6890.md) | 236 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140009f80](decompiled/game-funcs/140009f80_FUN_140009f80.md) | 235 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x140174c40](decompiled/game-funcs/140174c40_FUN_140174c40.md) | 234 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401aa890](decompiled/game-funcs/1401aa890_FUN_1401aa890.md) | 234 | `helper_with_7_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402ce960](decompiled/game-funcs/1402ce960_FUN_1402ce960.md) | 234 | `struct_handler` | Reads/writes many fields on a struct (8 field accesses on param_1) | pattern | struct_handler |
| [0x1402d1900](decompiled/game-funcs/1402d1900_FUN_1402d1900.md) | 234 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140197730](decompiled/game-funcs/140197730_FUN_140197730.md) | 233 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401c85b0](decompiled/game-funcs/1401c85b0_FUN_1401c85b0.md) | 232 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14007ad10](decompiled/game-funcs/14007ad10_FUN_14007ad10.md) | 231 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400cb670](decompiled/game-funcs/1400cb670_FUN_1400cb670.md) | 230 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401a9ef0](decompiled/game-funcs/1401a9ef0_FUN_1401a9ef0.md) | 230 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400b6170](decompiled/game-funcs/1400b6170_FUN_1400b6170.md) | 229 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401ab3d0](decompiled/game-funcs/1401ab3d0_FUN_1401ab3d0.md) | 229 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14005bad0](decompiled/game-funcs/14005bad0_FUN_14005bad0.md) | 228 | `trigger_event` | Triggers the 'event' sound or event | pattern | plays_sound_or_event |
| [0x140010b00](decompiled/game-funcs/140010b00_FUN_140010b00.md) | 227 | `switch_dispatch` | Multi-way switch; dispatches by enum/state value | pattern | switch_dispatcher |
| [0x140082550](decompiled/game-funcs/140082550_FUN_140082550.md) | 227 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140092620](decompiled/game-funcs/140092620_FUN_140092620.md) | 227 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402da06c](decompiled/game-funcs/1402da06c_FUN_1402da06c.md) | 227 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14002f0f0](decompiled/game-funcs/14002f0f0_FUN_14002f0f0.md) | 225 | `trigger_event` | Triggers the 'event' sound or event | pattern | plays_sound_or_event |
| [0x1400c69c0](decompiled/game-funcs/1400c69c0_FUN_1400c69c0.md) | 225 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401acdd0](decompiled/game-funcs/1401acdd0_FUN_1401acdd0.md) | 225 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400a32c0](decompiled/game-funcs/1400a32c0_FUN_1400a32c0.md) | 224 | `batch_call_0c6580` | Calls FUN_1400c6580 6 times in a loop | pattern | repeated_op |
| [0x1402cfa08](decompiled/game-funcs/1402cfa08_FUN_1402cfa08.md) | 222 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402f31e0](decompiled/game-funcs/1402f31e0_FUN_1402f31e0.md) | 222 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140010430](decompiled/game-funcs/140010430_FUN_140010430.md) | 220 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140100c90](decompiled/game-funcs/140100c90_FUN_140100c90.md) | 220 | `struct_handler` | Reads/writes many fields on a struct (8 field accesses on param_1) | pattern | struct_handler |
| [0x140038f20](decompiled/game-funcs/140038f20_FUN_140038f20.md) | 218 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140053730](decompiled/game-funcs/140053730_FUN_140053730.md) | 218 | `struct_handler` | Reads/writes many fields on a struct (14 field accesses on param_1) | pattern | struct_handler |
| [0x1400b4a10](decompiled/game-funcs/1400b4a10_FUN_1400b4a10.md) | 216 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x1402f66e0](decompiled/game-funcs/1402f66e0_FUN_1402f66e0.md) | 216 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400a5e00](decompiled/game-funcs/1400a5e00_FUN_1400a5e00.md) | 215 | `bad_gene_index_error` | Reports a bad gene index | string | helper |
| [0x140107550](decompiled/game-funcs/140107550_FUN_140107550.md) | 214 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401c86a0](decompiled/game-funcs/1401c86a0_FUN_1401c86a0.md) | 214 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14000ce00](decompiled/game-funcs/14000ce00_FUN_14000ce00.md) | 213 | `struct_handler` | Reads/writes many fields on a struct (12 field accesses on param_1) | pattern | struct_handler |
| [0x140082330](decompiled/game-funcs/140082330_FUN_140082330.md) | 213 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402ef618](decompiled/game-funcs/1402ef618_FUN_1402ef618.md) | 213 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400a5d20](decompiled/game-funcs/1400a5d20_FUN_1400a5d20.md) | 212 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14004eeb0](decompiled/game-funcs/14004eeb0_FUN_14004eeb0.md) | 211 | `struct_handler` | Reads/writes many fields on a struct (14 field accesses on param_1) | pattern | struct_handler |
| [0x1400cf540](decompiled/game-funcs/1400cf540_FUN_1400cf540.md) | 211 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140083b50](decompiled/game-funcs/140083b50_FUN_140083b50.md) | 210 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402d7098](decompiled/game-funcs/1402d7098_FUN_1402d7098.md) | 210 | `struct_handler` | Reads/writes many fields on a struct (20 field accesses on param_1) | pattern | struct_handler |
| [0x140028820](decompiled/game-funcs/140028820_FUN_140028820.md) | 209 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402f6abc](decompiled/game-funcs/1402f6abc_FUN_1402f6abc.md) | 208 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14009c6a0](decompiled/game-funcs/14009c6a0_FUN_14009c6a0.md) | 207 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140100fc0](decompiled/game-funcs/140100fc0_FUN_140100fc0.md) | 207 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401979c0](decompiled/game-funcs/1401979c0_FUN_1401979c0.md) | 207 | `batch_call_179690` | Calls FUN_140179690 4 times in a loop | pattern | repeated_op |
| [0x1402e6770](decompiled/game-funcs/1402e6770_FUN_1402e6770.md) | 207 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400874e0](decompiled/game-funcs/1400874e0_FUN_1400874e0.md) | 205 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140104b20](decompiled/game-funcs/140104b20_FUN_140104b20.md) | 205 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401637d0](decompiled/game-funcs/1401637d0_FUN_1401637d0.md) | 205 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402e9cd4](decompiled/game-funcs/1402e9cd4_FUN_1402e9cd4.md) | 205 | `batch_call_2f4f90` | Calls FUN_1402f4f90 4 times in a loop | pattern | repeated_op |
| [0x1401c9e50](decompiled/game-funcs/1401c9e50_FUN_1401c9e50.md) | 204 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14009f350](decompiled/game-funcs/14009f350_FUN_14009f350.md) | 203 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14012f790](decompiled/game-funcs/14012f790_FUN_14012f790.md) | 203 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402eebd8](decompiled/game-funcs/1402eebd8_FUN_1402eebd8.md) | 203 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14008d2d0](decompiled/game-funcs/14008d2d0_FUN_14008d2d0.md) | 202 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400a9290](decompiled/game-funcs/1400a9290_FUN_1400a9290.md) | 201 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x14012ef60](decompiled/game-funcs/14012ef60_FUN_14012ef60.md) | 200 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140075320](decompiled/game-funcs/140075320_FUN_140075320.md) | 199 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400bf630](decompiled/game-funcs/1400bf630_FUN_1400bf630.md) | 199 | `destructor_like` | Calls delete/free helpers; likely a destructor | pattern | destructor_like |
| [0x1400c7720](decompiled/game-funcs/1400c7720_FUN_1400c7720.md) | 199 | `destructor_like` | Calls delete/free helpers; likely a destructor | pattern | destructor_like |
| [0x140163700](decompiled/game-funcs/140163700_FUN_140163700.md) | 199 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401ab560](decompiled/game-funcs/1401ab560_FUN_1401ab560.md) | 199 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140010240](decompiled/game-funcs/140010240_FUN_140010240.md) | 198 | `struct_handler` | Reads/writes many fields on a struct (11 field accesses on param_1) | pattern | struct_handler |
| [0x140042de0](decompiled/game-funcs/140042de0_FUN_140042de0.md) | 198 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401b54e0](decompiled/game-funcs/1401b54e0_FUN_1401b54e0.md) | 197 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140016810](decompiled/game-funcs/140016810_FUN_140016810.md) | 196 | `struct_handler` | Reads/writes many fields on a struct (13 field accesses on param_1) | pattern | struct_handler |
| [0x1400bf700](decompiled/game-funcs/1400bf700_FUN_1400bf700.md) | 195 | `destructor_like` | Calls delete/free helpers; likely a destructor | pattern | destructor_like |
| [0x1402da530](decompiled/game-funcs/1402da530_FUN_1402da530.md) | 195 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140037420](decompiled/game-funcs/140037420_FUN_140037420.md) | 193 | `destructor_like` | Calls delete/free helpers; likely a destructor | pattern | destructor_like |
| [0x1402e9b78](decompiled/game-funcs/1402e9b78_FUN_1402e9b78.md) | 193 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c9f10](decompiled/game-funcs/1400c9f10_FUN_1400c9f10.md) | 189 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c6d00](decompiled/game-funcs/1400c6d00_FUN_1400c6d00.md) | 188 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14012e790](decompiled/game-funcs/14012e790_FUN_14012e790.md) | 188 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401cbb30](decompiled/game-funcs/1401cbb30_FUN_1401cbb30.md) | 188 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14004f150](decompiled/game-funcs/14004f150_FUN_14004f150.md) | 187 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402f4ed4](decompiled/game-funcs/1402f4ed4_FUN_1402f4ed4.md) | 186 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401885b0](decompiled/game-funcs/1401885b0_FUN_1401885b0.md) | 185 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400128b0](decompiled/game-funcs/1400128b0_FUN_1400128b0.md) | 184 | `struct_handler` | Reads/writes many fields on a struct (14 field accesses on param_1) | pattern | struct_handler |
| [0x140027750](decompiled/game-funcs/140027750_FUN_140027750.md) | 184 | `destructor_like` | Calls delete/free helpers; likely a destructor | pattern | destructor_like |
| [0x1402d0290](decompiled/game-funcs/1402d0290_FUN_1402d0290.md) | 183 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400cca50](decompiled/game-funcs/1400cca50_FUN_1400cca50.md) | 182 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402cd39c](decompiled/game-funcs/1402cd39c_FUN_1402cd39c.md) | 182 | `destructor_like` | Calls delete/free helpers; likely a destructor | pattern | destructor_like |
| [0x1402d7230](decompiled/game-funcs/1402d7230_FUN_1402d7230.md) | 182 | `struct_handler` | Reads/writes many fields on a struct (11 field accesses on param_1) | pattern | struct_handler |
| [0x1401c9630](decompiled/game-funcs/1401c9630_FUN_1401c9630.md) | 181 | `batch_call_1841e0` | Calls FUN_1401841e0 10 times in a loop | pattern | repeated_op |
| [0x1402e0598](decompiled/game-funcs/1402e0598_FUN_1402e0598.md) | 181 | `struct_handler` | Reads/writes many fields on a struct (12 field accesses on param_1) | pattern | struct_handler |
| [0x1402e8544](decompiled/game-funcs/1402e8544_FUN_1402e8544.md) | 181 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400a3200](decompiled/game-funcs/1400a3200_FUN_1400a3200.md) | 179 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401aaee0](decompiled/game-funcs/1401aaee0_FUN_1401aaee0.md) | 179 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402d8ca8](decompiled/game-funcs/1402d8ca8_FUN_1402d8ca8.md) | 179 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400124f0](decompiled/game-funcs/1400124f0_FUN_1400124f0.md) | 177 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402d8a8c](decompiled/game-funcs/1402d8a8c_FUN_1402d8a8c.md) | 177 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402ece80](decompiled/game-funcs/1402ece80_FUN_1402ece80.md) | 177 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c9fe0](decompiled/game-funcs/1400c9fe0_FUN_1400c9fe0.md) | 176 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402d3908](decompiled/game-funcs/1402d3908_FUN_1402d3908.md) | 176 | `struct_handler` | Reads/writes many fields on a struct (13 field accesses on param_1) | pattern | struct_handler |
| [0x140005960](decompiled/game-funcs/140005960_FUN_140005960.md) | 175 | `struct_handler` | Reads/writes many fields on a struct (12 field accesses on param_1) | pattern | struct_handler |
| [0x1402eaf4c](decompiled/game-funcs/1402eaf4c_FUN_1402eaf4c.md) | 175 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140067270](decompiled/game-funcs/140067270_FUN_140067270.md) | 174 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400b8720](decompiled/game-funcs/1400b8720_FUN_1400b8720.md) | 174 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400d8d00](decompiled/game-funcs/1400d8d00_FUN_1400d8d00.md) | 174 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402e93d0](decompiled/game-funcs/1402e93d0_FUN_1402e93d0.md) | 174 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14004f0a0](decompiled/game-funcs/14004f0a0_FUN_14004f0a0.md) | 173 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140142b00](decompiled/game-funcs/140142b00_FUN_140142b00.md) | 173 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401753d0](decompiled/game-funcs/1401753d0_FUN_1401753d0.md) | 173 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401aaff0](decompiled/game-funcs/1401aaff0_FUN_1401aaff0.md) | 171 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140012800](decompiled/game-funcs/140012800_FUN_140012800.md) | 170 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402d3580](decompiled/game-funcs/1402d3580_FUN_1402d3580.md) | 170 | `struct_handler` | Reads/writes many fields on a struct (13 field accesses on param_1) | pattern | struct_handler |
| [0x1400471e0](decompiled/game-funcs/1400471e0_FUN_1400471e0.md) | 169 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400b2e30](decompiled/game-funcs/1400b2e30_FUN_1400b2e30.md) | 169 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14009bcc0](decompiled/game-funcs/14009bcc0_FUN_14009bcc0.md) | 168 | `destructor_like` | Calls delete/free helpers; likely a destructor | pattern | destructor_like |
| [0x1400a8680](decompiled/game-funcs/1400a8680_FUN_1400a8680.md) | 168 | `struct_handler` | Reads/writes many fields on a struct (8 field accesses on param_1) | pattern | struct_handler |
| [0x1402d1ca8](decompiled/game-funcs/1402d1ca8_FUN_1402d1ca8.md) | 168 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400b85b0](decompiled/game-funcs/1400b85b0_FUN_1400b85b0.md) | 167 | `struct_handler` | Reads/writes many fields on a struct (11 field accesses on param_1) | pattern | struct_handler |
| [0x1402c8240](decompiled/game-funcs/1402c8240_FUN_1402c8240.md) | 167 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140081600](decompiled/game-funcs/140081600_FUN_140081600.md) | 166 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14000cee0](decompiled/game-funcs/14000cee0_FUN_14000cee0.md) | 165 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14006ffa0](decompiled/game-funcs/14006ffa0_FUN_14006ffa0.md) | 165 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400bf070](decompiled/game-funcs/1400bf070_FUN_1400bf070.md) | 165 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 4 fields) | pattern | struct_init |
| [0x1402ce1e0](decompiled/game-funcs/1402ce1e0_FUN_1402ce1e0.md) | 165 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14005e310](decompiled/game-funcs/14005e310_FUN_14005e310.md) | 164 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400ca150](decompiled/game-funcs/1400ca150_FUN_1400ca150.md) | 164 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140074460](decompiled/game-funcs/140074460_FUN_140074460.md) | 163 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400ce9b0](decompiled/game-funcs/1400ce9b0_FUN_1400ce9b0.md) | 163 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140100d80](decompiled/game-funcs/140100d80_FUN_140100d80.md) | 163 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402f0358](decompiled/game-funcs/1402f0358_FUN_1402f0358.md) | 163 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140012970](decompiled/game-funcs/140012970_FUN_140012970.md) | 162 | `struct_handler` | Reads/writes many fields on a struct (8 field accesses on param_1) | pattern | struct_handler |
| [0x1401ab7a0](decompiled/game-funcs/1401ab7a0_FUN_1401ab7a0.md) | 162 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402ed0c0](decompiled/game-funcs/1402ed0c0_FUN_1402ed0c0.md) | 162 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402f7f1c](decompiled/game-funcs/1402f7f1c_FUN_1402f7f1c.md) | 162 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140024b40](decompiled/game-funcs/140024b40_FUN_140024b40.md) | 161 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 3 fields) | pattern | struct_init |
| [0x140025e00](decompiled/game-funcs/140025e00_FUN_140025e00.md) | 160 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14004cee0](decompiled/game-funcs/14004cee0_FUN_14004cee0.md) | 160 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14008d150](decompiled/game-funcs/14008d150_FUN_14008d150.md) | 160 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400aabb0](decompiled/game-funcs/1400aabb0_FUN_1400aabb0.md) | 159 | `struct_handler` | Reads/writes many fields on a struct (11 field accesses on param_1) | pattern | struct_handler |
| [0x1402e08a8](decompiled/game-funcs/1402e08a8_FUN_1402e08a8.md) | 159 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 7 fields) | pattern | struct_init |
| [0x140005e10](decompiled/game-funcs/140005e10_FUN_140005e10.md) | 158 | `struct_handler` | Reads/writes many fields on a struct (8 field accesses on param_1) | pattern | struct_handler |
| [0x14008d0a0](decompiled/game-funcs/14008d0a0_FUN_14008d0a0.md) | 158 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c8dc0](decompiled/game-funcs/1400c8dc0_FUN_1400c8dc0.md) | 157 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140010c10](decompiled/game-funcs/140010c10_FUN_140010c10.md) | 156 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140067e60](decompiled/game-funcs/140067e60_FUN_140067e60.md) | 155 | `trigger_event` | Triggers the 'event' sound or event | pattern | plays_sound_or_event |
| [0x140087ec0](decompiled/game-funcs/140087ec0_FUN_140087ec0.md) | 155 | `destructor_like` | Calls delete/free helpers; likely a destructor | pattern | destructor_like |
| [0x1400befd0](decompiled/game-funcs/1400befd0_FUN_1400befd0.md) | 155 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 17 fields) | pattern | struct_init |
| [0x1400bf150](decompiled/game-funcs/1400bf150_FUN_1400bf150.md) | 155 | `destructor_like` | Calls delete/free helpers; likely a destructor | pattern | destructor_like |
| [0x1400c5580](decompiled/game-funcs/1400c5580_FUN_1400c5580.md) | 155 | `destructor_like` | Calls delete/free helpers; likely a destructor | pattern | destructor_like |
| [0x1402cd300](decompiled/game-funcs/1402cd300_FUN_1402cd300.md) | 155 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402cdfa0](decompiled/game-funcs/1402cdfa0_FUN_1402cdfa0.md) | 155 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402ce7c8](decompiled/game-funcs/1402ce7c8_FUN_1402ce7c8.md) | 155 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402cea4c](decompiled/game-funcs/1402cea4c_FUN_1402cea4c.md) | 155 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402eb0c8](decompiled/game-funcs/1402eb0c8_FUN_1402eb0c8.md) | 154 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402eb16c](decompiled/game-funcs/1402eb16c_FUN_1402eb16c.md) | 154 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140037380](decompiled/game-funcs/140037380_FUN_140037380.md) | 153 | `destructor_like` | Calls delete/free helpers; likely a destructor | pattern | destructor_like |
| [0x1400642e0](decompiled/game-funcs/1400642e0_FUN_1400642e0.md) | 153 | `destructor_like` | Calls delete/free helpers; likely a destructor | pattern | destructor_like |
| [0x140174d30](decompiled/game-funcs/140174d30_FUN_140174d30.md) | 153 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402d72e8](decompiled/game-funcs/1402d72e8_FUN_1402d72e8.md) | 153 | `struct_handler` | Reads/writes many fields on a struct (12 field accesses on param_1) | pattern | struct_handler |
| [0x1402ed000](decompiled/game-funcs/1402ed000_FUN_1402ed000.md) | 153 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402ce288](decompiled/game-funcs/1402ce288_FUN_1402ce288.md) | 152 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402cf00c](decompiled/game-funcs/1402cf00c_FUN_1402cf00c.md) | 152 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400a58b0](decompiled/game-funcs/1400a58b0_FUN_1400a58b0.md) | 151 | `destructor_like` | Calls delete/free helpers; likely a destructor | pattern | destructor_like |
| [0x1400766f0](decompiled/game-funcs/1400766f0_FUN_1400766f0.md) | 149 | `destructor_like` | Calls delete/free helpers; likely a destructor | pattern | destructor_like |
| [0x140008300](decompiled/game-funcs/140008300_FUN_140008300.md) | 148 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140101220](decompiled/game-funcs/140101220_FUN_140101220.md) | 148 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140174dd0](decompiled/game-funcs/140174dd0_FUN_140174dd0.md) | 148 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401c5df0](decompiled/game-funcs/1401c5df0_FUN_1401c5df0.md) | 148 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401c42c0](decompiled/game-funcs/1401c42c0_FUN_1401c42c0.md) | 146 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140025730](decompiled/game-funcs/140025730_FUN_140025730.md) | 145 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14009bb10](decompiled/game-funcs/14009bb10_FUN_14009bb10.md) | 145 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140175500](decompiled/game-funcs/140175500_FUN_140175500.md) | 145 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14012df60](decompiled/game-funcs/14012df60_FUN_14012df60.md) | 144 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401ab340](decompiled/game-funcs/1401ab340_FUN_1401ab340.md) | 144 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402e86c4](decompiled/game-funcs/1402e86c4_FUN_1402e86c4.md) | 144 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402f3150](decompiled/game-funcs/1402f3150_FUN_1402f3150.md) | 144 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14004f010](decompiled/game-funcs/14004f010_FUN_14004f010.md) | 143 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400273e0](decompiled/game-funcs/1400273e0_FUN_1400273e0.md) | 141 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14009f5e0](decompiled/game-funcs/14009f5e0_FUN_14009f5e0.md) | 141 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402ceae8](decompiled/game-funcs/1402ceae8_FUN_1402ceae8.md) | 141 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402d3e44](decompiled/game-funcs/1402d3e44_FUN_1402d3e44.md) | 141 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402e1948](decompiled/game-funcs/1402e1948_FUN_1402e1948.md) | 140 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402e9320](decompiled/game-funcs/1402e9320_FUN_1402e9320.md) | 140 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402e9480](decompiled/game-funcs/1402e9480_FUN_1402e9480.md) | 140 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140040ee0](decompiled/game-funcs/140040ee0_FUN_140040ee0.md) | 139 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400d8c70](decompiled/game-funcs/1400d8c70_FUN_1400d8c70.md) | 139 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14008d200](decompiled/game-funcs/14008d200_FUN_14008d200.md) | 138 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c5c80](decompiled/game-funcs/1400c5c80_FUN_1400c5c80.md) | 138 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402d19ec](decompiled/game-funcs/1402d19ec_FUN_1402d19ec.md) | 138 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14004c9d0](decompiled/game-funcs/14004c9d0_FUN_14004c9d0.md) | 137 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 4 fields) | pattern | struct_init |
| [0x1402eeb50](decompiled/game-funcs/1402eeb50_FUN_1402eeb50.md) | 136 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402d0350](decompiled/game-funcs/1402d0350_FUN_1402d0350.md) | 135 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x14008d760](decompiled/game-funcs/14008d760_FUN_14008d760.md) | 134 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402c8190](decompiled/game-funcs/1402c8190_FUN_1402c8190.md) | 134 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140015560](decompiled/game-funcs/140015560_FUN_140015560.md) | 133 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402e0510](decompiled/game-funcs/1402e0510_FUN_1402e0510.md) | 133 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402d36ec](decompiled/game-funcs/1402d36ec_FUN_1402d36ec.md) | 132 | `struct_handler` | Reads/writes many fields on a struct (13 field accesses on param_1) | pattern | struct_handler |
| [0x1402d3a7c](decompiled/game-funcs/1402d3a7c_FUN_1402d3a7c.md) | 132 | `struct_handler` | Reads/writes many fields on a struct (13 field accesses on param_1) | pattern | struct_handler |
| [0x1400cead0](decompiled/game-funcs/1400cead0_FUN_1400cead0.md) | 131 | `helper_with_6_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140142630](decompiled/game-funcs/140142630_FUN_140142630.md) | 131 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14004cab0](decompiled/game-funcs/14004cab0_FUN_14004cab0.md) | 130 | `struct_handler` | Reads/writes many fields on a struct (11 field accesses on param_1) | pattern | struct_handler |
| [0x1400f9b40](decompiled/game-funcs/1400f9b40_FUN_1400f9b40.md) | 129 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140027810](decompiled/game-funcs/140027810_FUN_140027810.md) | 128 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140072f50](decompiled/game-funcs/140072f50_FUN_140072f50.md) | 126 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400d7110](decompiled/game-funcs/1400d7110_FUN_1400d7110.md) | 126 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140142960](decompiled/game-funcs/140142960_FUN_140142960.md) | 126 | `helper_with_7_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402e8180](decompiled/game-funcs/1402e8180_FUN_1402e8180.md) | 126 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c6e80](decompiled/game-funcs/1400c6e80_FUN_1400c6e80.md) | 125 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c8570](decompiled/game-funcs/1400c8570_FUN_1400c8570.md) | 125 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401792e0](decompiled/game-funcs/1401792e0_FUN_1401792e0.md) | 125 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400125b0](decompiled/game-funcs/1400125b0_FUN_1400125b0.md) | 124 | `struct_handler` | Reads/writes many fields on a struct (10 field accesses on param_1) | pattern | struct_handler |
| [0x140072e40](decompiled/game-funcs/140072e40_FUN_140072e40.md) | 124 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402d6ad0](decompiled/game-funcs/1402d6ad0_FUN_1402d6ad0.md) | 124 | `struct_handler` | Reads/writes many fields on a struct (10 field accesses on param_1) | pattern | struct_handler |
| [0x14004ef90](decompiled/game-funcs/14004ef90_FUN_14004ef90.md) | 123 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402c7138](decompiled/game-funcs/1402c7138_FUN_1402c7138.md) | 123 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400058e0](decompiled/game-funcs/1400058e0_FUN_1400058e0.md) | 122 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402ce164](decompiled/game-funcs/1402ce164_FUN_1402ce164.md) | 122 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400727d0](decompiled/game-funcs/1400727d0_FUN_1400727d0.md) | 120 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400cc9d0](decompiled/game-funcs/1400cc9d0_FUN_1400cc9d0.md) | 120 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401638b0](decompiled/game-funcs/1401638b0_FUN_1401638b0.md) | 120 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14004ce60](decompiled/game-funcs/14004ce60_FUN_14004ce60.md) | 119 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402e9b00](decompiled/game-funcs/1402e9b00_FUN_1402e9b00.md) | 119 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402ecd60](decompiled/game-funcs/1402ecd60_FUN_1402ecd60.md) | 119 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402d74e0](decompiled/game-funcs/1402d74e0_FUN_1402d74e0.md) | 118 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402d8964](decompiled/game-funcs/1402d8964_FUN_1402d8964.md) | 118 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140080b00](decompiled/game-funcs/140080b00_FUN_140080b00.md) | 117 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401cba40](decompiled/game-funcs/1401cba40_FUN_1401cba40.md) | 117 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402f4f90](decompiled/game-funcs/1402f4f90_FUN_1402f4f90.md) | 117 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400249e0](decompiled/game-funcs/1400249e0_FUN_1400249e0.md) | 116 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401cbbf0](decompiled/game-funcs/1401cbbf0_FUN_1401cbbf0.md) | 116 | `trigger_event` | Triggers the 'event' sound or event | pattern | plays_sound_or_event |
| [0x14008de50](decompiled/game-funcs/14008de50_FUN_14008de50.md) | 115 | `trigger_event` | Triggers the 'event' sound or event | pattern | plays_sound_or_event |
| [0x1402f6960](decompiled/game-funcs/1402f6960_FUN_1402f6960.md) | 115 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14004c820](decompiled/game-funcs/14004c820_FUN_14004c820.md) | 114 | `struct_handler` | Reads/writes many fields on a struct (11 field accesses on param_1) | pattern | struct_handler |
| [0x14012f860](decompiled/game-funcs/14012f860_FUN_14012f860.md) | 114 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140072640](decompiled/game-funcs/140072640_FUN_140072640.md) | 113 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140027900](decompiled/game-funcs/140027900_FUN_140027900.md) | 112 | `destructor_like` | Calls delete/free helpers; likely a destructor | pattern | destructor_like |
| [0x140046de0](decompiled/game-funcs/140046de0_FUN_140046de0.md) | 112 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140105730](decompiled/game-funcs/140105730_FUN_140105730.md) | 112 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401ab4c0](decompiled/game-funcs/1401ab4c0_FUN_1401ab4c0.md) | 112 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400d8c00](decompiled/game-funcs/1400d8c00_FUN_1400d8c00.md) | 111 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401c95c0](decompiled/game-funcs/1401c95c0_FUN_1401c95c0.md) | 111 | `struct_handler` | Reads/writes many fields on a struct (8 field accesses on param_1) | pattern | struct_handler |
| [0x1402f8670](decompiled/game-funcs/1402f8670_FUN_1402f8670.md) | 111 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400743e0](decompiled/game-funcs/1400743e0_FUN_1400743e0.md) | 109 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400fb8c0](decompiled/game-funcs/1400fb8c0_FUN_1400fb8c0.md) | 109 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402d348c](decompiled/game-funcs/1402d348c_FUN_1402d348c.md) | 109 | `struct_handler` | Reads/writes many fields on a struct (13 field accesses on param_1) | pattern | struct_handler |
| [0x1402d3810](decompiled/game-funcs/1402d3810_FUN_1402d3810.md) | 109 | `struct_handler` | Reads/writes many fields on a struct (13 field accesses on param_1) | pattern | struct_handler |
| [0x14007b260](decompiled/game-funcs/14007b260_FUN_14007b260.md) | 108 | `struct_handler` | Reads/writes many fields on a struct (9 field accesses on param_1) | pattern | struct_handler |
| [0x1400c6940](decompiled/game-funcs/1400c6940_FUN_1400c6940.md) | 108 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140030810](decompiled/game-funcs/140030810_FUN_140030810.md) | 107 | `destructor_like` | Calls delete/free helpers; likely a destructor | pattern | destructor_like |
| [0x1400308d0](decompiled/game-funcs/1400308d0_FUN_1400308d0.md) | 107 | `destructor_like` | Calls delete/free helpers; likely a destructor | pattern | destructor_like |
| [0x1402cd0d0](decompiled/game-funcs/1402cd0d0_FUN_1402cd0d0.md) | 106 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402d3dd8](decompiled/game-funcs/1402d3dd8_FUN_1402d3dd8.md) | 106 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400285e0](decompiled/game-funcs/1400285e0_FUN_1400285e0.md) | 105 | `destructor_like` | Calls delete/free helpers; likely a destructor | pattern | destructor_like |
| [0x1400a8610](decompiled/game-funcs/1400a8610_FUN_1400a8610.md) | 104 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14003f740](decompiled/game-funcs/14003f740_FUN_14003f740.md) | 103 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140084300](decompiled/game-funcs/140084300_FUN_140084300.md) | 103 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c5680](decompiled/game-funcs/1400c5680_FUN_1400c5680.md) | 103 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140174970](decompiled/game-funcs/140174970_FUN_140174970.md) | 103 | `batch_call_1841e0` | Calls FUN_1401841e0 4 times in a loop | pattern | repeated_op |
| [0x1402cd068](decompiled/game-funcs/1402cd068_FUN_1402cd068.md) | 102 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14009b740](decompiled/game-funcs/14009b740_FUN_14009b740.md) | 101 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400b6820](decompiled/game-funcs/1400b6820_FUN_1400b6820.md) | 101 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401c9c60](decompiled/game-funcs/1401c9c60_FUN_1401c9c60.md) | 101 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401cbac0](decompiled/game-funcs/1401cbac0_FUN_1401cbac0.md) | 101 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140163c40](decompiled/game-funcs/140163c40_FUN_140163c40.md) | 100 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402da180](decompiled/game-funcs/1402da180_FUN_1402da180.md) | 100 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402f87d0](decompiled/game-funcs/1402f87d0_FUN_1402f87d0.md) | 100 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140080680](decompiled/game-funcs/140080680_FUN_140080680.md) | 99 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140081fa0](decompiled/game-funcs/140081fa0_FUN_140081fa0.md) | 99 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140087e30](decompiled/game-funcs/140087e30_FUN_140087e30.md) | 99 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400a8a00](decompiled/game-funcs/1400a8a00_FUN_1400a8a00.md) | 99 | `struct_handler` | Reads/writes many fields on a struct (15 field accesses on param_1) | pattern | struct_handler |
| [0x14012f1a0](decompiled/game-funcs/14012f1a0_FUN_14012f1a0.md) | 97 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402f8700](decompiled/game-funcs/1402f8700_FUN_1402f8700.md) | 97 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400250c0](decompiled/game-funcs/1400250c0_FUN_1400250c0.md) | 96 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 4 fields) | pattern | struct_init |
| [0x140050a70](decompiled/game-funcs/140050a70_FUN_140050a70.md) | 95 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402f6598](decompiled/game-funcs/1402f6598_FUN_1402f6598.md) | 95 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14003f680](decompiled/game-funcs/14003f680_FUN_14003f680.md) | 93 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14010dd70](decompiled/game-funcs/14010dd70_FUN_14010dd70.md) | 92 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402ec1dc](decompiled/game-funcs/1402ec1dc_FUN_1402ec1dc.md) | 92 | `trigger_event` | Triggers the 'event' sound or event | pattern | plays_sound_or_event |
| [0x1402e8754](decompiled/game-funcs/1402e8754_FUN_1402e8754.md) | 91 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402e8c20](decompiled/game-funcs/1402e8c20_FUN_1402e8c20.md) | 90 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14012dff0](decompiled/game-funcs/14012dff0_FUN_14012dff0.md) | 89 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401426c0](decompiled/game-funcs/1401426c0_FUN_1401426c0.md) | 89 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401cd800](decompiled/game-funcs/1401cd800_FUN_1401cd800.md) | 88 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400833d0](decompiled/game-funcs/1400833d0_FUN_1400833d0.md) | 87 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400256d0](decompiled/game-funcs/1400256d0_FUN_1400256d0.md) | 86 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14003e720](decompiled/game-funcs/14003e720_FUN_14003e720.md) | 86 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140175050](decompiled/game-funcs/140175050_FUN_140175050.md) | 86 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140023f30](decompiled/game-funcs/140023f30_FUN_140023f30.md) | 85 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14008cc20](decompiled/game-funcs/14008cc20_FUN_14008cc20.md) | 85 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401842c0](decompiled/game-funcs/1401842c0_FUN_1401842c0.md) | 85 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140188550](decompiled/game-funcs/140188550_FUN_140188550.md) | 85 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402cefac](decompiled/game-funcs/1402cefac_FUN_1402cefac.md) | 85 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402e1bf8](decompiled/game-funcs/1402e1bf8_FUN_1402e1bf8.md) | 85 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402f67d0](decompiled/game-funcs/1402f67d0_FUN_1402f67d0.md) | 85 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140024a60](decompiled/game-funcs/140024a60_FUN_140024a60.md) | 84 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400257d0](decompiled/game-funcs/1400257d0_FUN_1400257d0.md) | 84 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14009c330](decompiled/game-funcs/14009c330_FUN_14009c330.md) | 84 | `destructor_like` | Calls delete/free helpers; likely a destructor | pattern | destructor_like |
| [0x140104ac0](decompiled/game-funcs/140104ac0_FUN_140104ac0.md) | 84 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140104f00](decompiled/game-funcs/140104f00_FUN_140104f00.md) | 84 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14000b3a0](decompiled/game-funcs/14000b3a0_FUN_14000b3a0.md) | 83 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400b49b0](decompiled/game-funcs/1400b49b0_FUN_1400b49b0.md) | 83 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402dfea0](decompiled/game-funcs/1402dfea0_FUN_1402dfea0.md) | 83 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14009bab0](decompiled/game-funcs/14009bab0_FUN_14009bab0.md) | 82 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c4340](decompiled/game-funcs/1400c4340_FUN_1400c4340.md) | 82 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400745d0](decompiled/game-funcs/1400745d0_FUN_1400745d0.md) | 81 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401747e0](decompiled/game-funcs/1401747e0_FUN_1401747e0.md) | 81 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402ed930](decompiled/game-funcs/1402ed930_FUN_1402ed930.md) | 81 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402f8770](decompiled/game-funcs/1402f8770_FUN_1402f8770.md) | 81 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140028310](decompiled/game-funcs/140028310_FUN_140028310.md) | 80 | `destructor_like` | Calls delete/free helpers; likely a destructor | pattern | destructor_like |
| [0x1401cade0](decompiled/game-funcs/1401cade0_FUN_1401cade0.md) | 80 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14005bf10](decompiled/game-funcs/14005bf10_FUN_14005bf10.md) | 79 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140067850](decompiled/game-funcs/140067850_FUN_140067850.md) | 79 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401123f0](decompiled/game-funcs/1401123f0_FUN_1401123f0.md) | 79 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14003f7b0](decompiled/game-funcs/14003f7b0_FUN_14003f7b0.md) | 78 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c5740](decompiled/game-funcs/1400c5740_FUN_1400c5740.md) | 76 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14012f0d0](decompiled/game-funcs/14012f0d0_FUN_14012f0d0.md) | 76 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402cd13c](decompiled/game-funcs/1402cd13c_FUN_1402cd13c.md) | 76 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140040980](decompiled/game-funcs/140040980_FUN_140040980.md) | 74 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c56f0](decompiled/game-funcs/1400c56f0_FUN_1400c56f0.md) | 74 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402ed9d0](decompiled/game-funcs/1402ed9d0_FUN_1402ed9d0.md) | 74 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c6180](decompiled/game-funcs/1400c6180_FUN_1400c6180.md) | 73 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400fb380](decompiled/game-funcs/1400fb380_FUN_1400fb380.md) | 73 | `helper_with_5_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402eed70](decompiled/game-funcs/1402eed70_FUN_1402eed70.md) | 73 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14004ca60](decompiled/game-funcs/14004ca60_FUN_14004ca60.md) | 72 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400d8db0](decompiled/game-funcs/1400d8db0_FUN_1400d8db0.md) | 72 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140009e10](decompiled/game-funcs/140009e10_FUN_140009e10.md) | 71 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14000b2a0](decompiled/game-funcs/14000b2a0_FUN_14000b2a0.md) | 71 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402c5b14](decompiled/game-funcs/1402c5b14_FUN_1402c5b14.md) | 71 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402c5bd4](decompiled/game-funcs/1402c5bd4_FUN_1402c5bd4.md) | 71 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402f03fc](decompiled/game-funcs/1402f03fc_FUN_1402f03fc.md) | 71 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402c6c88](decompiled/game-funcs/1402c6c88_FUN_1402c6c88.md) | 70 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400162f0](decompiled/game-funcs/1400162f0_FUN_1400162f0.md) | 69 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400509e0](decompiled/game-funcs/1400509e0_FUN_1400509e0.md) | 67 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140009e60](decompiled/game-funcs/140009e60_FUN_140009e60.md) | 66 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140009eb0](decompiled/game-funcs/140009eb0_FUN_140009eb0.md) | 66 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14000b2f0](decompiled/game-funcs/14000b2f0_FUN_14000b2f0.md) | 66 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14000b340](decompiled/game-funcs/14000b340_FUN_14000b340.md) | 66 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140080ab0](decompiled/game-funcs/140080ab0_FUN_140080ab0.md) | 65 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c65c0](decompiled/game-funcs/1400c65c0_FUN_1400c65c0.md) | 65 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402175d0](decompiled/game-funcs/1402175d0_FUN_1402175d0.md) | 64 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402f6a7c](decompiled/game-funcs/1402f6a7c_FUN_1402f6a7c.md) | 64 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400410f0](decompiled/game-funcs/1400410f0_FUN_1400410f0.md) | 63 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401010d0](decompiled/game-funcs/1401010d0_FUN_1401010d0.md) | 63 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140025320](decompiled/game-funcs/140025320_FUN_140025320.md) | 62 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140025450](decompiled/game-funcs/140025450_FUN_140025450.md) | 62 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14012e730](decompiled/game-funcs/14012e730_FUN_14012e730.md) | 61 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401840e0](decompiled/game-funcs/1401840e0_FUN_1401840e0.md) | 61 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402ed8c0](decompiled/game-funcs/1402ed8c0_FUN_1402ed8c0.md) | 61 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140084570](decompiled/game-funcs/140084570_FUN_140084570.md) | 60 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401755c0](decompiled/game-funcs/1401755c0_FUN_1401755c0.md) | 60 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402e9a80](decompiled/game-funcs/1402e9a80_FUN_1402e9a80.md) | 60 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400730f0](decompiled/game-funcs/1400730f0_FUN_1400730f0.md) | 59 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c8d30](decompiled/game-funcs/1400c8d30_FUN_1400c8d30.md) | 59 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401aaea0](decompiled/game-funcs/1401aaea0_FUN_1401aaea0.md) | 59 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401c9760](decompiled/game-funcs/1401c9760_FUN_1401c9760.md) | 59 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402c704c](decompiled/game-funcs/1402c704c_FUN_1402c704c.md) | 59 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140050a30](decompiled/game-funcs/140050a30_FUN_140050a30.md) | 57 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400b7660](decompiled/game-funcs/1400b7660_FUN_1400b7660.md) | 57 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401429e0](decompiled/game-funcs/1401429e0_FUN_1401429e0.md) | 57 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140040fe0](decompiled/game-funcs/140040fe0_FUN_140040fe0.md) | 56 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c6580](decompiled/game-funcs/1400c6580_FUN_1400c6580.md) | 56 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402f0160](decompiled/game-funcs/1402f0160_FUN_1402f0160.md) | 56 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140027980](decompiled/game-funcs/140027980_FUN_140027980.md) | 55 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c7520](decompiled/game-funcs/1400c7520_FUN_1400c7520.md) | 55 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402e6fb0](decompiled/game-funcs/1402e6fb0_FUN_1402e6fb0.md) | 55 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402ed990](decompiled/game-funcs/1402ed990_FUN_1402ed990.md) | 55 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14012dec0](decompiled/game-funcs/14012dec0_FUN_14012dec0.md) | 54 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401aafa0](decompiled/game-funcs/1401aafa0_FUN_1401aafa0.md) | 54 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14000cdc0](decompiled/game-funcs/14000cdc0_FUN_14000cdc0.md) | 53 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140040ea0](decompiled/game-funcs/140040ea0_FUN_140040ea0.md) | 53 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402d8374](decompiled/game-funcs/1402d8374_FUN_1402d8374.md) | 53 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402eeef8](decompiled/game-funcs/1402eeef8_FUN_1402eeef8.md) | 53 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402eef64](decompiled/game-funcs/1402eef64_FUN_1402eef64.md) | 53 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14004a210](decompiled/game-funcs/14004a210_FUN_14004a210.md) | 52 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14009be60](decompiled/game-funcs/14009be60_FUN_14009be60.md) | 52 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140082060](decompiled/game-funcs/140082060_FUN_140082060.md) | 51 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401841a0](decompiled/game-funcs/1401841a0_FUN_1401841a0.md) | 51 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401ab760](decompiled/game-funcs/1401ab760_FUN_1401ab760.md) | 51 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402e6f60](decompiled/game-funcs/1402e6f60_FUN_1402e6f60.md) | 51 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402ebdf0](decompiled/game-funcs/1402ebdf0_FUN_1402ebdf0.md) | 51 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140025dc0](decompiled/game-funcs/140025dc0_FUN_140025dc0.md) | 50 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14003ed30](decompiled/game-funcs/14003ed30_FUN_14003ed30.md) | 50 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400679e0](decompiled/game-funcs/1400679e0_FUN_1400679e0.md) | 50 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140113380](decompiled/game-funcs/140113380_FUN_140113380.md) | 50 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401ca4b0](decompiled/game-funcs/1401ca4b0_FUN_1401ca4b0.md) | 50 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400a5370](decompiled/game-funcs/1400a5370_FUN_1400a5370.md) | 49 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401841f0](decompiled/game-funcs/1401841f0_FUN_1401841f0.md) | 49 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140184230](decompiled/game-funcs/140184230_FUN_140184230.md) | 49 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402e1c60](decompiled/game-funcs/1402e1c60_FUN_1402e1c60.md) | 48 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140080b80](decompiled/game-funcs/140080b80_FUN_140080b80.md) | 47 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400a8e00](decompiled/game-funcs/1400a8e00_FUN_1400a8e00.md) | 47 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401ab530](decompiled/game-funcs/1401ab530_FUN_1401ab530.md) | 47 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402e7d80](decompiled/game-funcs/1402e7d80_FUN_1402e7d80.md) | 47 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402ec97c](decompiled/game-funcs/1402ec97c_FUN_1402ec97c.md) | 47 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402ed900](decompiled/game-funcs/1402ed900_FUN_1402ed900.md) | 47 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14009f5a0](decompiled/game-funcs/14009f5a0_FUN_14009f5a0.md) | 46 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400a8750](decompiled/game-funcs/1400a8750_FUN_1400a8750.md) | 45 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140174920](decompiled/game-funcs/140174920_FUN_140174920.md) | 44 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401c9730](decompiled/game-funcs/1401c9730_FUN_1401c9730.md) | 44 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402da150](decompiled/game-funcs/1402da150_FUN_1402da150.md) | 44 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140066180](decompiled/game-funcs/140066180_FUN_140066180.md) | 43 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14012e0b0](decompiled/game-funcs/14012e0b0_FUN_14012e0b0.md) | 42 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14012e0e0](decompiled/game-funcs/14012e0e0_FUN_14012e0e0.md) | 42 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14012e2e0](decompiled/game-funcs/14012e2e0_FUN_14012e2e0.md) | 42 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402eba80](decompiled/game-funcs/1402eba80_FUN_1402eba80.md) | 42 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402ebdc0](decompiled/game-funcs/1402ebdc0_FUN_1402ebdc0.md) | 42 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402f8d60](decompiled/game-funcs/1402f8d60_FUN_1402f8d60.md) | 42 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400fb9c0](decompiled/game-funcs/1400fb9c0_FUN_1400fb9c0.md) | 41 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c8d90](decompiled/game-funcs/1400c8d90_FUN_1400c8d90.md) | 40 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14012e850](decompiled/game-funcs/14012e850_FUN_14012e850.md) | 39 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400ca0f0](decompiled/game-funcs/1400ca0f0_FUN_1400ca0f0.md) | 38 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140040950](decompiled/game-funcs/140040950_FUN_140040950.md) | 37 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402e6840](decompiled/game-funcs/1402e6840_FUN_1402e6840.md) | 37 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400845c0](decompiled/game-funcs/1400845c0_FUN_1400845c0.md) | 36 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140179430](decompiled/game-funcs/140179430_FUN_140179430.md) | 35 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402e688c](decompiled/game-funcs/1402e688c_FUN_1402e688c.md) | 35 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402e68b0](decompiled/game-funcs/1402e68b0_FUN_1402e68b0.md) | 35 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400844c0](decompiled/game-funcs/1400844c0_FUN_1400844c0.md) | 34 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c6520](decompiled/game-funcs/1400c6520_FUN_1400c6520.md) | 34 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14012ee40](decompiled/game-funcs/14012ee40_FUN_14012ee40.md) | 34 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140217520](decompiled/game-funcs/140217520_FUN_140217520.md) | 34 | `helper_with_4_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402c5c3c](decompiled/game-funcs/1402c5c3c_FUN_1402c5c3c.md) | 34 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402c5c60](decompiled/game-funcs/1402c5c60_FUN_1402c5c60.md) | 34 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402e6868](decompiled/game-funcs/1402e6868_FUN_1402e6868.md) | 34 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140024060](decompiled/game-funcs/140024060_FUN_140024060.md) | 33 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402c5a60](decompiled/game-funcs/1402c5a60_FUN_1402c5a60.md) | 33 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14009dd90](decompiled/game-funcs/14009dd90_FUN_14009dd90.md) | 32 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c6df0](decompiled/game-funcs/1400c6df0_FUN_1400c6df0.md) | 32 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1402e7d50](decompiled/game-funcs/1402e7d50_FUN_1402e7d50.md) | 32 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1402ecfa0](decompiled/game-funcs/1402ecfa0_FUN_1402ecfa0.md) | 32 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402ed0a0](decompiled/game-funcs/1402ed0a0_FUN_1402ed0a0.md) | 32 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402f86e0](decompiled/game-funcs/1402f86e0_FUN_1402f86e0.md) | 32 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x140024090](decompiled/game-funcs/140024090_FUN_140024090.md) | 31 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400278e0](decompiled/game-funcs/1400278e0_FUN_1400278e0.md) | 31 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140082010](decompiled/game-funcs/140082010_FUN_140082010.md) | 31 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402c5c1c](decompiled/game-funcs/1402c5c1c_FUN_1402c5c1c.md) | 31 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402c7c00](decompiled/game-funcs/1402c7c00_FUN_1402c7c00.md) | 31 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14008d290](decompiled/game-funcs/14008d290_FUN_14008d290.md) | 30 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14012fd40](decompiled/game-funcs/14012fd40_FUN_14012fd40.md) | 30 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x140179690](decompiled/game-funcs/140179690_FUN_140179690.md) | 30 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1401a9ed0](decompiled/game-funcs/1401a9ed0_FUN_1401a9ed0.md) | 30 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402cd454](decompiled/game-funcs/1402cd454_FUN_1402cd454.md) | 30 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14012e770](decompiled/game-funcs/14012e770_FUN_14012e770.md) | 29 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x14012ef10](decompiled/game-funcs/14012ef10_FUN_14012ef10.md) | 29 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140197710](decompiled/game-funcs/140197710_FUN_140197710.md) | 29 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1402e8c00](decompiled/game-funcs/1402e8c00_FUN_1402e8c00.md) | 29 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1402e8cc0](decompiled/game-funcs/1402e8cc0_FUN_1402e8cc0.md) | 29 | `wrap_2e8cc0` | Wrapper that delegates to FUN_1402e8cc0 | pattern | wrapper |
| [0x1400a3610](decompiled/game-funcs/1400a3610_FUN_1400a3610.md) | 28 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1400c6120](decompiled/game-funcs/1400c6120_FUN_1400c6120.md) | 28 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1400cf970](decompiled/game-funcs/1400cf970_FUN_1400cf970.md) | 28 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1400cf9a0](decompiled/game-funcs/1400cf9a0_FUN_1400cf9a0.md) | 28 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x140104dc0](decompiled/game-funcs/140104dc0_FUN_140104dc0.md) | 28 | `wrap_104dc0` | Wrapper that delegates to FUN_140104dc0 | pattern | wrapper |
| [0x140106b90](decompiled/game-funcs/140106b90_FUN_140106b90.md) | 28 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1402f4460](decompiled/game-funcs/1402f4460_FUN_1402f4460.md) | 28 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14000b270](decompiled/game-funcs/14000b270_FUN_14000b270.md) | 27 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1400c5530](decompiled/game-funcs/1400c5530_FUN_1400c5530.md) | 27 | `wrap_0c5530` | Wrapper that delegates to FUN_1400c5530 | pattern | wrapper |
| [0x1400c5560](decompiled/game-funcs/1400c5560_FUN_1400c5560.md) | 27 | `wrap_0c5560` | Wrapper that delegates to FUN_1400c5560 | pattern | wrapper |
| [0x1402f0dec](decompiled/game-funcs/1402f0dec_FUN_1402f0dec.md) | 25 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1402e8664](decompiled/game-funcs/1402e8664_FUN_1402e8664.md) | 24 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402f05fc](decompiled/game-funcs/1402f05fc_FUN_1402f05fc.md) | 24 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1402f0e08](decompiled/game-funcs/1402f0e08_FUN_1402f0e08.md) | 24 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1400cf950](decompiled/game-funcs/1400cf950_FUN_1400cf950.md) | 23 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402cd4c0](decompiled/game-funcs/1402cd4c0_FUN_1402cd4c0.md) | 22 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1402d0770](decompiled/game-funcs/1402d0770_FUN_1402d0770.md) | 22 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x140072ca0](decompiled/game-funcs/140072ca0_FUN_140072ca0.md) | 21 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x140072cc0](decompiled/game-funcs/140072cc0_FUN_140072cc0.md) | 21 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1400a53b0](decompiled/game-funcs/1400a53b0_FUN_1400a53b0.md) | 21 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1402c5ac0](decompiled/game-funcs/1402c5ac0_FUN_1402c5ac0.md) | 21 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1402ebf8c](decompiled/game-funcs/1402ebf8c_FUN_1402ebf8c.md) | 21 | `wrap_2ebf8c` | Wrapper that delegates to FUN_1402ebf8c | pattern | wrapper |
| [0x140174040](decompiled/game-funcs/140174040_FUN_140174040.md) | 20 | `wrap_174040` | Wrapper that delegates to FUN_140174040 | pattern | wrapper |
| [0x1402f7fc8](decompiled/game-funcs/1402f7fc8_FUN_1402f7fc8.md) | 20 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x14005cda0](decompiled/game-funcs/14005cda0_FUN_14005cda0.md) | 19 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x140174fc0](decompiled/game-funcs/140174fc0_FUN_140174fc0.md) | 19 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1402e9080](decompiled/game-funcs/1402e9080_FUN_1402e9080.md) | 19 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1400082e0](decompiled/game-funcs/1400082e0_FUN_1400082e0.md) | 18 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14005e210](decompiled/game-funcs/14005e210_FUN_14005e210.md) | 18 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x14005e250](decompiled/game-funcs/14005e250_FUN_14005e250.md) | 18 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1402e93b0](decompiled/game-funcs/1402e93b0_FUN_1402e93b0.md) | 18 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14002cca0](decompiled/game-funcs/14002cca0_FUN_14002cca0.md) | 17 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14009c780](decompiled/game-funcs/14009c780_FUN_14009c780.md) | 17 | `wrap_09c780` | Wrapper that delegates to FUN_14009c780 | pattern | wrapper |
| [0x1400c5f10](decompiled/game-funcs/1400c5f10_FUN_1400c5f10.md) | 17 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1400c5f30](decompiled/game-funcs/1400c5f30_FUN_1400c5f30.md) | 17 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1400c5f50](decompiled/game-funcs/1400c5f50_FUN_1400c5f50.md) | 17 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1400c5f70](decompiled/game-funcs/1400c5f70_FUN_1400c5f70.md) | 17 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x14017ffb0](decompiled/game-funcs/14017ffb0_FUN_14017ffb0.md) | 17 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1402e16a0](decompiled/game-funcs/1402e16a0_FUN_1402e16a0.md) | 17 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1402eda20](decompiled/game-funcs/1402eda20_FUN_1402eda20.md) | 17 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x140024130](decompiled/game-funcs/140024130_FUN_140024130.md) | 16 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14002f0d0](decompiled/game-funcs/14002f0d0_FUN_14002f0d0.md) | 16 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400478f0](decompiled/game-funcs/1400478f0_FUN_1400478f0.md) | 16 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400bc560](decompiled/game-funcs/1400bc560_FUN_1400bc560.md) | 16 | `wrap_0bc560` | Wrapper that delegates to FUN_1400bc560 | pattern | wrapper |
| [0x1400bf7d0](decompiled/game-funcs/1400bf7d0_FUN_1400bf7d0.md) | 16 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c4320](decompiled/game-funcs/1400c4320_FUN_1400c4320.md) | 16 | `wrap_0c4320` | Wrapper that delegates to FUN_1400c4320 | pattern | wrapper |
| [0x1400c6550](decompiled/game-funcs/1400c6550_FUN_1400c6550.md) | 15 | `wrap_0c6550` | Wrapper that delegates to FUN_1400c6550 | pattern | wrapper |
| [0x14009c320](decompiled/game-funcs/14009c320_FUN_14009c320.md) | 14 | `wrap_09c320` | Wrapper that delegates to FUN_14009c320 | pattern | wrapper |
| [0x140138fe0](decompiled/game-funcs/140138fe0_FUN_140138fe0.md) | 14 | `wrap_138fe0` | Wrapper that delegates to FUN_140138fe0 | pattern | wrapper |
| [0x1401492f0](decompiled/game-funcs/1401492f0_FUN_1401492f0.md) | 14 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140179b30](decompiled/game-funcs/140179b30_FUN_140179b30.md) | 13 | `wrap_179b30` | Wrapper that delegates to FUN_140179b30 | pattern | wrapper |
| [0x140179b40](decompiled/game-funcs/140179b40_FUN_140179b40.md) | 13 | `wrap_179b40` | Wrapper that delegates to FUN_140179b40 | pattern | wrapper |
| [0x140179b60](decompiled/game-funcs/140179b60_FUN_140179b60.md) | 13 | `wrap_179b60` | Wrapper that delegates to FUN_140179b60 | pattern | wrapper |
| [0x14017ca90](decompiled/game-funcs/14017ca90_FUN_14017ca90.md) | 13 | `wrap_17ca90` | Wrapper that delegates to FUN_14017ca90 | pattern | wrapper |
| [0x14017caa0](decompiled/game-funcs/14017caa0_FUN_14017caa0.md) | 13 | `wrap_17caa0` | Wrapper that delegates to FUN_14017caa0 | pattern | wrapper |
| [0x14017cab0](decompiled/game-funcs/14017cab0_FUN_14017cab0.md) | 13 | `wrap_17cab0` | Wrapper that delegates to FUN_14017cab0 | pattern | wrapper |
| [0x14017cae0](decompiled/game-funcs/14017cae0_FUN_14017cae0.md) | 13 | `wrap_17cae0` | Wrapper that delegates to FUN_14017cae0 | pattern | wrapper |
| [0x1401841e0](decompiled/game-funcs/1401841e0_FUN_1401841e0.md) | 13 | `wrap_1841e0` | Wrapper that delegates to FUN_1401841e0 | pattern | wrapper |
| [0x140188670](decompiled/game-funcs/140188670_FUN_140188670.md) | 13 | `wrap_188670` | Wrapper that delegates to FUN_140188670 | pattern | wrapper |
| [0x1402e8ce0](decompiled/game-funcs/1402e8ce0_FUN_1402e8ce0.md) | 13 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1400b6150](decompiled/game-funcs/1400b6150_FUN_1400b6150.md) | 12 | `wrap_0b6150` | Wrapper that delegates to FUN_1400b6150 | pattern | wrapper |
| [0x140163ab0](decompiled/game-funcs/140163ab0_FUN_140163ab0.md) | 12 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402da20c](decompiled/game-funcs/1402da20c_FUN_1402da20c.md) | 12 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400b4af0](decompiled/game-funcs/1400b4af0_FUN_1400b4af0.md) | 11 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x140138fc0](decompiled/game-funcs/140138fc0_FUN_140138fc0.md) | 11 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1402c7c2c](decompiled/game-funcs/1402c7c2c_FUN_1402c7c2c.md) | 11 | `wrap_2c7c2c` | Wrapper that delegates to FUN_1402c7c2c | pattern | wrapper |
| [0x1402ce0f8](decompiled/game-funcs/1402ce0f8_FUN_1402ce0f8.md) | 11 | `wrap_2ce0f8` | Wrapper that delegates to FUN_1402ce0f8 | pattern | wrapper |
| [0x1402e1710](decompiled/game-funcs/1402e1710_FUN_1402e1710.md) | 11 | `wrap_2e1710` | Wrapper that delegates to FUN_1402e1710 | pattern | wrapper |
| [0x1402e171c](decompiled/game-funcs/1402e171c_FUN_1402e171c.md) | 11 | `wrap_2e171c` | Wrapper that delegates to FUN_1402e171c | pattern | wrapper |
| [0x1400b7720](decompiled/game-funcs/1400b7720_FUN_1400b7720.md) | 10 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1400c4de0](decompiled/game-funcs/1400c4de0_FUN_1400c4de0.md) | 10 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402da254](decompiled/game-funcs/1402da254_FUN_1402da254.md) | 10 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402e8ca0](decompiled/game-funcs/1402e8ca0_FUN_1402e8ca0.md) | 10 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1402e8cb0](decompiled/game-funcs/1402e8cb0_FUN_1402e8cb0.md) | 10 | `wrap_2e8cb0` | Wrapper that delegates to FUN_1402e8cb0 | pattern | wrapper |
| [0x1402ec3b0](decompiled/game-funcs/1402ec3b0_FUN_1402ec3b0.md) | 10 | `wrap_2ec3b0` | Wrapper that delegates to FUN_1402ec3b0 | pattern | wrapper |
| [0x140009de0](decompiled/game-funcs/140009de0_FUN_140009de0.md) | 9 | `get_field_0xb4` | Returns the field at struct offset 0xb4 | pattern | getter |
| [0x140009df0](decompiled/game-funcs/140009df0_FUN_140009df0.md) | 9 | `get_field_0xb8` | Returns the field at struct offset 0xb8 | pattern | getter |
| [0x1402e90a0](decompiled/game-funcs/1402e90a0_FUN_1402e90a0.md) | 9 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1402f5700](decompiled/game-funcs/1402f5700_FUN_1402f5700.md) | 9 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x140005e00](decompiled/game-funcs/140005e00_FUN_140005e00.md) | 8 | `empty_stub` | Tiny <=8 byte stub (likely a `ret`) | pattern | empty_stub |
| [0x140009e00](decompiled/game-funcs/140009e00_FUN_140009e00.md) | 8 | `empty_stub` | Tiny <=8 byte stub (likely a `ret`) | pattern | empty_stub |
| [0x14000b290](decompiled/game-funcs/14000b290_FUN_14000b290.md) | 8 | `empty_stub` | Tiny <=8 byte stub (likely a `ret`) | pattern | empty_stub |
| [0x14000b390](decompiled/game-funcs/14000b390_FUN_14000b390.md) | 8 | `empty_stub` | Tiny <=8 byte stub (likely a `ret`) | pattern | empty_stub |
| [0x140023ed0](decompiled/game-funcs/140023ed0_FUN_140023ed0.md) | 8 | `empty_stub` | Tiny <=8 byte stub (likely a `ret`) | pattern | empty_stub |
| [0x140086330](decompiled/game-funcs/140086330_FUN_140086330.md) | 8 | `empty_stub` | Tiny <=8 byte stub (likely a `ret`) | pattern | empty_stub |
| [0x14008d2c0](decompiled/game-funcs/14008d2c0_FUN_14008d2c0.md) | 8 | `empty_stub` | Tiny <=8 byte stub (likely a `ret`) | pattern | empty_stub |
| [0x1400a89f0](decompiled/game-funcs/1400a89f0_FUN_1400a89f0.md) | 8 | `empty_stub` | Tiny <=8 byte stub (likely a `ret`) | pattern | empty_stub |
| [0x1400b7650](decompiled/game-funcs/1400b7650_FUN_1400b7650.md) | 8 | `empty_stub` | Tiny <=8 byte stub (likely a `ret`) | pattern | empty_stub |
| [0x1400c43c0](decompiled/game-funcs/1400c43c0_FUN_1400c43c0.md) | 8 | `empty_stub` | Tiny <=8 byte stub (likely a `ret`) | pattern | empty_stub |
| [0x1400c5c20](decompiled/game-funcs/1400c5c20_FUN_1400c5c20.md) | 8 | `empty_stub` | Tiny <=8 byte stub (likely a `ret`) | pattern | empty_stub |
| [0x1400c5c30](decompiled/game-funcs/1400c5c30_FUN_1400c5c30.md) | 8 | `empty_stub` | Tiny <=8 byte stub (likely a `ret`) | pattern | empty_stub |
| [0x1400c6570](decompiled/game-funcs/1400c6570_FUN_1400c6570.md) | 8 | `empty_stub` | Tiny <=8 byte stub (likely a `ret`) | pattern | empty_stub |
| [0x1401745e0](decompiled/game-funcs/1401745e0_FUN_1401745e0.md) | 8 | `empty_stub` | Tiny <=8 byte stub (likely a `ret`) | pattern | empty_stub |
| [0x1402f7fc0](decompiled/game-funcs/1402f7fc0_FUN_1402f7fc0.md) | 8 | `empty_stub` | Tiny <=8 byte stub (likely a `ret`) | pattern | empty_stub |
| [0x140138fb0](decompiled/game-funcs/140138fb0_FUN_140138fb0.md) | 7 | `empty_stub` | Tiny <=8 byte stub (likely a `ret`) | pattern | empty_stub |
| [0x1402e7d34](decompiled/game-funcs/1402e7d34_FUN_1402e7d34.md) | 7 | `empty_stub` | Tiny <=8 byte stub (likely a `ret`) | pattern | empty_stub |
| [0x1400c5c00](decompiled/game-funcs/1400c5c00_FUN_1400c5c00.md) | 5 | `empty_stub` | Tiny <=8 byte stub (likely a `ret`) | pattern | empty_stub |
| [0x1400c5c10](decompiled/game-funcs/1400c5c10_FUN_1400c5c10.md) | 5 | `empty_stub` | Tiny <=8 byte stub (likely a `ret`) | pattern | empty_stub |
| [0x140139010](decompiled/game-funcs/140139010_FUN_140139010.md) | 5 | `empty_stub` | Tiny <=8 byte stub (likely a `ret`) | pattern | empty_stub |
| [0x1402c7088](decompiled/game-funcs/1402c7088_FUN_1402c7088.md) | 5 | `empty_stub` | Tiny <=8 byte stub (likely a `ret`) | pattern | empty_stub |
| [0x1402eba70](decompiled/game-funcs/1402eba70_FUN_1402eba70.md) | 5 | `empty_stub` | Tiny <=8 byte stub (likely a `ret`) | pattern | empty_stub |
| [0x1400734c0](decompiled/game-funcs/1400734c0_FUN_1400734c0.md) | 3 | `empty_stub` | Tiny <=8 byte stub (likely a `ret`) | pattern | empty_stub |
| [0x1400bcaf0](decompiled/game-funcs/1400bcaf0_FUN_1400bcaf0.md) | 3 | `empty_stub` | Tiny <=8 byte stub (likely a `ret`) | pattern | empty_stub |
| [0x1400c8d80](decompiled/game-funcs/1400c8d80_FUN_1400c8d80.md) | 3 | `empty_stub` | Tiny <=8 byte stub (likely a `ret`) | pattern | empty_stub |

## domain: `-` (24 functions)

| Addr | Size | Proposed name | Description | Source | Category |
|---|---|---|---|---|---|
| [0x140104370](decompiled/game-funcs/140104370_FUN_140104370.md) | 650 | `medium_loop_handler` | Moderate loop-based handler | pattern | medium_loop |
| [0x1400450b0](decompiled/game-funcs/1400450b0_FUN_1400450b0.md) | 384 | `float_helper` | Heavy float arithmetic (probably geometry or genetics expression) | pattern | float_math |
| [0x1400447e0](decompiled/game-funcs/1400447e0_FUN_1400447e0.md) | 284 | `batch_call_2e9a80` | Calls FUN_1402e9a80 5 times in a loop | pattern | repeated_op |
| [0x14005d360](decompiled/game-funcs/14005d360_FUN_14005d360.md) | 267 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14003f590](decompiled/game-funcs/14003f590_FUN_14003f590.md) | 227 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140044ff0](decompiled/game-funcs/140044ff0_FUN_140044ff0.md) | 177 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400c7560](decompiled/game-funcs/1400c7560_FUN_1400c7560.md) | 140 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14008fed0](decompiled/game-funcs/14008fed0_FUN_14008fed0.md) | 126 | `init_struct` | Zero-initializes consecutive struct fields (zero-inits 3 fields) | pattern | struct_init |
| [0x1402cf9a4](decompiled/game-funcs/1402cf9a4_FUN_1402cf9a4.md) | 97 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14003f6f0](decompiled/game-funcs/14003f6f0_FUN_14003f6f0.md) | 70 | `helper_with_3_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400b7730](decompiled/game-funcs/1400b7730_FUN_1400b7730.md) | 53 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400453a0](decompiled/game-funcs/1400453a0_FUN_1400453a0.md) | 49 | `helper_with_1_callees` | Generic helper that calls other functions | pattern | helper |
| [0x14009e2c0](decompiled/game-funcs/14009e2c0_FUN_14009e2c0.md) | 41 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400d0c50](decompiled/game-funcs/1400d0c50_FUN_1400d0c50.md) | 39 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x140071ed0](decompiled/game-funcs/140071ed0_FUN_140071ed0.md) | 35 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1400b9220](decompiled/game-funcs/1400b9220_FUN_1400b9220.md) | 30 | `helper_with_2_callees` | Generic helper that calls other functions | pattern | helper |
| [0x1402c6a38](decompiled/game-funcs/1402c6a38_FUN_1402c6a38.md) | 27 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1400ca240](decompiled/game-funcs/1400ca240_FUN_1400ca240.md) | 17 | `wrap_0ca240` | Wrapper that delegates to FUN_1400ca240 | pattern | wrapper |
| [0x140067e30](decompiled/game-funcs/140067e30_FUN_140067e30.md) | 16 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x1400b76a0](decompiled/game-funcs/1400b76a0_FUN_1400b76a0.md) | 16 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x140086310](decompiled/game-funcs/140086310_FUN_140086310.md) | 15 | `tiny_return_fn` | Tiny function whose body is just a return | pattern | simple_return |
| [0x140023ec0](decompiled/game-funcs/140023ec0_FUN_140023ec0.md) | 8 | `empty_stub` | Tiny <=8 byte stub (likely a `ret`) | pattern | empty_stub |
| [0x1402c6cd0](decompiled/game-funcs/1402c6cd0_FUN_1402c6cd0.md) | 8 | `empty_stub` | Tiny <=8 byte stub (likely a `ret`) | pattern | empty_stub |
| [0x14003f330](decompiled/game-funcs/14003f330_FUN_14003f330.md) | 7 | `empty_stub` | Tiny <=8 byte stub (likely a `ret`) | pattern | empty_stub |
