// Address: 0x140278540
// Ghidra name: FUN_140278540
// ============ 0x140278540 FUN_140278540 (size=46) ============


void FUN_140278540(longlong param_1)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  FUN_140142b00("SDL_JOYSTICK_HIDAPI_WII_PLAYER_LED",FUN_140279cf0,lVar1);

  *(undefined8 *)(lVar1 + 8) = 0;

  return;

}




