// Address: 0x140199220
// Ghidra name: FUN_140199220
// ============ 0x140199220 FUN_140199220 (size=244) ============


undefined4 FUN_140199220(LPCWSTR param_1)



{

  ATOM AVar1;

  int iVar2;

  undefined4 uVar3;

  longlong lVar4;

  WNDCLASSEXW local_58;

  

  iVar2 = FUN_140174be0();

  if (iVar2 == 0) {

    return 0;

  }

  lVar4 = FUN_140174d30(iVar2,"SDL.internal.tray.cleanup",0);

  if (lVar4 != 0) {

    return 1;

  }

  local_58.cbSize = 0x50;

  local_58.style = 0;

  local_58.hCursor = (HCURSOR)0x0;

  local_58.hIcon = (HICON)0x0;

  local_58.hIconSm = (HICON)0x0;

  local_58.lpszMenuName = (LPCWSTR)0x0;

  local_58.hbrBackground = (HBRUSH)0x0;

  local_58.hInstance = (HINSTANCE)0x0;

  local_58.cbClsExtra = 0;

  local_58.cbWndExtra = 0;

  local_58.lpfnWndProc = FUN_140199630;

  local_58.lpszClassName = param_1;

  AVar1 = RegisterClassExW(&local_58);

  if (AVar1 == 0) {

    uVar3 = FUN_14012e850("Couldn\'t register tray class");

  }

  else {

    FUN_1401753d0(iVar2,"SDL.internal.tray.cleanup",local_58.lpszClassName,FUN_1401991c0,0);

    uVar3 = 1;

  }

  return uVar3;

}




