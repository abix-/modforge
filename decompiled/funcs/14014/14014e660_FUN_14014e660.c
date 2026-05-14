// Address: 0x14014e660
// Ghidra name: FUN_14014e660
// ============ 0x14014e660 FUN_14014e660 (size=193) ============


undefined8

FUN_14014e660(longlong param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)



{

  longlong lVar1;

  char cVar2;

  

  if (param_2 != (undefined4 *)0x0) {

    *param_2 = 0;

  }

  if (param_3 != (undefined4 *)0x0) {

    *param_3 = 0;

  }

  if (param_4 != (undefined4 *)0x0) {

    *param_4 = 0;

  }

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar2 = FUN_1401aa7c0(param_1,2), cVar2 == '\0')))) {

    FUN_14012e850("Parameter \'%s\' is invalid","renderer");

  }

  else {

    if (*(char *)(param_1 + 0x2d8) == '\0') {

      lVar1 = *(longlong *)(param_1 + 0x138);

      if (param_2 != (undefined4 *)0x0) {

        *param_2 = *(undefined4 *)(lVar1 + 0x58);

      }

      if (param_3 != (undefined4 *)0x0) {

        *param_3 = *(undefined4 *)(lVar1 + 0x5c);

      }

      if (param_4 != (undefined4 *)0x0) {

        *param_4 = *(undefined4 *)(lVar1 + 0x54);

      }

      return 1;

    }

    FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

  }

  return 0;

}




