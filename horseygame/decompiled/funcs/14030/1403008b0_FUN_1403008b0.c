// Address: 0x1403008b0
// Ghidra name: FUN_1403008b0
// ============ 0x1403008b0 FUN_1403008b0 (size=209) ============


void FUN_1403008b0(void)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar1 = DAT_1403f2fc8;

  lVar2 = DAT_1403f2fc0;

  if (DAT_1403f2fc0 != 0) {

    for (; lVar2 != lVar1; lVar2 = lVar2 + 0x1018) {

      FUN_140027900(lVar2 + 8);

    }

    lVar2 = DAT_1403f2fc0;

    if ((0xfff < (ulonglong)(((DAT_1403f2fd0 - DAT_1403f2fc0) / 0x1018) * 0x1018)) &&

       (lVar2 = *(longlong *)(DAT_1403f2fc0 + -8), 0x1f < (DAT_1403f2fc0 - lVar2) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(lVar2);

    DAT_1403f2fc0 = 0;

    DAT_1403f2fc8 = 0;

    DAT_1403f2fd0 = 0;

  }

  return;

}




