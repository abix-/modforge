// Address: 0x14012cdb0
// Ghidra name: FUN_14012cdb0
// ============ 0x14012cdb0 FUN_14012cdb0 (size=40) ============


bool FUN_14012cdb0(undefined8 param_1,ulonglong param_2)



{

  longlong lVar1;

  ulonglong local_res18 [2];

  

  local_res18[0] =

       param_2 >> 0x38 | (param_2 & 0xff000000000000) >> 0x28 | (param_2 & 0xff0000000000) >> 0x18 |

       (param_2 & 0xff00000000) >> 8 | (param_2 & 0xff000000) << 8 | (param_2 & 0xff0000) << 0x18 |

       (param_2 & 0xff00) << 0x28 | param_2 << 0x38;

  lVar1 = FUN_14012cbb0(param_1,local_res18,8);

  return lVar1 == 8;

}




