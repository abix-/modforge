// Address: 0x140154ab0
// Ghidra name: FUN_140154ab0
// ============ 0x140154ab0 FUN_140154ab0 (size=404) ============


bool FUN_140154ab0(longlong param_1,longlong param_2)



{

  char cVar1;

  undefined1 uVar2;

  longlong lVar3;

  char *pcVar4;

  

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar1 = FUN_1401aa7c0(param_1,2), cVar1 == '\0')))) {

    pcVar4 = "renderer";

LAB_140154c2b:

    FUN_14012e850("Parameter \'%s\' is invalid",pcVar4);

  }

  else {

    if (*(char *)(param_1 + 0x2d8) != '\0') {

      FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

      return false;

    }

    if (param_2 != 0) {

      if ((DAT_1403e3d60 != '\0') && (cVar1 = FUN_1401aa7c0(param_2,3), cVar1 == '\0')) {

        pcVar4 = "texture";

        goto LAB_140154c2b;

      }

      if (param_1 != *(longlong *)(param_2 + 0x10)) {

        uVar2 = FUN_14012e850("Texture was not created with this renderer");

        return (bool)uVar2;

      }

      if (*(int *)(param_2 + 0x24) != 2) {

        uVar2 = FUN_14012e850("Texture not created with SDL_TEXTUREACCESS_TARGET");

        return (bool)uVar2;

      }

      if (*(longlong *)(param_2 + 0xf8) != 0) {

        param_2 = *(longlong *)(param_2 + 0xf8);

      }

    }

    if (param_2 == *(longlong *)(param_1 + 0x1f0)) {

      return true;

    }

    FUN_140149cf0(param_1);

    FUN_140179b40(*(undefined8 *)(param_1 + 0x1f8));

    *(longlong *)(param_1 + 0x1f0) = param_2;

    lVar3 = param_2 + 0x40;

    if (param_2 == 0) {

      lVar3 = param_1 + 0x140;

    }

    *(longlong *)(param_1 + 0x138) = lVar3;

    FUN_140156820(param_1);

    cVar1 = (**(code **)(param_1 + 0xb8))();

    if (cVar1 == '\0') {

      FUN_140179b60(*(undefined8 *)(param_1 + 0x1f8));

      return false;

    }

    FUN_140179b60(*(undefined8 *)(param_1 + 0x1f8));

    cVar1 = FUN_14014af50(param_1);

    if (cVar1 != '\0') {

      cVar1 = FUN_14014adb0(param_1);

      return cVar1 != '\0';

    }

  }

  return false;

}




