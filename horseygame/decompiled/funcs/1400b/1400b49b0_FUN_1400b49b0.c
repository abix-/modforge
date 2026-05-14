// Address: 0x1400b49b0
// Ghidra name: FUN_1400b49b0
// ============ 0x1400b49b0 FUN_1400b49b0 (size=83) ============


float * FUN_1400b49b0(longlong param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  

  fVar4 = DAT_14039ca44;

  if (*(int *)(param_1 + 0x1fc) == 0) {

    fVar4 = DAT_14039ca34;

  }

  fVar3 = *(float *)(param_1 + 0x124);

  if (*(char *)(param_1 + 0x1a) != '\0') {

    fVar3 = (float)((uint)fVar3 ^ DAT_14039cac0);

  }

  fVar1 = *(float *)(param_1 + 0x134);

  fVar2 = *(float *)(*(longlong *)(param_1 + 0x40) + 0x44);

  *param_2 = fVar3 + *(float *)(*(longlong *)(param_1 + 0x40) + 0x40);

  param_2[1] = fVar4 * fVar1 + fVar2;

  return param_2;

}




