// Address: 0x14022c840
// Ghidra name: FUN_14022c840
// ============ 0x14022c840 FUN_14022c840 (size=42) ============


void FUN_14022c840(longlong param_1)



{

  longlong lVar1;

  HHOOK hhk;

  

  lVar1 = *(longlong *)(param_1 + 0x188);

  hhk = *(HHOOK *)(lVar1 + 0x48);

  if (hhk != (HHOOK)0x0) {

    UnhookWindowsHookEx(hhk);

    *(undefined8 *)(lVar1 + 0x48) = 0;

  }

  return;

}




