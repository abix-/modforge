// Address: 0x140049630
// Ghidra name: FUN_140049630
// ============ 0x140049630 FUN_140049630 (size=1339) ============


void FUN_140049630(longlong param_1,int param_2,longlong param_3,int param_4,int param_5)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  byte bVar5;

  float *pfVar6;

  int iVar7;

  longlong lVar8;

  longlong lVar9;

  longlong lVar10;

  byte *pbVar11;

  longlong lVar12;

  undefined2 *puVar13;

  longlong lVar14;

  longlong lVar15;

  int iVar16;

  longlong lVar17;

  int iVar18;

  float local_a8 [32];

  

  fVar4 = DAT_1403053ec;

  iVar18 = 0;

  lVar10 = (longlong)param_2;

  lVar15 = 0x10;

  if (0 < param_5) {

    lVar9 = (longlong)param_4;

    lVar17 = lVar9 * 4 + 8;

    iVar16 = param_5;

    do {

      iVar7 = iVar16;

      if (iVar18 + (int)lVar15 <= param_5) {

        iVar7 = (int)lVar15;

      }

      lVar14 = 0;

      lVar15 = (longlong)iVar7;

      local_a8[0] = 0.0;

      local_a8[1] = 0.0;

      local_a8[2] = 0.0;

      local_a8[3] = 0.0;

      local_a8[4] = 0.0;

      local_a8[5] = 0.0;

      local_a8[6] = 0.0;

      local_a8[7] = 0.0;

      local_a8[8] = 0.0;

      local_a8[9] = 0.0;

      local_a8[10] = 0.0;

      local_a8[0xb] = 0.0;

      local_a8[0xc] = 0.0;

      local_a8[0xd] = 0.0;

      local_a8[0xe] = 0.0;

      local_a8[0xf] = 0.0;

      local_a8[0x10] = 0.0;

      local_a8[0x11] = 0.0;

      local_a8[0x12] = 0.0;

      local_a8[0x13] = 0.0;

      local_a8[0x14] = 0.0;

      local_a8[0x15] = 0.0;

      local_a8[0x16] = 0.0;

      local_a8[0x17] = 0.0;

      local_a8[0x18] = 0.0;

      local_a8[0x19] = 0.0;

      local_a8[0x1a] = 0.0;

      local_a8[0x1b] = 0.0;

      local_a8[0x1c] = 0.0;

      local_a8[0x1d] = 0.0;

      local_a8[0x1e] = 0.0;

      local_a8[0x1f] = 0.0;

      if (0 < lVar10) {

        pbVar11 = &DAT_1403d49e0 + lVar10 * 6;

        do {

          bVar5 = *pbVar11 & 6;

          if (bVar5 == 6) {

            lVar8 = 0;

            if (lVar15 < 4) {

              if (0 < iVar7) {

                lVar12 = *(longlong *)(param_3 + lVar14 * 8);

                goto LAB_1400497d7;

              }

            }

            else {

              lVar12 = *(longlong *)(param_3 + lVar14 * 8);

              pfVar6 = (float *)(lVar12 + (lVar9 + 2) * 4);

              do {

                fVar1 = pfVar6[-2];

                fVar2 = pfVar6[-1];

                fVar3 = local_a8[lVar8 * 2 + 1];

                local_a8[lVar8 * 2] = fVar1 + local_a8[lVar8 * 2];

                local_a8[lVar8 * 2 + 1] = fVar1 + fVar3;

                fVar1 = *pfVar6;

                local_a8[lVar8 * 2 + 2] = fVar2 + local_a8[lVar8 * 2 + 2];

                local_a8[lVar8 * 2 + 3] = fVar2 + local_a8[lVar8 * 2 + 3];

                fVar2 = pfVar6[1];

                pfVar6 = pfVar6 + 4;

                local_a8[lVar8 * 2 + 4] = fVar1 + local_a8[lVar8 * 2 + 4];

                local_a8[lVar8 * 2 + 5] = fVar1 + local_a8[lVar8 * 2 + 5];

                local_a8[lVar8 * 2 + 6] = fVar2 + local_a8[lVar8 * 2 + 6];

                local_a8[lVar8 * 2 + 7] = fVar2 + local_a8[lVar8 * 2 + 7];

                lVar8 = lVar8 + 4;

              } while (lVar8 < lVar15 + -3);

              if (lVar8 < lVar15) {

LAB_1400497d7:

                pfVar6 = (float *)(lVar12 + (lVar9 + lVar8) * 4);

                do {

                  fVar1 = *pfVar6;

                  pfVar6 = pfVar6 + 1;

                  fVar2 = local_a8[lVar8 * 2 + 1];

                  local_a8[lVar8 * 2] = fVar1 + local_a8[lVar8 * 2];

                  local_a8[lVar8 * 2 + 1] = fVar1 + fVar2;

                  lVar8 = lVar8 + 1;

                } while (lVar8 < lVar15);

              }

            }

          }

          else if (bVar5 == 2) {

            lVar8 = 0;

            if (lVar15 < 4) {

              if (0 < iVar7) {

                lVar12 = *(longlong *)(param_3 + lVar14 * 8);

                goto LAB_1400498a7;

              }

            }

            else {

              lVar12 = *(longlong *)(param_3 + lVar14 * 8);

              pfVar6 = (float *)(lVar12 + (lVar9 + 2) * 4);

              do {

                fVar1 = pfVar6[-1];

                fVar2 = local_a8[lVar8 * 2 + 2];

                local_a8[lVar8 * 2] = pfVar6[-2] + local_a8[lVar8 * 2];

                fVar3 = *pfVar6;

                local_a8[lVar8 * 2 + 2] = fVar1 + fVar2;

                fVar1 = pfVar6[1];

                pfVar6 = pfVar6 + 4;

                local_a8[lVar8 * 2 + 4] = local_a8[lVar8 * 2 + 4] + fVar3;

                local_a8[lVar8 * 2 + 6] = fVar1 + local_a8[lVar8 * 2 + 6];

                lVar8 = lVar8 + 4;

              } while (lVar8 < lVar15 + -3);

              if (lVar8 < lVar15) {

LAB_1400498a7:

                pfVar6 = (float *)(lVar12 + (lVar9 + lVar8) * 4);

                do {

                  fVar1 = *pfVar6;

                  pfVar6 = pfVar6 + 1;

                  local_a8[lVar8 * 2] = fVar1 + local_a8[lVar8 * 2];

                  lVar8 = lVar8 + 1;

                } while (lVar8 < lVar15);

              }

            }

          }

          else if (bVar5 == 4) {

            lVar8 = 0;

            if (lVar15 < 4) {

              if (0 < iVar7) {

                lVar12 = *(longlong *)(param_3 + lVar14 * 8);

                goto LAB_140049950;

              }

            }

            else {

              lVar12 = *(longlong *)(param_3 + lVar14 * 8);

              pfVar6 = (float *)(lVar17 + lVar12);

              do {

                fVar1 = pfVar6[-1];

                local_a8[lVar8 * 2 + 1] = pfVar6[-2] + local_a8[lVar8 * 2 + 1];

                fVar2 = *pfVar6;

                local_a8[lVar8 * 2 + 3] = fVar1 + local_a8[lVar8 * 2 + 3];

                fVar1 = pfVar6[1];

                pfVar6 = pfVar6 + 4;

                local_a8[lVar8 * 2 + 5] = fVar2 + local_a8[lVar8 * 2 + 5];

                local_a8[lVar8 * 2 + 7] = fVar1 + local_a8[lVar8 * 2 + 7];

                lVar8 = lVar8 + 4;

              } while (lVar8 < lVar15 + -3);

              if (lVar8 < lVar15) {

LAB_140049950:

                pfVar6 = (float *)(lVar12 + (lVar9 + lVar8) * 4);

                do {

                  fVar1 = *pfVar6;

                  pfVar6 = pfVar6 + 1;

                  local_a8[lVar8 * 2 + 1] = fVar1 + local_a8[lVar8 * 2 + 1];

                  lVar8 = lVar8 + 1;

                } while (lVar8 < lVar15);

              }

            }

          }

          lVar14 = lVar14 + 1;

          pbVar11 = pbVar11 + 1;

        } while (lVar14 < lVar10);

      }

      lVar14 = 0;

      lVar8 = (longlong)(iVar7 * 2);

      if (lVar8 < 4) {

        if (0 < iVar7 * 2) goto LAB_140049abf;

      }

      else {

        puVar13 = (undefined2 *)(param_1 + (longlong)(iVar18 * 2) * 2 + 4);

        do {

          iVar7 = (int)(local_a8[lVar14] + fVar4) + -0x43c00000;

          if (0xffff < (int)(local_a8[lVar14] + fVar4) + 0xbc408000U) {

            iVar7 = (iVar7 >> 0x1f & 0xffff0001U) + 0x7fff;

          }

          fVar1 = local_a8[lVar14 + 1];

          puVar13[-2] = (short)iVar7;

          iVar7 = (int)(fVar1 + fVar4) + -0x43c00000;

          if (0xffff < (int)(fVar1 + fVar4) + 0xbc408000U) {

            iVar7 = (iVar7 >> 0x1f & 0xffff0001U) + 0x7fff;

          }

          fVar1 = local_a8[lVar14 + 2];

          puVar13[-1] = (short)iVar7;

          iVar7 = (int)(fVar1 + fVar4) + -0x43c00000;

          if (0xffff < (int)(fVar1 + fVar4) + 0xbc408000U) {

            iVar7 = (iVar7 >> 0x1f & 0xffff0001U) + 0x7fff;

          }

          fVar1 = local_a8[lVar14 + 3];

          *puVar13 = (short)iVar7;

          iVar7 = (int)(fVar1 + fVar4) + -0x43c00000;

          if (0xffff < (int)(fVar1 + fVar4) + 0xbc408000U) {

            iVar7 = (iVar7 >> 0x1f & 0xffff0001U) + 0x7fff;

          }

          puVar13[1] = (short)iVar7;

          lVar14 = lVar14 + 4;

          puVar13 = puVar13 + 4;

        } while (lVar14 < lVar8 + -3);

        if (lVar14 < lVar8) {

LAB_140049abf:

          puVar13 = (undefined2 *)(param_1 + (iVar18 * 2 + lVar14) * 2);

          do {

            iVar7 = (int)(local_a8[lVar14] + fVar4) + -0x43c00000;

            if (0xffff < (int)(local_a8[lVar14] + fVar4) + 0xbc408000U) {

              iVar7 = (iVar7 >> 0x1f & 0xffff0001U) + 0x7fff;

            }

            *puVar13 = (short)iVar7;

            lVar14 = lVar14 + 1;

            puVar13 = puVar13 + 1;

          } while (lVar14 < lVar8);

        }

      }

      iVar18 = iVar18 + 0x10;

      iVar16 = iVar16 + -0x10;

      lVar9 = lVar9 + 0x10;

      lVar17 = lVar17 + 0x40;

    } while (iVar18 < param_5);

  }

  return;

}




