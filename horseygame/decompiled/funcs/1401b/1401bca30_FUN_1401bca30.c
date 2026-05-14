// Address: 0x1401bca30
// Ghidra name: FUN_1401bca30
// ============ 0x1401bca30 FUN_1401bca30 (size=146) ============


void FUN_1401bca30(longlong param_1,longlong param_2)



{

  uint uVar1;

  undefined8 uVar2;

  

  if (*(char *)(param_2 + 0x50) == '\0') {

    FUN_140179b40(*(undefined8 *)(param_1 + 0x8c8));

    if (*(uint *)(param_1 + 0x85c) <= *(int *)(param_1 + 0x858) + 1U) {

      uVar1 = *(uint *)(param_1 + 0x85c) * 2;

      *(uint *)(param_1 + 0x85c) = uVar1;

      uVar2 = FUN_140184230(*(undefined8 *)(param_1 + 0x850),(ulonglong)uVar1 << 3);

      *(undefined8 *)(param_1 + 0x850) = uVar2;

    }

    *(longlong *)(*(longlong *)(param_1 + 0x850) + (ulonglong)*(uint *)(param_1 + 0x858) * 8) =

         param_2;

    *(int *)(param_1 + 0x858) = *(int *)(param_1 + 0x858) + 1;

    *(undefined1 *)(param_2 + 0x50) = 1;

    FUN_140179b60(*(undefined8 *)(param_1 + 0x8c8));

  }

  return;

}




