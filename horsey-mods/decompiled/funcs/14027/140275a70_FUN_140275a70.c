// Address: 0x140275a70
// Ghidra name: FUN_140275a70
// ============ 0x140275a70 FUN_140275a70 (size=416) ============


undefined8 FUN_140275a70(longlong param_1)



{

  char cVar1;

  int iVar2;

  longlong *plVar3;

  undefined8 uVar4;

  int iVar5;

  undefined8 local_d8;

  undefined8 uStack_d0;

  undefined8 local_c8;

  undefined8 uStack_c0;

  undefined8 local_b8;

  undefined8 uStack_b0;

  undefined8 local_a8;

  undefined8 uStack_a0;

  undefined1 local_98;

  char local_88;

  char local_87;

  char local_86;

  char local_85;

  char local_84;

  

  plVar3 = (longlong *)FUN_1401841a0(1,0x170);

  if (plVar3 == (longlong *)0x0) {

    return 0;

  }

  *plVar3 = param_1;

  iVar5 = 0;

  *(longlong **)(param_1 + 0x70) = plVar3;

  if (*(longlong *)(param_1 + 0x28) != 0) {

    FUN_1401841e0();

    *(undefined8 *)(param_1 + 0x28) = 0;

  }

  FUN_1402083c0(param_1,"Steam Controller");

  cVar1 = FUN_140276ba0(*(undefined2 *)(param_1 + 0x22));

  if (cVar1 == '\0') {

    *(undefined1 *)(plVar3 + 1) = 1;

  }

  else {

    uStack_d0 = 0;

    local_d8 = 0xb400;

    local_c8 = 0;

    uStack_c0 = 0;

    local_98 = 0;

    local_b8 = 0;

    uStack_b0 = 0;

    local_a8 = 0;

    uStack_a0 = 0;

    iVar2 = FUN_140277070(param_1,&local_d8,2);

    if (iVar2 < 0) {

      uVar4 = FUN_14012e850("Failed to send ID_DONGLE_GET_WIRELESS_STATE request");

      return uVar4;

    }

    do {

      iVar2 = FUN_140276c10(*(undefined8 *)(param_1 + 0x80),&local_88,0x80);

      if (iVar2 == 0) {

        FUN_1401492f0(1);

      }

      else {

        if (iVar2 < 0) break;

        if ((4 < iVar2) && (local_88 == '\x01')) {

          if ((local_87 == '\0') &&

             (((local_86 == '\x03' && (local_85 != '\0')) && (local_84 != '\x01')))) {

            *(undefined1 *)(plVar3 + 1) = 1;

            break;

          }

          if (((local_87 == '\0') && (local_86 == '\x03')) &&

             ((local_85 != '\0' && (local_84 == '\x01')))) {

            *(undefined1 *)(plVar3 + 1) = 0;

            break;

          }

        }

      }

      iVar5 = iVar5 + 1;

    } while (iVar5 < 5);

    FUN_1401427d0("SDL_JOYSTICK_HIDAPI_STEAM_PAIRING_ENABLED",FUN_140277040,plVar3);

  }

  if ((char)plVar3[1] == '\0') {

    uVar4 = 1;

  }

  else {

    uVar4 = FUN_140208110(param_1,0);

  }

  return uVar4;

}




