// Address: 0x1401ce190
// Ghidra name: FUN_1401ce190
// ============ 0x1401ce190 FUN_1401ce190 (size=306) ============


undefined8 FUN_1401ce190(undefined8 *param_1,undefined8 param_2)



{

  longlong lVar1;

  char cVar2;

  int iVar3;

  undefined8 uVar4;

  int iVar5;

  uint uVar6;

  longlong lVar7;

  longlong lVar8;

  ulonglong uVar9;

  int *piVar10;

  

  if ((param_1[1] == 0) && (*(int *)(param_1 + 5) == 0)) {

    return 1;

  }

  FUN_140179b40(*param_1);

  iVar5 = *(int *)(param_1 + 5);

  lVar7 = (longlong)iVar5;

  if (((code *)param_1[1] == (code *)0x0) ||

     (cVar2 = (*(code *)param_1[1])(param_1[2],param_2), cVar2 != '\0')) {

    *(undefined1 *)((longlong)param_1 + 0x2c) = 1;

    if (0 < iVar5) {

      lVar8 = 0;

      do {

        lVar1 = param_1[4];

        if (*(char *)(lVar1 + 0x10 + lVar8) == '\0') {

          (**(code **)(lVar1 + lVar8))(*(undefined8 *)(lVar1 + 8 + lVar8),param_2);

        }

        lVar8 = lVar8 + 0x18;

        lVar7 = lVar7 + -1;

      } while (lVar7 != 0);

    }

    piVar10 = (int *)(param_1 + 5);

    *(undefined1 *)((longlong)param_1 + 0x2c) = 0;

    if (*(char *)((longlong)param_1 + 0x2d) != '\0') {

      uVar9 = (ulonglong)*piVar10;

      if (*piVar10 != 0) {

        lVar7 = uVar9 * 0x18;

        do {

          lVar7 = lVar7 + -0x18;

          iVar5 = (int)uVar9;

          lVar8 = lVar7 + param_1[4];

          uVar6 = iVar5 - 1;

          uVar9 = (ulonglong)uVar6;

          if (*(char *)(lVar8 + 0x10) != '\0') {

            iVar3 = *piVar10 + -1;

            *piVar10 = iVar3;

            if ((int)uVar6 < iVar3) {

              FUN_1402f8e20(lVar8,param_1[4] + (longlong)iVar5 * 0x18,

                            (longlong)(int)(iVar3 - uVar6) * 0x18);

            }

          }

        } while (uVar6 != 0);

      }

      *(undefined1 *)((longlong)param_1 + 0x2d) = 0;

    }

    FUN_140179b60(*param_1);

    uVar4 = 1;

  }

  else {

    FUN_140179b60(*param_1);

    uVar4 = 0;

  }

  return uVar4;

}




