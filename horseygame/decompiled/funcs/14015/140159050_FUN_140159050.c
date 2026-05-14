// Address: 0x140159050
// Ghidra name: FUN_140159050
// ============ 0x140159050 FUN_140159050 (size=96) ============


undefined4 FUN_140159050(longlong param_1)



{

  undefined4 uVar1;

  char cVar2;

  

  FUN_140159d30();

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar2 = FUN_1401aa7c0(param_1,4);

      if (cVar2 == '\0') goto LAB_14015908d;

    }

    uVar1 = *(undefined4 *)(param_1 + 0x44);

    FUN_14015bb10();

    return uVar1;

  }

LAB_14015908d:

  FUN_14012e850("Parameter \'%s\' is invalid","joystick");

  FUN_14015bb10();

  return 0xffffffff;

}




