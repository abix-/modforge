// Address: 0x1401769f0
// Ghidra name: FUN_1401769f0
// ============ 0x1401769f0 FUN_1401769f0 (size=153) ============


undefined1 FUN_1401769f0(longlong param_1,int param_2)



{

  char cVar1;

  undefined1 uVar2;

  

  if (param_1 == 0) {

LAB_140176a69:

    FUN_14012e850("Parameter \'%s\' is invalid","haptic");

  }

  else {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,6);

      if (cVar1 == '\0') goto LAB_140176a69;

    }

    cVar1 = FUN_14021b070(param_1);

    if (cVar1 != '\0') {

      uVar2 = FUN_14021b450();

      return uVar2;

    }

    cVar1 = FUN_140176cb0(param_1,param_2);

    if (cVar1 != '\0') {

      cVar1 = thunk_FUN_140288500(param_1,(longlong)param_2 * 0x50 + *(longlong *)(param_1 + 0x10));

      return cVar1 != '\0';

    }

  }

  return false;

}




