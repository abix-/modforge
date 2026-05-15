// Address: 0x140162430
// Ghidra name: FUN_140162430
// ============ 0x140162430 FUN_140162430 (size=720) ============


void FUN_140162430(void)



{

  longlong lVar1;

  ulonglong uVar2;

  uint uVar3;

  ulonglong uVar4;

  longlong lVar5;

  

  lVar1 = FUN_1401611a0();

  DAT_1403fc32c = 0;

  if (*(char *)(lVar1 + 0xf1) != '\0') {

    FUN_140186110(0xffffffffffffffff);

    *(undefined1 *)(lVar1 + 0xf1) = 0;

  }

  if (*(char *)(lVar1 + 0xf2) != '\0') {

    FUN_140186110(0xfffffffffffffffe);

    *(undefined1 *)(lVar1 + 0xf2) = 0;

  }

  if (*(longlong *)(lVar1 + 0x48) != 0) {

    FUN_140160750(0);

    FUN_140162f40(1);

  }

  FUN_140162d10(0);

  FUN_140162e60();

  if (*(longlong *)(lVar1 + 0x118) != 0) {

    FUN_140162be0(0);

  }

  lVar5 = *(longlong *)(lVar1 + 0x110);

  while (lVar5 != 0) {

    lVar5 = *(longlong *)(lVar5 + 0x10);

    FUN_140160eb0();

  }

  uVar2 = 0;

  *(undefined8 *)(lVar1 + 0x110) = 0;

  *(undefined8 *)(lVar1 + 0x120) = 0;

  if (*(longlong *)(lVar1 + 0x108) != 0) {

    uVar4 = uVar2;

    if (0 < *(int *)(lVar1 + 0x100)) {

      do {

        FUN_1401841e0(*(undefined8 *)(uVar4 + 0x10 + *(longlong *)(lVar1 + 0x108)));

        uVar3 = (int)uVar2 + 1;

        uVar2 = (ulonglong)uVar3;

        uVar4 = uVar4 + 0x18;

      } while ((int)uVar3 < *(int *)(lVar1 + 0x100));

    }

    FUN_1401841e0(*(undefined8 *)(lVar1 + 0x108));

    *(undefined8 *)(lVar1 + 0x108) = 0;

  }

  *(undefined4 *)(lVar1 + 0x100) = 0;

  FUN_140142b00("SDL_MOUSE_DOUBLE_CLICK_TIME",FUN_140161580,lVar1);

  FUN_140142b00("SDL_MOUSE_DOUBLE_CLICK_RADIUS",FUN_140161540,lVar1);

  FUN_140142b00("SDL_MOUSE_NORMAL_SPEED_SCALE",FUN_1401615f0,lVar1);

  FUN_140142b00("SDL_MOUSE_RELATIVE_SPEED_SCALE",FUN_1401616e0,lVar1);

  FUN_140142b00("SDL_MOUSE_RELATIVE_SYSTEM_SCALE",FUN_140161740,lVar1);

  FUN_140142b00("SDL_MOUSE_RELATIVE_MODE_CENTER",FUN_1401616c0,lVar1);

  FUN_140142b00("SDL_MOUSE_EMULATE_WARP_WITH_RELATIVE",FUN_1401617f0,lVar1);

  FUN_140142b00("SDL_TOUCH_MOUSE_EVENTS",FUN_140162eb0,lVar1);

  FUN_140142b00("SDL_MOUSE_TOUCH_EVENTS",FUN_140161780,lVar1);

  FUN_140142b00("SDL_PEN_MOUSE_EVENTS",FUN_140161830,lVar1);

  FUN_140142b00("SDL_PEN_TOUCH_EVENTS",FUN_140161850,lVar1);

  FUN_140142b00("SDL_MOUSE_AUTO_CAPTURE",FUN_140161500,lVar1);

  FUN_140142b00("SDL_MOUSE_RELATIVE_WARP_MOTION",FUN_140161760,lVar1);

  FUN_140142b00("SDL_MOUSE_RELATIVE_CURSOR_VISIBLE",FUN_140161690,lVar1);

  FUN_140142b00("SDL_MOUSE_INTEGER_MODE",FUN_1401615c0,lVar1);

  lVar5 = (longlong)DAT_1403fc328;

  while (lVar5 != 0) {

    lVar5 = lVar5 + -1;

    FUN_140162780(*(undefined4 *)(DAT_1403fc330 + lVar5 * 4));

  }

  FUN_1401841e0(DAT_1403fc330);

  DAT_1403fc330 = 0;

  FUN_1401aafa0(DAT_1403fc338);

  DAT_1403fc338 = 0;

  if (*(longlong *)(lVar1 + 0x130) != 0) {

    FUN_1401841e0();

  }

  FUN_1402f94c0(lVar1,0,0x138);

  return;

}




