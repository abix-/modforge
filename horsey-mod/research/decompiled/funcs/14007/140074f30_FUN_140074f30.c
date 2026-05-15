// Address: 0x140074f30
// Ghidra name: FUN_140074f30
// ============ 0x140074f30 FUN_140074f30 (size=65) ============


undefined8 * FUN_140074f30(undefined8 *param_1,longlong param_2)



{

  for (; param_2 != 0; param_2 = param_2 + -1) {

    *param_1 = 0;

    param_1[1] = 0;

    *(undefined4 *)(param_1 + 2) = 0x3f800000;

    *(undefined4 *)((longlong)param_1 + 0x14) = 0x3f800000;

    *(undefined4 *)(param_1 + 3) = 0x3f800000;

    *(undefined4 *)((longlong)param_1 + 0x1c) = 0x3f800000;

    param_1 = param_1 + 4;

  }

  return param_1;

}




