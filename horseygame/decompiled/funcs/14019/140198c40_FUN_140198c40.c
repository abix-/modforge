// Address: 0x140198c40
// Ghidra name: FUN_140198c40
// ============ 0x140198c40 FUN_140198c40 (size=125) ============


void FUN_140198c40(PNOTIFYICONDATAW param_1)



{

  char cVar1;

  

  if ((param_1 != (PNOTIFYICONDATAW)0x0) &&

     ((DAT_1403e3d60 == '\0' || (cVar1 = FUN_1401aa7c0(param_1,0xb), cVar1 != '\0')))) {

    FUN_14021efd0(param_1);

    Shell_NotifyIconW(2,param_1);

    if (*(longlong *)(param_1[5].szTip + 0x38) != 0) {

      FUN_140198820();

    }

    if (*(HICON *)(param_1[5].szTip + 0x34) != (HICON)0x0) {

      DestroyIcon(*(HICON *)(param_1[5].szTip + 0x34));

    }

    if (*(HWND *)(param_1[5].szTip + 0x30) != (HWND)0x0) {

      DestroyWindow(*(HWND *)(param_1[5].szTip + 0x30));

    }

    FUN_1401841e0(param_1);

  }

  return;

}




