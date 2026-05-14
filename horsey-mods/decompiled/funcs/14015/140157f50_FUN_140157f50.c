// Address: 0x140157f50
// Ghidra name: FUN_140157f50
// ============ 0x140157f50 FUN_140157f50 (size=216) ============


ulonglong FUN_140157f50(longlong param_1,int param_2,undefined4 *param_3,undefined4 *param_4)



{

  longlong lVar1;

  char cVar2;

  byte bVar3;

  ulonglong uVar4;

  

  FUN_140159d30();

  if (param_1 == 0) {

LAB_140157ff8:

    FUN_14012e850("Parameter \'%s\' is invalid","joystick");

    uVar4 = FUN_14015bb10();

    uVar4 = uVar4 & 0xffffffffffffff00;

  }

  else {

    if (DAT_1403e3d60 != '\0') {

      cVar2 = FUN_1401aa7c0(param_1,4);

      if (cVar2 == '\0') goto LAB_140157ff8;

    }

    if (param_2 < *(int *)(param_1 + 0x50)) {

      if (param_3 != (undefined4 *)0x0) {

        *param_3 = *(undefined4 *)(*(longlong *)(param_1 + 0x58) + (longlong)param_2 * 8);

      }

      lVar1 = (longlong)param_2 * 8;

      if (param_4 != (undefined4 *)0x0) {

        *param_4 = *(undefined4 *)(lVar1 + 4 + *(longlong *)(param_1 + 0x58));

      }

      *(undefined4 *)(lVar1 + *(longlong *)(param_1 + 0x58)) = 0;

      *(undefined4 *)(lVar1 + 4 + *(longlong *)(param_1 + 0x58)) = 0;

      FUN_14015bb10();

      uVar4 = 1;

    }

    else {

      bVar3 = FUN_14012e850("Joystick only has %d balls");

      FUN_14015bb10();

      uVar4 = (ulonglong)bVar3;

    }

  }

  return uVar4;

}




