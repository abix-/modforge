// Address: 0x140141170
// Ghidra name: FUN_140141170
// ============ 0x140141170 FUN_140141170 (size=139) ============


void FUN_140141170(void)



{

  longlong lVar1;

  

  _guard_check_icall();

  lVar1 = DAT_1403fbf18;

  while (lVar1 != 0) {

    DAT_1403fbf18 = *(longlong *)(lVar1 + 0x28);

    FUN_1401841e0(*(undefined8 *)(lVar1 + 0x10));

    FUN_1401841e0(*(undefined8 *)(lVar1 + 0x18));

    FUN_1401841e0(lVar1);

    lVar1 = DAT_1403fbf18;

  }

  DAT_1403fbf18 = lVar1;

  FUN_140157990(&PTR_s_SDL_GAMECONTROLLER_IGNORE_DEVICE_1403e1b60);

  FUN_140157990(&PTR_s_SDL_GAMECONTROLLER_IGNORE_DEVICE_1403e1bb0);

  if (DAT_1403fbf38 != 0) {

    FUN_1401aafa0();

    DAT_1403fbf38 = 0;

  }

  return;

}




