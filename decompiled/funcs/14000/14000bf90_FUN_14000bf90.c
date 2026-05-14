// Address: 0x14000bf90
// Ghidra name: FUN_14000bf90
// ============ 0x14000bf90 FUN_14000bf90 (size=40) ============


float * FUN_14000bf90(longlong param_1,float *param_2,float param_3)



{

  float fVar1;

  

  param_3 = param_3 * *(float *)(param_1 + 0x98);

  fVar1 = *(float *)(param_1 + 0xa4);

  param_2[1] = param_3 * *(float *)(param_1 + 0xa8);

  *param_2 = param_3 * fVar1;

  return param_2;

}




