// Address: 0x14013f130
// Ghidra name: FUN_14013f130
// ============ 0x14013f130 FUN_14013f130 (size=136) ============


undefined4 FUN_14013f130(undefined8 *param_1)



{

  undefined4 uVar1;

  char cVar2;

  longlong lVar3;

  

  FUN_140159d30();

  if (param_1 != (undefined8 *)0x0) {

    if (DAT_1403e3d60 != '\0') {

      cVar2 = FUN_1401aa7c0(param_1,5);

      if (cVar2 == '\0') goto LAB_14013f198;

    }

    cVar2 = FUN_1401596f0(*param_1);

    if (cVar2 != '\0') {

      lVar3 = FUN_140158f10(*(undefined4 *)*param_1);

      if (lVar3 != 0) {

        uVar1 = *(undefined4 *)(lVar3 + 0x14);

        FUN_14015bb10();

        return uVar1;

      }

      uVar1 = *(undefined4 *)(param_1 + 3);

      FUN_14015bb10();

      return uVar1;

    }

  }

LAB_14013f198:

  FUN_14012e850("Parameter \'%s\' is invalid","gamepad");

  FUN_14015bb10();

  return 0;

}




