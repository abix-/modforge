// Address: 0x14014f4e0
// Ghidra name: FUN_14014f4e0
// ============ 0x14014f4e0 FUN_14014f4e0 (size=77) ============


undefined8 FUN_14014f4e0(longlong param_1)



{

  char cVar1;

  

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,3);

      if (cVar1 == '\0') goto LAB_14014f512;

    }

    return *(undefined8 *)(param_1 + 0xd8);

  }

LAB_14014f512:

  FUN_14012e850("Parameter \'%s\' is invalid","texture");

  return 0;

}




