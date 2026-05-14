// Address: 0x14016e930
// Ghidra name: FUN_14016e930
// ============ 0x14016e930 FUN_14016e930 (size=132) ============


undefined4 FUN_14016e930(longlong param_1)



{

  char cVar1;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0xffffffff;

  }

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,1);

      if (cVar1 == '\0') goto LAB_14016e99d;

    }

    if ((*(uint *)(param_1 + 0x48) & 0xc0000) != 0) {

      FUN_14012e850("Operation invalid on popup windows");

      return 0xffffffff;

    }

    return *(undefined4 *)(param_1 + 0x170);

  }

LAB_14016e99d:

  FUN_14012e850("Invalid window");

  return 0xffffffff;

}




