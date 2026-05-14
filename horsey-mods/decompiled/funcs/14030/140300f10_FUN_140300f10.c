// Address: 0x140300f10
// Ghidra name: FUN_140300f10
// ============ 0x140300f10 FUN_140300f10 (size=119) ============


void FUN_140300f10(void)



{

  longlong lVar1;

  

  if (DAT_1403f34c8 != 0) {

    lVar1 = DAT_1403f34c8;

    if ((0xfff < (DAT_1403f34d8 - DAT_1403f34c8 & 0xfffffffffffffffcU)) &&

       (lVar1 = *(longlong *)(DAT_1403f34c8 + -8), 0x1f < (DAT_1403f34c8 - lVar1) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(lVar1);

    DAT_1403f34c8 = 0;

    DAT_1403f34d0 = 0;

    DAT_1403f34d8 = 0;

  }

  return;

}




