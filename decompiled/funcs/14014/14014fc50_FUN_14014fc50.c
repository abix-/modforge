// Address: 0x14014fc50
// Ghidra name: FUN_14014fc50
// ============ 0x14014fc50 FUN_14014fc50 (size=282) ============


undefined8 FUN_14014fc50(longlong param_1,float param_2,float param_3,float *param_4,float *param_5)



{

  float fVar1;

  int iVar2;

  char cVar3;

  

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar3 = FUN_1401aa7c0(param_1,2), cVar3 == '\0')))) {

    FUN_14012e850("Parameter \'%s\' is invalid","renderer");

  }

  else {

    if (*(char *)(param_1 + 0x2d8) == '\0') {

      param_2 = param_2 * *(float *)(param_1 + 0x1d8);

      param_3 = param_3 * *(float *)(param_1 + 0x1dc);

      if (*(int *)(param_1 + 0x194) != 0) {

        param_2 = ((param_2 - *(float *)(param_1 + 0x1b0)) * *(float *)(param_1 + 0x1a8)) /

                  *(float *)(param_1 + 0x1b8);

        param_3 = ((param_3 - *(float *)(param_1 + 0x1b4)) * *(float *)(param_1 + 0x1ac)) /

                  *(float *)(param_1 + 0x1bc);

      }

      iVar2 = *(int *)(param_1 + 0x14c);

      fVar1 = *(float *)(param_1 + 400);

      if (param_4 != (float *)0x0) {

        *param_4 = param_2 / *(float *)(param_1 + 0x18c) - (float)*(int *)(param_1 + 0x148);

      }

      if (param_5 != (float *)0x0) {

        *param_5 = param_3 / fVar1 - (float)iVar2;

      }

      return 1;

    }

    FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

  }

  return 0;

}




