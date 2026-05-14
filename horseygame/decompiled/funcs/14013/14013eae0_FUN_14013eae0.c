// Address: 0x14013eae0
// Ghidra name: FUN_14013eae0
// ============ 0x14013eae0 FUN_14013eae0 (size=170) ============


undefined8 FUN_14013eae0(longlong *param_1)



{

  char cVar1;

  int iVar2;

  undefined8 uVar3;

  

  FUN_140159d30();

  if (param_1 != (longlong *)0x0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,5);

      if (cVar1 == '\0') goto LAB_14013eb6a;

    }

    cVar1 = FUN_1401596f0(*param_1);

    if (cVar1 != '\0') {

      iVar2 = strcmp((char *)param_1[2],"*");

      if ((iVar2 != 0) && (*(longlong *)(*param_1 + 0x38) == 0)) {

        uVar3 = FUN_1401aa890(param_1[2]);

        FUN_14015bb10();

        return uVar3;

      }

      uVar3 = FUN_1401587b0(*param_1);

      FUN_14015bb10();

      return uVar3;

    }

  }

LAB_14013eb6a:

  FUN_14012e850("Parameter \'%s\' is invalid","gamepad");

  FUN_14015bb10();

  return 0;

}




