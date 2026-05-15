// Address: 0x1400ea190
// Ghidra name: FUN_1400ea190
// ============ 0x1400ea190 FUN_1400ea190 (size=1278) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



longlong FUN_1400ea190(longlong *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4

                      ,uint param_5)



{

  undefined1 uVar1;

  undefined8 uVar2;

  ulonglong uVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  longlong lVar7;

  code *pcVar8;

  longlong lVar9;

  uint uVar10;

  uint *puVar11;

  uint uVar12;

  longlong lVar13;

  ulonglong uVar14;

  int *piVar15;

  undefined1 *puVar16;

  longlong lVar17;

  ulonglong uVar18;

  ulonglong uVar19;

  longlong *plVar20;

  int *piVar21;

  uint uVar22;

  uint uVar23;

  byte *pbVar24;

  uint uVar25;

  longlong lVar26;

  uint local_148;

  longlong local_128 [2];

  byte *local_118;

  int local_ec [2];

  int local_e4 [41];

  

  if (4 < param_5) {

    _DAT_1403f4c40 = "bad req_comp";

    return 0;

  }

  uVar14 = 0;

  *(undefined4 *)(*param_1 + 8) = 0;

  iVar4 = FUN_1400e8890();

  if (iVar4 == 0) {

    FUN_1400e69b0(param_1);

    lVar7 = 0;

  }

  else {

    if (param_5 == 0) {

      param_5 = *(uint *)(*param_1 + 8);

    }

    uVar18 = (ulonglong)param_5;

    iVar4 = *(int *)(*param_1 + 8);

    if ((iVar4 == 3) && ((int)param_5 < 3)) {

      iVar4 = 1;

    }

    lVar26 = (longlong)iVar4;

    if (0 < iVar4) {

      piVar15 = local_ec;

      piVar21 = (int *)((longlong)param_1 + 0x35a4);

      uVar19 = uVar14;

      do {

        lVar7 = _malloc_base(*(int *)*param_1 + 3);

        *(longlong *)(piVar21 + 0xf) = lVar7;

        if (lVar7 == 0) goto LAB_1400ea339;

        lVar7 = param_1[0x6b1];

        piVar15[3] = 0;

        uVar3 = (longlong)(int)lVar7 / (longlong)*piVar21;

        iVar5 = (int)uVar3;

        piVar15[-1] = iVar5;

        iVar6 = *(int *)((longlong)param_1 + 0x358c) / piVar21[1];

        *piVar15 = iVar6;

        piVar15[2] = iVar6 >> 1;

        iVar4 = *(int *)*param_1;

        uVar2 = *(undefined8 *)(piVar21 + 0xb);

        *(undefined8 *)(piVar15 + -3) = uVar2;

        *(undefined8 *)(piVar15 + -5) = uVar2;

        piVar15[1] = (int)((ulonglong)(uint)(iVar4 + -1 + iVar5) / (uVar3 & 0xffffffff));

        if (iVar5 == 1) {

          if (iVar6 == 1) {

            pcVar8 = FUN_1400e51e0;

          }

          else {

            if (iVar6 != 2) goto LAB_1400ea2fa;

            pcVar8 = FUN_1400e51f0;

          }

        }

        else if (iVar5 == 2) {

          if (iVar6 == 1) {

            pcVar8 = FUN_1400e53d0;

          }

          else {

            pcVar8 = FUN_1400e54c0;

            if (iVar6 != 2) goto LAB_1400ea2fa;

          }

        }

        else {

LAB_1400ea2fa:

          pcVar8 = (code *)&LAB_1400e5590;

        }

        *(code **)(piVar15 + -7) = pcVar8;

        uVar19 = uVar19 + 1;

        piVar15 = piVar15 + 0xc;

        piVar21 = piVar21 + 0x12;

      } while ((longlong)uVar19 < lVar26);

    }

    lVar7 = _malloc_base(param_5 * ((int *)*param_1)[1] * *(int *)*param_1 + 1);

    if (lVar7 == 0) {

LAB_1400ea339:

      FUN_1400e69b0(param_1);

      _DAT_1403f4c40 = "outofmem";

      lVar7 = 0;

    }

    else {

      puVar11 = (uint *)*param_1;

      local_148 = 0;

      lVar9 = local_128[0];

      if (puVar11[1] != 0) {

        do {

          lVar17 = 0;

          puVar16 = (undefined1 *)((ulonglong)((uint)uVar14 * *puVar11 * (int)uVar18) + lVar7);

          uVar25 = (uint)uVar14;

          if (0 < lVar26) {

            plVar20 = param_1 + 0x6b8;

            piVar21 = local_e4;

            do {

              lVar9 = 8;

              iVar4 = *piVar21;

              lVar13 = -0x14;

              if (iVar4 < piVar21[-2] >> 1) {

                lVar9 = 0x10;

                lVar13 = -0x1c;

              }

              lVar9 = (**(code **)(piVar21 + -9))

                                (plVar20[4],*(undefined8 *)(lVar13 + (longlong)piVar21),

                                 *(undefined8 *)(lVar9 + -0x24 + (longlong)piVar21),piVar21[-1],

                                 piVar21[-3]);

              local_128[lVar17] = lVar9;

              iVar4 = iVar4 + 1;

              *piVar21 = iVar4;

              if (piVar21[-2] <= iVar4) {

                piVar21[1] = piVar21[1] + 1;

                *piVar21 = 0;

                *(longlong *)(piVar21 + -7) = *(longlong *)(piVar21 + -5);

                if (piVar21[1] < (int)*plVar20) {

                  *(longlong *)(piVar21 + -5) =

                       (longlong)*(int *)((longlong)plVar20 + 4) + *(longlong *)(piVar21 + -5);

                }

              }

              lVar17 = lVar17 + 1;

              piVar21 = piVar21 + 0xc;

              plVar20 = plVar20 + 9;

              lVar9 = local_128[0];

              uVar25 = local_148;

            } while (lVar17 < lVar26);

          }

          uVar14 = 0;

          uVar18 = (ulonglong)(int)param_5;

          puVar11 = (uint *)*param_1;

          if ((int)param_5 < 3) {

            if (param_5 == 1) {

              if (*puVar11 != 0) {

                do {

                  uVar12 = (int)uVar14 + 1;

                  puVar16[uVar14] = *(undefined1 *)(lVar9 + uVar14);

                  puVar11 = (uint *)*param_1;

                  uVar14 = (ulonglong)uVar12;

                } while (uVar12 < *puVar11);

              }

            }

            else if (*puVar11 != 0) {

              do {

                uVar12 = (int)uVar14 + 1;

                *puVar16 = *(undefined1 *)(uVar14 + lVar9);

                puVar16[1] = 0xff;

                puVar11 = (uint *)*param_1;

                uVar14 = (ulonglong)uVar12;

                puVar16 = puVar16 + 2;

              } while (uVar12 < *puVar11);

            }

          }

          else if (puVar11[2] == 3) {

            lVar17 = (longlong)(int)*puVar11;

            if (0 < lVar17) {

              puVar16 = puVar16 + 2;

              uVar25 = 0;

              pbVar24 = local_118;

              do {

                iVar4 = (uint)pbVar24[lVar9 - (longlong)local_118] * 0x10000 + 0x8000;

                uVar22 = (int)((*pbVar24 - 0x80) * 0x166e9 + iVar4) >> 0x10;

                uVar23 = (int)((uint)pbVar24[local_128[1] - (longlong)local_118] * -0x581a +

                               (uint)*pbVar24 * -0xb6d2 + 0x877600 + iVar4) >> 0x10;

                uVar10 = (int)((pbVar24[local_128[1] - (longlong)local_118] - 0x80) * 0x1c5a2 +

                              iVar4) >> 0x10;

                uVar12 = uVar22;

                if ((0xff < uVar22) && (uVar12 = 0xff, (int)uVar22 < 0)) {

                  uVar12 = uVar25;

                }

                uVar22 = uVar23;

                if ((0xff < uVar23) && (uVar22 = 0xff, (int)uVar23 < 0)) {

                  uVar22 = uVar25;

                }

                uVar23 = uVar10;

                if ((0xff < uVar10) && (uVar23 = 0xff, (int)uVar10 < 0)) {

                  uVar23 = uVar25;

                }

                puVar16[-2] = (char)uVar12;

                pbVar24 = pbVar24 + 1;

                puVar16[-1] = (char)uVar22;

                *puVar16 = (char)uVar23;

                puVar16[1] = 0xff;

                puVar16 = puVar16 + uVar18;

                lVar17 = lVar17 + -1;

              } while (lVar17 != 0);

              puVar11 = (uint *)*param_1;

              uVar18 = (ulonglong)param_5;

              uVar25 = local_148;

            }

          }

          else if (*puVar11 != 0) {

            do {

              uVar12 = (int)uVar14 + 1;

              uVar1 = *(undefined1 *)(uVar14 + lVar9);

              puVar16[2] = uVar1;

              puVar16[1] = uVar1;

              *puVar16 = uVar1;

              puVar16[3] = 0xff;

              puVar16 = puVar16 + uVar18;

              puVar11 = (uint *)*param_1;

              uVar14 = (ulonglong)uVar12;

            } while (uVar12 < *puVar11);

          }

          local_148 = uVar25 + 1;

          uVar14 = (ulonglong)local_148;

        } while (local_148 < puVar11[1]);

      }

      FUN_1400e69b0(param_1);

      *param_2 = *(undefined4 *)*param_1;

      *param_3 = *(undefined4 *)(*param_1 + 4);

      if (param_4 != (undefined4 *)0x0) {

        *param_4 = *(undefined4 *)(*param_1 + 8);

      }

    }

  }

  return lVar7;

}




