// Address: 0x140300310
// Ghidra name: FUN_140300310
// ============ 0x140300310 FUN_140300310 (size=119) ============


void FUN_140300310(void)



{

  longlong lVar1;

  

  if (DAT_1403ea2d0 != 0) {

    lVar1 = DAT_1403ea2d0;

    if ((0xfff < (DAT_1403ea2e0 - DAT_1403ea2d0 & 0xfffffffffffffff8U)) &&

       (lVar1 = *(longlong *)(DAT_1403ea2d0 + -8), 0x1f < (DAT_1403ea2d0 - lVar1) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(lVar1);

    DAT_1403ea2d0 = 0;

    DAT_1403ea2d8 = 0;

    DAT_1403ea2e0 = 0;

  }

  return;

}




