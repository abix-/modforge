// Address: 0x140300bc0
// Ghidra name: FUN_140300bc0
// ============ 0x140300bc0 FUN_140300bc0 (size=119) ============


void FUN_140300bc0(void)



{

  longlong lVar1;

  

  if (DAT_1403f3178 != 0) {

    lVar1 = DAT_1403f3178;

    if ((0xfff < (DAT_1403f3188 - DAT_1403f3178 & 0xfffffffffffffff0U)) &&

       (lVar1 = *(longlong *)(DAT_1403f3178 + -8), 0x1f < (DAT_1403f3178 - lVar1) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(lVar1);

    DAT_1403f3178 = 0;

    DAT_1403f3180 = 0;

    DAT_1403f3188 = 0;

  }

  return;

}




