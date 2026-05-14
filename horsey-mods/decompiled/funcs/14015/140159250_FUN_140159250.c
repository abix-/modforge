// Address: 0x140159250
// Ghidra name: FUN_140159250
// ============ 0x140159250 FUN_140159250 (size=340) ============


ulonglong FUN_140159250(void)



{

  char cVar1;

  ulonglong uVar2;

  byte bVar3;

  undefined **ppuVar4;

  uint uVar5;

  

  bVar3 = 0;

  if (DAT_1403fc058 == 0) {

    DAT_1403fc058 = FUN_140179a30();

  }

  uVar2 = FUN_14017e460(0x4000);

  if ((char)uVar2 == '\0') {

    return uVar2;

  }

  FUN_140159d30();

  DAT_1403fc068 = 1;

  uVar5 = 0;

  DAT_1403fc080 = FUN_1401aaee0(0,0,&LAB_1401aa980,&LAB_1401aa9c0,&LAB_1401aafe0,0);

  FUN_140159aa0(&PTR_s_SDL_JOYSTICK_OLD_XBOXONE_CONTROL_140333096_2_1403e23b0);

  FUN_140159aa0(&PTR_s_SDL_JOYSTICK_ARCADESTICK_DEVICES_1403e2400);

  FUN_140159aa0(&PTR_s_SDL_JOYSTICK_BLACKLIST_DEVICES_1403e2450);

  FUN_140159aa0(&PTR_s_SDL_JOYSTICK_FLIGHTSTICK_DEVICES_1403e24a0);

  FUN_140159aa0(&PTR_s_SDL_JOYSTICK_GAMECUBE_DEVICES_1403e24f0);

  FUN_140159aa0(&PTR_s_SDL_ROG_GAMEPAD_MICE_1403e2540);

  FUN_140159aa0(&PTR_s_SDL_JOYSTICK_THROTTLE_DEVICES_1403e2590);

  FUN_140159aa0(&PTR_s_SDL_JOYSTICK_WHEEL_DEVICES_1403e25e0);

  FUN_140159aa0(&PTR_s_SDL_JOYSTICK_ZERO_CENTERED_DEVIC_1403e2630);

  FUN_14013f480();

  FUN_1401427d0("SDL_JOYSTICK_ALLOW_BACKGROUND_EVENTS",FUN_140159820,0);

  FUN_140210bb0();

  ppuVar4 = &PTR_PTR_1403e2380;

  do {

    cVar1 = (**(code **)*ppuVar4)();

    ppuVar4 = ppuVar4 + 1;

    if (cVar1 != '\0') {

      bVar3 = 1;

    }

    uVar5 = uVar5 + 1;

  } while (uVar5 < 6);

  FUN_14015bb10();

  if (bVar3 == 0) {

    FUN_14015a670();

  }

  return (ulonglong)bVar3;

}




