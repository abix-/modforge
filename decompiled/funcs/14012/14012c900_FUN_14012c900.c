// Address: 0x14012c900
// Ghidra name: FUN_14012c900
// ============ 0x14012c900 FUN_14012c900 (size=59) ============


bool FUN_14012c900(undefined8 param_1,uint *param_2)



{

  longlong lVar1;

  uint local_res10 [6];

  

  local_res10[0] = 0;

  lVar1 = FUN_14012c730(param_1,local_res10,4);

  if (param_2 != (uint *)0x0) {

    *param_2 = local_res10[0] >> 0x18 | (local_res10[0] & 0xff0000) >> 8 |

               (local_res10[0] & 0xff00) << 8 | local_res10[0] << 0x18;

  }

  return lVar1 == 4;

}




