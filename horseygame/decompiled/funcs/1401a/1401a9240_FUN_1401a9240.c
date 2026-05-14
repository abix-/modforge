// Address: 0x1401a9240
// Ghidra name: FUN_1401a9240
// ============ 0x1401a9240 FUN_1401a9240 (size=143) ============


void FUN_1401a9240(void)



{

  BOOL BVar1;

  HMODULE hInstance;

  

  hInstance = GetModuleHandleW((LPCWSTR)0x0);

  if (DAT_1403fcd60 != (HWND)0x0) {

    BVar1 = DestroyWindow(DAT_1403fcd60);

    if (BVar1 == 0) {

      FUN_1401a9ed0("Unable to destroy Helper Window");

      return;

    }

    DAT_1403fcd60 = (HWND)0x0;

  }

  if (DAT_1403fcd68 != 0) {

    BVar1 = UnregisterClassW((LPCWSTR)PTR_u_SDLHelperWindowInputCatcher_1403e3d48,hInstance);

    if (BVar1 == 0) {

      FUN_1401a9ed0("Unable to destroy Helper Window Class");

      return;

    }

    DAT_1403fcd68 = 0;

  }

  return;

}




