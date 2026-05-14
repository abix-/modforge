// Address: 0x140158030
// Ghidra name: FUN_140158030
// ============ 0x140158030 FUN_140158030 (size=179) ============


ulonglong FUN_140158030(longlong param_1,int param_2)



{

  byte bVar1;

  char cVar2;

  ulonglong uVar3;

  

  FUN_140159d30();

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar2 = FUN_1401aa7c0(param_1,4);

      if (cVar2 == '\0') goto LAB_1401580b9;

    }

    if (param_2 < *(int *)(param_1 + 0x70)) {

      bVar1 = *(byte *)((longlong)param_2 + *(longlong *)(param_1 + 0x78));

      FUN_14015bb10();

      return (ulonglong)bVar1;

    }

    FUN_14012e850("Joystick only has %d buttons");

    FUN_14015bb10();

    return 0;

  }

LAB_1401580b9:

  FUN_14012e850("Parameter \'%s\' is invalid","joystick");

  uVar3 = FUN_14015bb10();

  return uVar3 & 0xffffffffffffff00;

}




