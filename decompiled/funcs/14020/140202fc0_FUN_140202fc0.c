// Address: 0x140202fc0
// Ghidra name: FUN_140202fc0
// ============ 0x140202fc0 FUN_140202fc0 (size=147) ============


bool FUN_140202fc0(longlong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)



{

  longlong lVar1;

  undefined4 local_38;

  undefined4 local_34;

  undefined4 local_30;

  undefined4 local_2c;

  undefined4 local_28;

  undefined4 local_24;

  undefined4 local_20;

  undefined8 local_1c;

  

  local_38 = 0;

  local_1c = 0;

  local_24 = 1;

  local_20 = 1;

  local_30 = 3;

  local_34 = param_4;

  local_2c = param_2;

  local_28 = param_3;

  FUN_140137fd0(*(undefined8 *)(param_1 + 8),*(undefined8 *)(param_1 + 0x58));

  lVar1 = FUN_1401355b0(*(undefined8 *)(param_1 + 8),&local_38);

  *(longlong *)(param_1 + 0x58) = lVar1;

  *(undefined4 *)(param_1 + 100) = param_2;

  *(undefined4 *)(param_1 + 0x68) = param_3;

  *(undefined4 *)(param_1 + 0x60) = param_4;

  return lVar1 != 0;

}




