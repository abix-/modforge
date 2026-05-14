// Address: 0x1400479b0
// Ghidra name: FUN_1400479b0
// ============ 0x1400479b0 FUN_1400479b0 (size=800) ============


undefined8 FUN_1400479b0(undefined8 param_1,uint *param_2,uint *param_3,uint param_4)



{

  longlong lVar1;

  float *pfVar2;

  longlong lVar3;

  float *pfVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  int iVar12;

  uint uVar13;

  float *pfVar14;

  ulonglong uVar15;

  uint uVar16;

  longlong lVar18;

  longlong lVar19;

  longlong lVar20;

  longlong lVar21;

  float fVar22;

  ulonglong uVar17;

  

  iVar12 = FUN_1400485e0();

  if (iVar12 < 0) {

    return 0;

  }

  uVar16 = *param_2;

  if ((int)uVar16 < (int)param_4) {

    param_4 = uVar16;

  }

  iVar12 = uVar16 * iVar12;

  uVar15 = 0;

  uVar16 = 0;

  lVar19 = (longlong)(int)param_4;

  lVar20 = (longlong)iVar12;

  if (*(char *)((longlong)param_2 + 0x1a) == '\0') {

    if ((0 < (int)param_4) && (0xf < param_4)) {

      lVar18 = *(longlong *)(param_2 + 8);

      if ((((uint *)(lVar18 + (longlong)(int)((param_4 - 1) + iVar12) * 4) < param_3) ||

          (param_3 + (int)(param_4 - 1) < (uint *)(lVar18 + lVar20 * 4))) &&

         ((param_2 + 8 < param_3 || (uVar16 = 0, param_3 + (int)(param_4 - 1) < param_2 + 8)))) {

        uVar13 = param_4 & 0x8000000f;

        if ((int)uVar13 < 0) {

          uVar13 = (uVar13 - 1 | 0xfffffff0) + 1;

        }

        pfVar14 = (float *)(param_3 + 8);

        lVar21 = (longlong)iVar12 * 4 + 0x20;

        uVar17 = uVar15;

        do {

          uVar16 = (int)uVar17 + 0x10;

          uVar17 = (ulonglong)uVar16;

          uVar15 = uVar15 + 0x10;

          pfVar4 = (float *)(lVar21 + -0x20 + lVar18);

          fVar22 = pfVar4[1];

          fVar5 = pfVar4[2];

          fVar6 = pfVar4[3];

          pfVar2 = (float *)(lVar21 + lVar18);

          fVar7 = *pfVar2;

          fVar8 = pfVar2[1];

          fVar9 = pfVar2[2];

          fVar10 = pfVar2[3];

          pfVar14[-8] = *pfVar4 + 0.0 + pfVar14[-8];

          pfVar14[-7] = fVar22 + 0.0 + pfVar14[-7];

          pfVar14[-6] = fVar5 + 0.0 + pfVar14[-6];

          pfVar14[-5] = fVar6 + 0.0 + pfVar14[-5];

          pfVar2 = (float *)(lVar21 + -0x10 + lVar18);

          fVar22 = pfVar2[1];

          fVar5 = pfVar2[2];

          fVar6 = pfVar2[3];

          pfVar14[-4] = *pfVar2 + 0.0 + pfVar14[-4];

          pfVar14[-3] = fVar22 + 0.0 + pfVar14[-3];

          pfVar14[-2] = fVar5 + 0.0 + pfVar14[-2];

          pfVar14[-1] = fVar6 + 0.0 + pfVar14[-1];

          pfVar2 = (float *)(lVar21 + 0x10 + lVar18);

          fVar22 = *pfVar2;

          fVar5 = pfVar2[1];

          fVar6 = pfVar2[2];

          fVar11 = pfVar2[3];

          lVar21 = lVar21 + 0x40;

          *pfVar14 = fVar7 + 0.0 + *pfVar14;

          pfVar14[1] = fVar8 + 0.0 + pfVar14[1];

          pfVar14[2] = fVar9 + 0.0 + pfVar14[2];

          pfVar14[3] = fVar10 + 0.0 + pfVar14[3];

          pfVar14[4] = fVar22 + 0.0 + pfVar14[4];

          pfVar14[5] = fVar5 + 0.0 + pfVar14[5];

          pfVar14[6] = fVar6 + 0.0 + pfVar14[6];

          pfVar14[7] = fVar11 + 0.0 + pfVar14[7];

          pfVar14 = pfVar14 + 0x10;

        } while ((longlong)uVar15 < (longlong)(int)(param_4 - uVar13));

      }

    }

    lVar18 = (longlong)(int)uVar16;

    if (lVar18 < lVar19) {

      if (3 < lVar19 - lVar18) {

        pfVar14 = (float *)(param_3 + lVar18 + 2);

        lVar21 = lVar20 + lVar18;

        do {

          lVar3 = lVar20 + lVar18;

          lVar18 = lVar18 + 4;

          lVar1 = lVar21 * 4;

          lVar21 = lVar21 + 4;

          pfVar14[-2] = *(float *)(*(longlong *)(param_2 + 8) + lVar1) + 0.0 + pfVar14[-2];

          pfVar14[-1] = *(float *)(*(longlong *)(param_2 + 8) + 4 + lVar3 * 4) + 0.0 + pfVar14[-1];

          *pfVar14 = *(float *)(*(longlong *)(param_2 + 8) + 8 + lVar3 * 4) + 0.0 + *pfVar14;

          pfVar14[1] = *(float *)(*(longlong *)(param_2 + 8) + 0xc + lVar3 * 4) + 0.0 + pfVar14[1];

          pfVar14 = pfVar14 + 4;

        } while (lVar18 < lVar19 + -3);

        if (lVar19 <= lVar18) {

          return 1;

        }

      }

      do {

        param_3[lVar18] =

             (uint)(*(float *)(*(longlong *)(param_2 + 8) + (lVar20 + lVar18) * 4) + 0.0 +

                   (float)param_3[lVar18]);

        lVar18 = lVar18 + 1;

      } while (lVar18 < lVar19);

    }

  }

  else {

    fVar22 = 0.0;

    if (3 < lVar19) {

      lVar18 = lVar20 * 4;

      lVar21 = (lVar19 - 4U >> 2) + 1;

      pfVar14 = (float *)(param_3 + 2);

      uVar15 = lVar21 * 4;

      do {

        fVar22 = fVar22 + *(float *)(*(longlong *)(param_2 + 8) + lVar18);

        pfVar14[-2] = fVar22 + pfVar14[-2];

        fVar22 = fVar22 + (float)param_2[4] + *(float *)(*(longlong *)(param_2 + 8) + 4 + lVar18);

        pfVar14[-1] = fVar22 + pfVar14[-1];

        fVar22 = fVar22 + (float)param_2[4] + *(float *)(*(longlong *)(param_2 + 8) + 8 + lVar18);

        *pfVar14 = fVar22 + *pfVar14;

        fVar22 = fVar22 + (float)param_2[4] + *(float *)(*(longlong *)(param_2 + 8) + 0xc + lVar18);

        lVar18 = lVar18 + 0x10;

        pfVar14[1] = fVar22 + pfVar14[1];

        pfVar14 = pfVar14 + 4;

        fVar22 = fVar22 + (float)param_2[4];

        lVar21 = lVar21 + -1;

      } while (lVar21 != 0);

    }

    if ((longlong)uVar15 < lVar19) {

      do {

        fVar22 = fVar22 + *(float *)(*(longlong *)(param_2 + 8) + (lVar20 + uVar15) * 4);

        param_3[uVar15] = (uint)(fVar22 + (float)param_3[uVar15]);

        uVar15 = uVar15 + 1;

        fVar22 = fVar22 + (float)param_2[4];

      } while ((longlong)uVar15 < lVar19);

      return 1;

    }

  }

  return 1;

}




