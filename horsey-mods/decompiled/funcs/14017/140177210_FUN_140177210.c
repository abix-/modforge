// Address: 0x140177210
// Ghidra name: FUN_140177210
// ============ 0x140177210 FUN_140177210 (size=96) ============


undefined4 FUN_140177210(longlong param_1)



{

  undefined4 uVar1;

  char cVar2;

  

  FUN_140177410();

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar2 = FUN_1401aa7c0(param_1,7);

      if (cVar2 == '\0') goto LAB_14017724d;

    }

    uVar1 = *(undefined4 *)(param_1 + 0x10);

    FUN_140177750();

    return uVar1;

  }

LAB_14017724d:

  FUN_14012e850("Parameter \'%s\' is invalid","sensor");

  FUN_140177750();

  return 0xffffffff;

}




