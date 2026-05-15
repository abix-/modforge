// Address: 0x1401a6be0
// Ghidra name: FUN_1401a6be0
// ============ 0x1401a6be0 FUN_1401a6be0 (size=303) ============


void FUN_1401a6be0(longlong param_1,int param_2,int param_3)



{

  int *piVar1;

  int *piVar2;

  longlong lVar3;

  int iVar4;

  byte bVar5;

  longlong lVar6;

  int iVar7;

  int iVar8;

  byte bVar9;

  ulonglong uVar10;

  longlong lVar11;

  int iVar12;

  

  iVar12 = 0;

  lVar11 = (longlong)param_3;

  if (1 < param_2) {

    lVar6 = (longlong)(param_3 + 1);

    if (lVar6 < 0x21) {

      iVar4 = *(int *)(param_1 + lVar11 * 4);

      do {

        iVar4 = iVar4 + *(int *)(param_1 + lVar6 * 4);

        lVar6 = lVar6 + 1;

        *(int *)(param_1 + lVar11 * 4) = iVar4;

      } while (lVar6 < 0x21);

    }

    iVar7 = 0;

    iVar8 = 0;

    lVar6 = lVar11;

    iVar4 = param_3;

    if (1 < lVar11) {

      bVar9 = 0;

      iVar4 = param_3 - ((param_3 - 2U & 0xfffffffe) + 2);

      do {

        bVar5 = bVar9 + 1;

        iVar7 = iVar7 + (*(int *)(param_1 + lVar6 * 4) << (bVar9 & 0x1f));

        bVar9 = bVar9 + 2;

        lVar3 = lVar6 * 4;

        lVar6 = lVar6 + -2;

        iVar8 = iVar8 + (*(int *)(param_1 + -4 + lVar3) << (bVar5 & 0x1f));

      } while (1 < lVar6);

    }

    if (0 < lVar6) {

      iVar12 = *(int *)(param_1 + lVar6 * 4) << ((byte)param_3 - (char)iVar4 & 0x1f);

    }

    iVar12 = iVar12 + iVar8 + iVar7;

    iVar4 = 1 << ((byte)param_3 & 0x1f);

    if (iVar12 != iVar4) {

      uVar10 = (ulonglong)(uint)(iVar12 - iVar4);

      do {

        piVar2 = (int *)(param_1 + lVar11 * 4);

        *piVar2 = *piVar2 + -1;

        lVar6 = lVar11;

        do {

          lVar6 = lVar6 + -1;

          if (lVar6 < 1) goto LAB_1401a6cff;

          iVar12 = *(int *)(param_1 + lVar6 * 4);

          piVar2 = (int *)(param_1 + lVar6 * 4);

        } while (iVar12 == 0);

        piVar1 = piVar2 + 1;

        *piVar1 = *piVar1 + 2;

        *piVar2 = iVar12 + -1;

LAB_1401a6cff:

        uVar10 = uVar10 - 1;

      } while (uVar10 != 0);

    }

  }

  return;

}




