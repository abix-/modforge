// Address: 0x140228f40
// Ghidra name: FUN_140228f40
// ============ 0x140228f40 FUN_140228f40 (size=196) ============


undefined8

FUN_140228f40(longlong param_1,undefined8 param_2,undefined8 param_3,tagPOINT param_4,

             undefined4 *param_5)



{

  BOOL BVar1;

  tagPOINT local_res8;

  LONG LStackX_24;

  

  FUN_14012e280(7,". In DragEnter at %ld, %ld",(ulonglong)param_4 & 0xffffffff,

                (ulonglong)param_4 >> 0x20);

  *param_5 = 1;

  local_res8 = param_4;

  BVar1 = ScreenToClient(*(HWND *)(param_1 + 0x18),&local_res8);

  LStackX_24 = param_4.y;

  if (BVar1 != 0) {

    FUN_14012e280(7,". In DragEnter at %ld, %ld => window %u at %ld, %ld",

                  (ulonglong)param_4 & 0xffffffff,LStackX_24,**(undefined4 **)(param_1 + 0x10),

                  local_res8.x,local_res8.y);

    FUN_14022e000(*(undefined8 *)(param_1 + 0x10));

    return 0;

  }

  FUN_14012e280(7,". In DragEnter at %ld, %ld => nil, nil",(ulonglong)param_4 & 0xffffffff,

                LStackX_24);

  return 0;

}




