// Address: 0x14027a2e0
// Ghidra name: FUN_14027a2e0
// ============ 0x14027a2e0 FUN_14027a2e0 (size=137) ============


undefined4 FUN_14027a2e0(longlong param_1,longlong param_2)



{

  longlong lVar1;

  undefined1 uVar2;

  undefined4 uVar3;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  _guard_check_icall();

  *(longlong *)(lVar1 + 8) = param_2;

  *(undefined8 *)(lVar1 + 0x15) = 0;

  *(undefined8 *)(lVar1 + 0x1d) = 0;

  *(undefined8 *)(lVar1 + 0x25) = 0;

  *(undefined8 *)(lVar1 + 0x2d) = 0;

  *(undefined8 *)(lVar1 + 0x35) = 0;

  *(undefined8 *)(lVar1 + 0x3d) = 0;

  *(undefined8 *)(lVar1 + 0x45) = 0;

  *(undefined8 *)(lVar1 + 0x4d) = 0;

  uVar3 = FUN_140158960(param_2);

  *(undefined4 *)(lVar1 + 0x10) = uVar3;

  uVar2 = FUN_140142940("SDL_JOYSTICK_HIDAPI_XBOX_360_PLAYER_LED",1);

  *(undefined1 *)(lVar1 + 0x14) = uVar2;

  FUN_14027a830(lVar1);

  FUN_1401427d0("SDL_JOYSTICK_HIDAPI_XBOX_360_PLAYER_LED",FUN_14027a7b0,lVar1);

  *(undefined4 *)(param_2 + 0x70) = 0xb;

  *(undefined4 *)(param_2 + 0x44) = 6;

  *(undefined4 *)(param_2 + 0x60) = 1;

  return 1;

}




