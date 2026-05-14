// Address: 0x1402774b0
// Ghidra name: FUN_1402774b0
// ============ 0x1402774b0 FUN_1402774b0 (size=438) ============


undefined8 FUN_1402774b0(short *param_1,undefined8 param_2,longlong param_3)



{

  char cVar1;

  short sVar2;

  undefined8 uVar3;

  

  if (*param_1 != 1) {

    if (((byte)*param_1 & 0xf) != 4) {

      return 0;

    }

    uVar3 = FUN_140277240();

    return uVar3;

  }

  if ((char)param_1[1] == '\x01') {

    if (*(int *)(param_3 + 4) == *(int *)(param_1 + 2)) {

      return 1;

    }

    FUN_140276700(param_3,param_1 + 2);

    *(short *)(param_3 + 0x28) = param_1[0xe];

    *(short *)(param_3 + 0x2a) = param_1[0xf];

    *(short *)(param_3 + 0x2c) = param_1[0x10];

    *(float *)(param_3 + 0x34) = (float)(int)param_1[0x14];

    *(float *)(param_3 + 0x38) = (float)(int)param_1[0x15];

    *(float *)(param_3 + 0x3c) = (float)(int)param_1[0x16];

    *(float *)(param_3 + 0x40) = (float)(int)param_1[0x17];

    *(short *)(param_3 + 0x2e) = param_1[0x11];

    *(short *)(param_3 + 0x30) = param_1[0x12];

    sVar2 = param_1[0x13];

  }

  else {

    if ((char)param_1[1] != '\a') {

      return 0;

    }

    if (*(int *)(param_3 + 4) == *(int *)(param_1 + 2)) {

      return 1;

    }

    FUN_140276700(param_3,param_1 + 2);

    cVar1 = (char)param_1[0xc];

    if (cVar1 == '\x01') {

      *(float *)(param_3 + 0x34) = (float)(int)*(short *)((longlong)param_1 + 0x19);

      *(float *)(param_3 + 0x38) = (float)(int)*(short *)((longlong)param_1 + 0x1b);

      *(float *)(param_3 + 0x3c) = (float)(int)*(short *)((longlong)param_1 + 0x1d);

      *(float *)(param_3 + 0x40) = (float)(int)*(short *)((longlong)param_1 + 0x1f);

      return 1;

    }

    if (cVar1 == '\x02') {

      *(undefined2 *)(param_3 + 0x28) = *(undefined2 *)((longlong)param_1 + 0x19);

      *(undefined2 *)(param_3 + 0x2a) = *(undefined2 *)((longlong)param_1 + 0x1b);

      *(undefined2 *)(param_3 + 0x2c) = *(undefined2 *)((longlong)param_1 + 0x1d);

      return 1;

    }

    if (cVar1 != '\x03') {

      return 1;

    }

    *(undefined2 *)(param_3 + 0x2e) = *(undefined2 *)((longlong)param_1 + 0x19);

    *(undefined2 *)(param_3 + 0x30) = *(undefined2 *)((longlong)param_1 + 0x1b);

    sVar2 = *(short *)((longlong)param_1 + 0x1d);

  }

  *(short *)(param_3 + 0x32) = sVar2;

  return 1;

}




