// Address: 0x14027b480
// Ghidra name: FUN_14027b480
// ============ 0x14027b480 FUN_14027b480 (size=146) ============


undefined8 FUN_14027b480(longlong param_1,longlong param_2)



{

  longlong lVar1;

  int iVar2;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  _guard_check_icall();

  *(undefined4 *)(lVar1 + 0x31) = 0;

  *(undefined4 *)(lVar1 + 0x38) = 0;

  *(undefined8 *)(lVar1 + 0x40) = 0;

  *(undefined1 *)(lVar1 + 0x48) = 0;

  iVar2 = 0xb;

  *(undefined8 *)(lVar1 + 0x5c) = 0;

  *(undefined8 *)(lVar1 + 100) = 0;

  *(undefined8 *)(lVar1 + 0x6c) = 0;

  *(undefined8 *)(lVar1 + 0x74) = 0;

  *(undefined8 *)(lVar1 + 0x7c) = 0;

  *(undefined8 *)(lVar1 + 0x84) = 0;

  *(undefined8 *)(lVar1 + 0x8c) = 0;

  *(undefined8 *)(lVar1 + 0x94) = 0;

  *(undefined4 *)(param_2 + 0x70) = 0xb;

  if (*(char *)(lVar1 + 0x2d) != '\0') {

    iVar2 = 0xc;

    *(undefined4 *)(param_2 + 0x70) = 0xc;

  }

  if (*(char *)(lVar1 + 0x2a) != '\0') {

    *(int *)(param_2 + 0x70) = iVar2 + 4;

  }

  *(undefined4 *)(param_2 + 0x44) = 6;

  *(undefined4 *)(param_2 + 0x60) = 1;

  FUN_1401427d0("SDL_JOYSTICK_HIDAPI_XBOX_ONE_HOME_LED",FUN_14027d260,lVar1);

  return 1;

}




