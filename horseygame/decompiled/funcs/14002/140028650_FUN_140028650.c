// Address: 0x140028650
// Ghidra name: FUN_140028650
// ============ 0x140028650 FUN_140028650 (size=462) ============


void FUN_140028650(int *param_1,byte *param_2,int param_3)



{

  byte bVar1;

  byte bVar2;

  byte *pbVar3;

  byte *pbVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  

  if (param_2 == (byte *)0x0) {

    FID_conflict__assert(L"now",L"C:\\dev\\tinyxml\\tinyxmlparser.cpp",0xc6);

  }

  if (0 < param_1[4]) {

    pbVar3 = *(byte **)(param_1 + 2);

    iVar6 = *param_1;

    iVar7 = param_1[1];

    if (pbVar3 == (byte *)0x0) {

      FID_conflict__assert(L"p",L"C:\\dev\\tinyxml\\tinyxmlparser.cpp",0xd2);

    }

joined_r0x0001400286c7:

    pbVar4 = pbVar3;

    if (pbVar4 < param_2) {

      bVar1 = *pbVar4;

      if (bVar1 == 0) {

        return;

      }

      if (bVar1 == 9) {

        iVar7 = iVar7 + (param_1[4] - iVar7 % param_1[4]);

        pbVar3 = pbVar4 + 1;

      }

      else {

        if (bVar1 != 10) {

          if (bVar1 == 0xd) {

            iVar6 = iVar6 + 1;

            iVar7 = 0;

            pbVar3 = pbVar4 + 1;

            if (pbVar4[1] == 10) {

              pbVar3 = pbVar4 + 2;

            }

            goto joined_r0x0001400286c7;

          }

          if (bVar1 == 0xef) {

            if (param_3 == 1) {

              bVar1 = pbVar4[1];

              pbVar3 = pbVar4;

              if ((bVar1 != 0) && (bVar2 = pbVar4[2], bVar2 != 0)) {

                if (bVar1 == 0xbb) {

LAB_14002873b:

                  if (bVar2 == 0xbf) {

                    pbVar3 = pbVar4 + 3;

                    goto joined_r0x0001400286c7;

                  }

                }

                else if (bVar1 == 0xbf) {

                  if (bVar2 != 0xbe) goto LAB_14002873b;

                  pbVar3 = pbVar4 + 3;

                  goto joined_r0x0001400286c7;

                }

                iVar7 = iVar7 + 1;

                pbVar3 = pbVar4 + 3;

              }

              goto joined_r0x0001400286c7;

            }

          }

          else if (param_3 == 1) {

            iVar5 = *(int *)(&DAT_140399fb0 + (ulonglong)bVar1 * 4);

            if (iVar5 == 0) {

              iVar5 = 1;

            }

            iVar7 = iVar7 + 1;

            pbVar3 = pbVar4 + iVar5;

            goto joined_r0x0001400286c7;

          }

          iVar7 = iVar7 + 1;

          pbVar3 = pbVar4 + 1;

          goto joined_r0x0001400286c7;

        }

        iVar6 = iVar6 + 1;

        iVar7 = 0;

        pbVar3 = pbVar4 + 1;

        if (pbVar4[1] == 0xd) {

          pbVar3 = pbVar4 + 2;

        }

      }

      goto joined_r0x0001400286c7;

    }

    *param_1 = iVar6;

    param_1[1] = iVar7;

    if (iVar6 < -1) {

      FID_conflict__assert(L"cursor.row >= -1",L"C:\\dev\\tinyxml\\tinyxmlparser.cpp",0x133);

    }

    if (param_1[1] < -1) {

      FID_conflict__assert(L"cursor.col >= -1",L"C:\\dev\\tinyxml\\tinyxmlparser.cpp",0x134);

    }

    *(byte **)(param_1 + 2) = pbVar4;

    if (pbVar4 == (byte *)0x0) {

      FID_conflict__assert(L"stamp",L"C:\\dev\\tinyxml\\tinyxmlparser.cpp",0x136);

    }

  }

  return;

}




