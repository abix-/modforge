// Address: 0x140300b40
// Ghidra name: FUN_140300b40
// ============ 0x140300b40 FUN_140300b40 (size=119) ============


void FUN_140300b40(void)



{

  longlong lVar1;

  

  if (DAT_1403f3140 != 0) {

    lVar1 = DAT_1403f3140;

    if ((0xfff < (DAT_1403f3150 - DAT_1403f3140 & 0xfffffffffffffffcU)) &&

       (lVar1 = *(longlong *)(DAT_1403f3140 + -8), 0x1f < (DAT_1403f3140 - lVar1) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(lVar1);

    DAT_1403f3140 = 0;

    DAT_1403f3148 = 0;

    DAT_1403f3150 = 0;

  }

  return;

}




