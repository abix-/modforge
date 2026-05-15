// Address: 0x1402192f0
// Ghidra name: FUN_1402192f0
// ============ 0x1402192f0 FUN_1402192f0 (size=509) ============


undefined8 FUN_1402192f0(longlong param_1)



{

  code *pcVar1;

  int iVar2;

  int iVar3;

  undefined8 uVar4;

  longlong lVar5;

  char *pcVar6;

  undefined8 *puVar7;

  int local_res8 [2];

  undefined8 local_48 [8];

  

  iVar3 = 0;

  local_res8[0] = 0;

  if (*(int *)(param_1 + 0x410) < 1) {

    uVar4 = FUN_14012e850("SDL_EGL_LoadLibraryOnly() has not been called or has failed.");

    return uVar4;

  }

  pcVar1 = *(code **)(*(longlong *)(param_1 + 0x690) + 0xd8);

  if (pcVar1 == (code *)0x0) {

    uVar4 = FUN_14012e850(

                         "eglQueryDevicesEXT is missing (EXT_device_enumeration not supported by the drivers?)"

                         );

    return uVar4;

  }

  if (*(longlong *)(*(longlong *)(param_1 + 0x690) + 0xe8) == 0) {

    uVar4 = FUN_14012e850(

                         "eglGetPlatformDisplayEXT is missing (EXT_platform_base not supported by the drivers?)"

                         );

    return uVar4;

  }

  iVar2 = (*pcVar1)(8,local_48,local_res8);

  if (iVar2 != 1) {

    uVar4 = FUN_14012e850("eglQueryDevicesEXT() failed");

    return uVar4;

  }

  lVar5 = FUN_140142960("SDL_HINT_EGL_DEVICE");

  if (lVar5 == 0) {

    if (0 < local_res8[0]) {

      puVar7 = local_48;

      do {

        lVar5 = (**(code **)(*(longlong *)(param_1 + 0x690) + 0xe8))(0x313f,*puVar7,0);

        if (lVar5 != 0) {

          iVar2 = (**(code **)(*(longlong *)(param_1 + 0x690) + 0x48))(lVar5,0);

          if (iVar2 == 1) {

            *(longlong *)(*(longlong *)(param_1 + 0x690) + 0x10) = lVar5;

            goto LAB_1402194d6;

          }

          (**(code **)(*(longlong *)(param_1 + 0x690) + 0x50))(lVar5);

        }

        iVar3 = iVar3 + 1;

        puVar7 = puVar7 + 1;

      } while (iVar3 < local_res8[0]);

    }

    pcVar6 = "Could not find a valid EGL device to initialize";

  }

  else {

    iVar3 = thunk_FUN_1402d89dc(lVar5);

    if (iVar3 < local_res8[0]) {

      lVar5 = *(longlong *)(param_1 + 0x690);

      uVar4 = (**(code **)(lVar5 + 0xe8))(0x313f,local_48[iVar3],0);

      *(undefined8 *)(lVar5 + 0x10) = uVar4;

      lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x690) + 0x10);

      if (lVar5 == 0) {

        pcVar6 = "eglGetPlatformDisplayEXT() failed.";

      }

      else {

        iVar3 = (**(code **)(*(longlong *)(param_1 + 0x690) + 0x48))(lVar5,0,0);

        if (iVar3 == 1) {

LAB_1402194d6:

          FUN_140219100(param_1);

          lVar5 = *(longlong *)(param_1 + 0x690);

          *(undefined1 *)(lVar5 + 0x34) = 1;

          return CONCAT71((int7)((ulonglong)lVar5 >> 8),1);

        }

        pcVar6 = "Could not initialize EGL";

      }

    }

    else {

      pcVar6 = "Invalid EGL device is requested.";

    }

  }

  uVar4 = FUN_14012e850(pcVar6);

  return uVar4;

}




