// Address: 0x14006cb40
// Ghidra name: FUN_14006cb40
// ============ 0x14006cb40 FUN_14006cb40 (size=233) ============


void FUN_14006cb40(int *param_1,int *param_2,int *param_3)



{

  longlong lVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  longlong lVar7;

  bool bVar8;

  bool bVar9;

  

  iVar3 = *param_2;

  iVar4 = *param_1;

  iVar5 = *(int *)(DAT_1403fb0d8 + 0x2cc + (longlong)iVar3 * 4);

  iVar2 = *(int *)(DAT_1403fb0d8 + 0x2cc + (longlong)iVar4 * 4);

  bVar9 = SBORROW4(iVar5,iVar2);

  iVar6 = iVar5 - iVar2;

  bVar8 = false;

  if (iVar5 == iVar2) {

    iVar2 = *(int *)(DAT_1403fb0d8 + 0x298 + (longlong)iVar4 * 4);

    iVar5 = *(int *)(DAT_1403fb0d8 + 0x298 + (longlong)iVar3 * 4);

    bVar9 = SBORROW4(iVar5,iVar2);

    iVar6 = iVar5 - iVar2;

    bVar8 = iVar5 == iVar2;

  }

  if (!bVar8 && bVar9 == iVar6 < 0) {

    *param_2 = iVar4;

    *param_1 = iVar3;

  }

  iVar3 = *param_3;

  lVar7 = (longlong)iVar3;

  iVar4 = *param_2;

  lVar1 = lVar7 * 4 + 0x2cc;

  iVar5 = *(int *)(lVar1 + DAT_1403fb0d8);

  iVar2 = *(int *)(DAT_1403fb0d8 + 0x2cc + (longlong)iVar4 * 4);

  bVar9 = SBORROW4(iVar5,iVar2);

  iVar6 = iVar5 - iVar2;

  bVar8 = false;

  if (iVar5 == iVar2) {

    iVar2 = *(int *)(DAT_1403fb0d8 + 0x298 + (longlong)iVar4 * 4);

    iVar5 = *(int *)(DAT_1403fb0d8 + 0x298 + lVar7 * 4);

    bVar9 = SBORROW4(iVar5,iVar2);

    iVar6 = iVar5 - iVar2;

    bVar8 = iVar5 == iVar2;

  }

  if (!bVar8 && bVar9 == iVar6 < 0) {

    *param_3 = iVar4;

    *param_2 = iVar3;

    iVar4 = *param_1;

    iVar5 = *(int *)(lVar1 + DAT_1403fb0d8);

    iVar2 = *(int *)(DAT_1403fb0d8 + 0x2cc + (longlong)iVar4 * 4);

    bVar9 = SBORROW4(iVar5,iVar2);

    iVar6 = iVar5 - iVar2;

    bVar8 = false;

    if (iVar5 == iVar2) {

      iVar2 = *(int *)(DAT_1403fb0d8 + 0x298 + (longlong)iVar4 * 4);

      iVar5 = *(int *)(DAT_1403fb0d8 + (lVar7 + 0xa6) * 4);

      bVar9 = SBORROW4(iVar5,iVar2);

      iVar6 = iVar5 - iVar2;

      bVar8 = iVar5 == iVar2;

    }

    if (!bVar8 && bVar9 == iVar6 < 0) {

      *param_2 = iVar4;

      *param_1 = iVar3;

    }

  }

  return;

}




