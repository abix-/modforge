// Address: 0x14009f5a0
// Ghidra name: FUN_14009f5a0
// ============ 0x14009f5a0 FUN_14009f5a0 (size=46) ============


longlong FUN_14009f5a0(longlong param_1,int param_2)



{

  longlong lVar1;

  

  lVar1 = param_1 + 0x1ec;

  if (param_2 == 2) {

    return param_1 + 0x240;

  }

  if (param_2 == 4) {

    return param_1 + 0x2e8;

  }

  if (param_2 == 3) {

    lVar1 = param_1 + 0x294;

  }

  return lVar1;

}




