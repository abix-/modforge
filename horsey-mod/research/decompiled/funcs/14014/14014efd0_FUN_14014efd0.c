// Address: 0x14014efd0
// Ghidra name: FUN_14014efd0
// ============ 0x14014efd0 FUN_14014efd0 (size=74) ============


undefined8 FUN_14014efd0(longlong param_1)



{

  char cVar1;

  

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,3);

      if (cVar1 == '\0') goto LAB_14014efff;

    }

    return *(undefined8 *)(param_1 + 0x10);

  }

LAB_14014efff:

  FUN_14012e850("Parameter \'%s\' is invalid","texture");

  return 0;

}




