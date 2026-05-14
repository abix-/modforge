// Address: 0x1400a8aa0
// Ghidra name: FUN_1400a8aa0
// ============ 0x1400a8aa0 FUN_1400a8aa0 (size=248) ============


undefined8 FUN_1400a8aa0(longlong param_1,float param_2,float param_3,float param_4)



{

  int iVar1;

  undefined8 uVar2;

  float fVar3;

  float fVar4;

  

  *(float *)(param_1 + 0x68) = param_2;

  param_2 = param_2 - *(float *)(param_1 + 0x28);

  *(float *)(param_1 + 0x6c) = param_3;

  param_3 = param_3 - *(float *)(param_1 + 0x2c);

  *(float *)(param_1 + 0x20) = param_3;

  fVar4 = param_3 * param_3 + param_2 * param_2;

  if (fVar4 < 0.0) {

    fVar4 = (float)FUN_1402cdfa0(fVar4);

  }

  else {

    fVar4 = SQRT(fVar4);

  }

  if (DAT_14039c9f0 <= fVar4) {

    param_2 = (DAT_14039ca44 / fVar4) * param_2;

    *(float *)(param_1 + 0x20) = (DAT_14039ca44 / fVar4) * param_3;

  }

  else {

    fVar4 = 0.0;

  }

  fVar3 = param_4 * *(float *)(param_1 + 0x20);

  fVar4 = fVar4 / param_4 + DAT_14030d098;

  *(float *)(param_1 + 0x1c) = param_2 * param_4;

  *(float *)(param_1 + 0x20) = fVar3;

  iVar1 = (int)fVar4;

  *(int *)(param_1 + 0x24) = iVar1;

  if (iVar1 < 1) {

    uVar2 = CONCAT71((uint7)(uint3)((uint)iVar1 >> 8),1);

  }

  else {

    *(int *)(param_1 + 0x24) = iVar1 + -1;

    uVar2 = FUN_1400a8ba0(param_1,param_2 * param_4,fVar3);

  }

  return uVar2;

}




