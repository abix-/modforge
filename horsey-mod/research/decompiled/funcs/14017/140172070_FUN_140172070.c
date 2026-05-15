// Address: 0x140172070
// Ghidra name: FUN_140172070
// ============ 0x140172070 FUN_140172070 (size=287) ============


bool FUN_140172070(longlong param_1,longlong param_2)



{

  char cVar1;

  undefined1 uVar2;

  int iVar3;

  longlong lVar4;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return false;

  }

  if ((param_1 != 0) &&

     ((DAT_1403e3d60 == '\0' || (cVar1 = FUN_1401aa7c0(param_1,1), cVar1 != '\0')))) {

    if ((*(uint *)(param_1 + 0x48) >> 0x1e & 1) == 0) {

      uVar2 = FUN_14012e850("Window must be created with SDL_WINDOW_TRANSPARENT");

      return (bool)uVar2;

    }

    iVar3 = FUN_14016ea50(param_1);

    if (iVar3 != 0) {

      lVar4 = 0;

      if ((param_2 != 0) && (lVar4 = FUN_140145bb0(param_2,0x16862004), lVar4 == 0)) {

        return false;

      }

      cVar1 = FUN_1401755a0(iVar3,"SDL.window.shape",lVar4);

      if (cVar1 != '\0') {

        if (*(code **)(DAT_1403fc410 + 0x168) == (code *)0x0) {

          return true;

        }

        cVar1 = (**(code **)(DAT_1403fc410 + 0x168))(DAT_1403fc410,param_1,lVar4);

        return cVar1 != '\0';

      }

    }

    return false;

  }

  FUN_14012e850("Invalid window");

  return false;

}




