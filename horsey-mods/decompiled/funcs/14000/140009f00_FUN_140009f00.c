// Address: 0x140009f00
// Ghidra name: FUN_140009f00
// ============ 0x140009f00 FUN_140009f00 (size=117) ============


void FUN_140009f00(longlong param_1)



{

  uint uVar1;

  float fVar2;

  uint uVar3;

  uint uVar4;

  

  uVar1 = DAT_14039cac0;

  uVar3 = *(uint *)(param_1 + 0x88) ^ DAT_14039cac0;

  *(uint *)(param_1 + 0xa0) = *(uint *)(param_1 + 0xa0) ^ DAT_14039cac0;

  uVar4 = *(uint *)(param_1 + 0x90) ^ uVar1;

  *(uint *)(param_1 + 0x88) = uVar3;

  *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) ^ uVar1;

  *(uint *)(param_1 + 0x90) = uVar4;

  fVar2 = *(float *)(param_1 + 0x94) * DAT_14039ca80;

  *(uint *)(param_1 + 0x9c) = uVar4;

  *(float *)(param_1 + 0x98) = fVar2;

  return;

}




