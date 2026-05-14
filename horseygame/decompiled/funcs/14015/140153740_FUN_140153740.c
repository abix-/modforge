// Address: 0x140153740
// Ghidra name: FUN_140153740
// ============ 0x140153740 FUN_140153740 (size=120) ============


ulonglong FUN_140153740(longlong param_1)



{

  char cVar1;

  ulonglong uVar2;

  

  if (param_1 == 0) {

LAB_14015379d:

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","renderer");

  }

  else {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,2);

      if (cVar1 == '\0') goto LAB_14015379d;

    }

    if (*(char *)(param_1 + 0x2d8) != '\0') {

      uVar2 = FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

      return uVar2 & 0xffffffffffffff00;

    }

    uVar2 = *(ulonglong *)(param_1 + 0x138);

    if ((-1 < *(int *)(uVar2 + 0x10)) && (-1 < *(int *)(uVar2 + 0x14))) {

      return CONCAT71((int7)(uVar2 >> 8),1);

    }

  }

  return uVar2 & 0xffffffffffffff00;

}




