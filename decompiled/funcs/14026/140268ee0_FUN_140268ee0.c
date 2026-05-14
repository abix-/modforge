// Address: 0x140268ee0
// Ghidra name: FUN_140268ee0
// ============ 0x140268ee0 FUN_140268ee0 (size=151) ============


void FUN_140268ee0(longlong param_1)



{

  longlong lVar1;

  char *pcVar2;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  if ((*(char *)(lVar1 + 0x10) == '\0') &&

     ((*(char *)(lVar1 + 0x24) == '\0' || (*(char *)(lVar1 + 0x24) == '?')))) {

    FUN_14026cf10(lVar1,0x3f);

  }

  FUN_140142b00("SDL_JOYSTICK_ENHANCED_REPORTS",FUN_14026ca70,lVar1);

  if ((*(int *)(lVar1 + 0x20) == 1) ||

     (pcVar2 = "SDL_JOYSTICK_HIDAPI_SWITCH_HOME_LED", *(int *)(lVar1 + 0x20) == 2)) {

    pcVar2 = "SDL_JOYSTICK_HIDAPI_JOYCON_HOME_LED";

  }

  FUN_140142b00(pcVar2,FUN_14026cae0,lVar1);

  FUN_140142b00("SDL_JOYSTICK_HIDAPI_SWITCH_PLAYER_LED",FUN_14026cb70,lVar1);

  *(undefined8 *)(lVar1 + 8) = 0;

  *(undefined1 *)(lVar1 + 0x99) = 0;

  *(undefined2 *)(lVar1 + 0x34) = 0;

  return;

}




