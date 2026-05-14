// Address: 0x1400153b0
// Ghidra name: FUN_1400153b0
// ============ 0x1400153b0 FUN_1400153b0 (size=48) ============


float * FUN_1400153b0(longlong param_1,float *param_2,float param_3)



{

  float fVar1;

  float fVar2;

  

  fVar1 = *(float *)(param_1 + 0xa8);

  fVar2 = *(float *)(param_1 + 0xbc);

  param_2[1] = fVar1 * *(float *)(param_1 + 0xc0) * param_3;

  *param_2 = fVar1 * fVar2 * param_3;

  return param_2;

}




