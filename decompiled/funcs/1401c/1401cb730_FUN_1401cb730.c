// Address: 0x1401cb730
// Ghidra name: FUN_1401cb730
// ============ 0x1401cb730 FUN_1401cb730 (size=144) ============


void FUN_1401cb730(longlong param_1,longlong param_2)



{

  uint uVar1;

  uint uVar2;

  ulonglong uVar3;

  undefined8 uVar4;

  

  uVar2 = *(uint *)(param_1 + 0x1f8);

  uVar3 = 0;

  if (uVar2 != 0) {

    do {

      if (*(longlong *)(*(longlong *)(param_1 + 0x1f0) + uVar3 * 8) == param_2) {

        return;

      }

      uVar1 = (int)uVar3 + 1;

      uVar3 = (ulonglong)uVar1;

    } while (uVar1 < uVar2);

  }

  if (uVar2 == *(uint *)(param_1 + 0x1fc)) {

    uVar2 = *(uint *)(param_1 + 0x1fc) + 1;

    *(uint *)(param_1 + 0x1fc) = uVar2;

    uVar4 = FUN_140184230(*(undefined8 *)(param_1 + 0x1f0),(ulonglong)uVar2 << 3);

    *(undefined8 *)(param_1 + 0x1f0) = uVar4;

  }

  *(longlong *)(*(longlong *)(param_1 + 0x1f0) + (ulonglong)*(uint *)(param_1 + 0x1f8) * 8) =

       param_2;

  *(int *)(param_1 + 0x1f8) = *(int *)(param_1 + 0x1f8) + 1;

  return;

}




