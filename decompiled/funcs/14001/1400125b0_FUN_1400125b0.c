// Address: 0x1400125b0
// Ghidra name: FUN_1400125b0
// ============ 0x1400125b0 FUN_1400125b0 (size=124) ============


void FUN_1400125b0(longlong param_1,undefined4 param_2)



{

  int iVar1;

  undefined8 uVar2;

  undefined8 uVar3;

  

  iVar1 = *(int *)(param_1 + 0x38);

  if (*(int *)(param_1 + 0x3c) == iVar1) {

    uVar2 = *(undefined8 *)(param_1 + 0x30);

    *(int *)(param_1 + 0x38) = iVar1 * 2;

    uVar3 = _malloc_base((longlong)(iVar1 * 8));

    *(undefined8 *)(param_1 + 0x30) = uVar3;

    FUN_1402f8e20(uVar3,uVar2,(longlong)*(int *)(param_1 + 0x3c) << 2);

    thunk_FUN_1402e9a80(uVar2);

  }

  *(undefined4 *)(*(longlong *)(param_1 + 0x30) + (longlong)*(int *)(param_1 + 0x3c) * 4) = param_2;

  *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;

  return;

}




