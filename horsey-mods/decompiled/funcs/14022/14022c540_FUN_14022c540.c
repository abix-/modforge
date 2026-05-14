// Address: 0x14022c540
// Ghidra name: FUN_14022c540
// ============ 0x14022c540 FUN_14022c540 (size=94) ============


void FUN_14022c540(undefined8 param_1,longlong param_2)



{

  HWND hWnd;

  uint uVar1;

  uint uVar2;

  

  hWnd = *(HWND *)(*(longlong *)(param_2 + 0x188) + 8);

  uVar1 = GetWindowLongW(hWnd,-0x10);

  uVar2 = FUN_140229ea0(param_2);

                    /* WARNING: Could not recover jumptable at 0x00014022c597. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  SetWindowLongW(hWnd,-0x10,uVar2 | uVar1 & 0x7f30ffff);

  return;

}




