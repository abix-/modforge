// Address: 0x14022c5e0
// Ghidra name: FUN_14022c5e0
// ============ 0x14022c5e0 FUN_14022c5e0 (size=93) ============


void FUN_14022c5e0(undefined8 param_1,longlong param_2)



{

  HWND hWnd;

  size_t sVar1;

  LPCWSTR lpString;

  

  hWnd = *(HWND *)(*(longlong *)(param_2 + 0x188) + 8);

  sVar1 = strlen(*(char **)(param_2 + 8));

  lpString = (LPCWSTR)FUN_140197820("UTF-16LE",&DAT_14039c6f0,*(undefined8 *)(param_2 + 8),sVar1 + 1

                                   );

  SetWindowTextW(hWnd,lpString);

  FUN_1401841e0(lpString);

  return;

}




