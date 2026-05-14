// Address: 0x140221210
// Ghidra name: FUN_140221210
// ============ 0x140221210 FUN_140221210 (size=96) ============


undefined8 FUN_140221210(longlong param_1)



{

  BOOL BVar1;

  int iVar2;

  HWND hWndNewOwner;

  

  hWndNewOwner = (HWND)0x0;

  iVar2 = 0;

  if (*(longlong *)(param_1 + 0x348) != 0) {

    hWndNewOwner = *(HWND *)(*(longlong *)(*(longlong *)(param_1 + 0x348) + 0x188) + 8);

    iVar2 = 0;

  }

  do {

    BVar1 = OpenClipboard(hWndNewOwner);

    if (BVar1 != 0) {

      return 1;

    }

    FUN_1401492f0(10);

    iVar2 = iVar2 + 1;

  } while (iVar2 < 3);

  return 0;

}




