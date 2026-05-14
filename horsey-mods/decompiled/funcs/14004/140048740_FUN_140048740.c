// Address: 0x140048740
// Ghidra name: FUN_140048740
// ============ 0x140048740 FUN_140048740 (size=455) ============


undefined8 FUN_140048740(undefined8 param_1,int *param_2,longlong param_3,int param_4,int param_5)



{

  int iVar1;

  int iVar2;

  longlong lVar3;

  int iVar4;

  longlong lVar5;

  longlong lVar6;

  int iVar7;

  longlong lVar8;

  longlong lVar9;

  float fVar10;

  float fVar11;

  

  iVar2 = FUN_1400485e0();

  fVar10 = 0.0;

  if (iVar2 < 0) {

    return 0;

  }

  iVar1 = *param_2;

  if (iVar1 < param_4) {

    param_4 = iVar1;

  }

  iVar4 = 0;

  lVar5 = (longlong)param_4;

  lVar9 = 0;

  if (lVar5 < 4) {

    if (param_4 < 1) {

      return 1;

    }

  }

  else {

    iVar7 = param_5 * 2;

    lVar6 = (longlong)(iVar2 * iVar1) * 4;

    lVar8 = (lVar5 - 4U >> 2) + 1;

    iVar4 = (int)lVar8 * 4;

    lVar9 = lVar8 * 4;

    do {

      fVar11 = fVar10 + *(float *)(lVar6 + *(longlong *)(param_2 + 8));

      lVar3 = (longlong)(param_5 * -2 + iVar7);

      *(float *)(param_3 + lVar3 * 4) = fVar11 + *(float *)(param_3 + lVar3 * 4);

      if (*(char *)((longlong)param_2 + 0x1a) != '\0') {

        fVar10 = fVar11;

      }

      fVar11 = fVar10 + *(float *)(lVar6 + 4 + *(longlong *)(param_2 + 8));

      *(float *)(param_3 + (longlong)(iVar7 - param_5) * 4) =

           fVar11 + *(float *)(param_3 + (longlong)(iVar7 - param_5) * 4);

      if (*(char *)((longlong)param_2 + 0x1a) != '\0') {

        fVar10 = fVar11;

      }

      fVar11 = fVar10 + *(float *)(*(longlong *)(param_2 + 8) + 8 + lVar6);

      *(float *)(param_3 + (longlong)iVar7 * 4) = fVar11 + *(float *)(param_3 + (longlong)iVar7 * 4)

      ;

      if (*(char *)((longlong)param_2 + 0x1a) != '\0') {

        fVar10 = fVar11;

      }

      fVar11 = fVar10 + *(float *)(*(longlong *)(param_2 + 8) + 0xc + lVar6);

      *(float *)(param_3 + (longlong)(iVar7 + param_5) * 4) =

           fVar11 + *(float *)(param_3 + (longlong)(iVar7 + param_5) * 4);

      if (*(char *)((longlong)param_2 + 0x1a) != '\0') {

        fVar10 = fVar11;

      }

      iVar7 = iVar7 + param_5 * 4;

      lVar6 = lVar6 + 0x10;

      lVar8 = lVar8 + -1;

    } while (lVar8 != 0);

    if (lVar5 <= lVar9) {

      return 1;

    }

  }

  iVar4 = iVar4 * param_5;

  lVar6 = (iVar2 * iVar1 + lVar9) * 4;

  lVar5 = lVar5 - lVar9;

  do {

    fVar11 = fVar10 + *(float *)(*(longlong *)(param_2 + 8) + lVar6);

    *(float *)(param_3 + (longlong)iVar4 * 4) = fVar11 + *(float *)(param_3 + (longlong)iVar4 * 4);

    if (*(char *)((longlong)param_2 + 0x1a) != '\0') {

      fVar10 = fVar11;

    }

    iVar4 = iVar4 + param_5;

    lVar6 = lVar6 + 4;

    lVar5 = lVar5 + -1;

  } while (lVar5 != 0);

  return 1;

}




