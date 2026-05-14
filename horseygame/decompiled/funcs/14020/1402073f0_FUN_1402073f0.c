// Address: 0x1402073f0
// Ghidra name: FUN_1402073f0
// ============ 0x1402073f0 FUN_1402073f0 (size=105) ============


longlong FUN_1402073f0(longlong param_1)



{

  longlong lVar1;

  

  if (param_1 == 0) {

    lVar1 = 0;

  }

  else {

    lVar1 = FUN_14012fd40();

    lVar1 = FUN_140197820(&DAT_14039c6f0,"WCHAR_T",param_1,lVar1 * 2 + 2);

    if (lVar1 == 0) {

      lVar1 = FUN_14012fd40(param_1);

      lVar1 = FUN_140197820(&DAT_14039c6f0,"UCS-2-INTERNAL",param_1,lVar1 * 2 + 2);

      return lVar1;

    }

  }

  return lVar1;

}




