// Address: 0x140157da0
// Ghidra name: FUN_140157da0
// ============ 0x140157da0 FUN_140157da0 (size=252) ============


ulonglong FUN_140157da0(longlong param_1,int param_2,undefined2 *param_3)



{

  byte bVar1;

  longlong lVar2;

  char cVar3;

  ulonglong uVar4;

  

  FUN_140159d30();

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar3 = FUN_1401aa7c0(param_1,4);

      if (cVar3 == '\0') goto LAB_140157e72;

    }

    if (*(int *)(param_1 + 0x44) <= param_2) {

      FUN_14012e850("Joystick only has %d axes");

      FUN_14015bb10();

      return 0;

    }

    if (param_3 != (undefined2 *)0x0) {

      lVar2 = (longlong)param_2 * 10;

      *param_3 = *(undefined2 *)(lVar2 + *(longlong *)(param_1 + 0x48));

      bVar1 = *(byte *)(*(longlong *)(param_1 + 0x48) + 6 + lVar2);

      FUN_14015bb10();

      return (ulonglong)bVar1;

    }

    bVar1 = *(byte *)(*(longlong *)(param_1 + 0x48) + 6 + (longlong)param_2 * 10);

    FUN_14015bb10();

    return (ulonglong)bVar1;

  }

LAB_140157e72:

  FUN_14012e850("Parameter \'%s\' is invalid","joystick");

  uVar4 = FUN_14015bb10();

  return uVar4 & 0xffffffffffffff00;

}




