// Address: 0x1401590b0
// Ghidra name: FUN_1401590b0
// ============ 0x1401590b0 FUN_1401590b0 (size=96) ============


undefined4 FUN_1401590b0(longlong param_1)



{

  undefined4 uVar1;

  char cVar2;

  

  FUN_140159d30();

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar2 = FUN_1401aa7c0(param_1,4);

      if (cVar2 == '\0') goto LAB_1401590ed;

    }

    uVar1 = *(undefined4 *)(param_1 + 0x50);

    FUN_14015bb10();

    return uVar1;

  }

LAB_1401590ed:

  FUN_14012e850("Parameter \'%s\' is invalid","joystick");

  FUN_14015bb10();

  return 0xffffffff;

}




