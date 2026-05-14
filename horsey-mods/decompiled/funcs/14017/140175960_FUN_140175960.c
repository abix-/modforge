// Address: 0x140175960
// Ghidra name: FUN_140175960
// ============ 0x140175960 FUN_140175960 (size=193) ============


undefined1 FUN_140175960(longlong param_1,int param_2)



{

  char cVar1;

  undefined1 uVar2;

  int iVar3;

  

  if (param_1 == 0) {

LAB_140175a01:

    FUN_14012e850("Parameter \'%s\' is invalid","haptic");

  }

  else {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,6);

      if (cVar1 == '\0') goto LAB_140175a01;

    }

    cVar1 = FUN_14021b070(param_1);

    if (cVar1 != '\0') {

      uVar2 = FUN_14021b030();

      return uVar2;

    }

    cVar1 = FUN_140176cb0(param_1,param_2);

    if (cVar1 != '\0') {

      if ((*(uint *)(param_1 + 0x20) & 0x40000) == 0) {

        uVar2 = FUN_14012e850("Haptic: Device does not support status queries.");

        return uVar2;

      }

      FUN_14012e710();

      iVar3 = thunk_FUN_140287980(param_1,(longlong)param_2 * 0x50 + *(longlong *)(param_1 + 0x10));

      return 0 < iVar3;

    }

  }

  return false;

}




