// Address: 0x1401bcfc0
// Ghidra name: FUN_1401bcfc0
// ============ 0x1401bcfc0 FUN_1401bcfc0 (size=135) ============


void FUN_1401bcfc0(longlong param_1,undefined8 param_2)



{

  uint uVar1;

  undefined8 uVar2;

  

  FUN_140179b40(*(undefined8 *)(param_1 + 0x7e0));

  if (*(uint *)(param_1 + 0x7f4) <= *(int *)(param_1 + 0x7f0) + 1U) {

    uVar1 = *(uint *)(param_1 + 0x7f4) * 2;

    *(uint *)(param_1 + 0x7f4) = uVar1;

    uVar2 = FUN_140184230(*(undefined8 *)(param_1 + 0x7e8),(ulonglong)uVar1 << 3);

    *(undefined8 *)(param_1 + 0x7e8) = uVar2;

  }

  *(undefined8 *)(*(longlong *)(param_1 + 0x7e8) + (ulonglong)*(uint *)(param_1 + 0x7f0) * 8) =

       param_2;

  *(int *)(param_1 + 0x7f0) = *(int *)(param_1 + 0x7f0) + 1;

  FUN_140179b60(*(undefined8 *)(param_1 + 0x7e0));

  return;

}




