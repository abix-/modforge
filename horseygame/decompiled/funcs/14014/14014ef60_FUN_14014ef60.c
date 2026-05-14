// Address: 0x14014ef60
// Ghidra name: FUN_14014ef60
// ============ 0x14014ef60 FUN_14014ef60 (size=106) ============


undefined8 FUN_14014ef60(longlong param_1)



{

  char cVar1;

  

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,2);

      if (cVar1 == '\0') goto LAB_14014efaf;

    }

    if (*(char *)(param_1 + 0x2d8) != '\0') {

      FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

      return 0;

    }

    return *(undefined8 *)(param_1 + 0x118);

  }

LAB_14014efaf:

  FUN_14012e850("Parameter \'%s\' is invalid","renderer");

  return 0;

}




