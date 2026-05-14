// Address: 0x1403003f0
// Ghidra name: FUN_1403003f0
// ============ 0x1403003f0 FUN_1403003f0 (size=152) ============


void FUN_1403003f0(void)



{

  longlong lVar1;

  

  if (DAT_1403eacf0 != 0) {

    lVar1 = DAT_1403eacf0;

    if ((0xfff < (ulonglong)(((DAT_1403ead00 - DAT_1403eacf0) / 0x24) * 0x24)) &&

       (lVar1 = *(longlong *)(DAT_1403eacf0 + -8), 0x1f < (DAT_1403eacf0 - lVar1) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(lVar1);

    DAT_1403eacf0 = 0;

    DAT_1403eacf8 = 0;

    DAT_1403ead00 = 0;

  }

  return;

}




