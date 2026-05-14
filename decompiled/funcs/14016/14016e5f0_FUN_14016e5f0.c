// Address: 0x14016e5f0
// Ghidra name: FUN_14016e5f0
// ============ 0x14016e5f0 FUN_14016e5f0 (size=106) ============


undefined4 FUN_14016e5f0(longlong param_1)



{

  char cVar1;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return DAT_14039ca80;

  }

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,1);

      if (cVar1 == '\0') goto LAB_14016e640;

    }

    return *(undefined4 *)(param_1 + 0xf8);

  }

LAB_14016e640:

  FUN_14012e850("Invalid window");

  return DAT_14039ca80;

}




