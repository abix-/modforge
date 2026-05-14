// Address: 0x14026cf10
// Ghidra name: FUN_14026cf10
// ============ 0x14026cf10 FUN_14026cf10 (size=55) ============


undefined1 FUN_14026cf10(longlong param_1,char param_2)



{

  undefined1 uVar1;

  char local_res10 [24];

  

  if (param_2 == *(char *)(param_1 + 0x25)) {

    return 1;

  }

  *(char *)(param_1 + 0x25) = param_2;

  local_res10[0] = param_2;

  uVar1 = FUN_14026d5b0(param_1,3,local_res10,1,0);

  return uVar1;

}




