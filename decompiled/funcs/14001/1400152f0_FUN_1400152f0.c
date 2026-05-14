// Address: 0x1400152f0
// Ghidra name: FUN_1400152f0
// ============ 0x1400152f0 FUN_1400152f0 (size=83) ============


float * FUN_1400152f0(longlong param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  longlong lVar6;

  

  lVar6 = *(longlong *)(param_1 + 0x60);

  fVar1 = *(float *)(param_1 + 0x90);

  fVar2 = *(float *)(param_1 + 0x94);

  fVar3 = *(float *)(lVar6 + 0x18);

  fVar4 = *(float *)(lVar6 + 0x14);

  fVar5 = *(float *)(lVar6 + 0x10);

  *param_2 = (fVar3 * fVar1 - fVar4 * fVar2) + *(float *)(lVar6 + 0xc);

  param_2[1] = fVar1 * fVar4 + fVar3 * fVar2 + fVar5;

  return param_2;

}




