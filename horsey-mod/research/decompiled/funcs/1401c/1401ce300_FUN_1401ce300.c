// Address: 0x1401ce300
// Ghidra name: FUN_1401ce300
// ============ 0x1401ce300 FUN_1401ce300 (size=77) ============


void FUN_1401ce300(longlong *param_1)



{

  if (*param_1 != 0) {

    FUN_140179b30();

    *param_1 = 0;

  }

  if (param_1[4] != 0) {

    FUN_1401841e0();

    param_1[4] = 0;

    *(undefined4 *)(param_1 + 5) = 0;

  }

  param_1[1] = 0;

  param_1[2] = 0;

  param_1[3] = 0;

  return;

}




