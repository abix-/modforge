// Address: 0x14006cfa0
// Ghidra name: FUN_14006cfa0
// ============ 0x14006cfa0 FUN_14006cfa0 (size=285) ============


void FUN_14006cfa0(longlong param_1,longlong param_2,ulonglong param_3,int *param_4)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  longlong lVar5;

  longlong lVar6;

  longlong lVar7;

  longlong lVar8;

  bool bVar9;

  bool bVar10;

  

  lVar7 = (longlong)(param_3 - 1) >> 1;

  lVar5 = param_2;

  while (lVar5 < lVar7) {

    lVar6 = (longlong)*(int *)(param_1 + 8 + lVar5 * 8);

    lVar8 = (longlong)*(int *)(param_1 + 4 + lVar5 * 8);

    iVar1 = *(int *)(DAT_1403fb0d8 + 0x2cc + lVar6 * 4);

    iVar2 = *(int *)(DAT_1403fb0d8 + 0x2cc + lVar8 * 4);

    bVar10 = SBORROW4(iVar1,iVar2);

    iVar3 = iVar1 - iVar2;

    bVar9 = false;

    if (iVar1 == iVar2) {

      iVar1 = *(int *)(DAT_1403fb0d8 + 0x298 + lVar8 * 4);

      iVar2 = *(int *)(DAT_1403fb0d8 + 0x298 + lVar6 * 4);

      bVar10 = SBORROW4(iVar2,iVar1);

      iVar3 = iVar2 - iVar1;

      bVar9 = iVar2 == iVar1;

    }

    lVar6 = (ulonglong)(bVar9 || bVar10 != iVar3 < 0) + 1 + lVar5 * 2;

    *(undefined4 *)(param_1 + lVar5 * 4) = *(undefined4 *)(param_1 + lVar6 * 4);

    lVar5 = lVar6;

  }

  if ((lVar5 == lVar7) && ((param_3 & 1) == 0)) {

    *(undefined4 *)(param_1 + lVar5 * 4) = *(undefined4 *)(param_1 + -4 + param_3 * 4);

    lVar5 = param_3 - 1;

  }

  if (param_2 < lVar5) {

    while( true ) {

      lVar7 = lVar5 + -1 >> 1;

      iVar2 = *(int *)(param_1 + lVar7 * 4);

      iVar3 = *(int *)(DAT_1403fb0d8 + 0x2cc + (longlong)iVar2 * 4);

      iVar1 = *(int *)(DAT_1403fb0d8 + 0x2cc + (longlong)*param_4 * 4);

      bVar10 = SBORROW4(iVar3,iVar1);

      iVar4 = iVar3 - iVar1;

      bVar9 = false;

      if (iVar3 == iVar1) {

        iVar1 = *(int *)(DAT_1403fb0d8 + 0x298 + (longlong)*param_4 * 4);

        iVar3 = *(int *)(DAT_1403fb0d8 + 0x298 + (longlong)iVar2 * 4);

        bVar10 = SBORROW4(iVar3,iVar1);

        iVar4 = iVar3 - iVar1;

        bVar9 = iVar3 == iVar1;

      }

      if (bVar9 || bVar10 != iVar4 < 0) break;

      *(int *)(param_1 + lVar5 * 4) = iVar2;

      lVar5 = lVar7;

      if (lVar7 <= param_2) {

        *(int *)(param_1 + lVar7 * 4) = *param_4;

        return;

      }

    }

  }

  *(int *)(param_1 + lVar5 * 4) = *param_4;

  return;

}




