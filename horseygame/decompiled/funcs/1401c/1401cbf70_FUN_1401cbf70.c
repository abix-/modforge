// Address: 0x1401cbf70
// Ghidra name: FUN_1401cbf70
// ============ 0x1401cbf70 FUN_1401cbf70 (size=135) ============


void FUN_1401cbf70(longlong param_1,undefined8 param_2)



{

  uint uVar1;

  undefined8 uVar2;

  

  FUN_140179b40(*(undefined8 *)(param_1 + 0x228));

  if (*(uint *)(param_1 + 0x1ec) <= *(int *)(param_1 + 0x1e8) + 1U) {

    uVar1 = *(uint *)(param_1 + 0x1ec) * 2;

    *(uint *)(param_1 + 0x1ec) = uVar1;

    uVar2 = FUN_140184230(*(undefined8 *)(param_1 + 0x1e0),(ulonglong)uVar1 << 3);

    *(undefined8 *)(param_1 + 0x1e0) = uVar2;

  }

  *(undefined8 *)(*(longlong *)(param_1 + 0x1e0) + (ulonglong)*(uint *)(param_1 + 0x1e8) * 8) =

       param_2;

  *(int *)(param_1 + 0x1e8) = *(int *)(param_1 + 0x1e8) + 1;

  FUN_140179b60(*(undefined8 *)(param_1 + 0x228));

  return;

}




