// Address: 0x140131b00
// Ghidra name: FUN_140131b00
// ============ 0x140131b00 FUN_140131b00 (size=95) ============


int FUN_140131b00(longlong param_1)



{

  int iVar1;

  

  if (param_1 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","camera");

    return 0;

  }

  FUN_140130b40();

  iVar1 = *(int *)(param_1 + 0x1c8);

  if (iVar1 == 0) {

    iVar1 = FUN_1401746e0();

    *(int *)(param_1 + 0x1c8) = iVar1;

  }

  FUN_140130b70(param_1);

  return iVar1;

}




