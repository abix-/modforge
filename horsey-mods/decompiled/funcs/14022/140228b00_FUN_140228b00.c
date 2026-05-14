// Address: 0x140228b00
// Ghidra name: FUN_140228b00
// ============ 0x140228b00 FUN_140228b00 (size=296) ============


undefined8 FUN_140228b00(longlong param_1,longlong param_2)



{

  longlong lVar1;

  char cVar2;

  undefined8 uVar3;

  

  lVar1 = *(longlong *)(param_2 + 0x188);

  if (*(int *)(param_1 + 0x3f0) != 4) {

    cVar2 = FUN_140142940("SDL_VIDEO_FORCE_EGL",0);

    if (cVar2 == '\0') {

      FUN_14021a5f0(param_1);

      *(undefined8 *)(param_1 + 0x1c8) = 0;

      *(code **)(param_1 + 0x1a0) = FUN_140223210;

      *(code **)(param_1 + 0x1a8) = FUN_140222e00;

      *(code **)(param_1 + 0x1b0) = FUN_140223900;

      *(code **)(param_1 + 0x1b8) = FUN_140222a60;

      *(code **)(param_1 + 0x1c0) = FUN_140223390;

      *(code **)(param_1 + 0x1d0) = FUN_140223420;

      *(code **)(param_1 + 0x1d8) = FUN_140222e50;

      *(code **)(param_1 + 0x1e0) = FUN_1402238d0;

      *(code **)(param_1 + 0x1e8) = FUN_140222de0;

      cVar2 = FUN_140223210(param_1,0);

      if (cVar2 == '\0') {

        return 0;

      }

      uVar3 = FUN_140222a60(param_1,param_2);

      return uVar3;

    }

  }

  uVar3 = FUN_140218860(param_1,*(undefined8 *)(lVar1 + 200));

  return uVar3;

}




