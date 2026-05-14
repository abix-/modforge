// Address: 0x14028c150
// Ghidra name: FUN_14028c150
// ============ 0x14028c150 FUN_14028c150 (size=703) ============


void FUN_14028c150(longlong param_1)



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

  iVar6 = (*(int *)(param_1 + 0x1c) - ((int)(iVar10 + 7 + (iVar10 + 7 >> 0x1f & 7U)) >> 3)) + iVar10

  ;

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

              if ((uVar8 & 7) == 0) {

                bVar7 = *pbVar12;

                pbVar12 = pbVar12 + 1;

              }

              bVar7 = bVar7 >> 1;

              uVar8 = uVar8 + 1;

            } while ((int)uVar8 < iVar13);

            iVar13 = *(int *)(param_1 + 0x20);

          }

          if ((int)uVar8 < iVar10) {

            do {

              if ((uVar8 & 7) == 0) {

                bVar7 = *pbVar12;

                pbVar12 = pbVar12 + 1;

              }

              uVar8 = uVar8 + 1;

              bVar3 = bVar7 & 1;

              bVar7 = bVar7 >> 1;

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

              if ((uVar8 & 7) == 0) {

                bVar7 = *pbVar12;

                pbVar12 = pbVar12 + 1;

              }

              bVar7 = bVar7 * '\x02';

              uVar8 = uVar8 + 1;

            } while ((int)uVar8 < iVar13);

            iVar13 = *(int *)(param_1 + 0x20);

          }

          if ((int)uVar8 < iVar10) {

            do {

              if ((uVar8 & 7) == 0) {

                bVar7 = *pbVar12;

                pbVar12 = pbVar12 + 1;

              }

              uVar8 = uVar8 + 1;

              bVar3 = bVar7 >> 7;

              bVar7 = bVar7 * '\x02';

              *pbVar14 = bVar3;

              pbVar14 = pbVar14 + 1;

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

            bVar7 = (byte)uVar9;

            if ((uVar8 & 7) == 0) {

              bVar7 = *pbVar12;

              pbVar12 = pbVar12 + 1;

            }

            uVar9 = (ulonglong)(bVar7 >> 1);

            uVar8 = uVar8 + 1;

          } while ((int)uVar8 < iVar13);

          iVar13 = *(int *)(param_1 + 0x20);

        }

        if ((int)uVar8 < iVar10) {

          do {

            if ((uVar8 & 7) == 0) {

              uVar9 = (ulonglong)*pbVar12;

              pbVar12 = pbVar12 + 1;

            }

            uVar8 = uVar8 + 1;

            uVar4 = (uint)uVar9;

            uVar9 = uVar9 >> 1;

            *pbVar14 = *(byte *)((ulonglong)(uVar4 & 1) + lVar2);

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

            bVar7 = (byte)uVar9;

            if ((uVar8 & 7) == 0) {

              bVar7 = *pbVar12;

              pbVar12 = pbVar12 + 1;

            }

            uVar9 = (ulonglong)(byte)(bVar7 * '\x02');

            uVar8 = uVar8 + 1;

          } while ((int)uVar8 < iVar13);

          iVar13 = *(int *)(param_1 + 0x20);

        }

        if ((int)uVar8 < iVar10) {

          do {

            if ((uVar8 & 7) == 0) {

              uVar9 = (ulonglong)*pbVar12;

              pbVar12 = pbVar12 + 1;

            }

            uVar8 = uVar8 + 1;

            uVar5 = uVar9 >> 7;

            uVar9 = (ulonglong)(byte)((char)uVar9 * '\x02');

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




