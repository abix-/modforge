// Address: 0x14004aa10
// Ghidra name: FUN_14004aa10
// ============ 0x14004aa10 FUN_14004aa10 (size=2423) ============


void FUN_14004aa10(longlong param_1,float *param_2,float *param_3,int param_4,float param_5,

                  float param_6,double param_7,char param_8)



{

  uint uVar1;

  longlong lVar2;

  longlong lVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  int iVar11;

  float *pfVar12;

  int iVar13;

  int iVar14;

  int iVar15;

  int iVar16;

  uint uVar17;

  uint uVar18;

  uint uVar19;

  float *pfVar20;

  longlong lVar21;

  uint uVar22;

  float fVar23;

  float fVar24;

  float fVar25;

  float fVar26;

  float fVar27;

  float fVar28;

  float fVar29;

  float fVar30;

  float fVar31;

  float fVar32;

  float fVar33;

  float fVar34;

  float fVar35;

  float local_118;

  float local_114;

  int local_10c;

  uint uStack_fc;

  uint uStack_f4;

  longlong local_e0;

  

  lVar2 = *(longlong *)(param_1 + 0x10);

  lVar3 = *(longlong *)(param_1 + 0x18);

  local_e0 = (longlong)(int)param_5;

  fVar23 = (float)param_7;

  uVar1 = *(uint *)(param_1 + 4);

  local_10c = 0;

  if (0 < local_e0) {

    pfVar20 = (float *)((longlong)param_4 * 0x10 + 8 + *(longlong *)(DAT_1403ea2a8 + 0xb8));

    lVar21 = *(longlong *)(DAT_1403ea2a8 + 0xc0) - *(longlong *)(DAT_1403ea2a8 + 0xb8);

    do {

      fVar27 = (float)local_10c;

      uVar17 = 0xffffffff;

      fVar34 = fVar27 * param_6 + fVar23;

      fVar29 = (fVar27 + DAT_14030374c) * param_6 + fVar23;

      fVar28 = (fVar27 + DAT_14039ca44) * param_6 + fVar23;

      fVar27 = (fVar27 + DAT_14030338c) * param_6 + fVar23;

      uVar19 = uVar17;

      if ((float)(int)fVar34 <= fVar34) {

        uVar19 = 0;

      }

      if ((float)(int)fVar28 <= fVar28) {

        uStack_fc = 0;

      }

      else {

        uStack_fc = 0xffffffff;

      }

      if ((float)(int)fVar29 <= fVar29) {

        uVar17 = 0;

      }

      if ((float)(int)fVar27 <= fVar27) {

        uStack_f4 = 0;

      }

      else {

        uStack_f4 = 0xffffffff;

      }

      uVar22 = (int)fVar28 - (uStack_fc & 1);

      uVar18 = (int)fVar27 - (uStack_f4 & 1);

      uVar17 = (int)fVar29 - (uVar17 & 1);

      uVar19 = (int)fVar34 - (uVar19 & 1);

      if (param_8 == '\0') {

        if (uVar19 < uVar1) {

          fVar24 = *(float *)(lVar2 + (longlong)(int)uVar19 * 4);

        }

        else {

          fVar24 = 0.0;

        }

        if (uVar22 < uVar1) {

          fVar25 = *(float *)(lVar2 + (longlong)(int)uVar22 * 4);

        }

        else {

          fVar25 = 0.0;

        }

        if (uVar17 < uVar1) {

          fVar26 = *(float *)(lVar2 + (longlong)(int)uVar17 * 4);

        }

        else {

          fVar26 = 0.0;

        }

        if (uVar18 < uVar1) {

          fVar35 = *(float *)(lVar2 + (longlong)(int)uVar18 * 4);

        }

        else {

          fVar35 = 0.0;

        }

        if (uVar19 + 1 < uVar1) {

          fVar30 = *(float *)(lVar2 + 4 + (longlong)(int)uVar19 * 4);

        }

        else {

          fVar30 = 0.0;

        }

        if (uVar22 + 1 < uVar1) {

          fVar33 = *(float *)(lVar2 + 4 + (longlong)(int)uVar22 * 4);

        }

        else {

          fVar33 = 0.0;

        }

        if (uVar17 + 1 < uVar1) {

          fVar32 = *(float *)(lVar2 + 4 + (longlong)(int)uVar17 * 4);

        }

        else {

          fVar32 = 0.0;

        }

        if (uVar18 + 1 < uVar1) {

          fVar31 = *(float *)(lVar2 + 4 + (longlong)(int)uVar18 * 4);

        }

        else {

          fVar31 = 0.0;

        }

      }

      else {

        iVar13 = (int)uVar19 % (int)uVar1;

        iVar14 = (int)uVar22 % (int)uVar1;

        iVar15 = (int)uVar17 % (int)uVar1;

        iVar16 = (int)uVar18 % (int)uVar1;

        iVar11 = iVar13 + uVar1;

        if (-1 < iVar13) {

          iVar11 = iVar13;

        }

        fVar24 = *(float *)(lVar2 + (longlong)iVar11 * 4);

        iVar11 = iVar14 + uVar1;

        if (-1 < iVar14) {

          iVar11 = iVar14;

        }

        fVar25 = *(float *)(lVar2 + (longlong)iVar11 * 4);

        iVar11 = iVar15 + uVar1;

        if (-1 < iVar15) {

          iVar11 = iVar15;

        }

        fVar26 = *(float *)(lVar2 + (longlong)iVar11 * 4);

        iVar11 = iVar16 + uVar1;

        if (-1 < iVar16) {

          iVar11 = iVar16;

        }

        fVar35 = *(float *)(lVar2 + (longlong)iVar11 * 4);

        iVar13 = (int)(uVar19 + 1) % (int)uVar1;

        iVar14 = (int)(uVar22 + 1) % (int)uVar1;

        iVar15 = (int)(uVar18 + 1) % (int)uVar1;

        iVar16 = (int)(uVar17 + 1) % (int)uVar1;

        iVar11 = iVar13 + uVar1;

        if (-1 < iVar13) {

          iVar11 = iVar13;

        }

        fVar30 = *(float *)(lVar2 + (longlong)iVar11 * 4);

        iVar11 = iVar14 + uVar1;

        if (-1 < iVar14) {

          iVar11 = iVar14;

        }

        fVar33 = *(float *)(lVar2 + (longlong)iVar11 * 4);

        iVar11 = iVar16 + uVar1;

        if (-1 < iVar16) {

          iVar11 = iVar16;

        }

        fVar32 = *(float *)(lVar2 + (longlong)iVar11 * 4);

        iVar11 = iVar15 + uVar1;

        if (-1 < iVar15) {

          iVar11 = iVar15;

        }

        fVar31 = *(float *)(lVar2 + (longlong)iVar11 * 4);

      }

      fVar24 = (fVar30 - fVar24) * (fVar34 - (float)(int)uVar19) + fVar24;

      fVar25 = (fVar33 - fVar25) * (fVar28 - (float)(int)uVar22) + fVar25;

      fVar26 = (fVar32 - fVar26) * (fVar29 - (float)(int)uVar17) + fVar26;

      fVar35 = (fVar31 - fVar35) * (fVar27 - (float)(int)uVar18) + fVar35;

      if (*(int *)(param_1 + 8) == 2) {

        if (param_8 == '\0') {

          if (uVar19 < uVar1) {

            local_114 = *(float *)(lVar3 + (longlong)(int)uVar19 * 4);

          }

          else {

            local_114 = 0.0;

          }

          if (uVar22 < uVar1) {

            local_118 = *(float *)(lVar3 + (longlong)(int)uVar22 * 4);

          }

          else {

            local_118 = 0.0;

          }

          if (uVar17 < uVar1) {

            param_7._0_4_ = *(float *)(lVar3 + (longlong)(int)uVar17 * 4);

          }

          else {

            param_7._0_4_ = 0.0;

          }

          if (uVar18 < uVar1) {

            param_5 = *(float *)(lVar3 + (longlong)(int)uVar18 * 4);

          }

          else {

            param_5 = 0.0;

          }

          if (uVar19 + 1 < uVar1) {

            fVar30 = *(float *)(lVar3 + 4 + (longlong)(int)uVar19 * 4);

          }

          else {

            fVar30 = 0.0;

          }

          if (uVar22 + 1 < uVar1) {

            fVar33 = *(float *)(lVar3 + 4 + (longlong)(int)uVar22 * 4);

          }

          else {

            fVar33 = 0.0;

          }

          if (uVar17 + 1 < uVar1) {

            fVar32 = *(float *)(lVar3 + 4 + (longlong)(int)uVar17 * 4);

          }

          else {

            fVar32 = 0.0;

          }

          if (uVar18 + 1 < uVar1) {

            fVar31 = *(float *)(lVar3 + 4 + (longlong)(int)uVar18 * 4);

          }

          else {

            fVar31 = 0.0;

          }

        }

        else {

          iVar13 = (int)uVar19 % (int)uVar1;

          iVar14 = (int)uVar22 % (int)uVar1;

          iVar15 = (int)uVar17 % (int)uVar1;

          iVar16 = (int)uVar18 % (int)uVar1;

          iVar11 = iVar13 + uVar1;

          if (-1 < iVar13) {

            iVar11 = iVar13;

          }

          local_114 = *(float *)(lVar3 + (longlong)iVar11 * 4);

          iVar11 = iVar14 + uVar1;

          if (-1 < iVar14) {

            iVar11 = iVar14;

          }

          iVar13 = iVar15 + uVar1;

          if (-1 < iVar15) {

            iVar13 = iVar15;

          }

          local_118 = *(float *)(lVar3 + (longlong)iVar11 * 4);

          param_7._0_4_ = *(float *)(lVar3 + (longlong)iVar13 * 4);

          iVar11 = iVar16 + uVar1;

          if (-1 < iVar16) {

            iVar11 = iVar16;

          }

          iVar13 = (int)(uVar19 + 1) % (int)uVar1;

          param_5 = *(float *)(lVar3 + (longlong)iVar11 * 4);

          iVar14 = (int)(uVar22 + 1) % (int)uVar1;

          iVar15 = (int)(uVar17 + 1) % (int)uVar1;

          iVar16 = (int)(uVar18 + 1) % (int)uVar1;

          iVar11 = iVar13 + uVar1;

          if (-1 < iVar13) {

            iVar11 = iVar13;

          }

          fVar30 = *(float *)(lVar3 + (longlong)iVar11 * 4);

          iVar11 = iVar14 + uVar1;

          if (-1 < iVar14) {

            iVar11 = iVar14;

          }

          fVar33 = *(float *)(lVar3 + (longlong)iVar11 * 4);

          iVar11 = iVar15 + uVar1;

          if (-1 < iVar15) {

            iVar11 = iVar15;

          }

          fVar32 = *(float *)(lVar3 + (longlong)iVar11 * 4);

          iVar11 = iVar16 + uVar1;

          if (-1 < iVar16) {

            iVar11 = iVar16;

          }

          fVar31 = *(float *)(lVar3 + (longlong)iVar11 * 4);

        }

        fVar4 = param_2[1];

        fVar5 = param_2[2];

        fVar6 = param_2[3];

        fVar7 = *param_3;

        fVar8 = param_3[1];

        fVar9 = param_3[2];

        fVar10 = param_3[3];

        pfVar12 = (float *)((longlong)pfVar20 + lVar21);

        pfVar20[-2] = *param_2 * fVar24 + pfVar20[-2];

        pfVar20[-1] = fVar4 * fVar25 + pfVar20[-1];

        *pfVar20 = fVar5 * fVar26 + *pfVar20;

        pfVar20[1] = fVar6 * fVar35 + pfVar20[1];

        fVar24 = ((fVar30 - local_114) * (fVar34 - (float)(int)uVar19) + local_114) * fVar7 +

                 pfVar12[-2];

        fVar27 = ((fVar31 - param_5) * (fVar27 - (float)(int)uVar18) + param_5) * fVar10 +

                 pfVar12[1];

        fVar29 = ((fVar32 - param_7._0_4_) * (fVar29 - (float)(int)uVar17) + param_7._0_4_) * fVar9

                 + *pfVar12;

        fVar28 = ((fVar33 - local_118) * (fVar28 - (float)(int)uVar22) + local_118) * fVar8 +

                 pfVar12[-1];

      }

      else {

        fVar27 = *param_3;

        fVar28 = param_3[1];

        fVar29 = param_3[2];

        fVar34 = param_3[3];

        fVar30 = param_2[1];

        fVar33 = param_2[2];

        fVar32 = param_2[3];

        pfVar12 = (float *)((longlong)pfVar20 + lVar21);

        pfVar20[-2] = *param_2 * fVar24 + pfVar20[-2];

        pfVar20[-1] = fVar30 * fVar25 + pfVar20[-1];

        *pfVar20 = fVar33 * fVar26 + *pfVar20;

        pfVar20[1] = fVar32 * fVar35 + pfVar20[1];

        fVar24 = fVar27 * fVar24 + pfVar12[-2];

        fVar27 = fVar34 * fVar35 + pfVar12[1];

        fVar29 = fVar29 * fVar26 + *pfVar12;

        fVar28 = fVar28 * fVar25 + pfVar12[-1];

      }

      pfVar12 = (float *)((longlong)pfVar20 + lVar21);

      pfVar20 = pfVar20 + 4;

      pfVar12[-2] = fVar24;

      local_10c = local_10c + 4;

      local_e0 = local_e0 + -1;

      pfVar12[-1] = fVar28;

      *pfVar12 = fVar29;

      pfVar12[1] = fVar27;

    } while (local_e0 != 0);

  }

  return;

}




