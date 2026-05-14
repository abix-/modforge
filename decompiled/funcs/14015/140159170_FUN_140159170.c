// Address: 0x140159170
// Ghidra name: FUN_140159170
// ============ 0x140159170 FUN_140159170 (size=96) ============


undefined4 FUN_140159170(longlong param_1)



{

  undefined4 uVar1;

  char cVar2;

  

  FUN_140159d30();

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar2 = FUN_1401aa7c0(param_1,4);

      if (cVar2 == '\0') goto LAB_1401591ad;

    }

    uVar1 = *(undefined4 *)(param_1 + 0x60);

    FUN_14015bb10();

    return uVar1;

  }

LAB_1401591ad:

  FUN_14012e850("Parameter \'%s\' is invalid","joystick");

  FUN_14015bb10();

  return 0xffffffff;

}




