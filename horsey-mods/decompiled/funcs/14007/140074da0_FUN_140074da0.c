// Address: 0x140074da0
// Ghidra name: FUN_140074da0
// ============ 0x140074da0 FUN_140074da0 (size=392) ============


void FUN_140074da0(longlong *param_1,ulonglong param_2)



{

  ulonglong uVar1;

  longlong lVar2;

  ulonglong uVar3;

  longlong lVar4;

  longlong lVar5;

  

  if (0x492492492492492 < param_2) {

                    /* WARNING: Subroutine does not return */

    FUN_14002f0d0();

  }

  lVar2 = (param_1[1] - *param_1) / 0x38;

  uVar1 = (param_1[2] - *param_1) / 0x38;

  if (0x492492492492492 - (uVar1 >> 1) < uVar1) {

    uVar3 = 0x492492492492492;

  }

  else {

    uVar1 = (uVar1 >> 1) + uVar1;

    uVar3 = param_2;

    if ((param_2 <= uVar1) && (uVar3 = uVar1, 0x492492492492492 < uVar1)) {

                    /* WARNING: Subroutine does not return */

      FUN_140024090();

    }

  }

  lVar4 = FUN_1400285e0(uVar3 * 0x38);

  lVar5 = param_2 - lVar2;

  if (lVar5 != 0) {

    FUN_1402f94c0(lVar2 * 0x38 + lVar4,0,lVar5 * 0x38);

  }

  FUN_1402f8e20(lVar4,*param_1,param_1[1] - *param_1);

  lVar2 = *param_1;

  if (lVar2 != 0) {

    lVar5 = lVar2;

    if ((0xfff < (ulonglong)(((param_1[2] - lVar2) / 0x38) * 0x38)) &&

       (lVar5 = *(longlong *)(lVar2 + -8), 0x1f < (lVar2 - lVar5) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(lVar5);

  }

  *param_1 = lVar4;

  param_1[1] = param_2 * 0x38 + lVar4;

  param_1[2] = uVar3 * 0x38 + lVar4;

  return;

}




