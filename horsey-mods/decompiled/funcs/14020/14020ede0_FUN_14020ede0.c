// Address: 0x14020ede0
// Ghidra name: FUN_14020ede0
// ============ 0x14020ede0 FUN_14020ede0 (size=103) ============


undefined1 FUN_14020ede0(void)



{

  char cVar1;

  

  cVar1 = FUN_140285480();

  if ((cVar1 == '\0') || (cVar1 = FUN_140286550(), cVar1 == '\0')) {

    FUN_14020ed40();

    return 0;

  }

  FUN_1402205c0();

  DAT_1403fd310 = FUN_140142940("SDL_JOYSTICK_THREAD",1);

  if (DAT_1403fd310 == '\0') {

    cVar1 = FUN_14020f170(&DAT_1403fd330);

  }

  else {

    cVar1 = FUN_14020f490();

  }

  if (cVar1 == '\0') {

    return 0;

  }

  FUN_14020f650();

  FUN_14020ec00();

  return 1;

}




