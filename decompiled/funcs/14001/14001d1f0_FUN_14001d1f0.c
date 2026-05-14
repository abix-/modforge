// Address: 0x14001d1f0
// Ghidra name: FUN_14001d1f0
// ============ 0x14001d1f0 FUN_14001d1f0 (size=48) ============


float * FUN_14001d1f0(longlong param_1,float *param_2,float param_3)



{

  float fVar1;

  float fVar2;

  

  fVar1 = *(float *)(param_1 + 0xd8);

  fVar2 = *(float *)(param_1 + 300);

  param_2[1] = fVar1 * *(float *)(param_1 + 0x130) * param_3;

  *param_2 = fVar1 * fVar2 * param_3;

  return param_2;

}




