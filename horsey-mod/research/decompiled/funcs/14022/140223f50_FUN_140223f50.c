// Address: 0x140223f50
// Ghidra name: FUN_140223f50
// ============ 0x140223f50 FUN_140223f50 (size=99) ============


void FUN_140223f50(longlong param_1)



{

  HWND pHVar1;

  

  if ((*(char *)(param_1 + 0x140) != '\0') &&

     (pHVar1 = *(HWND *)(param_1 + 0x150), pHVar1 != (HWND)0x0)) {

    if (*(char *)(param_1 + 0x142) == '\0') {

      FUN_140223f00(param_1);

      return;

    }

    if (pHVar1 == *(HWND *)(param_1 + 0x148)) {

      ImmAssociateContext(pHVar1,*(HIMC *)(param_1 + 0x160));

    }

    *(undefined1 *)(param_1 + 0x141) = 1;

    FUN_140225110(param_1);

    return;

  }

  return;

}




