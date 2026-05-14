// Address: 0x140154cf0
// Ghidra name: FUN_140154cf0
// ============ 0x140154cf0 FUN_140154cf0 (size=295) ============


undefined8 FUN_140154cf0(longlong param_1,int param_2)



{

  char cVar1;

  char extraout_AL;

  undefined4 uVar2;

  undefined8 uVar3;

  

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar1 = FUN_1401aa7c0(param_1,2), cVar1 == '\0')))) {

    FUN_14012e850("Parameter \'%s\' is invalid","renderer");

    return 0;

  }

  if (*(char *)(param_1 + 0x2d8) != '\0') {

    FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

    return 0;

  }

  *(bool *)(param_1 + 0x121) = param_2 != 0;

  if (*(char *)(param_1 + 0x114) != '\0') {

    if (*(longlong *)(param_1 + 0x118) == 0) {

      if (param_2 == 0) {

        return 1;

      }

      goto LAB_140154d6a;

    }

    FUN_1401723f0(0,*(longlong *)(param_1 + 0x118),param_2);

    if (extraout_AL != '\0') {

      *(undefined1 *)(param_1 + 0x122) = 0;

      return 1;

    }

  }

  if ((*(code **)(param_1 + 0xe0) == (code *)0x0) ||

     (cVar1 = (**(code **)(param_1 + 0xe0))(param_1,param_2), cVar1 == '\0')) {

    if (param_2 == 0) {

      *(undefined1 *)(param_1 + 0x122) = 0;

    }

    else {

      if (param_2 != 1) {

LAB_140154d6a:

        uVar3 = FUN_14012e850("That operation is not supported");

        return uVar3;

      }

      *(undefined1 *)(param_1 + 0x122) = 1;

    }

  }

  uVar2 = FUN_14014f090(param_1);

  FUN_140175360(uVar2,"SDL.renderer.vsync",(longlong)param_2);

  return 1;

}




