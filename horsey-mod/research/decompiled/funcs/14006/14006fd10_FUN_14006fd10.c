// Address: 0x14006fd10
// Ghidra name: FUN_14006fd10
// ============ 0x14006fd10 FUN_14006fd10 (size=65) ============


longlong FUN_14006fd10(longlong param_1,longlong param_2)



{

  if (param_2 != 0) {

    FUN_1402f94c0(param_1,0,param_2 * 0x24);

    return param_2 * 0x24 + param_1;

  }

  return param_1;

}




