// Address: 0x14001da90
// Ghidra name: FUN_14001da90
// ============ 0x14001da90 FUN_14001da90 (size=32) ============


float * FUN_14001da90(longlong param_1,float *param_2,float param_3)



{

  float fVar1;

  

  fVar1 = *(float *)(param_1 + 0xa0);

  *param_2 = param_3 * *(float *)(param_1 + 0x9c);

  param_2[1] = param_3 * fVar1;

  return param_2;

}




