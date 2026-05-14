// Address: 0x14015a670
// Ghidra name: FUN_14015a670
// ============ 0x14015a670 FUN_14015a670 (size=407) ============


void FUN_14015a670(void)



{

  int iVar1;

  int *piVar2;

  longlong lVar3;

  undefined **ppuVar4;

  

  FUN_140159d30();

  DAT_1403fc069 = 1;

  piVar2 = (int *)FUN_140158f60(0);

  lVar3 = DAT_1403fc070;

  if (piVar2 != (int *)0x0) {

    iVar1 = *piVar2;

    if (iVar1 != 0) {

      lVar3 = 0;

      do {

        FUN_14015a550(iVar1);

        iVar1 = piVar2[lVar3 + 1];

        lVar3 = lVar3 + 1;

      } while (iVar1 != 0);

    }

    FUN_1401841e0(piVar2);

    lVar3 = DAT_1403fc070;

  }

  while (lVar3 != 0) {

    DAT_1403fc070 = lVar3;

    *(undefined4 *)(lVar3 + 0x154) = 1;

    FUN_1401575b0(lVar3);

    lVar3 = DAT_1403fc070;

  }

  ppuVar4 = &PTR_PTR_1403e23a8;

  DAT_1403fc070 = 0;

  do {

    (**(code **)(*ppuVar4 + 0x98))();

    ppuVar4 = ppuVar4 + -1;

  } while (0x1403e237f < (longlong)ppuVar4);

  if (DAT_1403fc078 != 0) {

    FUN_1401841e0();

    DAT_1403fc078 = 0;

    DAT_1403fc06c = 0;

  }

  FUN_14017e880(0x4000);

  FUN_140210c00();

  FUN_140142b00("SDL_JOYSTICK_ALLOW_BACKGROUND_EVENTS",FUN_140159820,0);

  FUN_140157990(&PTR_s_SDL_JOYSTICK_OLD_XBOXONE_CONTROL_140333096_2_1403e23b0);

  FUN_140157990(&PTR_s_SDL_JOYSTICK_ARCADESTICK_DEVICES_1403e2400);

  FUN_140157990(&PTR_s_SDL_JOYSTICK_BLACKLIST_DEVICES_1403e2450);

  FUN_140157990(&PTR_s_SDL_JOYSTICK_FLIGHTSTICK_DEVICES_1403e24a0);

  FUN_140157990(&PTR_s_SDL_JOYSTICK_GAMECUBE_DEVICES_1403e24f0);

  FUN_140157990(&PTR_s_SDL_ROG_GAMEPAD_MICE_1403e2540);

  FUN_140157990(&PTR_s_SDL_JOYSTICK_THROTTLE_DEVICES_1403e2590);

  FUN_140157990(&PTR_s_SDL_JOYSTICK_WHEEL_DEVICES_1403e25e0);

  FUN_140157990(&PTR_s_SDL_JOYSTICK_ZERO_CENTERED_DEVIC_1403e2630);

  FUN_140141170();

  if (DAT_1403fc080 != 0) {

    FUN_1401aafa0();

    DAT_1403fc080 = 0;

  }

  DAT_1403fc069 = 0;

  DAT_1403fc068 = 0;

  FUN_14015bb10();

  return;

}




