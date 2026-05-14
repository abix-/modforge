// Address: 0x1402194f0
// Ghidra name: FUN_1402194f0
// ============ 0x1402194f0 FUN_1402194f0 (size=569) ============


undefined8 FUN_1402194f0(longlong param_1,undefined8 param_2,undefined8 param_3,int param_4)



{

  longlong *plVar1;

  longlong lVar2;

  char cVar3;

  int iVar4;

  undefined8 uVar5;

  longlong lVar6;

  

  uVar5 = FUN_140219df0();

  if ((char)uVar5 == '\0') {

    return uVar5;

  }

  plVar1 = (longlong *)(param_1 + 0x690);

  lVar6 = 0;

  *(undefined8 *)(*plVar1 + 0x10) = 0;

  if (param_4 != 0) {

    FUN_140219100(param_1);

    lVar2 = *plVar1;

    if ((*(int *)(lVar2 + 0x28) == 1) && (*(int *)(lVar2 + 0x2c) == 5)) {

      uVar5 = FUN_140188550(*(undefined8 *)(lVar2 + 8),"eglGetPlatformDisplay");

      *(undefined8 *)(lVar2 + 0xe0) = uVar5;

      if (*(longlong *)(*plVar1 + 0xe0) == 0) {

        uVar5 = FUN_14012e850("Could not retrieve EGL function eglGetPlatformDisplay");

        return uVar5;

      }

    }

    else if (*(longlong *)(lVar2 + 0xe0) == 0) {

      cVar3 = FUN_1402191b0(param_1,1,"EGL_EXT_platform_base");

      if (cVar3 != '\0') {

        lVar6 = *plVar1;

        uVar5 = FUN_140219030(param_1,"eglGetPlatformDisplayEXT");

        *(undefined8 *)(lVar6 + 0xe8) = uVar5;

        if (*(code **)(*plVar1 + 0xe8) != (code *)0x0) {

          lVar6 = *(longlong *)(param_1 + 0x690);

          uVar5 = (**(code **)(*plVar1 + 0xe8))(param_4,param_3,0);

          *(undefined8 *)(lVar6 + 0x10) = uVar5;

        }

      }

      goto LAB_140219665;

    }

    if ((*(code **)(param_1 + 0x520) != (code *)0x0) &&

       (lVar6 = (**(code **)(param_1 + 0x520))(*(undefined8 *)(param_1 + 0x538)), lVar6 == 0)) {

      *(undefined4 *)(param_1 + 0x410) = 0;

      *(undefined1 *)(param_1 + 0x418) = 0;

      uVar5 = FUN_14012e850("EGL platform attribute callback returned NULL pointer");

      return uVar5;

    }

    lVar2 = *(longlong *)(param_1 + 0x690);

    uVar5 = (**(code **)(*plVar1 + 0xe0))(param_4,param_3,lVar6);

    *(undefined8 *)(lVar2 + 0x10) = uVar5;

    FUN_1401841e0(lVar6);

  }

LAB_140219665:

  if (((*(longlong *)(*(longlong *)(param_1 + 0x690) + 0x10) == 0) &&

      (*(longlong *)(*(longlong *)(param_1 + 0x690) + 0x40) != 0)) &&

     (cVar3 = FUN_140142940("SDL_VIDEO_EGL_ALLOW_GETDISPLAY_FALLBACK",1), cVar3 != '\0')) {

    lVar6 = *(longlong *)(param_1 + 0x690);

    uVar5 = (**(code **)(lVar6 + 0x40))(param_3);

    *(undefined8 *)(lVar6 + 0x10) = uVar5;

  }

  lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x690) + 0x10);

  if (lVar6 == 0) {

    *(undefined4 *)(param_1 + 0x410) = 0;

    *(undefined1 *)(param_1 + 0x418) = 0;

    uVar5 = FUN_14012e850("Could not get EGL display");

  }

  else {

    iVar4 = (**(code **)(*(longlong *)(param_1 + 0x690) + 0x48))(lVar6,0,0);

    if (iVar4 == 1) {

      FUN_140219100(param_1);

      lVar6 = *(longlong *)(param_1 + 0x690);

      *(undefined1 *)(lVar6 + 0x34) = 0;

      uVar5 = CONCAT71((int7)((ulonglong)lVar6 >> 8),1);

    }

    else {

      *(undefined4 *)(param_1 + 0x410) = 0;

      *(undefined1 *)(param_1 + 0x418) = 0;

      uVar5 = FUN_14012e850("Could not initialize EGL");

    }

  }

  return uVar5;

}




