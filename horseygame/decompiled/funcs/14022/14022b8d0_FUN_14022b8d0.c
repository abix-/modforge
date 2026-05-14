// Address: 0x14022b8d0
// Ghidra name: FUN_14022b8d0
// ============ 0x14022b8d0 FUN_14022b8d0 (size=423) ============


void FUN_14022b8d0(undefined8 param_1,longlong param_2)



{

  HWND hWnd;

  char cVar1;

  char cVar2;

  char cVar3;

  DWORD idAttachTo;

  DWORD idAttach;

  HWND hWnd_00;

  longlong lVar4;

  

  cVar1 = FUN_140142940("SDL_FORCE_RAISEWINDOW",0);

  cVar2 = FUN_140142940("SDL_WINDOW_ACTIVATE_WHEN_RAISED",1);

  lVar4 = *(longlong *)(param_2 + 0x188);

  idAttachTo = 0;

  idAttach = 0;

  hWnd = *(HWND *)(lVar4 + 8);

  if (cVar1 != '\0') {

    hWnd_00 = GetForegroundWindow();

    idAttachTo = GetCurrentThreadId();

    idAttach = GetWindowThreadProcessId(hWnd_00,(LPDWORD)0x0);

    ShowWindow(hWnd,9);

    AttachThreadInput(idAttach,idAttachTo,1);

    SetWindowPos(hWnd,(HWND)0xffffffffffffffff,0,0,0,0,3);

    cVar3 = FUN_140172540();

    if ((cVar3 == '\0') || ((*(uint *)(param_2 + 0x48) >> 0x10 & 1) == 0)) {

      SetWindowPos(hWnd,(HWND)0xfffffffffffffffe,0,0,0,0,3);

    }

  }

  if (cVar2 == '\0') {

    SetWindowPos(hWnd,(HWND)0x0,0,0,0,0,*(uint *)(lVar4 + 0xd0) | 0x213);

  }

  else {

    SetForegroundWindow(hWnd);

    if ((*(uint *)(param_2 + 0x48) & 0x80080000) == 0x80000) {

      lVar4 = FUN_140183290();

      FUN_14022bad0(param_2,*(longlong *)(param_2 + 0x1a8) == lVar4);

    }

  }

  if (cVar1 != '\0') {

    AttachThreadInput(idAttach,idAttachTo,0);

    SetFocus(hWnd);

    SetActiveWindow(hWnd);

  }

  return;

}




