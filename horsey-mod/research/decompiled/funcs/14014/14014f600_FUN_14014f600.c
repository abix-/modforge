// Address: 0x14014f600
// Ghidra name: FUN_14014f600
// ============ 0x14014f600 FUN_14014f600 (size=157) ============


undefined8 FUN_14014f600(longlong param_1,float *param_2,float *param_3)



{

  char cVar1;

  

  if (param_2 != (float *)0x0) {

    *param_2 = 0.0;

  }

  if (param_3 != (float *)0x0) {

    *param_3 = 0.0;

  }

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,3);

      if (cVar1 == '\0') goto LAB_14014f678;

    }

    if (param_2 != (float *)0x0) {

      *param_2 = (float)*(int *)(param_1 + 4);

    }

    if (param_3 != (float *)0x0) {

      *param_3 = (float)*(int *)(param_1 + 8);

    }

    return 1;

  }

LAB_14014f678:

  FUN_14012e850("Parameter \'%s\' is invalid","texture");

  return 0;

}




