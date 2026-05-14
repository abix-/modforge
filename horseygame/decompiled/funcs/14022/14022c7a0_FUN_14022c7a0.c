// Address: 0x14022c7a0
// Ghidra name: FUN_14022c7a0
// ============ 0x14022c7a0 FUN_14022c7a0 (size=79) ============


void FUN_14022c7a0(longlong param_1,LONG param_2,LONG param_3)



{

  longlong lVar1;

  tagPOINT local_res8 [4];

  

  lVar1 = *(longlong *)(param_1 + 0x188);

  local_res8[0].x = param_2;

  local_res8[0].y = param_3;

  ClientToScreen(*(HWND *)(lVar1 + 8),local_res8);

  SendMessageW(*(HWND *)(lVar1 + 8),0x313,0,

               (ulonglong)CONCAT22((undefined2)local_res8[0].y,(undefined2)local_res8[0].x));

  return;

}




