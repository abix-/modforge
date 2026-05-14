// Address: 0x140217410
// Ghidra name: FUN_140217410
// ============ 0x140217410 FUN_140217410 (size=81) ============


void FUN_140217410(undefined8 *param_1)



{

  if (param_1 != (undefined8 *)0x0) {

    FUN_140163d70(param_1[2]);

    if (*(int *)((longlong)param_1 + 0x1c) < *(int *)(param_1 + 3)) {

      *(int *)((longlong)param_1 + 0x1c) = *(int *)((longlong)param_1 + 0x1c) + 1;

      FUN_14017cea0(*param_1);

      FUN_14017cea0(param_1[2]);

      FUN_140163d70(param_1[1]);

      return;

    }

    FUN_14017cea0(param_1[2]);

  }

  return;

}




