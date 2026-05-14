// Address: 0x14001aa70
// Ghidra name: FUN_14001aa70
// ============ 0x14001aa70 FUN_14001aa70 (size=32) ============


float * FUN_14001aa70(longlong param_1,float *param_2,float param_3)



{

  float fVar1;

  

  fVar1 = *(float *)(param_1 + 0x98);

  *param_2 = param_3 * *(float *)(param_1 + 0x94);

  param_2[1] = param_3 * fVar1;

  return param_2;

}




