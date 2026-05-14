// Address: 0x14016f2a0
// Ghidra name: FUN_14016f2a0
// ============ 0x14016f2a0 FUN_14016f2a0 (size=224) ============


undefined8 FUN_14016f2a0(longlong param_1)



{

  ulonglong uVar1;

  char cVar2;

  undefined8 uVar3;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar2 = FUN_1401aa7c0(param_1,1), cVar2 == '\0')))) {

    FUN_14012e850("Invalid window");

    return 0;

  }

  uVar1 = *(ulonglong *)(param_1 + 0x48);

  if ((uVar1 & 0xc0000) != 0) {

    FUN_14012e850("Operation invalid on popup windows");

    return 0;

  }

  if (*(code **)(DAT_1403fc410 + 0xd0) != (code *)0x0) {

    if ((uVar1 & 0x20) == 0) {

      uVar3 = FUN_14012e850("A window without the \'SDL_WINDOW_RESIZABLE\' flag can\'t be maximized"

                           );

      return uVar3;

    }

    if ((uVar1 & 8) == 0) {

      (**(code **)(DAT_1403fc410 + 0xd0))(DAT_1403fc410,param_1);

      FUN_140172f30(param_1);

      return 1;

    }

    *(ulonglong *)(param_1 + 0x50) = *(ulonglong *)(param_1 + 0x50) | 0x80;

    return 1;

  }

  uVar3 = FUN_14012e850("That operation is not supported");

  return uVar3;

}




