// Address: 0x140176a90
// Ghidra name: FUN_140176a90
// ============ 0x140176a90 FUN_140176a90 (size=99) ============


undefined1 FUN_140176a90(longlong param_1)



{

  char cVar1;

  undefined1 uVar2;

  

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,6);

      if (cVar1 == '\0') goto LAB_140176ad8;

    }

    cVar1 = FUN_14021b070(param_1);

    if (cVar1 != '\0') {

      uVar2 = FUN_14021b430();

      return uVar2;

    }

    uVar2 = thunk_FUN_1402884c0(param_1);

    return uVar2;

  }

LAB_140176ad8:

  FUN_14012e850("Parameter \'%s\' is invalid","haptic");

  return 0;

}




