// Address: 0x14015fdf0
// Ghidra name: FUN_14015fdf0
// ============ 0x14015fdf0 FUN_14015fdf0 (size=77) ============


bool FUN_14015fdf0(undefined8 param_1,undefined4 param_2)



{

  longlong lVar1;

  undefined8 local_res18 [2];

  

  local_res18[0] = 0;

  lVar1 = FUN_14015cb20(param_1,local_res18);

  if (lVar1 != 0) {

    FUN_140139010(lVar1 + 0x10,param_2);

  }

  FUN_14015d3e0(local_res18[0]);

  return lVar1 != 0;

}




