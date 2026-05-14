// Address: 0x140146f20
// Ghidra name: FUN_140146f20
// ============ 0x140146f20 FUN_140146f20 (size=84) ============


undefined1 FUN_140146f20(uint *param_1)



{

  char cVar1;

  undefined1 uVar2;

  

  cVar1 = FUN_1401489c0();

  if (cVar1 == '\0') {

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","surface");

    return uVar2;

  }

  if ((param_1[0x18] == 0) && ((param_1[0xc] & 4) != 0)) {

    FUN_1401d2c00(param_1);

  }

  param_1[0x18] = param_1[0x18] + 1;

  *param_1 = *param_1 | 4;

  FUN_140148a20(param_1);

  return 1;

}




