// Address: 0x14022c340
// Ghidra name: FUN_14022c340
// ============ 0x14022c340 FUN_14022c340 (size=107) ============


undefined8 FUN_14022c340(undefined8 param_1,longlong param_2,longlong param_3)



{

  longlong lVar1;

  HWND hWndChild;

  uint uVar2;

  HWND hWndNewParent;

  

  lVar1 = *(longlong *)(param_2 + 0x188);

  if (param_3 == 0) {

    hWndNewParent = (HWND)0x0;

  }

  else {

    hWndNewParent = *(HWND *)(*(longlong *)(param_3 + 0x188) + 8);

  }

  uVar2 = GetWindowLongW(*(HWND *)(lVar1 + 8),-0x10);

  hWndChild = *(HWND *)(lVar1 + 8);

  if ((uVar2 >> 0x1e & 1) == 0) {

    SetWindowLongPtrW(hWndChild,-8,(LONG_PTR)hWndNewParent);

    return 1;

  }

  SetParent(hWndChild,hWndNewParent);

  return 1;

}




