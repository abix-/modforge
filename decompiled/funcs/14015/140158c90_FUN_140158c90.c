// Address: 0x140158c90
// Ghidra name: FUN_140158c90
// ============ 0x140158c90 FUN_140158c90 (size=103) ============


undefined8 FUN_140158c90(longlong param_1)



{

  char cVar1;

  undefined8 uVar2;

  

  FUN_140159d30();

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,4);

      if (cVar1 == '\0') goto LAB_140158cd7;

    }

    uVar2 = FUN_1401aa890(*(undefined8 *)(param_1 + 0x18));

    FUN_14015bb10();

    return uVar2;

  }

LAB_140158cd7:

  FUN_14012e850("Parameter \'%s\' is invalid","joystick");

  FUN_14015bb10();

  return 0;

}




