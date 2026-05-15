// Address: 0x1401a0500
// Ghidra name: FUN_1401a0500
// ============ 0x1401a0500 FUN_1401a0500 (size=1269) ============


undefined8

FUN_1401a0500(longlong param_1,short *param_2,longlong param_3,longlong param_4,longlong param_5,

             int param_6,short *param_7)



{

  uint *puVar1;

  byte bVar2;

  uint uVar3;

  undefined4 uVar4;

  int iVar5;

  undefined8 uVar6;

  ulonglong uVar7;

  uint uVar8;

  char *pcVar9;

  byte bVar10;

  uint uVar11;

  uint uVar12;

  int iVar13;

  short sVar14;

  longlong lVar15;

  int iVar16;

  

  if (*(int *)(param_1 + 0x4824) < 0x10) {

    FUN_14019f510();

  }

  if (*(int *)(param_1 + 0x4824) < 0x10) {

    FUN_14019f510(param_1);

  }

  uVar12 = *(uint *)(param_1 + 0x4820);

  bVar10 = *(byte *)((ulonglong)(uVar12 >> 0x17) + param_3);

  if (bVar10 == 0xff) {

    puVar1 = (uint *)(param_3 + 0x62c);

    iVar16 = 10;

    uVar8 = *puVar1;

    while (uVar8 <= uVar12 >> 0x10) {

      iVar16 = iVar16 + 1;

      puVar1 = puVar1 + 1;

      uVar8 = *puVar1;

    }

    iVar13 = *(int *)(param_1 + 0x4824);

    if (iVar16 == 0x11) {

      *(int *)(param_1 + 0x4824) = iVar13 + -0x10;

      uVar6 = FUN_14019f050("Corrupt JPEG");

      return uVar6;

    }

    if (iVar13 < iVar16) goto LAB_1401a0714;

    uVar8 = (uVar12 >> (0x20 - (byte)iVar16 & 0x1f) &

            *(uint *)(&DAT_14033b310 + (longlong)iVar16 * 4)) +

            *(int *)(param_3 + 0x64c + (longlong)iVar16 * 4);

    if (0xff < uVar8) goto LAB_1401a0714;

    *(int *)(param_1 + 0x4824) = iVar13 - iVar16;

    *(uint *)(param_1 + 0x4820) = uVar12 << ((byte)iVar16 & 0x1f);

    bVar10 = *(byte *)((longlong)(int)uVar8 + 0x400 + param_3);

  }

  else {

    bVar2 = *(byte *)((ulonglong)bVar10 + 0x500 + param_3);

    if (*(int *)(param_1 + 0x4824) < (int)(uint)bVar2) goto LAB_1401a0714;

    *(uint *)(param_1 + 0x4820) = uVar12 << (bVar2 & 0x1f);

    *(uint *)(param_1 + 0x4824) = *(int *)(param_1 + 0x4824) - (uint)bVar2;

    bVar10 = *(byte *)((ulonglong)bVar10 + 0x400 + param_3);

  }

  if (0xf < bVar10) goto LAB_1401a0714;

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

  if (bVar10 == 0) {

LAB_1401a06ed:

    iVar16 = 0;

  }

  else {

    if (*(int *)(param_1 + 0x4824) < (int)(uint)bVar10) {

      FUN_14019f510(param_1);

    }

    if (*(int *)(param_1 + 0x4824) < (int)(uint)bVar10) goto LAB_1401a06ed;

    uVar12 = *(uint *)(param_1 + 0x4820);

    uVar11 = uVar12 << (bVar10 & 0x1f) | uVar12 >> 0x20 - (bVar10 & 0x1f);

    uVar8 = *(uint *)(&DAT_14033b310 + (ulonglong)bVar10 * 4);

    *(uint *)(param_1 + 0x4824) = *(int *)(param_1 + 0x4824) - (uint)bVar10;

    uVar3 = *(uint *)(&DAT_14033b360 + (ulonglong)bVar10 * 4);

    *(uint *)(param_1 + 0x4820) = ~uVar8 & uVar11;

    iVar16 = (0xffffffffU - ((int)uVar12 >> 0x1f) & uVar3) + (uVar8 & uVar11);

  }

  iVar13 = *(int *)((longlong)param_6 * 0x60 + 0x46b8 + param_1);

  iVar5 = FUN_14019c9d0(iVar13,iVar16);

  if (iVar5 != 0) {

    uVar7 = (ulonglong)(uint)(iVar13 + iVar16);

    *(int *)((longlong)param_6 * 0x60 + 0x46b8 + param_1) = iVar13 + iVar16;

    sVar14 = *param_7;

    iVar16 = FUN_1401a1bf0(uVar7,sVar14);

    if (iVar16 == 0) {

      uVar6 = FUN_14019f050("Corrupt JPEG");

    }

    else {

      iVar16 = 1;

      *param_2 = sVar14 * (short)uVar7;

      do {

        if (*(int *)(param_1 + 0x4824) < 0x10) {

          FUN_14019f510(param_1);

        }

        iVar13 = *(int *)(param_1 + 0x4824);

        sVar14 = *(short *)(param_5 + (ulonglong)(*(uint *)(param_1 + 0x4820) >> 0x17) * 2);

        uVar12 = (uint)sVar14;

        if (uVar12 == 0) {

          if (iVar13 < 0x10) {

            FUN_14019f510(param_1);

          }

          uVar12 = *(uint *)(param_1 + 0x4820);

          bVar10 = *(byte *)((ulonglong)(uVar12 >> 0x17) + param_4);

          uVar7 = (ulonglong)bVar10;

          if (bVar10 == 0xff) {

            puVar1 = (uint *)(param_4 + 0x62c);

            iVar13 = 10;

            lVar15 = 10;

            uVar8 = *puVar1;

            while (uVar8 <= uVar12 >> 0x10) {

              iVar13 = iVar13 + 1;

              puVar1 = puVar1 + 1;

              lVar15 = lVar15 + 1;

              uVar8 = *puVar1;

            }

            iVar5 = *(int *)(param_1 + 0x4824);

            if (iVar13 == 0x11) {

              *(int *)(param_1 + 0x4824) = iVar5 + -0x10;

            }

            else if (iVar13 <= iVar5) {

              bVar10 = (byte)iVar13;

              uVar8 = *(int *)(param_4 + 0x64c + lVar15 * 4) +

                      (uVar12 >> (0x20 - bVar10 & 0x1f) & *(uint *)(&DAT_14033b310 + lVar15 * 4));

              if (uVar8 < 0x100) {

                iVar5 = iVar5 - iVar13;

                uVar7 = (ulonglong)(int)uVar8;

                goto LAB_1401a08d1;

              }

            }

          }

          else {

            bVar10 = *(byte *)(uVar7 + 0x500 + param_4);

            if ((int)(uint)bVar10 <= *(int *)(param_1 + 0x4824)) {

              iVar5 = *(int *)(param_1 + 0x4824) - (uint)bVar10;

LAB_1401a08d1:

              *(int *)(param_1 + 0x4824) = iVar5;

              *(uint *)(param_1 + 0x4820) = uVar12 << (bVar10 & 0x1f);

              bVar10 = *(byte *)(uVar7 + 0x400 + param_4);

              uVar12 = bVar10 & 0xf;

              if ((bVar10 & 0xf) != 0) {

                iVar16 = (uint)(bVar10 >> 4) + iVar16;

                bVar10 = (&DAT_14033b3a0)[iVar16];

                if (iVar5 < (int)uVar12) {

                  FUN_14019f510(param_1);

                }

                if (*(int *)(param_1 + 0x4824) < (int)uVar12) {

                  sVar14 = 0;

                }

                else {

                  uVar8 = *(uint *)(param_1 + 0x4820);

                  uVar11 = uVar8 << (sbyte)uVar12 | uVar8 >> 0x20 - (sbyte)uVar12;

                  uVar3 = *(uint *)(&DAT_14033b310 + (ulonglong)uVar12 * 4);

                  uVar4 = *(undefined4 *)(&DAT_14033b360 + (ulonglong)uVar12 * 4);

                  *(uint *)(param_1 + 0x4824) = *(int *)(param_1 + 0x4824) - uVar12;

                  *(uint *)(param_1 + 0x4820) = ~uVar3 & uVar11;

                  sVar14 = (0xffffU - (short)((int)uVar8 >> 0x1f) & (ushort)uVar4) +

                           ((ushort)uVar3 & (ushort)uVar11);

                }

                goto LAB_1401a099e;

              }

              if (bVar10 == 0xf0) {

                iVar16 = iVar16 + 0x10;

                goto LAB_1401a09ab;

              }

              break;

            }

          }

          pcVar9 = "Corrupt JPEG";

LAB_1401a09d5:

          uVar6 = FUN_14019f050(pcVar9);

          return uVar6;

        }

        uVar8 = uVar12 & 0xf;

        iVar16 = iVar16 + ((int)uVar12 >> 4 & 0xfU);

        if (iVar13 < (int)uVar8) {

          pcVar9 = "Combined length longer than code bits available";

          goto LAB_1401a09d5;

        }

        *(uint *)(param_1 + 0x4824) = iVar13 - uVar8;

        bVar10 = (&DAT_14033b3a0)[iVar16];

        *(uint *)(param_1 + 0x4820) = *(uint *)(param_1 + 0x4820) << (sbyte)uVar8;

        sVar14 = (short)(char)((ushort)sVar14 >> 8);

LAB_1401a099e:

        iVar16 = iVar16 + 1;

        param_2[bVar10] = param_7[bVar10] * sVar14;

LAB_1401a09ab:

      } while (iVar16 < 0x40);

      uVar6 = 1;

    }

    return uVar6;

  }

LAB_1401a0714:

  uVar6 = FUN_14019f050("Corrupt JPEG");

  return uVar6;

}




