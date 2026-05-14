// Address: 0x14013e240
// Ghidra name: FUN_14013e240
// ============ 0x14013e240 FUN_14013e240 (size=127) ============


undefined8 FUN_14013e240(undefined8 *param_1,undefined4 param_2)



{

  undefined4 uVar1;

  char cVar2;

  undefined8 uVar3;

  

  FUN_140159d30();

  if (param_1 != (undefined8 *)0x0) {

    if (DAT_1403e3d60 != '\0') {

      cVar2 = FUN_1401aa7c0(param_1,5);

      if (cVar2 == '\0') goto LAB_14013e29a;

    }

    cVar2 = FUN_1401596f0(*param_1);

    if (cVar2 != '\0') {

      uVar1 = *(undefined4 *)((longlong)param_1 + 0x1c);

      FUN_14015bb10();

      uVar3 = FUN_14013e150(uVar1,param_2);

      return uVar3;

    }

  }

LAB_14013e29a:

  FUN_14012e850("Parameter \'%s\' is invalid","gamepad");

  FUN_14015bb10();

  return 0;

}




