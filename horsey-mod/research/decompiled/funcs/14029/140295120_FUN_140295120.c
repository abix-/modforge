// Address: 0x140295120
// Ghidra name: FUN_140295120
// ============ 0x140295120 FUN_140295120 (size=622) ============


void FUN_140295120(longlong param_1)



{

  ushort uVar1;

  uint uVar2;

  int iVar3;

  int iVar4;

  longlong lVar5;

  longlong lVar6;

  int iVar7;

  ushort *puVar8;

  ushort *puVar9;

  ushort uVar10;

  int iVar11;

  

  lVar5 = *(longlong *)(param_1 + 0x58);

  uVar2 = *(uint *)(param_1 + 0x38);

  puVar9 = *(ushort **)(param_1 + 8);

  iVar3 = *(int *)(param_1 + 0x1c);

  puVar8 = *(ushort **)(param_1 + 0x30);

  iVar4 = *(int *)(param_1 + 0x44);

  lVar6 = *(longlong *)(param_1 + 0x48);

  if (*(int *)(lVar5 + 0x14) == 0) {

    uVar10 = *(ushort *)(lVar6 + 0x10) | *(ushort *)(lVar6 + 0xc) | *(ushort *)(lVar6 + 8);

    iVar7 = *(int *)(param_1 + 0x3c);

    while (iVar7 != 0) {

      iVar11 = (int)(((int)(uVar2 + 7) >> 0x1f & 7U) + uVar2 + 7) >> 3;

      switch(uVar2 & 7) {

      case 1:

        goto switchD_1402952bd_caseD_1;

      case 2:

        goto switchD_1402952bd_caseD_2;

      case 3:

        goto switchD_1402952bd_caseD_3;

      case 4:

        goto switchD_1402952bd_caseD_4;

      case 5:

        goto switchD_1402952bd_caseD_5;

      case 6:

        goto switchD_1402952bd_caseD_6;

      case 7:

        goto switchD_1402952bd_caseD_7;

      }

      do {

        *puVar8 = *puVar9 & uVar10;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

switchD_1402952bd_caseD_7:

        *puVar8 = *puVar9 & uVar10;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

switchD_1402952bd_caseD_6:

        *puVar8 = *puVar9 & uVar10;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

switchD_1402952bd_caseD_5:

        *puVar8 = *puVar9 & uVar10;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

switchD_1402952bd_caseD_4:

        *puVar8 = *puVar9 & uVar10;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

switchD_1402952bd_caseD_3:

        *puVar8 = *puVar9 & uVar10;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

switchD_1402952bd_caseD_2:

        *puVar8 = *puVar9 & uVar10;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

switchD_1402952bd_caseD_1:

        uVar1 = *puVar9;

        iVar11 = iVar11 + -1;

        puVar9 = puVar9 + 1;

        *puVar8 = uVar1 & uVar10;

        puVar8 = puVar8 + 1;

      } while (0 < iVar11);

      puVar9 = (ushort *)((longlong)puVar9 + (longlong)iVar3);

      puVar8 = (ushort *)((longlong)puVar8 + (longlong)iVar4);

      iVar7 = iVar7 + -1;

    }

  }

  else {

    uVar10 = (ushort)(*(byte *)(param_1 + 0x83) >> (8U - *(char *)(lVar5 + 0x1b) & 0x1f)) <<

             (*(byte *)(lVar5 + 0x1f) & 0x1f);

    iVar7 = *(int *)(param_1 + 0x3c);

    while (iVar7 != 0) {

      iVar11 = (int)(((int)(uVar2 + 7) >> 0x1f & 7U) + uVar2 + 7) >> 3;

      switch(uVar2 & 7) {

      case 1:

        goto switchD_1402951bd_caseD_1;

      case 2:

        goto switchD_1402951bd_caseD_2;

      case 3:

        goto switchD_1402951bd_caseD_3;

      case 4:

        goto switchD_1402951bd_caseD_4;

      case 5:

        goto switchD_1402951bd_caseD_5;

      case 6:

        goto switchD_1402951bd_caseD_6;

      case 7:

        goto switchD_1402951bd_caseD_7;

      }

      do {

        *puVar8 = uVar10 | *puVar9;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

switchD_1402951bd_caseD_7:

        *puVar8 = uVar10 | *puVar9;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

switchD_1402951bd_caseD_6:

        *puVar8 = uVar10 | *puVar9;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

switchD_1402951bd_caseD_5:

        *puVar8 = uVar10 | *puVar9;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

switchD_1402951bd_caseD_4:

        *puVar8 = uVar10 | *puVar9;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

switchD_1402951bd_caseD_3:

        *puVar8 = uVar10 | *puVar9;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

switchD_1402951bd_caseD_2:

        *puVar8 = uVar10 | *puVar9;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

switchD_1402951bd_caseD_1:

        iVar11 = iVar11 + -1;

        uVar1 = *puVar9;

        puVar9 = puVar9 + 1;

        *puVar8 = uVar10 | uVar1;

        puVar8 = puVar8 + 1;

      } while (0 < iVar11);

      puVar9 = (ushort *)((longlong)puVar9 + (longlong)iVar3);

      puVar8 = (ushort *)((longlong)puVar8 + (longlong)iVar4);

      iVar7 = iVar7 + -1;

    }

  }

  return;

}




