// Address: 0x140019db0
// Ghidra name: FUN_140019db0
// ============ 0x140019db0 FUN_140019db0 (size=83) ============


float * FUN_140019db0(longlong param_1,float *param_2,float param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  

  fVar1 = *(float *)(param_1 + 0xb0);

  fVar2 = *(float *)(param_1 + 0xa8);

  fVar3 = *(float *)(param_1 + 0xf4);

  fVar4 = *(float *)(param_1 + 0xec);

  *param_2 = (fVar1 * *(float *)(param_1 + 0xe8) + fVar2 * *(float *)(param_1 + 0xf0)) * param_3;

  param_2[1] = (fVar2 * fVar3 + fVar1 * fVar4) * param_3;

  return param_2;

}




