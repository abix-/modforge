// Address: 0x1401585d0
// Ghidra name: FUN_1401585d0
// ============ 0x1401585d0 FUN_1401585d0 (size=136) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 * FUN_1401585d0(undefined8 *param_1,longlong param_2)



{

  undefined8 uVar1;

  undefined8 uVar2;

  char cVar3;

  

  FUN_140159d30();

  if (param_2 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar3 = FUN_1401aa7c0(param_2,4);

      if (cVar3 == '\0') goto LAB_140158628;

    }

    uVar1 = *(undefined8 *)(param_2 + 0x20);

    uVar2 = *(undefined8 *)(param_2 + 0x28);

    FUN_14015bb10();

    *param_1 = uVar1;

    param_1[1] = uVar2;

    return param_1;

  }

LAB_140158628:

  FUN_14012e850("Parameter \'%s\' is invalid","joystick");

  FUN_14015bb10();

  uVar1 = uRam00000001403fc090;

  *param_1 = _DAT_1403fc088;

  param_1[1] = uVar1;

  return param_1;

}




