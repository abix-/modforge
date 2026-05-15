// Address: 0x140174210
// Ghidra name: FUN_140174210
// ============ 0x140174210 FUN_140174210 (size=97) ============


bool FUN_140174210(longlong param_1)



{

  char cVar1;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return false;

  }

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,1);

      if (cVar1 == '\0') goto LAB_14017425d;

    }

    return *(longlong *)(param_1 + 0x100) != 0;

  }

LAB_14017425d:

  FUN_14012e850("Invalid window");

  return false;

}




