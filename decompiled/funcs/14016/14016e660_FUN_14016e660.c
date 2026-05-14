// Address: 0x14016e660
// Ghidra name: FUN_14016e660
// ============ 0x14016e660 FUN_14016e660 (size=93) ============


undefined8 FUN_14016e660(longlong param_1)



{

  char cVar1;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,1);

      if (cVar1 == '\0') goto LAB_14016e6a9;

    }

    return *(undefined8 *)(param_1 + 0x1a8);

  }

LAB_14016e6a9:

  FUN_14012e850("Invalid window");

  return 0;

}




