// Address: 0x140175ce0
// Ghidra name: FUN_140175ce0
// ============ 0x140175ce0 FUN_140175ce0 (size=76) ============


undefined4 FUN_140175ce0(longlong param_1)



{

  char cVar1;

  

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,6);

      if (cVar1 == '\0') goto LAB_140175d0e;

    }

    return *(undefined4 *)(param_1 + 0x18);

  }

LAB_140175d0e:

  FUN_14012e850("Parameter \'%s\' is invalid","haptic");

  return 0xffffffff;

}




