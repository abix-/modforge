// Address: 0x1401caec0
// Ghidra name: FUN_1401caec0
// ============ 0x1401caec0 FUN_1401caec0 (size=137) ============


void FUN_1401caec0(longlong param_1,longlong param_2)



{

  uint uVar1;

  ulonglong uVar2;

  

  FUN_140179b40(*(undefined8 *)(param_1 + 0x228));

  uVar2 = 0;

  if (*(int *)(param_2 + 0x3c) != 0) {

    do {

      FUN_1401cae30(param_1,*(undefined8 *)(*(longlong *)(param_2 + 0x30) + uVar2 * 8));

      uVar1 = (int)uVar2 + 1;

      uVar2 = (ulonglong)uVar1;

    } while (uVar1 < *(uint *)(param_2 + 0x3c));

  }

  FUN_1401747e0(*(undefined4 *)(param_2 + 0x20));

  FUN_1401841e0(*(undefined8 *)(param_2 + 0x48));

  FUN_1401841e0(*(undefined8 *)(param_2 + 0x30));

  FUN_1401841e0(param_2);

  FUN_140179b60(*(undefined8 *)(param_1 + 0x228));

  return;

}




