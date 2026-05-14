// Address: 0x140009c30
// Ghidra name: FUN_140009c30
// ============ 0x140009c30 FUN_140009c30 (size=91) ============


float * FUN_140009c30(longlong param_1,float *param_2,float param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  

  fVar4 = *(float *)(param_1 + 0xb0) + *(float *)(param_1 + 0xac);

  fVar1 = *(float *)(param_1 + 0xa4);

  fVar2 = *(float *)(param_1 + 0xfc);

  fVar3 = *(float *)(param_1 + 0xf4);

  param_2[1] = (fVar1 * *(float *)(param_1 + 0x100) + fVar4 * *(float *)(param_1 + 0xf8)) * param_3;

  *param_2 = (fVar1 * fVar2 + fVar4 * fVar3) * param_3;

  return param_2;

}




