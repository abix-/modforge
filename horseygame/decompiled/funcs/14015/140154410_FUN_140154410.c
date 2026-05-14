// Address: 0x140154410
// Ghidra name: FUN_140154410
// ============ 0x140154410 FUN_140154410 (size=277) ============


undefined8 FUN_140154410(longlong param_1,int param_2,undefined8 param_3,int param_4)



{

  int iVar1;

  char cVar2;

  int iVar3;

  undefined8 uVar4;

  longlong lVar5;

  longlong lVar6;

  int *piVar7;

  

  if (param_1 == 0) {

    uVar4 = FUN_14012e850("Parameter \'%s\' is invalid","state");

    return uVar4;

  }

  cVar2 = FUN_140149d80();

  if (cVar2 != '\0') {

    iVar1 = *(int *)(param_1 + 0x48);

    iVar3 = 0;

    if (0 < iVar1) {

      piVar7 = *(int **)(param_1 + 0x50);

      do {

        if (*piVar7 == param_2) {

          lVar5 = FUN_140184230(*(undefined8 *)(piVar7 + 2),param_4);

          if (lVar5 == 0) {

            return 0;

          }

          FUN_1402f8e20(lVar5,param_3,param_4);

          *(longlong *)(piVar7 + 2) = lVar5;

          piVar7[4] = param_4;

          return 1;

        }

        iVar3 = iVar3 + 1;

        piVar7 = piVar7 + 6;

      } while (iVar3 < iVar1);

    }

    lVar5 = FUN_140184230(*(undefined8 *)(param_1 + 0x50),((longlong)iVar1 + 1) * 0x18);

    if (lVar5 != 0) {

      piVar7 = (int *)(lVar5 + (longlong)*(int *)(param_1 + 0x48) * 0x18);

      *piVar7 = param_2;

      piVar7[4] = param_4;

      lVar6 = FUN_1401841f0(param_4);

      *(longlong *)(piVar7 + 2) = lVar6;

      if (lVar6 != 0) {

        FUN_1402f8e20(lVar6,param_3,param_4);

        *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 1;

        *(longlong *)(param_1 + 0x50) = lVar5;

        return 1;

      }

      FUN_1401841e0(lVar5);

    }

  }

  return 0;

}




