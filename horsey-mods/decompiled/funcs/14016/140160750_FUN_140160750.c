// Address: 0x140160750
// Ghidra name: FUN_140160750
// ============ 0x140160750 FUN_140160750 (size=140) ============


void FUN_140160750(char param_1)



{

  longlong lVar1;

  char cVar2;

  longlong lVar3;

  

  lVar3 = FUN_1401611a0();

  if (*(longlong *)(lVar3 + 0x48) == 0) {

    FUN_14012e850("That operation is not supported");

    return;

  }

  cVar2 = FUN_14016f720();

  if (cVar2 == '\0') {

    FUN_14012e850("SDL_CaptureMouse() must be called on the main thread");

    return;

  }

  if (param_1 != '\0') {

    lVar1 = FUN_140183290();

    if (lVar1 == 0) {

      FUN_14012e850("No window has focus");

      return;

    }

  }

  *(char *)(lVar3 + 0xf4) = param_1;

  FUN_140162f40(0);

  return;

}




