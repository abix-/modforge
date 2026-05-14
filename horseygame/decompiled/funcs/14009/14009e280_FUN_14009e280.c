// Address: 0x14009e280
// Ghidra name: FUN_14009e280
// ============ 0x14009e280 FUN_14009e280 (size=57) ============


void FUN_14009e280(longlong param_1,float param_2)



{

  longlong *plVar1;

  undefined4 local_res10 [6];

  

  local_res10[0] = 0x20;

  plVar1 = (longlong *)FUN_14009f4a0(param_1 + 0x10,local_res10);

  *(float *)(*plVar1 + 0x24) = param_2 + *(float *)(*plVar1 + 0x24);

  return;

}




