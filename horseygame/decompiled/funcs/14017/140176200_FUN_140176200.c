// Address: 0x140176200
// Ghidra name: FUN_140176200
// ============ 0x140176200 FUN_140176200 (size=472) ============


longlong FUN_140176200(undefined8 param_1)



{

  char cVar1;

  undefined2 uVar2;

  undefined2 uVar3;

  int iVar4;

  int iVar5;

  longlong lVar6;

  

  FUN_140159d30();

  cVar1 = FUN_140176180(param_1);

  lVar6 = DAT_1403fc460;

  if (cVar1 == '\0') {

    FUN_14012e850("Haptic: Joystick isn\'t a haptic device.");

    FUN_14015bb10();

    return 0;

  }

  for (; lVar6 != 0; lVar6 = *(longlong *)(lVar6 + 0x80)) {

    cVar1 = FUN_14021aeb0(lVar6,param_1);

    if ((cVar1 != '\0') || (cVar1 = FUN_14021b4f0(lVar6,param_1), cVar1 != '\0')) {

      *(int *)(lVar6 + 0x30) = *(int *)(lVar6 + 0x30) + 1;

      FUN_14015bb10();

      return lVar6;

    }

  }

  lVar6 = FUN_1401841a0(1,0x88);

  if (lVar6 != 0) {

    FUN_1401aa9d0(lVar6,6,1);

    *(undefined4 *)(lVar6 + 0x34) = 0xffffffff;

    cVar1 = FUN_14021b470(param_1);

    if (cVar1 == '\0') {

      cVar1 = thunk_FUN_140288220(lVar6,param_1);

      if (cVar1 != '\0') goto LAB_140176328;

      FUN_14012e850("Haptic: SDL_SYS_HapticOpenFromJoystick failed.");

      FUN_1401aa9d0(lVar6,6,0);

    }

    else {

      cVar1 = FUN_14021b140();

      if (cVar1 != '\0') {

LAB_140176328:

        FUN_14015bb10();

        uVar2 = FUN_140158e60(param_1);

        uVar3 = FUN_140158b60(param_1);

        iVar4 = FUN_140159050(param_1);

        iVar5 = FUN_140175e40(uVar2,uVar3);

        if (0 < iVar5) {

          *(int *)(lVar6 + 0x24) = iVar5;

        }

        if ((-1 < iVar4) && (iVar4 < iVar5)) {

          *(int *)(lVar6 + 0x24) = iVar4;

        }

        *(int *)(lVar6 + 0x30) = *(int *)(lVar6 + 0x30) + 1;

        *(longlong *)(lVar6 + 0x80) = DAT_1403fc460;

        DAT_1403fc460 = lVar6;

        FUN_1401aa9d0(lVar6,6,1);

        if ((*(uint *)(lVar6 + 0x20) & 0x10000) != 0) {

          FUN_1401768f0(lVar6,100);

        }

        if ((*(uint *)(lVar6 + 0x20) & 0x20000) != 0) {

          FUN_140176830(lVar6,0);

        }

        return lVar6;

      }

      FUN_14012e850("Haptic: SDL_HIDAPI_HapticOpenFromJoystick failed.");

    }

    FUN_1401841e0(lVar6);

  }

  FUN_14015bb10();

  return 0;

}




