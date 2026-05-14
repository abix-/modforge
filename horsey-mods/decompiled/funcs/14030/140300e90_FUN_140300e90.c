// Address: 0x140300e90
// Ghidra name: FUN_140300e90
// ============ 0x140300e90 FUN_140300e90 (size=119) ============


void FUN_140300e90(void)



{

  longlong lVar1;

  

  if (DAT_1403f34f8 != 0) {

    lVar1 = DAT_1403f34f8;

    if ((0xfff < (DAT_1403f3508 - DAT_1403f34f8 & 0xfffffffffffffff8U)) &&

       (lVar1 = *(longlong *)(DAT_1403f34f8 + -8), 0x1f < (DAT_1403f34f8 - lVar1) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(lVar1);

    DAT_1403f34f8 = 0;

    DAT_1403f3500 = 0;

    DAT_1403f3508 = 0;

  }

  return;

}




