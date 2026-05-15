// Address: 0x14001d130
// Ghidra name: FUN_14001d130
// ============ 0x14001d130 FUN_14001d130 (size=83) ============


float * FUN_14001d130(longlong param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  longlong lVar6;

  

  lVar6 = *(longlong *)(param_1 + 0x60);

  fVar1 = *(float *)(param_1 + 0x98);

  fVar2 = *(float *)(param_1 + 0x9c);

  fVar3 = *(float *)(lVar6 + 0x18);

  fVar4 = *(float *)(lVar6 + 0x14);

  fVar5 = *(float *)(lVar6 + 0x10);

  *param_2 = (fVar3 * fVar1 - fVar4 * fVar2) + *(float *)(lVar6 + 0xc);

  param_2[1] = fVar1 * fVar4 + fVar3 * fVar2 + fVar5;

  return param_2;

}




