// Address: 0x140157ea0
// Ghidra name: FUN_140157ea0
// ============ 0x140157ea0 FUN_140157ea0 (size=164) ============


undefined2 FUN_140157ea0(longlong param_1,int param_2)



{

  undefined2 uVar1;

  char cVar2;

  

  FUN_140159d30();

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar2 = FUN_1401aa7c0(param_1,4);

      if (cVar2 == '\0') goto LAB_140157f1c;

    }

    if (param_2 < *(int *)(param_1 + 0x44)) {

      uVar1 = *(undefined2 *)(*(longlong *)(param_1 + 0x48) + 2 + (longlong)param_2 * 10);

      FUN_14015bb10();

      return uVar1;

    }

    FUN_14012e850("Joystick only has %d axes");

    FUN_14015bb10();

    return 0;

  }

LAB_140157f1c:

  FUN_14012e850("Parameter \'%s\' is invalid","joystick");

  FUN_14015bb10();

  return 0;

}




