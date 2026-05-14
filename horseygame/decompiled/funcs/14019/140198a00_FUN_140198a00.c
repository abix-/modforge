// Address: 0x140198a00
// Ghidra name: FUN_140198a00
// ============ 0x140198a00 FUN_140198a00 (size=566) ============


PNOTIFYICONDATAW FUN_140198a00(longlong param_1,char *param_2)



{

  char cVar1;

  UINT UVar2;

  PNOTIFYICONDATAW lpData;

  HWND pHVar3;

  size_t sVar4;

  undefined8 uVar5;

  HICON pHVar6;

  

  cVar1 = FUN_14017e7d0();

  if (cVar1 == '\0') {

    FUN_14012e850("This function should be called on the main thread");

    return (PNOTIFYICONDATAW)0x0;

  }

  lpData = (PNOTIFYICONDATAW)FUN_1401841a0(1,1000);

  if (lpData == (PNOTIFYICONDATAW)0x0) {

    return (PNOTIFYICONDATAW)0x0;

  }

  lpData[5].szTip[0x38] = L'\0';

  lpData[5].szTip[0x39] = L'\0';

  lpData[5].szTip[0x3a] = L'\0';

  lpData[5].szTip[0x3b] = L'\0';

  cVar1 = FUN_140199220(L"SDL_TRAY");

  if (cVar1 == '\0') {

    FUN_14012e850("Failed to register SDL_TRAY window class");

    return (PNOTIFYICONDATAW)0x0;

  }

  pHVar3 = CreateWindowExW(0,L"SDL_TRAY",(LPCWSTR)0x0,0xcf0000,-0x80000000,0,-0x80000000,0,(HWND)0x0

                           ,(HMENU)0x0,(HINSTANCE)0x0,(LPVOID)0x0);

  *(HWND *)(lpData[5].szTip + 0x30) = pHVar3;

  FUN_1401a9fe0(pHVar3);

  *(undefined4 *)&lpData->field_0x4 = 0;

  FUN_1402f94c0(&lpData->field_0x1c,0,0x314);

  lpData[4].szTip[0x36] = L'\0';

  lpData[4].szTip[0x37] = L'\0';

  lpData[4].szTip[0x38] = L'\0';

  lpData[4].szTip[0x39] = L'\0';

  lpData[4].szTip[0x3a] = L'\0';

  lpData[4].szTip[0x3b] = L'\0';

  lpData[4].szTip[0x3c] = L'\0';

  lpData[4].szTip[0x3d] = L'\0';

  *(undefined8 *)(lpData[4].szTip + 0x3e) = 0;

  *(undefined8 *)&lpData[5].field_0x4 = 0;

  *(undefined8 *)((longlong)&lpData[5].hWnd + 4) = 0;

  lpData[5].uFlags = 0;

  lpData[5].uCallbackMessage = 0;

  *(undefined8 *)&lpData[5].field_0x1c = 0;

  *(undefined8 *)((longlong)&lpData[5].hIcon + 4) = 0;

  lpData[5].szTip[2] = L'\0';

  lpData[5].szTip[3] = L'\0';

  lpData[5].szTip[4] = L'\0';

  lpData[5].szTip[5] = L'\0';

  lpData[5].szTip[6] = L'\0';

  lpData[5].szTip[7] = L'\0';

  lpData[5].szTip[8] = L'\0';

  lpData[5].szTip[9] = L'\0';

  lpData[5].szTip[10] = L'\0';

  lpData[5].szTip[0xb] = L'\0';

  lpData[5].szTip[0xc] = L'\0';

  lpData[5].szTip[0xd] = L'\0';

  lpData[5].szTip[0xe] = L'\0';

  lpData[5].szTip[0xf] = L'\0';

  lpData[5].szTip[0x10] = L'\0';

  lpData[5].szTip[0x11] = L'\0';

  lpData[5].szTip[0x12] = L'\0';

  lpData[5].szTip[0x13] = L'\0';

  lpData[5].szTip[0x14] = L'\0';

  lpData[5].szTip[0x15] = L'\0';

  lpData[5].szTip[0x16] = L'\0';

  lpData[5].szTip[0x17] = L'\0';

  lpData[5].szTip[0x18] = L'\0';

  lpData[5].szTip[0x19] = L'\0';

  lpData[5].szTip[0x1a] = L'\0';

  lpData[5].szTip[0x1b] = L'\0';

  lpData[5].szTip[0x1c] = L'\0';

  lpData[5].szTip[0x1d] = L'\0';

  lpData[5].szTip[0x1e] = L'\0';

  lpData[5].szTip[0x1f] = L'\0';

  lpData[5].szTip[0x20] = L'\0';

  lpData[5].szTip[0x21] = L'\0';

  lpData[5].szTip[0x22] = L'\0';

  lpData[5].szTip[0x23] = L'\0';

  lpData[5].szTip[0x24] = L'\0';

  lpData[5].szTip[0x25] = L'\0';

  lpData[5].szTip[0x26] = L'\0';

  lpData[5].szTip[0x27] = L'\0';

  lpData[5].szTip[0x28] = L'\0';

  lpData[5].szTip[0x29] = L'\0';

  lpData[5].szTip[0x2a] = L'\0';

  lpData[5].szTip[0x2b] = L'\0';

  lpData[5].szTip[0x2c] = L'\0';

  lpData[5].szTip[0x2d] = L'\0';

  lpData[5].szTip[0x2e] = L'\0';

  lpData[5].szTip[0x2f] = L'\0';

  lpData->hWnd = *(HWND *)(lpData[5].szTip + 0x30);

  lpData->cbSize = 0x3d0;

  UVar2 = FUN_140199930();

  lpData->uID = UVar2;

  lpData->uFlags = 0x87;

  lpData->uCallbackMessage = 0x401;

  lpData[4].szTip[0x34] = L'\x04';

  lpData[4].szTip[0x35] = L'\0';

  sVar4 = strlen(param_2);

  uVar5 = FUN_140197820("UTF-16LE",&DAT_14039c6f0,param_2,sVar4 + 1);

  FUN_14012fcd0(lpData->szTip,uVar5,0x80);

  FUN_1401841e0(uVar5);

  if (param_1 != 0) {

    pHVar6 = (HICON)FUN_1401a9650(param_1);

    lpData->hIcon = pHVar6;

    if (pHVar6 != (HICON)0x0) goto LAB_140198bde;

  }

  pHVar6 = (HICON)FUN_140199950();

  lpData->hIcon = pHVar6;

LAB_140198bde:

  *(HICON *)(lpData[5].szTip + 0x34) = pHVar6;

  Shell_NotifyIconW(0,lpData);

  Shell_NotifyIconW(4,lpData);

  SetWindowLongPtrW(*(HWND *)(lpData[5].szTip + 0x30),-0x15,(LONG_PTR)lpData);

  FUN_14021efb0(lpData);

  return lpData;

}




