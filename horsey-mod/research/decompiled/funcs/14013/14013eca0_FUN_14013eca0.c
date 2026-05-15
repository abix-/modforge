// Address: 0x14013eca0
// Ghidra name: FUN_14013eca0
// ============ 0x14013eca0 FUN_14013eca0 (size=112) ============


undefined4 FUN_14013eca0(undefined8 *param_1)



{

  char cVar1;

  undefined4 uVar2;

  

  FUN_140159d30();

  if (param_1 != (undefined8 *)0x0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,5);

      if (cVar1 == '\0') goto LAB_14013ecf0;

    }

    cVar1 = FUN_1401596f0(*param_1);

    if (cVar1 != '\0') {

      uVar2 = FUN_140158c10(*param_1);

      FUN_14015bb10();

      return uVar2;

    }

  }

LAB_14013ecf0:

  FUN_14012e850("Parameter \'%s\' is invalid","gamepad");

  FUN_14015bb10();

  return 0;

}




