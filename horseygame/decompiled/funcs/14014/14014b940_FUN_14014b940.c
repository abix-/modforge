// Address: 0x14014b940
// Ghidra name: FUN_14014b940
// ============ 0x14014b940 FUN_14014b940 (size=248) ============


longlong FUN_14014b940(longlong param_1,longlong param_2,longlong param_3,longlong *param_4)



{

  ulonglong uVar1;

  ulonglong uVar2;

  longlong lVar3;

  ulonglong uVar4;

  

  uVar1 = *(ulonglong *)(param_1 + 0x2a0);

  uVar4 = uVar1 + param_2 + param_3;

  if ((param_3 == 0) || (uVar2 = param_3 - 1U & uVar1, uVar2 == 0)) {

    param_3 = 0;

  }

  else {

    param_3 = param_3 - uVar2;

  }

  if (*(ulonglong *)(param_1 + 0x2a8) < uVar4) {

    uVar2 = 0x400;

    if (*(longlong *)(param_1 + 0x298) != 0) {

      uVar2 = *(ulonglong *)(param_1 + 0x2a8);

    }

    do {

      uVar2 = uVar2 * 2;

    } while (uVar2 < uVar4);

    lVar3 = FUN_140184230(*(longlong *)(param_1 + 0x298),uVar2);

    if (lVar3 == 0) {

      return 0;

    }

    *(longlong *)(param_1 + 0x298) = lVar3;

    *(ulonglong *)(param_1 + 0x2a8) = uVar2;

  }

  if (param_4 != (longlong *)0x0) {

    *param_4 = uVar1 + param_3;

  }

  *(longlong *)(param_1 + 0x2a0) = *(longlong *)(param_1 + 0x2a0) + param_3 + param_2;

  return *(longlong *)(param_1 + 0x298) + uVar1 + param_3;

}




