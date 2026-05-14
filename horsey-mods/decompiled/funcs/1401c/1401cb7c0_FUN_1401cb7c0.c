// Address: 0x1401cb7c0
// Ghidra name: FUN_1401cb7c0
// ============ 0x1401cb7c0 FUN_1401cb7c0 (size=148) ============


void FUN_1401cb7c0(longlong param_1,longlong param_2)



{

  uint uVar1;

  uint uVar2;

  ulonglong uVar3;

  undefined8 uVar4;

  

  uVar3 = 0;

  uVar2 = *(uint *)(param_1 + 0x998);

  if (uVar2 != 0) {

    do {

      if (*(longlong *)(*(longlong *)(param_1 + 0x990) + uVar3 * 8) == param_2) {

        return;

      }

      uVar1 = (int)uVar3 + 1;

      uVar3 = (ulonglong)uVar1;

    } while (uVar1 < uVar2);

  }

  if (uVar2 == *(uint *)(param_1 + 0x99c)) {

    uVar2 = *(uint *)(param_1 + 0x99c) + 1;

    *(uint *)(param_1 + 0x99c) = uVar2;

    uVar4 = FUN_140184230(*(undefined8 *)(param_1 + 0x990),(ulonglong)uVar2 << 3);

    *(undefined8 *)(param_1 + 0x990) = uVar4;

  }

  *(longlong *)(*(longlong *)(param_1 + 0x990) + (ulonglong)*(uint *)(param_1 + 0x998) * 8) =

       param_2;

  *(int *)(param_1 + 0x998) = *(int *)(param_1 + 0x998) + 1;

  FUN_140138fb0(param_2 + 0x74,1);

  return;

}




