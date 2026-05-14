// Address: 0x140160e30
// Ghidra name: FUN_140160e30
// ============ 0x140160e30 FUN_140160e30 (size=119) ============


void FUN_140160e30(longlong param_1)



{

  int iVar1;

  longlong lVar2;

  

  if (param_1 != 0) {

    iVar1 = 0;

    if (0 < *(int *)(param_1 + 8)) {

      lVar2 = 0;

      do {

        FUN_140160eb0(*(undefined8 *)(*(longlong *)(param_1 + 0x10) + lVar2));

        iVar1 = iVar1 + 1;

        lVar2 = lVar2 + 8;

      } while (iVar1 < *(int *)(param_1 + 8));

    }

    FUN_1401841e0(*(undefined8 *)(param_1 + 0x10));

    FUN_1401841e0(*(undefined8 *)(param_1 + 0x18));

    FUN_1401841e0(param_1);

  }

  return;

}




