// Address: 0x140290d10
// Ghidra name: FUN_140290d10
// ============ 0x140290d10 FUN_140290d10 (size=362) ============


void FUN_140290d10(longlong param_1)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  uint uVar4;

  longlong lVar5;

  int iVar6;

  int iVar7;

  byte *pbVar8;

  undefined2 *puVar9;

  

  iVar1 = *(int *)(param_1 + 0x44);

  uVar2 = *(uint *)(param_1 + 0x38);

  pbVar8 = *(byte **)(param_1 + 8);

  iVar3 = *(int *)(param_1 + 0x1c);

  puVar9 = *(undefined2 **)(param_1 + 0x30);

  lVar5 = *(longlong *)(param_1 + 0x68);

  uVar4 = *(uint *)(param_1 + 0x7c);

  iVar7 = *(int *)(param_1 + 0x3c);

  while (iVar7 != 0) {

    iVar6 = uVar2 + 7;

    iVar6 = (int)((iVar6 >> 0x1f & 7U) + iVar6) >> 3;

    switch(uVar2 & 7) {

    case 1:

      goto switchD_140290d80_caseD_1;

    case 2:

      goto switchD_140290d80_caseD_2;

    case 3:

      goto switchD_140290d80_caseD_3;

    case 4:

      goto switchD_140290d80_caseD_4;

    case 5:

      goto switchD_140290d80_caseD_5;

    case 6:

      goto switchD_140290d80_caseD_6;

    case 7:

      goto switchD_140290d80_caseD_7;

    }

    do {

      if (*pbVar8 != uVar4) {

        *puVar9 = *(undefined2 *)(lVar5 + (ulonglong)*pbVar8 * 2);

      }

      pbVar8 = pbVar8 + 1;

      puVar9 = puVar9 + 1;

switchD_140290d80_caseD_7:

      if (*pbVar8 != uVar4) {

        *puVar9 = *(undefined2 *)(lVar5 + (ulonglong)*pbVar8 * 2);

      }

      pbVar8 = pbVar8 + 1;

      puVar9 = puVar9 + 1;

switchD_140290d80_caseD_6:

      if (*pbVar8 != uVar4) {

        *puVar9 = *(undefined2 *)(lVar5 + (ulonglong)*pbVar8 * 2);

      }

      pbVar8 = pbVar8 + 1;

      puVar9 = puVar9 + 1;

switchD_140290d80_caseD_5:

      if (*pbVar8 != uVar4) {

        *puVar9 = *(undefined2 *)(lVar5 + (ulonglong)*pbVar8 * 2);

      }

      pbVar8 = pbVar8 + 1;

      puVar9 = puVar9 + 1;

switchD_140290d80_caseD_4:

      if (*pbVar8 != uVar4) {

        *puVar9 = *(undefined2 *)(lVar5 + (ulonglong)*pbVar8 * 2);

      }

      pbVar8 = pbVar8 + 1;

      puVar9 = puVar9 + 1;

switchD_140290d80_caseD_3:

      if (*pbVar8 != uVar4) {

        *puVar9 = *(undefined2 *)(lVar5 + (ulonglong)*pbVar8 * 2);

      }

      pbVar8 = pbVar8 + 1;

      puVar9 = puVar9 + 1;

switchD_140290d80_caseD_2:

      if (*pbVar8 != uVar4) {

        *puVar9 = *(undefined2 *)(lVar5 + (ulonglong)*pbVar8 * 2);

      }

      pbVar8 = pbVar8 + 1;

      puVar9 = puVar9 + 1;

switchD_140290d80_caseD_1:

      if (*pbVar8 != uVar4) {

        *puVar9 = *(undefined2 *)(lVar5 + (ulonglong)*pbVar8 * 2);

      }

      pbVar8 = pbVar8 + 1;

      puVar9 = puVar9 + 1;

      iVar6 = iVar6 + -1;

    } while (0 < iVar6);

    pbVar8 = pbVar8 + iVar3;

    puVar9 = puVar9 + iVar1 / 2;

    iVar7 = iVar7 + -1;

  }

  return;

}




