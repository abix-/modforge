// Address: 0x14004b960
// Ghidra name: FUN_14004b960
// ============ 0x14004b960 FUN_14004b960 (size=2740) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



void FUN_14004b960(longlong param_1,longlong *param_2,int param_3,uint param_4,uint param_5,

                  longlong param_6)



{

  byte bVar1;

  short sVar2;

  byte *pbVar3;

  undefined8 uVar4;

  longlong lVar5;

  int iVar6;

  int iVar7;

  ulonglong uVar8;

  longlong lVar9;

  int iVar10;

  uint uVar11;

  ulonglong uVar12;

  longlong *plVar13;

  longlong lVar14;

  undefined1 *puVar15;

  uint uVar16;

  longlong lVar17;

  longlong lVar18;

  ulonglong uVar19;

  uint *puVar20;

  short sVar21;

  longlong lVar22;

  uint *puVar23;

  longlong lVar24;

  int *piVar25;

  bool bVar26;

  int local_res8 [2];

  longlong *local_res10;

  uint local_res18;

  undefined1 auStack_d8 [64];

  uint *local_98 [2];

  longlong local_88;

  longlong local_80;

  longlong local_78;

  longlong local_70;

  longlong local_68;

  int local_60;

  longlong local_58;

  longlong *local_50;

  longlong local_48;

  longlong local_40;

  

  lVar24 = param_6;

  puVar15 = auStack_d8;

  puVar23 = (uint *)((longlong)(int)param_5 * 0x20 + *(longlong *)(param_1 + 0x1d8));

  lVar22 = (longlong)param_3;

  sVar21 = *(short *)(param_1 + 0x154 + (longlong)(int)param_5 * 2);

  param_5 = CONCAT22(param_5._2_2_,sVar21);

  local_98[0] = puVar23;

  lVar17 = (longlong)

           *(int *)((ulonglong)*(byte *)((longlong)puVar23 + 0xd) * 0x848 +

                   *(longlong *)(param_1 + 0xb8));

  uVar11 = param_4 * 2;

  if (sVar21 != 2) {

    uVar11 = param_4;

  }

  local_60 = *(int *)(param_1 + 0x94);

  uVar16 = uVar11;

  if (*puVar23 < uVar11) {

    uVar16 = *puVar23;

  }

  if (puVar23[1] < uVar11) {

    uVar11 = puVar23[1];

  }

  local_res18 = (uVar11 - uVar16) / puVar23[2];

  lVar14 = (longlong)*(int *)(param_1 + 4);

  uVar19 = (ulonglong)(int)local_res18;

  if (*(longlong *)(param_1 + 0x80) == 0) {

    uVar12 = (uVar19 + 1) * lVar14 * 8;

    uVar8 = uVar12 + 0xf;

    if (uVar8 <= uVar12) {

      uVar8 = 0xffffffffffffff0;

    }

    puVar15 = auStack_d8 + -(uVar8 & 0xfffffffffffffff0);

    puVar20 = (uint *)((longlong)local_98 + -(uVar8 & 0xfffffffffffffff0));

  }

  else {

    iVar10 = *(int *)(param_1 + 0x94) - (local_res18 * 8 + 8) * *(int *)(param_1 + 4);

    if (iVar10 < *(int *)(param_1 + 0x90)) {

      puVar20 = (uint *)0x0;

      puVar15 = auStack_d8;

    }

    else {

      puVar20 = (uint *)((longlong)iVar10 + *(longlong *)(param_1 + 0x80));

      *(int *)(param_1 + 0x94) = iVar10;

    }

  }

  local_98[1] = puVar20;

  plVar13 = (longlong *)((longlong)puVar20 + lVar14 * 8);

  if (0 < lVar14) {

    lVar9 = 0;

    do {

      *(longlong **)((longlong)puVar20 + lVar9 * 8) = plVar13;

      plVar13 = (longlong *)((longlong)plVar13 + (longlong)(int)(local_res18 * 8));

      lVar9 = lVar9 + 1;

    } while (lVar9 < lVar14);

  }

  local_88 = lVar22;

  local_res10 = param_2;

  if (0 < param_3) {

    lVar14 = 0;

    do {

      if (*(char *)(lVar14 + lVar24) == '\0') {

        *(undefined8 *)(puVar15 + -8) = 0x14004bad9;

        FUN_1402f94c0();

      }

      lVar14 = lVar14 + 1;

    } while (lVar14 < lVar22);

    uVar19 = (ulonglong)local_res18;

    puVar20 = local_98[1];

    puVar23 = local_98[0];

  }

  local_80 = lVar17;

  if (((short)param_5 == 2) && (param_3 != 1)) {

    iVar10 = 0;

    if (0 < lVar22) {

      lVar17 = 0;

      do {

        if (*(char *)(lVar17 + lVar24) == '\0') break;

        iVar10 = iVar10 + 1;

        lVar17 = lVar17 + 1;

      } while (lVar17 < lVar22);

    }

    if (iVar10 != param_3) {

      lVar24 = 0;

      do {

        iVar10 = 0;

        if (param_3 == 2) {

          if (0 < (int)local_res18) {

            lVar17 = 0;

            puVar23 = local_98[0];

            uVar11 = local_res18;

            do {

              param_5 = iVar10 * puVar23[2] + *puVar23;

              local_res8[0] = (int)param_5 >> 1;

              param_5 = param_5 & 1;

              if (lVar24 == 0) {

                lVar22 = (ulonglong)*(byte *)((longlong)puVar23 + 0xd) * 0x848 +

                         *(longlong *)(param_1 + 0xb8);

                if (*(int *)(param_1 + 0x6f8) < 10) {

                  if (*(int *)(param_1 + 0x6f8) == 0) {

                    *(undefined4 *)(param_1 + 0x6f4) = 0;

                  }

                  do {

                    if (*(int *)(param_1 + 0x6ec) == 0) {

                      if (*(char *)(param_1 + 0x6e4) == '\0') {

                        *(undefined8 *)(puVar15 + -8) = 0x14004bbe5;

                        iVar6 = FUN_14004eeb0();

                        bVar26 = iVar6 == 0;

                        goto LAB_14004bbe7;

                      }

                    }

                    else {

                      bVar26 = *(char *)(param_1 + 0x6e4) == '\0';

LAB_14004bbe7:

                      if (bVar26) break;

                    }

                    *(char *)(param_1 + 0x6e4) = *(char *)(param_1 + 0x6e4) + -1;

                    *(int *)(param_1 + 0x6fc) = *(int *)(param_1 + 0x6fc) + 1;

                    pbVar3 = *(byte **)(param_1 + 0x40);

                    if (pbVar3 == (byte *)0x0) {

                      uVar4 = *(undefined8 *)(param_1 + 0x30);

                      *(undefined8 *)(puVar15 + -8) = 0x14004bc19;

                      uVar11 = FUN_1402ce36c(uVar4);

                      if (uVar11 == 0xffffffff) goto LAB_14004bc20;

                    }

                    else if (pbVar3 < *(byte **)(param_1 + 0x50)) {

                      uVar11 = (uint)*pbVar3;

                      *(byte **)(param_1 + 0x40) = pbVar3 + 1;

                    }

                    else {

LAB_14004bc20:

                      uVar11 = 0;

                      *(undefined4 *)(param_1 + 0x98) = 1;

                    }

                    *(int *)(param_1 + 0x6f4) =

                         *(int *)(param_1 + 0x6f4) +

                         ((uVar11 & 0xff) << ((byte)*(int *)(param_1 + 0x6f8) & 0x1f));

                    iVar6 = *(int *)(param_1 + 0x6f8) + 8;

                    *(int *)(param_1 + 0x6f8) = iVar6;

                  } while (iVar6 < 0x19);

                }

                sVar21 = *(short *)(lVar22 + 0x30 +

                                   (ulonglong)(*(uint *)(param_1 + 0x6f4) & 0x3ff) * 2);

                uVar19 = (ulonglong)sVar21;

                if (sVar21 < 0) {

                  *(undefined8 *)(puVar15 + -8) = 0x14004bc9e;

                  uVar11 = FUN_140048360(param_1,lVar22);

                  uVar19 = (ulonglong)uVar11;

                }

                else {

                  bVar1 = *(byte *)(*(longlong *)(lVar22 + 8) + uVar19);

                  piVar25 = (int *)(param_1 + 0x6f8);

                  *piVar25 = *piVar25 - (uint)bVar1;

                  *(uint *)(param_1 + 0x6f4) = *(uint *)(param_1 + 0x6f4) >> (bVar1 & 0x1f);

                  if (*piVar25 < 0) {

                    *(undefined4 *)(param_1 + 0x6f8) = 0;

                    uVar19 = 0xffffffff;

                  }

                }

                iVar6 = (int)uVar19;

                if (*(char *)(lVar22 + 0x1b) != '\0') {

                  iVar6 = *(int *)(*(longlong *)(lVar22 + 0x838) + (longlong)iVar6 * 4);

                }

                if (iVar6 == -1) goto LAB_14004c3f4;

                *(undefined8 *)(lVar17 + *(longlong *)local_98[1]) =

                     *(undefined8 *)(*(longlong *)(local_98[0] + 4) + (longlong)iVar6 * 8);

                puVar23 = local_98[0];

                uVar11 = local_res18;

              }

              lVar22 = 0;

              puVar20 = local_98[1];

              if (0 < local_80) {

                do {

                  if ((int)uVar11 <= iVar10) break;

                  sVar21 = *(short *)(*(longlong *)(puVar23 + 6) +

                                     (lVar24 + (ulonglong)

                                               *(byte *)(*(longlong *)

                                                          (*(longlong *)puVar20 + lVar17) + lVar22)

                                               * 8) * 2);

                  if (sVar21 < 0) {

                    uVar11 = (iVar10 + 1) * puVar23[2] + *puVar23;

                    param_5 = uVar11 & 1;

                    local_res8[0] = (int)uVar11 >> 1;

                  }

                  else {

                    *(uint *)(puVar15 + 0x38) = puVar23[2];

                    *(uint *)(puVar15 + 0x30) = param_4;

                    lVar14 = *(longlong *)(param_1 + 0xb8);

                    *(int **)(puVar15 + 0x28) = local_res8;

                    *(uint **)(puVar15 + 0x20) = &param_5;

                    *(undefined8 *)(puVar15 + -8) = 0x14004bd62;

                    iVar6 = FUN_140047cd0(param_1,(longlong)sVar21 * 0x848 + lVar14,local_res10,2);

                    puVar23 = local_98[0];

                    puVar20 = local_98[1];

                    if (iVar6 == 0) goto LAB_14004c3f4;

                  }

                  lVar22 = lVar22 + 1;

                  iVar10 = iVar10 + 1;

                  uVar11 = local_res18;

                } while (lVar22 < local_80);

              }

              lVar17 = lVar17 + 8;

            } while (iVar10 < (int)uVar11);

          }

        }

        else if ((2 < param_3) && (0 < (int)local_res18)) {

          lVar17 = 0;

          puVar23 = local_98[0];

          uVar11 = local_res18;

          do {

            iVar6 = iVar10 * puVar23[2] + *puVar23;

            local_res8[0] = iVar6 / param_3;

            param_5 = iVar6 % param_3;

            if (lVar24 == 0) {

              lVar22 = (ulonglong)*(byte *)((longlong)puVar23 + 0xd) * 0x848 +

                       *(longlong *)(param_1 + 0xb8);

              if (*(int *)(param_1 + 0x6f8) < 10) {

                if (*(int *)(param_1 + 0x6f8) == 0) {

                  *(undefined4 *)(param_1 + 0x6f4) = 0;

                }

                do {

                  if (*(int *)(param_1 + 0x6ec) == 0) {

                    if (*(char *)(param_1 + 0x6e4) == '\0') {

                      *(undefined8 *)(puVar15 + -8) = 0x14004be53;

                      iVar6 = FUN_14004eeb0();

                      bVar26 = iVar6 == 0;

                      goto LAB_14004be55;

                    }

                  }

                  else {

                    bVar26 = *(char *)(param_1 + 0x6e4) == '\0';

LAB_14004be55:

                    if (bVar26) break;

                  }

                  *(char *)(param_1 + 0x6e4) = *(char *)(param_1 + 0x6e4) + -1;

                  *(int *)(param_1 + 0x6fc) = *(int *)(param_1 + 0x6fc) + 1;

                  pbVar3 = *(byte **)(param_1 + 0x40);

                  if (pbVar3 == (byte *)0x0) {

                    uVar4 = *(undefined8 *)(param_1 + 0x30);

                    *(undefined8 *)(puVar15 + -8) = 0x14004be87;

                    uVar11 = FUN_1402ce36c(uVar4);

                    if (uVar11 == 0xffffffff) goto LAB_14004be8e;

                  }

                  else if (pbVar3 < *(byte **)(param_1 + 0x50)) {

                    uVar11 = (uint)*pbVar3;

                    *(byte **)(param_1 + 0x40) = pbVar3 + 1;

                  }

                  else {

LAB_14004be8e:

                    uVar11 = 0;

                    *(undefined4 *)(param_1 + 0x98) = 1;

                  }

                  *(int *)(param_1 + 0x6f4) =

                       *(int *)(param_1 + 0x6f4) +

                       ((uVar11 & 0xff) << ((byte)*(int *)(param_1 + 0x6f8) & 0x1f));

                  iVar6 = *(int *)(param_1 + 0x6f8) + 8;

                  *(int *)(param_1 + 0x6f8) = iVar6;

                } while (iVar6 < 0x19);

              }

              sVar21 = *(short *)(lVar22 + 0x30 +

                                 (ulonglong)(*(uint *)(param_1 + 0x6f4) & 0x3ff) * 2);

              uVar19 = (ulonglong)sVar21;

              if (sVar21 < 0) {

                *(undefined8 *)(puVar15 + -8) = 0x14004bf0c;

                uVar11 = FUN_140048360(param_1,lVar22);

                uVar19 = (ulonglong)uVar11;

              }

              else {

                bVar1 = *(byte *)(*(longlong *)(lVar22 + 8) + uVar19);

                piVar25 = (int *)(param_1 + 0x6f8);

                *piVar25 = *piVar25 - (uint)bVar1;

                *(uint *)(param_1 + 0x6f4) = *(uint *)(param_1 + 0x6f4) >> (bVar1 & 0x1f);

                if (*piVar25 < 0) {

                  *(undefined4 *)(param_1 + 0x6f8) = 0;

                  uVar19 = 0xffffffff;

                }

              }

              iVar6 = (int)uVar19;

              if (*(char *)(lVar22 + 0x1b) != '\0') {

                iVar6 = *(int *)(*(longlong *)(lVar22 + 0x838) + (longlong)iVar6 * 4);

              }

              if (iVar6 == -1) goto LAB_14004c3f4;

              *(undefined8 *)(lVar17 + *(longlong *)local_98[1]) =

                   *(undefined8 *)(*(longlong *)(local_98[0] + 4) + (longlong)iVar6 * 8);

              puVar23 = local_98[0];

              puVar20 = local_98[1];

              uVar11 = local_res18;

            }

            lVar22 = 0;

            if (0 < local_80) {

              do {

                if ((int)uVar11 <= iVar10) break;

                sVar21 = *(short *)(*(longlong *)(puVar23 + 6) +

                                   (lVar24 + (ulonglong)

                                             *(byte *)(*(longlong *)(*(longlong *)puVar20 + lVar17)

                                                      + lVar22) * 8) * 2);

                if (sVar21 < 0) {

                  iVar6 = (iVar10 + 1) * puVar23[2] + *puVar23;

                  local_res8[0] = iVar6 / param_3;

                  param_5 = iVar6 % param_3;

                }

                else {

                  *(uint *)(puVar15 + 0x38) = puVar23[2];

                  *(uint *)(puVar15 + 0x30) = param_4;

                  lVar14 = *(longlong *)(param_1 + 0xb8);

                  *(int **)(puVar15 + 0x28) = local_res8;

                  *(uint **)(puVar15 + 0x20) = &param_5;

                  *(undefined8 *)(puVar15 + -8) = 0x14004bfc3;

                  iVar6 = FUN_140047cd0(param_1,(longlong)sVar21 * 0x848 + lVar14,local_res10,

                                        param_3);

                  puVar23 = local_98[0];

                  puVar20 = local_98[1];

                  if (iVar6 == 0) goto LAB_14004c3f4;

                }

                lVar22 = lVar22 + 1;

                iVar10 = iVar10 + 1;

                uVar11 = local_res18;

              } while (lVar22 < local_80);

            }

            lVar17 = lVar17 + 8;

          } while (iVar10 < (int)uVar11);

        }

        lVar24 = lVar24 + 1;

        puVar20 = local_98[1];

      } while (lVar24 < 8);

    }

  }

  else {

    local_68 = 0;

    sVar21 = (short)param_5;

    do {

      iVar10 = 0;

      local_res8[0] = 0;

      lVar14 = local_68;

      if (0 < (int)uVar19) {

        local_48 = 0;

        do {

          lVar9 = local_48;

          if ((lVar14 == 0) && (lVar18 = 0, 0 < lVar22)) {

            do {

              if (*(char *)(lVar18 + lVar24) == '\0') {

                lVar17 = (ulonglong)*(byte *)((longlong)puVar23 + 0xd) * 0x848 +

                         *(longlong *)(param_1 + 0xb8);

                if (*(int *)(param_1 + 0x6f8) < 10) {

                  if (*(int *)(param_1 + 0x6f8) == 0) {

                    *(undefined4 *)(param_1 + 0x6f4) = 0;

                  }

                  do {

                    if (*(int *)(param_1 + 0x6ec) == 0) {

                      if (*(char *)(param_1 + 0x6e4) == '\0') {

                        *(undefined8 *)(puVar15 + -8) = 0x14004c0c3;

                        iVar10 = FUN_14004eeb0();

                        bVar26 = iVar10 == 0;

                        goto LAB_14004c0c5;

                      }

                    }

                    else {

                      bVar26 = *(char *)(param_1 + 0x6e4) == '\0';

LAB_14004c0c5:

                      if (bVar26) break;

                    }

                    *(char *)(param_1 + 0x6e4) = *(char *)(param_1 + 0x6e4) + -1;

                    *(int *)(param_1 + 0x6fc) = *(int *)(param_1 + 0x6fc) + 1;

                    pbVar3 = *(byte **)(param_1 + 0x40);

                    if (pbVar3 == (byte *)0x0) {

                      uVar4 = *(undefined8 *)(param_1 + 0x30);

                      *(undefined8 *)(puVar15 + -8) = 0x14004c0f7;

                      uVar11 = FUN_1402ce36c(uVar4);

                      if (uVar11 == 0xffffffff) goto LAB_14004c0fe;

                    }

                    else if (pbVar3 < *(byte **)(param_1 + 0x50)) {

                      uVar11 = (uint)*pbVar3;

                      *(byte **)(param_1 + 0x40) = pbVar3 + 1;

                    }

                    else {

LAB_14004c0fe:

                      uVar11 = 0;

                      *(undefined4 *)(param_1 + 0x98) = 1;

                    }

                    *(int *)(param_1 + 0x6f4) =

                         *(int *)(param_1 + 0x6f4) +

                         ((uVar11 & 0xff) << ((byte)*(int *)(param_1 + 0x6f8) & 0x1f));

                    iVar10 = *(int *)(param_1 + 0x6f8) + 8;

                    *(int *)(param_1 + 0x6f8) = iVar10;

                  } while (iVar10 < 0x19);

                }

                sVar21 = *(short *)(lVar17 + 0x30 +

                                   (ulonglong)(*(uint *)(param_1 + 0x6f4) & 0x3ff) * 2);

                uVar19 = (ulonglong)sVar21;

                if (sVar21 < 0) {

                  *(undefined8 *)(puVar15 + -8) = 0x14004c17c;

                  uVar11 = FUN_140048360(param_1,lVar17);

                  uVar19 = (ulonglong)uVar11;

                }

                else {

                  bVar1 = *(byte *)(*(longlong *)(lVar17 + 8) + uVar19);

                  piVar25 = (int *)(param_1 + 0x6f8);

                  *piVar25 = *piVar25 - (uint)bVar1;

                  *(uint *)(param_1 + 0x6f4) = *(uint *)(param_1 + 0x6f4) >> (bVar1 & 0x1f);

                  if (*piVar25 < 0) {

                    *(undefined4 *)(param_1 + 0x6f8) = 0;

                    uVar19 = 0xffffffff;

                  }

                }

                iVar10 = (int)uVar19;

                if (*(char *)(lVar17 + 0x1b) != '\0') {

                  iVar10 = *(int *)(*(longlong *)(lVar17 + 0x838) + (longlong)iVar10 * 4);

                }

                if (iVar10 == -1) goto LAB_14004c3f4;

                *(undefined8 *)(lVar9 + *(longlong *)((longlong)local_98[1] + lVar18 * 8)) =

                     *(undefined8 *)(*(longlong *)(puVar23 + 4) + (longlong)iVar10 * 8);

                lVar22 = local_88;

              }

              lVar18 = lVar18 + 1;

            } while (lVar18 < lVar22);

            uVar19 = (ulonglong)local_res18;

            lVar17 = local_80;

            sVar21 = (short)param_5;

            iVar10 = local_res8[0];

          }

          local_78 = 0;

          if (0 < lVar17) {

            do {

              if ((int)uVar19 <= iVar10) break;

              local_58 = 0;

              lVar18 = local_78;

              if (0 < lVar22) {

                lVar17 = (longlong)local_98[1] - (longlong)local_res10;

                lVar22 = local_88;

                local_50 = local_res10;

                local_70 = lVar17;

                do {

                  if ((*(char *)(local_58 + lVar24) == '\0') &&

                     (sVar2 = *(short *)(*(longlong *)(puVar23 + 6) +

                                        ((ulonglong)

                                         *(byte *)(*(longlong *)

                                                    (*(longlong *)(lVar17 + (longlong)local_50) +

                                                    lVar9) + lVar18) * 8 + lVar14) * 2),

                     lVar17 = local_70, lVar22 = local_88, lVar18 = local_78, -1 < sVar2)) {

                    uVar11 = puVar23[2];

                    uVar19 = 0;

                    lVar5 = *local_50;

                    piVar25 = (int *)((longlong)sVar2 * 0x848 + *(longlong *)(param_1 + 0xb8));

                    iVar6 = uVar11 * iVar10 + *local_98[0];

                    lVar24 = param_6;

                    lVar14 = local_68;

                    puVar23 = local_98[0];

                    if (sVar21 == 0) {

                      iVar7 = (int)uVar11 / *piVar25;

                      lVar9 = local_48;

                      if (0 < iVar7) {

                        local_40 = (longlong)iVar6;

                        iVar6 = uVar11 - iVar6;

                        do {

                          lVar24 = uVar19 + local_40;

                          *(int *)(puVar15 + 0x20) = iVar7;

                          *(undefined8 *)(puVar15 + -8) = 0x14004c2d3;

                          iVar10 = FUN_140048740(param_1,piVar25,lVar24 * 4 + lVar5,iVar6);

                          if (iVar10 == 0) goto LAB_14004c3f4;

                          uVar11 = (int)uVar19 + 1;

                          uVar19 = (ulonglong)uVar11;

                          iVar6 = iVar6 + -1;

                          lVar17 = local_70;

                          lVar22 = local_88;

                          lVar18 = local_78;

                          lVar9 = local_48;

                          lVar14 = local_68;

                          puVar23 = local_98[0];

                          lVar24 = param_6;

                          iVar10 = local_res8[0];

                        } while ((int)uVar11 < iVar7);

                      }

                    }

                    else if (0 < (int)uVar11) {

                      do {

                        *(undefined8 *)(puVar15 + -8) = 0x14004c32f;

                        iVar10 = FUN_1400479b0(param_1,piVar25,(longlong)iVar6 * 4 + lVar5,

                                               uVar11 - (int)uVar19);

                        if (iVar10 == 0) goto LAB_14004c3f4;

                        uVar16 = (int)uVar19 + *piVar25;

                        uVar19 = (ulonglong)uVar16;

                        iVar6 = iVar6 + *piVar25;

                        lVar17 = local_70;

                        lVar22 = local_88;

                        lVar18 = local_78;

                        lVar14 = local_68;

                        puVar23 = local_98[0];

                        lVar24 = param_6;

                        iVar10 = local_res8[0];

                      } while ((int)uVar16 < (int)uVar11);

                    }

                  }

                  local_58 = local_58 + 1;

                  local_50 = local_50 + 1;

                  sVar21 = (short)param_5;

                } while (local_58 < lVar22);

                uVar19 = (ulonglong)local_res18;

                lVar17 = local_80;

                lVar22 = local_88;

              }

              local_78 = lVar18 + 1;

              iVar10 = iVar10 + 1;

              sVar21 = (short)param_5;

              local_res8[0] = iVar10;

            } while (local_78 < lVar17);

          }

          local_48 = lVar9 + 8;

          sVar21 = (short)param_5;

        } while (iVar10 < (int)uVar19);

      }

      local_68 = lVar14 + 1;

    } while (local_68 < 8);

  }

LAB_14004c3f4:

  *(int *)(param_1 + 0x94) = local_60;

  return;

}




