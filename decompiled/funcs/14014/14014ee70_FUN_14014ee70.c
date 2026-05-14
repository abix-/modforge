// Address: 0x14014ee70
// Ghidra name: FUN_14014ee70
// ============ 0x14014ee70 FUN_14014ee70 (size=234) ============


undefined8 FUN_14014ee70(longlong param_1,int *param_2)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  float fVar4;

  

  if (param_2 != (int *)0x0) {

    param_2[0] = 0;

    param_2[1] = 0;

    param_2[2] = 0;

    param_2[3] = 0;

  }

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar2 = FUN_1401aa7c0(param_1,2);

      if (cVar2 == '\0') goto LAB_14014ef3a;

    }

    if (*(char *)(param_1 + 0x2d8) != '\0') {

      FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

      return 0;

    }

    if (param_2 != (int *)0x0) {

      piVar1 = *(int **)(param_1 + 0x138);

      *param_2 = piVar1[2];

      param_2[1] = piVar1[3];

      iVar3 = piVar1[4];

      if (iVar3 < 0) {

        fVar4 = (float)thunk_FUN_1402e33f0((float)*piVar1 / (float)piVar1[0x24]);

        iVar3 = (int)fVar4;

      }

      param_2[2] = iVar3;

      iVar3 = piVar1[5];

      if (iVar3 < 0) {

        fVar4 = (float)thunk_FUN_1402e33f0((float)piVar1[1] / (float)piVar1[0x25]);

        iVar3 = (int)fVar4;

      }

      param_2[3] = iVar3;

    }

    return 1;

  }

LAB_14014ef3a:

  FUN_14012e850("Parameter \'%s\' is invalid","renderer");

  return 0;

}




