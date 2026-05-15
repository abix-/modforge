// Address: 0x1400a8890
// Ghidra name: FUN_1400a8890
// ============ 0x1400a8890 FUN_1400a8890 (size=337) ============


void FUN_1400a8890(longlong param_1,float param_2,float param_3,float param_4,float param_5)



{

  float fVar1;

  uint uVar2;

  float fVar3;

  

  if (param_5 != 0.0) {

    uVar2 = (uint)param_5 ^ DAT_14039cac0;

    fVar1 = (float)FUN_1400c6940(uVar2,param_5);

    param_2 = param_2 + fVar1;

    fVar1 = (float)FUN_1400c6940(uVar2,param_5);

    param_3 = param_3 + fVar1;

  }

  *(float *)(param_1 + 0x68) = param_2;

  param_2 = param_2 - *(float *)(param_1 + 0x28);

  *(float *)(param_1 + 0x6c) = param_3;

  param_3 = param_3 - *(float *)(param_1 + 0x2c);

  *(float *)(param_1 + 0x20) = param_3;

  fVar1 = param_3 * param_3 + param_2 * param_2;

  if (fVar1 < 0.0) {

    fVar1 = (float)FUN_1402cdfa0(fVar1);

  }

  else {

    fVar1 = SQRT(fVar1);

  }

  fVar3 = 0.0;

  if (DAT_14039c9f0 <= fVar1) {

    param_2 = (DAT_14039ca44 / fVar1) * param_2;

    *(float *)(param_1 + 0x20) = (DAT_14039ca44 / fVar1) * param_3;

    fVar3 = fVar1;

  }

  fVar1 = fVar3 / param_4 + DAT_14030d098;

  *(float *)(param_1 + 0x1c) = param_2 * param_4;

  *(float *)(param_1 + 0x20) = param_4 * *(float *)(param_1 + 0x20);

  *(int *)(param_1 + 0x24) = (int)fVar1;

  return;

}




