// Address: 0x14014fd70
// Ghidra name: FUN_14014fd70
// ============ 0x14014fd70 FUN_14014fd70 (size=282) ============


undefined8 FUN_14014fd70(longlong param_1,float param_2,float param_3,float *param_4,float *param_5)



{

  float fVar1;

  char cVar2;

  float fVar3;

  float fVar4;

  

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar2 = FUN_1401aa7c0(param_1,2), cVar2 == '\0')))) {

    FUN_14012e850("Parameter \'%s\' is invalid","renderer");

  }

  else {

    if (*(char *)(param_1 + 0x2d8) == '\0') {

      fVar4 = ((float)*(int *)(param_1 + 0x148) + param_2) * *(float *)(param_1 + 0x18c);

      fVar3 = ((float)*(int *)(param_1 + 0x14c) + param_3) * *(float *)(param_1 + 400);

      if (*(int *)(param_1 + 0x194) != 0) {

        fVar4 = (fVar4 * *(float *)(param_1 + 0x1b8)) / *(float *)(param_1 + 0x1a8) +

                *(float *)(param_1 + 0x1b0);

        fVar3 = (fVar3 * *(float *)(param_1 + 0x1bc)) / *(float *)(param_1 + 0x1ac) +

                *(float *)(param_1 + 0x1b4);

      }

      fVar1 = *(float *)(param_1 + 0x1dc);

      if (param_4 != (float *)0x0) {

        *param_4 = fVar4 / *(float *)(param_1 + 0x1d8);

      }

      if (param_5 != (float *)0x0) {

        *param_5 = fVar3 / fVar1;

      }

      return 1;

    }

    FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

  }

  return 0;

}




