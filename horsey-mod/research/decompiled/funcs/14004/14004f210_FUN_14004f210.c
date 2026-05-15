// Address: 0x14004f210
// Ghidra name: FUN_14004f210
// ============ 0x14004f210 FUN_14004f210 (size=5901) ============


/* WARNING: Type propagation algorithm not settling */



undefined8 FUN_14004f210(longlong param_1,uint param_2)



{

  byte bVar1;

  char *pcVar2;

  byte *pbVar3;

  double dVar4;

  double dVar5;

  double dVar6;

  byte bVar7;

  byte bVar8;

  byte bVar9;

  char cVar10;

  uint uVar11;

  uint uVar12;

  int iVar13;

  int iVar14;

  int iVar15;

  longlong lVar16;

  uint uVar17;

  ulonglong uVar18;

  int iVar19;

  char *pcVar20;

  int *piVar21;

  uint uVar22;

  ulonglong uVar23;

  uint uVar24;

  ulonglong uVar25;

  uint uVar26;

  ulonglong uVar27;

  bool bVar28;

  double dVar29;

  double dVar30;

  undefined4 uVar31;

  undefined4 uVar32;

  uint local_res18 [2];

  uint local_res20 [2];

  char local_f4 [4];

  byte local_f0;

  byte local_ef;

  byte local_ee;

  byte local_ed;

  byte local_ec;

  byte local_eb;

  byte local_ea;

  byte local_e9;

  byte local_e8;

  byte local_e7;

  byte local_e6;

  byte local_e5;

  byte local_e4;

  byte local_e3;

  byte local_e2;

  byte local_e1;

  byte local_e0;

  byte local_df;

  byte local_de;

  ulonglong local_d8;

  undefined8 local_d0;

  uint local_c8;

  uint local_c0;

  uint local_b8;

  undefined4 uStack_b4;

  uint local_b0;

  uint local_a8;

  uint local_a4;

  undefined8 local_a0;

  

  uVar26 = 0;

  uVar31 = 0;

  uVar32 = 0;

  dVar4 = 0.0;

  local_c0 = 0;

  uVar11 = FUN_140042950();

  if (uVar11 == 0) {

    *(undefined4 *)(param_1 + 0x9c) = 7;

    return 0;

  }

  if (uVar11 < param_2) {

    *(undefined4 *)(param_1 + 0x9c) = 0xb;

    return 0;

  }

  uVar17 = *(int *)(param_1 + 0xac) - *(int *)(param_1 + 0xa8) >> 2;

  uVar12 = param_2 - uVar17;

  uVar24 = *(uint *)(param_1 + 0x6c);

  uVar23 = *(ulonglong *)(param_1 + 100);

  local_a4 = uVar26;

  dVar5 = DAT_1403053e0;

  dVar6 = DAT_1403053f8;

  uVar11 = uVar26;

  if (uVar17 <= param_2) {

    local_a4 = uVar12;

    uVar11 = uVar12;

  }

  do {

    local_res18[0] = uVar24;

    local_d0._4_4_ = (uint)(uVar23 >> 0x20);

    uVar24 = local_d0._4_4_;

    DAT_1403053e0 = dVar5;

    DAT_1403053f8 = dVar6;

    local_d0 = uVar23;

    local_c8 = local_res18[0];

    if (local_res18[0] != 0xffffffff) {

      local_a0 = *(ulonglong *)(param_1 + 0x70);

      local_res20[0] = *(uint *)(param_1 + 0x78);

      if (local_res18[0] < uVar11) {

        uVar23 = uVar23 & 0xffffffff;

        bVar28 = local_d0._4_4_ == (uint)local_a0;

        uVar12 = (uint)local_a0;

        local_d8 = uVar23;

        if (bVar28) goto LAB_14004fb22;

        goto LAB_14004f390;

      }

      iVar13 = FUN_1400428f0(param_1);

      if (iVar13 == 0) {

        return 0;

      }

      uVar26 = *(uint *)(param_1 + 0x580);

      goto LAB_14005090d;

    }

    FUN_140050920(param_1,uVar24);

    iVar13 = FUN_14004cc90(param_1,&local_d0);

    uVar24 = local_c8;

    uVar23 = local_d0;

    dVar5 = DAT_1403053e0;

    dVar6 = DAT_1403053f8;

  } while (iVar13 != 0);

LAB_14004f9f5:

  if (*(char *)(param_1 + 0x5c) == '\0') {

    FUN_140050920(param_1,*(undefined4 *)(param_1 + 0x60));

    iVar13 = 0;

    *(undefined4 *)(param_1 + 0x4f8) = 0;

    *(undefined1 *)(param_1 + 0x6e5) = 1;

    *(undefined4 *)(param_1 + 0x6e8) = 0xffffffff;

    *(undefined8 *)(param_1 + 0x764) = 0;

    if (*(int *)(param_1 + 0x98) == 0) {

LAB_14004fa40:

      if (*(int *)(param_1 + 0x6e8) == -1) {

        pcVar20 = *(char **)(param_1 + 0x40);

        if (pcVar20 == (char *)0x0) {

          iVar14 = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

          cVar10 = (char)iVar14;

          if (iVar14 == -1) goto LAB_1400501e3;

        }

        else if (pcVar20 < *(char **)(param_1 + 0x50)) {

          cVar10 = *pcVar20;

          *(char **)(param_1 + 0x40) = pcVar20 + 1;

        }

        else {

LAB_1400501e3:

          cVar10 = '\0';

          *(undefined4 *)(param_1 + 0x98) = 1;

        }

        if ((((*(int *)(param_1 + 0x98) != 0) || (cVar10 != 'O')) ||

            (cVar10 = FUN_14004ca60(param_1), cVar10 != 'g')) ||

           (((cVar10 = FUN_14004ca60(param_1), cVar10 != 'g' ||

             (cVar10 = FUN_14004ca60(param_1), cVar10 != 'S')) ||

            (iVar14 = FUN_140053810(param_1), iVar14 == 0)))) goto LAB_1400504eb;

        if ((*(byte *)(param_1 + 0x6e3) & 1) != 0) {

          *(undefined4 *)(param_1 + 0x6ec) = 0;

          *(undefined1 *)(param_1 + 0x6e4) = 0;

          *(undefined4 *)(param_1 + 0x9c) = 0x25;

          return 0;

        }

      }

      iVar14 = FUN_1400535f0();

      if (iVar14 != 0) {

        piVar21 = (int *)(param_1 + 0x6f8);

        iVar14 = *piVar21;

        if (-1 < iVar14) {

          if (iVar14 < 1) {

            *(undefined4 *)(param_1 + 0x6f4) = 0;

            do {

              if ((*(char *)(param_1 + 0x6e4) == '\0') &&

                 ((*(int *)(param_1 + 0x6ec) != 0 || (iVar14 = FUN_14004eeb0(), iVar14 == 0)))) {

                *(undefined4 *)(param_1 + 0x6f8) = 0xffffffff;

                goto LAB_1400503dc;

              }

              *(char *)(param_1 + 0x6e4) = *(char *)(param_1 + 0x6e4) + -1;

              *(int *)(param_1 + 0x6fc) = *(int *)(param_1 + 0x6fc) + 1;

              pbVar3 = *(byte **)(param_1 + 0x40);

              if (pbVar3 == (byte *)0x0) {

                uVar26 = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

                if (uVar26 == 0xffffffff) goto LAB_1400502e0;

              }

              else if (pbVar3 < *(byte **)(param_1 + 0x50)) {

                uVar26 = (uint)*pbVar3;

                *(byte **)(param_1 + 0x40) = pbVar3 + 1;

              }

              else {

LAB_1400502e0:

                uVar26 = 0;

                *(undefined4 *)(param_1 + 0x98) = 1;

              }

              *(int *)(param_1 + 0x6f4) =

                   *(int *)(param_1 + 0x6f4) + ((uVar26 & 0xff) << ((byte)*piVar21 & 0x1f));

              iVar14 = *piVar21 + 8;

              *piVar21 = iVar14;

            } while (iVar14 < 1);

          }

          piVar21 = (int *)(param_1 + 0x6f8);

          uVar26 = *(uint *)(param_1 + 0x6f4);

          *(uint *)(param_1 + 0x6f4) = uVar26 >> 1;

          *piVar21 = iVar14 + -1;

          if ((uVar26 & 1) != 0) {

            if (*(char *)(param_1 + 0x5c) == '\0') {

LAB_140050332:

              do {

                if ((*(char *)(param_1 + 0x6e4) == '\0') &&

                   ((*(int *)(param_1 + 0x6ec) != 0 || (iVar14 = FUN_14004eeb0(), iVar14 == 0))))

                goto LAB_140050394;

                *(char *)(param_1 + 0x6e4) = *(char *)(param_1 + 0x6e4) + -1;

                *(int *)(param_1 + 0x6fc) = *(int *)(param_1 + 0x6fc) + 1;

                uVar23 = *(ulonglong *)(param_1 + 0x40);

                if (uVar23 == 0) {

                  iVar14 = FUN_1402ce36c();

                  if (iVar14 == -1) goto LAB_140050385;

                }

                else {

                  if (uVar23 < *(ulonglong *)(param_1 + 0x50)) {

                    *piVar21 = 0;

                    *(ulonglong *)(param_1 + 0x40) = uVar23 + 1;

                    goto LAB_140050332;

                  }

LAB_140050385:

                  *(undefined4 *)(param_1 + 0x98) = 1;

                }

                *piVar21 = 0;

              } while( true );

            }

            goto LAB_1400504eb;

          }

        }

LAB_1400503dc:

        uVar31 = FUN_14004cee0(*(int *)(param_1 + 0x1f0) + -1);

        iVar14 = FUN_14004cb40(param_1,uVar31);

        lVar16 = (longlong)iVar14;

        if ((iVar14 != -1) && (iVar14 < *(int *)(param_1 + 0x1f0))) {

          if (*(char *)(param_1 + 500 + lVar16 * 6) == '\0') {

            iVar14 = *(int *)(param_1 + 0xa8);

            iVar15 = iVar13;

          }

          else {

            iVar14 = *(int *)(param_1 + 0xac);

            iVar13 = FUN_14004cb40(param_1,1);

            iVar15 = FUN_14004cb40(param_1,1);

          }

          cVar10 = *(char *)(param_1 + 500 + lVar16 * 6);

          iVar19 = iVar14 >> 1;

          if ((cVar10 == '\0') || (iVar13 != 0)) {

            local_res18[0] = 0;

            iVar13 = iVar19;

            if (cVar10 != '\0') goto LAB_14005048b;

          }

          else {

            local_res18[0] = iVar14 - *(int *)(param_1 + 0xa8) >> 2;

            iVar13 = iVar14 + *(int *)(param_1 + 0xa8) >> 2;

LAB_14005048b:

            if (iVar15 == 0) {

              iVar19 = iVar14 * 3 - *(int *)(param_1 + 0xa8) >> 2;

              iVar14 = *(int *)(param_1 + 0xa8) + iVar14 * 3 >> 2;

            }

          }

          iVar13 = FUN_140053a40(param_1,local_res20,param_1 + lVar16 * 6 + 500,local_res18[0],

                                 iVar13,iVar19,iVar14,local_res18);

          if (iVar13 != 0) {

            FUN_140055060(param_1,local_res20[0],local_res18[0],iVar19);

          }

        }

      }

    }

  }

LAB_1400504eb:

  *(undefined4 *)(param_1 + 0x9c) = 0x25;

  return 0;

LAB_14004f390:

  uVar17 = uVar12 - uVar24;

  local_a8 = uVar17;

  if (uVar17 < 0x10001) {

    FUN_140050920(param_1);

    goto LAB_14004fa91;

  }

  if ((int)uVar26 < 2) {

    if (uVar26 == 0) {

      dVar4 = (double)(uint)(local_a0._4_4_ - (int)uVar23) / (double)local_res20[0];

      dVar30 = (double)(uVar11 - local_res18[0]) * dVar4 + (double)(uVar23 & 0xffffffff);

    }

    else {

      dVar29 = ((double)uVar11 - (double)local_b0) * dVar4;

      dVar30 = dVar29;

      if ((0.0 <= dVar29) && (dVar30 = dVar5, dVar5 <= dVar29)) {

        dVar30 = dVar29;

      }

      dVar29 = dVar30;

      if ((dVar30 < 0.0) && (dVar29 = dVar6, dVar30 <= dVar6)) {

        dVar29 = dVar30;

      }

      dVar30 = (double)CONCAT44(uVar32,uVar31) + dVar29 + dVar29;

    }

    dVar29 = (double)uVar24;

    if ((double)uVar24 <= dVar30) {

      dVar29 = dVar30;

    }

    dVar30 = (double)(uVar12 - 0x10000);

    if (dVar29 <= (double)(uVar12 - 0x10000)) {

      dVar30 = dVar29;

    }

    uVar31 = SUB84(dVar30,0);

    uVar32 = (undefined4)((ulonglong)dVar30 >> 0x20);

    uVar23 = (ulonglong)dVar30;

  }

  else {

    uVar23 = (ulonglong)((uVar24 - 0x8000) + (uVar17 >> 1));

  }

  FUN_140050920(param_1,uVar23);

  if (*(int *)(param_1 + 0x98) == 0) {

    do {

      uVar23 = 0;

      pcVar20 = *(char **)(param_1 + 0x40);

      if (pcVar20 == (char *)0x0) {

        iVar13 = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

        cVar10 = (char)iVar13;

        if (iVar13 == -1) goto LAB_14004f4cd;

LAB_14004f4a9:

        if (cVar10 == 'O') {

          uVar25 = uVar23;

          if (*(char *)(param_1 + 0x5c) == '\0') {

            if (*(longlong *)(param_1 + 0x40) == 0) {

              iVar13 = *(int *)(param_1 + 0x38);

              iVar14 = FUN_1402cf00c();

              uVar25 = (ulonglong)(uint)(iVar14 - iVar13);

            }

            else {

              uVar25 = (ulonglong)

                       (uint)((int)*(longlong *)(param_1 + 0x40) - *(int *)(param_1 + 0x48));

            }

          }

          if (*(uint *)(param_1 + 0x58) < (int)uVar25 - 0x19U) break;

          iVar13 = 1;

          lVar16 = 1;

          do {

            pcVar20 = *(char **)(param_1 + 0x40);

            if (pcVar20 == (char *)0x0) {

              iVar14 = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

              cVar10 = (char)iVar14;

              if (iVar14 == -1) goto LAB_14004f542;

            }

            else if (pcVar20 < *(char **)(param_1 + 0x50)) {

              cVar10 = *pcVar20;

              *(char **)(param_1 + 0x40) = pcVar20 + 1;

            }

            else {

LAB_14004f542:

              cVar10 = '\0';

              *(undefined4 *)(param_1 + 0x98) = 1;

            }

            bVar9 = DAT_1403d45db;

            bVar8 = DAT_1403d45da;

            bVar7 = DAT_1403d45d9;

            bVar1 = DAT_1403d45d8;

            if (cVar10 != (&DAT_1403d45d8)[lVar16]) break;

            iVar13 = iVar13 + 1;

            lVar16 = lVar16 + 1;

          } while (lVar16 < 4);

          if (*(int *)(param_1 + 0x98) != 0) break;

          if (iVar13 == 4) {

            pcVar20 = local_f4;

            lVar16 = 0x17;

            do {

              pcVar2 = *(char **)(param_1 + 0x40);

              if (pcVar2 == (char *)0x0) {

                iVar13 = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

                cVar10 = (char)iVar13;

                if (iVar13 == -1) goto LAB_14004f5db;

              }

              else if (pcVar2 < *(char **)(param_1 + 0x50)) {

                cVar10 = *pcVar2;

                *(char **)(param_1 + 0x40) = pcVar2 + 1;

              }

              else {

LAB_14004f5db:

                cVar10 = '\0';

                *(undefined4 *)(param_1 + 0x98) = 1;

              }

              *pcVar20 = cVar10;

              pcVar20 = pcVar20 + 1;

              lVar16 = lVar16 + -1;

            } while (lVar16 != 0);

            if (*(int *)(param_1 + 0x98) != 0) break;

            if (local_f4[0] == '\0') {

              uVar26 = (uint)local_e1;

              uVar11 = (uint)local_e0;

              uVar24 = (uint)local_df;

              uVar12 = (uint)local_e2;

              uVar17 = (&DAT_1403ea2f0)[bVar1] << 8 ^

                       (&DAT_1403ea2f0)

                       [(ulonglong)((uint)(&DAT_1403ea2f0)[bVar1] >> 0x18) ^ (ulonglong)bVar7];

              uVar17 = uVar17 << 8 ^

                       (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)bVar8];

              uVar17 = uVar17 << 8 ^

                       (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)bVar9];

              uVar17 = uVar17 << 8 ^ (&DAT_1403ea2f0)[uVar17 >> 0x18];

              uVar17 = uVar17 << 8 ^

                       (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)(byte)local_f4[1]];

              uVar17 = uVar17 << 8 ^

                       (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)(byte)local_f4[2]];

              uVar17 = uVar17 << 8 ^

                       (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)(byte)local_f4[3]];

              uVar17 = uVar17 << 8 ^

                       (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)local_f0];

              uVar17 = uVar17 << 8 ^

                       (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)local_ef];

              uVar17 = uVar17 << 8 ^

                       (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)local_ee];

              uVar17 = uVar17 << 8 ^

                       (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)local_ed];

              uVar17 = uVar17 << 8 ^

                       (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)local_ec];

              uVar17 = uVar17 << 8 ^

                       (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)local_eb];

              uVar17 = uVar17 << 8 ^

                       (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)local_ea];

              uVar17 = uVar17 << 8 ^

                       (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)local_e9];

              uVar17 = uVar17 << 8 ^

                       (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)local_e8];

              uVar17 = uVar17 << 8 ^

                       (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)local_e7];

              uVar17 = uVar17 << 8 ^

                       (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)local_e6];

              uVar17 = uVar17 << 8 ^

                       (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)local_e5];

              uVar17 = uVar17 << 8 ^

                       (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)local_e4];

              uVar17 = uVar17 << 8 ^

                       (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)local_e3];

              uVar17 = uVar17 << 8 ^ (&DAT_1403ea2f0)[uVar17 >> 0x18];

              uVar17 = uVar17 << 8 ^ (&DAT_1403ea2f0)[uVar17 >> 0x18];

              uVar17 = uVar17 << 8 ^ (&DAT_1403ea2f0)[uVar17 >> 0x18];

              uVar17 = uVar17 << 8 ^ (&DAT_1403ea2f0)[uVar17 >> 0x18];

              uVar17 = uVar17 << 8 ^

                       (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)local_de];

              if (local_de != 0) {

                uVar27 = (ulonglong)local_de;

                do {

                  pbVar3 = *(byte **)(param_1 + 0x40);

                  if (pbVar3 == (byte *)0x0) {

                    uVar22 = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

                    uVar18 = (ulonglong)uVar22;

                    if (uVar22 == 0xffffffff) goto LAB_14004f932;

                  }

                  else if (pbVar3 < *(byte **)(param_1 + 0x50)) {

                    uVar18 = (ulonglong)*pbVar3;

                    *(byte **)(param_1 + 0x40) = pbVar3 + 1;

                  }

                  else {

LAB_14004f932:

                    uVar18 = 0;

                    *(undefined4 *)(param_1 + 0x98) = 1;

                  }

                  uVar22 = (int)uVar23 + ((uint)uVar18 & 0xff);

                  uVar23 = (ulonglong)uVar22;

                  uVar17 = uVar17 << 8 ^

                           (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ uVar18 & 0xff];

                  uVar27 = uVar27 - 1;

                } while (uVar27 != 0);

                if (uVar22 != 0) {

                  if (*(int *)(param_1 + 0x98) != 0) break;

                  if (uVar22 != 0) {

                    do {

                      pbVar3 = *(byte **)(param_1 + 0x40);

                      if (pbVar3 == (byte *)0x0) {

                        uVar22 = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

                        uVar27 = (ulonglong)uVar22;

                        if (uVar22 == 0xffffffff) goto LAB_14004f9ab;

                      }

                      else if (pbVar3 < *(byte **)(param_1 + 0x50)) {

                        uVar27 = (ulonglong)*pbVar3;

                        *(byte **)(param_1 + 0x40) = pbVar3 + 1;

                      }

                      else {

LAB_14004f9ab:

                        uVar27 = 0;

                        *(undefined4 *)(param_1 + 0x98) = 1;

                      }

                      uVar17 = uVar17 << 8 ^

                               (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ uVar27 & 0xff];

                      uVar23 = uVar23 - 1;

                    } while (uVar23 != 0);

                  }

                }

              }

              if (uVar17 == uVar11 * 0x10000 + uVar26 * 0x100 + uVar24 * 0x1000000 + uVar12)

              goto LAB_14004fa73;

            }

          }

          FUN_140050920(param_1,uVar25);

        }

      }

      else {

        if (pcVar20 < *(char **)(param_1 + 0x50)) {

          cVar10 = *pcVar20;

          *(char **)(param_1 + 0x40) = pcVar20 + 1;

          goto LAB_14004f4a9;

        }

LAB_14004f4cd:

        *(undefined4 *)(param_1 + 0x98) = 1;

      }

      if (*(int *)(param_1 + 0x98) != 0) break;

    } while( true );

  }

  goto LAB_14004f9f5;

LAB_14004fa73:

  FUN_140050920(param_1,(int)uVar25 + -1);

  uVar23 = local_d8;

  uVar12 = (uint)local_a0;

  uVar17 = local_a8;

  uVar26 = local_c0;

  uVar11 = local_a4;

LAB_14004fa91:

  while( true ) {

    iVar13 = FUN_14004cc90(param_1,&local_b8);

    if (iVar13 == 0) goto LAB_14004f9f5;

    if (local_b0 != 0xffffffff) break;

    FUN_140050920(param_1,uStack_b4);

  }

  if (local_b8 == uVar12) {

    if ((1 < (int)uVar26) || (uVar17 < 0x10001)) goto LAB_14004fb22;

  }

  else if (uVar11 < local_b0) {

    local_res20[0] = local_b0;

    uVar12 = local_b8;

    local_a0 = CONCAT44(uStack_b4,local_b8);

  }

  else {

    uVar23 = (ulonglong)local_b8;

    local_res18[0] = local_b0;

    local_d8 = uVar23;

    local_d0 = CONCAT44(uStack_b4,local_b8);

  }

  uVar26 = uVar26 + 1;

  bVar28 = local_d0._4_4_ == uVar12;

  uVar24 = local_d0._4_4_;

  local_c0 = uVar26;

  if (bVar28) goto LAB_14004fb22;

  goto LAB_14004f390;

LAB_14004fb22:

  FUN_140050920(param_1,uVar23 & 0xffffffff);

  iVar13 = FUN_140053730(param_1);

  if (iVar13 != 0) {

    iVar13 = *(int *)(param_1 + 0x700);

LAB_14004fb43:

    uVar25 = 0;

    lVar16 = (longlong)iVar13;

    if (iVar13 < 1) {

LAB_14004fb6c:

      if ((*(byte *)(param_1 + 0x6e3) & 1) != 0) {

        if (((uint)uVar23 < 0x10000) ||

           (uVar26 = (uint)uVar23 - 0x10000, uVar26 < *(uint *)(param_1 + 0x60))) {

          uVar26 = *(uint *)(param_1 + 0x60);

        }

LAB_14004fb92:

        FUN_140050920(param_1,uVar26);

        if (*(int *)(param_1 + 0x98) == 0) {

          do {

            uVar23 = 0;

            pcVar20 = *(char **)(param_1 + 0x40);

            if (pcVar20 == (char *)0x0) {

              iVar13 = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

              cVar10 = (char)iVar13;

              if (iVar13 == -1) goto LAB_14004fbe4;

LAB_14004fbc0:

              if (cVar10 == 'O') {

                uVar25 = uVar23;

                if (*(char *)(param_1 + 0x5c) == '\0') {

                  if (*(longlong *)(param_1 + 0x40) == 0) {

                    iVar13 = *(int *)(param_1 + 0x38);

                    iVar14 = FUN_1402cf00c();

                    uVar25 = (ulonglong)(uint)(iVar14 - iVar13);

                  }

                  else {

                    uVar25 = (ulonglong)

                             (uint)((int)*(longlong *)(param_1 + 0x40) - *(int *)(param_1 + 0x48));

                  }

                }

                if (*(uint *)(param_1 + 0x58) < (int)uVar25 - 0x19U) break;

                iVar13 = 1;

                lVar16 = 1;

                do {

                  pcVar20 = *(char **)(param_1 + 0x40);

                  if (pcVar20 == (char *)0x0) {

                    iVar14 = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

                    cVar10 = (char)iVar14;

                    if (iVar14 == -1) goto LAB_14004fc5b;

                  }

                  else if (pcVar20 < *(char **)(param_1 + 0x50)) {

                    cVar10 = *pcVar20;

                    *(char **)(param_1 + 0x40) = pcVar20 + 1;

                  }

                  else {

LAB_14004fc5b:

                    cVar10 = '\0';

                    *(undefined4 *)(param_1 + 0x98) = 1;

                  }

                  bVar9 = DAT_1403d45db;

                  bVar8 = DAT_1403d45da;

                  bVar7 = DAT_1403d45d9;

                  bVar1 = DAT_1403d45d8;

                  if (cVar10 != (&DAT_1403d45d8)[lVar16]) break;

                  iVar13 = iVar13 + 1;

                  lVar16 = lVar16 + 1;

                } while (lVar16 < 4);

                if (*(int *)(param_1 + 0x98) != 0) break;

                if (iVar13 == 4) {

                  pcVar20 = local_f4;

                  lVar16 = 0x17;

                  do {

                    pcVar2 = *(char **)(param_1 + 0x40);

                    if (pcVar2 == (char *)0x0) {

                      iVar13 = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

                      cVar10 = (char)iVar13;

                      if (iVar13 == -1) goto LAB_14004fcfb;

                    }

                    else if (pcVar2 < *(char **)(param_1 + 0x50)) {

                      cVar10 = *pcVar2;

                      *(char **)(param_1 + 0x40) = pcVar2 + 1;

                    }

                    else {

LAB_14004fcfb:

                      cVar10 = '\0';

                      *(undefined4 *)(param_1 + 0x98) = 1;

                    }

                    *pcVar20 = cVar10;

                    pcVar20 = pcVar20 + 1;

                    lVar16 = lVar16 + -1;

                  } while (lVar16 != 0);

                  if (*(int *)(param_1 + 0x98) != 0) break;

                  if (local_f4[0] == '\0') {

                    uVar26 = (uint)local_e0;

                    uVar11 = (uint)local_e1;

                    uVar24 = (uint)local_df;

                    uVar12 = (uint)local_e2;

                    uVar17 = (&DAT_1403ea2f0)[bVar1] << 8 ^

                             (&DAT_1403ea2f0)

                             [(ulonglong)((uint)(&DAT_1403ea2f0)[bVar1] >> 0x18) ^ (ulonglong)bVar7]

                    ;

                    uVar17 = uVar17 << 8 ^

                             (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)bVar8];

                    uVar17 = uVar17 << 8 ^

                             (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)bVar9];

                    uVar17 = uVar17 << 8 ^ (&DAT_1403ea2f0)[uVar17 >> 0x18];

                    uVar17 = uVar17 << 8 ^

                             (&DAT_1403ea2f0)

                             [(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)(byte)local_f4[1]];

                    uVar17 = uVar17 << 8 ^

                             (&DAT_1403ea2f0)

                             [(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)(byte)local_f4[2]];

                    uVar17 = uVar17 << 8 ^

                             (&DAT_1403ea2f0)

                             [(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)(byte)local_f4[3]];

                    uVar17 = uVar17 << 8 ^

                             (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)local_f0];

                    uVar17 = uVar17 << 8 ^

                             (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)local_ef];

                    uVar17 = uVar17 << 8 ^

                             (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)local_ee];

                    uVar17 = uVar17 << 8 ^

                             (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)local_ed];

                    uVar17 = uVar17 << 8 ^

                             (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)local_ec];

                    uVar17 = uVar17 << 8 ^

                             (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)local_eb];

                    uVar17 = uVar17 << 8 ^

                             (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)local_ea];

                    uVar17 = uVar17 << 8 ^

                             (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)local_e9];

                    uVar17 = uVar17 << 8 ^

                             (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)local_e8];

                    uVar17 = uVar17 << 8 ^

                             (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)local_e7];

                    uVar17 = uVar17 << 8 ^

                             (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)local_e6];

                    uVar17 = uVar17 << 8 ^

                             (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)local_e5];

                    uVar17 = uVar17 << 8 ^

                             (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)local_e4];

                    uVar17 = uVar17 << 8 ^

                             (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)local_e3];

                    uVar17 = uVar17 << 8 ^ (&DAT_1403ea2f0)[uVar17 >> 0x18];

                    uVar17 = uVar17 << 8 ^ (&DAT_1403ea2f0)[uVar17 >> 0x18];

                    uVar17 = uVar17 << 8 ^ (&DAT_1403ea2f0)[uVar17 >> 0x18];

                    uVar17 = uVar17 << 8 ^ (&DAT_1403ea2f0)[uVar17 >> 0x18];

                    uVar17 = uVar17 << 8 ^

                             (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ (ulonglong)local_de];

                    if (local_de != 0) {

                      uVar27 = (ulonglong)local_de;

                      do {

                        pbVar3 = *(byte **)(param_1 + 0x40);

                        if (pbVar3 == (byte *)0x0) {

                          uVar22 = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

                          uVar18 = (ulonglong)uVar22;

                          if (uVar22 == 0xffffffff) goto LAB_140050052;

                        }

                        else if (pbVar3 < *(byte **)(param_1 + 0x50)) {

                          uVar18 = (ulonglong)*pbVar3;

                          *(byte **)(param_1 + 0x40) = pbVar3 + 1;

                        }

                        else {

LAB_140050052:

                          uVar18 = 0;

                          *(undefined4 *)(param_1 + 0x98) = 1;

                        }

                        uVar22 = (int)uVar23 + ((uint)uVar18 & 0xff);

                        uVar23 = (ulonglong)uVar22;

                        uVar17 = uVar17 << 8 ^

                                 (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ uVar18 & 0xff];

                        uVar27 = uVar27 - 1;

                      } while (uVar27 != 0);

                      if (uVar22 != 0) {

                        if (*(int *)(param_1 + 0x98) != 0) break;

                        if (uVar22 != 0) {

                          do {

                            pbVar3 = *(byte **)(param_1 + 0x40);

                            if (pbVar3 == (byte *)0x0) {

                              uVar22 = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

                              uVar27 = (ulonglong)uVar22;

                              if (uVar22 == 0xffffffff) goto LAB_1400500cb;

                            }

                            else if (pbVar3 < *(byte **)(param_1 + 0x50)) {

                              uVar27 = (ulonglong)*pbVar3;

                              *(byte **)(param_1 + 0x40) = pbVar3 + 1;

                            }

                            else {

LAB_1400500cb:

                              uVar27 = 0;

                              *(undefined4 *)(param_1 + 0x98) = 1;

                            }

                            uVar17 = uVar17 << 8 ^

                                     (&DAT_1403ea2f0)[(ulonglong)(uVar17 >> 0x18) ^ uVar27 & 0xff];

                            uVar23 = uVar23 - 1;

                          } while (uVar23 != 0);

                        }

                      }

                    }

                    uVar23 = 0;

                    if (uVar17 == uVar11 * 0x100 + uVar26 * 0x10000 + uVar24 * 0x1000000 + uVar12)

                    goto LAB_140050116;

                  }

                }

                FUN_140050920(param_1,uVar25);

              }

            }

            else {

              if (pcVar20 < *(char **)(param_1 + 0x50)) {

                cVar10 = *pcVar20;

                *(char **)(param_1 + 0x40) = pcVar20 + 1;

                goto LAB_14004fbc0;

              }

LAB_14004fbe4:

              *(undefined4 *)(param_1 + 0x98) = 1;

            }

            if (*(int *)(param_1 + 0x98) != 0) break;

          } while( true );

        }

        goto LAB_14004f9f5;

      }

    }

    else {

      do {

        if (*(char *)(lVar16 + 0x5e3 + param_1) != -1) break;

        iVar13 = iVar13 + -1;

        lVar16 = lVar16 + -1;

      } while (0 < lVar16);

      if (iVar13 < 1) goto LAB_14004fb6c;

    }

    iVar14 = 0;

    *(undefined4 *)(param_1 + 0x584) = 0;

    *(undefined4 *)(param_1 + 0x6f8) = 0;

    *(undefined4 *)(param_1 + 0x6ec) = 0;

    *(undefined4 *)(param_1 + 0x6fc) = 0;

    *(undefined1 *)(param_1 + 0x6e4) = 0;

    *(undefined4 *)(param_1 + 0x4f8) = 0;

    *(int *)(param_1 + 0x6e8) = iVar13;

    uVar23 = uVar25;

    if (0 < iVar13) {

      do {

        bVar1 = *(byte *)(uVar23 + 0x5e4 + param_1);

        if (*(longlong *)(param_1 + 0x40) == 0) {

          iVar15 = FUN_1402cf00c(*(undefined8 *)(param_1 + 0x30));

          FUN_1402cea4c(*(undefined8 *)(param_1 + 0x30),iVar15 + (uint)bVar1,0);

        }

        else {

          uVar27 = *(longlong *)(param_1 + 0x40) + (ulonglong)bVar1;

          *(ulonglong *)(param_1 + 0x40) = uVar27;

          if (*(ulonglong *)(param_1 + 0x50) <= uVar27) {

            *(undefined4 *)(param_1 + 0x98) = 1;

          }

        }

        uVar23 = uVar23 + 1;

      } while ((longlong)uVar23 < (longlong)iVar13);

    }

    piVar21 = (int *)(param_1 + 0x6f8);

    iVar13 = *(int *)(param_1 + 0x98);

    *(undefined8 *)(param_1 + 0x764) = 0;

joined_r0x0001400505a3:

    if (iVar13 != 0) {

      return 0;

    }

    if (*(int *)(param_1 + 0x6e8) == -1) {

      pcVar20 = *(char **)(param_1 + 0x40);

      if (pcVar20 == (char *)0x0) {

        iVar13 = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

        cVar10 = (char)iVar13;

        if (iVar13 == -1) goto LAB_1400505e8;

      }

      else if (pcVar20 < *(char **)(param_1 + 0x50)) {

        cVar10 = *pcVar20;

        *(char **)(param_1 + 0x40) = pcVar20 + 1;

      }

      else {

LAB_1400505e8:

        cVar10 = '\0';

        *(undefined4 *)(param_1 + 0x98) = 1;

      }

      if (*(int *)(param_1 + 0x98) != 0) {

        return 0;

      }

      if ((((cVar10 != 'O') || (cVar10 = FUN_14004ca60(param_1), cVar10 != 'g')) ||

          (cVar10 = FUN_14004ca60(param_1), cVar10 != 'g')) ||

         (cVar10 = FUN_14004ca60(param_1), cVar10 != 'S')) {

        *(undefined4 *)(param_1 + 0x9c) = 0x1e;

        return 0;

      }

      iVar13 = FUN_140053810(param_1);

      if (iVar13 == 0) {

        return 0;

      }

      if ((*(byte *)(param_1 + 0x6e3) & 1) != 0) {

        *(undefined4 *)(param_1 + 0x6ec) = 0;

        *(undefined1 *)(param_1 + 0x6e4) = 0;

        *(undefined4 *)(param_1 + 0x9c) = 0x20;

        return 0;

      }

    }

    iVar13 = FUN_1400535f0();

    if (iVar13 == 0) {

      return 0;

    }

    iVar13 = *piVar21;

    if (-1 < iVar13) {

      if (iVar13 < 1) {

        *(undefined4 *)(param_1 + 0x6f4) = 0;

        do {

          if ((*(char *)(param_1 + 0x6e4) == '\0') &&

             ((*(int *)(param_1 + 0x6ec) != 0 || (iVar13 = FUN_14004eeb0(), iVar13 == 0)))) {

            *(undefined4 *)(param_1 + 0x6f8) = 0xffffffff;

            goto LAB_1400507e2;

          }

          *(char *)(param_1 + 0x6e4) = *(char *)(param_1 + 0x6e4) + -1;

          *(int *)(param_1 + 0x6fc) = *(int *)(param_1 + 0x6fc) + 1;

          pbVar3 = *(byte **)(param_1 + 0x40);

          if (pbVar3 == (byte *)0x0) {

            uVar26 = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

            if (uVar26 == 0xffffffff) goto LAB_1400506de;

          }

          else if (pbVar3 < *(byte **)(param_1 + 0x50)) {

            uVar26 = (uint)*pbVar3;

            *(byte **)(param_1 + 0x40) = pbVar3 + 1;

          }

          else {

LAB_1400506de:

            uVar26 = 0;

            *(undefined4 *)(param_1 + 0x98) = 1;

          }

          *(int *)(param_1 + 0x6f4) =

               *(int *)(param_1 + 0x6f4) + ((uVar26 & 0xff) << ((byte)*piVar21 & 0x1f));

          iVar13 = *piVar21 + 8;

          *piVar21 = iVar13;

        } while (iVar13 < 1);

      }

      uVar26 = *(uint *)(param_1 + 0x6f4);

      *(uint *)(param_1 + 0x6f4) = uVar26 >> 1;

      *piVar21 = iVar13 + -1;

      if ((uVar26 & 1) != 0) {

        if (*(char *)(param_1 + 0x5c) != '\0') {

          *(undefined4 *)(param_1 + 0x9c) = 0x23;

          return 0;

        }

LAB_140050730:

        do {

          if ((*(char *)(param_1 + 0x6e4) == '\0') &&

             ((*(int *)(param_1 + 0x6ec) != 0 || (iVar13 = FUN_14004eeb0(param_1), iVar13 == 0))))

          goto LAB_140050792;

          *(char *)(param_1 + 0x6e4) = *(char *)(param_1 + 0x6e4) + -1;

          *(int *)(param_1 + 0x6fc) = *(int *)(param_1 + 0x6fc) + 1;

          uVar23 = *(ulonglong *)(param_1 + 0x40);

          if (uVar23 == 0) {

            iVar13 = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

            if (iVar13 == -1) goto LAB_140050783;

          }

          else {

            if (uVar23 < *(ulonglong *)(param_1 + 0x50)) {

              *piVar21 = 0;

              *(ulonglong *)(param_1 + 0x40) = uVar23 + 1;

              goto LAB_140050730;

            }

LAB_140050783:

            *(undefined4 *)(param_1 + 0x98) = 1;

          }

          *piVar21 = 0;

        } while( true );

      }

    }

LAB_1400507e2:

    uVar31 = FUN_14004cee0(*(int *)(param_1 + 0x1f0) + -1);

    iVar13 = FUN_14004cb40(param_1,uVar31);

    lVar16 = (longlong)iVar13;

    if (iVar13 == -1) {

      return 0;

    }

    if (*(int *)(param_1 + 0x1f0) <= iVar13) {

      return 0;

    }

    if (*(char *)(param_1 + 500 + lVar16 * 6) == '\0') {

      iVar13 = *(int *)(param_1 + 0xa8);

      iVar15 = iVar14;

    }

    else {

      iVar13 = *(int *)(param_1 + 0xac);

      iVar14 = FUN_14004cb40(param_1,1);

      iVar15 = FUN_14004cb40(param_1,1);

    }

    cVar10 = *(char *)(param_1 + 500 + lVar16 * 6);

    iVar19 = iVar13 >> 1;

    if ((cVar10 == '\0') || (iVar14 != 0)) {

      local_res18[0] = 0;

      iVar14 = iVar19;

      if (cVar10 != '\0') goto LAB_1400508a0;

    }

    else {

      local_res18[0] = iVar13 - *(int *)(param_1 + 0xa8) >> 2;

      uVar25 = (ulonglong)local_res18[0];

      iVar14 = *(int *)(param_1 + 0xa8) + iVar13 >> 2;

LAB_1400508a0:

      if (iVar15 == 0) {

        iVar19 = iVar13 * 3 - *(int *)(param_1 + 0xa8) >> 2;

        iVar13 = *(int *)(param_1 + 0xa8) + iVar13 * 3 >> 2;

      }

    }

    iVar13 = FUN_140053a40(param_1,local_res20,param_1 + lVar16 * 6 + 500,uVar25,iVar14,iVar19,

                           iVar13,local_res18);

    if (iVar13 == 0) {

      return 0;

    }

    FUN_140055060(param_1,local_res20[0],local_res18[0],iVar19);

    uVar26 = *(uint *)(param_1 + 0x580);

LAB_14005090d:

    if (uVar26 <= param_2) {

      return 1;

    }

  }

  goto LAB_1400504eb;

LAB_140050116:

  uVar11 = 0;

  uVar26 = uVar11;

  if (*(char *)(param_1 + 0x5c) == '\0') {

    if (*(longlong *)(param_1 + 0x40) == 0) {

      iVar13 = *(int *)(param_1 + 0x38);

      iVar14 = FUN_1402cf00c(*(undefined8 *)(param_1 + 0x30));

      uVar26 = iVar14 - iVar13;

    }

    else {

      uVar26 = (int)*(longlong *)(param_1 + 0x40) - *(int *)(param_1 + 0x48);

    }

  }

  FUN_140050920(param_1,(int)uVar25 + -1);

  uVar24 = (uint)local_d8;

  if (uVar26 < uVar24) goto LAB_14004fb92;

  if (*(char *)(param_1 + 0x5c) == '\0') {

    if (*(longlong *)(param_1 + 0x40) == 0) {

      iVar13 = *(int *)(param_1 + 0x38);

      iVar14 = FUN_1402cf00c(*(undefined8 *)(param_1 + 0x30));

      uVar11 = iVar14 - iVar13;

    }

    else {

      uVar11 = (int)*(longlong *)(param_1 + 0x40) - *(int *)(param_1 + 0x48);

    }

  }

  if (uVar11 < uVar24) goto LAB_140050187;

  goto LAB_14004fb92;

LAB_140050187:

  if (*(char *)(param_1 + 0x5c) == '\0') {

    if (*(longlong *)(param_1 + 0x40) == 0) {

      iVar13 = *(int *)(param_1 + 0x38);

      iVar14 = FUN_1402cf00c(*(undefined8 *)(param_1 + 0x30));

      uVar23 = (ulonglong)(uint)(iVar14 - iVar13);

    }

    else {

      uVar23 = (ulonglong)(uint)((int)*(longlong *)(param_1 + 0x40) - *(int *)(param_1 + 0x48));

    }

  }

  local_d8 = uVar23;

  iVar13 = FUN_140053730(param_1);

  if (iVar13 == 0) goto LAB_14004f9f5;

  iVar13 = *(int *)(param_1 + 0x5e0) + -1;

  goto LAB_14004fb43;

LAB_140050792:

  *piVar21 = 0;

  iVar13 = *(int *)(param_1 + 0x98);

  goto joined_r0x0001400505a3;

LAB_140050394:

  *piVar21 = 0;

  if (*(int *)(param_1 + 0x98) != 0) {

    *(undefined4 *)(param_1 + 0x9c) = 0x25;

    return 0;

  }

  goto LAB_14004fa40;

}




