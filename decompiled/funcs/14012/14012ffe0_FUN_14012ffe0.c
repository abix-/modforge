// Address: 0x14012ffe0
// Ghidra name: FUN_14012ffe0
// ============ 0x14012ffe0 FUN_14012ffe0 (size=63) ============


undefined4 FUN_14012ffe0(longlong param_1,longlong *param_2,undefined8 param_3)



{

  longlong lVar1;

  undefined4 local_res10 [6];

  

  local_res10[0] = 0;

  lVar1 = FUN_14012ea30(param_1,0,param_3,local_res10);

  if (param_2 != (longlong *)0x0) {

    *param_2 = param_1 + lVar1 * 2;

  }

  return local_res10[0];

}




