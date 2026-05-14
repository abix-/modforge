// Address: 0x1401bf820
// Ghidra name: FUN_1401bf820
// ============ 0x1401bf820 FUN_1401bf820 (size=137) ============


void FUN_1401bf820(longlong param_1,longlong param_2)



{

  uint uVar1;

  ulonglong uVar2;

  

  FUN_140179b40(*(undefined8 *)(param_1 + 0x8c8));

  uVar2 = 0;

  if (*(int *)(param_2 + 0x34) != 0) {

    do {

      FUN_1401bca30(param_1,*(undefined8 *)(*(longlong *)(param_2 + 0x38) + uVar2 * 8));

      uVar1 = (int)uVar2 + 1;

      uVar2 = (ulonglong)uVar1;

    } while (uVar1 < *(uint *)(param_2 + 0x34));

  }

  FUN_1401747e0(*(undefined4 *)(param_2 + 0x20));

  FUN_1401841e0(*(undefined8 *)(param_2 + 0x40));

  FUN_1401841e0(*(undefined8 *)(param_2 + 0x38));

  FUN_1401841e0(param_2);

  FUN_140179b60(*(undefined8 *)(param_1 + 0x8c8));

  return;

}




