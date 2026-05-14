// Address: 0x1401319e0
// Ghidra name: FUN_1401319e0
// ============ 0x1401319e0 FUN_1401319e0 (size=75) ============


undefined4 FUN_1401319e0(longlong param_1)



{

  undefined4 uVar1;

  

  if (param_1 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","camera");

    return 0;

  }

  FUN_140130b40();

  uVar1 = *(undefined4 *)(param_1 + 0x6c);

  FUN_140130b70(param_1);

  return uVar1;

}




