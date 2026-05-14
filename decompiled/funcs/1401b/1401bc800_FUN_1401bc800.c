// Address: 0x1401bc800
// Ghidra name: FUN_1401bc800
// ============ 0x1401bc800 FUN_1401bc800 (size=153) ============


void FUN_1401bc800(longlong param_1,undefined8 *param_2)



{

  uint uVar1;

  undefined8 uVar2;

  

  if (*(char *)((longlong)param_2 + 0x35) == '\0') {

    FUN_140179b40(*(undefined8 *)(param_1 + 0x8c8));

    if (*(uint *)(param_1 + 0x86c) <= *(int *)(param_1 + 0x868) + 1U) {

      uVar1 = *(uint *)(param_1 + 0x86c) * 2;

      *(uint *)(param_1 + 0x86c) = uVar1;

      uVar2 = FUN_140184230(*(undefined8 *)(param_1 + 0x860),(ulonglong)uVar1 << 3);

      *(undefined8 *)(param_1 + 0x860) = uVar2;

    }

    *(undefined8 **)(*(longlong *)(param_1 + 0x860) + (ulonglong)*(uint *)(param_1 + 0x868) * 8) =

         param_2;

    *(int *)(param_1 + 0x868) = *(int *)(param_1 + 0x868) + 1;

    *(undefined1 *)((longlong)param_2 + 0x35) = 1;

    *param_2 = 0;

    FUN_140179b60(*(undefined8 *)(param_1 + 0x8c8));

  }

  return;

}




