// Address: 0x1401587b0
// Ghidra name: FUN_1401587b0
// ============ 0x1401587b0 FUN_1401587b0 (size=117) ============


undefined8 FUN_1401587b0(undefined4 *param_1)



{

  char cVar1;

  undefined4 *puVar2;

  undefined8 uVar3;

  

  FUN_140159d30();

  if (param_1 != (undefined4 *)0x0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,4);

      if (cVar1 == '\0') goto LAB_140158805;

    }

    puVar2 = (undefined4 *)FUN_140158f10(*param_1);

    if (puVar2 != (undefined4 *)0x0) {

      param_1 = puVar2;

    }

    uVar3 = FUN_1401aa890(*(undefined8 *)(param_1 + 2));

    FUN_14015bb10();

    return uVar3;

  }

LAB_140158805:

  FUN_14012e850("Parameter \'%s\' is invalid","joystick");

  FUN_14015bb10();

  return 0;

}




