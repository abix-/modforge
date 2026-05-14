// Address: 0x14008ff60
// Ghidra name: FUN_14008ff60
// ============ 0x14008ff60 FUN_14008ff60 (size=88) ============


void FUN_14008ff60(longlong param_1,undefined4 param_2)



{

  FUN_1400fb2b0(DAT_1403f4e00);

  if (*(longlong *)(param_1 + 0x278) != 0) {

    *(undefined4 *)(*(longlong *)(param_1 + 0x278) + 0x254) = param_2;

    FUN_1400cd560(param_1,*(undefined4 *)(*(longlong *)(param_1 + 0x278) + 8));

    return;

  }

  FUN_1400cdae0(param_1);

  return;

}




