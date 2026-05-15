// Address: 0x1401a1110
// Ghidra name: FUN_1401a1110
// ============ 0x1401a1110 FUN_1401a1110 (size=700) ============


undefined8 FUN_1401a1110(longlong param_1,short *param_2,longlong param_3,int param_4)



{

  uint *puVar1;

  uint uVar2;

  uint uVar3;

  int iVar4;

  undefined8 uVar5;

  ulonglong uVar6;

  byte bVar7;

  uint uVar8;

  int iVar9;

  int iVar10;

  short sVar11;

  uint uVar12;

  

  if (*(int *)(param_1 + 0x4838) != 0) {

    uVar5 = FUN_14019f050("Corrupt JPEG");

    return uVar5;

  }

  if (*(int *)(param_1 + 0x4824) < 0x10) {

    FUN_14019f510();

  }

  if (*(int *)(param_1 + 0x483c) == 0) {

    param_2[0] = 0;

    param_2[1] = 0;

    param_2[2] = 0;

    param_2[3] = 0;

    param_2[4] = 0;

    param_2[5] = 0;

    param_2[6] = 0;

    param_2[7] = 0;

    param_2[8] = 0;

    param_2[9] = 0;

    param_2[10] = 0;

    param_2[0xb] = 0;

    param_2[0xc] = 0;

    param_2[0xd] = 0;

    param_2[0xe] = 0;

    param_2[0xf] = 0;

    param_2[0x10] = 0;

    param_2[0x11] = 0;

    param_2[0x12] = 0;

    param_2[0x13] = 0;

    param_2[0x14] = 0;

    param_2[0x15] = 0;

    param_2[0x16] = 0;

    param_2[0x17] = 0;

    param_2[0x18] = 0;

    param_2[0x19] = 0;

    param_2[0x1a] = 0;

    param_2[0x1b] = 0;

    param_2[0x1c] = 0;

    param_2[0x1d] = 0;

    param_2[0x1e] = 0;

    param_2[0x1f] = 0;

    param_2[0x20] = 0;

    param_2[0x21] = 0;

    param_2[0x22] = 0;

    param_2[0x23] = 0;

    param_2[0x24] = 0;

    param_2[0x25] = 0;

    param_2[0x26] = 0;

    param_2[0x27] = 0;

    param_2[0x28] = 0;

    param_2[0x29] = 0;

    param_2[0x2a] = 0;

    param_2[0x2b] = 0;

    param_2[0x2c] = 0;

    param_2[0x2d] = 0;

    param_2[0x2e] = 0;

    param_2[0x2f] = 0;

    param_2[0x30] = 0;

    param_2[0x31] = 0;

    param_2[0x32] = 0;

    param_2[0x33] = 0;

    param_2[0x34] = 0;

    param_2[0x35] = 0;

    param_2[0x36] = 0;

    param_2[0x37] = 0;

    param_2[0x38] = 0;

    param_2[0x39] = 0;

    param_2[0x3a] = 0;

    param_2[0x3b] = 0;

    param_2[0x3c] = 0;

    param_2[0x3d] = 0;

    param_2[0x3e] = 0;

    param_2[0x3f] = 0;

    if (*(int *)(param_1 + 0x4824) < 0x10) {

      FUN_14019f510(param_1);

    }

    uVar2 = *(uint *)(param_1 + 0x4820);

    bVar7 = *(byte *)((ulonglong)(uVar2 >> 0x17) + param_3);

    uVar6 = (ulonglong)bVar7;

    if (bVar7 == 0xff) {

      puVar1 = (uint *)(param_3 + 0x62c);

      iVar10 = 10;

      uVar12 = *puVar1;

      while (uVar12 <= uVar2 >> 0x10) {

        iVar10 = iVar10 + 1;

        puVar1 = puVar1 + 1;

        uVar12 = *puVar1;

      }

      iVar9 = *(int *)(param_1 + 0x4824);

      if (iVar10 == 0x11) {

        *(int *)(param_1 + 0x4824) = iVar9 + -0x10;

      }

      else if (iVar10 <= iVar9) {

        bVar7 = (byte)iVar10;

        uVar12 = (uVar2 >> (0x20 - bVar7 & 0x1f) & *(uint *)(&DAT_14033b310 + (longlong)iVar10 * 4))

                 + *(int *)(param_3 + 0x64c + (longlong)iVar10 * 4);

        if (uVar12 < 0x100) {

          iVar9 = iVar9 - iVar10;

          uVar6 = (ulonglong)(int)uVar12;

          goto LAB_1401a126e;

        }

      }

    }

    else {

      bVar7 = *(byte *)(uVar6 + 0x500 + param_3);

      if ((int)(uint)bVar7 <= *(int *)(param_1 + 0x4824)) {

        iVar9 = *(int *)(param_1 + 0x4824) - (uint)bVar7;

LAB_1401a126e:

        *(int *)(param_1 + 0x4824) = iVar9;

        *(uint *)(param_1 + 0x4820) = uVar2 << (bVar7 & 0x1f);

        bVar7 = *(byte *)(uVar6 + 0x400 + param_3);

        if (bVar7 < 0x10) {

          if (bVar7 == 0) {

LAB_1401a12fa:

            iVar10 = 0;

          }

          else {

            if (iVar9 < (int)(uint)bVar7) {

              FUN_14019f510(param_1);

            }

            if (*(int *)(param_1 + 0x4824) < (int)(uint)bVar7) goto LAB_1401a12fa;

            uVar2 = *(uint *)(param_1 + 0x4820);

            uVar8 = uVar2 << (bVar7 & 0x1f) | uVar2 >> 0x20 - (bVar7 & 0x1f);

            uVar12 = *(uint *)(&DAT_14033b310 + (ulonglong)bVar7 * 4);

            *(uint *)(param_1 + 0x4824) = *(int *)(param_1 + 0x4824) - (uint)bVar7;

            uVar3 = *(uint *)(&DAT_14033b360 + (ulonglong)bVar7 * 4);

            *(uint *)(param_1 + 0x4820) = ~uVar12 & uVar8;

            iVar10 = (0xffffffffU - ((int)uVar2 >> 0x1f) & uVar3) + (uVar12 & uVar8);

          }

          iVar9 = *(int *)((longlong)param_4 * 0x60 + 0x46b8 + param_1);

          iVar4 = FUN_14019c9d0(iVar9,iVar10);

          if (iVar4 != 0) {

            iVar9 = iVar9 + iVar10;

            sVar11 = (short)iVar9;

            *(int *)((longlong)param_4 * 0x60 + 0x46b8 + param_1) = iVar9;

            bVar7 = (byte)*(undefined4 *)(param_1 + 0x4840);

            iVar10 = FUN_1401a1bf0(iVar9,1 << (bVar7 & 0x1f));

            if (iVar10 != 0) {

              *param_2 = (1 << (bVar7 & 0x1f)) * sVar11;

              goto LAB_1401a13af;

            }

          }

        }

      }

    }

    uVar5 = FUN_14019f050("Corrupt JPEG");

  }

  else {

    if (*(int *)(param_1 + 0x4824) < 1) {

      FUN_14019f510(param_1);

    }

    if (0 < *(int *)(param_1 + 0x4824)) {

      iVar10 = *(int *)(param_1 + 0x4820);

      *(int *)(param_1 + 0x4820) = iVar10 * 2;

      *(int *)(param_1 + 0x4824) = *(int *)(param_1 + 0x4824) + -1;

      if (iVar10 < 0) {

        *param_2 = *param_2 + (1 << ((byte)*(undefined4 *)(param_1 + 0x4840) & 0x1f));

      }

    }

LAB_1401a13af:

    uVar5 = 1;

  }

  return uVar5;

}




