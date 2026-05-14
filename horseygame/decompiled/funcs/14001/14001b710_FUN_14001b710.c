// Address: 0x14001b710
// Ghidra name: FUN_14001b710
// ============ 0x14001b710 FUN_14001b710 (size=40) ============


float * FUN_14001b710(longlong param_1,float *param_2,float param_3)



{

  float fVar1;

  

  param_3 = param_3 * *(float *)(param_1 + 0xa0);

  fVar1 = *(float *)(param_1 + 0xb0);

  param_2[1] = param_3 * *(float *)(param_1 + 0xb4);

  *param_2 = param_3 * fVar1;

  return param_2;

}




