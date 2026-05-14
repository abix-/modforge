// Address: 0x14000cd20
// Ghidra name: FUN_14000cd20
// ============ 0x14000cd20 FUN_14000cd20 (size=54) ============


void FUN_14000cd20(longlong param_1,undefined4 *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  

  *param_2 = 0;

  fVar1 = *(float *)(param_1 + 0x14);

  fVar4 = *(float *)(param_1 + 0x10);

  fVar2 = *(float *)(param_1 + 0x1c);

  fVar3 = *(float *)(param_1 + 0x18);

  param_2[3] = 0;

  fVar4 = (fVar4 + fVar3) * DAT_14039ca34;

  param_2[2] = (fVar1 + fVar2) * DAT_14039ca34;

  param_2[1] = fVar4;

  return;

}




