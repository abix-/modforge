// Address: 0x14012c880
// Ghidra name: FUN_14012c880
// ============ 0x14012c880 FUN_14012c880 (size=62) ============


bool FUN_14012c880(undefined8 param_1,ushort *param_2)



{

  longlong lVar1;

  ushort local_res10 [12];

  

  local_res10[0] = 0;

  lVar1 = FUN_14012c730(param_1,local_res10,2);

  if (param_2 != (ushort *)0x0) {

    *param_2 = local_res10[0] >> 8 | local_res10[0] << 8;

  }

  return lVar1 == 2;

}




