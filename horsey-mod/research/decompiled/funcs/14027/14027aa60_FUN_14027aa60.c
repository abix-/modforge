// Address: 0x14027aa60
// Ghidra name: FUN_14027aa60
// ============ 0x14027aa60 FUN_14027aa60 (size=143) ============


undefined4 FUN_14027aa60(longlong param_1,longlong param_2)



{

  longlong lVar1;

  undefined1 uVar2;

  undefined4 uVar3;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  _guard_check_icall();

  *(undefined8 *)(lVar1 + 0x11) = 0;

  *(undefined8 *)(lVar1 + 0x19) = 0;

  *(undefined8 *)(lVar1 + 0x21) = 0;

  *(undefined8 *)(lVar1 + 0x29) = 0;

  *(undefined8 *)(lVar1 + 0x31) = 0;

  *(undefined8 *)(lVar1 + 0x39) = 0;

  *(undefined8 *)(lVar1 + 0x41) = 0;

  *(undefined8 *)(lVar1 + 0x49) = 0;

  uVar3 = FUN_140158960(param_2);

  *(undefined4 *)(lVar1 + 0xc) = uVar3;

  uVar2 = FUN_140142940("SDL_JOYSTICK_HIDAPI_XBOX_360_PLAYER_LED",1);

  *(undefined1 *)(lVar1 + 0x10) = uVar2;

  FUN_14027b0c0(lVar1);

  FUN_1401427d0("SDL_JOYSTICK_HIDAPI_XBOX_360_PLAYER_LED",FUN_14027afd0,lVar1);

  *(undefined4 *)(param_2 + 0x70) = 0xb;

  *(undefined4 *)(param_2 + 0x44) = 6;

  *(undefined4 *)(param_2 + 0x60) = 1;

  *(undefined4 *)(param_2 + 0xe4) = 2;

  return 1;

}




