// Address: 0x1402785a0
// Ghidra name: FUN_1402785a0
// ============ 0x1402785a0 FUN_1402785a0 (size=52) ============


void FUN_1402785a0(longlong param_1,undefined1 param_2)



{

  undefined1 local_res10 [24];

  

  local_res10[0] = param_2;

  FUN_14027a030(param_1,0xa600fe,local_res10,1,1);

  *(undefined1 *)(param_1 + 0x2a) = local_res10[0];

  return;

}




