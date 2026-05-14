// Address: 0x1400234e0
// Ghidra name: FUN_1400234e0
// ============ 0x1400234e0 FUN_1400234e0 (size=737) ============


void FUN_1400234e0(float *param_1,longlong param_2,longlong param_3,int param_4,longlong param_5,

                  float *param_6)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  float *pfVar6;

  int iVar7;

  int iVar8;

  longlong lVar9;

  longlong lVar10;

  longlong lVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  

  iVar4 = *(int *)(param_5 + 0x98);

  lVar11 = (longlong)iVar4;

  lVar9 = (longlong)param_4;

  if ((param_4 < 0) || (*(int *)(param_2 + 0x98) <= param_4)) {

    FID_conflict__assert

              (L"0 <= edge1 && edge1 < poly1->m_vertexCount",

               L"C:\\dev\\Box2d2\\Box2D\\Collision\\b2CollidePolygon.cpp",0x97);

  }

  iVar8 = 0;

  iVar7 = 0;

  fVar16 = *(float *)(param_2 + 0x58 + lVar9 * 8);

  lVar10 = 0;

  fVar1 = param_6[3];

  fVar15 = *(float *)(param_3 + 0xc) * fVar16 -

           *(float *)(param_3 + 8) * *(float *)(param_2 + 0x5c + lVar9 * 8);

  fVar2 = param_6[2];

  fVar16 = fVar16 * *(float *)(param_3 + 8) +

           *(float *)(param_3 + 0xc) * *(float *)(param_2 + 0x5c + lVar9 * 8);

  fVar14 = fVar2 * fVar16 + fVar1 * fVar15;

  fVar15 = fVar1 * fVar16 - fVar2 * fVar15;

  fVar16 = DAT_14039ca64;

  if (3 < lVar11) {

    pfVar6 = (float *)(param_5 + 100);

    lVar9 = (lVar11 - 4U >> 2) + 1;

    lVar10 = lVar9 * 4;

    do {

      fVar12 = fVar15 * pfVar6[-2] + fVar14 * pfVar6[-3];

      fVar13 = fVar16;

      if (fVar12 < fVar16) {

        fVar13 = fVar12;

      }

      iVar5 = iVar7;

      if (fVar16 <= fVar12) {

        iVar5 = iVar8;

      }

      fVar12 = fVar14 * pfVar6[-1] + fVar15 * *pfVar6;

      fVar16 = fVar13;

      if (fVar12 < fVar13) {

        fVar16 = fVar12;

      }

      iVar8 = iVar7 + 1;

      if (fVar13 <= fVar12) {

        iVar8 = iVar5;

      }

      fVar12 = fVar15 * pfVar6[2] + fVar14 * pfVar6[1];

      fVar13 = fVar16;

      if (fVar12 < fVar16) {

        fVar13 = fVar12;

      }

      iVar5 = iVar7 + 2;

      if (fVar16 <= fVar12) {

        iVar5 = iVar8;

      }

      fVar16 = fVar15 * pfVar6[4] + fVar14 * pfVar6[3];

      iVar8 = iVar7 + 3;

      if (fVar13 <= fVar16) {

        iVar8 = iVar5;

        fVar16 = fVar13;

      }

      iVar7 = iVar7 + 4;

      pfVar6 = pfVar6 + 8;

      lVar9 = lVar9 + -1;

    } while (lVar9 != 0);

  }

  for (; lVar10 < lVar11; lVar10 = lVar10 + 1) {

    fVar13 = fVar15 * *(float *)(param_5 + 0x5c + lVar10 * 8) +

             fVar14 * *(float *)(param_5 + 0x58 + lVar10 * 8);

    iVar5 = iVar7;

    if (fVar16 <= fVar13) {

      iVar5 = iVar8;

      fVar13 = fVar16;

    }

    iVar7 = iVar7 + 1;

    fVar16 = fVar13;

    iVar8 = iVar5;

  }

  lVar9 = (longlong)iVar8;

  iVar7 = iVar8 + 1;

  fVar16 = *(float *)(param_5 + 0x18 + lVar9 * 8);

  if (iVar4 <= iVar7) {

    iVar7 = 0;

  }

  fVar14 = *(float *)(param_5 + 0x1c + lVar9 * 8);

  fVar15 = *(float *)(param_5 + 0x18 + lVar9 * 8);

  fVar13 = *(float *)(param_5 + 0x1c + lVar9 * 8);

  lVar9 = (longlong)iVar7;

  fVar12 = param_6[1];

  fVar3 = *param_6;

  *(char *)(param_1 + 2) = (char)param_4;

  param_1[1] = fVar2 * fVar16 + fVar1 * fVar14 + fVar12;

  *(char *)((longlong)param_1 + 9) = (char)iVar8;

  *(undefined2 *)((longlong)param_1 + 10) = 1;

  *param_1 = (fVar1 * fVar15 - fVar2 * fVar13) + fVar3;

  fVar16 = param_6[2];

  fVar1 = param_6[3];

  fVar2 = *(float *)(param_5 + 0x18 + lVar9 * 8);

  fVar14 = *(float *)(param_5 + 0x18 + lVar9 * 8);

  fVar15 = *(float *)(param_5 + 0x1c + lVar9 * 8);

  fVar13 = *(float *)(param_5 + 0x1c + lVar9 * 8);

  fVar12 = param_6[1];

  fVar3 = *param_6;

  *(char *)(param_1 + 5) = (char)param_4;

  param_1[4] = fVar16 * fVar2 + fVar1 * fVar15 + fVar12;

  *(char *)((longlong)param_1 + 0x15) = (char)iVar7;

  param_1[3] = (fVar1 * fVar14 - fVar16 * fVar13) + fVar3;

  *(undefined2 *)((longlong)param_1 + 0x16) = 1;

  return;

}




