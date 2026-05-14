// Address: 0x1400a6c40
// Ghidra name: FUN_1400a6c40
// ============ 0x1400a6c40 FUN_1400a6c40 (size=109) ============


undefined8 * FUN_1400a6c40(undefined8 *param_1,longlong param_2)



{

  for (; param_2 != 0; param_2 = param_2 + -1) {

    *param_1 = 0;

    FUN_1402f94c0(param_1 + 5,0,0xff0);

    param_1[1] = 0;

    param_1[2] = 0;

    param_1[3] = 0;

    param_1[4] = 0xf;

    *(undefined1 *)(param_1 + 1) = 0;

    param_1 = param_1 + 0x203;

  }

  return param_1;

}




