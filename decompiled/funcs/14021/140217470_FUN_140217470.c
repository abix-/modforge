// Address: 0x140217470
// Ghidra name: FUN_140217470
// ============ 0x140217470 FUN_140217470 (size=162) ============


undefined1 FUN_140217470(undefined8 *param_1,longlong param_2,undefined8 param_3)



{

  undefined1 uVar1;

  

  if ((param_1 != (undefined8 *)0x0) && (param_2 != 0)) {

    FUN_140163d70(param_1[2]);

    *(int *)(param_1 + 3) = *(int *)(param_1 + 3) + 1;

    FUN_14017cea0(param_1[2]);

    FUN_140179b60(param_2);

    uVar1 = FUN_14017ceb0(*param_1,param_3);

    FUN_140163d70(param_1[2]);

    if (0 < *(int *)((longlong)param_1 + 0x1c)) {

      FUN_14017cea0(param_1[1]);

      *(int *)((longlong)param_1 + 0x1c) = *(int *)((longlong)param_1 + 0x1c) + -1;

    }

    *(int *)(param_1 + 3) = *(int *)(param_1 + 3) + -1;

    FUN_14017cea0(param_1[2]);

    FUN_140179b40(param_2);

    return uVar1;

  }

  return 1;

}




