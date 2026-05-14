// Address: 0x140176e80
// Ghidra name: FUN_140176e80
// ============ 0x140176e80 FUN_140176e80 (size=154) ============


undefined8 FUN_140176e80(longlong param_1,undefined8 param_2,uint param_3)



{

  char cVar1;

  

  FUN_140177410();

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,7);

      if (cVar1 == '\0') goto LAB_140176ef0;

    }

    if (0xf < param_3) {

      param_3 = 0x10;

    }

    FUN_1402f8e20(param_2,param_1 + 0x18,(longlong)(int)param_3 << 2);

    FUN_140177750();

    return 1;

  }

LAB_140176ef0:

  FUN_14012e850("Parameter \'%s\' is invalid","sensor");

  FUN_140177750();

  return 0;

}




