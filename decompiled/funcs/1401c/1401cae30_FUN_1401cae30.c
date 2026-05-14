// Address: 0x1401cae30
// Ghidra name: FUN_1401cae30
// ============ 0x1401cae30 FUN_1401cae30 (size=135) ============


void FUN_1401cae30(longlong param_1,undefined8 param_2)



{

  uint uVar1;

  undefined8 uVar2;

  

  FUN_140179b40(*(undefined8 *)(param_1 + 0x228));

  if (*(uint *)(param_1 + 0x1cc) <= *(int *)(param_1 + 0x1c8) + 1U) {

    uVar1 = *(uint *)(param_1 + 0x1cc) * 2;

    *(uint *)(param_1 + 0x1cc) = uVar1;

    uVar2 = FUN_140184230(*(undefined8 *)(param_1 + 0x1c0),(ulonglong)uVar1 << 3);

    *(undefined8 *)(param_1 + 0x1c0) = uVar2;

  }

  *(undefined8 *)(*(longlong *)(param_1 + 0x1c0) + (ulonglong)*(uint *)(param_1 + 0x1c8) * 8) =

       param_2;

  *(int *)(param_1 + 0x1c8) = *(int *)(param_1 + 0x1c8) + 1;

  FUN_140179b60(*(undefined8 *)(param_1 + 0x228));

  return;

}




