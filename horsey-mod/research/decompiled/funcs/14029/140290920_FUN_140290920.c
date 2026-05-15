// Address: 0x140290920
// Ghidra name: FUN_140290920
// ============ 0x140290920 FUN_140290920 (size=578) ============


void FUN_140290920(longlong param_1)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  longlong lVar5;

  int iVar6;

  int iVar7;

  byte *pbVar8;

  byte *pbVar9;

  

  lVar5 = *(longlong *)(param_1 + 0x68);

  uVar1 = *(uint *)(param_1 + 0x38);

  iVar7 = *(int *)(param_1 + 0x3c);

  pbVar9 = *(byte **)(param_1 + 8);

  iVar2 = *(int *)(param_1 + 0x1c);

  pbVar8 = *(byte **)(param_1 + 0x30);

  iVar3 = *(int *)(param_1 + 0x44);

  uVar4 = *(uint *)(param_1 + 0x7c);

  if (lVar5 == 0) {

    while (iVar7 != 0) {

      iVar6 = (int)(((int)(uVar1 + 7) >> 0x1f & 7U) + uVar1 + 7) >> 3;

      switch(uVar1 & 7) {

      case 1:

        goto switchD_140290a9f_caseD_1;

      case 2:

        goto switchD_140290a9f_caseD_2;

      case 3:

        goto switchD_140290a9f_caseD_3;

      case 4:

        goto switchD_140290a9f_caseD_4;

      case 5:

        goto switchD_140290a9f_caseD_5;

      case 6:

        goto switchD_140290a9f_caseD_6;

      case 7:

        goto switchD_140290a9f_caseD_7;

      }

      do {

        if (*pbVar9 != uVar4) {

          *pbVar8 = *pbVar9;

        }

        pbVar8 = pbVar8 + 1;

        pbVar9 = pbVar9 + 1;

switchD_140290a9f_caseD_7:

        if (*pbVar9 != uVar4) {

          *pbVar8 = *pbVar9;

        }

        pbVar8 = pbVar8 + 1;

        pbVar9 = pbVar9 + 1;

switchD_140290a9f_caseD_6:

        if (*pbVar9 != uVar4) {

          *pbVar8 = *pbVar9;

        }

        pbVar8 = pbVar8 + 1;

        pbVar9 = pbVar9 + 1;

switchD_140290a9f_caseD_5:

        if (*pbVar9 != uVar4) {

          *pbVar8 = *pbVar9;

        }

        pbVar8 = pbVar8 + 1;

        pbVar9 = pbVar9 + 1;

switchD_140290a9f_caseD_4:

        if (*pbVar9 != uVar4) {

          *pbVar8 = *pbVar9;

        }

        pbVar8 = pbVar8 + 1;

        pbVar9 = pbVar9 + 1;

switchD_140290a9f_caseD_3:

        if (*pbVar9 != uVar4) {

          *pbVar8 = *pbVar9;

        }

        pbVar8 = pbVar8 + 1;

        pbVar9 = pbVar9 + 1;

switchD_140290a9f_caseD_2:

        if (*pbVar9 != uVar4) {

          *pbVar8 = *pbVar9;

        }

        pbVar8 = pbVar8 + 1;

        pbVar9 = pbVar9 + 1;

switchD_140290a9f_caseD_1:

        if (*pbVar9 != uVar4) {

          *pbVar8 = *pbVar9;

        }

        pbVar8 = pbVar8 + 1;

        pbVar9 = pbVar9 + 1;

        iVar6 = iVar6 + -1;

      } while (0 < iVar6);

      pbVar9 = pbVar9 + iVar2;

      pbVar8 = pbVar8 + iVar3;

      iVar7 = iVar7 + -1;

    }

  }

  else {

    while (iVar7 != 0) {

      iVar6 = (int)(((int)(uVar1 + 7) >> 0x1f & 7U) + uVar1 + 7) >> 3;

      switch(uVar1 & 7) {

      case 0:

        do {

          if (*pbVar9 != uVar4) {

            *pbVar8 = *(byte *)((ulonglong)*pbVar9 + lVar5);

          }

          pbVar8 = pbVar8 + 1;

          pbVar9 = pbVar9 + 1;

switchD_14029099b_caseD_7:

          if (*pbVar9 != uVar4) {

            *pbVar8 = *(byte *)((ulonglong)*pbVar9 + lVar5);

          }

          pbVar8 = pbVar8 + 1;

          pbVar9 = pbVar9 + 1;

switchD_14029099b_caseD_6:

          if (*pbVar9 != uVar4) {

            *pbVar8 = *(byte *)((ulonglong)*pbVar9 + lVar5);

          }

          pbVar8 = pbVar8 + 1;

          pbVar9 = pbVar9 + 1;

switchD_14029099b_caseD_5:

          if (*pbVar9 != uVar4) {

            *pbVar8 = *(byte *)((ulonglong)*pbVar9 + lVar5);

          }

          pbVar8 = pbVar8 + 1;

          pbVar9 = pbVar9 + 1;

switchD_14029099b_caseD_4:

          if (*pbVar9 != uVar4) {

            *pbVar8 = *(byte *)((ulonglong)*pbVar9 + lVar5);

          }

          pbVar8 = pbVar8 + 1;

          pbVar9 = pbVar9 + 1;

switchD_14029099b_caseD_3:

          if (*pbVar9 != uVar4) {

            *pbVar8 = *(byte *)((ulonglong)*pbVar9 + lVar5);

          }

          pbVar8 = pbVar8 + 1;

          pbVar9 = pbVar9 + 1;

switchD_14029099b_caseD_2:

          if (*pbVar9 != uVar4) {

            *pbVar8 = *(byte *)((ulonglong)*pbVar9 + lVar5);

          }

          pbVar8 = pbVar8 + 1;

          pbVar9 = pbVar9 + 1;

switchD_14029099b_caseD_1:

          if (*pbVar9 != uVar4) {

            *pbVar8 = *(byte *)((ulonglong)*pbVar9 + lVar5);

          }

          pbVar8 = pbVar8 + 1;

          pbVar9 = pbVar9 + 1;

          iVar6 = iVar6 + -1;

        } while (0 < iVar6);

        break;

      case 1:

        goto switchD_14029099b_caseD_1;

      case 2:

        goto switchD_14029099b_caseD_2;

      case 3:

        goto switchD_14029099b_caseD_3;

      case 4:

        goto switchD_14029099b_caseD_4;

      case 5:

        goto switchD_14029099b_caseD_5;

      case 6:

        goto switchD_14029099b_caseD_6;

      case 7:

        goto switchD_14029099b_caseD_7;

      }

      pbVar9 = pbVar9 + iVar2;

      pbVar8 = pbVar8 + iVar3;

      iVar7 = iVar7 + -1;

    }

  }

  return;

}




