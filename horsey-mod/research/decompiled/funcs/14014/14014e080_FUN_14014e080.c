// Address: 0x14014e080
// Ghidra name: FUN_14014e080
// ============ 0x14014e080 FUN_14014e080 (size=143) ============


longlong FUN_14014e080(longlong param_1)



{

  char cVar1;

  undefined4 uVar2;

  longlong lVar3;

  

  if (param_1 == 0) {

LAB_14014e0f4:

    FUN_14012e850("Parameter \'%s\' is invalid","renderer");

    lVar3 = 0;

  }

  else {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,2);

      if (cVar1 == '\0') goto LAB_14014e0f4;

    }

    if (*(char *)(param_1 + 0x2d8) != '\0') {

      FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

      return 0;

    }

    uVar2 = FUN_14014f090(param_1);

    lVar3 = FUN_140174d30(uVar2,"SDL.renderer.gpu.device",0);

    if (lVar3 == 0) {

      FUN_14012e850("Renderer isn\'t a GPU renderer");

      return 0;

    }

  }

  return lVar3;

}




