// Address: 0x1401adcc0
// Ghidra name: FUN_1401adcc0
// ============ 0x1401adcc0 FUN_1401adcc0 (size=73) ============


undefined8 * FUN_1401adcc0(undefined8 *param_1,int param_2)



{

  if (param_2 == 1) {

    *(undefined4 *)param_1 = 1;

    *(undefined4 *)((longlong)param_1 + 4) = 1;

    *(undefined4 *)(param_1 + 1) = 1;

    *(undefined4 *)((longlong)param_1 + 0xc) = 3;

    return param_1;

  }

  if (param_2 == 0xb) {

    *(undefined4 *)param_1 = 4;

    *(undefined4 *)((longlong)param_1 + 4) = 3;

    *(undefined4 *)(param_1 + 1) = 6;

    *(undefined4 *)((longlong)param_1 + 0xc) = 5;

    return param_1;

  }

  *param_1 = 0;

  param_1[1] = 0;

  return param_1;

}




