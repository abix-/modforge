// Address: 0x14028ed40
// Ghidra name: FUN_14028ed40
// ============ 0x14028ed40 FUN_14028ed40 (size=454) ============


void FUN_14028ed40(longlong param_1)



{

  byte bVar1;

  uint uVar2;

  int iVar3;

  longlong lVar4;

  uint uVar5;

  int iVar6;

  uint uVar7;

  int iVar8;

  int iVar9;

  byte *pbVar10;

  undefined2 *puVar11;

  ulonglong uVar12;

  int iVar13;

  

  iVar13 = *(int *)(param_1 + 0x20);

  iVar8 = *(int *)(param_1 + 0x38) + iVar13;

  iVar9 = *(int *)(param_1 + 0x3c);

  pbVar10 = *(byte **)(param_1 + 8);

  puVar11 = *(undefined2 **)(param_1 + 0x30);

  uVar2 = *(uint *)(param_1 + 0x7c);

  lVar4 = *(longlong *)(param_1 + 0x68);

  iVar6 = (*(int *)(param_1 + 0x1c) - (iVar8 + 1) / 2) + iVar8;

  if (iVar9 != 0) {

    iVar3 = *(int *)(param_1 + 0x44);

    if ((**(uint **)(param_1 + 0x48) & 0xf00000) == 0x100000) {

      do {

        iVar9 = iVar9 + -1;

        uVar12 = 0;

        uVar7 = 0;

        if (0 < iVar13) {

          do {

            bVar1 = 0;

            if ((uVar7 & 1) == 0) {

              bVar1 = *pbVar10;

              pbVar10 = pbVar10 + 1;

            }

            uVar12 = (ulonglong)(bVar1 >> 4);

            uVar7 = uVar7 + 1;

          } while ((int)uVar7 < iVar13);

          iVar13 = *(int *)(param_1 + 0x20);

        }

        if ((int)uVar7 < iVar8) {

          do {

            if ((uVar7 & 1) == 0) {

              uVar12 = (ulonglong)*pbVar10;

              pbVar10 = pbVar10 + 1;

            }

            uVar5 = (uint)uVar12 & 0xf;

            if (uVar5 != uVar2) {

              uVar5 = uVar5 * 4;

              *puVar11 = *(undefined2 *)((ulonglong)uVar5 + lVar4);

              *(undefined1 *)(puVar11 + 1) = *(undefined1 *)((ulonglong)uVar5 + 2 + lVar4);

            }

            uVar12 = uVar12 >> 4;

            puVar11 = (undefined2 *)((longlong)puVar11 + 3);

            uVar7 = uVar7 + 1;

          } while ((int)uVar7 < iVar8);

          iVar13 = *(int *)(param_1 + 0x20);

        }

        pbVar10 = pbVar10 + iVar6;

        puVar11 = (undefined2 *)((longlong)puVar11 + (longlong)iVar3);

      } while (iVar9 != 0);

    }

    else {

      do {

        iVar9 = iVar9 + -1;

        uVar12 = 0;

        uVar7 = 0;

        if (0 < iVar13) {

          do {

            bVar1 = 0;

            if ((uVar7 & 1) == 0) {

              bVar1 = *pbVar10;

              pbVar10 = pbVar10 + 1;

            }

            uVar12 = (ulonglong)(byte)(bVar1 << 4);

            uVar7 = uVar7 + 1;

          } while ((int)uVar7 < iVar13);

          iVar13 = *(int *)(param_1 + 0x20);

        }

        if ((int)uVar7 < iVar8) {

          do {

            if ((uVar7 & 1) == 0) {

              uVar12 = (ulonglong)*pbVar10;

              pbVar10 = pbVar10 + 1;

            }

            uVar5 = (uint)(uVar12 >> 4);

            if (uVar5 != uVar2) {

              uVar5 = uVar5 * 4;

              *puVar11 = *(undefined2 *)((ulonglong)uVar5 + lVar4);

              *(undefined1 *)(puVar11 + 1) = *(undefined1 *)((ulonglong)uVar5 + 2 + lVar4);

            }

            uVar12 = (ulonglong)(byte)((char)uVar12 << 4);

            puVar11 = (undefined2 *)((longlong)puVar11 + 3);

            uVar7 = uVar7 + 1;

          } while ((int)uVar7 < iVar8);

          iVar13 = *(int *)(param_1 + 0x20);

        }

        pbVar10 = pbVar10 + iVar6;

        puVar11 = (undefined2 *)((longlong)puVar11 + (longlong)iVar3);

      } while (iVar9 != 0);

    }

  }

  return;

}




