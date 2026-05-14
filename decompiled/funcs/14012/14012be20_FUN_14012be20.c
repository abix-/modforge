// Address: 0x14012be20
// Ghidra name: FUN_14012be20
// ============ 0x14012be20 FUN_14012be20 (size=62) ============


ulonglong FUN_14012be20(longlong param_1)



{

  ulonglong uVar1;

  

  if (param_1 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","context");

    return 0;

  }

  uVar1 = (ulonglong)*(uint *)(param_1 + 0x44);

  if (*(uint *)(param_1 + 0x44) == 0) {

    uVar1 = FUN_1401746e0();

    *(int *)(param_1 + 0x44) = (int)uVar1;

  }

  return uVar1;

}




