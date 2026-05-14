// Address: 0x1401c9c60
// Ghidra name: FUN_1401c9c60
// ============ 0x1401c9c60 FUN_1401c9c60 (size=101) ============


void FUN_1401c9c60(uint *param_1)



{

  uint uVar1;

  ulonglong uVar2;

  

  uVar2 = 0;

  if (*param_1 != 0) {

    do {

      FUN_1401c9730(*(undefined8 *)(*(longlong *)(param_1 + 2) + uVar2 * 8));

      uVar1 = (int)uVar2 + 1;

      uVar2 = (ulonglong)uVar1;

    } while (uVar1 < *param_1);

  }

  FUN_1401841e0(*(undefined8 *)(param_1 + 2));

  FUN_1401841e0(*(undefined8 *)(param_1 + 6));

  FUN_140179b30(*(undefined8 *)(param_1 + 8));

  FUN_1401841e0(param_1);

  return;

}




