// Address: 0x1401851d0
// Ghidra name: FUN_1401851d0
// ============ 0x1401851d0 FUN_1401851d0 (size=755) ============


undefined8 FUN_1401851d0(float *param_1,int param_2,float *param_3,float *param_4)



{

  bool bVar1;

  longlong lVar2;

  float *pfVar3;

  longlong lVar4;

  ulonglong uVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  

  if (param_1 == (float *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","points");

    return 0;

  }

  if (param_2 < 1) {

    FUN_14012e850("Parameter \'%s\' is invalid","count");

    return 0;

  }

  uVar5 = (ulonglong)param_2;

  if (param_3 == (float *)0x0) {

    if (param_4 == (float *)0x0) {

      return 1;

    }

    fVar11 = *param_1;

    fVar8 = param_1[1];

    fVar13 = fVar8;

    fVar16 = fVar11;

    if (1 < uVar5) {

      lVar2 = 1;

      if (4 < uVar5) {

        pfVar3 = param_1 + 4;

        lVar4 = (uVar5 - 5 >> 2) + 1;

        lVar2 = lVar4 * 4 + 1;

        do {

          fVar7 = pfVar3[-2];

          fVar6 = pfVar3[-1];

          fVar9 = fVar7;

          fVar14 = fVar16;

          if ((fVar11 <= fVar7) && (fVar9 = fVar11, fVar14 = fVar7, fVar7 <= fVar16)) {

            fVar14 = fVar16;

          }

          fVar7 = fVar6;

          fVar10 = fVar13;

          if ((fVar8 <= fVar6) && (fVar7 = fVar8, fVar10 = fVar6, fVar6 <= fVar13)) {

            fVar10 = fVar13;

          }

          fVar6 = *pfVar3;

          fVar15 = pfVar3[1];

          fVar11 = fVar6;

          fVar8 = fVar14;

          if ((fVar9 <= fVar6) && (fVar11 = fVar9, fVar8 = fVar6, fVar6 <= fVar14)) {

            fVar8 = fVar14;

          }

          fVar6 = fVar15;

          fVar9 = fVar10;

          if ((fVar7 <= fVar15) && (fVar6 = fVar7, fVar9 = fVar15, fVar15 <= fVar10)) {

            fVar9 = fVar10;

          }

          fVar7 = pfVar3[2];

          fVar14 = pfVar3[3];

          fVar10 = fVar7;

          fVar15 = fVar8;

          if ((fVar11 <= fVar7) && (fVar10 = fVar11, fVar15 = fVar7, fVar7 <= fVar8)) {

            fVar15 = fVar8;

          }

          fVar7 = fVar14;

          fVar12 = fVar9;

          if ((fVar6 <= fVar14) && (fVar7 = fVar6, fVar12 = fVar14, fVar14 <= fVar9)) {

            fVar12 = fVar9;

          }

          fVar6 = pfVar3[4];

          fVar9 = pfVar3[5];

          fVar11 = fVar6;

          fVar16 = fVar15;

          if ((fVar10 <= fVar6) && (fVar11 = fVar10, fVar16 = fVar6, fVar6 <= fVar15)) {

            fVar16 = fVar15;

          }

          fVar8 = fVar9;

          fVar13 = fVar12;

          if ((fVar7 <= fVar9) && (fVar8 = fVar7, fVar13 = fVar9, fVar9 <= fVar12)) {

            fVar13 = fVar12;

          }

          pfVar3 = pfVar3 + 8;

          lVar4 = lVar4 + -1;

        } while (lVar4 != 0);

        if ((longlong)uVar5 <= lVar2) goto LAB_140185477;

      }

      do {

        fVar7 = param_1[lVar2 * 2];

        fVar6 = param_1[lVar2 * 2 + 1];

        fVar9 = fVar7;

        fVar14 = fVar16;

        if ((fVar11 <= fVar7) && (fVar9 = fVar11, fVar14 = fVar7, fVar7 <= fVar16)) {

          fVar14 = fVar16;

        }

        fVar16 = fVar14;

        fVar11 = fVar9;

        fVar7 = fVar6;

        fVar9 = fVar13;

        if ((fVar8 <= fVar6) && (fVar7 = fVar8, fVar9 = fVar6, fVar6 <= fVar13)) {

          fVar9 = fVar13;

        }

        fVar13 = fVar9;

        fVar8 = fVar7;

        lVar2 = lVar2 + 1;

      } while (lVar2 < (longlong)uVar5);

    }

  }

  else {

    bVar1 = false;

    if ((param_3[2] < 0.0) || (param_3[3] < 0.0)) {

      return 0;

    }

    lVar2 = 0;

    fVar7 = 0.0;

    fVar6 = 0.0;

    fVar9 = 0.0;

    fVar14 = 0.0;

    do {

      fVar10 = param_1[lVar2 * 2];

      fVar15 = param_1[lVar2 * 2 + 1];

      fVar8 = fVar7;

      fVar11 = fVar6;

      fVar13 = fVar9;

      fVar16 = fVar14;

      if ((((*param_3 <= fVar10) && (fVar10 <= (param_3[2] + *param_3) - 0.0)) &&

          (param_3[1] <= fVar15)) && (fVar15 <= (param_3[3] + param_3[1]) - 0.0)) {

        fVar8 = fVar15;

        fVar11 = fVar10;

        if (bVar1) {

          if ((fVar6 <= fVar10) && (fVar11 = fVar6, fVar16 = fVar10, fVar10 <= fVar14)) {

            fVar16 = fVar14;

          }

          if ((fVar7 <= fVar15) && (fVar8 = fVar7, fVar13 = fVar15, fVar15 <= fVar9)) {

            fVar13 = fVar9;

          }

        }

        else {

          if (param_4 == (float *)0x0) {

            return 1;

          }

          bVar1 = true;

          fVar13 = fVar15;

          fVar16 = fVar10;

        }

      }

      lVar2 = lVar2 + 1;

      fVar7 = fVar8;

      fVar6 = fVar11;

      fVar9 = fVar13;

      fVar14 = fVar16;

    } while (lVar2 < (longlong)uVar5);

    if (!bVar1) {

      return 0;

    }

    if (param_4 == (float *)0x0) {

      return 1;

    }

  }

LAB_140185477:

  *param_4 = fVar11;

  param_4[1] = fVar8;

  param_4[2] = (fVar16 - fVar11) + 0.0;

  param_4[3] = (fVar13 - fVar8) + 0.0;

  return 1;

}




