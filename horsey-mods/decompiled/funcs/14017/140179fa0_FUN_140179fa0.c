// Address: 0x140179fa0
// Ghidra name: FUN_140179fa0
// ============ 0x140179fa0 FUN_140179fa0 (size=138) ============


void FUN_140179fa0(float *param_1,float *param_2,float *param_3,float *param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  

  fVar1 = *param_1;

  fVar2 = *param_3;

  fVar3 = *param_2;

  *param_1 = fVar3 * param_4[1] + fVar1 * *param_4 + fVar2 * param_4[2];

  *param_2 = fVar3 * param_4[4] + fVar1 * param_4[3] + fVar2 * param_4[5];

  *param_3 = fVar3 * param_4[7] + fVar1 * param_4[6] + fVar2 * param_4[8];

  return;

}




