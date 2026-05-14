// Address: 0x1401848d0
// Ghidra name: FUN_1401848d0
// ============ 0x1401848d0 FUN_1401848d0 (size=1209) ============


undefined4 FUN_1401848d0(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5)



{

  float fVar1;

  float fVar2;

  char cVar3;

  uint uVar4;

  float *pfVar5;

  float *pfVar6;

  ulonglong uVar7;

  ulonglong uVar8;

  float *pfVar9;

  float fVar10;

  double extraout_XMM0_Qa;

  double extraout_XMM0_Qa_00;

  double dVar11;

  double extraout_XMM0_Qa_01;

  float fVar12;

  ulonglong uVar13;

  float fVar14;

  undefined4 uVar15;

  float fVar16;

  undefined4 uVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  float fVar21;

  float fVar22;

  

  if (param_1 == (float *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_14030db68);

    return 0;

  }

  pfVar5 = param_2;

  pfVar6 = param_3;

  pfVar9 = param_4;

  cVar3 = FUN_140185e60();

  if (cVar3 != '\0') {

    FUN_14012e850("Potential rect math overflow");

    return 0;

  }

  if (param_2 == (float *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140338d58);

    return 0;

  }

  if (param_3 == (float *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140338d5c);

    return 0;

  }

  if (pfVar9 == (float *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140338d60);

    return 0;

  }

  if (param_5 == (float *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140338d64);

    return 0;

  }

  fVar20 = param_1[2];

  if ((fVar20 < 0.0) || (param_1[3] < 0.0)) {

LAB_140184d42:

    uVar15 = 0;

  }

  else {

    fVar1 = *param_1;

    fVar2 = param_1[1];

    fVar19 = *pfVar5;

    fVar18 = *pfVar6;

    fVar14 = *param_4;

    uVar15 = 0;

    fVar21 = (fVar1 + fVar20) - 0.0;

    fVar16 = *param_5;

    uVar17 = 0;

    fVar22 = (fVar2 + param_1[3]) - 0.0;

    if ((((fVar19 < fVar1) ||

         ((((fVar21 < fVar19 || (fVar14 < fVar1)) || (fVar21 < fVar14)) ||

          ((fVar18 < fVar2 || (fVar22 < fVar18)))))) || (fVar16 < fVar2)) || (fVar22 < fVar16)) {

      if ((((fVar19 < fVar1) && (fVar14 < fVar1)) || ((fVar21 < fVar19 && (fVar21 < fVar14)))) ||

         (((fVar18 < fVar2 && (fVar16 < fVar2)) || ((fVar22 < fVar18 && (fVar22 < fVar16))))))

      goto LAB_140184d42;

      if (fVar18 == fVar16) {

        if (fVar1 <= fVar19) {

          if (fVar21 < fVar19) {

            *pfVar5 = fVar21;

          }

        }

        else {

          *pfVar5 = fVar1;

        }

        if (fVar14 < fVar1) {

          *param_4 = fVar1;

          return 1;

        }

        if (fVar21 < fVar14) {

          *param_4 = fVar21;

          return 1;

        }

      }

      else {

        if (fVar19 != fVar14) {

          uVar4 = FUN_140184880(fVar20,fVar19,fVar18);

          uVar7 = (ulonglong)uVar4;

          uVar13 = CONCAT44(uVar17,fVar16);

          uVar8 = CONCAT44(uVar15,fVar14);

          dVar11 = extraout_XMM0_Qa;

          fVar20 = 0.0;

          fVar10 = 0.0;

          do {

            uVar4 = FUN_140184880(dVar11,uVar8,uVar13);

            uVar8 = (ulonglong)uVar4;

            dVar11 = extraout_XMM0_Qa_00;

            while( true ) {

              uVar4 = (uint)uVar7;

              if ((uVar4 == 0) && ((uint)uVar8 == 0)) {

                *param_2 = fVar19;

                *param_3 = fVar18;

                *pfVar9 = fVar14;

                *param_5 = fVar16;

                return 1;

              }

              if ((uVar4 & (uint)uVar8) != 0) goto LAB_140184d42;

              if (uVar4 == 0) break;

              fVar12 = fVar2;

              if (((uVar7 & 2) == 0) && (fVar12 = fVar22, (uVar7 & 1) == 0)) {

                if ((uVar7 & 4) == 0) {

                  fVar12 = fVar10;

                  if ((uVar7 & 8) == 0) goto LAB_140184c37;

                  fVar10 = fVar21 - fVar19;

                  fVar12 = fVar16 - fVar18;

                  fVar20 = fVar21;

                }

                else {

                  fVar10 = fVar16 - fVar18;

                  fVar12 = fVar1 - fVar19;

                  fVar20 = fVar1;

                }

                dVar11 = (double)(fVar14 - fVar19);

                fVar12 = (float)(((double)fVar10 * (double)fVar12) / dVar11 + (double)fVar18);

              }

              else {

                dVar11 = (double)(fVar16 - fVar18);

                fVar20 = (float)(((double)(fVar12 - fVar18) * (double)(fVar14 - fVar19)) / dVar11 +

                                (double)fVar19);

              }

LAB_140184c37:

              fVar18 = fVar12;

              fVar19 = fVar20;

              uVar4 = FUN_140184880(dVar11,fVar19,fVar18);

              uVar7 = (ulonglong)uVar4;

              dVar11 = extraout_XMM0_Qa_01;

              fVar20 = fVar19;

              fVar10 = fVar18;

            }

            fVar12 = fVar2;

            if (((uVar8 & 2) == 0) && (fVar12 = fVar22, (uVar8 & 1) == 0)) {

              if ((uVar8 & 4) == 0) {

                fVar12 = fVar10;

                if ((uVar8 & 8) == 0) goto LAB_140184d17;

                fVar10 = fVar16 - fVar18;

                fVar16 = fVar21 - fVar19;

                fVar20 = fVar21;

              }

              else {

                fVar16 = fVar16 - fVar18;

                fVar10 = fVar1 - fVar19;

                fVar20 = fVar1;

              }

              dVar11 = (double)(fVar14 - fVar19);

              fVar12 = (float)(((double)fVar16 * (double)fVar10) / dVar11 + (double)fVar18);

            }

            else {

              dVar11 = (double)(fVar16 - fVar18);

              fVar20 = (float)(((double)(fVar12 - fVar18) * (double)(fVar14 - fVar19)) / dVar11 +

                              (double)fVar19);

            }

LAB_140184d17:

            fVar16 = fVar12;

            fVar14 = fVar20;

            uVar13 = (ulonglong)(uint)fVar16;

            uVar8 = (ulonglong)(uint)fVar14;

            fVar20 = fVar14;

            fVar10 = fVar16;

          } while( true );

        }

        if (fVar2 <= fVar18) {

          if (fVar22 < fVar18) {

            *pfVar6 = fVar22;

          }

        }

        else {

          *pfVar6 = fVar2;

        }

        if (fVar16 < fVar2) {

          *param_5 = fVar2;

          return 1;

        }

        if (fVar22 < fVar16) {

          *param_5 = fVar22;

        }

      }

    }

    uVar15 = 1;

  }

  return uVar15;

}




