// Address: 0x1401758c0
// Ghidra name: FUN_1401758c0
// ============ 0x1401758c0 FUN_1401758c0 (size=152) ============


void FUN_1401758c0(longlong param_1,int param_2)



{

  char cVar1;

  

  if (param_1 == 0) {

LAB_14017593a:

    FUN_14012e850("Parameter \'%s\' is invalid","haptic");

  }

  else {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,6);

      if (cVar1 == '\0') goto LAB_14017593a;

    }

    cVar1 = FUN_14021b070(param_1);

    if (cVar1 != '\0') {

      FUN_14021b020();

      return;

    }

    cVar1 = FUN_140176cb0(param_1,param_2);

    if ((cVar1 != '\0') &&

       (*(longlong *)((longlong)param_2 * 0x50 + *(longlong *)(param_1 + 0x10) + 0x48) != 0)) {

      FUN_14021abe0(param_1);

      return;

    }

  }

  return;

}




