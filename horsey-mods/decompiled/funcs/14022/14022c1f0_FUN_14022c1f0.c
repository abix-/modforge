// Address: 0x14022c1f0
// Ghidra name: FUN_14022c1f0
// ============ 0x14022c1f0 FUN_14022c1f0 (size=66) ============


undefined8 FUN_14022c1f0(undefined8 param_1,longlong param_2,char param_3)



{

  HWND hWnd;

  BOOL BVar1;

  undefined4 extraout_var;

  undefined4 extraout_var_00;

  longlong lVar2;

  

  lVar2 = *(longlong *)(param_2 + 0x1a8);

  hWnd = *(HWND *)(*(longlong *)(lVar2 + 0x188) + 8);

  if (param_3 != '\0') {

    BVar1 = EnableWindow(hWnd,0);

    return CONCAT71((int7)(CONCAT44(extraout_var,BVar1) >> 8),1);

  }

  if ((*(byte *)(param_2 + 0x48) & 8) == 0) {

    BVar1 = EnableWindow(hWnd,1);

    lVar2 = CONCAT44(extraout_var_00,BVar1);

  }

  return CONCAT71((int7)((ulonglong)lVar2 >> 8),1);

}




