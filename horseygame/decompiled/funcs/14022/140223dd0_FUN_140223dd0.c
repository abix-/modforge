// Address: 0x140223dd0
// Ghidra name: FUN_140223dd0
// ============ 0x140223dd0 FUN_140223dd0 (size=161) ============


void FUN_140223dd0(longlong param_1)



{

  HIMC pHVar1;

  

  if ((*(char *)(param_1 + 0x140) != '\0') &&

     (pHVar1 = ImmGetContext(*(HWND *)(param_1 + 0x150)), pHVar1 != (HIMC)0x0)) {

    ImmNotifyIME(pHVar1,0x15,4,0);

    ImmSetCompositionStringW(pHVar1,9,&DAT_140356c04,2,&DAT_140356c04,2);

    ImmNotifyIME(pHVar1,0x11,0,0);

    ImmReleaseContext(*(HWND *)(param_1 + 0x150),pHVar1);

    FUN_140224c10(param_1);

  }

  return;

}




