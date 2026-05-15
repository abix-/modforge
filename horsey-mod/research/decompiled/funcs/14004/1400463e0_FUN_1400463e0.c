// Address: 0x1400463e0
// Ghidra name: FUN_1400463e0
// ============ 0x1400463e0 FUN_1400463e0 (size=2552) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



int * FUN_1400463e0(undefined8 *param_1)



{

  undefined4 *puVar1;

  short sVar2;

  short sVar3;

  short sVar4;

  ushort uVar5;

  char cVar6;

  int iVar7;

  uint uVar8;

  undefined8 *puVar9;

  int *piVar10;

  longlong lVar11;

  undefined8 uVar12;

  ulonglong uVar13;

  int *piVar14;

  undefined4 *puVar15;

  uint uVar16;

  longlong lVar17;

  short *psVar18;

  char *pcVar19;

  longlong lVar20;

  float *pfVar21;

  int *piVar22;

  undefined8 *puVar23;

  undefined4 *puVar24;

  code *pcVar25;

  longlong lVar26;

  longlong lVar27;

  int iVar28;

  undefined4 uVar29;

  undefined4 uVar30;

  undefined4 uVar31;

  undefined4 uVar32;

  int local_res18;

  int local_res20 [2];

  undefined1 auStack_7d0d0 [40];

  short asStack_7d0a8 [256052];

  

  if ((DAT_1403ea293 != '\0') && (2 < *(int *)(param_1 + 2))) {

    uVar13 = param_1[3];

    puVar9 = param_1;

    if (0xf < uVar13) {

      puVar9 = (undefined8 *)*param_1;

    }

    puVar23 = param_1;

    if (*(char *)((longlong)*(int *)(param_1 + 2) + -3 + (longlong)puVar9) == 's') {

      puVar9 = param_1;

      if (0xf < uVar13) {

        puVar9 = (undefined8 *)*param_1;

      }

      cVar6 = FUN_1400d8e00(puVar9);

      if (cVar6 == '\0') {

        if (0xf < (ulonglong)param_1[3]) {

          puVar23 = (undefined8 *)*param_1;

        }

        pcVar19 = "error loading sfxr: %s";

      }

      else {

        iVar7 = FUN_1400d9010(asStack_7d0a8,0x3e800);

        piVar10 = (int *)_malloc_base(0x20);

        if (piVar10 != (int *)0x0) {

          *piVar10 = 0xac44;

          piVar10[2] = 1;

          piVar10[1] = iVar7 + -1;

          lVar17 = 0;

          piVar10[3] = 0;

          iVar7 = (int)((iVar7 + 2U & 0xfffffffc) + ((int)(iVar7 + 2U) >> 0x1f & 3U)) >> 2;

          lVar11 = FUN_14004a210((longlong)iVar7 << 4);

          *(longlong *)(piVar10 + 4) = lVar11;

          if (lVar11 != 0) {

            piVar10[6] = 0;

            piVar10[7] = 0;

            iVar7 = iVar7 + -1;

            lVar26 = (longlong)iVar7;

            if (lVar26 < 4) {

              lVar27 = lVar17;

              if (iVar7 < 1) goto LAB_1400466fd;

            }

            else {

              pfVar21 = (float *)(lVar11 + 0x20);

              lVar20 = (lVar26 - 4U >> 2) + 1;

              lVar27 = lVar20 * 4;

              do {

                sVar2 = asStack_7d0a8[lVar17 + 1];

                sVar3 = asStack_7d0a8[lVar17 + 2];

                sVar4 = asStack_7d0a8[lVar17 + 3];

                pfVar21[-8] = (float)(int)asStack_7d0a8[lVar17];

                pfVar21[-7] = (float)(int)sVar2;

                pfVar21[-6] = (float)(int)sVar3;

                pfVar21[-5] = (float)(int)sVar4;

                sVar2 = asStack_7d0a8[lVar17 + 5];

                sVar3 = asStack_7d0a8[lVar17 + 6];

                sVar4 = asStack_7d0a8[lVar17 + 7];

                pfVar21[-4] = (float)(int)asStack_7d0a8[lVar17 + 4];

                pfVar21[-3] = (float)(int)sVar2;

                pfVar21[-2] = (float)(int)sVar3;

                pfVar21[-1] = (float)(int)sVar4;

                sVar2 = asStack_7d0a8[lVar17 + 9];

                sVar3 = asStack_7d0a8[lVar17 + 10];

                sVar4 = asStack_7d0a8[lVar17 + 0xb];

                *pfVar21 = (float)(int)asStack_7d0a8[lVar17 + 8];

                pfVar21[1] = (float)(int)sVar2;

                pfVar21[2] = (float)(int)sVar3;

                pfVar21[3] = (float)(int)sVar4;

                sVar2 = asStack_7d0a8[lVar17 + 0xd];

                sVar3 = asStack_7d0a8[lVar17 + 0xe];

                sVar4 = asStack_7d0a8[lVar17 + 0xf];

                pfVar21[4] = (float)(int)asStack_7d0a8[lVar17 + 0xc];

                pfVar21[5] = (float)(int)sVar2;

                pfVar21[6] = (float)(int)sVar3;

                pfVar21[7] = (float)(int)sVar4;

                lVar17 = lVar17 + 0x10;

                pfVar21 = pfVar21 + 0x10;

                lVar20 = lVar20 + -1;

              } while (lVar20 != 0);

              if (lVar26 <= lVar27) goto LAB_1400466fd;

            }

            pfVar21 = (float *)(lVar27 * 0x10 + lVar11);

            psVar18 = asStack_7d0a8 + lVar17 + 1;

            lVar26 = lVar26 - lVar27;

            do {

              sVar2 = *psVar18;

              sVar3 = psVar18[1];

              sVar4 = psVar18[2];

              *pfVar21 = (float)(int)psVar18[-1];

              pfVar21[1] = (float)(int)sVar2;

              pfVar21[2] = (float)(int)sVar3;

              pfVar21[3] = (float)(int)sVar4;

              psVar18 = psVar18 + 4;

              pfVar21 = pfVar21 + 4;

              lVar26 = lVar26 + -1;

            } while (lVar26 != 0);

LAB_1400466fd:

            FUN_140027900(param_1);

            return piVar10;

          }

        }

        if (0xf < (ulonglong)param_1[3]) {

          puVar23 = (undefined8 *)*param_1;

        }

        pcVar19 = "error allocating sound %s";

      }

    }

    else {

      local_res20[0] = 0;

      puVar9 = param_1;

      if (0xf < uVar13) {

        puVar9 = (undefined8 *)*param_1;

      }

      uVar12 = FUN_140027980(auStack_7d0d0,puVar9);

      piVar10 = (int *)FUN_1400c4a10(uVar12,local_res20);

      if (piVar10 == (int *)0x0) {

        if (0xf < (ulonglong)param_1[3]) {

          puVar23 = (undefined8 *)*param_1;

        }

        pcVar19 = "error loading sound %s";

      }

      else {

        uVar13 = (ulonglong)local_res20[0];

        if (((0xb < uVar13) && (*piVar10 == 0x46464952)) && (piVar10[2] == 0x45564157)) {

          for (piVar22 = piVar10 + 3;

              7 < (longlong)((longlong)piVar10 + (uVar13 - (longlong)piVar22));

              piVar22 = (int *)((longlong)piVar22 + ((ulonglong)(uVar8 + 1) & 0xfffffffe) + 8)) {

            uVar8 = piVar22[1];

            if (*piVar22 == 0x20746d66) {

              if (((longlong)((longlong)piVar10 + (uVar13 - (longlong)piVar22)) <

                   (longlong)(ulonglong)(uVar8 + 8)) || (uVar8 < 0x10)) break;

              uVar5 = *(ushort *)((longlong)piVar22 + 10);

              iVar7 = piVar22[3];

              sVar2 = *(short *)((longlong)piVar22 + 0x16);

              uVar8 = (uint)uVar5;

              if ((uVar8 != 1) && (uVar8 != 2)) break;

              iVar28 = 2;

              if ((short)piVar22[2] == 1) {

                if (sVar2 == 8) {

                  pcVar25 = (code *)&LAB_140046090;

                  local_res18 = 1;

                }

                else if (sVar2 == 0x10) {

                  pcVar25 = (code *)&LAB_1400460c0;

                  local_res18 = 2;

                }

                else {

                  if (sVar2 != 0x18) {

                    if (sVar2 == 0x20) {

                      pcVar25 = FUN_140046130;

                      goto LAB_1400468e3;

                    }

                    break;

                  }

                  pcVar25 = (code *)&LAB_1400460e0;

                  local_res18 = 3;

                }

              }

              else {

                if ((short)piVar22[2] != 3) break;

                if (sVar2 == 0x20) {

                  pcVar25 = (code *)&LAB_140046150;

LAB_1400468e3:

                  local_res18 = 4;

                }

                else {

                  if (sVar2 != 0x40) break;

                  pcVar25 = (code *)&LAB_140046170;

                  local_res18 = 8;

                }

              }

              if (7 < (longlong)((longlong)piVar10 + (uVar13 - (longlong)piVar22)))

              goto LAB_140046900;

              break;

            }

          }

        }

LAB_1400467e2:

        FUN_1400c4de0(piVar10);

LAB_1400467ea:

        if (0xf < (ulonglong)param_1[3]) {

          puVar23 = (undefined8 *)*param_1;

        }

        pcVar19 = "error reading sound %s";

      }

    }

    FUN_1400c4320(pcVar19,puVar23);

  }

  FUN_140027900(param_1);

  return (int *)0x0;

LAB_140046900:

  uVar16 = piVar22[1];

  if (*piVar22 != 0x61746164) goto code_r0x000140046907;

  piVar22 = piVar22 + 2;

  if ((longlong)(ulonglong)uVar16 <= (longlong)((longlong)piVar10 + (uVar13 - (longlong)piVar22))) {

    piVar14 = (int *)_malloc_base(0x20);

    piVar14[3] = 0;

    *piVar14 = iVar7;

    uVar16 = uVar16 / (local_res18 * uVar8);

    piVar14[1] = uVar16;

    piVar14[2] = uVar8;

    iVar7 = (int)((uVar16 + 3 & 0xfffffffc) + ((int)(uVar16 + 3) >> 0x1f & 3U)) >> 2;

    uVar16 = uVar16 & 3;

    lVar11 = (longlong)iVar7 * 0x10;

    uVar8 = iVar7 - 1;

    if (uVar5 == 1) {

      puVar15 = (undefined4 *)FUN_14004a210(lVar11);

      *(undefined4 **)(piVar14 + 4) = puVar15;

      piVar14[6] = 0;

      piVar14[7] = 0;

      if (0 < (int)uVar8) {

        uVar13 = (ulonglong)uVar8;

        puVar24 = puVar15;

        do {

          uVar29 = (*pcVar25)(piVar22,iVar28 + -2,1);

          uVar30 = (*pcVar25)(piVar22,iVar28 + -1,1);

          uVar31 = (*pcVar25)(piVar22,iVar28,1);

          uVar32 = (*pcVar25)(piVar22,iVar28 + 1,1);

          *puVar24 = uVar29;

          puVar24[1] = uVar30;

          puVar24[2] = uVar31;

          puVar24[3] = uVar32;

          iVar28 = iVar28 + 4;

          puVar24 = puVar24 + 4;

          uVar13 = uVar13 - 1;

        } while (uVar13 != 0);

      }

      iVar7 = iVar7 * 4;

      (*pcVar25)(piVar22,iVar7 + -4,1);

      if (1 < uVar16) {

        (*pcVar25)(piVar22,iVar7 + -3,1);

      }

      if (2 < uVar16) {

        (*pcVar25)(piVar22,iVar7 + -2,1);

      }

    }

    else {

      lVar17 = FUN_14004a210((longlong)iVar7 << 5);

      puVar15 = (undefined4 *)(lVar11 + lVar17);

      if (0 < (int)uVar8) {

        uVar13 = (ulonglong)uVar8;

        iVar28 = 4;

        puVar24 = puVar15;

        do {

          uVar29 = (*pcVar25)(piVar22,iVar28 + -4,1);

          uVar30 = (*pcVar25)(piVar22,iVar28 + -2,1);

          uVar31 = (*pcVar25)(piVar22,iVar28,1);

          uVar32 = (*pcVar25)(piVar22,iVar28 + 2,1);

          puVar1 = (undefined4 *)((lVar17 - (longlong)puVar15) + (longlong)puVar24);

          *puVar1 = uVar29;

          puVar1[1] = uVar30;

          puVar1[2] = uVar31;

          puVar1[3] = uVar32;

          uVar29 = (*pcVar25)(piVar22,iVar28 + -3,1);

          uVar30 = (*pcVar25)(piVar22,iVar28 + -1,1);

          uVar31 = (*pcVar25)(piVar22,iVar28 + 1,1);

          uVar32 = (*pcVar25)(piVar22,iVar28 + 3,1);

          *puVar24 = uVar29;

          puVar24[1] = uVar30;

          puVar24[2] = uVar31;

          puVar24[3] = uVar32;

          iVar28 = iVar28 + 8;

          puVar24 = puVar24 + 4;

          uVar13 = uVar13 - 1;

        } while (uVar13 != 0);

      }

      (*pcVar25)(piVar22,iVar7 * 8 + -8,1);

      if (1 < uVar16) {

        (*pcVar25)(piVar22,iVar7 * 8 + -6,1);

      }

      if (2 < uVar16) {

        (*pcVar25)(piVar22,iVar7 * 8 + -4,1);

      }

      (*pcVar25)(piVar22,iVar7 * 8 + -7,1);

      if (1 < uVar16) {

        (*pcVar25)(piVar22,iVar7 * 8 + -5,1);

      }

      if (2 < uVar16) {

        (*pcVar25)(piVar22,iVar7 * 8 + -3,1);

      }

      FUN_14004a120(lVar17,iVar7 + -1);

      *(longlong *)(piVar14 + 4) = lVar17;

      *(undefined4 **)(piVar14 + 6) = puVar15;

    }

    FUN_14004a120(puVar15);

    FUN_1400c4de0(piVar10);

    if (piVar14 != (int *)0x0) {

      FUN_140027900(param_1);

      return piVar14;

    }

    goto LAB_1400467ea;

  }

  goto LAB_1400467e2;

code_r0x000140046907:

  piVar22 = (int *)((longlong)piVar22 + ((ulonglong)(uVar16 + 1) & 0xfffffffe) + 8);

  if ((longlong)((longlong)piVar10 + (uVar13 - (longlong)piVar22)) < 8) goto LAB_1400467e2;

  goto LAB_140046900;

}




