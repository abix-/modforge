// Address: 0x140008400
// Ghidra name: FUN_140008400
// ============ 0x140008400 FUN_140008400 (size=299) ============


void FUN_140008400(longlong param_1,longlong param_2,longlong param_3,float *param_4,float *param_5)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  

  *(longlong *)(param_1 + 0x10) = param_2;

  *(longlong *)(param_1 + 0x18) = param_3;

  fVar1 = *(float *)(param_2 + 0x18);

  fVar2 = *(float *)(param_2 + 0x14);

  fVar4 = *param_4 - *(float *)(param_2 + 0xc);

  fVar3 = param_4[1] - *(float *)(param_2 + 0x10);

  *(float *)(param_1 + 0x28) = fVar2 * fVar3 + fVar1 * fVar4;

  *(float *)(param_1 + 0x2c) = fVar1 * fVar3 - fVar2 * fVar4;

  fVar1 = *(float *)(param_3 + 0x18);

  fVar2 = *(float *)(param_3 + 0x14);

  fVar4 = *param_4 - *(float *)(param_3 + 0xc);

  fVar3 = param_4[1] - *(float *)(param_3 + 0x10);

  *(float *)(param_1 + 0x30) = fVar2 * fVar3 + fVar1 * fVar4;

  *(float *)(param_1 + 0x34) = fVar1 * fVar3 - fVar2 * fVar4;

  fVar1 = *(float *)(param_2 + 0x18);

  fVar2 = *(float *)(param_2 + 0x14);

  fVar3 = *param_5;

  fVar4 = param_5[1];

  *(float *)(param_1 + 0x38) = fVar2 * fVar4 + fVar1 * fVar3;

  *(float *)(param_1 + 0x3c) = fVar1 * fVar4 - fVar2 * fVar3;

  fVar1 = (float)FUN_1402cd4c0(*(undefined4 *)(param_3 + 0x14),*(undefined4 *)(param_3 + 0x18));

  fVar2 = (float)FUN_1402cd4c0(*(undefined4 *)(param_2 + 0x14),*(undefined4 *)(param_2 + 0x18));

  *(float *)(param_1 + 0x40) = fVar1 - fVar2;

  return;

}




