// Address: 0x140172c00
// Ghidra name: FUN_140172c00
// ============ 0x140172c00 FUN_140172c00 (size=262) ============


undefined8 FUN_140172c00(longlong param_1)



{

  longlong lVar1;

  char cVar2;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if ((param_1 != 0) &&

     ((DAT_1403e3d60 == '\0' || (cVar2 = FUN_1401aa7c0(param_1,1), cVar2 != '\0')))) {

    if ((*(byte *)(param_1 + 0x48) & 8) != 0) {

      if ((*(longlong *)(param_1 + 0x1a8) != 0) &&

         ((*(byte *)(*(longlong *)(param_1 + 0x1a8) + 0x48) & 8) != 0)) {

        *(undefined1 *)(param_1 + 0x10a) = 1;

        return 1;

      }

      if (*(code **)(DAT_1403fc410 + 0xb8) == (code *)0x0) {

        FUN_140162ca0(param_1);

        FUN_140183d70(param_1);

      }

      else {

        (**(code **)(DAT_1403fc410 + 0xb8))(DAT_1403fc410,param_1);

      }

      FUN_1401cda90(param_1,0x202,0,0);

      for (lVar1 = *(longlong *)(param_1 + 0x1b0);

          (lVar1 != 0 &&

          ((*(char *)(lVar1 + 0x10a) != '\0' || ((*(byte *)(lVar1 + 0x48) & 8) == 0))));

          lVar1 = *(longlong *)(lVar1 + 0x1c0)) {

        FUN_140172c00(lVar1);

        *(undefined1 *)(lVar1 + 0x10a) = 0;

      }

    }

    return 1;

  }

  FUN_14012e850("Invalid window");

  return 0;

}




