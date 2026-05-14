// Address: 0x14028e800
// Ghidra name: FUN_14028e800
// ============ 0x14028e800 FUN_14028e800 (size=409) ============


void FUN_14028e800(longlong param_1)



{

  byte bVar1;

  longlong lVar2;

  int iVar3;

  uint uVar4;

  ulonglong uVar5;

  int iVar6;

  uint uVar7;

  ulonglong uVar8;

  int iVar9;

  int iVar10;

  byte *pbVar11;

  int iVar12;

  undefined2 *puVar13;

  

  iVar12 = *(int *)(param_1 + 0x20);

  iVar10 = *(int *)(param_1 + 0x3c);

  iVar9 = *(int *)(param_1 + 0x38) + iVar12;

  pbVar11 = *(byte **)(param_1 + 8);

  puVar13 = *(undefined2 **)(param_1 + 0x30);

  lVar2 = *(longlong *)(param_1 + 0x68);

  iVar3 = *(int *)(param_1 + 0x44) / 2;

  iVar6 = (*(int *)(param_1 + 0x1c) - (iVar9 + 1) / 2) + iVar9;

  if (iVar10 != 0) {

    if ((**(uint **)(param_1 + 0x48) & 0xf00000) == 0x100000) {

      do {

        iVar10 = iVar10 + -1;

        uVar8 = 0;

        uVar7 = 0;

        if (0 < iVar12) {

          do {

            bVar1 = 0;

            if ((uVar7 & 1) == 0) {

              bVar1 = *pbVar11;

              pbVar11 = pbVar11 + 1;

            }

            uVar8 = (ulonglong)(bVar1 >> 4);

            uVar7 = uVar7 + 1;

          } while ((int)uVar7 < iVar12);

          iVar12 = *(int *)(param_1 + 0x20);

        }

        if ((int)uVar7 < iVar9) {

          do {

            if ((uVar7 & 1) == 0) {

              uVar8 = (ulonglong)*pbVar11;

              pbVar11 = pbVar11 + 1;

            }

            uVar7 = uVar7 + 1;

            uVar4 = (uint)uVar8;

            uVar8 = uVar8 >> 4;

            *puVar13 = *(undefined2 *)(lVar2 + (ulonglong)(uVar4 & 0xf) * 2);

            puVar13 = puVar13 + 1;

          } while ((int)uVar7 < iVar9);

          iVar12 = *(int *)(param_1 + 0x20);

        }

        pbVar11 = pbVar11 + iVar6;

        puVar13 = puVar13 + iVar3;

      } while (iVar10 != 0);

    }

    else {

      do {

        iVar10 = iVar10 + -1;

        uVar8 = 0;

        uVar7 = 0;

        if (0 < iVar12) {

          do {

            bVar1 = 0;

            if ((uVar7 & 1) == 0) {

              bVar1 = *pbVar11;

              pbVar11 = pbVar11 + 1;

            }

            uVar8 = (ulonglong)(byte)(bVar1 << 4);

            uVar7 = uVar7 + 1;

          } while ((int)uVar7 < iVar12);

          iVar12 = *(int *)(param_1 + 0x20);

        }

        if ((int)uVar7 < iVar9) {

          do {

            if ((uVar7 & 1) == 0) {

              uVar8 = (ulonglong)*pbVar11;

              pbVar11 = pbVar11 + 1;

            }

            uVar7 = uVar7 + 1;

            uVar5 = uVar8 >> 4;

            uVar8 = (ulonglong)(byte)((char)uVar8 << 4);

            *puVar13 = *(undefined2 *)(lVar2 + uVar5 * 2);

            puVar13 = puVar13 + 1;

          } while ((int)uVar7 < iVar9);

          iVar12 = *(int *)(param_1 + 0x20);

        }

        pbVar11 = pbVar11 + iVar6;

        puVar13 = puVar13 + iVar3;

      } while (iVar10 != 0);

    }

  }

  return;

}




