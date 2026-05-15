// Address: 0x140227940
// Ghidra name: FUN_140227940
// ============ 0x140227940 FUN_140227940 (size=590) ============


void FUN_140227940(ulonglong *param_1,undefined8 param_2,longlong param_3,undefined8 param_4,

                  float *param_5,float *param_6)



{

  undefined4 uVar1;

  int iVar2;

  longlong lVar3;

  ulonglong uVar4;

  ulonglong *puVar5;

  uint uVar6;

  ulonglong uVar7;

  ulonglong uVar8;

  ulonglong uVar9;

  ulonglong uVar10;

  int iVar11;

  longlong lVar12;

  ulonglong uVar13;

  

  if (param_1 != (ulonglong *)0x0) {

    if (param_3 == 0) {

      uVar1 = FUN_14016dba0();

      lVar3 = FUN_14016dd00(uVar1);

    }

    else {

      lVar3 = FUN_14016de50(param_3);

    }

    uVar10 = (longlong)*param_5 * 0x10000;

    uVar9 = (longlong)*param_6 * 0x10000;

    if (lVar3 == 0) {

      uVar13 = 0x60;

    }

    else {

      uVar13 = (ulonglong)(*(float *)(lVar3 + 0x58) * DAT_140304040);

    }

    if (*(char *)((longlong)param_1 + 0x6c) == '\0') {

      iVar2 = 0x60;

      if (*(char *)((longlong)param_1 + 0x6d) != '\0') {

        iVar2 = (int)uVar13;

      }

      uVar6 = iVar2 * (int)param_1[0xc];

      *param_5 = (float)((longlong)(uVar6 * uVar10) / 0xc00) * DAT_1403053bc;

      *param_6 = (float)((longlong)(uVar6 * uVar9) / 0xc00) * DAT_1403053bc;

    }

    else {

      iVar2 = FUN_140190050(uVar10 & 0xffffffff);

      uVar8 = (ulonglong)iVar2;

      iVar2 = FUN_140190050(uVar9 & 0xffffffff);

      uVar7 = (ulonglong)iVar2;

      uVar4 = uVar7;

      if (uVar7 < uVar8) {

        uVar4 = uVar8;

      }

      if (uVar8 < uVar7) {

        uVar7 = uVar8;

      }

      uVar7 = uVar7 + uVar4 * 2;

      if (uVar7 != 0) {

        uVar4 = 1;

        puVar5 = param_1;

        do {

          uVar8 = uVar4;

          puVar5 = puVar5 + 1;

          uVar4 = uVar8;

          if (uVar7 < *puVar5) break;

          uVar6 = (int)uVar8 + 1;

          uVar4 = (ulonglong)uVar6;

        } while ((int)uVar6 < 5);

        iVar2 = (int)param_1[0xd];

        iVar11 = (int)uVar8 + -1;

        uVar6 = *(uint *)((longlong)param_1 + 100);

        lVar3 = 0;

        *(int *)(param_1 + 0xd) = iVar11;

        if (param_1[uVar8] - param_1[uVar8 - 1] != 0) {

          lVar3 = (longlong)(param_1[uVar8 + 5] - param_1[uVar8 + 4]) /

                  (longlong)(param_1[uVar8] - param_1[uVar8 - 1]);

          lVar3 = lVar3 - (lVar3 * param_1[uVar4 - 1] - param_1[uVar4 + 4]) / uVar7;

        }

        if (iVar2 < iVar11) {

          uVar6 = uVar6 * 2;

          lVar12 = param_1[(longlong)iVar2 + 1] - param_1[iVar2];

          if (lVar12 != 0) {

            lVar12 = (longlong)(param_1[(longlong)iVar2 + 6] - param_1[(longlong)iVar2 + 5]) /

                     lVar12;

            lVar3 = lVar3 + (lVar12 - (lVar12 * param_1[iVar2] - param_1[(longlong)iVar2 + 5]) /

                                      uVar7);

          }

        }

        lVar3 = (uVar13 & 0xffffffff) * lVar3;

        *param_5 = (float)((longlong)(lVar3 * uVar10) / (longlong)(ulonglong)uVar6) * DAT_1403053bc;

        *param_6 = (float)((longlong)(lVar3 * uVar9) / (longlong)(ulonglong)uVar6) * DAT_1403053bc;

      }

    }

  }

  return;

}




