// Address: 0x14013e850
// Ghidra name: FUN_14013e850
// ============ 0x14013e850 FUN_14013e850 (size=132) ============


undefined8 FUN_14013e850(longlong *param_1)



{

  longlong lVar1;

  char cVar2;

  undefined8 uVar3;

  undefined4 local_18;

  undefined4 uStack_14;

  undefined4 uStack_10;

  undefined4 uStack_c;

  

  FUN_140159d30();

  if (param_1 != (longlong *)0x0) {

    if (DAT_1403e3d60 != '\0') {

      cVar2 = FUN_1401aa7c0(param_1,5);

      if (cVar2 == '\0') goto LAB_14013e8b4;

    }

    cVar2 = FUN_1401596f0(*param_1);

    if (cVar2 != '\0') {

      lVar1 = *param_1;

      local_18 = *(undefined4 *)(lVar1 + 0x20);

      uStack_14 = *(undefined4 *)(lVar1 + 0x24);

      uStack_10 = *(undefined4 *)(lVar1 + 0x28);

      uStack_c = *(undefined4 *)(lVar1 + 0x2c);

      uVar3 = FUN_14013c130(param_1[4],&local_18);

      FUN_14015bb10();

      return uVar3;

    }

  }

LAB_14013e8b4:

  FUN_14012e850("Parameter \'%s\' is invalid","gamepad");

  FUN_14015bb10();

  return 0;

}




