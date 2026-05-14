// Address: 0x1401487a0
// Ghidra name: FUN_1401487a0
// ============ 0x1401487a0 FUN_1401487a0 (size=69) ============


undefined1 FUN_1401487a0(longlong param_1,undefined4 param_2)



{

  char cVar1;

  undefined1 uVar2;

  

  cVar1 = FUN_1401489c0();

  if (cVar1 == '\0') {

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","surface");

    return uVar2;

  }

  *(undefined4 *)(param_1 + 0x40) = param_2;

  return 1;

}




