// Address: 0x140082010
// Ghidra name: FUN_140082010
// ============ 0x140082010 FUN_140082010 (size=31) ============


void FUN_140082010(longlong param_1)



{

  undefined4 uVar1;

  

  uVar1 = 0;

  if (*(int *)(*(longlong *)(param_1 + 0x80) + 0x1c) == 6) {

    uVar1 = 0xd;

  }

  *(undefined4 *)(param_1 + 0x70) = uVar1;

  FUN_140080e40();

  return;

}




