// Address: 0x1403005b0
// Ghidra name: FUN_1403005b0
// ============ 0x1403005b0 FUN_1403005b0 (size=115) ============


void FUN_1403005b0(void)



{

  longlong lVar1;

  

  if (DAT_1403ead28 != 0) {

    lVar1 = DAT_1403ead28;

    if ((0xfff < (ulonglong)(DAT_1403ead38 - DAT_1403ead28)) &&

       (lVar1 = *(longlong *)(DAT_1403ead28 + -8), 0x1f < (DAT_1403ead28 - lVar1) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(lVar1);

    DAT_1403ead28 = 0;

    DAT_1403ead30 = 0;

    DAT_1403ead38 = 0;

  }

  return;

}




