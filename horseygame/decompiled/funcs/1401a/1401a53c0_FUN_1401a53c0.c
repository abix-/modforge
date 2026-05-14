// Address: 0x1401a53c0
// Ghidra name: FUN_1401a53c0
// ============ 0x1401a53c0 FUN_1401a53c0 (size=375) ============


void FUN_1401a53c0(ushort *param_1,int param_2)



{

  longlong lVar1;

  ushort *puVar2;

  longlong lVar3;

  ushort *puVar4;

  ushort *puVar5;

  int iVar6;

  int iVar7;

  uint uVar8;

  int iVar9;

  ulonglong uVar10;

  int iVar11;

  

  if (param_2 != 0) {

    if (param_2 == 1) {

      *param_1 = 1;

      return;

    }

    *param_1 = *param_1 + param_1[2];

    iVar9 = 1;

    iVar6 = 1;

    iVar7 = 2;

    iVar11 = 0;

    if (1 < param_2 + -1) {

      puVar5 = param_1 + 4;

      puVar2 = param_1;

      puVar4 = param_1;

      do {

        puVar4 = puVar4 + 2;

        if ((iVar7 < param_2) && (*puVar5 <= *puVar2)) {

          iVar7 = iVar7 + 1;

          *puVar4 = *puVar5;

          puVar5 = puVar5 + 2;

        }

        else {

          iVar11 = iVar11 + 1;

          *puVar4 = *puVar2;

          *puVar2 = (ushort)iVar6;

          puVar2 = puVar2 + 2;

        }

        if ((iVar7 < param_2) && ((iVar6 <= iVar11 || (*puVar5 <= *puVar2)))) {

          iVar7 = iVar7 + 1;

          *puVar4 = *puVar4 + *puVar5;

          puVar5 = puVar5 + 2;

        }

        else {

          iVar11 = iVar11 + 1;

          *puVar4 = *puVar4 + *puVar2;

          *puVar2 = (ushort)iVar6;

          puVar2 = puVar2 + 2;

        }

        iVar6 = iVar6 + 1;

      } while (iVar6 < param_2 + -1);

    }

    iVar6 = param_2 + -3;

    param_1[(longlong)(param_2 + -2) * 2] = 0;

    if (-1 < iVar6) {

      puVar5 = param_1 + (longlong)iVar6 * 2;

      do {

        iVar6 = iVar6 + -1;

        *puVar5 = param_1[(ulonglong)*puVar5 * 2] + 1;

        puVar5 = puVar5 + -2;

      } while (-1 < iVar6);

    }

    iVar6 = param_2 + -1;

    uVar8 = 0;

    lVar1 = (longlong)(param_2 + -2);

    do {

      iVar7 = 0;

      if (lVar1 < 0) {

LAB_1401a5507:

        uVar10 = (ulonglong)(uint)(iVar9 - iVar7);

        do {

          lVar3 = (longlong)iVar6;

          iVar6 = iVar6 + -1;

          param_1[lVar3 * 2] = (ushort)uVar8;

          uVar10 = uVar10 - 1;

        } while (uVar10 != 0);

      }

      else {

        do {

          if (param_1[lVar1 * 2] != uVar8) break;

          iVar7 = iVar7 + 1;

          lVar1 = lVar1 + -1;

        } while (-1 < lVar1);

        if (iVar7 < iVar9) goto LAB_1401a5507;

      }

      iVar9 = iVar7 * 2;

      uVar8 = uVar8 + 1;

    } while (0 < iVar9);

  }

  return;

}




