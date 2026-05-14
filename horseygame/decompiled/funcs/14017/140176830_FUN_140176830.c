// Address: 0x140176830
// Ghidra name: FUN_140176830
// ============ 0x140176830 FUN_140176830 (size=184) ============


undefined1 FUN_140176830(longlong param_1,uint param_2)



{

  char cVar1;

  undefined1 uVar2;

  

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,6);

      if (cVar1 == '\0') goto LAB_1401768c8;

    }

    if ((*(uint *)(param_1 + 0x20) & 0x20000) == 0) {

      uVar2 = FUN_14012e850("Haptic: Device does not support setting autocenter.");

      return uVar2;

    }

    if (param_2 < 0x65) {

      cVar1 = FUN_14021b070(param_1);

      if (cVar1 != '\0') {

        uVar2 = FUN_14021b410();

        return uVar2;

      }

      uVar2 = thunk_FUN_140288400(param_1,param_2);

      return uVar2;

    }

    uVar2 = FUN_14012e850("Haptic: Autocenter must be between 0 and 100.");

    return uVar2;

  }

LAB_1401768c8:

  FUN_14012e850("Parameter \'%s\' is invalid","haptic");

  return 0;

}




