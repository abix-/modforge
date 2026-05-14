// Address: 0x14014f090
// Ghidra name: FUN_14014f090
// ============ 0x14014f090 FUN_14014f090 (size=120) ============


ulonglong FUN_14014f090(longlong param_1)



{

  char cVar1;

  ulonglong uVar2;

  

  if (param_1 == 0) {

LAB_14014f0ed:

    FUN_14012e850("Parameter \'%s\' is invalid","renderer");

    uVar2 = 0;

  }

  else {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,2);

      if (cVar1 == '\0') goto LAB_14014f0ed;

    }

    if (*(char *)(param_1 + 0x2d8) != '\0') {

      FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

      return 0;

    }

    uVar2 = (ulonglong)*(uint *)(param_1 + 0x2c8);

    if (*(uint *)(param_1 + 0x2c8) == 0) {

      uVar2 = FUN_1401746e0();

      *(int *)(param_1 + 0x2c8) = (int)uVar2;

      return uVar2;

    }

  }

  return uVar2;

}




