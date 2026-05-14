// Address: 0x1401c9d80
// Ghidra name: FUN_1401c9d80
// ============ 0x1401c9d80 FUN_1401c9d80 (size=206) ============


void FUN_1401c9d80(longlong param_1)



{

  uint uVar1;

  ulonglong uVar2;

  ulonglong uVar3;

  longlong lVar4;

  

  if (param_1 != 0) {

    uVar3 = 0;

    if (*(int *)(param_1 + 0x18) != 0) {

      do {

        lVar4 = uVar3 * 0x60 + *(longlong *)(param_1 + 0x10);

        if (*(longlong *)(lVar4 + 0x18) != 0) {

          uVar2 = 0;

          if (*(int *)(lVar4 + 0x10) != 0) {

            do {

              FUN_1401cade0(uVar2 * 0x20 + *(longlong *)(lVar4 + 0x18));

              uVar1 = (int)uVar2 + 1;

              uVar2 = (ulonglong)uVar1;

            } while (uVar1 < *(uint *)(lVar4 + 0x10));

          }

          FUN_1401841e0(*(undefined8 *)(lVar4 + 0x18));

        }

        FUN_1401cade0(lVar4 + 0x20);

        FUN_1401cade0(lVar4 + 0x40);

        uVar1 = (int)uVar3 + 1;

        uVar3 = (ulonglong)uVar1;

      } while (uVar1 < *(uint *)(param_1 + 0x18));

    }

    FUN_1401841e0(*(undefined8 *)(param_1 + 0x10));

    FUN_1401cade0(param_1 + 0x28);

    if (*(longlong **)(param_1 + 0x20) != (longlong *)0x0) {

      (**(code **)(**(longlong **)(param_1 + 0x20) + 0x10))();

    }

    FUN_1401841e0(param_1);

  }

  return;

}




