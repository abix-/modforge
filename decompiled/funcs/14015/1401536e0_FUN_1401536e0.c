// Address: 0x1401536e0
// Ghidra name: FUN_1401536e0
// ============ 0x1401536e0 FUN_1401536e0 (size=90) ============


undefined8 FUN_1401536e0(longlong param_1,float param_2,float param_3,float *param_4,float *param_5)



{

  float fVar1;

  

  param_2 = param_2 * *(float *)(param_1 + 0x1d8);

  param_3 = param_3 * *(float *)(param_1 + 0x1dc);

  if (*(int *)(param_1 + 0x194) != 0) {

    param_2 = (param_2 * *(float *)(param_1 + 0x1a8)) / *(float *)(param_1 + 0x1b8);

    param_3 = (param_3 * *(float *)(param_1 + 0x1ac)) / *(float *)(param_1 + 0x1bc);

  }

  fVar1 = *(float *)(param_1 + 400);

  *param_4 = param_2 / *(float *)(param_1 + 0x18c);

  *param_5 = param_3 / fVar1;

  return 1;

}




