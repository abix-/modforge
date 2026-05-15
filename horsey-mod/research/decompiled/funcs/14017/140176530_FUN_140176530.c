// Address: 0x140176530
// Ghidra name: FUN_140176530
// ============ 0x140176530 FUN_140176530 (size=125) ============


undefined1 FUN_140176530(longlong param_1)



{

  char cVar1;

  undefined1 uVar2;

  

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,6);

      if (cVar1 == '\0') goto LAB_140176592;

    }

    if ((*(uint *)(param_1 + 0x20) & 0x80000) == 0) {

      uVar2 = FUN_14012e850("Haptic: Device does not support setting pausing.");

      return uVar2;

    }

    cVar1 = FUN_14021b070(param_1);

    if (cVar1 != '\0') {

      uVar2 = FUN_14021b3a0();

      return uVar2;

    }

    uVar2 = thunk_FUN_1402882f0(param_1);

    return uVar2;

  }

LAB_140176592:

  FUN_14012e850("Parameter \'%s\' is invalid","haptic");

  return 0;

}




