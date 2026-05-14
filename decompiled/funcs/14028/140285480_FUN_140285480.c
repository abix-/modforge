// Address: 0x140285480
// Ghidra name: FUN_140285480
// ============ 0x140285480 FUN_140285480 (size=69) ============


undefined1 FUN_140285480(void)



{

  char cVar1;

  char cVar2;

  

  cVar1 = FUN_140142940("SDL_XINPUT_ENABLED");

  if (cVar1 != '\0') {

    cVar2 = FUN_140284e70();

    if (cVar2 == '\0') {

      cVar1 = '\0';

    }

    DAT_1403fde20 = cVar1;

    return 1;

  }

  DAT_1403fde20 = cVar1;

  return 1;

}




