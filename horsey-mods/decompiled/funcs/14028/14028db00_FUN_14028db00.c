// Address: 0x14028db00
// Ghidra name: FUN_14028db00
// ============ 0x14028db00 FUN_14028db00 (size=459) ============


void FUN_14028db00(longlong param_1)



{

  int iVar1;

  longlong lVar2;

  uint uVar3;

  int iVar4;

  uint uVar5;

  int iVar6;

  int iVar7;

  byte *pbVar8;

  byte bVar9;

  uint uVar10;

  ulonglong uVar11;

  int iVar12;

  undefined1 *puVar13;

  

  iVar12 = *(int *)(param_1 + 0x20);

  iVar7 = *(int *)(param_1 + 0x38) + iVar12;

  iVar6 = *(int *)(param_1 + 0x3c);

  pbVar8 = *(byte **)(param_1 + 8);

  puVar13 = *(undefined1 **)(param_1 + 0x30);

  lVar2 = *(longlong *)(param_1 + 0x68);

  iVar4 = (*(int *)(param_1 + 0x1c) - ((int)(iVar7 + 3 + (iVar7 + 3 >> 0x1f & 3U)) >> 2)) + iVar7;

  if (iVar6 != 0) {

    iVar1 = *(int *)(param_1 + 0x44);

    if ((**(uint **)(param_1 + 0x48) & 0xf00000) == 0x100000) {

      do {

        iVar6 = iVar6 + -1;

        uVar11 = 0;

        uVar5 = 0;

        if (0 < iVar12) {

          do {

            bVar9 = (byte)uVar11;

            if ((uVar5 & 3) == 0) {

              bVar9 = *pbVar8;

              pbVar8 = pbVar8 + 1;

            }

            uVar11 = (ulonglong)(bVar9 >> 2);

            uVar5 = uVar5 + 1;

          } while ((int)uVar5 < iVar12);

          iVar12 = *(int *)(param_1 + 0x20);

        }

        if ((int)uVar5 < iVar7) {

          do {

            if ((uVar5 & 3) == 0) {

              uVar11 = (ulonglong)*pbVar8;

              pbVar8 = pbVar8 + 1;

            }

            uVar5 = uVar5 + 1;

            uVar10 = (uint)uVar11;

            uVar3 = (uVar10 & 3) << 2;

            *puVar13 = *(undefined1 *)((ulonglong)uVar3 + lVar2);

            puVar13[1] = *(undefined1 *)((ulonglong)uVar3 + 1 + lVar2);

            uVar11 = uVar11 >> 2;

            puVar13[2] = *(undefined1 *)(lVar2 + 2 + (ulonglong)(uVar10 & 3) * 4);

            puVar13 = puVar13 + 3;

          } while ((int)uVar5 < iVar7);

          iVar12 = *(int *)(param_1 + 0x20);

        }

        pbVar8 = pbVar8 + iVar4;

        puVar13 = puVar13 + iVar1;

      } while (iVar6 != 0);

    }

    else {

      do {

        iVar6 = iVar6 + -1;

        uVar11 = 0;

        uVar5 = 0;

        if (0 < iVar12) {

          do {

            bVar9 = (byte)uVar11;

            if ((uVar5 & 3) == 0) {

              bVar9 = *pbVar8;

              pbVar8 = pbVar8 + 1;

            }

            uVar11 = (ulonglong)(byte)(bVar9 << 2);

            uVar5 = uVar5 + 1;

          } while ((int)uVar5 < iVar12);

          iVar12 = *(int *)(param_1 + 0x20);

        }

        if ((int)uVar5 < iVar7) {

          do {

            if ((uVar5 & 3) == 0) {

              uVar11 = (ulonglong)*pbVar8;

              pbVar8 = pbVar8 + 1;

            }

            uVar5 = uVar5 + 1;

            uVar3 = (int)(uVar11 >> 6) << 2;

            uVar11 = (ulonglong)(byte)((char)uVar11 << 2);

            *puVar13 = *(undefined1 *)((ulonglong)uVar3 + lVar2);

            puVar13[1] = *(undefined1 *)((ulonglong)uVar3 + 1 + lVar2);

            puVar13[2] = *(undefined1 *)((ulonglong)uVar3 + 2 + lVar2);

            puVar13 = puVar13 + 3;

          } while ((int)uVar5 < iVar7);

          iVar12 = *(int *)(param_1 + 0x20);

        }

        pbVar8 = pbVar8 + iVar4;

        puVar13 = puVar13 + iVar1;

      } while (iVar6 != 0);

    }

  }

  return;

}




