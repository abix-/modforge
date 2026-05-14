// Address: 0x1401cad50
// Ghidra name: FUN_1401cad50
// ============ 0x1401cad50 FUN_1401cad50 (size=135) ============


void FUN_1401cad50(longlong param_1,undefined8 param_2)



{

  uint uVar1;

  undefined8 uVar2;

  

  FUN_140179b40(*(undefined8 *)(param_1 + 0x220));

  if (*(uint *)(param_1 + 0x15c) <= *(int *)(param_1 + 0x158) + 1U) {

    uVar1 = *(uint *)(param_1 + 0x15c) * 2;

    *(uint *)(param_1 + 0x15c) = uVar1;

    uVar2 = FUN_140184230(*(undefined8 *)(param_1 + 0x150),(ulonglong)uVar1 << 3);

    *(undefined8 *)(param_1 + 0x150) = uVar2;

  }

  *(undefined8 *)(*(longlong *)(param_1 + 0x150) + (ulonglong)*(uint *)(param_1 + 0x158) * 8) =

       param_2;

  *(int *)(param_1 + 0x158) = *(int *)(param_1 + 0x158) + 1;

  FUN_140179b60(*(undefined8 *)(param_1 + 0x220));

  return;

}




