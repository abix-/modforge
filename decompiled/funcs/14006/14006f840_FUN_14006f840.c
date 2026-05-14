// Address: 0x14006f840
// Ghidra name: FUN_14006f840
// ============ 0x14006f840 FUN_14006f840 (size=403) ============


void FUN_14006f840(longlong *param_1,ulonglong param_2)



{

  longlong lVar1;

  ulonglong uVar2;

  longlong lVar3;

  ulonglong uVar4;

  longlong lVar5;

  ulonglong uVar6;

  

  lVar1 = param_1[1];

  lVar3 = *param_1;

  uVar6 = lVar1 - lVar3 >> 3;

  if (param_2 < uVar6) {

    param_1[1] = lVar3 + param_2 * 8;

    return;

  }

  if (uVar6 < param_2) {

    uVar4 = param_1[2] - lVar3 >> 3;

    if (param_2 <= uVar4) {

      lVar3 = (param_2 - uVar6) * 8;

      FUN_1402f94c0(lVar1,0,lVar3);

      param_1[1] = lVar3 + lVar1;

      return;

    }

    if (0x1fffffffffffffff < param_2) {

                    /* WARNING: Subroutine does not return */

      FUN_14002f0d0();

    }

    if (0x1fffffffffffffff - (uVar4 >> 1) < uVar4) {

      uVar2 = 0x1fffffffffffffff;

    }

    else {

      uVar4 = uVar4 + (uVar4 >> 1);

      uVar2 = param_2;

      if ((param_2 <= uVar4) && (uVar2 = uVar4, 0x1fffffffffffffff < uVar4)) {

                    /* WARNING: Subroutine does not return */

        FUN_140024090();

      }

    }

    lVar3 = FUN_1400285e0(uVar2 * 8);

    FUN_1402f94c0(lVar3 + uVar6 * 8,0,(param_2 - uVar6) * 8);

    FUN_1402f8e20(lVar3);

    lVar1 = *param_1;

    if (lVar1 != 0) {

      lVar5 = lVar1;

      if ((0xfff < (param_1[2] - lVar1 & 0xfffffffffffffff8U)) &&

         (lVar5 = *(longlong *)(lVar1 + -8), 0x1f < (lVar1 - lVar5) - 8U)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088(lVar5);

    }

    *param_1 = lVar3;

    param_1[1] = lVar3 + param_2 * 8;

    param_1[2] = uVar2 * 8 + lVar3;

  }

  return;

}




