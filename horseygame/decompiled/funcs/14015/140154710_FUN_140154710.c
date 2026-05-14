// Address: 0x140154710
// Ghidra name: FUN_140154710
// ============ 0x140154710 FUN_140154710 (size=205) ============


undefined1 FUN_140154710(longlong param_1,int param_2)



{

  char cVar1;

  undefined1 uVar2;

  

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,2);

      if (cVar1 == '\0') goto LAB_1401547bd;

    }

    if (*(char *)(param_1 + 0x2d8) != '\0') {

      FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

      return 0;

    }

    if (param_2 == 0x7fffffff) {

      uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","blendMode");

      return uVar2;

    }

    cVar1 = FUN_14014a380(param_1,param_2);

    if (cVar1 == '\0') {

      uVar2 = FUN_14012e850("That operation is not supported");

      return uVar2;

    }

    *(int *)(param_1 + 0x22c) = param_2;

    return 1;

  }

LAB_1401547bd:

  FUN_14012e850("Parameter \'%s\' is invalid","renderer");

  return 0;

}




