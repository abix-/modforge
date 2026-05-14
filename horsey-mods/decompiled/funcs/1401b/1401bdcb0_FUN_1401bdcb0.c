// Address: 0x1401bdcb0
// Ghidra name: FUN_1401bdcb0
// ============ 0x1401bdcb0 FUN_1401bdcb0 (size=161) ============


void FUN_1401bdcb0(longlong param_1,undefined8 *param_2)



{

  int iVar1;

  undefined8 uVar2;

  longlong *plVar3;

  longlong lVar4;

  

  iVar1 = *(int *)(param_1 + 0xa88) + -1;

  if (-1 < iVar1) {

    lVar4 = (longlong)iVar1;

    plVar3 = (longlong *)(*(longlong *)(param_1 + 0xa80) + lVar4 * 8);

    do {

      if ((undefined8 *)*plVar3 == param_2) {

        return;

      }

      plVar3 = plVar3 + -1;

      lVar4 = lVar4 + -1;

    } while (-1 < lVar4);

  }

  if (*(int *)(param_1 + 0xa88) == *(int *)(param_1 + 0xa8c)) {

    iVar1 = *(int *)(param_1 + 0xa8c) + 1;

    *(int *)(param_1 + 0xa8c) = iVar1;

    uVar2 = FUN_140184230(*(undefined8 *)(param_1 + 0xa80),(longlong)iVar1 << 3);

    *(undefined8 *)(param_1 + 0xa80) = uVar2;

  }

  *(undefined8 **)(*(longlong *)(param_1 + 0xa80) + (longlong)*(int *)(param_1 + 0xa88) * 8) =

       param_2;

  *(int *)(param_1 + 0xa88) = *(int *)(param_1 + 0xa88) + 1;

  FUN_1401bd730(param_1,*param_2);

  return;

}




