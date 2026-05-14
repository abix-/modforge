// Address: 0x1402953d0
// Ghidra name: FUN_1402953d0
// ============ 0x1402953d0 FUN_1402953d0 (size=566) ============


void FUN_1402953d0(longlong param_1)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  longlong lVar5;

  longlong lVar6;

  int iVar7;

  uint *puVar8;

  uint *puVar9;

  uint uVar10;

  int iVar11;

  

  lVar5 = *(longlong *)(param_1 + 0x58);

  uVar1 = *(uint *)(param_1 + 0x38);

  puVar9 = *(uint **)(param_1 + 8);

  iVar2 = *(int *)(param_1 + 0x1c);

  puVar8 = *(uint **)(param_1 + 0x30);

  iVar3 = *(int *)(param_1 + 0x44);

  lVar6 = *(longlong *)(param_1 + 0x48);

  if (*(int *)(lVar5 + 0x14) == 0) {

    uVar10 = *(uint *)(lVar6 + 0x10) | *(uint *)(lVar6 + 0xc) | *(uint *)(lVar6 + 8);

    iVar7 = *(int *)(param_1 + 0x3c);

    while (iVar7 != 0) {

      iVar11 = (int)(((int)(uVar1 + 7) >> 0x1f & 7U) + uVar1 + 7) >> 3;

      switch(uVar1 & 7) {

      case 1:

        goto switchD_14029554d_caseD_1;

      case 2:

        goto switchD_14029554d_caseD_2;

      case 3:

        goto switchD_14029554d_caseD_3;

      case 4:

        goto switchD_14029554d_caseD_4;

      case 5:

        goto switchD_14029554d_caseD_5;

      case 6:

        goto switchD_14029554d_caseD_6;

      case 7:

        goto switchD_14029554d_caseD_7;

      }

      do {

        *puVar8 = *puVar9 & uVar10;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

switchD_14029554d_caseD_7:

        *puVar8 = *puVar9 & uVar10;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

switchD_14029554d_caseD_6:

        *puVar8 = *puVar9 & uVar10;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

switchD_14029554d_caseD_5:

        *puVar8 = *puVar9 & uVar10;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

switchD_14029554d_caseD_4:

        *puVar8 = *puVar9 & uVar10;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

switchD_14029554d_caseD_3:

        *puVar8 = *puVar9 & uVar10;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

switchD_14029554d_caseD_2:

        *puVar8 = *puVar9 & uVar10;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

switchD_14029554d_caseD_1:

        uVar4 = *puVar9;

        iVar11 = iVar11 + -1;

        puVar9 = puVar9 + 1;

        *puVar8 = uVar4 & uVar10;

        puVar8 = puVar8 + 1;

      } while (0 < iVar11);

      puVar9 = (uint *)((longlong)puVar9 + (longlong)iVar2);

      puVar8 = (uint *)((longlong)puVar8 + (longlong)iVar3);

      iVar7 = iVar7 + -1;

    }

  }

  else {

    uVar10 = (uint)(*(byte *)(param_1 + 0x83) >> (8U - *(char *)(lVar5 + 0x1b) & 0x1f)) <<

             (*(byte *)(lVar5 + 0x1f) & 0x1f);

    iVar7 = *(int *)(param_1 + 0x3c);

    while (iVar7 != 0) {

      iVar11 = (int)(((int)(uVar1 + 7) >> 0x1f & 7U) + uVar1 + 7) >> 3;

      switch(uVar1 & 7) {

      case 1:

        goto switchD_14029546d_caseD_1;

      case 2:

        goto switchD_14029546d_caseD_2;

      case 3:

        goto switchD_14029546d_caseD_3;

      case 4:

        goto switchD_14029546d_caseD_4;

      case 5:

        goto switchD_14029546d_caseD_5;

      case 6:

        goto switchD_14029546d_caseD_6;

      case 7:

        goto switchD_14029546d_caseD_7;

      }

      do {

        *puVar8 = uVar10 | *puVar9;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

switchD_14029546d_caseD_7:

        *puVar8 = uVar10 | *puVar9;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

switchD_14029546d_caseD_6:

        *puVar8 = uVar10 | *puVar9;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

switchD_14029546d_caseD_5:

        *puVar8 = uVar10 | *puVar9;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

switchD_14029546d_caseD_4:

        *puVar8 = uVar10 | *puVar9;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

switchD_14029546d_caseD_3:

        *puVar8 = uVar10 | *puVar9;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

switchD_14029546d_caseD_2:

        *puVar8 = uVar10 | *puVar9;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

switchD_14029546d_caseD_1:

        iVar11 = iVar11 + -1;

        uVar4 = *puVar9;

        puVar9 = puVar9 + 1;

        *puVar8 = uVar10 | uVar4;

        puVar8 = puVar8 + 1;

      } while (0 < iVar11);

      puVar9 = (uint *)((longlong)puVar9 + (longlong)iVar2);

      puVar8 = (uint *)((longlong)puVar8 + (longlong)iVar3);

      iVar7 = iVar7 + -1;

    }

  }

  return;

}




