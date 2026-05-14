// Address: 0x140158960
// Ghidra name: FUN_140158960
// ============ 0x140158960 FUN_140158960 (size=102) ============


undefined4 FUN_140158960(undefined4 *param_1)



{

  char cVar1;

  undefined4 uVar2;

  

  FUN_140159d30();

  if (param_1 != (undefined4 *)0x0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,4);

      if (cVar1 == '\0') goto LAB_1401589a3;

    }

    uVar2 = FUN_1401591d0(*param_1);

    FUN_14015bb10();

    return uVar2;

  }

LAB_1401589a3:

  FUN_14012e850("Parameter \'%s\' is invalid","joystick");

  FUN_14015bb10();

  return 0xffffffff;

}




