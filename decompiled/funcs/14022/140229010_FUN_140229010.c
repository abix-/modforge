// Address: 0x140229010
// Ghidra name: FUN_140229010
// ============ 0x140229010 FUN_140229010 (size=209) ============


undefined8 FUN_140229010(longlong param_1,undefined8 param_2,tagPOINT param_3,undefined4 *param_4)



{

  BOOL BVar1;

  tagPOINT local_res8;

  LONG LStackX_1c;

  

  FUN_14012e280(7,". In DragOver at %ld, %ld",param_3,(ulonglong)param_3 >> 0x20);

  *param_4 = 1;

  local_res8 = param_3;

  BVar1 = ScreenToClient(*(HWND *)(param_1 + 0x18),&local_res8);

  LStackX_1c = param_3.y;

  if (BVar1 != 0) {

    FUN_14012e280(7,". In DragOver at %ld, %ld => window %u at %ld, %ld",

                  (ulonglong)param_3 & 0xffffffff,LStackX_1c,**(undefined4 **)(param_1 + 0x10),

                  local_res8.x,local_res8.y);

    FUN_14022e000(*(undefined8 *)(param_1 + 0x10));

    return 0;

  }

  FUN_14012e280(7,". In DragOver at %ld, %ld => nil, nil",(ulonglong)param_3 & 0xffffffff,LStackX_1c

               );

  return 0;

}




