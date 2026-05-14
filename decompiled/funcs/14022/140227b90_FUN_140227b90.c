// Address: 0x140227b90
// Ghidra name: FUN_140227b90
// ============ 0x140227b90 FUN_140227b90 (size=79) ============


undefined8 FUN_140227b90(longlong param_1)



{

  longlong lVar1;

  

  if (param_1 != 0) {

    SetCapture(*(HWND *)(*(longlong *)(param_1 + 0x188) + 8));

    return 1;

  }

  lVar1 = FUN_140161230();

  if ((lVar1 != 0) && (*(char *)(*(longlong *)(lVar1 + 0x188) + 0xac) == '\0')) {

    FUN_140162ca0(0);

  }

  ReleaseCapture();

  return 1;

}




