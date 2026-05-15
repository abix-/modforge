// Address: 0x14012c840
// Ghidra name: FUN_14012c840
// ============ 0x14012c840 FUN_14012c840 (size=55) ============


bool FUN_14012c840(undefined8 param_1,undefined1 *param_2)



{

  longlong lVar1;

  undefined1 local_res10 [24];

  

  local_res10[0] = 0;

  lVar1 = FUN_14012c730(param_1,local_res10,1);

  if (param_2 != (undefined1 *)0x0) {

    *param_2 = local_res10[0];

  }

  return lVar1 == 1;

}




