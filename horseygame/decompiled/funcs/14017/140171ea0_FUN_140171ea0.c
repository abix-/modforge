// Address: 0x140171ea0
// Ghidra name: FUN_140171ea0
// ============ 0x140171ea0 FUN_140171ea0 (size=210) ============


undefined8 FUN_140171ea0(longlong param_1,char param_2)



{

  char cVar1;

  ulonglong uVar2;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,1);

      if (cVar1 == '\0') goto LAB_140171f59;

    }

    FUN_140160f90();

    cVar1 = FUN_14016eac0(param_1);

    if (param_2 != cVar1) {

      uVar2 = *(ulonglong *)(param_1 + 0x48) | 0x8000;

      if (param_2 == '\0') {

        uVar2 = *(ulonglong *)(param_1 + 0x48) & 0xffffffffffff7fff;

      }

      *(ulonglong *)(param_1 + 0x48) = uVar2;

      cVar1 = FUN_1401630f0();

      if (cVar1 == '\0') {

        uVar2 = *(ulonglong *)(param_1 + 0x48) & 0xffffffffffff7fff;

        if (param_2 == '\0') {

          uVar2 = *(ulonglong *)(param_1 + 0x48) | 0x8000;

        }

        *(ulonglong *)(param_1 + 0x48) = uVar2;

        return 0;

      }

    }

    return 1;

  }

LAB_140171f59:

  FUN_14012e850("Invalid window");

  return 0;

}




