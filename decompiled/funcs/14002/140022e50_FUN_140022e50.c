// Address: 0x140022e50
// Ghidra name: FUN_140022e50
// ============ 0x140022e50 FUN_140022e50 (size=801) ============


float FUN_140022e50(longlong param_1,float *param_2,int param_3,longlong param_4,float *param_5)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float *pfVar5;

  int iVar6;

  longlong lVar7;

  longlong lVar8;

  longlong lVar9;

  int iVar10;

  int iVar11;

  longlong lVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  

  lVar8 = (longlong)*(int *)(param_4 + 0x98);

  lVar9 = (longlong)param_3;

  if ((param_3 < 0) || (*(int *)(param_1 + 0x98) <= param_3)) {

    FID_conflict__assert

              (L"0 <= edge1 && edge1 < poly1->m_vertexCount",

               L"C:\\dev\\Box2d2\\Box2D\\Collision\\b2CollidePolygon.cpp",0x20);

  }

  fVar14 = *(float *)(param_1 + 0x58 + lVar9 * 8);

  iVar10 = 0;

  fVar1 = param_2[2];

  fVar2 = param_2[3];

  iVar6 = 0;

  lVar7 = 0;

  fVar3 = param_5[3];

  fVar4 = param_5[2];

  fVar19 = fVar2 * fVar14 - fVar1 * *(float *)(param_1 + 0x5c + lVar9 * 8);

  fVar18 = fVar14 * fVar1 + fVar2 * *(float *)(param_1 + 0x5c + lVar9 * 8);

  fVar16 = fVar4 * fVar18 + fVar3 * fVar19;

  fVar17 = fVar3 * fVar18 - fVar4 * fVar19;

  fVar14 = DAT_14039ca64;

  if (3 < lVar8) {

    pfVar5 = (float *)(param_4 + 0x24);

    lVar12 = (lVar8 - 4U >> 2) + 1;

    lVar7 = lVar12 * 4;

    do {

      fVar13 = fVar17 * pfVar5[-2] + fVar16 * pfVar5[-3];

      fVar15 = fVar14;

      if (fVar13 < fVar14) {

        fVar15 = fVar13;

      }

      iVar11 = iVar6;

      if (fVar14 <= fVar13) {

        iVar11 = iVar10;

      }

      fVar13 = fVar16 * pfVar5[-1] + fVar17 * *pfVar5;

      fVar14 = fVar15;

      if (fVar13 < fVar15) {

        fVar14 = fVar13;

      }

      iVar10 = iVar6 + 1;

      if (fVar15 <= fVar13) {

        iVar10 = iVar11;

      }

      fVar13 = fVar17 * pfVar5[2] + fVar16 * pfVar5[1];

      fVar15 = fVar14;

      if (fVar13 < fVar14) {

        fVar15 = fVar13;

      }

      iVar11 = iVar6 + 2;

      if (fVar14 <= fVar13) {

        iVar11 = iVar10;

      }

      fVar14 = fVar17 * pfVar5[4] + fVar16 * pfVar5[3];

      iVar10 = iVar6 + 3;

      if (fVar15 <= fVar14) {

        iVar10 = iVar11;

        fVar14 = fVar15;

      }

      iVar6 = iVar6 + 4;

      pfVar5 = pfVar5 + 8;

      lVar12 = lVar12 + -1;

    } while (lVar12 != 0);

  }

  for (; lVar7 < lVar8; lVar7 = lVar7 + 1) {

    fVar15 = fVar17 * *(float *)(param_4 + 0x1c + lVar7 * 8) +

             fVar16 * *(float *)(param_4 + 0x18 + lVar7 * 8);

    iVar11 = iVar6;

    if (fVar14 <= fVar15) {

      iVar11 = iVar10;

      fVar15 = fVar14;

    }

    iVar6 = iVar6 + 1;

    fVar14 = fVar15;

    iVar10 = iVar11;

  }

  fVar14 = *(float *)(param_1 + 0x1c + lVar9 * 8);

  fVar16 = *(float *)(param_1 + 0x18 + lVar9 * 8);

  fVar17 = *(float *)(param_4 + 0x1c + (longlong)iVar10 * 8);

  fVar15 = *(float *)(param_4 + 0x18 + (longlong)iVar10 * 8);

  return ((fVar15 * fVar4 + fVar17 * fVar3 + param_5[1]) -

         (fVar16 * fVar1 + fVar14 * fVar2 + param_2[1])) * fVar18 +

         (((fVar15 * fVar3 - fVar17 * fVar4) + *param_5) -

         ((fVar16 * fVar2 - fVar14 * fVar1) + *param_2)) * fVar19;

}




