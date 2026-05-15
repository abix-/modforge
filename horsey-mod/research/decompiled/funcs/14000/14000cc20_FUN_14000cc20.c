// Address: 0x14000cc20
// Ghidra name: FUN_14000cc20
// ============ 0x14000cc20 FUN_14000cc20 (size=242) ============


void FUN_14000cc20(longlong param_1,float *param_2,float *param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  

  fVar6 = param_3[3];

  fVar1 = *(float *)(param_1 + 0xc);

  fVar2 = param_3[2];

  fVar5 = *(float *)(param_1 + 0x14) * fVar6 + *(float *)(param_1 + 0x10) * fVar2 + param_3[1];

  fVar4 = (*(float *)(param_1 + 0x10) * fVar6 - *(float *)(param_1 + 0x14) * fVar2) + *param_3;

  fVar3 = *(float *)(param_1 + 0x1c) * fVar6 + *(float *)(param_1 + 0x18) * fVar2 + param_3[1];

  fVar2 = (*(float *)(param_1 + 0x18) * fVar6 - *(float *)(param_1 + 0x1c) * fVar2) + *param_3;

  fVar6 = fVar5;

  if (fVar5 <= fVar3) {

    fVar6 = fVar3;

  }

  if (fVar3 <= fVar5) {

    fVar5 = fVar3;

  }

  fVar3 = fVar4;

  if (fVar4 <= fVar2) {

    fVar3 = fVar2;

  }

  if (fVar2 <= fVar4) {

    fVar4 = fVar2;

  }

  param_2[3] = fVar6 + fVar1;

  param_2[1] = fVar5 - fVar1;

  param_2[2] = fVar3 + fVar1;

  *param_2 = fVar4 - fVar1;

  return;

}




