// Address: 0x14016f4f0
// Ghidra name: FUN_14016f4f0
// ============ 0x14016f4f0 FUN_14016f4f0 (size=196) ============


undefined8 FUN_14016f4f0(longlong param_1)



{

  char cVar1;

  undefined8 uVar2;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar1 = FUN_1401aa7c0(param_1,1), cVar1 == '\0')))) {

    FUN_14012e850("Invalid window");

    return 0;

  }

  if ((*(ulonglong *)(param_1 + 0x48) & 0xc0000) != 0) {

    FUN_14012e850("Operation invalid on popup windows");

    return 0;

  }

  if (*(code **)(DAT_1403fc410 + 0xd8) != (code *)0x0) {

    if ((*(ulonglong *)(param_1 + 0x48) & 8) == 0) {

      (**(code **)(DAT_1403fc410 + 0xd8))(DAT_1403fc410,param_1);

      FUN_140172f30(param_1);

      return 1;

    }

    *(ulonglong *)(param_1 + 0x50) = *(ulonglong *)(param_1 + 0x50) | 0x40;

    return 1;

  }

  uVar2 = FUN_14012e850("That operation is not supported");

  return uVar2;

}




