// Address: 0x1401588a0
// Ghidra name: FUN_1401588a0
// ============ 0x1401588a0 FUN_1401588a0 (size=135) ============


undefined8 FUN_1401588a0(longlong param_1)



{

  char cVar1;

  undefined8 uVar2;

  

  FUN_140159d30();

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,4);

      if (cVar1 == '\0') goto LAB_140158907;

    }

    if (*(longlong *)(param_1 + 0x10) != 0) {

      uVar2 = FUN_1401aa890();

      FUN_14015bb10();

      return uVar2;

    }

    FUN_14012e850("That operation is not supported");

    FUN_14015bb10();

    return 0;

  }

LAB_140158907:

  FUN_14012e850("Parameter \'%s\' is invalid","joystick");

  FUN_14015bb10();

  return 0;

}




