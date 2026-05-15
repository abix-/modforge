// Address: 0x1402d74e0
// Ghidra name: FUN_1402d74e0
// ============ 0x1402d74e0 FUN_1402d74e0 (size=118) ============


void FUN_1402d74e0(longlong param_1)



{

  longlong lVar1;

  

  lVar1 = FUN_1402cd068();

  *(undefined8 *)(param_1 + 0x18) = *(undefined8 *)(lVar1 + 0x90);

  *(undefined8 *)(param_1 + 0x20) = *(undefined8 *)(lVar1 + 0x88);

  FUN_1402eeef8(lVar1,(undefined8 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 8));

  FUN_1402eef64(lVar1,param_1 + 0x20,*(undefined8 *)(param_1 + 8));

  if ((*(uint *)(lVar1 + 0x3a8) & 2) == 0) {

    *(uint *)(lVar1 + 0x3a8) = *(uint *)(lVar1 + 0x3a8) | 2;

    *(undefined1 *)(param_1 + 0x28) = 2;

  }

  return;

}




