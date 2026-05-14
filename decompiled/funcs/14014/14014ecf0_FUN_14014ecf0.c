// Address: 0x14014ecf0
// Ghidra name: FUN_14014ecf0
// ============ 0x14014ecf0 FUN_14014ecf0 (size=195) ============


undefined8 FUN_14014ecf0(longlong param_1,undefined4 *param_2,undefined4 *param_3)



{

  char cVar1;

  

  if (param_2 != (undefined4 *)0x0) {

    *param_2 = 0xffffffff;

  }

  if (param_3 != (undefined4 *)0x0) {

    *param_3 = 0xffffffff;

  }

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,2);

      if (cVar1 == '\0') goto LAB_14014ed8e;

    }

    if (*(char *)(param_1 + 0x2d8) != '\0') {

      FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

      return 0;

    }

    if (param_2 != (undefined4 *)0x0) {

      *param_2 = *(undefined4 *)(param_1 + 0x230);

    }

    if (param_3 != (undefined4 *)0x0) {

      *param_3 = *(undefined4 *)(param_1 + 0x234);

    }

    return 1;

  }

LAB_14014ed8e:

  FUN_14012e850("Parameter \'%s\' is invalid","renderer");

  return 0;

}




