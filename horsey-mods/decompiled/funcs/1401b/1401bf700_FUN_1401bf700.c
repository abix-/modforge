// Address: 0x1401bf700
// Ghidra name: FUN_1401bf700
// ============ 0x1401bf700 FUN_1401bf700 (size=135) ============


void FUN_1401bf700(longlong param_1,undefined8 param_2)



{

  uint uVar1;

  undefined8 uVar2;

  

  FUN_140179b40(*(undefined8 *)(param_1 + 0x8c8));

  if (*(uint *)(param_1 + 0x87c) <= *(int *)(param_1 + 0x878) + 1U) {

    uVar1 = *(uint *)(param_1 + 0x87c) * 2;

    *(uint *)(param_1 + 0x87c) = uVar1;

    uVar2 = FUN_140184230(*(undefined8 *)(param_1 + 0x870),(ulonglong)uVar1 << 3);

    *(undefined8 *)(param_1 + 0x870) = uVar2;

  }

  *(undefined8 *)(*(longlong *)(param_1 + 0x870) + (ulonglong)*(uint *)(param_1 + 0x878) * 8) =

       param_2;

  *(int *)(param_1 + 0x878) = *(int *)(param_1 + 0x878) + 1;

  FUN_140179b60(*(undefined8 *)(param_1 + 0x8c8));

  return;

}




