// Address: 0x1401a90f0
// Ghidra name: FUN_1401a90f0
// ============ 0x1401a90f0 FUN_1401a90f0 (size=328) ============


undefined1 FUN_1401a90f0(void)



{

  undefined1 uVar1;

  DWORD DVar2;

  HMODULE hInstance;

  WNDCLASSW local_58;

  

  hInstance = GetModuleHandleW((LPCWSTR)0x0);

  if (DAT_1403fcd60 == (HWND)0x0) {

    local_58.lpfnWndProc = DefWindowProcW_exref;

    local_58.lpszClassName = (LPCWSTR)PTR_u_SDLHelperWindowInputCatcher_1403e3d48;

    local_58.style = 0;

    local_58._4_4_ = 0;

    local_58.cbClsExtra = 0;

    local_58.cbWndExtra = 0;

    local_58.hIcon = (HICON)0x0;

    local_58.hCursor = (HCURSOR)0x0;

    local_58.hbrBackground = (HBRUSH)0x0;

    local_58.lpszMenuName = (LPCWSTR)0x0;

    local_58.hInstance = hInstance;

    DAT_1403fcd68 = RegisterClassW(&local_58);

    if (DAT_1403fcd68 == 0) {

      DVar2 = GetLastError();

      if (DVar2 != 0x582) {

        uVar1 = FUN_1401a9ed0("Unable to create Helper Window Class");

        return uVar1;

      }

    }

    DAT_1403fcd60 =

         CreateWindowExW(0,(LPCWSTR)PTR_u_SDLHelperWindowInputCatcher_1403e3d48,

                         (LPCWSTR)PTR_u_SDLHelperWindowInputMsgWindow_1403e3d50,0,-0x80000000,

                         -0x80000000,-0x80000000,-0x80000000,(HWND)0xfffffffffffffffd,(HMENU)0x0,

                         hInstance,(LPVOID)0x0);

    if (DAT_1403fcd60 == (HWND)0x0) {

      UnregisterClassW((LPCWSTR)PTR_u_SDLHelperWindowInputCatcher_1403e3d48,hInstance);

      uVar1 = FUN_1401a9ed0("Unable to create Helper Window");

      return uVar1;

    }

  }

  return 1;

}




