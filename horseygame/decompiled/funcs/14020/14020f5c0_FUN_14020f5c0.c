// Address: 0x14020f5c0
// Ghidra name: FUN_14020f5c0
// ============ 0x14020f5c0 FUN_14020f5c0 (size=131) ============


bool FUN_14020f5c0(longlong param_1,undefined8 param_2)



{

  char cVar1;

  BOOL BVar2;

  tagMSG local_38;

  

  BVar2 = 1;

  if (*(longlong *)(param_1 + 0x58) == 0) {

    return false;

  }

  FUN_140179b60(param_2);

  while( true ) {

    cVar1 = FUN_14020f6a0();

    if (cVar1 != '\0') break;

    BVar2 = GetMessageW(&local_38,(HWND)0x0,0,0);

    if (BVar2 < 1) break;

    TranslateMessage(&local_38);

    DispatchMessageW(&local_38);

  }

  FUN_140179b40(param_2);

  return BVar2 != -1;

}




