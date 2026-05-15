// Address: 0x14022bb30
// Ghidra name: FUN_14022bb30
// ============ 0x14022bb30 FUN_14022bb30 (size=135) ============


void FUN_14022bb30(undefined8 param_1,longlong param_2)



{

  longlong lVar1;

  HWND hWnd;

  uint uVar2;

  uint uVar3;

  

  lVar1 = *(longlong *)(param_2 + 0x188);

  hWnd = *(HWND *)(lVar1 + 8);

  uVar2 = GetWindowLongW(hWnd,-0x10);

  uVar3 = FUN_140229ea0(param_2);

  *(undefined1 *)(lVar1 + 100) = 1;

  SetWindowLongW(hWnd,-0x10,uVar3 | uVar2 & 0x7f30ffff);

  FUN_14022c420(param_2,*(uint *)(lVar1 + 0xd0) | 0x234,0);

  *(undefined1 *)(lVar1 + 100) = 0;

  return;

}




