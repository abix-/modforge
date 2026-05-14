// Address: 0x1402709a0
// Ghidra name: FUN_1402709a0
// ============ 0x1402709a0 FUN_1402709a0 (size=78) ============


void FUN_1402709a0(longlong param_1)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  FUN_140142b00("SDL_JOYSTICK_HIDAPI_PS4_REPORT_INTERVAL",FUN_140271fa0,lVar1);

  FUN_140142b00("SDL_JOYSTICK_ENHANCED_REPORTS",FUN_140271f10,lVar1);

  *(undefined8 *)(lVar1 + 8) = 0;

  *(undefined1 *)(lVar1 + 0x24) = 0;

  *(undefined2 *)(lVar1 + 0x21) = 0;

  return;

}




