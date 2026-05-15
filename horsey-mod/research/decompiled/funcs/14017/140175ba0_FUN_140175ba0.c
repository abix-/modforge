// Address: 0x140175ba0
// Ghidra name: FUN_140175ba0
// ============ 0x140175ba0 FUN_140175ba0 (size=78) ============


undefined8 FUN_140175ba0(longlong param_1)



{

  char cVar1;

  undefined8 uVar2;

  

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,6);

      if (cVar1 == '\0') goto LAB_140175bd3;

    }

    uVar2 = FUN_1401aa890(*(undefined8 *)(param_1 + 8));

    return uVar2;

  }

LAB_140175bd3:

  FUN_14012e850("Parameter \'%s\' is invalid","haptic");

  return 0;

}




