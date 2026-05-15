// Address: 0x140268760
// Ghidra name: FUN_140268760
// ============ 0x140268760 FUN_140268760 (size=560) ============


undefined8 FUN_140268760(longlong param_1,longlong param_2)



{

  longlong lVar1;

  char cVar2;

  undefined1 uVar3;

  undefined4 uVar4;

  undefined8 uVar5;

  char *pcVar6;

  longlong lVar7;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  _guard_check_icall();

  *(longlong *)(lVar1 + 8) = param_2;

  *(undefined1 *)(lVar1 + 0x18) = 1;

  if (*(char *)(lVar1 + 0x10) == '\0') {

    FUN_140269a70(lVar1);

    lVar7 = lVar1 + 0x38;

    *(undefined1 *)(lVar1 + 0x25) = *(undefined1 *)(lVar1 + 0x24);

    FUN_14026cf50(param_1,lVar7);

    FUN_14026cf50(param_1,lVar7 + 4);

    if (*(char *)(param_1 + 0x54) == '\0') {

      cVar2 = FUN_140269200(lVar1);

      if (cVar2 == '\0') {

        FUN_14012e850("Couldn\'t setup USB mode");

        return 0;

      }

    }

    cVar2 = FUN_14026c340(lVar1);

    if (cVar2 == '\0') {

      FUN_14012e850("Couldn\'t load stick calibration");

      return 0;

    }

    if (((*(int *)(lVar1 + 0x20) != 7) && (5 < *(int *)(lVar1 + 0x20) - 8U)) &&

       ((*(short *)(param_1 + 0x20) != 0xe6f || (*(short *)(param_1 + 0x22) != 0x18c)))) {

      cVar2 = FUN_14026bf50(lVar1);

      if (cVar2 != '\0') {

        *(undefined1 *)(lVar1 + 0x98) = 1;

      }

    }

    FUN_14026cf90(lVar1,1);

    FUN_1401427d0("SDL_JOYSTICK_ENHANCED_REPORTS",FUN_14026ca70,lVar1);

    if (*(char *)(param_1 + 0x54) == '\0') {

      cVar2 = FUN_14026d490(lVar1,4,0,0,0);

      if (cVar2 == '\0') {

        FUN_14012e850("Couldn\'t start USB reports");

        return 0;

      }

    }

    cVar2 = FUN_14026bf00(lVar1);

    if (cVar2 != '\0') {

      if ((*(int *)(lVar1 + 0x20) == 1) ||

         (pcVar6 = "SDL_JOYSTICK_HIDAPI_SWITCH_HOME_LED", *(int *)(lVar1 + 0x20) == 2)) {

        pcVar6 = "SDL_JOYSTICK_HIDAPI_JOYCON_HOME_LED";

      }

      FUN_1401427d0(pcVar6,FUN_14026cae0,lVar1);

    }

  }

  cVar2 = FUN_140268f80(*(undefined2 *)(param_1 + 0x20),*(undefined2 *)(param_1 + 0x22),

                        *(undefined4 *)(lVar1 + 0x20));

  if (cVar2 != '\0') {

    *(undefined1 *)(lVar1 + 0x11) = 1;

  }

  uVar4 = FUN_140158960(param_2);

  *(undefined4 *)(lVar1 + 0x14) = uVar4;

  uVar3 = FUN_140142940("SDL_JOYSTICK_HIDAPI_SWITCH_PLAYER_LED",1);

  *(undefined1 *)(lVar1 + 0x12) = uVar3;

  FUN_14026d300(lVar1);

  FUN_1401427d0("SDL_JOYSTICK_HIDAPI_SWITCH_PLAYER_LED",FUN_14026cb70,lVar1);

  *(undefined4 *)(param_2 + 0x70) = 0x10;

  *(undefined4 *)(param_2 + 0x44) = 6;

  *(undefined4 *)(param_2 + 0x60) = 1;

  *(undefined1 *)(lVar1 + 0x18) = 0;

  uVar5 = FUN_140149350();

  *(undefined8 *)(lVar1 + 0xa0) = uVar5;

  *(undefined8 *)(lVar1 + 0xa8) = uVar5;

  *(undefined8 *)(lVar1 + 0xc0) = 5000000;

  uVar3 = FUN_140142940("SDL_JOYSTICK_HIDAPI_VERTICAL_JOY_CONS",0);

  *(undefined1 *)(lVar1 + 0xd0) = uVar3;

  return 1;

}




