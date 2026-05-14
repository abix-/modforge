// Address: 0x140176f60
// Ghidra name: FUN_140176f60
// ============ 0x140176f60 FUN_140176f60 (size=92) ============


undefined4 FUN_140176f60(undefined4 *param_1)



{

  undefined4 uVar1;

  char cVar2;

  

  FUN_140177410();

  if (param_1 != (undefined4 *)0x0) {

    if (DAT_1403e3d60 != '\0') {

      cVar2 = FUN_1401aa7c0(param_1,7);

      if (cVar2 == '\0') goto LAB_140176f9c;

    }

    uVar1 = *param_1;

    FUN_140177750();

    return uVar1;

  }

LAB_140176f9c:

  FUN_14012e850("Parameter \'%s\' is invalid","sensor");

  FUN_140177750();

  return 0;

}




