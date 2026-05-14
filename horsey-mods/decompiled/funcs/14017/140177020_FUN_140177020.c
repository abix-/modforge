// Address: 0x140177020
// Ghidra name: FUN_140177020
// ============ 0x140177020 FUN_140177020 (size=103) ============


undefined8 FUN_140177020(longlong param_1)



{

  char cVar1;

  undefined8 uVar2;

  

  FUN_140177410();

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,7);

      if (cVar1 == '\0') goto LAB_140177067;

    }

    uVar2 = FUN_1401aa890(*(undefined8 *)(param_1 + 8));

    FUN_140177750();

    return uVar2;

  }

LAB_140177067:

  FUN_14012e850("Parameter \'%s\' is invalid","sensor");

  FUN_140177750();

  return 0;

}




