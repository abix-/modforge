// Address: 0x1401cbea0
// Ghidra name: FUN_1401cbea0
// ============ 0x1401cbea0 FUN_1401cbea0 (size=135) ============


void FUN_1401cbea0(longlong param_1,undefined8 param_2)



{

  uint uVar1;

  undefined8 uVar2;

  

  FUN_140179b40(*(undefined8 *)(param_1 + 0x228));

  if (*(uint *)(param_1 + 0x1fc) <= *(int *)(param_1 + 0x1f8) + 1U) {

    uVar1 = *(uint *)(param_1 + 0x1fc) * 2;

    *(uint *)(param_1 + 0x1fc) = uVar1;

    uVar2 = FUN_140184230(*(undefined8 *)(param_1 + 0x1f0),(ulonglong)uVar1 << 3);

    *(undefined8 *)(param_1 + 0x1f0) = uVar2;

  }

  *(undefined8 *)(*(longlong *)(param_1 + 0x1f0) + (ulonglong)*(uint *)(param_1 + 0x1f8) * 8) =

       param_2;

  *(int *)(param_1 + 0x1f8) = *(int *)(param_1 + 0x1f8) + 1;

  FUN_140179b60(*(undefined8 *)(param_1 + 0x228));

  return;

}




