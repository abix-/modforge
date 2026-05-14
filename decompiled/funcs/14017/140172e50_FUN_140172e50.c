// Address: 0x140172e50
// Ghidra name: FUN_140172e50
// ============ 0x140172e50 FUN_140172e50 (size=178) ============


undefined8 FUN_140172e50(longlong param_1)



{

  char cVar1;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if ((param_1 != 0) &&

     ((DAT_1403e3d60 == '\0' || (cVar1 = FUN_1401aa7c0(param_1,1), cVar1 != '\0')))) {

    if (*(char *)(param_1 + 0x138) != '\0') {

      if (*(code **)(DAT_1403fc410 + 0x268) != (code *)0x0) {

        (**(code **)(DAT_1403fc410 + 0x268))(DAT_1403fc410,param_1);

      }

      *(undefined1 *)(param_1 + 0x138) = 0;

    }

    cVar1 = FUN_140169bb0();

    if ((cVar1 != '\0') && (cVar1 = FUN_140170250(param_1), cVar1 != '\0')) {

      if (*(code **)(DAT_1403fc410 + 0x290) != (code *)0x0) {

        (**(code **)(DAT_1403fc410 + 0x290))(DAT_1403fc410,param_1);

      }

    }

    return 1;

  }

  FUN_14012e850("Invalid window");

  return 0;

}




