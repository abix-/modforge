// Address: 0x14016e1f0
// Ghidra name: FUN_14016e1f0
// ============ 0x14016e1f0 FUN_14016e1f0 (size=150) ============


undefined8 FUN_14016e1f0(longlong param_1)



{

  char cVar1;

  undefined8 uVar2;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,1);

      if (cVar1 == '\0') goto LAB_14016e272;

    }

    if ((*(ulonglong *)(param_1 + 0x48) & 0xc0000) != 0) {

      FUN_14012e850("Operation invalid on popup windows");

      return 0;

    }

    if ((*(ulonglong *)(param_1 + 0x48) & 1) != 0) {

      uVar2 = FUN_14016d920(param_1 + 200);

      return uVar2;

    }

    uVar2 = FUN_14016d920(param_1 + 0xa0);

    return uVar2;

  }

LAB_14016e272:

  FUN_14012e850("Invalid window");

  return 0;

}




