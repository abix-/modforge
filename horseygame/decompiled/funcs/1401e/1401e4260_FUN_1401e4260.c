// Address: 0x1401e4260
// Ghidra name: FUN_1401e4260
// ============ 0x1401e4260 FUN_1401e4260 (size=55) ============


undefined8 FUN_1401e4260(longlong param_1,int param_2)



{

  undefined8 uVar1;

  

  if (param_2 < 0) {

    uVar1 = FUN_14012e850("That operation is not supported");

    return uVar1;

  }

  if (param_2 < 1) {

    param_2 = 0;

  }

  *(int *)(*(longlong *)(param_1 + 0x2e0) + 0x40) = param_2;

  FUN_1401e4740();

  return 1;

}




