// Address: 0x140167840
// Ghidra name: FUN_140167840
// ============ 0x140167840 FUN_140167840 (size=635) ============


int FUN_140167840(undefined8 *param_1,longlong param_2,int param_3,float param_4)



{

  float fVar1;

  undefined8 uVar2;

  char cVar3;

  uint uVar4;

  int iVar5;

  longlong lVar6;

  longlong lVar7;

  ulonglong uVar8;

  int iVar9;

  ulonglong uVar10;

  char *pcVar11;

  int iVar12;

  longlong lVar13;

  ulonglong uVar14;

  int iVar15;

  undefined8 local_res8;

  undefined8 local_res10;

  undefined1 local_58 [32];

  

  if (param_1 == (undefined8 *)0x0) {

    pcVar11 = "stream";

  }

  else if (param_2 == 0) {

    pcVar11 = "buf";

  }

  else {

    if (-1 < param_3) {

      if (param_3 == 0) {

        return 0;

      }

      FUN_140179b40(*param_1);

      cVar3 = FUN_140163e40(param_1);

      if (cVar3 == '\0') {

        FUN_140179b60(*param_1);

        return -1;

      }

      fVar1 = *(float *)((longlong)param_1 + 0x5c);

      iVar15 = (*(uint *)((longlong)param_1 + 0x3c) >> 3 & 0x1f) * *(int *)(param_1 + 8);

      param_3 = param_3 - param_3 % iVar15;

      if (param_1[2] != 0) {

        local_res8 = 0;

        lVar13 = (longlong)(param_3 / iVar15);

        lVar6 = FUN_1401644e0(param_1,&local_res8);

        uVar2 = local_res8;

        if (lVar13 < lVar6) {

          lVar6 = lVar13;

        }

        lVar6 = lVar13 - lVar6;

        lVar7 = FUN_1401648f0(param_1,*(undefined4 *)(param_1 + 7),local_res8);

        if (lVar7 != 0) {

          lVar13 = FUN_140214360(lVar13,lVar7,uVar2);

          lVar6 = FUN_140214360(lVar6,lVar7,uVar2);

        }

        uVar4 = (*(uint *)(param_1 + 6) >> 3 & 0x1f) * *(int *)((longlong)param_1 + 0x34);

        uVar8 = (ulonglong)uVar4 * lVar13;

        uVar10 = (ulonglong)uVar4 * lVar6;

        uVar14 = 0x7fffffff;

        if ((longlong)uVar8 < 0x7fffffff) {

          uVar14 = uVar8 & 0xffffffff;

        }

        uVar8 = 0x7fffffff;

        if ((longlong)uVar10 < 0x7fffffff) {

          uVar8 = uVar10 & 0xffffffff;

        }

        (*(code *)param_1[2])(param_1[3],param_1,uVar8,uVar14);

      }

      iVar12 = 0;

      iVar9 = iVar12;

      if (0 < param_3) {

        do {

          lVar6 = FUN_140164870(param_1,local_58,&local_res10,&local_res8);

          if (lVar6 != 0) {

            cVar3 = FUN_140168f00(param_1,local_58,local_res10);

            if (cVar3 != '\0') {

              iVar5 = (param_3 - iVar12) / iVar15;

              iVar9 = 0x1000;

              if (iVar5 < 0x1000) {

                iVar9 = iVar5;

              }

              iVar5 = (int)lVar6;

              if (iVar9 < lVar6) {

                iVar5 = iVar9;

              }

              cVar3 = FUN_140164580(param_1,iVar12 + param_2,iVar5,param_4 * fVar1);

              if (cVar3 != '\0') {

                iVar12 = iVar12 + iVar5 * iVar15;

                goto LAB_140167a76;

              }

            }

            iVar9 = -1;

            if (iVar12 != 0) {

              iVar9 = iVar12;

            }

            break;

          }

          iVar9 = iVar12;

          if ((char)local_res8 == '\0') break;

          FUN_140217e40(param_1[0xc]);

          param_1[0xd] = 0;

          *(undefined4 *)(param_1 + 0xe) = 0;

          param_1[0x14] = 0;

          param_1[0xf] = 0;

LAB_140167a76:

          iVar9 = iVar12;

        } while (iVar12 < param_3);

      }

      FUN_140179b60(*param_1);

      return iVar9;

    }

    pcVar11 = "len";

  }

  FUN_14012e850("Parameter \'%s\' is invalid",pcVar11);

  return -1;

}




