// Address: 0x140158c10
// Ghidra name: FUN_140158c10
// ============ 0x140158c10 FUN_140158c10 (size=123) ============


int FUN_140158c10(longlong param_1)



{

  char cVar1;

  int iVar2;

  

  FUN_140159d30();

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,4);

      if (cVar1 == '\0') goto LAB_140158c6b;

    }

    iVar2 = *(int *)(param_1 + 0x150);

    if (iVar2 == 0) {

      iVar2 = FUN_1401746e0();

      *(int *)(param_1 + 0x150) = iVar2;

    }

    FUN_14015bb10();

    return iVar2;

  }

LAB_140158c6b:

  FUN_14012e850("Parameter \'%s\' is invalid","joystick");

  FUN_14015bb10();

  return 0;

}




