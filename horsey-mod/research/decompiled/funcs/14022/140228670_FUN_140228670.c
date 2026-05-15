// Address: 0x140228670
// Ghidra name: FUN_140228670
// ============ 0x140228670 FUN_140228670 (size=162) ============


undefined8 FUN_140228670(longlong param_1,undefined4 param_2,undefined4 param_3)



{

  longlong lVar1;

  HWND hWnd;

  float fVar2;

  tagPOINT local_res8;

  

  lVar1 = *(longlong *)(param_1 + 0x188);

  hWnd = *(HWND *)(lVar1 + 8);

  if ((*(char *)(lVar1 + 0x65) == '\0') && (*(char *)(lVar1 + 0x66) == '\0')) {

    fVar2 = (float)thunk_FUN_1402e1d00(param_2);

    local_res8.x = (LONG)fVar2;

    fVar2 = (float)thunk_FUN_1402e1d00(param_3);

    local_res8.y = (LONG)fVar2;

    ClientToScreen(hWnd,&local_res8);

    FUN_140228460(local_res8.x,local_res8.y);

    FUN_1401628f0(0,param_1,0,0,param_2,param_3);

  }

  return 1;

}




