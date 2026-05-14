// Address: 0x14000e340
// Ghidra name: FUN_14000e340
// ============ 0x14000e340 FUN_14000e340 (size=148) ============


undefined8 FUN_14000e340(longlong param_1,float *param_2,float *param_3)



{

  float *pfVar1;

  longlong lVar2;

  

  if (0 < (longlong)*(int *)(param_1 + 0x98)) {

    lVar2 = 0;

    pfVar1 = (float *)(param_1 + 0x1c);

    do {

      if (0.0 < ((param_2[2] * (param_3[1] - param_2[1]) + param_2[3] * (*param_3 - *param_2)) -

                pfVar1[-1]) * pfVar1[0xf] +

                ((param_2[3] * (param_3[1] - param_2[1]) - param_2[2] * (*param_3 - *param_2)) -

                *pfVar1) * pfVar1[0x10]) {

        return 0;

      }

      lVar2 = lVar2 + 1;

      pfVar1 = pfVar1 + 2;

    } while (lVar2 < *(int *)(param_1 + 0x98));

  }

  return 1;

}




