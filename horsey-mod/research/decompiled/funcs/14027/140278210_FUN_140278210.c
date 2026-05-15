// Address: 0x140278210
// Ghidra name: FUN_140278210
// ============ 0x140278210 FUN_140278210 (size=284) ============


undefined8 FUN_140278210(longlong param_1,longlong param_2)



{

  longlong lVar1;

  char cVar2;

  undefined1 uVar3;

  undefined4 uVar4;

  undefined8 uVar5;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  _guard_check_icall();

  *(longlong *)(lVar1 + 8) = param_2;

  FUN_140279650(lVar1);

  FUN_140278760(lVar1,lVar1 + 0x29,lVar1 + 0x2a);

  cVar2 = FUN_140279690(lVar1,0);

  if (cVar2 != '\0') {

    FUN_140279d20();

  }

  if ((*(int *)(lVar1 + 0x1c) == 0x80) || (*(int *)(lVar1 + 0x1c) == 0x81)) {

    FUN_14015a190(param_2,1,DAT_14039ca5c);

    if (*(int *)(lVar1 + 0x1c) == 0x81) {

      FUN_14015a190(param_2,3,DAT_14039ca5c);

    }

    if (*(char *)(lVar1 + 0x29) != '\0') {

      FUN_14015a190(param_2,2,DAT_14039ca5c);

    }

  }

  uVar4 = FUN_140158960(param_2);

  *(undefined4 *)(lVar1 + 0x24) = uVar4;

  uVar3 = FUN_140142940("SDL_JOYSTICK_HIDAPI_WII_PLAYER_LED",1);

  *(undefined1 *)(lVar1 + 0x20) = uVar3;

  FUN_140279f50(lVar1);

  FUN_1401427d0("SDL_JOYSTICK_HIDAPI_WII_PLAYER_LED",FUN_140279cf0,lVar1);

  uVar4 = 0xf;

  if (*(int *)(lVar1 + 0x1c) != 0x83) {

    uVar4 = 0x1a;

  }

  *(undefined4 *)(param_2 + 0x70) = uVar4;

  *(undefined4 *)(param_2 + 0x44) = 6;

  uVar5 = FUN_140149350();

  *(undefined8 *)(lVar1 + 0x48) = uVar5;

  return 1;

}




