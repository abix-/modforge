// Address: 0x14000b240
// Ghidra name: FUN_14000b240
// ============ 0x14000b240 FUN_14000b240 (size=32) ============


float * FUN_14000b240(longlong param_1,float *param_2,float param_3)



{

  float fVar1;

  

  fVar1 = *(float *)(param_1 + 0x94);

  *param_2 = param_3 * *(float *)(param_1 + 0x90);

  param_2[1] = param_3 * fVar1;

  return param_2;

}




