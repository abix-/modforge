// Address: 0x14019cde0
// Ghidra name: FUN_14019cde0
// ============ 0x14019cde0 FUN_14019cde0 (size=731) ============


ulonglong FUN_14019cde0(ulonglong *param_1)



{

  uint uVar1;

  ushort uVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  uint uVar5;

  int iVar6;

  uint uVar7;

  ulonglong uVar8;

  int iVar9;

  ulonglong uVar10;

  ulonglong uVar11;

  int iVar12;

  byte local_9f8 [31];

  byte abStack_9d9 [465];

  ushort local_808 [1016];

  

  if ((int)param_1[2] < 5) {

    FUN_14019f170();

  }

  uVar4 = param_1[3];

  *(int *)(param_1 + 2) = (int)param_1[2] + -5;

  *(uint *)(param_1 + 3) = (uint)uVar4 >> 5;

  uVar1 = ((uint)uVar4 & 0x1f) + 0x101;

  if ((int)param_1[2] < 5) {

    FUN_14019f170(param_1);

  }

  *(int *)(param_1 + 2) = (int)param_1[2] + -5;

  iVar12 = ((uint)param_1[3] & 0x1f) + 1;

  *(uint *)(param_1 + 3) = (uint)param_1[3] >> 5;

  if ((int)param_1[2] < 4) {

    FUN_14019f170(param_1);

  }

  uVar4 = param_1[3];

  uVar7 = uVar1 + iVar12;

  iVar6 = (int)param_1[2] + -4;

  *(uint *)(param_1 + 3) = (uint)uVar4 >> 4;

  uVar8 = 0;

  *(int *)(param_1 + 2) = iVar6;

  uVar5 = ((uint)uVar4 & 0xf) + 4;

  local_9f8[0x10] = 0;

  local_9f8[0x11] = 0;

  uVar11 = (ulonglong)uVar5;

  local_9f8[0] = 0;

  local_9f8[1] = 0;

  local_9f8[2] = 0;

  local_9f8[3] = 0;

  local_9f8[4] = 0;

  local_9f8[5] = 0;

  local_9f8[6] = 0;

  local_9f8[7] = 0;

  local_9f8[8] = 0;

  local_9f8[9] = 0;

  local_9f8[10] = 0;

  local_9f8[0xb] = 0;

  local_9f8[0xc] = 0;

  local_9f8[0xd] = 0;

  local_9f8[0xe] = 0;

  local_9f8[0xf] = 0;

  local_9f8[0x12] = 0;

  uVar4 = uVar8;

  if (uVar5 != 0) {

    do {

      if (iVar6 < 3) {

        FUN_14019f170(param_1);

      }

      uVar3 = param_1[3];

      *(int *)(param_1 + 2) = (int)param_1[2] + -3;

      iVar6 = (int)param_1[2];

      *(uint *)(param_1 + 3) = (uint)uVar3 >> 3;

      uVar10 = uVar4 + 1;

      local_9f8[(byte)(&DAT_14033b5f0)[uVar4]] = (byte)(uint)uVar3 & 7;

      uVar4 = uVar10;

    } while ((longlong)uVar10 < (longlong)uVar11);

  }

  iVar6 = FUN_1401a4e00(local_808,local_9f8,0x13);

  if (iVar6 != 0) {

    do {

      if ((int)param_1[2] < 0x10) {

        if (*param_1 < param_1[1]) {

          FUN_14019f170(param_1);

        }

        else {

          if (*(int *)((longlong)param_1 + 0x14) != 0) goto LAB_14019d081;

          *(undefined4 *)((longlong)param_1 + 0x14) = 1;

          *(int *)(param_1 + 2) = (int)param_1[2] + 0x10;

        }

      }

      uVar2 = local_808[(uint)param_1[3] & 0x1ff];

      if (uVar2 == 0) {

        uVar5 = FUN_1401a5120(param_1,local_808);

      }

      else {

        *(uint *)(param_1 + 2) = (int)param_1[2] - (uint)(uVar2 >> 9);

        *(uint *)(param_1 + 3) = (uint)param_1[3] >> ((byte)(uVar2 >> 9) & 0x1f);

        uVar5 = uVar2 & 0x1ff;

      }

      if (0x12 < uVar5) goto LAB_14019d081;

      iVar6 = (int)uVar8;

      if ((int)uVar5 < 0x10) {

        iVar9 = 1;

        abStack_9d9[(longlong)iVar6 + 1] = (byte)uVar5;

      }

      else {

        uVar4 = 0;

        if (uVar5 == 0x10) {

          if ((int)param_1[2] < 2) {

            FUN_14019f170(param_1);

          }

          *(int *)(param_1 + 2) = (int)param_1[2] + -2;

          iVar9 = ((uint)param_1[3] & 3) + 3;

          *(uint *)(param_1 + 3) = (uint)param_1[3] >> 2;

          if (iVar6 == 0) goto LAB_14019d081;

          uVar4 = (ulonglong)abStack_9d9[iVar6];

        }

        else {

          if (uVar5 == 0x11) {

            if ((int)param_1[2] < 3) {

              FUN_14019f170(param_1);

            }

            *(int *)(param_1 + 2) = (int)param_1[2] + -3;

            uVar5 = (uint)param_1[3] >> 3;

            iVar9 = ((uint)param_1[3] & 7) + 3;

          }

          else {

            if (uVar5 != 0x12) goto LAB_14019d081;

            if ((int)param_1[2] < 7) {

              FUN_14019f170(param_1);

            }

            *(int *)(param_1 + 2) = (int)param_1[2] + -7;

            uVar5 = (uint)param_1[3] >> 7;

            iVar9 = ((uint)param_1[3] & 0x7f) + 0xb;

          }

          *(uint *)(param_1 + 3) = uVar5;

        }

        if ((int)(uVar7 - iVar6) < iVar9) goto LAB_14019d081;

        FUN_1402f94c0(abStack_9d9 + (longlong)iVar6 + 1,uVar4 & 0xff,iVar9);

      }

      uVar5 = iVar6 + iVar9;

      uVar8 = (ulonglong)uVar5;

    } while ((int)uVar5 < (int)uVar7);

    if (uVar5 != uVar7) {

LAB_14019d081:

      uVar4 = FUN_14019f050("Corrupt PNG");

      return uVar4;

    }

    iVar6 = FUN_1401a4e00((longlong)param_1 + 0x3c,abStack_9d9 + 1,uVar1);

    if (iVar6 != 0) {

      iVar12 = FUN_1401a4e00(param_1 + 0x104,abStack_9d9 + (ulonglong)uVar1 + 1,iVar12);

      return (ulonglong)(iVar12 != 0);

    }

  }

  return 0;

}




