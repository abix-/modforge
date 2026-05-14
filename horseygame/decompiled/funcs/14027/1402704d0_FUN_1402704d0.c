// Address: 0x1402704d0
// Ghidra name: FUN_1402704d0
// ============ 0x1402704d0 FUN_1402704d0 (size=192) ============


undefined8 FUN_1402704d0(longlong param_1,longlong param_2)



{

  longlong lVar1;

  undefined4 uVar2;

  undefined8 uVar3;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  _guard_check_icall();

  *(longlong *)(lVar1 + 8) = param_2;

  uVar3 = FUN_140149350();

  *(undefined8 *)(lVar1 + 0x58) = uVar3;

  *(undefined2 *)(lVar1 + 0x24) = 0;

  *(undefined2 *)(lVar1 + 100) = 0;

  *(undefined1 *)(lVar1 + 0x66) = 0;

  *(undefined8 *)(lVar1 + 0x84) = 0;

  *(undefined8 *)(lVar1 + 0x8c) = 0;

  *(undefined8 *)(lVar1 + 0x94) = 0;

  *(undefined8 *)(lVar1 + 0x9c) = 0;

  *(undefined8 *)(lVar1 + 0xa4) = 0;

  *(undefined8 *)(lVar1 + 0xac) = 0;

  *(undefined4 *)(lVar1 + 0xb4) = 0;

  *(undefined2 *)(lVar1 + 0xb8) = 0;

  uVar2 = FUN_140158960(param_2);

  *(undefined4 *)(lVar1 + 0x60) = uVar2;

  *(undefined4 *)(param_2 + 0x70) = 0xb;

  if (*(char *)(lVar1 + 0x16) != '\0') {

    *(undefined4 *)(param_2 + 0x70) = 0xc;

  }

  *(undefined4 *)(param_2 + 0x44) = 6;

  *(undefined4 *)(param_2 + 0x60) = 1;

  FUN_1401427d0("SDL_JOYSTICK_HIDAPI_PS4_REPORT_INTERVAL",FUN_140271fa0,lVar1);

  FUN_1401427d0("SDL_JOYSTICK_ENHANCED_REPORTS",FUN_140271f10,lVar1);

  return 1;

}




