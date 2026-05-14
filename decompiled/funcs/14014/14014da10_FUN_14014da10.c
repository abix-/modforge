// Address: 0x14014da10
// Ghidra name: FUN_14014da10
// ============ 0x14014da10 FUN_14014da10 (size=343) ============


void FUN_14014da10(longlong param_1)



{

  undefined4 uVar1;

  longlong lVar2;

  

  *(undefined1 *)(param_1 + 0x2d8) = 1;

  FUN_1401cda70(1,FUN_1401537c0,param_1);

  if (*(longlong *)(param_1 + 0x118) != 0) {

    uVar1 = FUN_14016ea50();

    lVar2 = FUN_140174d30(uVar1,"SDL.internal.window.renderer",0);

    if (lVar2 == param_1) {

      FUN_1401745e0(uVar1,"SDL.internal.window.renderer");

    }

    FUN_140170080(*(undefined8 *)(param_1 + 0x118),param_1);

  }

  if (*(char *)(param_1 + 0x114) != '\0') {

    FUN_140149cf0(param_1);

  }

  FUN_14014ddb0(param_1);

  if (*(longlong *)(param_1 + 0x2d0) != 0) {

    FUN_14014dd50();

    *(undefined8 *)(param_1 + 0x2d0) = 0;

  }

  lVar2 = *(longlong *)(param_1 + 0x1e8);

  while (lVar2 != 0) {

    FUN_14014dc20(lVar2,1);

    lVar2 = *(longlong *)(param_1 + 0x1e8);

  }

  if (*(longlong *)(param_1 + 0x200) != 0) {

    FUN_1401aafa0();

    *(undefined8 *)(param_1 + 0x200) = 0;

  }

  if (*(code **)(param_1 + 0xd8) != (code *)0x0) {

    (**(code **)(param_1 + 0xd8))(param_1);

  }

  if (*(longlong *)(param_1 + 0x1f8) != 0) {

    FUN_140179b30();

    *(undefined8 *)(param_1 + 0x1f8) = 0;

  }

  if (*(longlong *)(param_1 + 0x298) != 0) {

    FUN_1401841e0();

    *(undefined8 *)(param_1 + 0x298) = 0;

  }

  if (*(longlong *)(param_1 + 0x108) != 0) {

    FUN_1401841e0();

    *(undefined8 *)(param_1 + 0x108) = 0;

  }

  if (*(int *)(param_1 + 0x2c8) != 0) {

    FUN_1401747e0();

    *(undefined4 *)(param_1 + 0x2c8) = 0;

  }

  return;

}




