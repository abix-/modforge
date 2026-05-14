// Address: 0x14022a7f0
// Ghidra name: FUN_14022a7f0
// ============ 0x14022a7f0 FUN_14022a7f0 (size=199) ============


void FUN_14022a7f0(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,

                  undefined8 param_5,undefined4 param_6)



{

  HWND hWnd;

  uint uVar1;

  LONG LVar2;

  HMENU pHVar3;

  bool bVar4;

  

  hWnd = *(HWND *)(*(longlong *)(param_1 + 0x188) + 8);

  uVar1 = GetWindowLongW(hWnd,-0x10);

  LVar2 = GetWindowLongW(hWnd,-0x14);

  if ((uVar1 >> 0x1e & 1) == 0) {

    pHVar3 = GetMenu(hWnd);

    bVar4 = pHVar3 != (HMENU)0x0;

  }

  else {

    bVar4 = false;

  }

  FUN_14022a9d0(param_1,uVar1,LVar2,bVar4,param_2,param_3,param_4,param_5,param_6);

  return;

}




