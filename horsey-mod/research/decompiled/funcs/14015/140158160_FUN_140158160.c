// Address: 0x140158160
// Ghidra name: FUN_140158160
// ============ 0x140158160 FUN_140158160 (size=95) ============


undefined2 FUN_140158160(longlong param_1)



{

  undefined2 uVar1;

  char cVar2;

  

  FUN_140159d30();

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar2 = FUN_1401aa7c0(param_1,4);

      if (cVar2 == '\0') goto LAB_14015819f;

    }

    uVar1 = *(undefined2 *)(param_1 + 0x30);

    FUN_14015bb10();

    return uVar1;

  }

LAB_14015819f:

  FUN_14012e850("Parameter \'%s\' is invalid","joystick");

  FUN_14015bb10();

  return 0;

}




