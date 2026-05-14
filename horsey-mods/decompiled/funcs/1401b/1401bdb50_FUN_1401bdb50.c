// Address: 0x1401bdb50
// Ghidra name: FUN_1401bdb50
// ============ 0x1401bdb50 FUN_1401bdb50 (size=164) ============


void FUN_1401bdb50(longlong param_1,longlong param_2)



{

  int iVar1;

  undefined8 uVar2;

  longlong *plVar3;

  longlong lVar4;

  

  iVar1 = *(int *)(param_1 + 0xa28) + -1;

  if (-1 < iVar1) {

    lVar4 = (longlong)iVar1;

    plVar3 = (longlong *)(*(longlong *)(param_1 + 0xa20) + lVar4 * 8);

    do {

      if (*plVar3 == param_2) {

        return;

      }

      plVar3 = plVar3 + -1;

      lVar4 = lVar4 + -1;

    } while (-1 < lVar4);

  }

  if (*(int *)(param_1 + 0xa28) == *(int *)(param_1 + 0xa2c)) {

    iVar1 = *(int *)(param_1 + 0xa2c) + 1;

    *(int *)(param_1 + 0xa2c) = iVar1;

    uVar2 = FUN_140184230(*(undefined8 *)(param_1 + 0xa20),(longlong)iVar1 << 3);

    *(undefined8 *)(param_1 + 0xa20) = uVar2;

  }

  *(longlong *)(*(longlong *)(param_1 + 0xa20) + (longlong)*(int *)(param_1 + 0xa28) * 8) = param_2;

  *(int *)(param_1 + 0xa28) = *(int *)(param_1 + 0xa28) + 1;

  FUN_140138fb0(param_2 + 0x54,1);

  return;

}




