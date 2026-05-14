// Address: 0x1400c8570
// Ghidra name: FUN_1400c8570
// ============ 0x1400c8570 FUN_1400c8570 (size=125) ============


undefined8 * FUN_1400c8570(undefined8 *param_1,longlong param_2)



{

  for (; param_2 != 0; param_2 = param_2 + -1) {

    *param_1 = 0;

    param_1[1] = 0;

    param_1[2] = 0;

    param_1[3] = 0xf;

    *(undefined1 *)param_1 = 0;

    param_1[4] = 0;

    param_1[5] = 0;

    param_1[6] = 0;

    param_1[7] = 0xf;

    *(undefined1 *)(param_1 + 4) = 0;

    param_1[0xe] = 0;

    param_1[0xf] = 0;

    param_1[0x10] = 0;

    param_1[9] = 0xffffffffffffffff;

    *(undefined4 *)((longlong)param_1 + 100) = 0xffffffff;

    *(undefined4 *)(param_1 + 0xd) = 0;

    *(undefined1 *)((longlong)param_1 + 0x6c) = 0;

    *(undefined1 *)(param_1 + 8) = 0;

    *(undefined4 *)((longlong)param_1 + 0x44) = 0;

    param_1[10] = 0;

    *(undefined1 *)(param_1 + 0xb) = 0;

    *(undefined8 *)((longlong)param_1 + 0x5c) = 0;

    param_1 = param_1 + 0x11;

  }

  return param_1;

}




