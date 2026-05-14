// Address: 0x14014f020
// Ghidra name: FUN_14014f020
// ============ 0x14014f020 FUN_14014f020 (size=110) ============


undefined8 FUN_14014f020(longlong param_1)



{

  char cVar1;

  undefined8 uVar2;

  

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,2);

      if (cVar1 == '\0') goto LAB_14014f073;

    }

    if (*(char *)(param_1 + 0x2d8) != '\0') {

      FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

      return 0;

    }

    uVar2 = FUN_1401aa890(*(undefined8 *)(param_1 + 0x100));

    return uVar2;

  }

LAB_14014f073:

  FUN_14012e850("Parameter \'%s\' is invalid","renderer");

  return 0;

}




