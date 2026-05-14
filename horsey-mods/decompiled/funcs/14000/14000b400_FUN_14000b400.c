// Address: 0x14000b400
// Ghidra name: FUN_14000b400
// ============ 0x14000b400 FUN_14000b400 (size=104) ============


void FUN_14000b400(longlong param_1)



{

  uint uVar1;

  uint uVar2;

  

  uVar2 = DAT_14039cac0;

  *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) ^ DAT_14039cac0;

  uVar1 = *(uint *)(param_1 + 0xb8);

  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb4) ^ uVar2;

  *(uint *)(param_1 + 0xb4) = uVar1 ^ uVar2;

  *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) ^ uVar2;

  *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) ^ uVar2;

  return;

}




