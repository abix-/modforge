// Address: 0x140163e70
// Ghidra name: FUN_140163e70
// ============ 0x140163e70 FUN_140163e70 (size=1485) ============


void FUN_140163e70(int param_1,ulonglong param_2,uint param_3,int param_4,longlong param_5,

                  ulonglong param_6,uint param_7,int param_8,longlong param_9,ulonglong param_10,

                  float param_11)



{

  longlong lVar1;

  float *pfVar2;

  float *pfVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  char cVar12;

  uint uVar13;

  float *pfVar14;

  uint uVar15;

  ulonglong uVar16;

  longlong lVar18;

  longlong lVar19;

  uint uVar20;

  code *pcVar21;

  ulonglong uVar22;

  code *pcVar23;

  longlong lVar24;

  longlong lVar25;

  code *pcVar17;

  

  if (param_1 == 0) {

    return;

  }

  pcVar21 = (code *)0x0;

  if ((param_4 == param_8) && (cVar12 = FUN_14015d510(param_4,param_5,param_9), cVar12 != '\0')) {

    param_9 = 0;

LAB_140163fa6:

    if (param_11 == DAT_14039ca44) {

      if (param_3 == param_7) {

        if (param_9 == 0) {

          if (param_2 == param_6) {

            return;

          }

          FUN_1402f8e20(param_6,param_2,(longlong)(int)(((param_7 & 0xff) >> 3) * param_1 * param_8)

                       );

          return;

        }

        goto LAB_1401643fa;

      }

      if ((param_3 ^ param_7) == 0x1000) {

        if (param_9 != 0) {

          FUN_140168840(param_1,param_6,param_2,param_8,param_9,param_7);

          param_2 = param_6;

        }

        FUN_140211280(param_6,param_2,param_1 * param_8,param_7 & 0xff);

        return;

      }

    }

  }

  else {

    if (param_5 != 0) {

      uVar16 = param_6;

      if (param_10 != 0) {

        uVar16 = param_10;

      }

      FUN_140168840(param_1,uVar16,param_2,param_4,param_5,param_3);

      param_2 = uVar16;

    }

    if (param_4 == param_8) goto LAB_140163fa6;

  }

  uVar16 = param_6;

  if (param_10 != 0) {

    uVar16 = param_10;

  }

  if (param_3 != 0x8120) {

    if ((param_4 != param_8) || (uVar22 = param_6, param_7 != 0x8120)) {

      uVar22 = uVar16;

    }

    FUN_1402112a0(uVar22,param_2,param_1 * param_4,param_3);

    param_2 = uVar22;

  }

  uVar20 = param_1 * param_4;

  uVar22 = param_2;

  if (param_11 != DAT_14039ca44) {

    if ((param_4 != param_8) || (uVar22 = param_6, param_7 != 0x8120)) {

      uVar22 = uVar16;

    }

    lVar19 = (longlong)(int)uVar20;

    uVar15 = 0;

    if (param_2 == uVar22) {

      if ((0 < (int)uVar20) && (0xf < uVar20)) {

        uVar13 = uVar20 & 0x8000000f;

        if ((int)uVar13 < 0) {

          uVar13 = (uVar13 - 1 | 0xfffffff0) + 1;

        }

        pfVar14 = (float *)(uVar22 + 0x20);

        pcVar17 = pcVar21;

        pcVar23 = pcVar21;

        do {

          uVar15 = (int)pcVar17 + 0x10;

          pcVar17 = (code *)(ulonglong)uVar15;

          pcVar23 = pcVar23 + 0x10;

          pfVar14[-8] = pfVar14[-8] * param_11;

          pfVar14[-7] = pfVar14[-7] * param_11;

          pfVar14[-6] = pfVar14[-6] * param_11;

          pfVar14[-5] = pfVar14[-5] * param_11;

          pfVar14[-4] = param_11 * pfVar14[-4];

          pfVar14[-3] = param_11 * pfVar14[-3];

          pfVar14[-2] = param_11 * pfVar14[-2];

          pfVar14[-1] = param_11 * pfVar14[-1];

          *pfVar14 = param_11 * *pfVar14;

          pfVar14[1] = param_11 * pfVar14[1];

          pfVar14[2] = param_11 * pfVar14[2];

          pfVar14[3] = param_11 * pfVar14[3];

          pfVar14[4] = pfVar14[4] * param_11;

          pfVar14[5] = pfVar14[5] * param_11;

          pfVar14[6] = pfVar14[6] * param_11;

          pfVar14[7] = pfVar14[7] * param_11;

          pfVar14 = pfVar14 + 0x10;

        } while ((longlong)pcVar23 < (longlong)(int)(uVar20 - uVar13));

      }

      lVar18 = (longlong)(int)uVar15;

      if (lVar18 < lVar19) {

        if (3 < lVar19 - lVar18) {

          lVar1 = lVar18 + 2;

          lVar24 = ((lVar19 - lVar18) - 4U >> 2) + 1;

          lVar18 = lVar18 + lVar24 * 4;

          pfVar14 = (float *)(uVar22 + lVar1 * 4);

          do {

            pfVar14[-2] = param_11 * pfVar14[-2];

            pfVar14[-1] = param_11 * pfVar14[-1];

            *pfVar14 = param_11 * *pfVar14;

            pfVar14[1] = param_11 * pfVar14[1];

            lVar24 = lVar24 + -1;

            pfVar14 = pfVar14 + 4;

          } while (lVar24 != 0);

          if (lVar19 <= lVar18) goto LAB_140164344;

        }

        do {

          *(float *)(uVar22 + lVar18 * 4) = param_11 * *(float *)(uVar22 + lVar18 * 4);

          lVar18 = lVar18 + 1;

        } while (lVar18 < lVar19);

      }

    }

    else {

      if (((0 < (int)uVar20) && (0xf < uVar20)) &&

         ((param_2 + (longlong)(int)(uVar20 - 1) * 4 < uVar22 ||

          (uVar22 + (longlong)(int)(uVar20 - 1) * 4 < param_2)))) {

        uVar13 = uVar20 & 0x8000000f;

        if ((int)uVar13 < 0) {

          uVar13 = (uVar13 - 1 | 0xfffffff0) + 1;

        }

        lVar18 = param_2 - uVar22;

        pfVar14 = (float *)(uVar22 + 0x10);

        pcVar17 = pcVar21;

        pcVar23 = pcVar21;

        do {

          pfVar3 = (float *)((longlong)pfVar14 + lVar18 + -0x10);

          fVar4 = pfVar3[1];

          fVar5 = pfVar3[2];

          fVar6 = pfVar3[3];

          uVar15 = (int)pcVar17 + 0x10;

          pcVar17 = (code *)(ulonglong)uVar15;

          pcVar23 = pcVar23 + 0x10;

          pfVar2 = (float *)((longlong)pfVar14 + lVar18);

          fVar7 = *pfVar2;

          fVar8 = pfVar2[1];

          fVar9 = pfVar2[2];

          fVar10 = pfVar2[3];

          pfVar14[-4] = *pfVar3 * param_11;

          pfVar14[-3] = fVar4 * param_11;

          pfVar14[-2] = fVar5 * param_11;

          pfVar14[-1] = fVar6 * param_11;

          pfVar2 = (float *)((longlong)pfVar14 + lVar18 + 0x10);

          fVar4 = *pfVar2;

          fVar5 = pfVar2[1];

          fVar6 = pfVar2[2];

          fVar11 = pfVar2[3];

          *pfVar14 = fVar7 * param_11;

          pfVar14[1] = fVar8 * param_11;

          pfVar14[2] = fVar9 * param_11;

          pfVar14[3] = fVar10 * param_11;

          pfVar2 = (float *)((longlong)pfVar14 + lVar18 + 0x20);

          fVar7 = *pfVar2;

          fVar8 = pfVar2[1];

          fVar9 = pfVar2[2];

          fVar10 = pfVar2[3];

          pfVar14[4] = fVar4 * param_11;

          pfVar14[5] = fVar5 * param_11;

          pfVar14[6] = fVar6 * param_11;

          pfVar14[7] = fVar11 * param_11;

          pfVar14[8] = fVar7 * param_11;

          pfVar14[9] = fVar8 * param_11;

          pfVar14[10] = fVar9 * param_11;

          pfVar14[0xb] = fVar10 * param_11;

          pfVar14 = pfVar14 + 0x10;

        } while ((longlong)pcVar23 < (longlong)(int)(uVar20 - uVar13));

      }

      lVar18 = (longlong)(int)uVar15;

      if (lVar18 < lVar19) {

        if (3 < lVar19 - lVar18) {

          lVar1 = lVar18 + 1;

          lVar24 = param_2 - uVar22;

          lVar25 = ((lVar19 - lVar18) - 4U >> 2) + 1;

          lVar18 = lVar18 + lVar25 * 4;

          pfVar14 = (float *)(uVar22 + lVar1 * 4);

          do {

            pfVar2 = pfVar14 + 4;

            pfVar14[-1] = param_11 * *(float *)(lVar24 + -0x14 + (longlong)pfVar2);

            *pfVar14 = param_11 * *(float *)(lVar24 + -0x10 + (longlong)pfVar2);

            pfVar14[1] = param_11 * *(float *)(lVar24 + -0xc + (longlong)pfVar2);

            pfVar14[2] = param_11 * *(float *)(lVar24 + -8 + (longlong)pfVar2);

            lVar25 = lVar25 + -1;

            pfVar14 = pfVar2;

          } while (lVar25 != 0);

          if (lVar19 <= lVar18) goto LAB_140164344;

        }

        lVar19 = lVar19 - lVar18;

        pfVar14 = (float *)(uVar22 + lVar18 * 4);

        do {

          *pfVar14 = param_11 * *(float *)((param_2 - uVar22) + -4 + (longlong)(pfVar14 + 1));

          lVar19 = lVar19 + -1;

          pfVar14 = pfVar14 + 1;

        } while (lVar19 != 0);

      }

    }

  }

LAB_140164344:

  param_2 = uVar22;

  if (param_4 != param_8) {

    pcVar17 = *(code **)("SDL.thread.create.userdata" +

                        ((longlong)param_8 + (longlong)param_4 * 8) * 8);

    pcVar23 = pcVar21;

    if (pcVar17 == (code *)&LAB_140167510) {

      cVar12 = FUN_14017fe70();

      pcVar23 = (code *)&LAB_140167550;

      if (cVar12 == '\0') {

        pcVar23 = pcVar21;

      }

    }

    else if ((pcVar17 == (code *)&LAB_140166eb0) && (cVar12 = FUN_14017fed0(), cVar12 != '\0')) {

      pcVar23 = (code *)&LAB_140166ef0;

    }

    param_2 = param_6;

    if (param_7 != 0x8120) {

      param_2 = uVar16;

    }

    if (pcVar23 == (code *)0x0) {

      pcVar23 = pcVar17;

    }

    (*pcVar23)(param_2,uVar22,param_1);

  }

  if (param_7 != 0x8120) {

    FUN_140211190(param_6,param_2,param_1 * param_8,param_7);

    param_2 = param_6;

  }

  if (param_9 == 0) {

    return;

  }

LAB_1401643fa:

  FUN_140168840(param_1,param_6,param_2,param_8,param_9,param_7);

  return;

}




