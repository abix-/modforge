// Address: 0x14014e350
// Ghidra name: FUN_14014e350
// ============ 0x14014e350 FUN_14014e350 (size=239) ============


undefined8

FUN_14014e350(longlong param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,

             undefined4 *param_5)



{

  undefined4 uVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  char cVar4;

  

  if (param_2 != (undefined4 *)0x0) {

    *param_2 = 0;

  }

  if (param_3 != (undefined4 *)0x0) {

    *param_3 = 0;

  }

  if (param_4 != (undefined4 *)0x0) {

    *param_4 = 0;

  }

  if (param_5 != (undefined4 *)0x0) {

    *param_5 = 0;

  }

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar4 = FUN_1401aa7c0(param_1,2), cVar4 == '\0')))) {

    FUN_14012e850("Parameter \'%s\' is invalid","renderer");

  }

  else {

    if (*(char *)(param_1 + 0x2d8) == '\0') {

      uVar1 = *(undefined4 *)(param_1 + 0x220);

      uVar2 = *(undefined4 *)(param_1 + 0x224);

      uVar3 = *(undefined4 *)(param_1 + 0x228);

      if (param_2 != (undefined4 *)0x0) {

        *param_2 = *(undefined4 *)(param_1 + 0x21c);

      }

      if (param_3 != (undefined4 *)0x0) {

        *param_3 = uVar1;

      }

      if (param_4 != (undefined4 *)0x0) {

        *param_4 = uVar2;

      }

      if (param_5 != (undefined4 *)0x0) {

        *param_5 = uVar3;

      }

      return 1;

    }

    FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

  }

  return 0;

}




