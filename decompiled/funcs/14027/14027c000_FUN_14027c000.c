// Address: 0x14027c000
// Ghidra name: FUN_14027c000
// ============ 0x14027c000 FUN_14027c000 (size=1170) ============


undefined8 FUN_14027c000(undefined8 param_1,longlong param_2,char *param_3,int param_4)



{

  char cVar1;

  uint uVar2;

  int iVar3;

  char cVar4;

  undefined8 uVar5;

  int *piVar6;

  int iVar7;

  longlong lVar8;

  ulonglong uVar9;

  uint7 uVar10;

  int iVar11;

  char *pcVar12;

  uint local_58 [2];

  longlong local_50;

  int *local_48;

  

  piVar6 = *(int **)(param_2 + 0x50);

  local_48 = piVar6;

  uVar5 = FUN_140149300();

  iVar11 = 0;

  cVar1 = *param_3;

  if (0 < *piVar6) {

    local_50 = 0;

    do {

      lVar8 = local_50;

      pcVar12 = (char *)(*(longlong *)(piVar6 + 2) + local_50);

      if (*pcVar12 == cVar1) {

        uVar9 = (ulonglong)*(uint *)(pcVar12 + 0xc);

        cVar4 = FUN_1402c5990(param_3 + 1,param_4 + -1,*(undefined4 *)(pcVar12 + 8),uVar9,local_58);

        if (cVar4 != '\0') {

          uVar2 = *(uint *)(pcVar12 + 4);

          uVar10 = (uint7)(uVar9 >> 8);

          if (uVar2 < 0x1003a) {

            if (uVar2 == 0x10039) {

              switch(local_58[0]) {

              case 1:

                FUN_14015ae90(uVar5,param_1,0,CONCAT71(uVar10,1));

                break;

              case 2:

                FUN_14015ae90(uVar5,param_1,0,CONCAT71(uVar10,3));

                break;

              case 3:

                FUN_14015ae90(uVar5,param_1,0,CONCAT71(uVar10,2));

                break;

              case 4:

                FUN_14015ae90(uVar5,param_1,0,CONCAT71(uVar10,6));

                break;

              case 5:

                FUN_14015ae90(uVar5,param_1,0,CONCAT71(uVar10,4));

                break;

              case 6:

                FUN_14015ae90(uVar5,param_1,0,CONCAT71(uVar10,0xc));

                break;

              case 7:

                FUN_14015ae90(uVar5,param_1,0,CONCAT71(uVar10,8));

                break;

              case 8:

                FUN_14015ae90(uVar5,param_1,0,CONCAT71(uVar10,9));

                break;

              default:

                FUN_14015ae90(uVar5,param_1,0,(ulonglong)uVar10 << 8);

              }

            }

            else {

              switch(uVar2 - 0x10030) {

              case 0:

                FUN_14027d220(uVar5,param_1,0,local_58[0]);

                break;

              case 1:

                FUN_14027d220(uVar5,param_1,1,local_58[0]);

                break;

              case 2:

                if (*(int *)(pcVar12 + 0xc) == 0x10) goto switchD_14027c0c8_caseD_3;

                if (*(int *)(pcVar12 + 0xc) == 10) {

LAB_14027c127:

                  FUN_14027d230(uVar5,param_1,4,local_58[0]);

                }

                break;

              case 3:

switchD_14027c0c8_caseD_3:

                FUN_14027d220(uVar5,param_1,2,local_58[0]);

                break;

              case 4:

switchD_14027c0c8_caseD_4:

                FUN_14027d220(uVar5,param_1,3,local_58[0]);

                break;

              case 5:

                if (*(int *)(pcVar12 + 0xc) == 0x10) goto switchD_14027c0c8_caseD_4;

                if (*(int *)(pcVar12 + 0xc) == 10) goto LAB_14027c16d;

              }

            }

          }

          else if (uVar2 < 0xc0082) {

            if (uVar2 == 0xc0081) {

              if (*(char *)(param_2 + 0x2a) != '\0') {

                if (*(char *)(param_2 + 0x2b) == '\0') {

                  local_58[0] = 0;

                }

                cVar4 = *(char *)(param_2 + 0x2d);

                FUN_14015ad00(uVar5,param_1,cVar4 + '\v',local_58[0] & 0xffffff01);

                FUN_14015ad00(uVar5,param_1,cVar4 + '\f',

                              CONCAT31((uint3)(local_58[0] >> 9),(char)(local_58[0] >> 1)) &

                              0xffffff01);

                FUN_14015ad00(uVar5,param_1,cVar4 + 0xdU,local_58[0] >> 2 & 0xffffff01);

                FUN_14015ad00(uVar5,param_1,(byte)(cVar4 + 0xdU) + 1,local_58[0] >> 3 & 0xffffff01);

              }

            }

            else if (uVar2 == 0x200c4) {

LAB_14027c16d:

              FUN_14027d230(uVar5,param_1,5,local_58[0]);

            }

            else {

              if (uVar2 == 0x200c5) goto LAB_14027c127;

              if (uVar2 == 0x60020) {

                FUN_14027bfb0(param_1,local_58[0]);

              }

              else if ((uVar2 == 0x90001) && (local_58[0] != *(uint *)(param_2 + 0x58))) {

                *(uint *)(param_2 + 0x58) = local_58[0];

                if (*(int *)(pcVar12 + 0xc) == 0xc) {

                  piVar6 = &DAT_14037fbe8;

                }

                else {

                  if (*(int *)(pcVar12 + 0xc) != 0xf) goto switchD_14027c0c8_default;

                  piVar6 = &DAT_14037fc18;

                }

                iVar7 = 0;

                do {

                  iVar3 = *piVar6;

                  if (iVar3 != -1) {

                    if (iVar3 == 4) {

                      cVar4 = *(char *)(param_2 + 0x2e);

LAB_14027c2ff:

                      if (cVar4 != '\0') goto LAB_14027c315;

                    }

                    else if (iVar3 == 5) {

                      cVar4 = *(char *)(param_2 + 0x2f);

                      goto LAB_14027c2ff;

                    }

                    FUN_14015ad00(uVar5,param_1,iVar3,(byte)local_58[0] & 1);

                  }

LAB_14027c315:

                  local_58[0] = local_58[0] >> 1;

                  iVar7 = iVar7 + 1;

                  piVar6 = piVar6 + 1;

                  lVar8 = local_50;

                } while (iVar7 < *(int *)(pcVar12 + 0xc));

              }

            }

          }

          else if (uVar2 == 0xc0085) {

            *(bool *)(param_2 + 0x2b) = local_58[0] == 0;

          }

          else if (uVar2 == 0xc00b2) {

            if (*(char *)(param_2 + 0x2d) != '\0') {

              FUN_14015ad00(uVar5,param_1,0xb,CONCAT71(uVar10,local_58[0] != 0));

            }

          }

          else if (uVar2 == 0xc0223) {

            if (local_58[0] != 0) {

              *(undefined1 *)(param_2 + 0x2f) = 1;

            }

            FUN_14015ad00(uVar5,param_1,5,CONCAT71(uVar10,local_58[0] != 0));

          }

          else if (uVar2 == 0xc0224) {

            if (local_58[0] != 0) {

              *(undefined1 *)(param_2 + 0x2e) = 1;

            }

            FUN_14015ad00(uVar5,param_1,4,CONCAT71(uVar10,local_58[0] != 0));

          }

        }

      }

switchD_14027c0c8_default:

      local_50 = lVar8 + 0x10;

      iVar11 = iVar11 + 1;

      piVar6 = local_48;

    } while (iVar11 < *local_48);

  }

  return 1;

}




