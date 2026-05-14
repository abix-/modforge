// Address: 0x14012c980
// Ghidra name: FUN_14012c980
// ============ 0x14012c980 FUN_14012c980 (size=63) ============


bool FUN_14012c980(undefined8 param_1,ulonglong *param_2)



{

  longlong lVar1;

  ulonglong local_res10 [3];

  

  local_res10[0] = 0;

  lVar1 = FUN_14012c730(param_1,local_res10,8);

  if (param_2 != (ulonglong *)0x0) {

    *param_2 = local_res10[0] >> 0x38 | (local_res10[0] & 0xff000000000000) >> 0x28 |

               (local_res10[0] & 0xff0000000000) >> 0x18 | (local_res10[0] & 0xff00000000) >> 8 |

               (local_res10[0] & 0xff000000) << 8 | (local_res10[0] & 0xff0000) << 0x18 |

               (local_res10[0] & 0xff00) << 0x28 | local_res10[0] << 0x38;

  }

  return lVar1 == 8;

}




