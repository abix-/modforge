// Address: 0x1401766f0
// Ghidra name: FUN_1401766f0
// ============ 0x1401766f0 FUN_1401766f0 (size=116) ============


undefined1 FUN_1401766f0(longlong param_1)



{

  char cVar1;

  undefined1 uVar2;

  

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,6);

      if (cVar1 == '\0') goto LAB_140176749;

    }

    if ((*(uint *)(param_1 + 0x20) & 0x80000) == 0) {

      return 1;

    }

    cVar1 = FUN_14021b070(param_1);

    if (cVar1 != '\0') {

      uVar2 = FUN_14021b3e0();

      return uVar2;

    }

    uVar2 = thunk_FUN_140288370(param_1);

    return uVar2;

  }

LAB_140176749:

  FUN_14012e850("Parameter \'%s\' is invalid","haptic");

  return 0;

}




