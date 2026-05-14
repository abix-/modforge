// Address: 0x14013c030
// Ghidra name: FUN_14013c030
// ============ 0x14013c030 FUN_14013c030 (size=250) ============


void FUN_14013c030(longlong param_1,float *param_2,float *param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  

  _guard_check_icall();

  *param_3 = 0.0;

  fVar2 = *(float *)(param_1 + 0x110) * *param_2 + 0.0;

  *param_3 = fVar2;

  fVar2 = *(float *)(param_1 + 0x114) * param_2[1] + fVar2;

  *param_3 = fVar2;

  fVar3 = *(float *)(param_1 + 0x118);

  fVar1 = param_2[2];

  param_3[1] = 0.0;

  *param_3 = fVar3 * fVar1 + fVar2;

  fVar2 = *(float *)(param_1 + 0x11c) * *param_2 + 0.0;

  param_3[1] = fVar2;

  fVar2 = *(float *)(param_1 + 0x120) * param_2[1] + fVar2;

  param_3[1] = fVar2;

  fVar3 = *(float *)(param_1 + 0x124);

  fVar1 = param_2[2];

  param_3[2] = 0.0;

  param_3[1] = fVar3 * fVar1 + fVar2;

  fVar3 = *(float *)(param_1 + 0x128) * *param_2 + 0.0;

  param_3[2] = fVar3;

  fVar3 = *(float *)(param_1 + 300) * param_2[1] + fVar3;

  param_3[2] = fVar3;

  param_3[2] = *(float *)(param_1 + 0x130) * param_2[2] + fVar3;

  return;

}




