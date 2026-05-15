// Address: 0x140131a70
// Ghidra name: FUN_140131a70
// ============ 0x140131a70 FUN_140131a70 (size=81) ============


undefined4 FUN_140131a70(longlong param_1)



{

  undefined4 uVar1;

  

  if (param_1 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","camera");

    return 0xffffffff;

  }

  FUN_140130b40();

  uVar1 = *(undefined4 *)(param_1 + 0x1cc);

  FUN_140130b70(param_1);

  return uVar1;

}




