// Address: 0x1401cf1a0
// Ghidra name: FUN_1401cf1a0
// ============ 0x1401cf1a0 FUN_1401cf1a0 (size=6162) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1401cf1a0(int param_1,ushort *param_2,longlong param_3,longlong param_4,int *param_5,

                  uint param_6)



{

  char cVar1;

  byte bVar2;

  byte bVar3;

  byte bVar4;

  ushort uVar5;

  ushort uVar6;

  undefined2 uVar7;

  int iVar8;

  longlong lVar9;

  uint uVar10;

  uint uVar11;

  uint uVar12;

  uint uVar13;

  uint *puVar14;

  uint *puVar15;

  uint uVar16;

  uint uVar17;

  uint uVar18;

  uint uVar19;

  int iVar20;

  uint uVar21;

  uint uVar22;

  uint uVar23;

  longlong lVar24;

  int iVar25;

  uint uVar26;

  uint uVar27;

  uint uVar28;

  int iVar29;

  ulonglong uVar30;

  int iVar31;

  undefined1 *puVar32;

  int iVar33;

  ulonglong uVar34;

  uint *puVar35;

  uint *puVar36;

  ushort *puVar37;

  ushort *puVar38;

  uint *puVar39;

  byte *pbVar40;

  int iVar41;

  uint uVar42;

  int iVar43;

  undefined1 auVar44 [16];

  uint uVar45;

  uint uVar46;

  uint uVar47;

  uint uVar48;

  uint uVar49;

  uint uVar50;

  uint uVar51;

  uint uVar52;

  uint uVar53;

  undefined1 auVar54 [16];

  undefined1 auVar55 [16];

  undefined1 auVar56 [16];

  undefined1 auVar57 [16];

  longlong local_res20;

  int local_b8;

  ulonglong local_98;

  ulonglong local_80;

  

  uVar19 = _UNK_14034a94c;

  uVar18 = _UNK_14034a948;

  uVar17 = _UNK_14034a944;

  uVar16 = _DAT_14034a940;

  uVar46 = _UNK_14034a93c;

  uVar28 = _UNK_14034a938;

  uVar22 = _UNK_14034a934;

  uVar42 = _DAT_14034a930;

  uVar13 = _UNK_14034a92c;

  uVar12 = _UNK_14034a928;

  uVar11 = _UNK_14034a924;

  uVar10 = _DAT_14034a920;

  uVar23 = _UNK_14033c2bc;

  uVar21 = _UNK_14033c2b8;

  uVar27 = _UNK_14033c2b4;

  uVar26 = _DAT_14033c2b0;

  lVar9 = *(longlong *)(param_3 + 0x38);

  cVar1 = *(char *)(lVar9 + 5);

  auVar57._4_4_ = param_6;

  auVar57._0_4_ = param_6;

  auVar57._8_4_ = param_6;

  auVar57._12_4_ = param_6;

  if (param_6 == 0xff) {

    if (cVar1 == '\x01') {

      iVar31 = 0;

      iVar8 = *param_5;

      iVar43 = param_5[2];

      iVar41 = param_5[3];

      param_4 = param_4 - iVar8;

      local_res20 = param_4;

      do {

        do {

          bVar2 = *(byte *)((longlong)param_2 + 1);

          iVar31 = iVar31 + (uint)(byte)*param_2;

          param_2 = param_2 + 1;

          if (bVar2 == 0) {

            if (iVar31 == 0) {

              return;

            }

          }

          else {

            uVar26 = (uint)bVar2;

            if (iVar31 < iVar43 + iVar8) {

              iVar20 = iVar8 - iVar31;

              uVar27 = uVar26;

              iVar29 = 0;

              if ((iVar20 < 1) || (uVar27 = uVar26 - iVar20, iVar29 = iVar20, 0 < (int)uVar27)) {

                uVar21 = (iVar43 + iVar8) - (iVar29 + iVar31);

                if ((int)uVar27 <= (int)uVar21) {

                  uVar21 = uVar27;

                }

                FUN_1402f8e20((iVar29 + iVar31) + param_4,

                              (byte *)((longlong)iVar29 + (longlong)param_2),(longlong)(int)uVar21);

                param_4 = local_res20;

              }

            }

            param_2 = (ushort *)((longlong)param_2 + (ulonglong)bVar2);

            iVar31 = iVar31 + uVar26;

          }

        } while (iVar31 != param_1);

        iVar31 = 0;

        param_4 = param_4 + *(int *)(param_3 + 0x10);

        iVar41 = iVar41 + -1;

        local_res20 = param_4;

      } while (iVar41 != 0);

    }

    else if (cVar1 == '\x02') {

      iVar31 = 0;

      iVar8 = *param_5;

      iVar43 = param_5[2];

      iVar41 = param_5[3];

      param_4 = param_4 - iVar8 * 2;

      local_res20 = param_4;

      do {

        do {

          bVar2 = *(byte *)((longlong)param_2 + 1);

          iVar31 = iVar31 + (uint)(byte)*param_2;

          param_2 = param_2 + 1;

          if (bVar2 == 0) {

            if (iVar31 == 0) {

              return;

            }

          }

          else {

            uVar26 = (uint)bVar2;

            if (iVar31 < iVar43 + iVar8) {

              iVar20 = iVar8 - iVar31;

              uVar27 = uVar26;

              iVar29 = 0;

              if ((iVar20 < 1) || (uVar27 = uVar26 - iVar20, iVar29 = iVar20, 0 < (int)uVar27)) {

                uVar21 = (iVar43 + iVar8) - (iVar29 + iVar31);

                if ((int)uVar27 <= (int)uVar21) {

                  uVar21 = uVar27;

                }

                FUN_1402f8e20((iVar29 + iVar31) * 2 + param_4,

                              (byte *)((longlong)(iVar29 * 2) + (longlong)param_2),

                              (longlong)(int)uVar21 * 2);

                param_4 = local_res20;

              }

            }

            param_2 = (ushort *)((longlong)param_2 + (ulonglong)((uint)bVar2 + (uint)bVar2));

            iVar31 = iVar31 + uVar26;

          }

        } while (iVar31 != param_1);

        iVar31 = 0;

        param_4 = param_4 + *(int *)(param_3 + 0x10);

        iVar41 = iVar41 + -1;

        local_res20 = param_4;

      } while (iVar41 != 0);

    }

    else if (cVar1 == '\x03') {

      iVar31 = 0;

      iVar8 = *param_5;

      iVar43 = param_5[2];

      iVar41 = param_5[3];

      param_4 = param_4 - iVar8 * 3;

      local_res20 = param_4;

      do {

        do {

          bVar2 = *(byte *)((longlong)param_2 + 1);

          iVar31 = iVar31 + (uint)(byte)*param_2;

          param_2 = param_2 + 1;

          if (bVar2 == 0) {

            if (iVar31 == 0) {

              return;

            }

          }

          else {

            uVar26 = (uint)bVar2;

            if (iVar31 < iVar43 + iVar8) {

              iVar20 = iVar8 - iVar31;

              uVar27 = uVar26;

              iVar29 = 0;

              if ((iVar20 < 1) || (uVar27 = uVar26 - iVar20, iVar29 = iVar20, 0 < (int)uVar27)) {

                uVar21 = (iVar43 + iVar8) - (iVar29 + iVar31);

                if ((int)uVar27 <= (int)uVar21) {

                  uVar21 = uVar27;

                }

                FUN_1402f8e20((iVar29 + iVar31) * 3 + param_4,

                              (byte *)((longlong)(iVar29 * 3) + (longlong)param_2),

                              (longlong)(int)uVar21 * 3);

                param_4 = local_res20;

              }

            }

            param_2 = (ushort *)((longlong)param_2 + (ulonglong)((uint)bVar2 + (uint)bVar2 * 2));

            iVar31 = iVar31 + uVar26;

          }

        } while (iVar31 != param_1);

        iVar31 = 0;

        param_4 = param_4 + *(int *)(param_3 + 0x10);

        iVar41 = iVar41 + -1;

        local_res20 = param_4;

      } while (iVar41 != 0);

    }

    else if (cVar1 == '\x04') {

      iVar31 = 0;

      iVar8 = *param_5;

      iVar43 = param_5[2];

      iVar41 = param_5[3];

      param_4 = param_4 - iVar8 * 4;

      local_res20 = param_4;

      do {

        do {

          uVar5 = param_2[1];

          iVar31 = iVar31 + (uint)*param_2;

          param_2 = param_2 + 2;

          if (uVar5 == 0) {

            if (iVar31 == 0) {

              return;

            }

          }

          else {

            uVar26 = (uint)uVar5;

            if (iVar31 < iVar43 + iVar8) {

              iVar20 = iVar8 - iVar31;

              uVar27 = uVar26;

              iVar29 = 0;

              if ((iVar20 < 1) || (uVar27 = uVar26 - iVar20, iVar29 = iVar20, 0 < (int)uVar27)) {

                uVar21 = (iVar43 + iVar8) - (iVar29 + iVar31);

                if ((int)uVar27 <= (int)uVar21) {

                  uVar21 = uVar27;

                }

                FUN_1402f8e20((iVar29 + iVar31) * 4 + param_4,

                              (byte *)((longlong)(iVar29 * 4) + (longlong)param_2),

                              (longlong)(int)uVar21 << 2);

                param_4 = local_res20;

              }

            }

            param_2 = (ushort *)((longlong)param_2 + (ulonglong)((uint)uVar5 * 4));

            iVar31 = iVar31 + uVar26;

          }

        } while (iVar31 != param_1);

        iVar31 = 0;

        param_4 = param_4 + *(int *)(param_3 + 0x10);

        iVar41 = iVar41 + -1;

        local_res20 = param_4;

      } while (iVar41 != 0);

    }

  }

  else if (cVar1 == '\x02') {

    uVar26 = *(uint *)(lVar9 + 0x10);

    uVar27 = *(uint *)(lVar9 + 0xc);

    uVar21 = *(uint *)(lVar9 + 8);

    uVar23 = uVar26 | uVar27 | uVar21;

    if (uVar23 == 0x7fff) {

      if (((uVar27 == 0x3e0) || (uVar21 == 0x3e0)) || (uVar26 == 0x3e0)) {

        iVar8 = *param_5;

        iVar43 = param_5[3];

        iVar41 = param_5[2] + iVar8;

        param_4 = param_4 - iVar8 * 2;

        if (param_6 != 0x80) {

          iVar31 = 0;

          do {

            do {

              bVar2 = *(byte *)((longlong)param_2 + 1);

              iVar31 = iVar31 + (uint)(byte)*param_2;

              param_2 = param_2 + 1;

              if (bVar2 == 0) {

                if (iVar31 == 0) {

                  return;

                }

              }

              else {

                uVar26 = (uint)bVar2;

                if (iVar31 < iVar41) {

                  iVar20 = iVar8 - iVar31;

                  uVar27 = uVar26;

                  iVar29 = 0;

                  if ((iVar20 < 1) || (uVar27 = uVar26 - iVar20, iVar29 = iVar20, 0 < (int)uVar27))

                  {

                    uVar21 = iVar41 - (iVar29 + iVar31);

                    if ((int)uVar27 <= (int)uVar21) {

                      uVar21 = uVar27;

                    }

                    puVar37 = (ushort *)((iVar29 + iVar31) * 2 + param_4);

                    if (0 < (int)uVar21) {

                      uVar30 = (ulonglong)uVar21;

                      puVar38 = puVar37;

                      do {

                        uVar7 = *(undefined2 *)

                                 ((longlong)puVar38 +

                                 (longlong)

                                 (((longlong)(iVar29 * 2) - (longlong)puVar37) + (longlong)param_2))

                        ;

                        uVar27 = CONCAT22(*puVar38,*puVar38) & 0x3e07c1f;

                        uVar27 = (((CONCAT22(uVar7,uVar7) & 0x3e07c1f) - uVar27) * (param_6 >> 3) >>

                                 5) + uVar27 & 0x3e07c1f;

                        *puVar38 = (ushort)(uVar27 >> 0x10) | (ushort)uVar27;

                        uVar30 = uVar30 - 1;

                        puVar38 = puVar38 + 1;

                      } while (uVar30 != 0);

                    }

                  }

                }

                param_2 = (ushort *)((longlong)param_2 + (ulonglong)((uint)bVar2 + (uint)bVar2));

                iVar31 = iVar31 + uVar26;

              }

            } while (iVar31 != param_1);

            iVar31 = 0;

            param_4 = param_4 + *(int *)(param_3 + 0x10);

            iVar43 = iVar43 + -1;

          } while (iVar43 != 0);

          return;

        }

        iVar31 = 0;

        local_res20 = param_4;

        do {

          do {

            bVar2 = *(byte *)((longlong)param_2 + 1);

            iVar31 = iVar31 + (uint)(byte)*param_2;

            param_2 = param_2 + 1;

            if (bVar2 == 0) {

              if (iVar31 == 0) {

                return;

              }

            }

            else {

              uVar26 = (uint)bVar2;

              if (iVar31 < iVar41) {

                iVar20 = iVar8 - iVar31;

                uVar27 = uVar26;

                iVar29 = 0;

                if ((iVar20 < 1) || (uVar27 = uVar26 - iVar20, iVar29 = iVar20, 0 < (int)uVar27)) {

                  uVar21 = iVar41 - (iVar29 + iVar31);

                  if ((int)uVar27 <= (int)uVar21) {

                    uVar21 = uVar27;

                  }

                  puVar39 = (uint *)((longlong)(iVar29 * 2) + (longlong)param_2);

                  puVar36 = (uint *)(param_4 + (iVar29 + iVar31) * 2);

                  param_4 = local_res20;

                  if ((((byte)puVar39 ^ (byte)puVar36) & 3) == 0) {

                    if (((ulonglong)puVar39 & 3) != 0) {

                      uVar27 = *puVar39;

                      puVar39 = (uint *)((longlong)puVar39 + 2);

                      *(ushort *)puVar36 =

                           (short)(((ushort)*puVar36 & 0xfbde) + ((ushort)uVar27 & 0xfbde) >> 1) +

                           ((ushort)*puVar36 & (ushort)uVar27 & 0x421);

                      puVar36 = (uint *)((longlong)puVar36 + 2);

                      uVar21 = uVar21 - 1;

                    }

                    if (1 < uVar21) {

                      uVar30 = (ulonglong)((uVar21 - 2 >> 1) + 1);

                      do {

                        uVar27 = *puVar39;

                        uVar21 = uVar21 - 2;

                        puVar39 = puVar39 + 1;

                        *puVar36 = (*puVar36 >> 1 & 0x7def7def) + (uVar27 >> 1 & 0x7def7def) +

                                   (*puVar36 & uVar27 & 0x4210421);

                        puVar36 = puVar36 + 1;

                        uVar30 = uVar30 - 1;

                      } while (uVar30 != 0);

                    }

                    if (uVar21 != 0) {

                      *(ushort *)puVar36 =

                           (short)(((ushort)*puVar36 & 0xfbde) + ((ushort)*puVar39 & 0xfbde) >> 1) +

                           ((ushort)*puVar36 & (ushort)*puVar39 & 0x421);

                    }

                  }

                  else if (uVar21 != 0) {

                    puVar35 = puVar36;

                    do {

                      uVar5 = *(ushort *)

                               ((longlong)puVar35 + ((longlong)puVar39 - (longlong)puVar36));

                      *(ushort *)puVar35 =

                           (short)((uVar5 & 0xfbde) + ((ushort)*puVar35 & 0xfbde) >> 1) +

                           (uVar5 & (ushort)*puVar35 & 0x421);

                      uVar21 = uVar21 - 1;

                      puVar35 = (uint *)((longlong)puVar35 + 2);

                    } while (uVar21 != 0);

                  }

                }

              }

              param_2 = (ushort *)((longlong)param_2 + (ulonglong)((uint)bVar2 + (uint)bVar2));

              iVar31 = iVar31 + uVar26;

            }

          } while (iVar31 != param_1);

          iVar31 = 0;

          param_4 = param_4 + *(int *)(param_3 + 0x10);

          iVar43 = iVar43 + -1;

          local_res20 = param_4;

        } while (iVar43 != 0);

        return;

      }

    }

    else if ((uVar23 == 0xffff) && (((uVar27 == 0x7e0 || (uVar21 == 0x7e0)) || (uVar26 == 0x7e0))))

    {

      iVar8 = *param_5;

      iVar43 = param_5[3];

      iVar41 = param_5[2] + iVar8;

      param_4 = param_4 - iVar8 * 2;

      if (param_6 != 0x80) {

        iVar31 = 0;

        do {

          do {

            bVar2 = *(byte *)((longlong)param_2 + 1);

            iVar31 = iVar31 + (uint)(byte)*param_2;

            param_2 = param_2 + 1;

            if (bVar2 == 0) {

              if (iVar31 == 0) {

                return;

              }

            }

            else {

              uVar26 = (uint)bVar2;

              if (iVar31 < iVar41) {

                iVar20 = iVar8 - iVar31;

                uVar27 = uVar26;

                iVar29 = 0;

                if ((iVar20 < 1) || (uVar27 = uVar26 - iVar20, iVar29 = iVar20, 0 < (int)uVar27)) {

                  uVar21 = iVar41 - (iVar29 + iVar31);

                  if ((int)uVar27 <= (int)uVar21) {

                    uVar21 = uVar27;

                  }

                  puVar37 = (ushort *)((iVar29 + iVar31) * 2 + param_4);

                  if (0 < (int)uVar21) {

                    uVar30 = (ulonglong)uVar21;

                    puVar38 = puVar37;

                    do {

                      uVar7 = *(undefined2 *)

                               ((longlong)puVar38 +

                               (longlong)

                               (((longlong)(iVar29 * 2) - (longlong)puVar37) + (longlong)param_2));

                      uVar27 = CONCAT22(*puVar38,*puVar38) & 0x7e0f81f;

                      uVar27 = (((CONCAT22(uVar7,uVar7) & 0x7e0f81f) - uVar27) * (param_6 >> 3) >> 5

                               ) + uVar27 & 0x7e0f81f;

                      *puVar38 = (ushort)(uVar27 >> 0x10) | (ushort)uVar27;

                      uVar30 = uVar30 - 1;

                      puVar38 = puVar38 + 1;

                    } while (uVar30 != 0);

                  }

                }

              }

              param_2 = (ushort *)((longlong)param_2 + (ulonglong)((uint)bVar2 + (uint)bVar2));

              iVar31 = iVar31 + uVar26;

            }

          } while (iVar31 != param_1);

          iVar31 = 0;

          param_4 = param_4 + *(int *)(param_3 + 0x10);

          iVar43 = iVar43 + -1;

        } while (iVar43 != 0);

        return;

      }

      iVar31 = 0;

      local_res20 = param_4;

      do {

        do {

          bVar2 = *(byte *)((longlong)param_2 + 1);

          iVar31 = iVar31 + (uint)(byte)*param_2;

          param_2 = param_2 + 1;

          if (bVar2 == 0) {

            if (iVar31 == 0) {

              return;

            }

          }

          else {

            uVar26 = (uint)bVar2;

            if (iVar31 < iVar41) {

              iVar20 = iVar8 - iVar31;

              uVar27 = uVar26;

              iVar29 = 0;

              if ((iVar20 < 1) || (uVar27 = uVar26 - iVar20, iVar29 = iVar20, 0 < (int)uVar27)) {

                uVar21 = iVar41 - (iVar29 + iVar31);

                if ((int)uVar27 <= (int)uVar21) {

                  uVar21 = uVar27;

                }

                puVar39 = (uint *)((longlong)(iVar29 * 2) + (longlong)param_2);

                puVar36 = (uint *)(param_4 + (iVar29 + iVar31) * 2);

                param_4 = local_res20;

                if ((((byte)puVar36 ^ (byte)puVar39) & 3) == 0) {

                  if (((ulonglong)puVar39 & 3) != 0) {

                    uVar27 = *puVar39;

                    puVar39 = (uint *)((longlong)puVar39 + 2);

                    *(ushort *)puVar36 =

                         (short)(((ushort)*puVar36 & 0xf7de) + ((ushort)uVar27 & 0xf7de) >> 1) +

                         ((ushort)*puVar36 & (ushort)uVar27 & 0x821);

                    puVar36 = (uint *)((longlong)puVar36 + 2);

                    uVar21 = uVar21 - 1;

                  }

                  if (1 < uVar21) {

                    uVar30 = (ulonglong)((uVar21 - 2 >> 1) + 1);

                    do {

                      uVar21 = uVar21 - 2;

                      uVar27 = *puVar39;

                      puVar39 = puVar39 + 1;

                      *puVar36 = (*puVar36 & uVar27 & 0x8210821) + (*puVar36 >> 1 & 0x7bef7bef) +

                                 (uVar27 >> 1 & 0x7bef7bef);

                      puVar36 = puVar36 + 1;

                      uVar30 = uVar30 - 1;

                    } while (uVar30 != 0);

                  }

                  if (uVar21 != 0) {

                    *(ushort *)puVar36 =

                         (short)(((ushort)*puVar39 & 0xf7de) + ((ushort)*puVar36 & 0xf7de) >> 1) +

                         ((ushort)*puVar36 & (ushort)*puVar39 & 0x821);

                  }

                }

                else if (uVar21 != 0) {

                  puVar35 = puVar36;

                  do {

                    uVar5 = *(ushort *)((longlong)puVar35 + ((longlong)puVar39 - (longlong)puVar36))

                    ;

                    *(ushort *)puVar35 =

                         (short)(((ushort)*puVar35 & 0xf7de) + (uVar5 & 0xf7de) >> 1) +

                         (uVar5 & (ushort)*puVar35 & 0x821);

                    uVar21 = uVar21 - 1;

                    puVar35 = (uint *)((longlong)puVar35 + 2);

                  } while (uVar21 != 0);

                }

              }

            }

            param_2 = (ushort *)((longlong)param_2 + (ulonglong)((uint)bVar2 + (uint)bVar2));

            iVar31 = iVar31 + uVar26;

          }

        } while (iVar31 != param_1);

        iVar31 = 0;

        param_4 = param_4 + *(int *)(param_3 + 0x10);

        iVar43 = iVar43 + -1;

        local_res20 = param_4;

      } while (iVar43 != 0);

      return;

    }

    iVar31 = 0;

    iVar8 = *param_5;

    iVar43 = param_5[3];

    iVar41 = param_5[2];

    param_4 = param_4 - iVar8 * 2;

    local_res20 = param_4;

    local_b8 = iVar43;

    do {

      do {

        bVar2 = *(byte *)((longlong)param_2 + 1);

        uVar5 = *param_2;

        param_2 = param_2 + 1;

        iVar31 = iVar31 + (uint)(byte)uVar5;

        uVar26 = (uint)bVar2;

        if (bVar2 == 0) {

          if (iVar31 == 0) {

            return;

          }

        }

        else {

          if (iVar31 < iVar41 + iVar8) {

            iVar29 = iVar8 - iVar31;

            iVar43 = 0;

            if ((iVar29 < 1) || (uVar26 = uVar26 - iVar29, iVar43 = iVar29, 0 < (int)uVar26)) {

              uVar27 = (iVar41 + iVar8) - (iVar43 + iVar31);

              if ((int)uVar26 <= (int)uVar27) {

                uVar27 = uVar26;

              }

              local_80 = (ulonglong)uVar27;

              puVar37 = (ushort *)((iVar43 + iVar31) * 2 + param_4);

              if (0 < (int)uVar27) {

                lVar24 = (longlong)(iVar43 * 2) - (longlong)puVar37;

                do {

                  uVar30 = (ulonglong)*puVar37;

                  bVar3 = *(byte *)(lVar9 + 0x1c);

                  bVar4 = *(byte *)(lVar9 + 0x1e);

                  uVar5 = *(ushort *)((longlong)puVar37 + (longlong)(lVar24 + (longlong)param_2));

                  uVar26 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x18)]

                                       [(uVar30 & *(uint *)(lVar9 + 8)) >> (bVar3 & 0x3f)];

                  uVar27 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x1a)]

                                       [(*(uint *)(lVar9 + 0x10) & uVar30) >> (bVar4 & 0x3f)];

                  *puVar37 = (short)((((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x18)]

                                             [((ulonglong)uVar5 & (ulonglong)*(uint *)(lVar9 + 8))

                                              >> (bVar3 & 0x3f)] - uVar26) * param_6 >> 8) + uVar26

                                    >> (8 - *(byte *)(lVar9 + 0x18) & 0x1f)) << (bVar3 & 0x1f) |

                             (short)((((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x1a)]

                                             [((ulonglong)uVar5 & (ulonglong)*(uint *)(lVar9 + 0x10)

                                              ) >> (bVar4 & 0x3f)] - uVar27) * param_6 >> 8) +

                                     uVar27 >> (8 - *(byte *)(lVar9 + 0x1a) & 0x1f)) <<

                             (bVar4 & 0x1f) |

                             (short)((((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x19)]

                                                   [((ulonglong)uVar5 &

                                                    (ulonglong)*(uint *)(lVar9 + 0xc)) >>

                                                    (*(byte *)(lVar9 + 0x1d) & 0x3f)] -

                                      (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x19)]

                                                  [(*(uint *)(lVar9 + 0xc) & uVar30) >>

                                                   (*(byte *)(lVar9 + 0x1d) & 0x3f)]) * param_6 >> 8

                                     ) + (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x19)]

                                                     [(*(uint *)(lVar9 + 0xc) & uVar30) >>

                                                      (*(byte *)(lVar9 + 0x1d) & 0x3f)] >>

                                    (8 - *(byte *)(lVar9 + 0x19) & 0x1f)) <<

                             (*(byte *)(lVar9 + 0x1d) & 0x1f) | *(ushort *)(lVar9 + 0x14);

                  puVar37 = puVar37 + 1;

                  local_80 = local_80 - 1;

                  param_4 = local_res20;

                } while (local_80 != 0);

              }

            }

          }

          param_2 = (ushort *)((longlong)param_2 + (ulonglong)((uint)bVar2 * 2));

          iVar31 = iVar31 + (uint)bVar2;

          iVar43 = local_b8;

        }

      } while (iVar31 != param_1);

      iVar31 = 0;

      param_4 = param_4 + *(int *)(param_3 + 0x10);

      iVar43 = iVar43 + -1;

      local_res20 = param_4;

      local_b8 = iVar43;

    } while (iVar43 != 0);

  }

  else if (cVar1 == '\x03') {

    iVar31 = 0;

    iVar8 = *param_5;

    iVar43 = param_5[3];

    iVar41 = param_5[2];

    param_4 = param_4 - iVar8 * 3;

    local_res20 = param_4;

    local_b8 = iVar43;

    do {

      do {

        bVar2 = *(byte *)((longlong)param_2 + 1);

        uVar5 = *param_2;

        param_2 = param_2 + 1;

        iVar31 = iVar31 + (uint)(byte)uVar5;

        uVar26 = (uint)bVar2;

        if (bVar2 == 0) {

          if (iVar31 == 0) {

            return;

          }

        }

        else {

          if (iVar31 < iVar41 + iVar8) {

            iVar29 = iVar8 - iVar31;

            iVar43 = 0;

            if ((iVar29 < 1) || (uVar26 = uVar26 - iVar29, iVar43 = iVar29, 0 < (int)uVar26)) {

              uVar27 = (iVar41 + iVar8) - (iVar43 + iVar31);

              lVar24 = (longlong)((iVar43 + iVar31) * 3);

              if ((int)uVar26 <= (int)uVar27) {

                uVar27 = uVar26;

              }

              local_80 = (ulonglong)uVar27;

              puVar32 = (undefined1 *)(lVar24 + param_4);

              if (0 < (int)uVar27) {

                pbVar40 = (byte *)((longlong)(iVar43 * 3) + 1 + (longlong)param_2);

                lVar24 = ((lVar24 - iVar43 * 3) - (longlong)param_2) + param_4;

                do {

                  bVar3 = *(byte *)(lVar9 + 0x1d);

                  bVar4 = *(byte *)(lVar9 + 0x1e);

                  uVar34 = (ulonglong)

                           CONCAT21(CONCAT11(pbVar40[lVar24 + 1],pbVar40[lVar24]),*puVar32);

                  uVar26 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x18)]

                                       [(*(uint *)(lVar9 + 8) & uVar34) >>

                                        (*(byte *)(lVar9 + 0x1c) & 0x3f)];

                  uVar30 = (ulonglong)CONCAT21(*(undefined2 *)pbVar40,pbVar40[-1]);

                  uVar21 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x1a)]

                                       [(*(uint *)(lVar9 + 0x10) & uVar34) >> (bVar4 & 0x3f)];

                  uVar27 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x19)]

                                       [(*(uint *)(lVar9 + 0xc) & uVar34) >> (bVar3 & 0x3f)];

                  uVar26 = ((((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x1a)]

                                    [(*(uint *)(lVar9 + 0x10) & uVar30) >> (bVar4 & 0x3f)] - uVar21)

                             * param_6 >> 8) + uVar21 >> (8 - *(byte *)(lVar9 + 0x1a) & 0x1f)) <<

                           (bVar4 & 0x1f) |

                           ((((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x19)]

                                    [(*(uint *)(lVar9 + 0xc) & uVar30) >> (bVar3 & 0x3f)] - uVar27)

                             * param_6 >> 8) + uVar27 >> (8 - *(byte *)(lVar9 + 0x19) & 0x1f)) <<

                           (bVar3 & 0x1f) |

                           ((((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x18)]

                                    [(*(uint *)(lVar9 + 8) & uVar30) >>

                                     (*(byte *)(lVar9 + 0x1c) & 0x3f)] - uVar26) * param_6 >> 8) +

                            uVar26 >> (8U - *(char *)(lVar9 + 0x18) & 0x1f)) <<

                           (*(byte *)(lVar9 + 0x1c) & 0x1f) | *(uint *)(lVar9 + 0x14);

                  *puVar32 = (char)uVar26;

                  puVar32 = puVar32 + 3;

                  pbVar40[lVar24] = (byte)(uVar26 >> 8);

                  pbVar40[lVar24 + 1] = (byte)(uVar26 >> 0x10);

                  pbVar40 = pbVar40 + 3;

                  local_80 = local_80 - 1;

                  param_4 = local_res20;

                } while (local_80 != 0);

              }

            }

          }

          param_2 = (ushort *)((longlong)param_2 + (ulonglong)((uint)bVar2 * 3));

          iVar31 = iVar31 + (uint)bVar2;

          iVar43 = local_b8;

        }

      } while (iVar31 != param_1);

      iVar31 = 0;

      param_4 = param_4 + *(int *)(param_3 + 0x10);

      iVar43 = iVar43 + -1;

      local_res20 = param_4;

      local_b8 = iVar43;

    } while (iVar43 != 0);

  }

  else if (cVar1 == '\x04') {

    if (((*(uint *)(lVar9 + 0x10) | *(uint *)(lVar9 + 0xc) | *(uint *)(lVar9 + 8)) == 0xffffff) &&

       (((*(uint *)(lVar9 + 0xc) == 0xff00 || (*(uint *)(lVar9 + 8) == 0xff00)) ||

        (*(uint *)(lVar9 + 0x10) == 0xff00)))) {

      iVar8 = *param_5;

      iVar43 = param_5[3];

      iVar41 = param_5[2] + iVar8;

      param_4 = param_4 - iVar8 * 4;

      if (param_6 == 0x80) {

        iVar31 = 0;

        do {

          do {

            uVar5 = param_2[1];

            iVar31 = iVar31 + (uint)*param_2;

            param_2 = param_2 + 2;

            if (uVar5 == 0) {

              if (iVar31 == 0) {

                return;

              }

            }

            else {

              uVar26 = (uint)uVar5;

              if (iVar31 < iVar41) {

                iVar20 = iVar8 - iVar31;

                iVar29 = 0;

                uVar27 = uVar26;

                if ((iVar20 < 1) || (uVar27 = uVar26 - iVar20, iVar29 = iVar20, 0 < (int)uVar27)) {

                  uVar21 = iVar41 - (iVar29 + iVar31);

                  if ((int)uVar27 <= (int)uVar21) {

                    uVar21 = uVar27;

                  }

                  iVar20 = 0;

                  puVar39 = (uint *)((longlong)(iVar29 * 4) + (longlong)param_2);

                  puVar36 = (uint *)((iVar29 + iVar31) * 4 + param_4);

                  if (0 < (int)uVar21) {

                    if ((0xf < uVar21) &&

                       ((puVar39 + (int)(uVar21 - 1) < puVar36 ||

                        (puVar36 + (int)(uVar21 - 1) < puVar39)))) {

                      uVar27 = uVar21 & 0x8000000f;

                      if ((int)uVar27 < 0) {

                        uVar27 = (uVar27 - 1 | 0xfffffff0) + 1;

                      }

                      do {

                        iVar20 = iVar20 + 0x10;

                        uVar23 = puVar39[1];

                        uVar10 = puVar39[2];

                        uVar11 = puVar39[3];

                        uVar12 = puVar39[4];

                        uVar13 = puVar39[5];

                        uVar45 = puVar39[6];

                        uVar47 = puVar39[7];

                        *puVar36 = ((uVar16 & *puVar36) + (uVar16 & *puVar39) >> 1) +

                                   (*puVar36 & *puVar39 & uVar42);

                        puVar36[1] = ((uVar17 & puVar36[1]) + (uVar17 & uVar23) >> 1) +

                                     (puVar36[1] & uVar23 & uVar22);

                        puVar36[2] = ((uVar18 & puVar36[2]) + (uVar18 & uVar10) >> 1) +

                                     (puVar36[2] & uVar10 & uVar28);

                        puVar36[3] = ((uVar19 & puVar36[3]) + (uVar19 & uVar11) >> 1) +

                                     (puVar36[3] & uVar11 & uVar46);

                        uVar23 = puVar39[8];

                        uVar10 = puVar39[9];

                        uVar11 = puVar39[10];

                        uVar48 = puVar39[0xb];

                        puVar36[4] = ((uVar16 & puVar36[4]) + (uVar16 & uVar12) >> 1) +

                                     (puVar36[4] & uVar12 & uVar42);

                        puVar36[5] = ((uVar17 & puVar36[5]) + (uVar17 & uVar13) >> 1) +

                                     (puVar36[5] & uVar13 & uVar22);

                        puVar36[6] = ((uVar18 & puVar36[6]) + (uVar18 & uVar45) >> 1) +

                                     (puVar36[6] & uVar45 & uVar28);

                        puVar36[7] = ((uVar19 & puVar36[7]) + (uVar19 & uVar47) >> 1) +

                                     (puVar36[7] & uVar47 & uVar46);

                        uVar12 = puVar39[0xc];

                        uVar13 = puVar39[0xd];

                        uVar45 = puVar39[0xe];

                        uVar47 = puVar39[0xf];

                        puVar39 = puVar39 + 0x10;

                        puVar36[8] = ((uVar16 & puVar36[8]) + (uVar16 & uVar23) >> 1) +

                                     (puVar36[8] & uVar23 & uVar42);

                        puVar36[9] = ((uVar17 & puVar36[9]) + (uVar17 & uVar10) >> 1) +

                                     (puVar36[9] & uVar10 & uVar22);

                        puVar36[10] = ((uVar18 & puVar36[10]) + (uVar18 & uVar11) >> 1) +

                                      (puVar36[10] & uVar11 & uVar28);

                        puVar36[0xb] = ((uVar19 & puVar36[0xb]) + (uVar19 & uVar48) >> 1) +

                                       (puVar36[0xb] & uVar48 & uVar46);

                        puVar36[0xc] = ((uVar16 & puVar36[0xc]) + (uVar16 & uVar12) >> 1) +

                                       (puVar36[0xc] & uVar12 & uVar42);

                        puVar36[0xd] = ((uVar17 & puVar36[0xd]) + (uVar17 & uVar13) >> 1) +

                                       (puVar36[0xd] & uVar13 & uVar22);

                        puVar36[0xe] = ((uVar18 & puVar36[0xe]) + (uVar18 & uVar45) >> 1) +

                                       (puVar36[0xe] & uVar45 & uVar28);

                        puVar36[0xf] = ((uVar19 & puVar36[0xf]) + (uVar19 & uVar47) >> 1) +

                                       (puVar36[0xf] & uVar47 & uVar46);

                        puVar36 = puVar36 + 0x10;

                      } while (iVar20 < (int)(uVar21 - uVar27));

                      if ((int)uVar21 <= iVar20) goto LAB_1401cf7f6;

                    }

                    uVar30 = (ulonglong)(uVar21 - iVar20);

                    puVar35 = puVar36;

                    do {

                      *puVar35 = ((*puVar35 & 0xfefefe) +

                                  (*(uint *)((longlong)puVar35 +

                                            ((longlong)puVar39 - (longlong)puVar36)) & 0xfefefe) >>

                                 1) + (*puVar35 &

                                       *(uint *)((longlong)puVar35 +

                                                ((longlong)puVar39 - (longlong)puVar36)) & 0x10101);

                      uVar30 = uVar30 - 1;

                      puVar35 = puVar35 + 1;

                    } while (uVar30 != 0);

                  }

                }

              }

LAB_1401cf7f6:

              param_2 = (ushort *)((longlong)param_2 + (ulonglong)((uint)uVar5 * 4));

              iVar31 = iVar31 + uVar26;

            }

          } while (iVar31 != param_1);

          iVar31 = 0;

          param_4 = param_4 + *(int *)(param_3 + 0x10);

          iVar43 = iVar43 + -1;

        } while (iVar43 != 0);

      }

      else {

        iVar29 = 0;

        iVar31 = DAT_1403e8ad0;

        do {

          do {

            uVar5 = param_2[1];

            iVar29 = iVar29 + (uint)*param_2;

            param_2 = param_2 + 2;

            if (uVar5 == 0) {

              if (iVar29 == 0) {

                return;

              }

            }

            else {

              uVar42 = (uint)uVar5;

              iVar20 = iVar31;

              if (iVar29 < iVar41) {

                iVar25 = iVar8 - iVar29;

                iVar33 = 0;

                uVar22 = uVar42;

                if ((iVar25 < 1) || (uVar22 = uVar42 - iVar25, iVar33 = iVar25, 0 < (int)uVar22)) {

                  uVar28 = iVar41 - (iVar33 + iVar29);

                  if ((int)uVar22 <= (int)uVar28) {

                    uVar28 = uVar22;

                  }

                  iVar25 = 0;

                  puVar39 = (uint *)((longlong)(iVar33 * 4) + (longlong)param_2);

                  puVar36 = (uint *)((iVar33 + iVar29) * 4 + param_4);

                  iVar20 = DAT_1403e8ad0;

                  if (0 < (int)uVar28) {

                    iVar33 = iVar25;

                    if (((7 < uVar28) && (1 < iVar31)) &&

                       ((puVar39 + (int)(uVar28 - 1) < puVar36 ||

                        (iVar33 = 0, puVar36 + (int)(uVar28 - 1) < puVar39)))) {

                      uVar22 = uVar28 & 0x80000007;

                      if ((int)uVar22 < 0) {

                        uVar22 = (uVar22 - 1 | 0xfffffff8) + 1;

                      }

                      do {

                        iVar25 = iVar25 + 8;

                        uVar46 = *puVar39;

                        puVar35 = puVar39 + 1;

                        puVar14 = puVar39 + 2;

                        puVar15 = puVar39 + 3;

                        uVar45 = uVar10 & *puVar36;

                        uVar47 = uVar11 & puVar36[1];

                        uVar48 = uVar12 & puVar36[2];

                        uVar49 = uVar13 & puVar36[3];

                        uVar50 = uVar26 & *puVar36;

                        uVar51 = uVar27 & puVar36[1];

                        uVar52 = uVar21 & puVar36[2];

                        uVar53 = uVar23 & puVar36[3];

                        uVar16 = puVar39[4];

                        uVar17 = puVar39[5];

                        uVar18 = puVar39[6];

                        uVar19 = puVar39[7];

                        puVar39 = puVar39 + 8;

                        auVar56._0_4_ = (uVar10 & uVar46) - uVar45;

                        auVar56._4_4_ = (uVar11 & *puVar35) - uVar47;

                        auVar56._8_4_ = (uVar12 & *puVar14) - uVar48;

                        auVar56._12_4_ = (uVar13 & *puVar15) - uVar49;

                        auVar44._0_4_ = (uVar26 & uVar46) - uVar50;

                        auVar44._4_4_ = (uVar27 & *puVar35) - uVar51;

                        auVar44._8_4_ = (uVar21 & *puVar14) - uVar52;

                        auVar44._12_4_ = (uVar23 & *puVar15) - uVar53;

                        auVar54 = pmulld(auVar56,auVar57);

                        auVar44 = pmulld(auVar44,auVar57);

                        *puVar36 = (auVar54._0_4_ >> 8) + uVar45 & uVar10 |

                                   (auVar44._0_4_ >> 8) + uVar50 & uVar26;

                        puVar36[1] = (auVar54._4_4_ >> 8) + uVar47 & uVar11 |

                                     (auVar44._4_4_ >> 8) + uVar51 & uVar27;

                        puVar36[2] = (auVar54._8_4_ >> 8) + uVar48 & uVar12 |

                                     (auVar44._8_4_ >> 8) + uVar52 & uVar21;

                        puVar36[3] = (auVar54._12_4_ >> 8) + uVar49 & uVar13 |

                                     (auVar44._12_4_ >> 8) + uVar53 & uVar23;

                        uVar46 = uVar10 & puVar36[4];

                        uVar45 = uVar11 & puVar36[5];

                        uVar47 = uVar12 & puVar36[6];

                        uVar48 = uVar13 & puVar36[7];

                        uVar49 = uVar26 & puVar36[4];

                        uVar50 = uVar27 & puVar36[5];

                        uVar51 = uVar21 & puVar36[6];

                        uVar52 = uVar23 & puVar36[7];

                        auVar55._0_4_ = (uVar10 & uVar16) - uVar46;

                        auVar55._4_4_ = (uVar11 & uVar17) - uVar45;

                        auVar55._8_4_ = (uVar12 & uVar18) - uVar47;

                        auVar55._12_4_ = (uVar13 & uVar19) - uVar48;

                        auVar54._0_4_ = (uVar26 & uVar16) - uVar49;

                        auVar54._4_4_ = (uVar27 & uVar17) - uVar50;

                        auVar54._8_4_ = (uVar21 & uVar18) - uVar51;

                        auVar54._12_4_ = (uVar23 & uVar19) - uVar52;

                        auVar56 = pmulld(auVar55,auVar57);

                        auVar44 = pmulld(auVar54,auVar57);

                        puVar36[4] = (auVar56._0_4_ >> 8) + uVar46 & uVar10 |

                                     (auVar44._0_4_ >> 8) + uVar49 & uVar26;

                        puVar36[5] = (auVar56._4_4_ >> 8) + uVar45 & uVar11 |

                                     (auVar44._4_4_ >> 8) + uVar50 & uVar27;

                        puVar36[6] = (auVar56._8_4_ >> 8) + uVar47 & uVar12 |

                                     (auVar44._8_4_ >> 8) + uVar51 & uVar21;

                        puVar36[7] = (auVar56._12_4_ >> 8) + uVar48 & uVar13 |

                                     (auVar44._12_4_ >> 8) + uVar52 & uVar23;

                        puVar36 = puVar36 + 8;

                      } while (iVar25 < (int)(uVar28 - uVar22));

                      iVar33 = iVar25;

                      iVar20 = DAT_1403e8ad0;

                      if ((int)uVar28 <= iVar25) goto LAB_1401cfa57;

                    }

                    uVar30 = (ulonglong)(uVar28 - iVar33);

                    puVar35 = puVar36;

                    do {

                      uVar22 = *(uint *)((longlong)puVar35 + ((longlong)puVar39 - (longlong)puVar36)

                                        );

                      uVar46 = *puVar35 & 0xff00;

                      uVar28 = *puVar35 & 0xff00ff;

                      *puVar35 = (((uVar22 & 0xff00ff) - uVar28) * param_6 >> 8) + uVar28 & 0xff00ff

                                 | (((uVar22 & 0xff00) - uVar46) * param_6 >> 8) + uVar46 & 0xff00;

                      uVar30 = uVar30 - 1;

                      puVar35 = puVar35 + 1;

                      iVar20 = DAT_1403e8ad0;

                    } while (uVar30 != 0);

                  }

                }

              }

LAB_1401cfa57:

              param_2 = (ushort *)((longlong)param_2 + (ulonglong)((uint)uVar5 * 4));

              iVar29 = iVar29 + uVar42;

              iVar31 = iVar20;

            }

          } while (iVar29 != param_1);

          iVar29 = 0;

          param_4 = param_4 + *(int *)(param_3 + 0x10);

          iVar43 = iVar43 + -1;

        } while (iVar43 != 0);

      }

    }

    else {

      iVar31 = 0;

      iVar8 = *param_5;

      iVar43 = param_5[3];

      iVar41 = param_5[2];

      param_4 = param_4 - iVar8 * 4;

      local_res20 = param_4;

      local_b8 = iVar43;

      do {

        do {

          uVar5 = param_2[1];

          uVar6 = *param_2;

          param_2 = param_2 + 2;

          iVar31 = iVar31 + (uint)uVar6;

          uVar26 = (uint)uVar5;

          if (uVar5 == 0) {

            if (iVar31 == 0) {

              return;

            }

          }

          else {

            if (iVar31 < iVar41 + iVar8) {

              iVar20 = iVar8 - iVar31;

              iVar29 = 0;

              if ((iVar20 < 1) || (uVar26 = uVar26 - iVar20, iVar29 = iVar20, 0 < (int)uVar26)) {

                uVar27 = (iVar41 + iVar8) - (iVar29 + iVar31);

                if ((int)uVar26 <= (int)uVar27) {

                  uVar27 = uVar26;

                }

                local_98 = (ulonglong)uVar27;

                puVar36 = (uint *)((iVar29 + iVar31) * 4 + param_4);

                iVar43 = local_b8;

                if (0 < (int)uVar27) {

                  lVar24 = (longlong)(iVar29 * 4) - (longlong)puVar36;

                  do {

                    uVar26 = *(uint *)((longlong)puVar36 + (longlong)(lVar24 + (longlong)param_2));

                    uVar27 = *puVar36;

                    bVar2 = *(byte *)(lVar9 + 0x1c);

                    bVar3 = *(byte *)(lVar9 + 0x1e);

                    uVar23 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x18)]

                                         [(*(uint *)(lVar9 + 8) & uVar27) >> (bVar2 & 0x3f)];

                    uVar21 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x1a)]

                                         [(*(uint *)(lVar9 + 0x10) & uVar27) >> (bVar3 & 0x3f)];

                    uVar27 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x19)]

                                         [(*(uint *)(lVar9 + 0xc) & uVar27) >>

                                          (*(byte *)(lVar9 + 0x1d) & 0x3f)];

                    *puVar36 = ((((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x18)]

                                        [(*(uint *)(lVar9 + 8) & uVar26) >> (bVar2 & 0x3f)] - uVar23

                                 ) * param_6 >> 8) + uVar23 >> (8 - *(byte *)(lVar9 + 0x18) & 0x1f))

                               << (bVar2 & 0x1f) |

                               ((((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x1a)]

                                        [(*(uint *)(lVar9 + 0x10) & uVar26) >> (bVar3 & 0x3f)] -

                                 uVar21) * param_6 >> 8) + uVar21 >>

                               (8 - *(byte *)(lVar9 + 0x1a) & 0x1f)) << (bVar3 & 0x1f) |

                               ((((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x19)]

                                        [(*(uint *)(lVar9 + 0xc) & uVar26) >>

                                         (*(byte *)(lVar9 + 0x1d) & 0x3f)] - uVar27) * param_6 >> 8)

                                + uVar27 >> (8U - *(char *)(lVar9 + 0x19) & 0x1f)) <<

                               (*(byte *)(lVar9 + 0x1d) & 0x1f) | *(uint *)(lVar9 + 0x14);

                    puVar36 = puVar36 + 1;

                    local_98 = local_98 - 1;

                    param_4 = local_res20;

                  } while (local_98 != 0);

                }

              }

            }

            param_2 = (ushort *)((longlong)param_2 + (ulonglong)((uint)uVar5 * 4));

            iVar31 = iVar31 + (uint)uVar5;

          }

        } while (iVar31 != param_1);

        iVar31 = 0;

        param_4 = param_4 + *(int *)(param_3 + 0x10);

        iVar43 = iVar43 + -1;

        local_res20 = param_4;

        local_b8 = iVar43;

      } while (iVar43 != 0);

    }

  }

  return;

}




