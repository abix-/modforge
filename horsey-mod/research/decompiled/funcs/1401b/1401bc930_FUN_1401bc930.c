// Address: 0x1401bc930
// Ghidra name: FUN_1401bc930
// ============ 0x1401bc930 FUN_1401bc930 (size=111) ============


void FUN_1401bc930(longlong param_1)



{

  longlong lVar1;

  uint uVar2;

  undefined8 uVar3;

  

  lVar1 = *(longlong *)(param_1 + 0x110);

  uVar2 = *(int *)(lVar1 + 0x7d8) + 1;

  if (*(uint *)(lVar1 + 0x7dc) <= uVar2) {

    *(uint *)(lVar1 + 0x7dc) = uVar2;

    uVar3 = FUN_140184230(*(undefined8 *)(lVar1 + 2000),(ulonglong)uVar2 << 3);

    *(undefined8 *)(lVar1 + 2000) = uVar3;

  }

  *(longlong *)(*(longlong *)(lVar1 + 2000) + (ulonglong)*(uint *)(lVar1 + 0x7d8) * 8) = param_1;

  *(int *)(lVar1 + 0x7d8) = *(int *)(lVar1 + 0x7d8) + 1;

  return;

}




