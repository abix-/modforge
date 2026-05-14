// Address: 0x1401bc8a0
// Ghidra name: FUN_1401bc8a0
// ============ 0x1401bc8a0 FUN_1401bc8a0 (size=142) ============


void FUN_1401bc8a0(longlong param_1,longlong param_2)



{

  uint uVar1;

  ulonglong uVar2;

  

  FUN_140179b40(*(undefined8 *)(param_1 + 0x8c8));

  uVar2 = 0;

  if (*(int *)(param_2 + 0x14) != 0) {

    do {

      FUN_1401bc800(param_1,*(undefined8 *)(*(longlong *)(param_2 + 8) + uVar2 * 8));

      uVar1 = (int)uVar2 + 1;

      uVar2 = (ulonglong)uVar1;

    } while (uVar1 < *(uint *)(param_2 + 0x14));

  }

  if (*(longlong *)(param_2 + 0x20) != 0) {

    FUN_1401841e0();

    *(undefined8 *)(param_2 + 0x20) = 0;

  }

  FUN_1401841e0(*(undefined8 *)(param_2 + 8));

  FUN_1401841e0(param_2);

  FUN_140179b60(*(undefined8 *)(param_1 + 0x8c8));

  return;

}




