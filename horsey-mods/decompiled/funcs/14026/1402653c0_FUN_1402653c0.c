// Address: 0x1402653c0
// Ghidra name: FUN_1402653c0
// ============ 0x1402653c0 FUN_1402653c0 (size=86) ============


void FUN_1402653c0(undefined8 *param_1,undefined8 param_2)



{

  *(int *)(param_1 + 6) = *(int *)(param_1 + 6) + 1;

  if (8 < *(int *)(param_1 + 6)) {

    if (param_1[3] != 0) {

      FUN_1401841e0();

      param_1[3] = 0;

    }

    *(undefined1 *)((longlong)param_1 + 0x14) = 0;

  }

  FUN_1402650d0(*param_1,param_2,*(undefined4 *)(param_1 + 4),

                *(short *)((longlong)param_1 + 0x16) - *(short *)(param_1 + 4));

  return;

}




