// Address: 0x140199510
// Ghidra name: FUN_140199510
// ============ 0x140199510 FUN_140199510 (size=125) ============


void FUN_140199510(PNOTIFYICONDATAW param_1,longlong param_2)



{

  char cVar1;

  HICON pHVar2;

  

  if (param_1 == (PNOTIFYICONDATAW)0x0) {

    return;

  }

  if ((DAT_1403e3d60 != '\0') && (cVar1 = FUN_1401aa7c0(param_1,0xb), cVar1 == '\0')) {

    return;

  }

  if (*(HICON *)(param_1[5].szTip + 0x34) != (HICON)0x0) {

    DestroyIcon(*(HICON *)(param_1[5].szTip + 0x34));

  }

  if (param_2 != 0) {

    pHVar2 = (HICON)FUN_1401a9650(param_2);

    param_1->hIcon = pHVar2;

    if (pHVar2 != (HICON)0x0) goto LAB_14019956d;

  }

  pHVar2 = (HICON)FUN_140199950();

  param_1->hIcon = pHVar2;

LAB_14019956d:

  *(HICON *)(param_1[5].szTip + 0x34) = pHVar2;

  Shell_NotifyIconW(1,param_1);

  return;

}




