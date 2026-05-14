// Address: 0x140151710
// Ghidra name: FUN_140151710
// ============ 0x140151710 FUN_140151710 (size=251) ============


undefined1 FUN_140151710(longlong param_1,longlong param_2,int param_3)



{

  char cVar1;

  undefined1 uVar2;

  uint uVar3;

  ulonglong uVar4;

  

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar1 = FUN_1401aa7c0(param_1,2), cVar1 == '\0')))) {

    FUN_14012e850("Parameter \'%s\' is invalid","renderer");

    return 0;

  }

  if (*(char *)(param_1 + 0x2d8) != '\0') {

    FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

    return 0;

  }

  if (param_2 != 0) {

    if (0 < param_3) {

      uVar4 = 0;

      do {

        cVar1 = FUN_140151600(param_1,uVar4 * 0x10 + param_2);

        if (cVar1 == '\0') {

          return 0;

        }

        uVar3 = (int)uVar4 + 1;

        uVar4 = (ulonglong)uVar3;

      } while ((int)uVar3 < param_3);

    }

    return 1;

  }

  uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","SDL_RenderRects(): rects");

  return uVar2;

}




