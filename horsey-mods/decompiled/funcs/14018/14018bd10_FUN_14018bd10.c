// Address: 0x14018bd10
// Ghidra name: FUN_14018bd10
// ============ 0x14018bd10 FUN_14018bd10 (size=116) ============


bool FUN_14018bd10(longlong param_1,ulonglong param_2)



{

  DWORD DVar1;

  BOOL BVar2;

  tagMSG local_38;

  

  if ((param_1 == 0x11) && ((param_2 >> 0x18 & 1) == 0)) {

    DVar1 = GetMessageTime();

    BVar2 = PeekMessageW(&local_38,(HWND)0x0,0,0,0);

    if ((BVar2 != 0) &&

       ((((local_38.message - 0x100 & 0xfffffffb) == 0 && (local_38.wParam == 0x12)) &&

        ((local_38.lParam & 0x1000000U) != 0)))) {

      return local_38.time == DVar1;

    }

  }

  return false;

}




