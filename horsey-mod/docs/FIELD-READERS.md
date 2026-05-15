# Horse-struct field readers

Auto-derived from `research/decompiled/all_functions.c` by
`research/extract-field-readers.py`. For each of the 23
direct-copy offsets the consumer `FUN_1400ab3d0` writes,
this lists every other function that reads that offset off
a pointer. Consumer itself excluded.

Caveat: matches any `*(T*)(var + 0xNN)` pattern, so non-horse
structs with the same offset will produce false positives.
Filter by function name / call chain when classifying.

## `+0x58` (88 dec)

165 functions, 245 read sites.

| Function | Hits | First line | First snippet |
|---|---|---|---|
| `FUN_140043c60` | 8 | 75544 | `*(undefined1 *)(*(longlong *)(DAT_1403ea2a8 + 0x58) + 9) = 0;` |
| `FUN_140219730` | 7 | 748664 | `uVar6 = (**(code **)(lVar2 + 0x58))("eglQueryDevicesEXT");` |
| `FUN_1400450b0` | 6 | 76948 | `*(undefined4 *)(*(longlong *)(DAT_1403ea2a8 + 0x58) + 0xc);` |
| `FUN_1401b9390` | 6 | 619030 | `(*(longlong *)(param_2 + 0x58) + 0x28 + uVar3 * 0x50) + 0x48) +` |
| `FUN_1401c9cd0` | 5 | 641780 | `FUN_1401cade0(*(longlong *)(lVar1 + 0x58) + 0x28);` |
| `FUN_1401caf50` | 5 | 643454 | `FUN_1401cade0(*(longlong *)(lVar5 + 0x58) + 0x28);` |
| `FUN_14000fbc0` | 4 | 13198 | `if ((*(byte *)(*(longlong *)(param_1 + 0x58) + 0x19298) & 2) != 0) {` |
| `FUN_140010010` | 4 | 13524 | `if ((*(byte *)(*(longlong *)(param_1 + 0x58) + 0x19298) & 2) != 0) {` |
| `FUN_140157f50` | 4 | 459724 | `*param_3 = *(undefined4 *)(*(longlong *)(param_1 + 0x58) + (longlong)param_2 * 8);` |
| `FUN_140010140` | 3 | 13608 | `if ((*(byte *)(*(longlong *)(param_1 + 0x58) + 0x19298) & 2) != 0) {` |
| `FUN_140010310` | 3 | 13734 | `if ((*(byte *)(*(longlong *)(param_1 + 0x58) + 0x19298) & 2) != 0) {` |
| `FUN_1400113e0` | 3 | 15352 | `*(undefined8 *)(lVar13 + 0x18) = *(undefined8 *)(param_1 + 0x58);` |
| `FUN_14003f590` | 3 | 69448 | `if (*(longlong *)(DAT_1403ea2a8 + 0x58) != 0) {` |
| `FUN_140209e50` | 3 | 725026 | `lVar1 = *(longlong *)(lVar2 + 0x58);` |
| `FUN_140010430` | 2 | 13834 | `if ((*(byte *)(*(longlong *)(param_1 + 0x58) + 0x19298) & 2) != 0) {` |
| `FUN_14002b180` | 2 | 47610 | `if (uVar2 < *(ulonglong *)(param_1 + 0x58)) {` |
| `FUN_14003ee40` | 2 | 68836 | `if (*(longlong *)(DAT_1403ea2a8 + 0x58) != 0) {` |
| `FUN_14003f2c0` | 2 | 69198 | `if (*(longlong *)(DAT_1403ea2a8 + 0x58) != 0) {` |
| `FUN_14003f740` | 2 | 69576 | `if (*(longlong *)(DAT_1403ea2a8 + 0x58) != 0) {` |
| `FUN_14003f7b0` | 2 | 69616 | `if (*(longlong *)(DAT_1403ea2a8 + 0x58) != 0) {` |
| `FUN_140042950` | 2 | 74152 | `if ((*(uint *)(param_1 + 0x58) < 0x10000) \|\|` |
| `FUN_140045310` | 2 | 77062 | `if (*(longlong *)(DAT_1403ea2a8 + 0x58) != 0) {` |
| `FUN_1400453a0` | 2 | 77092 | `if (*(longlong *)(DAT_1403ea2a8 + 0x58) != 0) {` |
| `FUN_1400453e0` | 2 | 77230 | `*(undefined1 *)(*(longlong *)(DAT_1403ea2a8 + 0x58) + 9) = 0;` |
| `FUN_1400455f0` | 2 | 77346 | `*(undefined1 *)(*(longlong *)(DAT_1403ea2a8 + 0x58) + 9) = 0;` |
| `FUN_140046320` | 2 | 78144 | `if (*(longlong *)(DAT_1403ea2a8 + 0x58) != 0) {` |
| `FUN_14004f210` | 2 | 91666 | `if (*(uint *)(param_1 + 0x58) < (int)uVar25 - 0x19U) break;` |
| `FUN_1400df280` | 2 | 257330 | `if (*(char *)(lVar9 + 0x58) != '\0') {` |
| `FUN_1400e0aa0` | 2 | 259380 | `fVar4 = *(float *)(lVar13 + 0x58);` |
| `FUN_1400fbae0` | 2 | 295888 | `for (lVar9 = *(longlong *)(lVar9 + 0x10); lVar9 != 0; lVar9 = *(longlong *)(lVar9 + 0x58)) {` |
| `FUN_140107660` | 2 | 310742 | `uVar27 = *(ulonglong *)(uVar27 + 0x58)) {` |
| `FUN_140147e50` | 2 | 438022 | `FUN_140146010(*(undefined8 *)(*(longlong *)(param_1 + 0x58) + lVar2));` |
| `FUN_140161f10` | 2 | 476228 | `if ((*(char *)(lVar6 + 0xe0) != '\0') && (*(code **)(lVar6 + 0x58) != (code *)0x0)) {` |
| `FUN_14016fc90` | 2 | 496986 | `if ((*(code **)(lVar7 + 0x58) != (code *)0x0) && (*(longlong *)(param_1 + 0x10) != 0)) {` |
| `FUN_1401e2180` | 2 | 673922 | `if (*(longlong **)(lVar1 + 0x58) != (longlong *)0x0) {` |
| `FUN_1401e7cc0` | 2 | 681588 | `if (*(longlong **)(lVar1 + 0x58) != (longlong *)0x0) {` |
| `FUN_140219030` | 2 | 747654 | `if (((0x10004 < uVar3) && (*(code **)(lVar2 + 0x58) != (code *)0x0)) &&` |
| `FUN_14022afa0` | 2 | 773710 | `if (((*(uint *)(param_2 + 0x48) >> 0x1e & 1) != 0) && (*(longlong *)(lVar1 + 0x58) != 0)) {` |
| `FUN_1402706d0` | 2 | 918626 | `if (*(longlong *)(lVar1 + 0x58) + 500U <= uVar4) {` |
| `FUN_1402897c0` | 2 | 951898 | `if ((((param_2 != 0) && (param_1 != 0)) && (*(longlong **)(param_1 + 0x58) != (longlong *)0x0)) &&` |
| `FUN_140289c70` | 2 | 952356 | `if ((param_1 != 0) && (*(undefined8 **)(param_1 + 0x58) != (undefined8 *)0x0)) {` |
| `FUN_140289c90` | 2 | 952378 | `if ((param_1 != 0) && (*(longlong *)(param_1 + 0x58) != 0)) {` |
| `FUN_1402c8bd4` | 2 | 1035744 | `if (param_1 < *(undefined8 **)(lVar1 + 0x58)) {` |
| `FUN_1402c8dfc` | 2 | 1035790 | `if (param_1 == *(longlong *)(lVar2 + 0x58)) {` |
| `FUN_14000d3c0` | 1 | 10400 | `puVar1[0xb] = *(undefined8 *)(param_1 + 0x58);` |
| `FUN_140010240` | 1 | 13692 | `lVar2 = *(longlong *)(param_1 + 0x58);` |
| `FUN_140011000` | 1 | 14810 | `if (param_2 == *(longlong *)(param_1 + 0x58)) {` |
| `FUN_1400111f0` | 1 | 14966 | `lVar11 = *(longlong *)(param_1 + 0x58);` |
| `FUN_140016810` | 1 | 21770 | `(*(float *)(param_1 + 0x58) - *(float *)(param_1 + 0x10)));` |
| `FUN_140016c70` | 1 | 22166 | `fStack_118 = *(float *)(param_3 + 0x58);` |
| `FUN_1400248b0` | 1 | 36796 | `if (0xf < *(ulonglong *)(param_1 + 0x58)) {` |
| `FUN_1400256d0` | 1 | 38484 | `if (*(ulonglong *)(lVar3 + 0x58) < 0x10) {` |
| `FUN_140025730` | 1 | 38566 | `if (0xf < *(ulonglong *)(lVar3 + 0x58)) {` |
| `FUN_1400257d0` | 1 | 38624 | `if (0xf < *(ulonglong *)(lVar2 + 0x58)) {` |
| `FUN_140025830` | 1 | 38710 | `if (0xf < *(ulonglong *)(lVar3 + 0x58)) {` |
| `FUN_140025bc0` | 1 | 39090 | `if (0xf < *(ulonglong *)(lVar5 + 0x58)) {` |
| `FUN_140026610` | 1 | 40118 | `if (0xf < *(ulonglong *)(param_1 + 0x58)) {` |
| `FUN_14003f680` | 1 | 69504 | `if ((DAT_1403ea290 == '\0') \|\| (lVar1 = *(longlong *)(DAT_1403ea2a8 + 0x58), lVar1 == 0)) {` |
| `FUN_140045c20` | 1 | 77954 | `if ((lVar1 != *(longlong *)(lVar2 + 0x58)) && (lVar1 != *(longlong *)(lVar2 + 0x60))) {` |
| `FUN_140054a60` | 1 | 99798 | `if (*(uint *)(param_1 + 0x58) < iVar21 - 0x19U) {` |
| `FUN_140060a80` | 1 | 112300 | `if (*(char *)(lVar5 + 0x58) != '\0') {` |
| `FUN_140082640` | 1 | 152648 | `lVar4 = *(longlong *)(lVar4 + 0x58)) {` |
| `FUN_140083c30` | 1 | 153990 | `FUN_1400060e0(*(undefined8 *)(param_1 + 0x58),local_78);` |
| `FUN_140083d40` | 1 | 154084 | `FUN_1400060e0(*(undefined8 *)(param_1 + 0x58),local_68);` |
| `FUN_140083e10` | 1 | 154188 | `FUN_1400060e0(*(undefined8 *)(param_1 + 0x58),local_98);` |
| `FUN_1400b47e0` | 1 | 208414 | `FUN_140005eb0(*(undefined8 *)(lVar2 + 0x58),lVar2);` |
| `FUN_1400b6fd0` | 1 | 211710 | `local_c0 = *(undefined8 *)(lVar3 + 0x58);` |
| `FUN_1400b7770` | 1 | 212274 | `uVar5 = *(undefined8 *)(lVar4 + 0x58);` |
| `FUN_1400b7fe0` | 1 | 213050 | `FUN_140006230(*(undefined8 *)(lVar8 + 0x58));` |
| `FUN_1400be730` | 1 | 219618 | `*param_2 = *(undefined4 *)(param_1 + 0x58);` |
| `FUN_1400bea50` | 1 | 219990 | `*(undefined8 *)(puVar8 + 0x13) = *(undefined8 *)(lVar10 + 0x58);` |
| `FUN_1400dde40` | 1 | 256860 | `if (*pfVar12 <= *(float *)(lVar7 + 0x58) * DAT_14039ca34 + fVar22) {` |
| `FUN_140101dc0` | 1 | 303512 | `uVar1 = *(ulonglong *)(uVar1 + 0x58)) {` |
| `FUN_140102060` | 1 | 303880 | `uVar15 = *(ulonglong *)(uVar15 + 0x58);` |
| `FUN_140102860` | 1 | 304188 | `lVar1 = *(longlong *)(lVar1 + 0x58)) {` |
| `FUN_1401029c0` | 1 | 304302 | `lVar2 = *(longlong *)(lVar2 + 0x58);` |
| `FUN_140110bf0` | 1 | 320268 | `iVar26 = *(int *)(lVar25 + 0x58);` |
| `FUN_140111a50` | 1 | 322532 | `iVar8 = *(int *)(lVar11 + 0x58);` |
| `FUN_140131930` | 1 | 403576 | `uVar1 = *(undefined4 *)(param_1 + 0x58);` |
| `FUN_140142ea0` | 1 | 431292 | `lVar4 = FUN_140184230(*(undefined8 *)(param_1 + 0x58),(longlong)*(int *)(param_1 + 0x50) * 8 + 8);` |
| `FUN_1401452e0` | 1 | 434826 | `uVar2 = *(undefined8 *)(*(longlong *)(param_1 + 0x58) + uVar19);` |
| `FUN_140146ad0` | 1 | 436430 | `FUN_1402f8e20(plVar3 + 1,*(undefined8 *)(param_1 + 0x58),` |
| `FUN_14014a7b0` | 1 | 442312 | `pcVar6 = *(code **)(param_1 + 0x58);` |
| `FUN_14014ac90` | 1 | 442406 | `cVar1 = (**(code **)(param_1 + 0x58))` |
| `FUN_14014e660` | 1 | 447386 | `*param_2 = *(undefined4 *)(lVar1 + 0x58);` |
| `FUN_1401575b0` | 1 | 458840 | `FUN_1401841e0(*(undefined8 *)(param_1 + 0x58));` |
| `FUN_1401648f0` | 1 | 480110 | `lVar1 = FUN_140214330((int)((float)param_2 * *(float *)(param_1 + 0x58)),` |
| `FUN_14016a4b0` | 1 | 487762 | `if (fVar1 != *(float *)(param_1 + 0x58)) {` |
| `FUN_14016d370` | 1 | 492038 | `return *(undefined4 *)(lVar1 + 0x58);` |
| `FUN_14016e050` | 1 | 493552 | `return *(undefined4 *)(param_1 + 0x58);` |
| `FUN_140170ff0` | 1 | 498614 | `uVar2 = (**(code **)(DAT_1403fc410 + 0x58))(DAT_1403fc410,param_1,lVar3);` |
| `FUN_140176ce0` | 1 | 507700 | `(**(code **)(*(longlong *)(param_1 + 0x58) + 0x48))(param_1);` |
| `FUN_1401777e0` | 1 | 508768 | `(**(code **)(*(longlong *)(lVar1 + 0x58) + 0x40))(lVar1);` |
| `FUN_140177c50` | 1 | 509166 | `uVar1 = (**(code **)(param_1 + 0x58))(*(undefined8 *)(param_1 + 0x60));` |
| `FUN_140188750` | 1 | 536304 | `uVar10 = *(ulonglong *)(param_1 + 0x58);` |
| `FUN_140188f70` | 1 | 537192 | `local_res8 = *(ulonglong *)(param_1 + 0x58);` |
| `FUN_140189320` | 1 | 537580 | `uVar7 = *(ulonglong *)(param_1 + 0x58);` |
| `FUN_140189b70` | 1 | 538380 | `local_res8 = *(ulonglong *)(param_1 + 0x58);` |
| `FUN_140189ca0` | 1 | 538518 | `local_res8 = *(ulonglong *)(param_1 + 0x58);` |
| `FUN_1401b8810` | 1 | 618000 | `FUN_140179b30(*(undefined8 *)(lVar1 + 0x58));` |
| `FUN_1401beac0` | 1 | 627116 | `if ((*(int *)(param_1 + 0x58) != 0) && (*(int *)(param_2 + 0x58) == 0)) {` |
| `FUN_1401cba40` | 1 | 644512 | `(**(code **)(**(longlong **)(param_1 + 0x58) + 0x18))();` |
| `FUN_1401e3ba0` | 1 | 676318 | `local_b8[uVar4 + 1] = *(longlong *)(lVar2 + 0x58);` |
| `FUN_1401e8a10` | 1 | 682884 | `(*(longlong **)(lVar1 + 0x28),*(undefined4 *)(lVar1 + 0x58),` |
| `FUN_1401e9660` | 1 | 683894 | `FUN_1401ea070(uVar4,*(undefined8 *)(lVar3 + 0x58),*(undefined4 *)(lVar3 + 0x68),0x80);` |
| `FUN_1401eab10` | 1 | 685602 | `uVar4 = FUN_1401ea670(lVar2,*(undefined8 *)(lVar1 + 0x58),0,*param_3 / 2,param_3[1] / 2,` |
| `FUN_1401ee270` | 1 | 689550 | `(**(code **)(lVar2 + 0x58))(0x4000);` |
| `FUN_1401f0390` | 1 | 691698 | `uVar4 = (**(code **)(param_1 + 0x58))();` |
| `FUN_1401fd130` | 1 | 707448 | `*param_4 = *(undefined8 *)(lVar2 + 0x58);` |
| `FUN_140202ca0` | 1 | 715064 | `if ((*(char *)(lVar6 + 0x40) != '\0') \|\| (*(char *)(lVar6 + 0x58) != '\0')) {` |
| `FUN_140202fc0` | 1 | 715202 | `FUN_140137fd0(*(undefined8 *)(param_1 + 8),*(undefined8 *)(param_1 + 0x58));` |
| `FUN_140203060` | 1 | 715446 | `if (*(char *)(lVar6 + 0x58) != '\0') {` |
| `FUN_140203a80` | 1 | 716258 | `if (*(longlong *)(pcVar1 + 0x58) != 0) {` |
| `FUN_140204140` | 1 | 716760 | `local_78 = *(undefined8 *)(lVar1 + 0x58);` |
| `FUN_140204280` | 1 | 716902 | `local_res8 = *(undefined8 *)(lVar3 + 0x58);` |
| `FUN_1402045a0` | 1 | 717150 | `lVar7 = *(longlong *)(lVar3 + 0x58);` |
| `FUN_140207eb0` | 1 | 721856 | `uVar3 = *(undefined4 *)(lVar1 + 0x58);` |
| `FUN_1402090f0` | 1 | 723682 | `lVar1 = *(longlong *)(lVar1 + 0x58);` |
| `FUN_140209f60` | 1 | 725142 | `lVar1 = *(longlong *)(lVar1 + 0x58);` |
| `FUN_14020a140` | 1 | 725262 | `lVar1 = *(longlong *)(lVar1 + 0x58);` |
| `FUN_14020ad80` | 1 | 726618 | `cVar10 = *(char *)(lVar3 + 0x58) + '\x01';` |
| `FUN_14020fa10` | 1 | 733320 | `*param_1 = *(undefined8 *)(lVar2 + 0x58);` |
| `FUN_140216540` | 1 | 743530 | `uVar6 = *(undefined8 *)(param_1 + 0x58);` |
| `FUN_140225c60` | 1 | 766582 | `uVar10 = *(undefined4 *)(param_3 + 0x58);` |
| `FUN_140226360` | 1 | 767162 | `param_6[3] = *(undefined4 *)(pWVar3 + 0x58);` |
| `FUN_140227940` | 1 | 769302 | `uVar13 = (ulonglong)(*(float *)(lVar3 + 0x58) * DAT_140304040);` |
| `FUN_140272660` | 1 | 921012 | `*(undefined2 *)(param_2 + 0x30) = *(undefined2 *)(lVar1 + 0x58);` |
| `FUN_1402783e0` | 1 | 928836 | `if ((*(ulonglong *)(lVar1 + 0x58) != 0) && (*(ulonglong *)(lVar1 + 0x58) <= uVar5)) {` |
| `FUN_14027c000` | 1 | 934218 | `else if ((uVar2 == 0x90001) && (local_58[0] != *(uint *)(param_2 + 0x58))) {` |
| `FUN_14027d570` | 1 | 936084 | `uVar3 = *(undefined8 *)(param_2 + 0x58);` |
| `FUN_140289960` | 1 | 952070 | `puVar1 = *(undefined8 **)(lVar6 + 0x58);` |
| `FUN_140289b70` | 1 | 952260 | `if ((param_1 != 0) && (puVar1 = *(undefined8 **)(param_1 + 0x58), puVar1 != (undefined8 *)0x0)) {` |
| `FUN_14028f280` | 1 | 961838 | `lVar5 = *(longlong *)(param_1 + 0x58);` |
| `FUN_14028fc70` | 1 | 962488 | `lVar7 = *(longlong *)(param_1 + 0x58);` |
| `FUN_140291460` | 1 | 964888 | `lVar7 = *(longlong *)(param_1 + 0x58);` |
| `FUN_140292310` | 1 | 965724 | `lVar8 = *(longlong *)(param_1 + 0x58);` |
| `FUN_1402935f0` | 1 | 966988 | `lVar7 = *(longlong *)(param_1 + 0x58);` |
| `FUN_140293af0` | 1 | 967380 | `puVar5 = *(uint **)(param_1 + 0x58);` |
| `FUN_1402949f0` | 1 | 968498 | `lVar4 = *(longlong *)(param_1 + 0x58);` |
| `FUN_140294c20` | 1 | 968760 | `lVar11 = *(longlong *)(param_1 + 0x58);` |
| `FUN_140295120` | 1 | 969300 | `lVar5 = *(longlong *)(param_1 + 0x58);` |
| `FUN_1402953d0` | 1 | 969600 | `lVar5 = *(longlong *)(param_1 + 0x58);` |
| `FUN_140295650` | 1 | 969936 | `lVar6 = *(longlong *)(param_1 + 0x58);` |
| `FUN_1402958c0` | 1 | 970178 | `lVar5 = *(longlong *)(param_1 + 0x58);` |
| `FUN_140295af0` | 1 | 970412 | `puVar9 = *(uint **)(param_1 + 0x58);` |
| `FUN_140296080` | 1 | 970848 | `puVar5 = *(uint **)(param_1 + 0x58);` |
| `FUN_140297650` | 1 | 972526 | `puVar8 = *(uint **)(param_1 + 0x58);` |
| `FUN_140299510` | 1 | 974842 | `lVar6 = *(longlong *)(param_1 + 0x58);` |
| `FUN_140299770` | 1 | 975048 | `lVar5 = *(longlong *)(param_1 + 0x58);` |
| `FUN_140299ba0` | 1 | 975474 | `lVar4 = *(longlong *)(param_1 + 0x58);` |
| `FUN_14029c020` | 1 | 979042 | `lVar11 = *(longlong *)(param_1 + 0x58);` |
| `FUN_14029d250` | 1 | 980232 | `lVar12 = *(longlong *)(param_1 + 0x58);` |
| `FUN_14029e390` | 1 | 981392 | `lVar10 = *(longlong *)(param_1 + 0x58);` |
| `FUN_14029fb60` | 1 | 982964 | `uVar23 = (uint)*(byte *)(*(longlong *)(param_1 + 0x58) + 5) * *(int *)(param_1 + 0x38);` |
| `FUN_1402a05f0` | 1 | 984070 | `piVar9 = *(int **)(param_1 + 0x58);` |
| `FUN_1402c9074` | 1 | 1036134 | `plVar2 = *(longlong **)(lVar1 + 0x58);` |
| `FUN_1402cbbd8` | 1 | 1041876 | `if (*(longlong *)(param_1 + 0x58) != 0) {` |
| `FUN_1402cbdc4` | 1 | 1041984 | `if (*(longlong *)(param_1 + 0x58) != 0) {` |
| `FUN_1402e842c` | 1 | 1096238 | `FUN_1402e9a80(*(undefined8 *)(local_20 + 0x58));` |
| `FUN_1402fc58d` | 1 | 1130542 | `FUN_1402c7088(*(undefined8 *)(param_2 + 0x58),200);` |
| `FUN_1402ff20a` | 1 | 1132456 | `FUN_1402c7088(*(undefined8 *)(param_2 + 0x58),200);` |
| `FUN_1402ffa6f` | 1 | 1132880 | `FUN_1402c7784(*(undefined8 *)(param_2 + 0x50),*(undefined8 *)(param_2 + 0x58),` |
| `FUN_1402ffc15` | 1 | 1133044 | `if (*(char *)(param_2 + 0x58) != '\0') {` |
| `FUN_1402fff8a` | 1 | 1133516 | `FUN_1402e171c(*(undefined8 *)(param_2 + 0x58));` |
| `FUN_14030004c` | 1 | 1133646 | `__acrt_unlock(**(undefined4 **)(param_2 + 0x58));` |

## `+0x5c` (92 dec)

25 functions, 49 read sites.

| Function | Hits | First line | First snippet |
|---|---|---|---|
| `FUN_1401a57b0` | 9 | 590472 | `iVar1 = *(int *)(param_1 + 0x5c);` |
| `FUN_1401a7350` | 9 | 593576 | `uVar10 = *(int *)(param_1 + 0x5c) + 2;` |
| `FUN_140131ef0` | 3 | 404174 | `iVar9 = *(int *)(param_1 + 0x5c);` |
| `FUN_1401a7a20` | 3 | 593974 | `uVar4 = *(uint *)(param_1 + 0x60) \| 1 << (*(uint *)(param_1 + 0x5c) & 0x1f);` |
| `FUN_140042b70` | 2 | 74338 | `if (*(char *)(param_1 + 0x5c) != '\0') {` |
| `FUN_140042f50` | 2 | 74800 | `if (*(char *)(param_1 + 0x5c) != '\0') {` |
| `FUN_1400e0aa0` | 2 | 259382 | `fVar1 = *(float *)(lVar13 + 0x5c);` |
| `FUN_140208080` | 2 | 722004 | `iVar1 = *(int *)(param_3 + 0x5c);` |
| `FUN_140016810` | 1 | 21764 | `(uint)((*(float *)(param_1 + 0x5c) - *(float *)(param_1 + 0x14)) *` |
| `FUN_140016c70` | 1 | 22168 | `fStack_114 = *(float *)(param_3 + 0x5c);` |
| `FUN_1400410f0` | 1 | 71842 | `if (*(char *)(param_1 + 0x5c) != '\0') {` |
| `FUN_140041280` | 1 | 72206 | `if (*(char *)(param_1 + 0x5c) != '\0') {` |
| `FUN_140042130` | 1 | 73442 | `if (*(char *)(param_1 + 0x5c) != '\0') goto LAB_14004272f;` |
| `FUN_1400428f0` | 1 | 74068 | `if (*(char *)(param_1 + 0x5c) != '\0') {` |
| `FUN_140042950` | 1 | 74126 | `if (*(char *)(param_1 + 0x5c) != '\0') {` |
| `FUN_14004f210` | 1 | 92760 | `if (*(char *)(param_1 + 0x5c) != '\0') {` |
| `FUN_140050920` | 1 | 93048 | `if (*(char *)(param_1 + 0x5c) != '\0') {` |
| `FUN_140055360` | 1 | 100590 | `if (*(char *)(param_1 + 0x5c) != '\0') {` |
| `FUN_140055c30` | 1 | 101256 | `if ((((0 < *(int *)(lVar1 + 0x5c)) && (0 < *(int *)(lVar1 + 0x54))) &&` |
| `FUN_140131930` | 1 | 403578 | `uVar2 = *(undefined4 *)(param_1 + 0x5c);` |
| `FUN_14014e660` | 1 | 447392 | `*param_3 = *(undefined4 *)(lVar1 + 0x5c);` |
| `FUN_1401beac0` | 1 | 627128 | `if ((*(int *)(param_1 + 0x5c) != 0) && (*(int *)(param_2 + 0x5c) == 0)) {` |
| `FUN_1401e8a10` | 1 | 682886 | `*(undefined4 *)(lVar1 + 0x5c));` |
| `FUN_140207d60` | 1 | 721718 | `uVar3 = *(undefined4 *)(lVar1 + 0x5c);` |
| `FUN_140225c60` | 1 | 766584 | `uVar2 = *(undefined4 *)(param_3 + 0x5c);` |

## `+0x60` (96 dec)

204 functions, 351 read sites.

| Function | Hits | First line | First snippet |
|---|---|---|---|
| `FUN_140104370` | 21 | 306222 | `*(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x39d) =` |
| `FUN_140098660` | 10 | 177890 | `*(float *)(*(longlong *)(param_1 + 0x60) + 0xac4) = (float)(DAT_1403d9e68 + -0x3c);` |
| `FUN_14008ffc0` | 9 | 170380 | `*(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x5d) = 0;` |
| `FUN_1401a57b0` | 9 | 590480 | `*(uint *)(param_1 + 0x60);` |
| `FUN_140089510` | 8 | 161998 | `*(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x53d) = 1;` |
| `FUN_1401a7350` | 8 | 593578 | `uVar11 = 2 << ((byte)*(int *)(param_1 + 0x5c) & 0x1f) \| *(uint *)(param_1 + 0x60);` |
| `FUN_1400450b0` | 6 | 76974 | `*(undefined1 *)(*(longlong *)(DAT_1403ea2a8 + 0x60) + 9) = 0;` |
| `FUN_140094a20` | 6 | 174130 | `*(undefined4 *)(*(longlong *)(param_1 + 0x60) + 0xa60) = 0x431d0000;` |
| `FUN_140043c60` | 5 | 75600 | `*(float *)(*(longlong *)(DAT_1403ea2a8 + 0x60) + 0xc) =` |
| `FUN_1400ca260` | 5 | 233792 | `lVar2 = *(longlong *)(param_1 + 0x60);` |
| `FUN_1400060e0` | 4 | 2290 | `*(undefined8 *)(lVar4 + 0x38) = *(undefined8 *)(*(longlong *)(lVar4 + 0x60) + 0x80);` |
| `FUN_140030bd0` | 4 | 54218 | `*(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x405) = 0;` |
| `FUN_140055dc0` | 4 | 101418 | `*(float *)(*(longlong *)(param_1 + 0x60) + 0x37c) = (float)iVar6;` |
| `FUN_1401b9390` | 4 | 619020 | `if (*(uint *)(param_2 + 0x60) != 0) {` |
| `FUN_14020ad80` | 4 | 726548 | `uVar11 = *(undefined8 *)(lVar3 + 0x60);` |
| `FUN_140011000` | 3 | 14788 | `lVar4 = *(longlong *)(*(longlong *)(param_2 + 0x60) + 0x10);` |
| `FUN_14004f210` | 3 | 91250 | `FUN_140050920(param_1,*(undefined4 *)(param_1 + 0x60));` |
| `FUN_140055c30` | 3 | 101248 | `*(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x335) = uVar2;` |
| `FUN_14006bc00` | 3 | 124900 | `*(float *)(*(longlong *)(param_1 + 0x60) + 0x4ac) * DAT_140303354,` |
| `FUN_1400dbe10` | 3 | 253496 | `*(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x335) = 1;` |
| `FUN_1400f6fe0` | 3 | 290552 | `*(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x5d) = 1;` |
| `FUN_1401104f0` | 3 | 319516 | `*(float *)(*(longlong *)(param_1 + 0x60) + 0x514) = (float)(DAT_1403ed994 + 0x16);` |
| `FUN_140131ef0` | 3 | 404176 | `if ((iVar9 < 1) \|\| (iVar4 = *(int *)(param_1 + 0x60), iVar4 < 1)) {` |
| `FUN_140164f60` | 3 | 480800 | `if ((param_6 != 0) && (lVar4 = FUN_140217c10(*(undefined8 *)(param_1 + 0x60)), lVar4 == 0)) {` |
| `FUN_140216540` | 3 | 743584 | `piVar9 = (int *)FUN_14015de30(*(undefined4 *)(param_1 + 0x60));` |
| `FUN_14001e5e0` | 2 | 30114 | `lVar15 = *(longlong *)(*(longlong *)(lVar4 + 0x60) + 0x10);` |
| `FUN_14003d890` | 2 | 67448 | `(((sVar4 = *(short *)(*(longlong *)(lVar6 + 0x60) + 0x34), sVar4 == 2 &&` |
| `FUN_14003ee40` | 2 | 68842 | `if (*(longlong *)(DAT_1403ea2a8 + 0x60) != 0) {` |
| `FUN_14003f2c0` | 2 | 69204 | `if (*(longlong *)(DAT_1403ea2a8 + 0x60) != 0) {` |
| `FUN_14003f590` | 2 | 69454 | `if (*(longlong *)(DAT_1403ea2a8 + 0x60) != 0) {` |
| `FUN_14003f740` | 2 | 69582 | `if (*(longlong *)(DAT_1403ea2a8 + 0x60) != 0) {` |
| `FUN_14003f7b0` | 2 | 69622 | `if (*(longlong *)(DAT_1403ea2a8 + 0x60) != 0) {` |
| `FUN_140042950` | 2 | 74154 | `(uVar6 = *(uint *)(param_1 + 0x58) - 0x10000, uVar6 < *(uint *)(param_1 + 0x60))) {` |
| `FUN_140045310` | 2 | 77068 | `if (*(longlong *)(DAT_1403ea2a8 + 0x60) != 0) {` |
| `FUN_1400453a0` | 2 | 77098 | `if (*(longlong *)(DAT_1403ea2a8 + 0x60) != 0) {` |
| `FUN_1400453e0` | 2 | 77212 | `*(undefined1 *)(*(longlong *)(DAT_1403ea2a8 + 0x60) + 9) = 0;` |
| `FUN_1400455f0` | 2 | 77340 | `*(undefined1 *)(*(longlong *)(DAT_1403ea2a8 + 0x60) + 9) = 0;` |
| `FUN_140046320` | 2 | 78150 | `if (*(longlong *)(DAT_1403ea2a8 + 0x60) != 0) {` |
| `FUN_140056620` | 2 | 102240 | `lVar14 = *(longlong *)(param_1 + 0x60);` |
| `FUN_14005a720` | 2 | 106256 | `if (*(char *)(*(longlong *)(param_1 + 0x60) + 0x746) != '\0') {` |
| `FUN_14007b2e0` | 2 | 145408 | `*(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x5d) = 1;` |
| `FUN_1400d2090` | 2 | 243202 | `if (1 < (ulonglong)((*(longlong *)(param_1 + 0x68) - *(longlong *)(param_1 + 0x60)) / 0x68)) {` |
| `FUN_1400d52c0` | 2 | 246654 | `lVar6 = *(longlong *)(param_1 + 0x60);` |
| `FUN_1400dcab0` | 2 | 254762 | `if (((iVar22 == 1) && (*(char *)(*(longlong *)(param_1 + 0x60) + 0x39d) != '\0')) &&` |
| `FUN_14010ba40` | 2 | 315534 | `lVar11 = (longlong)*(int *)(lVar33 + 0x60);` |
| `FUN_14015a3a0` | 2 | 464098 | `if (0 < *(int *)(param_1 + 0x60)) {` |
| `FUN_14015daf0` | 2 | 469474 | `puVar1[6] = *(undefined8 *)(lVar2 + 0x60);` |
| `FUN_140164580` | 2 | 479942 | `lVar10 = FUN_140217eb0(*(undefined8 *)(param_1 + 0x60),param_2,iVar2,iVar3,uVar11,` |
| `FUN_1401a7a20` | 2 | 593974 | `uVar4 = *(uint *)(param_1 + 0x60) \| 1 << (*(uint *)(param_1 + 0x5c) & 0x1f);` |
| `FUN_1401bce00` | 2 | 624116 | `uVar1 = *(uint *)(param_2 + 0x60);` |
| `FUN_1401caf50` | 2 | 643464 | `FUN_1401841e0(*(undefined8 *)(lVar5 + 0x60));` |
| `FUN_140203060` | 2 | 715384 | `local_e4 = *(undefined4 *)(param_1 + 0x60);` |
| `FUN_140209760` | 2 | 724480 | `iVar3 = (**(code **)(*(longlong *)**(undefined8 **)(lVar1 + 0x60) + 0x38))` |
| `FUN_140209880` | 2 | 724560 | `iVar2 = (**(code **)(*(longlong *)**(undefined8 **)(lVar1 + 0x60) + 0x38))` |
| `FUN_14020de30` | 2 | 730890 | `if (*(int *)(param_1 + 0x60) < 0xff) {` |
| `FUN_14020fe40` | 2 | 733804 | `uVar11 = (longlong)*(int *)(param_1 + 0x60) * 4;` |
| `FUN_140215880` | 2 | 742528 | `piVar8 = (int *)FUN_14015de30(*(undefined4 *)(param_1 + 0x60));` |
| `FUN_14022c870` | 2 | 776040 | `if (*(longlong *)(lVar1 + 0x60) != 0) {` |
| `FUN_14022cb80` | 2 | 776348 | `if (*(longlong *)(lVar1 + 0x60) != 0) {` |
| `FUN_140272910` | 2 | 921268 | `if (*(longlong *)(lVar1 + 0x60) + 500U <= uVar4) {` |
| `FUN_140006230` | 1 | 2400 | `lVar3 = *(longlong *)(param_2 + 0x60);` |
| `FUN_1400063f0` | 1 | 2758 | `((*(char *)(*(longlong *)(lVar11 + 0x60) + 0x3a) == '\0' &&` |
| `FUN_140006950` | 1 | 3770 | `*(char *)(*(longlong *)(lVar2 + 0x60) + 0x3a) == '\0' &&` |
| `FUN_140008560` | 1 | 5358 | `lVar9 = *(longlong *)(param_1 + 0x60);` |
| `FUN_140009b70` | 1 | 6416 | `lVar6 = *(longlong *)(param_1 + 0x60);` |
| `FUN_140009ca0` | 1 | 6560 | `lVar4 = *(longlong *)(param_1 + 0x60);` |
| `FUN_140009e10` | 1 | 6652 | `lVar1 = *(longlong *)(param_1 + 0x60);` |
| `FUN_140009e60` | 1 | 6694 | `lVar1 = *(longlong *)(param_1 + 0x60);` |
| `FUN_140009eb0` | 1 | 6736 | `lVar1 = *(longlong *)(param_1 + 0x60);` |
| `FUN_14000a0a0` | 1 | 6960 | `lVar6 = *(longlong *)(param_1 + 0x60);` |
| `FUN_14000b270` | 1 | 7880 | `*(float *)(*(longlong *)(param_1 + 0x60) + 0x38)) - *(float *)(param_1 + 0xb0);` |
| `FUN_14000b2a0` | 1 | 7916 | `lVar1 = *(longlong *)(param_1 + 0x60);` |
| `FUN_14000b2f0` | 1 | 7958 | `lVar1 = *(longlong *)(param_1 + 0x60);` |
| `FUN_14000b340` | 1 | 8000 | `lVar1 = *(longlong *)(param_1 + 0x60);` |
| `FUN_14000b3a0` | 1 | 8060 | `lVar1 = *(longlong *)(param_1 + 0x60);` |
| `FUN_14000b4a0` | 1 | 8214 | `lVar6 = *(longlong *)(param_1 + 0x60);` |
| `FUN_14000d3c0` | 1 | 10402 | `puVar1[0xc] = *(undefined8 *)(param_1 + 0x60);` |
| `FUN_1400111f0` | 1 | 14980 | `lVar13 = *(longlong *)(lVar11 + 0x60);` |
| `FUN_1400113e0` | 1 | 15346 | `lVar5 = *(longlong *)(*(longlong *)(lVar13 + 0x60) + 0x10);` |
| `FUN_1400145b0` | 1 | 18870 | `lVar6 = *(longlong *)(param_1 + 0x60);` |
| `FUN_1400152f0` | 1 | 19558 | `lVar6 = *(longlong *)(param_1 + 0x60);` |
| `FUN_140016c70` | 1 | 22952 | `if (*(char *)(local_148 + 0x60) != '\0') {` |
| `FUN_140018650` | 1 | 24316 | `lVar8 = *(longlong *)(param_1 + 0x60);` |
| `FUN_140018e70` | 1 | 24780 | `lVar6 = *(longlong *)(param_1 + 0x60);` |
| `FUN_140019cf0` | 1 | 25428 | `lVar6 = *(longlong *)(param_1 + 0x60);` |
| `FUN_140019e50` | 1 | 25634 | `lVar8 = *(longlong *)(param_1 + 0x60);` |
| `FUN_14001aaa0` | 1 | 26310 | `lVar6 = *(longlong *)(param_1 + 0x60);` |
| `FUN_14001b650` | 1 | 26928 | `lVar6 = *(longlong *)(param_1 + 0x60);` |
| `FUN_14001bb70` | 1 | 27380 | `lVar6 = *(longlong *)(param_1 + 0x60);` |
| `FUN_14001d130` | 1 | 28296 | `lVar6 = *(longlong *)(param_1 + 0x60);` |
| `FUN_14001dc60` | 1 | 29144 | `FUN_14000d080(*(undefined8 *)(*(longlong *)(param_1 + 0x60) + 0x18),&local_48,` |
| `FUN_14001ddf0` | 1 | 29292 | `FUN_140021550(local_118,param_2,*(undefined8 *)(*(longlong *)(param_1 + 0x60) + 0x18),param_3);` |
| `FUN_14001df50` | 1 | 29426 | `lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x60) + 0x18);` |
| `FUN_14001e1a0` | 1 | 29618 | `FUN_14000d080(*(undefined8 *)(*(longlong *)(param_1 + 0x60) + 0x18),&local_178,` |
| `FUN_14001e350` | 1 | 29746 | `FUN_140022a90(param_2,*(undefined8 *)(*(longlong *)(param_1 + 0x60) + 0x18),param_3,` |
| `FUN_14001e480` | 1 | 29868 | `FUN_1400237d0(param_2,*(undefined8 *)(*(longlong *)(param_1 + 0x60) + 0x18),param_3,` |
| `FUN_14001e5b0` | 1 | 29990 | `FUN_1400210d0(param_2,*(undefined8 *)(*(longlong *)(param_1 + 0x60) + 0x18),param_3,` |
| `FUN_140025450` | 1 | 38170 | `plVar1 = *(longlong **)(param_1 + 0x60);` |
| `FUN_1400272d0` | 1 | 41328 | `*(longlong *)(*(longlong *)(param_1 + 0x60) + 0x68) = param_2;` |
| `FUN_14002fe00` | 1 | 53406 | `(**(code **)(lVar12 + 0x60))(param_1,uVar1);` |
| `FUN_140038860` | 1 | 63134 | `*(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x5d) = 0;` |
| `FUN_1400428f0` | 1 | 74076 | `FUN_140050920(param_1,*(undefined4 *)(param_1 + 0x60));` |
| `FUN_140045c20` | 1 | 77954 | `if ((lVar1 != *(longlong *)(lVar2 + 0x58)) && (lVar1 != *(longlong *)(lVar2 + 0x60))) {` |
| `FUN_140058480` | 1 | 103614 | `*(bool *)(*(longlong *)(param_1 + 0x60) + 0x746) = 0x1e < *(int *)(DAT_1403fb0d8 + 0x314);` |
| `FUN_140068bb0` | 1 | 121700 | `lVar4 = *(longlong *)(lVar3 + 0x60);` |
| `FUN_14006b040` | 1 | 124288 | `if ((*(char *)(*(longlong *)(param_1 + 0x60) + 0x53d) == '\0') \|\|` |
| `FUN_14007c970` | 1 | 146910 | `lVar1 = *(longlong *)(param_1 + 0x60);` |
| `FUN_14008fce0` | 1 | 168054 | `FUN_140027f50(*(longlong *)(param_1 + 0x60) + 0xa30,_Str);` |
| `FUN_1400b6fd0` | 1 | 211712 | `uStack_b8 = *(undefined8 *)(lVar3 + 0x60);` |
| `FUN_1400ba940` | 1 | 217188 | `lVar28 = *(longlong *)(lVar6 + 0x60);` |
| `FUN_1400bea50` | 1 | 219988 | `uVar5 = *(undefined8 *)(lVar10 + 0x60);` |
| `FUN_1400ca150` | 1 | 233620 | `lVar2 = *(longlong *)(param_1 + 0x60);` |
| `FUN_1400ca240` | 1 | 233666 | `*(undefined1 *)((longlong)param_2 * 0x68 + 0x5d + *(longlong *)(param_1 + 0x60)) = param_3;` |
| `FUN_1400cba60` | 1 | 235462 | `lVar3 = *(longlong *)(param_1 + 0x60);` |
| `FUN_1400dde40` | 1 | 256160 | `(*(char *)(*(longlong *)(param_1 + 0x60) + 0x39d) != '\0')) &&` |
| `FUN_1400e25b0` | 1 | 260962 | `(*(char *)(*(longlong *)(param_1 + 0x60) + 0x39d) != '\0')) {` |
| `FUN_1400f5280` | 1 | 289210 | `*(bool *)(*(longlong *)(param_1 + 0x60) + 0x5d) = 0 < iVar15;` |
| `FUN_14010a5e0` | 1 | 314024 | `*(longlong *)(param_1 + 0x60));` |
| `FUN_14010dff0` | 1 | 318566 | `lVar21 = *(longlong *)(param_1 + 0x60);` |
| `FUN_14010fc10` | 1 | 319086 | `lVar4 = *(longlong *)(param_1 + 0x60);` |
| `FUN_140131930` | 1 | 403580 | `uVar3 = *(undefined4 *)(param_1 + 0x60);` |
| `FUN_140137150` | 1 | 411650 | `puVar1 = *(uint **)(param_1 + 0x60);` |
| `FUN_14014de30` | 1 | 446390 | `(**(code **)(param_1 + 0x60))(param_1);` |
| `FUN_140158660` | 1 | 460480 | `if (param_2 < *(int *)(param_1 + 0x60)) {` |
| `FUN_140159170` | 1 | 461856 | `uVar1 = *(undefined4 *)(param_1 + 0x60);` |
| `FUN_14015cef0` | 1 | 468224 | `if (*(int *)(param_1 + 0x60) != 0x8120) {` |
| `FUN_14015d7a0` | 1 | 469022 | `if (*(int *)(param_1 + 0x60) != 0x8120) {` |
| `FUN_14015e2b0` | 1 | 470078 | `*param_2 = *(undefined8 *)(lVar2 + 0x60);` |
| `FUN_14015ec40` | 1 | 471024 | `local_40 = *(undefined8 *)(local_48 + 0x60);` |
| `FUN_14015f430` | 1 | 471624 | `uVar4 = (*(uint *)(param_1 + 0x60) >> 3 & 0x1f) * *(int *)(param_1 + 100);` |
| `FUN_14015fd50` | 1 | 472480 | `uVar1 = *(uint *)(param_1 + 0x60);` |
| `FUN_14015fec0` | 1 | 472674 | `local_58 = *(undefined8 *)(param_1 + 0x60);` |
| `FUN_1401600c0` | 1 | 472828 | `((*(uint *)(param_1 + 0x60) >> 3 & 0x1f) * *(int *)(param_1 + 100))) * 1000);` |
| `FUN_140161f10` | 1 | 476232 | `(*(undefined8 *)(lVar6 + 0x60),param_1,param_2,param_3,&param_5,&param_6);` |
| `FUN_1401644e0` | 1 | 479812 | `local_res8 = FUN_140217b30(*(undefined8 *)(param_1 + 0x60));` |
| `FUN_140164870` | 1 | 480070 | `local_18[0] = FUN_140217b30(*(undefined8 *)(param_1 + 0x60));` |
| `FUN_140164d70` | 1 | 480644 | `uVar2 = FUN_140217dc0(*(undefined8 *)(param_1 + 0x60),param_2,&local_30,&local_38,local_res8);` |
| `FUN_140168f00` | 1 | 485382 | `uVar2 = *(undefined8 *)(param_1 + 0x60);` |
| `FUN_140171a90` | 1 | 499678 | `pcVar3 = *(code **)(lVar11 + 0x60);` |
| `FUN_1401778a0` | 1 | 508814 | `bVar1 = (**(code **)(param_1 + 8))(*(undefined8 *)(param_1 + 0x60));` |
| `FUN_140177900` | 1 | 508884 | `uVar1 = (**(code **)(param_1 + 0x50))(*(undefined8 *)(param_1 + 0x60),param_2,param_3);` |
| `FUN_1401779f0` | 1 | 508948 | `(**(code **)(param_1 + 0x38))(*(undefined8 *)(param_1 + 0x60),param_2);` |
| `FUN_140177a90` | 1 | 509000 | `(**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x60),puVar2,param_3,param_4);` |
| `FUN_140177b70` | 1 | 509124 | `(**(code **)(param_1 + 0x20))(*(undefined8 *)(param_1 + 0x60),param_2,puVar2);` |
| `FUN_140177c50` | 1 | 509166 | `uVar1 = (**(code **)(param_1 + 0x58))(*(undefined8 *)(param_1 + 0x60));` |
| `FUN_140178190` | 1 | 509704 | `(**(code **)(param_1 + 0x28))(*(undefined8 *)(param_1 + 0x60),param_2,param_3,param_4);` |
| `FUN_140178250` | 1 | 509776 | `(**(code **)(param_1 + 0x40))(*(undefined8 *)(param_1 + 0x60),param_2);` |
| `FUN_1401782f0` | 1 | 509842 | `uVar1 = (**(code **)(param_1 + 0x48))(*(undefined8 *)(param_1 + 0x60),param_2,param_3);` |
| `FUN_1401783e0` | 1 | 509884 | `uVar1 = (**(code **)(param_1 + 0x10))(*(undefined8 *)(param_1 + 0x60));` |
| `FUN_140178420` | 1 | 509938 | `(**(code **)(param_1 + 0x30))(*(undefined8 *)(param_1 + 0x60),param_2,param_3,param_4);` |
| `FUN_140189320` | 1 | 537602 | `local_b0 = *(undefined8 *)(param_1 + 0x60);` |
| `FUN_1401934d0` | 1 | 557728 | `uVar2 = (ulonglong)*(uint *)(param_1 + 0x60);` |
| `FUN_1401beac0` | 1 | 627140 | `if ((*(int *)(param_1 + 0x60) != 0) && (*(int *)(param_2 + 0x60) == 0)) {` |
| `FUN_1401c9cd0` | 1 | 641790 | `FUN_1401841e0(*(undefined8 *)(lVar1 + 0x60));` |
| `FUN_1401cacc0` | 1 | 643178 | `FUN_1401841e0(*(undefined8 *)(param_2 + 0x60));` |
| `FUN_1401cc320` | 1 | 645350 | `FUN_1401841e0(*(undefined8 *)(param_2 + 0x60));` |
| `FUN_1401cc650` | 1 | 645872 | `if ((*(int *)(lVar1 + 0x60) != 0) && (uVar13 = 0, iVar3 == 1)) {` |
| `FUN_1401dcdf0` | 1 | 667244 | `if (*(char *)(lVar1 + 0x60) != '\0') {` |
| `FUN_1401e3ba0` | 1 | 676304 | `if (*(char *)(lVar2 + 0x60) != '\0') {` |
| `FUN_1401e45b0` | 1 | 677218 | `if ((*(char *)(lVar1 + 0x38) != '\0') \|\| (*(char *)(lVar1 + 0x60) != '\0')) {` |
| `FUN_1401e51e0` | 1 | 678366 | `(*(longlong **)(lVar2 + 0x28),*(undefined8 *)(lVar1 + 0x60),0);` |
| `FUN_1401e7960` | 1 | 681436 | `local_48 = *(undefined4 *)(lVar1 + 0x60);` |
| `FUN_1401e9660` | 1 | 683900 | `local_b8[uVar6] = *(undefined8 *)(lVar3 + 0x60);` |
| `FUN_1401e9870` | 1 | 684004 | `iVar8 = *(int *)(lVar1 + 0x60);` |
| `FUN_1401ee270` | 1 | 689528 | `(**(code **)(lVar2 + 0x60))(fVar16,fVar17,fVar15,fVar1);` |
| `FUN_1401f06c0` | 1 | 691932 | `uVar1 = (**(code **)(param_1 + 0x60))(param_3);` |
| `FUN_1401ff0c0` | 1 | 709872 | `local_28 = *(undefined4 *)(lVar2 + 0x60);` |
| `FUN_140203be0` | 1 | 716344 | `FUN_140137fd0(*(undefined8 *)(lVar1 + 8),*(undefined8 *)(pcVar2 + 0x60));` |
| `FUN_140204280` | 1 | 716904 | `uVar12 = FUN_140137970(*(undefined4 *)(lVar3 + 0x60));` |
| `FUN_140204cb0` | 1 | 717784 | `bVar4 = FUN_140204fe0(lVar1,uVar9,*(undefined8 *)(lVar2 + 0x60),uVar12 * 2,*param_3 / 2,` |
| `FUN_1402051e0` | 1 | 718042 | `bVar4 = FUN_140204fe0(lVar1,uVar5,*(undefined8 *)(lVar2 + 0x60),uVar6 * 2,*param_3 / 2,` |
| `FUN_140206970` | 1 | 719844 | `return *(undefined4 *)(lVar1 + 0x60);` |
| `FUN_140209270` | 1 | 724298 | `iVar7 = *(int *)(param_1 + 0x60);` |
| `FUN_14020a370` | 1 | 725576 | `iVar2 = *(int *)(param_1 + 0x60);` |
| `FUN_14020fa10` | 1 | 733318 | `uVar1 = *(undefined8 *)(lVar2 + 0x60);` |
| `FUN_140216e70` | 1 | 744466 | `uVar10 = FUN_140216d80(*(undefined4 *)(param_1 + 0x60));` |
| `FUN_140219f80` | 1 | 749170 | `uVar8 = (**(code **)(lVar4 + 0x60))` |
| `FUN_1402246a0` | 1 | 764678 | `iVar3 = *(int *)(lVar6 + 0x60);` |
| `FUN_140225c60` | 1 | 766586 | `uVar3 = *(undefined4 *)(param_3 + 0x60);` |
| `FUN_140271d80` | 1 | 920132 | `FUN_140272050(&local_28,*(undefined4 *)(param_1 + 0x60));` |
| `FUN_1402783e0` | 1 | 928872 | `if ((iVar3 < 0) \|\| (*(char *)(lVar1 + 0x60) != '\0')) {` |
| `FUN_14027d570` | 1 | 936116 | `if (((bVar1 & 0x10) == 0) && (uVar13 = 4, *(char *)(param_2 + 0x60) != '\0')) {` |
| `FUN_140280490` | 1 | 939656 | `lVar2 = *(longlong *)(param_2 + 0x60);` |
| `FUN_140285a70` | 1 | 946586 | `bVar2 = *(byte *)(param_2 + 0x60);` |
| `FUN_14029a780` | 1 | 977270 | `lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x60) + 8);` |
| `FUN_14029afc0` | 1 | 977854 | `lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x60) + 8);` |
| `FUN_14029b740` | 1 | 978406 | `lVar13 = *(longlong *)(*(longlong *)(param_1 + 0x60) + 8);` |
| `FUN_1402a05f0` | 1 | 984074 | `lVar10 = *(longlong *)(param_1 + 0x60);` |
| `FUN_1402c8390` | 1 | 1034628 | `*(longlong *)(lVar2 + 0x60) + (ulonglong)uVar1 * 0x14;` |
| `FUN_1402c8e50` | 1 | 1035842 | `return *(undefined8 *)(lVar1 + 0x60);` |
| `FUN_1402c8e90` | 1 | 1035964 | `(ulonglong)**(uint **)(param_4 + 0x38) + *(longlong *)(lVar2 + 0x60),0,0,0);` |
| `FUN_1402c8f30` | 1 | 1036024 | `FUN_1402c83f4((ulonglong)**(uint **)(param_4 + 0x38) + *(longlong *)(lVar2 + 0x60),local_28,` |
| `FUN_1402e842c` | 1 | 1096240 | `FUN_1402e9a80(*(undefined8 *)(local_20 + 0x60));` |
| `FUN_1402f9d80` | 1 | 1129948 | `FUN_1402c7088(*(undefined8 *)(param_2 + 0x60),0x70);` |
| `FUN_1402facfc` | 1 | 1130180 | `FUN_1402c7088(*(undefined8 *)(param_2 + 0x60),0x498);` |
| `FUN_1402fcb14` | 1 | 1130620 | `FUN_1402c7088(*(undefined8 *)(param_2 + 0x60),0x498);` |
| `FUN_1402fccd6` | 1 | 1130674 | `if ((*(uint *)(param_2 + 0x60) & 1) != 0) {` |
| `FUN_1402fd81f` | 1 | 1130974 | `FUN_1402c7088(*(undefined8 *)(param_2 + 0x60),0x498);` |
| `FUN_1402fe088` | 1 | 1131280 | `FUN_1402c7088(*(undefined8 *)(param_2 + 0x60),0x498);` |
| `FUN_1402fe0a5` | 1 | 1131298 | `FUN_1402c7088(*(undefined8 *)(param_2 + 0x60),0x498);` |
| `FUN_1402fe51c` | 1 | 1131430 | `FUN_1402c7088(*(undefined8 *)(param_2 + 0x60),0x498);` |
| `FUN_1402ff9e8` | 1 | 1132810 | `FUN_1402c7784(*(undefined8 *)(param_2 + 0x60),*(undefined8 *)(param_2 + 0x68),` |
| `FUN_1402ffef2` | 1 | 1133416 | `FUN_1402e171c(*(undefined8 *)(param_2 + 0x60));` |
| `FUN_140300100` | 1 | 1133776 | `__acrt_lowio_unlock_fh(*(undefined4 *)(param_2 + 0x60));` |

## `+0x64` (100 dec)

33 functions, 42 read sites.

| Function | Hits | First line | First snippet |
|---|---|---|---|
| `FUN_1400ba940` | 2 | 216944 | `uVar4 = *(uint *)(lVar34 + 100);` |
| `FUN_1400df280` | 2 | 258110 | `uVar4 = *(undefined4 *)(lVar28 + 100);` |
| `FUN_14010ba40` | 2 | 315550 | `lVar11 = (longlong)*(int *)(lVar33 + 100);` |
| `FUN_14015fd50` | 2 | 472486 | `iVar4 = (uVar1 >> 3 & 0x1f) * *(int *)(param_1 + 0x84) * *(int *)(param_1 + 100);` |
| `FUN_14016a310` | 2 | 487644 | `if (((iVar4 != *(int *)(param_1 + 100)) && (cVar3 = FUN_14016d280(), cVar3 != '\0')) &&` |
| `FUN_14016f980` | 2 | 496296 | `if (((iVar4 != *(int *)(param_1 + 100)) && (cVar3 = FUN_14016d280(), cVar3 != '\0')) &&` |
| `FUN_140204140` | 2 | 716768 | `uStack_60 = *(undefined8 *)(lVar1 + 100);` |
| `FUN_14025bf40` | 2 | 893312 | `else if (((param_2 < *(int *)(param_1 + 100)) \|\| (param_3 < *(int *)(param_1 + 0x68))) \|\|` |
| `FUN_14025fc80` | 2 | 897416 | `if ((((*(int *)(param_1 + 100) <= param_2) && (*(int *)(param_1 + 0x68) <= param_3)) &&` |
| `FUN_14004f210` | 1 | 91162 | `uVar23 = *(ulonglong *)(param_1 + 100);` |
| `FUN_140053810` | 1 | 98038 | `*(uint *)(param_1 + 0x68) = *(int *)(param_1 + 100) + 0x1b + uVar2 + iVar5;` |
| `FUN_140105980` | 1 | 308184 | `iVar5 = *(int *)(lVar2 + 100);` |
| `FUN_140110bf0` | 1 | 320240 | `iVar26 = *(int *)(lVar25 + 100);` |
| `FUN_140111a50` | 1 | 322504 | `iVar8 = *(int *)(lVar11 + 100);` |
| `FUN_140131930` | 1 | 403590 | `param_2[2] = *(undefined8 *)(param_1 + 100);` |
| `FUN_1401466d0` | 1 | 436010 | `*param_2 = *(undefined8 *)(param_1 + 100);` |
| `FUN_14015e240` | 1 | 470028 | `uVar3 = *(undefined4 *)(lVar1 + 100);` |
| `FUN_14015f430` | 1 | 471624 | `uVar4 = (*(uint *)(param_1 + 0x60) >> 3 & 0x1f) * *(int *)(param_1 + 100);` |
| `FUN_14015fec0` | 1 | 472764 | `*(undefined4 *)(param_1 + 100),0xffffffff);` |
| `FUN_1401600c0` | 1 | 472828 | `((*(uint *)(param_1 + 0x60) >> 3 & 0x1f) * *(int *)(param_1 + 100))) * 1000);` |
| `FUN_14016a4b0` | 1 | 487750 | `fVar1 = (float)FUN_14016d370(*(undefined4 *)(param_1 + 100));` |
| `FUN_140170430` | 1 | 497546 | `if (*param_1 == *(int *)(lVar1 + 100)) {` |
| `FUN_1401a5ab0` | 1 | 591326 | `uVar24 = *(int *)(param_1 + 100) - 1;` |
| `FUN_1401beac0` | 1 | 627152 | `if ((*(int *)(param_1 + 100) != 0) && (*(int *)(param_2 + 100) == 0)) {` |
| `FUN_1401e90d0` | 1 | 683470 | `if (*(char *)(lVar2 + 100) != '\0') {` |
| `FUN_1401ff0c0` | 1 | 709874 | `local_24 = *(undefined4 *)(lVar2 + 100);` |
| `FUN_140215880` | 1 | 742732 | `(*(uint *)(param_1 + 0x60) >> 3 & 0x1f) * *(int *)(param_1 + 100);` |
| `FUN_140216540` | 1 | 743616 | `iVar3 = *(int *)(param_1 + 100);` |
| `FUN_140216e70` | 1 | 744464 | `uVar4 = *(undefined4 *)(param_1 + 100);` |
| `FUN_140225c60` | 1 | 766588 | `uVar4 = *(undefined4 *)(param_3 + 100);` |
| `FUN_14025ea00` | 1 | 895588 | `iVar2 = *(int *)(param_1 + 100);` |
| `FUN_14025fd90` | 1 | 897524 | `iVar2 = *(int *)(param_1 + 100);` |
| `FUN_140271d80` | 1 | 920124 | `local_28 = (ulonglong)CONCAT11(*(undefined1 *)(param_1 + 100),*(undefined1 *)(param_1 + 0x65));` |

## `+0x68` (104 dec)

198 functions, 251 read sites.

| Function | Hits | First line | First snippet |
|---|---|---|---|
| `FUN_1400060e0` | 4 | 2286 | `*puVar1 = *(undefined8 *)(lVar4 + 0x68);` |
| `FUN_14002b180` | 4 | 47510 | `if (*(char *)(lVar7 + 0x68) != '\0') {` |
| `FUN_1400ca260` | 4 | 233794 | `if (((*(longlong *)(param_1 + 0x68) - lVar2) / 0x68 != 0) && (*(char *)(lVar2 + 0x5d) != '\0')) {` |
| `FUN_1401a5ab0` | 4 | 590970 | `if (*(uint *)(param_1 + 0x68) != 0) {` |
| `FUN_140240d00` | 4 | 863300 | `(**(code **)(param_1 + 0x68))(iVar2,*param_3,param_3[1],param_3[2]);` |
| `FUN_140011000` | 3 | 14790 | `lVar5 = *(longlong *)(*(longlong *)(param_2 + 0x68) + 0x10);` |
| `FUN_1400293d0` | 3 | 44810 | `if (*(char *)(param_1 + 0x68) != '\0') {` |
| `FUN_140029a90` | 3 | 45776 | `if (*(char *)(lVar13 + 0x68) != '\0') {` |
| `FUN_14002a130` | 3 | 46024 | `if (*(char *)(lVar4 + 0x68) != '\0') {` |
| `FUN_14003d890` | 3 | 67450 | `(*(short *)(*(longlong *)(lVar6 + 0x68) + 0x34) == 1)) \|\|` |
| `FUN_140068bb0` | 3 | 121704 | `(*(longlong *)(lVar3 + 0x68) != *(longlong *)(param_1 + 0x260))) goto LAB_140068d45;` |
| `FUN_1400063f0` | 2 | 2642 | `for (lVar4 = *(longlong *)(param_1 + 0x19320); lVar4 != 0; lVar4 = *(longlong *)(lVar4 + 0x68)) {` |
| `FUN_140006950` | 2 | 3202 | `for (lVar2 = *(longlong *)(param_1 + 0x19320); lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 0x68))` |
| `FUN_1400111f0` | 2 | 14982 | `lVar14 = *(longlong *)(lVar11 + 0x68);` |
| `FUN_1400113e0` | 2 | 15212 | `plVar10 = *(longlong **)(param_1 + 0x68);` |
| `FUN_14001e5e0` | 2 | 30116 | `lVar5 = *(longlong *)(*(longlong *)(lVar4 + 0x68) + 0x10);` |
| `FUN_1400273e0` | 2 | 41364 | `lVar4 = *(longlong *)(param_1 + 0x68);` |
| `FUN_140029110` | 2 | 44566 | `if (*(char *)(param_1 + 0x68) != '\0') {` |
| `FUN_1400447e0` | 2 | 76334 | `if (*(int *)(DAT_1403ea2a8 + 0x6c) == *(int *)(DAT_1403ea2a8 + 0x68)) {` |
| `FUN_1400ba940` | 2 | 216874 | `if ((*(float *)(lVar34 + 0x68) != 0.0) \|\| (*(float *)(lVar34 + 0x6c) != 0.0)) {` |
| `FUN_140104370` | 2 | 306352 | `lVar3 = *(longlong *)(param_1 + 0x68) - lVar2;` |
| `FUN_14015daf0` | 2 | 469476 | `*(undefined4 *)(puVar1 + 7) = *(undefined4 *)(lVar2 + 0x68);` |
| `FUN_14015f430` | 2 | 471632 | `iVar2 = (iVar3 / *(int *)(param_1 + 0x68)) * 2;` |
| `FUN_1401600c0` | 2 | 472830 | `FUN_1401492f0(lVar1 / (longlong)*(int *)(param_1 + 0x68) & 0xffffffff,` |
| `FUN_1401e2180` | 2 | 673930 | `if (*(longlong **)(lVar1 + 0x68) != (longlong *)0x0) {` |
| `FUN_1401f0390` | 2 | 691824 | `(**(code **)(param_1 + 0x68))(*puVar1);` |
| `FUN_140206a80` | 2 | 720046 | `(**(code **)(*(longlong *)(lVar2 + 0x68) + 0x48))(lVar2);` |
| `FUN_140207340` | 2 | 720748 | `if (*(longlong *)(param_1 + 0x68) != 0) {` |
| `FUN_140208a20` | 2 | 722988 | `if (((*(longlong *)(lVar1 + 0xa0) == 0) && (*(longlong *)(lVar1 + 0x68) != 0)) &&` |
| `FUN_140215880` | 2 | 742554 | `if (*(int *)(param_1 + 0x68) != *(int *)(local_70 + 4)) {` |
| `FUN_140216540` | 2 | 743596 | `iVar3 = *(int *)(param_1 + 0x68);` |
| `FUN_140216e70` | 2 | 744406 | `iVar2 = *(int *)(param_1 + 0x68);` |
| `FUN_14025bf40` | 2 | 893312 | `else if (((param_2 < *(int *)(param_1 + 100)) \|\| (param_3 < *(int *)(param_1 + 0x68))) \|\|` |
| `FUN_14025fc80` | 2 | 897416 | `if ((((*(int *)(param_1 + 100) <= param_2) && (*(int *)(param_1 + 0x68) <= param_3)) &&` |
| `FUN_140284930` | 2 | 944836 | `cVar1 = (**(code **)(*(longlong *)(lVar3 + 0x68) + 0x50))(lVar3,param_2);` |
| `FUN_1402c4b40` | 2 | 1025242 | `*(undefined8 *)(*(longlong *)(lVar1 + 0x70) + 0x68) = *(undefined8 *)(lVar1 + 0x68);` |
| `FUN_1402c4ba0` | 2 | 1025292 | `*(undefined8 *)(*(longlong *)(lVar1 + 0x70) + 0x68) = *(undefined8 *)(lVar1 + 0x68);` |
| `FUN_140005cf0` | 1 | 1932 | `lVar1 = *(longlong *)(lVar2 + 0x68);` |
| `FUN_140006230` | 1 | 2402 | `lVar4 = *(longlong *)(param_2 + 0x68);` |
| `FUN_140007610` | 1 | 4144 | `for (lVar1 = *(longlong *)(param_1 + 0x19320); lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x68))` |
| `FUN_140008560` | 1 | 5356 | `lVar8 = *(longlong *)(param_1 + 0x68);` |
| `FUN_140009bd0` | 1 | 6462 | `lVar6 = *(longlong *)(param_1 + 0x68);` |
| `FUN_140009ca0` | 1 | 6558 | `lVar3 = *(longlong *)(param_1 + 0x68);` |
| `FUN_140009e10` | 1 | 6662 | `lVar1 = *(longlong *)(param_1 + 0x68);` |
| `FUN_140009e60` | 1 | 6704 | `lVar1 = *(longlong *)(param_1 + 0x68);` |
| `FUN_140009eb0` | 1 | 6746 | `lVar1 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14000a0a0` | 1 | 6958 | `lVar5 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14000b270` | 1 | 7878 | `return (*(float *)(*(longlong *)(param_1 + 0x68) + 0x38) -` |
| `FUN_14000b2a0` | 1 | 7926 | `lVar1 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14000b2f0` | 1 | 7968 | `lVar1 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14000b340` | 1 | 8010 | `lVar1 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14000b3a0` | 1 | 8070 | `lVar1 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14000b4a0` | 1 | 8212 | `lVar5 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14000d3c0` | 1 | 10404 | `puVar1[0xd] = *(undefined8 *)(param_1 + 0x68);` |
| `FUN_1400145b0` | 1 | 18868 | `lVar5 = *(longlong *)(param_1 + 0x68);` |
| `FUN_140015350` | 1 | 19604 | `lVar6 = *(longlong *)(param_1 + 0x68);` |
| `FUN_140018650` | 1 | 24322 | `lVar9 = *(longlong *)(param_1 + 0x68);` |
| `FUN_140018e70` | 1 | 24786 | `lVar7 = *(longlong *)(param_1 + 0x68);` |
| `FUN_140019d50` | 1 | 25474 | `lVar6 = *(longlong *)(param_1 + 0x68);` |
| `FUN_140019e50` | 1 | 25640 | `lVar9 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14001aaa0` | 1 | 26308 | `lVar5 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14001b6b0` | 1 | 26974 | `lVar6 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14001bb70` | 1 | 27382 | `lVar7 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14001d190` | 1 | 28342 | `lVar6 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14001d410` | 1 | 28578 | `lVar5 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14001da30` | 1 | 28910 | `lVar6 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14001dc60` | 1 | 29148 | `FUN_1400210d0(param_2,&local_48,param_3,*(undefined8 *)(*(longlong *)(param_1 + 0x68) + 0x18),` |
| `FUN_14001ddf0` | 1 | 29288 | `local_128 = *(undefined8 *)(*(longlong *)(param_1 + 0x68) + 0x18);` |
| `FUN_14001df50` | 1 | 29424 | `lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x68) + 0x18);` |
| `FUN_14001e1a0` | 1 | 29622 | `local_188 = *(undefined8 *)(*(longlong *)(param_1 + 0x68) + 0x18);` |
| `FUN_14001e350` | 1 | 29748 | `*(undefined8 *)(*(longlong *)(param_1 + 0x68) + 0x18),param_4);` |
| `FUN_14001e480` | 1 | 29870 | `*(undefined8 *)(*(longlong *)(param_1 + 0x68) + 0x18),param_4);` |
| `FUN_14001e5b0` | 1 | 29992 | `*(undefined8 *)(*(longlong *)(param_1 + 0x68) + 0x18),param_4);` |
| `FUN_1400256d0` | 1 | 38494 | `lVar3 = *(longlong *)(lVar3 + 0x68);` |
| `FUN_140025730` | 1 | 38586 | `lVar3 = *(longlong *)(lVar3 + 0x68);` |
| `FUN_140025830` | 1 | 38730 | `lVar3 = *(longlong *)(lVar3 + 0x68);` |
| `FUN_140025bc0` | 1 | 39120 | `lVar5 = *(longlong *)(lVar5 + 0x68);` |
| `FUN_140026b90` | 1 | 40680 | `lVar3 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14002aab0` | 1 | 46862 | `if (*(char *)(lVar7 + 0x68) != '\0') {` |
| `FUN_14002adc0` | 1 | 47132 | `if (*(char *)(lVar6 + 0x68) != '\0') {` |
| `FUN_14002b4d0` | 1 | 47920 | `if (*(char *)(lVar5 + 0x68) != '\0') {` |
| `FUN_14002b650` | 1 | 48202 | `if (*(char *)(lVar3 + 0x68) != '\0') {` |
| `FUN_1400a8a00` | 1 | 197036 | `*(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x68);` |
| `FUN_1400b6fd0` | 1 | 211714 | `local_b0 = *(undefined8 *)(lVar3 + 0x68);` |
| `FUN_1400bea50` | 1 | 219996 | `*(undefined8 *)(puVar8 + 0x17) = *(undefined8 *)(lVar10 + 0x68);` |
| `FUN_1400c9c30` | 1 | 233238 | `puVar4 = *(undefined4 **)(param_1 + 0x68);` |
| `FUN_1400ca150` | 1 | 233622 | `if ((((ulonglong)(longlong)param_3 < (ulonglong)((*(longlong *)(param_1 + 0x68) - lVar2) / 0x68)` |
| `FUN_1400d2090` | 1 | 243202 | `if (1 < (ulonglong)((*(longlong *)(param_1 + 0x68) - *(longlong *)(param_1 + 0x60)) / 0x68)) {` |
| `FUN_14010ba40` | 1 | 315892 | `iVar24 = (int)(*(float *)(lVar33 + 0x68) * fVar5);` |
| `FUN_140149cf0` | 1 | 440844 | `uVar1 = (**(code **)(param_1 + 0x68))();` |
| `FUN_140149da0` | 1 | 440934 | `uVar1 = (**(code **)(param_1 + 0x68))();` |
| `FUN_1401575b0` | 1 | 458842 | `FUN_1401841e0(*(undefined8 *)(param_1 + 0x68));` |
| `FUN_140158660` | 1 | 460482 | `bVar1 = *(byte *)((longlong)param_2 + *(longlong *)(param_1 + 0x68));` |
| `FUN_14015e2b0` | 1 | 470080 | `*(undefined4 *)(param_2 + 1) = *(undefined4 *)(lVar2 + 0x68);` |
| `FUN_14015ec40` | 1 | 471026 | `local_38 = *(undefined4 *)(local_48 + 0x68);` |
| `FUN_14015fec0` | 1 | 472670 | `uVar3 = *(undefined4 *)(param_1 + 0x68);` |
| `FUN_140161f10` | 1 | 476248 | `(**(code **)(lVar6 + 0x68))` |
| `FUN_140164580` | 1 | 479920 | `iVar4 = *(int *)(param_1 + 0x68);` |
| `FUN_14016a310` | 1 | 487692 | `lVar2 = *(longlong *)(lVar6 + 0x68);` |
| `FUN_14016dd30` | 1 | 493226 | `if ((iVar6 == 0) && (iVar6 = *(int *)(param_1 + 0x68), iVar6 == 0)) {` |
| `FUN_14016e190` | 1 | 493704 | `piVar1 = *(int **)(piVar1 + 0x68)) {` |
| `FUN_14016f980` | 1 | 496346 | `lVar2 = *(longlong *)(lVar6 + 0x68);` |
| `FUN_140172190` | 1 | 500230 | `pcVar2 = *(code **)(lVar3 + 0x68);` |
| `FUN_140176ce0` | 1 | 507698 | `FUN_1401747e0(*(undefined4 *)(param_1 + 0x68));` |
| `FUN_140177140` | 1 | 508154 | `iVar2 = *(int *)(param_1 + 0x68);` |
| `FUN_14018d180` | 1 | 543304 | `if ((lVar9 != 0) && (*(undefined2 *)(lVar9 + 0x67) = 0, *(char *)(lVar9 + 0x68) != '\0')) {` |
| `FUN_1401beac0` | 1 | 627164 | `if ((*(int *)(param_1 + 0x68) != 0) && (*(int *)(param_2 + 0x68) == 0)) {` |
| `FUN_1401c97e0` | 1 | 641626 | `if (*(longlong *)(param_1 + 0x68) != 0) {` |
| `FUN_1401cba40` | 1 | 644488 | `pcVar2 = (code *)FUN_140188550(*(undefined8 *)(param_1 + 0x68),"D3D12GetDebugInterface");` |
| `FUN_1401e3ba0` | 1 | 676308 | `local_b8[uVar4] = *(longlong *)(lVar2 + 0x68);` |
| `FUN_1401e7960` | 1 | 681442 | `(**(code **)(**(longlong **)(lVar1 + 0x68) + 0x48))(*(longlong **)(lVar1 + 0x68),&local_res18);` |
| `FUN_1401e7ec0` | 1 | 681750 | `(**(code **)(**(longlong **)(lVar1 + 0x68) + 0x48))(*(longlong **)(lVar1 + 0x68),local_res8);` |
| `FUN_1401e9660` | 1 | 683894 | `FUN_1401ea070(uVar4,*(undefined8 *)(lVar3 + 0x58),*(undefined4 *)(lVar3 + 0x68),0x80);` |
| `FUN_1401ff0c0` | 1 | 709878 | `local_1c = *(undefined4 *)(lVar2 + 0x68);` |
| `FUN_140204140` | 1 | 716786 | `if ((local_res10[0] != *(int *)(lVar1 + 100)) \|\| (local_res8[0] != *(int *)(lVar1 + 0x68))) {` |
| `FUN_140206640` | 1 | 719558 | `if (((*(short *)(lVar3 + 0x20) != 0x37d7) && (*(longlong *)(lVar3 + 0x68) != 0)) &&` |
| `FUN_140206750` | 1 | 719632 | `(**(code **)(*(longlong *)(lVar1 + 0x68) + 0x88))(lVar1,param_1);` |
| `FUN_1402069a0` | 1 | 719878 | `UNRECOVERED_JUMPTABLE = *(code **)(*(longlong *)(lVar1 + 0x68) + 0x38);` |
| `FUN_1402069e0` | 1 | 719918 | `UNRECOVERED_JUMPTABLE = *(code **)(*(longlong *)(lVar1 + 0x68) + 0x40);` |
| `FUN_140206bd0` | 1 | 720122 | `(**(code **)(*(longlong *)(local_res20 + 0x68) + 0x58))(local_res20,param_1,param_2,param_3);` |
| `FUN_140206c50` | 1 | 720162 | `(**(code **)(*(longlong *)(local_res20 + 0x68) + 0x60))(local_res20,param_1,param_2,param_3);` |
| `FUN_140206d50` | 1 | 720242 | `(**(code **)(*(longlong *)(local_res20 + 0x68) + 0x78))(local_res20,param_1,param_2,param_3);` |
| `FUN_140207920` | 1 | 721310 | `if ((((*(longlong *)(lVar1 + 0x68) != 0) && (*(char *)(lVar1 + 0x9a) == '\0')) &&` |
| `FUN_140207ae0` | 1 | 721460 | `(*(longlong *)(lVar1 + 0x68) != 0)) {` |
| `FUN_140207f20` | 1 | 721894 | `if ((((*(longlong *)(lVar1 + 0x68) != 0) && (*(char *)(lVar1 + 0x9a) == '\0')) &&` |
| `FUN_140208550` | 1 | 722590 | `cVar2 = *(char *)(*(longlong *)(param_1 + 0x68) + 8);` |
| `FUN_1402087d0` | 1 | 722840 | `((((*(longlong *)(lVar5 + 0x68) != 0 \|\| (*(longlong *)(lVar5 + 0xb0) != 0)) &&` |
| `FUN_140208ab0` | 1 | 723034 | `uVar2 = (**(code **)(*(longlong *)(param_1 + 0x68) + 0x68))(param_1,param_2);` |
| `FUN_140209760` | 1 | 724468 | `local_28 = *(undefined8 *)(lVar1 + 0x68);` |
| `FUN_140209880` | 1 | 724548 | `local_28 = *(undefined8 *)(lVar1 + 0x68);` |
| `FUN_14020bb70` | 1 | 727658 | `(**(code **)(lVar1 + 0x78))(*(undefined8 *)(lVar1 + 0x68),param_2);` |
| `FUN_14020bd60` | 1 | 727878 | `(**(code **)(lVar1 + 0x80))(*(undefined8 *)(lVar1 + 0x68),param_2,param_3);` |
| `FUN_14020bde0` | 1 | 727930 | `(**(code **)(lVar1 + 0x88))(*(undefined8 *)(lVar1 + 0x68),param_2,param_3);` |
| `FUN_14020be60` | 1 | 727978 | `(**(code **)(lVar1 + 0x90))(*(undefined8 *)(lVar1 + 0x68),param_2,param_3,param_4);` |
| `FUN_14020bee0` | 1 | 728030 | `(**(code **)(lVar1 + 0x98))(*(undefined8 *)(lVar1 + 0x68),param_2,param_3);` |
| `FUN_14020bf60` | 1 | 728084 | `uVar2 = (**(code **)(lVar1 + 0xa0))(*(undefined8 *)(lVar1 + 0x68),param_2);` |
| `FUN_14020bfd0` | 1 | 728144 | `(**(code **)(lVar1 + 0x70))(*(undefined8 *)(lVar1 + 0x68));` |
| `FUN_14020d110` | 1 | 729758 | `(**(code **)(param_1 + 0xa8))(*(undefined8 *)(param_1 + 0x68));` |
| `FUN_14020fa30` | 1 | 733346 | `return *(undefined4 *)(lVar1 + 0x68);` |
| `FUN_14020fc00` | 1 | 733526 | `(DAT_1403fd3b0,*(undefined4 *)(lVar2 + 0x68),*puVar1,&local_res8);` |
| `FUN_140210280` | 1 | 734152 | `uVar2 = *(uint *)(param_1 + 0x68);` |
| `FUN_1402104a0` | 1 | 734448 | `if ((*(byte *)(lVar9 + 0x68) & 0xe) == 0) {` |
| `FUN_140210780` | 1 | 734594 | `return *(uint *)(param_1 + 0x68) >> 0x12 & 0xffffff01;` |
| `FUN_1402171e0` | 1 | 744694 | `iVar1 = *(int *)(param_1 + 0x68);` |
| `FUN_140218860` | 1 | 747122 | `lVar10 = (**(code **)(lVar10 + 0x68))` |
| `FUN_14025ea00` | 1 | 895590 | `iVar3 = *(int *)(param_1 + 0x68);` |
| `FUN_14025fd90` | 1 | 897522 | `iVar1 = *(int *)(param_1 + 0x68);` |
| `FUN_140271d80` | 1 | 920142 | `CONCAT13(*(undefined1 *)(param_1 + 0x68),` |
| `FUN_140280490` | 1 | 939660 | `*(longlong *)(param_2 + 0x60) = *(longlong *)(param_2 + 0x68) + lVar2;` |
| `FUN_140284a80` | 1 | 944950 | `cVar2 = (**(code **)(*(longlong *)(lVar1 + 0x68) + 0x58))(lVar1,param_2,param_3,param_4);` |
| `FUN_140284b20` | 1 | 945008 | `cVar2 = (**(code **)(*(longlong *)(lVar1 + 0x68) + 0x60))(lVar1,param_2,param_3,param_4);` |
| `FUN_140284bc0` | 1 | 945064 | `uVar2 = (**(code **)(*(longlong *)(lVar1 + 0x68) + 0x68))(lVar1,param_2);` |
| `FUN_140284c40` | 1 | 945122 | `cVar2 = (**(code **)(*(longlong *)(lVar1 + 0x68) + 0x70))` |
| `FUN_140284ce0` | 1 | 945182 | `cVar2 = (**(code **)(*(longlong *)(lVar1 + 0x68) + 0x80))(lVar1,param_2,param_3);` |
| `FUN_140284e00` | 1 | 945296 | `(**(code **)(*(longlong *)(lVar1 + 0x68) + 0x88))(lVar1,param_2);` |
| `FUN_14028b000` | 1 | 954230 | `uVar2 = *(ulonglong *)(param_1 + 0x68);` |
| `FUN_14028b250` | 1 | 954444 | `uVar4 = *(ulonglong *)(param_1 + 0x68);` |
| `FUN_14028c150` | 1 | 955924 | `lVar2 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14028c420` | 1 | 956272 | `lVar3 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14028c720` | 1 | 956634 | `lVar1 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14028c8d0` | 1 | 956836 | `lVar2 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14028ca90` | 1 | 957042 | `lVar2 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14028cc70` | 1 | 957260 | `lVar3 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14028ce40` | 1 | 957480 | `lVar1 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14028cff0` | 1 | 957682 | `lVar2 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14028d1b0` | 1 | 957882 | `lVar2 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14028d480` | 1 | 958228 | `lVar3 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14028d790` | 1 | 958590 | `lVar1 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14028d940` | 1 | 958792 | `lVar2 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14028db00` | 1 | 958996 | `lVar2 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14028dce0` | 1 | 959212 | `lVar3 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14028deb0` | 1 | 959432 | `lVar1 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14028e060` | 1 | 959634 | `lVar2 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14028e220` | 1 | 959834 | `lVar2 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14028e4f0` | 1 | 960182 | `lVar3 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14028e800` | 1 | 960552 | `lVar2 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14028e9a0` | 1 | 960754 | `lVar2 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14028eb60` | 1 | 960962 | `lVar3 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14028ed40` | 1 | 961178 | `lVar4 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14028ef10` | 1 | 961398 | `lVar2 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14028f0c0` | 1 | 961600 | `lVar2 = *(longlong *)(param_1 + 0x68);` |
| `FUN_1402907d0` | 1 | 963290 | `lVar5 = *(longlong *)(param_1 + 0x68);` |
| `FUN_140290920` | 1 | 963446 | `lVar5 = *(longlong *)(param_1 + 0x68);` |
| `FUN_140290bb0` | 1 | 963808 | `lVar5 = *(longlong *)(param_1 + 0x68);` |
| `FUN_140290d10` | 1 | 963988 | `lVar5 = *(longlong *)(param_1 + 0x68);` |
| `FUN_140290ea0` | 1 | 964188 | `lVar5 = *(longlong *)(param_1 + 0x68);` |
| `FUN_140291000` | 1 | 964338 | `lVar5 = *(longlong *)(param_1 + 0x68);` |
| `FUN_140291170` | 1 | 964504 | `lVar5 = *(longlong *)(param_1 + 0x68);` |
| `FUN_1402912d0` | 1 | 964670 | `lVar5 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14029a780` | 1 | 977264 | `lVar7 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14029afc0` | 1 | 977848 | `lVar8 = *(longlong *)(param_1 + 0x68);` |
| `FUN_14029b740` | 1 | 978398 | `lVar12 = *(longlong *)(param_1 + 0x68);` |
| `FUN_1402c8e64` | 1 | 1035864 | `return *(undefined8 *)(lVar1 + 0x68);` |
| `FUN_1402cbdc4` | 1 | 1041966 | `local_58[1] = *(undefined8 *)(param_1 + 0x68);` |
| `FUN_1402e842c` | 1 | 1096242 | `FUN_1402e9a80(*(undefined8 *)(local_20 + 0x68));` |
| `FUN_1402f4f90` | 1 | 1119436 | `if (*(undefined **)(param_1 + 0x68) != PTR_DAT_1403e8ce8) {` |
| `FUN_1402ff9e8` | 1 | 1132810 | `FUN_1402c7784(*(undefined8 *)(param_2 + 0x60),*(undefined8 *)(param_2 + 0x68),` |
| `FUN_140300117` | 1 | 1133794 | `__acrt_unlock(**(undefined4 **)(param_2 + 0x68));` |

## `+0x6c` (108 dec)

47 functions, 56 read sites.

| Function | Hits | First line | First snippet |
|---|---|---|---|
| `FUN_140043c60` | 3 | 75702 | `if (0 < *(int *)(DAT_1403ea2a8 + 0x6c)) {` |
| `FUN_140216260` | 3 | 743338 | `local_res8[0] = local_res8[0] / *(uint *)(param_1 + 0x6c);` |
| `FUN_140043aa0` | 2 | 75438 | `if (0 < *(int *)(DAT_1403ea2a8 + 0x6c)) {` |
| `FUN_1400447e0` | 2 | 76342 | `(longlong)*(int *)(DAT_1403ea2a8 + 0x6c) << 3);` |
| `FUN_14020fa50` | 2 | 733410 | `if ((*(byte *)(lVar1 + 0x6c) & 3) != 0) {` |
| `FUN_140216ab0` | 2 | 744034 | `if (local_res8[0] / *(uint *)(param_1 + 0x6c) != *(uint *)(lVar1 + 0x24)) {` |
| `FUN_140216e70` | 2 | 744444 | `lVar9 = FUN_1401841f0((longlong)*(int *)(param_1 + 0x6c));` |
| `FUN_140016810` | 1 | 21724 | `iVar1 = *(int *)(param_1 + 0x6c);` |
| `FUN_14004f210` | 1 | 91160 | `uVar24 = *(uint *)(param_1 + 0x6c);` |
| `FUN_1400a8a00` | 1 | 197038 | `*(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x6c);` |
| `FUN_1400afc20` | 1 | 204050 | `fVar22 = *(float *)(param_2 + 0x6c) - DAT_1403053e8;` |
| `FUN_1400ba940` | 1 | 216874 | `if ((*(float *)(lVar34 + 0x68) != 0.0) \|\| (*(float *)(lVar34 + 0x6c) != 0.0)) {` |
| `FUN_14010ba40` | 1 | 315894 | `iVar36 = (int)(*(float *)(lVar33 + 0x6c) * fVar5);` |
| `FUN_140130fb0` | 1 | 402756 | `puVar2[1] = *(undefined4 *)(param_1 + 0x6c);` |
| `FUN_140131470` | 1 | 403162 | `piVar1[1] = *(int *)(param_1 + 0x6c);` |
| `FUN_1401319e0` | 1 | 403628 | `uVar1 = *(undefined4 *)(param_1 + 0x6c);` |
| `FUN_140131c30` | 1 | 403882 | `FUN_14012ef10(param_2,param_3,"SDLCamera%d",*(undefined4 *)(param_1 + 0x6c));` |
| `FUN_1401324e0` | 1 | 404730 | `cVar1 = FUN_1401ab340(DAT_1403fb630,*(undefined4 *)(param_1 + 0x6c));` |
| `FUN_1401466d0` | 1 | 436008 | `uVar1 = *(undefined8 *)(param_1 + 0x6c);` |
| `FUN_14015f430` | 1 | 471622 | `uVar1 = *(uint *)(param_1 + 0x6c);` |
| `FUN_1401600c0` | 1 | 472826 | `(int)((*(uint *)(param_1 + 0x6c) /` |
| `FUN_140164580` | 1 | 479916 | `iVar8 = *(int *)(param_1 + 0x6c);` |
| `FUN_140171a90` | 1 | 499578 | `param_2 = *(uint *)(param_1 + 0x6c);` |
| `FUN_140173190` | 1 | 502178 | `FUN_1401cda90(param_1,0x205,*(undefined4 *)(param_1 + 0x6c),*(undefined4 *)(param_1 + 0x70))` |
| `FUN_140176ce0` | 1 | 507696 | `if (*(int *)(param_1 + 0x6c) < 1) {` |
| `FUN_14017dc90` | 1 | 519044 | `(((param_2 = param_1 + 100, param_2 == 0 \|\| (*(int *)(param_1 + 0x6c) < 1)) \|\|` |
| `FUN_140188680` | 1 | 536160 | `iVar2 = *(int *)(param_1 + 0x6c);` |
| `FUN_140188750` | 1 | 536434 | `iVar3 = *(int *)(param_1 + 0x6c);` |
| `FUN_140189250` | 1 | 537436 | `iVar1 = *(int *)(param_1 + 0x6c);` |
| `FUN_140189320` | 1 | 537696 | `iVar3 = *(int *)(param_1 + 0x6c);` |
| `FUN_1401a5ab0` | 1 | 591228 | `bVar6 = *(byte *)(param_1 + 0x6c);` |
| `FUN_1401beac0` | 1 | 627176 | `if ((*(int *)(param_1 + 0x6c) != 0) && (*(int *)(param_2 + 0x6c) == 0)) {` |
| `FUN_1401ff0c0` | 1 | 709880 | `local_18 = *(undefined4 *)(lVar2 + 0x6c);` |
| `FUN_1402161f0` | 1 | 743278 | `*(uint *)(lVar1 + 0x24) = local_res8[0] / *(uint *)(param_1 + 0x6c);` |
| `FUN_140216540` | 1 | 743612 | `iVar2 = *(int *)(param_1 + 0x6c) * 8;` |
| `FUN_1402169b0` | 1 | 743966 | `if (local_res10[0] / *(uint *)(param_1 + 0x6c) !=` |
| `FUN_1402171e0` | 1 | 744678 | `lVar4 = FUN_1401841f0((longlong)*(int *)(param_1 + 0x6c));` |
| `FUN_14022a9d0` | 1 | 773084 | `FUN_140170020(param_1,*(undefined4 *)(param_1 + 0x6c),*(undefined4 *)(param_1 + 0x70),param_5,` |
| `FUN_14022bcb0` | 1 | 775012 | `local_70 = *(undefined4 *)(param_2 + 0x6c);` |
| `FUN_14025bf40` | 1 | 893314 | `((*(int *)(param_1 + 100) + *(int *)(param_1 + 0x6c) <= param_2 \|\|` |
| `FUN_14025ea00` | 1 | 895592 | `iVar4 = *(int *)(param_1 + 0x6c);` |
| `FUN_14025fc80` | 1 | 897418 | `(param_2 < *(int *)(param_1 + 100) + *(int *)(param_1 + 0x6c))) &&` |
| `FUN_14025fd90` | 1 | 897528 | `iVar4 = *(int *)(param_1 + 0x6c);` |
| `FUN_140271460` | 1 | 919512 | `dVar6 = (((double)*(ushort *)(lVar2 + 0x6a) / (double)*(ushort *)(lVar2 + 0x6c)) * DAT_140333080)` |
| `FUN_140271660` | 1 | 919734 | `(float)*(ushort *)(lVar1 + 0x6c)) / (float)*(ushort *)(lVar1 + 0x6a);` |
| `FUN_140274520` | 1 | 923374 | `if (cVar1 != *(char *)(param_1 + 0x6c)) {` |
| `FUN_140282610` | 1 | 942154 | `*(uint *)(param_2 + 0x44) = (uint)*(byte *)(lVar1 + 0x6c);` |

## `+0x70` (112 dec)

232 functions, 309 read sites.

| Function | Hits | First line | First snippet |
|---|---|---|---|
| `FUN_1401c8b30` | 10 | 640474 | `iVar4 = (**(code **)(**(longlong **)(param_1 + 0x70) + 0xd8))` |
| `FUN_1401c7580` | 8 | 638502 | `iVar1 = (**(code **)(**(longlong **)(param_1 + 0x70) + 0xd8))` |
| `FUN_140082640` | 4 | 152306 | `iVar3 = *(int *)(param_1 + 0x70);` |
| `FUN_1401c5ac0` | 4 | 636426 | `iVar3 = (**(code **)(**(longlong **)(param_1 + 0x70) + 0x48))` |
| `FUN_1401c7e90` | 4 | 639178 | `iVar1 = (**(code **)(**(longlong **)(param_1 + 0x70) + 0x70))` |
| `FUN_1401ca1e0` | 4 | 642390 | `(**(code **)(**(longlong **)(param_1 + 0x70) + 0x90))` |
| `FUN_1401ccd30` | 4 | 646158 | `iVar2 = (**(code **)(**(longlong **)(param_1 + 0x70) + 0x68))` |
| `FUN_140043c60` | 3 | 75706 | `lVar2 = *(longlong *)(uVar5 + *(longlong *)(lVar3 + 0x70));` |
| `FUN_1400447e0` | 3 | 76340 | `FUN_1402f8e20(uVar3,*(undefined8 *)(DAT_1403ea2a8 + 0x70),` |
| `FUN_1400df280` | 3 | 257270 | `*(longlong *)(lVar9 + 0x78) - *(longlong *)(lVar9 + 0x70) >> 2;` |
| `FUN_1402648d0` | 3 | 903342 | `*(undefined1 *)(lVar2 + 0x155) = *(undefined1 *)(param_2 + 0x70);` |
| `FUN_1402c4b40` | 3 | 1025240 | `if (*(longlong *)(lVar1 + 0x70) != 0) {` |
| `FUN_1402c4ba0` | 3 | 1025290 | `if (*(longlong *)(lVar1 + 0x70) != 0) {` |
| `FUN_140010430` | 2 | 13816 | `for (lVar1 = *(longlong *)(param_1 + 0x70); lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 8)) {` |
| `FUN_140011000` | 2 | 14792 | `if ((*(longlong **)(param_1 + 0x70) != (longlong *)0x0) && ((*(byte *)(param_2 + 8) & 2) != 0)) {` |
| `FUN_1400111f0` | 2 | 14984 | `iVar1 = *(int *)(lVar11 + 0x70);` |
| `FUN_140043aa0` | 2 | 75442 | `lVar1 = *(longlong *)(uVar7 + *(longlong *)(DAT_1403ea2a8 + 0x70));` |
| `FUN_140080e40` | 2 | 150642 | `iVar10 = *(int *)(param_1 + 0x70);` |
| `FUN_1400b5fe0` | 2 | 210366 | `for (lVar6 = *(longlong *)(lVar5 + 0x70); lVar6 != 0; lVar6 = *(longlong *)(lVar6 + 8)) {` |
| `FUN_1400ba940` | 2 | 216978 | `FUN_14000b2f0(uVar2,(float)(*(uint *)(lVar34 + 0x70) ^ uVar10) * fVar36);` |
| `FUN_1400fbae0` | 2 | 295704 | `if ((((*(char *)(param_1 + 0x70) != '\0') && (cVar3 == '\0')) &&` |
| `FUN_14015a3a0` | 2 | 464084 | `if (0 < *(int *)(param_1 + 0x70)) {` |
| `FUN_14016fc90` | 2 | 496994 | `if ((*(code **)(lVar7 + 0x70) != (code *)0x0) &&` |
| `FUN_140176ce0` | 2 | 507730 | `DAT_1403fc480 = *(longlong *)(param_1 + 0x70);` |
| `FUN_1401b9390` | 2 | 619072 | `if (*(longlong *)(param_2 + 0x70) != 0) {` |
| `FUN_1401c3bd0` | 2 | 633696 | `iVar3 = (**(code **)(**(longlong **)(param_1 + 0x70) + 0x58))` |
| `FUN_1401c3db0` | 2 | 634044 | `iVar6 = (**(code **)(**(longlong **)(param_1 + 0x70) + 0x50))` |
| `FUN_1401c4180` | 2 | 634212 | `(**(code **)(**(longlong **)(param_1 + 0x70) + 0xb0))` |
| `FUN_1401c79e0` | 2 | 639092 | `iVar3 = (**(code **)(**(longlong **)(param_1 + 0x70) + 0x80))` |
| `FUN_1401c7fa0` | 2 | 639720 | `iVar3 = (**(code **)(**(longlong **)(param_1 + 0x70) + 0x80))` |
| `FUN_1401c97e0` | 2 | 641582 | `if (*(longlong **)(param_1 + 0x70) != (longlong *)0x0) {` |
| `FUN_1401cb240` | 2 | 643714 | `if ((param_3 == 0x887a0005) && (*(longlong **)(param_1 + 0x70) != (longlong *)0x0)) {` |
| `FUN_1401cbac0` | 2 | 644538 | `iVar1 = (**(code **)**(undefined8 **)(param_1 + 0x70))` |
| `FUN_1401cbb30` | 2 | 644602 | `iVar1 = (**(code **)**(undefined8 **)(param_1 + 0x70))` |
| `FUN_1401ccbd0` | 2 | 646046 | `iVar1 = (**(code **)(**(longlong **)(param_1 + 0x70) + 0x68))` |
| `FUN_1401ccc40` | 2 | 646086 | `iVar1 = (**(code **)(**(longlong **)(param_1 + 0x70) + 0x68))` |
| `FUN_1401ee270` | 2 | 689494 | `(**(code **)(lVar2 + 0x70))(fVar16,fVar17,fVar15,fVar1);` |
| `FUN_140209270` | 2 | 724100 | `*(int *)(param_1 + 0x70) + ((uint)*puVar16 - (uint)puVar16[-1]) + 1;` |
| `FUN_14020a950` | 2 | 726196 | `cVar1 = *(char *)(DAT_1403fd1c0 + 0x70);` |
| `FUN_14020bfd0` | 2 | 728142 | `if (*(code **)(lVar1 + 0x70) != (code *)0x0) {` |
| `FUN_14020de30` | 2 | 730876 | `if (*(int *)(param_1 + 0x70) < 0xff) {` |
| `FUN_140271460` | 2 | 919480 | `lVar2 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140271660` | 2 | 919680 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140280040` | 2 | 939110 | `if (*(char *)(*(longlong *)(param_1 + 0x70) + 9) != '\0') {` |
| `FUN_140280490` | 2 | 939644 | `if ((*(int *)(param_2 + 0x70) != 0) &&` |
| `FUN_140282590` | 2 | 942062 | `if (*(char *)(*(longlong *)(param_1 + 0x70) + 0xe) != '\0') {` |
| `FUN_140282990` | 2 | 942480 | `lVar3 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140005cf0` | 1 | 1934 | `lVar3 = *(longlong *)(lVar2 + 0x70);` |
| `FUN_1400063f0` | 1 | 2822 | `if ((*(char *)(lVar4 + 0x70) != '\x01') &&` |
| `FUN_14000d3c0` | 1 | 10406 | `puVar1[0xe] = *(undefined8 *)(param_1 + 0x70);` |
| `FUN_14000fbc0` | 1 | 13292 | `*(undefined8 *)(pfVar4 + 2) = *(undefined8 *)(param_1 + 0x70);` |
| `FUN_140010010` | 1 | 13544 | `lVar2 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140010140` | 1 | 13622 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140010240` | 1 | 13702 | `for (lVar1 = *(longlong *)(param_1 + 0x70); lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 8)) {` |
| `FUN_140010310` | 1 | 13748 | `lVar3 = *(longlong *)(param_1 + 0x70);` |
| `FUN_14001dc60` | 1 | 29146 | `*(undefined4 *)(param_1 + 0x70));` |
| `FUN_14001e1a0` | 1 | 29620 | `*(undefined4 *)(param_1 + 0x70));` |
| `FUN_14001f210` | 1 | 31004 | `lVar13 = (longlong)*(int *)(lVar20 + 0x70);` |
| `FUN_14004f210` | 1 | 91198 | `local_a0 = *(ulonglong *)(param_1 + 0x70);` |
| `FUN_14006dbf0` | 1 | 127120 | `FUN_140075670(*(undefined4 *)(param_1 + 0x70));` |
| `FUN_14006f460` | 1 | 128940 | `FUN_140075690(*(undefined1 *)(param_1 + 0x70));` |
| `FUN_140081600` | 1 | 151016 | `uVar1 = *(uint *)(param_1 + 0x70);` |
| `FUN_140081d10` | 1 | 151590 | `uVar1 = *(uint *)(param_1 + 0x70);` |
| `FUN_140081fa0` | 1 | 151728 | `&& (*(int *)(param_1 + 0x70) != 0xb)) {` |
| `FUN_140082410` | 1 | 152000 | `iVar1 = *(int *)(param_1 + 0x70);` |
| `FUN_140084570` | 1 | 154716 | `for (lVar1 = *(longlong *)(param_1 + 0x70); lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 8)) {` |
| `FUN_1400845f0` | 1 | 154780 | `for (lVar1 = *(longlong *)(param_1 + 0x70); lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 8)) {` |
| `FUN_140084b70` | 1 | 155078 | `for (lVar1 = *(longlong *)(param_1 + 0x70); lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 8)) {` |
| `FUN_1400b6170` | 1 | 210496 | `for (lVar4 = *(longlong *)(lVar1 + 0x70); lVar4 != 0; lVar4 = *(longlong *)(lVar4 + 8)) {` |
| `FUN_1400b6890` | 1 | 211034 | `for (lVar4 = *(longlong *)(lVar2 + 0x70); lVar4 != 0; lVar4 = *(longlong *)(lVar4 + 8)) {` |
| `FUN_1400b6990` | 1 | 211116 | `for (lVar4 = *(longlong *)(lVar2 + 0x70); lVar4 != 0; lVar4 = *(longlong *)(lVar4 + 8)) {` |
| `FUN_1400b6aa0` | 1 | 211232 | `(lVar4 = *(longlong *)(lVar3 + 0x70), lVar4 != 0)) {` |
| `FUN_1400b6fd0` | 1 | 211716 | `uStack_a8 = *(undefined8 *)(lVar3 + 0x70);` |
| `FUN_1400bea50` | 1 | 219994 | `uVar5 = *(undefined8 *)(lVar10 + 0x70);` |
| `FUN_1400c9c30` | 1 | 233266 | `if ((ulonglong)((*(longlong *)(param_1 + 0x70) - lVar8) / 0x68) < uVar7) {` |
| `FUN_1400e3520` | 1 | 261324 | `lVar4 = *(longlong *)(lVar4 + 0x70);` |
| `FUN_140106bc0` | 1 | 309738 | `(*(int *)(lVar5 + 0x70) != 0xd)) {` |
| `FUN_140107190` | 1 | 310098 | `((*(int *)(lVar2 + 0x1fc) < *(int *)(lVar2 + 0x200) && (*(int *)(lVar12 + 0x70) != 0xd))))` |
| `FUN_140137fd0` | 1 | 413278 | `(**(code **)(param_1 + 0x70))(*(undefined8 *)(param_1 + 0x298));` |
| `FUN_140155130` | 1 | 455952 | `cVar3 = (**(code **)(lVar2 + 0x70))(lVar2,puVar6);` |
| `FUN_140158030` | 1 | 459794 | `if (param_2 < *(int *)(param_1 + 0x70)) {` |
| `FUN_140159110` | 1 | 461808 | `uVar1 = *(undefined4 *)(param_1 + 0x70);` |
| `FUN_14015e240` | 1 | 470030 | `uVar2 = FUN_14015dd70(*(undefined8 *)(lVar1 + 0x70),uVar3);` |
| `FUN_14015fec0` | 1 | 472762 | `FUN_140168720(puVar9,puVar1,lVar10 + (longlong)puVar9,*(undefined8 *)(param_1 + 0x70),` |
| `FUN_140161f10` | 1 | 476250 | `(*(undefined8 *)(lVar6 + 0x70),param_1,param_2,param_3,&param_5,&param_6);` |
| `FUN_140164580` | 1 | 479928 | `lVar10 = FUN_1401648f0(param_1,*(undefined4 *)(param_1 + 0x70),*puVar1);` |
| `FUN_140171350` | 1 | 498926 | `pcVar1 = *(code **)(lVar4 + 0x70);` |
| `FUN_140171a90` | 1 | 499584 | `param_3 = *(uint *)(param_1 + 0x70);` |
| `FUN_140173190` | 1 | 502178 | `FUN_1401cda90(param_1,0x205,*(undefined4 *)(param_1 + 0x6c),*(undefined4 *)(param_1 + 0x70))` |
| `FUN_1401777e0` | 1 | 508766 | `for (lVar1 = DAT_1403fc480; lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x70)) {` |
| `FUN_14017dc90` | 1 | 519046 | `(*(int *)(param_1 + 0x70) < 1)))) {` |
| `FUN_14017ff80` | 1 | 523346 | `pcVar1 = *(code **)(param_1 + 0x70);` |
| `FUN_14018a130` | 1 | 538984 | `iVar1 = *(int *)(param_1 + 0x70);` |
| `FUN_1401a6b30` | 1 | 592292 | `(ulonglong)*(uint *)(param_1 + 0x70) + 0x392aa + param_1,uVar1);` |
| `FUN_1401abb10` | 1 | 599840 | `iVar1 = strcmp(*(char **)(param_1 + 0x70),param_2);` |
| `FUN_1401ac730` | 1 | 600932 | `pcVar6 = *(char **)(param_1 + 0x70);` |
| `FUN_1401beac0` | 1 | 627188 | `if ((*(int *)(param_1 + 0x70) != 0) && (*(int *)(param_2 + 0x70) == 0)) {` |
| `FUN_1401c5560` | 1 | 635972 | `iVar1 = (**(code **)(**(longlong **)(param_1 + 0x70) + 0x120))();` |
| `FUN_1401e2180` | 1 | 673938 | `FUN_1401841e0(*(undefined8 *)(lVar1 + 0x70));` |
| `FUN_1401e2730` | 1 | 674630 | `lVar5 = *(longlong *)(lVar1 + 0x70);` |
| `FUN_1401e45b0` | 1 | 677246 | `(longlong)(int)(uVar4 * *(int *)(lVar1 + 0x7c)) + *(longlong *)(lVar1 + 0x70),` |
| `FUN_1401e7230` | 1 | 681140 | `*(longlong *)(puVar8 + 10) + (ulonglong)*(uint *)(lVar3 + 0x70) * *(longlong *)(puVar8 + 8)` |
| `FUN_1401e7960` | 1 | 681444 | `local_res18 = local_res18 + (ulonglong)(uint)((int)uVar7 * *(int *)(lVar1 + 0x70));` |
| `FUN_1401e7cc0` | 1 | 681606 | `FUN_1401e7e30(param_1,*(undefined8 *)(lVar1 + 0x70));` |
| `FUN_1401e7ec0` | 1 | 681752 | `return (ulonglong)(uint)(*(int *)(lVar1 + 200) * *(int *)(lVar1 + 0x70)) + local_res8[0];` |
| `FUN_1401f3710` | 1 | 695662 | `(iVar4 = memcmp(puVar5,*(void **)(lVar7 + 0x70),(size_t)puVar12), iVar4 != 0)))))) {` |
| `FUN_1401f6480` | 1 | 698986 | `local_20 = *(undefined4 *)(lVar1 + 0x70);` |
| `FUN_1401fd220` | 1 | 707534 | `fVar13 = (float)*(int *)(param_3 + 4) / (float)*(int *)(lVar6 + 0x70);` |
| `FUN_140202720` | 1 | 714770 | `FUN_140138370(*(undefined8 *)(puVar6 + 8),param_2,*(undefined4 *)(puVar6 + 0x70),` |
| `FUN_140204950` | 1 | 717408 | `*(undefined4 *)(lVar1 + 0x70),local_res8[0]);` |
| `FUN_140207340` | 1 | 720774 | `if (*(longlong *)(param_1 + 0x70) != 0) {` |
| `FUN_140209760` | 1 | 724470 | `uStack_20 = *(undefined8 *)(lVar1 + 0x70);` |
| `FUN_140209880` | 1 | 724550 | `uStack_20 = *(undefined8 *)(lVar1 + 0x70);` |
| `FUN_14020a370` | 1 | 725572 | `iVar18 = *(int *)(param_1 + 0x70) - (uint)(byte)pcVar11[0x38];` |
| `FUN_14020ad80` | 1 | 726530 | `uVar12 = *(int *)(param_1 + 0x70) - 1;` |
| `FUN_14020fa50` | 1 | 733378 | `lVar1 = *(longlong *)(lVar4 + 0x70);` |
| `FUN_14020fd00` | 1 | 733620 | `cVar1 = FUN_140210780(*(undefined8 *)(lVar2 + 0x70));` |
| `FUN_14020fe40` | 1 | 733774 | `uVar13 = (ulonglong)*(int *)(param_1 + 0x70);` |
| `FUN_140218ef0` | 1 | 747500 | `(**(code **)(lVar1 + 0x70))(*(undefined8 *)(lVar1 + 0x10));` |
| `FUN_14022a9d0` | 1 | 773084 | `FUN_140170020(param_1,*(undefined4 *)(param_1 + 0x6c),*(undefined4 *)(param_1 + 0x70),param_5,` |
| `FUN_14022bcb0` | 1 | 775014 | `local_6c = *(undefined4 *)(param_2 + 0x70);` |
| `FUN_140240d00` | 1 | 863290 | `(**(code **)(param_1 + 0x70))(iVar2,*param_3,param_3[1],param_3[2],param_3[3]);` |
| `FUN_14025bf40` | 1 | 893316 | `(*(int *)(param_1 + 0x70) + *(int *)(param_1 + 0x68) <= param_3)))) {` |
| `FUN_14025ea00` | 1 | 895594 | `iVar5 = *(int *)(param_1 + 0x70);` |
| `FUN_14025fc80` | 1 | 897420 | `(param_3 < *(int *)(param_1 + 0x70) + *(int *)(param_1 + 0x68))) {` |
| `FUN_14025fd90` | 1 | 897526 | `iVar3 = *(int *)(param_1 + 0x70);` |
| `FUN_140263ad0` | 1 | 902304 | `pcVar1 = *(char **)(param_1 + 0x70);` |
| `FUN_140263bb0` | 1 | 902366 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140263c20` | 1 | 902426 | `pcVar1 = *(char **)(param_1 + 0x70);` |
| `FUN_140263d00` | 1 | 902542 | `pcVar1 = *(char **)(param_1 + 0x70);` |
| `FUN_140263d60` | 1 | 902588 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140264c60` | 1 | 903654 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140264ec0` | 1 | 903832 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140268130` | 1 | 908158 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140268760` | 1 | 908662 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140268990` | 1 | 908826 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140268af0` | 1 | 908918 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140268b70` | 1 | 908984 | `lVar2 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140268c40` | 1 | 909076 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140268cd0` | 1 | 909136 | `plVar1 = *(longlong **)(param_1 + 0x70);` |
| `FUN_140268ee0` | 1 | 909308 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_14026cfc0` | 1 | 914448 | `lVar2 = *(longlong *)(param_1 + 0x70);` |
| `FUN_14026d740` | 1 | 915154 | `puVar1 = *(undefined8 **)(param_1 + 0x70);` |
| `FUN_14026d850` | 1 | 915274 | `uVar1 = *(undefined8 *)(param_1 + 0x70);` |
| `FUN_14026e410` | 1 | 915990 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_14026e4e0` | 1 | 916082 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_14026e800` | 1 | 916360 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_14026e8a0` | 1 | 916430 | `uVar1 = *(undefined8 *)(param_1 + 0x70);` |
| `FUN_14026eba0` | 1 | 916682 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_14026fe90` | 1 | 917734 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_14026ff30` | 1 | 917796 | `lVar2 = *(longlong *)(param_1 + 0x70);` |
| `FUN_14026ff80` | 1 | 917842 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_1402704d0` | 1 | 918380 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140270650` | 1 | 918454 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_1402706d0` | 1 | 918538 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_1402709a0` | 1 | 918718 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140271d10` | 1 | 920050 | `if (*(char *)(*(longlong *)(param_1 + 0x70) + 0x20) != '\0') {` |
| `FUN_140272660` | 1 | 920944 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140272770` | 1 | 921052 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140272890` | 1 | 921102 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140272910` | 1 | 921176 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140272b70` | 1 | 921344 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140273ce0` | 1 | 922738 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140274270` | 1 | 923032 | `if (*(char *)(*(longlong *)(param_1 + 0x70) + 0x20) == '\0') {` |
| `FUN_1402746d0` | 1 | 923542 | `lVar2 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140274790` | 1 | 923654 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140274860` | 1 | 923710 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140275130` | 1 | 924218 | `pcVar1 = *(char **)(param_1 + 0x70);` |
| `FUN_140275210` | 1 | 924302 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_1402753d0` | 1 | 924458 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_1402754a0` | 1 | 924572 | `uVar1 = *(undefined8 *)(param_1 + 0x70);` |
| `FUN_140275c20` | 1 | 925084 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140275e10` | 1 | 925304 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140275eb0` | 1 | 925408 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_1402764e0` | 1 | 925682 | `FUN_140142b00("SDL_JOYSTICK_HIDAPI_STEAM_HOME_LED",FUN_140276fb0,*(undefined8 *)(param_1 + 0x70));` |
| `FUN_140276510` | 1 | 925708 | `uVar1 = *(undefined8 *)(param_1 + 0x70);` |
| `FUN_140276650` | 1 | 925898 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_1402766c0` | 1 | 925936 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140277890` | 1 | 927962 | `lVar2 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140277990` | 1 | 928046 | `fVar1 = (DAT_14039ca44 / (float)**(uint **)(param_1 + 0x70)) * DAT_14037f68c;` |
| `FUN_140277c00` | 1 | 928396 | `puVar2 = *(uint **)(param_1 + 0x70);` |
| `FUN_140278210` | 1 | 928602 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140278330` | 1 | 928692 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140278390` | 1 | 928738 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_1402783e0` | 1 | 928800 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140278540` | 1 | 928898 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140279a40` | 1 | 930754 | `uVar1 = *(undefined8 *)(param_1 + 0x70);` |
| `FUN_140279dd0` | 1 | 931146 | `lVar2 = *(longlong *)(param_1 + 0x70);` |
| `FUN_14027a2e0` | 1 | 931668 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_14027a3f0` | 1 | 931794 | `uVar1 = *(undefined8 *)(param_1 + 0x70);` |
| `FUN_14027a4e0` | 1 | 931844 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_14027aa60` | 1 | 932230 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_14027ab70` | 1 | 932368 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_14027b480` | 1 | 933050 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_14027b600` | 1 | 933138 | `if (*(char *)(*(longlong *)(param_1 + 0x70) + 0x29) == '\0') {` |
| `FUN_14027b670` | 1 | 933194 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_14027b820` | 1 | 933286 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_14027d2e0` | 1 | 935612 | `uVar1 = *(undefined8 *)(param_1 + 0x70);` |
| `FUN_14027d490` | 1 | 935728 | `puVar1 = *(undefined8 **)(param_1 + 0x70);` |
| `FUN_14027dd30` | 1 | 936256 | `pcVar1 = *(char **)(param_1 + 0x70);` |
| `FUN_14027df70` | 1 | 936464 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_14027e0d0` | 1 | 936662 | `lVar2 = *(longlong *)(param_1 + 0x70);` |
| `FUN_14027e520` | 1 | 936846 | `if (**(char **)(param_1 + 0x70) != param_2) {` |
| `FUN_14027e740` | 1 | 937082 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_14027ebd0` | 1 | 937462 | `puVar1 = *(ushort **)(param_1 + 0x70);` |
| `FUN_14027f5a0` | 1 | 938100 | `if (*(char *)(*(longlong *)(param_1 + 0x70) + 0x21) == '\0') {` |
| `FUN_14027f720` | 1 | 938252 | `*(short *)(*(longlong *)(param_1 + 0x70) + 0x22) = (short)iVar2;` |
| `FUN_14027fd90` | 1 | 938748 | `pcVar1 = *(char **)(param_1 + 0x70);` |
| `FUN_14027fea0` | 1 | 938964 | `if (*(char *)(*(longlong *)(param_1 + 0x70) + 4) == '\0') {` |
| `FUN_14027ff50` | 1 | 939018 | `uVar1 = *(undefined8 *)(param_1 + 0x70);` |
| `FUN_140280b80` | 1 | 939818 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140280d00` | 1 | 940010 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140281cc0` | 1 | 941236 | `lVar2 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140281e30` | 1 | 941346 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140281f20` | 1 | 941430 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140282610` | 1 | 942132 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140282720` | 1 | 942258 | `if (*(char *)(*(longlong *)(param_1 + 0x70) + 0x10) != '\0') {` |
| `FUN_1402827e0` | 1 | 942334 | `if (*(char *)(*(longlong *)(param_1 + 0x70) + 0xf) == '\0') {` |
| `FUN_1402828a0` | 1 | 942402 | `uVar1 = *(undefined8 *)(param_1 + 0x70);` |
| `FUN_140283130` | 1 | 943088 | `lVar1 = *(longlong *)(param_1 + 0x70);` |
| `FUN_140283640` | 1 | 943496 | `puVar1 = *(undefined8 **)(param_1 + 0x70);` |
| `FUN_140283780` | 1 | 943642 | `uVar2 = *(undefined8 *)(param_1 + 0x70);` |
| `FUN_140285a70` | 1 | 946602 | `bVar2 = *(byte *)(param_2 + 0x70);` |
| `FUN_1402a05f0` | 1 | 984078 | `uVar11 = *(undefined8 *)(param_1 + 0x70);` |
| `FUN_1402e842c` | 1 | 1096236 | `FUN_1402e9a80(*(undefined8 *)(local_20 + 0x70));` |
| `FUN_1402f4f90` | 1 | 1119442 | `if (*(undefined **)(param_1 + 0x70) != PTR_DAT_1403e8cf0) {` |
| `FUN_1402fdd80` | 1 | 1131208 | `FUN_1402c7088(*(undefined8 *)(param_2 + 0x70),0x498);` |
| `FUN_1402fe0ce` | 1 | 1131316 | `FUN_1402c7088(*(undefined8 *)(param_2 + 0x70),0x498);` |
| `FUN_1402ff9e8` | 1 | 1132812 | `*(undefined8 *)(param_2 + 0x70),*(undefined8 *)(param_2 + 0x78));` |
| `FUN_1402ffa6f` | 1 | 1132882 | `*(undefined8 *)(param_2 + 0x28),*(undefined8 *)(param_2 + 0x70));` |
| `FUN_1402fffc1` | 1 | 1133552 | `FUN_1402e171c(*(undefined8 *)(param_2 + 0x70));` |
| `FUN_1402ffff2` | 1 | 1133588 | `if (*(char *)(param_2 + 0x70) != '\0') {` |

## `+0x74` (116 dec)

25 functions, 31 read sites.

| Function | Hits | First line | First snippet |
|---|---|---|---|
| `FUN_1400fbae0` | 3 | 295828 | `uVar7 = *(uint *)(param_1 + 0x74) & 0x80000003;` |
| `FUN_1400816b0` | 2 | 151140 | `iVar7 = *(int *)(param_1 + 0x74) / 3;` |
| `FUN_14008b6f0` | 2 | 163990 | `FUN_140072e40(CONCAT44(fVar2 - *(float *)(DAT_1403fb0d8 + 0x74),` |
| `FUN_1400ba940` | 2 | 216986 | `FUN_14000b2f0(uVar2,fVar36 * *(float *)(lVar34 + 0x74));` |
| `FUN_1401a6b30` | 2 | 592284 | `if (*(uint *)(param_1 + 0x74) <= uVar1) {` |
| `FUN_1400111f0` | 1 | 14986 | `iVar2 = *(int *)(lVar11 + 0x74);` |
| `FUN_14001f210` | 1 | 31012 | `lVar14 = (longlong)*(int *)(lVar20 + 0x74);` |
| `FUN_14006f460` | 1 | 128944 | `FUN_1400756b0(*(undefined2 *)(param_1 + 0x74));` |
| `FUN_140080e40` | 1 | 150710 | `iVar6 = *(int *)(param_1 + 0x74);` |
| `FUN_140081600` | 1 | 151012 | `if (((fVar3 <= (float)*(int *)(param_1 + 0x74)) && (0 < *(int *)(uVar2 + 0x1fc))) &&` |
| `FUN_140082060` | 1 | 151798 | `(*(int *)(param_1 + 0x8c) / 2 + *(int *)(param_1 + 0x74) / 2);` |
| `FUN_1400820a0` | 1 | 151852 | `(*(int *)(param_1 + 0x8c) / 2 + *(int *)(param_1 + 0x74) / 2) *` |
| `FUN_140082640` | 1 | 152284 | `iVar6 = *(int *)(param_1 + 0x74);` |
| `FUN_1400fc520` | 1 | 296292 | `uVar9 = (int)((*(int *)(param_1 + 0x74) >> 0x1f & 3U) + *(int *)(param_1 + 0x74)) >> 2 &` |
| `FUN_140107660` | 1 | 313334 | `if ((((*(int *)(lVar16 + 0x74) < *(int *)(lVar16 + 0x8c) / 2) &&` |
| `FUN_140173190` | 1 | 502184 | `FUN_1401cda90(param_1,0x206,*(undefined4 *)(param_1 + 0x74),` |
| `FUN_1401beac0` | 1 | 627200 | `if ((*(int *)(param_1 + 0x74) != 0) && (*(int *)(param_2 + 0x74) == 0)) {` |
| `FUN_1401f6480` | 1 | 698988 | `local_1c = *(undefined4 *)(lVar1 + 0x74);` |
| `FUN_1401fd220` | 1 | 707536 | `fVar14 = (float)*(int *)(param_3 + 8) / (float)*(int *)(lVar6 + 0x74);` |
| `FUN_140202720` | 1 | 714772 | `*(undefined4 *)(puVar6 + 0x74));` |
| `FUN_140204950` | 1 | 717404 | `if (local_res8[0] != *(int *)(lVar1 + 0x74)) {` |
| `FUN_14022a1e0` | 1 | 772552 | `if (((*(int *)(param_2 + 0x74) != 0) && (*(int *)(param_2 + 0x74) != local_38.right)) \|\|` |
| `FUN_14022a9d0` | 1 | 773090 | `*param_7 = *(int *)(param_1 + 0x74);` |
| `FUN_14022b770` | 1 | 774348 | `iVar3 = *(int *)(param_2 + 0x74);` |
| `FUN_140282ba0` | 1 | 942958 | `iVar3 = *(int *)(param_2 + 0x74);` |

## `+0x78` (120 dec)

255 functions, 337 read sites.

| Function | Hits | First line | First snippet |
|---|---|---|---|
| `FUN_14005d190` | 8 | 108574 | `*(undefined1 *)(*(longlong *)(param_1 + 0x78) + lVar9 + lVar8) =` |
| `FUN_140063410` | 6 | 115606 | `fVar4 = (*(float *)(*(longlong *)(param_1 + 0x78) + 0x38) * DAT_14039ca34 +` |
| `FUN_1400dde40` | 6 | 255866 | `lVar7 = *(longlong *)(param_1 + 0x78);` |
| `FUN_140082640` | 5 | 152298 | `iVar10 = *(int *)(param_1 + 0x78) + 1;` |
| `FUN_1400f5280` | 5 | 288506 | `lVar20 = *(longlong *)(param_1 + 0x78);` |
| `FUN_14001f210` | 3 | 31014 | `fVar10 = *(float *)(lVar20 + 0x78);` |
| `FUN_1400d23d0` | 3 | 243382 | `if (((ulonglong)(*(longlong *)(param_1 + 0x80) - *(longlong *)(param_1 + 0x78) >> 4) < 4) \|\|` |
| `FUN_1400df280` | 3 | 257270 | `*(longlong *)(lVar9 + 0x78) - *(longlong *)(lVar9 + 0x70) >> 2;` |
| `FUN_1400fa910` | 3 | 294342 | `fVar14 = (*(float **)(param_1 + 0x78))[2] * DAT_14039ca34;` |
| `FUN_1401f14c0` | 3 | 692806 | `(**(code **)(lVar1 + 0x78))(1,piVar2);` |
| `FUN_140205900` | 3 | 718562 | `uVar2 = FUN_140137ac0(*(undefined8 *)(param_1 + 8),*(undefined8 *)(param_1 + 0x78),1);` |
| `FUN_1402c4ad0` | 3 | 1025192 | `if (*(longlong *)(param_2 + 0x78) != 0) {` |
| `FUN_1402ca7bc` | 3 | 1039902 | `if (*(int *)(lVar9 + 0x78) != -2) {` |
| `FUN_1402cc3e0` | 3 | 1042564 | `if (*(int *)(lVar6 + 0x78) != -2) {` |
| `FUN_1402e01d4` | 3 | 1080082 | `iVar2 = FUN_1402dfea0(this + 8,*(undefined8 *)(this + 0x78));` |
| `FUN_140026b90` | 2 | 40632 | `if (*(longlong *)(param_1 + 0x78) != 0) {` |
| `FUN_14005d360` | 2 | 108690 | `if ((*(int *)(param_1 + 0xc) == 0xc) && (*(longlong *)(param_1 + 0x78) != 0)) {` |
| `FUN_14005fcf0` | 2 | 111456 | `FUN_1400c57a0(&local_res8,*(longlong *)(param_1 + 0x78) + 0x30,fVar2);` |
| `FUN_140065c10` | 2 | 118476 | `local_38 = *(undefined8 *)(*(longlong *)(param_1 + 0x78) + 0x30);` |
| `FUN_14006dbf0` | 2 | 127122 | `FUN_140075670(*(longlong *)(param_1 + 0x78) != 0);` |
| `FUN_1400886a0` | 2 | 160008 | `lVar4 = *(longlong *)(param_1 + 0x78);` |
| `FUN_140089510` | 2 | 161304 | `FUN_1400a5400(*(undefined8 *)(lVar14 + 0x78));` |
| `FUN_1400b9250` | 2 | 214368 | `else if ((iVar9 == 0xc) && (*(longlong *)(param_2 + 0x78) != 0)) {` |
| `FUN_1400ccb10` | 2 | 236550 | `pfVar1 = *(float **)(param_1 + 0x78);` |
| `FUN_1400cd0f0` | 2 | 237098 | `*(undefined8 *)(param_1 + 0x78),0), cVar3 == '\0')) {` |
| `FUN_1400cddd0` | 2 | 238042 | `*(undefined8 *)(param_1 + 0x78),0);` |
| `FUN_1400cf540` | 2 | 239592 | `lVar3 = *(longlong *)(param_1 + 0x78);` |
| `FUN_1400d5ff0` | 2 | 247312 | `uVar10 = *(undefined8 *)(param_1 + 0x78);` |
| `FUN_1400dbb00` | 2 | 253198 | `(float)((double)(*(float *)(*(longlong *)(param_1 + 0x78) + 0x3c) +` |
| `FUN_1400e25b0` | 2 | 260776 | `fVar9 = *(float *)(*(longlong *)(param_1 + 0x78) + 0x38);` |
| `FUN_1400f9bd0` | 2 | 293838 | `fVar19 = **(float **)(param_1 + 0x78) + DAT_14039ca34;` |
| `FUN_1400fc520` | 2 | 296372 | `if (7 < (int)*(uint *)(param_1 + 0x78)) {` |
| `FUN_140161f10` | 2 | 476192 | `if ((*(byte *)(lVar6 + 0x78) & 1) != 0) {` |
| `FUN_14016fc90` | 2 | 497004 | `if ((*(code **)(lVar7 + 0x78) != (code *)0x0) &&` |
| `FUN_1401b9390` | 2 | 619082 | `if (*(longlong *)(param_2 + 0x78) != 0) {` |
| `FUN_1401e2730` | 2 | 674678 | `*param_4 = (longlong)(int)(uVar7 * *param_3) + param_3[1] * *(int *)(lVar1 + 0x78) + lVar5;` |
| `FUN_1401e45b0` | 2 | 677244 | `(longlong)(*(int *)(lVar1 + 0x78) * *(int *)(lVar1 + 0x80)) +` |
| `FUN_1401e7cc0` | 2 | 681596 | `if (*(longlong **)(lVar1 + 0x78) != (longlong *)0x0) {` |
| `FUN_1401f8a10` | 2 | 702570 | `local_b8 = *(undefined8 *)(lVar8 + 0x78);` |
| `FUN_1401f9a50` | 2 | 703722 | `if (*(longlong *)(lVar1 + 0x78) != 0) {` |
| `FUN_140206750` | 2 | 719606 | `FUN_140179b60(*(undefined8 *)(lVar1 + 0x78));` |
| `FUN_140206a80` | 2 | 720042 | `FUN_140179b40(*(undefined8 *)(lVar2 + 0x78));` |
| `FUN_140207340` | 2 | 720764 | `FUN_140179b40(*(undefined8 *)(param_1 + 0x78));` |
| `FUN_140208a20` | 2 | 722990 | `(cVar2 = FUN_140179b50(*(undefined8 *)(lVar1 + 0x78)), cVar2 != '\0')) {` |
| `FUN_14020bb70` | 2 | 727652 | `if ((lVar1 != 0) && (*(code **)(lVar1 + 0x78) != (code *)0x0)) {` |
| `FUN_14026a530` | 2 | 912150 | `FUN_140179b60(*(undefined8 *)(lVar10 + 0x78));` |
| `FUN_140270a20` | 2 | 919042 | `*(longlong *)(param_3 + 0x78) + (ulonglong)(ushort)(sVar4 - *(short *)(param_3 + 0x80));` |
| `FUN_1402734c0` | 2 | 922168 | `lVar3 = (ulonglong)(uVar7 - *(int *)(param_3 + 0x80)) + *(longlong *)(param_3 + 0x78);` |
| `FUN_140282ba0` | 2 | 942962 | `lVar17 = (ulonglong)(uint)(iVar6 - iVar3) * 1000 + *(longlong *)(param_2 + 0x78);` |
| `FUN_1402c4cf0` | 2 | 1025434 | `*(undefined8 *)(*(longlong *)(lVar1 + 0x80) + 0x78) = *(undefined8 *)(lVar1 + 0x78);` |
| `FUN_1402c5170` | 2 | 1025842 | `*(undefined8 *)(*(longlong *)(lVar1 + 0x80) + 0x78) = *(undefined8 *)(lVar1 + 0x78);` |
| `FUN_1402e0598` | 2 | 1080346 | `iVar6 = FUN_1402dfea0(param_1 + 8,*(undefined8 *)(param_1 + 0x78));` |
| `FUN_14000d3c0` | 1 | 10408 | `puVar1[0xf] = *(undefined8 *)(param_1 + 0x78);` |
| `FUN_140011000` | 1 | 14856 | `uVar6 = *(undefined8 *)(param_1 + 0x78);` |
| `FUN_1400113e0` | 1 | 15218 | `uVar11 = *(undefined8 *)(param_1 + 0x78);` |
| `FUN_140027000` | 1 | 40972 | `FUN_140027f50(param_2 + 0x68,plVar2,*(undefined8 *)(param_1 + 0x78));` |
| `FUN_14002cfc0` | 1 | 50086 | `cVar2 = FUN_1400c5740(local_res8,*(undefined8 *)(param_1 + 0x78),0);` |
| `FUN_14002d7c0` | 1 | 51650 | `cVar9 = FUN_1400c5740(&local_res8,*(undefined8 *)(param_1 + 0x78),0);` |
| `FUN_14002f200` | 1 | 52336 | `uVar3 = FUN_1400c57a0(local_res8,*(longlong *)(param_1 + 0x78) + 0x30,0);` |
| `FUN_140038040` | 1 | 62510 | `uVar6 = *(undefined8 *)(param_1 + 0x78);` |
| `FUN_14004f0a0` | 1 | 90910 | `*param_1 = *(undefined8 *)(DAT_1403ea2a8 + 0x78);` |
| `FUN_14004f210` | 1 | 91200 | `local_res20[0] = *(uint *)(param_1 + 0x78);` |
| `FUN_14005cf70` | 1 | 108374 | `if (*(longlong *)(param_1 + 0x78) != 0) {` |
| `FUN_140063e10` | 1 | 116020 | `cVar1 = FUN_1400c5740(&local_res8,*(longlong *)(param_1 + 0x78) + 0x40,0);` |
| `FUN_1400646d0` | 1 | 116818 | `uVar8 = FUN_1400c57a0(local_88,*(longlong *)(param_1 + 0x78) + 0x30,0);` |
| `FUN_140064a60` | 1 | 117038 | `uVar2 = FUN_1400c57a0(local_res8,*(longlong *)(param_1 + 0x78) + 0x30,0);` |
| `FUN_140068120` | 1 | 121124 | `FUN_1400c5740(&local_res8,*(undefined8 *)(param_1 + 0x78),0);` |
| `FUN_14006aef0` | 1 | 124002 | `cVar4 = FUN_1400c5740(&local_res8,*(undefined8 *)(param_1 + 0x78),0);` |
| `FUN_14006f460` | 1 | 128946 | `FUN_1400756b0(*(undefined2 *)(param_1 + 0x78));` |
| `FUN_140088350` | 1 | 159790 | `lVar2 = *(longlong *)(param_1 + 0x78);` |
| `FUN_1400b6fd0` | 1 | 211718 | `local_a0 = *(undefined4 *)(lVar3 + 0x78);` |
| `FUN_1400bea50` | 1 | 220002 | `*(undefined8 *)(puVar8 + 0x1b) = *(undefined8 *)(lVar10 + 0x78);` |
| `FUN_1400cca50` | 1 | 236502 | `pfVar3 = *(float **)(param_1 + 0x78);` |
| `FUN_1400cf620` | 1 | 239704 | `pfVar4 = (float *)(*(longlong *)(param_1 + 0x78) + (longlong)param_3 * 0x10);` |
| `FUN_1400d0a00` | 1 | 241578 | `lVar3 = *(longlong *)(param_1 + 0x78);` |
| `FUN_1400d5ba0` | 1 | 246874 | `lVar3 = *(longlong *)(param_1 + 0x78);` |
| `FUN_1400d5d90` | 1 | 246982 | `pfVar1 = *(float **)(param_1 + 0x78);` |
| `FUN_1400dbe10` | 1 | 253408 | `lVar2 = *(longlong *)(param_1 + 0x78);` |
| `FUN_1400e3520` | 1 | 261322 | `lVar1 = *(longlong *)(lVar4 + 0x78);` |
| `FUN_1400faf30` | 1 | 294738 | `FUN_1400c56f0(local_18,uStack_14,*(undefined8 *)(param_1 + 0x78),0);` |
| `FUN_1400fb050` | 1 | 294862 | `FUN_1400c57a0(&local_res8,*(undefined8 *)(param_1 + 0x78),DAT_14039ca44);` |
| `FUN_140137f70` | 1 | 413206 | `(**(code **)(param_1 + 0x78))(*(undefined8 *)(param_1 + 0x298));` |
| `FUN_140156f30` | 1 | 458236 | `cVar4 = (**(code **)(lVar1 + 0x78))(lVar1,lVar3,*puVar2,*(undefined8 *)(puVar2 + 2));` |
| `FUN_1401575b0` | 1 | 458844 | `FUN_1401841e0(*(undefined8 *)(param_1 + 0x78));` |
| `FUN_140158030` | 1 | 459796 | `bVar1 = *(byte *)((longlong)param_2 + *(longlong *)(param_1 + 0x78));` |
| `FUN_1401629c0` | 1 | 476982 | `if ((*(byte *)(lVar2 + 0x78) & 2) == 0) {` |
| `FUN_140168f00` | 1 | 485378 | `cVar3 = FUN_14015da30(param_1 + 0x68,param_2,*(undefined8 *)(param_1 + 0x78),param_3);` |
| `FUN_14016b4e0` | 1 | 489044 | `FUN_1401747e0(*(undefined4 *)(lVar1 + 0x78));` |
| `FUN_1401711e0` | 1 | 498792 | `pcVar1 = *(code **)(lVar4 + 0x78);` |
| `FUN_140173190` | 1 | 502186 | `*(undefined4 *)(param_1 + 0x78));` |
| `FUN_1401a6b30` | 1 | 592304 | `if ((*(int *)(param_1 + 0x78) != 0) && (*(int *)(param_1 + 0x74) == 0)) {` |
| `FUN_1401beac0` | 1 | 627212 | `if ((*(int *)(param_1 + 0x78) != 0) && (*(int *)(param_2 + 0x78) == 0)) {` |
| `FUN_1401c79e0` | 1 | 639064 | `iVar3 = (**(code **)(param_1 + 0x78))(local_d50,1,&local_res20,&local_res18);` |
| `FUN_1401c7fa0` | 1 | 639692 | `iVar3 = (**(code **)(param_1 + 0x78))(local_d58,1,&local_d68,&local_res20);` |
| `FUN_1401e7230` | 1 | 681136 | `(**(code **)(**(longlong **)(lVar3 + 0x78) + 0x48))(*(longlong **)(lVar3 + 0x78),puVar8 + 10);` |
| `FUN_1401e9660` | 1 | 683902 | `FUN_1401ea070(uVar4,*(undefined8 *)(lVar3 + 0x78),uVar1,0x80);` |
| `FUN_1401eab10` | 1 | 685608 | `uVar4 = FUN_1401ea670(lVar2,*(undefined8 *)(lVar1 + 0x78),0,*param_3 / 2,param_3[1] / 2,` |
| `FUN_1402057a0` | 1 | 718412 | `if (*(longlong *)(param_1 + 0x78) != 0) {` |
| `FUN_140209760` | 1 | 724472 | `local_18 = *(undefined4 *)(lVar1 + 0x78);` |
| `FUN_140209880` | 1 | 724552 | `local_18 = *(undefined4 *)(lVar1 + 0x78);` |
| `FUN_140218bd0` | 1 | 747246 | `uVar3 = (**(code **)(lVar1 + 0x78))` |
| `FUN_14021d3c0` | 1 | 754506 | `if ((*(int *)(param_1 + 0x78) != 0) && ((*(uint *)(param_1 + 0x108) & 0xffffefff) == 0)) {` |
| `FUN_14022a1e0` | 1 | 772554 | `((*(int *)(param_2 + 0x78) != 0 && (*(int *)(param_2 + 0x78) != local_38.bottom)))) {` |
| `FUN_14022a9d0` | 1 | 773092 | `uVar8 = (ulonglong)*(uint *)(param_1 + 0x78);` |
| `FUN_14022b770` | 1 | 774370 | `iVar3 = *(int *)(param_2 + 0x78);` |
| `FUN_140240d00` | 1 | 863262 | `(**(code **)(param_1 + 0x78))(uVar1);` |
| `FUN_140298870` | 1 | 973980 | `if ((*(char *)((longlong)puVar3 + 5) == '\x02') && (*(int *)(param_1 + 0x78) != 0)) {` |
| `FUN_14029f870` | 1 | 982820 | `if (*(int *)(param_1 + 0x78) != 0) {` |
| `FUN_1402a05f0` | 1 | 984064 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402a2a20` | 1 | 987060 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402a3170` | 1 | 987520 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402a3700` | 1 | 987948 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402a3b90` | 1 | 988294 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402a40c0` | 1 | 988644 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402a4600` | 1 | 988968 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402a4830` | 1 | 989136 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402a4af0` | 1 | 989308 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402a4d20` | 1 | 989476 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402a4fd0` | 1 | 989670 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402a5550` | 1 | 990046 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402a5ad0` | 1 | 990434 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402a60f0` | 1 | 990822 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402a6810` | 1 | 991272 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402a6c40` | 1 | 991584 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402a70f0` | 1 | 991882 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402a7280` | 1 | 992014 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402a74b0` | 1 | 992186 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402a79c0` | 1 | 992540 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402a8060` | 1 | 992970 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402a8490` | 1 | 993282 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402a8940` | 1 | 993578 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402a8ae0` | 1 | 993706 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402a8d10` | 1 | 993876 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402a92f0` | 1 | 994286 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402a94e0` | 1 | 994510 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402a9a60` | 1 | 994844 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402a9cc0` | 1 | 995036 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402a9e60` | 1 | 995164 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402aa090` | 1 | 995332 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402aa520` | 1 | 995666 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402aaa00` | 1 | 996010 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402aaf40` | 1 | 996354 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402ab4a0` | 1 | 996684 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402ab6d0` | 1 | 996852 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402aba90` | 1 | 997108 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402abc80` | 1 | 997326 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402ac1f0` | 1 | 997682 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402ac440` | 1 | 997872 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402ac5d0` | 1 | 998002 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402ac800` | 1 | 998190 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402ace20` | 1 | 998556 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402ad410` | 1 | 998988 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402ad970` | 1 | 999332 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402adef0` | 1 | 999766 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402ae430` | 1 | 1000086 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402ae630` | 1 | 1000290 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402ae8a0` | 1 | 1000492 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402aead0` | 1 | 1000644 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402aecc0` | 1 | 1000798 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402aef70` | 1 | 1000972 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402af1d0` | 1 | 1001156 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402af720` | 1 | 1001528 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402afc90` | 1 | 1001908 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b0260` | 1 | 1002296 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b0990` | 1 | 1002738 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b0ba0` | 1 | 1002948 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b0fc0` | 1 | 1003250 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b1230` | 1 | 1003470 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b16e0` | 1 | 1003766 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b18c0` | 1 | 1003912 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b1b20` | 1 | 1004096 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b2070` | 1 | 1004438 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b2200` | 1 | 1004568 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b2430` | 1 | 1004738 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b2940` | 1 | 1005090 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b2f10` | 1 | 1005472 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b34a0` | 1 | 1005798 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b3690` | 1 | 1005996 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b39e0` | 1 | 1006292 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b3df0` | 1 | 1006602 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b42d0` | 1 | 1006940 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b4780` | 1 | 1007262 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b4cf0` | 1 | 1007586 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b4e90` | 1 | 1007714 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b50c0` | 1 | 1007884 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b55d0` | 1 | 1008204 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b57b0` | 1 | 1008402 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b5a00` | 1 | 1008628 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b5f90` | 1 | 1008972 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b6460` | 1 | 1009306 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b6900` | 1 | 1009650 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b6e60` | 1 | 1010004 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b7380` | 1 | 1010330 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b75b0` | 1 | 1010484 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b77b0` | 1 | 1010694 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b7a70` | 1 | 1010870 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b7ce0` | 1 | 1011094 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b8270` | 1 | 1011442 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b8450` | 1 | 1011588 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b86b0` | 1 | 1011772 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b8bf0` | 1 | 1012156 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b9210` | 1 | 1012536 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b97e0` | 1 | 1012904 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b9c80` | 1 | 1013224 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402b9e90` | 1 | 1013448 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402ba3b0` | 1 | 1013778 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402ba620` | 1 | 1013974 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402ba810` | 1 | 1014118 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402baa40` | 1 | 1014278 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402baca0` | 1 | 1014454 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402baf50` | 1 | 1014644 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402bb490` | 1 | 1015016 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402bba20` | 1 | 1015396 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402bbff0` | 1 | 1015784 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402bc620` | 1 | 1016146 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402bca40` | 1 | 1016448 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402bce70` | 1 | 1016760 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402bd320` | 1 | 1017080 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402bd7d0` | 1 | 1017378 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402bd980` | 1 | 1017522 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402bde90` | 1 | 1017856 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402be0e0` | 1 | 1018016 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402be5f0` | 1 | 1018370 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402beb90` | 1 | 1018730 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402bf120` | 1 | 1019070 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402bf540` | 1 | 1019372 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402bf970` | 1 | 1019684 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402bfe20` | 1 | 1020004 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402c02d0` | 1 | 1020302 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402c0460` | 1 | 1020434 | `uVar4 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402c0690` | 1 | 1020606 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402c0ba0` | 1 | 1020948 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402c10b0` | 1 | 1021302 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402c1650` | 1 | 1021662 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402c1bd0` | 1 | 1022008 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402c2070` | 1 | 1022346 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402c2500` | 1 | 1022692 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402c2a30` | 1 | 1023042 | `uVar1 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402c2f70` | 1 | 1023366 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402c31a0` | 1 | 1023534 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402c3460` | 1 | 1023706 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402c3690` | 1 | 1023874 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402c3950` | 1 | 1024068 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402c3ed0` | 1 | 1024444 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402c4450` | 1 | 1024832 | `uVar5 = *(uint *)(param_1 + 0x78);` |
| `FUN_1402df9d0` | 1 | 1078696 | `iVar3 = parse_floating_point<>(*(undefined8 *)(param_1 + 0x78),&local_28,local_res10);` |
| `FUN_1402dfa74` | 1 | 1078790 | `iVar3 = parse_floating_point<>(*(undefined8 *)(param_1 + 0x78),&local_28,&local_res10);` |
| `FUN_1402e0a58` | 1 | 1081290 | `FUN_1402f00bc(local_res8,&param_5,(longlong)*(int *)(**(longlong **)(this + 0x78) + 8));` |
| `FUN_1402e842c` | 1 | 1096248 | `FUN_1402e9a80(*(undefined8 *)(local_20 + 0x78));` |
| `FUN_1402f4f90` | 1 | 1119448 | `if (*(undefined **)(param_1 + 0x78) != PTR_DAT_1403e8cf8) {` |
| `FUN_1402fcc81` | 1 | 1130638 | `FUN_1402c7088(*(undefined8 *)(param_2 + 0x78),0x1f48);` |
| `FUN_1402fda08` | 1 | 1131028 | `FUN_1402c7088(*(undefined8 *)(param_2 + 0x78),0x1f48);` |
| `FUN_1402ff9e8` | 1 | 1132812 | `*(undefined8 *)(param_2 + 0x70),*(undefined8 *)(param_2 + 0x78));` |
| `FUN_1402ffab9` | 1 | 1132948 | `thunk_FUN_1402cb4e0(**(undefined8 **)(param_2 + 0x48),*(undefined8 *)(param_2 + 0x78),` |
| `FUN_1402ffb60` | 1 | 1133008 | `FUN_1402cb9c4(**(undefined8 **)(param_2 + 0x48),*(undefined8 *)(param_2 + 0x78),` |

## `+0x7c` (124 dec)

41 functions, 46 read sites.

| Function | Hits | First line | First snippet |
|---|---|---|---|
| `FUN_14001f210` | 4 | 31018 | `fVar30 = *(float *)(lVar20 + 0x7c);` |
| `FUN_1400ba940` | 2 | 217068 | `uVar15 = *(uint *)(lVar34 + 0x7c);` |
| `FUN_14016fc90` | 2 | 496928 | `*(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_1 + 0x7c);` |
| `FUN_14006f460` | 1 | 128950 | `FUN_140075670(*(undefined4 *)(param_1 + 0x7c));` |
| `FUN_140080e40` | 1 | 150888 | `if (((*(int *)(DAT_1403fb0d8 + 0x410) == 1) && (*(int *)(param_1 + 0x7c) % 10 == 9)) &&` |
| `FUN_140082640` | 1 | 152302 | `iVar11 = *(int *)(param_1 + 0x7c) + 1;` |
| `FUN_1400b6fd0` | 1 | 211720 | `uStack_9c = *(undefined4 *)(lVar3 + 0x7c);` |
| `FUN_140161f10` | 1 | 476256 | `uVar7 = FUN_140190500(param_5 + *(float *)(lVar6 + 0x7c),&param_5);` |
| `FUN_140171f80` | 1 | 499982 | `*(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_1 + 0x7c);` |
| `FUN_1401beac0` | 1 | 627224 | `if ((*(int *)(param_1 + 0x7c) != 0) && (*(int *)(param_2 + 0x7c) == 0)) {` |
| `FUN_1401e45b0` | 1 | 677246 | `(longlong)(int)(uVar4 * *(int *)(lVar1 + 0x7c)) + *(longlong *)(lVar1 + 0x70),` |
| `FUN_140209760` | 1 | 724474 | `uStack_14 = *(undefined4 *)(lVar1 + 0x7c);` |
| `FUN_140209880` | 1 | 724554 | `uStack_14 = *(undefined4 *)(lVar1 + 0x7c);` |
| `FUN_14020f9f0` | 1 | 733294 | `return *(undefined4 *)(lVar1 + 0x7c);` |
| `FUN_14020fa50` | 1 | 733392 | `*(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(lVar1 + 0x7c);` |
| `FUN_14022a9d0` | 1 | 773100 | `FUN_140170020(param_1,*(undefined4 *)(param_1 + 0x7c),*(undefined4 *)(param_1 + 0x80),param_5,` |
| `FUN_14022bcb0` | 1 | 775016 | `local_88 = *(LONG *)(param_2 + 0x7c);` |
| `FUN_14028c420` | 1 | 956282 | `uVar2 = *(uint *)(param_1 + 0x7c);` |
| `FUN_14028c8d0` | 1 | 956834 | `uVar1 = *(uint *)(param_1 + 0x7c);` |
| `FUN_14028cc70` | 1 | 957258 | `uVar1 = *(uint *)(param_1 + 0x7c);` |
| `FUN_14028cff0` | 1 | 957680 | `uVar1 = *(uint *)(param_1 + 0x7c);` |
| `FUN_14028d480` | 1 | 958238 | `uVar2 = *(uint *)(param_1 + 0x7c);` |
| `FUN_14028d940` | 1 | 958790 | `uVar1 = *(uint *)(param_1 + 0x7c);` |
| `FUN_14028dce0` | 1 | 959210 | `uVar1 = *(uint *)(param_1 + 0x7c);` |
| `FUN_14028e060` | 1 | 959632 | `uVar1 = *(uint *)(param_1 + 0x7c);` |
| `FUN_14028e4f0` | 1 | 960192 | `uVar2 = *(uint *)(param_1 + 0x7c);` |
| `FUN_14028e9a0` | 1 | 960752 | `uVar1 = *(uint *)(param_1 + 0x7c);` |
| `FUN_14028ed40` | 1 | 961176 | `uVar2 = *(uint *)(param_1 + 0x7c);` |
| `FUN_14028f0c0` | 1 | 961598 | `uVar1 = *(uint *)(param_1 + 0x7c);` |
| `FUN_14028fc70` | 1 | 962512 | `uVar6 = *(uint *)(param_1 + 0x7c);` |
| `FUN_140290920` | 1 | 963460 | `uVar4 = *(uint *)(param_1 + 0x7c);` |
| `FUN_140290d10` | 1 | 963990 | `uVar4 = *(uint *)(param_1 + 0x7c);` |
| `FUN_140291000` | 1 | 964340 | `uVar4 = *(uint *)(param_1 + 0x7c);` |
| `FUN_1402912d0` | 1 | 964672 | `uVar4 = *(uint *)(param_1 + 0x7c);` |
| `FUN_140292310` | 1 | 965730 | `uVar6 = *(uint *)(param_1 + 0x7c);` |
| `FUN_140294f70` | 1 | 969110 | `uVar9 = *(uint *)(param_1 + 0x7c) & uVar8;` |
| `FUN_140296080` | 1 | 970886 | `uVar9 = *(uint *)(param_1 + 0x7c) & uVar23;` |
| `FUN_140297650` | 1 | 972542 | `uVar12 = *(uint *)(param_1 + 0x7c) & uVar13;` |
| `FUN_14029b740` | 1 | 978402 | `uVar9 = *(uint *)(param_1 + 0x7c);` |
| `FUN_14029e390` | 1 | 981398 | `uVar7 = *(uint *)(param_1 + 0x7c);` |
| `FUN_1402a05f0` | 1 | 984100 | `uVar6 = *(uint *)(param_1 + 0x7c);` |

## `+0x80` (128 dec)

295 functions, 457 read sites.

| Function | Hits | First line | First snippet |
|---|---|---|---|
| `FUN_140082640` | 15 | 152258 | `lVar4 = *(longlong *)(param_1 + 0x80);` |
| `FUN_140080e40` | 11 | 150666 | `lVar8 = *(longlong *)(param_1 + 0x80);` |
| `FUN_1400816b0` | 11 | 151132 | `iVar2 = *(int *)(*(longlong *)(param_1 + 0x80) + 0x254);` |
| `FUN_140102060` | 8 | 303722 | `iVar16 = *(int *)(*(longlong *)(uVar15 + 0x80) + 0x24c);` |
| `FUN_140080cc0` | 6 | 150466 | `if ((iVar1 != 0) \|\| (param_2 = 0xb, *(char *)(*(longlong *)(param_1 + 0x80) + 0x162) != '\0')) {` |
| `FUN_1400820a0` | 6 | 151836 | `if ((*(char *)(param_1 + 0x11) == '\0') && (*(longlong *)(param_1 + 0x80) != 0)) {` |
| `FUN_14001f210` | 5 | 31100 | `*(float *)(lVar20 + 0x80)) -` |
| `FUN_1400831e0` | 5 | 153012 | `if ((*(int *)(param_1 + 0x38) == -1) && (*(int *)(*(longlong *)(param_1 + 0x80) + 0x234) < 0)) {` |
| `FUN_140272910` | 5 | 921192 | `iVar3 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),&local_98,0x80,0);` |
| `FUN_14001b740` | 4 | 27126 | `param_1[0x15] = *(undefined8 *)(lVar3 + 0x80);` |
| `FUN_140021550` | 4 | 33516 | `if (0 < *(int *)(param_1 + 0x80)) {` |
| `FUN_14016fc90` | 4 | 496932 | `*(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_1 + 0x80);` |
| `FUN_1401e7230` | 4 | 681018 | `(**(code **)(**(longlong **)(lVar3 + 0x80) + 0x48))(*(longlong **)(lVar3 + 0x80),puVar8 + 4);` |
| `FUN_1402706d0` | 4 | 918554 | `iVar3 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),&local_a8,0x80,0);` |
| `FUN_140272200` | 4 | 920648 | `iVar6 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),&local_a8,0x80,0x10);` |
| `FUN_14027f5a0` | 4 | 938104 | `iVar2 = FUN_140195730(*(undefined8 *)(param_1 + 0x80),&local_res8,7);` |
| `FUN_14004d8d0` | 3 | 89116 | `puVar11 = (undefined4 *)((longlong)iVar13 + *(longlong *)(param_1 + 0x80));` |
| `FUN_140081d10` | 3 | 151598 | `if (((*(float *)(*(longlong *)(param_1 + 0x80) + 0x150) != 0.0) &&` |
| `FUN_140102b40` | 3 | 304362 | `if ((*(char *)(param_1 + 0x260) != '\0') && (lVar1 = *(longlong *)(param_2 + 0x80), lVar1 != 0)) {` |
| `FUN_14026e640` | 3 | 916198 | `if ((((param_1 != 0) && (*(longlong *)(param_1 + 0x80) != 0)) &&` |
| `FUN_1402734c0` | 3 | 922168 | `lVar3 = (ulonglong)(uVar7 - *(int *)(param_3 + 0x80)) + *(longlong *)(param_3 + 0x78);` |
| `FUN_14027ab70` | 3 | 932378 | `iVar2 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),&local_58,0x40,0);` |
| `FUN_14027dd30` | 3 | 936274 | `FUN_14027e010(*(undefined8 *)(param_1 + 0x80));` |
| `FUN_14027f720` | 3 | 938272 | `iVar2 = FUN_140195730(*(undefined8 *)(param_1 + 0x80),&local_res8,7);` |
| `FUN_1402c4ad0` | 3 | 1025194 | `if (*(longlong *)(param_2 + 0x80) != 0) {` |
| `FUN_1402c4cf0` | 3 | 1025432 | `if (*(longlong *)(lVar1 + 0x80) != 0) {` |
| `FUN_1402c5170` | 3 | 1025840 | `if (*(longlong *)(lVar1 + 0x80) != 0) {` |
| `FUN_140006230` | 2 | 2434 | `if (param_2 + 0x20 == *(longlong *)(lVar3 + 0x80)) {` |
| `FUN_140009ca0` | 2 | 6570 | `(*(float *)(param_1 + 0x80) * fVar2 + fVar1 * *(float *)(param_1 + 0x84) +` |
| `FUN_140018e70` | 2 | 24900 | `if (*(float *)(param_1 + 0x80) <= 0.0) {` |
| `FUN_14001aaa0` | 2 | 26462 | `if (0.0 < *(float *)(param_1 + 0x80)) {` |
| `FUN_140026b90` | 2 | 40638 | `if (0xf < *(ulonglong *)(param_1 + 0x80)) {` |
| `FUN_140054630` | 2 | 99490 | `lVar1 = *(longlong *)(param_1 + 0x80);` |
| `FUN_140082330` | 2 | 151952 | `if (*(int *)(lVar6 + *(longlong *)(param_1 + 0x80)) != -1) {` |
| `FUN_140082430` | 2 | 152044 | `if (*(int *)(*(longlong *)(param_1 + 0x80) + 0x234) < 0) {` |
| `FUN_1400ba940` | 2 | 217020 | `if (0.0 < *(float *)(lVar34 + 0x80)) {` |
| `FUN_1400fd3e0` | 2 | 297250 | `if (((*(int *)(lVar6 + 8) == 0) && (lVar1 = *(longlong *)(lVar6 + 0x80), lVar1 != 0)) &&` |
| `FUN_140105da0` | 2 | 308562 | `) && ((*(longlong *)(lVar7 + 0x80) != 0 &&` |
| `FUN_140106bc0` | 2 | 309732 | `(lVar2 = *(longlong *)(lVar5 + 0x80), *(char *)(lVar5 + 0x11) == '\0')))) &&` |
| `FUN_140107190` | 2 | 310094 | `(lVar2 = *(longlong *)(lVar12 + 0x80), *(char *)(lVar12 + 0x11) == '\0')))) &&` |
| `FUN_14010ba40` | 2 | 316030 | `if (((*(int *)(lVar33 + 8) == 0) && (lVar34 = *(longlong *)(lVar33 + 0x80), lVar34 != 0)) &&` |
| `FUN_14013ba20` | 2 | 419396 | `if ((*(longlong *)(param_1 + 0x80) != 0) && (lVar1 = FUN_14013aaf0(1), lVar1 != 0)) {` |
| `FUN_140155130` | 2 | 455916 | `(**(code **)(lVar2 + 0x80))(lVar2,*(undefined8 *)(param_1 + 0x38));` |
| `FUN_1401575b0` | 2 | 458848 | `if (0 < *(int *)(param_1 + 0x80)) {` |
| `FUN_14015a3a0` | 2 | 464112 | `if (0 < *(int *)(param_1 + 0x80)) {` |
| `FUN_140175600` | 2 | 505376 | `DAT_1403fc460 = *(ulonglong *)(param_1 + 0x80);` |
| `FUN_1401b9390` | 2 | 619092 | `if (*(longlong *)(param_2 + 0x80) != 0) {` |
| `FUN_1401ccf50` | 2 | 646478 | `FUN_1402f8e20((ulonglong)(uVar6 * iVar7) + *(longlong *)(lVar9 + 0x80) + local_70,` |
| `FUN_1401ee270` | 2 | 689612 | `pcVar9 = *(code **)(lVar2 + 0x80);` |
| `FUN_1401f4bb0` | 2 | 696948 | `pcVar12 = *(code **)(param_1 + 0x80);` |
| `FUN_1401f9a50` | 2 | 703730 | `if (*(longlong *)(lVar1 + 0x80) != 0) {` |
| `FUN_14020bd60` | 2 | 727872 | `if (*(code **)(lVar1 + 0x80) != (code *)0x0) {` |
| `FUN_140218c30` | 2 | 747438 | `lVar6 = (**(code **)(lVar6 + 0x80))` |
| `FUN_14022bcb0` | 2 | 774910 | `lVar2 = *(longlong *)(param_3 + 0x80);` |
| `FUN_140263900` | 2 | 902186 | `uVar3 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),&local_48,0x25,0);` |
| `FUN_140263ad0` | 2 | 902306 | `iVar2 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),&local_48,0x40,0);` |
| `FUN_140264c60` | 2 | 903658 | `iVar4 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),local_68,0x40,*(undefined4 *)(lVar1 + 0x14))` |
| `FUN_14026d850` | 2 | 915284 | `iVar2 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),local_48,0x40,0);` |
| `FUN_14026e4e0` | 2 | 916092 | `iVar2 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),&local_48,0x40,0);` |
| `FUN_14026e8a0` | 2 | 916440 | `uVar2 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),local_48,0x40,0);` |
| `FUN_14026ea10` | 2 | 916532 | `iVar1 = FUN_14026ffd0(*(undefined8 *)(param_1 + 0x80),0xf2,&local_48,0x40);` |
| `FUN_1402700b0` | 2 | 917988 | `if ((param_1 != 0) && (*(longlong *)(param_1 + 0x80) != 0)) {` |
| `FUN_140270120` | 2 | 918144 | `iVar5 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),local_48,0x40,0x10);` |
| `FUN_140271660` | 2 | 919688 | `in_RAX = FUN_14026ffd0(*(undefined8 *)(param_1 + 0x80),2,&local_a8,0x40);` |
| `FUN_140272190` | 2 | 920508 | `if ((param_1 != 0) && (*(longlong *)(param_1 + 0x80) != 0)) {` |
| `FUN_140274860` | 2 | 923720 | `iVar2 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),&local_48,0x40,0);` |
| `FUN_1402754a0` | 2 | 924582 | `iVar2 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),local_48,0x40,0);` |
| `FUN_140275eb0` | 2 | 925426 | `iVar9 = FUN_140276c10(*(undefined8 *)(param_1 + 0x80),local_d8,0x80);` |
| `FUN_140276960` | 2 | 926238 | `iVar2 = FUN_140193250(*(undefined8 *)(param_1 + 0x80),param_2,0x41);` |
| `FUN_140277070` | 2 | 927154 | `iVar2 = FUN_140193880(*(undefined8 *)(param_1 + 0x80),param_2,0x41);` |
| `FUN_140277810` | 2 | 927896 | `iVar1 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),local_48,0x40,0x10);` |
| `FUN_140277890` | 2 | 927976 | `cVar3 = FUN_140277b60(*(undefined8 *)(param_1 + 0x80));` |
| `FUN_14027a3f0` | 2 | 931804 | `iVar2 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),local_48,0x40,0);` |
| `FUN_14027b670` | 2 | 933204 | `uVar2 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),local_48,0x40,0);` |
| `FUN_14027d2e0` | 2 | 935622 | `iVar2 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),local_48,0x40,0);` |
| `FUN_14027fba0` | 2 | 938614 | `iVar2 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),local_48,0x40,0x50);` |
| `FUN_14027ff50` | 2 | 939028 | `iVar2 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),local_48,0x40,0);` |
| `FUN_140280d00` | 2 | 940034 | `iVar2 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),local_58,0x40,0);` |
| `FUN_140281cc0` | 2 | 941258 | `FUN_140195730(*(undefined8 *)(param_1 + 0x80),&local_68,0xc);` |
| `FUN_1402828a0` | 2 | 942412 | `iVar2 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),local_48,0x40,0);` |
| `FUN_140283390` | 2 | 943280 | `iVar1 = FUN_140195730(*(undefined8 *)(param_1 + 0x80),&local_48,0x30);` |
| `FUN_140283780` | 2 | 943652 | `iVar3 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),local_48,0x40,0);` |
| `FUN_140300163` | 2 | 1133856 | `puVar1 = *(uint **)(param_2 + 0x80);` |
| `FUN_140008560` | 1 | 5418 | `fVar19 = *(float *)(param_1 + 0x80) - *(float *)(param_1 + 0xd4);` |
| `FUN_140009380` | 1 | 6104 | `fVar24 = *(float *)(param_1 + 0x80) - *(float *)(param_1 + 0xd4);` |
| `FUN_140009b70` | 1 | 6418 | `fVar1 = *(float *)(param_1 + 0x80);` |
| `FUN_14000a0a0` | 1 | 7016 | `fVar16 = *(float *)(param_1 + 0x80) - *(float *)(param_1 + 0xd4);` |
| `FUN_14000ace0` | 1 | 7726 | `fVar24 = *(float *)(param_1 + 0x80) - *(float *)(param_1 + 0xd4);` |
| `FUN_14000b4a0` | 1 | 8274 | `fVar15 = *(float *)(param_1 + 0x80) - *(float *)(param_1 + 0xbc);` |
| `FUN_14000bc20` | 1 | 8676 | `fVar18 = *(float *)(param_1 + 0x80) - *(float *)(param_1 + 0xbc);` |
| `FUN_14000d3c0` | 1 | 10410 | `puVar1[0x10] = *(undefined8 *)(param_1 + 0x80);` |
| `FUN_140010430` | 1 | 13822 | `for (lVar1 = *(longlong *)(param_1 + 0x80); lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x18)) {` |
| `FUN_1400145b0` | 1 | 18952 | `fVar11 = (fVar20 + fVar13) - *(float *)(param_1 + 0x80);` |
| `FUN_140014e30` | 1 | 19392 | `fVar24 = (*(float *)(lVar12 + lVar13 * 0xc) + fVar25) - *(float *)(param_1 + 0x80);` |
| `FUN_140018650` | 1 | 24376 | `fVar17 = *(float *)(param_1 + 0x80) - *(float *)(param_1 + 0xbc);` |
| `FUN_140019e50` | 1 | 25694 | `fVar17 = *(float *)(param_1 + 0x80) - *(float *)(param_1 + 0xb8);` |
| `FUN_14001a5b0` | 1 | 26072 | `fVar24 = *(float *)(param_1 + 0x80) - *(float *)(param_1 + 0xb8);` |
| `FUN_14001b280` | 1 | 26758 | `if (*(float *)(param_1 + 0x80) <= 0.0) {` |
| `FUN_14001d410` | 1 | 28654 | `fVar19 = *(float *)(param_1 + 0x80) - *(float *)(param_1 + 0xbc);` |
| `FUN_14001da30` | 1 | 28912 | `fVar1 = *(float *)(param_1 + 0x80);` |
| `FUN_1400228d0` | 1 | 34050 | `lVar5 = (longlong)*(int *)(param_1 + 0x80);` |
| `FUN_140026370` | 1 | 39872 | `FUN_140027f50(param_2 + 0x70,plVar3,*(undefined8 *)(param_1 + 0x80));` |
| `FUN_140027000` | 1 | 40966 | `if (0xf < *(ulonglong *)(param_1 + 0x80)) {` |
| `FUN_14004b960` | 1 | 86322 | `puVar20 = (uint *)((longlong)iVar10 + *(longlong *)(param_1 + 0x80));` |
| `FUN_14004dc90` | 1 | 89494 | `pfVar15 = (float *)((longlong)iVar6 + *(longlong *)(param_3 + 0x80));` |
| `FUN_1400509e0` | 1 | 93152 | `return (longlong)iVar1 + *(longlong *)(param_1 + 0x80);` |
| `FUN_140050a30` | 1 | 93202 | `return (longlong)iVar1 + *(longlong *)(param_1 + 0x80);` |
| `FUN_14006f460` | 1 | 128936 | `FUN_14006ee10(*(undefined8 *)(param_1 + 0x80));` |
| `FUN_14006f4e0` | 1 | 128994 | `FUN_140080730(param_1,*(undefined8 *)(param_1 + 0x80),0,0);` |
| `FUN_140080a70` | 1 | 150316 | `lVar1 = *(longlong *)(param_1 + 0x80);` |
| `FUN_140080ab0` | 1 | 150350 | `lVar1 = *(longlong *)(param_1 + 0x80);` |
| `FUN_140080b00` | 1 | 150386 | `lVar1 = *(longlong *)(param_1 + 0x80);` |
| `FUN_140080b80` | 1 | 150430 | `if (*(int *)(*(longlong *)(param_1 + 0x80) + 0x1c) == 1) {` |
| `FUN_140081600` | 1 | 150996 | `uVar2 = *(ulonglong *)(param_1 + 0x80);` |
| `FUN_140081fa0` | 1 | 151726 | `if (((param_2 == '\0') && (lVar1 = *(longlong *)(param_1 + 0x80), *(int *)(lVar1 + 0x24c) == 2))` |
| `FUN_140082010` | 1 | 151770 | `if (*(int *)(*(longlong *)(param_1 + 0x80) + 0x1c) == 6) {` |
| `FUN_140082060` | 1 | 151796 | `return ((*(int *)(*(longlong *)(param_1 + 0x80) + 0x1fc) != 0) + 1) *` |
| `FUN_140082550` | 1 | 152146 | `lVar1 = *(longlong *)(param_1 + 0x80);` |
| `FUN_140083340` | 1 | 153078 | `FUN_1400be730(*(undefined8 *)(param_1 + 0x80));` |
| `FUN_1400b6fd0` | 1 | 211722 | `uStack_98 = *(undefined4 *)(lVar3 + 0x80);` |
| `FUN_1400bea50` | 1 | 220000 | `uVar5 = *(undefined8 *)(lVar10 + 0x80);` |
| `FUN_1400cf540` | 1 | 239594 | `puVar1 = *(undefined8 **)(param_1 + 0x80);` |
| `FUN_1400d23d0` | 1 | 243382 | `if (((ulonglong)(*(longlong *)(param_1 + 0x80) - *(longlong *)(param_1 + 0x78) >> 4) < 4) \|\|` |
| `FUN_140101dc0` | 1 | 303532 | `lVar2 = *(longlong *)(uVar1 + 0x80);` |
| `FUN_140102df0` | 1 | 304544 | `local_98 = *(longlong *)(param_2 + 0x80);` |
| `FUN_140107660` | 1 | 313330 | `lVar28 = *(longlong *)(lVar16 + 0x80);` |
| `FUN_140137eb0` | 1 | 413098 | `(**(code **)(param_1 + 0x80))(*(undefined8 *)(param_1 + 0x298));` |
| `FUN_14013acf0` | 1 | 418020 | `*(undefined8 *)(lVar1 + 0x10) = *(undefined8 *)(param_1 + 0x80);` |
| `FUN_14013ef20` | 1 | 424990 | `if ((param_2 < 0) \|\| (*(int *)(lVar2 + 0x80) <= param_2)) {` |
| `FUN_14013f2b0` | 1 | 425374 | `if (((lVar1 != 0) && (uVar2 = 0, -1 < param_2)) && (param_2 < *(int *)(lVar1 + 0x80))) {` |
| `FUN_14013f310` | 1 | 425412 | `uVar2 = *(undefined4 *)(lVar1 + 0x80);` |
| `FUN_140144330` | 1 | 432840 | `(**(code **)(param_1 + 0x80))(param_1,param_2,param_3,param_4);` |
| `FUN_140154990` | 1 | 455190 | `*(float *)(lVar1 + 0x90) = param_2 * *(float *)(lVar1 + 0x80);` |
| `FUN_14015a220` | 1 | 463922 | `iVar1 = *(int *)(param_1 + 0x80);` |
| `FUN_140161f10` | 1 | 476260 | `uVar7 = FUN_140190500(param_6 + *(float *)(lVar6 + 0x80),&param_6);` |
| `FUN_14016b4e0` | 1 | 489054 | `FUN_1401841e0(*(undefined8 *)(lVar1 + 0x80));` |
| `FUN_14016d390` | 1 | 492066 | `return *(undefined8 *)(lVar1 + 0x80);` |
| `FUN_140170800` | 1 | 497936 | `pcVar1 = *(code **)(lVar2 + 0x80);` |
| `FUN_140171f80` | 1 | 499984 | `*(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_1 + 0x80);` |
| `FUN_140176200` | 1 | 506646 | `for (; lVar6 != 0; lVar6 = *(longlong *)(lVar6 + 0x80)) {` |
| `FUN_14017ba60` | 1 | 515624 | `if (*(longlong *)(param_1 + 0x80) != 0) {` |
| `FUN_140180570` | 1 | 524110 | `uVar6 = FUN_140188550(*(undefined8 *)(lVar4 + 0x80),"SetProcessDpiAwareness");` |
| `FUN_140181390` | 1 | 525050 | `if (*(longlong *)(lVar1 + 0x80) != 0) {` |
| `FUN_1401beac0` | 1 | 627236 | `if ((*(int *)(param_1 + 0x80) != 0) && (*(int *)(param_2 + 0x80) == 0)) {` |
| `FUN_1401c3db0` | 1 | 633944 | `FUN_1401c7380(&local_6e8,local_428,*(undefined8 *)(param_1 + 0x80));` |
| `FUN_1401c95c0` | 1 | 641136 | `if (*(longlong *)(param_1 + 0x80) != 0) {` |
| `FUN_1401c97e0` | 1 | 641678 | `FUN_1401841e0(*(undefined8 *)(param_1 + 0x80));` |
| `FUN_1401e45b0` | 1 | 677244 | `(longlong)(*(int *)(lVar1 + 0x78) * *(int *)(lVar1 + 0x80)) +` |
| `FUN_1401e6b30` | 1 | 680232 | `(**(code **)(**(longlong **)(lVar1 + 0x80) + 0x48))(*(longlong **)(lVar1 + 0x80),puVar3 + 1)` |
| `FUN_1401e8fd0` | 1 | 683342 | `local_18 = *(undefined8 *)(param_1 + 0x80);` |
| `FUN_1401e9660` | 1 | 683904 | `local_b8[uVar6 + 1] = *(undefined8 *)(lVar3 + 0x80);` |
| `FUN_1401e9870` | 1 | 684154 | `uVar11 = FUN_1401e60b0(*(undefined8 *)(lVar1 + 0x80),param_6[uVar14]);` |
| `FUN_1401f32b0` | 1 | 695236 | `(**(code **)(lVar2 + 0x80))(0xc11);` |
| `FUN_1401f8a10` | 1 | 702630 | `iVar5 = FUN_1401f6570(lVar1,*(undefined8 *)(lVar8 + 0x80),lVar8 + 0x88,lVar8 + 0x90);` |
| `FUN_140203060` | 1 | 715548 | `local_d0 = *(undefined8 *)(param_1 + 0x80);` |
| `FUN_1402057a0` | 1 | 718406 | `if (*(longlong *)(param_1 + 0x80) != 0) {` |
| `FUN_140205900` | 1 | 718578 | `local_28 = *(undefined8 *)(param_1 + 0x80);` |
| `FUN_140207340` | 1 | 720766 | `if (*(longlong *)(param_1 + 0x80) != 0) {` |
| `FUN_140208550` | 1 | 722570 | `if ((*(longlong *)(param_1 + 0x68) == 0) && (*(longlong *)(param_1 + 0x80) != 0)) {` |
| `FUN_140209760` | 1 | 724476 | `uStack_10 = *(undefined4 *)(lVar1 + 0x80);` |
| `FUN_140209880` | 1 | 724556 | `uStack_10 = *(undefined4 *)(lVar1 + 0x80);` |
| `FUN_14020bc00` | 1 | 727816 | `if (*(longlong *)(lVar2 + 0x80) != 0) {` |
| `FUN_14020fa50` | 1 | 733394 | `*(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(lVar1 + 0x80);` |
| `FUN_1402262e0` | 1 | 767010 | `BVar1 = GetMonitorInfoW(*(HMONITOR *)(*(longlong *)(param_2 + 0x80) + 0x40),&local_38);` |
| `FUN_140226500` | 1 | 767224 | `lVar1 = *(longlong *)(param_2 + 0x80);` |
| `FUN_1402268d0` | 1 | 767594 | `BVar1 = GetMonitorInfoW(*(HMONITOR *)(*(longlong *)(param_2 + 0x80) + 0x40),&local_38);` |
| `FUN_140226f30` | 1 | 768332 | `if (*(int *)(*(longlong *)(lVar5 + 0x80) + 0x48) == 1) {` |
| `FUN_140227060` | 1 | 768408 | `lpszDeviceName = *(LPCWSTR *)(param_2 + 0x80);` |
| `FUN_14022a9d0` | 1 | 773100 | `FUN_140170020(param_1,*(undefined4 *)(param_1 + 0x7c),*(undefined4 *)(param_1 + 0x80),param_5,` |
| `FUN_140263db0` | 1 | 902622 | `iVar1 = FUN_140195730(*(undefined8 *)(param_1 + 0x80),local_res8,1);` |
| `FUN_140268470` | 1 | 908462 | `if ((param_1 != 0) && (*(longlong *)(param_1 + 0x80) != 0)) {` |
| `FUN_14026d3d0` | 1 | 914830 | `FUN_140195730(*(undefined8 *)(lVar1 + 0x80),param_2,param_3);` |
| `FUN_14026eba0` | 1 | 916692 | `uVar3 = FUN_14026ffd0(*(undefined8 *)(param_1 + 0x80),0,&local_48,0x40);` |
| `FUN_140270a20` | 1 | 919042 | `*(longlong *)(param_3 + 0x78) + (ulonglong)(ushort)(sVar4 - *(short *)(param_3 + 0x80));` |
| `FUN_140271e50` | 1 | 920236 | `iVar1 = FUN_14026ffd0(*(undefined8 *)(param_1 + 0x80),0x12,&local_48,0x40);` |
| `FUN_140273ce0` | 1 | 922740 | `iVar5 = FUN_14026ffd0(*(undefined8 *)(param_1 + 0x80),5,&local_a8,0x40);` |
| `FUN_140275340` | 1 | 924426 | `iVar1 = FUN_140195730(*(undefined8 *)(param_1 + 0x80),&local_res10,5);` |
| `FUN_140275a70` | 1 | 925000 | `iVar2 = FUN_140276c10(*(undefined8 *)(param_1 + 0x80),&local_88,0x80);` |
| `FUN_140277a30` | 1 | 928122 | `iVar1 = FUN_140193880(*(undefined8 *)(param_1 + 0x80),&local_58,0x41);` |
| `FUN_14027a9c0` | 1 | 932192 | `iVar1 = FUN_140195730(*(undefined8 *)(param_1 + 0x80),&local_18,0xc);` |
| `FUN_14027b200` | 1 | 932866 | `iVar3 = FUN_140193520(*(undefined8 *)(param_1 + 0x80),local_408,0x400);` |
| `FUN_14027df20` | 1 | 936416 | `iVar1 = FUN_140195730(*(undefined8 *)(param_1 + 0x80),&local_18,10);` |
| `FUN_14027df70` | 1 | 936496 | `iVar3 = FUN_140193880(*(undefined8 *)(param_1 + 0x80),&local_48,0x40);` |
| `FUN_14027e670` | 1 | 937004 | `uVar3 = FUN_140193900(*(undefined8 *)(param_1 + 0x80),1);` |
| `FUN_14027e740` | 1 | 937136 | `iVar3 = FUN_140193780(*(undefined8 *)(param_1 + 0x80),&local_28,lVar7);` |
| `FUN_14027ea50` | 1 | 937284 | `iVar1 = FUN_140195730(*(undefined8 *)(param_1 + 0x80),param_3,(longlong)param_4);` |
| `FUN_14027f510` | 1 | 938036 | `iVar1 = FUN_140195730(*(undefined8 *)(param_1 + 0x80),&local_res8,7);` |
| `FUN_14027f900` | 1 | 938432 | `iVar1 = FUN_140195730(*(undefined8 *)(param_1 + 0x80),&local_res18,7);` |
| `FUN_140280e70` | 1 | 940096 | `iVar1 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),param_3,param_4,0);` |
| `FUN_140282360` | 1 | 941830 | `iVar1 = FUN_140195730(*(undefined8 *)(param_1 + 0x80),&local_28,0x20);` |
| `FUN_1402823d0` | 1 | 941870 | `iVar1 = FUN_140195730(*(undefined8 *)(param_1 + 0x80),&local_res8,6);` |
| `FUN_140282420` | 1 | 941906 | `iVar1 = FUN_140195730(*(undefined8 *)(param_1 + 0x80),local_res8,4);` |
| `FUN_140282590` | 1 | 942098 | `iVar1 = FUN_140195730(*(undefined8 *)(param_1 + 0x80),&local_38,0x30);` |
| `FUN_1402827e0` | 1 | 942364 | `iVar1 = FUN_140195730(*(undefined8 *)(param_1 + 0x80),&local_38,0x30);` |
| `FUN_140283540` | 1 | 943404 | `uVar2 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),local_88,0x80,10);` |
| `FUN_1402a05f0` | 1 | 984084 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402a2a20` | 1 | 987054 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402a4600` | 1 | 988970 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402a4830` | 1 | 989138 | `bVar2 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402a4af0` | 1 | 989310 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402a4d20` | 1 | 989478 | `bVar2 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402a4fd0` | 1 | 989668 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402a5550` | 1 | 990044 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402a5ad0` | 1 | 990428 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402a60f0` | 1 | 990816 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402a70f0` | 1 | 991884 | `bVar2 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402a7280` | 1 | 992020 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402a74b0` | 1 | 992188 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402a79c0` | 1 | 992534 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402a8940` | 1 | 993580 | `bVar2 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402a8ae0` | 1 | 993712 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402a8d10` | 1 | 993878 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402a94e0` | 1 | 994504 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402a9cc0` | 1 | 995038 | `bVar2 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402a9e60` | 1 | 995170 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402aa520` | 1 | 995670 | `bVar2 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402aaf40` | 1 | 996352 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402ab4a0` | 1 | 996686 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402ab6d0` | 1 | 996854 | `bVar2 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402abc80` | 1 | 997324 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402ac440` | 1 | 997874 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402ac5d0` | 1 | 998008 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402ac800` | 1 | 998184 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402ace20` | 1 | 998560 | `bVar2 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402ad410` | 1 | 998986 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402ae8a0` | 1 | 1000494 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402aead0` | 1 | 1000646 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402aecc0` | 1 | 1000800 | `bVar2 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402aef70` | 1 | 1000978 | `bVar2 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402af1d0` | 1 | 1001158 | `bVar2 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402af720` | 1 | 1001526 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402afc90` | 1 | 1001906 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402b0260` | 1 | 1002290 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402b16e0` | 1 | 1003768 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402b18c0` | 1 | 1003918 | `bVar2 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402b1b20` | 1 | 1004098 | `bVar2 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402b2070` | 1 | 1004440 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402b2200` | 1 | 1004574 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402b2430` | 1 | 1004740 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402b2940` | 1 | 1005088 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402b2f10` | 1 | 1005466 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402b3df0` | 1 | 1006604 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402b4780` | 1 | 1007260 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402b4cf0` | 1 | 1007588 | `bVar2 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402b4e90` | 1 | 1007720 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402b50c0` | 1 | 1007886 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402b5a00` | 1 | 1008622 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402b5f90` | 1 | 1008974 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402b6900` | 1 | 1009648 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402b7380` | 1 | 1010332 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402b77b0` | 1 | 1010696 | `bVar2 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402b7ce0` | 1 | 1011092 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402b8270` | 1 | 1011444 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402b8450` | 1 | 1011594 | `bVar2 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402b86b0` | 1 | 1011770 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402b8bf0` | 1 | 1012150 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402b9210` | 1 | 1012534 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402ba620` | 1 | 1013976 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402ba810` | 1 | 1014120 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402baa40` | 1 | 1014284 | `bVar2 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402baca0` | 1 | 1014456 | `bVar2 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402baf50` | 1 | 1014642 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402bb490` | 1 | 1015014 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402bba20` | 1 | 1015394 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402bbff0` | 1 | 1015778 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402bd7d0` | 1 | 1017380 | `bVar3 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402bd980` | 1 | 1017524 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402bde90` | 1 | 1017852 | `bVar2 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402be0e0` | 1 | 1018018 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402be5f0` | 1 | 1018364 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402beb90` | 1 | 1018724 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402c02d0` | 1 | 1020304 | `bVar2 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402c0460` | 1 | 1020440 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402c0690` | 1 | 1020608 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402c0ba0` | 1 | 1020950 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402c10b0` | 1 | 1021296 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402c1650` | 1 | 1021656 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402c2f70` | 1 | 1023368 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402c31a0` | 1 | 1023536 | `bVar2 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402c3460` | 1 | 1023708 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402c3690` | 1 | 1023876 | `bVar2 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402c3950` | 1 | 1024066 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402c3ed0` | 1 | 1024442 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402c4450` | 1 | 1024826 | `bVar1 = *(byte *)(param_1 + 0x80);` |
| `FUN_1402df9d0` | 1 | 1078706 | `plVar1 = *(longlong **)(param_1 + 0x80);` |
| `FUN_1402dfa74` | 1 | 1078800 | `plVar1 = *(longlong **)(param_1 + 0x80);` |
| `FUN_1402dfb1c` | 1 | 1078880 | `puVar2 = *(undefined8 **)(param_1 + 0x80);` |
| `FUN_1402dfcc0` | 1 | 1079100 | `puVar2 = *(undefined8 **)(param_1 + 0x80);` |
| `FUN_1402e0c88` | 1 | 1081326 | `plVar1 = *(longlong **)(param_1 + 0x80);` |
| `FUN_1402e842c` | 1 | 1096250 | `FUN_1402e9a80(*(undefined8 *)(local_20 + 0x80));` |
| `FUN_1402e9cd4` | 1 | 1099248 | `((param_1 == 2 && ((*(byte *)(DAT_1403ff160 + 0x80) & 1) != 0)))) {` |
| `FUN_1402f4f90` | 1 | 1119454 | `if (*(undefined **)(param_1 + 0x80) != PTR_DAT_1403e8d00) {` |
| `FUN_1402f9cb0` | 1 | 1129864 | `plVar1 = *(longlong **)(param_2 + 0x80);` |
| `FUN_1402ffab9` | 1 | 1132950 | `*(undefined8 *)(param_2 + 0x80),lVar2,*(undefined8 *)(param_2 + 0x90),0,0,1);` |
| `FUN_1402ffb60` | 1 | 1133010 | `*(undefined8 *)(param_2 + 0x80),lVar2,*(undefined8 *)(param_2 + 0x90),0,0,1);` |

## `+0x84` (132 dec)

42 functions, 51 read sites.

| Function | Hits | First line | First snippet |
|---|---|---|---|
| `FUN_140021550` | 4 | 32874 | `(fVar30 * fVar24 - *(float *)(param_1 + 0x8c) * fVar39) + *(float *)(param_1 + 0x84);` |
| `FUN_140009ca0` | 2 | 6570 | `(*(float *)(param_1 + 0x80) * fVar2 + fVar1 * *(float *)(param_1 + 0x84) +` |
| `FUN_14001b740` | 2 | 27142 | `fVar10 = *(float *)(lVar3 + 0x84);` |
| `FUN_14001f210` | 2 | 31020 | `fVar34 = *(float *)(lVar20 + 0x84);` |
| `FUN_1400aabb0` | 2 | 198816 | `*(undefined1 *)(param_1 + 0x84));` |
| `FUN_14015fd50` | 2 | 472486 | `iVar4 = (uVar1 >> 3 & 0x1f) * *(int *)(param_1 + 0x84) * *(int *)(param_1 + 100);` |
| `FUN_14016fc90` | 2 | 496936 | `*(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(param_1 + 0x84);` |
| `FUN_140008560` | 1 | 5416 | `fVar25 = *(float *)(param_1 + 0x84) - *(float *)(param_1 + 0xd8);` |
| `FUN_140009380` | 1 | 6110 | `fVar29 = *(float *)(param_1 + 0x84) - *(float *)(param_1 + 0xd8);` |
| `FUN_140009b70` | 1 | 6420 | `fVar2 = *(float *)(param_1 + 0x84);` |
| `FUN_14000a0a0` | 1 | 7018 | `fVar15 = *(float *)(param_1 + 0x84) - *(float *)(param_1 + 0xd8);` |
| `FUN_14000ace0` | 1 | 7728 | `fVar22 = *(float *)(param_1 + 0x84) - *(float *)(param_1 + 0xd8);` |
| `FUN_14000b4a0` | 1 | 8272 | `fVar14 = *(float *)(param_1 + 0x84) - *(float *)(param_1 + 0xc0);` |
| `FUN_14000bc20` | 1 | 8674 | `fVar20 = *(float *)(param_1 + 0x84) - *(float *)(param_1 + 0xc0);` |
| `FUN_1400145b0` | 1 | 18954 | `fVar10 = (fVar19 + fVar17) - *(float *)(param_1 + 0x84);` |
| `FUN_140014e30` | 1 | 19398 | `fVar15 = (fVar2 + fVar26) - *(float *)(param_1 + 0x84);` |
| `FUN_140018650` | 1 | 24374 | `fVar16 = *(float *)(param_1 + 0x84) - *(float *)(param_1 + 0xc0);` |
| `FUN_140018e70` | 1 | 24938 | `fVar11 = ((fVar11 + fVar11) * *(float *)(param_1 + 0x84) * fVar20 + fVar14 * fVar15) * fVar14;` |
| `FUN_140019e50` | 1 | 25692 | `fVar16 = *(float *)(param_1 + 0x84) - *(float *)(param_1 + 0xbc);` |
| `FUN_14001a5b0` | 1 | 26074 | `fVar22 = *(float *)(param_1 + 0x84) - *(float *)(param_1 + 0xbc);` |
| `FUN_14001aaa0` | 1 | 26470 | `fVar12 = ((fVar12 + fVar12) * *(float *)(param_1 + 0x84) * fVar17 + fVar14 * fVar18) * fVar14;` |
| `FUN_14001d410` | 1 | 28656 | `fVar12 = *(float *)(param_1 + 0x84) - *(float *)(param_1 + 0xc0);` |
| `FUN_14001da30` | 1 | 28914 | `fVar2 = *(float *)(param_1 + 0x84);` |
| `FUN_1400b6fd0` | 1 | 211724 | `uStack_94 = *(undefined4 *)(lVar3 + 0x84);` |
| `FUN_140154990` | 1 | 455192 | `*(float *)(lVar1 + 0x94) = param_3 * *(float *)(lVar1 + 0x84);` |
| `FUN_14015d7a0` | 1 | 468972 | `if ((cVar2 == '\0') \|\| (param_3 != *(int *)(param_1 + 0x84))) {` |
| `FUN_14015e2b0` | 1 | 470084 | `*param_3 = *(undefined4 *)(lVar2 + 0x84);` |
| `FUN_140170800` | 1 | 497944 | `uVar4 = FUN_140172190(param_1,*(undefined4 *)(param_1 + 0x84),*(undefined4 *)(param_1 + 0x88));` |
| `FUN_140171f80` | 1 | 499986 | `*(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(param_1 + 0x84);` |
| `FUN_1401bce00` | 1 | 624120 | `(uVar2 = *(uint *)(param_2 + 0x84), uVar2 == *(uint *)(param_3 + 0x84))) &&` |
| `FUN_1401beac0` | 1 | 627248 | `if ((*(int *)(param_1 + 0x84) != 0) && (*(int *)(param_2 + 0x84) == 0)) {` |
| `FUN_140209760` | 1 | 724478 | `uStack_c = *(undefined4 *)(lVar1 + 0x84);` |
| `FUN_140209880` | 1 | 724558 | `uStack_c = *(undefined4 *)(lVar1 + 0x84);` |
| `FUN_14020fa50` | 1 | 733396 | `uVar3 = *(undefined4 *)(lVar1 + 0x84);` |
| `FUN_1402150d0` | 1 | 741636 | `iVar3 = (**(code **)(*plVar1 + 0x18))(plVar1,*(undefined4 *)(param_1 + 0x84),&local_res8);` |
| `FUN_1402151a0` | 1 | 741724 | `uVar3 = (**(code **)(*plVar1 + 0x20))(plVar1,*(undefined4 *)(param_1 + 0x84),0);` |
| `FUN_1402155b0` | 1 | 742160 | `if ((cVar2 == '\0') && (local_res10[0] <= *(uint *)(param_1 + 0x84))) {` |
| `FUN_140215880` | 1 | 742656 | `dVar16 = (double)thunk_FUN_1402e1d50((double)*(int *)(param_1 + 0x84) /` |
| `FUN_140216e70` | 1 | 744404 | `iVar7 = *(int *)(param_1 + 0x84) * 1000;` |
| `FUN_1402171e0` | 1 | 744692 | `iVar2 = *(int *)(param_1 + 0x84) * 1000;` |
| `FUN_14022a9d0` | 1 | 773106 | `*param_7 = *(int *)(param_1 + 0x84);` |
| `FUN_14022b5f0` | 1 | 774192 | `*param_3 = *(int *)(param_2 + 0x84);` |

## `+0x88` (136 dec)

116 functions, 162 read sites.

| Function | Hits | First line | First snippet |
|---|---|---|---|
| `FUN_1400113e0` | 6 | 15370 | `*(undefined8 *)(lVar13 + 0x38) = *(undefined8 *)(lVar5 + 0x88);` |
| `FUN_1402f40d8` | 6 | 1117512 | `if (iVar16 == *(int *)(*(longlong *)(local_res18 + 0x88) + 4)) {` |
| `FUN_14004b750` | 5 | 86040 | `lVar3 = *(longlong *)(DAT_1403ea2a8 + 0x88);` |
| `FUN_14001b740` | 4 | 27128 | `param_1[0x13] = *(undefined8 *)(lVar3 + 0x88);` |
| `FUN_140021550` | 4 | 32870 | `*(float *)(param_1 + 0x88);` |
| `FUN_1401c6d10` | 4 | 637738 | `lVar4 = *(longlong *)(param_1 + 0x88);` |
| `FUN_1401e7230` | 4 | 681026 | `*(longlong *)(puVar8 + 4) + (ulonglong)*(uint *)(lVar3 + 0x88) * lVar9;` |
| `FUN_1401ec9f0` | 4 | 687744 | `(**(code **)(lVar1 + 0x88))(1,piVar2);` |
| `FUN_1400ba940` | 3 | 216316 | `((*(int *)(lVar26 + 100 + lVar27) == 0 && (*(longlong *)(lVar28 + 0x88) != 0)))) &&` |
| `FUN_1401b9390` | 3 | 619106 | `lVar1 = *(longlong *)(uVar4 * 8 + *(longlong *)(param_2 + 0x88));` |
| `FUN_140009ca0` | 2 | 6566 | `return ((*(float *)(param_1 + 0x88) * *(float *)(lVar3 + 0x14) +` |
| `FUN_140011000` | 2 | 14830 | `if (param_2 + 0x20 == *(longlong *)(lVar4 + 0x88)) {` |
| `FUN_140155130` | 2 | 455982 | `if (*(code **)(lVar2 + 0x88) != (code *)0x0) {` |
| `FUN_1401575b0` | 2 | 458852 | `FUN_1401841e0(*(undefined8 *)(uVar3 + 8 + *(longlong *)(param_1 + 0x88)));` |
| `FUN_140161f10` | 2 | 476166 | `(bVar3 = true, (*(uint *)(*(longlong *)(lVar6 + 0x88) + 0x48) >> 0xf & 1) == 0)) {` |
| `FUN_14016fc90` | 2 | 496940 | `*(undefined4 *)(param_1 + 0x78) = *(undefined4 *)(param_1 + 0x88);` |
| `FUN_1401812e0` | 2 | 524960 | `if (*(code **)(lVar1 + 0x88) != (code *)0x0) {` |
| `FUN_140191d70` | 2 | 555520 | `if (*(longlong *)(param_1 + 0x88) != 0) {` |
| `FUN_140191e00` | 2 | 555566 | `if (*(longlong *)(param_1 + 0x88) != 0) {` |
| `FUN_140191e90` | 2 | 555612 | `if (*(longlong *)(param_1 + 0x88) != 0) {` |
| `FUN_1401de770` | 2 | 669320 | `if (*(longlong **)(lVar1 + 0x88) != (longlong *)0x0) {` |
| `FUN_1401f9a50` | 2 | 703746 | `if (*(longlong *)(lVar1 + 0x88) != 0) {` |
| `FUN_14020bde0` | 2 | 727924 | `if (*(code **)(lVar1 + 0x88) != (code *)0x0) {` |
| `FUN_140006230` | 1 | 2482 | `for (plVar1 = *(longlong **)(lVar4 + 0x88); plVar1 != (longlong *)0x0;` |
| `FUN_140008560` | 1 | 5420 | `fVar27 = *(float *)(param_1 + 0x88) - *(float *)(param_1 + 0xdc);` |
| `FUN_140009380` | 1 | 6120 | `fVar25 = *(float *)(param_1 + 0x88) - *(float *)(param_1 + 0xdc);` |
| `FUN_140009bd0` | 1 | 6464 | `fVar1 = *(float *)(param_1 + 0x88);` |
| `FUN_140009f00` | 1 | 6786 | `uVar3 = *(uint *)(param_1 + 0x88) ^ DAT_14039cac0;` |
| `FUN_14000a0a0` | 1 | 7026 | `fVar10 = *(float *)(param_1 + 0x88) - *(float *)(param_1 + 0xdc);` |
| `FUN_14000ace0` | 1 | 7732 | `fVar23 = *(float *)(param_1 + 0x88) - *(float *)(param_1 + 0xdc);` |
| `FUN_14000b4a0` | 1 | 8284 | `fVar11 = *(float *)(param_1 + 0x88) - *(float *)(param_1 + 0xc4);` |
| `FUN_14000bc20` | 1 | 8682 | `fVar13 = *(float *)(param_1 + 0x88) - *(float *)(param_1 + 0xc4);` |
| `FUN_14000d3c0` | 1 | 10412 | `puVar1[0x11] = *(undefined8 *)(param_1 + 0x88);` |
| `FUN_140010310` | 1 | 13762 | `lVar3 = *(longlong *)(param_1 + 0x88);` |
| `FUN_1400145b0` | 1 | 18962 | `fVar18 = (fVar9 + fVar18) - *(float *)(param_1 + 0x88);` |
| `FUN_140014e30` | 1 | 19402 | `fVar19 = (fVar3 + fVar17) - *(float *)(param_1 + 0x88);` |
| `FUN_140018650` | 1 | 24386 | `fVar13 = *(float *)(param_1 + 0x88) - *(float *)(param_1 + 0xc4);` |
| `FUN_140018e70` | 1 | 24840 | `fVar15 = *(float *)(param_1 + 0x88) - *(float *)(param_1 + 200);` |
| `FUN_140019960` | 1 | 25328 | `fVar17 = *(float *)(param_1 + 0x88) - *(float *)(param_1 + 200);` |
| `FUN_140019cf0` | 1 | 25430 | `fVar1 = *(float *)(param_1 + 0x88);` |
| `FUN_140019e50` | 1 | 25702 | `fVar13 = *(float *)(param_1 + 0x88) - *(float *)(param_1 + 0xc0);` |
| `FUN_14001a5b0` | 1 | 26090 | `fVar18 = *(float *)(param_1 + 0x88) - *(float *)(param_1 + 0xc0);` |
| `FUN_14001b040` | 1 | 26646 | `*(float *)(param_1 + 0x88) + *(float *)(param_1 + 0xa0) * *(float *)(param_1 + 0x9c)) *` |
| `FUN_14001bb70` | 1 | 27378 | `lVar5 = *(longlong *)(param_1 + 0x88);` |
| `FUN_14001d410` | 1 | 28698 | `((fVar10 + fVar1) - *(float *)(param_1 + 0x88)) * *(float *)(param_1 + 0x98);` |
| `FUN_14001da20` | 1 | 28878 | `*param_2 = *(undefined8 *)(param_1 + 0x88);` |
| `FUN_140026370` | 1 | 39866 | `if (0xf < *(ulonglong *)(param_1 + 0x88)) {` |
| `FUN_140026b90` | 1 | 40764 | `lVar3 = *(longlong *)(param_1 + 0x88);` |
| `FUN_140043aa0` | 1 | 75490 | `thunk_FUN_1402e9a80(*(undefined8 *)(DAT_1403ea2a8 + 0x88));` |
| `FUN_14004f010` | 1 | 90842 | `lVar1 = *(longlong *)(DAT_1403ea2a8 + 0x88);` |
| `FUN_1400831e0` | 1 | 153028 | `*(int *)(param_1 + 0x70) == 0xb,*(undefined4 *)(param_1 + 0x88));` |
| `FUN_1400b6fd0` | 1 | 211726 | `local_90 = *(undefined4 *)(lVar3 + 0x88);` |
| `FUN_1400bea50` | 1 | 220008 | `*(undefined8 *)(puVar8 + 0x1f) = *(undefined8 *)(lVar10 + 0x88);` |
| `FUN_1400cf540` | 1 | 239612 | `if ((ulonglong)(*(longlong *)(param_1 + 0x88) - lVar3 >> 4) < uVar2) {` |
| `FUN_1400fbae0` | 1 | 295576 | `if (*(int *)(param_1 + 0x88) < iVar6) {` |
| `FUN_140102b40` | 1 | 304414 | `fVar7 = (float)(*(uint *)(param_2 + 0x88) ^ DAT_14039cac0);` |
| `FUN_140138000` | 1 | 413314 | `(**(code **)(param_1 + 0x88))(*(undefined8 *)(param_1 + 0x298));` |
| `FUN_14013ef20` | 1 | 424998 | `piVar3 = (int *)((longlong)param_2 * 0x10 + *(longlong *)(lVar2 + 0x88));` |
| `FUN_14013f2b0` | 1 | 425376 | `uVar2 = *(undefined4 *)(*(longlong *)(lVar1 + 0x88) + (longlong)param_2 * 0x10);` |
| `FUN_14015a220` | 1 | 463926 | `lVar2 = FUN_140184230(*(undefined8 *)(param_1 + 0x88),lVar4 + 0x10);` |
| `FUN_14015a3a0` | 1 | 464118 | `piVar3 = (int *)((longlong)iVar2 * 0x10 + *(longlong *)(param_1 + 0x88));` |
| `FUN_140160090` | 1 | 472796 | `FUN_1402f94c0(param_2,*(undefined4 *)(param_1 + 0x88),(longlong)param_3);` |
| `FUN_140161230` | 1 | 474916 | `return *(undefined8 *)(lVar1 + 0x88);` |
| `FUN_1401613c0` | 1 | 475144 | `if ((param_1 != 0) \|\| (param_1 = *(longlong *)(lVar2 + 0x88), param_1 != 0)) {` |
| `FUN_1401618c0` | 1 | 475716 | `if (((param_1 != 0) \|\| (param_1 = *(longlong *)(lVar1 + 0x88), param_1 != 0)) &&` |
| `FUN_140161be0` | 1 | 476044 | `local_a8 = **(undefined4 **)(lVar2 + 0x88);` |
| `FUN_1401629c0` | 1 | 476956 | `local_a8 = **(undefined4 **)(lVar2 + 0x88);` |
| `FUN_140162ca0` | 1 | 477198 | `lVar1 = *(longlong *)(lVar2 + 0x88);` |
| `FUN_140162ed0` | 1 | 477450 | `(*(longlong *)(lVar3 + 0x88) != 0)) &&` |
| `FUN_140162f40` | 1 | 477508 | `lVar5 = *(longlong *)(lVar4 + 0x88);` |
| `FUN_140163030` | 1 | 477586 | `lVar1 = *(longlong *)(lVar1 + 0x88);` |
| `FUN_14016df60` | 1 | 493502 | `uVar2 = (**(code **)(DAT_1403fc410 + 0x88))(DAT_1403fc410,param_1,puVar4,puVar3,puVar6,puVar5)` |
| `FUN_140170800` | 1 | 497944 | `uVar4 = FUN_140172190(param_1,*(undefined4 *)(param_1 + 0x84),*(undefined4 *)(param_1 + 0x88));` |
| `FUN_140171f80` | 1 | 499988 | `*(undefined4 *)(param_1 + 0x78) = *(undefined4 *)(param_1 + 0x88);` |
| `FUN_14017ba60` | 1 | 515632 | `if (*(longlong *)(param_1 + 0x88) != 0) {` |
| `FUN_140191f20` | 1 | 555650 | `lVar1 = *(longlong *)(param_1 + 0x88);` |
| `FUN_1401a6b30` | 1 | 592276 | `**(longlong **)(param_1 + 0x98) = *(longlong *)(param_1 + 0xb0) - *(longlong *)(param_1 + 0x88);` |
| `FUN_1401bafe0` | 1 | 621566 | `(uVar2 = (uint)param_2[0x11], uVar2 == *(uint *)(param_3 + 0x88))) {` |
| `FUN_1401bce00` | 1 | 624178 | `in_RAX = (ulonglong)*(uint *)(param_3 + 0x88);` |
| `FUN_1401beac0` | 1 | 627260 | `if ((*(int *)(param_1 + 0x88) != 0) && (*(int *)(param_2 + 0x88) == 0)) {` |
| `FUN_1401c97e0` | 1 | 641660 | `if (*(longlong *)(param_1 + 0x88) != 0) {` |
| `FUN_1401d0e20` | 1 | 652414 | `puVar24 = (uint *)(*(longlong *)(param_1 + 0x88) + 4);` |
| `FUN_1401d1440` | 1 | 653160 | `puVar26 = (uint *)(*(longlong *)(param_1 + 0x88) + 4);` |
| `FUN_1401d2c00` | 1 | 655116 | `FUN_1401841e0(*(undefined8 *)(param_1 + 0x88));` |
| `FUN_1401de5a0` | 1 | 669072 | `plVar5 = *(longlong **)(lVar1 + 0x88);` |
| `FUN_1401df5c0` | 1 | 670346 | `(*(longlong **)(lVar1 + 0x10),0,*(undefined8 *)(lVar1 + 0x88));` |
| `FUN_1401e6b30` | 1 | 680240 | `puVar3[1] = puVar3[1] + (ulonglong)*(uint *)(lVar1 + 0x88) * lVar5;` |
| `FUN_1401e9660` | 1 | 683896 | `uVar1 = *(undefined4 *)(lVar3 + 0x88);` |
| `FUN_1401f4bb0` | 1 | 697000 | `(**(code **)(param_1 + 0x88))();` |
| `FUN_1401fe550` | 1 | 708896 | `lVar6 = *(longlong *)(lVar3 + 0x88);` |
| `FUN_140205900` | 1 | 718548 | `if (*(uint *)(param_1 + 0x88) < param_3) {` |
| `FUN_14020bc00` | 1 | 727824 | `if (*(longlong *)(lVar2 + 0x88) != 0) {` |
| `FUN_1402153b0` | 1 | 741998 | `FUN_1402f94c0(param_2,*(undefined4 *)(param_1 + 0x88));` |
| `FUN_140215f20` | 1 | 743082 | `FUN_1402f94c0(local_res18,*(undefined4 *)(param_1 + 0x88),local_res10[0]);` |
| `FUN_140216e70` | 1 | 744456 | `FUN_1402f94c0(lVar9,*(undefined4 *)(param_1 + 0x88),(longlong)*(int *)(param_1 + 0x6c));` |
| `FUN_140217040` | 1 | 744554 | `FUN_1402f94c0(param_2,*(undefined4 *)(param_1 + 0x88),(longlong)iVar3);` |
| `FUN_140218f20` | 1 | 747532 | `(**(code **)(lVar1 + 0x88))(*(undefined8 *)(lVar1 + 0x10));` |
| `FUN_14021d910` | 1 | 754944 | `(**(code **)(param_1 + 0x88))(param_1 + 0x90);` |
| `FUN_14022a9d0` | 1 | 773108 | `uVar8 = (ulonglong)*(uint *)(param_1 + 0x88);` |
| `FUN_14022b5f0` | 1 | 774194 | `*param_4 = *(LONG *)(param_2 + 0x88);` |
| `FUN_140268990` | 1 | 908864 | `lVar2 = *(longlong *)(lVar1 + 0x88);` |
| `FUN_140269ba0` | 1 | 911352 | `lVar2 = *(longlong *)(param_1 + 0x88);` |
| `FUN_140270a20` | 1 | 918844 | `if (*(byte *)(param_3 + 0x88) != bVar7) {` |
| `FUN_140272cb0` | 1 | 921484 | `if (*(byte *)(param_3 + 0x88) != bVar1) {` |
| `FUN_14028b000` | 1 | 954256 | `return (int)((double)iVar4 * *(double *)(param_1 + 0x88));` |
| `FUN_14028b250` | 1 | 954492 | `return (int)((double)iVar6 * *(double *)(param_1 + 0x88));` |
| `FUN_1402d74e0` | 1 | 1063862 | `*(undefined8 *)(param_1 + 0x20) = *(undefined8 *)(lVar1 + 0x88);` |
| `FUN_1402d8d60` | 1 | 1068162 | `*(undefined8 *)(this + 0x10) = *(undefined8 *)(lVar3 + 0x88);` |
| `FUN_1402e01d4` | 1 | 1079784 | `uVar7 = *(undefined4 *)(param_1 + 0x88);` |
| `FUN_1402f4f90` | 1 | 1119460 | `if (*(undefined **)(param_1 + 0x88) != PTR_DAT_1403e8d08) {` |
| `FUN_1402f5850` | 1 | 1120528 | `uStack_18 = *(undefined8 *)(local_28 + 0x88);` |
| `FUN_1402fcc9e` | 1 | 1130656 | `FUN_1402c7088(*(undefined8 *)(param_2 + 0x88),0x498);` |
| `FUN_1402fd1f3` | 1 | 1130806 | `FUN_1402c7088(*(undefined8 *)(param_2 + 0x88),0x58);` |
| `FUN_1402ff33f` | 1 | 1132514 | `FUN_140030810(*(undefined8 *)(param_2 + 0x88));` |
| `FUN_1402ffab9` | 1 | 1132934 | `lVar2 = *(longlong *)(param_2 + 0x88);` |
| `FUN_1402ffb60` | 1 | 1132990 | `lVar2 = *(longlong *)(param_2 + 0x88);` |

## `+0x8c` (140 dec)

71 functions, 95 read sites.

| Function | Hits | First line | First snippet |
|---|---|---|---|
| `FUN_140021550` | 6 | 32868 | `fVar24 * *(float *)(param_1 + 0x8c) + fVar30 * *(float *)(param_5 + 0x14) +` |
| `FUN_1402706d0` | 3 | 918548 | `if (0 < *(int *)(param_1 + 0x8c)) {` |
| `FUN_140272910` | 3 | 921186 | `if (0 < *(int *)(param_1 + 0x8c)) {` |
| `FUN_14027ab70` | 3 | 932372 | `if (0 < *(int *)(param_1 + 0x8c)) {` |
| `FUN_140009ca0` | 2 | 6568 | `*(float *)(lVar3 + 0x18) * *(float *)(param_1 + 0x8c) + *(float *)(lVar3 + 0x10)) -` |
| `FUN_1400fbae0` | 2 | 295614 | `if ((0 < *(int *)(param_1 + 0x8c)) &&` |
| `FUN_14018c820` | 2 | 542668 | `iVar8 = (int)*(undefined8 *)(lVar3 + 0x8c);` |
| `FUN_1402072d0` | 2 | 720712 | `lVar2 = FUN_140184230(*(undefined8 *)(param_1 + 0x90),(longlong)*(int *)(param_1 + 0x8c) * 4 + 4);` |
| `FUN_140207340` | 2 | 720750 | `iVar1 = *(int *)(param_1 + 0x8c);` |
| `FUN_140207920` | 2 | 721318 | `iVar2 = *(int *)(lVar1 + 0x8c);` |
| `FUN_140207ae0` | 2 | 721462 | `if (param_1 < *(int *)(lVar1 + 0x8c)) {` |
| `FUN_140208230` | 2 | 722184 | `if (0 < *(int *)(param_1 + 0x8c)) {` |
| `FUN_1402089a0` | 2 | 722932 | `if (0 < *(int *)(param_1 + 0x8c)) {` |
| `FUN_140208b70` | 2 | 723078 | `if (0 < *(int *)(param_1 + 0x8c)) {` |
| `FUN_140268cd0` | 2 | 909146 | `if (0 < *(int *)(param_1 + 0x8c)) {` |
| `FUN_14027dd30` | 2 | 936260 | `if (0 < *(int *)(param_1 + 0x8c)) {` |
| `FUN_140280d00` | 2 | 940016 | `if (0 < *(int *)(param_1 + 0x8c)) {` |
| `FUN_140008560` | 1 | 5426 | `fVar17 = *(float *)(param_1 + 0x8c) - *(float *)(param_1 + 0xe0);` |
| `FUN_140009380` | 1 | 6106 | `fVar33 = *(float *)(param_1 + 0x8c) - *(float *)(param_1 + 0xe0);` |
| `FUN_140009bd0` | 1 | 6466 | `fVar2 = *(float *)(param_1 + 0x8c);` |
| `FUN_14000a0a0` | 1 | 7028 | `fVar9 = *(float *)(param_1 + 0x8c) - *(float *)(param_1 + 0xe0);` |
| `FUN_14000ace0` | 1 | 7736 | `fVar19 = *(float *)(param_1 + 0x8c) - *(float *)(param_1 + 0xe0);` |
| `FUN_14000b4a0` | 1 | 8286 | `fVar10 = *(float *)(param_1 + 0x8c) - *(float *)(param_1 + 200);` |
| `FUN_14000bc20` | 1 | 8672 | `fVar22 = *(float *)(param_1 + 0x8c) - *(float *)(param_1 + 200);` |
| `FUN_1400145b0` | 1 | 18960 | `fVar17 = (fVar14 + fVar2) - *(float *)(param_1 + 0x8c);` |
| `FUN_140014e30` | 1 | 19400 | `fVar18 = (fVar4 + fVar21) - *(float *)(param_1 + 0x8c);` |
| `FUN_140018650` | 1 | 24388 | `fVar12 = *(float *)(param_1 + 0x8c) - *(float *)(param_1 + 200);` |
| `FUN_140018e70` | 1 | 24842 | `fVar20 = *(float *)(param_1 + 0x8c) - *(float *)(param_1 + 0xcc);` |
| `FUN_140019960` | 1 | 25330 | `fVar22 = *(float *)(param_1 + 0x8c) - *(float *)(param_1 + 0xcc);` |
| `FUN_140019cf0` | 1 | 25432 | `fVar2 = *(float *)(param_1 + 0x8c);` |
| `FUN_140019e50` | 1 | 25704 | `fVar12 = *(float *)(param_1 + 0x8c) - *(float *)(param_1 + 0xc4);` |
| `FUN_14001a5b0` | 1 | 26086 | `fVar23 = *(float *)(param_1 + 0x8c) - *(float *)(param_1 + 0xc4);` |
| `FUN_14001aaa0` | 1 | 26370 | `fVar14 = *(float *)(param_1 + 0x8c) - *(float *)(param_1 + 200);` |
| `FUN_14001b280` | 1 | 26786 | `fVar18 = *(float *)(param_1 + 0x8c) - *(float *)(param_1 + 200);` |
| `FUN_14001b650` | 1 | 26930 | `fVar1 = *(float *)(param_1 + 0x8c);` |
| `FUN_14001d410` | 1 | 28702 | `*(float *)(param_1 + 0x98) * ((fVar3 + fVar20) - *(float *)(param_1 + 0x8c));` |
| `FUN_140080e40` | 1 | 150712 | `iVar1 = *(int *)(param_1 + 0x8c);` |
| `FUN_140081600` | 1 | 151008 | `fVar3 = (float)*(int *)(param_1 + 0x8c) / DAT_14030338c;` |
| `FUN_140082060` | 1 | 151798 | `(*(int *)(param_1 + 0x8c) / 2 + *(int *)(param_1 + 0x74) / 2);` |
| `FUN_1400820a0` | 1 | 151852 | `(*(int *)(param_1 + 0x8c) / 2 + *(int *)(param_1 + 0x74) / 2) *` |
| `FUN_140082640` | 1 | 152286 | `iVar3 = *(int *)(param_1 + 0x8c);` |
| `FUN_1400b6fd0` | 1 | 211728 | `uStack_8c = *(undefined4 *)(lVar3 + 0x8c);` |
| `FUN_1400ba940` | 1 | 216866 | `((iVar16 = *(int *)(lVar34 + 0x8c), iVar16 != 0 \|\| (*(int *)(lVar34 + 0x90) != 0)))) {` |
| `FUN_140107660` | 1 | 313334 | `if ((((*(int *)(lVar16 + 0x74) < *(int *)(lVar16 + 0x8c) / 2) &&` |
| `FUN_1401bce00` | 1 | 624182 | `(in_RAX = (ulonglong)*(uint *)(param_3 + 0x8c),` |
| `FUN_1401beac0` | 1 | 627272 | `if ((*(int *)(param_1 + 0x8c) != 0) && (*(int *)(param_2 + 0x8c) == 0)) {` |
| `FUN_140207890` | 1 | 721238 | `iVar1 = *(int *)(param_1 + 0x8c);` |
| `FUN_140208110` | 1 | 722092 | `lVar4 = (longlong)*(int *)(lVar2 + 0x8c);` |
| `FUN_140218580` | 1 | 746638 | `FUN_1401cda90(param_2,0x205,*(undefined4 *)(param_2 + 0x8c),*(undefined4 *)(param_2 + 0x90));` |
| `FUN_14022a9d0` | 1 | 773116 | `FUN_140170020(param_1,*(undefined4 *)(param_1 + 0x8c),*(undefined4 *)(param_1 + 0x90),param_5,` |
| `FUN_140264c60` | 1 | 903754 | `if ((iVar4 < 0) && (0 < *(int *)(param_1 + 0x8c))) {` |
| `FUN_14026d850` | 1 | 915276 | `if (*(int *)(param_1 + 0x8c) < 1) {` |
| `FUN_14026e4e0` | 1 | 916084 | `if (*(int *)(param_1 + 0x8c) < 1) {` |
| `FUN_14026e8a0` | 1 | 916432 | `if (*(int *)(param_1 + 0x8c) < 1) {` |
| `FUN_14026eba0` | 1 | 916684 | `if (0 < *(int *)(param_1 + 0x8c)) {` |
| `FUN_1402734c0` | 1 | 922094 | `if (*(byte *)(param_3 + 0x8c) != bVar1) {` |
| `FUN_140274270` | 1 | 923034 | `if (0 < *(int *)(param_1 + 0x8c)) {` |
| `FUN_140274860` | 1 | 923712 | `if (*(int *)(param_1 + 0x8c) < 1) {` |
| `FUN_1402754a0` | 1 | 924574 | `if (*(int *)(param_1 + 0x8c) < 1) {` |
| `FUN_140275eb0` | 1 | 925412 | `if (0 < *(int *)(param_1 + 0x8c)) {` |
| `FUN_140277890` | 1 | 927964 | `if ((0 < *(int *)(param_1 + 0x8c)) &&` |
| `FUN_1402783e0` | 1 | 928802 | `if (*(int *)(param_1 + 0x8c) < 1) {` |
| `FUN_14027a3f0` | 1 | 931796 | `if (*(int *)(param_1 + 0x8c) < 1) {` |
| `FUN_14027b670` | 1 | 933196 | `if (*(int *)(param_1 + 0x8c) < 1) {` |
| `FUN_14027d2e0` | 1 | 935614 | `if (*(int *)(param_1 + 0x8c) < 1) {` |
| `FUN_14027e520` | 1 | 936858 | `if (0 < *(int *)(param_1 + 0x8c)) {` |
| `FUN_14027e740` | 1 | 937094 | `if ((*(int *)(param_1 + 0x8c) < 1) \|\|` |
| `FUN_14027ff50` | 1 | 939020 | `if (*(int *)(param_1 + 0x8c) < 1) {` |
| `FUN_140281f20` | 1 | 941436 | `if (0 < *(int *)(param_1 + 0x8c)) {` |
| `FUN_1402828a0` | 1 | 942404 | `if (*(int *)(param_1 + 0x8c) < 1) {` |
| `FUN_140283780` | 1 | 943644 | `if (*(int *)(param_1 + 0x8c) < 1) {` |

## `+0x90` (144 dec)

150 functions, 221 read sites.

| Function | Hits | First line | First snippet |
|---|---|---|---|
| `FUN_140021550` | 4 | 33458 | `fVar39 = *(float *)(param_1 + 0x90);` |
| `FUN_1401c6d10` | 4 | 637736 | `if (uVar14 - 2 < *(uint *)(param_1 + 0x90)) {` |
| `FUN_14004d8d0` | 3 | 89108 | `iVar13 = *(int *)(param_1 + 0x90);` |
| `FUN_1400fbae0` | 3 | 295726 | `iVar8 = *(int *)(param_1 + 0x90);` |
| `FUN_1401cc650` | 3 | 645816 | `(**(code **)(**(longlong **)(lVar1 + 0x90) + 0x50))(*(longlong **)(lVar1 + 0x90),1,&local_res8);` |
| `FUN_1401df5c0` | 3 | 670334 | `if (*(longlong **)(lVar1 + 0x90) != (longlong *)0x0) {` |
| `FUN_1401f32b0` | 3 | 695298 | `(**(code **)(lVar2 + 0x90))(uVar9,0,uVar11);` |
| `FUN_140205850` | 3 | 718480 | `FUN_1401384e0(*(undefined8 *)(param_1 + 0x90),param_1 + 0xe8);` |
| `FUN_1402706d0` | 3 | 918550 | `uVar5 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));` |
| `FUN_140272910` | 3 | 921188 | `uVar5 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));` |
| `FUN_14027ab70` | 3 | 932374 | `lVar3 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));` |
| `FUN_1402e0d04` | 3 | 1081606 | `local_res10[0] = *(longlong **)(lVar2 + 0x90);` |
| `FUN_140008560` | 2 | 5434 | `fVar22 = fVar13 * *(float *)(param_1 + 0x90) - fVar12 * *(float *)(param_1 + 0x94);` |
| `FUN_140009380` | 2 | 6136 | `fVar41 = *(float *)(param_1 + 0x90) * fVar20 - *(float *)(param_1 + 0x94) * fVar19;` |
| `FUN_140009ca0` | 2 | 6574 | `(*(float *)(param_1 + 0x94) * fVar1 + *(float *)(param_1 + 0x90) * fVar2) +` |
| `FUN_14000bc20` | 2 | 8724 | `fVar17 = fVar13 - *(float *)(param_1 + 0x90);` |
| `FUN_14001b740` | 2 | 27152 | `param_1[0x17] = *(undefined8 *)(lVar3 + 0x90);` |
| `FUN_14001d410` | 2 | 28614 | `fVar11 = *(float *)(param_1 + 0x90) * DAT_14039ca54;` |
| `FUN_14013b880` | 2 | 419238 | `lVar3 = *(longlong *)(lVar1 + 0x90);` |
| `FUN_14013dbb0` | 2 | 422708 | `if ((lVar1 != 0) && (0 < *(int *)(lVar1 + 0x90))) {` |
| `FUN_14013dc20` | 2 | 422772 | `if (0 < *(int *)(lVar1 + 0x90)) {` |
| `FUN_14013ed10` | 2 | 424774 | `if ((lVar1 != 0) && (0 < *(int *)(lVar1 + 0x90))) {` |
| `FUN_14013ed80` | 2 | 424830 | `if ((lVar1 != 0) && (0 < *(int *)(lVar1 + 0x90))) {` |
| `FUN_140142010` | 2 | 429818 | `if (0 < *(int *)(lVar4 + 0x90)) {` |
| `FUN_14015a600` | 2 | 464286 | `if (0 < *(int *)(param_1 + 0x90)) {` |
| `FUN_140161be0` | 2 | 475932 | `*(float *)(lVar2 + 0x90) / (float)*(int *)(param_2 + 0x20),` |
| `FUN_140161f10` | 2 | 476322 | `*(float *)(lVar6 + 0xa0) = *(float *)(lVar6 + 0x90);` |
| `FUN_1401812e0` | 2 | 524940 | `if (*(code **)(lVar1 + 0x90) != (code *)0x0) {` |
| `FUN_1401c97e0` | 2 | 641574 | `if (*(longlong **)(param_1 + 0x90) != (longlong *)0x0) {` |
| `FUN_1401de770` | 2 | 669328 | `if (*(longlong **)(lVar1 + 0x90) != (longlong *)0x0) {` |
| `FUN_1401e9870` | 2 | 684188 | `uVar11 = FUN_1401e60b0(*(undefined8 *)(lVar1 + 0x90),*param_8);` |
| `FUN_1401f9a50` | 2 | 703738 | `if (*(longlong *)(lVar1 + 0x90) != 0) {` |
| `FUN_140207340` | 2 | 720752 | `while ((iVar1 != 0 && (*(undefined4 **)(param_1 + 0x90) != (undefined4 *)0x0))) {` |
| `FUN_140207890` | 2 | 721242 | `piVar2 = *(int **)(param_1 + 0x90);` |
| `FUN_140207920` | 2 | 721320 | `while ((iVar2 != 0 && (*(undefined4 **)(lVar1 + 0x90) != (undefined4 *)0x0))) {` |
| `FUN_140208330` | 2 | 722268 | `CONCAT31((int3)((uint)**(int **)(lVar1 + 0x90) >> 8),` |
| `FUN_140208e20` | 2 | 723402 | `if (*(longlong *)(lVar1 + 0x90) != 0) {` |
| `FUN_14020be60` | 2 | 727976 | `if (*(code **)(lVar1 + 0x90) != (code *)0x0) {` |
| `FUN_140268cd0` | 2 | 909148 | `uVar6 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));` |
| `FUN_14026d850` | 2 | 915282 | `lVar3 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));` |
| `FUN_14026e4e0` | 2 | 916090 | `lVar3 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));` |
| `FUN_14026e8a0` | 2 | 916438 | `lVar3 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));` |
| `FUN_140274860` | 2 | 923718 | `lVar3 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));` |
| `FUN_1402754a0` | 2 | 924580 | `lVar3 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));` |
| `FUN_1402766c0` | 2 | 925938 | `if (*(undefined4 **)(param_1 + 0x90) != (undefined4 *)0x0) {` |
| `FUN_140277890` | 2 | 927966 | `(lVar5 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90)), lVar5 != 0)) {` |
| `FUN_1402783e0` | 2 | 928808 | `lVar4 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));` |
| `FUN_14027a3f0` | 2 | 931802 | `lVar3 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));` |
| `FUN_14027b670` | 2 | 933202 | `lVar3 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));` |
| `FUN_14027d2e0` | 2 | 935620 | `lVar3 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));` |
| `FUN_14027dd30` | 2 | 936262 | `lVar3 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));` |
| `FUN_14027e740` | 2 | 937096 | `(lVar5 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90)), lVar5 == 0)) {` |
| `FUN_14027ff50` | 2 | 939026 | `lVar3 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));` |
| `FUN_140280d00` | 2 | 940018 | `lVar4 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));` |
| `FUN_1402828a0` | 2 | 942410 | `lVar3 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));` |
| `FUN_140283780` | 2 | 943650 | `lVar4 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));` |
| `FUN_1402e8544` | 2 | 1096358 | `if (*(longlong *)(param_1 + 0x90) != 0) {` |
| `FUN_140009f00` | 1 | 6790 | `uVar4 = *(uint *)(param_1 + 0x90) ^ uVar1;` |
| `FUN_14000a0a0` | 1 | 7144 | `fVar13 = fVar18 * *(float *)(param_1 + 0x90);` |
| `FUN_14000b240` | 1 | 7842 | `*param_2 = param_3 * *(float *)(param_1 + 0x90);` |
| `FUN_14000b4a0` | 1 | 8322 | `if (0.0 < fVar18 - *(float *)(param_1 + 0x90)) {` |
| `FUN_14000b9a0` | 1 | 8498 | `fVar18 = *(float *)(param_1 + 0x94) - *(float *)(param_1 + 0x90);` |
| `FUN_14000bfd0` | 1 | 8836 | `return *(undefined4 *)(param_1 + 0x90);` |
| `FUN_14000d3c0` | 1 | 10414 | `puVar1[0x12] = *(undefined8 *)(param_1 + 0x90);` |
| `FUN_1400145b0` | 1 | 18930 | `fVar14 = *(float *)(param_1 + 0x90) - *(float *)(param_1 + 0xd4);` |
| `FUN_140014e30` | 1 | 19380 | `fVar24 = *(float *)(param_1 + 0x90) - *(float *)(param_1 + 0xd4);` |
| `FUN_1400152f0` | 1 | 19560 | `fVar1 = *(float *)(param_1 + 0x90);` |
| `FUN_140018650` | 1 | 24446 | `fVar14 = *(float *)(param_2 + 8) * *(float *)(param_1 + 0x90);` |
| `FUN_140018e70` | 1 | 24850 | `fVar20 = *(float *)(param_1 + 0x90) - *(float *)(param_1 + 0xd0);` |
| `FUN_140019960` | 1 | 25336 | `fVar16 = *(float *)(param_1 + 0x90) - *(float *)(param_1 + 0xd0);` |
| `FUN_140019d50` | 1 | 25476 | `fVar1 = *(float *)(param_1 + 0x90);` |
| `FUN_14001a5b0` | 1 | 26100 | `for (fVar18 = (fVar5 - fVar1) - *(float *)(param_1 + 0x90); DAT_14039ca50 < fVar18;` |
| `FUN_14001aaa0` | 1 | 26368 | `fVar18 = *(float *)(param_1 + 0x90) - *(float *)(param_1 + 0xcc);` |
| `FUN_14001b280` | 1 | 26790 | `fVar21 = *(float *)(param_1 + 0x90) - *(float *)(param_1 + 0xcc);` |
| `FUN_14001b650` | 1 | 26932 | `fVar2 = *(float *)(param_1 + 0x90);` |
| `FUN_14001bb70` | 1 | 27398 | `lVar8 = *(longlong *)(param_1 + 0x90);` |
| `FUN_14001f210` | 1 | 31008 | `lVar17 = (longlong)*(int *)(lVar20 + 0x90);` |
| `FUN_1400293d0` | 1 | 44846 | `local_38 = *(undefined4 *)(param_1 + 0x90);` |
| `FUN_14004b750` | 1 | 86038 | `uVar13 = *(int *)(DAT_1403ea2a8 + 0x90) - 1;` |
| `FUN_14004b960` | 1 | 86312 | `if (iVar10 < *(int *)(param_1 + 0x90)) {` |
| `FUN_14004dc90` | 1 | 89482 | `if (iVar6 < *(int *)(param_3 + 0x90)) {` |
| `FUN_14004f010` | 1 | 90846 | `uVar5 = *(int *)(DAT_1403ea2a8 + 0x90) - 1;` |
| `FUN_1400509e0` | 1 | 93144 | `iVar1 = *(int *)(param_1 + 0x90);` |
| `FUN_140050a30` | 1 | 93194 | `if (iVar1 < *(int *)(param_1 + 0x90)) {` |
| `FUN_140080e40` | 1 | 150706 | `local_res8 = *(float *)(param_1 + 0x90);` |
| `FUN_140083c30` | 1 | 153988 | `local_2c = CONCAT44(*(float *)(param_2 + 0x90) * DAT_140303fe4,(undefined4)local_2c);` |
| `FUN_1400b6fd0` | 1 | 211730 | `uStack_88 = *(undefined4 *)(lVar3 + 0x90);` |
| `FUN_1400ba940` | 1 | 216866 | `((iVar16 = *(int *)(lVar34 + 0x8c), iVar16 != 0 \|\| (*(int *)(lVar34 + 0x90) != 0)))) {` |
| `FUN_1400bea50` | 1 | 220006 | `uVar5 = *(undefined8 *)(lVar10 + 0x90);` |
| `FUN_1400fb8c0` | 1 | 295338 | `if (*(int *)(param_1 + 0x90) != -1) {` |
| `FUN_1400fb9c0` | 1 | 295380 | `if (*(int *)(param_1 + 0x90) != -1) {` |
| `FUN_1401307d0` | 1 | 402062 | `FUN_140146010(*(undefined8 *)(param_1 + 0x90));` |
| `FUN_140131ef0` | 1 | 404246 | `if (*(longlong *)(param_1 + 0x90) != 0) {` |
| `FUN_140137fa0` | 1 | 413242 | `(**(code **)(param_1 + 0x90))(*(undefined8 *)(param_1 + 0x298));` |
| `FUN_1401394c0` | 1 | 416080 | `lVar1 = *(longlong *)(lVar2 + 0x90);` |
| `FUN_14013b770` | 1 | 419126 | `lVar1 = *(longlong *)(lVar2 + 0x90);` |
| `FUN_140150b10` | 1 | 450846 | `fVar1 = *(float *)(lVar3 + 0x90);` |
| `FUN_140156430` | 1 | 457470 | `uVar3 = (**(code **)(lVar1 + 0x90))(lVar1,param_1,&local_18,param_3,param_4);` |
| `FUN_140156de0` | 1 | 458088 | `fVar3 = *(float *)(param_2 + 0x90);` |
| `FUN_14015a190` | 1 | 463870 | `iVar2 = *(int *)(param_1 + 0x90);` |
| `FUN_1401612e0` | 1 | 475026 | `*param_1 = *(undefined4 *)(lVar1 + 0x90);` |
| `FUN_1401629c0` | 1 | 476960 | `local_94 = *(undefined4 *)(lVar2 + 0x90);` |
| `FUN_140162d10` | 1 | 477288 | `FUN_1401618c0(lVar4,*(undefined4 *)(lVar3 + 0x90),*(undefined4 *)(lVar3 + 0x94),1);` |
| `FUN_14016a4b0` | 1 | 487758 | `fVar1 = (float)(**(code **)(DAT_1403fc410 + 0x90))(DAT_1403fc410,param_1);` |
| `FUN_140183d70` | 1 | 528902 | `FUN_140163140((float)*(int *)(DAT_1403fc6e0 + 0x18) + *(float *)(lVar3 + 0x90),` |
| `FUN_1401a6b30` | 1 | 592290 | `FUN_1402f8e20(*(longlong *)(param_1 + 0xc0) + *(longlong *)(param_1 + 0x90),` |
| `FUN_1401bafe0` | 1 | 621608 | `in_RAX = *(ulonglong *)(param_3 + 0x90);` |
| `FUN_1401bc750` | 1 | 623562 | `if (*(longlong *)(param_2 + 0x90) != 0) {` |
| `FUN_1401bce00` | 1 | 624186 | `((in_RAX = (ulonglong)*(uint *)(param_3 + 0x90),` |
| `FUN_1401beac0` | 1 | 627284 | `if ((*(int *)(param_1 + 0x90) != 0) && (*(int *)(param_2 + 0x90) == 0)) {` |
| `FUN_1401bf8b0` | 1 | 628314 | `if (*(longlong *)(lVar4 + 0x90) != 0) {` |
| `FUN_1401cd410` | 1 | 646664 | `plVar1 = *(longlong **)(param_1 + 0x90);` |
| `FUN_1401de5a0` | 1 | 669068 | `plVar5 = *(longlong **)(lVar1 + 0x90);` |
| `FUN_1401e7cc0` | 1 | 681608 | `FUN_1401e7e30(param_1,*(undefined8 *)(lVar1 + 0x90));` |
| `FUN_1401e8fd0` | 1 | 683344 | `local_10 = *(undefined8 *)(param_1 + 0x90);` |
| `FUN_1401fe550` | 1 | 708904 | `lVar5 = *(longlong *)(lVar3 + 0x90);` |
| `FUN_140203060` | 1 | 715296 | `uVar2 = *(undefined8 *)(param_1 + 0x90);` |
| `FUN_1402045a0` | 1 | 717180 | `if (*(longlong *)(lVar3 + 0x90) != 0) {` |
| `FUN_1402057f0` | 1 | 718440 | `if (*(longlong *)(param_1 + 0x90) != 0) {` |
| `FUN_1402072d0` | 1 | 720712 | `lVar2 = FUN_140184230(*(undefined8 *)(param_1 + 0x90),(longlong)*(int *)(param_1 + 0x8c) * 4 + 4);` |
| `FUN_140207ae0` | 1 | 721470 | `*param_2 = *(undefined4 *)(*(longlong *)(lVar1 + 0x90) + (longlong)param_1 * 4);` |
| `FUN_140208110` | 1 | 722098 | `FUN_140208230(lVar2,*(undefined4 *)(*(longlong *)(lVar2 + 0x90) + lVar4 * 4));` |
| `FUN_140208230` | 1 | 722190 | `if (*(int *)(lVar5 + *(longlong *)(param_1 + 0x90)) == param_2) {` |
| `FUN_1402089a0` | 1 | 722938 | `lVar1 = FUN_1401581c0(*(undefined4 *)(*(longlong *)(param_1 + 0x90) + lVar3));` |
| `FUN_140208b70` | 1 | 723084 | `lVar1 = FUN_1401581c0(*(undefined4 *)(*(longlong *)(param_1 + 0x90) + lVar3));` |
| `FUN_14020bc00` | 1 | 727808 | `if (*(longlong *)(lVar2 + 0x90) != 0) {` |
| `FUN_1402104a0` | 1 | 734420 | `((*(int *)(lVar9 + 0x90) != 0 &&` |
| `FUN_140218580` | 1 | 746638 | `FUN_1401cda90(param_2,0x205,*(undefined4 *)(param_2 + 0x8c),*(undefined4 *)(param_2 + 0x90));` |
| `FUN_14022a9d0` | 1 | 773116 | `FUN_140170020(param_1,*(undefined4 *)(param_1 + 0x8c),*(undefined4 *)(param_1 + 0x90),param_5,` |
| `FUN_14022bad0` | 1 | 774634 | `FUN_140163140((float)*(int *)(DAT_1403fc6e0 + 0x18) + *(float *)(lVar4 + 0x90),` |
| `FUN_140268990` | 1 | 908852 | `if (*(char *)(lVar1 + 0x90) != '\0') {` |
| `FUN_140269ba0` | 1 | 911358 | `if (*(char *)(param_1 + 0x90) != '\0') {` |
| `FUN_14026eba0` | 1 | 916686 | `lVar2 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));` |
| `FUN_140273be0` | 1 | 922576 | `if (*(char *)(param_1 + 0x90) != '\0') {` |
| `FUN_140274270` | 1 | 923036 | `FUN_140208230(param_1,**(undefined4 **)(param_1 + 0x90));` |
| `FUN_140275eb0` | 1 | 925414 | `local_res8 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));` |
| `FUN_140276650` | 1 | 925910 | `uVar2 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));` |
| `FUN_14027e520` | 1 | 936860 | `FUN_140208230(param_1,**(undefined4 **)(param_1 + 0x90));` |
| `FUN_140281f20` | 1 | 941438 | `FUN_140208230(param_1,**(undefined4 **)(param_1 + 0x90));` |
| `FUN_14028b250` | 1 | 954484 | `iVar6 = ((int)((iVar5 - (uint)uVar1) * *(int *)(param_1 + 0x90)) >> 0x10) +` |
| `FUN_1402d74e0` | 1 | 1063860 | `*(undefined8 *)(param_1 + 0x18) = *(undefined8 *)(lVar1 + 0x90);` |
| `FUN_1402d8d60` | 1 | 1068160 | `*(undefined8 *)p_Var1 = *(undefined8 *)(lVar3 + 0x90);` |
| `FUN_1402e64c4` | 1 | 1091744 | `local_res8[0] = *(undefined8 **)(lVar1 + 0x90);` |
| `FUN_1402f4f90` | 1 | 1119466 | `if (*(undefined **)(param_1 + 0x90) != PTR_DAT_1403e8d10) {` |
| `FUN_1402f5198` | 1 | 1120156 | `(lVar2 = *(longlong *)(lVar1 + 0x90), lVar2 == 0)) {` |
| `FUN_1402f5850` | 1 | 1120526 | `local_20 = *(undefined **)(local_28 + 0x90);` |
| `FUN_1402f9e00` | 1 | 1129974 | `plVar1 = *(longlong **)(param_2 + 0x90);` |
| `FUN_1402fa790` | 1 | 1130114 | `FUN_1402c7088(*(undefined8 *)(param_2 + 0x90),0x30);` |
| `FUN_1402ffab9` | 1 | 1132950 | `*(undefined8 *)(param_2 + 0x80),lVar2,*(undefined8 *)(param_2 + 0x90),0,0,1);` |
| `FUN_1402ffb60` | 1 | 1133010 | `*(undefined8 *)(param_2 + 0x80),lVar2,*(undefined8 *)(param_2 + 0x90),0,0,1);` |

## `+0x94` (148 dec)

63 functions, 103 read sites.

| Function | Hits | First line | First snippet |
|---|---|---|---|
| `FUN_140008560` | 4 | 5372 | `fVar1 = *(float *)(lVar9 + 0x94);` |
| `FUN_14001bb70` | 4 | 27412 | `fVar34 = *(float *)(lVar6 + 0x94);` |
| `FUN_14001e5e0` | 4 | 30142 | `*(undefined4 *)(lVar17 + 0x78) = *(undefined4 *)(lVar15 + 0x94);` |
| `FUN_14000a0a0` | 3 | 6974 | `fVar17 = *(float *)(lVar6 + 0x94);` |
| `FUN_1400145b0` | 3 | 18884 | `*(undefined4 *)(param_1 + 0xe4) = *(undefined4 *)(lVar6 + 0x94);` |
| `FUN_140018650` | 3 | 24332 | `fVar1 = *(float *)(lVar8 + 0x94);` |
| `FUN_140018b00` | 3 | 24622 | `fVar2 = *(float *)(param_1 + 0x94);` |
| `FUN_140018e70` | 3 | 24796 | `fVar18 = *(float *)(lVar6 + 0x94);` |
| `FUN_140019e50` | 3 | 25650 | `fVar1 = *(float *)(lVar8 + 0x94);` |
| `FUN_14001aaa0` | 3 | 26324 | `*(undefined4 *)(param_1 + 0xd8) = *(undefined4 *)(lVar6 + 0x94);` |
| `FUN_140021550` | 3 | 32932 | `fVar24 = (*(float *)(param_1 + 0x94) - *(float *)(param_1 + 0xa4)) * fVar30 +` |
| `FUN_14004d8d0` | 3 | 89112 | `if (iVar6 <= *(int *)(param_1 + 0x94)) {` |
| `FUN_14015cef0` | 3 | 468168 | `FUN_14015d2e0(*(undefined1 *)(param_1 + 0x94));` |
| `FUN_140009380` | 2 | 6136 | `fVar41 = *(float *)(param_1 + 0x90) * fVar20 - *(float *)(param_1 + 0x94) * fVar19;` |
| `FUN_140009ca0` | 2 | 6574 | `(*(float *)(param_1 + 0x94) * fVar1 + *(float *)(param_1 + 0x90) * fVar2) +` |
| `FUN_14000b4a0` | 2 | 8228 | `*(undefined4 *)(param_1 + 0xcc) = *(undefined4 *)(lVar6 + 0x94);` |
| `FUN_14001d410` | 2 | 28586 | `fVar13 = *(float *)(lVar5 + 0x94);` |
| `FUN_14004b960` | 2 | 86268 | `local_60 = *(int *)(param_1 + 0x94);` |
| `FUN_14004dc90` | 2 | 89456 | `local_dc = *(int *)(param_3 + 0x94);` |
| `FUN_1400ba940` | 2 | 217054 | `(local_138[(longlong)iVar16 * 5 + (longlong)*(int *)(lVar34 + 0x94)] == '\0')) {` |
| `FUN_1400fbae0` | 2 | 295872 | `iVar8 = *(int *)(param_1 + 0x94);` |
| `FUN_140161be0` | 2 | 475934 | `*(float *)(lVar2 + 0x94) / (float)*(int *)(param_2 + 0x24),` |
| `FUN_140161f10` | 2 | 476324 | `fVar8 = *(float *)(lVar6 + 0x94);` |
| `FUN_14018c820` | 2 | 542672 | `FUN_140228460(((int)*(undefined8 *)(lVar3 + 0x94) - iVar8) / 2 + DAT_1403fcbb8 + iVar8,` |
| `FUN_140009f00` | 1 | 6798 | `fVar2 = *(float *)(param_1 + 0x94) * DAT_14039ca80;` |
| `FUN_14000b240` | 1 | 7840 | `fVar1 = *(float *)(param_1 + 0x94);` |
| `FUN_14000b9a0` | 1 | 8498 | `fVar18 = *(float *)(param_1 + 0x94) - *(float *)(param_1 + 0x90);` |
| `FUN_140014e30` | 1 | 19382 | `fVar21 = *(float *)(param_1 + 0x94) - *(float *)(param_1 + 0xd8);` |
| `FUN_1400152f0` | 1 | 19562 | `fVar2 = *(float *)(param_1 + 0x94);` |
| `FUN_140019960` | 1 | 25332 | `fVar19 = *(float *)(param_1 + 0x94) - *(float *)(param_1 + 0xd4);` |
| `FUN_140019d50` | 1 | 25478 | `fVar2 = *(float *)(param_1 + 0x94);` |
| `FUN_14001aa70` | 1 | 26222 | `*param_2 = param_3 * *(float *)(param_1 + 0x94);` |
| `FUN_14001b280` | 1 | 26794 | `fVar17 = *(float *)(param_1 + 0x94) - *(float *)(param_1 + 0xd0);` |
| `FUN_14001b6b0` | 1 | 26976 | `fVar1 = *(float *)(param_1 + 0x94);` |
| `FUN_1400509e0` | 1 | 93148 | `if (iVar4 <= *(int *)(param_1 + 0x94)) {` |
| `FUN_140050a30` | 1 | 93192 | `iVar1 = *(int *)(param_1 + 0x94) - uVar3;` |
| `FUN_140080e40` | 1 | 150722 | `((float)*(int *)(param_1 + 0x94) <= (float)iVar6)) &&` |
| `FUN_140081600` | 1 | 151002 | `fVar3 = (float)*(int *)(param_1 + 0x94);` |
| `FUN_1400b6fd0` | 1 | 211732 | `uStack_84 = *(undefined4 *)(lVar3 + 0x94);` |
| `FUN_140142010` | 1 | 429836 | `if ((*(int *)(lVar4 + 0x94) != 0) \|\|` |
| `FUN_140150b10` | 1 | 450848 | `fVar2 = *(float *)(lVar3 + 0x94);` |
| `FUN_140156de0` | 1 | 458090 | `fVar1 = *(float *)(param_2 + 0x94);` |
| `FUN_14015de70` | 1 | 469706 | `cVar4 = *(char *)(param_1 + 0x94);` |
| `FUN_14015e5c0` | 1 | 470394 | `if (*(char *)(param_1 + 0x94) != '\0') {` |
| `FUN_14015ec40` | 1 | 471020 | `cVar1 = *(char *)(local_48 + 0x94);` |
| `FUN_14015eda0` | 1 | 471206 | `iVar4 = FUN_14015c250(*(undefined1 *)(lVar5 + 0x94),1);` |
| `FUN_14015fe40` | 1 | 472600 | `if (*(char *)(param_1 + 0x94) != '\0') {` |
| `FUN_14015fec0` | 1 | 472672 | `cVar2 = *(char *)(param_1 + 0x94);` |
| `FUN_1401612e0` | 1 | 475032 | `*param_2 = *(undefined4 *)(lVar1 + 0x94);` |
| `FUN_1401629c0` | 1 | 476962 | `local_90 = *(undefined4 *)(lVar2 + 0x94);` |
| `FUN_140162d10` | 1 | 477288 | `FUN_1401618c0(lVar4,*(undefined4 *)(lVar3 + 0x90),*(undefined4 *)(lVar3 + 0x94),1);` |
| `FUN_140183d70` | 1 | 528904 | `(float)*(int *)(DAT_1403fc6e0 + 0x1c) + *(float *)(lVar3 + 0x94));` |
| `FUN_1401bce00` | 1 | 624190 | `(in_RAX = (ulonglong)*(uint *)(param_3 + 0x94),` |
| `FUN_1401beac0` | 1 | 627296 | `if ((*(int *)(param_1 + 0x94) != 0) && (*(int *)(param_2 + 0x94) == 0)) {` |
| `FUN_140215530` | 1 | 742088 | `thunk_FUN_140180060(3 - (uint)(*(char *)(param_1 + 0x94) != '\0'));` |
| `FUN_140215700` | 1 | 742274 | `cVar1 = FUN_140289bb0(param_1,&local_res8,*(undefined1 *)(param_1 + 0x94));` |
| `FUN_140215880` | 1 | 742570 | `if ((*(char *)(param_1 + 0x94) != '\0') &&` |
| `FUN_140216e70` | 1 | 744394 | `cVar1 = *(char *)(param_1 + 0x94);` |
| `FUN_14022a9d0` | 1 | 773122 | `*param_7 = *(int *)(param_1 + 0x94);` |
| `FUN_14022bad0` | 1 | 774636 | `(float)*(int *)(DAT_1403fc6e0 + 0x1c) + *(float *)(lVar4 + 0x94));` |
| `FUN_140268990` | 1 | 908878 | `if (*(uint *)(lVar1 + 0x94) < CONCAT22(param_3,param_4)) {` |
| `FUN_140269ba0` | 1 | 911360 | `uVar1 = *(uint *)(param_1 + 0x94);` |
| `FUN_140277670` | 1 | 927778 | `if (uVar4 != *(uint *)(param_1 + 0x94)) {` |

## `+0x98` (152 dec)

129 functions, 207 read sites.

| Function | Hits | First line | First snippet |
|---|---|---|---|
| `FUN_14004f210` | 13 | 91298 | `if ((((*(int *)(param_1 + 0x98) != 0) \|\| (cVar10 != 'O')) \|\|` |
| `FUN_14003c8c0` | 8 | 66590 | `uVar12 = FUN_1400833d0(*(undefined8 *)(param_1 + 0x98),(ulonglong)DAT_140304c68 << 0x20,1);` |
| `FUN_140021550` | 6 | 32934 | `(*(float *)(param_1 + 0x98) - *(float *)(param_1 + 0xa8)) *` |
| `FUN_140042130` | 5 | 73426 | `iVar6 = *(int *)(param_1 + 0x98);` |
| `FUN_140054a60` | 5 | 99748 | `iVar15 = *(int *)(param_1 + 0x98);` |
| `FUN_14000f610` | 3 | 12776 | `uVar7 = *(uint *)(param_1 + 0x98);` |
| `FUN_140022a90` | 3 | 34240 | `if (0 < (longlong)*(int *)(param_2 + 0x98)) {` |
| `FUN_140068bb0` | 3 | 121662 | `FUN_1400b3dc0(lVar1,*(undefined8 *)(param_1 + 0x98));` |
| `FUN_140084670` | 3 | 154874 | `if (*(int *)(lVar3 + 0x98) != 2) {` |
| `FUN_14008ffc0` | 3 | 170308 | `FUN_1400b3dc0(*(undefined8 *)(*plVar36 + lVar31),*(undefined8 *)(param_1 + 0x98));` |
| `FUN_1400ce540` | 3 | 238610 | `lVar5 = *(longlong *)(param_1 + 0x98);` |
| `FUN_1401cc420` | 3 | 645472 | `if (*(char *)(param_1 + 0x98) != '\0') {` |
| `FUN_1401ef800` | 3 | 690856 | `pcVar8 = *(code **)(param_1 + 0x98);` |
| `FUN_140008560` | 2 | 5472 | `fVar22 = fVar13 * *(float *)(param_1 + 0x98) - fVar12 * *(float *)(param_1 + 0x9c);` |
| `FUN_140009380` | 2 | 6144 | `fVar33 = *(float *)(param_1 + 0x98) * fVar20 - *(float *)(param_1 + 0x9c) * fVar19;` |
| `FUN_14000a690` | 2 | 7426 | `fVar25 = *(float *)(param_1 + 0x98);` |
| `FUN_14000d4e0` | 2 | 10504 | `if (0 < *(int *)(param_1 + 0x98)) {` |
| `FUN_14000dec0` | 2 | 11170 | `param_3 = *(int *)(param_1 + 0x98);` |
| `FUN_14000e0e0` | 2 | 11336 | `param_3 = *(int *)(param_1 + 0x98);` |
| `FUN_14000e340` | 2 | 11506 | `if (0 < (longlong)*(int *)(param_1 + 0x98)) {` |
| `FUN_14000e3e0` | 2 | 11590 | `if (*(int *)(param_1 + 0x98) < 1) {` |
| `FUN_14000e620` | 2 | 11748 | `if (1 < *(int *)(param_1 + 0x98)) {` |
| `FUN_140018e70` | 2 | 24908 | `fVar19 = *(float *)(param_1 + 0x98) * fVar11 - *(float *)(param_1 + 0x9c) * fVar10;` |
| `FUN_14001d410` | 2 | 28698 | `((fVar10 + fVar1) - *(float *)(param_1 + 0x88)) * *(float *)(param_1 + 0x98);` |
| `FUN_140022e50` | 2 | 34466 | `lVar8 = (longlong)*(int *)(param_4 + 0x98);` |
| `FUN_1400234e0` | 2 | 34960 | `iVar4 = *(int *)(param_5 + 0x98);` |
| `FUN_140026b90` | 2 | 40716 | `if (*(longlong *)(param_1 + 0x98) != 0) {` |
| `FUN_140042f50` | 2 | 74808 | `iVar1 = *(int *)(param_1 + 0x98);` |
| `FUN_1400a6e10` | 2 | 195186 | `uVar6 = FUN_140005e10(*(undefined8 *)(param_1 + 0x98),&local_68);` |
| `FUN_1400c0660` | 2 | 223438 | `*(undefined8 *)(*(longlong *)(param_1 + 0x98) + 0x19338) = DAT_1403ffbe8;` |
| `FUN_1400f5280` | 2 | 288594 | `uVar10 = FUN_1400833d0(*(undefined8 *)(param_1 + 0x98),` |
| `FUN_14013dc20` | 2 | 422774 | `piVar2 = *(int **)(lVar1 + 0x98);` |
| `FUN_1401565b0` | 2 | 457620 | `if (*(longlong *)(lVar1 + 0x98) != 0) {` |
| `FUN_14015a600` | 2 | 464292 | `if (*(int *)(lVar1 + *(longlong *)(param_1 + 0x98)) == param_2) {` |
| `FUN_1401bafe0` | 2 | 621612 | `(in_RAX = (ulonglong)*(uint *)(param_3 + 0x98),` |
| `FUN_1401c3bd0` | 2 | 633666 | `if (*(char *)(param_1 + 0x98) != '\0') {` |
| `FUN_1401c5ac0` | 2 | 636408 | `cVar1 = *(char *)(param_1 + 0x98);` |
| `FUN_1401c79e0` | 2 | 639070 | `if (*(char *)(param_1 + 0x98) != '\0') {` |
| `FUN_1401c7fa0` | 2 | 639698 | `if (*(char *)(param_1 + 0x98) != '\0') {` |
| `FUN_1401cb240` | 2 | 643724 | `if (*(char *)(param_1 + 0x98) != '\0') {` |
| `FUN_1401f4bb0` | 2 | 696954 | `pcVar12 = *(code **)(param_1 + 0x98);` |
| `FUN_14020bee0` | 2 | 728024 | `if (*(code **)(lVar1 + 0x98) != (code *)0x0) {` |
| `FUN_1402ccc10` | 2 | 1043470 | `if ((*(ulonglong *)(param_1 + 0x98) < *(ulonglong *)((longlong)Self + 0x10)) \|\|` |
| `FUN_14000a0a0` | 1 | 7148 | `fVar18 = fVar18 * *(float *)(param_1 + 0x98);` |
| `FUN_14000b260` | 1 | 7862 | `return param_2 * *(float *)(param_1 + 0x98);` |
| `FUN_14000b4a0` | 1 | 8380 | `fVar19 = *(float *)(param_2 + 8) * *(float *)(param_1 + 0x98);` |
| `FUN_14000b9a0` | 1 | 8530 | `fVar18 = *(float *)(param_1 + 0x98);` |
| `FUN_14000bf90` | 1 | 8796 | `param_3 = param_3 * *(float *)(param_1 + 0x98);` |
| `FUN_14000d3c0` | 1 | 10416 | `*(undefined4 *)(puVar1 + 0x13) = *(undefined4 *)(param_1 + 0x98);` |
| `FUN_1400145b0` | 1 | 18940 | `fVar9 = *(float *)(param_1 + 0x98) - *(float *)(param_1 + 0xdc);` |
| `FUN_140014e30` | 1 | 19388 | `fVar22 = *(float *)(param_1 + 0x98) - *(float *)(param_1 + 0xdc);` |
| `FUN_140015350` | 1 | 19606 | `fVar1 = *(float *)(param_1 + 0x98);` |
| `FUN_140016340` | 1 | 21468 | `*(undefined4 *)(param_1 + 3) = *(undefined4 *)(param_2 + 0x98);` |
| `FUN_140018650` | 1 | 24454 | `fVar13 = *(float *)(param_1 + 0x98) * *(float *)(param_2 + 8);` |
| `FUN_140018b00` | 1 | 24558 | `fVar2 = *(float *)(param_1 + 0x98);` |
| `FUN_140019e50` | 1 | 25754 | `fVar14 = fVar12 * *(float *)(param_1 + 0x98);` |
| `FUN_14001aa70` | 1 | 26220 | `fVar1 = *(float *)(param_1 + 0x98);` |
| `FUN_14001aaa0` | 1 | 26382 | `fVar18 = *(float *)(param_1 + 0x98) - *(float *)(param_1 + 0xd4);` |
| `FUN_14001b280` | 1 | 26788 | `fVar22 = *(float *)(param_1 + 0x98) - *(float *)(param_1 + 0xd4);` |
| `FUN_14001b6b0` | 1 | 26978 | `fVar2 = *(float *)(param_1 + 0x98);` |
| `FUN_14001bb70` | 1 | 27506 | `fVar26 = *(float *)(param_1 + 0x98) - *(float *)(param_1 + 0xec);` |
| `FUN_14001c850` | 1 | 28088 | `fVar27 = *(float *)(param_1 + 0x98) - *(float *)(param_1 + 0xec);` |
| `FUN_14001d130` | 1 | 28298 | `fVar1 = *(float *)(param_1 + 0x98);` |
| `FUN_140023180` | 1 | 34682 | `iVar1 = *(int *)(param_2 + 0x98);` |
| `FUN_1400237d0` | 1 | 35354 | `if (*(int *)(lVar6 + 0x98) <= iVar9) {` |
| `FUN_140027000` | 1 | 40986 | `FUN_140027f50(param_2 + 0x88,plVar2,*(undefined8 *)(param_1 + 0x98));` |
| `FUN_14002d170` | 1 | 50348 | `FUN_1400b3dc0(lVar6,*(undefined8 *)(param_1 + 0x98));` |
| `FUN_140041280` | 1 | 72222 | `if (*(int *)(param_1 + 0x98) != 0) break;` |
| `FUN_140042b70` | 1 | 74492 | `if (*(int *)(param_1 + 0x98) != 0) break;` |
| `FUN_140043aa0` | 1 | 75424 | `puVar4 = *(undefined8 **)(DAT_1403ea2a8 + 0x98);` |
| `FUN_14004edb0` | 1 | 90622 | `if (*(int *)(param_1 + 0x98) != 0) {` |
| `FUN_14004ef90` | 1 | 90808 | `*puVar2 = *(undefined8 *)(DAT_1403ea2a8 + 0x98);` |
| `FUN_140055360` | 1 | 100606 | `if (*(int *)(param_1 + 0x98) != 0) {` |
| `FUN_140068120` | 1 | 121050 | `uVar5 = FUN_1400833d0(*(undefined8 *)(param_1 + 0x98),DAT_1403d9178,0);` |
| `FUN_14006ac30` | 1 | 123734 | `FUN_140006230(*(undefined8 *)(param_1 + 0x98));` |
| `FUN_14006ae90` | 1 | 123902 | `FUN_140006230(*(undefined8 *)(param_1 + 0x98));` |
| `FUN_140082640` | 1 | 152638 | `if (*(int *)(param_1 + 0x78) != *(int *)(param_1 + 0x98)) goto LAB_14008312f;` |
| `FUN_140094a20` | 1 | 174296 | `if (*(longlong *)(param_1 + 0x98) != 0) {` |
| `FUN_140097dd0` | 1 | 177646 | `FUN_1400b3dc0(lVar3,*(undefined8 *)(param_1 + 0x98));` |
| `FUN_1400b6fd0` | 1 | 211734 | `local_80 = *(undefined4 *)(lVar3 + 0x98);` |
| `FUN_1400bcb00` | 1 | 217910 | `if (0 < *(int *)(lVar15 + 0x98)) {` |
| `FUN_1400bea50` | 1 | 220012 | `puVar8[0x23] = *(undefined4 *)(lVar10 + 0x98);` |
| `FUN_1400ce9b0` | 1 | 238856 | `lVar1 = *(longlong *)(param_1 + 0x98);` |
| `FUN_1400cead0` | 1 | 238892 | `FUN_1400b3dc0(param_2,*(undefined8 *)(param_1 + 0x98));` |
| `FUN_1400fa800` | 1 | 294252 | `lVar3 = *(longlong *)(param_1 + 0x98);` |
| `FUN_1400fbae0` | 1 | 295624 | `if (*(int *)(param_1 + 0x98) < 1) {` |
| `FUN_1401307d0` | 1 | 402066 | `FUN_140146010(*(undefined8 *)(param_1 + 0x98));` |
| `FUN_140131ef0` | 1 | 404254 | `if (*(longlong *)(param_1 + 0x98) != 0) {` |
| `FUN_14013dbb0` | 1 | 422710 | `piVar2 = *(int **)(lVar1 + 0x98);` |
| `FUN_14013ed10` | 1 | 424776 | `piVar2 = *(int **)(lVar1 + 0x98);` |
| `FUN_14013ed80` | 1 | 424832 | `piVar4 = *(int **)(lVar1 + 0x98);` |
| `FUN_140142010` | 1 | 429820 | `piVar6 = *(int **)(lVar4 + 0x98);` |
| `FUN_1401575b0` | 1 | 458866 | `FUN_1401841e0(*(undefined8 *)(param_1 + 0x98));` |
| `FUN_14015a190` | 1 | 463874 | `lVar4 = FUN_140184230(*(undefined8 *)(param_1 + 0x98),lVar3 * 0x18 + 0x18);` |
| `FUN_14015d7a0` | 1 | 468984 | `if ((*(longlong *)(param_1 + 0x98) != 0) && (iVar1 < *(int *)(param_1 + 0xb0))) {` |
| `FUN_140161330` | 1 | 475062 | `*param_1 = *(undefined4 *)(lVar1 + 0x98);` |
| `FUN_14016ebe0` | 1 | 494916 | `(**(code **)(DAT_1403fc410 + 0x98))(DAT_1403fc410,param_1,puVar5,puVar4);` |
| `FUN_140197e70` | 1 | 565522 | `lVar5 = *(longlong *)(lVar1 + 0x98);` |
| `FUN_140198020` | 1 | 565650 | `lVar1 = *(longlong *)(param_2 + 0x98);` |
| `FUN_140198310` | 1 | 565878 | `lVar1 = *(longlong *)(param_1 + 0x98);` |
| `FUN_1401a6b30` | 1 | 592274 | `if (*(longlong **)(param_1 + 0x98) != (longlong *)0x0) {` |
| `FUN_1401bc750` | 1 | 623570 | `if (*(longlong *)(param_2 + 0x98) != 0) {` |
| `FUN_1401bce00` | 1 | 624196 | `CONCAT31((int3)((uint)*(int *)(param_3 + 0x98) >> 8),` |
| `FUN_1401beac0` | 1 | 627308 | `if ((*(int *)(param_1 + 0x98) != 0) && (*(int *)(param_2 + 0x98) == 0)) {` |
| `FUN_1401bf8b0` | 1 | 628320 | `if (*(longlong *)(lVar4 + 0x98) != 0) {` |
| `FUN_1401c37e0` | 1 | 633428 | `if (*(char *)(param_1 + 0x98) != '\0') {` |
| `FUN_1401c3db0` | 1 | 633870 | `if (*(char *)(param_1 + 0x98) != '\0') {` |
| `FUN_1401c54a0` | 1 | 635888 | `if (*(char *)(param_1 + 0x98) != '\0') {` |
| `FUN_1401c5730` | 1 | 636150 | `if (*(char *)(lVar1 + 0x98) != '\0') {` |
| `FUN_1401c85b0` | 1 | 639806 | `if (*(char *)(param_1 + 0x98) != '\0') {` |
| `FUN_1401c92f0` | 1 | 640914 | `if ((*(char *)(param_1 + 0x98) != '\0') && (*(longlong *)(param_2 + 0x18) != 0)) {` |
| `FUN_1401cb3d0` | 1 | 643836 | `if ((*(char *)(param_1 + 0x98) != '\0') && (param_3 != (char *)0x0)) {` |
| `FUN_1401cc320` | 1 | 645348 | `if ((*(char *)(param_1 + 0x98) != '\0') && (param_3 != 0)) {` |
| `FUN_1401cc570` | 1 | 645570 | `if ((*(char *)(param_1 + 0x98) != '\0') && (param_3 != 0)) {` |
| `FUN_1401ccc40` | 1 | 646112 | `if (*(char *)(param_1 + 0x98) != '\0') {` |
| `FUN_1401cd5b0` | 1 | 646880 | `if (*(char *)(param_1 + 0x98) != '\0') {` |
| `FUN_1401cd770` | 1 | 646996 | `if (*(char *)(param_1 + 0x98) != '\0') {` |
| `FUN_1401e7cc0` | 1 | 681612 | `if (*(char *)(lVar1 + 0x98) != '\0') {` |
| `FUN_1401e9660` | 1 | 683878 | `if (*(char *)(lVar3 + 0x98) != '\0') {` |
| `FUN_1401ea3b0` | 1 | 685094 | `if (*(char *)(lVar1 + 0x98) != '\0') {` |
| `FUN_1401ec080` | 1 | 687582 | `(**(code **)(lVar3 + 0x98))(uVar2);` |
| `FUN_1401ee270` | 1 | 689544 | `(**(code **)(lVar2 + 0x98))(0xc11);` |
| `FUN_140203060` | 1 | 715390 | `local_e4 = *(undefined4 *)(*(longlong *)(*(longlong *)(param_1 + 0x98) + 0x138) + 0x10);` |
| `FUN_140204280` | 1 | 716898 | `puVar4 = *(uint **)(lVar3 + 0x98);` |
| `FUN_14022a9d0` | 1 | 773124 | `uVar8 = (ulonglong)*(uint *)(param_1 + 0x98);` |
| `FUN_140268c40` | 1 | 909080 | `if ((*(char *)(lVar1 + 0x98) != '\0') && ((param_3 == '\0' \|\| (*(char *)(lVar1 + 0x34) != '\0'))))` |
| `FUN_1402fbd1c` | 1 | 1130278 | `FUN_1402c7088(*(undefined8 *)(param_2 + 0x98),0x498);` |
| `FUN_1402fcadc` | 1 | 1130602 | `FUN_1402c7088(*(undefined8 *)(param_2 + 0x98),0x498);` |
| `FUN_1402fffa4` | 1 | 1133534 | `__acrt_unlock(**(undefined4 **)(param_2 + 0x98));` |

## `+0x9c` (156 dec)

35 functions, 70 read sites.

| Function | Hits | First line | First snippet |
|---|---|---|---|
| `FUN_14001bb70` | 5 | 27424 | `fVar36 = *(float *)(lVar6 + 0x9c);` |
| `FUN_140008560` | 4 | 5380 | `fVar3 = *(float *)(lVar9 + 0x9c);` |
| `FUN_14000b4a0` | 4 | 8232 | `*(undefined4 *)(param_1 + 0xd4) = *(undefined4 *)(lVar6 + 0x9c);` |
| `FUN_140018e70` | 4 | 24804 | `fVar1 = *(float *)(lVar6 + 0x9c);` |
| `FUN_14001e5e0` | 4 | 30146 | `*(undefined4 *)(lVar17 + 0x80) = *(undefined4 *)(lVar15 + 0x9c);` |
| `FUN_1400ba940` | 4 | 216954 | `uVar32 = *(uint *)(lVar34 + 0x9c);` |
| `FUN_14000a0a0` | 3 | 6982 | `fVar2 = *(float *)(lVar6 + 0x9c);` |
| `FUN_1400145b0` | 3 | 18888 | `*(undefined4 *)(param_1 + 0xec) = *(undefined4 *)(lVar6 + 0x9c);` |
| `FUN_140019e50` | 3 | 25658 | `fVar3 = *(float *)(lVar8 + 0x9c);` |
| `FUN_140009380` | 2 | 6144 | `fVar33 = *(float *)(param_1 + 0x98) * fVar20 - *(float *)(param_1 + 0x9c) * fVar19;` |
| `FUN_14000b9a0` | 2 | 8500 | `lVar15 = (longlong)*(int *)(param_1 + 0x9c);` |
| `FUN_14000bc20` | 2 | 8648 | `lVar11 = (longlong)*(int *)(param_1 + 0x9c);` |
| `FUN_140018650` | 2 | 24340 | `fVar3 = *(float *)(lVar8 + 0x9c);` |
| `FUN_14001aaa0` | 2 | 26328 | `*(undefined4 *)(param_1 + 0xe0) = *(undefined4 *)(lVar6 + 0x9c);` |
| `FUN_14001d410` | 2 | 28590 | `fVar14 = *(float *)(lVar5 + 0x9c);` |
| `FUN_14001d7e0` | 2 | 28784 | `fVar9 = *(float *)(param_1 + 0x9c);` |
| `FUN_140021550` | 2 | 32940 | `fVar33 = *(float *)(param_1 + 0xa4) - *(float *)(param_1 + 0x9c);` |
| `FUN_140082640` | 2 | 152692 | `iVar6 = FUN_1400c5c20(*(undefined4 *)(param_1 + 0x9c),*(undefined4 *)(lVar4 + 0x44))` |
| `FUN_1401bafe0` | 2 | 621618 | `CONCAT31((int3)((uint)*(int *)(param_3 + 0x9c) >> 8),` |
| `FUN_14000a690` | 1 | 7316 | `fVar22 = *(float *)(param_1 + 0x9c);` |
| `FUN_140014e30` | 1 | 19386 | `fVar19 = *(float *)(param_1 + 0x9c) - *(float *)(param_1 + 0xe0);` |
| `FUN_140015350` | 1 | 19608 | `fVar2 = *(float *)(param_1 + 0x9c);` |
| `FUN_140018b00` | 1 | 24630 | `fVar20 = fVar20 * *(float *)(param_1 + 0x9c);` |
| `FUN_14001aa90` | 1 | 26242 | `return param_2 * *(float *)(param_1 + 0x9c);` |
| `FUN_14001b040` | 1 | 26646 | `*(float *)(param_1 + 0x88) + *(float *)(param_1 + 0xa0) * *(float *)(param_1 + 0x9c)) *` |
| `FUN_14001c850` | 1 | 28094 | `fVar30 = *(float *)(param_1 + 0x9c) - *(float *)(param_1 + 0xf0);` |
| `FUN_14001d130` | 1 | 28300 | `fVar2 = *(float *)(param_1 + 0x9c);` |
| `FUN_14001da90` | 1 | 28948 | `*param_2 = param_3 * *(float *)(param_1 + 0x9c);` |
| `FUN_140041280` | 1 | 72260 | `if ((*(int *)(param_1 + 0x9c) != 0x20) \|\| (*(int *)(param_1 + 0x4f8) != 0)) {` |
| `FUN_1400fc520` | 1 | 296642 | `if (*(char *)(param_1 + 0x9c) != '\0') {` |
| `FUN_140161330` | 1 | 475068 | `*param_2 = *(undefined4 *)(lVar1 + 0x9c);` |
| `FUN_1401bce00` | 1 | 624122 | `(in_RAX = (ulonglong)*(uint *)(param_3 + 0x9c),` |
| `FUN_1401beac0` | 1 | 627320 | `if ((*(int *)(param_1 + 0x9c) != 0) && (*(int *)(param_2 + 0x9c) == 0)) {` |
| `FUN_1402246a0` | 1 | 764642 | `iVar3 = *(int *)(lVar6 + 0x9c);` |
| `FUN_14022c8c0` | 1 | 776250 | `local_78.left = *(int *)(lVar2 + 0x9c) + iVar8;` |

## `+0xa0` (160 dec)

84 functions, 118 read sites.

| Function | Hits | First line | First snippet |
|---|---|---|---|
| `FUN_140204140` | 4 | 716742 | `uVar4 = *(undefined8 *)(lVar1 + 0xa0);` |
| `FUN_14000b9a0` | 3 | 8502 | `lVar16 = (longlong)*(int *)(param_1 + 0xa0);` |
| `FUN_14000bc20` | 3 | 8650 | `lVar12 = (longlong)*(int *)(param_1 + 0xa0);` |
| `FUN_14001a2e0` | 3 | 25886 | `lVar17 = (longlong)*(int *)(param_1 + 0xa0);` |
| `FUN_14004f0a0` | 3 | 90894 | `param_1[6] = *(undefined8 *)(DAT_1403ea2a8 + 0xa0);` |
| `FUN_1401ee270` | 3 | 689704 | `(**(code **)(lVar2 + 0xa0))(0x8074);` |
| `FUN_1401ef800` | 3 | 691000 | `pcVar8 = *(code **)(param_1 + 0xa0);` |
| `FUN_14000b4a0` | 2 | 8422 | `iVar4 = *(int *)(param_1 + 0xa0);` |
| `FUN_140018e70` | 2 | 24862 | `fVar23 = *(float *)(param_1 + 0xa0) * fVar11 - *(float *)(param_1 + 0xa4) * fVar10;` |
| `FUN_140019960` | 2 | 25344 | `fVar26 = *(float *)(param_1 + 0xa0) * fVar13 - *(float *)(param_1 + 0xa4) * fVar12;` |
| `FUN_140019e50` | 2 | 25784 | `iVar7 = *(int *)(param_1 + 0xa0);` |
| `FUN_14001a5b0` | 2 | 26046 | `lVar14 = (longlong)*(int *)(param_1 + 0xa0);` |
| `FUN_14001b740` | 2 | 27150 | `*(undefined4 *)(param_1 + 0x19) = *(undefined4 *)(lVar3 + 0xa0);` |
| `FUN_14001d7e0` | 2 | 28786 | `fVar1 = *(float *)(param_1 + 0xa0);` |
| `FUN_140021550` | 2 | 32942 | `fVar35 = *(float *)(param_1 + 0xa8) - *(float *)(param_1 + 0xa0);` |
| `FUN_140026b90` | 2 | 40722 | `if (0xf < *(ulonglong *)(param_1 + 0xa0)) {` |
| `FUN_1400fc520` | 2 | 296418 | `iVar8 = *(int *)(param_1 + 0xa0);` |
| `FUN_140155780` | 2 | 456506 | `if (*(longlong *)(lVar2 + 0xa0) != 0) {` |
| `FUN_140160390` | 2 | 473272 | `if ((float)iVar8 <= *(float *)(param_1 + 0xa0)) {` |
| `FUN_140161f10` | 2 | 476204 | `fVar9 = param_5 - *(float *)(lVar6 + 0xa0);` |
| `FUN_140171820` | 2 | 499334 | `if (*(code **)(DAT_1403fc410 + 0xa0) != (code *)0x0) {` |
| `FUN_140181590` | 2 | 525236 | `if ((*(longlong *)(lVar1 + 200) != 0) && (*(code **)(lVar1 + 0xa0) != (code *)0x0)) {` |
| `FUN_1401a6b30` | 2 | 592280 | `if (*(longlong **)(param_1 + 0xa0) != (longlong *)0x0) {` |
| `FUN_140203060` | 2 | 715500 | `FUN_140137ce0(*(undefined8 *)(param_1 + 0xa0),0,puVar8,uVar9);` |
| `FUN_140204280` | 2 | 716994 | `uVar10 = FUN_140132c70(*(undefined8 *)(lVar3 + 0xa0));` |
| `FUN_1402087d0` | 2 | 722844 | `lVar5 = *(longlong *)(lVar5 + 0xa0);` |
| `FUN_140009380` | 1 | 6148 | `fVar29 = (fVar6 - fVar1) - *(float *)(param_1 + 0xa0);` |
| `FUN_14000a690` | 1 | 7314 | `if (((*(char *)(param_1 + 0xa0) != '\0') && (*(int *)(param_1 + 0x11c) != 3)) && (bVar18)) {` |
| `FUN_14000b290` | 1 | 7896 | `return *(undefined1 *)(param_1 + 0xa0);` |
| `FUN_140014e30` | 1 | 19486 | `fVar23 = (*(float *)(param_1 + 0xa0) - fVar16) - fVar6 * fVar22;` |
| `FUN_140018b00` | 1 | 24566 | `fVar17 = fVar20 * *(float *)(param_1 + 0xa0);` |
| `FUN_14001aaa0` | 1 | 26506 | `fVar13 = param_2[2] * *(float *)(param_1 + 0xa0);` |
| `FUN_14001b040` | 1 | 26646 | `*(float *)(param_1 + 0x88) + *(float *)(param_1 + 0xa0) * *(float *)(param_1 + 0x9c)) *` |
| `FUN_14001b710` | 1 | 27010 | `param_3 = param_3 * *(float *)(param_1 + 0xa0);` |
| `FUN_14001bb70` | 1 | 27564 | `fVar19 = *(float *)(param_1 + 0xa0) - *(float *)(param_1 + 0xf4);` |
| `FUN_14001c850` | 1 | 28168 | `fVar27 = *(float *)(param_1 + 0xa0) - *(float *)(param_1 + 0xf4);` |
| `FUN_14001d190` | 1 | 28344 | `fVar1 = *(float *)(param_1 + 0xa0);` |
| `FUN_14001d410` | 1 | 28712 | `fVar14 = param_2[2] * *(float *)(param_1 + 0xa0);` |
| `FUN_14001da90` | 1 | 28946 | `fVar1 = *(float *)(param_1 + 0xa0);` |
| `FUN_14001e5e0` | 1 | 30184 | `*puVar14 = *(undefined8 *)(lVar4 + 0xa0);` |
| `FUN_140027000` | 1 | 40980 | `if (0xf < *(ulonglong *)(param_1 + 0xa0)) {` |
| `FUN_1400293d0` | 1 | 44912 | `if (0xf < *(ulonglong *)(lVar9 + 0xa0)) {` |
| `FUN_140043aa0` | 1 | 75412 | `for (lVar1 = *(longlong *)(DAT_1403ea2a8 + 0xa0); lVar1 != 0;` |
| `FUN_140045c20` | 1 | 77950 | `for (lVar1 = *(longlong *)(DAT_1403ea2a8 + 0xa0); lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x30))` |
| `FUN_140068120` | 1 | 121106 | `FUN_140083c30(*(undefined8 *)(param_1 + 0xa0),*(undefined8 *)(param_1 + 600),DAT_1403d9178,0,` |
| `FUN_140080e40` | 1 | 150734 | `lVar8 = FUN_140102060(DAT_1403fb0d8,param_1,iVar10,iVar11,*(undefined4 *)(param_1 + 0xa0),` |
| `FUN_140094a20` | 1 | 174302 | `lVar22 = *(longlong *)(param_1 + 0xa0);` |
| `FUN_1400ce540` | 1 | 238696 | `uVar7 = FUN_140083430(*(undefined8 *)(param_1 + 0xa0),&local_148,0,fVar3,0);` |
| `FUN_1400fbae0` | 1 | 295584 | `if (((*(char *)(param_1 + 0xac) == '\0') && (*(int *)(param_1 + 0xa0) != 0)) \|\|` |
| `FUN_1400fcd60` | 1 | 296696 | `FUN_140075670(*(undefined4 *)(param_1 + 0xa0));` |
| `FUN_140131ef0` | 1 | 404262 | `if (*(longlong *)(param_1 + 0xa0) != 0) {` |
| `FUN_140137f40` | 1 | 413170 | `(**(code **)(param_1 + 0xa0))(*(undefined8 *)(param_1 + 0x298));` |
| `FUN_14015a4e0` | 1 | 464172 | `uVar2 = (**(code **)(local_res20 + 0xa0))(local_res18[0],param_2);` |
| `FUN_14015a960` | 1 | 464616 | `if ((param_2 == *(short *)(param_1 + 0xa0)) && (param_3 == *(short *)(param_1 + 0xa2))) {` |
| `FUN_14015d7a0` | 1 | 469018 | `FUN_140190140(*(undefined8 *)(param_1 + 0xa0));` |
| `FUN_1401644e0` | 1 | 479814 | `local_res10 = *(undefined8 *)(param_1 + 0xa0);` |
| `FUN_140164870` | 1 | 480084 | `local_res8 = *(undefined8 *)(param_1 + 0xa0);` |
| `FUN_140170b70` | 1 | 498262 | `*(undefined8 *)(param_1 + 200) = *(undefined8 *)(param_1 + 0xa0);` |
| `FUN_140170cc0` | 1 | 498384 | `*(undefined8 *)(param_1 + 200) = *(undefined8 *)(param_1 + 0xa0);` |
| `FUN_1401bc750` | 1 | 623578 | `if (*(longlong *)(param_2 + 0xa0) != 0) {` |
| `FUN_1401beac0` | 1 | 627332 | `if ((*(int *)(param_1 + 0xa0) != 0) && (*(int *)(param_2 + 0xa0) == 0)) {` |
| `FUN_1401bf8b0` | 1 | 628326 | `if (*(longlong *)(lVar4 + 0xa0) != 0) {` |
| `FUN_1401c97e0` | 1 | 641548 | `FUN_1401747e0(*(undefined4 *)(param_1 + 0xa0));` |
| `FUN_1401dd550` | 1 | 667900 | `FUN_1401841e0(*(undefined8 *)(lVar2 + 0xa0));` |
| `FUN_1401dd9b0` | 1 | 668206 | `lVar7 = *(longlong *)(lVar1 + 0xa0);` |
| `FUN_1401df920` | 1 | 670672 | `(longlong)(int)(uVar3 * *(int *)(puVar1 + 0xac)) + *(longlong *)(puVar1 + 0xa0),` |
| `FUN_1401e9660` | 1 | 683886 | `local_b8[uVar6] = *(undefined8 *)(lVar3 + 0xa0);` |
| `FUN_1401f4bb0` | 1 | 696994 | `(**(code **)(param_1 + 0xa0))(2);` |
| `FUN_140203a80` | 1 | 716188 | `if (*(longlong *)(pcVar1 + 0xa0) != 0) {` |
| `FUN_140204b80` | 1 | 717614 | `uVar4 = FUN_140132c70(*(undefined8 *)(lVar1 + 0xa0));` |
| `FUN_140204cb0` | 1 | 717692 | `uVar9 = FUN_140132c70(*(undefined8 *)(lVar1 + 0xa0));` |
| `FUN_1402051e0` | 1 | 718036 | `uVar5 = FUN_140132c70(*(undefined8 *)(lVar1 + 0xa0));` |
| `FUN_140205350` | 1 | 718108 | `uVar6 = FUN_140132c70(*(undefined8 *)(lVar1 + 0xa0));` |
| `FUN_140205710` | 1 | 718388 | `FUN_140137da0(*(undefined8 *)(param_1 + 0xa0),0,local_48,0x40);` |
| `FUN_1402057f0` | 1 | 718446 | `uVar1 = FUN_140132d50(*(undefined8 *)(param_1 + 0xa0),param_1 + 0xa8,1,0);` |
| `FUN_140206e40` | 1 | 720332 | `lVar1 = *(longlong *)(DAT_1403fd198 + 0xa0);` |
| `FUN_140208230` | 1 | 722178 | `param_1 = *(longlong *)(param_1 + 0xa0);` |
| `FUN_140208330` | 1 | 722262 | `lVar1 = *(longlong *)(param_1 + 0xa0);` |
| `FUN_14020bf60` | 1 | 728084 | `uVar2 = (**(code **)(lVar1 + 0xa0))(*(undefined8 *)(lVar1 + 0x68),param_2);` |
| `FUN_14021a4f0` | 1 | 749420 | `iVar2 = (**(code **)(lVar1 + 0xa0))(*(undefined8 *)(lVar1 + 0x10));` |
| `FUN_14022c8c0` | 1 | 776248 | `local_78.top = *(int *)(lVar2 + 0xa0) + iVar7;` |
| `FUN_140268990` | 1 | 908836 | `if (*(longlong *)(param_1 + 0xa0) != 0) {` |
| `FUN_14027cef0` | 1 | 935174 | `if (*(longlong *)(param_1 + 0xa0) != 0) {` |
| `FUN_14027d190` | 1 | 935436 | `lVar2 = *(longlong *)(param_2 + 0xa0);` |

## `+0xa4` (164 dec)

33 functions, 56 read sites.

| Function | Hits | First line | First snippet |
|---|---|---|---|
| `FUN_140021550` | 5 | 32884 | `fVar39 = *(float *)(param_1 + 0xac) - *(float *)(param_1 + 0xa4);` |
| `FUN_140080e40` | 4 | 150792 | `*(undefined4 *)(param_1 + 0xa4),*(undefined4 *)(lVar8 + 0x24c),` |
| `FUN_140018b00` | 3 | 24568 | `lVar14 = (longlong)*(int *)(param_1 + 0xa4);` |
| `FUN_14001a2e0` | 3 | 25892 | `lVar18 = (longlong)*(int *)(param_1 + 0xa4);` |
| `FUN_14001a5b0` | 3 | 26048 | `lVar15 = (longlong)*(int *)(param_1 + 0xa4);` |
| `FUN_14000b9a0` | 2 | 8520 | `(fVar5 - fVar2 * *(float *)(param_1 + 0xb0))) * *(float *)(param_1 + 0xa4) +` |
| `FUN_140014ba0` | 2 | 19232 | `(fVar3 * fVar6 + fVar8) * *(float *)(param_1 + 0xc0)) * *(float *)(param_1 + 0xa4)) *` |
| `FUN_140018650` | 2 | 24472 | `iVar7 = *(int *)(param_1 + 0xa4);` |
| `FUN_140018e70` | 2 | 24862 | `fVar23 = *(float *)(param_1 + 0xa0) * fVar11 - *(float *)(param_1 + 0xa4) * fVar10;` |
| `FUN_140019960` | 2 | 25344 | `fVar26 = *(float *)(param_1 + 0xa0) * fVar13 - *(float *)(param_1 + 0xa4) * fVar12;` |
| `FUN_140019e50` | 2 | 25794 | `iVar7 = *(int *)(param_1 + 0xa4);` |
| `FUN_1400228d0` | 2 | 34068 | `fVar8 = *(float *)(param_1 + 0xa4);` |
| `FUN_1400fc520` | 2 | 296428 | `*(uint *)(DAT_1403fb0d8 + 0x268) = (0 < *(int *)(param_1 + 0xa4)) + 1;` |
| `FUN_140160390` | 2 | 473294 | `if ((float)iVar6 <= *(float *)(param_1 + 0xa4)) {` |
| `FUN_140161f10` | 2 | 476206 | `fVar10 = param_6 - *(float *)(lVar6 + 0xa4);` |
| `FUN_140008560` | 1 | 5596 | `fVar25 = *(float *)(param_1 + 0xa4);` |
| `FUN_140008cd0` | 1 | 5848 | `local_b8 = *(undefined8 *)(param_1 + 0xa4);` |
| `FUN_140009c30` | 1 | 6506 | `fVar1 = *(float *)(param_1 + 0xa4);` |
| `FUN_14000a690` | 1 | 7318 | `fVar20 = *(float *)(param_1 + 0xa4) * *param_2;` |
| `FUN_14000bf90` | 1 | 8798 | `fVar1 = *(float *)(param_1 + 0xa4);` |
| `FUN_1400145b0` | 1 | 19052 | `fVar10 = *(float *)(param_1 + 0xa4);` |
| `FUN_140014e30` | 1 | 19464 | `fVar6 = *(float *)(param_1 + 0xa4);` |
| `FUN_14001aaa0` | 1 | 26486 | `*(float *)(param_1 + 0x88) = fVar14 * (fVar13 - *(float *)(param_1 + 0xa4)) * fVar18 * fVar12;` |
| `FUN_14001b280` | 1 | 26832 | `fVar17 = fVar17 - *(float *)(param_1 + 0xa4);` |
| `FUN_14001bb70` | 1 | 27560 | `fVar18 = *(float *)(param_1 + 0xa4) - *(float *)(param_1 + 0xf8);` |
| `FUN_14001c850` | 1 | 28158 | `fVar26 = *(float *)(param_1 + 0xa4) - *(float *)(param_1 + 0xf8);` |
| `FUN_14001d190` | 1 | 28346 | `fVar2 = *(float *)(param_1 + 0xa4);` |
| `FUN_14001d7e0` | 1 | 28814 | `fVar13 = *(float *)(param_1 + 0xa4) * *param_2;` |
| `FUN_1400aabb0` | 1 | 198808 | `iVar1 = *(int *)(param_1 + 0xa4);` |
| `FUN_1400fcd60` | 1 | 296698 | `FUN_140075670(*(undefined4 *)(param_1 + 0xa4));` |
| `FUN_14010a5e0` | 1 | 314470 | `if ((iVar11 != (*(int *)(lVar7 + 0xa4) != 0) + 1) \|\|` |
| `FUN_1401beac0` | 1 | 627344 | `if ((*(int *)(param_1 + 0xa4) != 0) && (*(int *)(param_2 + 0xa4) == 0)) {` |
| `FUN_14022c8c0` | 1 | 776246 | `local_78.right = *(int *)(lVar2 + 0xa4) + iVar8;` |

## `+0x200` (512 dec)

35 functions, 53 read sites.

| Function | Hits | First line | First snippet |
|---|---|---|---|
| `FUN_1400d52c0` | 5 | 246548 | `if (*(int *)(lVar2 + 0x200) <= *(int *)(lVar2 + 0x1fc)) {` |
| `FUN_140102060` | 3 | 303822 | `iVar12 = (*(int *)(lVar2 + 0x1fc) * 9) / *(int *)(lVar2 + 0x200) -` |
| `FUN_140155130` | 3 | 455918 | `FUN_1401ab340(*(undefined8 *)(lVar2 + 0x200),*(undefined8 *)(param_1 + 0x36));` |
| `FUN_1401c6970` | 3 | 637452 | `FUN_1401cb1d0(param_1,*(undefined8 *)(*(longlong *)(param_2 + 0x200) + uVar5 * 8));` |
| `FUN_1401cb9a0` | 3 | 644430 | `if (*(undefined8 **)(*(longlong *)(param_1 + 0x200) + uVar3 * 8) == param_2) {` |
| `FUN_1400b76a0` | 2 | 212112 | `return CONCAT31((int3)((uint)*(int *)(param_1 + 0x200) >> 8),` |
| `FUN_1400d2090` | 2 | 243254 | `if (*(int *)(param_1 + 0x200) != 1) {` |
| `FUN_140106bc0` | 2 | 309736 | `if ((*(int *)(lVar2 + 0x1fc) <= *(int *)(lVar2 + 0x200) + -2) &&` |
| `FUN_140173d30` | 2 | 503042 | `if ((*(int *)(lVar1 + 0x570) != 0) && (*(code **)(lVar1 + 0x200) != (code *)0x0)) {` |
| `FUN_1401741d0` | 2 | 503406 | `iVar2 < 1)) && (*(code **)(lVar1 + 0x200) != (code *)0x0)) {` |
| `FUN_1401c2330` | 2 | 631438 | `FUN_140179b40(*(undefined8 *)(param_1 + 0x200));` |
| `FUN_140056620` | 1 | 102610 | `if (*(int *)(lVar14 + 0x1fc) < *(int *)(lVar14 + 0x200)) {` |
| `FUN_14005e3c0` | 1 | 109694 | `*(undefined4 *)(lVar8 + 0x1fc) = *(undefined4 *)(lVar8 + 0x200);` |
| `FUN_140080e40` | 1 | 150724 | `((0 < *(int *)(lVar8 + 0x1fc) && (*(int *)(lVar8 + 0x1fc) < *(int *)(lVar8 + 0x200))))) &&` |
| `FUN_140081600` | 1 | 151014 | `(*(int *)(uVar2 + 0x1fc) < *(int *)(uVar2 + 0x200))) {` |
| `FUN_1400b7660` | 1 | 212086 | `if ((((0 < iVar1) \|\| (param_3 != '\0')) && (iVar1 < *(int *)(param_1 + 0x200))) &&` |
| `FUN_1400ba940` | 1 | 216414 | `iVar16 = (*(int *)(param_1 + 0x1fc) * 9) / *(int *)(param_1 + 0x200);` |
| `FUN_1400cfa00` | 1 | 240176 | `if ((iVar1 < 3) && ((iVar1 < 2 \|\| (*(int *)(param_2 + 0x1fc) < *(int *)(param_2 + 0x200) + -2))))` |
| `FUN_1400dcab0` | 1 | 254382 | `local_ac = *(int *)(lVar1 + 0x200);` |
| `FUN_1400df280` | 1 | 257632 | `iVar8 = *(int *)(lVar9 + 0x200) - *(int *)(lVar9 + 0x1fc);` |
| `FUN_1400e0aa0` | 1 | 259996 | `if ((*(int *)(lVar13 + 0x1c) != 6) && (*(int *)(lVar13 + 0x1fc) < *(int *)(lVar13 + 0x200)))` |
| `FUN_140100230` | 1 | 301262 | `uVar4 = FUN_1400c6580(*(int *)(lVar8 + 0x200) + -1);` |
| `FUN_140100e30` | 1 | 302288 | `(*(int *)(param_2 + 0x1fc) < *(int *)(param_2 + 0x200))) {` |
| `FUN_140101dc0` | 1 | 303548 | `iVar9 = *(int *)(lVar2 + 0x200);` |
| `FUN_140107190` | 1 | 310098 | `((*(int *)(lVar2 + 0x1fc) < *(int *)(lVar2 + 0x200) && (*(int *)(lVar12 + 0x70) != 0xd))))` |
| `FUN_140107660` | 1 | 311356 | `uVar11 = FUN_1400c6580(*(int *)(lVar16 + 0x200) + -2);` |
| `FUN_140138c10` | 1 | 414622 | `uVar2 = (**(code **)(param_1 + 0x200))(*(undefined8 *)(param_1 + 0x298));` |
| `FUN_14014da10` | 1 | 446030 | `if (*(longlong *)(param_1 + 0x200) != 0) {` |
| `FUN_1401c5ac0` | 1 | 636534 | `((*(longlong *)(lVar4 + 0x200) != 0 && (lVar6 != 0)))))) {` |
| `FUN_1401c9630` | 1 | 641202 | `FUN_1401841e0(*(undefined8 *)(param_1 + 0x200));` |
| `FUN_1401c97e0` | 1 | 641666 | `FUN_140179b30(*(undefined8 *)(param_1 + 0x200));` |
| `FUN_1401e3d10` | 1 | 676472 | `if (lVar11 != *(longlong *)(lVar1 + 0x200)) {` |
| `FUN_1401ef800` | 1 | 690788 | `if (*(char *)(param_1 + 0x200) != '\0') {` |
| `FUN_140224be0` | 1 | 764952 | `FUN_1401838c0(param_1 + 0x1a8,*(undefined4 *)(param_1 + 0x1f8),*(undefined4 *)(param_1 + 0x200),` |
| `FUN_1402ff070` | 1 | 1132276 | `FUN_1402c7088(*(undefined8 *)(param_2 + 0x200),600);` |

## `+0x254` (596 dec)

36 functions, 116 read sites.

| Function | Hits | First line | First snippet |
|---|---|---|---|
| `FUN_140098660` | 20 | 178656 | `iVar14 = FUN_1400c6dd0(*(int *)(param_1 + 0x254) + -0x3c,0xf);` |
| `FUN_140094a20` | 13 | 174064 | `(0xb4 < *(int *)(param_1 + 0x254))) && ((DAT_1403ed570 != '\0' \|\| (DAT_1403ed968 != 0)))) {` |
| `FUN_140089510` | 8 | 162220 | `if (*(int *)(param_1 + 0x254) != 0x3c) goto LAB_14008b577;` |
| `FUN_1400e25b0` | 8 | 260834 | `if (((*(int *)(param_1 + 0x250) == 2) && (*(int *)(param_1 + 0x254) < 0x96)) \|\|` |
| `FUN_14007b2e0` | 7 | 145724 | `if ((*(int *)(param_1 + 0x254) != 0x3c) \|\| (*(char *)(param_1 + 0x2a8) != '\0'))` |
| `FUN_14008b6f0` | 6 | 163570 | `uVar10 = *(int *)(param_1 + 0x254) / 0x1e & 0x80000001;` |
| `FUN_14003a940` | 5 | 65192 | `if (*(int *)(param_1 + 0x254) != 5) {` |
| `FUN_140035280` | 4 | 59468 | `iVar4 = FUN_1400c6df0(*(int *)(param_1 + 0x254) - iVar9,0x20);` |
| `FUN_140063410` | 4 | 115594 | `if (*(int *)(param_1 + 0x254) < 4) {` |
| `FUN_14007c970` | 4 | 146940 | `uVar7 = (int)((*(int *)(param_1 + 0x254) >> 0x1f & 7U) + *(int *)(param_1 + 0x254)) >> 3 &` |
| `FUN_14005fcf0` | 3 | 111504 | `FUN_1400cd5a0(param_1,*(int *)(param_1 + 0x254) != 1);` |
| `FUN_14002d170` | 2 | 50318 | `iVar7 = (*(int *)(param_1 + 0x254) + -1) / 0x3c;` |
| `FUN_14002d7c0` | 2 | 50862 | `fVar24 = (float)*(int *)(param_1 + 0x254) * DAT_14030335c;` |
| `FUN_14002f300` | 2 | 52582 | `iVar1 = *(int *)(param_1 + 0x254);` |
| `FUN_14003c8c0` | 2 | 66586 | `*(undefined4 *)(param_1 + 600) = *(undefined4 *)(param_1 + 0x254);` |
| `FUN_14003d890` | 2 | 67298 | `if (((*piVar1 == 3) && (*(int *)(param_1 + 0x254) < 4)) && (*(int *)(param_1 + 0x250) == 0x78)) {` |
| `FUN_140063e10` | 2 | 115996 | `iVar3 = *(int *)(param_1 + 0x254);` |
| `FUN_140088350` | 2 | 159706 | `FUN_1400cf540(param_1,0,*(float *)(param_1 + 0x118) - *(float *)(DAT_1403f4e00 + 0x254),` |
| `FUN_140097dd0` | 2 | 177308 | `iVar4 = (*(int *)(param_1 + 0x254) + -1) / 0x3c;` |
| `FUN_1401041f0` | 2 | 306132 | `if ((DAT_1403d9524 != '\0') && (*(int *)(param_1 + 0x254) != 0)) {` |
| `FUN_14002e790` | 1 | 51932 | `uVar9 = *(int *)(param_1 + 0x254) / 0x1e & 0x80000001;` |
| `FUN_140058480` | 1 | 103654 | `iVar3 = *(int *)(param_1 + 0x254);` |
| `FUN_14005a720` | 1 | 106168 | `if (*(int *)(param_1 + 0x254) != 3) {` |
| `FUN_14005ba00` | 1 | 106776 | `FUN_140075670(*(undefined4 *)(param_1 + 0x254));` |
| `FUN_14005c3d0` | 1 | 107512 | `*(longlong *)(param_1 + 0x148)) && (*(char *)(param_1 + 0x254) != '\0')) &&` |
| `FUN_140060a80` | 1 | 112284 | `if (*(int *)(param_1 + 0x254) != 2) {` |
| `FUN_140061920` | 1 | 113268 | `iVar1 = *(int *)(param_1 + 0x254);` |
| `FUN_140066200` | 1 | 118872 | `*(undefined8 *)(param_1 + 0xe4) = *(undefined8 *)(param_1 + 0x254);` |
| `FUN_140067270` | 1 | 119660 | `if ((*(float *)(param_1 + 0x254) < fVar1) \|\| (fVar1 + param_2[2] <= *(float *)(param_1 + 0x254)))` |
| `FUN_1400676c0` | 1 | 120036 | `fVar7 = (float)FUN_1400c6180(*(undefined4 *)(param_1 + 0x254),fVar2 + DAT_14030374c,` |
| `FUN_14006dc80` | 1 | 127386 | `FUN_140075670(*(undefined4 *)(param_1 + 0x254));` |
| `FUN_1400c0660` | 1 | 222634 | `iVar26 = *(int *)(param_1 + 0x254);` |
| `FUN_1400cd5a0` | 1 | 237642 | `fVar18 = *(float *)(DAT_1403f4e00 + 0x254);` |
| `FUN_1400fa800` | 1 | 294226 | `fVar5 = *(float *)(param_1 + 0x254) * DAT_14039ca34;` |
| `FUN_14010ba40` | 1 | 315954 | `if (*(int *)(param_1 + 0x254) % 0x1c20 == 1) {` |
| `FUN_1401ef800` | 1 | 690890 | `(*(int *)(param_1 + 0x254) + *(int *)(param_1 + 0x204),iVar9,` |

## `+0x2a8` (680 dec)

25 functions, 42 read sites.

| Function | Hits | First line | First snippet |
|---|---|---|---|
| `FUN_140032ac0` | 5 | 56538 | `if (*(longlong *)(param_1 + 0x2a8) - lVar6 >> 4 != 0) {` |
| `FUN_14003d890` | 5 | 67836 | `FUN_140009e60(*(undefined8 *)(param_1 + 0x2a8));` |
| `FUN_140094a20` | 4 | 176134 | `(longlong)*(int *)(param_1 + 0x2a8) * 0x10) = 1;` |
| `FUN_140032f90` | 2 | 56938 | `if (*(longlong *)(param_1 + 0x2a8) - lVar13 >> 4 != 0) {` |
| `FUN_14003c8c0` | 2 | 66992 | `FUN_140009e60(*(undefined8 *)(param_1 + 0x2a8),0);` |
| `FUN_140092820` | 2 | 171506 | `uVar17 = (ulonglong)*(int *)(param_1 + 0x2a8);` |
| `FUN_1400cacd0` | 2 | 234664 | `*(float *)(lVar21 + 0x2b0) + *(float *)(lVar21 + 0x2a8));` |
| `FUN_1400cba60` | 2 | 235478 | `local_resc = (*(float *)(lVar3 + 0x2b0) * DAT_14039ca34 + *(float *)(lVar3 + 0x2a8)) *` |
| `FUN_14014b940` | 2 | 443674 | `if (*(ulonglong *)(param_1 + 0x2a8) < uVar4) {` |
| `FUN_140030d50` | 1 | 54356 | `if (*(longlong *)(param_1 + 0x2a0) != *(longlong *)(param_1 + 0x2a8)) {` |
| `FUN_140039190` | 1 | 64254 | `CONCAT44((*(float *)(lVar19 + 0x2b0) * DAT_14039ca34 + *(float *)(lVar19 + 0x2a8)` |
| `FUN_140064b50` | 1 | 117272 | `if ((sVar12 == *(size_t *)(param_1 + 0x2a8)) &&` |
| `FUN_14006ee10` | 1 | 128402 | `FUN_1400756d0(*(undefined8 *)(param_1 + 0x2a8));` |
| `FUN_14007b2e0` | 1 | 145724 | `if ((*(int *)(param_1 + 0x254) != 0x3c) \|\| (*(char *)(param_1 + 0x2a8) != '\0'))` |
| `FUN_14007d970` | 1 | 147352 | `FUN_140075750(*(undefined1 *)(param_1 + 0x2a8));` |
| `FUN_14007fc40` | 1 | 149924 | `FUN_140071d20(*(undefined4 *)(param_1 + 0x2a8));` |
| `FUN_14008e1d0` | 1 | 166260 | `iVar1 = *(int *)(&DAT_14030b7a8 + (*(ulonglong *)(lVar2 + 0x2a8) % 9) * 4) * 2;` |
| `FUN_1400ba940` | 1 | 216180 | `if ((*(byte *)(param_1 + 0x2a8) & 1) == 0) {` |
| `FUN_1400dcab0` | 1 | 254390 | `uVar17 = *(longlong *)(*(longlong *)(param_1 + 0x148) + 0x2a8) + *(longlong *)(lVar1 + 0x2a8);` |
| `FUN_140134650` | 1 | 407604 | `else if ((*(uint *)(param_1 + 0x2a8) & *(uint *)(param_2 + 0x18)) == 0) {` |
| `FUN_140135420` | 1 | 408752 | `else if ((*(uint *)(param_1 + 0x2a8) & *(uint *)(param_2 + 0x18)) == 0) {` |
| `FUN_140137850` | 1 | 412356 | `return *(undefined4 *)(param_1 + 0x2a8);` |
| `FUN_1401697e0` | 1 | 486512 | `cVar2 = (**(code **)(lVar3 + 0x2a8))(lVar3);` |
| `FUN_1401f32b0` | 1 | 695216 | `(fVar17 != *(float *)(lVar2 + 0x2a8))) \|\|` |
| `FUN_1402f5198` | 1 | 1119618 | `FUN_1402e9a80(*(undefined8 *)(param_1 + 0x2a8));` |
