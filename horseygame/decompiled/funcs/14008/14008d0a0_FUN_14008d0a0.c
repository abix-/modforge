// Address: 0x14008d0a0
// Ghidra name: FUN_14008d0a0
// ============ 0x14008d0a0 FUN_14008d0a0 (size=158) ============


void FUN_14008d0a0(undefined8 *param_1)



{

  uint uVar1;

  BOOL BVar2;

  HGLOBAL hMem;

  LPVOID pvVar3;

  undefined8 *puVar4;

  

  uVar1 = *(uint *)(param_1 + 2);

  hMem = GlobalAlloc(0x2002,(ulonglong)(uVar1 + 1));

  pvVar3 = GlobalLock(hMem);

  puVar4 = param_1;

  if (0xf < (ulonglong)param_1[3]) {

    puVar4 = (undefined8 *)*param_1;

  }

  FUN_1402f8e20(pvVar3,puVar4,(ulonglong)uVar1);

  *(undefined1 *)((ulonglong)uVar1 + (longlong)pvVar3) = 0;

  GlobalUnlock(hMem);

  BVar2 = OpenClipboard((HWND)0x0);

  if (BVar2 != 0) {

    EmptyClipboard();

    SetClipboardData(1,hMem);

    CloseClipboard();

  }

  FUN_140027900(param_1);

  return;

}




