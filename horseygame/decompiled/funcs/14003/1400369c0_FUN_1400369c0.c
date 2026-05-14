// Address: 0x1400369c0
// Ghidra name: FUN_1400369c0
// ============ 0x1400369c0 FUN_1400369c0 (size=496) ============


void FUN_1400369c0(longlong *param_1,longlong *param_2,longlong *param_3)



{

  longlong *plVar1;

  longlong lVar2;

  longlong lVar3;

  longlong lVar4;

  longlong *plVar5;

  longlong *plVar6;

  

  lVar2 = *param_1;

  lVar3 = (longlong)param_3 - (longlong)param_1 >> 3;

  if (lVar3 < 0x29) {

    lVar3 = *param_2;

    if (*(int *)(lVar3 + 0x228) < *(int *)(lVar2 + 0x228)) {

      *param_2 = lVar2;

      *param_1 = lVar3;

    }

    lVar2 = *param_3;

    if (*(int *)(lVar2 + 0x228) < *(int *)(*param_2 + 0x228)) {

      *param_3 = *param_2;

      *param_2 = lVar2;

      if (*(int *)(lVar2 + 0x228) < *(int *)(*param_1 + 0x228)) {

        *param_2 = *param_1;

        *param_1 = lVar2;

      }

    }

  }

  else {

    lVar4 = lVar3 + 1 >> 3;

    lVar3 = param_1[lVar4];

    plVar1 = param_1 + lVar4;

    if (*(int *)(lVar3 + 0x228) < *(int *)(lVar2 + 0x228)) {

      *plVar1 = lVar2;

      *param_1 = lVar3;

    }

    lVar2 = param_1[lVar4 * 2];

    if (*(int *)(lVar2 + 0x228) < *(int *)(*plVar1 + 0x228)) {

      param_1[lVar4 * 2] = *plVar1;

      *plVar1 = lVar2;

      if (*(int *)(lVar2 + 0x228) < *(int *)(*param_1 + 0x228)) {

        *plVar1 = *param_1;

        *param_1 = lVar2;

      }

    }

    lVar2 = *param_2;

    plVar5 = param_2 + -lVar4;

    if (*(int *)(lVar2 + 0x228) < *(int *)(*plVar5 + 0x228)) {

      *param_2 = *plVar5;

      *plVar5 = lVar2;

    }

    lVar2 = param_2[lVar4];

    if (*(int *)(lVar2 + 0x228) < *(int *)(*param_2 + 0x228)) {

      param_2[lVar4] = *param_2;

      *param_2 = lVar2;

      if (*(int *)(lVar2 + 0x228) < *(int *)(*plVar5 + 0x228)) {

        *param_2 = *plVar5;

        *plVar5 = lVar2;

      }

    }

    plVar6 = param_3 + lVar4 * -2;

    plVar5 = param_3 + -lVar4;

    lVar2 = *plVar5;

    if (*(int *)(lVar2 + 0x228) < *(int *)(*plVar6 + 0x228)) {

      *plVar5 = *plVar6;

      *plVar6 = lVar2;

    }

    lVar2 = *param_3;

    if (*(int *)(lVar2 + 0x228) < *(int *)(*plVar5 + 0x228)) {

      *param_3 = *plVar5;

      *plVar5 = lVar2;

      if (*(int *)(lVar2 + 0x228) < *(int *)(*plVar6 + 0x228)) {

        *plVar5 = *plVar6;

        *plVar6 = lVar2;

      }

    }

    lVar2 = *param_2;

    if (*(int *)(lVar2 + 0x228) < *(int *)(*plVar1 + 0x228)) {

      *param_2 = *plVar1;

      *plVar1 = lVar2;

    }

    lVar2 = *plVar5;

    if (*(int *)(lVar2 + 0x228) < *(int *)(*param_2 + 0x228)) {

      *plVar5 = *param_2;

      *param_2 = lVar2;

      if (*(int *)(lVar2 + 0x228) < *(int *)(*plVar1 + 0x228)) {

        *param_2 = *plVar1;

        *plVar1 = lVar2;

        return;

      }

    }

  }

  return;

}




