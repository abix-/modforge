// Address: 0x14019ba80
// Ghidra name: FUN_14019ba80
// ============ 0x14019ba80 FUN_14019ba80 (size=1964) ============


longlong FUN_14019ba80(longlong *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4

                      ,uint param_5,int *param_6)



{

  byte *pbVar1;

  uint uVar2;

  undefined8 uVar3;

  bool bVar4;

  bool bVar5;

  byte bVar6;

  undefined1 uVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  longlong lVar11;

  longlong lVar12;

  code *pcVar13;

  char *pcVar14;

  int *piVar15;

  uint uVar16;

  longlong lVar17;

  ulonglong uVar18;

  int *piVar19;

  byte *pbVar20;

  longlong *plVar21;

  ulonglong uVar22;

  ulonglong uVar23;

  longlong lVar24;

  ulonglong uVar25;

  longlong lVar26;

  undefined4 uVar27;

  longlong lVar28;

  uint local_144;

  longlong local_130 [4];

  byte *local_110;

  int local_ec [2];

  int local_e4 [41];

  

  *(undefined4 *)(*param_1 + 8) = 0;

  if (4 < param_5) {

    FUN_14019f050("Internal error");

    return 0;

  }

  iVar8 = FUN_14019ed50();

  if (iVar8 == 0) goto LAB_14019c202;

  uVar16 = 1;

  if (param_5 == 0) {

    param_5 = 1;

    if (2 < *(int *)(*param_1 + 8)) {

      param_5 = 3;

    }

  }

  piVar15 = (int *)*param_1;

  uVar2 = piVar15[2];

  if ((uVar2 == 3) &&

     (((int)param_1[0x90a] == 3 ||

      ((*(int *)((longlong)param_1 + 0x484c) == 0 && ((int)param_1[0x909] == 0)))))) {

    bVar4 = true;

    bVar5 = true;

LAB_14019bb33:

    if ((2 < (int)param_5) || (bVar4)) goto LAB_14019bb43;

  }

  else {

    bVar4 = false;

    bVar5 = false;

    if (uVar2 == 3) goto LAB_14019bb33;

LAB_14019bb43:

    uVar16 = uVar2;

    if ((int)uVar2 < 1) {

LAB_14019c202:

      FUN_14019cdd0(param_1);

      return 0;

    }

  }

  local_130[0] = 0;

  local_130[1] = 0;

  local_130[2] = 0;

  local_130[3] = 0;

  if (param_6 == (int *)0x0) {

    uVar25 = (ulonglong)uVar16;

    if (uVar16 != 0) {

      lVar11 = 0;

      piVar19 = local_ec;

      piVar15 = (int *)((longlong)param_1 + 0x46a4);

      uVar18 = 0;

      do {

        lVar12 = thunk_FUN_1401841f0(*(int *)*param_1 + 3,uVar18);

        *(longlong *)(piVar15 + 0x11) = lVar12;

        if (lVar12 == 0) goto LAB_14019bd19;

        lVar12 = param_1[0x8d1];

        piVar19[3] = 0;

        uVar22 = (longlong)(int)lVar12 / (longlong)*piVar15;

        iVar9 = (int)uVar22;

        piVar19[-1] = iVar9;

        iVar10 = *(int *)((longlong)param_1 + 0x468c) / piVar15[1];

        *piVar19 = iVar10;

        piVar19[2] = iVar10 >> 1;

        iVar8 = *(int *)*param_1;

        uVar3 = *(undefined8 *)(piVar15 + 0xb);

        *(undefined8 *)(piVar19 + -3) = uVar3;

        uVar22 = uVar22 & 0xffffffff;

        uVar23 = (ulonglong)(uint)(iVar8 + -1 + iVar9);

        uVar18 = uVar23 % uVar22;

        *(undefined8 *)(piVar19 + -5) = uVar3;

        piVar19[1] = (int)(uVar23 / uVar22);

        if (iVar9 == 1) {

          if (iVar10 == 1) {

            pcVar13 = FUN_14019c600;

          }

          else {

            if (iVar10 != 2) goto LAB_14019bcd9;

            pcVar13 = FUN_1401a4870;

          }

        }

        else if (iVar9 == 2) {

          if (iVar10 == 1) {

            pcVar13 = FUN_1401a44c0;

          }

          else {

            if (iVar10 != 2) goto LAB_14019bcd9;

            pcVar13 = (code *)param_1[0x910];

          }

        }

        else {

LAB_14019bcd9:

          pcVar13 = (code *)&LAB_1401a4480;

        }

        *(code **)(piVar19 + -7) = pcVar13;

        lVar11 = lVar11 + 1;

        piVar19 = piVar19 + 0xc;

        piVar15 = piVar15 + 0x18;

      } while (lVar11 < (longlong)uVar25);

    }

    lVar11 = FUN_1401a1b30(param_5,*(undefined4 *)*param_1,((undefined4 *)*param_1)[1],1);

    if (lVar11 != 0) {

      piVar15 = (int *)*param_1;

      local_144 = 0;

      lVar12 = local_130[2];

      lVar17 = local_130[0];

      lVar24 = local_130[3];

      lVar28 = local_130[1];

      if (piVar15[1] != 0) {

        do {

          local_110 = (byte *)((ulonglong)(local_144 * *piVar15 * param_5) + lVar11);

          lVar26 = 0;

          if (uVar25 != 0) {

            plVar21 = param_1 + 0x8d8;

            piVar15 = local_e4;

            do {

              lVar12 = 8;

              iVar8 = *piVar15;

              lVar17 = -0x14;

              if (iVar8 < piVar15[-2] >> 1) {

                lVar12 = 0x10;

                lVar17 = -0x1c;

              }

              lVar12 = (**(code **)(piVar15 + -9))

                                 (plVar21[5],*(undefined8 *)(lVar17 + (longlong)piVar15),

                                  *(undefined8 *)(lVar12 + -0x24 + (longlong)piVar15),piVar15[-1],

                                  piVar15[-3]);

              local_130[lVar26] = lVar12;

              iVar8 = iVar8 + 1;

              *piVar15 = iVar8;

              if (piVar15[-2] <= iVar8) {

                piVar15[1] = piVar15[1] + 1;

                *piVar15 = 0;

                *(longlong *)(piVar15 + -7) = *(longlong *)(piVar15 + -5);

                if (piVar15[1] < (int)*plVar21) {

                  *(longlong *)(piVar15 + -5) =

                       (longlong)*(int *)((longlong)plVar21 + 4) + *(longlong *)(piVar15 + -5);

                }

              }

              lVar26 = lVar26 + 1;

              piVar15 = piVar15 + 0xc;

              plVar21 = plVar21 + 0xc;

            } while (lVar26 < (longlong)uVar25);

            piVar15 = (int *)*param_1;

            lVar12 = local_130[2];

            lVar17 = local_130[0];

            lVar24 = local_130[3];

            lVar28 = local_130[1];

          }

          pbVar20 = local_110;

          if ((int)param_5 < 3) {

            if (bVar5) {

              uVar18 = 0;

              if (param_5 == 1) {

                if (*piVar15 != 0) {

                  do {

                    bVar6 = FUN_14019d1d0(*(undefined1 *)(uVar18 + lVar17),

                                          *(undefined1 *)(uVar18 + lVar28),

                                          *(undefined1 *)(uVar18 + lVar12));

                    *pbVar20 = bVar6;

                    pbVar20 = pbVar20 + 1;

                    uVar16 = (int)uVar18 + 1;

                    uVar18 = (ulonglong)uVar16;

                  } while (uVar16 < *(uint *)*param_1);

                }

              }

              else if (*piVar15 != 0) {

                do {

                  bVar6 = FUN_14019d1d0(*(undefined1 *)(uVar18 + lVar17),

                                        *(undefined1 *)(uVar18 + lVar28),

                                        *(undefined1 *)(uVar18 + lVar12));

                  *pbVar20 = bVar6;

                  uVar16 = (int)uVar18 + 1;

                  uVar18 = (ulonglong)uVar16;

                  pbVar20[1] = 0xff;

                  pbVar20 = pbVar20 + 2;

                } while (uVar16 < *(uint *)*param_1);

              }

            }

            else if (piVar15[2] == 4) {

              if (*(int *)((longlong)param_1 + 0x484c) == 0) {

                uVar18 = 0;

                if (*piVar15 != 0) {

                  do {

                    bVar6 = FUN_14019ca40(*(undefined1 *)(uVar18 + lVar12),

                                          *(undefined1 *)(uVar18 + lVar24));

                    uVar23 = (ulonglong)bVar6;

                    bVar6 = FUN_14019ca40(*(undefined1 *)(uVar18 + lVar28));

                    uVar22 = (ulonglong)bVar6;

                    uVar7 = FUN_14019ca40(*(undefined1 *)(uVar18 + lVar17));

                    bVar6 = FUN_14019d1d0(uVar7,uVar22 & 0xffffffff,uVar23 & 0xffffffff);

                    *pbVar20 = bVar6;

                    uVar16 = (int)uVar18 + 1;

                    uVar18 = (ulonglong)uVar16;

                    pbVar20[1] = 0xff;

                    pbVar20 = pbVar20 + (int)param_5;

                  } while (uVar16 < *(uint *)*param_1);

                }

              }

              else {

                if (*(int *)((longlong)param_1 + 0x484c) != 2) goto LAB_14019c137;

                uVar18 = 0;

                if (*piVar15 != 0) {

                  lVar26 = (longlong)(int)param_5;

                  do {

                    bVar6 = FUN_14019ca40(~*(byte *)(uVar18 + lVar17),

                                          *(undefined1 *)(uVar18 + lVar24));

                    *pbVar20 = bVar6;

                    uVar16 = (int)uVar18 + 1;

                    uVar18 = (ulonglong)uVar16;

                    pbVar20[1] = 0xff;

                    pbVar20 = pbVar20 + lVar26;

                  } while (uVar16 < *(uint *)*param_1);

                }

              }

            }

            else {

LAB_14019c137:

              uVar18 = 0;

              if (param_5 == 1) {

                if (*piVar15 != 0) {

                  do {

                    local_110[uVar18] = *(byte *)(uVar18 + lVar17);

                    uVar16 = (int)uVar18 + 1;

                    uVar18 = (ulonglong)uVar16;

                  } while (uVar16 < *(uint *)*param_1);

                }

              }

              else if (*piVar15 != 0) {

                do {

                  pbVar1 = (byte *)(uVar18 + lVar17);

                  uVar16 = (int)uVar18 + 1;

                  uVar18 = (ulonglong)uVar16;

                  *pbVar20 = *pbVar1;

                  pbVar20[1] = 0xff;

                  pbVar20 = pbVar20 + 2;

                } while (uVar16 < *(uint *)*param_1);

              }

            }

          }

          else if (piVar15[2] == 3) {

            if (bVar5) {

              uVar18 = 0;

              if (*piVar15 != 0) {

                do {

                  *pbVar20 = *(byte *)(uVar18 + lVar17);

                  pbVar20[1] = *(byte *)(uVar18 + lVar28);

                  pbVar1 = (byte *)(uVar18 + lVar12);

                  uVar16 = (int)uVar18 + 1;

                  uVar18 = (ulonglong)uVar16;

                  pbVar20[2] = *pbVar1;

                  pbVar20[3] = 0xff;

                  pbVar20 = pbVar20 + (int)param_5;

                } while (uVar16 < *(uint *)*param_1);

              }

            }

            else {

              iVar8 = *piVar15;

              pcVar13 = (code *)param_1[0x90f];

LAB_14019beca:

              (*pcVar13)(local_110,lVar17,lVar28,lVar12,iVar8,param_5);

            }

          }

          else if (piVar15[2] == 4) {

            if (*(int *)((longlong)param_1 + 0x484c) == 0) {

              uVar18 = 0;

              if (*piVar15 != 0) {

                lVar26 = (longlong)(int)param_5;

                do {

                  bVar6 = FUN_14019ca40(*(undefined1 *)(uVar18 + lVar17),

                                        *(undefined1 *)(uVar18 + lVar24));

                  *pbVar20 = bVar6;

                  bVar6 = FUN_14019ca40(*(undefined1 *)(uVar18 + lVar28));

                  pbVar20[1] = bVar6;

                  bVar6 = FUN_14019ca40(*(undefined1 *)(uVar18 + lVar12));

                  pbVar20[2] = bVar6;

                  uVar16 = (int)uVar18 + 1;

                  uVar18 = (ulonglong)uVar16;

                  pbVar20[3] = 0xff;

                  pbVar20 = pbVar20 + lVar26;

                } while (uVar16 < *(uint *)*param_1);

              }

            }

            else {

              iVar8 = *piVar15;

              pcVar13 = (code *)param_1[0x90f];

              if (*(int *)((longlong)param_1 + 0x484c) != 2) goto LAB_14019beca;

              (*pcVar13)(local_110,lVar17,lVar28,lVar12,iVar8,param_5);

              uVar18 = 0;

              if (*(int *)*param_1 != 0) {

                lVar26 = (longlong)(int)param_5;

                do {

                  bVar6 = FUN_14019ca40(~*pbVar20,*(undefined1 *)(uVar18 + lVar24));

                  iVar8 = (int)uVar18;

                  *pbVar20 = bVar6;

                  bVar6 = FUN_14019ca40(~pbVar20[1]);

                  pbVar20[1] = bVar6;

                  bVar6 = FUN_14019ca40(~pbVar20[2]);

                  pbVar20[2] = bVar6;

                  uVar18 = (ulonglong)(iVar8 + 1U);

                  pbVar20 = pbVar20 + lVar26;

                } while (iVar8 + 1U < *(uint *)*param_1);

              }

            }

          }

          else {

            uVar18 = 0;

            if (*piVar15 != 0) {

              do {

                bVar6 = *(byte *)(uVar18 + lVar17);

                uVar16 = (int)uVar18 + 1;

                uVar18 = (ulonglong)uVar16;

                pbVar20[2] = bVar6;

                pbVar20[1] = bVar6;

                *pbVar20 = bVar6;

                pbVar20[3] = 0xff;

                pbVar20 = pbVar20 + (int)param_5;

              } while (uVar16 < *(uint *)*param_1);

            }

          }

          piVar15 = (int *)*param_1;

          local_144 = local_144 + 1;

        } while (local_144 < (uint)piVar15[1]);

      }

LAB_14019c1ba:

      FUN_14019cdd0(param_1);

      *param_2 = *(undefined4 *)*param_1;

      *param_3 = *(undefined4 *)(*param_1 + 4);

      if (param_4 == (undefined4 *)0x0) {

        return lVar11;

      }

      uVar27 = 1;

      if (2 < *(int *)(*param_1 + 8)) {

        uVar27 = 3;

      }

      *param_4 = uVar27;

      return lVar11;

    }

LAB_14019bd19:

    FUN_14019cdd0(param_1);

    pcVar14 = "Out of memory";

  }

  else if ((*param_6 == *piVar15) && (param_6[1] == piVar15[1])) {

    if (!bVar4) {

      lVar11 = FUN_14019c3f0(param_1);

      goto LAB_14019c1ba;

    }

    FUN_14019cdd0();

    pcVar14 = "Can\'t convert RGB to NV12";

  }

  else {

    FUN_14019cdd0(param_1);

    pcVar14 = "Unexpected size";

  }

  FUN_14019f050(pcVar14);

  return 0;

}




