// Address: 0x140228c50
// Ghidra name: FUN_140228c50
// ============ 0x140228c50 FUN_140228c50 (size=270) ============


undefined8 FUN_140228c50(longlong param_1,undefined8 param_2)



{

  char cVar1;

  undefined8 uVar2;

  

  if (*(int *)(param_1 + 0x3f0) != 4) {

    cVar1 = FUN_140142940("SDL_VIDEO_FORCE_EGL",0);

    if (cVar1 == '\0') {

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

      uVar2 = FUN_140223210(param_1,param_2);

      return uVar2;

    }

  }

  if (*(longlong *)(param_1 + 0x690) == 0) {

    uVar2 = FUN_1402194f0(param_1,0,0,*(undefined4 *)(param_1 + 0x40c));

    return uVar2;

  }

  return 1;

}




