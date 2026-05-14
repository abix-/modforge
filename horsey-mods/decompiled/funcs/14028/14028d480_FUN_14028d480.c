// Address: 0x14028d480
// Ghidra name: FUN_14028d480
// ============ 0x14028d480 FUN_14028d480 (size=761) ============


void FUN_14028d480(longlong param_1)



{

  int iVar1;

  uint uVar2;

  longlong lVar3;

  int iVar4;

  uint uVar5;

  int iVar6;

  byte *pbVar7;

  byte *pbVar8;

  int iVar9;

  byte bVar10;

  int iVar11;

  

  iVar9 = *(int *)(param_1 + 0x20);

  iVar6 = *(int *)(param_1 + 0x38) + iVar9;

  lVar3 = *(longlong *)(param_1 + 0x68);

  iVar11 = *(int *)(param_1 + 0x3c);

  pbVar7 = *(byte **)(param_1 + 8);

  pbVar8 = *(byte **)(param_1 + 0x30);

  iVar1 = *(int *)(param_1 + 0x44);

  uVar2 = *(uint *)(param_1 + 0x7c);

  iVar4 = (*(int *)(param_1 + 0x1c) - ((int)(iVar6 + 3 + (iVar6 + 3 >> 0x1f & 3U)) >> 2)) + iVar6;

  uVar5 = **(uint **)(param_1 + 0x48) & 0xf00000;

  if (lVar3 == 0) {

    if (iVar11 != 0) {

      if (uVar5 == 0x100000) {

        do {

          iVar11 = iVar11 + -1;

          bVar10 = 0;

          uVar5 = 0;

          if (0 < iVar9) {

            do {

              if ((uVar5 & 3) == 0) {

                bVar10 = *pbVar7;

                pbVar7 = pbVar7 + 1;

              }

              bVar10 = bVar10 >> 2;

              uVar5 = uVar5 + 1;

            } while ((int)uVar5 < iVar9);

            iVar9 = *(int *)(param_1 + 0x20);

          }

          if ((int)uVar5 < iVar6) {

            do {

              if ((uVar5 & 3) == 0) {

                bVar10 = *pbVar7;

                pbVar7 = pbVar7 + 1;

              }

              if ((bVar10 & 3) != uVar2) {

                *pbVar8 = bVar10 & 3;

              }

              pbVar8 = pbVar8 + 1;

              bVar10 = bVar10 >> 2;

              uVar5 = uVar5 + 1;

            } while ((int)uVar5 < iVar6);

            iVar9 = *(int *)(param_1 + 0x20);

          }

          pbVar7 = pbVar7 + iVar4;

          pbVar8 = pbVar8 + iVar1;

        } while (iVar11 != 0);

      }

      else {

        do {

          iVar11 = iVar11 + -1;

          bVar10 = 0;

          uVar5 = 0;

          if (0 < iVar9) {

            do {

              if ((uVar5 & 3) == 0) {

                bVar10 = *pbVar7;

                pbVar7 = pbVar7 + 1;

              }

              bVar10 = bVar10 << 2;

              uVar5 = uVar5 + 1;

            } while ((int)uVar5 < iVar9);

            iVar9 = *(int *)(param_1 + 0x20);

          }

          if ((int)uVar5 < iVar6) {

            do {

              if ((uVar5 & 3) == 0) {

                bVar10 = *pbVar7;

                pbVar7 = pbVar7 + 1;

              }

              if (bVar10 >> 6 != uVar2) {

                *pbVar8 = bVar10 >> 6;

              }

              pbVar8 = pbVar8 + 1;

              bVar10 = bVar10 << 2;

              uVar5 = uVar5 + 1;

            } while ((int)uVar5 < iVar6);

            iVar9 = *(int *)(param_1 + 0x20);

          }

          pbVar7 = pbVar7 + iVar4;

          pbVar8 = pbVar8 + iVar1;

        } while (iVar11 != 0);

      }

    }

  }

  else if (iVar11 != 0) {

    if (uVar5 == 0x100000) {

      do {

        iVar11 = iVar11 + -1;

        bVar10 = 0;

        uVar5 = 0;

        if (0 < iVar9) {

          do {

            if ((uVar5 & 3) == 0) {

              bVar10 = *pbVar7;

              pbVar7 = pbVar7 + 1;

            }

            bVar10 = bVar10 >> 2;

            uVar5 = uVar5 + 1;

          } while ((int)uVar5 < iVar9);

          iVar9 = *(int *)(param_1 + 0x20);

        }

        if ((int)uVar5 < iVar6) {

          do {

            if ((uVar5 & 3) == 0) {

              bVar10 = *pbVar7;

              pbVar7 = pbVar7 + 1;

            }

            if ((bVar10 & 3) != uVar2) {

              *pbVar8 = *(byte *)((ulonglong)(bVar10 & 3) + lVar3);

            }

            pbVar8 = pbVar8 + 1;

            bVar10 = bVar10 >> 2;

            uVar5 = uVar5 + 1;

          } while ((int)uVar5 < iVar6);

          iVar9 = *(int *)(param_1 + 0x20);

        }

        pbVar7 = pbVar7 + iVar4;

        pbVar8 = pbVar8 + iVar1;

      } while (iVar11 != 0);

    }

    else {

      do {

        iVar11 = iVar11 + -1;

        bVar10 = 0;

        uVar5 = 0;

        if (0 < iVar9) {

          do {

            if ((uVar5 & 3) == 0) {

              bVar10 = *pbVar7;

              pbVar7 = pbVar7 + 1;

            }

            bVar10 = bVar10 << 2;

            uVar5 = uVar5 + 1;

          } while ((int)uVar5 < iVar9);

          iVar9 = *(int *)(param_1 + 0x20);

        }

        if ((int)uVar5 < iVar6) {

          do {

            if ((uVar5 & 3) == 0) {

              bVar10 = *pbVar7;

              pbVar7 = pbVar7 + 1;

            }

            if (bVar10 >> 6 != uVar2) {

              *pbVar8 = *(byte *)((ulonglong)(bVar10 >> 6) + lVar3);

            }

            pbVar8 = pbVar8 + 1;

            bVar10 = bVar10 << 2;

            uVar5 = uVar5 + 1;

          } while ((int)uVar5 < iVar6);

          iVar9 = *(int *)(param_1 + 0x20);

        }

        pbVar7 = pbVar7 + iVar4;

        pbVar8 = pbVar8 + iVar1;

      } while (iVar11 != 0);

    }

  }

  return;

}




