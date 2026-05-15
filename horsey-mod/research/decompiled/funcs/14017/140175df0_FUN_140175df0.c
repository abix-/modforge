// Address: 0x140175df0
// Ghidra name: FUN_140175df0
// ============ 0x140175df0 FUN_140175df0 (size=80) ============


bool FUN_140175df0(longlong param_1)



{

  char cVar1;

  

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,6);

      if (cVar1 == '\0') goto LAB_140175e25;

    }

    return (*(uint *)(param_1 + 0x20) & 0x802) != 0;

  }

LAB_140175e25:

  FUN_14012e850("Parameter \'%s\' is invalid","haptic");

  return false;

}




