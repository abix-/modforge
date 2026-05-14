// Address: 0x140290bb0
// Ghidra name: FUN_140290bb0
// ============ 0x140290bb0 FUN_140290bb0 (size=319) ============


void FUN_140290bb0(longlong param_1)



{

  byte bVar1;

  uint uVar2;

  int iVar3;

  int iVar4;

  longlong lVar5;

  int iVar6;

  undefined2 *puVar7;

  byte *pbVar8;

  int iVar9;

  

  uVar2 = *(uint *)(param_1 + 0x38);

  pbVar8 = *(byte **)(param_1 + 8);

  iVar3 = *(int *)(param_1 + 0x1c);

  puVar7 = *(undefined2 **)(param_1 + 0x30);

  iVar4 = *(int *)(param_1 + 0x44);

  lVar5 = *(longlong *)(param_1 + 0x68);

  iVar6 = *(int *)(param_1 + 0x3c);

  while (iVar6 != 0) {

    iVar9 = uVar2 + 7;

    iVar9 = (int)((iVar9 >> 0x1f & 7U) + iVar9) >> 3;

    switch(uVar2 & 7) {

    case 1:

      goto switchD_140290c1e_caseD_1;

    case 2:

      goto switchD_140290c1e_caseD_2;

    case 3:

      goto switchD_140290c1e_caseD_3;

    case 4:

      goto switchD_140290c1e_caseD_4;

    case 5:

      goto switchD_140290c1e_caseD_5;

    case 6:

      goto switchD_140290c1e_caseD_6;

    case 7:

      goto switchD_140290c1e_caseD_7;

    }

    do {

      bVar1 = *pbVar8;

      pbVar8 = pbVar8 + 1;

      *puVar7 = *(undefined2 *)(lVar5 + (ulonglong)bVar1 * 2);

      puVar7 = puVar7 + 1;

switchD_140290c1e_caseD_7:

      bVar1 = *pbVar8;

      pbVar8 = pbVar8 + 1;

      *puVar7 = *(undefined2 *)(lVar5 + (ulonglong)bVar1 * 2);

      puVar7 = puVar7 + 1;

switchD_140290c1e_caseD_6:

      bVar1 = *pbVar8;

      pbVar8 = pbVar8 + 1;

      *puVar7 = *(undefined2 *)(lVar5 + (ulonglong)bVar1 * 2);

      puVar7 = puVar7 + 1;

switchD_140290c1e_caseD_5:

      bVar1 = *pbVar8;

      pbVar8 = pbVar8 + 1;

      *puVar7 = *(undefined2 *)(lVar5 + (ulonglong)bVar1 * 2);

      puVar7 = puVar7 + 1;

switchD_140290c1e_caseD_4:

      bVar1 = *pbVar8;

      pbVar8 = pbVar8 + 1;

      *puVar7 = *(undefined2 *)(lVar5 + (ulonglong)bVar1 * 2);

      puVar7 = puVar7 + 1;

switchD_140290c1e_caseD_3:

      bVar1 = *pbVar8;

      pbVar8 = pbVar8 + 1;

      *puVar7 = *(undefined2 *)(lVar5 + (ulonglong)bVar1 * 2);

      puVar7 = puVar7 + 1;

switchD_140290c1e_caseD_2:

      bVar1 = *pbVar8;

      pbVar8 = pbVar8 + 1;

      *puVar7 = *(undefined2 *)(lVar5 + (ulonglong)bVar1 * 2);

      puVar7 = puVar7 + 1;

switchD_140290c1e_caseD_1:

      bVar1 = *pbVar8;

      iVar9 = iVar9 + -1;

      pbVar8 = pbVar8 + 1;

      *puVar7 = *(undefined2 *)(lVar5 + (ulonglong)bVar1 * 2);

      puVar7 = puVar7 + 1;

    } while (0 < iVar9);

    pbVar8 = pbVar8 + iVar3;

    puVar7 = (undefined2 *)((longlong)puVar7 + (longlong)iVar4);

    iVar6 = iVar6 + -1;

  }

  return;

}




