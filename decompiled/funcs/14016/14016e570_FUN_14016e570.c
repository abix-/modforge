// Address: 0x14016e570
// Ghidra name: FUN_14016e570
// ============ 0x14016e570 FUN_14016e570 (size=118) ============


longlong FUN_14016e570(longlong param_1)



{

  char cVar1;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar1 = FUN_1401aa7c0(param_1,1), cVar1 == '\0')))) {

    FUN_14012e850("Invalid window");

  }

  else if ((param_1 + 0x150 != 0) && (0 < *(int *)(param_1 + 0x158))) {

    if (0 < *(int *)(param_1 + 0x15c)) {

      return param_1 + 0x150;

    }

    return 0;

  }

  return 0;

}




