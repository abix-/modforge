// Address: 0x14014d980
// Ghidra name: FUN_14014d980
// ============ 0x14014d980 FUN_14014d980 (size=133) ============


void FUN_14014d980(longlong param_1)



{

  ulonglong uVar1;

  uint uVar2;

  ulonglong uVar3;

  

  if (param_1 != 0) {

    FUN_140149d80();

    if (0 < *(int *)(param_1 + 0x48)) {

      uVar1 = 0;

      uVar3 = uVar1;

      do {

        FUN_1401841e0(*(undefined8 *)(*(longlong *)(param_1 + 0x50) + 8 + uVar1));

        uVar2 = (int)uVar3 + 1;

        uVar3 = (ulonglong)uVar2;

        uVar1 = uVar1 + 0x18;

      } while ((int)uVar2 < *(int *)(param_1 + 0x48));

      FUN_1401841e0(*(undefined8 *)(param_1 + 0x50));

    }

    FUN_1401841e0(*(undefined8 *)(param_1 + 0x20));

    FUN_1401841e0(*(undefined8 *)(param_1 + 0x30));

    FUN_1401841e0(*(undefined8 *)(param_1 + 0x40));

    FUN_1401841e0(param_1);

  }

  return;

}




