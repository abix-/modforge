// Address: 0x140158720
// Ghidra name: FUN_140158720
// ============ 0x140158720 FUN_140158720 (size=92) ============


undefined4 FUN_140158720(undefined4 *param_1)



{

  undefined4 uVar1;

  char cVar2;

  

  FUN_140159d30();

  if (param_1 != (undefined4 *)0x0) {

    if (DAT_1403e3d60 != '\0') {

      cVar2 = FUN_1401aa7c0(param_1,4);

      if (cVar2 == '\0') goto LAB_14015875c;

    }

    uVar1 = *param_1;

    FUN_14015bb10();

    return uVar1;

  }

LAB_14015875c:

  FUN_14012e850("Parameter \'%s\' is invalid","joystick");

  FUN_14015bb10();

  return 0;

}




