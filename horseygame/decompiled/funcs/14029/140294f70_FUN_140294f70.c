// Address: 0x140294f70
// Ghidra name: FUN_140294f70
// ============ 0x140294f70 FUN_140294f70 (size=399) ============


void FUN_140294f70(longlong param_1)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  ushort *puVar6;

  ushort *puVar7;

  uint uVar8;

  uint uVar9;

  

  uVar1 = *(uint *)(param_1 + 0x38);

  iVar2 = *(int *)(param_1 + 0x1c);

  uVar8 = ~*(uint *)(*(longlong *)(param_1 + 0x48) + 0x14);

  puVar7 = *(ushort **)(param_1 + 8);

  puVar6 = *(ushort **)(param_1 + 0x30);

  iVar3 = *(int *)(param_1 + 0x44);

  uVar9 = *(uint *)(param_1 + 0x7c) & uVar8;

  iVar5 = *(int *)(param_1 + 0x3c);

  while (iVar5 != 0) {

    iVar4 = uVar1 + 7;

    iVar4 = (int)((iVar4 >> 0x1f & 7U) + iVar4) >> 3;

    switch(uVar1 & 7) {

    case 1:

      goto switchD_140294ffc_caseD_1;

    case 2:

      goto switchD_140294ffc_caseD_2;

    case 3:

      goto switchD_140294ffc_caseD_3;

    case 4:

      goto switchD_140294ffc_caseD_4;

    case 5:

      goto switchD_140294ffc_caseD_5;

    case 6:

      goto switchD_140294ffc_caseD_6;

    case 7:

      goto switchD_140294ffc_caseD_7;

    }

    do {

      if ((*puVar7 & uVar8) != uVar9) {

        *puVar6 = *puVar7;

      }

      puVar6 = puVar6 + 1;

      puVar7 = puVar7 + 1;

switchD_140294ffc_caseD_7:

      if ((*puVar7 & uVar8) != uVar9) {

        *puVar6 = *puVar7;

      }

      puVar6 = puVar6 + 1;

      puVar7 = puVar7 + 1;

switchD_140294ffc_caseD_6:

      if ((*puVar7 & uVar8) != uVar9) {

        *puVar6 = *puVar7;

      }

      puVar6 = puVar6 + 1;

      puVar7 = puVar7 + 1;

switchD_140294ffc_caseD_5:

      if ((*puVar7 & uVar8) != uVar9) {

        *puVar6 = *puVar7;

      }

      puVar6 = puVar6 + 1;

      puVar7 = puVar7 + 1;

switchD_140294ffc_caseD_4:

      if ((*puVar7 & uVar8) != uVar9) {

        *puVar6 = *puVar7;

      }

      puVar6 = puVar6 + 1;

      puVar7 = puVar7 + 1;

switchD_140294ffc_caseD_3:

      if ((*puVar7 & uVar8) != uVar9) {

        *puVar6 = *puVar7;

      }

      puVar6 = puVar6 + 1;

      puVar7 = puVar7 + 1;

switchD_140294ffc_caseD_2:

      if ((*puVar7 & uVar8) != uVar9) {

        *puVar6 = *puVar7;

      }

      puVar6 = puVar6 + 1;

      puVar7 = puVar7 + 1;

switchD_140294ffc_caseD_1:

      if ((*puVar7 & uVar8) != uVar9) {

        *puVar6 = *puVar7;

      }

      puVar6 = puVar6 + 1;

      puVar7 = puVar7 + 1;

      iVar4 = iVar4 + -1;

    } while (0 < iVar4);

    puVar7 = puVar7 + iVar2 / 2;

    puVar6 = puVar6 + iVar3 / 2;

    iVar5 = iVar5 + -1;

  }

  return;

}




