// Address: 0x14004a400
// Ghidra name: FUN_14004a400
// ============ 0x14004a400 FUN_14004a400 (size=1548) ============


void FUN_14004a400(int param_1)



{

  undefined8 *puVar1;

  char cVar2;

  longlong lVar3;

  bool bVar4;

  longlong lVar5;

  float fVar6;

  uint uVar7;

  int iVar8;

  float *pfVar9;

  undefined4 uVar10;

  undefined2 uVar11;

  longlong lVar12;

  int iVar13;

  float *pfVar14;

  int iVar15;

  longlong lVar16;

  int iVar17;

  int iVar18;

  int iVar19;

  int iVar20;

  undefined2 uVar21;

  int iVar22;

  int iVar23;

  bool bVar24;

  float fVar25;

  undefined1 auVar26 [16];

  float fVar27;

  undefined1 auVar28 [16];

  undefined1 auVar29 [16];

  double dVar30;

  float fVar31;

  undefined8 local_e8;

  undefined8 uStack_e0;

  undefined8 uStack_d0;

  undefined8 local_c8;

  undefined8 uStack_c0;

  undefined8 local_b8;

  undefined8 uStack_b0;

  

  SDL_LockMutex(*(undefined8 *)(DAT_1403ea2a8 + 0x38));

  iVar8 = (int)(param_1 + (param_1 >> 0x1f & 3U)) >> 2;

  pfVar9 = DAT_1403ea2a8;

  if (iVar8 != 0) {

    lVar12 = *(longlong *)(DAT_1403ea2a8 + 0x2e);

    pfVar14 = *(float **)(DAT_1403ea2a8 + 0x30);

    FUN_1402f94c0(lVar12,0,(longlong)(int)DAT_1403ea2a8[0x2c] << 4);

    FUN_1402f94c0(pfVar14,0,(longlong)(int)DAT_1403ea2a8[0x2c] << 4);

    uVar7 = DAT_14039cac0;

    fVar6 = DAT_14039ca44;

    pfVar9 = DAT_1403ea2a8;

    if (*(char *)(DAT_1403ea2a8 + 2) == '\0') {

      lVar16 = *(longlong *)(DAT_1403ea2a8 + 0x28);

joined_r0x00014004a4d1:

      lVar5 = lVar16;

      if (lVar5 != 0) {

        lVar3 = *(longlong *)(lVar5 + 0x28);

        lVar16 = *(longlong *)(lVar5 + 0x30);

        if (((lVar3 == 0) || (*(char *)(lVar5 + 9) == '\0')) || (*(char *)(pfVar9 + 0x34) == '\0'))

        {

LAB_14004a7d6:

          FUN_14004b750(lVar5);

          pfVar9 = DAT_1403ea2a8;

        }

        else if ((*(char *)(lVar5 + 10) == '\0') &&

                (fVar31 = *(float *)(lVar5 + 0x18), fVar31 != 0.0)) {

          if (*(char *)(lVar5 + 8) == '\0') {

            fVar25 = pfVar9[5];

          }

          else {

            fVar25 = pfVar9[3];

          }

          bVar4 = fVar31 == fVar6;

          iVar23 = 0;

          fVar27 = fVar25 * *(float *)(lVar5 + 0xc) * *(float *)(lVar5 + 0x14) * *pfVar9 * pfVar9[1]

          ;

          fVar25 = fVar25 * *(float *)(lVar5 + 0xc) * *(float *)(lVar5 + 0x10) * (fVar6 - *pfVar9) *

                            pfVar9[1];

          auVar28._0_8_ = CONCAT44(fVar27,fVar27);

          auVar28._8_4_ = fVar27;

          auVar28._12_4_ = fVar27;

          auVar26._0_8_ = CONCAT44(fVar25,fVar25);

          auVar26._8_4_ = fVar25;

          auVar26._12_4_ = fVar25;

          if (0 < iVar8) {

            uStack_e0 = auVar26._8_8_;

            uStack_d0 = auVar28._8_8_;

            iVar13 = iVar8;

            do {

              dVar30 = *(double *)(lVar5 + 0x20);

              auVar29._8_8_ = 0;

              auVar29._0_8_ = dVar30;

              if (fVar31 < 0.0) {

                bVar24 = 0.0 < dVar30;

              }

              else {

                bVar24 = dVar30 < (double)*(int *)(lVar3 + 4);

              }

              if (!bVar24) {

                if (*(char *)(lVar5 + 0xb) == '\0') goto LAB_14004a7d6;

                if (fVar31 < 0.0) {

                  while (dVar30 < 0.0) {

                    dVar30 = (double)*(int *)(lVar3 + 4) + auVar29._0_8_;

                    *(double *)(lVar5 + 0x20) = dVar30;

                    auVar29._8_8_ = 0;

                    auVar29._0_8_ = dVar30;

                  }

                }

                else {

                  iVar15 = *(int *)(lVar3 + 4);

                  if ((double)iVar15 <= dVar30) {

                    do {

                      dVar30 = auVar29._0_8_ - (double)iVar15;

                      *(double *)(lVar5 + 0x20) = dVar30;

                      auVar29._0_8_ = dVar30;

                      iVar15 = *(int *)(lVar3 + 4);

                    } while ((double)iVar15 <= dVar30);

                  }

                }

              }

              cVar2 = *(char *)(lVar5 + 0xb);

              iVar15 = iVar13;

              if ((cVar2 == '\0') || (bVar4)) {

                if (fVar31 < 0.0) {

                  iVar18 = (int)(dVar30 / (double)(float)((uint)*(float *)(lVar5 + 0x18) ^ uVar7));

                  if (iVar18 < iVar13) {

                    iVar15 = iVar18;

                  }

                }

                else {

                  iVar15 = (int)(((double)*(int *)(lVar3 + 4) - dVar30) /

                                (double)*(float *)(lVar5 + 0x18));

                  if (iVar13 <= iVar15) {

                    iVar15 = iVar13;

                  }

                }

              }

              pfVar9 = DAT_1403ea2a8;

              if (iVar15 < 1) break;

              iVar18 = (int)(((int)(iVar23 + 3U) >> 0x1f & 3U) + (iVar23 + 3U & 0xfffffffc)) >> 2;

              uVar10 = (undefined4)((longlong)iVar15 + 3U >> 2);

              if (bVar4) {

                uStack_b0 = uStack_d0;

                uStack_c0 = uStack_e0;

                local_c8 = auVar26._0_8_;

                local_b8 = auVar28._0_8_;

                FUN_14004b390(lVar3,&local_c8,&local_b8,iVar18,uVar10,

                              (int)(((int)dVar30 & 0xfffffffcU) + ((int)dVar30 >> 0x1f & 3U)) >> 2);

              }

              else {

                uStack_c0 = uStack_d0;

                uStack_b0 = uStack_e0;

                local_c8 = auVar28._0_8_;

                local_b8 = auVar26._0_8_;

                FUN_14004aa10(lVar3,&local_b8,&local_c8,iVar18,uVar10,fVar31,dVar30,cVar2);

              }

              fVar31 = *(float *)(lVar5 + 0x18);

              iVar23 = iVar23 + iVar15;

              iVar13 = iVar13 - iVar15;

              *(double *)(lVar5 + 0x20) =

                   (double)fVar31 * (double)iVar15 + *(double *)(lVar5 + 0x20);

              pfVar9 = DAT_1403ea2a8;

            } while (0 < iVar13);

          }

        }

        goto joined_r0x00014004a4d1;

      }

    }

    iVar8 = 0;

    if (0 < (int)pfVar9[0x2c]) {

      lVar12 = lVar12 - (longlong)pfVar14;

      lVar16 = *(longlong *)(pfVar9 + 0x32) - (longlong)pfVar14;

      do {

        pfVar9 = (float *)((longlong)pfVar14 + lVar12);

        iVar19 = (int)pfVar14[1];

        iVar18 = (int)*pfVar9;

        iVar15 = (int)pfVar14[2];

        iVar22 = (int)*pfVar14;

        iVar23 = (int)pfVar9[3];

        iVar20 = (int)pfVar9[1];

        iVar13 = (int)pfVar14[3];

        iVar17 = (int)pfVar9[2];

        if (iVar18 < 0x8000) {

          uVar11 = (undefined2)iVar18;

          if (iVar18 < -0x8000) {

            uVar11 = 0x8000;

          }

        }

        else {

          uVar11 = 0x7fff;

        }

        if (iVar22 < 0x8000) {

          uVar21 = (undefined2)iVar22;

          if (iVar22 < -0x8000) {

            uVar21 = 0x8000;

          }

        }

        else {

          uVar21 = 0x7fff;

        }

        local_e8._0_4_ = CONCAT22(uVar21,uVar11);

        if (iVar20 < 0x8000) {

          uVar11 = (undefined2)iVar20;

          if (iVar20 < -0x8000) {

            uVar11 = 0x8000;

          }

        }

        else {

          uVar11 = 0x7fff;

        }

        local_e8._0_6_ = CONCAT24(uVar11,(undefined4)local_e8);

        if (iVar19 < 0x8000) {

          uVar11 = (undefined2)iVar19;

          if (iVar19 < -0x8000) {

            uVar11 = 0x8000;

          }

        }

        else {

          uVar11 = 0x7fff;

        }

        local_e8 = CONCAT26(uVar11,(undefined6)local_e8);

        if (iVar17 < 0x8000) {

          uStack_e0._0_2_ = (undefined2)iVar17;

          if (iVar17 < -0x8000) {

            uStack_e0._0_2_ = 0x8000;

          }

        }

        else {

          uStack_e0._0_2_ = 0x7fff;

        }

        if (iVar15 < 0x8000) {

          uStack_e0._2_2_ = (undefined2)iVar15;

          if (iVar15 < -0x8000) {

            uStack_e0._2_2_ = 0x8000;

          }

        }

        else {

          uStack_e0._2_2_ = 0x7fff;

        }

        if (iVar23 < 0x8000) {

          uStack_e0._4_2_ = (undefined2)iVar23;

          if (iVar23 < -0x8000) {

            uStack_e0._4_2_ = 0x8000;

          }

        }

        else {

          uStack_e0._4_2_ = 0x7fff;

        }

        if (iVar13 < 0x8000) {

          uStack_e0._6_2_ = (undefined2)iVar13;

          if (iVar13 < -0x8000) {

            uStack_e0._6_2_ = 0x8000;

          }

        }

        else {

          uStack_e0._6_2_ = 0x7fff;

        }

        iVar8 = iVar8 + 1;

        puVar1 = (undefined8 *)(lVar16 + (longlong)pfVar14);

        *puVar1 = local_e8;

        puVar1[1] = uStack_e0;

        pfVar14 = pfVar14 + 4;

        pfVar9 = DAT_1403ea2a8;

      } while (iVar8 < (int)DAT_1403ea2a8[0x2c]);

    }

  }

  SDL_UnlockMutex(*(undefined8 *)(pfVar9 + 0x38));

  return;

}




