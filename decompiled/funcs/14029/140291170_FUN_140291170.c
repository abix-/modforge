// Address: 0x140291170
// Ghidra name: FUN_140291170
// ============ 0x140291170 FUN_140291170 (size=306) ============


void FUN_140291170(longlong param_1)



{

  byte bVar1;

  int iVar2;

  uint uVar3;

  int iVar4;

  longlong lVar5;

  int iVar6;

  undefined4 *puVar7;

  byte *pbVar8;

  int iVar9;

  

  iVar2 = *(int *)(param_1 + 0x44);

  uVar3 = *(uint *)(param_1 + 0x38);

  pbVar8 = *(byte **)(param_1 + 8);

  iVar4 = *(int *)(param_1 + 0x1c);

  puVar7 = *(undefined4 **)(param_1 + 0x30);

  lVar5 = *(longlong *)(param_1 + 0x68);

  iVar6 = *(int *)(param_1 + 0x3c);

  while (iVar6 != 0) {

    iVar9 = uVar3 + 7;

    iVar9 = (int)((iVar9 >> 0x1f & 7U) + iVar9) >> 3;

    switch(uVar3 & 7) {

    case 1:

      goto switchD_1402911e0_caseD_1;

    case 2:

      goto switchD_1402911e0_caseD_2;

    case 3:

      goto switchD_1402911e0_caseD_3;

    case 4:

      goto switchD_1402911e0_caseD_4;

    case 5:

      goto switchD_1402911e0_caseD_5;

    case 6:

      goto switchD_1402911e0_caseD_6;

    case 7:

      goto switchD_1402911e0_caseD_7;

    }

    do {

      *puVar7 = *(undefined4 *)(lVar5 + (ulonglong)*pbVar8 * 4);

      puVar7 = puVar7 + 1;

      pbVar8 = pbVar8 + 1;

switchD_1402911e0_caseD_7:

      *puVar7 = *(undefined4 *)(lVar5 + (ulonglong)*pbVar8 * 4);

      puVar7 = puVar7 + 1;

      pbVar8 = pbVar8 + 1;

switchD_1402911e0_caseD_6:

      *puVar7 = *(undefined4 *)(lVar5 + (ulonglong)*pbVar8 * 4);

      puVar7 = puVar7 + 1;

      pbVar8 = pbVar8 + 1;

switchD_1402911e0_caseD_5:

      *puVar7 = *(undefined4 *)(lVar5 + (ulonglong)*pbVar8 * 4);

      puVar7 = puVar7 + 1;

      pbVar8 = pbVar8 + 1;

switchD_1402911e0_caseD_4:

      *puVar7 = *(undefined4 *)(lVar5 + (ulonglong)*pbVar8 * 4);

      puVar7 = puVar7 + 1;

      pbVar8 = pbVar8 + 1;

switchD_1402911e0_caseD_3:

      *puVar7 = *(undefined4 *)(lVar5 + (ulonglong)*pbVar8 * 4);

      puVar7 = puVar7 + 1;

      pbVar8 = pbVar8 + 1;

switchD_1402911e0_caseD_2:

      *puVar7 = *(undefined4 *)(lVar5 + (ulonglong)*pbVar8 * 4);

      puVar7 = puVar7 + 1;

      pbVar8 = pbVar8 + 1;

switchD_1402911e0_caseD_1:

      bVar1 = *pbVar8;

      iVar9 = iVar9 + -1;

      pbVar8 = pbVar8 + 1;

      *puVar7 = *(undefined4 *)(lVar5 + (ulonglong)bVar1 * 4);

      puVar7 = puVar7 + 1;

    } while (0 < iVar9);

    pbVar8 = pbVar8 + iVar4;

    puVar7 = puVar7 + ((int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2);

    iVar6 = iVar6 + -1;

  }

  return;

}




