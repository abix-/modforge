// Address: 0x1402f8700
// Ghidra name: FUN_1402f8700
// ============ 0x1402f8700 FUN_1402f8700 (size=97) ============


bool FUN_1402f8700(int *param_1)



{

  int iVar1;

  undefined8 local_res8;

  

  FUN_1402f6830(*param_1);

  FUN_1402f6960(param_1[1]);

  local_res8 = 0;

  iVar1 = FUN_1402f86e0(&local_res8);

  if ((iVar1 == 0) && (*param_1 == (int)local_res8)) {

    return param_1[1] != local_res8._4_4_;

  }

  return true;

}




