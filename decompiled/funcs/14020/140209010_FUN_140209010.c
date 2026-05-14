// Address: 0x140209010
// Ghidra name: FUN_140209010
// ============ 0x140209010 FUN_140209010 (size=66) ============


undefined4 FUN_140209010(void)



{

  char cVar1;

  int iVar2;

  

  cVar1 = FUN_140142940("SDL_JOYSTICK_RAWINPUT",0);

  if (cVar1 == '\0') {

    return 1;

  }

  iVar2 = FUN_1401a9990();

  if ((iVar2 != 0) && (cVar1 = FUN_140220700(), cVar1 != '\0')) {

    DAT_1403fd1b0 = 1;

    FUN_140209ec0();

    return 1;

  }

  return 0;

}




