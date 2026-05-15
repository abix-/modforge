// Address: 0x1401859f0
// Ghidra name: FUN_1401859f0
// ============ 0x1401859f0 FUN_1401859f0 (size=312) ============


undefined8 FUN_1401859f0(int *param_1,int *param_2,int *param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  char cVar4;

  undefined8 uVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int *piVar9;

  int *piVar10;

  

  if (param_1 == (int *)0x0) {

    uVar5 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_1403376fc);

    return uVar5;

  }

  if (param_2 == (int *)0x0) {

    uVar5 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_1403380bc);

    return uVar5;

  }

  piVar9 = param_2;

  piVar10 = param_3;

  cVar4 = FUN_140185e20();

  if (cVar4 == '\0') {

    cVar4 = FUN_140185e20(piVar9);

    if (cVar4 == '\0') {

      if (piVar10 == (int *)0x0) {

        uVar5 = FUN_14012e850("Parameter \'%s\' is invalid","result");

        return uVar5;

      }

      if ((0 < param_1[2]) && (0 < param_1[3])) {

        if ((0 < param_2[2]) && (0 < param_2[3])) {

          iVar1 = *param_1;

          iVar6 = param_1[2] + iVar1;

          iVar2 = *param_2;

          iVar7 = param_2[2] + iVar2;

          if (iVar1 <= iVar2) {

            iVar2 = iVar1;

          }

          *piVar10 = iVar2;

          if (iVar7 <= iVar6) {

            iVar7 = iVar6;

          }

          piVar10[2] = iVar7 - iVar2;

          iVar1 = param_1[1];

          iVar2 = param_1[3];

          iVar7 = piVar9[1];

          iVar6 = piVar9[3];

          iVar3 = iVar7;

          if (iVar1 <= iVar7) {

            iVar3 = iVar1;

          }

          piVar10[1] = iVar3;

          iVar8 = iVar6 + iVar7;

          if (iVar6 + iVar7 <= iVar2 + iVar1) {

            iVar8 = iVar2 + iVar1;

          }

          piVar10[3] = iVar8 - iVar3;

          return 1;

        }

        uVar5 = *(undefined8 *)(param_1 + 2);

        *(undefined8 *)piVar10 = *(undefined8 *)param_1;

        *(undefined8 *)(piVar10 + 2) = uVar5;

        return 1;

      }

      if ((0 < param_2[2]) && (0 < param_2[3])) {

        uVar5 = *(undefined8 *)(param_2 + 2);

        *(undefined8 *)param_3 = *(undefined8 *)param_2;

        *(undefined8 *)(param_3 + 2) = uVar5;

        return 1;

      }

      param_3[0] = 0;

      param_3[1] = 0;

      param_3[2] = 0;

      param_3[3] = 0;

      return 1;

    }

  }

  uVar5 = FUN_14012e850("Potential rect math overflow");

  return uVar5;

}




