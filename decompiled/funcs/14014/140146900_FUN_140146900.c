// Address: 0x140146900
// Ghidra name: FUN_140146900
// ============ 0x140146900 FUN_140146900 (size=453) ============


longlong FUN_140146900(longlong param_1,float param_2)



{

  char cVar1;

  int iVar2;

  int iVar3;

  longlong *plVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  longlong lVar8;

  longlong lVar9;

  longlong lVar10;

  int iVar11;

  int iVar12;

  double dVar13;

  

  cVar1 = FUN_1401489c0();

  if (cVar1 == '\0') {

    FUN_14012e850("Parameter \'%s\' is invalid","surface");

    return 0;

  }

  cVar1 = FUN_140148930(param_1);

  if (cVar1 == '\0') {

    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;

    return param_1;

  }

  plVar4 = (longlong *)FUN_140146ad0(param_1,0);

  if (plVar4 == (longlong *)0x0) {

    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;

    return param_1;

  }

  lVar10 = 0;

  dVar13 = (double)thunk_FUN_1402e1d50((double)((float)*(int *)(param_1 + 8) * param_2));

  iVar12 = (int)dVar13;

  dVar13 = (double)thunk_FUN_1402e1d50((double)((float)*(int *)(param_1 + 0xc) * param_2));

  iVar3 = -1;

  iVar7 = (int)dVar13;

  iVar5 = -1;

  lVar9 = lVar10;

  for (lVar8 = *plVar4; lVar8 != 0; lVar8 = plVar4[lVar8]) {

    iVar6 = *(int *)(lVar8 + 0xc) - iVar7;

    iVar11 = *(int *)(lVar8 + 0xc) * *(int *)(lVar8 + 8);

    iVar2 = *(int *)(lVar8 + 8) - iVar12;

    iVar2 = iVar6 * iVar6 + iVar2 * iVar2;

    if (((iVar3 < 0) || (iVar2 < iVar3)) || ((iVar7 * iVar12 < iVar11 && (iVar5 < iVar7 * iVar12))))

    {

      lVar9 = lVar8;

      iVar5 = iVar11;

      iVar3 = iVar2;

    }

    lVar8 = lVar10 + 1;

    lVar10 = lVar10 + 1;

  }

  FUN_1401841e0(plVar4);

  lVar8 = lVar9;

  if ((*(int *)(lVar9 + 8) == iVar12) && (*(int *)(lVar9 + 0xc) == iVar7)) {

LAB_140146aa0:

    *(int *)(lVar9 + 0x20) = *(int *)(lVar9 + 0x20) + 1;

    lVar10 = lVar9;

  }

  else {

    do {

      iVar3 = (*(int *)(lVar8 + 8) + 1) / 2;

      iVar2 = (*(int *)(lVar8 + 0xc) + 1) / 2;

      iVar5 = iVar7;

      if (iVar7 <= iVar2) {

        iVar5 = iVar2;

      }

      iVar2 = iVar12;

      if (iVar12 <= iVar3) {

        iVar2 = iVar3;

      }

      lVar10 = FUN_140148140(lVar8,iVar2,iVar5,1);

      if (lVar8 != lVar9) {

        FUN_140146010(lVar8);

      }

      if (lVar10 == 0) goto LAB_140146aa0;

      lVar8 = lVar10;

    } while ((*(int *)(lVar10 + 8) != iVar12) || (*(int *)(lVar10 + 0xc) != iVar7));

  }

  return lVar10;

}




