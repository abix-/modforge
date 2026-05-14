// Address: 0x140229bb0
// Ghidra name: FUN_140229bb0
// ============ 0x140229bb0 FUN_140229bb0 (size=244) ============


void FUN_140229bb0(undefined8 param_1,longlong param_2)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_2 + 0x188);

  if (lVar1 != 0) {

    if (*(longlong *)(lVar1 + 0xd8) != 0) {

      FUN_14022a680(param_2,0);

    }

    FUN_1401841e0(*(undefined8 *)(lVar1 + 0xb0));

    if (*(HHOOK *)(lVar1 + 0x48) != (HHOOK)0x0) {

      UnhookWindowsHookEx(*(HHOOK *)(lVar1 + 0x48));

    }

    if (*(HICON *)(lVar1 + 0x38) != (HICON)0x0) {

      DestroyIcon(*(HICON *)(lVar1 + 0x38));

    }

    ReleaseDC(*(HWND *)(lVar1 + 8),*(HDC *)(lVar1 + 0x18));

    RemovePropW(*(HWND *)(lVar1 + 8),L"SDL_WindowData");

    if ((*(uint *)(param_2 + 0x48) >> 0xb & 1) == 0) {

      DestroyWindow(*(HWND *)(lVar1 + 8));

      if ((*(char *)(lVar1 + 0xad) != '\0') && (*(HWND *)(lVar1 + 0x10) != (HWND)0x0)) {

        DestroyWindow(*(HWND *)(lVar1 + 0x10));

      }

    }

    else if (*(longlong *)(lVar1 + 0x40) != 0) {

      SetWindowLongPtrW(*(HWND *)(lVar1 + 8),-4,*(longlong *)(lVar1 + 0x40));

    }

    FUN_1401841e0(lVar1);

    *(undefined8 *)(param_2 + 0x188) = 0;

    return;

  }

  *(undefined8 *)(param_2 + 0x188) = 0;

  return;

}




