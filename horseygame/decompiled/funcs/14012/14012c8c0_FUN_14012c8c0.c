// Address: 0x14012c8c0
// Ghidra name: FUN_14012c8c0
// ============ 0x14012c8c0 FUN_14012c8c0 (size=58) ============


bool FUN_14012c8c0(undefined8 param_1,undefined2 *param_2)



{

  longlong lVar1;

  undefined2 local_res10 [12];

  

  local_res10[0] = 0;

  lVar1 = FUN_14012c730(param_1,local_res10,2);

  if (param_2 != (undefined2 *)0x0) {

    *param_2 = local_res10[0];

  }

  return lVar1 == 2;

}




