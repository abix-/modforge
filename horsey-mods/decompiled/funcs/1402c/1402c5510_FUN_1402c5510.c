// Address: 0x1402c5510
// Ghidra name: FUN_1402c5510
// ============ 0x1402c5510 FUN_1402c5510 (size=121) ============


undefined8 FUN_1402c5510(longlong param_1,uint param_2)



{

  longlong lVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = *(int *)(param_1 + 0x24);

  if (iVar2 == *(int *)(param_1 + 0x20)) {

    iVar3 = *(int *)(param_1 + 0x20) + 4;

    lVar1 = FUN_140184230(*(undefined8 *)(param_1 + 0x28),(longlong)iVar3 << 2);

    if (lVar1 == 0) {

      return 0;

    }

    iVar2 = *(int *)(param_1 + 0x24);

    *(longlong *)(param_1 + 0x28) = lVar1;

    *(int *)(param_1 + 0x20) = iVar3;

  }

  if (param_2 < 0x10000) {

    param_2 = param_2 | *(int *)(param_1 + 4) << 0x10;

  }

  lVar1 = *(longlong *)(param_1 + 0x28);

  *(uint *)(lVar1 + (longlong)iVar2 * 4) = param_2;

  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;

  return CONCAT71((int7)((ulonglong)lVar1 >> 8),1);

}




