// Address: 0x14013ee50
// Ghidra name: FUN_14013ee50
// ============ 0x14013ee50 FUN_14013ee50 (size=110) ============


undefined8 FUN_14013ee50(longlong *param_1)



{

  undefined8 uVar1;

  char cVar2;

  

  FUN_140159d30();

  if (param_1 != (longlong *)0x0) {

    if (DAT_1403e3d60 != '\0') {

      cVar2 = FUN_1401aa7c0(param_1,5);

      if (cVar2 == '\0') goto LAB_14013ee9e;

    }

    cVar2 = FUN_1401596f0(*param_1);

    if (cVar2 != '\0') {

      uVar1 = *(undefined8 *)(*param_1 + 0x38);

      FUN_14015bb10();

      return uVar1;

    }

  }

LAB_14013ee9e:

  FUN_14012e850("Parameter \'%s\' is invalid","gamepad");

  FUN_14015bb10();

  return 0;

}




