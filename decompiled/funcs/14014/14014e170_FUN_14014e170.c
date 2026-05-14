// Address: 0x14014e170
// Ghidra name: FUN_14014e170
// ============ 0x14014e170 FUN_14014e170 (size=153) ============


undefined8 FUN_14014e170(undefined4 param_1,undefined8 *param_2)



{

  undefined8 uVar1;

  char cVar2;

  longlong in_RCX;

  

  if (param_2 != (undefined8 *)0x0) {

    param_1 = 0;

    *param_2 = 0;

    param_2[1] = 0;

  }

  if (in_RCX != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar2 = FUN_1401aa7c0(param_1,2);

      if (cVar2 == '\0') goto LAB_14014e1e9;

    }

    if (*(char *)(in_RCX + 0x2d8) != '\0') {

      FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

      return 0;

    }

    if (param_2 != (undefined8 *)0x0) {

      uVar1 = *(undefined8 *)(*(longlong *)(in_RCX + 0x138) + 0x30);

      *param_2 = *(undefined8 *)(*(longlong *)(in_RCX + 0x138) + 0x28);

      param_2[1] = uVar1;

    }

    return 1;

  }

LAB_14014e1e9:

  FUN_14012e850("Parameter \'%s\' is invalid","renderer");

  return 0;

}




