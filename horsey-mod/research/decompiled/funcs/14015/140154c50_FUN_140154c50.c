// Address: 0x140154c50
// Ghidra name: FUN_140154c50
// ============ 0x140154c50 FUN_140154c50 (size=157) ============


undefined1 FUN_140154c50(longlong param_1,undefined4 param_2,undefined4 param_3)



{

  char cVar1;

  

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,2);

      if (cVar1 == '\0') goto LAB_140154cc8;

    }

    if (*(char *)(param_1 + 0x2d8) != '\0') {

      FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

      return 0;

    }

    *(undefined4 *)(param_1 + 0x230) = param_2;

    *(undefined4 *)(param_1 + 0x234) = param_3;

    return 1;

  }

LAB_140154cc8:

  FUN_14012e850("Parameter \'%s\' is invalid","renderer");

  return 0;

}




