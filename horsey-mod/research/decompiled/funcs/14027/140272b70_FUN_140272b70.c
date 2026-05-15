// Address: 0x140272b70
// Ghidra name: FUN_140272b70
// ============ 0x140272b70 FUN_140272b70 (size=78) ============


void FUN_140272b70(longlong param_1)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  FUN_140142b00("SDL_JOYSTICK_ENHANCED_REPORTS",FUN_140274490,lVar1);

  FUN_140142b00("SDL_JOYSTICK_HIDAPI_PS5_PLAYER_LED",FUN_140274520,lVar1);

  *(undefined8 *)(lVar1 + 8) = 0;

  *(undefined2 *)(lVar1 + 0x22) = 0;

  *(undefined1 *)(lVar1 + 0x21) = 0;

  return;

}




