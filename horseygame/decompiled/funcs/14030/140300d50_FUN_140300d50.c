// Address: 0x140300d50
// Ghidra name: FUN_140300d50
// ============ 0x140300d50 FUN_140300d50 (size=117) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140300d50(void)



{

  longlong lVar1;

  longlong lVar2;

  

  if (0xf < DAT_1403da650) {

    lVar1 = CONCAT71(DAT_1403da638._1_7_,(undefined1)DAT_1403da638);

    lVar2 = lVar1;

    if ((0xfff < DAT_1403da650 + 1) &&

       (lVar2 = *(longlong *)(lVar1 + -8), 0x1f < (lVar1 - lVar2) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(lVar2);

  }

  _DAT_1403da648 = _DAT_14039caa0;

  DAT_1403da650 = _UNK_14039caa8;

  DAT_1403da638._0_1_ = 0;

  return;

}




