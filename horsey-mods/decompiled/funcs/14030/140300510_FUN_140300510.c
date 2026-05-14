// Address: 0x140300510
// Ghidra name: FUN_140300510
// ============ 0x140300510 FUN_140300510 (size=149) ============


void FUN_140300510(void)



{

  longlong lVar1;

  

  if (DAT_1403eacd8 != 0) {

    lVar1 = DAT_1403eacd8;

    if ((0xfff < (ulonglong)(((DAT_1403eace8 - DAT_1403eacd8) / 0x38) * 0x38)) &&

       (lVar1 = *(longlong *)(DAT_1403eacd8 + -8), 0x1f < (DAT_1403eacd8 - lVar1) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(lVar1);

    DAT_1403eacd8 = 0;

    DAT_1403eace0 = 0;

    DAT_1403eace8 = 0;

  }

  return;

}




