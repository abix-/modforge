// Address: 0x140272660
// Ghidra name: FUN_140272660
// ============ 0x140272660 FUN_140272660 (size=271) ============


undefined8 FUN_140272660(longlong param_1,longlong param_2)



{

  longlong lVar1;

  undefined1 uVar2;

  char cVar3;

  undefined4 uVar4;

  undefined8 uVar5;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  _guard_check_icall();

  *(longlong *)(lVar1 + 8) = param_2;

  uVar5 = FUN_140149350();

  *(undefined8 *)(lVar1 + 0x60) = uVar5;

  *(undefined2 *)(lVar1 + 0x23) = 0;

  *(undefined2 *)(lVar1 + 0x6e) = 0;

  *(undefined1 *)(lVar1 + 0x70) = 0;

  *(undefined4 *)(lVar1 + 0x74) = 0;

  *(undefined8 *)(lVar1 + 0x84) = 0;

  *(undefined8 *)(lVar1 + 0x8c) = 0;

  *(undefined8 *)(lVar1 + 0x94) = 0;

  *(undefined8 *)(lVar1 + 0x9c) = 0;

  *(undefined8 *)(lVar1 + 0xa4) = 0;

  *(undefined8 *)(lVar1 + 0xac) = 0;

  *(undefined8 *)(lVar1 + 0xb4) = 0;

  *(undefined8 *)(lVar1 + 0xbc) = 0;

  uVar4 = FUN_140158960(param_2);

  *(undefined4 *)(lVar1 + 0x68) = uVar4;

  uVar2 = FUN_140142940("SDL_JOYSTICK_HIDAPI_PS5_PLAYER_LED",1);

  *(undefined1 *)(lVar1 + 0x6c) = uVar2;

  cVar3 = FUN_140159400(*(undefined2 *)(param_1 + 0x20),*(undefined2 *)(param_1 + 0x22));

  if (cVar3 == '\0') {

    uVar4 = 0xb;

    if (*(char *)(lVar1 + 0x16) != '\0') {

      uVar4 = 0xd;

    }

    *(undefined4 *)(param_2 + 0x70) = uVar4;

  }

  else {

    *(undefined4 *)(param_2 + 0x70) = 0x11;

  }

  *(undefined4 *)(param_2 + 0x44) = 6;

  *(undefined4 *)(param_2 + 0x60) = 1;

  *(undefined2 *)(param_2 + 0x30) = *(undefined2 *)(lVar1 + 0x58);

  if (*(char *)(lVar1 + 0x10) != '\0') {

    *(undefined4 *)(param_2 + 0xe4) = 2;

  }

  FUN_1401427d0("SDL_JOYSTICK_ENHANCED_REPORTS",FUN_140274490,lVar1);

  FUN_1401427d0("SDL_JOYSTICK_HIDAPI_PS5_PLAYER_LED",FUN_140274520,lVar1);

  return 1;

}




