// Address: 0x14028dce0
// Ghidra name: FUN_14028dce0
// ============ 0x14028dce0 FUN_14028dce0 (size=454) ============


void FUN_14028dce0(longlong param_1)



{

  uint uVar1;

  int iVar2;

  longlong lVar3;

  uint uVar4;

  int iVar5;

  uint uVar6;

  int iVar7;

  int iVar8;

  byte *pbVar9;

  undefined2 *puVar10;

  byte bVar11;

  ulonglong uVar12;

  int iVar13;

  

  iVar13 = *(int *)(param_1 + 0x20);

  iVar7 = *(int *)(param_1 + 0x38) + iVar13;

  iVar8 = *(int *)(param_1 + 0x3c);

  pbVar9 = *(byte **)(param_1 + 8);

  puVar10 = *(undefined2 **)(param_1 + 0x30);

  uVar1 = *(uint *)(param_1 + 0x7c);

  lVar3 = *(longlong *)(param_1 + 0x68);

  iVar5 = (*(int *)(param_1 + 0x1c) - ((int)(iVar7 + 3 + (iVar7 + 3 >> 0x1f & 3U)) >> 2)) + iVar7;

  if (iVar8 != 0) {

    iVar2 = *(int *)(param_1 + 0x44);

    if ((**(uint **)(param_1 + 0x48) & 0xf00000) == 0x100000) {

      do {

        iVar8 = iVar8 + -1;

        uVar12 = 0;

        uVar6 = 0;

        if (0 < iVar13) {

          do {

            bVar11 = (byte)uVar12;

            if ((uVar6 & 3) == 0) {

              bVar11 = *pbVar9;

              pbVar9 = pbVar9 + 1;

            }

            uVar12 = (ulonglong)(bVar11 >> 2);

            uVar6 = uVar6 + 1;

          } while ((int)uVar6 < iVar13);

          iVar13 = *(int *)(param_1 + 0x20);

        }

        if ((int)uVar6 < iVar7) {

          do {

            if ((uVar6 & 3) == 0) {

              uVar12 = (ulonglong)*pbVar9;

              pbVar9 = pbVar9 + 1;

            }

            uVar4 = (uint)uVar12 & 3;

            if (uVar4 != uVar1) {

              uVar4 = uVar4 * 4;

              *puVar10 = *(undefined2 *)((ulonglong)uVar4 + lVar3);

              *(undefined1 *)(puVar10 + 1) = *(undefined1 *)((ulonglong)uVar4 + 2 + lVar3);

            }

            uVar12 = uVar12 >> 2;

            puVar10 = (undefined2 *)((longlong)puVar10 + 3);

            uVar6 = uVar6 + 1;

          } while ((int)uVar6 < iVar7);

          iVar13 = *(int *)(param_1 + 0x20);

        }

        pbVar9 = pbVar9 + iVar5;

        puVar10 = (undefined2 *)((longlong)puVar10 + (longlong)iVar2);

      } while (iVar8 != 0);

    }

    else {

      do {

        iVar8 = iVar8 + -1;

        uVar12 = 0;

        uVar6 = 0;

        if (0 < iVar13) {

          do {

            bVar11 = (byte)uVar12;

            if ((uVar6 & 3) == 0) {

              bVar11 = *pbVar9;

              pbVar9 = pbVar9 + 1;

            }

            uVar12 = (ulonglong)(byte)(bVar11 << 2);

            uVar6 = uVar6 + 1;

          } while ((int)uVar6 < iVar13);

          iVar13 = *(int *)(param_1 + 0x20);

        }

        if ((int)uVar6 < iVar7) {

          do {

            if ((uVar6 & 3) == 0) {

              uVar12 = (ulonglong)*pbVar9;

              pbVar9 = pbVar9 + 1;

            }

            uVar4 = (uint)(uVar12 >> 6);

            if (uVar4 != uVar1) {

              uVar4 = uVar4 * 4;

              *puVar10 = *(undefined2 *)((ulonglong)uVar4 + lVar3);

              *(undefined1 *)(puVar10 + 1) = *(undefined1 *)((ulonglong)uVar4 + 2 + lVar3);

            }

            uVar12 = (ulonglong)(byte)((char)uVar12 << 2);

            puVar10 = (undefined2 *)((longlong)puVar10 + 3);

            uVar6 = uVar6 + 1;

          } while ((int)uVar6 < iVar7);

          iVar13 = *(int *)(param_1 + 0x20);

        }

        pbVar9 = pbVar9 + iVar5;

        puVar10 = (undefined2 *)((longlong)puVar10 + (longlong)iVar2);

      } while (iVar8 != 0);

    }

  }

  return;

}




