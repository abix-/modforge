// Address: 0x14018c570
// Ghidra name: FUN_14018c570
// ============ 0x14018c570 FUN_14018c570 (size=68) ============


void FUN_14018c570(longlong param_1)



{

  if (*(HICON *)(param_1 + 0x20) != (HICON)0x0) {

    DestroyIcon(*(HICON *)(param_1 + 0x20));

  }

  if (*(HICON *)(param_1 + 0x48) != (HICON)0x0) {

    DestroyIcon(*(HICON *)(param_1 + 0x48));

  }

  FUN_1401841e0(DAT_1403fcb80);

  DAT_1403fcb80 = 0;

  return;

}




