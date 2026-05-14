// Address: 0x1401bf670
// Ghidra name: FUN_1401bf670
// ============ 0x1401bf670 FUN_1401bf670 (size=135) ============


void FUN_1401bf670(longlong param_1,undefined8 param_2)



{

  uint uVar1;

  undefined8 uVar2;

  

  FUN_140179b40(*(undefined8 *)(param_1 + 0x8c8));

  if (*(uint *)(param_1 + 0x88c) <= *(int *)(param_1 + 0x888) + 1U) {

    uVar1 = *(uint *)(param_1 + 0x88c) * 2;

    *(uint *)(param_1 + 0x88c) = uVar1;

    uVar2 = FUN_140184230(*(undefined8 *)(param_1 + 0x880),(ulonglong)uVar1 << 3);

    *(undefined8 *)(param_1 + 0x880) = uVar2;

  }

  *(undefined8 *)(*(longlong *)(param_1 + 0x880) + (ulonglong)*(uint *)(param_1 + 0x888) * 8) =

       param_2;

  *(int *)(param_1 + 0x888) = *(int *)(param_1 + 0x888) + 1;

  FUN_140179b60(*(undefined8 *)(param_1 + 0x8c8));

  return;

}




