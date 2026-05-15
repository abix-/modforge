// Address: 0x1400c3410
// Ghidra name: FUN_1400c3410
// ============ 0x1400c3410 FUN_1400c3410 (size=193) ============


void FUN_1400c3410(longlong *param_1)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar1 = *param_1;

  if (lVar1 != 0) {

    lVar2 = param_1[1];

    for (; lVar1 != lVar2; lVar1 = lVar1 + 0x28) {

      FUN_140027900(lVar1);

    }

    lVar1 = *param_1;

    lVar2 = lVar1;

    if ((0xfff < (ulonglong)(((param_1[2] - lVar1) / 0x28) * 0x28)) &&

       (lVar2 = *(longlong *)(lVar1 + -8), 0x1f < (lVar1 - lVar2) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(lVar2);

    *param_1 = 0;

    param_1[1] = 0;

    param_1[2] = 0;

  }

  return;

}




