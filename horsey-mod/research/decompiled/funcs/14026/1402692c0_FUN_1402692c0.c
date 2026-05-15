// Address: 0x1402692c0
// Ghidra name: FUN_1402692c0
// ============ 0x1402692c0 FUN_1402692c0 (size=102) ============


void FUN_1402692c0(longlong param_1,undefined1 param_2,longlong param_3,undefined1 param_4,

                  undefined1 *param_5)



{

  *(undefined8 *)(param_5 + 1) = 0;

  *(undefined8 *)(param_5 + 9) = 0;

  *(undefined8 *)(param_5 + 0x11) = 0;

  *(undefined8 *)(param_5 + 0x19) = 0;

  *(undefined8 *)(param_5 + 0x21) = 0;

  *(undefined8 *)(param_5 + 0x29) = 0;

  *param_5 = 1;

  param_5[1] = *(undefined1 *)(param_1 + 0x2c);

  *(undefined8 *)(param_5 + 2) = *(undefined8 *)(param_1 + 0x38);

  param_5[10] = param_2;

  if (param_3 != 0) {

    FUN_1402f8e20(param_5 + 0xb,param_3,param_4);

  }

  *(byte *)(param_1 + 0x2c) = *(char *)(param_1 + 0x2c) + 1U & 0xf;

  return;

}




