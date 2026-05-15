// Address: 0x14013e670
// Ghidra name: FUN_14013e670
// ============ 0x14013e670 FUN_14013e670 (size=106) ============


undefined8 FUN_14013e670(undefined8 *param_1)



{

  undefined8 uVar1;

  char cVar2;

  

  FUN_140159d30();

  if (param_1 != (undefined8 *)0x0) {

    if (DAT_1403e3d60 != '\0') {

      cVar2 = FUN_1401aa7c0(param_1,5);

      if (cVar2 == '\0') goto LAB_14013e6ba;

    }

    cVar2 = FUN_1401596f0(*param_1);

    if (cVar2 != '\0') {

      uVar1 = *param_1;

      FUN_14015bb10();

      return uVar1;

    }

  }

LAB_14013e6ba:

  FUN_14012e850("Parameter \'%s\' is invalid","gamepad");

  FUN_14015bb10();

  return 0;

}




