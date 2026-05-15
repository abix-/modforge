// Address: 0x14028ca90
// Ghidra name: FUN_14028ca90
// ============ 0x14028ca90 FUN_14028ca90 (size=457) ============


void FUN_14028ca90(longlong param_1)



{

  int iVar1;

  longlong lVar2;

  ulonglong uVar3;

  uint uVar4;

  int iVar5;

  uint uVar6;

  int iVar7;

  int iVar8;

  byte *pbVar9;

  byte bVar10;

  uint uVar11;

  ulonglong uVar12;

  int iVar13;

  undefined1 *puVar14;

  

  iVar13 = *(int *)(param_1 + 0x20);

  iVar8 = *(int *)(param_1 + 0x38) + iVar13;

  iVar7 = *(int *)(param_1 + 0x3c);

  pbVar9 = *(byte **)(param_1 + 8);

  puVar14 = *(undefined1 **)(param_1 + 0x30);

  lVar2 = *(longlong *)(param_1 + 0x68);

  iVar5 = (*(int *)(param_1 + 0x1c) - ((int)(iVar8 + 7 + (iVar8 + 7 >> 0x1f & 7U)) >> 3)) + iVar8;

  if (iVar7 != 0) {

    iVar1 = *(int *)(param_1 + 0x44);

    if ((**(uint **)(param_1 + 0x48) & 0xf00000) == 0x100000) {

      do {

        iVar7 = iVar7 + -1;

        uVar12 = 0;

        uVar6 = 0;

        if (0 < iVar13) {

          do {

            bVar10 = (byte)uVar12;

            if ((uVar6 & 7) == 0) {

              bVar10 = *pbVar9;

              pbVar9 = pbVar9 + 1;

            }

            uVar12 = (ulonglong)(bVar10 >> 1);

            uVar6 = uVar6 + 1;

          } while ((int)uVar6 < iVar13);

          iVar13 = *(int *)(param_1 + 0x20);

        }

        if ((int)uVar6 < iVar8) {

          do {

            if ((uVar6 & 7) == 0) {

              uVar12 = (ulonglong)*pbVar9;

              pbVar9 = pbVar9 + 1;

            }

            uVar6 = uVar6 + 1;

            uVar11 = (uint)uVar12;

            uVar4 = (uVar11 & 1) << 2;

            *puVar14 = *(undefined1 *)((ulonglong)uVar4 + lVar2);

            puVar14[1] = *(undefined1 *)((ulonglong)uVar4 + 1 + lVar2);

            uVar12 = uVar12 >> 1;

            puVar14[2] = *(undefined1 *)(lVar2 + 2 + (ulonglong)(uVar11 & 1) * 4);

            puVar14 = puVar14 + 3;

          } while ((int)uVar6 < iVar8);

          iVar13 = *(int *)(param_1 + 0x20);

        }

        pbVar9 = pbVar9 + iVar5;

        puVar14 = puVar14 + iVar1;

      } while (iVar7 != 0);

    }

    else {

      do {

        iVar7 = iVar7 + -1;

        uVar12 = 0;

        uVar6 = 0;

        if (0 < iVar13) {

          do {

            bVar10 = (byte)uVar12;

            if ((uVar6 & 7) == 0) {

              bVar10 = *pbVar9;

              pbVar9 = pbVar9 + 1;

            }

            uVar12 = (ulonglong)(byte)(bVar10 * '\x02');

            uVar6 = uVar6 + 1;

          } while ((int)uVar6 < iVar13);

          iVar13 = *(int *)(param_1 + 0x20);

        }

        if ((int)uVar6 < iVar8) {

          do {

            if ((uVar6 & 7) == 0) {

              uVar12 = (ulonglong)*pbVar9;

              pbVar9 = pbVar9 + 1;

            }

            uVar6 = uVar6 + 1;

            uVar3 = uVar12 >> 7;

            uVar12 = (ulonglong)(byte)((char)uVar12 * '\x02');

            uVar4 = (int)uVar3 << 2;

            *puVar14 = *(undefined1 *)((ulonglong)uVar4 + lVar2);

            puVar14[1] = *(undefined1 *)((ulonglong)uVar4 + 1 + lVar2);

            puVar14[2] = *(undefined1 *)((ulonglong)uVar4 + 2 + lVar2);

            puVar14 = puVar14 + 3;

          } while ((int)uVar6 < iVar8);

          iVar13 = *(int *)(param_1 + 0x20);

        }

        pbVar9 = pbVar9 + iVar5;

        puVar14 = puVar14 + iVar1;

      } while (iVar7 != 0);

    }

  }

  return;

}




