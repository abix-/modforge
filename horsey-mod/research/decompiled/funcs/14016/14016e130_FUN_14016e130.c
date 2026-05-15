// Address: 0x14016e130
// Ghidra name: FUN_14016e130
// ============ 0x14016e130 FUN_14016e130 (size=94) ============


ulonglong FUN_14016e130(longlong param_1)



{

  char cVar1;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,1);

      if (cVar1 == '\0') goto LAB_14016e17a;

    }

    return *(ulonglong *)(param_1 + 0x50) | *(ulonglong *)(param_1 + 0x48);

  }

LAB_14016e17a:

  FUN_14012e850("Invalid window");

  return 0;

}




