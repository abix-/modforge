// Address: 0x140175ab0
// Ghidra name: FUN_140175ab0
// ============ 0x140175ab0 FUN_140175ab0 (size=72) ============


undefined4 FUN_140175ab0(undefined4 *param_1)



{

  char cVar1;

  

  if (param_1 != (undefined4 *)0x0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,6);

      if (cVar1 == '\0') goto LAB_140175add;

    }

    return *param_1;

  }

LAB_140175add:

  FUN_14012e850("Parameter \'%s\' is invalid","haptic");

  return 0;

}




