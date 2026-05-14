// Address: 0x140199950
// Ghidra name: FUN_140199950
// ============ 0x140199950 FUN_140199950 (size=116) ============


void FUN_140199950(void)



{

  ushort uVar1;

  HMODULE hInstance;

  char *pcVar2;

  HICON pHVar3;

  

  hInstance = GetModuleHandleW((LPCWSTR)0x0);

  if (hInstance != (HMODULE)0x0) {

    pcVar2 = (char *)FUN_140142960("SDL_WINDOWS_INTRESOURCE_ICON_SMALL");

    if ((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) {

      pcVar2 = (char *)FUN_140142960("SDL_WINDOWS_INTRESOURCE_ICON");

      if ((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) goto LAB_1401999ab;

    }

    uVar1 = thunk_FUN_1402d89dc(pcVar2);

    pHVar3 = LoadIconW(hInstance,(LPCWSTR)(ulonglong)uVar1);

    if (pHVar3 != (HICON)0x0) {

      return;

    }

  }

LAB_1401999ab:

                    /* WARNING: Could not recover jumptable at 0x0001401999b7. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  LoadIconW((HINSTANCE)0x0,(LPCWSTR)0x7f00);

  return;

}




