// Address: 0x14016e9c0
// Ghidra name: FUN_14016e9c0
// ============ 0x14016e9c0 FUN_14016e9c0 (size=143) ============


undefined4 FUN_14016e9c0(longlong param_1)



{

  char cVar1;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return DAT_14039ca80;

  }

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,1);

      if (cVar1 == '\0') goto LAB_14016ea35;

    }

    if ((*(uint *)(param_1 + 0x48) & 0xc0000) != 0) {

      FUN_14012e850("Operation invalid on popup windows");

      return DAT_14039ca80;

    }

    return *(undefined4 *)(param_1 + 0x174);

  }

LAB_14016ea35:

  FUN_14012e850("Invalid window");

  return DAT_14039ca80;

}




