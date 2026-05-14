// Address: 0x140167ad0
// Ghidra name: FUN_140167ad0
// ============ 0x140167ad0 FUN_140167ad0 (size=238) ============


undefined8 FUN_140167ad0(undefined8 *param_1,int *param_2,int *param_3)



{

  undefined8 uVar1;

  

  if (param_1 == (undefined8 *)0x0) {

    if (param_2 != (int *)0x0) {

      param_2[0] = 0;

      param_2[1] = 0;

      param_2[2] = 0;

    }

    if (param_3 != (int *)0x0) {

      param_3[0] = 0;

      param_3[1] = 0;

      param_3[2] = 0;

    }

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid","stream");

    return uVar1;

  }

  FUN_140179b40(*param_1);

  if (param_2 != (int *)0x0) {

    *(undefined8 *)param_2 = param_1[6];

    param_2[2] = *(int *)(param_1 + 7);

  }

  if (param_3 != (int *)0x0) {

    *(undefined8 *)param_3 = *(undefined8 *)((longlong)param_1 + 0x3c);

    param_3[2] = *(int *)((longlong)param_1 + 0x44);

  }

  FUN_140179b60(*param_1);

  if ((param_2 != (int *)0x0) && (*param_2 == 0)) {

    uVar1 = FUN_14012e850("Stream has no source format");

    return uVar1;

  }

  if ((param_3 != (int *)0x0) && (*param_3 == 0)) {

    uVar1 = FUN_14012e850("Stream has no destination format");

    return uVar1;

  }

  return 1;

}




