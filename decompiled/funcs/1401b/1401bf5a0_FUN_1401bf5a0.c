// Address: 0x1401bf5a0
// Ghidra name: FUN_1401bf5a0
// ============ 0x1401bf5a0 FUN_1401bf5a0 (size=135) ============


void FUN_1401bf5a0(longlong param_1,undefined8 param_2)



{

  uint uVar1;

  undefined8 uVar2;

  

  FUN_140179b40(*(undefined8 *)(param_1 + 0x8c8));

  if (*(uint *)(param_1 + 0x89c) <= *(int *)(param_1 + 0x898) + 1U) {

    uVar1 = *(uint *)(param_1 + 0x89c) * 2;

    *(uint *)(param_1 + 0x89c) = uVar1;

    uVar2 = FUN_140184230(*(undefined8 *)(param_1 + 0x890),(ulonglong)uVar1 << 3);

    *(undefined8 *)(param_1 + 0x890) = uVar2;

  }

  *(undefined8 *)(*(longlong *)(param_1 + 0x890) + (ulonglong)*(uint *)(param_1 + 0x898) * 8) =

       param_2;

  *(int *)(param_1 + 0x898) = *(int *)(param_1 + 0x898) + 1;

  FUN_140179b60(*(undefined8 *)(param_1 + 0x8c8));

  return;

}




