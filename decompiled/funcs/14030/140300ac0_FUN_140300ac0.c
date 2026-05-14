// Address: 0x140300ac0
// Ghidra name: FUN_140300ac0
// ============ 0x140300ac0 FUN_140300ac0 (size=119) ============


void FUN_140300ac0(void)



{

  longlong lVar1;

  

  if (DAT_1403f3120 != 0) {

    lVar1 = DAT_1403f3120;

    if ((0xfff < (DAT_1403f3130 - DAT_1403f3120 & 0xfffffffffffffffcU)) &&

       (lVar1 = *(longlong *)(DAT_1403f3120 + -8), 0x1f < (DAT_1403f3120 - lVar1) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(lVar1);

    DAT_1403f3120 = 0;

    DAT_1403f3128 = 0;

    DAT_1403f3130 = 0;

  }

  return;

}




