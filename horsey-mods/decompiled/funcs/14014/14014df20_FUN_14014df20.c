// Address: 0x14014df20
// Ghidra name: FUN_14014df20
// ============ 0x14014df20 FUN_14014df20 (size=188) ============


undefined8 FUN_14014df20(longlong param_1,undefined4 *param_2,undefined4 *param_3)



{

  undefined4 *puVar1;

  char cVar2;

  

  if (param_2 != (undefined4 *)0x0) {

    *param_2 = 0;

  }

  if (param_3 != (undefined4 *)0x0) {

    *param_3 = 0;

  }

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar2 = FUN_1401aa7c0(param_1,2);

      if (cVar2 == '\0') goto LAB_14014dfb7;

    }

    if (*(char *)(param_1 + 0x2d8) != '\0') {

      FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

      return 0;

    }

    puVar1 = *(undefined4 **)(param_1 + 0x138);

    if (param_2 != (undefined4 *)0x0) {

      *param_2 = *puVar1;

    }

    if (param_3 != (undefined4 *)0x0) {

      *param_3 = puVar1[1];

    }

    return 1;

  }

LAB_14014dfb7:

  FUN_14012e850("Parameter \'%s\' is invalid","renderer");

  return 0;

}




