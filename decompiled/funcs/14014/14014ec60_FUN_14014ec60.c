// Address: 0x14014ec60
// Ghidra name: FUN_14014ec60
// ============ 0x14014ec60 FUN_14014ec60 (size=135) ============


undefined8 FUN_14014ec60(longlong param_1)



{

  longlong lVar1;

  char cVar2;

  undefined4 uVar3;

  undefined8 uVar4;

  

  if (param_1 == 0) {

LAB_14014eccc:

    FUN_14012e850("Parameter \'%s\' is invalid","renderer");

  }

  else {

    if (DAT_1403e3d60 != '\0') {

      cVar2 = FUN_1401aa7c0(param_1,2);

      if (cVar2 == '\0') goto LAB_14014eccc;

    }

    if (*(char *)(param_1 + 0x2d8) != '\0') {

      FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

      return 0;

    }

    lVar1 = *(longlong *)(param_1 + 0x1f0);

    if (lVar1 != 0) {

      uVar3 = FUN_14014f530(lVar1);

      uVar4 = FUN_140174d30(uVar3,"SDL.internal.texture.parent",lVar1);

      return uVar4;

    }

  }

  return 0;

}




