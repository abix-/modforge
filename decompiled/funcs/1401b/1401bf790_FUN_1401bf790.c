// Address: 0x1401bf790
// Ghidra name: FUN_1401bf790
// ============ 0x1401bf790 FUN_1401bf790 (size=135) ============


void FUN_1401bf790(longlong param_1,undefined8 param_2)



{

  uint uVar1;

  undefined8 uVar2;

  

  FUN_140179b40(*(undefined8 *)(param_1 + 0x8c8));

  if (*(uint *)(param_1 + 0x8ac) <= *(int *)(param_1 + 0x8a8) + 1U) {

    uVar1 = *(uint *)(param_1 + 0x8ac) * 2;

    *(uint *)(param_1 + 0x8ac) = uVar1;

    uVar2 = FUN_140184230(*(undefined8 *)(param_1 + 0x8a0),(ulonglong)uVar1 << 3);

    *(undefined8 *)(param_1 + 0x8a0) = uVar2;

  }

  *(undefined8 *)(*(longlong *)(param_1 + 0x8a0) + (ulonglong)*(uint *)(param_1 + 0x8a8) * 8) =

       param_2;

  *(int *)(param_1 + 0x8a8) = *(int *)(param_1 + 0x8a8) + 1;

  FUN_140179b60(*(undefined8 *)(param_1 + 0x8c8));

  return;

}




