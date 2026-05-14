// Address: 0x14016c930
// Ghidra name: FUN_14016c930
// ============ 0x14016c930 FUN_14016c930 (size=352) ============


char FUN_14016c930(longlong param_1,longlong param_2)



{

  char cVar1;

  longlong lVar2;

  

  if (DAT_1403fc410 == 0) {

    cVar1 = FUN_1401730c0();

    return cVar1;

  }

  lVar2 = FUN_14016c700();

  if ((param_1 == lVar2) && (lVar2 = FUN_14016c6d0(), param_2 == lVar2)) {

    return '\x01';

  }

  if (param_2 == 0) {

    param_1 = 0;

  }

  else if (param_1 == 0) {

    if (*(char *)(DAT_1403fc410 + 0x558) == '\0') {

      cVar1 = FUN_14012e850("Use of OpenGL without a window is not supported on this platform");

      return cVar1;

    }

  }

  else {

    if (DAT_1403fc410 == 0) {

      FUN_1401730c0();

      return '\0';

    }

    if ((DAT_1403e3d60 != '\0') && (cVar1 = FUN_1401aa7c0(param_1,1), cVar1 == '\0')) {

      FUN_14012e850("Invalid window");

      return '\0';

    }

    if ((*(byte *)(param_1 + 0x48) & 2) == 0) {

      cVar1 = FUN_14012e850("The specified window isn\'t an OpenGL window");

      return cVar1;

    }

  }

  cVar1 = (**(code **)(DAT_1403fc410 + 0x1c0))(DAT_1403fc410,param_1,param_2);

  lVar2 = DAT_1403fc410;

  if (cVar1 != '\0') {

    *(longlong *)(DAT_1403fc410 + 0x540) = param_1;

    *(longlong *)(lVar2 + 0x548) = param_2;

    FUN_140163ac0(lVar2 + 0x550,param_1,0);

    FUN_140163ac0(DAT_1403fc410 + 0x554,param_2,0);

  }

  return cVar1;

}




