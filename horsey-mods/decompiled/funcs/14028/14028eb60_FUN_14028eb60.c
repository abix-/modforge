// Address: 0x14028eb60
// Ghidra name: FUN_14028eb60
// ============ 0x14028eb60 FUN_14028eb60 (size=459) ============


void FUN_14028eb60(longlong param_1)



{

  byte bVar1;

  int iVar2;

  longlong lVar3;

  uint uVar4;

  int iVar5;

  uint uVar6;

  int iVar7;

  int iVar8;

  byte *pbVar9;

  uint uVar10;

  ulonglong uVar11;

  int iVar12;

  undefined1 *puVar13;

  

  iVar12 = *(int *)(param_1 + 0x20);

  iVar8 = *(int *)(param_1 + 0x38) + iVar12;

  iVar7 = *(int *)(param_1 + 0x3c);

  pbVar9 = *(byte **)(param_1 + 8);

  puVar13 = *(undefined1 **)(param_1 + 0x30);

  lVar3 = *(longlong *)(param_1 + 0x68);

  iVar5 = (*(int *)(param_1 + 0x1c) - (iVar8 + 1) / 2) + iVar8;

  if (iVar7 != 0) {

    iVar2 = *(int *)(param_1 + 0x44);

    if ((**(uint **)(param_1 + 0x48) & 0xf00000) == 0x100000) {

      do {

        iVar7 = iVar7 + -1;

        uVar11 = 0;

        uVar6 = 0;

        if (0 < iVar12) {

          do {

            bVar1 = 0;

            if ((uVar6 & 1) == 0) {

              bVar1 = *pbVar9;

              pbVar9 = pbVar9 + 1;

            }

            uVar11 = (ulonglong)(bVar1 >> 4);

            uVar6 = uVar6 + 1;

          } while ((int)uVar6 < iVar12);

          iVar12 = *(int *)(param_1 + 0x20);

        }

        if ((int)uVar6 < iVar8) {

          do {

            if ((uVar6 & 1) == 0) {

              uVar11 = (ulonglong)*pbVar9;

              pbVar9 = pbVar9 + 1;

            }

            uVar6 = uVar6 + 1;

            uVar10 = (uint)uVar11;

            uVar4 = (uVar10 & 0xf) << 2;

            *puVar13 = *(undefined1 *)((ulonglong)uVar4 + lVar3);

            puVar13[1] = *(undefined1 *)((ulonglong)uVar4 + 1 + lVar3);

            uVar11 = uVar11 >> 4;

            puVar13[2] = *(undefined1 *)(lVar3 + 2 + (ulonglong)(uVar10 & 0xf) * 4);

            puVar13 = puVar13 + 3;

          } while ((int)uVar6 < iVar8);

          iVar12 = *(int *)(param_1 + 0x20);

        }

        pbVar9 = pbVar9 + iVar5;

        puVar13 = puVar13 + iVar2;

      } while (iVar7 != 0);

    }

    else {

      do {

        iVar7 = iVar7 + -1;

        uVar11 = 0;

        uVar6 = 0;

        if (0 < iVar12) {

          do {

            bVar1 = 0;

            if ((uVar6 & 1) == 0) {

              bVar1 = *pbVar9;

              pbVar9 = pbVar9 + 1;

            }

            uVar11 = (ulonglong)(byte)(bVar1 << 4);

            uVar6 = uVar6 + 1;

          } while ((int)uVar6 < iVar12);

          iVar12 = *(int *)(param_1 + 0x20);

        }

        if ((int)uVar6 < iVar8) {

          do {

            if ((uVar6 & 1) == 0) {

              uVar11 = (ulonglong)*pbVar9;

              pbVar9 = pbVar9 + 1;

            }

            uVar6 = uVar6 + 1;

            uVar4 = (int)(uVar11 >> 4) << 2;

            uVar11 = (ulonglong)(byte)((char)uVar11 << 4);

            *puVar13 = *(undefined1 *)((ulonglong)uVar4 + lVar3);

            puVar13[1] = *(undefined1 *)((ulonglong)uVar4 + 1 + lVar3);

            puVar13[2] = *(undefined1 *)((ulonglong)uVar4 + 2 + lVar3);

            puVar13 = puVar13 + 3;

          } while ((int)uVar6 < iVar8);

          iVar12 = *(int *)(param_1 + 0x20);

        }

        pbVar9 = pbVar9 + iVar5;

        puVar13 = puVar13 + iVar2;

      } while (iVar7 != 0);

    }

  }

  return;

}




