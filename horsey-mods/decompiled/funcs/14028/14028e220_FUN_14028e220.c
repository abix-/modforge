// Address: 0x14028e220
// Ghidra name: FUN_14028e220
// ============ 0x14028e220 FUN_14028e220 (size=706) ============


void FUN_14028e220(longlong param_1)



{

  int iVar1;

  longlong lVar2;

  byte bVar3;

  uint uVar4;

  ulonglong uVar5;

  int iVar6;

  byte bVar7;

  uint uVar8;

  ulonglong uVar9;

  int iVar10;

  int iVar11;

  byte *pbVar12;

  int iVar13;

  byte *pbVar14;

  

  iVar13 = *(int *)(param_1 + 0x20);

  iVar10 = *(int *)(param_1 + 0x38) + iVar13;

  lVar2 = *(longlong *)(param_1 + 0x68);

  iVar11 = *(int *)(param_1 + 0x3c);

  pbVar12 = *(byte **)(param_1 + 8);

  pbVar14 = *(byte **)(param_1 + 0x30);

  iVar1 = *(int *)(param_1 + 0x44);

  iVar6 = (*(int *)(param_1 + 0x1c) - (iVar10 + 1) / 2) + iVar10;

  uVar8 = **(uint **)(param_1 + 0x48) & 0xf00000;

  if (lVar2 == 0) {

    if (iVar11 != 0) {

      if (uVar8 == 0x100000) {

        do {

          iVar11 = iVar11 + -1;

          bVar7 = 0;

          uVar8 = 0;

          if (0 < iVar13) {

            do {

              bVar7 = 0;

              if ((uVar8 & 1) == 0) {

                bVar7 = *pbVar12;

                pbVar12 = pbVar12 + 1;

              }

              bVar7 = bVar7 >> 4;

              uVar8 = uVar8 + 1;

            } while ((int)uVar8 < iVar13);

            iVar13 = *(int *)(param_1 + 0x20);

          }

          if ((int)uVar8 < iVar10) {

            do {

              if ((uVar8 & 1) == 0) {

                bVar7 = *pbVar12;

                pbVar12 = pbVar12 + 1;

              }

              uVar8 = uVar8 + 1;

              bVar3 = bVar7 & 0xf;

              bVar7 = bVar7 >> 4;

              *pbVar14 = bVar3;

              pbVar14 = pbVar14 + 1;

            } while ((int)uVar8 < iVar10);

            iVar13 = *(int *)(param_1 + 0x20);

          }

          pbVar12 = pbVar12 + iVar6;

          pbVar14 = pbVar14 + iVar1;

        } while (iVar11 != 0);

      }

      else {

        do {

          iVar11 = iVar11 + -1;

          bVar7 = 0;

          uVar8 = 0;

          if (0 < iVar13) {

            do {

              bVar7 = 0;

              if ((uVar8 & 1) == 0) {

                bVar7 = *pbVar12;

                pbVar12 = pbVar12 + 1;

              }

              bVar7 = bVar7 << 4;

              uVar8 = uVar8 + 1;

            } while ((int)uVar8 < iVar13);

            iVar13 = *(int *)(param_1 + 0x20);

          }

          if ((int)uVar8 < iVar10) {

            do {

              if ((uVar8 & 1) == 0) {

                bVar7 = *pbVar12;

                pbVar12 = pbVar12 + 1;

              }

              uVar8 = uVar8 + 1;

              *pbVar14 = bVar7 >> 4;

              pbVar14 = pbVar14 + 1;

              bVar7 = bVar7 << 4;

            } while ((int)uVar8 < iVar10);

            iVar13 = *(int *)(param_1 + 0x20);

          }

          pbVar12 = pbVar12 + iVar6;

          pbVar14 = pbVar14 + iVar1;

        } while (iVar11 != 0);

      }

    }

  }

  else if (iVar11 != 0) {

    if (uVar8 == 0x100000) {

      do {

        iVar11 = iVar11 + -1;

        uVar9 = 0;

        uVar8 = 0;

        if (0 < iVar13) {

          do {

            bVar7 = 0;

            if ((uVar8 & 1) == 0) {

              bVar7 = *pbVar12;

              pbVar12 = pbVar12 + 1;

            }

            uVar9 = (ulonglong)(bVar7 >> 4);

            uVar8 = uVar8 + 1;

          } while ((int)uVar8 < iVar13);

          iVar13 = *(int *)(param_1 + 0x20);

        }

        if ((int)uVar8 < iVar10) {

          do {

            if ((uVar8 & 1) == 0) {

              uVar9 = (ulonglong)*pbVar12;

              pbVar12 = pbVar12 + 1;

            }

            uVar8 = uVar8 + 1;

            uVar4 = (uint)uVar9;

            uVar9 = uVar9 >> 4;

            *pbVar14 = *(byte *)((ulonglong)(uVar4 & 0xf) + lVar2);

            pbVar14 = pbVar14 + 1;

          } while ((int)uVar8 < iVar10);

          iVar13 = *(int *)(param_1 + 0x20);

        }

        pbVar12 = pbVar12 + iVar6;

        pbVar14 = pbVar14 + iVar1;

      } while (iVar11 != 0);

    }

    else {

      do {

        iVar11 = iVar11 + -1;

        uVar9 = 0;

        uVar8 = 0;

        if (0 < iVar13) {

          do {

            bVar7 = 0;

            if ((uVar8 & 1) == 0) {

              bVar7 = *pbVar12;

              pbVar12 = pbVar12 + 1;

            }

            uVar9 = (ulonglong)(byte)(bVar7 << 4);

            uVar8 = uVar8 + 1;

          } while ((int)uVar8 < iVar13);

          iVar13 = *(int *)(param_1 + 0x20);

        }

        if ((int)uVar8 < iVar10) {

          do {

            if ((uVar8 & 1) == 0) {

              uVar9 = (ulonglong)*pbVar12;

              pbVar12 = pbVar12 + 1;

            }

            uVar8 = uVar8 + 1;

            uVar5 = uVar9 >> 4;

            uVar9 = (ulonglong)(byte)((char)uVar9 << 4);

            *pbVar14 = *(byte *)(uVar5 + lVar2);

            pbVar14 = pbVar14 + 1;

          } while ((int)uVar8 < iVar10);

          iVar13 = *(int *)(param_1 + 0x20);

        }

        pbVar12 = pbVar12 + iVar6;

        pbVar14 = pbVar14 + iVar1;

      } while (iVar11 != 0);

    }

  }

  return;

}




