// Address: 0x1401854d0
// Ghidra name: FUN_1401854d0
// ============ 0x1401854d0 FUN_1401854d0 (size=430) ============


undefined8 FUN_1401854d0(int *param_1,int param_2,int *param_3,int *param_4)



{

  uint uVar1;

  uint uVar2;

  int iVar3;

  int iVar4;

  bool bVar5;

  int iVar6;

  undefined8 uVar7;

  ulonglong uVar8;

  longlong lVar9;

  int iVar10;

  ulonglong uVar11;

  ulonglong uVar12;

  int iVar13;

  ulonglong uVar14;

  int iVar15;

  ulonglong uVar16;

  int iVar17;

  ulonglong uVar18;

  

  uVar8 = 0;

  if (param_1 == (int *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","points");

    return 0;

  }

  if (param_2 < 1) {

    FUN_14012e850("Parameter \'%s\' is invalid","count");

    return 0;

  }

  uVar12 = (ulonglong)param_2;

  if (param_3 == (int *)0x0) {

    if (param_4 != (int *)0x0) {

      iVar10 = *param_1;

      iVar13 = param_1[1];

      iVar17 = iVar10;

      iVar15 = iVar13;

      if (1 < uVar12) {

        lVar9 = 1;

        do {

          iVar3 = param_1[lVar9 * 2];

          iVar4 = param_1[lVar9 * 2 + 1];

          iVar6 = iVar3;

          if ((iVar10 <= iVar3) && (iVar6 = iVar10, iVar17 < iVar3)) {

            iVar17 = iVar3;

          }

          iVar10 = iVar6;

          iVar3 = iVar4;

          if ((iVar13 <= iVar4) && (iVar3 = iVar13, iVar15 < iVar4)) {

            iVar15 = iVar4;

          }

          iVar13 = iVar3;

          lVar9 = lVar9 + 1;

        } while (lVar9 < (longlong)uVar12);

      }

LAB_14018563f:

      *param_4 = iVar10;

      param_4[1] = iVar13;

      param_4[2] = (iVar17 - iVar10) + 1;

      param_4[3] = (iVar15 - iVar13) + 1;

    }

LAB_14018565a:

    uVar7 = 1;

  }

  else {

    bVar5 = false;

    if ((0 < param_3[2]) &&

       (uVar11 = uVar8, uVar14 = uVar8, uVar16 = uVar8, uVar18 = uVar8, 0 < param_3[3])) {

      do {

        uVar1 = param_1[uVar8 * 2];

        uVar2 = param_1[uVar8 * 2 + 1];

        if ((*param_3 <= (int)uVar1) &&

           ((((int)uVar1 <= *param_3 + -1 + param_3[2] && (param_3[1] <= (int)uVar2)) &&

            ((int)uVar2 <= param_3[1] + -1 + param_3[3])))) {

          if (bVar5) {

            if ((int)uVar1 < (int)uVar11) {

              uVar11 = (ulonglong)uVar1;

            }

            else if ((int)uVar18 < (int)uVar1) {

              uVar18 = (ulonglong)uVar1;

            }

            if ((int)uVar2 < (int)uVar14) {

              uVar14 = (ulonglong)uVar2;

            }

            else if ((int)uVar16 < (int)uVar2) {

              uVar16 = (ulonglong)uVar2;

            }

          }

          else {

            if (param_4 == (int *)0x0) goto LAB_14018565a;

            uVar18 = (ulonglong)uVar1;

            uVar11 = (ulonglong)uVar1;

            uVar16 = (ulonglong)uVar2;

            uVar14 = (ulonglong)uVar2;

            bVar5 = true;

          }

        }

        iVar15 = (int)uVar16;

        iVar13 = (int)uVar14;

        iVar17 = (int)uVar18;

        iVar10 = (int)uVar11;

        uVar8 = uVar8 + 1;

      } while ((longlong)uVar8 < (longlong)uVar12);

      if (bVar5) {

        if (param_4 != (int *)0x0) goto LAB_14018563f;

        goto LAB_14018565a;

      }

    }

    uVar7 = 0;

  }

  return uVar7;

}




