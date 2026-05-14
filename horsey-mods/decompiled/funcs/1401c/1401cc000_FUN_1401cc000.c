// Address: 0x1401cc000
// Ghidra name: FUN_1401cc000
// ============ 0x1401cc000 FUN_1401cc000 (size=135) ============


void FUN_1401cc000(longlong param_1,undefined8 param_2)



{

  uint uVar1;

  undefined8 uVar2;

  

  FUN_140179b40(*(undefined8 *)(param_1 + 0x228));

  if (*(uint *)(param_1 + 0x1dc) <= *(int *)(param_1 + 0x1d8) + 1U) {

    uVar1 = *(uint *)(param_1 + 0x1dc) * 2;

    *(uint *)(param_1 + 0x1dc) = uVar1;

    uVar2 = FUN_140184230(*(undefined8 *)(param_1 + 0x1d0),(ulonglong)uVar1 << 3);

    *(undefined8 *)(param_1 + 0x1d0) = uVar2;

  }

  *(undefined8 *)(*(longlong *)(param_1 + 0x1d0) + (ulonglong)*(uint *)(param_1 + 0x1d8) * 8) =

       param_2;

  *(int *)(param_1 + 0x1d8) = *(int *)(param_1 + 0x1d8) + 1;

  FUN_140179b60(*(undefined8 *)(param_1 + 0x228));

  return;

}




