// Address: 0x14022c640
// Ghidra name: FUN_14022c640
// ============ 0x14022c640 FUN_14022c640 (size=345) ============


void FUN_14022c640(undefined8 param_1,longlong param_2)



{

  longlong lVar1;

  HWND hWnd;

  char cVar2;

  uint uVar3;

  uint uVar4;

  ulonglong uVar5;

  char cVar6;

  

  lVar1 = *(longlong *)(param_2 + 0x188);

  hWnd = *(HWND *)(lVar1 + 8);

  cVar2 = FUN_140142940("SDL_WINDOW_ACTIVATE_WHEN_SHOWN",1);

  uVar5 = *(ulonglong *)(param_2 + 0x48);

  if ((uVar5 & 0xc0000) != 0) {

    FUN_14022c3b0(param_1,param_2);

    uVar5 = *(ulonglong *)(param_2 + 0x48);

  }

  if (((*(byte *)(param_2 + 0x50) & 1) != 0) && ((uVar5 & 0x10) == 0)) {

    *(ulonglong *)(param_2 + 0x48) = uVar5 | 0x10;

    uVar3 = GetWindowLongW(hWnd,-0x10);

    uVar4 = FUN_140229ea0(param_2);

    SetWindowLongW(hWnd,-0x10,uVar4 | uVar3 & 0x7f30ffff);

    *(ulonglong *)(param_2 + 0x48) = *(ulonglong *)(param_2 + 0x48) & 0xffffffffffffffef;

  }

  uVar3 = GetWindowLongW(hWnd,-0x14);

  *(undefined1 *)(lVar1 + 0x6d) = 1;

  cVar6 = '\0';

  if ((uVar3 >> 0x1b & 1) == 0) {

    cVar6 = cVar2;

  }

  if (cVar6 == '\0') {

    SetWindowPos(hWnd,(HWND)0x0,0,0,0,0,*(uint *)(*(longlong *)(param_2 + 0x188) + 0xd0) | 599);

  }

  else {

    ShowWindow(hWnd,5);

  }

  *(undefined1 *)(lVar1 + 0x6d) = 0;

  if (((*(uint *)(param_2 + 0x48) & 0x80080000) == 0x80000) && (cVar6 != '\0')) {

    FUN_14022bad0(param_2,1);

  }

  if ((*(uint *)(param_2 + 0x48) >> 0xc & 1) != 0) {

    FUN_14022c1f0(param_1,param_2,1);

  }

  return;

}




