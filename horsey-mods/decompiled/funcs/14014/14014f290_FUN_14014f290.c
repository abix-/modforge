// Address: 0x14014f290
// Ghidra name: FUN_14014f290
// ============ 0x14014f290 FUN_14014f290 (size=110) ============


undefined8 FUN_14014f290(longlong param_1,undefined4 *param_2)



{

  char cVar1;

  

  if (param_2 != (undefined4 *)0x0) {

    *param_2 = 0x7fffffff;

  }

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,3);

      if (cVar1 == '\0') goto LAB_14014f2de;

    }

    if (param_2 != (undefined4 *)0x0) {

      *param_2 = *(undefined4 *)(param_1 + 0x28);

    }

    return 1;

  }

LAB_14014f2de:

  FUN_14012e850("Parameter \'%s\' is invalid","texture");

  return 0;

}




