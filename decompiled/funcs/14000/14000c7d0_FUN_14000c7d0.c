// Address: 0x14000c7d0
// Ghidra name: FUN_14000c7d0
// ============ 0x14000c7d0 FUN_14000c7d0 (size=112) ============


void FUN_14000c7d0(longlong param_1,float *param_2,float *param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  

  fVar1 = *(float *)(param_1 + 0xc);

  fVar2 = (param_3[3] * *(float *)(param_1 + 0x10) - param_3[2] * *(float *)(param_1 + 0x14)) +

          *param_3;

  fVar3 = *(float *)(param_1 + 0x10) * param_3[2] + param_3[3] * *(float *)(param_1 + 0x14) +

          param_3[1];

  *param_2 = fVar2 - fVar1;

  param_2[1] = fVar3 - fVar1;

  fVar1 = *(float *)(param_1 + 0xc);

  param_2[2] = fVar2 + fVar1;

  param_2[3] = fVar3 + fVar1;

  return;

}




