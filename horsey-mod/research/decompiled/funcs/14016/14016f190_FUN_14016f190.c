// Address: 0x14016f190
// Ghidra name: FUN_14016f190
// ============ 0x14016f190 FUN_14016f190 (size=269) ============


undefined8 FUN_14016f190(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  char cVar3;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if ((param_1 != 0) &&

     ((DAT_1403e3d60 == '\0' || (cVar3 = FUN_1401aa7c0(param_1,1), cVar3 != '\0')))) {

    if ((*(byte *)(param_1 + 0x48) & 8) == 0) {

      lVar2 = DAT_1403fc410;

      for (lVar1 = *(longlong *)(param_1 + 0x1b0);

          (DAT_1403fc410 = lVar2, lVar1 != 0 && ((*(byte *)(lVar1 + 0x48) & 8) == 0));

          lVar1 = *(longlong *)(lVar1 + 0x1c0)) {

        FUN_14016f190(lVar1);

        *(undefined1 *)(lVar1 + 0x10a) = 1;

        lVar2 = DAT_1403fc410;

      }

      *(ulonglong *)(param_1 + 0x50) = (ulonglong)(*(uint *)(param_1 + 0x48) & 0x1001c1);

      *(undefined1 *)(param_1 + 0x109) = 1;

      if (*(code **)(lVar2 + 0xc0) == (code *)0x0) {

        FUN_140162ca0(0);

        FUN_140183d70(0);

      }

      else {

        (**(code **)(lVar2 + 0xc0))(lVar2,param_1);

      }

      *(undefined1 *)(param_1 + 0x109) = 0;

      FUN_1401cda90(param_1,0x203,0,0);

      return 1;

    }

    *(undefined1 *)(param_1 + 0x10a) = 0;

    return 1;

  }

  FUN_14012e850("Invalid window");

  return 0;

}




