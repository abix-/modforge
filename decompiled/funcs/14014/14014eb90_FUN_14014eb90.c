// Address: 0x14014eb90
// Ghidra name: FUN_14014eb90
// ============ 0x14014eb90 FUN_14014eb90 (size=196) ============


undefined8 FUN_14014eb90(longlong param_1,undefined4 *param_2,undefined4 *param_3)



{

  longlong lVar1;

  char cVar2;

  

  if (param_2 != (undefined4 *)0x0) {

    *param_2 = 0x3f800000;

  }

  if (param_3 != (undefined4 *)0x0) {

    *param_3 = 0x3f800000;

  }

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar2 = FUN_1401aa7c0(param_1,2);

      if (cVar2 == '\0') goto LAB_14014ec2f;

    }

    if (*(char *)(param_1 + 0x2d8) != '\0') {

      FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

      return 0;

    }

    lVar1 = *(longlong *)(param_1 + 0x138);

    if (param_2 != (undefined4 *)0x0) {

      *param_2 = *(undefined4 *)(lVar1 + 0x4c);

    }

    if (param_3 != (undefined4 *)0x0) {

      *param_3 = *(undefined4 *)(lVar1 + 0x50);

    }

    return 1;

  }

LAB_14014ec2f:

  FUN_14012e850("Parameter \'%s\' is invalid","renderer");

  return 0;

}




