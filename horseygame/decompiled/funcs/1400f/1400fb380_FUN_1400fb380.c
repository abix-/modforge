// Address: 0x1400fb380
// Ghidra name: FUN_1400fb380
// ============ 0x1400fb380 FUN_1400fb380 (size=73) ============


void FUN_1400fb380(longlong param_1)



{

  *(int *)(param_1 + 0x250) = *(int *)(param_1 + 0x250) + 1;

  FUN_1400ca260();

  FUN_1400ceb60(param_1);

  if (*(int *)(param_1 + 0x250) == 0x1e) {

    FUN_1400d23d0(param_1);

  }

  if (*(int *)(param_1 + 0xe0) == 0) {

    FUN_1400fa910(param_1);

    return;

  }

  return;

}




