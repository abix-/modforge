// Address: 0x14013c2f0
// Ghidra name: FUN_14013c2f0
// ============ 0x14013c2f0 FUN_14013c2f0 (size=347) ============


void FUN_14013c2f0(undefined8 param_1,longlong param_2,int param_3,uint param_4)



{

  int iVar1;

  longlong lVar2;

  bool bVar3;

  int iVar4;

  char cVar5;

  int iVar6;

  int *piVar7;

  int *piVar8;

  int *piVar9;

  uint uVar10;

  int *piVar11;

  

  piVar8 = (int *)0x0;

  _guard_check_icall();

  lVar2 = *(longlong *)(*(longlong *)(param_2 + 0x38) + (longlong)param_3 * 8);

  piVar9 = piVar8;

  if (0 < *(int *)(param_2 + 0x28)) {

    piVar7 = *(int **)(param_2 + 0x30);

    piVar11 = piVar8;

    do {

      if ((*piVar7 == 2) && (param_3 == piVar7[1])) {

        iVar6 = piVar7[3];

        iVar1 = piVar7[2];

        iVar4 = iVar1;

        if (iVar1 < iVar6) {

          iVar4 = iVar6;

          iVar6 = iVar1;

        }

        if ((iVar6 <= (int)param_4) && (piVar9 = piVar7, (int)param_4 <= iVar4)) break;

      }

      uVar10 = (int)piVar11 + 1;

      piVar11 = (int *)(ulonglong)uVar10;

      piVar7 = piVar7 + 8;

      piVar9 = piVar8;

    } while ((int)uVar10 < *(int *)(param_2 + 0x28));

  }

  if (lVar2 == 0) {

LAB_14013c38e:

    if (piVar9 == (int *)0x0) goto LAB_14013c428;

  }

  else if ((piVar9 == (int *)0x0) || (cVar5 = FUN_14013c620(lVar2,piVar9), cVar5 == '\0')) {

    FUN_14013c910(param_1,param_2);

    goto LAB_14013c38e;

  }

  if (piVar9[4] == 2) {

    iVar1 = piVar9[6];

    iVar6 = piVar9[2];

    if ((iVar6 != iVar1) || (piVar9[3] != piVar9[7])) {

      param_4 = (int)(((float)(int)(param_4 - iVar6) / (float)(piVar9[3] - iVar6)) *

                     (float)(piVar9[7] - iVar1)) + iVar1;

    }

    FUN_140141cf0(param_1,param_2,piVar9[5],param_4 & 0xffff);

  }

  else {

    iVar1 = piVar9[2];

    iVar6 = (piVar9[3] - iVar1) / 2 + iVar1;

    if (piVar9[3] < iVar1) {

      bVar3 = (int)param_4 <= iVar6;

    }

    else {

      bVar3 = iVar6 <= (int)param_4;

    }

    FUN_140141d70(param_1,param_2,piVar9[5],bVar3);

  }

LAB_14013c428:

  *(int **)(*(longlong *)(param_2 + 0x38) + (longlong)param_3 * 8) = piVar9;

  return;

}




