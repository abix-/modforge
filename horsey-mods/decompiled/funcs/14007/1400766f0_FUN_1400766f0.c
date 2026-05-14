// Address: 0x1400766f0
// Ghidra name: FUN_1400766f0
// ============ 0x1400766f0 FUN_1400766f0 (size=149) ============


void FUN_1400766f0(longlong *param_1,longlong param_2,longlong param_3,longlong param_4)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar1 = *param_1;

  if (lVar1 != 0) {

    lVar2 = lVar1;

    if ((0xfff < (ulonglong)(param_1[2] - lVar1)) &&

       (lVar2 = *(longlong *)(lVar1 + -8), 0x1f < (lVar1 - lVar2) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(lVar2);

  }

  *param_1 = param_2;

  param_1[1] = param_2 + param_3;

  param_1[2] = param_2 + param_4;

  return;

}




