// Address: 0x140300cd0
// Ghidra name: FUN_140300cd0
// ============ 0x140300cd0 FUN_140300cd0 (size=117) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140300cd0(void)



{

  longlong lVar1;

  longlong lVar2;

  

  if (0xf < DAT_1403da670) {

    lVar1 = CONCAT71(DAT_1403da658._1_7_,(undefined1)DAT_1403da658);

    lVar2 = lVar1;

    if ((0xfff < DAT_1403da670 + 1) &&

       (lVar2 = *(longlong *)(lVar1 + -8), 0x1f < (lVar1 - lVar2) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(lVar2);

  }

  DAT_1403da668 = _DAT_14039caa0;

  DAT_1403da670 = _UNK_14039caa8;

  DAT_1403da658._0_1_ = 0;

  return;

}




