// Address: 0x140192130
// Ghidra name: FUN_140192130
// ============ 0x140192130 FUN_140192130 (size=191) ============


void FUN_140192130(longlong *param_1,undefined8 *param_2)



{

  undefined8 uVar1;

  

  if (*param_1 == 0) {

    uVar1 = 0;

  }

  else {

    uVar1 = FUN_14012f0d0();

  }

  *param_2 = uVar1;

  *(short *)(param_2 + 1) = (short)param_1[1];

  *(undefined2 *)((longlong)param_2 + 10) = *(undefined2 *)((longlong)param_1 + 10);

  if (param_1[2] == 0) {

    uVar1 = 0;

  }

  else {

    uVar1 = FUN_14012fc00();

  }

  param_2[2] = uVar1;

  *(short *)(param_2 + 3) = (short)param_1[3];

  if (param_1[4] == 0) {

    uVar1 = 0;

  }

  else {

    uVar1 = FUN_14012fc00();

  }

  param_2[4] = uVar1;

  if (param_1[5] == 0) {

    uVar1 = 0;

  }

  else {

    uVar1 = FUN_14012fc00();

  }

  param_2[5] = uVar1;

  *(short *)(param_2 + 6) = (short)param_1[6];

  *(undefined2 *)((longlong)param_2 + 0x32) = *(undefined2 *)((longlong)param_1 + 0x32);

  *(undefined4 *)((longlong)param_2 + 0x34) = *(undefined4 *)((longlong)param_1 + 0x34);

  *(undefined4 *)(param_2 + 7) = *(undefined4 *)((longlong)param_1 + 0x44);

  *(int *)((longlong)param_2 + 0x3c) = (int)param_1[9];

  *(undefined4 *)(param_2 + 8) = *(undefined4 *)((longlong)param_1 + 0x4c);

  *(int *)((longlong)param_2 + 0x44) = (int)param_1[8];

  param_2[9] = 0;

  return;

}




