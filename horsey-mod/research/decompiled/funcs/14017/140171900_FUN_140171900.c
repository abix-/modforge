// Address: 0x140171900
// Ghidra name: FUN_140171900
// ============ 0x140171900 FUN_140171900 (size=390) ============


ulonglong FUN_140171900(longlong param_1,longlong param_2)



{

  char cVar1;

  byte bVar2;

  ulonglong uVar3;

  longlong lVar4;

  

  if (DAT_1403fc410 != 0) {

    if ((param_1 == 0) ||

       ((DAT_1403e3d60 != '\0' && (cVar1 = FUN_1401aa7c0(param_1,1), cVar1 == '\0')))) {

LAB_140171a5b:

      uVar3 = FUN_14012e850("Invalid window");

      return uVar3 & 0xffffffffffffff00;

    }

    if ((*(uint *)(param_1 + 0x48) & 0xc0000) != 0) {

LAB_140171a42:

      uVar3 = FUN_14012e850("Operation invalid on popup windows");

      return uVar3 & 0xffffffffffffff00;

    }

    if (param_2 != 0) {

      if (DAT_1403fc410 == 0) goto LAB_140171a74;

      if ((DAT_1403e3d60 != '\0') && (cVar1 = FUN_1401aa7c0(param_2,1), cVar1 == '\0'))

      goto LAB_140171a5b;

      if ((*(uint *)(param_2 + 0x48) & 0xc0000) != 0) goto LAB_140171a42;

      if (param_1 == param_2) {

        uVar3 = FUN_14012e850("Cannot set the parent of a window to itself.");

        return uVar3;

      }

    }

    if (*(code **)(DAT_1403fc410 + 0xa8) == (code *)0x0) {

      uVar3 = FUN_14012e850("That operation is not supported");

      return uVar3;

    }

    if ((*(uint *)(param_1 + 0x48) >> 0xc & 1) == 0) {

      if (*(longlong *)(param_1 + 0x1a8) != param_2) {

        bVar2 = (**(code **)(DAT_1403fc410 + 0xa8))(DAT_1403fc410,param_1,param_2);

        uVar3 = (ulonglong)bVar2;

        lVar4 = 0;

        if (bVar2 != 0) {

          lVar4 = param_2;

        }

        FUN_140173720(param_1,lVar4,uVar3);

        return uVar3 & 0xff;

      }

      return CONCAT71((uint7)(uint3)(*(uint *)(param_1 + 0x48) >> 8),1);

    }

    uVar3 = FUN_14012e850(

                         "Modal windows cannot change parents; call SDL_SetWindowModal() to clear modal status first."

                         );

    return uVar3;

  }

LAB_140171a74:

  uVar3 = FUN_1401730c0();

  return uVar3 & 0xffffffffffffff00;

}




