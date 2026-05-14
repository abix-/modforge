# All game-logic functions (auto-summarized)

1234 game-logic functions. Each has a one-line summary.

**source = string**: summary derived from a recognized in-game string.
**source = pattern**: summary derived from code-shape category.

| Source | Count | % |
|---|---|---|
| pattern | 1168 | 94.7% |
| string | 66 | 5.3% |

## Functions (string-anchored first, then by size)

| Addr | Size | Summary | Source | Domain |
|---|---|---|---|---|
| 0x14009f680 | 14074 | Error: bad gene index (gene expression) | string | world_event |
| 0x140094a20 | 13205 | Track: race-ready prompt | string | race |
| 0x140107660 | 12134 | Location: zoo | string | world_event |
| 0x1400f6fe0 | 9683 | Sound: prize appears | string | world_event |
| 0x1400d2ab0 | 9349 | Sound: prize appears | string | world_event |
| 0x140089510 | 8654 | Action: serialize genome to clipboard | string | world_event |
| 0x14008ffc0 | 8565 | Error: race odds compute failed | string | world_event |
| 0x140058480 | 7589 | Stat: genetic diversity | string | world_event |
| 0x1400b0740 | 7483 | Render: horse decoration | string | world_event |
| 0x1400ba940 | 7179 | Sound: jet engine loop | string | world_event |
| 0x1400e0aa0 | 6908 | Empty-state: all horses rested | string | fatigue |
| 0x140033a10 | 6233 | Action: take a DNA sample | string | genetics |
| 0x140039190 | 6047 | Location: circus | string | world_event |
| 0x1400c0660 | 5765 | Debug: roster stats | string | debug |
| 0x14007b2e0 | 5750 | Location: sumo arena | string | world_event |
| 0x140061f40 | 5304 | Dialog: bad race comment | string | world_event |
| 0x1400fe2e0 | 5277 | Error: tilemap file missing | string | world_event |
| 0x14010a5e0 | 5188 | Vehicle: hot air balloon | string | world_event |
| 0x1400dde40 | 5159 | Eligibility check: rejects too-tired horse | string | fatigue |
| 0x1400dcab0 | 4986 | Eligibility check: rejects too-old horse | string | aging |
| 0x14010ba40 | 4610 | Stat: genetic diversity | string | debug |
| 0x1400df280 | 4364 | Retirement: (old) record-holding horse | string | aging |
| 0x140066200 | 4188 | Location: Sweetie's House | string | debug |
| 0x14002d7c0 | 4033 | Sound: won race | string | race |
| 0x140060a80 | 3713 | Prompt: rest the horse | string | fatigue |
| 0x140076a10 | 3488 | Loader: tilemap horsey.tmx | string | settings_io |
| 0x14007e030 | 3320 | Location: paddock | string | world_event |
| 0x140082640 | 2966 | Sound: horse eats | string | world_event |
| 0x1400a74e0 | 2941 | Dialog: welcome | string | world_event |
| 0x1400ceb60 | 2502 | Action/sound: whip crack | string | world_event |
| 0x1400a3eb0 | 2491 | Error: unknown gene in chromoMap | string | world_event |
| 0x1400cacd0 | 2454 | Render: sleep animation | string | race |
| 0x14006e480 | 2439 | Save file: read/write save<N>.dat | string | save_io |
| 0x1400bd820 | 2270 | Render: thought bubble | string | world_event |
| 0x1400fd580 | 2159 | Location: zoo | string | world_event |
| 0x14006dc80 | 2026 | Save file: read/write save<N>.dat | string | save_io |
| 0x140080e40 | 1972 | Location: stable | string | world_event |
| 0x14002fe00 | 1630 | Daily event: ate hay | string | world_event |
| 0x1400816b0 | 1610 | Sound: wild mating | string | breeding |
| 0x1400fa910 | 1539 | Location: zoo | string | world_event |
| 0x14005f1f0 | 1125 | NPC: Clarence character | string | world_event |
| 0x1401046c0 | 1004 | Location: stable | string | world_event |
| 0x1400d23d0 | 873 | Sound: horse eats | string | world_event |
| 0x1400379e0 | 850 | Location: circus | string | world_event |
| 0x14008f6e0 | 804 | Location: paddock | string | world_event |
| 0x140088000 | 775 | Location: CRISPR Lab | string | world_event |
| 0x140069ee0 | 590 | Location: saloon | string | world_event |
| 0x14007dbf0 | 518 | Action: lasso | string | world_event |
| 0x14008fce0 | 477 | Sound: on-your-mark | string | world_event |
| 0x14008f130 | 459 | Dialog: welcome | string | world_event |
| 0x140104c00 | 433 | Sound: lose money | string | world_event |
| 0x14005fad0 | 431 | Location: paddock | string | world_event |
| 0x140065a90 | 376 | Location: hutch | string | world_event |
| 0x1400fd3e0 | 375 | Status: chromosome scan progress | string | genetics |
| 0x140105980 | 374 | Status: champion horse | string | race |
| 0x14003ee40 | 354 | Loader: sound.xml registry | string | world_event |
| 0x14005c5d0 | 320 | Dialog: welcome | string | world_event |
| 0x140064590 | 306 | Location: hutch | string | world_event |
| 0x1400f4ea0 | 282 | Location: Sweetie's House | string | world_event |
| 0x1400cb8c0 | 280 | Sound: prize appears | string | world_event |
| 0x14007ad10 | 231 | Location: sumo arena | string | world_event |
| 0x14002f0f0 | 225 | Location: acres | string | world_event |
| 0x1400a5e00 | 215 | Error: bad gene index (gene expression) | string | world_event |
| 0x140067e60 | 155 | Location: power plant | string | world_event |
| 0x14008de50 | 115 | Location: car lot | string | world_event |
| 0x1401123f0 | 79 | Location: zoo | string | world_event |
| 0x140050ad0 | 11025 | Batch helper; calls FUN_14004cb40 x71 | pattern | world_event |
| 0x1400ab3d0 | 8647 | Struct initializer; zero-inits 7 fields | pattern | world_event |
| 0x140092820 | 5156 | Struct initializer; zero-inits 5 fields | pattern | world_event |
| 0x1400b9540 | 5110 | Struct initializer; zero-inits 3 fields | pattern | world_event |
| 0x1402f6c9c | 4734 | Batch helper; calls FUN_1402f94c0 x8 | pattern | world_event |
| 0x1401c10d0 | 4690 | Batch helper; calls FUN_1401c97e0 x17 | pattern | world_event |
| 0x14004dc90 | 4047 | Batch helper; calls FUN_14004cf80 x5 | pattern | world_event |
| 0x1400d0c80 | 4008 | Batch helper; calls FUN_1402c7088 x10 | pattern | world_event |
| 0x14007c970 | 3987 | Batch helper; calls FUN_140086570 x9 | pattern | race |
| 0x1402d8d60 | 3443 | Batch helper; calls FUN_1402f08b0 x22 | pattern | world_event |
| 0x14003f810 | 3359 | Batch helper; calls FUN_1402f8e20 x6 | pattern | world_event |
| 0x1400c35b0 | 3356 | Batch helper; calls FUN_1400c5f50 x6 | pattern | world_event |
| 0x1400da2f0 | 3290 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x140006950 | 3264 | Batch helper; calls FUN_1402cdc50 x6 | pattern | world_event |
| 0x1400ad5c0 | 3254 | Batch helper; calls FUN_1400a9360 x10 | pattern | race |
| 0x140016c70 | 3150 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x1401acec0 | 3099 | Batch helper; calls FUN_1401841f0 x14 | pattern | world_event |
| 0x140053a40 | 3042 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x140086910 | 3007 | Batch helper; calls FUN_1402c7088 x11 | pattern | world_event |
| 0x14006b040 | 2987 | Batch helper; calls FUN_1402c7088 x8 | pattern | world_event |
| 0x14001f7b0 | 2954 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x1401035b0 | 2834 | Batch helper; calls FUN_1402f8e20 x10 | pattern | world_event |
| 0x14004b960 | 2740 | Struct initializer; zero-inits 6 fields | pattern | world_event |
| 0x1400ca260 | 2646 | Struct initializer; zero-inits 4 fields | pattern | world_event |
| 0x1400aed30 | 2595 | Batch helper; calls FUN_1400a9360 x9 | pattern | world_event |
| 0x1400b3dc0 | 2575 | Struct initializer; zero-inits 4 fields | pattern | world_event |
| 0x1400463e0 | 2552 | Large loop-containing handler | pattern | world_event |
| 0x1400d98f0 | 2517 | Batch helper; calls FUN_1402d8d60 x8 | pattern | world_event |
| 0x140106140 | 2405 | Batch helper; calls FUN_1402c7088 x8 | pattern | world_event |
| 0x140196db0 | 2291 | Multi-way switch dispatcher | pattern | world_event |
| 0x1400d52c0 | 2253 | Batch helper; calls FUN_1400c7520 x8 | pattern | world_event |
| 0x1400b2490 | 2096 | Batch helper; calls FUN_1400b2cd0 x4 | pattern | world_event |
| 0x1400b4b10 | 2053 | Batch helper; calls FUN_1402f8e20 x6 | pattern | world_event |
| 0x140097dd0 | 2046 | Batch helper; calls FUN_1400c6580 x7 | pattern | world_event |
| 0x140013d80 | 2038 | Batch helper; calls FUN_1402cdc50 x4 | pattern | world_event |
| 0x1400cc1d0 | 2029 | Batch helper; calls FUN_1400d0c80 x15 | pattern | world_event |
| 0x1402d0790 | 2022 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x1400bfa90 | 1970 | Batch helper; calls FUN_1402c6760 x7 | pattern | world_event |
| 0x140093d90 | 1956 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x1400bcb00 | 1924 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x1400cba60 | 1894 | Batch helper; calls FUN_1400cc9d0 x4 | pattern | world_event |
| 0x140017910 | 1887 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x14009c8c0 | 1881 | Batch helper; calls FUN_1402c704c x11 | pattern | world_event |
| 0x1400cddd0 | 1833 | Batch helper; calls FUN_1402f8e20 x8 | pattern | world_event |
| 0x14001eae0 | 1832 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x14000eef0 | 1814 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x1400b78d0 | 1787 | Batch helper; calls FUN_1400c5c10 x11 | pattern | world_event |
| 0x140012ba0 | 1765 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x14005d710 | 1728 | Batch helper; calls FUN_1400c6580 x7 | pattern | world_event |
| 0x140015c30 | 1718 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x140047cd0 | 1675 | Large loop-containing handler | pattern | world_event |
| 0x1400afc20 | 1664 | Batch helper; calls FUN_1400a9360 x4 | pattern | world_event |
| 0x1400ae6b0 | 1656 | Batch helper; calls FUN_1400a9360 x8 | pattern | world_event |
| 0x1401112f0 | 1624 | Batch helper; calls FUN_140110ef0 x4 | pattern | world_event |
| 0x140102df0 | 1621 | Iterates horse list at obj+0xb8/+0xc0 | pattern | world_event |
| 0x1400e0420 | 1610 | Batch helper; calls FUN_1400c6580 x5 | pattern | world_event |
| 0x14009d750 | 1577 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x140013290 | 1575 | Batch helper; calls FUN_140012a20 x4 | pattern | world_event |
| 0x1400d03f0 | 1539 | Large loop-containing handler | pattern | world_event |
| 0x14006a420 | 1505 | Struct initializer; zero-inits 6 fields | pattern | world_event |
| 0x1400449e0 | 1493 | Large loop-containing handler | pattern | world_event |
| 0x140106bc0 | 1463 | Batch helper; calls FUN_1402c7088 x4 | pattern | world_event |
| 0x14001f210 | 1430 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x140010540 | 1427 | Batch helper; calls FUN_140012630 x10 | pattern | world_event |
| 0x14010d7e0 | 1413 | Batch helper; calls FUN_1400c6940 x28 | pattern | world_event |
| 0x1400a4880 | 1397 | Batch helper; calls FUN_140025900 x4 | pattern | debug |
| 0x1402e4980 | 1386 | Batch helper; calls FUN_1402ecfa0 x5 | pattern | world_event |
| 0x1400b3070 | 1367 | Batch helper; calls FUN_1402f94c0 x4 | pattern | world_event |
| 0x1400063f0 | 1364 | Struct initializer; zero-inits 3 fields | pattern | world_event |
| 0x1402f8e20 | 1353 | Multi-way switch dispatcher | pattern | world_event |
| 0x1400d72f0 | 1342 | Batch helper; calls FUN_1400b6150 x16 | pattern | world_event |
| 0x140049630 | 1339 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x1400cd5a0 | 1326 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x1400e3670 | 1319 | Batch helper; calls FUN_1400e35f0 x5 | pattern | aging |
| 0x140020bb0 | 1306 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x1402d0f80 | 1277 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x140048e90 | 1264 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x1400155f0 | 1250 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x1400d5ff0 | 1241 | Large loop-containing handler | pattern | world_event |
| 0x14001e5e0 | 1229 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x140102060 | 1225 | Batch helper; calls FUN_1400c5c20 x4 | pattern | world_event |
| 0x140105260 | 1223 | Batch helper; calls FUN_1400c6580 x15 | pattern | world_event |
| 0x14000bfe0 | 1221 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x1400693b0 | 1207 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x1400138c0 | 1203 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x140020700 | 1199 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x1400aa2b0 | 1183 | Heavy float math (likely geometry / genetics expression) | pattern | race |
| 0x1400d7830 | 1181 | Batch helper; calls FUN_1400b6150 x32 | pattern | world_event |
| 0x1400a5400 | 1178 | Batch helper; calls FUN_1402f8e20 x5 | pattern | world_event |
| 0x1402edc48 | 1171 | Large loop-containing handler | pattern | world_event |
| 0x1400c86f0 | 1167 | Heavy float math (likely geometry / genetics expression) | pattern | race |
| 0x1402de160 | 1164 | Large loop-containing handler | pattern | world_event |
| 0x1400af790 | 1158 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x1401005b0 | 1157 | Large loop-containing handler | pattern | world_event |
| 0x140018070 | 1141 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x1400b87e0 | 1137 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x1402d5aec | 1133 | Large loop-containing handler | pattern | world_event |
| 0x1400db270 | 1124 | Batch helper; calls FUN_1400cf540 x8 | pattern | world_event |
| 0x1400b02b0 | 1116 | Batch helper; calls FUN_1400a9360 x4 | pattern | world_event |
| 0x1401c97e0 | 1105 | Struct initializer; zero-inits 17 fields | pattern | world_event |
| 0x1400a9c80 | 1093 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x1400b7fe0 | 1073 | Large loop-containing handler | pattern | world_event |
| 0x140054630 | 1065 | Batch helper; calls FUN_1402e9a80 x29 | pattern | world_event |
| 0x1400ae280 | 1059 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x14000da90 | 1057 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x14010f7e0 | 1050 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x1400c8e70 | 1049 | Large loop-containing handler | pattern | world_event |
| 0x1400b5b50 | 1048 | Batch helper; calls FUN_1402f8e20 x4 | pattern | world_event |
| 0x1400cfda0 | 1047 | Large loop-containing handler | pattern | world_event |
| 0x1400b39b0 | 1034 | Batch helper; calls FUN_1400a5370 x4 | pattern | world_event |
| 0x14009e2f0 | 1027 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x1400d9010 | 1018 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x1400fdee0 | 1018 | Batch helper; calls FUN_1402c704c x24 | pattern | save_io |
| 0x1402cd4e0 | 1018 | Batch helper; calls FUN_1402e8cc0 x8 | pattern | world_event |
| 0x14004c420 | 1017 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x14001b740 | 1014 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x140011cb0 | 1012 | Large loop-containing handler | pattern | world_event |
| 0x1400113e0 | 1002 | Large loop-containing handler | pattern | world_event |
| 0x140071420 | 993 | Loop-containing helper | pattern | world_event |
| 0x140073c30 | 989 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x1400c4a10 | 965 | Batch helper; calls FUN_1402c7088 x5 | pattern | world_event |
| 0x140057c20 | 961 | Batch helper; calls FUN_1400c9c30 x12 | pattern | world_event |
| 0x1400c9420 | 961 | Struct initializer; zero-inits 7 fields | pattern | world_event |
| 0x140020340 | 948 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x14004d8d0 | 946 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x1400c43d0 | 935 | Batch helper; calls FUN_1402c7088 x5 | pattern | world_event |
| 0x1400a65d0 | 920 | Batch helper; calls FUN_140025900 x4 | pattern | debug |
| 0x140086570 | 919 | Loop-containing helper | pattern | world_event |
| 0x14010d260 | 918 | Batch helper; calls FUN_1400c6940 x12 | pattern | world_event |
| 0x1402cf520 | 916 | Loop-containing helper | pattern | world_event |
| 0x1402eef9c | 915 | Loop-containing helper | pattern | world_event |
| 0x1400168e0 | 904 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x140105da0 | 904 | Iterates horse list at obj+0xb8/+0xc0 | pattern | world_event |
| 0x1400aac60 | 902 | Struct initializer; zero-inits 11 fields | pattern | world_event |
| 0x1400dbe10 | 896 | Struct initializer; zero-inits 4 fields | pattern | world_event |
| 0x1400ff790 | 886 | Iterates horse list at obj+0xb8/+0xc0 | pattern | world_event |
| 0x1402eb6f0 | 882 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x1402d4650 | 878 | Struct initializer; zero-inits 8 fields | pattern | world_event |
| 0x1402d42e8 | 871 | Struct initializer; zero-inits 8 fields | pattern | world_event |
| 0x1400bea50 | 869 | Iterates horse list at obj+0xb8/+0xc0 | pattern | world_event |
| 0x1400d2740 | 869 | Heavy float math (likely geometry / genetics expression) | pattern | race |
| 0x1400fce70 | 860 | Loop-containing helper | pattern | world_event |
| 0x140060710 | 855 | Loop-containing helper | pattern | save_io |
| 0x1400164b0 | 854 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x14004d3b0 | 851 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x1400b3650 | 851 | Batch helper; calls FUN_1400a53b0 x4 | pattern | world_event |
| 0x140067ad0 | 850 | Loop-containing helper | pattern | world_event |
| 0x1400b6fd0 | 849 | Heavy float math (likely geometry / genetics expression) | pattern | race |
| 0x1400c8220 | 831 | Loop-containing helper | pattern | world_event |
| 0x1402cf1e0 | 830 | Batch helper; calls FUN_1402e8c20 x5 | pattern | world_event |
| 0x1401bbf50 | 828 | Batch helper; calls FUN_1401749e0 x5 | pattern | world_event |
| 0x1400d2090 | 821 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x140088990 | 817 | Batch helper; calls FUN_1400c6580 x11 | pattern | world_event |
| 0x14006ee10 | 816 | Batch helper; calls FUN_140075690 x8 | pattern | save_io |
| 0x1402ee62c | 815 | Loop-containing helper | pattern | world_event |
| 0x1400a5950 | 810 | Loop-containing helper | pattern | world_event |
| 0x140102530 | 805 | Iterates horse list at obj+0xb8/+0xc0 | pattern | world_event |
| 0x1401b5d50 | 805 | Heavy float math (likely geometry / genetics expression) | pattern | world_event |
| 0x1400479b0 | 800 | Float math helper | pattern | world_event |
| 0x140101990 | 799 | Float math helper | pattern | world_event |
| 0x1400293d0 | 790 | Struct initializer; zero-inits 3 fields | pattern | world_event |
| 0x1402cdc50 | 785 | Float math helper | pattern | world_event |
| 0x1400119a0 | 780 | Batch helper; calls FUN_1402e9a80 x4 | pattern | world_event |
| 0x1402ebab0 | 778 | Float math helper | pattern | world_event |
| 0x14006f150 | 772 | Batch helper; calls FUN_140075c60 x8 | pattern | save_io |
| 0x140024220 | 766 | Helper function (calls other game functions) | pattern | world_event |
| 0x140080730 | 766 | Struct field accessor; 32 field accesses on param_1 | pattern | world_event |
| 0x140048b90 | 765 | Loop-containing helper | pattern | world_event |
| 0x1400b56d0 | 761 | Loop-containing helper | pattern | world_event |
| 0x1400120b0 | 754 | Batch helper; calls FUN_1400124f0 x4 | pattern | world_event |
| 0x140055060 | 753 | Loop-containing helper | pattern | world_event |
| 0x14008d460 | 752 | Helper function (calls other game functions) | pattern | world_event |
| 0x14009b7b0 | 751 | Loop-containing helper | pattern | world_event |
| 0x1400d4f50 | 747 | Loop-containing helper | pattern | race |
| 0x14006d790 | 746 | Batch helper; calls FUN_1402c704c x6 | pattern | save_io |
| 0x14000f8d0 | 740 | Float math helper | pattern | world_event |
| 0x1400b9250 | 740 | Loop-containing helper | pattern | world_event |
| 0x1402efaac | 740 | Loop-containing helper | pattern | world_event |
| 0x1400886a0 | 739 | Float math helper | pattern | world_event |
| 0x14008cc80 | 736 | Batch helper; calls FUN_1402f94c0 x5 | pattern | world_event |
| 0x1400cdae0 | 733 | Iterates horse list at param[0x26]/[0x27] | pattern | world_event |
| 0x1402d8688 | 731 | Loop-containing helper | pattern | world_event |
| 0x1402d83ac | 729 | Loop-containing helper | pattern | world_event |
| 0x1400297b0 | 728 | Batch helper; calls FUN_1402c704c x5 | pattern | world_event |
| 0x1400cce00 | 728 | Iterates horse list at obj+0xb8/+0xc0 | pattern | world_event |
| 0x140005a10 | 725 | Struct initializer; zero-inits 7 fields | pattern | world_event |
| 0x1402f94c0 | 725 | Multi-way switch dispatcher | pattern | world_event |
| 0x140074020 | 722 | Float math helper | pattern | world_event |
| 0x1400581a0 | 715 | Loop-containing helper | pattern | world_event |
| 0x1400aa760 | 711 | Float math helper | pattern | race |
| 0x140071150 | 710 | Float math helper | pattern | race |
| 0x14000fd50 | 698 | Float math helper | pattern | world_event |
| 0x1402d1e3c | 692 | Helper function (calls other game functions) | pattern | world_event |
| 0x140008030 | 688 | Float math helper | pattern | world_event |
| 0x140049380 | 688 | Loop-containing helper | pattern | world_event |
| 0x1400b6360 | 682 | Float math helper | pattern | world_event |
| 0x1400c9980 | 680 | Iterates horse list at param[0x26]/[0x27] | pattern | world_event |
| 0x1400d83f0 | 680 | Batch helper; calls FUN_1400b6150 x4 | pattern | world_event |
| 0x1400d7fe0 | 673 | Loop-containing helper | pattern | world_event |
| 0x140102b40 | 673 | Struct field accessor; 14 field accesses on param_1 | pattern | world_event |
| 0x140101dc0 | 663 | Float math helper | pattern | world_event |
| 0x140105b00 | 661 | Loop-containing helper | pattern | world_event |
| 0x140049b70 | 655 | Float math helper | pattern | world_event |
| 0x140010ce0 | 653 | Loop-containing helper | pattern | world_event |
| 0x140084060 | 653 | Batch helper; calls FUN_140009e60 x4 | pattern | world_event |
| 0x140104370 | 650 | Loop-containing helper | pattern | - |
| 0x1400cd2d0 | 640 | Batch helper; calls FUN_140071ed0 x4 | pattern | world_event |
| 0x140032320 | 639 | Loop-containing helper | pattern | world_event |
| 0x1400c7d80 | 639 | Batch helper; calls FUN_140075690 x5 | pattern | save_io |
| 0x140043810 | 638 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401c9f60 | 637 | Batch helper; calls FUN_14012e0b0 x8 | pattern | world_event |
| 0x1400b8f90 | 636 | Struct initializer; zero-inits 3 fields | pattern | world_event |
| 0x140048360 | 634 | Loop-containing helper | pattern | world_event |
| 0x1400d86a0 | 632 | Batch helper; calls FUN_1400b6150 x8 | pattern | world_event |
| 0x140048910 | 630 | Loop-containing helper | pattern | world_event |
| 0x140110bf0 | 625 | Loop-containing helper | pattern | world_event |
| 0x1400bf3c0 | 623 | Loop-containing helper | pattern | world_event |
| 0x140042b70 | 608 | Struct initializer; zero-inits 3 fields | pattern | world_event |
| 0x1400820a0 | 607 | Loop-containing helper | pattern | world_event |
| 0x140047690 | 603 | Loop-containing helper | pattern | world_event |
| 0x1402e6268 | 602 | Batch helper; calls FUN_1402e8664 x4 | pattern | world_event |
| 0x14000e0e0 | 601 | Float math helper | pattern | world_event |
| 0x1402d6bc0 | 601 | Loop-containing helper | pattern | world_event |
| 0x14004d150 | 600 | Float math helper | pattern | world_event |
| 0x1400d5d90 | 597 | Batch helper; calls FUN_140071ed0 x5 | pattern | race |
| 0x1402d7d00 | 593 | Helper function (calls other game functions) | pattern | world_event |
| 0x140073780 | 592 | Float math helper | pattern | world_event |
| 0x1400fb050 | 589 | Struct field accessor; 9 field accesses on param_1 | pattern | world_event |
| 0x14003f340 | 575 | Helper function (calls other game functions) | pattern | world_event |
| 0x140094540 | 574 | Loop-containing helper | pattern | race |
| 0x1401107d0 | 571 | Loop-containing helper | pattern | aging |
| 0x1400c7910 | 566 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400ffd00 | 565 | Loop-containing helper | pattern | world_event |
| 0x140026080 | 562 | Loop-containing helper | pattern | world_event |
| 0x1400c31e0 | 555 | Loop-containing helper | pattern | world_event |
| 0x140005eb0 | 554 | Loop-containing helper | pattern | world_event |
| 0x140053810 | 553 | Batch helper; calls FUN_14004c8a0 x5 | pattern | world_event |
| 0x140092150 | 552 | Loop-containing helper | pattern | race |
| 0x1400b6aa0 | 551 | Float math helper | pattern | world_event |
| 0x1400ccbd0 | 551 | Iterates horse list at obj+0xb8/+0xc0 | pattern | world_event |
| 0x14005bc30 | 548 | Loop-containing helper | pattern | world_event |
| 0x1400b54a0 | 546 | Float math helper | pattern | world_event |
| 0x140041900 | 544 | Batch helper; calls FUN_140054630 x4 | pattern | world_event |
| 0x14009bea0 | 543 | Loop-containing helper | pattern | world_event |
| 0x1400ab1b0 | 535 | Float math helper | pattern | world_event |
| 0x140100a40 | 535 | Loop-containing helper | pattern | world_event |
| 0x14005cf70 | 534 | Helper function (calls other game functions) | pattern | world_event |
| 0x140030940 | 528 | Plays sound; trigger='Biohacker' | pattern | world_event |
| 0x1400bedc0 | 528 | Loop-containing helper | pattern | world_event |
| 0x1400b6610 | 518 | Float math helper | pattern | world_event |
| 0x1402e6d50 | 518 | Loop-containing helper | pattern | world_event |
| 0x1401b52b0 | 517 | Float math helper | pattern | world_event |
| 0x1402d285c | 515 | Struct field accessor; 30 field accesses on param_1 | pattern | world_event |
| 0x1402d2c6c | 515 | Struct field accessor; 30 field accesses on param_1 | pattern | world_event |
| 0x1402d307c | 515 | Struct field accessor; 30 field accesses on param_1 | pattern | world_event |
| 0x1400c8010 | 513 | Batch helper; calls FUN_140075c60 x5 | pattern | save_io |
| 0x1400d8e00 | 511 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402eda40 | 510 | Loop-containing helper | pattern | world_event |
| 0x140111a50 | 508 | Loop-containing helper | pattern | world_event |
| 0x140046e50 | 506 | Loop-containing helper | pattern | world_event |
| 0x1400a9360 | 502 | Float math helper | pattern | world_event |
| 0x1402cfda0 | 502 | Float math helper | pattern | world_event |
| 0x1400a33b0 | 501 | Loop-containing helper | pattern | world_event |
| 0x14009ebd0 | 499 | Loop-containing helper | pattern | world_event |
| 0x140025120 | 497 | Loop-containing helper | pattern | world_event |
| 0x140040ca0 | 497 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400c5d10 | 497 | Loop-containing helper | pattern | world_event |
| 0x1400fd1e0 | 495 | Iterates horse list at obj+0xb8/+0xc0 | pattern | world_event |
| 0x140011000 | 494 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400111f0 | 493 | Loop-containing helper | pattern | world_event |
| 0x1400749b0 | 486 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400a9560 | 486 | Batch helper; calls FUN_1400a9360 x4 | pattern | world_event |
| 0x14005de20 | 485 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400a2ed0 | 485 | Loop-containing helper | pattern | world_event |
| 0x1400ffb10 | 484 | Loop-containing helper | pattern | world_event |
| 0x1402ecb70 | 483 | Loop-containing helper | pattern | world_event |
| 0x1400d6d50 | 482 | Batch helper; calls FUN_1400b6150 x4 | pattern | world_event |
| 0x1402ef434 | 480 | Loop-containing helper | pattern | world_event |
| 0x140111f20 | 477 | Loop-containing helper | pattern | world_event |
| 0x140110a10 | 473 | Loop-containing helper | pattern | world_event |
| 0x14005c9b0 | 472 | Struct field accessor; 13 field accesses on param_1 | pattern | world_event |
| 0x1400aa0d0 | 472 | Float math helper | pattern | world_event |
| 0x1400cd0f0 | 472 | Iterates horse list at obj+0xb8/+0xc0 | pattern | world_event |
| 0x14010d600 | 472 | Batch helper; calls FUN_1400c6940 x4 | pattern | world_event |
| 0x1400a4e00 | 468 | Helper function (calls other game functions) | pattern | debug |
| 0x140037710 | 467 | Helper function (calls other game functions) | pattern | world_event |
| 0x140094810 | 467 | Float math helper | pattern | race |
| 0x1400117d0 | 459 | Loop-containing helper | pattern | world_event |
| 0x1402e06dc | 457 | Struct initializer; zero-inits 10 fields | pattern | world_event |
| 0x140012630 | 456 | Loop-containing helper | pattern | world_event |
| 0x1400c9c30 | 456 | Loop-containing helper | pattern | world_event |
| 0x140048740 | 455 | Float math helper | pattern | world_event |
| 0x1400d6f40 | 455 | Batch helper; calls FUN_1400b6150 x8 | pattern | world_event |
| 0x1401057b0 | 455 | Loop-containing helper | pattern | aging |
| 0x1402dff58 | 455 | Struct initializer; zero-inits 19 fields | pattern | world_event |
| 0x14001d240 | 454 | Float math helper | pattern | world_event |
| 0x1401003e0 | 454 | Loop-containing helper | pattern | world_event |
| 0x140072100 | 453 | Loop-containing helper | pattern | world_event |
| 0x14004cf80 | 452 | Float math helper | pattern | world_event |
| 0x1400cf620 | 451 | Float math helper | pattern | world_event |
| 0x14005d190 | 450 | Loop-containing helper | pattern | world_event |
| 0x1402d7b3c | 449 | Helper function (calls other game functions) | pattern | world_event |
| 0x140006230 | 446 | Loop-containing helper | pattern | world_event |
| 0x1402f0198 | 445 | Loop-containing helper | pattern | world_event |
| 0x140087c70 | 442 | Loop-containing helper | pattern | world_event |
| 0x140110ef0 | 442 | Helper function (calls other game functions) | pattern | world_event |
| 0x140055360 | 441 | Batch helper; calls FUN_14004cb40 x4 | pattern | world_event |
| 0x1402d05a0 | 441 | Batch helper; calls FUN_1402ed0a0 x5 | pattern | world_event |
| 0x1400c7320 | 438 | Loop-containing helper | pattern | world_event |
| 0x1401017d0 | 437 | Loop-containing helper | pattern | world_event |
| 0x1402f0444 | 437 | Loop-containing helper | pattern | world_event |
| 0x14004d710 | 434 | Float math helper | pattern | world_event |
| 0x1402ec028 | 433 | Loop-containing helper | pattern | world_event |
| 0x1400d6b90 | 432 | Loop-containing helper | pattern | world_event |
| 0x14012e880 | 432 | Loop-containing helper | pattern | world_event |
| 0x1402efd94 | 432 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402d1af8 | 431 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400b6cd0 | 430 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400760f0 | 424 | Loop-containing helper | pattern | save_io |
| 0x14004a250 | 423 | Loop-containing helper | pattern | world_event |
| 0x1402eb470 | 421 | Helper function (calls other game functions) | pattern | world_event |
| 0x140064380 | 420 | Loop-containing helper | pattern | race |
| 0x140100230 | 419 | Loop-containing helper | pattern | world_event |
| 0x1400753f0 | 418 | Helper function (calls other game functions) | pattern | world_event |
| 0x14007da00 | 418 | Batch helper; calls FUN_1402f8e20 x5 | pattern | race |
| 0x140071d20 | 417 | Loop-containing helper | pattern | world_event |
| 0x1400b47e0 | 417 | Struct initializer; zero-inits 3 fields | pattern | world_event |
| 0x1400be740 | 416 | Loop-containing helper | pattern | world_event |
| 0x140027c80 | 415 | Batch helper; calls FUN_1402f8e20 x4 | pattern | world_event |
| 0x140049f80 | 411 | Loop-containing helper | pattern | world_event |
| 0x140197820 | 407 | Float math helper | pattern | world_event |
| 0x1402e0a58 | 406 | Struct initializer; zero-inits 15 fields | pattern | world_event |
| 0x1400c8b90 | 404 | Helper function (calls other game functions) | pattern | race |
| 0x14006f840 | 403 | Helper function (calls other game functions) | pattern | save_io |
| 0x14006fb70 | 403 | Helper function (calls other game functions) | pattern | save_io |
| 0x140076550 | 403 | Helper function (calls other game functions) | pattern | save_io |
| 0x140032610 | 402 | Loop-containing helper | pattern | world_event |
| 0x1400c9290 | 400 | Loop-containing helper | pattern | world_event |
| 0x1400d7cd0 | 399 | Batch helper; calls FUN_1400b6150 x4 | pattern | world_event |
| 0x14000fbc0 | 398 | Loop-containing helper | pattern | world_event |
| 0x14006f9e0 | 397 | Helper function (calls other game functions) | pattern | save_io |
| 0x140074da0 | 392 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402d50cc | 391 | Struct field accessor; 11 field accesses on param_1 | pattern | world_event |
| 0x1402cee24 | 390 | Loop-containing helper | pattern | world_event |
| 0x1400d1c40 | 386 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402e6bc0 | 385 | Loop-containing helper | pattern | world_event |
| 0x1400450b0 | 384 | Float math helper | pattern | - |
| 0x1400153e0 | 383 | Loop-containing helper | pattern | world_event |
| 0x140025f00 | 383 | Loop-containing helper | pattern | world_event |
| 0x1400b8420 | 383 | Loop-containing helper | pattern | world_event |
| 0x1400b2ee0 | 382 | Loop-containing helper | pattern | world_event |
| 0x1400d7e60 | 382 | Batch helper; calls FUN_1400b6150 x8 | pattern | world_event |
| 0x140007610 | 381 | Struct initializer; zero-inits 4 fields | pattern | world_event |
| 0x140049e00 | 381 | Loop-containing helper | pattern | world_event |
| 0x14002cd80 | 379 | Plays sound; trigger='Abandoned' | pattern | world_event |
| 0x140100e30 | 379 | Helper function (calls other game functions) | pattern | world_event |
| 0x140071810 | 378 | Loop-containing helper | pattern | world_event |
| 0x140072a10 | 378 | Multi-way switch dispatcher | pattern | world_event |
| 0x140076790 | 378 | Helper function (calls other game functions) | pattern | save_io |
| 0x140163ac0 | 378 | Batch helper; calls FUN_140138fe0 x4 | pattern | world_event |
| 0x1400bf7f0 | 376 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402eff44 | 376 | Helper function (calls other game functions) | pattern | world_event |
| 0x140012a20 | 374 | Float math helper | pattern | world_event |
| 0x14006f6c0 | 373 | Batch helper; calls FUN_1402f8e20 x6 | pattern | save_io |
| 0x1400c4e20 | 373 | Helper function (calls other game functions) | pattern | save_io |
| 0x1402ee300 | 372 | Loop-containing helper | pattern | world_event |
| 0x140027f50 | 369 | Helper function (calls other game functions) | pattern | world_event |
| 0x14006d610 | 368 | Iterates horse list at obj+0xb8/+0xc0 | pattern | save_io |
| 0x140030680 | 366 | Helper function (calls other game functions) | pattern | world_event |
| 0x14000d4e0 | 365 | Struct initializer; zero-inits 3 fields | pattern | world_event |
| 0x140057a60 | 365 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401041f0 | 365 | Struct initializer; zero-inits 4 fields | pattern | world_event |
| 0x14010de70 | 365 | Float math helper | pattern | world_event |
| 0x1402cd188 | 365 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401427d0 | 364 | Helper function (calls other game functions) | pattern | world_event |
| 0x140064060 | 363 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400aaa30 | 363 | Float math helper | pattern | world_event |
| 0x140080cc0 | 362 | Struct initializer; zero-inits 4 fields | pattern | world_event |
| 0x140075120 | 359 | Float math helper | pattern | world_event |
| 0x1400b5fe0 | 357 | Loop-containing helper | pattern | race |
| 0x140016340 | 356 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400924b0 | 356 | Loop-containing helper | pattern | race |
| 0x1402daf2c | 356 | Helper function (calls other game functions) | pattern | world_event |
| 0x140036850 | 352 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401300a0 | 352 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400d1f20 | 350 | Struct field accessor; 10 field accesses on param_1 | pattern | fatigue |
| 0x140027b20 | 348 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400485e0 | 348 | Loop-containing helper | pattern | world_event |
| 0x140074f80 | 348 | Loop-containing helper | pattern | world_event |
| 0x1402cecc8 | 347 | Helper function (calls other game functions) | pattern | world_event |
| 0x14017c930 | 345 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402ebe30 | 345 | Batch helper; calls FUN_1402e68b0 x4 | pattern | world_event |
| 0x1400739e0 | 344 | Float math helper | pattern | world_event |
| 0x140067330 | 343 | Helper function (calls other game functions) | pattern | debug |
| 0x1402c793c | 343 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400d8290 | 342 | Loop-containing helper | pattern | world_event |
| 0x1400be8f0 | 341 | Loop-containing helper | pattern | world_event |
| 0x1400b7770 | 340 | Struct field accessor; 12 field accesses on param_1 | pattern | world_event |
| 0x1400d7190 | 339 | Batch helper; calls FUN_1400b6150 x12 | pattern | world_event |
| 0x140184320 | 339 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402ef840 | 338 | Loop-containing helper | pattern | world_event |
| 0x1400a8890 | 337 | Float math helper | pattern | world_event |
| 0x1400cb760 | 337 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402ceb78 | 336 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400d6a40 | 335 | Iterates horse list at param[0x26]/[0x27] | pattern | save_io |
| 0x14010cd90 | 335 | Loop-containing helper | pattern | world_event |
| 0x140103450 | 334 | Iterates horse list at obj+0xb8/+0xc0 | pattern | world_event |
| 0x140067560 | 333 | Helper function (calls other game functions) | pattern | debug |
| 0x1402ef6f0 | 333 | Loop-containing helper | pattern | world_event |
| 0x140015ae0 | 332 | Float math helper | pattern | world_event |
| 0x140174e70 | 332 | Float math helper | pattern | world_event |
| 0x14004cb40 | 330 | Loop-containing helper | pattern | world_event |
| 0x1402f08b0 | 330 | Multi-way switch dispatcher | pattern | world_event |
| 0x14004ec60 | 328 | Loop-containing helper | pattern | world_event |
| 0x1400409d0 | 326 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400060e0 | 324 | Loop-containing helper | pattern | world_event |
| 0x1400676c0 | 324 | Helper function (calls other game functions) | pattern | debug |
| 0x140055c30 | 323 | Helper function (calls other game functions) | pattern | race |
| 0x14012e110 | 323 | Helper function (calls other game functions) | pattern | world_event |
| 0x140179150 | 323 | Loop-containing helper | pattern | world_event |
| 0x1402eca20 | 323 | Loop-containing helper | pattern | world_event |
| 0x140007dd0 | 321 | Float math helper | pattern | world_event |
| 0x140084370 | 321 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400a2d80 | 321 | Loop-containing helper | pattern | world_event |
| 0x1402e8f40 | 320 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400d8ab0 | 319 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400535f0 | 318 | Struct initializer; zero-inits 3 fields | pattern | world_event |
| 0x140009ca0 | 315 | Struct field accessor; 14 field accesses on param_1 | pattern | world_event |
| 0x1400123b0 | 314 | Loop-containing helper | pattern | world_event |
| 0x140047420 | 314 | Loop-containing helper | pattern | world_event |
| 0x1401c4180 | 314 | Helper function (calls other game functions) | pattern | world_event |
| 0x14006fe60 | 309 | Loop-containing helper | pattern | world_event |
| 0x1400b6e90 | 307 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402e8e00 | 307 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402c6b54 | 306 | Loop-containing helper | pattern | world_event |
| 0x1402f6830 | 304 | Helper function (calls other game functions) | pattern | world_event |
| 0x140007ca0 | 302 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400279c0 | 302 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402c9210 | 302 | Loop-containing helper | pattern | world_event |
| 0x140010010 | 301 | Loop-containing helper | pattern | world_event |
| 0x140071f00 | 301 | Loop-containing helper | pattern | world_event |
| 0x14006f590 | 298 | Helper function (calls other game functions) | pattern | save_io |
| 0x1402d0130 | 298 | Batch helper; calls FUN_1402ece80 x6 | pattern | world_event |
| 0x14004c8a0 | 295 | Batch helper; calls FUN_1402ce36c x4 | pattern | world_event |
| 0x1400184f0 | 294 | Helper function (calls other game functions) | pattern | world_event |
| 0x140047560 | 293 | Helper function (calls other game functions) | pattern | world_event |
| 0x140027540 | 292 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401750b0 | 292 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402e0d04 | 292 | Helper function (calls other game functions) | pattern | world_event |
| 0x140092380 | 290 | Struct field accessor; 21 field accesses on param_1 | pattern | race |
| 0x1401ab630 | 290 | Helper function (calls other game functions) | pattern | world_event |
| 0x140083480 | 289 | Float math helper | pattern | world_event |
| 0x14009c390 | 289 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400b2cd0 | 288 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400c6bd0 | 288 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402eada0 | 286 | Struct initializer; zero-inits 3 fields | pattern | world_event |
| 0x140010310 | 285 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401cb240 | 285 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402ee50c | 285 | Struct initializer; zero-inits 3 fields | pattern | world_event |
| 0x140027e30 | 284 | Helper function (calls other game functions) | pattern | world_event |
| 0x14003e600 | 284 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400447e0 | 284 | Batch helper; calls FUN_1402e9a80 x5 | pattern | - |
| 0x1400b8c60 | 283 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402ee1e4 | 283 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400bf970 | 281 | Helper function (calls other game functions) | pattern | world_event |
| 0x140082430 | 280 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400c57a0 | 277 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402ce36c | 275 | Helper function (calls other game functions) | pattern | world_event |
| 0x140077ae0 | 274 | Helper function (calls other game functions) | pattern | world_event |
| 0x140086450 | 274 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400c6ab0 | 274 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400c7c60 | 274 | Helper function (calls other game functions) | pattern | world_event |
| 0x140071000 | 272 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402f6b8c | 272 | Helper function (calls other game functions) | pattern | world_event |
| 0x140075fd0 | 271 | Helper function (calls other game functions) | pattern | save_io |
| 0x1400c7600 | 270 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402e0948 | 269 | Struct field accessor; 9 field accesses on param_1 | pattern | world_event |
| 0x14005d360 | 267 | Helper function (calls other game functions) | pattern | - |
| 0x1401c7e90 | 267 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400272d0 | 264 | Helper function (calls other game functions) | pattern | world_event |
| 0x140055b20 | 263 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400a9180 | 263 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402ee0dc | 263 | Helper function (calls other game functions) | pattern | world_event |
| 0x140083c30 | 262 | Helper function (calls other game functions) | pattern | world_event |
| 0x140184480 | 262 | Helper function (calls other game functions) | pattern | world_event |
| 0x140005cf0 | 260 | Batch helper; calls FUN_1402e9a80 x5 | pattern | world_event |
| 0x140007f20 | 260 | Helper function (calls other game functions) | pattern | world_event |
| 0x140104df0 | 260 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402ef330 | 260 | Helper function (calls other game functions) | pattern | world_event |
| 0x14006d470 | 259 | Helper function (calls other game functions) | pattern | save_io |
| 0x140072fe0 | 259 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400d1e10 | 259 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401c0ba0 | 259 | Multi-way switch dispatcher | pattern | world_event |
| 0x1401749e0 | 257 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401ab100 | 257 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402e8cf0 | 257 | Helper function (calls other game functions) | pattern | world_event |
| 0x140076910 | 255 | Helper function (calls other game functions) | pattern | save_io |
| 0x1400ab0a0 | 255 | Helper function (calls other game functions) | pattern | world_event |
| 0x140179a30 | 255 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400bf2c0 | 253 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400cfa00 | 253 | Helper function (calls other game functions) | pattern | world_event |
| 0x140092710 | 252 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400b6990 | 252 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400c9e00 | 251 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402ce864 | 250 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400c85f0 | 249 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400457f0 | 247 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402ee95c | 247 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402cf0e0 | 246 | Helper function (calls other game functions) | pattern | world_event |
| 0x14004edb0 | 244 | Struct field accessor; 14 field accesses on param_1 | pattern | world_event |
| 0x1400a6cb0 | 244 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400b6260 | 244 | Helper function (calls other game functions) | pattern | world_event |
| 0x140075a80 | 243 | Helper function (calls other game functions) | pattern | save_io |
| 0x1401746e0 | 242 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402e01d4 | 241 | Struct field accessor; 14 field accesses on param_1 | pattern | world_event |
| 0x140071990 | 239 | Helper function (calls other game functions) | pattern | world_event |
| 0x14004a120 | 236 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400b6890 | 236 | Helper function (calls other game functions) | pattern | world_event |
| 0x140009f80 | 235 | Float math helper | pattern | world_event |
| 0x1400c03a0 | 235 | Helper function (calls other game functions) | pattern | debug |
| 0x140174c40 | 234 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401aa890 | 234 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402ce960 | 234 | Struct field accessor; 8 field accesses on param_1 | pattern | world_event |
| 0x1402d1900 | 234 | Helper function (calls other game functions) | pattern | world_event |
| 0x140197730 | 233 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401c85b0 | 232 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400cb670 | 230 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401a9ef0 | 230 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400b6170 | 229 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401ab3d0 | 229 | Helper function (calls other game functions) | pattern | world_event |
| 0x14005bad0 | 228 | Plays sound; trigger='GifLand' | pattern | world_event |
| 0x140010b00 | 227 | Multi-way switch dispatcher | pattern | world_event |
| 0x14003f590 | 227 | Helper function (calls other game functions) | pattern | - |
| 0x140082550 | 227 | Helper function (calls other game functions) | pattern | world_event |
| 0x140092620 | 227 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402da06c | 227 | Helper function (calls other game functions) | pattern | world_event |
| 0x14009c7d0 | 225 | Helper function (calls other game functions) | pattern | race |
| 0x1400c69c0 | 225 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401acdd0 | 225 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400a32c0 | 224 | Batch helper; calls FUN_1400c6580 x6 | pattern | world_event |
| 0x1402cfa08 | 222 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402f31e0 | 222 | Helper function (calls other game functions) | pattern | world_event |
| 0x140010430 | 220 | Helper function (calls other game functions) | pattern | world_event |
| 0x140075850 | 220 | Helper function (calls other game functions) | pattern | save_io |
| 0x1400762a0 | 220 | Helper function (calls other game functions) | pattern | save_io |
| 0x140100c90 | 220 | Struct field accessor; 8 field accesses on param_1 | pattern | world_event |
| 0x140038f20 | 218 | Helper function (calls other game functions) | pattern | world_event |
| 0x140053730 | 218 | Struct field accessor; 14 field accesses on param_1 | pattern | world_event |
| 0x1400b4a10 | 216 | Float math helper | pattern | world_event |
| 0x1402f66e0 | 216 | Helper function (calls other game functions) | pattern | world_event |
| 0x140107550 | 214 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401c86a0 | 214 | Helper function (calls other game functions) | pattern | world_event |
| 0x14000ce00 | 213 | Struct field accessor; 12 field accesses on param_1 | pattern | world_event |
| 0x140082330 | 213 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402ef618 | 213 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400a5d20 | 212 | Helper function (calls other game functions) | pattern | world_event |
| 0x14004eeb0 | 211 | Struct field accessor; 14 field accesses on param_1 | pattern | world_event |
| 0x1400cf540 | 211 | Helper function (calls other game functions) | pattern | world_event |
| 0x140083b50 | 210 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402d7098 | 210 | Struct field accessor; 20 field accesses on param_1 | pattern | world_event |
| 0x140028820 | 209 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402f6abc | 208 | Helper function (calls other game functions) | pattern | world_event |
| 0x14009c6a0 | 207 | Helper function (calls other game functions) | pattern | world_event |
| 0x140100fc0 | 207 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401979c0 | 207 | Batch helper; calls FUN_140179690 x4 | pattern | world_event |
| 0x1402e6770 | 207 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400874e0 | 205 | Helper function (calls other game functions) | pattern | world_event |
| 0x140104b20 | 205 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401637d0 | 205 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402e9cd4 | 205 | Batch helper; calls FUN_1402f4f90 x4 | pattern | world_event |
| 0x1401c9e50 | 204 | Helper function (calls other game functions) | pattern | world_event |
| 0x14009f350 | 203 | Helper function (calls other game functions) | pattern | world_event |
| 0x14012f790 | 203 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402eebd8 | 203 | Helper function (calls other game functions) | pattern | world_event |
| 0x140027470 | 202 | Helper function (calls other game functions) | pattern | debug |
| 0x14008d2d0 | 202 | Helper function (calls other game functions) | pattern | world_event |
| 0x140025490 | 201 | Helper function (calls other game functions) | pattern | debug |
| 0x1400a9290 | 201 | Float math helper | pattern | world_event |
| 0x14012ef60 | 200 | Helper function (calls other game functions) | pattern | world_event |
| 0x140075320 | 199 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400bf630 | 199 | Destructor / cleanup helper | pattern | world_event |
| 0x1400c7720 | 199 | Destructor / cleanup helper | pattern | world_event |
| 0x140163700 | 199 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401ab560 | 199 | Helper function (calls other game functions) | pattern | world_event |
| 0x140010240 | 198 | Struct field accessor; 11 field accesses on param_1 | pattern | world_event |
| 0x140042de0 | 198 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401b54e0 | 197 | Helper function (calls other game functions) | pattern | world_event |
| 0x140016810 | 196 | Struct field accessor; 13 field accesses on param_1 | pattern | world_event |
| 0x1400bf700 | 195 | Destructor / cleanup helper | pattern | world_event |
| 0x1402da530 | 195 | Helper function (calls other game functions) | pattern | world_event |
| 0x140037420 | 193 | Destructor / cleanup helper | pattern | world_event |
| 0x140067490 | 193 | Helper function (calls other game functions) | pattern | debug |
| 0x1402e9b78 | 193 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400c9f10 | 189 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400c6d00 | 188 | Helper function (calls other game functions) | pattern | world_event |
| 0x14012e790 | 188 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401cbb30 | 188 | Helper function (calls other game functions) | pattern | world_event |
| 0x14004f150 | 187 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402f4ed4 | 186 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401885b0 | 185 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400128b0 | 184 | Struct field accessor; 14 field accesses on param_1 | pattern | world_event |
| 0x140027750 | 184 | Destructor / cleanup helper | pattern | world_event |
| 0x1400dc2d0 | 183 | Destructor / cleanup helper | pattern | fatigue |
| 0x1402d0290 | 183 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400cca50 | 182 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402cd39c | 182 | Destructor / cleanup helper | pattern | world_event |
| 0x1402d7230 | 182 | Struct field accessor; 11 field accesses on param_1 | pattern | world_event |
| 0x1401c9630 | 181 | Batch helper; calls FUN_1401841e0 x10 | pattern | world_event |
| 0x1402e0598 | 181 | Struct field accessor; 12 field accesses on param_1 | pattern | world_event |
| 0x1402e8544 | 181 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400a3200 | 179 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401aaee0 | 179 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402d8ca8 | 179 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400124f0 | 177 | Helper function (calls other game functions) | pattern | world_event |
| 0x140044ff0 | 177 | Helper function (calls other game functions) | pattern | - |
| 0x1402d8a8c | 177 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402ece80 | 177 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400c9fe0 | 176 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402d3908 | 176 | Struct field accessor; 13 field accesses on param_1 | pattern | world_event |
| 0x140005960 | 175 | Struct field accessor; 12 field accesses on param_1 | pattern | world_event |
| 0x1402eaf4c | 175 | Helper function (calls other game functions) | pattern | world_event |
| 0x140067270 | 174 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400b8720 | 174 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400d8d00 | 174 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402e93d0 | 174 | Helper function (calls other game functions) | pattern | world_event |
| 0x14004f0a0 | 173 | Helper function (calls other game functions) | pattern | world_event |
| 0x14006f4e0 | 173 | Struct field accessor; 11 field accesses on param_1 | pattern | save_io |
| 0x140142b00 | 173 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401753d0 | 173 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401aaff0 | 171 | Helper function (calls other game functions) | pattern | world_event |
| 0x140012800 | 170 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402d3580 | 170 | Struct field accessor; 13 field accesses on param_1 | pattern | world_event |
| 0x1400471e0 | 169 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400b2e30 | 169 | Helper function (calls other game functions) | pattern | world_event |
| 0x14009bcc0 | 168 | Destructor / cleanup helper | pattern | world_event |
| 0x1400a8680 | 168 | Struct field accessor; 8 field accesses on param_1 | pattern | world_event |
| 0x1402d1ca8 | 168 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400b85b0 | 167 | Struct field accessor; 11 field accesses on param_1 | pattern | world_event |
| 0x1402c8240 | 167 | Helper function (calls other game functions) | pattern | world_event |
| 0x140081600 | 166 | Helper function (calls other game functions) | pattern | world_event |
| 0x14000cee0 | 165 | Helper function (calls other game functions) | pattern | world_event |
| 0x14006ffa0 | 165 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400bf070 | 165 | Struct initializer; zero-inits 4 fields | pattern | world_event |
| 0x1402ce1e0 | 165 | Helper function (calls other game functions) | pattern | world_event |
| 0x14005e310 | 164 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400641d0 | 164 | Helper function (calls other game functions) | pattern | race |
| 0x1400ca150 | 164 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400262c0 | 163 | Helper function (calls other game functions) | pattern | debug |
| 0x140074460 | 163 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400ce9b0 | 163 | Helper function (calls other game functions) | pattern | world_event |
| 0x140100d80 | 163 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402f0358 | 163 | Helper function (calls other game functions) | pattern | world_event |
| 0x140012970 | 162 | Struct field accessor; 8 field accesses on param_1 | pattern | world_event |
| 0x1401ab7a0 | 162 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402ed0c0 | 162 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402f7f1c | 162 | Helper function (calls other game functions) | pattern | world_event |
| 0x140024b40 | 161 | Struct initializer; zero-inits 3 fields | pattern | world_event |
| 0x1402d185c | 161 | Helper function (calls other game functions) | pattern | save_io |
| 0x140025e00 | 160 | Helper function (calls other game functions) | pattern | world_event |
| 0x14004cee0 | 160 | Helper function (calls other game functions) | pattern | world_event |
| 0x14008d150 | 160 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400aabb0 | 159 | Struct field accessor; 11 field accesses on param_1 | pattern | world_event |
| 0x1402e08a8 | 159 | Struct initializer; zero-inits 7 fields | pattern | world_event |
| 0x140005e10 | 158 | Struct field accessor; 8 field accesses on param_1 | pattern | world_event |
| 0x140075f20 | 158 | Helper function (calls other game functions) | pattern | save_io |
| 0x14008d0a0 | 158 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400c8dc0 | 157 | Helper function (calls other game functions) | pattern | world_event |
| 0x140010c10 | 156 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402d15ac | 156 | Helper function (calls other game functions) | pattern | save_io |
| 0x140087ec0 | 155 | Destructor / cleanup helper | pattern | world_event |
| 0x1400befd0 | 155 | Struct initializer; zero-inits 17 fields | pattern | world_event |
| 0x1400bf150 | 155 | Destructor / cleanup helper | pattern | world_event |
| 0x1400c5580 | 155 | Destructor / cleanup helper | pattern | world_event |
| 0x1402cd300 | 155 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402cdfa0 | 155 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402ce7c8 | 155 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402cea4c | 155 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402eb0c8 | 154 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402eb16c | 154 | Helper function (calls other game functions) | pattern | world_event |
| 0x140037380 | 153 | Destructor / cleanup helper | pattern | world_event |
| 0x1400642e0 | 153 | Destructor / cleanup helper | pattern | world_event |
| 0x140174d30 | 153 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402d72e8 | 153 | Struct field accessor; 12 field accesses on param_1 | pattern | world_event |
| 0x1402ed000 | 153 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402ce288 | 152 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402cf00c | 152 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402db0a8 | 152 | Helper function (calls other game functions) | pattern | debug |
| 0x1400a58b0 | 151 | Destructor / cleanup helper | pattern | world_event |
| 0x1400766f0 | 149 | Destructor / cleanup helper | pattern | world_event |
| 0x140008300 | 148 | Helper function (calls other game functions) | pattern | world_event |
| 0x14000e340 | 148 | Helper function (calls other game functions) | pattern | race |
| 0x140101220 | 148 | Helper function (calls other game functions) | pattern | world_event |
| 0x140174dd0 | 148 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401c5df0 | 148 | Helper function (calls other game functions) | pattern | world_event |
| 0x140075940 | 146 | Helper function (calls other game functions) | pattern | save_io |
| 0x1401c42c0 | 146 | Helper function (calls other game functions) | pattern | world_event |
| 0x140025730 | 145 | Helper function (calls other game functions) | pattern | world_event |
| 0x14009bb10 | 145 | Helper function (calls other game functions) | pattern | world_event |
| 0x140175500 | 145 | Helper function (calls other game functions) | pattern | world_event |
| 0x14012df60 | 144 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401ab340 | 144 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402e86c4 | 144 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402f3150 | 144 | Helper function (calls other game functions) | pattern | world_event |
| 0x14004f010 | 143 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400273e0 | 141 | Helper function (calls other game functions) | pattern | world_event |
| 0x14009f5e0 | 141 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402ceae8 | 141 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402d3e44 | 141 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400c7560 | 140 | Helper function (calls other game functions) | pattern | - |
| 0x1402e1948 | 140 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402e9320 | 140 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402e9480 | 140 | Helper function (calls other game functions) | pattern | world_event |
| 0x140040ee0 | 139 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400d8c70 | 139 | Helper function (calls other game functions) | pattern | world_event |
| 0x14008d200 | 138 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400c5c80 | 138 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402d19ec | 138 | Helper function (calls other game functions) | pattern | world_event |
| 0x14004c9d0 | 137 | Struct initializer; zero-inits 4 fields | pattern | world_event |
| 0x1402eeb50 | 136 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402d0350 | 135 | Float math helper | pattern | world_event |
| 0x14008d760 | 134 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402c8190 | 134 | Helper function (calls other game functions) | pattern | world_event |
| 0x140015560 | 133 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402e0510 | 133 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402d36ec | 132 | Struct field accessor; 13 field accesses on param_1 | pattern | world_event |
| 0x1402d3a7c | 132 | Struct field accessor; 13 field accesses on param_1 | pattern | world_event |
| 0x1400cead0 | 131 | Helper function (calls other game functions) | pattern | world_event |
| 0x140142630 | 131 | Helper function (calls other game functions) | pattern | world_event |
| 0x14004cab0 | 130 | Struct field accessor; 11 field accesses on param_1 | pattern | world_event |
| 0x14006d580 | 129 | Helper function (calls other game functions) | pattern | save_io |
| 0x1400f9b40 | 129 | Helper function (calls other game functions) | pattern | world_event |
| 0x140027810 | 128 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400e35f0 | 128 | Helper function (calls other game functions) | pattern | aging |
| 0x140072f50 | 126 | Helper function (calls other game functions) | pattern | world_event |
| 0x14008fed0 | 126 | Struct initializer; zero-inits 3 fields | pattern | - |
| 0x1400d7110 | 126 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400fb7f0 | 126 | Struct field accessor; 11 field accesses on param_1 | pattern | save_io |
| 0x140142960 | 126 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402e8180 | 126 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400c6e80 | 125 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400c8570 | 125 | Helper function (calls other game functions) | pattern | world_event |
| 0x140112100 | 125 | Helper function (calls other game functions) | pattern | aging |
| 0x1401792e0 | 125 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400125b0 | 124 | Struct field accessor; 10 field accesses on param_1 | pattern | world_event |
| 0x140072e40 | 124 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402d6ad0 | 124 | Struct field accessor; 10 field accesses on param_1 | pattern | world_event |
| 0x14004ef90 | 123 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402c7138 | 123 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400058e0 | 122 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402ce164 | 122 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400727d0 | 120 | Helper function (calls other game functions) | pattern | world_event |
| 0x140072ed0 | 120 | Helper function (calls other game functions) | pattern | debug |
| 0x1400cc9d0 | 120 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401638b0 | 120 | Helper function (calls other game functions) | pattern | world_event |
| 0x14004ce60 | 119 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402e9b00 | 119 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402ecd60 | 119 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402d74e0 | 118 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402d8964 | 118 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400764d0 | 117 | Helper function (calls other game functions) | pattern | save_io |
| 0x140080b00 | 117 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401cba40 | 117 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402f4f90 | 117 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400249e0 | 116 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401cbbf0 | 116 | Plays sound; trigger='DXGIGetDebugInterface' | pattern | world_event |
| 0x1400fb2b0 | 115 | Helper function (calls other game functions) | pattern | race |
| 0x1402f6960 | 115 | Helper function (calls other game functions) | pattern | world_event |
| 0x14004c820 | 114 | Struct field accessor; 11 field accesses on param_1 | pattern | world_event |
| 0x14012f860 | 114 | Helper function (calls other game functions) | pattern | world_event |
| 0x140072640 | 113 | Helper function (calls other game functions) | pattern | world_event |
| 0x140027900 | 112 | Destructor / cleanup helper | pattern | world_event |
| 0x140046de0 | 112 | Helper function (calls other game functions) | pattern | world_event |
| 0x140105730 | 112 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401ab4c0 | 112 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400d8c00 | 111 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401c95c0 | 111 | Struct field accessor; 8 field accesses on param_1 | pattern | world_event |
| 0x1402f8670 | 111 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400743e0 | 109 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400fb8c0 | 109 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402d348c | 109 | Struct field accessor; 13 field accesses on param_1 | pattern | world_event |
| 0x1402d3810 | 109 | Struct field accessor; 13 field accesses on param_1 | pattern | world_event |
| 0x14007b260 | 108 | Struct field accessor; 9 field accesses on param_1 | pattern | world_event |
| 0x1400c6940 | 108 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400267d0 | 107 | Helper function (calls other game functions) | pattern | debug |
| 0x140030810 | 107 | Destructor / cleanup helper | pattern | world_event |
| 0x1400308d0 | 107 | Destructor / cleanup helper | pattern | world_event |
| 0x1400985e0 | 107 | Helper function (calls other game functions) | pattern | race |
| 0x1402cd0d0 | 106 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402d3dd8 | 106 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400285e0 | 105 | Destructor / cleanup helper | pattern | world_event |
| 0x1400a8610 | 104 | Helper function (calls other game functions) | pattern | world_event |
| 0x14003f740 | 103 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400757e0 | 103 | Batch helper; calls FUN_1400764d0 x4 | pattern | save_io |
| 0x140084300 | 103 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400c5680 | 103 | Helper function (calls other game functions) | pattern | world_event |
| 0x140174970 | 103 | Batch helper; calls FUN_1401841e0 x4 | pattern | world_event |
| 0x1402cd068 | 102 | Helper function (calls other game functions) | pattern | world_event |
| 0x14009b740 | 101 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400b6820 | 101 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401c9c60 | 101 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401cbac0 | 101 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400c68d0 | 100 | Helper function (calls other game functions) | pattern | race |
| 0x140163c40 | 100 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402da180 | 100 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402f87d0 | 100 | Helper function (calls other game functions) | pattern | world_event |
| 0x140080680 | 99 | Helper function (calls other game functions) | pattern | world_event |
| 0x140081fa0 | 99 | Helper function (calls other game functions) | pattern | world_event |
| 0x140087e30 | 99 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400a8a00 | 99 | Struct field accessor; 15 field accesses on param_1 | pattern | world_event |
| 0x1400276e0 | 98 | Helper function (calls other game functions) | pattern | debug |
| 0x14012f1a0 | 97 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402cf9a4 | 97 | Helper function (calls other game functions) | pattern | - |
| 0x1402f8700 | 97 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400250c0 | 96 | Struct initializer; zero-inits 4 fields | pattern | world_event |
| 0x1400372c0 | 95 | Destructor / cleanup helper | pattern | genetics |
| 0x14003f2c0 | 95 | Helper function (calls other game functions) | pattern | debug |
| 0x140050a70 | 95 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402f6598 | 95 | Helper function (calls other game functions) | pattern | world_event |
| 0x14003f680 | 93 | Helper function (calls other game functions) | pattern | world_event |
| 0x140070f90 | 92 | Helper function (calls other game functions) | pattern | race |
| 0x14010dd70 | 92 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402ec1dc | 92 | Plays sound; trigger='AppPolicyGetProcessTerminationMethod' | pattern | world_event |
| 0x1402e8754 | 91 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402e8c20 | 90 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400755f0 | 89 | Helper function (calls other game functions) | pattern | save_io |
| 0x1400b35f0 | 89 | Helper function (calls other game functions) | pattern | debug |
| 0x14012dff0 | 89 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401426c0 | 89 | Helper function (calls other game functions) | pattern | world_event |
| 0x14008ff60 | 88 | Helper function (calls other game functions) | pattern | race |
| 0x1401cd800 | 88 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400833d0 | 87 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400256d0 | 86 | Helper function (calls other game functions) | pattern | world_event |
| 0x14003e720 | 86 | Helper function (calls other game functions) | pattern | world_event |
| 0x140175050 | 86 | Helper function (calls other game functions) | pattern | world_event |
| 0x140023f30 | 85 | Helper function (calls other game functions) | pattern | world_event |
| 0x14008cc20 | 85 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401842c0 | 85 | Helper function (calls other game functions) | pattern | world_event |
| 0x140188550 | 85 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402cefac | 85 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402e1bf8 | 85 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402f67d0 | 85 | Helper function (calls other game functions) | pattern | world_event |
| 0x140024a60 | 84 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400257d0 | 84 | Helper function (calls other game functions) | pattern | world_event |
| 0x140064530 | 84 | Destructor / cleanup helper | pattern | race |
| 0x14009c330 | 84 | Destructor / cleanup helper | pattern | world_event |
| 0x140104ac0 | 84 | Helper function (calls other game functions) | pattern | world_event |
| 0x140104f00 | 84 | Helper function (calls other game functions) | pattern | world_event |
| 0x14000b3a0 | 83 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400b49b0 | 83 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402dfea0 | 83 | Helper function (calls other game functions) | pattern | world_event |
| 0x14009bab0 | 82 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400c4340 | 82 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400745d0 | 81 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401747e0 | 81 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402ed930 | 81 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402f8770 | 81 | Helper function (calls other game functions) | pattern | world_event |
| 0x140028310 | 80 | Destructor / cleanup helper | pattern | world_event |
| 0x1401cade0 | 80 | Helper function (calls other game functions) | pattern | world_event |
| 0x14005bf10 | 79 | Helper function (calls other game functions) | pattern | world_event |
| 0x140067850 | 79 | Helper function (calls other game functions) | pattern | world_event |
| 0x14003f7b0 | 78 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400b5f80 | 78 | Helper function (calls other game functions) | pattern | aging |
| 0x1400c5740 | 76 | Helper function (calls other game functions) | pattern | world_event |
| 0x14012f0d0 | 76 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402cd13c | 76 | Helper function (calls other game functions) | pattern | world_event |
| 0x140040980 | 74 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400c56f0 | 74 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402ed9d0 | 74 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400c6180 | 73 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400fb380 | 73 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402eed70 | 73 | Helper function (calls other game functions) | pattern | world_event |
| 0x14004ca60 | 72 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400d8db0 | 72 | Helper function (calls other game functions) | pattern | world_event |
| 0x140009e10 | 71 | Helper function (calls other game functions) | pattern | world_event |
| 0x14000b2a0 | 71 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402c5b14 | 71 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402c5bd4 | 71 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402f03fc | 71 | Helper function (calls other game functions) | pattern | world_event |
| 0x14003f6f0 | 70 | Helper function (calls other game functions) | pattern | - |
| 0x1402c6c88 | 70 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400162f0 | 69 | Helper function (calls other game functions) | pattern | world_event |
| 0x140076480 | 69 | Helper function (calls other game functions) | pattern | save_io |
| 0x140075bd0 | 68 | Helper function (calls other game functions) | pattern | save_io |
| 0x1400509e0 | 67 | Helper function (calls other game functions) | pattern | world_event |
| 0x140075790 | 67 | Helper function (calls other game functions) | pattern | save_io |
| 0x140009e60 | 66 | Helper function (calls other game functions) | pattern | world_event |
| 0x140009eb0 | 66 | Helper function (calls other game functions) | pattern | world_event |
| 0x14000b2f0 | 66 | Helper function (calls other game functions) | pattern | world_event |
| 0x14000b340 | 66 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400755a0 | 66 | Helper function (calls other game functions) | pattern | save_io |
| 0x140025930 | 65 | Helper function (calls other game functions) | pattern | debug |
| 0x140025980 | 65 | Helper function (calls other game functions) | pattern | debug |
| 0x14006fd10 | 65 | Helper function (calls other game functions) | pattern | save_io |
| 0x140075e80 | 65 | Helper function (calls other game functions) | pattern | save_io |
| 0x140080ab0 | 65 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400c65c0 | 65 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400c78c0 | 65 | Helper function (calls other game functions) | pattern | aging |
| 0x140075d50 | 64 | Helper function (calls other game functions) | pattern | save_io |
| 0x140075ed0 | 64 | Helper function (calls other game functions) | pattern | save_io |
| 0x1402175d0 | 64 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402f6a7c | 64 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400410f0 | 63 | Helper function (calls other game functions) | pattern | world_event |
| 0x140075cb0 | 63 | Helper function (calls other game functions) | pattern | save_io |
| 0x1401010d0 | 63 | Helper function (calls other game functions) | pattern | world_event |
| 0x140025320 | 62 | Helper function (calls other game functions) | pattern | world_event |
| 0x140025450 | 62 | Helper function (calls other game functions) | pattern | world_event |
| 0x140075c60 | 62 | Helper function (calls other game functions) | pattern | save_io |
| 0x14000f890 | 61 | Helper function (calls other game functions) | pattern | race |
| 0x140075b80 | 61 | Helper function (calls other game functions) | pattern | save_io |
| 0x14012e730 | 61 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401840e0 | 61 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402ed8c0 | 61 | Helper function (calls other game functions) | pattern | world_event |
| 0x140084570 | 60 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401755c0 | 60 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402e9a80 | 60 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400730f0 | 59 | Helper function (calls other game functions) | pattern | world_event |
| 0x140075e30 | 59 | Helper function (calls other game functions) | pattern | save_io |
| 0x1400c8d30 | 59 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401aaea0 | 59 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401c9760 | 59 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402c704c | 59 | Helper function (calls other game functions) | pattern | world_event |
| 0x140075c20 | 58 | Helper function (calls other game functions) | pattern | save_io |
| 0x140050a30 | 57 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400b7660 | 57 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401429e0 | 57 | Helper function (calls other game functions) | pattern | world_event |
| 0x140040fe0 | 56 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400c6580 | 56 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402f0160 | 56 | Helper function (calls other game functions) | pattern | world_event |
| 0x140027980 | 55 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400c7520 | 55 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402e6fb0 | 55 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402ed990 | 55 | Helper function (calls other game functions) | pattern | world_event |
| 0x14012dec0 | 54 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401aafa0 | 54 | Helper function (calls other game functions) | pattern | world_event |
| 0x14000cdc0 | 53 | Helper function (calls other game functions) | pattern | world_event |
| 0x140040ea0 | 53 | Helper function (calls other game functions) | pattern | world_event |
| 0x140075da0 | 53 | Helper function (calls other game functions) | pattern | save_io |
| 0x1400b7730 | 53 | Helper function (calls other game functions) | pattern | - |
| 0x1402d8374 | 53 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402eeef8 | 53 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402eef64 | 53 | Helper function (calls other game functions) | pattern | world_event |
| 0x14004a210 | 52 | Helper function (calls other game functions) | pattern | world_event |
| 0x14009be60 | 52 | Helper function (calls other game functions) | pattern | world_event |
| 0x140082060 | 51 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401841a0 | 51 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401ab760 | 51 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402e6f60 | 51 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402ebdf0 | 51 | Helper function (calls other game functions) | pattern | world_event |
| 0x140025dc0 | 50 | Helper function (calls other game functions) | pattern | world_event |
| 0x14003ed30 | 50 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400679e0 | 50 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400c66c0 | 50 | Helper function (calls other game functions) | pattern | race |
| 0x140113380 | 50 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401ca4b0 | 50 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400453a0 | 49 | Helper function (calls other game functions) | pattern | - |
| 0x1400a5370 | 49 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401841f0 | 49 | Helper function (calls other game functions) | pattern | world_event |
| 0x140184230 | 49 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402e1c60 | 48 | Helper function (calls other game functions) | pattern | world_event |
| 0x14005c970 | 47 | Helper function (calls other game functions) | pattern | save_io |
| 0x140080b80 | 47 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400a8e00 | 47 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401ab530 | 47 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402e7d80 | 47 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402ec97c | 47 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402ed900 | 47 | Helper function (calls other game functions) | pattern | world_event |
| 0x14009f5a0 | 46 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400a8750 | 45 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401012c0 | 45 | Helper function (calls other game functions) | pattern | save_io |
| 0x1400258d0 | 44 | Helper function (calls other game functions) | pattern | debug |
| 0x140025900 | 44 | Helper function (calls other game functions) | pattern | debug |
| 0x1400c02b0 | 44 | Helper function (calls other game functions) | pattern | debug |
| 0x140174920 | 44 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401c9730 | 44 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402da150 | 44 | Helper function (calls other game functions) | pattern | world_event |
| 0x140066180 | 43 | Helper function (calls other game functions) | pattern | world_event |
| 0x14012e0b0 | 42 | Helper function (calls other game functions) | pattern | world_event |
| 0x14012e0e0 | 42 | Helper function (calls other game functions) | pattern | world_event |
| 0x14012e2e0 | 42 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402eba80 | 42 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402ebdc0 | 42 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402f8d60 | 42 | Helper function (calls other game functions) | pattern | world_event |
| 0x14009e2c0 | 41 | Helper function (calls other game functions) | pattern | - |
| 0x1400fb9c0 | 41 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400c8d90 | 40 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400cf9d0 | 40 | Helper function (calls other game functions) | pattern | race |
| 0x14009c7a0 | 39 | Helper function (calls other game functions) | pattern | debug |
| 0x1400d0c50 | 39 | Helper function (calls other game functions) | pattern | - |
| 0x14012e850 | 39 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400ca0f0 | 38 | Helper function (calls other game functions) | pattern | world_event |
| 0x140040950 | 37 | Helper function (calls other game functions) | pattern | world_event |
| 0x140071120 | 37 | Helper function (calls other game functions) | pattern | debug |
| 0x1402e6840 | 37 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400845c0 | 36 | Helper function (calls other game functions) | pattern | world_event |
| 0x14003f290 | 35 | Helper function (calls other game functions) | pattern | debug |
| 0x140071ed0 | 35 | Helper function (calls other game functions) | pattern | - |
| 0x140179430 | 35 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402e688c | 35 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402e68b0 | 35 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400844c0 | 34 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400c6520 | 34 | Helper function (calls other game functions) | pattern | world_event |
| 0x14010dde0 | 34 | Helper function (calls other game functions) | pattern | save_io |
| 0x14010de10 | 34 | Helper function (calls other game functions) | pattern | save_io |
| 0x14012ee40 | 34 | Helper function (calls other game functions) | pattern | world_event |
| 0x140217520 | 34 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402c5c3c | 34 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402c5c60 | 34 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402e6868 | 34 | Helper function (calls other game functions) | pattern | world_event |
| 0x140024060 | 33 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402c5a60 | 33 | Helper function (calls other game functions) | pattern | world_event |
| 0x14009dd90 | 32 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400c6df0 | 32 | Tiny return-only function | pattern | world_event |
| 0x1402e7d50 | 32 | Tiny return-only function | pattern | world_event |
| 0x1402ecfa0 | 32 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402ed0a0 | 32 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402f86e0 | 32 | Tiny return-only function | pattern | world_event |
| 0x140024090 | 31 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400278e0 | 31 | Helper function (calls other game functions) | pattern | world_event |
| 0x140082010 | 31 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402c5c1c | 31 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402c7c00 | 31 | Helper function (calls other game functions) | pattern | world_event |
| 0x14008d290 | 30 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400b9220 | 30 | Helper function (calls other game functions) | pattern | - |
| 0x14012fd40 | 30 | Tiny return-only function | pattern | world_event |
| 0x140179690 | 30 | Helper function (calls other game functions) | pattern | world_event |
| 0x1401a9ed0 | 30 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402cd454 | 30 | Helper function (calls other game functions) | pattern | world_event |
| 0x140027b00 | 29 | Tiny return-only function | pattern | race |
| 0x14012e770 | 29 | Tiny return-only function | pattern | world_event |
| 0x14012ef10 | 29 | Helper function (calls other game functions) | pattern | world_event |
| 0x140197710 | 29 | Tiny return-only function | pattern | world_event |
| 0x1402e8c00 | 29 | Tiny return-only function | pattern | world_event |
| 0x1402e8cc0 | 29 | Wrapper; single delegated call to FUN_1402e8cc0 | pattern | world_event |
| 0x1400a3610 | 28 | Tiny return-only function | pattern | world_event |
| 0x1400c6120 | 28 | Tiny return-only function | pattern | world_event |
| 0x1400cf970 | 28 | Tiny return-only function | pattern | world_event |
| 0x1400cf9a0 | 28 | Tiny return-only function | pattern | world_event |
| 0x140104dc0 | 28 | Wrapper; single delegated call to FUN_140104dc0 | pattern | world_event |
| 0x140106b90 | 28 | Tiny return-only function | pattern | world_event |
| 0x1402f4460 | 28 | Helper function (calls other game functions) | pattern | world_event |
| 0x14000b270 | 27 | Tiny return-only function | pattern | world_event |
| 0x1400c5530 | 27 | Wrapper; single delegated call to FUN_1400c5530 | pattern | world_event |
| 0x1400c5560 | 27 | Wrapper; single delegated call to FUN_1400c5560 | pattern | world_event |
| 0x1402c6a38 | 27 | Tiny return-only function | pattern | - |
| 0x1402f0dec | 25 | Tiny return-only function | pattern | world_event |
| 0x1402e8664 | 24 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402f05fc | 24 | Tiny return-only function | pattern | world_event |
| 0x1402f0e08 | 24 | Tiny return-only function | pattern | world_event |
| 0x140082410 | 23 | Tiny return-only function | pattern | debug |
| 0x1400b4990 | 23 | Tiny return-only function | pattern | race |
| 0x1400cf950 | 23 | Helper function (calls other game functions) | pattern | world_event |
| 0x140075750 | 22 | Helper function (calls other game functions) | pattern | save_io |
| 0x1402cd4c0 | 22 | Tiny return-only function | pattern | world_event |
| 0x1402d0770 | 22 | Tiny return-only function | pattern | world_event |
| 0x140072ca0 | 21 | Tiny return-only function | pattern | world_event |
| 0x140072cc0 | 21 | Tiny return-only function | pattern | world_event |
| 0x140075770 | 21 | Helper function (calls other game functions) | pattern | save_io |
| 0x1400a53b0 | 21 | Tiny return-only function | pattern | world_event |
| 0x1402c5ac0 | 21 | Tiny return-only function | pattern | world_event |
| 0x1402ebf8c | 21 | Wrapper; single delegated call to FUN_1402ebf8c | pattern | world_event |
| 0x1400756b0 | 20 | Helper function (calls other game functions) | pattern | save_io |
| 0x1400756d0 | 20 | Helper function (calls other game functions) | pattern | save_io |
| 0x1400c6500 | 20 | Wrapper; single delegated call to FUN_1400c6500 | pattern | debug |
| 0x140174040 | 20 | Wrapper; single delegated call to FUN_140174040 | pattern | world_event |
| 0x1402f7fc8 | 20 | Tiny return-only function | pattern | world_event |
| 0x14005cda0 | 19 | Tiny return-only function | pattern | world_event |
| 0x140075670 | 19 | Helper function (calls other game functions) | pattern | save_io |
| 0x140075690 | 19 | Helper function (calls other game functions) | pattern | save_io |
| 0x140075710 | 19 | Helper function (calls other game functions) | pattern | save_io |
| 0x140075730 | 19 | Helper function (calls other game functions) | pattern | save_io |
| 0x140174fc0 | 19 | Tiny return-only function | pattern | world_event |
| 0x1402e9080 | 19 | Tiny return-only function | pattern | world_event |
| 0x1400082e0 | 18 | Helper function (calls other game functions) | pattern | world_event |
| 0x14005e210 | 18 | Tiny return-only function | pattern | world_event |
| 0x14005e230 | 18 | Tiny return-only function | pattern | aging |
| 0x14005e250 | 18 | Tiny return-only function | pattern | world_event |
| 0x14005e270 | 18 | Tiny return-only function | pattern | aging |
| 0x140110750 | 18 | Tiny return-only function | pattern | save_io |
| 0x1402e93b0 | 18 | Helper function (calls other game functions) | pattern | world_event |
| 0x14002cca0 | 17 | Helper function (calls other game functions) | pattern | world_event |
| 0x140040fc0 | 17 | Wrapper; single delegated call to FUN_140040fc0 | pattern | race |
| 0x14009c780 | 17 | Wrapper; single delegated call to FUN_14009c780 | pattern | world_event |
| 0x1400c5f10 | 17 | Tiny return-only function | pattern | world_event |
| 0x1400c5f30 | 17 | Tiny return-only function | pattern | world_event |
| 0x1400c5f50 | 17 | Tiny return-only function | pattern | world_event |
| 0x1400c5f70 | 17 | Tiny return-only function | pattern | world_event |
| 0x1400ca240 | 17 | Wrapper; single delegated call to FUN_1400ca240 | pattern | - |
| 0x14017ffb0 | 17 | Tiny return-only function | pattern | world_event |
| 0x1402e16a0 | 17 | Tiny return-only function | pattern | world_event |
| 0x1402eda20 | 17 | Tiny return-only function | pattern | world_event |
| 0x140024130 | 16 | Helper function (calls other game functions) | pattern | world_event |
| 0x14002f0d0 | 16 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400478f0 | 16 | Helper function (calls other game functions) | pattern | world_event |
| 0x140067e30 | 16 | Tiny return-only function | pattern | - |
| 0x1400b76a0 | 16 | Tiny return-only function | pattern | - |
| 0x1400bc560 | 16 | Wrapper; single delegated call to FUN_1400bc560 | pattern | world_event |
| 0x1400bf7d0 | 16 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400c4320 | 16 | Wrapper; single delegated call to FUN_1400c4320 | pattern | world_event |
| 0x140086310 | 15 | Tiny return-only function | pattern | - |
| 0x1400c6550 | 15 | Wrapper; single delegated call to FUN_1400c6550 | pattern | world_event |
| 0x1400cd560 | 15 | Helper function (calls other game functions) | pattern | race |
| 0x14009c320 | 14 | Wrapper; single delegated call to FUN_14009c320 | pattern | world_event |
| 0x140138fe0 | 14 | Wrapper; single delegated call to FUN_140138fe0 | pattern | world_event |
| 0x1401492f0 | 14 | Helper function (calls other game functions) | pattern | world_event |
| 0x140075650 | 13 | Tiny return-only function | pattern | save_io |
| 0x1400c42f0 | 13 | Wrapper; single delegated call to FUN_1400c42f0 | pattern | debug |
| 0x140179b30 | 13 | Wrapper; single delegated call to FUN_140179b30 | pattern | world_event |
| 0x140179b40 | 13 | Wrapper; single delegated call to FUN_140179b40 | pattern | world_event |
| 0x140179b60 | 13 | Wrapper; single delegated call to FUN_140179b60 | pattern | world_event |
| 0x14017ca90 | 13 | Wrapper; single delegated call to FUN_14017ca90 | pattern | world_event |
| 0x14017caa0 | 13 | Wrapper; single delegated call to FUN_14017caa0 | pattern | world_event |
| 0x14017cab0 | 13 | Wrapper; single delegated call to FUN_14017cab0 | pattern | world_event |
| 0x14017cae0 | 13 | Wrapper; single delegated call to FUN_14017cae0 | pattern | world_event |
| 0x1401841e0 | 13 | Wrapper; single delegated call to FUN_1401841e0 | pattern | world_event |
| 0x140188670 | 13 | Wrapper; single delegated call to FUN_140188670 | pattern | world_event |
| 0x1402e8ce0 | 13 | Tiny return-only function | pattern | world_event |
| 0x1400b6150 | 12 | Wrapper; single delegated call to FUN_1400b6150 | pattern | world_event |
| 0x1400cd580 | 12 | Helper function (calls other game functions) | pattern | debug |
| 0x140163ab0 | 12 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402da20c | 12 | Helper function (calls other game functions) | pattern | world_event |
| 0x1400b4af0 | 11 | Tiny return-only function | pattern | world_event |
| 0x140138fc0 | 11 | Tiny return-only function | pattern | world_event |
| 0x1402c7c2c | 11 | Wrapper; single delegated call to FUN_1402c7c2c | pattern | world_event |
| 0x1402ce0f8 | 11 | Wrapper; single delegated call to FUN_1402ce0f8 | pattern | world_event |
| 0x1402e1710 | 11 | Wrapper; single delegated call to FUN_1402e1710 | pattern | world_event |
| 0x1402e171c | 11 | Wrapper; single delegated call to FUN_1402e171c | pattern | world_event |
| 0x1400b7720 | 10 | Tiny return-only function | pattern | world_event |
| 0x1400c4de0 | 10 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402da254 | 10 | Helper function (calls other game functions) | pattern | world_event |
| 0x1402e8ca0 | 10 | Tiny return-only function | pattern | world_event |
| 0x1402e8cb0 | 10 | Wrapper; single delegated call to FUN_1402e8cb0 | pattern | world_event |
| 0x1402ec3b0 | 10 | Wrapper; single delegated call to FUN_1402ec3b0 | pattern | world_event |
| 0x140009de0 | 9 | Getter; returns field at +0xb4 | pattern | world_event |
| 0x140009df0 | 9 | Getter; returns field at +0xb8 | pattern | world_event |
| 0x1402e90a0 | 9 | Tiny return-only function | pattern | world_event |
| 0x1402f5700 | 9 | Tiny return-only function | pattern | world_event |
| 0x140005e00 | 8 | Empty stub (likely a ret) | pattern | world_event |
| 0x140009e00 | 8 | Empty stub (likely a ret) | pattern | world_event |
| 0x14000b290 | 8 | Empty stub (likely a ret) | pattern | world_event |
| 0x14000b390 | 8 | Empty stub (likely a ret) | pattern | world_event |
| 0x140023ec0 | 8 | Empty stub (likely a ret) | pattern | - |
| 0x140023ed0 | 8 | Empty stub (likely a ret) | pattern | world_event |
| 0x140086330 | 8 | Empty stub (likely a ret) | pattern | world_event |
| 0x14008d2c0 | 8 | Empty stub (likely a ret) | pattern | world_event |
| 0x1400a89f0 | 8 | Empty stub (likely a ret) | pattern | world_event |
| 0x1400b7650 | 8 | Empty stub (likely a ret) | pattern | world_event |
| 0x1400c42e0 | 8 | Empty stub (likely a ret) | pattern | debug |
| 0x1400c4310 | 8 | Empty stub (likely a ret) | pattern | debug |
| 0x1400c43c0 | 8 | Empty stub (likely a ret) | pattern | world_event |
| 0x1400c4df0 | 8 | Empty stub (likely a ret) | pattern | save_io |
| 0x1400c4e00 | 8 | Empty stub (likely a ret) | pattern | debug |
| 0x1400c5c20 | 8 | Empty stub (likely a ret) | pattern | world_event |
| 0x1400c5c30 | 8 | Empty stub (likely a ret) | pattern | world_event |
| 0x1400c6570 | 8 | Empty stub (likely a ret) | pattern | world_event |
| 0x1401745e0 | 8 | Empty stub (likely a ret) | pattern | world_event |
| 0x1402c6cd0 | 8 | Empty stub (likely a ret) | pattern | - |
| 0x1402f7fc0 | 8 | Empty stub (likely a ret) | pattern | world_event |
| 0x14003f330 | 7 | Empty stub (likely a ret) | pattern | - |
| 0x140138fb0 | 7 | Empty stub (likely a ret) | pattern | world_event |
| 0x1402e7d34 | 7 | Empty stub (likely a ret) | pattern | world_event |
| 0x1400c5c00 | 5 | Empty stub (likely a ret) | pattern | world_event |
| 0x1400c5c10 | 5 | Empty stub (likely a ret) | pattern | world_event |
| 0x140139010 | 5 | Empty stub (likely a ret) | pattern | world_event |
| 0x1402c7088 | 5 | Empty stub (likely a ret) | pattern | world_event |
| 0x1402eba70 | 5 | Empty stub (likely a ret) | pattern | world_event |
| 0x1400734c0 | 3 | Empty stub (likely a ret) | pattern | world_event |
| 0x1400bcaf0 | 3 | Empty stub (likely a ret) | pattern | world_event |
| 0x1400c8d80 | 3 | Empty stub (likely a ret) | pattern | world_event |