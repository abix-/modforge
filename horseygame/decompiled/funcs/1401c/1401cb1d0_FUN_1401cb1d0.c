// Address: 0x1401cb1d0
// Ghidra name: FUN_1401cb1d0
// ============ 0x1401cb1d0 FUN_1401cb1d0 (size=107) ============


void FUN_1401cb1d0(longlong param_1,undefined8 param_2)



{

  uint uVar1;

  undefined8 uVar2;

  

  if (*(uint *)(param_1 + 0x13c) <= *(uint *)(param_1 + 0x138)) {

    uVar1 = *(uint *)(param_1 + 0x13c) * 2;

    *(uint *)(param_1 + 0x13c) = uVar1;

    uVar2 = FUN_140184230(*(undefined8 *)(param_1 + 0x130),(ulonglong)uVar1 << 3);

    *(undefined8 *)(param_1 + 0x130) = uVar2;

  }

  *(undefined8 *)(*(longlong *)(param_1 + 0x130) + (ulonglong)*(uint *)(param_1 + 0x138) * 8) =

       param_2;

  *(int *)(param_1 + 0x138) = *(int *)(param_1 + 0x138) + 1;

  return;

}




