// Address: 0x14028deb0
// Ghidra name: FUN_14028deb0
// ============ 0x14028deb0 FUN_14028deb0 (size=425) ============


void FUN_14028deb0(longlong param_1)



{

  longlong lVar1;

  int iVar2;

  uint uVar3;

  ulonglong uVar4;

  int iVar5;

  uint uVar6;

  byte bVar7;

  ulonglong uVar8;

  int iVar9;

  int iVar10;

  byte *pbVar11;

  int iVar12;

  undefined4 *puVar13;

  

  iVar12 = *(int *)(param_1 + 0x20);

  iVar10 = *(int *)(param_1 + 0x3c);

  pbVar11 = *(byte **)(param_1 + 8);

  iVar9 = *(int *)(param_1 + 0x38) + iVar12;

  puVar13 = *(undefined4 **)(param_1 + 0x30);

  lVar1 = *(longlong *)(param_1 + 0x68);

  iVar2 = (int)(*(int *)(param_1 + 0x44) + (*(int *)(param_1 + 0x44) >> 0x1f & 3U)) >> 2;

  iVar5 = (*(int *)(param_1 + 0x1c) - ((int)(iVar9 + 3 + (iVar9 + 3 >> 0x1f & 3U)) >> 2)) + iVar9;

  if (iVar10 != 0) {

    if ((**(uint **)(param_1 + 0x48) & 0xf00000) == 0x100000) {

      do {

        iVar10 = iVar10 + -1;

        uVar8 = 0;

        uVar6 = 0;

        if (0 < iVar12) {

          do {

            bVar7 = (byte)uVar8;

            if ((uVar6 & 3) == 0) {

              bVar7 = *pbVar11;

              pbVar11 = pbVar11 + 1;

            }

            uVar8 = (ulonglong)(bVar7 >> 2);

            uVar6 = uVar6 + 1;

          } while ((int)uVar6 < iVar12);

          iVar12 = *(int *)(param_1 + 0x20);

        }

        if ((int)uVar6 < iVar9) {

          do {

            if ((uVar6 & 3) == 0) {

              uVar8 = (ulonglong)*pbVar11;

              pbVar11 = pbVar11 + 1;

            }

            uVar6 = uVar6 + 1;

            uVar3 = (uint)uVar8;

            uVar8 = uVar8 >> 2;

            *puVar13 = *(undefined4 *)(lVar1 + (ulonglong)(uVar3 & 3) * 4);

            puVar13 = puVar13 + 1;

          } while ((int)uVar6 < iVar9);

          iVar12 = *(int *)(param_1 + 0x20);

        }

        pbVar11 = pbVar11 + iVar5;

        puVar13 = puVar13 + iVar2;

      } while (iVar10 != 0);

    }

    else {

      do {

        iVar10 = iVar10 + -1;

        uVar8 = 0;

        uVar6 = 0;

        if (0 < iVar12) {

          do {

            bVar7 = (byte)uVar8;

            if ((uVar6 & 3) == 0) {

              bVar7 = *pbVar11;

              pbVar11 = pbVar11 + 1;

            }

            uVar8 = (ulonglong)(byte)(bVar7 << 2);

            uVar6 = uVar6 + 1;

          } while ((int)uVar6 < iVar12);

          iVar12 = *(int *)(param_1 + 0x20);

        }

        if ((int)uVar6 < iVar9) {

          do {

            if ((uVar6 & 3) == 0) {

              uVar8 = (ulonglong)*pbVar11;

              pbVar11 = pbVar11 + 1;

            }

            uVar6 = uVar6 + 1;

            uVar4 = uVar8 >> 6;

            uVar8 = (ulonglong)(byte)((char)uVar8 << 2);

            *puVar13 = *(undefined4 *)(lVar1 + uVar4 * 4);

            puVar13 = puVar13 + 1;

          } while ((int)uVar6 < iVar9);

          iVar12 = *(int *)(param_1 + 0x20);

        }

        pbVar11 = pbVar11 + iVar5;

        puVar13 = puVar13 + iVar2;

      } while (iVar10 != 0);

    }

  }

  return;

}




