// Address: 0x14018d6c0
// Ghidra name: FUN_14018d6c0
// ============ 0x14018d6c0 FUN_14018d6c0 (size=51) ============


undefined8 FUN_14018d6c0(longlong *param_1)



{

  char cVar1;

  

  if ((*(uint *)(*param_1 + 0x48) & 0xc0000) == 0) {

    cVar1 = FUN_140142940("SDL_MOUSE_FOCUS_CLICKTHROUGH",0);

    if (cVar1 == '\0') {

      return 1;

    }

  }

  return 0;

}




