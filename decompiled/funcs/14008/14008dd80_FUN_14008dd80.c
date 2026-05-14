// Address: 0x14008dd80
// Ghidra name: FUN_14008dd80
// ============ 0x14008dd80 FUN_14008dd80 (size=193) ============


void FUN_14008dd80(longlong *param_1)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar1 = *param_1;

  if (lVar1 != 0) {

    lVar2 = param_1[1];

    for (; lVar1 != lVar2; lVar1 = lVar1 + 0x18) {

      FUN_140030810(lVar1);

    }

    lVar1 = *param_1;

    lVar2 = lVar1;

    if ((0xfff < (ulonglong)(((param_1[2] - lVar1) / 0x18) * 0x18)) &&

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




