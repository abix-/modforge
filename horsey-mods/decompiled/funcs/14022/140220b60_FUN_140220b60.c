// Address: 0x140220b60
// Ghidra name: FUN_140220b60
// ============ 0x140220b60 FUN_140220b60 (size=82) ============


void FUN_140220b60(longlong param_1)



{

  DWORD DVar1;

  longlong lVar2;

  int local_res8 [2];

  

  DVar1 = GetClipboardSequenceNumber();

  if (DVar1 != *(DWORD *)(param_1 + 8)) {

    if (DVar1 != 0) {

      local_res8[0] = 0;

      lVar2 = FUN_140220a10(local_res8);

      if (lVar2 != 0) {

        FUN_140218400(0,lVar2,(longlong)local_res8[0]);

      }

    }

    *(DWORD *)(param_1 + 8) = DVar1;

  }

  return;

}




