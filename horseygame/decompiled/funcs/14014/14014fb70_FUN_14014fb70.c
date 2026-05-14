// Address: 0x14014fb70
// Ghidra name: FUN_14014fb70
// ============ 0x14014fb70 FUN_14014fb70 (size=106) ============


undefined1 FUN_14014fb70(longlong param_1)



{

  char cVar1;

  undefined1 uVar2;

  

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,2);

      if (cVar1 == '\0') goto LAB_14014fbbf;

    }

    if (*(char *)(param_1 + 0x2d8) != '\0') {

      FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

      return 0;

    }

    uVar2 = FUN_14014a540(param_1);

    return uVar2;

  }

LAB_14014fbbf:

  FUN_14012e850("Parameter \'%s\' is invalid","renderer");

  return 0;

}




