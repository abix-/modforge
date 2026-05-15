// Address: 0x1401a6d10
// Ghidra name: FUN_1401a6d10
// ============ 0x1401a6d10 FUN_1401a6d10 (size=316) ============


undefined8 FUN_1401a6d10(undefined8 *param_1,undefined8 param_2,undefined8 param_3,uint param_4)



{

  *param_1 = param_2;

  param_1[1] = param_3;

  *(uint *)(param_1 + 2) = param_4;

  *(uint *)((longlong)param_1 + 0x14) = ((param_4 & 0xfff) + 2) / 3 + 1;

  *(uint *)((longlong)param_1 + 0x1c) = param_4 >> 0xe & 1;

  *(uint *)(param_1 + 3) = (((int)param_4 >> 2 & 0x3ffU) + 2) / 3 + 1;

  if ((param_4 >> 0xf & 1) == 0) {

    FUN_1402f94c0((longlong)param_1 + 0x292aa,0,0x10000);

  }

  param_1[10] = 8;

  param_1[0xb] = 0;

  param_1[6] = (longlong)param_1 + 0x92ab;

  param_1[5] = 0;

  param_1[7] = (longlong)param_1 + 0x92aa;

  *(undefined8 *)((longlong)param_1 + 0x7c) = 0;

  param_1[0xc] = 0;

  *(undefined8 *)((longlong)param_1 + 0x74) = 0;

  *(undefined8 *)((longlong)param_1 + 0x6c) = 0;

  *(undefined4 *)((longlong)param_1 + 0x84) = 0;

  *(undefined4 *)(param_1 + 0xd) = 0;

  param_1[0x11] = 0;

  param_1[0x12] = 0;

  param_1[0x13] = 0;

  param_1[0x14] = 0;

  *(undefined4 *)(param_1 + 0x15) = 0;

  param_1[0x16] = 0;

  param_1[0x17] = 0;

  param_1[0x18] = 0;

  param_1[8] = (longlong)param_1 + 0x392aa;

  param_1[9] = (longlong)param_1 + 0x392aa;

  param_1[4] = 1;

  FUN_1402f94c0((longlong)param_1 + 0x81ca,0,0x240);

  *(undefined8 *)((longlong)param_1 + 0x840a) = 0;

  *(undefined8 *)((longlong)param_1 + 0x8412) = 0;

  *(undefined8 *)((longlong)param_1 + 0x841a) = 0;

  *(undefined8 *)((longlong)param_1 + 0x8422) = 0;

  *(undefined8 *)((longlong)param_1 + 0x842a) = 0;

  *(undefined8 *)((longlong)param_1 + 0x8432) = 0;

  *(undefined8 *)((longlong)param_1 + 0x843a) = 0;

  *(undefined8 *)((longlong)param_1 + 0x8442) = 0;

  return 0;

}




