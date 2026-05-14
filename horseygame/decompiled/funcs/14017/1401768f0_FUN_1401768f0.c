// Address: 0x1401768f0
// Ghidra name: FUN_1401768f0
// ============ 0x1401768f0 FUN_1401768f0 (size=255) ============


ulonglong FUN_1401768f0(longlong param_1,uint param_2)



{

  char cVar1;

  int iVar2;

  ulonglong uVar3;

  longlong lVar4;

  

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,6);

      if (cVar1 == '\0') goto LAB_1401769cf;

    }

    if ((*(uint *)(param_1 + 0x20) & 0x10000) == 0) {

      uVar3 = FUN_14012e850("Haptic: Device does not support setting gain.");

      return uVar3;

    }

    if (param_2 < 0x65) {

      lVar4 = FUN_140179690("SDL_HAPTIC_GAIN_MAX");

      if (lVar4 != 0) {

        iVar2 = thunk_FUN_1402d89dc(lVar4);

        if (iVar2 < 0) {

          iVar2 = 0;

        }

        else if (100 < iVar2) {

          iVar2 = 100;

        }

        param_2 = (int)(iVar2 * param_2) / 100;

      }

      cVar1 = FUN_14021b070(param_1);

      if (cVar1 != '\0') {

        uVar3 = FUN_14021b420();

        return uVar3;

      }

      uVar3 = thunk_FUN_140288460(param_1,param_2);

      return uVar3;

    }

    uVar3 = FUN_14012e850("Haptic: Gain must be between 0 and 100.");

    return uVar3;

  }

LAB_1401769cf:

  uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","haptic");

  return uVar3 & 0xffffffffffffff00;

}




