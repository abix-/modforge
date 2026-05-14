// Address: 0x1400e6a30
// Ghidra name: FUN_1400e6a30
// ============ 0x1400e6a30 FUN_1400e6a30 (size=1350) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



bool FUN_1400e6a30(undefined8 *param_1)



{

  byte bVar1;

  ushort uVar2;

  byte *pbVar3;

  uint uVar4;

  uint uVar5;

  int iVar6;

  undefined1 *puVar7;

  undefined1 uVar8;

  int iVar9;

  uint uVar10;

  longlong lVar11;

  ulonglong uVar12;

  int iVar13;

  ulonglong uVar14;

  int iVar15;

  undefined8 *puVar16;

  uint uVar17;

  uint uVar18;

  uint *puVar19;

  int *piVar20;

  byte local_a20 [23];

  undefined1 auStack_a09 [465];

  ushort local_838 [512];

  ushort auStack_438 [16];

  int aiStack_418 [10];

  int local_3f0;

  int aiStack_3ec [6];

  ushort auStack_3d4 [16];

  byte abStack_3b4 [288];

  ushort auStack_294 [298];

  

  iVar9 = *(int *)(param_1 + 2);

  uVar12 = 0;

  if (iVar9 < 5) {

    uVar4 = *(uint *)((longlong)param_1 + 0x14);

    iVar13 = iVar9;

    do {

      iVar9 = iVar9 + 8;

      pbVar3 = (byte *)*param_1;

      uVar17 = 0;

      if (pbVar3 < (byte *)param_1[1]) {

        bVar1 = *pbVar3;

        *param_1 = pbVar3 + 1;

        uVar17 = (uint)bVar1;

      }

      *(int *)(param_1 + 2) = iVar9;

      uVar4 = uVar17 << ((byte)iVar13 & 0x1f) | uVar4;

      iVar13 = iVar13 + 8;

      *(uint *)((longlong)param_1 + 0x14) = uVar4;

    } while (iVar9 < 0x19);

  }

  iVar9 = iVar9 + -5;

  uVar17 = *(uint *)((longlong)param_1 + 0x14) >> 5;

  uVar4 = (*(uint *)((longlong)param_1 + 0x14) & 0x1f) + 0x101;

  *(uint *)((longlong)param_1 + 0x14) = uVar17;

  *(int *)(param_1 + 2) = iVar9;

  uVar18 = 0;

  if (iVar9 < 5) {

    iVar13 = iVar9;

    do {

      pbVar3 = (byte *)*param_1;

      uVar5 = uVar18;

      if (pbVar3 < (byte *)param_1[1]) {

        bVar1 = *pbVar3;

        *param_1 = pbVar3 + 1;

        uVar5 = (uint)bVar1;

      }

      iVar9 = iVar13 + 8;

      uVar17 = uVar5 << ((byte)iVar13 & 0x1f) | uVar17;

      *(int *)(param_1 + 2) = iVar9;

      *(uint *)((longlong)param_1 + 0x14) = uVar17;

      iVar13 = iVar9;

    } while (iVar9 < 0x19);

  }

  uVar5 = uVar17 >> 5;

  iVar13 = (uVar17 & 0x1f) + 1;

  iVar9 = iVar9 + -5;

  *(uint *)((longlong)param_1 + 0x14) = uVar5;

  *(int *)(param_1 + 2) = iVar9;

  if (iVar9 < 4) {

    iVar6 = iVar9;

    do {

      pbVar3 = (byte *)*param_1;

      uVar17 = uVar18;

      if (pbVar3 < (byte *)param_1[1]) {

        bVar1 = *pbVar3;

        *param_1 = pbVar3 + 1;

        uVar17 = (uint)bVar1;

      }

      iVar9 = iVar6 + 8;

      uVar5 = uVar17 << ((byte)iVar6 & 0x1f) | uVar5;

      *(int *)(param_1 + 2) = iVar9;

      *(uint *)((longlong)param_1 + 0x14) = uVar5;

      iVar6 = iVar9;

    } while (iVar9 < 0x19);

  }

  puVar19 = (uint *)((longlong)param_1 + 0x14);

  uVar17 = uVar5 >> 4;

  iVar9 = iVar9 + -4;

  *puVar19 = uVar17;

  uVar5 = (uVar5 & 0xf) + 4;

  piVar20 = (int *)(param_1 + 2);

  *piVar20 = iVar9;

  local_a20[0] = 0;

  local_a20[1] = 0;

  local_a20[2] = 0;

  local_a20[3] = 0;

  local_a20[4] = 0;

  local_a20[5] = 0;

  local_a20[6] = 0;

  local_a20[7] = 0;

  local_a20[8] = 0;

  local_a20[9] = 0;

  local_a20[10] = 0;

  local_a20[0xb] = 0;

  local_a20[0xc] = 0;

  local_a20[0xd] = 0;

  local_a20[0xe] = 0;

  local_a20[0xf] = 0;

  local_a20[0x10] = 0;

  local_a20[0x11] = 0;

  local_a20[0x12] = 0;

  uVar14 = uVar12;

  if (uVar5 != 0) {

    do {

      uVar10 = uVar17;

      if (iVar9 < 3) {

        iVar6 = iVar9;

        do {

          pbVar3 = (byte *)*param_1;

          uVar10 = uVar18;

          if (pbVar3 < (byte *)param_1[1]) {

            bVar1 = *pbVar3;

            *param_1 = pbVar3 + 1;

            uVar10 = (uint)bVar1;

          }

          iVar9 = iVar6 + 8;

          uVar17 = uVar10 << ((byte)iVar6 & 0x1f) | uVar17;

          *piVar20 = iVar9;

          *puVar19 = uVar17;

          iVar6 = iVar9;

          uVar10 = uVar17;

        } while (iVar9 < 0x19);

      }

      bVar1 = (&DAT_1403db0b0)[uVar14];

      uVar17 = uVar10 >> 3;

      iVar9 = iVar9 + -3;

      *puVar19 = uVar17;

      uVar14 = uVar14 + 1;

      *piVar20 = iVar9;

      local_a20[bVar1] = (byte)uVar10 & 7;

    } while ((longlong)uVar14 < (longlong)(ulonglong)uVar5);

  }

  piVar20 = (int *)(param_1 + 2);

  puVar19 = (uint *)((longlong)param_1 + 0x14);

  puVar16 = param_1 + 1;

  iVar6 = FUN_1400f03f0(local_838,local_a20,0x13);

  if (iVar6 != 0) {

    do {

      if (iVar9 < 0x10) {

        uVar17 = *puVar19;

        iVar6 = iVar9;

        do {

          pbVar3 = (byte *)*param_1;

          uVar5 = uVar18;

          if (pbVar3 < (byte *)*puVar16) {

            bVar1 = *pbVar3;

            *param_1 = pbVar3 + 1;

            uVar5 = (uint)bVar1;

          }

          iVar9 = iVar6 + 8;

          uVar17 = uVar5 << ((byte)iVar6 & 0x1f) | uVar17;

          *piVar20 = iVar9;

          *puVar19 = uVar17;

          iVar6 = iVar9;

        } while (iVar9 < 0x19);

      }

      uVar14 = (ulonglong)local_838[uVar17 & 0x1ff];

      iVar6 = (int)uVar12;

      if (local_838[uVar17 & 0x1ff] < 0xffff) {

        uVar17 = uVar17 >> (abStack_3b4[uVar14] & 0x1f);

        iVar9 = iVar9 - (uint)abStack_3b4[uVar14];

LAB_1400e6d89:

        uVar2 = auStack_294[uVar14];

        *piVar20 = iVar9;

        *puVar19 = uVar17;

        if (uVar2 < 0x10) {

          iVar15 = 1;

          auStack_a09[(longlong)iVar6 + 1] = (char)uVar2;

        }

        else {

          if (uVar2 == 0x10) {

            if (iVar9 < 2) {

              do {

                iVar9 = iVar9 + 8;

                pbVar3 = (byte *)*param_1;

                uVar5 = uVar18;

                if (pbVar3 < (byte *)*puVar16) {

                  bVar1 = *pbVar3;

                  *param_1 = pbVar3 + 1;

                  uVar5 = (uint)bVar1;

                }

                *piVar20 = iVar9;

                uVar17 = uVar17 | uVar5 << ((char)iVar9 - 8U & 0x1f);

                *puVar19 = uVar17;

              } while (iVar9 < 0x19);

            }

            uVar5 = uVar17 & 3;

            uVar17 = uVar17 >> 2;

            iVar15 = uVar5 + 3;

            iVar9 = iVar9 + -2;

            puVar7 = auStack_a09 + (longlong)iVar6 + 1;

            uVar8 = auStack_a09[iVar6];

          }

          else {

            if (uVar2 == 0x11) {

              if (iVar9 < 3) {

                do {

                  iVar9 = iVar9 + 8;

                  pbVar3 = (byte *)*param_1;

                  uVar5 = uVar18;

                  if (pbVar3 < (byte *)*puVar16) {

                    bVar1 = *pbVar3;

                    *param_1 = pbVar3 + 1;

                    uVar5 = (uint)bVar1;

                  }

                  *piVar20 = iVar9;

                  uVar17 = uVar17 | uVar5 << ((char)iVar9 - 8U & 0x1f);

                  *puVar19 = uVar17;

                } while (iVar9 < 0x19);

              }

              iVar9 = iVar9 + -3;

              uVar5 = uVar17 & 7;

              uVar17 = uVar17 >> 3;

              iVar15 = uVar5 + 3;

            }

            else {

              uVar5 = uVar17;

              if (iVar9 < 7) {

                do {

                  iVar9 = iVar9 + 8;

                  pbVar3 = (byte *)*param_1;

                  uVar5 = 0;

                  if (pbVar3 < (byte *)*puVar16) {

                    bVar1 = *pbVar3;

                    *param_1 = pbVar3 + 1;

                    uVar5 = (uint)bVar1;

                  }

                  *piVar20 = iVar9;

                  uVar17 = uVar5 << ((char)iVar9 - 8U & 0x1f) | uVar17;

                  *puVar19 = uVar17;

                  uVar5 = uVar17;

                } while (iVar9 < 0x19);

              }

              iVar9 = iVar9 + -7;

              uVar17 = uVar5 >> 7;

              iVar15 = (uVar5 & 0x7f) + 0xb;

            }

            puVar7 = auStack_a09 + (longlong)iVar6 + 1;

            uVar8 = 0;

          }

          *puVar19 = uVar17;

          *piVar20 = iVar9;

          FUN_1402f94c0(puVar7,uVar8,iVar15);

        }

      }

      else {

        uVar5 = (int)uVar17 >> 1 & 0x5555U | (uVar17 & 0x5555) * 2;

        uVar5 = uVar5 >> 2 & 0x3333 | (uVar5 & 0x3333) << 2;

        uVar5 = uVar5 >> 4 & 0xf0f | (uVar5 & 0xf0f) << 4;

        uVar5 = (uVar5 & 0xff) << 8 | uVar5 >> 8;

        iVar15 = 10;

        lVar11 = 10;

        if (local_3f0 <= (int)uVar5) {

          do {

            lVar11 = lVar11 + 1;

            iVar15 = iVar15 + 1;

          } while (aiStack_418[lVar11] <= (int)uVar5);

          iVar9 = *piVar20;

          uVar17 = *puVar19;

        }

        if (iVar15 != 0x10) {

          iVar9 = iVar9 - iVar15;

          uVar17 = uVar17 >> ((byte)iVar15 & 0x1f);

          uVar14 = (ulonglong)

                   (int)((uint)auStack_3d4[lVar11] +

                        (((int)uVar5 >> (0x10 - (byte)iVar15 & 0x1f)) - (uint)auStack_438[lVar11]));

          goto LAB_1400e6d89;

        }

        iVar15 = 1;

        auStack_a09[(longlong)iVar6 + 1] = 0xff;

      }

      uVar5 = iVar6 + iVar15;

      uVar12 = (ulonglong)uVar5;

    } while ((int)uVar5 < (int)(uVar4 + iVar13));

    if (uVar5 == uVar4 + iVar13) {

      iVar9 = FUN_1400f03f0((longlong)param_1 + 0x34,auStack_a09 + 1,uVar4);

      if (iVar9 != 0) {

        iVar9 = FUN_1400f03f0(param_1 + 0x103,auStack_a09 + (ulonglong)uVar4 + 1,iVar13);

        return iVar9 != 0;

      }

    }

    else {

      _DAT_1403f4c40 = "bad codelengths";

    }

  }

  return false;

}




