// Address: 0x140276510
// Ghidra name: FUN_140276510
// ============ 0x140276510 FUN_140276510 (size=66) ============


void FUN_140276510(longlong param_1)



{

  undefined8 uVar1;

  char cVar2;

  

  uVar1 = *(undefined8 *)(param_1 + 0x70);

  cVar2 = FUN_140276ba0(*(undefined2 *)(param_1 + 0x22));

  if (cVar2 != '\0') {

    FUN_140142b00("SDL_JOYSTICK_HIDAPI_STEAM_PAIRING_ENABLED",FUN_140277040,uVar1);

    FUN_140276b20(uVar1,0);

    return;

  }

  return;

}




