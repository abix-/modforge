// Address: 0x1401bd7e0
// Ghidra name: FUN_1401bd7e0
// ============ 0x1401bd7e0 FUN_1401bd7e0 (size=171) ============


void FUN_1401bd7e0(longlong param_1,longlong param_2)



{

  int iVar1;

  undefined8 uVar2;

  longlong *plVar3;

  longlong lVar4;

  

  iVar1 = *(int *)(param_1 + 0xa18) + -1;

  if (-1 < iVar1) {

    lVar4 = (longlong)iVar1;

    plVar3 = (longlong *)(*(longlong *)(param_1 + 0xa10) + lVar4 * 8);

    do {

      if (*plVar3 == param_2) {

        return;

      }

      plVar3 = plVar3 + -1;

      lVar4 = lVar4 + -1;

    } while (-1 < lVar4);

  }

  if (*(int *)(param_1 + 0xa18) == *(int *)(param_1 + 0xa1c)) {

    iVar1 = *(int *)(param_1 + 0xa1c) + 1;

    *(int *)(param_1 + 0xa1c) = iVar1;

    uVar2 = FUN_140184230(*(undefined8 *)(param_1 + 0xa10),(longlong)iVar1 << 3);

    *(undefined8 *)(param_1 + 0xa10) = uVar2;

  }

  *(longlong *)(*(longlong *)(param_1 + 0xa10) + (longlong)*(int *)(param_1 + 0xa18) * 8) = param_2;

  *(int *)(param_1 + 0xa18) = *(int *)(param_1 + 0xa18) + 1;

  FUN_140138fb0(**(longlong **)(param_2 + 0x18) + 0x60,1);

  return;

}




