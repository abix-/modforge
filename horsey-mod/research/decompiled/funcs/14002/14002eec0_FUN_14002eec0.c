// Address: 0x14002eec0
// Ghidra name: FUN_14002eec0
// ============ 0x14002eec0 FUN_14002eec0 (size=327) ============


void FUN_14002eec0(longlong *param_1,ulonglong param_2)



{

  longlong lVar1;

  ulonglong uVar2;

  ulonglong uVar3;

  longlong lVar4;

  longlong lVar5;

  

  if (0x7ffffffffffffff < param_2) {

                    /* WARNING: Subroutine does not return */

    FUN_14002f0d0();

  }

  uVar2 = param_1[2] - *param_1 >> 5;

  lVar5 = param_1[1] - *param_1 >> 5;

  if (0x7ffffffffffffff - (uVar2 >> 1) < uVar2) {

    uVar3 = 0x7ffffffffffffff;

  }

  else {

    uVar2 = (uVar2 >> 1) + uVar2;

    uVar3 = param_2;

    if ((param_2 <= uVar2) && (uVar3 = uVar2, 0x7ffffffffffffff < uVar2)) {

                    /* WARNING: Subroutine does not return */

      FUN_140024090();

    }

  }

  lVar1 = FUN_1400285e0(uVar3 * 0x20);

  lVar4 = param_2 - lVar5;

  if (lVar4 != 0) {

    FUN_1402f94c0(lVar5 * 0x20 + lVar1,0,lVar4 * 0x20);

  }

  FUN_1402f8e20(lVar1);

  lVar5 = *param_1;

  if (lVar5 != 0) {

    lVar4 = lVar5;

    if ((0xfff < (param_1[2] - lVar5 & 0xffffffffffffffe0U)) &&

       (lVar4 = *(longlong *)(lVar5 + -8), 0x1f < (lVar5 - lVar4) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(lVar4);

  }

  *param_1 = lVar1;

  param_1[1] = param_2 * 0x20 + lVar1;

  param_1[2] = uVar3 * 0x20 + lVar1;

  return;

}




