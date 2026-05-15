// Address: 0x140176b00
// Ghidra name: FUN_140176b00
// ============ 0x140176b00 FUN_140176b00 (size=101) ============


undefined1 FUN_140176b00(longlong param_1)



{

  char cVar1;

  undefined1 uVar2;

  

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,6);

      if (cVar1 == '\0') goto LAB_140176b4a;

    }

    if (*(int *)(param_1 + 0x34) < 0) {

      uVar2 = FUN_14012e850("Haptic: Rumble effect not initialized on haptic device");

      return uVar2;

    }

    uVar2 = FUN_1401769f0(param_1);

    return uVar2;

  }

LAB_140176b4a:

  FUN_14012e850("Parameter \'%s\' is invalid","haptic");

  return 0;

}




