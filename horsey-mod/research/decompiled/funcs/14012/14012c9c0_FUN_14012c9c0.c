// Address: 0x14012c9c0
// Ghidra name: FUN_14012c9c0
// ============ 0x14012c9c0 FUN_14012c9c0 (size=60) ============


bool FUN_14012c9c0(undefined8 param_1,undefined8 *param_2)



{

  longlong lVar1;

  undefined8 local_res10 [3];

  

  local_res10[0] = 0;

  lVar1 = FUN_14012c730(param_1,local_res10,8);

  if (param_2 != (undefined8 *)0x0) {

    *param_2 = local_res10[0];

  }

  return lVar1 == 8;

}




