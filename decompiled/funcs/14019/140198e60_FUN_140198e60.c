// Address: 0x140198e60
// Ghidra name: FUN_140198e60
// ============ 0x140198e60 FUN_140198e60 (size=77) ============


undefined8 FUN_140198e60(longlong param_1)



{

  char cVar1;

  

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,0xb);

      if (cVar1 == '\0') goto LAB_140198e92;

    }

    return *(undefined8 *)(param_1 + 0x3e0);

  }

LAB_140198e92:

  FUN_14012e850("Parameter \'%s\' is invalid",&DAT_14033b05c);

  return 0;

}




