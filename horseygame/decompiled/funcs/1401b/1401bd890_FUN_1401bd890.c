// Address: 0x1401bd890
// Ghidra name: FUN_1401bd890
// ============ 0x1401bd890 FUN_1401bd890 (size=164) ============


void FUN_1401bd890(longlong param_1,longlong param_2)



{

  int iVar1;

  undefined8 uVar2;

  longlong *plVar3;

  longlong lVar4;

  

  iVar1 = *(int *)(param_1 + 0xa68) + -1;

  if (-1 < iVar1) {

    lVar4 = (longlong)iVar1;

    plVar3 = (longlong *)(*(longlong *)(param_1 + 0xa60) + lVar4 * 8);

    do {

      if (*plVar3 == param_2) {

        return;

      }

      plVar3 = plVar3 + -1;

      lVar4 = lVar4 + -1;

    } while (-1 < lVar4);

  }

  if (*(int *)(param_1 + 0xa68) == *(int *)(param_1 + 0xa6c)) {

    iVar1 = *(int *)(param_1 + 0xa6c) + 1;

    *(int *)(param_1 + 0xa6c) = iVar1;

    uVar2 = FUN_140184230(*(undefined8 *)(param_1 + 0xa60),(longlong)iVar1 << 3);

    *(undefined8 *)(param_1 + 0xa60) = uVar2;

  }

  *(longlong *)(*(longlong *)(param_1 + 0xa60) + (longlong)*(int *)(param_1 + 0xa68) * 8) = param_2;

  *(int *)(param_1 + 0xa68) = *(int *)(param_1 + 0xa68) + 1;

  FUN_140138fb0(param_2 + 0x30,1);

  return;

}




