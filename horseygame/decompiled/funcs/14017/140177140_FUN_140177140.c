// Address: 0x140177140
// Ghidra name: FUN_140177140
// ============ 0x140177140 FUN_140177140 (size=117) ============


int FUN_140177140(longlong param_1)



{

  char cVar1;

  int iVar2;

  

  FUN_140177410();

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,7);

      if (cVar1 == '\0') goto LAB_140177195;

    }

    iVar2 = *(int *)(param_1 + 0x68);

    if (iVar2 == 0) {

      iVar2 = FUN_1401746e0();

      *(int *)(param_1 + 0x68) = iVar2;

    }

    FUN_140177750();

    return iVar2;

  }

LAB_140177195:

  FUN_14012e850("Parameter \'%s\' is invalid","sensor");

  FUN_140177750();

  return 0;

}




