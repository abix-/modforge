// Address: 0x1401cb690
// Ghidra name: FUN_1401cb690
// ============ 0x1401cb690 FUN_1401cb690 (size=148) ============


void FUN_1401cb690(longlong param_1,longlong param_2)



{

  uint uVar1;

  uint uVar2;

  ulonglong uVar3;

  undefined8 uVar4;

  

  uVar3 = 0;

  uVar2 = *(uint *)(param_1 + 0x9a8);

  if (uVar2 != 0) {

    do {

      if (*(longlong *)(*(longlong *)(param_1 + 0x9a0) + uVar3 * 8) == param_2) {

        return;

      }

      uVar1 = (int)uVar3 + 1;

      uVar3 = (ulonglong)uVar1;

    } while (uVar1 < uVar2);

  }

  if (uVar2 == *(uint *)(param_1 + 0x9ac)) {

    uVar2 = *(uint *)(param_1 + 0x9ac) + 1;

    *(uint *)(param_1 + 0x9ac) = uVar2;

    uVar4 = FUN_140184230(*(undefined8 *)(param_1 + 0x9a0),(ulonglong)uVar2 << 3);

    *(undefined8 *)(param_1 + 0x9a0) = uVar4;

  }

  *(longlong *)(*(longlong *)(param_1 + 0x9a0) + (ulonglong)*(uint *)(param_1 + 0x9a8) * 8) =

       param_2;

  *(int *)(param_1 + 0x9a8) = *(int *)(param_1 + 0x9a8) + 1;

  FUN_140138fb0(param_2 + 0x28,1);

  return;

}




