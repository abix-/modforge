// Address: 0x140275c20
// Ghidra name: FUN_140275c20
// ============ 0x140275c20 FUN_140275c20 (size=409) ============


undefined8 FUN_140275c20(longlong param_1,longlong param_2)



{

  longlong lVar1;

  char cVar2;

  undefined8 uVar3;

  float fVar4;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  fVar4 = 0.0;

  _guard_check_icall();

  *(undefined1 *)(lVar1 + 9) = 0;

  *(undefined8 *)(lVar1 + 0x20) = 0;

  *(undefined8 *)(lVar1 + 0x28) = 0;

  *(undefined8 *)(lVar1 + 0x30) = 0;

  *(undefined8 *)(lVar1 + 0x38) = 0;

  *(undefined8 *)(lVar1 + 0x40) = 0;

  *(undefined8 *)(lVar1 + 0x48) = 0;

  *(undefined8 *)(lVar1 + 0x50) = 0;

  *(undefined8 *)(lVar1 + 0x58) = 0;

  *(undefined8 *)(lVar1 + 0x60) = 0;

  *(undefined8 *)(lVar1 + 0x68) = 0;

  *(undefined8 *)(lVar1 + 0x70) = 0;

  *(undefined8 *)(lVar1 + 0x78) = 0;

  *(undefined8 *)(lVar1 + 0x80) = 0;

  *(undefined8 *)(lVar1 + 0x88) = 0;

  *(undefined8 *)(lVar1 + 0x90) = 0;

  *(undefined8 *)(lVar1 + 0x98) = 0;

  *(undefined8 *)(lVar1 + 0xa0) = 0;

  *(undefined8 *)(lVar1 + 0xa8) = 0;

  *(undefined8 *)(lVar1 + 0xb0) = 0;

  *(undefined4 *)(lVar1 + 0xb8) = 0;

  *(undefined8 *)(lVar1 + 0xc0) = 0;

  *(undefined8 *)(lVar1 + 200) = 0;

  *(undefined8 *)(lVar1 + 0xd0) = 0;

  *(undefined8 *)(lVar1 + 0xd8) = 0;

  *(undefined8 *)(lVar1 + 0xe0) = 0;

  *(undefined8 *)(lVar1 + 0xe8) = 0;

  *(undefined8 *)(lVar1 + 0xf0) = 0;

  *(undefined8 *)(lVar1 + 0xf8) = 0;

  *(undefined8 *)(lVar1 + 0x100) = 0;

  *(undefined8 *)(lVar1 + 0x108) = 0;

  *(undefined8 *)(lVar1 + 0x110) = 0;

  *(undefined8 *)(lVar1 + 0x118) = 0;

  *(undefined8 *)(lVar1 + 0x120) = 0;

  *(undefined8 *)(lVar1 + 0x128) = 0;

  *(undefined8 *)(lVar1 + 0x130) = 0;

  *(undefined8 *)(lVar1 + 0x138) = 0;

  *(undefined8 *)(lVar1 + 0x140) = 0;

  *(undefined8 *)(lVar1 + 0x148) = 0;

  *(undefined8 *)(lVar1 + 0x150) = 0;

  *(undefined8 *)(lVar1 + 0x158) = 0;

  *(undefined8 *)(lVar1 + 0x160) = 0;

  *(undefined8 *)(lVar1 + 0x168) = 0;

  cVar2 = FUN_140276cb0(param_1,0,lVar1 + 0xc);

  if (cVar2 == '\0') {

    FUN_14012e850("Couldn\'t reset controller");

    uVar3 = 0;

  }

  else {

    if (*(uint *)(lVar1 + 0xc) != 0) {

      fVar4 = DAT_14037f68c / (float)*(uint *)(lVar1 + 0xc);

    }

    FUN_140276b90(lVar1 + 0x20,*(undefined1 *)(param_1 + 0x54));

    *(undefined4 *)(param_2 + 0x70) = 0xd;

    *(undefined4 *)(param_2 + 0x44) = 6;

    *(undefined4 *)(param_2 + 0x60) = 1;

    cVar2 = FUN_140276ba0(*(undefined2 *)(param_1 + 0x22));

    if (cVar2 != '\0') {

      *(undefined4 *)(param_2 + 0xe4) = 2;

    }

    FUN_14015a190(param_2,2,fVar4);

    FUN_14015a190(param_2,1,fVar4);

    FUN_1401427d0("SDL_JOYSTICK_HIDAPI_STEAM_HOME_LED",FUN_140276fb0,lVar1);

    uVar3 = 1;

  }

  return uVar3;

}




