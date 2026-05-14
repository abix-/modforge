// Address: 0x1401700f0
// Ghidra name: FUN_1401700f0
// ============ 0x1401700f0 FUN_1401700f0 (size=134) ============


void FUN_1401700f0(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar2 = (longlong)*(int *)(param_1 + 0x14);

  if (lVar2 != 0) {

    lVar1 = lVar2 * 0x28;

    do {

      lVar1 = lVar1 + -0x28;

      FUN_1401841e0(*(undefined8 *)(*(longlong *)(param_1 + 0x18) + 0x20 + lVar1));

      *(undefined8 *)(*(longlong *)(param_1 + 0x18) + 0x20 + lVar1) = 0;

      lVar2 = lVar2 + -1;

    } while (lVar2 != 0);

  }

  FUN_1401841e0(*(undefined8 *)(param_1 + 0x18));

  *(longlong *)(param_1 + 0x48) = param_1 + 0x20;

  *(undefined8 *)(param_1 + 0x18) = 0;

  *(undefined8 *)(param_1 + 0x10) = 0;

  return;

}




