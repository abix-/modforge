// Address: 0x140300720
// Ghidra name: FUN_140300720
// ============ 0x140300720 FUN_140300720 (size=117) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140300720(void)



{

  longlong lVar1;

  longlong lVar2;

  

  if (0xf < DAT_1403d9eb8) {

    lVar1 = CONCAT71(DAT_1403d9ea0._1_7_,(undefined1)DAT_1403d9ea0);

    lVar2 = lVar1;

    if ((0xfff < DAT_1403d9eb8 + 1) &&

       (lVar2 = *(longlong *)(lVar1 + -8), 0x1f < (lVar1 - lVar2) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(lVar2);

  }

  DAT_1403d9eb0 = _DAT_14039caa0;

  DAT_1403d9eb8 = _UNK_14039caa8;

  DAT_1403d9ea0._0_1_ = 0;

  return;

}




