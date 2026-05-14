// Address: 0x14014edc0
// Ghidra name: FUN_14014edc0
// ============ 0x14014edc0 FUN_14014edc0 (size=166) ============


undefined4 FUN_14014edc0(longlong param_1,undefined4 *param_2)



{

  char cVar1;

  undefined4 uVar2;

  

  if (param_2 != (undefined4 *)0x0) {

    *param_2 = 0;

  }

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,2);

      if (cVar1 == '\0') goto LAB_14014ee46;

    }

    if (*(char *)(param_1 + 0x2d8) != '\0') {

      FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

      return 0;

    }

    if (param_2 != (undefined4 *)0x0) {

      uVar2 = FUN_14014f090(param_1);

      uVar2 = FUN_140174c40(uVar2,"SDL.renderer.vsync",0);

      *param_2 = uVar2;

    }

    return 1;

  }

LAB_14014ee46:

  FUN_14012e850("Parameter \'%s\' is invalid","renderer");

  return 0;

}




