// Address: 0x1401cb9a0
// Ghidra name: FUN_1401cb9a0
// ============ 0x1401cb9a0 FUN_1401cb9a0 (size=155) ============


void FUN_1401cb9a0(longlong param_1,undefined8 *param_2)



{

  uint uVar1;

  uint uVar2;

  ulonglong uVar3;

  undefined8 uVar4;

  

  uVar2 = *(uint *)(param_1 + 0x208);

  uVar3 = 0;

  if (uVar2 != 0) {

    do {

      if (*(undefined8 **)(*(longlong *)(param_1 + 0x200) + uVar3 * 8) == param_2) {

        return;

      }

      uVar1 = (int)uVar3 + 1;

      uVar3 = (ulonglong)uVar1;

    } while (uVar1 < uVar2);

  }

  if (uVar2 == *(uint *)(param_1 + 0x20c)) {

    uVar2 = *(uint *)(param_1 + 0x20c) + 1;

    *(uint *)(param_1 + 0x20c) = uVar2;

    uVar4 = FUN_140184230(*(undefined8 *)(param_1 + 0x200),(ulonglong)uVar2 << 3);

    *(undefined8 *)(param_1 + 0x200) = uVar4;

  }

  *(undefined8 **)(*(longlong *)(param_1 + 0x200) + (ulonglong)*(uint *)(param_1 + 0x208) * 8) =

       param_2;

  *(int *)(param_1 + 0x208) = *(int *)(param_1 + 0x208) + 1;

  FUN_1401cb5f0(param_1,*param_2);

  return;

}




