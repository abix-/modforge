// Address: 0x14000d650
// Ghidra name: FUN_14000d650
// ============ 0x14000d650 FUN_14000d650 (size=1077) ============


float * FUN_14000d650(float *param_1,float *param_2,int param_3)



{

  float *pfVar1;

  float *pfVar2;

  float *pfVar3;

  float *pfVar4;

  float *pfVar5;

  float *pfVar6;

  float *pfVar7;

  float fVar8;

  longlong lVar9;

  float fVar10;

  float fVar11;

  float *pfVar12;

  float *pfVar13;

  float *pfVar14;

  float *pfVar15;

  float *pfVar16;

  longlong lVar17;

  longlong lVar18;

  int iVar19;

  longlong lVar20;

  int iVar21;

  float fVar22;

  float fVar23;

  float fVar24;

  float fVar25;

  float fVar26;

  float fVar27;

  float fVar28;

  float fVar29;

  float fVar30;

  float fVar31;

  

  lVar18 = (longlong)param_3;

  if (param_3 < 3) {

    FID_conflict__assert

              (L"count >= 3",L"C:\\dev\\Box2d2\\Box2D\\Collision\\Shapes\\b2PolygonShape.cpp",0x52);

  }

  fVar11 = DAT_14039ca34;

  fVar10 = DAT_14039ca30;

  lVar20 = 0;

  iVar21 = 0;

  fVar29 = 0.0;

  param_1[0] = 0.0;

  param_1[1] = 0.0;

  if (lVar18 < 4) {

    if (0 < param_3) {

      fVar31 = 0.0;

      fVar30 = 0.0;

      goto LAB_14000d962;

    }

  }

  else {

    pfVar12 = param_2 + 5;

    fVar31 = 0.0;

    fVar30 = 0.0;

    lVar17 = (lVar18 - 4U >> 2) + 1;

    iVar19 = 2;

    iVar21 = (int)lVar17 * 4;

    lVar20 = lVar17 * 4;

    do {

      pfVar1 = pfVar12 + -5;

      pfVar2 = pfVar12 + -4;

      pfVar13 = param_2;

      if (iVar19 + -1 < param_3) {

        pfVar13 = param_2 + (longlong)(iVar19 + -1) * 2;

      }

      fVar22 = ((pfVar13[1] - 0.0) * (*pfVar1 - 0.0) - (*pfVar13 - 0.0) * (*pfVar2 - 0.0)) * fVar11;

      fVar23 = fVar22 * fVar10;

      pfVar3 = pfVar12 + -3;

      pfVar4 = pfVar12 + -2;

      pfVar14 = param_2;

      if (iVar19 < param_3) {

        pfVar14 = param_2 + (longlong)iVar19 * 2;

      }

      fVar24 = ((pfVar14[1] - 0.0) * (*pfVar3 - 0.0) - (*pfVar14 - 0.0) * (*pfVar4 - 0.0)) * fVar11;

      fVar25 = fVar24 * fVar10;

      pfVar5 = pfVar12 + -1;

      fVar8 = *pfVar12;

      pfVar15 = param_2;

      if (iVar19 + 1 < param_3) {

        pfVar15 = param_2 + (longlong)(iVar19 + 1) * 2;

      }

      fVar26 = ((pfVar15[1] - 0.0) * (*pfVar5 - 0.0) - (*pfVar15 - 0.0) * (fVar8 - 0.0)) * fVar11;

      fVar27 = fVar26 * fVar10;

      pfVar6 = pfVar12 + 1;

      pfVar7 = pfVar12 + 2;

      pfVar16 = param_2;

      if (iVar19 + 2 < param_3) {

        pfVar16 = param_2 + (longlong)(iVar19 + 2) * 2;

      }

      iVar19 = iVar19 + 4;

      pfVar12 = pfVar12 + 8;

      fVar28 = ((pfVar16[1] - 0.0) * (*pfVar6 - 0.0) - (*pfVar16 - 0.0) * (*pfVar7 - 0.0)) * fVar11;

      fVar29 = fVar29 + fVar22 + fVar24 + fVar26 + fVar28;

      fVar28 = fVar28 * fVar10;

      fVar31 = (*pfVar6 + 0.0 + *pfVar16) * fVar28 +

               fVar31 + (*pfVar1 + 0.0 + *pfVar13) * fVar23 + (*pfVar3 + 0.0 + *pfVar14) * fVar25 +

               (*pfVar5 + 0.0 + *pfVar15) * fVar27;

      fVar30 = (*pfVar7 + 0.0 + pfVar16[1]) * fVar28 +

               fVar30 + (*pfVar2 + 0.0 + pfVar13[1]) * fVar23 +

               (*pfVar4 + 0.0 + pfVar14[1]) * fVar25 + (fVar8 + 0.0 + pfVar15[1]) * fVar27;

      *param_1 = fVar31;

      lVar17 = lVar17 + -1;

    } while (lVar17 != 0);

    param_1[1] = fVar30;

    if (lVar20 < lVar18) {

LAB_14000d962:

      do {

        iVar21 = iVar21 + 1;

        lVar17 = lVar20 * 2;

        lVar9 = lVar20 * 2;

        pfVar12 = param_2;

        if (iVar21 < param_3) {

          pfVar12 = param_2 + (longlong)iVar21 * 2;

        }

        lVar20 = lVar20 + 1;

        fVar22 = ((pfVar12[1] - 0.0) * (param_2[lVar17] - 0.0) -

                 (*pfVar12 - 0.0) * (param_2[lVar9 + 1] - 0.0)) * fVar11;

        fVar29 = fVar29 + fVar22;

        fVar22 = fVar22 * fVar10;

        fVar31 = (param_2[lVar17] + 0.0 + *pfVar12) * fVar22 + fVar31;

        fVar30 = (param_2[lVar9 + 1] + 0.0 + pfVar12[1]) * fVar22 + fVar30;

      } while (lVar20 < lVar18);

      *param_1 = fVar31;

      param_1[1] = fVar30;

    }

    if (DAT_14039c9f0 < fVar29) goto LAB_14000da23;

  }

  FID_conflict__assert

            (L"area > 1.192092896e-07F",

             L"C:\\dev\\Box2d2\\Box2D\\Collision\\Shapes\\b2PolygonShape.cpp",0x79);

LAB_14000da23:

  fVar29 = DAT_14039ca44 / fVar29;

  param_1[1] = fVar29 * param_1[1];

  *param_1 = fVar29 * *param_1;

  return param_1;

}




