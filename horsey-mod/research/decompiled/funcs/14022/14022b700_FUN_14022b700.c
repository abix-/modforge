// Address: 0x14022b700
// Ghidra name: FUN_14022b700
// ============ 0x14022b700 FUN_14022b700 (size=109) ============


void FUN_14022b700(undefined8 param_1,longlong param_2)



{

  HWND hWnd;

  undefined1 uVar1;

  undefined8 local_res10 [3];

  

  hWnd = *(HWND *)(*(longlong *)(param_2 + 0x188) + 8);

  if ((*(uint *)(param_2 + 0x48) >> 0xc & 1) != 0) {

    FUN_14022c1f0(param_1,param_2,0);

  }

  ShowWindow(hWnd,0);

  if ((*(uint *)(param_2 + 0x48) & 0x80080000) == 0x80000) {

    uVar1 = FUN_140172630(param_2,local_res10);

    FUN_14022bad0(local_res10[0],uVar1);

  }

  return;

}




