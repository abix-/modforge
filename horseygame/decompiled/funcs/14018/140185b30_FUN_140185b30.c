// Address: 0x140185b30
// Ghidra name: FUN_140185b30
// ============ 0x140185b30 FUN_140185b30 (size=330) ============


undefined1 FUN_140185b30(int param_1,int param_2,int param_3,longlong param_4,undefined4 *param_5)



{

  int iVar1;

  int iVar2;

  int iVar3;

  longlong lVar4;

  int *piVar5;

  int iVar6;

  

  if (param_1 < 1) {

    FUN_14012e850("Parameter \'%s\' is invalid","width");

    return 0;

  }

  if (param_2 < 1) {

    FUN_14012e850("Parameter \'%s\' is invalid","height");

    return 0;

  }

  if (param_4 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","rects");

    return 0;

  }

  if (param_5 != (undefined4 *)0x0) {

    if (param_3 < 1) {

      FUN_14012e850("Parameter \'%s\' is invalid","numrects");

      return 0;

    }

    lVar4 = (longlong)param_3;

    if (param_3 != 0) {

      piVar5 = (int *)(param_4 + 0xc);

      iVar3 = param_2;

      iVar1 = 0;

      do {

        iVar2 = piVar5[-2];

        iVar6 = *piVar5 + iVar2;

        if (iVar2 < 0) {

          iVar3 = 0;

        }

        else if (iVar2 < iVar3) {

          iVar3 = iVar2;

        }

        iVar2 = param_2;

        if ((iVar6 <= param_2) && (iVar2 = iVar1, iVar1 < iVar6)) {

          iVar2 = iVar6;

        }

        piVar5 = piVar5 + 4;

        lVar4 = lVar4 + -1;

        iVar1 = iVar2;

      } while (lVar4 != 0);

      if (iVar3 < iVar2) {

        *param_5 = 0;

        param_5[3] = iVar2 - iVar3;

        param_5[1] = iVar3;

        param_5[2] = param_1;

        return 1;

      }

    }

    return 0;

  }

  FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140338d08);

  return 0;

}




