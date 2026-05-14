// Address: 0x1401c9cd0
// Ghidra name: FUN_1401c9cd0
// ============ 0x1401c9cd0 FUN_1401c9cd0 (size=168) ============


void FUN_1401c9cd0(undefined8 param_1,longlong param_2)



{

  longlong lVar1;

  uint uVar2;

  ulonglong uVar3;

  

  uVar3 = 0;

  if (*(int *)(param_2 + 0x120) != 0) {

    do {

      lVar1 = uVar3 * 0x50 + param_2;

      FUN_1401cade0(*(longlong *)(lVar1 + 0x58) + 0x28);

      FUN_1401cade0(*(undefined8 *)(*(longlong *)(*(longlong *)(lVar1 + 0x58) + 0x10) + 0x18));

      FUN_1401841e0(*(undefined8 *)(*(longlong *)(*(longlong *)(lVar1 + 0x58) + 0x10) + 0x18));

      FUN_1401841e0(*(undefined8 *)(*(longlong *)(lVar1 + 0x58) + 0x10));

      FUN_1401841e0(*(undefined8 *)(lVar1 + 0x58));

      FUN_1401841e0(*(undefined8 *)(lVar1 + 0x60));

      uVar2 = (int)uVar3 + 1;

      uVar3 = (ulonglong)uVar2;

    } while (uVar2 < *(uint *)(param_2 + 0x120));

  }

  (**(code **)(**(longlong **)(param_2 + 0x18) + 0x10))();

  *(undefined8 *)(param_2 + 0x18) = 0;

  return;

}




