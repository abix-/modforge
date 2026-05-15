// Address: 0x140176770
// Ghidra name: FUN_140176770
// ============ 0x140176770 FUN_140176770 (size=182) ============


undefined1 FUN_140176770(longlong param_1,int param_2,undefined4 param_3)



{

  char cVar1;

  undefined1 uVar2;

  

  if (param_1 == 0) {

LAB_140176801:

    FUN_14012e850("Parameter \'%s\' is invalid","haptic");

  }

  else {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,6);

      if (cVar1 == '\0') goto LAB_140176801;

    }

    cVar1 = FUN_14021b070(param_1);

    if (cVar1 != '\0') {

      uVar2 = FUN_14021b400(param_1,param_2,param_3);

      return uVar2;

    }

    cVar1 = FUN_140176cb0(param_1,param_2);

    if (cVar1 != '\0') {

      cVar1 = thunk_FUN_1402883b0(param_1,(longlong)param_2 * 0x50 + *(longlong *)(param_1 + 0x10),

                                  param_3);

      return cVar1 != '\0';

    }

  }

  return false;

}




