// Address: 0x140150b10
// Ghidra name: FUN_140150b10
// ============ 0x140150b10 FUN_140150b10 (size=1576) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



ulonglong FUN_140150b10(longlong param_1,float *param_2,int param_3)



{

  float fVar1;

  float fVar2;

  longlong lVar3;

  bool bVar4;

  float fVar5;

  char cVar6;

  byte bVar7;

  int iVar8;

  int iVar9;

  ulonglong uVar10;

  ulonglong uVar11;

  ulonglong uVar12;

  int *piVar13;

  int iVar14;

  int iVar15;

  int iVar16;

  longlong lVar17;

  float *pfVar18;

  undefined1 *puVar19;

  int iVar20;

  int *piVar21;

  int iVar22;

  int iVar23;

  int iVar24;

  int iVar25;

  int iVar26;

  float fVar27;

  float fVar28;

  float fVar29;

  float fVar30;

  float fVar31;

  float fVar32;

  undefined1 auStack_158 [128];

  float local_d8;

  int local_d4;

  int local_d0;

  int local_cc;

  int local_c8;

  int local_c4;

  int local_c0;

  int local_bc;

  int local_b8;

  int local_b4;

  int local_b0;

  longlong local_a8;

  float *local_a0;

  int local_98;

  float *local_90;

  int *local_88;

  int *local_80;

  int *local_78;

  longlong local_70;

  ulonglong local_68;

  ulonglong local_60;

  

  puVar19 = auStack_158;

  bVar7 = 1;

  lVar17 = (longlong)param_3;

  if ((param_1 == 0) ||

     ((local_d8 = 2.8026e-45, DAT_1403e3d60 != '\0' &&

      (cVar6 = FUN_1401aa7c0(param_1,2), cVar6 == '\0')))) {

    uVar10 = FUN_14012e850("Parameter \'%s\' is invalid","renderer");

  }

  else {

    if (*(char *)(param_1 + 0x2d8) == '\0') {

      if (param_2 == (float *)0x0) {

        uVar10 = FUN_14012e850("Parameter \'%s\' is invalid","SDL_RenderLines(): points");

        return uVar10;

      }

      if (1 < param_3) {

        lVar3 = *(longlong *)(param_1 + 0x138);

        if ((*(int *)(lVar3 + 0x54) == 0) && (*(int *)(param_1 + 0x1e0) != 2)) {

          if ((*(int *)(param_1 + 0x1e0) != 0) &&

             ((*(float *)(lVar3 + 0x4c) == DAT_14039ca44 &&

              (*(float *)(lVar3 + 0x50) == DAT_14039ca44)))) {

            uVar10 = FUN_14014a6d0(param_1,param_2,param_3);

            return uVar10;

          }

          uVar10 = FUN_14014b2d0(param_1,param_2,param_3);

          return uVar10;

        }

        fVar1 = *(float *)(lVar3 + 0x90);

        fVar2 = *(float *)(lVar3 + 0x94);

        uVar10 = (longlong)(param_3 * 8) * 4;

        local_68 = uVar10;

        if (uVar10 < 0x80) {

          uVar11 = uVar10 + 0xf;

          if (uVar11 <= uVar10) {

            uVar11 = 0xffffffffffffff0;

          }

          puVar19 = auStack_158 + -(uVar11 & 0xfffffffffffffff0);

          local_a0 = (float *)((longlong)&local_d8 + -(uVar11 & 0xfffffffffffffff0));

        }

        else {

          local_a0 = (float *)FUN_1401841f0(uVar10);

        }

        uVar11 = (longlong)(param_3 * 0x12 + -0xc) * 4;

        local_60 = uVar11;

        if (uVar11 < 0x80) {

          uVar12 = uVar11 + 0xf;

          if (uVar12 <= uVar11) {

            uVar12 = 0xffffffffffffff0;

          }

          *(undefined8 *)(puVar19 + -8) = 0x140150cbd;

          piVar13 = (int *)(puVar19 + -(uVar12 & 0xfffffffffffffff0) + 0x80);

          puVar19 = puVar19 + -(uVar12 & 0xfffffffffffffff0);

        }

        else {

          *(undefined8 *)(puVar19 + -8) = 0x140150cd2;

          piVar13 = (int *)FUN_1401841f0(uVar11);

        }

        local_78 = piVar13;

        if ((local_a0 != (float *)0x0) && (piVar13 != (int *)0x0)) {

          local_90 = local_a0;

          local_98 = param_3 * 4;

          iVar24 = 0;

          if ((*param_2 == param_2[lVar17 * 2 + -2]) && (param_2[1] == param_2[lVar17 * 2 + -1])) {

            bVar4 = true;

          }

          else {

            bVar4 = false;

          }

          local_70 = lVar17;

          if (param_3 != 0) {

            local_a8 = 0;

            local_c4 = 0;

            local_c0 = 1;

            local_bc = -2;

            local_b8 = -3;

            local_b4 = -1;

            local_b0 = -4;

            iVar14 = 3;

            pfVar18 = local_a0;

            fVar29 = 0.0;

            fVar30 = 0.0;

            iVar24 = 0;

            do {

              lVar17 = local_a8;

              iVar26 = local_b0;

              iVar23 = local_b4;

              iVar25 = local_b8;

              iVar16 = local_bc;

              iVar22 = local_c0;

              iVar20 = local_c4;

              fVar5 = local_d8;

              fVar31 = fVar1 * param_2[local_a8 * 2];

              fVar32 = fVar2 * param_2[local_a8 * 2 + 1];

              *pfVar18 = fVar31;

              fVar27 = fVar31 + fVar1;

              pfVar18[6] = fVar31;

              pfVar18[1] = fVar32;

              fVar28 = fVar32 + fVar2;

              pfVar18[3] = fVar32;

              pfVar18[2] = fVar27;

              pfVar18[4] = fVar27;

              pfVar18[5] = fVar28;

              pfVar18[7] = fVar28;

              pfVar18 = pfVar18 + 8;

              local_90 = pfVar18;

              if ((local_a8 != 0) || (piVar21 = piVar13, !bVar4)) {

                *piVar13 = local_c4;

                piVar13[1] = iVar22;

                piVar13[2] = (int)fVar5;

                piVar13[3] = iVar14 + -3;

                piVar13[4] = iVar14 + -1;

                piVar13[5] = iVar14;

                iVar24 = iVar24 + 6;

                piVar21 = piVar13 + 6;

              }

              iVar22 = iVar14 + -3;

              piVar13 = piVar21;

              if (lVar17 != 0) {

                piVar13 = piVar21 + 1;

                if (fVar30 == fVar32) {

                  iVar20 = iVar16;

                  iVar8 = iVar25;

                  iVar15 = iVar14;

                  if (fVar31 <= fVar29) {

                    iVar22 = iVar26;

                    iVar20 = iVar14 + -1;

                    iVar8 = iVar14 + -2;

                    iVar15 = iVar23;

                  }

                  *piVar21 = iVar8;

                  iVar24 = iVar24 + 6;

                  *piVar13 = iVar22;

                  piVar21[2] = iVar15;

                  piVar21[3] = iVar8;

                  piVar21[4] = iVar15;

                  piVar21[5] = iVar20;

                  piVar13 = piVar21 + 6;

                  pfVar18 = local_90;

                  iVar20 = local_c4;

                }

                else if (fVar29 == fVar31) {

                  if (fVar32 <= fVar30) {

                    iVar22 = iVar14 + -7;

                    iVar8 = iVar14 + -1;

                    iVar15 = iVar14 + -6;

                    iVar20 = iVar14;

                  }

                  else {

                    iVar8 = iVar14 + -5;

                    iVar15 = iVar14 + -2;

                    iVar20 = iVar14 + -4;

                  }

                  *piVar21 = iVar8;

                  iVar24 = iVar24 + 6;

                  *piVar13 = iVar15;

                  piVar13 = piVar21 + 6;

                  piVar21[2] = iVar22;

                  piVar21[3] = iVar8;

                  piVar21[4] = iVar22;

                  piVar21[5] = iVar20;

                  pfVar18 = local_90;

                  iVar20 = local_c4;

                }

                else {

                  if (fVar32 <= fVar30) {

                    iVar15 = iVar14 + -6;

                    iVar20 = iVar14 + -1;

                    iVar8 = iVar14 + -7;

                    if (fVar31 <= fVar29) {

                      *piVar21 = iVar20;

                      *piVar13 = iVar14 + -2;

                      iVar9 = iVar14 + -4;

                      piVar21[2] = iVar15;

                      piVar21[3] = iVar20;

                      piVar21[4] = iVar15;

                      piVar21[5] = iVar8;

                      piVar21[6] = iVar14;

                      piVar21[7] = iVar20;

                      piVar21[8] = iVar8;

                      piVar21[9] = iVar14;

                      piVar21[10] = iVar8;

                    }

                    else {

                      *piVar21 = iVar8;

                      iVar9 = iVar14 + -5;

                      *piVar13 = iVar22;

                      piVar21[2] = iVar14;

                      piVar21[3] = iVar8;

                      piVar21[4] = iVar14;

                      piVar21[5] = iVar15;

                      piVar21[6] = iVar15;

                      piVar21[7] = iVar14;

                      piVar21[8] = iVar20;

                      piVar21[9] = iVar15;

                      piVar21[10] = iVar20;

                    }

                    piVar21[0xb] = iVar9;

                  }

                  else {

                    iVar20 = iVar14 + -5;

                    iVar25 = iVar14 + -2;

                    iVar16 = iVar14 + -4;

                    if (fVar31 <= fVar29) {

                      iVar8 = iVar14 + -1;

                      iVar15 = iVar14 + -7;

                      iVar23 = iVar22;

                      iVar26 = iVar25;

                      iVar9 = iVar16;

                      local_d4 = iVar15;

                      local_d0 = iVar25;

                      local_cc = iVar16;

                      local_c8 = iVar8;

                    }

                    else {

                      iVar23 = iVar14 + -6;

                      iVar26 = iVar14 + -6;

                      iVar8 = iVar20;

                      iVar15 = iVar22;

                      iVar9 = iVar14;

                      local_d4 = iVar25;

                      local_d0 = iVar22;

                      local_cc = iVar22;

                      local_c8 = iVar14;

                    }

                    local_88 = piVar13;

                    local_80 = piVar13;

                    *piVar21 = iVar23;

                    *piVar13 = local_d4;

                    piVar21[2] = local_d0;

                    piVar21[3] = iVar26;

                    piVar21[4] = iVar15;

                    iVar22 = iVar16;

                    iVar23 = iVar20;

                    if (fVar31 <= fVar29) {

                      iVar22 = iVar20;

                      iVar23 = iVar16;

                    }

                    piVar21[5] = iVar23;

                    if (fVar31 <= fVar29) {

                      iVar20 = iVar25;

                    }

                    piVar21[6] = iVar20;

                    local_88[6] = local_cc;

                    piVar21[8] = local_c8;

                    piVar13 = local_80;

                    piVar21[9] = iVar8;

                    piVar13[9] = iVar9;

                    piVar21[0xb] = iVar22;

                    iVar16 = local_bc;

                    iVar25 = local_b8;

                    iVar26 = local_b0;

                    iVar23 = local_b4;

                  }

                  iVar24 = iVar24 + 0xc;

                  piVar13 = piVar21 + 0xc;

                  pfVar18 = local_90;

                  lVar17 = local_a8;

                  iVar20 = local_c4;

                }

              }

              local_a8 = lVar17 + 1;

              local_d8 = (float)((int)local_d8 + 4);

              local_c0 = local_c0 + 4;

              local_c4 = iVar20 + 4;

              local_bc = iVar16 + 4;

              local_b8 = iVar25 + 4;

              local_b4 = iVar23 + 4;

              local_b0 = iVar26 + 4;

              iVar14 = iVar14 + 4;

              uVar11 = local_60;

              uVar10 = local_68;

              fVar29 = fVar31;

              fVar30 = fVar32;

            } while (local_a8 < local_70);

          }

          piVar13 = local_78;

          iVar14 = local_98;

          pfVar18 = local_a0;

          *(undefined4 *)(puVar19 + 0x78) = 1;

          *(undefined4 *)(puVar19 + 0x70) = 1;

          *(float *)(puVar19 + 0x68) = DAT_14039ca44;

          *(float *)(puVar19 + 0x60) = DAT_14039ca44;

          *(undefined4 *)(puVar19 + 0x58) = 4;

          *(int *)(puVar19 + 0x50) = iVar24;

          *(int **)(puVar19 + 0x48) = piVar13;

          *(int *)(puVar19 + 0x40) = iVar14;

          *(undefined4 *)(puVar19 + 0x38) = 0;

          *(undefined8 *)(puVar19 + 0x30) = 0;

          *(undefined4 *)(puVar19 + 0x28) = 0;

          *(longlong *)(puVar19 + 0x20) = param_1 + 0x21c;

          *(undefined8 *)(puVar19 + -8) = 0x1401510cc;

          bVar7 = FUN_14014ac90(param_1,0,pfVar18,8);

        }

        pfVar18 = local_a0;

        if (0x7f < uVar10) {

          *(undefined8 *)(puVar19 + -8) = 0x1401510e4;

          FUN_1401841e0(pfVar18);

        }

        if (0x7f < uVar11) {

          *(undefined8 *)(puVar19 + -8) = 0x1401510f5;

          FUN_1401841e0(piVar13);

        }

      }

      return (ulonglong)bVar7;

    }

    uVar10 = FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

  }

  return uVar10 & 0xffffffffffffff00;

}




