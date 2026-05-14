// Address: 0x14028cff0
// Ghidra name: FUN_14028cff0
// ============ 0x14028cff0 FUN_14028cff0 (size=435) ============


void FUN_14028cff0(longlong param_1)



{

  uint uVar1;

  longlong lVar2;

  int iVar3;

  uint uVar4;

  int iVar5;

  int iVar6;

  byte *pbVar7;

  byte bVar8;

  int iVar9;

  undefined4 *puVar10;

  int iVar11;

  

  iVar11 = *(int *)(param_1 + 0x20);

  iVar5 = *(int *)(param_1 + 0x38) + iVar11;

  iVar6 = *(int *)(param_1 + 0x3c);

  pbVar7 = *(byte **)(param_1 + 8);

  puVar10 = *(undefined4 **)(param_1 + 0x30);

  uVar1 = *(uint *)(param_1 + 0x7c);

  lVar2 = *(longlong *)(param_1 + 0x68);

  iVar9 = (*(int *)(param_1 + 0x1c) - ((int)(iVar5 + 7 + (iVar5 + 7 >> 0x1f & 7U)) >> 3)) + iVar5;

  iVar3 = (int)(*(int *)(param_1 + 0x44) + (*(int *)(param_1 + 0x44) >> 0x1f & 3U)) >> 2;

  if (iVar6 != 0) {

    if ((**(uint **)(param_1 + 0x48) & 0xf00000) == 0x100000) {

      do {

        iVar6 = iVar6 + -1;

        bVar8 = 0;

        uVar4 = 0;

        if (0 < iVar11) {

          do {

            if ((uVar4 & 7) == 0) {

              bVar8 = *pbVar7;

              pbVar7 = pbVar7 + 1;

            }

            bVar8 = bVar8 >> 1;

            uVar4 = uVar4 + 1;

          } while ((int)uVar4 < iVar11);

          iVar11 = *(int *)(param_1 + 0x20);

        }

        if ((int)uVar4 < iVar5) {

          do {

            if ((uVar4 & 7) == 0) {

              bVar8 = *pbVar7;

              pbVar7 = pbVar7 + 1;

            }

            if ((bVar8 & 1) != uVar1) {

              *puVar10 = *(undefined4 *)(lVar2 + (ulonglong)(bVar8 & 1) * 4);

            }

            bVar8 = bVar8 >> 1;

            puVar10 = puVar10 + 1;

            uVar4 = uVar4 + 1;

          } while ((int)uVar4 < iVar5);

          iVar11 = *(int *)(param_1 + 0x20);

        }

        pbVar7 = pbVar7 + iVar9;

        puVar10 = puVar10 + iVar3;

      } while (iVar6 != 0);

    }

    else {

      do {

        iVar6 = iVar6 + -1;

        bVar8 = 0;

        uVar4 = 0;

        if (0 < iVar11) {

          do {

            if ((uVar4 & 7) == 0) {

              bVar8 = *pbVar7;

              pbVar7 = pbVar7 + 1;

            }

            bVar8 = bVar8 * '\x02';

            uVar4 = uVar4 + 1;

          } while ((int)uVar4 < iVar11);

          iVar11 = *(int *)(param_1 + 0x20);

        }

        if ((int)uVar4 < iVar5) {

          do {

            if ((uVar4 & 7) == 0) {

              bVar8 = *pbVar7;

              pbVar7 = pbVar7 + 1;

            }

            if (bVar8 >> 7 != uVar1) {

              *puVar10 = *(undefined4 *)(lVar2 + (ulonglong)(bVar8 >> 7) * 4);

            }

            bVar8 = bVar8 * '\x02';

            puVar10 = puVar10 + 1;

            uVar4 = uVar4 + 1;

          } while ((int)uVar4 < iVar5);

          iVar11 = *(int *)(param_1 + 0x20);

        }

        pbVar7 = pbVar7 + iVar9;

        puVar10 = puVar10 + iVar3;

      } while (iVar6 != 0);

    }

  }

  return;

}




